
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//服务器用称号相关结构


#pragma once

#include "role_data_server_define.h"

#pragma pack(push, 1)


const INT TITLE_UPDATA_TIME		=	60 * 60 * TICK_PER_SECOND; //称号更新间隔

// 称号存储数据
struct s_title_save
{
	UINT16			n_title_id_;		// 称号ID
	DWORD			dw_state_mark_;		// 若为0，则表示已获取，否则表示para2
	tagDWORDTime	dw_time;			// 称号获得时间
};


// 角色称号提醒(用来通知数据库)
struct NET_DB2C_title_insert : public tag_net_message 
{  
	NET_DB2C_title_insert ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_title_insert" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id;  	// 角色ID
	s_title_save s_title_save_;	// 称号信息
};  


// 角色称号提醒(用来通知数据库)
struct NET_DB2C_title_delete : public tag_net_message 
{  
	NET_DB2C_title_delete ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_title_delete" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id;  	// 角色ID
	DWORD dw_title_id;	// 称号id
}; 


#pragma pack(pop)