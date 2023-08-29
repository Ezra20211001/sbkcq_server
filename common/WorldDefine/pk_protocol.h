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
*	@file		pk_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		pk��Ϣ
*/


#ifndef PK_PROTOCOL
#define PK_PROTOCOL

#include "protocol_common_errorcode.h"
#include "RoleDefine.h"
#include "currency_define.h"

#pragma pack(push, 1)

// 20��һ��PK����
const INT KILLBUFFID = 3000401;
const INT PKLEVELMIN = 1;
const INT KILLBADGEITEMCD = 5 * 60; // 5m
const INT KILLBADGEITEMCD_TICK = KILLBADGEITEMCD * TICK_PER_SECOND;
#define  KILLNOTICEUSEMONEY  (GOLD2SILVER * 10)
enum
{
	E_SafeGuard_Already			=	1,		// �Ѿ��ǵ�ǰ״̬
	E_SafeGuard_PKStateInvalid	=	2,		// PK״̬Ϊ�Ǻ�ƽ״̬�������л�������ģʽ
	E_SafeGuard_TimeLimit		=	3,		// �����ϴο�������ģʽ��ʱ��δ���������л�������ģʽ
	E_SafeGuard_LevelLimit		=	4,		// �ȼ�����
	E_SafeGuard_ItemLimit		=	5,		// ʹ�õ�IM��Ʒ���ƣ��޷��л�������ģʽ

	E_PK_LevelOutOf20		= 11,		// PK�ȼ�����
	E_PK_StartLimit				=   12,		// pk״̬���޲��ܱ仯
	E_PK_StateLimit				=	13,		// ս��״̬����
	E_PK_AreaLimit				=	15,		// PK��������
	E_PK_RedNameLimit			=	17,		// ��������
	E_PK_GuildLimit				=	18,		// ��������

	E_UseKillbadgeItem_TargetOffLine =	19,// ʹ��׷ɱ��ʱ,Ŀ�겻����
	E_UseKillbadgeItem_TargetInPrision	=	20,// ʹ��׷ɱ��ʱ,Ŀ��������
	E_UseKillbadgeItem_TargetNotRedName	=	21,// ʹ��׷ɱ��ʱ,�Է����Ǻ���
	E_UseKillbadgeItem_CDLimited		=	22,// 5����֮��ֻ��ʹ��һ��׷ɱ��
};
//-----------------------------------------------------------------------------
// ����pkֵ
//-----------------------------------------------------------------------------
struct NET_SIS_change_pk_value : public tag_net_message
{
	NET_SIS_change_pk_value()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_pk_value");
		dw_size = sizeof(NET_SIS_change_pk_value);
	}
	DWORD		dw_role_id;				//��ɫID
	INT			iPKValue;
	//BOOL		bIsPurpureDec;
};

//-----------------------------------------------------------------------------
// ����pk״̬
//-----------------------------------------------------------------------------
struct NET_SIC_change_pk_value : public tag_net_message
{
	NET_SIC_change_pk_value()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_change_pk_value");
		dw_size = sizeof(NET_SIC_change_pk_value);
	}
	ERolePKState	eState;						// �µ�PK״̬
};

struct NET_SIS_change_pk_state : public tag_net_message
{
	NET_SIS_change_pk_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_pk_state");
		dw_size = sizeof(NET_SIS_change_pk_state);
	}
	DWORD				dw_role_id;
	ERolePKState		ePKState;
	DWORD				dwError;
};

struct NET_SIC_use_skill_badge_item : public tag_net_message
{
	NET_SIC_use_skill_badge_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_use_skill_badge_item");
		dw_size = sizeof(NET_SIC_use_skill_badge_item);
	}
	DWORD dwTarget;
};

struct NET_SIS_use_skill_badge_item : public tag_net_message
{
	NET_SIS_use_skill_badge_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_use_skill_badge_item");
		dw_size = sizeof(NET_SIS_use_skill_badge_item);
	}
	DWORD dwError;
};

#pragma pack(pop)
#endif
