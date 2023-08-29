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
*	@file		few_connect_server.h
*	@author		lc
*	@date		2011/01/25	initial
*	@version	0.0.1.0
*	@brief		
*/

// 多线程服务器，适合较大流量的少量连接

#ifndef FEW_CONNECT_SERVER
#define FEW_CONNECT_SERVER
namespace networkbase {
class few_connect_server;

typedef fastdelegate::FastDelegate2<LPBYTE,DWORD,DWORD>		net_login_call_back;
typedef fastdelegate::FastDelegate1<DWORD,DWORD>			net_logout_call_back;
//typedef UINT (win_api* net_login_call_back)(BYTE* p_byte_, DWORD dw_size_);
//typedef UINT (win_api* net_logout_call_back)(DWORD dw_client_id_);

struct tag_client	
{
	DWORD			dw_id;
	SOCKET			socket;
	volatile BOOL	b_end;
	HANDLE			h_send_thread;
	HANDLE			h_recv_thread;
	safe_message_queue*		p_send_msg_queue;
	safe_message_queue*		p_recv_msg_queue;
	DWORD			dw_connect_time;
	INT				n_recv_package_num;

	tag_client():dw_id(INVALID_VALUE),socket(0),b_end(FALSE),
		h_send_thread(0),h_recv_thread(0),p_send_msg_queue(0),p_recv_msg_queue(0),
		dw_connect_time(0),n_recv_package_num(0){}
};

struct tag_thread_param
{
	few_connect_server* p_server;
	tag_client* p_client;
};

class NETWORK_API few_connect_server
{
public:
	BOOL init(net_login_call_back fn_login_, net_logout_call_back fn_logout_, INT n_port_, 
		BOOL b_repeat_use_port_=TRUE, BOOL b_package_mode_=TRUE);
	BOOL destory();

	// 发送消息, 并发送消息队列数量
	INT send_msg(DWORD dw_client_id_, LPVOID p_msg_, DWORD dw_msg_size_);
	// 接收消息，n_recv_num_返回接收队列消息数量
	BYTE* recv_msg(DWORD dw_client_id_, DWORD& dw_msg_size_, INT& n_recv_queue_num);
	// 消息处理完成后，释放接收到的消息内存
	VOID free_recv_msg(DWORD dw_client_id_, BYTE* p_free_msg_) ;
	
	// 踢出连线
	BOOL kick_connect(DWORD dw_client_id_);	


	// 获得服务器端口
	INT get_port() { return n_port; }

	// 获得客户端连接数量
	INT	get_connect_client_num() { return map_connect_client.size(); } 

	// 检查指定的连接客户端是否存在
	BOOL is_connect_client_exsit(DWORD dwID) { return map_connect_client.is_exist(dwID); }

	// 获得客户端sock名称
	BOOL get_client_sock_name(sockaddr_in* p_sockaddr_in_, DWORD dw_client_id_);

	// 获得发送消息的总数量
	volatile DWORD& get_send_msg_total_num() {return dw_send_msg_num;}

	// 获得接收消息的总数量
	volatile DWORD& get_recv_msg_total_num() {return dw_recv_msg_num;}

	// 获得发送消息的总字节数
	volatile DWORD& get_send_msg_total_bytes() {return dw_send_total_byte;}

	// 获得接收消息的总字节数
	volatile DWORD& get_recv_msg_total_bytes() {return dw_recv_total_byte;}

	BOOL is_end_accept() { return b_end_accept; }

	sockaddr_in get_sockadd_in() { return server_address; }

	SOCKET	get_socket() { return server_socket; }

	BOOL	get_mode() { return b_package_mode; }

	package_safe_map<DWORD, tag_client*>& get_client_map() { return map_connect_client; }

	net_login_call_back get_fn_login() { return fn_login; }

	safe_memory_pool* get_safe_mem_pool() { return p_memory_pool; }

	tag_thread_param& get_thread_recv_param() { return st_thread_recv_param; }
	tag_thread_param& get_thread_io_recv_param() { return st_thread_io_recv_param; }
	tag_thread_param& get_thread_send_param() { return st_thread_send_param; }

	VOID disconnect_client(tag_client* p_client_);

	BOOL	is_end_disconnect() { return b_end_discnnect; }
	package_safe_list<tag_client*>& get_delete_client_list() { return list_delete_client; }

	few_connect_server();
	~few_connect_server();


private:

	safe_memory_pool*						p_memory_pool;
	CRITICAL_SECTION					disconnect_lock;
	BOOL								b_package_mode;			// 是否采用合并包模式
	net_login_call_back					fn_login;				
	net_logout_call_back				fn_logout;

	volatile BOOL						b_end_accept;		// 是否关闭接受连线线程
	volatile BOOL						b_end_discnnect;	// 是否关闭断线线程
	package_safe_map<DWORD, tag_client*>		map_connect_client;			// 记录连接的客户端
	package_safe_list<tag_client*>				list_delete_client;		// 需要删除的客户端
	INT									n_port;				
	sockaddr_in							server_address;				// 服务器地址信息
	SOCKET								server_socket;				
	HANDLE								h_accept_thread;		// 创建连接线程句柄
	HANDLE								h_thread_disconnect;	// 离线线程句柄

	volatile DWORD						dw_send_msg_num;			
	volatile DWORD						dw_recv_msg_num;
	volatile DWORD						dw_send_total_byte;
	volatile DWORD						dw_recv_total_byte;

	tag_thread_param				st_thread_recv_param;
	tag_thread_param				st_thread_io_recv_param;
	tag_thread_param				st_thread_send_param;

};

UINT win_api few_connect_thread_accept(void* p);
UINT win_api few_connect_thread_recv(void* p);
UINT win_api few_connect_thread_io_recv(void* p);
UINT win_api few_connect_thread_send(void* p);
UINT win_api few_connect_thread_disconnect(void* p);

} // namespace networkbase {
#endif