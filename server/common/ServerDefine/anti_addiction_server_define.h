
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/


#ifndef _ANTI_ADDICTION_SERVER_DEFINE_H_
#define _ANTI_ADDICTION_SERVER_DEFINE_H_


#include "login_server_define.h"

enum e_anti_addiction_state
{
	eaas_null		= -1,
	eaas_begin		= 0, 

	eaas_healthy	= 0,
	eaas_weary		= 1,
	eaas_sick		= 2,

	eaas_end,
	eaas_num			 = eaas_end,
};

#define EFS_VALID( state ) ((state) >= eaas_begin && (state) < eaas_end)

// 一分钟有多少秒
const INT SECOND_PER_MINITE =  60;

// 多长时间保存一次
const INT TIME_PER_SAVE_MINITE =  5;

struct s_anti_addiction_notify
{
	DWORD				dw_account_id;
	DWORD				dw_state;
	DWORD				dw_account_online_time_min;
};


struct s_anti_addiction_info
{
	DWORD				dw_account_name_crc;
	INT					n_account_online_time_min;
	INT					n_account_offline_time_min;
	BOOL				b_online;
	e_anti_addiction_state	e_last_state;
	BOOL				b_last_online;
	BOOL				b_need_save;

	s_anti_addiction_info()
	{
		dw_account_name_crc = 0;
		n_account_online_time_min = 0;
		n_account_offline_time_min = 0;
		b_online = FALSE;
		b_last_online = FALSE;
		b_need_save = FALSE;
		e_last_state = eaas_null;
	}

	VOID Update()
	{
		if (b_online)
		{
			n_account_online_time_min++;

			if (0 == (n_account_online_time_min % TIME_PER_SAVE_MINITE))
				b_need_save = TRUE;
		}

		else
		{
			if (n_account_online_time_min != 0)
			{
				n_account_offline_time_min++;
				//! 离线超过5小时
				if (n_account_offline_time_min >= 60 * 5)
				{
					n_account_offline_time_min = 0;
					n_account_online_time_min = 0;
				}

				if (0 == (n_account_offline_time_min % TIME_PER_SAVE_MINITE))
					b_need_save = TRUE;
			}
		}
	}

	BOOL				need_notify();
	BOOL				need_save()	{	return b_need_save;	}
	VOID				set_saved()	{	b_need_save = FALSE;	}
	e_anti_addiction_state	status();


};

inline BOOL s_anti_addiction_info::need_notify()
{
	if (!b_online)
		return FALSE;

	//! 第一次登入
	if(!b_last_online && b_online)
		return TRUE;

	//! 状态改变了
	e_anti_addiction_state eNewState = status();
	if (eNewState != e_last_state)
	{
		e_last_state = eNewState;
		return TRUE;
	}

	BOOL bNotify = FALSE;

	
	switch(e_last_state)
	{
	case eaas_healthy:
		bNotify = !(n_account_online_time_min % 60);
		break;
	case eaas_weary:
		bNotify = !(n_account_online_time_min % 30);
		break;
	case eaas_sick:
		bNotify = !(n_account_online_time_min % 15);
		break;
	}

	return bNotify;
}

inline e_anti_addiction_state s_anti_addiction_info::status()
{
	if (n_account_online_time_min >= 0 && n_account_online_time_min < 180)
	{
		return eaas_healthy;
	}
	else if (n_account_online_time_min >= 180 && n_account_online_time_min < 300)
	{
		return eaas_weary;
	}
	else
	{
		return eaas_sick;
	}
}

#pragma pack(push,1)


//! 登入服务器与中心激活服务器的防沉迷消息
struct tagNC_LOGIN_CM : public tag_net_message 
{  
	tagNC_LOGIN_CM ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NC_LOGIN_CM" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_section_id;    // 大区编号
};  

struct tagNC_ANTIQUERYSTATE : public tag_net_message 
{   
	tagNC_ANTIQUERYSTATE ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NC_ANTIQUERYSTATE" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	CHAR sz_account_name[16]; // 帐号名
};  

struct tag_Antienthrall
{
	CHAR sz_account_name[16];
	BOOL b_guard;
};

struct tagNC_ANTIENTHRALL : public tag_net_message 
{   
	tagNC_ANTIENTHRALL ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NC_ANTIENTHRALL" ) ;
		dw_size = sizeof ( * this ) ; 
	}   
	DWORD dw_account_num; // 帐号数目
	//CHAR sz_account_name[1]; // 帐号名
	tag_Antienthrall st_Antienthrall[1];
};  

struct tagNS_ANTIENTHRALL : public tag_net_message 
{   
	tagNS_ANTIENTHRALL ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NS_ANTIENTHRALL" ) ;  
		dw_size = sizeof ( * this ) ; 
	}  
	CHAR sz_account_name[16]; // 帐号名
	BYTE by_color;// 状态
	DWORD dw_account_online_seconds;  // 累计在线时间秒
};  


// 登入服务器与世界服务器的防沉迷消息
struct tagNLW_FatigueNotify : public tag_net_message 
{   
	tagNLW_FatigueNotify ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NLW_FatigueNotify" ) ; 
		dw_size = sizeof ( * this ) ;    
	}
	INT n_num; 
	s_anti_addiction_notify notify[1]; 
};  

#pragma pack(pop)

#endif