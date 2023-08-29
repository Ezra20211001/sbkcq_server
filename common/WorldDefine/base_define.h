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

// �������ֵĳ���,�������������������̵�����
#define X_LONG_NAME				256
#define X_HUGE_NAME				512
#define X_SHORT_NAME			32
#define X_HUGE_CONTEXT			2048
#define X_IP_LEN				24
#define X_PET_NAME              7
#define INT64					__int64

CONST INT	TICK_TIME				= 200;					// ÿTick 200 ms
CONST INT	TICK_PER_SECOND			= (1000/TICK_TIME);		// ÿ�����Tick

//--------------------------------------------------------------------------------
// ������Ϸ�����ID��Χ
//--------------------------------------------------------------------------------
#define		MIN_PLAYER_ID			1
#define		MAX_PLAYER_ID			2000000000
#define		IS_PLAYER(ID)			( (ID) >= MIN_PLAYER_ID && (ID) <= MAX_PLAYER_ID )

#define		MIN_CREATURE_ID			2000000001
#define		MID_CREATURE_ID			2500000001		//��ֹ��̬����id������Χ,��������������¿�ʼ
#define		MAX_CREATURE_ID			3000000000

#define		IS_CREATURE(ID)			( (ID) >= MIN_CREATURE_ID && (ID) <= MAX_CREATURE_ID )

#define		MIN_NORMAL_CREATURE_ID	2000000001
#define		MAX_NORMAL_CREATURE_ID	2900000000//2800000000
#define		IS_NORMAL_CREATURE(ID)	( (ID) >= MIN_NORMAL_CREATURE_ID && (ID) <= MAX_NORMAL_CREATURE_ID )

#define		MIN_DOOR_ID				2900000001
#define		MAX_DOOR_ID				2901000000
#define		IS_DOOR(ID)				( (ID) >= MIN_DOOR_ID && (ID) <= MAX_DOOR_ID )
#define		OBJID_TO_DOORID(ID)		( MIN_DOOR_ID + (INT)( ( (INT64) (ID << 8) ) >> 8 ) )

#define		MIN_PET_ID				3000000001//2800000001
#define		MAX_PET_ID				4000000000//2900000000
#define		IS_PET(ID)				( (ID) >= MIN_PET_ID && (ID) <= MAX_PET_ID )

#define		MIN_ITEM_ID				1
#define		MAX_ITEM_ID				8999999

#define		MIN_EQUIP_ID			9000000

//------------------------------------------------------------------------
// ��Ǯtypeid
//------------------------------------------------------------------------
const DWORD		TYPE_ID_MONEY		= 8999999;// Ҳ���ᱻ�����õ�


//----------------------------------------------------------------
// �ж��Ƿ�Ϊװ��
//----------------------------------------------------------------
#define		MIsEquipment(dw_data_id)		( (dw_data_id) >= MIN_EQUIP_ID )

//----------------------------------------------------------------
// �ж��Ƿ�Ϊ������Ʒ
//----------------------------------------------------------------
#define		MIsQuestItem(pItemProto)			( EIT_Quest == (pItemProto)->eType )

// �����ö��
enum	EReceiveState
{
	ERCS_1		=	0x1,
	ERCS_2		=	0x2,
	ERCS_3		=	0x4,
	ERCS_4		=	0x8,
	ERCS_5		=	0x10,
	ERCS_6		=	0x20,
	ERCS_7		=	0x40,
	ERCS_8		=	0x80,
	ERCS_9		=	0x100,
	ERCS_10		=	0x200,
	ERCS_11		=	0x400,
	ERCS_12		=	0x800,
	ERCS_13		=	0x1000,
	ERCS_14		=	0x2000,
	ERCS_15		=	0x4000,
	ERCS_16		=	0x8000,
	ERCS_17		=	0x10000,
	ERCS_18		=	0x20000,
	ERCS_19		=	0x40000,
	ERCS_20		=	0x80000,
	ERCS_21		=	0x100000,
	ERCS_22		=	0x200000,
	ERCS_23		=	0x400000,
	ERCS_24		=	0x800000,
	ERCS_25		=	0x1000000,
	ERCS_26		=	0x2000000,
	ERCS_27		=	0x4000000,
	ERCS_28		=	0x8000000,
	ERCS_29		=	0x10000000,
	ERCS_30		=	0x20000000,

	ERCS_End	=	0x40000000,
};


////----------------------------------------------------------------
//// �ж�װ���Ƿ��Ѽ���
////----------------------------------------------------------------
//#define MIsIdentified(pEquip)			(pEquip->equipSpec.byQuality != (BYTE)EIQ_Null)
//
////----------------------------------------------------------------
//// �ж�װ���Ƿ�Ϊring
////----------------------------------------------------------------
//#define MIsRing(pEquip)				(EEP_Finger1 == ((tagEquipProto*)pEquip->pProtoType)->eEquipPos)
//#define MIsWeapon(pEquip)			(pEquip->pProtoType->eTySpe == EIT_Weapon)