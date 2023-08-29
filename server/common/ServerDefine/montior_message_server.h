
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//运维服务端与游戏世界之间的消息定义

#pragma once
#include "../ServerDefine/login_server_define.h"
#include "../ServerDefine/montior_define.h"
#include "../ServerDefine/gm_tool_define.h"
#include "../../common/WorldDefine/base_define.h"

#pragma pack(push, 1)


//! 游戏服务器告诉运维服务器登入
struct NET_S2C_login_service : public tag_net_message 
{   
	NET_S2C_login_service ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_S2C_login_service" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_section_id;	// 大区ID
	DWORD dw_world_id;		// 游戏世界ID
	E_server_type e_type;   // 类型
};  


//! 运维服务器确认收到登入
struct NET_S2S_login_service : public tag_net_message 
{ 
	NET_S2S_login_service ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_S2S_login_service" ) ;   
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_error_code;  	// 0:成功
};  

//! 运维服务端（GMserver），发到游戏世界本地运维服务（RTService） 的登入消协
struct NET_LS2S_login_service : public tag_net_message 
{ 
	NET_LS2S_login_service ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_LS2S_login_service" ) ;   
		dw_size = sizeof ( * this ) ;   
	}  
	E_server_type e_type;    	// 类型
};  


//! 初始连接确认消息 发自游戏世界本地运维服务（RTService）,发到运维服务端（GMserver）
struct NET_LS2C_login_service : public tag_net_message
{  
	NET_LS2C_login_service ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_LS2C_login_service" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;    	// 0:成功
};  


//! 关闭游戏世界服务器的消息，发自运维服务端（GMserver），发到游戏世界
struct NET_S2S_close : public tag_net_message 
{  
	NET_S2S_close ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_S2S_close" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
};  


//! 关闭游戏世界服务器的确认消息，发自游戏世界,发到运维服务端（GMserver）
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


//! 强行关闭游戏世界服务器的消息，发自运维服务端（GMserver），发到游戏世界本地运维服务（RTService）
struct NET_LS2S_close : public tag_net_message 
{ 
	NET_LS2S_close ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_LS2S_close" ) ; 
		dw_size = sizeof ( * this ) ;   
	}    
};  


//! 强行关闭游戏世界服务器的确认消息，发自游戏世界本地运维服务（RTService）,发到运维服务端（GMserver）
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


//! 开启游戏世界服务器的消息，发自运维服务端（GMserver），发到游戏世界本地运维服务（RTService）
struct NET_LS2S_start : public tag_net_message
{  
	NET_LS2S_start ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_LS2S_start" ) ;  
		dw_size = sizeof ( * this ) ;   
	}    
};  


//! 开启游戏世界服务器的确认消息，发自游戏世界本地运维服务（RTService）,发到运维服务端（GMserver）
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

//! 定时返回给该运维服务程序的服务器状态消息，发自游戏世界，发到运维服务端（GMserver）
struct NET_S2C_world_info : public tag_net_message
{   
	NET_S2C_world_info ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_S2C_world_info" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	E_world_status e_status;   
	INT n_online_num;			//游戏世界在线人数 4
	INT n_max_online_num;    	//游戏世界最大在线人数 4
};  



//! 双倍设置	，发自运维服务端（GMserver），发到游戏世界
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
	DWORD dwLastTime;  //时间 tagDWORDTime
	DWORD dwOpenTime;  //开放时间
	DWORD dwRatio;   	//比例
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

//! 取消双倍设置	，发自运维服务端（GMserver），发到游戏世界
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


//! 自动循环公告 ，发自运维服务端（GMserver），发到游戏世界
struct NET_S2S_auto_notice : public tag_net_message 
{  
	NET_S2S_auto_notice ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_S2S_auto_notice" ) ;
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_client_id;					//内容
	TCHAR sz_content[Notice_Content];	//颜色
	E_color_type e_type;				//循环间隔
	INT n_cir_interval;   
	//INT				nCirNum;		//循环次数
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

//! 右下角公告 ，发自运维服务端（GMserver），发到游戏世界
struct NET_S2S_right_notice : public tag_net_message 
{ 
	NET_S2S_right_notice ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_S2S_right_notice" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_client_id; 
	TCHAR sz_title[Notice_Title];  		//标题
	TCHAR sz_content[Notice_Content];	//内容
	TCHAR sz_link[Notice_Link];			//链接的网站
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

//! 取消右下角	，发自运维服务端（GMserver），发到游戏世界
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

//! 系统指令消息 ，发自运维服务端（GMserver），发到游戏世界的RTservice
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

//! 修改最大在线人数的消息 ，发自运维服务端（GMserver），发到游戏世界
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

//! 更新商城 ，发自运维服务端（GMserver），发到游戏世界
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



//! 封号 发自GMServer 发往LoginServer
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
	BOOL b_forbid;    //0:解封 1:封
};  

//! 封号 发自LoginServer 发往GMServer 
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


//! 封IP 发自GMServer 发往LoginServer
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

//! 封IP 发自LoginServer 发往GMServer 
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

//! 聊天频道自动公告，发自运维服务端（GMserver），发到游戏世界
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