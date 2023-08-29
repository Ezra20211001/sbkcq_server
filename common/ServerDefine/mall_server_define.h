
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//商城相关

#pragma once

#pragma pack(push)
#pragma pack(1)
//-----------------------------------------------------------------------------

enum
{
	edbl_group_purchase_faild		= 1,		// 读取帮派团购信息失败
};


//! 传输用结构
struct s_gp_info_key
{
	DWORD			dw_guild_id;
	DWORD			dw_role_id;
	DWORD			dw_mall_id;
};

struct s_gp_info : public s_gp_info_key 
{
	INT32			n_price;			//团购价格
	INT16			n_participator_num;	//响应人数
	INT16			n_require_num;		//团购所需人数
	INT32			n_remain_time;		//剩余时间
	DWORD			dw_participators[1];	//响应者列表

	INT32 size()
	{
		return sizeof(s_gp_info) + (n_participator_num-1) * sizeof(DWORD);
	}
};


struct NET_DB2C_get_all_gp_info : public tag_net_message
{   
	NET_DB2C_get_all_gp_info ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_get_all_gp_info" ) ; 
		dw_size = sizeof ( * this ) ;   
	}   
};  

struct NET_DB2S_get_all_gp_info : public tag_net_message 
{  
	NET_DB2S_get_all_gp_info ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_get_all_gp_info" ) ; 
		dw_size = sizeof ( * this ) ;    
	} 
	DWORD dw_error_code;   
	INT n_gp_info_num_;   
	s_gp_info gp_info_data_[1];     
};  

struct NET_DB2C_add_gp_info : public tag_net_message
{ 
	NET_DB2C_add_gp_info ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_add_gp_info" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	s_gp_info gp_info;    
};  

struct NET_DB2C_remove_gp_info : public tag_net_message 
{  
	NET_DB2C_remove_gp_info ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_remove_gp_info" ) ; 
		dw_size = sizeof ( * this ) ;  
	}   
	s_gp_info_key gp_info_key_;
};  

struct NET_DB2C_remove_guild_gp_info : public tag_net_message
{   
	NET_DB2C_remove_guild_gp_info ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_remove_guild_gp_info" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_guild_id;   
};  

struct NET_DB2C_update_gp_info : public tag_net_message 
{   
	NET_DB2C_update_gp_info ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_gp_info" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	s_gp_info_key gp_info_key_; 
	DWORD dw_new_participator_;     
};  

struct NET_DB2C_update_gp_time : public tag_net_message
{   
	NET_DB2C_update_gp_time ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_update_gp_time" ) ; 
		dw_size = sizeof ( * this ) ;   
	}   
};  

//-----------------------------------------------------------------------------
#pragma pack(pop)
