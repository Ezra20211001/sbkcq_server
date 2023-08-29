
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//��ά���������Ϸ����֮�����Ϣ����

#pragma once
#include "../ServerDefine/login_server_define.h"
#include "../ServerDefine/montior_define.h"
#include "../ServerDefine/gm_tool_define.h"
#include "../../common/WorldDefine/base_define.h"

#pragma pack(push, 1)


//! ��Ϸ������������ά����������
struct NET_S2C_login_service : public tag_net_message 
{   
	NET_S2C_login_service ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_S2C_login_service" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_section_id;	// ����ID
	DWORD dw_world_id;		// ��Ϸ����ID
	E_server_type e_type;   // ����
};  


//! ��ά������ȷ���յ�����
struct NET_S2S_login_service : public tag_net_message 
{ 
	NET_S2S_login_service ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_S2S_login_service" ) ;   
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_error_code;  	// 0:�ɹ�
};  

//! ��ά����ˣ�GMserver����������Ϸ���籾����ά����RTService�� �ĵ�����Э
struct NET_LS2S_login_service : public tag_net_message 
{ 
	NET_LS2S_login_service ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_LS2S_login_service" ) ;   
		dw_size = sizeof ( * this ) ;   
	}  
	E_server_type e_type;    	// ����
};  


//! ��ʼ����ȷ����Ϣ ������Ϸ���籾����ά����RTService��,������ά����ˣ�GMserver��
struct NET_LS2C_login_service : public tag_net_message
{  
	NET_LS2C_login_service ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_LS2C_login_service" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;    	// 0:�ɹ�
};  


//! �ر���Ϸ�������������Ϣ��������ά����ˣ�GMserver����������Ϸ����
struct NET_S2S_close : public tag_net_message 
{  
	NET_S2S_close ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_S2S_close" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
};  


//! �ر���Ϸ�����������ȷ����Ϣ��������Ϸ����,������ά����ˣ�GMserver��
struct NET_S2C_close : public tag_net_message 
{  
	NET_S2C_close ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_S2C_close" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_error_code; 
};  


//! ǿ�йر���Ϸ�������������Ϣ��������ά����ˣ�GMserver����������Ϸ���籾����ά����RTService��
struct NET_LS2S_close : public tag_net_message 
{ 
	NET_LS2S_close ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_LS2S_close" ) ; 
		dw_size = sizeof ( * this ) ;   
	}    
};  


//! ǿ�йر���Ϸ�����������ȷ����Ϣ��������Ϸ���籾����ά����RTService��,������ά����ˣ�GMserver��
struct NET_LS2C_close : public tag_net_message
{  
	NET_LS2C_close ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_LS2C_close" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_error_code;   
};  


//! ������Ϸ�������������Ϣ��������ά����ˣ�GMserver����������Ϸ���籾����ά����RTService��
struct NET_LS2S_start : public tag_net_message
{  
	NET_LS2S_start ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_LS2S_start" ) ;  
		dw_size = sizeof ( * this ) ;   
	}    
};  


//! ������Ϸ�����������ȷ����Ϣ��������Ϸ���籾����ά����RTService��,������ά����ˣ�GMserver��
struct NET_LS2C_start : public tag_net_message
{ 
	NET_LS2C_start ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_LS2C_start" ) ;  
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_error_code;  
};  

//! ��ʱ���ظ�����ά�������ķ�����״̬��Ϣ��������Ϸ���磬������ά����ˣ�GMserver��
struct NET_S2C_world_info : public tag_net_message
{   
	NET_S2C_world_info ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_S2C_world_info" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	E_world_status e_status;   
	INT n_online_num;			//��Ϸ������������ 4
	INT n_max_online_num;    	//��Ϸ��������������� 4
};  



//! ˫������	��������ά����ˣ�GMserver����������Ϸ����
struct NET_S2S_double : public tag_net_message 
{ 
	NET_S2S_double ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_S2S_double" ) ;   
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_client_id;  
	E_double_type eDType;  
	DWORD dwLastTime;  //ʱ�� tagDWORDTime
	DWORD dwOpenTime;  //����ʱ��
	DWORD dwRatio;   	//����
};  



struct NET_S2C_double : public tag_net_message 
{  
	NET_S2C_double ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_S2C_double" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_client_id;
	DWORD dw_error_code;   
};  

//! ȡ��˫������	��������ά����ˣ�GMserver����������Ϸ����
struct NET_S2S_cancel_double : public tag_net_message
{   
	NET_S2S_cancel_double ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_S2S_cancel_double" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_client_id;  
};  

struct NET_S2C_cancel_double : public tag_net_message 
{  
	NET_S2C_cancel_double ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_S2C_cancel_double" ) ;
		dw_size = sizeof ( * this ) ;   
	}
	DWORD dw_client_id; 
	DWORD dw_error_code;   
};  


//! �Զ�ѭ������ ��������ά����ˣ�GMserver����������Ϸ����
struct NET_S2S_auto_notice : public tag_net_message 
{  
	NET_S2S_auto_notice ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_S2S_auto_notice" ) ;
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_client_id;					//����
	TCHAR sz_content[Notice_Content];	//��ɫ
	E_color_type e_type;				//ѭ�����
	INT n_cir_interval;   
	//INT				nCirNum;		//ѭ������
};  

