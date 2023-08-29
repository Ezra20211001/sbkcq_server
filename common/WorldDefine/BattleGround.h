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

// ս��״̬
enum EBATTLEGROUNDSTATE 
{
	EBS_BEGIN	= 0,	// ��ʼ
	EBS_ING		= 1,	// ������
	EBS_END		= 2		// ������û��ʼ
};

// ��������
enum EBATTLENTEAM
{
	EBT_A,
	EBT_B,

	EBT_NUM
};

#define BATTLE_ROLE_LEVEL			40		// ս���ȼ�����
#define BATTLE_MAX_ROLE_NUMBER		200		// ս���������
#define BATTLE_ACTIVE_ID			20		// ս���id
#define BATLLE_REAL_TIME			5 		// ս��׼��ʱ��
#define BATTLE_LEADER_A				2800003	// ����a����
#define BATTLE_LEADER_B				2800004	// ����b����

// ս���������
struct tagBattleRoleData
{
	DWORD	dwRoleID;		// ���id
	BYTE	byBattleType;	// ��������
	INT		nKillNum1;		// ��ɱ�����
	INT		nKillNum2;		// ��ɱ������
	INT		nKillNum3;		// ��ɱ������
	INT		nScore;			// ����
	INT		nLevel;			// �ȼ�
	INT		nRank;			// ����
	INT		nKillSum;		// ��ɱ��

	tagBattleRoleData()
	{
		memset(this, 0, sizeof(*this));
	}
};
#pragma pack(pop)