
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
*	@file		map_protocol.h
*	@author		lc
*	@date		2011/03/08	initial
*	@version	0.0.1.0
*	@brief		
*/
#ifndef _BATTLE_GROUND_DEFINE_H_
#define _BATTLE_GROUND_DEFINE_H_

#include "protocol_common_errorcode.h"


#pragma pack(push, 1)

enum
{
	// 战场错误码
	E_Instance_battle_not_start				=	1,// 活动没开始
	E_Instance_battle_not_level				=	2,// 等级不足
	E_Instance_battle_max_num				=	3,// 人数满了
};


struct tagBattleResule
{
	BYTE	byType;			//阵营
	DWORD	dwRoleID;		//玩家id	
	INT		dwLevel;		//等级
	DWORD	dwKillNum;		//击杀敌人
	DWORD	dwKillBoss;		//击杀首领
	DWORD	dwKillSorder;	//击杀卫兵
	DWORD	dwScore;		//荣誉
};
// 进入战场
struct NET_SIC_enter_battle_instance : public tag_net_message
{
	NET_SIC_enter_battle_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_enter_battle_instance");
		dw_size = sizeof(*this);
	}

};


struct NET_SIS_enter_battle_instance : public tag_net_message
{
	NET_SIS_enter_battle_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_enter_battle_instance");
		dw_size = sizeof(*this);
	}
	DWORD dwErrorCode;
};

// 战场结束发送结果
struct NET_SIS_battle_ground_end : public tag_net_message
{
	NET_SIS_battle_ground_end()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_battle_ground_end");
		dw_size = sizeof(*this);
	}
	

	DWORD	dwNumber;
	tagBattleResule		sBattleData[1];

};


#pragma pack(pop)
#endif