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
*	@file		verification_protocol.h
*	@author		lc
*	@date		2012/02/06	initial
*	@version	0.0.1.0
*	@brief		在线验证码消息
*/


#ifndef VERIFICATION_PROTOCOL
#define VERIFICATION_PROTOCOL

#pragma pack(push, 1)


// 验证错误码
enum 
{
	E_VERIFICATION_OK			=	0,		// 验证成功

	E_VERIFICATION_ERROR		=	1,		// 验证码错误
};

//重置验证码
struct NET_SIC_reset_verification_code : public tag_net_message
{
	NET_SIC_reset_verification_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reset_verification_code");
		dw_size = sizeof(NET_SIC_reset_verification_code);
	}
};

struct NET_SIS_reset_verification_code : public tag_net_message
{
	NET_SIS_reset_verification_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reset_verification_code");
		dw_size = sizeof(NET_SIS_reset_verification_code);
	}
	//DWORD	dwVerificationCodeKey;
	//BYTE	byStrCode[8];			// 验证码加密后
	BYTE	byVerificationCodeIndex;
	DWORD	dwType;					// 策略类型 0:猜字符 1:算术运算 2:相同字
	INT		n_verify_code_size;
	BYTE	by_code[1];
};


// 需要验证了
struct NET_SIS_need_verification : public tag_net_message
{
	NET_SIS_need_verification()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_need_verification");
		dw_size = sizeof(NET_SIS_need_verification);
	}
	//DWORD	dwVerificationCodeKey;	// 验证码key
	//BYTE	byStrCode[8];			// 验证码加密后
	//BYTE	byVerificationCodeIndex;// 验证码的索引
	BYTE	byCount;				// 验证剩余次数
	DWORD	dwTime;					// 验证剩余时间
};


// 验证回复
struct NET_SIC_need_verification_return : public tag_net_message
{
	NET_SIC_need_verification_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_need_verification_return");
		dw_size = sizeof(NET_SIC_need_verification_return);
	}
	DWORD	dwVerificationCodeCrc;
};

struct NET_SIS_need_verification_return : public tag_net_message
{
	NET_SIS_need_verification_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_need_verification_return");
		dw_size = sizeof(NET_SIS_need_verification_return);
	}
	DWORD	dw_error_code;
	//DWORD	dw_new_key;
	//BYTE	byStrCode[8];	// 验证码加密后
	//BYTE	by_new_index;
};

// 进入验证准备阶段
struct NET_SIS_relay_verification : public tag_net_message
{
	NET_SIS_relay_verification()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_relay_verification");
		dw_size = sizeof(NET_SIS_relay_verification);
	}

	DWORD	dwTime;					// 验证准备剩余时间
};


// 进入正式验证
struct NET_SIC_goto_verification : public tag_net_message
{
	NET_SIC_goto_verification()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_goto_verification");
		dw_size = sizeof(NET_SIC_goto_verification);
	}
};

#pragma pack(pop)

#endif