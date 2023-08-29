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
// ��������
//-----------------------------------------------------------------------------
#define SLEEP_TIME			500

#define GET_MAX_PACKAGE_LENGTH		1024
#define MAX_UNIT_POOL_NUM		512
#define SPIN_COUNT		4000
//-----------------------------------------------------------------------------
// ��������Ϣ����׶�
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
	WSAOVERLAPPED			ov;						// IO�ṹ
	E_Server_State			e_state;			// �׶�״̬
	safe_memory_pool*			p_memory_pool;					// �����ڴ�
	tag_unit*				p_next;					
	DWORD					dw_trans_bytes;			// �ж����ֽڴ�����
	DWORD					dw_size;					// ���ݴ�С�������ڴ�ռ��С
	CHAR					p_buffer[sizeof(DWORD)];
};


struct tag_raw_unit
{
	safe_memory_pool*	p_memory_pool;					// �����ڴ�
	DWORD			dw_size;					// ���ݴ�С�������ڴ�ռ��С
	tag_raw_unit*		p_next;					
	CHAR			p_buffer[sizeof(DWORD)];
};


// ʵ������unit�Ĵ�С
#define UNIT_MEM_SIZE(size) (sizeof(tag_unit)+(size))

// LZO����ʹ����ѹ������
#define LZO_MEM_SIZE(size) (((size)/64) + 16 + 3)

// ����ʵ������unit�Ĵ�С
#define RAWUNIT_MEM_SIZE(size) (sizeof(tag_raw_unit)+(size))


//-----------------------------------------------------------------------------
//�����ͻ��˶���
//-----------------------------------------------------------------------------
struct tag_net_client
{
	BOOL volatile			b_shut_down;		// �Ƿ񱻹ر�
	LONG volatile			l_send_cast;		// �Ѿ�send������Ϣ������û���յ�֪ͨ��
	LONG volatile			l_recv_cast;		// �Ѿ�recv����Ϣ,����û���յ�֪ͨ��
	BOOL volatile			b_send;				// �Ƿ����������������

	SOCKET					sock;				// �ͻ��˵�socket
	DWORD					dw_session_id;		// �ͻ��˵�ID,���յ��ĵ�һ��������
	DWORD					dw_connect_time;	// ��¼δ��֤�ͻ���ʱ�䣬��ʱ�߳�
	DWORD					dw_send_size;		// �ȴ�������Ϣ��С

	safe_queue<tag_raw_unit*>* 	p_send_queue;		// ������Ϣ����,�ȴ�ƴ��ѹ��
	safe_queue<tag_unit*>* 		p_recv_queue;		// ������Ϣ����,�ȴ���ȡ����
};



//-----------------------------------------------------------------------------
// �ͻ��˵�½����
//-----------------------------------------------------------------------------
struct tag_login_param
{
	DWORD	dw_handle;	// �ͻ��˵ľ������¼�ͻ������ߵ�ַ
	DWORD	dw_address;	// �ͻ��˵�ַ
	DWORD	dw_port;		// �ͻ��˶˿�
};

#define LOGIN_PARAM_SIZE (((sizeof(sockaddr_in)+16)*2)+sizeof(tag_login_param))
#define LOGIN_PARAM_INDEX ((sizeof(sockaddr_in)+16)*2)

//-----------------------------------------------------------------------------
// ��������������
//-----------------------------------------------------------------------------
typedef fastdelegate::FastDelegate2<tag_unit*, tag_login_param*, UINT>	LOGIN_CALLBACK;
typedef fastdelegate::FastDelegate1<DWORD, UINT> LOGOUT_CALLBACK;

struct tag_server_config
{
	LOGIN_CALLBACK	fn_login;		// ��½�ص�����
	LOGOUT_CALLBACK	fn_logout;		// �ǳ��ص�����

	INT	n_port;						// �˿�
	INT n_max_client_num;			// ��������������������
	INT n_cpu_work_thread;			// ÿ��CPU�����Ĺ����߳�
	INT n_superfluity_work_thread;	// ���⸽�ӵĹ����߳�
	INT n_accept_num;				// �����Ľ��ռ�������
	DWORD dw_mem_pool_size;			// �ڴ�ش�С
	DWORD dw_auth_time_limit;		// ��֤ʱ��(����)
	DWORD dw_tick_send_size;		// ��ͻ���ÿ��������������ֽ���
	DWORD dw_max_recv_size;			// �������ֽ���
	bool b_repeat_port;				// �Ƿ�˿�����
	bool b_use_nagle;				// �Ƿ�ʹ��nagle�㷨

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




