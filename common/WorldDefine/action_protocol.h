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
*	@file		action_protocol.h
*	@author		lc
*	@date		2011/02/28	initial
*	@version	0.0.1.0
*	@brief		角色移动消息
*/


#ifndef ACTION_PROTOCOL
#define ACTION_PROTOCOL

#include "protocol_common_errorcode.h"

#pragma pack(push, 1)

//! 鼠标走动
struct NET_SIC_mouse_walk : public tag_net_message
{
	NET_SIC_mouse_walk()
	{ 
		ZeroMemory(this, sizeof(*this)); 
		dw_message_id = message_id_crc("NET_SIC_mouse_walk");
		dw_size = sizeof(NET_SIC_mouse_walk);
	}
	Vector3	srcPos;
	Vector3	dstPos;
};

//！键盘走动
struct NET_SIC_keyboar_walk : public tag_net_message
{
	NET_SIC_keyboar_walk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_keyboar_walk");
		dw_size = sizeof(NET_SIC_keyboar_walk);
	}
	Vector3	srcPos;
	Vector3	dstPos;
};

//! 停止走动
struct NET_SIC_stop_walk : public tag_net_message
{
	NET_SIC_stop_walk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stop_walk");
		dw_size = sizeof(NET_SIC_stop_walk);
	}
	Vector3	curPos;
};

//! 同步角色行走
struct NET_SIS_synchronize_walk : public tag_net_message
{
	NET_SIS_synchronize_walk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_walk");
		dw_size = sizeof(NET_SIS_synchronize_walk);
	}
	DWORD	dw_role_id;
	Vector3	srcPos;
	Vector3	dstPos;
	FLOAT	curTime;
	FLOAT	fXZSpeed;
	bool	bCollide;

};


//! 同步站立，角色进入视野是发送
struct NET_SIS_synchronize_stand : public tag_net_message
{
	NET_SIS_synchronize_stand()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_stand");
		dw_size = sizeof(NET_SIS_synchronize_stand);
	}
	DWORD	dw_role_id;
	Vector3	curPos;
	Vector3	faceTo;
};

//！角色移动失败
struct NET_SIS_move_failed : public tag_net_message
{
	NET_SIS_move_failed()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_move_failed");
		dw_size = sizeof(NET_SIS_move_failed);
	}
	Vector3 curPos;
	Vector3 faceTo;
};

//! 角色被击飞
struct NET_SIS_hit_fly : public tag_net_message
{
	NET_SIS_hit_fly()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_hit_fly");
		dw_size = sizeof(NET_SIS_hit_fly);
	}
	DWORD	dw_role_id;
	Vector3 curPos;
	Vector3 faceTo;	
	DWORD	dwSkillID;			
	DWORD   dwSrcRoleID;		//攻击者ID
	DWORD	dwChannelIndex;		//伤害管道编号
	bool	bCollide;			
};

//! 通知移动速度改变
struct NET_SIS_move_speed_change : public tag_net_message
{
	NET_SIS_move_speed_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_move_speed_change");
		dw_size = sizeof(NET_SIS_move_speed_change);
	}
	DWORD	dw_role_id;
	Vector3 curPos;
	Vector3 faceTo;
};

#pragma pack(pop)
#endif
