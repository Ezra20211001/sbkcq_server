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
 *	@file		fishing_protocol
 *	@author		mwh
 *	@date		2011/06/27	initial
 *	@version	0.0.1.0
 *	@brief		钓鱼协议
*/

#include "fishing_define.h"

#ifndef __FISHING_PROTOCOL_H__
#define __FISHING_PROTOCOL_H__
#pragma pack(push,1)

enum
{
	E_CantFishingNoBait = 1,		// 没有鱼饵
	E_CantFishingNoRod,				// 没有鱼竿
	E_CantFishingOutOfSpace,		// 空间不足
	E_CantFishingStateLimit,		// 状态限制
	E_CantFishingAreaLimit,			// 区域限制
	E_CantFishingNoSkill,			// 没学技能
	E_CantFishingNpcError,			// Npc错误
	E_CantFishingSkillLevel,		// 技能等级不够
	E_CantFishingOutOfLevel,   // 角色等级不够
	E_CantFishingOutOfVigour,		// 元气值不足
};

// 开始钓鱼
struct NET_SIC_Start_Fishing: public tag_net_message
{
	NET_SIC_Start_Fishing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Start_Fishing");
		dw_size = sizeof(*this);
	}
	DWORD dwNpcID;
	BOOL bAutoFish;			// 自动钓鱼
	DWORD dwSkill;			// 钓鱼技能
	INT64 n64Bait;			// 鱼饵
	INT64 n64FishingRod;	// 鱼竿
};

struct NET_SIS_Start_Fishing: public tag_net_message
{
	NET_SIS_Start_Fishing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Start_Fishing");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
};

// 结束钓鱼
struct NET_SIC_Stop_Fishing: public tag_net_message
{
	NET_SIC_Stop_Fishing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Stop_Fishing");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_Stop_Fishing: public tag_net_message
{
	NET_SIS_Stop_Fishing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Stop_Fishing");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
};

// 啥也没钓到
struct NET_SIS_Fishing_NullGet: public tag_net_message
{
	NET_SIS_Fishing_NullGet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Fishing_NullGet");
		dw_size = sizeof(*this);
	}
};

#pragma pack(pop)
#endif // __FISHING_PROTOCOL_H__