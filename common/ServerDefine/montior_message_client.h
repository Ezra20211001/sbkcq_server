
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//��ά�������ͻ���֮�����Ϣ����

#pragma once
#include "../ServerDefine/login_server_define.h"
#include "../common/WorldDefine/base_define.h"
#include "../ServerDefine/rt_define.h"
#include "../ServerDefine/gm_tool_define.h"

#pragma pack(push, 1)

enum E_msg_set
{
	e_nrtc_login_service,
	e_nrtc_challenge,
	e_nrtc_close,
	e_nrtc_start,
};

struct tagServerInfo
{
	BOOL			b_valid;
	E_world_status	e_status;
	INT				n_max_player_num;
	INT				n_player_online;	
};


//! ���ӳ�ʼ��Ϣ��������ά�ͻ��ˣ�RtClient����������ά������(GMserver)
struct NET_M2W_login_service : public tag_net_message 
{   
	NET_M2W_login_service ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_M2W_login_service" ) ;   
		dw_size = sizeof ( * this ) ;   
	}    
};  

//! ȷ��������Ϣ��������ά������(GMserver)��������ά��������Rtclient��
struct NET_W2M_login_service : public tag_net_message 
{   
	NET_W2M_login_service ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_W2M_login_service" ) ;  
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_error_code;    
};  

//! �ر���Ϸ�������������Ϣ��������ά�ͻ��ˣ�RtClient����������ά������(GMserver)
struct NET_M2W_close : public tag_net_message 
{   
	NET_M2W_close ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_M2W_close" ) ;
		dw_size = sizeof ( * this ) ;   
	}
	DWORD dw_section_id; 
	E_server_type e_type;
	DWORD dw_world_id;  
	BOOL b_force;    //FALSE:�����ر� //TRUE:ǿ�ƹر�	
};  


//! �ر���Ϸ�����������ȷ����Ϣ��������ά������(GMserver)��������ά�ͻ��ˣ�RtClient��
struct NET_W2M_close : public tag_net_message 
{  
	NET_W2M_close ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_W2M_close" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_error_code;   
};  

//! ������Ϸ�������������Ϣ��������ά�ͻ��ˣ�RtClient����������ά������(GMserver)
struct NET_M2W_start : public tag_net_message 
{ 
	NET_M2W_start ( ) 
	{
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_M2W_start" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_section_id; 
	E_server_type e_type;  
	DWORD dw_world_id;    
};  

//! ������Ϸ�����������ȷ����Ϣ��������ά������(GMserver)��������ά�ͻ��ˣ�RtClient��
struct NET_W2M_start : public tag_net_message 
{   
	NET_W2M_start ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_W2M_start" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_error_code;    
};  

//! ����˺Ű󶨵�IP��ַ
struct NET_M2W_bind_ip : public tag_net_message
{ 
	NET_M2W_bind_ip ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_M2W_bind_ip" ) ;   
		dw_size = sizeof ( * this ) ;    
	}  
	TCHAR sz_account_name[X_SHORT_NAME];  
	DWORD dw_ip;     
};  

struct NET_W2M_bind_ip : public tag_net_message 
{   
	NET_W2M_bind_ip ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_W2M_bind_ip" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;     
};  

//! ��������̬��Ϣ����Ϣ��������ά������(GMserver)��������ά�ͻ��ˣ�RtClient��
struct NET_W2M_all_server_dynainfo : public tag_net_message
{   
	NET_W2M_all_server_dynainfo ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_W2M_all_server_dynainfo" ) ;  
		dw_size = sizeof ( * this ) ;   
	} 
	INT n_section_num; //��������
	BYTE by_info[1];   //����ID-login״̬-world����-world[n]ID-World[n]GameServer״̬-World[n]DBServer״̬
};  


