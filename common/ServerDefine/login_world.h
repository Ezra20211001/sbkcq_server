
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//登陆服务器与区域服务器相关消息

#pragma once

#include "login_server_define.h"

#pragma pack(push, 1)

enum
{
	e_pl_num_limit				=	1,	// 超出人数限制

	e_pl_verify_code_error		=	11,	// 验证码错误
	e_pl_time_out				=	12,	// 超时
};

//! 区域服务器与登陆服务器认证消息
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

//! 心跳
struct NET_L2W_heart_beat : public tag_net_message 
{  
	NET_L2W_heart_beat ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_L2W_heart_beat" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
};  


//! 区域服务器通知登陆服务器当前服务器状态
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

//! 登陆服务器通知区域服务器帐号登入
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

//! 区域服务器通知登陆服务器帐号可以登入
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


//! 区域服务器通知登陆服务器玩家登入
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

//! 区域服务器通知登陆服务器玩家登出
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

//! 登陆服务器通知区域服务器踢出指定玩家(已经在区域服务器中的玩家再次登录时, 就要踢被区域服务器掉)
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

//! 区域服务器提出玩家时，通知给登陆服务器做记录
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


//! 区域服务器被关闭时，登陆服务器返回
struct NET_L2W_world_colsed : public tag_net_message 
{  
	NET_L2W_world_colsed ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_L2W_world_colsed" ) ;  
		dw_size = sizeof ( * this ) ; 
	}    
};  


//! 区域服务器被关闭时，通知给登陆服务器改变玩家登陆状态
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