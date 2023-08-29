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

const INT SAFE_GUARD_FORCE_LEVEL			=	40;							// ���봦��PK�����ĵȼ�����

const INT UNSET_PVP_TICK					=	30*TICK_PER_SECOND;			// PVP״̬�£���Ҫ�೤ʱ��ָ���δPVP״̬����λ���룩				


const INT PK_VALUE_MAX						=		99999999;		//PKֵ����
const INT ATTACK_WHITENAME_INCPK			=		720;			//�����Ǻ����������PKֵ
const INT ATTACK_INCPK_INTERVAL				=		6 * 60;		//�����Ǻ����������PKֵ�ļ��ʱ��
const INT KILL_LOWLEVEL_MINLEVEL			=		30;			//ɱС�ż������С�ȼ�
//const INT KILL_COMMON_PKINC					=		10;			//ɱ����ͨ��һ�õ�PKֵ
//const INT KILL_LOWLEVEL_PKINC				=		35;			//ɱС�ż����õ�PKֵ
//const float	PVP_AREA_PK_INCPER				=		0.8f;		//PK��ɱ��PKֵ����
//const float PEACE_AREA_PK_INCPER			=		1.2f;		//��ȫ��ɱ��PKֵ����
//const DWORD	PK_POLICEMAN_TYPEID				=		1000001;	//Ѳ��ID 
//const INT PK_DEC_INTERVALOF_NO_PRISION		=		60;		//��������ͼPK�ݼ�����
const INT PK_DEC_INTERVALOF_PRISION			=		60;		//PK�ݼ�����
const INT PK_DEC_ITENRVALOF_VALUE			=		-4;			//PKֵ˥��ֵ
//const float KILL_ENEMY_PKVAL_DECPER			=		-0.3f;		//ɱ���ж����PK˥���ٷֱ�
//const DWORD INVINCIBLE_BUFF_ID				=		3000004;	//�޵�buff 


#pragma pack(pop)