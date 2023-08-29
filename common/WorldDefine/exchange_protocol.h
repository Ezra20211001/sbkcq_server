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
*	@file		exchange_protocol.h
*	@author		lc
*	@date		2011/03/02	initial
*	@version	0.0.1.0
*	@brief		角色交易消息
*/


#ifndef EXCHANGE_PROTOCOL
#define EXCHANGE_PROTOCOL

#include "protocol_common_errorcode.h"
#include "ItemDefine.h"

#pragma pack(push, 1)
//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum
{
	E_Exchange_Accept				= E_Success,	// 对方同意交易
	E_Exchange_Refuse				= 1,	// 对方拒绝		
	E_Exchange_NotEnough_BagSpace	= 2,	// 背包空间不足
	E_Exchange_RoleBusy				= 3,	// 被申请方忙	
	E_Exchange_WithMore				= 4,	// 不能和多人同时交易
	E_Exchange_OutOfRange			= 5,	// 交易距离范围之外
	E_Exchange_NotInSame_Map		= 6,	// 不在同一区域
	E_Exchange_ItemCanNot_Exchange	= 7,	// 物品不能交易
	E_Exchange_ItemCanNot_Find		= 8,	// 没有找到指定数量的物品
	E_Exchange_NotEnough_Money		= 9,	// 交易的金钱不足
	E_Exchange_ApplicantTgt_Change	= 10,	// 交易申请的交易目标发生变化
	E_Exchange_NotAnswer			= 11,	// 对方没有响应
	E_Exchange_SelfBusy				= 12,	// 玩家自己忙
	E_Exchange_Trage_InDuel = 13, // 对方正在进行切磋。
	E_Exchange_NotInSafearea = 14,//交易双方需均在安全区内
};



// 玩家请求交换物品
struct NET_SIC_exchange_request : public tag_net_message
{
	NET_SIC_exchange_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_exchange_request");
		dw_size = sizeof(NET_SIC_exchange_request);
	}
	DWORD	dwDstID;	// 消息目标ID
};

struct NET_SIS_exchange_request : public tag_net_message
{
	NET_SIS_exchange_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_request");
		dw_size = sizeof(NET_SIS_exchange_request);
	}
	DWORD	dwSrcID;	// 消息发起者ID
};

// 目标玩家交易请求反馈
struct NET_SIC_exchange_request_result : public tag_net_message
{
	NET_SIC_exchange_request_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_exchange_request_result");
		dw_size = sizeof(NET_SIC_exchange_request_result);
	}
	DWORD	dw_error_code;
	DWORD	dwDstID;
};

// 服务器转发给目标玩家交易请求反馈
struct NET_SIS_exchange_request_result : public tag_net_message
{
	NET_SIS_exchange_request_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_request_result");
		dw_size = sizeof(NET_SIS_exchange_request_result);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;
	DWORD	dwDstID;
};

// 添加交易的物品装备
struct NET_SIC_add_exchange : public tag_net_message
{
	NET_SIC_add_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_add_exchange");
		dw_size = sizeof(NET_SIC_add_exchange);
	}
	INT64	n64_serial;	// 只需要64位序号,服务器负责初始化物品具体信息
};

struct NET_SIS_add_exchange_to_src : public tag_net_message
{
	NET_SIS_add_exchange_to_src()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_exchange_to_src");
		dw_size = sizeof(NET_SIS_add_exchange_to_src);
	}
	DWORD	dw_error_code;
	DWORD	dwDstID;
	INT64	n64_serial;
	INT32	nIndex;
};

struct NET_SIS_add_exchange_to_dest : public tag_net_message
{
	NET_SIS_add_exchange_to_dest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_exchange_to_dest");
		dw_size = sizeof(NET_SIS_add_exchange_to_dest);
	}
	DWORD	dwSrcID;
	INT32	nIndex;
	BYTE	byData[SIZE_EQUIP];	// 物品或装备(需要通知对方装备的详细信息)
};

// 取消交易的物品装备
struct NET_SIC_cancel_exchange_item : public tag_net_message
{
	NET_SIC_cancel_exchange_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_exchange_item");
		dw_size = sizeof(NET_SIC_cancel_exchange_item);
	}
	INT64	n64_serial;
};

struct NET_SIS_cancel_exchange_item : public tag_net_message
{
	NET_SIS_cancel_exchange_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_exchange_item");
		dw_size = sizeof(NET_SIS_cancel_exchange_item);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;
	DWORD	dwDstID;
	INT64	n64_serial;
};

struct NET_SIC_exchange_money : public tag_net_message
{
	NET_SIC_exchange_money()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_exchange_money");
		dw_size = sizeof(NET_SIC_exchange_money);
	}
	INT64	n64Money;
};

struct NET_SIS_exchange_money : public tag_net_message
{
	NET_SIS_exchange_money()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_money");
		dw_size = sizeof(NET_SIS_exchange_money);
	}
	DWORD	dw_error_code;	
	INT64	n64Money;
	DWORD	dwSrcID;
};

struct NET_SIC_exchange_item_lock : public tag_net_message
{
	NET_SIC_exchange_item_lock()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_exchange_item_lock");
		dw_size = sizeof(NET_SIC_exchange_item_lock);
	}
};

struct NET_SIS_exchange_item_lock : public tag_net_message
{
	NET_SIS_exchange_item_lock()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_item_lock");
		dw_size = sizeof(NET_SIS_exchange_item_lock);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;
};

// 取消交易
struct NET_SIC_exchange_cancel : public tag_net_message
{
	NET_SIC_exchange_cancel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_exchange_cancel");
		dw_size = sizeof(NET_SIC_exchange_cancel);
	}
};

struct NET_SIS_exchange_cancel : public tag_net_message
{
	NET_SIS_exchange_cancel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_cancel");
		dw_size = sizeof(NET_SIS_exchange_cancel);
	}
	DWORD	dwSrcID;
};

// 玩家确认交易
struct NET_SIC_exchange_verify : public tag_net_message
{
	NET_SIC_exchange_verify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_exchange_verify");
		dw_size = sizeof(NET_SIC_exchange_verify);
	}
	DWORD	dw_safe_code;
};

// 交易完成
struct NET_SIS_exchange_finish : public tag_net_message
{
	NET_SIS_exchange_finish()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_finish");
		dw_size = sizeof(NET_SIS_exchange_finish);
	}
	DWORD	dw_error_code;
	DWORD	dwFailedRoleID;		// 导致失败者ID
};


//----------------------------------------------------------------------------
#pragma pack(pop)
#endif