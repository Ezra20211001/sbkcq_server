
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
	// ս��������
	E_Instance_battle_not_start				=	1,// �û��ʼ
	E_Instance_battle_not_level				=	2,// �ȼ�����
	E_Instance_battle_max_num				=	3,// ��������
};


struct tagBattleResule
{
	BYTE	byType;			//��Ӫ
	DWORD	dwRoleID;		//���id	
	INT		dwLevel;		//�ȼ�
	DWORD	dwKillNum;		//��ɱ����
	DWORD	dwKillBoss;		//��ɱ����
	DWORD	dwKillSorder;	//��ɱ����
	DWORD	dwScore;		//����
};
// ����ս��
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

// ս���������ͽ��
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