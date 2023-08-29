
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//直充服务器与游戏世界的借口

#pragma once

//! 游戏世界登陆
struct tagNWB_Login : public tag_net_message 
{  
	tagNWB_Login ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NWB_Login" ) ;  
		dw_size = sizeof ( * this ) ; 
	} 
	TCHAR sz_world_name[X_SHORT_NAME]; 
};  

struct tagNBW_Login : public tag_net_message 
{  
	tagNBW_Login ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NBW_Login" ) ;  
		dw_size = sizeof ( * this ) ;  
	}
	DWORD dw_error_code;  
};  

//! 告知游戏世界取百宝袋
struct tagNBW_PickBaiBao : public tag_net_message
{  
	tagNBW_PickBaiBao ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NBW_PickBaiBao" ) ;   
		dw_size = sizeof ( * this ) ;  
	} 
	/*INT64 n64_serial;*/
	DWORD dw_account_id;  
	INT32 n32_yuanbao;
	DWORD dw_recharge_num;
};  

// 通知游戏世界更新领奖标志
struct tagNBW_ChangeReceive : public tag_net_message
{
	tagNBW_ChangeReceive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NBW_ChangeReceive");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
};

// 通知游戏世界更新序列号礼包
struct tagNBW_UpdateSerialReward : public tag_net_message
{
	tagNBW_UpdateSerialReward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NBW_UpdateSerialReward");
		dw_size = sizeof(*this);
	}

	DWORD dw_account_id;
	INT	  n_type;
	CHAR  sz_serial[X_SHORT_NAME];
};

// 通知重新加载自动拍卖
struct tagNBW_ReloadAutoPaimai : public tag_net_message
{
	tagNBW_ReloadAutoPaimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NBW_ReloadAutoPaimai");
		dw_size = sizeof(*this);
	}
};
