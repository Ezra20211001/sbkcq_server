/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef _ACTIVITY_SERVER_DEFINE_H_
#define _ACTIVITY_SERVER_DEFINE_H_

#pragma pack(push, 1)
struct s_activity_data
{
	DWORD							dw_id;		// !活动ID
	tagScriptData<ESD_Activity>		data;		// !活动脚本数据
};

//! 保存活动脚本
struct NET_DB2C_load_activity_data : public tag_net_message
{  
	NET_DB2C_load_activity_data ( ) 
	{
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_activity_data" ) ;   
		dw_size = sizeof ( * this ) ; 
	}    
};  

//! 读取活动脚本
struct NET_DB2S_load_activity_data : public tag_net_message 
{  
	NET_DB2S_load_activity_data ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_activity_data" ) ;   
		dw_size = sizeof ( * this ) ;   
	}   
	INT n_count;  
	s_activity_data activity[1]; 
};  

struct NET_DB2C_save_activity_data : public tag_net_message 
{   
	NET_DB2C_save_activity_data ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_save_activity_data" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	s_activity_data activity;   
};  

#pragma pack(pop)

#endif



