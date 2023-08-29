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
*	@file		pet_exchange_protocot.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		宠物交易消息
*/

#ifndef PET_EXCHANGE_PROTOCOL
#define PET_EXCHANGE_PROTOCOL

#include "protocol_common_errorcode.h"

#pragma pack(push, 1)
//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum
{
    E_Pet_Exchange_Accept				= E_Success,	// 对方同意交易
    E_Pet_Exchange_Refuse				= 1,	// 对方拒绝		
    E_Pet_Exchange_NotEnough_Space	    = 2,	// 宠物栏空间不足
    E_Pet_Exchange_RoleBusy				= 3,	// 被申请方忙	
    E_Pet_Exchange_WithMore				= 4,	// 不能和多人同时交易
    E_Pet_Exchange_OutOfRange			= 5,	// 交易距离范围之外
    E_Pet_Exchange_NotInSame_Map		= 6,	// 不在同一区域
    E_Pet_Exchange_PetCanNot_Exchange	= 7,	// 宠物不能交易
    E_Pet_Exchange_PetCanNot_Find		= 8,	// 没有找到指定的宠物
    E_Pet_Exchange_NotEnough_Money		= 9,	// 交易的金钱不足
    E_Pet_Exchange_ApplicantTgt_Change	= 10,	// 交易申请的交易目标发生变化
    E_Pet_Exchange_NotAnswer			= 11,	// 对方没有响应
    E_Pet_Exchange_SelfBusy				= 12,	// 玩家自己忙

	E_Pet_Exchange_PetHasEquip			= 20,	// 宠物有装备
	E_Pet_Exchange_RoleLvlNotEnough		= 21,	// 目标玩家等级不够
	E_Pet_Exchange_PetLocked			= 22,	// 宠物被锁定
	E_Pet_Exchange_PetBinded			= 23,	// 宠物被绑定
	E_Pet_Exchange_PetStateNotAllow		= 24,	// 宠物状态不允许

    E_Pet_Exchange_End
};




//----------------------------------------------------------------------------
// 交易握手
//----------------------------------------------------------------------------

// 玩家请求交换宠物
struct NET_SIC_pet_exchange_request : public tag_net_message
{
	NET_SIC_pet_exchange_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_request");
		dw_size = sizeof(NET_SIC_pet_exchange_request);
	}
	 DWORD	dwDstID;	// 消息目标ID
};

// 服务器转发给目标玩家
struct NET_SIS_pet_exchange_request : public tag_net_message
{
	NET_SIS_pet_exchange_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_request");
		dw_size = sizeof(NET_SIS_pet_exchange_request);
	}
	DWORD	dwSrcID;	// 消息发起者ID
};


// 目标玩家交易请求反馈
struct NET_SIC_pet_exchange_request_result : public tag_net_message
{
	NET_SIC_pet_exchange_request_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_request_result");
		dw_size = sizeof(NET_SIC_pet_exchange_request_result);
	}
	DWORD	dw_error_code;
	DWORD	dwDstID;
};


// 服务器转发给双方玩家交易请求反馈
struct NET_SIS_pet_exchange_request_result : public tag_net_message
{
	NET_SIS_pet_exchange_request_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_request_result");
		dw_size = sizeof(NET_SIS_pet_exchange_request_result);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;    // 发起者id
	DWORD	dwDstID;    // 目标id
};

//----------------------------------------------------------------------------
// 交易过程
//----------------------------------------------------------------------------


// 添加交易的宠物
struct NET_SIC_pet_exchange_add : public tag_net_message
{
	NET_SIC_pet_exchange_add()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_add");
		dw_size = sizeof(NET_SIC_pet_exchange_add);
	}
	 DWORD	dwPetID;
};

// 反馈，如成功则本地添加
struct NET_SIS_pet_exchange_add_to_src : public tag_net_message
{
	NET_SIS_pet_exchange_add_to_src()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_add_to_src");
		dw_size = sizeof(NET_SIS_pet_exchange_add_to_src);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;        // 添加发起者id
	DWORD	dwDstID;
	DWORD	dwPetID;
};


