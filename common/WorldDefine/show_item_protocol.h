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
*	@file		show_item_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		展示物品消息
*/


#ifndef SHOW_ITEM_PROTOCOL
#define SHOW_ITEM_PROTOCOL

#include "protocol_common_errorcode.h"
#include "ItemDefine.h"
#include "container_define.h"

#pragma pack(push, 1)

//错误码
enum
{
	E_RoleShowItem_ForbidChat			    = 1,				//禁止展示
	E_RoleShowItem_ServerNotReady			= 2,				//服务器没有准备好
	E_RoleShowItem_SendFailure			    = 3,				//发送物品失败
	E_RoleShowItem_Frequently			    = 4,				//展示过快

	E_RoleShowItem_World_NoItem				= 20,				//世界,没有道具
	E_RoleShowItem_World_NoMoney			= 21,				//世界,没有足够银两

	E_RoleShowItem_Pvt_RemoteRoleLeave		= 30,				//私聊,对方不在线
	E_RoleShowItem_Pvt_NoRoleName			= 31,				//私聊,没有目标玩家 
	E_RoleShowItem_Pvt_NoSelf				= 32,				//私聊,自己不能与自己私聊

	E_RoleShowItem_Guild_NoJoin				= 40,				//门派,没有门派

	E_RoleShowItem_Troop_NoJoin				= 50,				//队伍,没有队伍
};

//-----------------------------------------------------------------------------
//	展示装备
//-----------------------------------------------------------------------------
struct NET_SIC_role_show_equip : public tag_net_message
{
	NET_SIC_role_show_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_show_equip");
		dw_size = sizeof(NET_SIC_role_show_equip);
	}
	DWORD		 dwDestRoleID;	// 对谁展示
	BYTE		 byChannel;		// 展示频道
	EItemConType eConType;      // 装备位置(背包等等)
	INT64		 n64_serial;		// 装备64位ID
	TCHAR		 szMsg[1];
};

struct NET_SIS_role_show_equip : public tag_net_message
{
	NET_SIS_role_show_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_show_equip");
		dw_size = sizeof(NET_SIS_role_show_equip);
	}
	DWORD		dwSrcRoleID;	// 是谁展示 INVALID_VALUE代表系统发送
	DWORD		dwDestRoleID;	// 是对谁展示
	BYTE		byChannel;		// 展示频道
	BYTE		bGM;
	DWORD		dw_error_code;	// 错误码
	SHORT		sEquipSize;		// 装备信息
	SHORT		sMsgSize;		// 聊天信息
	BYTE	    byBuffer[1];	// 装备结构 tagEquip
};


//-----------------------------------------------------------------------------
//	展示物品
//-----------------------------------------------------------------------------
struct NET_SIC_role_show_item : public tag_net_message
{
	NET_SIC_role_show_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_show_item");
		dw_size = sizeof(NET_SIC_role_show_item);
	}
	DWORD		 dwDestRoleID;	// 对谁展示
	BYTE		 byChannel;		// 展示频道
	EItemConType eConType;		// 物品位置(背包等等)
	INT64		 n64_serial;		// 物品64位ID
	TCHAR		 szMsg[1];
};

struct NET_SIS_role_show_item : public tag_net_message
{
	NET_SIS_role_show_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_show_item");
		dw_size = sizeof(NET_SIS_role_show_item);
	}
	DWORD		dwSrcRoleID;	// 是谁展示 INVALID_VALUE代表系统发送
	DWORD		dwDestRoleID;	// 是对谁展示
	BYTE		byChannel;		// 展示频道
	BYTE		bGM;
	DWORD		dw_error_code;	// 错误码
	DWORD	    dw_data_id;		// 物品TypeID tagItem
	TCHAR		szMsg[1];
};


#pragma pack(pop)
#endif