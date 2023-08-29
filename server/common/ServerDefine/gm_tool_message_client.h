
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//GM服务端与GM工具之间的消息定义

#pragma once

#include "../../common/WorldDefine/base_define.h"
#include "gm_tool_define.h"
#include "rt_define.h"

#pragma pack(push, 1)

//!GM创建
struct NET_GM2C_gm_create : public tag_net_message 
{  
	NET_GM2C_gm_create ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_gm_create" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	TCHAR sz_name[X_SHORT_NAME];	//帐号
	DWORD dw_password_crc;			//密码CRC
	EPrivilege e_privilege;			//权限
};  

struct NET_GM2S_gm_create : public tag_net_message
{   
	NET_GM2S_gm_create ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_gm_create" ) ;
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_error_code;    
};  

//!GM修改
struct NET_GM2C_gm_modify : public tag_net_message 
{   
	NET_GM2C_gm_modify ( ) 
	{
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GM2C_gm_modify" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	TCHAR sz_name[X_SHORT_NAME];  //帐号
	EPrivilege e_privilege;  //权限
};  


struct NET_GM2S_gm_modify : public tag_net_message 
{  
	NET_GM2S_gm_modify ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GM2S_gm_modify" ) ;   
		dw_size = sizeof ( * this ) ; 
	}
	DWORD dw_error_code;   
};  

//!GM删除
struct NET_GM2C_gm_delete : public tag_net_message 
{  
	NET_GM2C_gm_delete ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_gm_delete" ) ;   
		dw_size = sizeof ( * this ) ; 
	}   
	TCHAR sz_name[X_SHORT_NAME];   	//帐号
};  

struct NET_GM2S_gm_delete : public tag_net_message 
{  
	NET_GM2S_gm_delete ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_gm_delete" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;   
};  

//! 角色恢复
struct NET_GM2C_role_resume : public tag_net_message 
{  
	NET_GM2C_role_resume ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GM2C_role_resume" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	INT n_old_id;  //角色原来的ID
	TCHAR sz_new_name[X_SHORT_NAME];//角色新起的名字
	DWORD dw_section_id;  //大区ID
	DWORD dw_world_id;     //游戏世界ID
};  


struct NET_GM2S_role_resume : public tag_net_message 
{  
	NET_GM2S_role_resume ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_role_resume" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_error_code;   
};  

//! 角色属性修改
struct NET_GM2C_promodify : public tag_net_message 
{  
	NET_GM2C_promodify ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_GM2C_promodify" ) ;
		dw_size = sizeof ( * this ) ;     
	}  
	TCHAR sz_name[X_SHORT_NAME];  //角色名字
	INT n_level;  //等级
	INT n_skill;  //天资点
	INT n_yuanbao; //元宝
	INT64 n64_exp; //经验
	INT64 n64_money;  //钱	
	DWORD dw_section_id;   //大区ID
	DWORD dw_world_id;   //游戏世界ID
};  


struct NET_GM2S_promodify : public tag_net_message
{ 
	NET_GM2S_promodify ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_promodify" ) ; 
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_error_code; 
};  


//!物品生成
struct NET_GM2C_item_create : public tag_net_message 
{  
	NET_GM2C_item_create ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GM2C_item_create" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	TCHAR sz_name[X_SHORT_NAME];  //角色
	DWORD dw_item_type_id;   //物品TypeID
	INT n_item_num;  //数量
	BYTE by_quality;   //品质
	DWORD dw_section_id;  //大区ID
	DWORD dw_world_id;   //游戏世界ID
};  

struct NET_GM2S_item_create : public tag_net_message 
{ 
	NET_GM2S_item_create ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_item_create" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_error_code; 
};  

//!物品删除
struct NET_GM2C_item_delete : public tag_net_message
{  
	NET_GM2C_item_delete ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GM2C_item_delete" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	TCHAR sz_name[X_SHORT_NAME];  //角色
	INT64 n64_item_id;  //物品全局ID
	DWORD dw_section_id;  //大区ID
	DWORD dw_world_id;   //游戏世界ID
};  


struct NET_GM2S_item_delete : public tag_net_message 
{  
	NET_GM2S_item_delete ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_item_delete" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code; 
};  

//!物品恢复
struct NET_GM2C_item_resume : public tag_net_message
{  
	NET_GM2C_item_resume ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_GM2C_item_resume" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	INT64 n64_serial_num;  //物品全局ID
	TCHAR sz_target_role[X_SHORT_NAME];  //目标角色名
	DWORD dw_section_id;  //大区ID
	DWORD dw_world_id;    //游戏世界ID
};  


struct NET_GM2S_item_resume : public tag_net_message
{  
	NET_GM2S_item_resume ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_item_resume" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;  
};  

//! 账号封停
struct NET_GM2C_account_forbid : public tag_net_message 
{  
	NET_GM2C_account_forbid ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_account_forbid" ) ;  
		dw_size = sizeof ( * this ) ; 
	} 
	TCHAR sz_account_str[LONG_STRING]; //账号串,各账号之间逗号分隔
	TCHAR sz_section_name[X_SHORT_NAME];  //大区
	TCHAR sz_world_name[X_SHORT_NAME]; //游戏世界
	INT n_action;  // 0:解封 1：封
};  


