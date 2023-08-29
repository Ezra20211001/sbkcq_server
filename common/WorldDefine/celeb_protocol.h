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
*	@file		celeb_protocol.h
*	@author		lc
*	@date		2011/03/02	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef CELEB_PROTOCOL
#define CELEB_PROTOCOL

#pragma pack(push, 1)

#include "reputation.h"
#include "famehall_define.h"
//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum
{
	E_FrameHall_Success					= 0,	// �ɹ�
	E_FrameHall_MemberOrderUnchanged	= 1,	// �����ó�Ա�б��ޱ仯
	E_FrameHall_RepOrderUnchanged		= 2,	// ���������ޱ仯
	E_FrameHall_ItemIsNotTreasure		= 3,	// ��Ʒ�����䱦
	E_FrameHall_TreasureAlreadyAct		= 4,	// �䱦�Ѽ���
	E_FrameHall_ActCountNotEnough		= 5,	// �����������
	E_FrameHall_ClanColNotEnough		= 6,	// ���幱�ײ���
	E_FrameHall_UnknownError			,		// δ֪����
};


//----------------------------------------------------------------------------
// ��ȡ����������ǰ50����ɫ�б�
//----------------------------------------------------------------------------
struct NET_SIC_celeb_role : public tag_net_message
{
	NET_SIC_celeb_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_celeb_role");
		dw_size = sizeof(NET_SIC_celeb_role);
	}
	BYTE		byClanType;				// ��������
	DWORD		dwUpdateTime;			// ����ʱ��� tagDWORDTime
};

struct NET_SIS_celeb_role : public tag_net_message
{
	NET_SIS_celeb_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_celeb_role");
		dw_size = sizeof(NET_SIS_celeb_role);
	}
	BYTE		eClanType;				// ��������EClanType
	BYTE		byErrCode;				// �Ƿ��б��ޱ仯��ΪE_FrameHall_MemberOrderUnchanged
	DWORD		dwUpdateTime;			// ������ʱ���
	BYTE		byRoleNum;				// �����������б�����(����50)
	BYTE		byData[1];				// ��ԱnameID�б�����(DWORD)
};


//----------------------------------------------------------------------------
// ����ǰ50����ɫ�б�
//----------------------------------------------------------------------------
struct NET_SIC_reputation_top : public tag_net_message
{
	NET_SIC_reputation_top()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reputation_top");
		dw_size = sizeof(NET_SIC_reputation_top);
	}
	BYTE 		byClanType;				// ��������
	DWORD		dwUpdateTime;			// ����ʱ��� tagDWORDTime
};

struct NET_SIS_reputation_top : public tag_net_message
{
	NET_SIS_reputation_top()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reputation_top");
		dw_size = sizeof(NET_SIS_reputation_top);
	}
	BYTE		byClanType;				// ��������EClanType
	BYTE		byErrCode;				// �Ƿ��б��ޱ仯��ΪE_FrameHall_RepOrderUnchanged
	DWORD		dwUpdateTime;			// ������ʱ���
	BYTE		byRoleNum;				// ÿ�����������б�����(����50)
	BYTE		byData[1];				// �䳤�б�����(tagRepRankData)
};


//----------------------------------------------------------------------------
// ����������м����䱦
//----------------------------------------------------------------------------
struct NET_SIC_get_activation_gens_treasure : public tag_net_message
{
	NET_SIC_get_activation_gens_treasure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_activation_gens_treasure");
		dw_size = sizeof(NET_SIC_get_activation_gens_treasure);
	}
	BYTE		byClanType;				// ��������EClanType
};

struct NET_SIS_get_activation_gens_treasure : public tag_net_message
{
	NET_SIS_get_activation_gens_treasure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_activation_gens_treasure");
		dw_size = sizeof(NET_SIS_get_activation_gens_treasure);
	}
	BYTE		byClanType;				// ��������EClanType
	INT16		n16ActTreasureNum;		// �Ѽ����䱦����
	BYTE		byData[1];				// ����tagTreasureData
};


//----------------------------------------------------------------------------
// �¼��������䱦֪ͨ
//----------------------------------------------------------------------------
struct NET_SIS_new_activation_treasure : public tag_net_message
{
	NET_SIS_new_activation_treasure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_new_activation_treasure");
		dw_size = sizeof(NET_SIS_new_activation_treasure);
	}
	INT16		n16TreasureID;
	DWORD		dwNameID;
};

//----------------------------------------------------------------------------
// �����ϻ��䱦
//----------------------------------------------------------------------------
struct NET_SIC_activation_treasure : public tag_net_message
{
	NET_SIC_activation_treasure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_activation_treasure");
		dw_size = sizeof(NET_SIC_activation_treasure);
	}
	UINT16		u16TreasureID;			// �䱦ID
};

struct NET_SIS_activation_treasure : public tag_net_message
{
	NET_SIS_activation_treasure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_activation_treasure");
		dw_size = sizeof(NET_SIS_activation_treasure);
	}
	DWORD		dwErrCode;				// ������
	UINT16		u16TreasureID;			// �䱦ID
};


#pragma pack(pop)
#endif