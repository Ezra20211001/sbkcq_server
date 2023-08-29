
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//直充服务器与网站接口

#pragma once


#pragma pack(push, 1)

//! 登陆 1623520129
struct tagWeb2Bill_Login : public tag_net_message
{  
	tagWeb2Bill_Login ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "Web2Bill_Login" ) ;  //1623520129 size 124
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_glod_code;						// 验证码
	CHAR  sz_world_name[X_SHORT_NAME];		// 游戏世界名称
	CHAR  sz_trade_code[X_SHORT_NAME];		// 交易号
	CHAR  sz_account_name[X_SHORT_NAME];	// 账号名称
	CHAR  sz_serial_reward[X_SHORT_NAME];	// 礼包序列号
	INT	  n_serial_type;					// 序列礼包类型
	DWORD dw_recharge_num;					// 充值金额
	DWORD dw_account_id;					// 账号id
	DWORD dw_receive_type;					// 奖励类型
	INT	  n_type;							//1 充值 2 奖励 3 港序列礼包 4 媒体礼包
}; 

//! 重新加载自动拍卖 1190903304
struct tagWeb2Bill_reload_auto_paimai : public tag_net_message
{
	tagWeb2Bill_reload_auto_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("Web2Bill_reload_auto_paimai");
		dw_size = sizeof(*this);
	}
	DWORD dw_glod_code;
	CHAR  sz_world_name[X_SHORT_NAME];
};

//! 元宝划拨
struct tagNBS_YuanBao : public tag_net_message
{   
	tagNBS_YuanBao ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NBS_YuanBao" ) ; 
		dw_size = sizeof ( * this ) ;   
	}   
	CHAR sz_token_id[50];// 令牌ID
	DWORD dw_world_id;   // 游戏世界ID
	CHAR sz_account_name[50];  // 帐号名
	INT n_num;   // 元宝数量
};  
struct tagBill2Web_Login : public tag_net_message
{
	tagBill2Web_Login()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("Bill2Web_Login"); //1917453688 size 84
		dw_size = sizeof(*this);
	}

	DWORD	dw_error;
	DWORD	dw_account_id;
	CHAR  sz_trade_code[X_SHORT_NAME];		// 交易号
	CHAR  sz_account_name[X_SHORT_NAME];	// 账号名称
	INT	  n_type;							//1 充值 2 奖励 2 港序列礼包
};

// 网页充值信息
struct tag_web_recharge_info
{
	DWORD	dw_world_crc;		// 游戏世界crc值
	CHAR	sz_trade_code[X_SHORT_NAME];		// 交易号
	CHAR	sz_account_name[X_SHORT_NAME];		// 账号名称
	DWORD	dw_account_id;		// 账号id
	DWORD	dw_recharge_num;	// 充实金额
};

// 网页活动信息
struct tag_web_act_info
{
	DWORD	dw_world_crc;		// 游戏世界crc值
	CHAR	sz_account_name[X_SHORT_NAME];		// 账号名称
	DWORD	dw_account_id;		// 账号id
	DWORD	dw_web_type;		// 活动类型
};

// 港序列礼包
struct tag_serial_reward_info
{
	DWORD	dw_world_crc;		// 游戏时间crc值
	CHAR	sz_account_name[X_SHORT_NAME];		// 账号名称
	DWORD	dw_account_id;		// 账号id
	CHAR	sz_serial_reward[X_SHORT_NAME];		// 礼包序列号
	INT		n_type;				// 序列礼包类型
};

// 媒体礼包信息
struct tag_media_act_info
{
	DWORD	dw_world_crc;		// 游戏世界crc值
	CHAR	sz_account_name[X_SHORT_NAME];		// 账号名称
	DWORD	dw_account_id;		// 账号id
	DWORD	dw_type;			// 礼包类型
};

#pragma pack(pop)
