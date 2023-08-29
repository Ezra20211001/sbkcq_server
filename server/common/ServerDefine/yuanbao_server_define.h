
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//元宝交易
#pragma once

#pragma pack(push)
#pragma pack(1)

#include "../../common/WorldDefine/currency_define.h"
#include "../../common/WorldDefine/mall_define.h"

//! 读取所有玩家的元宝交易账户
struct NET_DB2C_load_all_yuanbao_account : public tag_net_message 
{  
	NET_DB2C_load_all_yuanbao_account ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_all_yuanbao_account" ) ; 
		dw_size = sizeof ( * this ) ;
	}    
};  


struct NET_DB2S_load_all_yuanbao_account : public tag_net_message 
{  
	NET_DB2S_load_all_yuanbao_account ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_all_yuanbao_account" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	INT n_count;  
	tagYBAccount account[1]; 
};  

struct NET_DB2C_insert_account : public tag_net_message
{
	NET_DB2C_insert_account ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_insert_account" ) ; 
		dw_size = sizeof ( * this ) ;
	} 
	DWORD dw_role_id; // 创建一个元宝交易账户
}; 

struct NET_DB2C_syn_account_yanbao : public tag_net_message 
{ 
	NET_DB2C_syn_account_yanbao ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_syn_account_yanbao" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_role_id;  // 同步元宝交易账户元宝数
	INT n_yuanbao;  
};  

struct NET_DB2C_syn_account_silver : public tag_net_message 
{  
	NET_DB2C_syn_account_silver ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_syn_account_silver" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_role_id; // 同步元宝交易账户金钱数
	tagMoney money;   
};  

struct NET_DB2C_syn_submit_sell : public tag_net_message 
{ 
	NET_DB2C_syn_submit_sell ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_syn_submit_sell" ) ;
		dw_size = sizeof ( * this ) ; 
	}   
	DWORD dw_role_id;  // 同步元宝交易账户出售订单的状态
	bool b_sell_order;
};  

struct NET_DB2C_syn_submit_buy : public tag_net_message 
{ 
	NET_DB2C_syn_submit_buy ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_syn_submit_buy" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_role_id;	// 同步元宝交易账户收购订单的状态
	bool b_buy_order;  
};  

// 读取所有玩家的元宝交易账单
struct NET_DB2C_load_all_order : public tag_net_message
{   
	NET_DB2C_load_all_order ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_load_all_order" ) ; 
		dw_size = sizeof ( * this ) ;  
	}     
};  

struct NET_DB2S_load_all_order : public tag_net_message
{   
	NET_DB2S_load_all_order ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_load_all_order" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	INT n_count;   
	DWORD dw_max_order_id;  
	tagYuanBaoOrder yuanbao_order[1]; 
};  

// 创建元宝交易订单
struct NET_DB2C_insert_order : public tag_net_message
{  
	NET_DB2C_insert_order ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_insert_order" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	tagYBOrder yb_order;    
};  

struct NET_DB2C_complete_order : public tag_net_message 
{   
	NET_DB2C_complete_order ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_complete_order" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	tagCompleteOrder complete_order;   
};  


struct NET_DB2C_refresh_order : public tag_net_message 
{   
	NET_DB2C_refresh_order ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_refresh_order" ) ; 
		dw_size = sizeof ( * this ) ; 
	} 
	tagRefresh refresh_order;   
};  

struct NET_DB2C_get_role_yuanbao_order : public tag_net_message 
{  
	NET_DB2C_get_role_yuanbao_order ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_get_role_yuanbao_order" ) ;  
		dw_size = sizeof ( * this ) ;   
	}
	DWORD dw_role_id;     
};  

struct NET_DB2S_get_role_yuanbao_order : public tag_net_message 
{   
	NET_DB2S_get_role_yuanbao_order ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2S_get_role_yuanbao_order" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	INT n_count; 
	tagYuanBaoOrder yuanbao_order[1];   
};  

// 删除数据库中时间超过七天的所有订单
struct NET_DB2C_delete_yuanbao_order : public tag_net_message
{  
	NET_DB2C_delete_yuanbao_order ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_yuanbao_order" ) ;   
		dw_size = sizeof ( * this ) ;    
	} 
	DWORD dw_delete_time;  
};  

#pragma pack(pop)