/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

/**
*	@file		paimai_define.h
*	@author		lc
*	@date		2011/03/17	initial
*	@version	0.0.1.0
*	@brief		拍卖行结构，消息定义
*/

#ifndef PAIMAI_DEFINE
#define PAIMAI_DEFINE

#pragma pack(push, 1)

// 游戏服务器登陆拍卖行
struct NET_G2P_Login : public tag_net_message
{
	NET_G2P_Login()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_G2P_Login");
		dw_size = sizeof(NET_G2P_Login);
	}
	TCHAR	sz_ServerName[X_SHORT_NAME];
};

struct NET_P2G_Login : public tag_net_message
{
	NET_P2G_Login()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_P2G_Login");
		dw_size = sizeof(NET_P2G_Login);
	}
	DWORD	dw_Error;
};


// 索取验证码
struct NET_W2C_verify_code : public tag_net_message
{
	NET_W2C_verify_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_W2C_verify_code");
		dw_size = sizeof(NET_W2C_verify_code);
	}
	DWORD	dw_account_id;
};


struct NET_C2W_verify_code : public tag_net_message
{
	NET_C2W_verify_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2W_verify_code");
		dw_size = sizeof(NET_C2W_verify_code);
	}
	DWORD	dw_account_id;
	DWORD	dw_error_code;
	DWORD	dw_type;			// 策略类型 0:猜字符 1:算术运算 2:相同字
	DWORD	dw_param;			// 额外的参数
	DWORD	dw_answer_crc;		// 答案
	INT		n_verify_code_size;
	BYTE	by_code[1];
};

#pragma pack(pop)

#endif