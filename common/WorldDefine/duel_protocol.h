/*******************************************************************************

	Copyright 2010 by Shengshi Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	Shengshi Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	Shengshi Interactive  Co., Ltd.

*******************************************************************************/

/**
 *	@file		duel_protocol
 *	@author		mwh
 *	@date		2011/05/17	initial
 *	@version	0.0.1.0
 *	@brief		切磋系统
*/

#ifndef __DUEL_PROTOCOL_H__
#define __DUEL_PROTOCOL_H__

#pragma pack(push,1)

enum
{
	ASKDISTANCEMAX = 10 * 100, //  请求时，最大距离(cm)
	ASKTIMEOUTTIME = 10*1000, //  请求超时时间10秒
	ASKTIMEOUTTIMETICK = 10 * TICK_PER_SECOND, // 请求超时tick数
	DUELMAXDISTANCESQ = 2500 * 2500, // 切磋是最大距离平方
	FINISHHPRESTOREPER	= 500, // 血量恢复百分比(/10000)
	DUELBANNERTYPEID = 1000002, // 旗帜TypeID
};

enum
{
	EAskForDuel_OutOfDistance = 1,	// 切磋双方的距离过远，无法发起切磋。
	EAskForDuel_RedNameYourSelf,	// 您目前是红名状态，不能进行切磋。
	EAskForDuel_RedNameTarget,		// 您邀请是红名玩家，不能接受邀请。
	EAskForDuel_StateLimitYourSelf,	// 当前状态禁止进行切磋
	EAskForDuel_StateLimitTarget,   // 对方状态不能进行切磋
	EAskForDuel_TargetRefuse,		// 对方拒绝了你的切磋邀请。
	EAskForDuel_AlreadyAskFor,		// 您已发出切磋邀请，请等待对方回应。
	EAskForDuel_AlreadyInDuel,		// 您已经在进行切磋。
	EAskForDuel_TargetAlreadyInDuel,// 对方正在进行切磋。
	ETarget_NotExistOrOffline,		// 目标不存在或已经离线
	EDuel_Breakout,							// 切磋被中断
};

// 请求切磋
struct NET_SIC_AskForDuel : public tag_net_message
{
	NET_SIC_AskForDuel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_AskForDuel");
		dw_size = sizeof(*this);
	}
	DWORD dwTarget;
};

// 请求切磋回应
struct NET_SIS_AskForDuel : public tag_net_message
{
	NET_SIS_AskForDuel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_AskForDuel");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
	DWORD dwTarget;
};

// 转发请求给目标
struct NET_SIS_AskForDuelTransfer : public tag_net_message
{
	NET_SIS_AskForDuelTransfer()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_AskForDuelTransfer");
		dw_size = sizeof(*this);
	}
	DWORD dwTarget;
};

// 被请求人回应
struct NET_SIC_AskForDuelResponse : public tag_net_message
{
	NET_SIC_AskForDuelResponse()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_AskForDuelResponse");
		dw_size = sizeof(*this);
	}
	BYTE  byAck; // 0:拒绝 1:同意
	DWORD dwTarget;
};

struct NET_SIS_AskForDuelResponse : public tag_net_message
{
	NET_SIS_AskForDuelResponse()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_AskForDuelResponse");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
	DWORD dwTarget;
};

// 切磋开始
struct NET_SIS_DuelStart : public tag_net_message
{
	NET_SIS_DuelStart()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_DuelStart");
		dw_size = sizeof(*this);
	}
	DWORD dwTargetID;
	Vector3 bannerPos;
};

// 切磋结束
struct NET_SIS_DuelFinish : public tag_net_message
{
	NET_SIS_DuelFinish()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_DuelFinish");
		dw_size = sizeof(*this);
	}
	DWORD dwTargetID;
	DWORD dwError;
};

// 切磋结果广播
struct NET_SIS_DuelResultBroad : public tag_net_message
{
	NET_SIS_DuelResultBroad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_DuelResultBroad");
		dw_size = sizeof(*this);
	}
	DWORD dwLoser;
	DWORD dwWinner;
};

#pragma pack(pop)

#endif //__DUEL_PROTOCOL_H__
