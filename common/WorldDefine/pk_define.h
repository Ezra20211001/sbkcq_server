/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#pragma once

/**
*	@file		Sample.h
*	@author		mmz
*	@date		2010/10/06	initial
*	@version	0.0.1.0
*/


#include "RoleDefine.h"

#pragma pack(push, 1)

const INT SAFE_GUARD_FORCE_LEVEL			=	40;							// 必须处在PK保护的等级上限

const INT UNSET_PVP_TICK					=	30*TICK_PER_SECOND;			// PVP状态下，需要多长时间恢复到未PVP状态（单位：秒）				


const INT PK_VALUE_MAX						=		99999999;		//PK值上限
const INT ATTACK_WHITENAME_INCPK			=		720;			//攻击非红名玩家增加PK值
const INT ATTACK_INCPK_INTERVAL				=		6 * 60;		//攻击非红名玩家增加PK值的间隔时间
const INT KILL_LOWLEVEL_MINLEVEL			=		30;			//杀小号计算的最小等级
//const INT KILL_COMMON_PKINC					=		10;			//杀死普通玩家获得的PK值
//const INT KILL_LOWLEVEL_PKINC				=		35;			//杀小号计算获得的PK值
//const float	PVP_AREA_PK_INCPER				=		0.8f;		//PK区杀人PK值比例
//const float PEACE_AREA_PK_INCPER			=		1.2f;		//安全区杀人PK值比例
//const DWORD	PK_POLICEMAN_TYPEID				=		1000001;	//巡捕ID 
//const INT PK_DEC_INTERVALOF_NO_PRISION		=		60;		//非牢狱地图PK递减周期
const INT PK_DEC_INTERVALOF_PRISION			=		60;		//PK递减周期
const INT PK_DEC_ITENRVALOF_VALUE			=		-4;			//PK值衰减值
//const float KILL_ENEMY_PKVAL_DECPER			=		-0.3f;		//杀死敌对玩家PK衰减百分比
//const DWORD INVINCIBLE_BUFF_ID				=		3000004;	//无敌buff 


#pragma pack(pop)