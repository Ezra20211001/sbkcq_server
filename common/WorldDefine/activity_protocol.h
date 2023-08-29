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
*	@file		activity_protocol.h
*	@author		lc
*	@date		2011/03/01	initial
*	@version	0.0.1.0
*	@brief		活动协议
*/

#ifndef ACTIVITY_PROTOCOL
#define ACTIVITY_PROTOCOL

#pragma pack(push, 1)

//-----------------------------------------------------------------------------
// 脚本的缺省消息（NET_SIC_default_request)事件类型定义（该类型定义在lua中使用）
//-----------------------------------------------------------------------------
/*
dwEventType = 1				// 客户端请求PVP固定活动界面 
dwEventType = 2				// 查询玩家在固定活动中的排名
*/

enum 
{
	E_Open_Server_Has_Recv		=	1,  //奖励已经领取
	E_Open_Server_Not_Free_Bag	=	2,	//背包空间不足
	E_Open_Server_Not_Today		=	3,	//没到领取时间
	E_Open_Server_Cant			=	4,	//没到领取条件
};
//！ 广播活动状态
struct NET_SIS_acitvity_state : public tag_net_message
{
	NET_SIS_acitvity_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_acitvity_state");
		dw_size = sizeof(NET_SIS_acitvity_state);
	}
	INT		nState;							// 0-即将开始 1-开始 2-即将结束 3-结束 
	BYTE	byHour;
	BYTE	byMinute;
	DWORD	dwActivityID;
};

// 获取开服活动数据
struct NET_SIC_get_server_acitvity : public tag_net_message
{
	NET_SIC_get_server_acitvity()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_server_acitvity");
		dw_size = sizeof(NET_SIC_get_server_acitvity);
	}

};

struct NET_SIS_get_server_acitvity : public tag_net_message
{
	NET_SIS_get_server_acitvity()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_server_acitvity");
		dw_size = sizeof(NET_SIS_get_server_acitvity);
	}
	
	INT nDay;		//开服天数

	// 自己排名
	DWORD	dwSelf[7];

};

// 领取开服活动奖励
struct NET_SIC_get_server_acitvity_receive : public tag_net_message
{
	NET_SIC_get_server_acitvity_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_server_acitvity_receive");
		dw_size = sizeof(NET_SIC_get_server_acitvity_receive);
	}


	INT nDay;		//哪一天的奖励
};

struct NET_SIS_get_server_acitvity_receive : public tag_net_message
{
	NET_SIS_get_server_acitvity_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_server_acitvity_receive");
		dw_size = sizeof(NET_SIS_get_server_acitvity_receive);
	}

	DWORD dw_error_code;
};

#pragma pack(pop)
#endif