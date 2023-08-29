
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//任务相关

#pragma once

#pragma pack(push)
#pragma pack(1)
//-----------------------------------------------------------------------------

#include "../../common/WorldDefine/QuestDef.h"
//-----------------------------------------------------------------------------


//! 接取任务
struct NET_DB2C_accept_quest : public tag_net_message // 接取任务 World ---> DB
{   
	NET_DB2C_accept_quest ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_accept_quest" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_role_id;   // 角色ID
	tagAcceptQuest accept_quest_; 
};  

struct NET_DB2S_accept_quest : public tag_net_message // 接取任务 World <--- DB 暂时没有返回值
{ 
	NET_DB2S_accept_quest ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_accept_quest" ) ;
		dw_size = sizeof ( * this ) ;     
	} 
};  


//! 完成任务
struct NET_DB2C_complete_quest : public tag_net_message // 完成任务 World ---> DB
{   
	NET_DB2C_complete_quest ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_complete_quest" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_role_id;   // 角色ID
	tagQuestDoneSave quest_done_;    
};  


struct NET_DB2S_complete_quest : public tag_net_message // 完成任务 World <--- DB 暂时没有返回值
{  
	NET_DB2S_complete_quest ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_complete_quest" ) ;  
		dw_size = sizeof ( * this ) ;  
	}    
};  


//! 删除任务
struct NET_DB2C_discard_quest : public tag_net_message// 放弃任务 World ---> DB
{
	NET_DB2C_discard_quest ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_discard_quest" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_role_id;		// 角色ID
	UINT16 u16_quest_id_;   // 任务ID
};  



struct NET_DB2S_discard_quest : public tag_net_message 	// 放弃任务 World <--- DB
{  
	NET_DB2S_discard_quest ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_discard_quest" ) ; 
		dw_size = sizeof ( * this ) ;   
	}   
};  


//! 每天6点删除quest&quest_done表中的每日任务
struct NET_DB2C_clear_day_quest : public tag_net_message//World ---> DB
{
	NET_DB2C_clear_day_quest ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_clear_day_quest" ) ; 
		dw_size = sizeof ( * this ) ;  
	}
}; 

#pragma pack(pop)
