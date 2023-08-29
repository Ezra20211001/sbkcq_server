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
*	@file		motion_protocol.h
*	@author		lc
*	@date		2011/03/08	initial
*	@version	0.0.1.0
*	@brief		角色动作消息
*/

#ifndef MOTION_PROTOCOL
#define MOTION_PROTOCOL

#pragma pack(push, 1)

enum 
{
	E_Motion_Success			= 0,
	E_Motion_NotValid			= 1,	// 动作无效
	E_Motion_CanotActive		= 2,	// 无法进行交互
	E_Motion_FriendValNotEnough	= 3,	// 友好度不满足
	E_Motion_DistanceNotEnough	= 4,	// 距离不够
	E_Motion_RoleNotFround		= 5,	// 人物没找到
	E_Motion_DstRoleRefuse		= 6,	// 目标玩家拒绝
};

/*******************************************************************************
交互流程：
	验证阶段：
		1.客户端发NET_SIC_double_motion_invite请求服务器
		2.服务器进行判断，若通过，则发NET_SIS_double_motion_on_invite给被请求玩家
		3.被请求玩家选择是否接受发送NET_SIC_double_motion_on_invite给服务器
		4.服务器发送NET_SIS_double_motion_invite给请求玩家结果
	开始动作：
		5.请求玩家收到NET_SIS_double_motion_invite，跑到被请求玩家处
		6.请求玩家向服务器发送NET_SIC_double_motion_start开始双人动作
		7.服务器广播，双人动作开始	
*******************************************************************************/

//------------------------------------------------------------------------------
// 最大距离
//------------------------------------------------------------------------------
CONST INT MAX_MOTION_DIST	= 50 * 10;

//----------------------------------------------------------------------------
// 客户端表演个性动作
//----------------------------------------------------------------------------
struct NET_SIC_role_style_action : public tag_net_message
{
	NET_SIC_role_style_action()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_style_action");
		dw_size = sizeof(NET_SIC_role_style_action);
	}
	DWORD			dwActionID;
};

struct NET_SIS_role_style_action : public tag_net_message
{
	NET_SIS_role_style_action()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_style_action");
		dw_size = sizeof(NET_SIS_role_style_action);
	}
	DWORD			dw_role_id;
	DWORD			dwDstRoleID;
	DWORD			dwActionID;
};


//------------------------------------------------------------------------------
// 双人动作 主动邀请的消息
//------------------------------------------------------------------------------
struct NET_SIC_double_motion_invite : public tag_net_message
{
	NET_SIC_double_motion_invite()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_double_motion_invite");
		dw_size = sizeof(NET_SIC_double_motion_invite);
	}
	DWORD	dwDstRoleID;	// 目标玩家id
	DWORD	dwActionID;		// 动作id
};

struct NET_SIS_double_motion_invite : public tag_net_message
{
	NET_SIS_double_motion_invite()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_double_motion_invite");
		dw_size = sizeof(NET_SIS_double_motion_invite);
	}
	DWORD	dwErrCode;		// 错误码
};

//------------------------------------------------------------------------------
// 双人动作 被邀请的消息
//------------------------------------------------------------------------------
struct NET_SIS_double_motion_on_invite : public tag_net_message
{
	NET_SIS_double_motion_on_invite()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_double_motion_on_invite");
		dw_size = sizeof(NET_SIS_double_motion_on_invite);
	}
	DWORD	dwSrcRoleID;	// 发起玩家id
	DWORD	dwActionID;		// 动作id
};

struct NET_SIC_double_motion_on_invite : public tag_net_message
{
	NET_SIC_double_motion_on_invite()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_double_motion_on_invite");
		dw_size = sizeof(NET_SIC_double_motion_on_invite);
	}
	DWORD	dwSrcRoleID;	// 发起玩家id
	DWORD	dwActionID;		// 动作id
	BOOL	bAccpet;		// 是否同意
};

//------------------------------------------------------------------------------
// 双人动作 开始动作
//------------------------------------------------------------------------------
struct NET_SIC_double_motion_start : public tag_net_message
{
	NET_SIC_double_motion_start()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_double_motion_start");
		dw_size = sizeof(NET_SIC_double_motion_start);
	}
	DWORD	dwDstRoleID;	// 目标玩家id
	DWORD	dwActionID;		// 动作id
};



#pragma pack(pop)
#endif