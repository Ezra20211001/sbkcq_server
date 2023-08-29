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
*	@file		celeb_protocol.h
*	@author		lc
*	@date		2011/03/02	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef CELEB_PROTOCOL
#define CELEB_PROTOCOL

#pragma pack(push, 1)

#include "reputation.h"
#include "famehall_define.h"
//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum
{
	E_FrameHall_Success					= 0,	// 成功
	E_FrameHall_MemberOrderUnchanged	= 1,	// 名人堂成员列表无变化
	E_FrameHall_RepOrderUnchanged		= 2,	// 声望排名无变化
	E_FrameHall_ItemIsNotTreasure		= 3,	// 物品不是珍宝
	E_FrameHall_TreasureAlreadyAct		= 4,	// 珍宝已激活
	E_FrameHall_ActCountNotEnough		= 5,	// 激活次数不够
	E_FrameHall_ClanColNotEnough		= 6,	// 氏族贡献不够
	E_FrameHall_UnknownError			,		// 未知错误
};


//----------------------------------------------------------------------------
// 获取进入名人堂前50个角色列表
//----------------------------------------------------------------------------
struct NET_SIC_celeb_role : public tag_net_message
{
	NET_SIC_celeb_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_celeb_role");
		dw_size = sizeof(NET_SIC_celeb_role);
	}
	BYTE		byClanType;				// 氏族类型
	DWORD		dwUpdateTime;			// 更新时间戳 tagDWORDTime
};

struct NET_SIS_celeb_role : public tag_net_message
{
	NET_SIS_celeb_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_celeb_role");
		dw_size = sizeof(NET_SIS_celeb_role);
	}
	BYTE		eClanType;				// 氏族类型EClanType
	BYTE		byErrCode;				// 是否列表无变化则为E_FrameHall_MemberOrderUnchanged
	DWORD		dwUpdateTime;			// 最后更新时间戳
	BYTE		byRoleNum;				// 氏族名人堂列表数量(上限50)
	BYTE		byData[1];				// 成员nameID列表数据(DWORD)
};


//----------------------------------------------------------------------------
// 声望前50个角色列表
//----------------------------------------------------------------------------
struct NET_SIC_reputation_top : public tag_net_message
{
	NET_SIC_reputation_top()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reputation_top");
		dw_size = sizeof(NET_SIC_reputation_top);
	}
	BYTE 		byClanType;				// 氏族类型
	DWORD		dwUpdateTime;			// 更新时间戳 tagDWORDTime
};

struct NET_SIS_reputation_top : public tag_net_message
{
	NET_SIS_reputation_top()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reputation_top");
		dw_size = sizeof(NET_SIS_reputation_top);
	}
	BYTE		byClanType;				// 氏族类型EClanType
	BYTE		byErrCode;				// 是否列表无变化则为E_FrameHall_RepOrderUnchanged
	DWORD		dwUpdateTime;			// 最后更新时间戳
	BYTE		byRoleNum;				// 每氏族名人堂列表数量(上限50)
	BYTE		byData[1];				// 变长列表数据(tagRepRankData)
};


//----------------------------------------------------------------------------
// 获得氏族所有激活珍宝
//----------------------------------------------------------------------------
struct NET_SIC_get_activation_gens_treasure : public tag_net_message
{
	NET_SIC_get_activation_gens_treasure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_activation_gens_treasure");
		dw_size = sizeof(NET_SIC_get_activation_gens_treasure);
	}
	BYTE		byClanType;				// 氏族类型EClanType
};

struct NET_SIS_get_activation_gens_treasure : public tag_net_message
{
	NET_SIS_get_activation_gens_treasure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_activation_gens_treasure");
		dw_size = sizeof(NET_SIS_get_activation_gens_treasure);
	}
	BYTE		byClanType;				// 氏族类型EClanType
	INT16		n16ActTreasureNum;		// 已激活珍宝数量
	BYTE		byData[1];				// 数据tagTreasureData
};


//----------------------------------------------------------------------------
// 新激活氏族珍宝通知
//----------------------------------------------------------------------------
struct NET_SIS_new_activation_treasure : public tag_net_message
{
	NET_SIS_new_activation_treasure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_new_activation_treasure");
		dw_size = sizeof(NET_SIS_new_activation_treasure);
	}
	INT16		n16TreasureID;
	DWORD		dwNameID;
};

//----------------------------------------------------------------------------
// 激活氏话珍宝
//----------------------------------------------------------------------------
struct NET_SIC_activation_treasure : public tag_net_message
{
	NET_SIC_activation_treasure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_activation_treasure");
		dw_size = sizeof(NET_SIC_activation_treasure);
	}
	UINT16		u16TreasureID;			// 珍宝ID
};

struct NET_SIS_activation_treasure : public tag_net_message
{
	NET_SIS_activation_treasure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_activation_treasure");
		dw_size = sizeof(NET_SIS_activation_treasure);
	}
	DWORD		dwErrCode;				// 错误码
	UINT16		u16TreasureID;			// 珍宝ID
};


#pragma pack(pop)
#endif