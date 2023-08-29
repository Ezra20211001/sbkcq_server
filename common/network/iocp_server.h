/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

/**
*	@file		iocp_server.h
*	@author		lc
*	@date		2011/02/10	initial
*	@version	0.0.1.0
*	@brief		
*/


#ifndef IOCP_SERVER
#define IOCP_SERVER

#define MAX_WORK_THREAD 128

#include "server_define.h"

namespace networkbase {
	class memorysystem::safe_memory_pool;
	class IOCP;
	struct tag_work_param
	{
		IOCP* p_server;
		INT		n_index;
	};
//-----------------------------------------------------------------------------
// iocp服务器底层
//-----------------------------------------------------------------------------
class NETWORK_API IOCP
{
public:
	BOOL init(tag_server_config& param);
	BOOL destroy();
	log_file* get_log() { return m_pLog; }

	
	// 发送消息
	__forceinline VOID send(DWORD dw_handle_, LPVOID p_msg_, DWORD dw_size_);
	// 接收消息
	__forceinline LPBYTE recv(DWORD dw_handle_, DWORD& dw_size_, INT& n_recv_num_);
	// 激活发送线程，发送消息
	__forceinline VOID active_send() { ::SetEvent(h_event_send);	}
	// 释放处理后的消息
	__forceinline VOID free_recv(LPBYTE p_msg_);

	// 踢人
	VOID kick_client(DWORD dw_handle_);
	VOID clost_client(DWORD dw_handle_);
	
	tag_server_config* get_config() { return &st_config; }	
	
	LONG get_send_cast(DWORD dw_handle_) { return ((tag_net_client*)dw_handle_)->l_send_cast; }
	DWORD get_send_cast_size(DWORD dw_handle_) { return ((tag_net_client*)dw_handle_)->dw_send_size; }
	DWORD get_send_queue_num(DWORD dw_handle_) { return ((tag_net_client*)dw_handle_)->p_send_queue->get_num();}
	INT get_pool_num() { return n_pool_num; }	
	memorysystem::safe_memory_pool* get_pool(INT n) { return &p_memory_pool[n]; }	
	INT64& get_send_size() { return n64_send_size; }	
	//获得压缩后的大小
	INT64& get_compress_send_size() { return n64_compress_send_size; }	
	INT get_free_client_num() { return list_free_client.size(); }

	INT32& get_add_num() { return n32AddNum; }
	INT32& get_drop_num() { return n32DropNum; }
	INT32& get_recv_num() { return n32RecvAddNum; }
	INT32 get_recv_drop_num() { return n32RecvDropNum; }
	INT64& get_sec_send_size() { return n64SecSendSize; }
	INT64& get_io_pending() { return n_io_pending; }
	DWORD& get_io_pending_id() { return dw_io_pending_id; }

	BOOL is_end_work_thread() { return b_end_work_threak; }

	volatile INT& get_accept_num() { return n_accept_num; } 
	SOCKET& get_listen_sock() { return sock_listen; }

	LPFN_ACCEPTEX get_fn_accept() { return lp_fn_accept; }
	LPFN_GETACCEPTEXSOCKADDRS get_fn_get_accept_sockaddr() { return lp_fn_get_accept_sockaddr; }
	
	HANDLE get_event_accept() { return h_event_accept; }
	HANDLE get_competion_port() { return h_competion_port; }
	HANDLE get_event_send() { return h_event_send; }
	HANDLE get_event_destroy() { return h_event_destroy; }

	safe_list<tag_net_client*>& get_list_free_client() { return list_free_client; }
	safe_list<tag_net_client*>& get_list_unauth_client() { return list_unauth_client; }
	safe_list<tag_net_client*>& get_list_destroy_client() { return list_destroy_client; }

	VOID	destroy_client(tag_net_client* p_client_);
	VOID	pre_destroy_client(tag_net_client* p_client_, tag_unit* p_unit_);

	tag_net_client* get_client() { return p_client; }
	file_filter* get_filter() { return p_filter; }

	VOID   log_free_msg(DWORD dw_handle_, DWORD dw_Session_id);
	IOCP();
	~IOCP();

private:
	
