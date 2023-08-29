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
*	@file		guild_define.h
*	@author		mmz
*	@date		2010/10/11	initial
*	@version	0.0.1.0
*/

#pragma once


#pragma pack(push, 1)

// 战场状态
enum EBATTLEGROUNDSTATE 
{
	EBS_BEGIN	= 0,	// 开始
	EBS_ING		= 1,	// 进行中
	EBS_END		= 2		// 结束了没开始
};

// 队伍类型
enum EBATTLENTEAM
{
	EBT_A,
	EBT_B,

	EBT_NUM
};

#define BATTLE_ROLE_LEVEL			40		// 战场等级需求
#define BATTLE_MAX_ROLE_NUMBER		200		// 战场最大人数
#define BATTLE_ACTIVE_ID			20		// 战场活动id
#define BATLLE_REAL_TIME			5 		// 战场准备时间
#define BATTLE_LEADER_A				2800003	// 势力a首领
#define BATTLE_LEADER_B				2800004	// 势力b首领

// 战场玩家数据
struct tagBattleRoleData
{
	DWORD	dwRoleID;		// 玩家id
	BYTE	byBattleType;	// 所属势力
	INT		nKillNum1;		// 击杀玩家数
	INT		nKillNum2;		// 击杀卫兵数
	INT		nKillNum3;		// 击杀首领数
	INT		nScore;			// 荣誉
	INT		nLevel;			// 等级
	INT		nRank;			// 排名
	INT		nKillSum;		// 连杀数

	tagBattleRoleData()
	{
		memset(this, 0, sizeof(*this));
	}
};
#pragma pack(pop)