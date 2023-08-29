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
*	@file		few_connect_client.h
*	@author		lc
*	@date		2011/01/27	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef FEW_CONNECT_CLIENT
#define FEW_CONNECT_CLIENT

namespace networkbase {

enum E_few_connect_client_mode
{
	EFCCM_Package = 0,
	EFCCM_Stream = 1,
	EFCCM_Text = 2
};

class NETWORK_API few_connect_client
{
public:
	BOOL init(BOOL b_nagle_=TRUE, E_few_connect_client_mode e_mode_=EFCCM_Package);
	VOID destory();

	// 尝试重新创建连接
	VOID try_create_connect(LPCSTR sz_ip_, INT n_port_=0); 

	// 是否正在创建连接
	BOOL is_trying_create_connect();

	// 放弃创建连接
	VOID abandon_trying_connect();	

	BOOL is_connect() { return b_connected; }

	// 断开连接
	VOID disconnect(); 

	BOOL send_msg(LPVOID p_msg_, DWORD dw_msg_size_);
	
	LPBYTE recv_msg(DWORD& dw_msg_size_);
	
	VOID free_recv_msg(LPBYTE p_message);

	BOOL set_packagehead_byte(BOOL b_head_);	

	// 获得没有发送包的数量
	INT	get_nosend_package_num();

	// 获得已收到的待处理的包的数量
	INT	get_recv_package_num(); 

	// 获得总发包数量
	DWORD get_total_send_package_num() { return dw_send_total_num; }	

	// 获得每秒发送消息量
	DWORD get_out_cps(){ return dw_send_byte; } 

	// 获得每秒接收消息量
	volatile DWORD& get_in_cps(){ return dw_recv_byte; } 

	// 得到远端ip地址
	LPCSTR get_remote_ip() { return str_ip.c_str(); }

	// 获得主机名称
	BOOL get_host_name(std::string& str_name_);

	// 获得主机ip
	BOOL get_ip_by_host_name(DWORD& dw_ip_, LPCSTR p_host_name_);

	// 获得本机局域网地址
	BOOL get_local_lan_ip(DWORD& dw_ip_);

	// 获得本机广域网地址
	BOOL get_local_wan_ip(DWORD& dw_ip_);	

	CHAR* ip_to_string(DWORD dw_ip_);	
	DWORD stringip_to_ip(CHAR* sz_ip_);	

	BOOL trans_mode(E_few_connect_client_mode e_mode_); 

	INT& get_port() { return n_port; }
	SOCKET&	get_socket() { return n_socket; }

	volatile BOOL& is_end_connect() { return b_end_connect; }
	volatile BOOL& is_connected() { return b_connected; }
	volatile BOOL& is_end_send() { return b_end_send; }
	BOOL	is_package_head()	{ return b_package_head; }	
	volatile BOOL&	is_end_recv() { return b_end_recv; }

	volatile DWORD& get_send_total_num() { return dw_send_total_num; }
	volatile DWORD& get_recv_total_num() { return dw_recv_total_num; }
	volatile DWORD&	get_last_out_cps_time()	{ return dw_last_out_cps_time; }
	volatile DWORD&	get_send_byte()	{ return dw_send_byte; }
	volatile DWORD&	get_send_byte_count() { return dw_sent_byte_count; }
	volatile DWORD&	get_last_in_cps_time() { return dw_last_in_cps_time; }	
	volatile DWORD& get_recv_byte_count() { return dw_recv_byte_count; }

	HANDLE& get_connect_thread() { return h_connect_thread; }
	HANDLE& get_send_thread() { return h_send_thread; }
	HANDLE& get_recv_thread() { return h_recv_thread; }

	safe_message_queue*	get_send_msg_queue()	{ return p_send_msg_queue; }
	safe_message_queue*	get_recv_msg_queue()	{ return p_recv_msg_queue; }

	memorysystem::MemPool*	get_memory_pool() { return p_memory_pool; }

	E_few_connect_client_mode& get_trans_mode() { return e_trans_mode; }
	std::string& get_ip_string() { return str_ip; }

	few_connect_client();
	~few_connect_client();

private:
	
	E_few_connect_client_mode		e_trans_mode;	
	BOOL						b_package_head;		

	memorysystem::MemPool*		p_memory_pool;

	//接收，发送队列
	safe_message_queue*				p_send_msg_queue;
	safe_message_queue*				p_recv_msg_queue;
	
	std::string				str_ip;
	INT						n_port;
	SOCKET					n_socket;
	BOOL					b_nagle;

	HANDLE					h_connect_thread;
	HANDLE					h_send_thread;
	HANDLE					h_recv_thread;

	volatile BOOL			b_end_connect;
	volatile BOOL			b_end_send;
	volatile BOOL			b_end_recv;
	volatile BOOL			b_connected;		

	// 上次接收流量统计时间
	volatile DWORD			dw_last_in_cps_time;	
	// 上次发送流量统计时间
	volatile DWORD			dw_last_out_cps_time;
	volatile DWORD			dw_send_byte;		
	volatile DWORD			dw_recv_byte;			
	volatile DWORD			dw_sent_byte_count;
	volatile DWORD			dw_recv_byte_count;

	volatile DWORD			dw_send_total_num;	
	volatile DWORD			dw_recv_total_num;    

	VOID clear();
	BOOL blandness_close_socket(SOCKET& n_socket_, INT n_repeat_time_);
	BOOL blandness_close_threak(HANDLE& h_thread_, INT n_repeat_time_);

};

UINT win_api thread_connect(void* p);
UINT win_api thread_send(void* p);
UINT win_api thread_package_recv(void* p);	
UINT win_api thread_text_recv(void* p);


} // namespace networkbase {
#endif