	file_filter*	p_filter;

	LPFN_ACCEPTEX				lp_fn_accept;
	LPFN_GETACCEPTEXSOCKADDRS	lp_fn_get_accept_sockaddr;

	safe_list<tag_net_client*>	list_free_client;
	safe_list<tag_net_client*>	list_unauth_client;//未验证客户端列表
	safe_list<tag_net_client*>	list_destroy_client;
	
	//保存线程句柄
	std::vector<HANDLE>	v_thread_hanle;		
	BOOL				b_end_work_threak;	
	HANDLE				h_event_accept;
	HANDLE				h_event_send;
	HANDLE				h_event_destroy;

	tag_server_config	st_config;				// 服务器参数
    SOCKET				sock_listen;			// 监听socket
	HANDLE				h_competion_port;		// 完成端口

	tag_net_client*		p_client;				
	safe_memory_pool*		p_memory_pool;					
	INT					n_pool_num;				

	INT	volatile		n_accept_num;			// 占用的accept数量
	INT64				n64_send_size;			
	INT64				n64_compress_send_size;		

	// 接受连接请求的线程
	BOOL	create_accept_thread();
	
	// 完成端口处理线程
	BOOL	create_work_thread(INT n_thread_num_);
	
	// 踢出超时没有验证的客户端线程
	BOOL	create_unauth_heartbeat_thread();
	
	// 发送消息线程
	BOOL	create_send_thread();
	
	// 资源回收线程
	BOOL	create_destroy_thread();

	INT32   n32RecvAddNum;
	INT32   n32RecvDropNum;
	INT32   n32AddNum;
	INT32   n32DropNum;
	INT64   n64SecSendSize;
	INT64	n_io_pending;
	DWORD	dw_io_pending_id;

	tag_work_param st_work_param[MAX_WORK_THREAD];

	log_file* m_pLog;
};

UINT WINAPI thread_accept(LPVOID p);
UINT WINAPI	thread_work(LPVOID p);
UINT WINAPI	thread_unauth_hearbeat(LPVOID p);
UINT WINAPI	thread_work_send(LPVOID p);
UINT WINAPI	thread_destroy(LPVOID p);

VOID IOCP::send(DWORD dw_handle_, LPVOID p_msg_, DWORD dw_size_)
{
	tag_net_client* p_client = (tag_net_client*)dw_handle_;
	if( !p_client->b_shut_down )
	{
		// 寻找可以进入锁定的内存池
		INT n = (dw_handle_%(n_pool_num-1))+1;
		tag_raw_unit* p_send_unit=0;
		for(;!p_send_unit;)
		{
			if( ++n >= n_pool_num )
				n = 1;
			p_send_unit = (tag_raw_unit*)p_memory_pool[n].try_alloc_memory(RAWUNIT_MEM_SIZE(dw_size_));
		}

		p_send_unit->dw_size = dw_size_;
		p_send_unit->p_memory_pool = &p_memory_pool[n];
		memcpy(p_send_unit->p_buffer, p_msg_, dw_size_);
		Interlocked_Increment(&p_client->l_send_cast);
		p_client->dw_send_size += dw_size_;
		p_client->p_send_queue->add(p_send_unit);
	}
}

LPBYTE IOCP::recv(DWORD dw_handle_, DWORD& dw_size_, INT& n_recv_num_)
{
	tag_net_client* p_client = (tag_net_client*)dw_handle_;
	if( !p_client->b_shut_down )
	{
		n_recv_num_ = p_client->p_recv_queue->get_num();
		tag_unit* p_unit = p_client->p_recv_queue->get();
		if( !p_unit )
			return NULL;

		dw_size_ = p_unit->dw_size;
		return (LPBYTE)p_unit->p_buffer;
	}
	return NULL;
}

VOID IOCP::free_recv(LPBYTE p_msg_)
{
	tag_unit* p_unit = CONTAINING_RECORD(p_msg_, tag_unit, p_buffer);
	p_unit->p_memory_pool->free_memory(p_unit);
	n32RecvDropNum++;
}


} // namespace networkbase {
#endif