// 如成功则通知目标玩家添加宠物
struct NET_SIS_exchange_add_to_dest : public tag_net_message
{
	NET_SIS_exchange_add_to_dest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_add_to_dest");
		dw_size = sizeof(NET_SIS_exchange_add_to_dest);
	}
	DWORD	dwSrcID;        // 对方发起者id
	DWORD	dwPetID;
};


// 取消交易的宠物
struct NET_SIC_pet_exchange_subtract : public tag_net_message
{
	NET_SIC_pet_exchange_subtract()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_subtract");
		dw_size = sizeof(NET_SIC_pet_exchange_subtract);
	}
	DWORD	dwSrcID;        // 添加发起者id
	DWORD	dwPetID;
};


// 反馈，如成功则本地减少
struct NET_SIS_pet_exchange_subtract : public tag_net_message
{
	NET_SIS_pet_exchange_subtract()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_subtract");
		dw_size = sizeof(NET_SIS_pet_exchange_subtract);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;        // 减少发起者id
	DWORD	dwDstID;
	DWORD	dwPetID;
};


// 如成功则通知目标玩家取消宠物
struct NET_SIS_pet_exchange_subtract_to_dest : public tag_net_message
{
	NET_SIS_pet_exchange_subtract_to_dest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_subtract_to_dest");
		dw_size = sizeof(NET_SIS_pet_exchange_subtract_to_dest);
	}
	DWORD	dwSrcID;        // 减少发起者id
	DWORD	dwPetID;
};


// 金钱发生改变 
struct NET_SIC_pet_exchange_money : public tag_net_message
{
	NET_SIC_pet_exchange_money()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_money");
		dw_size = sizeof(NET_SIC_pet_exchange_money);
	}
	INT64	n64Money;
};


// 通知双方
struct NET_SIS_pet_exchange_money : public tag_net_message
{
	NET_SIS_pet_exchange_money()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_money");
		dw_size = sizeof(NET_SIS_pet_exchange_money);
	}
	DWORD	dw_error_code;	
	INT64	n64Money;
	DWORD	dwSrcID;       // 改变金钱发起者id
};

// 锁定交易宠物
struct NET_SIC_pet_exchange_lock : public tag_net_message
{
	NET_SIC_pet_exchange_lock()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_lock");
		dw_size = sizeof(NET_SIC_pet_exchange_lock);
	}
};


// 通知双方
struct NET_SIS_pet_exchange_lock : public tag_net_message
{
	NET_SIS_pet_exchange_lock()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_lock");
		dw_size = sizeof(NET_SIS_pet_exchange_lock);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;       // 锁定交易发起者id
};


// 取消交易
struct NET_SIC_pet_exchange_cancel : public tag_net_message
{
	NET_SIC_pet_exchange_cancel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_cancel");
		dw_size = sizeof(NET_SIC_pet_exchange_cancel);
	}
};


// 通知双方
struct NET_SIS_pet_exchange_cancel : public tag_net_message
{
	NET_SIS_pet_exchange_cancel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_cancel");
		dw_size = sizeof(NET_SIS_pet_exchange_cancel);
	}
	 DWORD	dwSrcID;        // 取消交易发起者id
};


// 玩家确认交易
struct NET_SIC_pet_exchange_verify : public tag_net_message
{
	NET_SIC_pet_exchange_verify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_verify");
		dw_size = sizeof(NET_SIC_pet_exchange_verify);
	}
};


// 交易完成
struct NET_SIS_pet_exchange_finish : public tag_net_message
{
	NET_SIS_pet_exchange_finish()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_finish");
		dw_size = sizeof(NET_SIS_pet_exchange_finish);
	}
	DWORD	dw_error_code;
	DWORD	dwFailedRoleID;		// 导致失败者ID
};


//----------------------------------------------------------------------------
#pragma pack(pop)
#endif