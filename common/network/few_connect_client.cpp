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
#include "few_connect_client.h"


#include "..\serverframe\safe_message_queue.h"
#include "..\memory\memory_pool.h"

#define CAL_TIME			1000
#define MEM_BUFFER			512*1024


namespace networkbase {

few_connect_client::few_connect_client()
{
	b_package_head = FALSE;	
	clear();
	p_memory_pool = new MemPool(MEM_BUFFER);
}

few_connect_client::~few_connect_client()
{
	this->destory();
	SAFE_DELETE(p_memory_pool);
}

VOID few_connect_client::clear()
{
	p_send_msg_queue = NULL;
	p_recv_msg_queue = NULL;

	str_ip.clear();
	n_port = 0;
	n_socket = 0;
	b_nagle = TRUE;

	h_connect_thread = 0;
	h_send_thread = 0;
	h_recv_thread = 0;

	::Interlocked_Exchange((LONG*)&b_end_connect, FALSE);
	::Interlocked_Exchange((LONG*)&b_end_send, FALSE);
	::Interlocked_Exchange((LONG*)&b_end_recv, FALSE);
	::Interlocked_Exchange((LONG*)&b_connected, FALSE);

}


BOOL few_connect_client::init(BOOL b_nagle_/*=TRUE*/, E_few_connect_client_mode e_mode_/*=EFCCM_Package*/)
{
	this->clear();

	b_nagle = b_nagle_;
	e_trans_mode = e_mode_;
	
	if( EFCCM_Package == e_trans_mode )
		p_send_msg_queue = new safe_message_queue(TRUE, TRUE);
	else
		p_send_msg_queue = new safe_message_queue(TRUE, FALSE);

	p_recv_msg_queue = new safe_message_queue(FALSE, FALSE);
	if( NULL == p_send_msg_queue || NULL == p_recv_msg_queue )
	{
		SAFE_DELETE(p_send_msg_queue);
		SAFE_DELETE(p_recv_msg_queue);
		return FALSE;
	}

	n_socket = socket(AF_INET, SOCK_STREAM, 0);
	if( INVALID_SOCKET == n_socket )
	{
		print_message(_T("could not create socket\r\n"));
		SAFE_DELETE(p_send_msg_queue);
		SAFE_DELETE(p_recv_msg_queue);
		return FALSE;
	}

	DWORD dw_cmd = 1;
	INT n_result = ioctlsocket( n_socket, FIONBIO, &dw_cmd );
	if( SOCKET_ERROR == n_result )
	{
		print_message(_T("set nonblocking mode failed in init client\r\n"));
		closesocket( n_socket );
		n_socket = 0;
		SAFE_DELETE(p_send_msg_queue);
		SAFE_DELETE(p_recv_msg_queue);
		return FALSE;
	}

	if( !b_nagle )
	{
		BOOL b_no_delay = TRUE;
		setsockopt(n_socket, IPPROTO_TCP, TCP_NODELAY, (char*)&b_no_delay, sizeof(b_no_delay));
	}

	DWORD dw_result_useaddr = TRUE;
	setsockopt( n_socket, SOL_SOCKET, SO_REUSEADDR, 
		(char*)&dw_result_useaddr, sizeof(dw_result_useaddr) );

	linger lin;
	lin.l_linger = 0;
	lin.l_onoff = 1;
	setsockopt( n_socket, SOL_SOCKET, SO_LINGER, (char*)&lin, sizeof(lin) );

	dw_last_out_cps_time = timeGetTime();
	dw_last_in_cps_time = timeGetTime();
	dw_send_byte = 0;
	dw_recv_byte = 0;
	dw_sent_byte_count = 0;
	dw_recv_byte_count = 0;

	dw_send_total_num = 0;
	dw_recv_total_num = 0;

	return TRUE;
}

void few_connect_client::destory()
{
	::Interlocked_Exchange((LONG*)&b_end_connect, TRUE);
	::Interlocked_Exchange((LONG*)&b_end_send, TRUE);
	::Interlocked_Exchange((LONG*)&b_end_recv, TRUE);

	blandness_close_threak(h_connect_thread, INFINITE);
	blandness_close_threak(h_send_thread, INFINITE);
	blandness_close_threak(h_recv_thread, INFINITE);

	if( TRUE == b_connected )
	{
		blandness_close_socket(n_socket, 20);
	}
	else
	{
		shutdown(n_socket, SD_SEND);
		closesocket(n_socket);
		n_socket = 0;
	}

	::Interlocked_Exchange((LONG*)&b_connected, FALSE);
	SAFE_DELETE( p_send_msg_queue );
	SAFE_DELETE( p_recv_msg_queue );
}

BOOL few_connect_client::blandness_close_socket(SOCKET& n_socket_, INT n_repeat_time_)
{
	if( 0 == n_socket_ )
		return TRUE;

	shutdown(n_socket_, SD_SEND);
	
	INT n_retry = 0;
	fd_set fdread;
	timeval block_time;	
	block_time.tv_sec = 0;
	block_time.tv_usec = SELECT_BLOCK_TIME;	
	
	while( n_retry++ < n_repeat_time_ )
	{
		FD_ZERO(&fdread);
		FD_SET(n_socket_, &fdread);
		if( 1 == select(0, &fdread, NULL, NULL, &block_time) )
		{
			CHAR chTemp;
			INT nResult = recv(n_socket_, &chTemp, 1, 0);
			if( 0 == nResult )	
			{
				closesocket( n_socket_ );
				n_socket_ = 0;
				return TRUE;
			}
			
			if( SOCKET_ERROR == nResult )	
				break;
		}
	}
	

	closesocket( n_socket_ );
	n_socket_ = 0;
	return FALSE;
}

BOOL few_connect_client::blandness_close_threak(HANDLE& h_thread_, INT n_repeat_time_)
{
	if( 0 == h_thread_ )
		return TRUE;

	DWORD dw_result = WaitForSingleObject(h_thread_, n_repeat_time_);
	SAFE_CLOSE_HANDLE(h_thread_);
	h_thread_ = 0;

	if( WAIT_TIMEOUT == dw_result )
		return FALSE;
	else
		return TRUE;
}


BOOL few_connect_client::send_msg(LPVOID p_msg_, DWORD dw_msg_size_)
{
	ASSERT(NULL != p_msg_);
	ASSERT(dw_msg_size_ > 0 && dw_msg_size_ < 0xFFFFFF);	
	
	if( FALSE == b_connected )
		return FALSE;

	dw_send_total_num++;
	return p_send_msg_queue->add_message((LPBYTE)p_msg_, dw_msg_size_);
}

LPBYTE few_connect_client::recv_msg(DWORD& dw_msg_size_)
{
	if( !VALID_POINT(p_recv_msg_queue) )
		return NULL;

	return p_recv_msg_queue->get_message(dw_msg_size_);
}

VOID few_connect_client::free_recv_msg(LPBYTE p_message)
{
	if( p_recv_msg_queue )
		p_recv_msg_queue->free_message(p_message);
}

BOOL few_connect_client::set_packagehead_byte(BOOL b_head_)
{
	if( EFCCM_Package != e_trans_mode )
		return FALSE;

	b_package_head = b_head_;
	return TRUE;
}


VOID few_connect_client::try_create_connect(LPCSTR sz_ip_, INT n_port_/*=0*/)
{
	this->disconnect();
	
	str_ip = sz_ip_;
	n_port = n_port_;

	h_connect_thread = (HANDLE)_beginthreadex(NULL, 0, thread_connect, this, 0, NULL);
}

BOOL few_connect_client::is_trying_create_connect()
{
	if( !h_connect_thread )
		return FALSE;

	DWORD dw_connect_exit_code = STILL_ACTIVE;
	GetExitCodeThread(h_connect_thread, &dw_connect_exit_code);
	if( STILL_ACTIVE == dw_connect_exit_code )
		return TRUE;
	else
		return FALSE;
}

VOID few_connect_client::abandon_trying_connect()
{
	this->destory();
	this->init(b_nagle, e_trans_mode);
}

VOID few_connect_client::disconnect()
{
	this->abandon_trying_connect();
}

INT	few_connect_client::get_nosend_package_num()
{
	if( !b_connected )
		return 0;

	return p_send_msg_queue->get_message_num();
}

INT	few_connect_client::get_recv_package_num()
{
	if( !b_connected )
		return 0;

	return p_recv_msg_queue->get_message_num();
}

UINT win_api thread_connect(void* p)
{
	few_connect_client* p_few_connect_client = (few_connect_client*)p;
	INT n_result = 0;
	sockaddr_in address;
	ZeroMemory(&address, sizeof(address));
	address.sin_addr.s_addr = inet_addr(p_few_connect_client->get_ip_string().c_str());
	address.sin_family = AF_INET;
	address.sin_port = htons(p_few_connect_client->get_port());

	if( INADDR_NONE == address.sin_addr.s_addr )
	{
		print_message(_T("[c] invalid IP\r\n"));
		goto __connected_terminated;
	}
	
	fd_set fdwrite;
	timeval block_time;	
	block_time.tv_sec = 0;
	block_time.tv_usec = SELECT_BLOCK_TIME;
	
	n_result = connect(p_few_connect_client->get_socket(), (sockaddr*)&(address), sizeof(address));
	if( SOCKET_ERROR == n_result )
	{	
		if( WSAEWOULDBLOCK == WSAGetLastError() )
		{
			for(INT n=0; n<64; n++) 
			{
				FD_ZERO(&fdwrite);
				FD_SET(p_few_connect_client->get_socket(), &fdwrite);

				if( 1 == select(0, NULL, &fdwrite, NULL, &block_time) )
					goto __connected;

				if( p_few_connect_client->is_end_connect() )
					goto __connected_terminated;
			}
		}

		goto __connected_terminated;
	}
	
__connected:

	p_few_connect_client->get_send_total_num() = 0;
	p_few_connect_client->get_recv_total_num() = 0; 

	p_few_connect_client->get_send_thread() = (HANDLE)_beginthreadex(NULL, 0, thread_send, p_few_connect_client, 0, NULL);

	switch( p_few_connect_client->get_trans_mode() )
	{
	case EFCCM_Package:
		p_few_connect_client->get_recv_thread() = (HANDLE)_beginthreadex(NULL, 0, thread_package_recv, p_few_connect_client, 0, NULL);
		break;
	case EFCCM_Stream:
	case EFCCM_Text:
		p_few_connect_client->get_recv_thread() = (HANDLE)_beginthreadex(NULL, 0, thread_text_recv, p_few_connect_client, 0, NULL);
		break;
	}

	::Interlocked_Exchange((LONG*)&p_few_connect_client->is_connected(), TRUE);
	_endthreadex(0);
	return 0;

__connected_terminated:
		
	::Interlocked_Exchange((LONG*)&p_few_connect_client->is_connected(), FALSE);
	_endthreadex(0);
	return 0;
}

UINT win_api thread_send(void* p)
{
	few_connect_client* p_few_connect_client = (few_connect_client*)p;
	fd_set fdwrite;
	timeval block_time;	
	block_time.tv_sec = 0;
	block_time.tv_usec = SELECT_BLOCK_TIME;	

	LPBYTE	p_msg = NULL, p_temp = NULL;
	DWORD	dw_msg_size = 0;
	INT		n_return = 0;

	while( FALSE == p_few_connect_client->is_end_send() )
	{
		for(;;)	
		{
			DWORD dw_time = timeGetTime();
			if( dw_time - p_few_connect_client->get_last_out_cps_time() >= CAL_TIME ) 
			{
				p_few_connect_client->get_last_out_cps_time() = dw_time;
				p_few_connect_client->get_send_byte() = p_few_connect_client->get_send_byte_count();
				p_few_connect_client->get_send_byte_count() = 0;
			}

			p_temp = p_msg = p_few_connect_client->get_send_msg_queue()->get_message(dw_msg_size);
			if( NULL == p_msg )
				break;	

			if( p_few_connect_client->is_package_head() )	
				*(u_long*)p_msg = htonl(*(u_long*)p_msg);

			while( dw_msg_size > 0 && FALSE == p_few_connect_client->is_end_send() )
			{
				n_return = send(p_few_connect_client->get_socket(), (char*)p_temp, dw_msg_size, 0);
				if( SOCKET_ERROR == n_return )
				{
					switch(WSAGetLastError())
					{
					case WSAEWOULDBLOCK:
					case WSAENOBUFS:
						FD_ZERO(&fdwrite);
						FD_SET(p_few_connect_client->get_socket(), &fdwrite);
						select(0, NULL, &fdwrite, NULL, &block_time);
						break;

					default:	
						shutdown(p_few_connect_client->get_socket(), SD_SEND);
						p_few_connect_client->get_send_msg_queue()->free_message(p_msg);
						goto __thread_send_end;
					}
				}
				else
				{
					p_temp += n_return;
					dw_msg_size -= n_return;
					p_few_connect_client->get_send_byte_count() += n_return;	
				}
			}

			p_few_connect_client->get_send_msg_queue()->free_message(p_msg);
			p_temp = p_msg = NULL;
		}

		::WaitForSingleObject(p_few_connect_client->get_send_msg_queue()->get_event(), 120);
	}


__thread_send_end:
	::Interlocked_Exchange((LONG*)&p_few_connect_client->is_connected(), FALSE);
	_endthreadex(0);
	return 0;
}

UINT win_api thread_package_recv(void* p)
{
	few_connect_client* p_few_connect_client = (few_connect_client*)p;
	fd_set fdread;
	timeval block_time;	
	block_time.tv_sec = 0;
	block_time.tv_usec = SELECT_BLOCK_TIME;

	INT n_result = 0;
	DWORD dw_msg_size = 0;
	DWORD dw_temp_size = 0;
	CHAR* p_temp = NULL;

	while( FALSE == p_few_connect_client->is_end_recv() )
	{
		dw_temp_size = sizeof(DWORD);
		p_temp = (char*)&dw_msg_size;

		DWORD dw_time = timeGetTime();
		if( dw_time - p_few_connect_client->get_last_in_cps_time() >= CAL_TIME )
		{
			p_few_connect_client->get_last_in_cps_time() = dw_time;
			p_few_connect_client->get_in_cps() = p_few_connect_client->get_recv_byte_count();
			p_few_connect_client->get_recv_byte_count() = 0;
		}

		while( dw_temp_size > 0 )
		{
			FD_ZERO(&fdread);
			FD_SET(p_few_connect_client->get_socket(), &fdread);
			if( 1 == select(0, &fdread, NULL, NULL, &block_time) )
			{
				n_result = recv( p_few_connect_client->get_socket(), p_temp, dw_temp_size, 0);
				if( 0 == n_result )	
					goto __thread_receive_end;

				if( SOCKET_ERROR == n_result )
				{
					shutdown(p_few_connect_client->get_socket(), SD_SEND);
					goto __thread_receive_end;
				}
				else
				{
					dw_temp_size -= n_result;
					p_temp += n_result;

					p_few_connect_client->get_recv_byte_count() += n_result;
				}
			}
			
			if( p_few_connect_client->is_end_recv() )
				goto __thread_receive_end;
		}

		if( p_few_connect_client->is_package_head() )	
			dw_msg_size = ntohl(dw_msg_size);

		if( SOCKET_ERROR != n_result )
		{
			char* pTemp = (char*)p_few_connect_client->get_memory_pool()->alloc_memory(dw_msg_size);
			dw_temp_size = dw_msg_size;
			p_temp = pTemp;
			while( dw_temp_size > 0 )
			{
				FD_ZERO(&fdread);
				FD_SET(p_few_connect_client->get_socket(), &fdread);
				if( 1 == select(0, &fdread, NULL, NULL, &block_time) )
				{
					n_result = recv(p_few_connect_client->get_socket(), p_temp, dw_temp_size, 0);
					if( 0 == n_result )	
					{
						p_few_connect_client->get_memory_pool()->free_memory(pTemp);
						goto __thread_receive_end;
					}

					if( n_result == SOCKET_ERROR )
					{
						shutdown(p_few_connect_client->get_socket(), SD_SEND);
						p_few_connect_client->get_memory_pool()->free_memory(pTemp);
						goto __thread_receive_end;
					}
					else
					{
						dw_temp_size -= n_result;
						p_temp += n_result;

						p_few_connect_client->get_recv_byte_count() += n_result;
					}
					
					if( p_few_connect_client->is_end_recv() )
					{
						p_few_connect_client->get_memory_pool()->free_memory(pTemp);
						goto __thread_receive_end;
					}
				}
			}
			
			p_few_connect_client->get_recv_total_num()++; 
			p_few_connect_client->get_recv_msg_queue()->add_message(pTemp, dw_msg_size);
			p_few_connect_client->get_memory_pool()->free_memory(pTemp);
		}
	}

__thread_receive_end:
	::Interlocked_Exchange((LONG*)&p_few_connect_client->is_connected(), FALSE);
	_endthreadex(0);
	return 0;
}

UINT win_api thread_text_recv(void* p)
{
	few_connect_client* p_few_connect_client = (few_connect_client*)p;
	fd_set fdread;
	timeval block_time;	
	block_time.tv_sec = 0;
	block_time.tv_usec = SELECT_BLOCK_TIME;

	CONST INT n_recv_buffer_size = 2048;
	INT n_result = 0;
	LPBYTE p_buffer = (LPBYTE)p_few_connect_client->get_memory_pool()->alloc_memory(n_recv_buffer_size);

	while( FALSE == p_few_connect_client->is_end_recv() )
	{
		DWORD dw_time = timeGetTime();
		if( dw_time - p_few_connect_client->get_last_in_cps_time() >= CAL_TIME )	
		{
			p_few_connect_client->get_last_in_cps_time() = dw_time;
			p_few_connect_client->get_in_cps() = p_few_connect_client->get_recv_byte_count();
			p_few_connect_client->get_recv_byte_count() = 0;
		}

		if( EFCCM_Stream == p_few_connect_client->get_trans_mode() )
		{
			FD_ZERO(&fdread);
			FD_SET(p_few_connect_client->get_socket(), &fdread);
			if( 1 == select(0, &fdread, NULL, NULL, &block_time) )
			{
				n_result = recv(p_few_connect_client->get_socket(), (CHAR*)p_buffer, n_recv_buffer_size, 0);
				if( 0 == n_result )	
					goto __thread_stream_receive_end;

				if( n_result == SOCKET_ERROR )	
				{
					shutdown(p_few_connect_client->get_socket(), SD_SEND);
					goto __thread_stream_receive_end;
				}
				else
				{
					p_few_connect_client->get_recv_byte_count() += n_result;	
					p_few_connect_client->get_recv_total_num()++;	
					p_few_connect_client->get_recv_msg_queue()->add_message(p_buffer, n_result);	
				}
			}
		}
		else if( EFCCM_Text == p_few_connect_client->get_trans_mode() )	
		{
			CHAR* p_temp = (CHAR*)p_buffer;
			DWORD dw_msg_size = 0;
			while( FALSE == p_few_connect_client->is_end_recv() )
			{
				FD_ZERO(&fdread);
				FD_SET(p_few_connect_client->get_socket(), &fdread);
				if( 1 == select(0, &fdread, NULL, NULL, &block_time) )
				{
					n_result = recv(p_few_connect_client->get_socket(), p_temp, 1, 0);	
					if( 0 == n_result )	
						goto __thread_stream_receive_end;

					if( n_result == SOCKET_ERROR )	
					{
						shutdown(p_few_connect_client->get_socket(), SD_SEND);
						goto __thread_stream_receive_end;
					}
					else
					{
						dw_msg_size += n_result;
						if( *p_temp == '\n' || dw_msg_size >= n_recv_buffer_size )
						{
							p_few_connect_client->get_recv_total_num()++; 
							p_few_connect_client->get_recv_msg_queue()->add_message(p_buffer, dw_msg_size);
							break;
						}

						p_few_connect_client->get_recv_byte_count() += n_result;
						p_temp += n_result;
					}
				}
				else
				{
					if( dw_msg_size == 0 )
						break;
				}
			}
		}


	}

__thread_stream_receive_end:
	p_few_connect_client->get_memory_pool()->free_memory(p_buffer);
	::Interlocked_Exchange((LONG*)&p_few_connect_client->is_connected(), FALSE);
	_endthreadex(0);
	return 0;
}

BOOL few_connect_client::trans_mode(E_few_connect_client_mode e_mode_)
{
	if( EFCCM_Package == e_trans_mode || EFCCM_Package == e_mode_ )
		return FALSE;

	e_trans_mode = e_mode_;
	return TRUE;

}

BOOL few_connect_client::get_host_name(std::string& str_name_)
{
	CHAR szHostName[LONG_STRING];
	INT nResult = gethostname(szHostName, sizeof(szHostName)-10);
	if( 0 == nResult )
	{
		str_name_ = szHostName;
		return TRUE;
	}

	return FALSE;
}

BOOL few_connect_client::get_ip_by_host_name(DWORD& dw_ip_, LPCSTR p_host_name_)
{
	ASSERT(p_host_name_);
	hostent* p = gethostbyname(p_host_name_);
	if( p )
	{
		INT n=0;
		while((DWORD*)p->h_addr_list[n])
		{
			dw_ip_ = *((DWORD*)p->h_addr_list[n]);
			n++;
		}
		return TRUE;
	}
	else
		return FALSE;
}

BOOL few_connect_client::get_local_lan_ip(DWORD& dw_ip_)
{
    SOCKET sd = WSASocket(AF_INET, SOCK_DGRAM, 0, 0, 0, 0);
    if( sd == SOCKET_ERROR )
	{
        print_message(_T("failed to get a socket.\r\n"));
		return FALSE;
    }

    INTERFACE_INFO st_interface_list[128];
    DWORD dw_bytes_return;
    if( SOCKET_ERROR == WSAIoctl(sd, SIO_GET_INTERFACE_LIST, 0, 0, 
		&st_interface_list,	sizeof(st_interface_list), &dw_bytes_return, 0, 0) ) 
	{
        print_message(_T("failed calling WSAIoctl\r\n"));
		closesocket(sd);
		return FALSE;
    }

	closesocket(sd);

	INT n_interface_num = dw_bytes_return / sizeof(INTERFACE_INFO);
    for( INT i = 0; i < n_interface_num; ++i) 
	{
		u_long n_flag = st_interface_list[i].iiFlags;
		if( !(n_flag & IFF_UP) )	// 必须可用
			continue;

		//if( nFlags & IFF_LOOPBACK ) // 不能是 loopback
		//	continue;

        sockaddr_in *p_address;
        p_address = (sockaddr_in *) & (st_interface_list[i].iiAddress);
        dw_ip_ = p_address->sin_addr.S_un.S_addr;

		if( p_address->sin_addr.S_un.S_un_b.s_b1 == 10 
			|| (p_address->sin_addr.S_un.S_un_b.s_b1 == 172 && p_address->sin_addr.S_un.S_un_b.s_b2 >= 16 && p_address->sin_addr.S_un.S_un_b.s_b2 <= 31)
			|| (p_address->sin_addr.S_un.S_un_b.s_b1 == 192 && p_address->sin_addr.S_un.S_un_b.s_b2 == 168) )
			return TRUE;
    }

	return FALSE;
}

BOOL few_connect_client::get_local_wan_ip(DWORD& dw_ip_)
{
    SOCKET sd = WSASocket(AF_INET, SOCK_DGRAM, 0, 0, 0, 0);
    if( sd == SOCKET_ERROR )
	{
        print_message(_T("failed to get a socket.\r\n"));
		return FALSE;
    }

    INTERFACE_INFO st_interface_list[128];
    DWORD dw_byte_return;
    if( SOCKET_ERROR == WSAIoctl(sd, SIO_GET_INTERFACE_LIST, 0, 0, 
		&st_interface_list,	sizeof(st_interface_list), &dw_byte_return, 0, 0) ) 
	{
        print_message(_T("failed calling WSAIoctl\r\n"));
		closesocket(sd);
		return FALSE;
    }

	closesocket(sd);

	INT n_interface_num = dw_byte_return / sizeof(INTERFACE_INFO);
    for( INT i = 0; i < n_interface_num; ++i) 
	{
		u_long n_flag = st_interface_list[i].iiFlags;
		if( !(n_flag & IFF_UP) )	
			continue;

		if( n_flag & IFF_LOOPBACK ) 
			continue;

        sockaddr_in *p_address;
        p_address = (sockaddr_in *) & (st_interface_list[i].iiAddress);
        dw_ip_ = p_address->sin_addr.S_un.S_addr;

   		if( !( p_address->sin_addr.S_un.S_un_b.s_b1 == 10 
			|| (p_address->sin_addr.S_un.S_un_b.s_b1 == 172 && p_address->sin_addr.S_un.S_un_b.s_b2 >= 16 && p_address->sin_addr.S_un.S_un_b.s_b2 <= 31)
			|| (p_address->sin_addr.S_un.S_un_b.s_b1 == 192 && p_address->sin_addr.S_un.S_un_b.s_b2 == 168) ))
			return TRUE;
    }

	return FALSE;
}

CHAR* few_connect_client::ip_to_string(DWORD dw_ip_)
{
	in_addr addr;
	addr.S_un.S_addr = dw_ip_;
	return inet_ntoa(addr);
}

DWORD few_connect_client::stringip_to_ip(CHAR* sz_ip_)
{
	return inet_addr(sz_ip_);
}

} // namespace networkbase {