struct NET_S2C_auto_notice : public tag_net_message
{  
	NET_S2C_auto_notice ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_S2C_auto_notice" ) ; 
		dw_size = sizeof ( * this ) ;    
	} 
	DWORD dw_client_id;  
	DWORD dw_error_code;   
};  

//! ���½ǹ��� ��������ά����ˣ�GMserver����������Ϸ����
struct NET_S2S_right_notice : public tag_net_message 
{ 
	NET_S2S_right_notice ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_S2S_right_notice" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_client_id; 
	TCHAR sz_title[Notice_Title];  		//����
	TCHAR sz_content[Notice_Content];	//����
	TCHAR sz_link[Notice_Link];			//���ӵ���վ
};  


struct NET_S2C_right_notice : public tag_net_message 
{  
	NET_S2C_right_notice ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_S2C_right_notice" ) ; 
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_client_id;  
	DWORD dw_error_code;  
};  

//! ȡ�����½�	��������ά����ˣ�GMserver����������Ϸ����
struct NET_S2S_cancel_right_notice : public tag_net_message
{  
	NET_S2S_cancel_right_notice ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_S2S_cancel_right_notice" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_client_id;    
};  

struct NET_S2C_cancel_right_notice : public tag_net_message 
{  
	NET_S2C_cancel_right_notice ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_S2C_cancel_right_notice" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_client_id;  
	DWORD dw_error_code; 
};  

//! ϵͳָ����Ϣ ��������ά����ˣ�GMserver����������Ϸ�����RTservice
struct NET_LS2S_system_cmd : public tag_net_message 
{  
	NET_LS2S_system_cmd ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_LS2S_system_cmd" ) ; 
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_client_id; 
	TCHAR sz_cmd[System_Cmd_Length];  
};  

struct NET_LS2C_system_cmd : public tag_net_message 
{ 
	NET_LS2C_system_cmd ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_LS2C_system_cmd" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_client_id;  
	DWORD dw_error_code;    
};  

//! �޸����������������Ϣ ��������ά����ˣ�GMserver����������Ϸ����
struct NET_S2S_max_number : public tag_net_message
{ 
	NET_S2S_max_number ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_S2S_max_number" ) ;  
		dw_size = sizeof ( * this ) ;    
	} 
	DWORD dw_client_id;  
	INT n_max_num;   
};  

struct NET_S2C_max_number : public tag_net_message 
{  
	NET_S2C_max_number ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_S2C_max_number" ) ;
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_client_id; 
	DWORD dw_error_code;   
};  

//! �����̳� ��������ά����ˣ�GMserver����������Ϸ����
struct NET_S2S_Update_mall : public tag_net_message 
{  
	NET_S2S_Update_mall ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_S2S_Update_mall" ) ;  
		dw_size = sizeof ( * this ) ;    
	} 
	DWORD dw_client_id;    
};  

struct NET_S2C_update_mall : public tag_net_message 
{ 
	NET_S2C_update_mall ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_S2C_update_mall" ) ; 
		dw_size = sizeof ( * this ) ;  
	}
	DWORD dw_client_id; 
	DWORD dw_error_code; 
};  



//! ��� ����GMServer ����LoginServer
struct NET_S2S_forbid_account : public tag_net_message 
{   
	NET_S2S_forbid_account ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_S2S_forbid_account" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_client_id;  
	TCHAR sz_account[LONG_STRING]; 
	TCHAR sz_world[X_SHORT_NAME]; 
	BOOL b_forbid;    //0:��� 1:��
};  

//! ��� ����LoginServer ����GMServer 
struct NET_S2C_forbid_account : public tag_net_message
{   
	NET_S2C_forbid_account ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_S2C_forbid_account" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_client_id;  
	TCHAR sz_account[X_SHORT_NAME];  
	DWORD dw_error_code;   
};  


//! ��IP ����GMServer ����LoginServer
struct NET_S2S_forbid_ip : public tag_net_message 
{  
	NET_S2S_forbid_ip ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_S2S_forbid_ip" ) ;
		dw_size = sizeof ( * this ) ;    
	}
	DWORD dw_client_id; 
	DWORD dw_ip;  
	BOOL b_forbid;   
};  

//! ��IP ����LoginServer ����GMServer 
struct NET_S2C_forbid_ip : public tag_net_message 
{ 
	NET_S2C_forbid_ip ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_S2C_forbid_ip" ) ; 
		dw_size = sizeof ( * this ) ;    
	}
	DWORD dw_client_id;   
	DWORD dw_error_code;     
};  

//! ����Ƶ���Զ����棬������ά����ˣ�GMserver����������Ϸ����
struct NET_S2S_auto_chat_notice : public tag_net_message
{   
	NET_S2S_auto_chat_notice ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_S2S_auto_chat_notice" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_client_id; 
	TCHAR sz_notice[HUGE_STRING];   
};  

struct NET_S2C_auto_chat_notice : public tag_net_message 
{  
	NET_S2C_auto_chat_notice ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_S2C_auto_chat_notice" ) ;  
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_client_id;  
	DWORD dw_error_code;  
};  

#pragma pack(pop)