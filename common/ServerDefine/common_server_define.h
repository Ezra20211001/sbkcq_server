/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

 角色通用数据消息
*******************************************************************************/


#ifndef _COMMON_SERVER_DEFINE_H_
#define _COMMON_SERVER_DEFINE_H_

#pragma pack(push, 1)
//-----------------------------------------------------------------------------

//! 更改包裹密码
struct NET_DB2C_change_bag_password : public tag_net_message
{   
	NET_DB2C_change_bag_password ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_change_bag_password" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_account_id; 
	DWORD dw_bag_password;  
};  


//! 设置安全吗
struct NET_DB2C_safe_code_set : public tag_net_message 
{  
	NET_DB2C_safe_code_set ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_safe_code_set" ) ; 
		dw_size = sizeof ( * this ) ;
	}  
	DWORD dw_account_id;
	DWORD dw_safe_code_crc;  
};  

//CMD_START(NDBS_SafeCodeSet)
//	DWORD		dw_error_code;
//CMD_END

//! 重设安全码
struct NET_DB2C_safe_code_reset : public tag_net_message 
{ 
	NET_DB2C_safe_code_reset ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_safe_code_reset" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_account_id; 
	DWORD dw_reset_time;   
};  

//! 取消安全码
struct NET_DB2C_safe_code_reset_cancel : public tag_net_message 
{  
	NET_DB2C_safe_code_reset_cancel ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_safe_code_reset_cancel" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_account_id;  
};  

//! 包裹大小更新
struct NET_DB2C_ware_size_update : public tag_net_message
{   
	NET_DB2C_ware_size_update ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_ware_size_update" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_account_id; 
	INT16 n16_ware_size; 
	INT16 n16_ware_step;
};  

//! 金钱更新
struct NET_DB2C_ware_money_update : public tag_net_message 
{   
	NET_DB2C_ware_money_update ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_ware_money_update" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_account_id; 
	INT64 n64_ware_silver; 
};  

//! 更新非绑定币
struct NET_DB2C_bag_money_update : public tag_net_message
{
	NET_DB2C_bag_money_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_bag_money_update");
		dw_size = sizeof(*this);
	}

	DWORD	dw_role_id;
	INT				n_bag_gold_;					// 背包中金子数
	INT				n_bag_silver_;					// 背包中银子数
	INT				n_bag_copper_;					// 背包中铜数
};

//! 元宝更新
struct NET_DB2C_baibao_yuanbao_update : public tag_net_message 
{  
	NET_DB2C_baibao_yuanbao_update ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_baibao_yuanbao_update" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_account_id; 
	INT nBaiBaoYuanBao;   
};  

//! 积分更新
struct NET_DB2C_exchange_volume_update : public tag_net_message
{
	NET_DB2C_exchange_volume_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_exchange_volume_update");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
	INT		n_volume;
};

// 更新奖品领取标志
struct NET_DB2C_update_receive : public tag_net_message
{
	NET_DB2C_update_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_receive");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
};

// 更新奖品领取标志
struct NET_DB2C_update_receive_ex : public tag_net_message
{
	NET_DB2C_update_receive_ex()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_receive_ex");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
	DWORD	dw_receive_type;
};

// 更新网页领奖标志
struct NET_DB2C_update_web_recieve : public tag_net_message
{
	NET_DB2C_update_web_recieve()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_web_recieve");
		dw_size = sizeof(*this);
	}

	DWORD	dw_account_id;
};

// 删除序列号礼包
struct NET_DB2C_delete_serial_reward : public tag_net_message
{
	NET_DB2C_delete_serial_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_delete_serial_reward");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
	CHAR	sz_serial[X_SHORT_NAME];
};


//-----------------------------------------------------------------------------
#pragma pack(pop)

#endif