
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//运维服务端与客户端之间的消息定义

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


//! 连接初始消息，发自运维客户端（RtClient），发到运维服务器(GMserver)
struct NET_M2W_login_service : public tag_net_message 
{   
	NET_M2W_login_service ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_M2W_login_service" ) ;   
		dw_size = sizeof ( * this ) ;   
	}    
};  

//! 确认连接消息，发自运维服务器(GMserver)，发到运维服务器（Rtclient）
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

//! 关闭游戏世界服务器的消息，发自运维客户端（RtClient），发到运维服务器(GMserver)
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
	BOOL b_force;    //FALSE:主动关闭 //TRUE:强制关闭	
};  


//! 关闭游戏世界服务器的确认消息，发自运维服务器(GMserver)，发到运维客户端（RtClient）
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

//! 开启游戏世界服务器的消息，发自运维客户端（RtClient），发到运维服务器(GMserver)
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

//! 开启游戏世界服务器的确认消息，发自运维服务器(GMserver)，发到运维客户端（RtClient）
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

//! 变更账号绑定的IP地址
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

//! 服务器动态信息包消息，发自运维服务器(GMserver)，发到运维客户端（RtClient）
struct NET_W2M_all_server_dynainfo : public tag_net_message
{   
	NET_W2M_all_server_dynainfo ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_W2M_all_server_dynainfo" ) ;  
		dw_size = sizeof ( * this ) ;   
	} 
	INT n_section_num; //大区个数
	BYTE by_info[1];   //大区ID-login状态-world数量-world[n]ID-World[n]GameServer状态-World[n]DBServer状态
};  


//! 服务器静态信息包消息，发自运维服务器(GMserver)，发到运维客户端（RtClient）
struct NET_W2M_all_server_stat_info : public tag_net_message
{   
	NET_W2M_all_server_stat_info ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_W2M_all_server_stat_info" ) ;
		dw_size = sizeof ( * this ) ;  
	} 
	INT n_section_num; //大区个数
	BYTE by_info[1];    //大区名-大区ID-login IP-world数量-world[n]名字-world[n]ID-siGameServerIP-LoginServerIP
};  

//! 账号验证消息，发自运维客户端RtClient，发到运维服务器(GMserver)
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

//! 账号验证的确认信息，发自运维服务器(GMserver)，发到运维客户端（RtClient）
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

//! 权限信息，发自运维服务器(GMserver)，发到运维客户端（RtClient）
struct NET_W2M_privilege_info : public tag_net_message 
{ 
	NET_W2M_privilege_info ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_W2M_privilege_info" ) ;
		dw_size = sizeof ( * this ) ;    
	}   
	INT n_num;			// 权限对数量
	DWORD dw_info[1];	// 该数字的二进制形式的每一位分别代表各消息的执行权限
};  


//! 发送系统指令的消息，发自运维客户端RtClient，发到运维服务器(GMserver)
 struct NET_M2W_system_cmd : public tag_net_message
 {  
	 NET_M2W_system_cmd ( ) 
	 {  
		 ZeroMemory ( this , sizeof ( * this ) ) ; 
		 dw_message_id = message_id_crc ( "NET_M2W_system_cmd" ) ;   
		 dw_size = sizeof ( * this ) ;  
	 }  
	 DWORD dwSectionID;		//大区ID
	 E_server_type e_type;  //服务器类型
	 DWORD dw_world_id;	  //游戏世界ID,db不接受指令
	 TCHAR sz_cmd[System_Cmd_Length];   //系统指令
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


//! 更改最大在线人数，发自运维客户端RtClient，发到运维服务器(GMserver)
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


//! 更新商城，发自运维客户端RtClient，发到运维服务器(GMserver)
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
