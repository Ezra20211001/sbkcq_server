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
 *	@file		fishing_protocol
 *	@author		mwh
 *	@date		2011/06/27	initial
 *	@version	0.0.1.0
 *	@brief		����Э��
*/

#include "fishing_define.h"

#ifndef __FISHING_PROTOCOL_H__
#define __FISHING_PROTOCOL_H__
#pragma pack(push,1)

enum
{
	E_CantFishingNoBait = 1,		// û�����
	E_CantFishingNoRod,				// û�����
	E_CantFishingOutOfSpace,		// �ռ䲻��
	E_CantFishingStateLimit,		// ״̬����
	E_CantFishingAreaLimit,			// ��������
	E_CantFishingNoSkill,			// ûѧ����
	E_CantFishingNpcError,			// Npc����
	E_CantFishingSkillLevel,		// ���ܵȼ�����
	E_CantFishingOutOfLevel,   // ��ɫ�ȼ�����
	E_CantFishingOutOfVigour,		// Ԫ��ֵ����
};

// ��ʼ����
struct NET_SIC_Start_Fishing: public tag_net_message
{
	NET_SIC_Start_Fishing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Start_Fishing");
		dw_size = sizeof(*this);
	}
	DWORD dwNpcID;
	BOOL bAutoFish;			// �Զ�����
	DWORD dwSkill;			// ���㼼��
	INT64 n64Bait;			// ���
	INT64 n64FishingRod;	// ���
};

struct NET_SIS_Start_Fishing: public tag_net_message
{
	NET_SIS_Start_Fishing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Start_Fishing");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
};

// ��������
struct NET_SIC_Stop_Fishing: public tag_net_message
{
	NET_SIC_Stop_Fishing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Stop_Fishing");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_Stop_Fishing: public tag_net_message
{
	NET_SIS_Stop_Fishing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Stop_Fishing");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
};

// ɶҲû����
struct NET_SIS_Fishing_NullGet: public tag_net_message
{
	NET_SIS_Fishing_NullGet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Fishing_NullGet");
		dw_size = sizeof(*this);
	}
};

#pragma pack(pop)
#endif // __FISHING_PROTOCOL_H__