//! ��������̬��Ϣ����Ϣ��������ά������(GMserver)��������ά�ͻ��ˣ�RtClient��
struct NET_W2M_all_server_stat_info : public tag_net_message
{   
	NET_W2M_all_server_stat_info ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_W2M_all_server_stat_info" ) ;
		dw_size = sizeof ( * this ) ;  
	} 
	INT n_section_num; //��������
	BYTE by_info[1];    //������-����ID-login IP-world����-world[n]����-world[n]ID-siGameServerIP-LoginServerIP
};  

//! �˺���֤��Ϣ��������ά�ͻ���RtClient��������ά������(GMserver)
struct NET_M2W_challenge : public tag_net_message 
{  
	NET_M2W_challenge ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_M2W_challenge" ) ; 
		dw_size = sizeof ( * this ) ;  
	}   
	TCHAR sz_account_name[X_SHORT_NAME];
	DWORD dw_password_crc;   
};  

//! �˺���֤��ȷ����Ϣ��������ά������(GMserver)��������ά�ͻ��ˣ�RtClient��
struct NET_W2M_challenge : public tag_net_message
{
	NET_W2M_challenge ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_W2M_challenge" ) ;
		dw_size = sizeof ( * this ) ;  
	}
	DWORD dw_error_code;
	EPrivilege e_privilege; 
};  

//! Ȩ����Ϣ��������ά������(GMserver)��������ά�ͻ��ˣ�RtClient��
struct NET_W2M_privilege_info : public tag_net_message 
{ 
	NET_W2M_privilege_info ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_W2M_privilege_info" ) ;
		dw_size = sizeof ( * this ) ;    
	}   
	INT n_num;			// Ȩ�޶�����
	DWORD dw_info[1];	// �����ֵĶ�������ʽ��ÿһλ�ֱ�������Ϣ��ִ��Ȩ��
};  


//! ����ϵͳָ�����Ϣ��������ά�ͻ���RtClient��������ά������(GMserver)
 struct NET_M2W_system_cmd : public tag_net_message
 {  
	 NET_M2W_system_cmd ( ) 
	 {  
		 ZeroMemory ( this , sizeof ( * this ) ) ; 
		 dw_message_id = message_id_crc ( "NET_M2W_system_cmd" ) ;   
		 dw_size = sizeof ( * this ) ;  
	 }  
	 DWORD dwSectionID;		//����ID
	 E_server_type e_type;  //����������
	 DWORD dw_world_id;	  //��Ϸ����ID,db������ָ��
	 TCHAR sz_cmd[System_Cmd_Length];   //ϵͳָ��
 };  

struct NET_W2M_system_cmd : public tag_net_message
{  
	NET_W2M_system_cmd ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_W2M_system_cmd" ) ;
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_error_code; 
	EPrivilege e_privilege;  
};  


//! �����������������������ά�ͻ���RtClient��������ά������(GMserver)
struct NET_M2W_max_number : public tag_net_message
{
	NET_M2W_max_number ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_M2W_max_number" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_section_id; 
	E_server_type e_type;
	DWORD dw_world_id;
	INT n_max_num;
};  

struct NET_W2M_max_number : public tag_net_message 
{  
	NET_W2M_max_number ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_W2M_max_number" ) ;  
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_error_code;   
};  


//! �����̳ǣ�������ά�ͻ���RtClient��������ά������(GMserver)
struct NET_M2W_update_mall : public tag_net_message
{   
	NET_M2W_update_mall ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_M2W_update_mall" ) ;   
		dw_size = sizeof ( * this ) ;
	} 
	DWORD dw_section_id; 
	E_server_type e_type;
	DWORD dw_world_id;    
};  

struct NET_W2M_update_mall : public tag_net_message
{   
	NET_W2M_update_mall ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_W2M_update_mall" ) ;
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_error_code;   
};  


{ 
	NET_M2W_gm_query ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_M2W_gm_query" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
};  

struct NET_W2M_gm_query : public tag_net_message 
{  
	NET_W2M_gm_query ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_W2M_gm_query" ) ;   
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_error_code;  
};  

#pragma pack(pop)