struct NET_GM2S_account_forbid : public tag_net_message 
{  
	NET_GM2S_account_forbid ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_account_forbid" ) ;
		dw_size = sizeof ( * this ) ;  
	}  
	TCHAR sz_account[X_SHORT_NAME]; 
	DWORD dw_error_code; 
};  

//!--双倍
struct NET_GM2C_double : public tag_net_message 
{  
	NET_GM2C_double ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_double" ) ; 
		dw_size = sizeof ( * this ) ;    
	}   
	E_double_type e_d_type; //开放时间
	DWORD dw_open_time;   //持续时长
	DWORD dw_last_time;  //比例
	DWORD dw_ration;  //大区ID,
	DWORD dw_section_id; 
	DWORD dw_world_id[1];  //世界	游戏世界ID[n]     代表该大区下所有游戏
};  

//!--右下角公告
struct NET_GM2C_right_notice : public tag_net_message 
{  
	NET_GM2C_right_notice ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_right_notice" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_notice_time;//公告时间 tagDWORDTime 0为即时
	TCHAR sz_tiele[Notice_Title];  //标题
	TCHAR sz_content[Notice_Content];  //内容
	TCHAR sz_link[Notice_Link];  //链接的网站
	DWORD dw_section_id;  //大区ID,
	DWORD dw_world_id[1];    //游戏世界ID[n]      游戏世界ID:INVALID_VALUE代表该大区下所有游戏世界											
};  


//! --自动循环公告
struct NET_GM2C_auto_notice : public tag_net_message
{   
	NET_GM2C_auto_notice ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_auto_notice" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	TCHAR sz_content[Notice_Content];	//内容
	E_color_type e_type;				//颜色
	INT n_time_interval;				//时间间隔
	INT n_cir_interval;					//循环间隔
	INT n_cir_num;						//循环次数
	DWORD dw_section_id;				//大区ID,
	DWORD dw_world_id[1];				//游戏世界ID[n]      游戏世界ID:INVALID_VALUE代表该大区下所有游戏世界	
};  


//!--与时间有关的返回消息
struct NET_GM2S_time_limited_msg : public tag_net_message
{  
	NET_GM2S_time_limited_msg ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_time_limited_msg" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	E_time_limited_msg e_type;  
	DWORD dw_error_code;// 0-成功
	DWORD dw_world_id;    
};  


//! 添加/删除黑名单IP
struct NET_GM2C_black_list : public tag_net_message
{   
	NET_GM2C_black_list ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_GM2C_black_list" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
	TCHAR sz_section_name[X_SHORT_NAME]; // 大区
	DWORD dw_ip;  // IP
	INT n_action;    // 0:解封 1：封
};  

struct NET_GM2S_black_list : public tag_net_message
{   
	NET_GM2S_black_list ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_GM2S_black_list" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_error_code;    
};  

//! 聊天频道自动公告
struct NET_GM2C_auto_chat_notice : public tag_net_message 
{   
	NET_GM2C_auto_chat_notice ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_auto_chat_notice" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	TCHAR sz_notice[HUGE_STRING];// 公告内容
	BYTE by_hour;  // 发送: 时
	BYTE by_minute;  // 发送: 分
	DWORD dw_section_id;// 大区ID
	DWORD dw_world_id[1];    // 游戏世界ID[n]      游戏世界ID:INVALID_VALUE代表该大区下所有游戏世界	// 发布时间
};  


struct NET_GM2S_aoto_chat_notice : public tag_net_message 
{   
	NET_GM2S_aoto_chat_notice ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_aoto_chat_notice" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_error_code;    
};  

//! 取消所有已设定聊天频道消息
struct NET_GM2C_cancel_auto_chat_notice : public tag_net_message 
{  
	NET_GM2C_cancel_auto_chat_notice ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_cancel_auto_chat_notice" ) ; 
		dw_size = sizeof ( * this ) ; 
	}   
};  

struct NET_GM2S_cancel_auto_chat_notice : public tag_net_message
{  
	NET_GM2S_cancel_auto_chat_notice ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_cancel_auto_chat_notice" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;  
};  

//! 取消所有计时消息
struct NET_GM2C_cancel_time_limited_msg : public tag_net_message 
{  
	NET_GM2C_cancel_time_limited_msg ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_cancel_time_limited_msg" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
};  

struct NET_GM2S_cancel_time_limited_msg : public tag_net_message 
{ 
	NET_GM2S_cancel_time_limited_msg ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_cancel_time_limited_msg" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;   
};  

//! 取消所有双倍设置
struct NET_GM2C_cancel_double_msg : public tag_net_message
{   
	NET_GM2C_cancel_double_msg ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_cancel_double_msg" ) ;
		dw_size = sizeof ( * this ) ;   
	}
};  

struct NET_GM2S_cancel_double_msg : public tag_net_message
{  
	NET_GM2S_cancel_double_msg ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_cancel_double_msg" ) ;  
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_error_code;    
};  

//! 取消所有已设定右下角
struct NET_GM2C_cancel_right_notice : public tag_net_message
{  
	NET_GM2C_cancel_right_notice ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_GM2C_cancel_right_notice" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
};  

struct NET_GM2S_cancel_right_notice : public tag_net_message 
{ 
	NET_GM2S_cancel_right_notice ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_cancel_right_notice" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;    
};  

#pragma pack(pop)
