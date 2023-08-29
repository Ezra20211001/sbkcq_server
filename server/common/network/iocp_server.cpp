/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#include "stdafx.h"
#include "iocp_server.h"

#include "..\serverbase\file_filter.h"
#include "../dump/code_dump.h"

#pragma intrinsic(memcpy)

namespace networkbase {

IOCP::IOCP()
{
	h_competion_port = 0;
	lp_fn_accept = 0;
	lp_fn_get_accept_sockaddr = 0;
	b_end_work_threak = FALSE;
	p_memory_pool = NULL;
	n_pool_num = 0;
	n_accept_num = 0;
	n64_send_size = 0;
	n64_compress_send_size = 0;

	n32AddNum = 0;
	n32DropNum = 0;
	n32RecvAddNum = 0;
	n32RecvDropNum = 0;
	n64SecSendSize = 0;
	n_io_pending = 0;
	dw_io_pending_id = 0;

	h_event_accept = ::CreateEvent(NULL, FALSE, TRUE, NULL);	
	h_event_send = ::CreateEvent(NULL, FALSE, TRUE, NULL);		
	h_event_destroy = ::CreateEvent(NULL, FALSE, TRUE, NULL);	
	p_filter = new file_filter;
	p_filter->init_file_filter(EFLT_MiniLzo);

	m_pLog = new log_file;
}

IOCP::~IOCP()
{
	m_pLog->close_file();
	SAFE_DELETE(m_pLog);
	SAFE_DELETE(p_filter);
	CloseHandle(h_event_accept);
	CloseHandle(h_event_send);
	CloseHandle(h_event_destroy);
}

BOOL IOCP::init(tag_server_config& param)
{
	ASSERT(param.fn_login && param.fn_logout);
	memcpy(&st_config, &param, sizeof(st_config)); 
	
	p_client = new tag_net_client[st_config.n_max_client_num];	
	if( !p_client )
		return FALSE;

	ZeroMemory(p_client, sizeof(tag_net_client)*st_config.n_max_client_num);
	for(INT n=0; n<st_config.n_max_client_num; n++)
	{
		p_client[n].p_recv_queue = new safe_queue<tag_unit*>;
		p_client[n].p_send_queue = new safe_queue<tag_raw_unit*>;
		list_free_client.pust_back(&p_client[n]);
	}

	sock_listen = socket(AF_INET, SOCK_STREAM, 0);	

	//端口重用
	if( st_config.b_repeat_port )
	{
		DWORD dw_repeat_useaddr = TRUE;	
		setsockopt( sock_listen, SOL_SOCKET, SO_REUSEADDR, 
			(char*)&dw_repeat_useaddr, sizeof(dw_repeat_useaddr) );
	}

	if( !st_config.b_use_nagle )
	{
		BOOL b_nagle = TRUE;
		setsockopt(sock_listen, IPPROTO_TCP, TCP_NODELAY, (char*)&b_nagle, sizeof(b_nagle));
	}

	sockaddr_in address;
    ZeroMemory(&address, sizeof(address));
    address.sin_family      = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port        = htons(st_config.n_port);

    while( SOCKET_ERROR == bind(sock_listen, (sockaddr*)&address, sizeof(address)) )
	{
		if( WSAEADDRINUSE == WSAGetLastError() )
		{
			++st_config.n_port;	
			address.sin_port = htons(st_config.n_port);
		}
		else
		{
			closesocket(sock_listen);
			ERROR_CLUE_ON(_T("bind() failed"));
			return FALSE;
		}
	}

    h_competion_port = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    listen( sock_listen, SOMAXCONN );
	CreateIoCompletionPort((HANDLE)sock_listen, h_competion_port, (DWORD)0, 0);

	GUID st_guid = WSAID_ACCEPTEX, st_guid2 = WSAID_GETACCEPTEXSOCKADDRS;
	DWORD dw_bytes = 0;
	WSAIoctl(sock_listen, SIO_GET_EXTENSION_FUNCTION_POINTER, &st_guid,
		sizeof(GUID), &lp_fn_accept, sizeof(lp_fn_accept), &dw_bytes, 0, 0);
	WSAIoctl(sock_listen, SIO_GET_EXTENSION_FUNCTION_POINTER, &st_guid2,
		sizeof(GUID), &lp_fn_get_accept_sockaddr,sizeof(lp_fn_get_accept_sockaddr), &dw_bytes, 0, 0);

	// 建立工作线程
	INT n_work_thread = (get_tool()->get_cup_num() * st_config.n_cpu_work_thread) 
		+ st_config.n_superfluity_work_thread;
	
	// 创建工作线程,分配内存池
	if( FALSE == create_work_thread(n_work_thread) )	
		return FALSE;
	
	// 创建连线请求线程
	if( FALSE == create_accept_thread() )	
		return FALSE;

	// 发送消息线程
	if( FALSE == create_send_thread() )	
		return FALSE;
	
	// 客户端验证线程
	if( FALSE == create_unauth_heartbeat_thread() )	
		return FALSE;

	// 销毁线程
	if( FALSE == create_destroy_thread() )	
		return FALSE;

	return TRUE;
}

BOOL IOCP::destroy()
{
	SAFE_CLOSE_HANDLE(h_competion_port);

	Interlocked_Exchange((LONG*)&b_end_work_threak, TRUE);
	for(INT n=(INT)v_thread_hanle.size()-1; n>=0; n--)
	{
		if( v_thread_hanle[n] )
		{
			WaitForSingleObject(v_thread_hanle[n], INFINITE);
			SAFE_CLOSE_HANDLE(v_thread_hanle[n]);
		}
	}

	for(INT n=0; n<st_config.n_max_client_num; n++)	
	{
		if( !p_client[n].b_shut_down )
		{
			closesocket(p_client[n].sock);
			
			SAFE_DELETE(p_client[n].p_recv_queue);
			SAFE_DELETE(p_client[n].p_send_queue);
		}
	}

	SAFE_DELETE_ARRAY(p_memory_pool);
	SAFE_DELETE_ARRAY(p_client);
	return TRUE;
}


//-----------------------------------------------------------------------------
// 温柔的踢出客户端
//-----------------------------------------------------------------------------
VOID IOCP::kick_client(DWORD dw_handle_)
{ 
	shutdown(((tag_net_client*)dw_handle_)->sock, SD_BOTH);
}

//-----------------------------------------------------------------------------
// 不管消息是否发送完成，强行踢出客户端
//-----------------------------------------------------------------------------
VOID IOCP::clost_client(DWORD dw_handle_)
{ 
	closesocket(((tag_net_client*)dw_handle_)->sock);
}

BOOL IOCP::create_accept_thread()
{
	INT n_return = _beginthreadex(NULL, 0, thread_accept, this, 0, NULL);
	if( 0 == n_return || -1 == n_return )
	{
		ERROR_CLUE_ON(_T("[s]create setup acceptex thread failed"));
		return FALSE;
	}

	// 激活event
	::SetEvent(h_event_accept);
	v_thread_hanle.push_back((HANDLE)n_return);
	return TRUE;
}

UINT WINAPI thread_accept(LPVOID p)
{
	THROW_EXCEPTION_START
	IOCP* p_server = (IOCP*)p;
	tag_net_client* p_client = NULL;
	BOOL b_result = FALSE;
	DWORD dw_bytes = 0;

	while( FALSE == p_server->is_end_work_thread() )
	{
		while( p_server->get_accept_num() < p_server->get_config()->n_accept_num 
			&& VALID_VALUE(p_client = p_server->get_list_free_client().pop_front()) )
		{
			p_client->b_shut_down = FALSE;		
			p_client->sock = socket(AF_INET, SOCK_STREAM, 0);
			p_client->dw_session_id = INVALID_VALUE;
			p_client->dw_connect_time = INVALID_VALUE;
			p_client->l_send_cast = 0;
			p_client->l_recv_cast = 1;
			p_client->dw_send_size = 0;
			p_client->b_send = TRUE;
			
			tag_unit* pUnit = (tag_unit*)p_server->get_pool(0)->alloc_memory(UNIT_MEM_SIZE(LOGIN_PARAM_SIZE));
			pUnit->p_memory_pool = p_server->get_pool(0);
			pUnit->ov.hEvent = NULL;
			pUnit->e_state = ESS_Accept;
			pUnit->p_next = NULL;
			((tag_login_param*)(&pUnit->p_buffer[LOGIN_PARAM_INDEX]))->dw_handle = (DWORD)p_client;
			
			b_result = (p_server->get_fn_accept())(p_server->get_listen_sock(), p_client->sock, pUnit->p_buffer, 0, 
				sizeof(sockaddr_in)+16, sizeof(sockaddr_in)+16, &dw_bytes, (OVERLAPPED*)pUnit);
			if( !b_result && ERROR_IO_PENDING != WSAGetLastError() )
			{
				p_server->destroy_client(p_client);
				pUnit->p_memory_pool->free_memory(pUnit);
				continue;
			}

			Interlocked_Increment((LONG*)&p_server->get_accept_num());
		}

		WaitForSingleObject(p_server->get_event_accept(), SLEEP_TIME);
	}

	shutdown(p_server->get_listen_sock(), SD_BOTH);
	closesocket(p_server->get_listen_sock());
	THROW_EXCEPTION_END
	return 0;
}

// 创建工作线程
BOOL IOCP::create_work_thread(INT n_thread_num_)
{
	p_memory_pool = new safe_memory_pool[n_thread_num_+1];
	n_pool_num = n_thread_num_+1;

    for(INT n=1; n<=n_thread_num_; n++)
    {
		if(n >= MAX_WORK_THREAD)
			return TRUE;

		p_memory_pool[n].set_max_memory_size(st_config.dw_mem_pool_size);

		st_work_param[n].p_server = this;
		st_work_param[n].n_index = n;

        INT n_return = _beginthreadex(NULL, 0, thread_work, (LPVOID)&st_work_param[n], 0, NULL);
		if( 0 == n_return || -1 == n_return )
		{
			ERROR_CLUE_ON(_T("[s]create worker thread failed"));
			return FALSE;
		}
		v_thread_hanle.push_back((HANDLE)n_return);
    }

	return TRUE;
}

UINT WINAPI	thread_work(LPVOID p)
{
	THROW_EXCEPTION_START

	tag_work_param* p_work_param = (tag_work_param*)p;
	IOCP* p_server = p_work_param->p_server;
	INT	n_index = p_work_param->n_index;
	INT n_result = 0;
	DWORD dw_flag = 0;
	DWORD dw_bytes = 0;
	BOOL b_dont_linger = TRUE;
	sockaddr_in *p_remote_addr, *p_local_addr;
	DWORD dw_remote_addr_size = 0, dw_local_addr_size = 0;
	
	WSAOVERLAPPED*	p_overlapped = NULL;
	tag_net_client* p_client = NULL;
	tag_unit* p_unit_got = NULL;
	tag_unit* p_unit = NULL;

	WSABUF st_wbuf;
	DWORD dw_need_bytes = 0;
	DWORD dw_comp_bytes = 0;
        
	while( !p_server->is_end_work_thread() )
	{
		// 得到完成端口状态
		n_result = GetQueuedCompletionStatus(p_server->get_competion_port(), &dw_comp_bytes, (DWORD*)&p_client, &p_overlapped, SLEEP_TIME);
		if( !p_overlapped )
			continue;

		p_unit_got = CONTAINING_RECORD(p_overlapped, tag_unit, ov);
		if( ESS_Accept == p_unit_got->e_state )	
		{
			p_client = (tag_net_client*)(((tag_login_param*)(&p_unit_got->p_buffer[LOGIN_PARAM_INDEX]))->dw_handle);
			Interlocked_Decrement((LONG*)&p_server->get_accept_num());	
			SetEvent(p_server->get_event_accept());
		}

		// 完成端口失败
		if( !n_result )	
		{
			p_server->pre_destroy_client(p_client, p_unit_got); 
			continue;
		}

		switch( p_unit_got->e_state )
		{
		case ESS_Accept:
			setsockopt(p_client->sock, SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT, (char*)&p_server->get_listen_sock(), sizeof(SOCKET));
			setsockopt(p_client->sock, SOL_SOCKET, SO_DONTLINGER, (char*)&b_dont_linger, sizeof(b_dont_linger));
			
			(p_server->get_fn_get_accept_sockaddr())(p_unit_got->p_buffer, 0, sizeof(sockaddr_in)+16, sizeof(sockaddr_in)+16, 
				(sockaddr**)&p_local_addr, (LPINT)&dw_local_addr_size, (sockaddr**)&p_remote_addr, (LPINT)&dw_remote_addr_size);
			((tag_login_param*)(&p_unit_got->p_buffer[LOGIN_PARAM_INDEX]))->dw_address = p_remote_addr->sin_addr.S_un.S_addr;
			((tag_login_param*)(&p_unit_got->p_buffer[LOGIN_PARAM_INDEX]))->dw_port = p_remote_addr->sin_port;

			if( !CreateIoCompletionPort((HANDLE)p_client->sock, p_server->get_competion_port(), (ULONG_PTR)p_client, 0) )	// 绑定完成端口
			{
				p_server->pre_destroy_client(p_client, p_unit_got); 
				break;
			}

			p_client->dw_connect_time = timeGetTime();
			p_server->get_list_unauth_client().pust_back(p_client);	

			p_unit = (tag_unit*)p_server->get_pool(n_index)->alloc_memory(UNIT_MEM_SIZE(p_server->get_config()->dw_max_recv_size));
			p_unit->p_memory_pool = p_server->get_pool(n_index);
			p_unit->ov.hEvent = NULL;
			p_unit->e_state = ESS_RecvLength;
			p_unit->dw_trans_bytes = 0;
			p_unit->dw_size = sizeof(DWORD);
			p_unit->p_next = p_unit_got;

			st_wbuf.buf = p_unit->p_buffer;
			st_wbuf.len = p_unit->dw_size;
			if( 0 != WSARecv(p_client->sock, &st_wbuf, 1, &dw_bytes, &dw_flag, &p_unit->ov, NULL) )
			{
				if( WSA_IO_PENDING != WSAGetLastError() )
					p_server->pre_destroy_client(p_client, p_unit);
			}	
			break;

			// 获取接收包长度
		case ESS_RecvLength:	
			if( dw_comp_bytes == 0 )
			{
				p_server->pre_destroy_client(p_client, p_unit_got);
				break;
			}

			dw_need_bytes = p_unit_got->dw_size - p_unit_got->dw_trans_bytes;
			p_unit_got->dw_trans_bytes += dw_comp_bytes;
			if( dw_comp_bytes == dw_need_bytes )
			{
				p_unit_got->dw_trans_bytes = 0;
				p_unit_got->dw_size = (*(DWORD*)&p_unit_got->p_buffer[0]);
				// 客户端发送消息超长
				if( p_unit_got->dw_size > p_server->get_config()->dw_max_recv_size )	
				{
					//p_server->get_log()->write_log(_T("SessionID %d recv length exceed limit\r\n"), p_client->dw_session_id);
					p_server->pre_destroy_client(p_client, p_unit_got);
					break;
				}
				p_unit_got->ov.hEvent = NULL;
				p_unit_got->e_state = ESS_Recv;
				st_wbuf.buf = p_unit_got->p_buffer;
				st_wbuf.len = p_unit_got->dw_size;
				if( 0 != WSARecv(p_client->sock, &st_wbuf, 1, &dw_bytes, &dw_flag, &p_unit_got->ov, NULL) )
				{
					if( WSA_IO_PENDING != WSAGetLastError() )
					{
						//p_server->get_log()->write_log(_T("ESS_RecvLength WSAGetLastError=%d Position = 1\r\n"), WSAGetLastError());
						p_server->pre_destroy_client(p_client, p_unit_got);
					}
				}	
			}
			else
			{
				p_unit_got->ov.hEvent = NULL;
				st_wbuf.buf = p_unit_got->p_buffer + p_unit_got->dw_trans_bytes;
				st_wbuf.len = p_unit_got->dw_size - p_unit_got->dw_trans_bytes;
				if( 0 != WSARecv(p_client->sock, &st_wbuf, 1, &dw_bytes, &dw_flag, &p_unit_got->ov, NULL) )
				{
					if( WSA_IO_PENDING != WSAGetLastError() )
					{
						//p_server->get_log()->write_log(_T("ESS_RecvLength WSAGetLastError=%d Position = 2\r\n"), WSAGetLastError());
						p_server->pre_destroy_client(p_client, p_unit_got);
					}
				}		
			}
			break;

		case ESS_Recv:	
			if( dw_comp_bytes == 0 )
			{
				p_server->pre_destroy_client(p_client, p_unit_got);
				break;
			}

			dw_need_bytes = p_unit_got->dw_size - p_unit_got->dw_trans_bytes;
			p_unit_got->dw_trans_bytes += dw_comp_bytes;
			// 消息接收完成
			if( dw_comp_bytes == dw_need_bytes )	
			{
				// 玩家发送的第一个封包
				if( p_unit_got->p_next )	
				{
					if( TRUE == p_server->get_list_unauth_client().erase(p_client) )
					{
						// 调用登陆回调函数
						tag_login_param* pParam = (tag_login_param*)(&p_unit_got->p_next->p_buffer[LOGIN_PARAM_INDEX]);
						p_client->dw_session_id = (p_server->get_config()->fn_login)(p_unit_got, pParam);
						if( INVALID_VALUE == p_client->dw_session_id )	
						{
							p_server->pre_destroy_client(p_client, p_unit_got);
							break;
						}

						p_unit_got->p_next->p_memory_pool->free_memory(p_unit_got->p_next);
						p_unit_got->p_next = NULL;
					}
					else	// 删除验证超时客户端
					{
						p_server->pre_destroy_client(p_client, p_unit_got);
						break;
					}
				}

				// 将收到的消息加入队列
				p_client->p_recv_queue->add(p_unit_got);	
			
				p_server->get_recv_num()++;
				p_unit = (tag_unit*)p_server->get_pool(n_index)->alloc_memory(UNIT_MEM_SIZE(p_server->get_config()->dw_max_recv_size));
				p_unit->p_memory_pool = p_server->get_pool(n_index);
				p_unit->ov.hEvent = NULL;
				p_unit->e_state = ESS_RecvLength;
				p_unit->dw_size = sizeof(DWORD);
				p_unit->dw_trans_bytes = 0;
				p_unit->p_next = NULL;

				st_wbuf.buf = p_unit->p_buffer;
				st_wbuf.len = p_unit->dw_size;
				if( 0 != WSARecv(p_client->sock, &st_wbuf, 1, &dw_bytes, &dw_flag, &p_unit->ov, NULL) )
				{
					if( WSA_IO_PENDING != WSAGetLastError() )
					{
						//p_server->get_log()->write_log(_T("ESS_Recv WSAGetLastError=%d Position = 1\r\n"), WSAGetLastError());
						p_server->pre_destroy_client(p_client, p_unit);
					}
				}				
			}
			else
			{
				p_unit_got->ov.hEvent = NULL;
				st_wbuf.buf = p_unit_got->p_buffer + p_unit_got->dw_trans_bytes;
				st_wbuf.len = p_unit_got->dw_size - p_unit_got->dw_trans_bytes;
				if( 0 != WSARecv(p_client->sock, &st_wbuf, 1, &dw_bytes, &dw_flag, &p_unit_got->ov, NULL) )
				{
					if( WSA_IO_PENDING != WSAGetLastError() )
					{
						//p_server->get_log()->write_log(_T("ESS_Recv WSAGetLastError=%d Position = 2\r\n"), WSAGetLastError());
						p_server->pre_destroy_client(p_client, p_unit_got);
					}
				}
			}
			break;

			// 消息发送完成，归还内存
		case ESS_Send:	
			p_client->dw_send_size -= p_unit_got->dw_size;
			p_unit_got->p_memory_pool->free_memory(p_unit_got);
			p_server->get_drop_num()++;
			Interlocked_Decrement(&p_client->l_send_cast);
			Interlocked_Exchange((LPLONG)&p_client->b_send, TRUE);
			break;
		default:
			{
#ifdef _DEBUG
				__asm int 3;
#endif
				p_server->get_log()->write_log(_T("p_unit_got->e_state%d\r\n"), p_unit_got->e_state);
				break;
			}

		}
	}
	
	THROW_EXCEPTION_END
	_endthreadex(0);
	return 0;
}

BOOL IOCP::create_send_thread()
{
    INT n_return = _beginthreadex(NULL, 0, thread_work_send, this, 0, NULL);
	if( 0 == n_return || -1 == n_return )
	{
		ERROR_CLUE_ON(_T("create send thread failed"));
		return FALSE;
    }

	v_thread_hanle.push_back((HANDLE)n_return);
	return TRUE;
}

UINT WINAPI thread_work_send(LPVOID p)
{
	THROW_EXCEPTION_START
	IOCP* p_server = (IOCP*)p;
	CHAR*		p_buff = new CHAR[p_server->get_config()->dw_tick_send_size];
	tag_raw_unit*	p_raw_unit = NULL;
	tag_unit*	p_unit = NULL;
	DWORD		dw_bytes = 0;
	DWORD		dw_total = 0;
	WSABUF		st_wbuf;
	INT			n_random = ( timeGetTime() % (p_server->get_pool_num()-1) ) + 1;
	tag_net_client* p_client = NULL;
	tag_file_filter_param st_param;
	st_param.b_compress = TRUE;
	st_param.b_success = FALSE;
	st_param.e_filter_type = EFLT_MiniLzo;
	st_param.p_memory_in = p_buff;
	st_param.dw_in_buffer_size = p_server->get_config()->dw_tick_send_size;

	while( !p_server->is_end_work_thread() )
	{
		for(INT n=0; n<p_server->get_config()->n_max_client_num; ++n)	
		{
			p_client = &p_server->get_client()[n];

			if( 0 == p_client->p_send_queue->get_num() )
				continue;

			if( p_client->b_shut_down )
			{
				INT n_num = 0;
				while( p_client->p_send_queue->get_num() > 0)
				{
					p_raw_unit = p_client->p_send_queue->get();
					Interlocked_Decrement(&p_client->l_send_cast);
					p_raw_unit->p_memory_pool->free_memory(p_raw_unit);
					n_num++;
					if(n_num > 200)
						break;
				}
				continue;
			}

			if(!p_client->b_send)
				continue;

			Interlocked_Increment(&p_client->l_send_cast);

			// 整合消息
			dw_total = 0;
			
			while( p_client->p_send_queue->get_num() > 0 )
			{
				p_raw_unit = p_client->p_send_queue->get();
				if(p_raw_unit->dw_size + dw_total >= p_server->get_config()->dw_tick_send_size)
				{
					p_client->p_send_queue->add_front(p_raw_unit);
					break;
				}
				Interlocked_Decrement(&p_client->l_send_cast);
				p_client->dw_send_size -= p_raw_unit->dw_size;
				memcpy(p_buff + dw_total, p_raw_unit->p_buffer, p_raw_unit->dw_size);
				dw_total += p_raw_unit->dw_size;
				p_raw_unit->p_memory_pool->free_memory(p_raw_unit);
			}

			// 空包处理
			if( dw_total == 0 )	
			{
				Interlocked_Decrement(&p_client->l_send_cast);
				continue;
			}

			// 进入内存锁定区分配内存
			for( p_unit=0;!p_unit; ) 
			{
				if( ++n_random >= p_server->get_pool_num() )
					n_random = 1;
				p_unit = (tag_unit*)p_server->get_pool(n_random)->try_alloc_memory(UNIT_MEM_SIZE(dw_total)+LZO_MEM_SIZE(dw_total)+sizeof(DWORD)*2);
				p_server->get_add_num()++;
			} 

			// 压缩消息
			st_param.dw_in_data_size = dw_total;
			st_param.dw_out_buffer_size = dw_total + LZO_MEM_SIZE(dw_total);
			st_param.dw_out_data_size = 0;
			st_param.p_memory_out = p_unit->p_buffer + sizeof(DWORD) * 2;
			p_server->get_filter()->filter_file(&st_param);

			// 在消息头填写大小和压缩前大小
			*(DWORD*)p_unit->p_buffer = st_param.dw_out_data_size;
			*(DWORD*)(p_unit->p_buffer + sizeof(DWORD)) = dw_total;
			p_unit->dw_size = st_param.dw_out_data_size + sizeof(DWORD) * 2;
			p_unit->ov.hEvent = NULL;
			p_unit->dw_trans_bytes = 0;
			p_unit->p_memory_pool = p_server->get_pool(n_random);
			p_unit->e_state = ESS_Send;
			p_unit->p_next = NULL;

			p_client->dw_send_size += p_unit->dw_size;

			st_wbuf.buf = p_unit->p_buffer;
			st_wbuf.len = p_unit->dw_size;
			if( WSASend(p_client->sock, &st_wbuf, 1, &dw_bytes, 0, &p_unit->ov, NULL) )
			{
				if( WSA_IO_PENDING != WSAGetLastError())
				{
					//p_server->get_log()->write_log(_T("IOCP SendMessage WSAGetLastError=%d\r\n"), WSAGetLastError());
					p_server->pre_destroy_client(p_client, p_unit);
					break;
				}
				else
				{
					Interlocked_Exchange((LPLONG)&p_client->b_send, FALSE);
					p_server->get_io_pending()++;
					p_server->get_io_pending_id() = p_client->dw_session_id;
				}
			}
			
			p_server->get_send_size() += dw_total + sizeof(DWORD) * 2; 
			p_server->get_compress_send_size() += st_param.dw_out_data_size + sizeof(DWORD);
		}
		WaitForSingleObject(p_server->get_event_send(), SLEEP_TIME);
		//added by mmz at 2010.9.21
		static DWORD dwCurTime = timeGetTime();
		static INT64 n64UpSendSize = p_server->get_compress_send_size();
		static INT64 n64EndSendSize = 0;
		if(timeGetTime() - dwCurTime >= 10*1000)
		{
			p_server->get_sec_send_size() = (n64EndSendSize-n64UpSendSize)/10;
			n64UpSendSize = p_server->get_compress_send_size();
			dwCurTime = timeGetTime();
		}
		else
		{
			n64EndSendSize = p_server->get_compress_send_size();
		}
	}
	
	SAFE_DELETE_ARRAY(p_buff);

	THROW_EXCEPTION_END

	_endthreadex(0);
	return 0;
}


//-----------------------------------------------------------------------------
// 创建未验证客户踢出线程
//-----------------------------------------------------------------------------
BOOL IOCP::create_unauth_heartbeat_thread()
{
	INT nReturn = _beginthreadex(NULL, 0, thread_unauth_hearbeat, this, 0, NULL);
	if( 0 == nReturn || -1 == nReturn )
	{
		ERROR_CLUE_ON(_T("[s]create heart beat to unauth client thread failed"));
		return FALSE;
	}

	v_thread_hanle.push_back((HANDLE)nReturn);
	return TRUE;
}


//-----------------------------------------------------------------------------
// 踢出未验证客户线程
//-----------------------------------------------------------------------------
UINT WINAPI thread_unauth_hearbeat(LPVOID p)
{
	THROW_EXCEPTION_START
	IOCP* p_server = (IOCP*)p;
	tag_net_client* p_client = NULL;

	while( !p_server->is_end_work_thread() )
	{
		if( p_server->get_list_unauth_client().size() > 0 )
		{
			DWORD dw_time = timeGetTime();
			p_server->get_list_unauth_client().lock();
			p_server->get_list_unauth_client().reset_iterator();
			while( p_server->get_list_unauth_client().peek(p_client) )
			{
				if( dw_time - p_client->dw_connect_time > p_server->get_config()->dw_auth_time_limit )
				{
					p_server->pre_destroy_client(p_client, NULL);
					p_server->get_list_unauth_client().erase_iterator();
					break;
				}
				p_server->get_list_unauth_client().add_iterator();
			}
			p_server->get_list_unauth_client().unlock();
		}
		
		Sleep(SLEEP_TIME);
	}
	THROW_EXCEPTION_END

	_endthreadex(0);
	return 0;
}


//-----------------------------------------------------------------------------
// 资源回收
//-----------------------------------------------------------------------------
VOID IOCP::pre_destroy_client(tag_net_client* p_client_, tag_unit* p_unit_)
{
	if( FALSE == Interlocked_Compare_Exchange((long*)(&p_client_->b_shut_down), TRUE, FALSE) )
	{
		shutdown(p_client_->sock, SD_BOTH);

		if( VALID_VALUE(p_client_->dw_session_id) )
			(st_config.fn_logout)(p_client_->dw_session_id);	// 调用登出回调函数
			
		list_destroy_client.pust_back(p_client_);
		SetEvent(h_event_destroy);

		closesocket(p_client_->sock);
	}

	if( p_unit_ )
	{
		if( ESS_Send == p_unit_->e_state )	
			Interlocked_Decrement(&p_client_->l_send_cast);
		else
			Interlocked_Decrement(&p_client_->l_recv_cast); 

		if( p_unit_->p_next )	
			p_unit_->p_next->p_memory_pool->free_memory(p_unit_->p_next);
		p_unit_->p_memory_pool->free_memory(p_unit_);
	}
}


//-----------------------------------------------------------------------------
// 创建回收资源处理线程
//-----------------------------------------------------------------------------
BOOL IOCP::create_destroy_thread()
{
	INT n_return = _beginthreadex(NULL, 0, thread_destroy, this, 0, NULL);
	if( 0 == n_return || -1 == n_return )
	{
		ERROR_CLUE_ON(_T("[s]create destroy client thread failed"));
		return FALSE;
	}

	v_thread_hanle.push_back((HANDLE)n_return);
	return TRUE;
}


//-----------------------------------------------------------------------------
// 回收资源线程
//-----------------------------------------------------------------------------
UINT WINAPI thread_destroy(LPVOID p)
{
	THROW_EXCEPTION_START
	IOCP* p_server = (IOCP*)p;
	tag_net_client*	p_client = NULL;

	while( !p_server->is_end_work_thread() )
	{
		if( !VALID_VALUE(p_client = p_server->get_list_destroy_client().pop_front()) )
		{
			WaitForSingleObject(p_server->get_event_destroy(), SLEEP_TIME);
			continue;
		}

		if( 0 == p_client->l_send_cast && 0 == p_client->l_recv_cast )
		{
			p_server->destroy_client(p_client);	// 真正清除并且回收
		}
		else
		{
			WaitForSingleObject(p_server->get_event_destroy(), SLEEP_TIME);
			p_server->get_list_destroy_client().pust_back(p_client);
		}
	}
	THROW_EXCEPTION_END

	_endthreadex(0);
	return 0;
}


//-----------------------------------------------------------------------------
// 资源回收
//-----------------------------------------------------------------------------
VOID IOCP::destroy_client(tag_net_client* p_client_)
{
	list_unauth_client.erase(p_client_);

	// 将我们收到的所有包都丢弃
	tag_unit* p_unit = NULL;
	while( p_unit = p_client_->p_recv_queue->get() )
		p_unit->p_memory_pool->free_memory(p_unit);

	tag_raw_unit* p_raw_unit = NULL;
	while( p_raw_unit = p_client_->p_send_queue->get() )
		p_raw_unit->p_memory_pool->free_memory(p_raw_unit);
	
	p_client_->b_shut_down = TRUE;
	p_client_->l_send_cast = 0;
	p_client_->l_recv_cast = 0;
	p_client_->dw_send_size = 0;
	p_client_->sock = INVALID_SOCKET;
	p_client_->dw_session_id = INVALID_VALUE;	
	p_client_->b_send = FALSE;
		
	list_free_client.pust_back(p_client_);
	
}

VOID IOCP::log_free_msg(DWORD dw_handle_, DWORD dw_Session_id)
{
	tag_net_client* p_client = (tag_net_client*)dw_handle_;
	if( !p_client->b_shut_down )
	{
		while(p_client->p_recv_queue->get_num())
		{
			tag_unit* p_unit = p_client->p_recv_queue->get();
			if( !p_unit )
				continue;

			tag_net_message* p_msg = (tag_net_message*)p_unit->p_buffer;

			get_log()->write_log(_T("session_id = %u, message_id=%u\r\n"), dw_Session_id, p_msg->dw_message_id);

			free_recv((LPBYTE)p_msg);
		}

		get_log()->write_log(_T("\r\n\r\n"));
	}
}


} // namespace networkbase {
