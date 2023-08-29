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
#include "few_connect_server.h"

// 使用其它部件
#include "..\serverframe\safe_message_queue.h"
#include "..\memory\safe_memory_pool.h"

namespace networkbase {

const INT RECV_BUFFER_SIZE = 2048;	

few_connect_server::few_connect_server()
{
	fn_login = NULL;
	fn_logout = NULL;
	InitializeCriticalSection(&disconnect_lock);
	p_memory_pool = new safe_memory_pool(4*1024*1024);	
}

few_connect_server::~few_connect_server()
{
	SAFE_DELETE(p_memory_pool);
	DeleteCriticalSection(&disconnect_lock);
}


//-----------------------------------------------------------------------------
// 初始化网络
//-----------------------------------------------------------------------------
BOOL few_connect_server::init(net_login_call_back fn_login_, net_logout_call_back fn_logout_, INT n_port_, 
							  BOOL b_repeat_use_port_/*=TRUE*/, BOOL b_package_mode_/*=TRUE*/)
{
	fn_login = fn_login_; 
	fn_logout = fn_logout_;
	b_package_mode = b_package_mode_;	

	::ZeroMemory(&st_thread_recv_param, sizeof(st_thread_recv_param));
	::ZeroMemory(&st_thread_io_recv_param, sizeof(st_thread_io_recv_param));
	::ZeroMemory(&st_thread_send_param, sizeof(st_thread_send_param));

	map_connect_client.clear();
	list_delete_client.clear();
	Interlocked_Exchange((LONG*)&b_end_accept, FALSE);
	Interlocked_Exchange((LONG*)&b_end_discnnect, FALSE);
	dw_send_msg_num = 0; 
	dw_recv_msg_num = 0;
	dw_send_total_byte = 0;
	dw_recv_total_byte = 0;

	n_port = n_port_;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(n_port);
	server_socket = socket(AF_INET, SOCK_STREAM, 0);	

	DWORD dw_argp = 1;
	INT n_ret = ioctlsocket( server_socket, FIONBIO, &dw_argp );	
	if( SOCKET_ERROR == n_ret )
	{
		ERROR_CLUE_ON(_T("set nonblocking mode failed in init server"));
		closesocket( server_socket );
		return FALSE;
	}
	
	linger st_lin;
	st_lin.l_onoff = 1;
	st_lin.l_linger = 0;
	setsockopt(server_socket, SOL_SOCKET, SO_LINGER, (char*)&st_lin, sizeof(st_lin));	

	if( b_repeat_use_port_ )
	{
		DWORD dwReUseAddr = TRUE;	
		setsockopt( server_socket, SOL_SOCKET, SO_REUSEADDR, 
			(char*)&dwReUseAddr, sizeof(dwReUseAddr) );
	}

	INT nAddresslen = sizeof(server_address);
	if( bind(server_socket, (sockaddr*)&server_address, nAddresslen) )	
	{
		ERROR_CLUE_ON(_T("bind error"));
		closesocket( server_socket );
		return FALSE;
	}
	else
	{
		listen( server_socket, 5 );	

		h_accept_thread = (HANDLE)_beginthreadex
			(NULL, 0, few_connect_thread_accept, this, 0, NULL);

		h_thread_disconnect = (HANDLE)_beginthreadex
			(NULL, 0, few_connect_thread_disconnect, this, 0, NULL);
	}

	return TRUE;
}

BOOL few_connect_server::destory()
{
	Interlocked_Exchange((LONG*)&b_end_accept, TRUE);
	WaitForSingleObject(h_accept_thread, INFINITE);
	SAFE_CLOSE_HANDLE(h_accept_thread);

	std::list<tag_client*> list_client;
	map_connect_client.copy_value_to_list(list_client);
	std::list<tag_client*>::iterator it;
	for(it=list_client.begin(); it!=list_client.end(); ++it)
		this->disconnect_client((*it));

	Interlocked_Exchange((LONG*)&b_end_discnnect, TRUE);
	WaitForSingleObject(h_thread_disconnect, INFINITE);
	SAFE_CLOSE_HANDLE(h_thread_disconnect);

	closesocket( server_socket );
	fn_login = NULL;
	fn_logout = NULL;

	return TRUE;
}


//-----------------------------------------------------------------------------
// 发送消息, 并发送消息队列数量
//-----------------------------------------------------------------------------
INT few_connect_server::send_msg(DWORD dw_client_id_, LPVOID p_msg_, DWORD dw_msg_size_)
{
	tag_client* p_client = map_connect_client.find(dw_client_id_);
	if( !VALID_POINT(p_client) )
		return INVALID_VALUE;

	p_client->p_send_msg_queue->add_message(p_msg_, dw_msg_size_);
	return p_client->p_send_msg_queue->get_message_num();
}


//-----------------------------------------------------------------------------
// 接收消息，n_recv_num_返回接收队列消息数量
//-----------------------------------------------------------------------------
BYTE* few_connect_server::recv_msg(DWORD dw_client_id_, DWORD& dw_msg_size_, INT& n_recv_queue_num)
{
	tag_client* p_client = map_connect_client.find(dw_client_id_);
	if( !VALID_POINT(p_client) )
		return NULL;

	n_recv_queue_num = p_client->p_recv_msg_queue->get_message_num();
	return p_client->p_recv_msg_queue->get_message(dw_msg_size_);
}


//-----------------------------------------------------------------------------
// 消息处理完成后，释放接收到的消息内存
//-----------------------------------------------------------------------------
VOID few_connect_server::free_recv_msg(DWORD dw_client_id_, BYTE* p_free_msg_) 
{
	tag_client* p_client = map_connect_client.find(dw_client_id_);
	if( !VALID_POINT(p_client) )
		return;

	p_client->p_recv_msg_queue->free_message(p_free_msg_);
}



//-----------------------------------------------------------------------------
// 踢出连线
//-----------------------------------------------------------------------------
BOOL few_connect_server::kick_connect(DWORD dw_client_id_)
{
	tag_client* p_client = map_connect_client.find(dw_client_id_);
	if( !VALID_POINT(p_client) )
		return FALSE;

	this->disconnect_client(p_client);
	return TRUE;
}


//-----------------------------------------------------------------------------
// 获得客户端sock名称
//-----------------------------------------------------------------------------
BOOL few_connect_server::get_client_sock_name(sockaddr_in* p_sockaddr_in_, DWORD dw_client_id_)
{
	tag_client* p_client = map_connect_client.find(dw_client_id_);
	if( !VALID_POINT(p_client) )
		return FALSE;

	INT nLen = (INT)sizeof(sockaddr_in);
	if( 0 == getpeername(p_client->socket, (sockaddr*)p_sockaddr_in_, &nLen) )
		return TRUE;
	else
		return FALSE;
}

UINT win_api few_connect_thread_accept(void* p)
{
	few_connect_server* p_server = (few_connect_server*)p;
	fd_set fdread;
	timeval block_time;
	block_time.tv_sec = 0;
	block_time.tv_usec = 1000*200;	
	INT nAddlen = sizeof(p_server->get_sockadd_in());
	
	while( !p_server->is_end_accept() )
	{
		FD_ZERO(&fdread);	
		FD_SET(p_server->get_socket(), &fdread);
		if( select(0, &fdread, NULL, NULL, &block_time) == 1 )	
		{
			tag_client* p_client = new tag_client;
			if( NULL == p_client )
				continue;

			p_client->socket	= accept( p_server->get_socket(), (sockaddr*)&(p_server->get_sockadd_in()), &nAddlen);
			if( p_client->socket == INVALID_SOCKET )
			{	
				delete(p_client);
				continue;
			}

			p_client->p_send_msg_queue = new safe_message_queue(TRUE, p_server->get_mode());
			p_client->p_recv_msg_queue = new safe_message_queue(FALSE, FALSE);
			if( NULL == p_client->p_send_msg_queue || NULL == p_client->p_recv_msg_queue )
			{
				SAFE_DELETE(p_client->p_send_msg_queue);
				SAFE_DELETE(p_client->p_recv_msg_queue);
				closesocket(p_client->socket);
				delete(p_client);
				continue;
			}

			p_client->dw_connect_time = timeGetTime();	

			if( p_server->get_mode() )
			{
				p_server->get_thread_recv_param().p_client = p_client;
				p_server->get_thread_recv_param().p_server = p_server;
				p_client->h_recv_thread = (HANDLE)_beginthreadex
					(NULL, 0, few_connect_thread_recv, &(p_server->get_thread_recv_param()), 0, NULL);
			}
			else
			{
				DWORD dw_client_id = (p_server->get_fn_login())(0, 0);
				if( INVALID_VALUE == dw_client_id )
				{
					SAFE_DELETE(p_client->p_send_msg_queue);
					SAFE_DELETE(p_client->p_recv_msg_queue);
					closesocket(p_client->socket);
					delete(p_client);
					continue;
				}

				p_client->dw_id = dw_client_id;
				p_server->get_client_map().add(dw_client_id, p_client);

				p_server->get_thread_io_recv_param().p_server = p_server;
				p_server->get_thread_io_recv_param().p_client = p_client;

				p_client->h_recv_thread = (HANDLE)_beginthreadex
					(NULL, 0, few_connect_thread_io_recv, &(p_server->get_thread_io_recv_param()), 0, NULL);
			}

			p_server->get_thread_send_param().p_server = p_server;
			p_server->get_thread_send_param().p_client = p_client;

			p_client->h_send_thread = (HANDLE)_beginthreadex
				(NULL, 0, few_connect_thread_send, &(p_server->get_thread_send_param()), 0, NULL);
		}
	}
	
	_endthreadex(0);
	return 0;
}

UINT win_api few_connect_thread_disconnect(void* p)
{
	few_connect_server* p_server = (few_connect_server*)p;

	while( !p_server->is_end_disconnect() || p_server->get_delete_client_list().size() > 0 )
	{
		tag_client* p_client = p_server->get_delete_client_list().pop_front();
		if( !VALID_POINT(p_client) )
		{
			Sleep(200);
			continue;
		}

		WaitForSingleObject(p_client->h_recv_thread, INFINITE);
		SAFE_CLOSE_HANDLE(p_client->h_recv_thread);

		WaitForSingleObject(p_client->h_send_thread, INFINITE);
		SAFE_CLOSE_HANDLE(p_client->h_send_thread);

		SAFE_DELETE(p_client->p_recv_msg_queue);
		SAFE_DELETE(p_client->p_send_msg_queue);

		closesocket(p_client->socket);
		delete(p_client);
	}

	_endthreadex(0);
	return 0;
}

UINT win_api few_connect_thread_send(void* p)
{

	tag_thread_param* p_st_thread_recv_param = (tag_thread_param*)p;
	tag_client* p_client = p_st_thread_recv_param->p_client;
	few_connect_server* p_server = p_st_thread_recv_param->p_server;

	fd_set fdwrite;
	timeval block_time;
	block_time.tv_sec = 0;
	block_time.tv_usec = 1000*200;	

	LPBYTE	p_msg = NULL, p_temp = NULL;
	DWORD	dw_msg_size = 0;
	INT		n_ret = 0;

	while( FALSE == p_client->b_end )
	{
		for(;;)	
		{
			p_temp = p_msg = p_client->p_send_msg_queue->get_message(dw_msg_size);
			if( NULL == p_msg )
				break;	

			while( dw_msg_size > 0 && !p_client->b_end )
			{
				n_ret = send(p_client->socket, (char*)p_temp, dw_msg_size, 0);
				if( SOCKET_ERROR == n_ret )
				{
					switch(WSAGetLastError())
					{
					case WSAEWOULDBLOCK:
					case WSAENOBUFS:
						FD_ZERO(&fdwrite);
						FD_SET(p_client->socket, &fdwrite);
						select(0, NULL, &fdwrite, NULL, &block_time);
						break;

					default:
						p_client->p_send_msg_queue->free_message(p_msg);
						goto __thread_send_end;
						break;
					}
				}
				else
				{
					p_temp += n_ret;
					dw_msg_size -= n_ret;
					p_server->get_send_msg_total_bytes() += n_ret;
				}
			}

			p_client->p_send_msg_queue->free_message(p_msg);
			p_temp = p_msg = NULL;
			p_server->get_send_msg_total_num()++;
		}

		::WaitForSingleObject(p_client->p_send_msg_queue->get_event(), 200);
	}

__thread_send_end:
	p_server->disconnect_client(p_client);
	_endthreadex(0);
	return 0;
}

UINT win_api few_connect_thread_recv(void* p)
{
	tag_thread_param* p_st_thread_recv_param = (tag_thread_param*)p;
	tag_client* p_client = p_st_thread_recv_param->p_client;
	few_connect_server* p_server = p_st_thread_recv_param->p_server;

	fd_set fdread;
	timeval block_time;	
	block_time.tv_sec = 0;
	block_time.tv_usec = 1000*200;	

	INT n_ret = 0;
	DWORD dw_msg_size = 0;
	DWORD dw_temp_size = 0;
	CHAR* p_temp = NULL;

	while( FALSE == p_client->b_end )
	{
		dw_temp_size = sizeof(DWORD);
		p_temp = (char*)&dw_msg_size;

		while( dw_temp_size > 0 )
		{
			FD_ZERO(&fdread);
			FD_SET(p_client->socket, &fdread);
			if( 1 == select(0, &fdread, NULL, NULL, &block_time) )
			{
				n_ret = recv(p_client->socket, p_temp, dw_temp_size, 0);
				if( 0 == n_ret || SOCKET_ERROR == n_ret )
					goto __thread_recv_end;

				dw_temp_size -= n_ret;
				p_temp += n_ret;
				p_server->get_recv_msg_total_bytes() += n_ret;
			}

			if( p_client->b_end )
				goto __thread_recv_end;

			if( 0 == p_client->n_recv_package_num && timeGetTime() - p_client->dw_connect_time > 1000 * 60 * 3 )
				goto __thread_recv_end;	
		}

		if( SOCKET_ERROR != n_ret )
		{
			char* p_temp_ = (char*)p_server->get_safe_mem_pool()->alloc_memory(dw_msg_size);
			dw_temp_size = dw_msg_size;
			p_temp = p_temp_;
			while( dw_temp_size > 0 )
			{
				FD_ZERO(&fdread);
				FD_SET(p_client->socket, &fdread);
				if( 1 == select(0, &fdread, NULL, NULL, &block_time) )
				{
					n_ret = recv(p_client->socket, p_temp, dw_temp_size, 0);
					if( 0 == n_ret || n_ret == SOCKET_ERROR )	
					{
						p_server->get_safe_mem_pool()->free_memory(p_temp_);
						goto __thread_recv_end;
					}

					dw_temp_size -= n_ret;
					p_temp += n_ret;
					p_server->get_recv_msg_total_bytes() += n_ret;
				}

				if( 0 == p_client->n_recv_package_num && timeGetTime() - p_client->dw_connect_time > 1000 * 60 * 3 )
					goto __thread_recv_end; 

				if( p_client->b_end )
					goto __thread_recv_end;
			}

			p_client->p_recv_msg_queue->add_message(p_temp_, dw_msg_size);
			p_client->n_recv_package_num++;
			if( 1 == p_client->n_recv_package_num )
			{
				DWORD dw_client_id = (p_server->get_fn_login())((LPBYTE)p_temp_, dw_msg_size);
				if( INVALID_VALUE == dw_client_id )
				{
					p_server->get_safe_mem_pool()->free_memory(p_temp_);
					goto __thread_recv_end;
				}

				p_client->dw_id = dw_client_id;
				p_server->get_client_map().add(dw_client_id, p_client);
			}

			p_server->get_recv_msg_total_num()++;
			p_server->get_safe_mem_pool()->free_memory(p_temp_);
		}
	}



__thread_recv_end:
	p_server->disconnect_client(p_client);
	_endthreadex(0);
	return 0;
}

UINT win_api few_connect_thread_io_recv(void* p)
{
	tag_thread_param* p_st_thread_recv_param = (tag_thread_param*)p;
	tag_client* p_client = p_st_thread_recv_param->p_client;
	few_connect_server* p_server = p_st_thread_recv_param->p_server;


	fd_set fdread;
	timeval block_time;	
	block_time.tv_sec = 0;
	block_time.tv_usec = 1000*200;	

	INT n_ret = 0;
	BYTE* p_buffer = (LPBYTE)p_server->get_safe_mem_pool()->alloc_memory(RECV_BUFFER_SIZE);

	while( FALSE == p_client->b_end )
	{
		FD_ZERO(&fdread);
		FD_SET(p_client->socket, &fdread);
		if( 1 == select(0, &fdread, NULL, NULL, &block_time) )
		{
			n_ret = recv(p_client->socket, (CHAR*)p_buffer, RECV_BUFFER_SIZE, 0);
			if( 0 == n_ret || n_ret == SOCKET_ERROR )	
			{
				goto __thread_stream_recv_end;
			}

			p_server->get_recv_msg_total_bytes() += n_ret;
			p_client->p_recv_msg_queue->add_message(p_buffer, n_ret);
			++p_client->n_recv_package_num;
			p_server->get_recv_msg_total_num()++;
		}

		if( p_client->b_end )
		{
			goto __thread_stream_recv_end;
		}
	}

__thread_stream_recv_end:
	p_server->get_safe_mem_pool()->free_memory(p_buffer);
	p_server->disconnect_client(p_client);
	_endthreadex(0);
	return 0;
}

VOID few_connect_server::disconnect_client(tag_client* p_client_)
{
	EnterCriticalSection(&disconnect_lock);
	if( p_client_->b_end )
	{
		LeaveCriticalSection(&disconnect_lock);
		return;
	}

	if( fn_logout && VALID_VALUE(p_client_->dw_id) )	
		(fn_logout)(p_client_->dw_id);	

	shutdown(p_client_->socket, SD_SEND);
	Interlocked_Exchange((LONG*)&p_client_->b_end, TRUE);
	map_connect_client.erase(p_client_->dw_id);

	LeaveCriticalSection(&disconnect_lock);

	list_delete_client.push_back(p_client_);
}

} // namespace networkbase {