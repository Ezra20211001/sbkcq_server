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
*	@file		server_define.h
*	@author		lc
*	@date		2011/02/09	initial
*	@version	0.0.1.0
*	@brief		
*/


#ifndef SERVER_DEFINE
#define SERVER_DEFINE

#include "..\memory\safe_memory_pool.h"
#include "safe_queue.h"
#include "safe_list.h"


namespace networkbase {
//-----------------------------------------------------------------------------
// 基本定义
//-----------------------------------------------------------------------------
#define SLEEP_TIME			500

#define GET_MAX_PACKAGE_LENGTH		1024
#define MAX_UNIT_POOL_NUM		512
#define SPIN_COUNT		4000
//-----------------------------------------------------------------------------
// 服务器消息处理阶段
//-----------------------------------------------------------------------------
enum E_Server_State
{
	ESS_Null = 0,
	ESS_Accept,
	ESS_RecvLength,
	ESS_Recv,
	ESS_Send,
	ESS_End 
};

struct tag_unit
{
	WSAOVERLAPPED			ov;						// IO结构
	E_Server_State			e_state;			// 阶段状态
	safe_memory_pool*			p_memory_pool;					// 分配内存
	tag_unit*				p_next;					
	DWORD					dw_trans_bytes;			// 有多少字节传输了
	DWORD					dw_size;					// 内容大小，不是内存空间大小
	CHAR					p_buffer[sizeof(DWORD)];
};


struct tag_raw_unit
{
	safe_memory_pool*	p_memory_pool;					// 分配内存
	DWORD			dw_size;					// 内容大小，不是内存空间大小
	tag_raw_unit*		p_next;					
	CHAR			p_buffer[sizeof(DWORD)];
};


// 实际申请unit的大小
#define UNIT_MEM_SIZE(size) (sizeof(tag_unit)+(size))

// LZO可能使数据压缩后变大
#define LZO_MEM_SIZE(size) (((size)/64) + 16 + 3)

// 计算实际申请unit的大小
#define RAWUNIT_MEM_SIZE(size) (sizeof(tag_raw_unit)+(size))


//-----------------------------------------------------------------------------
//单个客户端定义
//-----------------------------------------------------------------------------
struct tag_net_client
{
	BOOL volatile			b_shut_down;		// 是否被关闭
	LONG volatile			l_send_cast;		// 已经send出的消息，但还没有收到通知的
	LONG volatile			l_recv_cast;		// 已经recv的消息,但还没有收到通知的
	BOOL volatile			b_send;				// 是否允许继续发送数据

	SOCKET					sock;				// 客户端的socket
	DWORD					dw_session_id;		// 客户端的ID,由收到的第一个包生成
	DWORD					dw_connect_time;	// 记录未验证客户端时间，超时踢出
	DWORD					dw_send_size;		// 等待发送消息大小

	safe_queue<tag_raw_unit*>* 	p_send_queue;		// 发送消息队列,等待拼包压缩
	safe_queue<tag_unit*>* 		p_recv_queue;		// 接收消息队列,等待收取处理
};



//-----------------------------------------------------------------------------
// 客户端登陆参数
//-----------------------------------------------------------------------------
struct tag_login_param
{
	DWORD	dw_handle;	// 客户端的句柄，记录客户端连线地址
	DWORD	dw_address;	// 客户端地址
	DWORD	dw_port;		// 客户端端口
};

#define LOGIN_PARAM_SIZE (((sizeof(sockaddr_in)+16)*2)+sizeof(tag_login_param))
#define LOGIN_PARAM_INDEX ((sizeof(sockaddr_in)+16)*2)

//-----------------------------------------------------------------------------
// 服务器参数定义
//-----------------------------------------------------------------------------
typedef fastdelegate::FastDelegate2<tag_unit*, tag_login_param*, UINT>	LOGIN_CALLBACK;
typedef fastdelegate::FastDelegate1<DWORD, UINT> LOGOUT_CALLBACK;

struct tag_server_config
{
	LOGIN_CALLBACK	fn_login;		// 登陆回调函数
	LOGOUT_CALLBACK	fn_logout;		// 登出回调函数

	INT	n_port;						// 端口
	INT n_max_client_num;			// 服务器最大承载人数限制
	INT n_cpu_work_thread;			// 每个CPU启动的工作线程
	INT n_superfluity_work_thread;	// 额外附加的工作线程
	INT n_accept_num;				// 建立的接收监听数量
	DWORD dw_mem_pool_size;			// 内存池大小
	DWORD dw_auth_time_limit;		// 认证时限(毫秒)
	DWORD dw_tick_send_size;		// 向客户端每个心跳发送最大字节数
	DWORD dw_max_recv_size;			// 最大接收字节数
	bool b_repeat_port;				// 是否端口重用
	bool b_use_nagle;				// 是否使用nagle算法

	tag_server_config()
	{ 
		fn_login = NULL;
		fn_logout = NULL;
		n_port = 6008; 
		n_max_client_num = 4000; 
		n_cpu_work_thread = 2;
		n_superfluity_work_thread = 2;
		n_accept_num = 32; 
		
		dw_mem_pool_size = 12*1024*1024;
		dw_auth_time_limit = 20*1000;
		dw_tick_send_size =12*1024*1024;
		dw_max_recv_size = 1024/*512*/;
		
		b_repeat_port = false;
		b_use_nagle = false;
	}
};


} // namespace networkbase {
#endif




