
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//��½����������������������Ϣ

#pragma once

#include "login_server_define.h"

#pragma pack(push, 1)

enum
{
	e_pl_num_limit				=	1,	// ������������

	e_pl_verify_code_error		=	11,	// ��֤�����
	e_pl_time_out				=	12,	// ��ʱ
};

//! ������������½��������֤��Ϣ
struct NET_L2W_certification : public tag_net_message 
{   
	NET_L2W_certification ( ) 
	{  
		ZeroMemory (this, sizeof (*this)) ;   
		dw_message_id = message_id_crc ("NET_L2W_certification") ;   
		dw_size = sizeof (*this) ;     
	}   
	DWORD dw_golden_code;    
};  

struct NET_W2L_certification : public tag_net_message 
{   
	NET_W2L_certification ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_W2L_certification" ) ;   
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_golden_code;  
	TCHAR sz_world_name[X_SHORT_NAME];  
	DWORD dw_port;   
	DWORD dw_ip;
	INT n_online_account_num;
	DWORD dw_online_account_id[1];     
};  

//! ����
struct NET_L2W_heart_beat : public tag_net_message 
{  
	NET_L2W_heart_beat ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_L2W_heart_beat" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
};  


//! ���������֪ͨ��½��������ǰ������״̬
struct NET_W2L_world_status : public tag_net_message 
{   
	NET_W2L_world_status ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_W2L_world_status" ) ;
		dw_size = sizeof ( * this ) ;    
	}  
	E_world_status e_status;  
	INT n_player_num_limit; 
	INT n_cur_player_num;     
};  

//! ��½������֪ͨ����������ʺŵ���
struct NET_L2W_player_will_login : public tag_net_message
{  
	NET_L2W_player_will_login ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_L2W_player_will_login" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_account_id; 
	BYTE by_privilege;  
	DWORD dw_verify_code;   
	BOOL b_guard; 
	DWORD dw_account_online_sec;   
	char sz_account[X_SHORT_NAME];  
	tagDWORDTime dw_pre_login_time;
	DWORD dw_pre_login_ip;   
};  

//! ���������֪ͨ��½�������ʺſ��Ե���
struct NET_W2L_player_will_login : public tag_net_message
{  
	NET_W2L_player_will_login ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_W2L_player_will_login" ) ;   
		dw_size = sizeof ( * this ) ;
	}   
	DWORD dw_error_code;  
	DWORD dw_account_id;   
};  


//! ���������֪ͨ��½��������ҵ���
struct NET_W2L_player_login : public tag_net_message
{  
	NET_W2L_player_login ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_W2L_player_login" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_account_id;
	DWORD dw_ip; 
	DWORD dw_error_code; 
};  

//! ���������֪ͨ��½��������ҵǳ�
struct NET_W2L_player_logout : public tag_net_message 
{  
	NET_W2L_player_logout ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_W2L_player_logout" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_account_id;  
};  

//! ��½������֪ͨ����������߳�ָ�����(�Ѿ�������������е�����ٴε�¼ʱ, ��Ҫ�߱������������)
struct NET_L2W_kick_player : public tag_net_message
{ 
	NET_L2W_kick_player ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_L2W_kick_player" ) ;  
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_account_id;  
};  

//! ���������������ʱ��֪ͨ����½����������¼
struct NET_W2L_kick_log : public tag_net_message
{  
	NET_W2L_kick_log ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_W2L_kick_log" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_account_id;   
	DWORD dw_kick_time; 
	DWORD u_16err_code;   
	BYTE by_seal;   
	DWORD dw_role_level;
	CHAR  szRoleName[X_SHORT_NAME];
	CHAR  szWorldName[X_SHORT_NAME];
};  


//! ������������ر�ʱ����½����������
struct NET_L2W_world_colsed : public tag_net_message 
{  
	NET_L2W_world_colsed ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_L2W_world_colsed" ) ;  
		dw_size = sizeof ( * this ) ; 
	}    
};  


//! ������������ر�ʱ��֪ͨ����½�������ı���ҵ�½״̬
struct NET_2L_world_colsed : public tag_net_message
{   
	NET_2L_world_colsed ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_2L_world_colsed" ) ; 
		dw_size = sizeof ( * this ) ;   
	}   
};  



#pragma pack(pop)