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
*	@file		pk_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		pk消息
*/


#ifndef PK_PROTOCOL
#define PK_PROTOCOL

#include "protocol_common_errorcode.h"
#include "RoleDefine.h"
#include "currency_define.h"

#pragma pack(push, 1)

// 20级一下PK保护
const INT KILLBUFFID = 3000401;
const INT PKLEVELMIN = 1;
const INT KILLBADGEITEMCD = 5 * 60; // 5m
const INT KILLBADGEITEMCD_TICK = KILLBADGEITEMCD * TICK_PER_SECOND;
#define  KILLNOTICEUSEMONEY  (GOLD2SILVER * 10)
enum
{
	E_SafeGuard_Already			=	1,		// 已经是当前状态
	E_SafeGuard_PKStateInvalid	=	2,		// PK状态为非和平状态，不能切换到保护模式
	E_SafeGuard_TimeLimit		=	3,		// 距离上次开启自由模式的时间未到，不能切换到保护模式
	E_SafeGuard_LevelLimit		=	4,		// 等级限制
	E_SafeGuard_ItemLimit		=	5,		// 使用的IM物品限制，无法切换到保护模式

	E_PK_LevelOutOf20		= 11,		// PK等级限制
	E_PK_StartLimit				=   12,		// pk状态受限不能变化
	E_PK_StateLimit				=	13,		// 战斗状态限制
	E_PK_AreaLimit				=	15,		// PK区域限制
	E_PK_RedNameLimit			=	17,		// 红名限制
	E_PK_GuildLimit				=	18,		// 家族限制

	E_UseKillbadgeItem_TargetOffLine =	19,// 使用追杀令时,目标不在线
	E_UseKillbadgeItem_TargetInPrision	=	20,// 使用追杀令时,目标在牢狱
	E_UseKillbadgeItem_TargetNotRedName	=	21,// 使用追杀令时,对方不是红名
	E_UseKillbadgeItem_CDLimited		=	22,// 5分钟之内只能使用一次追杀令
};
//-----------------------------------------------------------------------------
// 设置pk值
//-----------------------------------------------------------------------------
struct NET_SIS_change_pk_value : public tag_net_message
{
	NET_SIS_change_pk_value()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_pk_value");
		dw_size = sizeof(NET_SIS_change_pk_value);
	}
	DWORD		dw_role_id;				//角色ID
	INT			iPKValue;
	//BOOL		bIsPurpureDec;
};

//-----------------------------------------------------------------------------
// 设置pk状态
//-----------------------------------------------------------------------------
struct NET_SIC_change_pk_value : public tag_net_message
{
	NET_SIC_change_pk_value()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_change_pk_value");
		dw_size = sizeof(NET_SIC_change_pk_value);
	}
	ERolePKState	eState;						// 新的PK状态
};

struct NET_SIS_change_pk_state : public tag_net_message
{
	NET_SIS_change_pk_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_pk_state");
		dw_size = sizeof(NET_SIS_change_pk_state);
	}
	DWORD				dw_role_id;
	ERolePKState		ePKState;
	DWORD				dwError;
};

struct NET_SIC_use_skill_badge_item : public tag_net_message
{
	NET_SIC_use_skill_badge_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_use_skill_badge_item");
		dw_size = sizeof(NET_SIC_use_skill_badge_item);
	}
	DWORD dwTarget;
};

struct NET_SIS_use_skill_badge_item : public tag_net_message
{
	NET_SIS_use_skill_badge_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_use_skill_badge_item");
		dw_size = sizeof(NET_SIS_use_skill_badge_item);
	}
	DWORD dwError;
};

#pragma pack(pop)
#endif
