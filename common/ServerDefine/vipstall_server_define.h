
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//VIP摊位服务器消息格式
#pragma once

#include "../common/WorldDefine/stall_define.h"

#pragma pack(push, 1)

struct s_vip_stall_to_db
{
	DWORD	dw_owner_id;
	INT32	n_remain_time;
	BYTE	by_stall_index;

	s_vip_stall_to_db()
	{
		dw_owner_id		= INVALID_VALUE;
		n_remain_time		= INVALID_VALUE;
		by_stall_index	= INVALID_VALUE;
	}
};

struct NET_DB2C_get_all_vip_stall_info : public tag_net_message 
{ 
	NET_DB2C_get_all_vip_stall_info ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_get_all_vip_stall_info" ) ; 
		dw_size = sizeof ( * this ) ;  
	}   
};  

struct NET_DB2S_get_all_vip_stall_info : public tag_net_message 
{   
	NET_DB2S_get_all_vip_stall_info ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_get_all_vip_stall_info" ) ;  
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_error_code; 
	s_vip_stall_to_db vip_stall_info[VIP_STALL_MAX_NUM];   
};  


struct NET_DB2C_apply_vip_stall : public tag_net_message 
{   
	NET_DB2C_apply_vip_stall ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_apply_vip_stall" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	s_vip_stall_to_db vip_stall_info; 
};  


struct NET_DB2C_update_vip_stall : public tag_net_message 
{ 
	NET_DB2C_update_vip_stall ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_vip_stall" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
};  

#pragma pack(pop)