/*******************************************************************************

	Copyright 2010 by tiankong Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef __MSG_RIDE_H__
#define __MSG_RIDE_H__

/**
 *	@file		ride_protocol.h
 *	@author		mawenhong
 *	@date		2010/11/16	initial
 *	@version	0.0.1.0
 *	@brief		���
*/

#include "../WorldDefine/ride_define.h"

#pragma pack(push,1)
enum
{
	E_Ride_Upgrade_Failed_MaxLevel			=	1,	//�ﵽ���ȼ�
	E_Ride_Upgrade_Failed_Out_of_Money		=	2,	//��Ǯ����
	E_Ride_Upgrade_Failed_No_GodStone		=	3,	//û����ʯ
	E_Ride_Upgrade_Failed_No_SoulStone		=	4,	//û�����ʯ
	E_Ride_Upgrade_Failed_Error_Npc			=	5,	//Npcû�⹦��
	E_Ride_Upgrade_Failed_Not_Exist			=	6,	//���ﲻ����
	E_Ride_Upgrade_Failed_Riding			=	7,	//������
	E_Ride_Upgrade_Failed_Failed			=	8,  //ǿ��ʧ��

	E_Ride_InLay_Failed_Error_Npc			=	9,	//Npcû�⹦��
	E_Ride_InLay_Failed_Not_Exist			=	10,	//���ﲻ����
	E_Ride_InLay_Failed_No_Equip			=	11,	//û����װ��
	E_Ride_InLay_Failed_HodeIndex_Full		=	12,	//û�п��ÿ�
	E_Ride_InLay_Failed_Riding				=	13,	//������

	E_Ride_RemoveInLay_Failed_No_InLay		=	14,	//����û��Ƕ��
	E_Ride_RemoveInLay_Failed_No_CrushStone	=	15, //û�д�ĥʯ
	E_Ride_RemoveInLay_Failed_Riding		=	16,	//������
	E_Ride_RemoveInLay_Failed_Out_Of_Money	=	17, //��Ǯ����
	E_Ride_RemoveInLay_Failed_Not_Exist		=	18,	//���ﲻ����
	E_Ride_RemoveInLay_Failed_Error_Npc		=	19, //Npcû�⹦��

	E_Ride_BeginRide_Failed_Not_Exist		=	20,	//���ﲻ����
	E_Ride_BeginRide_Failed_Riding			=	21, //������

	E_Ride_CancelRide_Failed_Not_Exist		=	22, //������
	E_Ride_CancelRide_Failed_Not_Riding		=	23,	//û��

	E_Ride_BeginRide_Failed_StateLimit		=	24,
	E_Ride_BeginRide_Failed_Already			=	25,
	E_Ride_BeginRide_Failed_Without_Fashion =	26, //��ȫ��û��װ������ʱװ�������
};

//ǿ��
struct NET_SIC_upgrade_ride : public tag_net_message
{
	NET_SIC_upgrade_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_upgrade_ride");
		dw_size = sizeof(*this);
	}
	DWORD dwNpcID;
	INT64 n64RideSerial;
	BYTE  byGodStoneNumber;
	BOOL  bUseBind;
};

struct NET_SIS_upgrade_ride : public tag_net_message
{
	NET_SIS_upgrade_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_upgrade_ride");
		dw_size = sizeof(*this);
	}
	DWORD	dwError;
	DWORD	dwNpcID;
	BOOL	bBindRide;	
};


//��������װ��
struct NET_SIC_ride_inlay : public tag_net_message
{
	NET_SIC_ride_inlay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_ride_inlay");
		dw_size = sizeof(*this);
	}
	INT64 n64RideSerial;
	INT64 n64ItemSerial[MAX_RIDEHOLE_NUM];
};

struct NET_SIS_ride_inlay : public tag_net_message
{
	NET_SIS_ride_inlay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_ride_inlay");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
};


////�Ƴ���Ƕ
//struct NET_SIC_remove_ride_inlay : public tag_net_message
//{
//	NET_SIC_remove_ride_inlay()
//	{
//		ZeroMemory(this, sizeof(*this));
//		dw_message_id = message_id_crc("NET_SIC_remove_ride_inlay");
//		dw_size = sizeof(*this);
//	}
//	DWORD dwNpcID;
//	INT64 n64RideSerial;
//	INT64 n64CrushStone;
//	BYTE  byIndex;
//};
//
//struct NET_SIS_remove_ride_inlay : public tag_net_message
//{
//	NET_SIS_remove_ride_inlay()
//	{
//		ZeroMemory(this, sizeof(*this));
//		dw_message_id = message_id_crc("NET_SIS_remove_ride_inlay");
//		dw_size = sizeof(*this);
//	}
//	DWORD dwError;
//};


//��ʼ���
struct NET_SIC_begin_ride : public tag_net_message
{
	NET_SIC_begin_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_begin_ride");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_begin_ride : public tag_net_message
{
	NET_SIS_begin_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_begin_ride");
		dw_size = sizeof(*this);
	}
	DWORD dwTypeID;
	INT		nLevel; 
	DWORD dwRoleID;
	DWORD dwError;
};

//��������
struct NET_SIC_tog_ride : public tag_net_message
{
	NET_SIC_tog_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_tog_ride");
		dw_size = sizeof(*this);
	}

	BYTE	byType;	//0:��� 1:��ȯ 2:Ԫ��
};

struct NET_SIS_tog_ride : public tag_net_message
{
	NET_SIS_tog_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_tog_ride");
		dw_size = sizeof(*this);
	}
	INT nCritNum;
	INT nExp;
	DWORD dw_error_code;
};

// ͬ����������
struct NET_SIC_get_raid_att : public tag_net_message
{
	NET_SIC_get_raid_att()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_raid_att");
		dw_size = sizeof(*this);
	}

};

struct NET_SIS_get_raid_att : public tag_net_message
{
	NET_SIS_get_raid_att()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_raid_att");
		dw_size = sizeof(*this);
	}
	INT nLevel;		//�ȼ�
	INT nCurExp;	//����
	DWORD dwType;	//ģ��id
};


// ������
struct NET_SIC_interrupt_begin_ride : public tag_net_message
{
	NET_SIC_interrupt_begin_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_interrupt_begin_ride");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_interrupt_begin_ride : public tag_net_message
{
	NET_SIS_interrupt_begin_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_interrupt_begin_ride");
		dw_size = sizeof(*this);
	}
	DWORD dwRoleID;
};

struct NET_SIS_new_mount : public tag_net_message
{
	NET_SIS_new_mount()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_new_mount");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	DWORD	dwPetTypeID;
	BYTE	bySolidateLevel;
};


//ȡ�����
struct NET_SIC_cancel_ride : public tag_net_message
{
	NET_SIC_cancel_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_ride");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_cancel_ride : public tag_net_message
{
	NET_SIS_cancel_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_ride");
		dw_size = sizeof(*this);
	}
	DWORD dwRoleID;
	DWORD dwError;
};

// װ������
struct NET_SIC_Equip_ride : public tag_net_message
{
	NET_SIC_Equip_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Equip_ride");
		dw_size = sizeof(*this);
	}
	INT64 n64RideSerial;
};

struct NET_SIS_Equip_ride : public tag_net_message
{
	NET_SIS_Equip_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Equip_ride");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
	INT64 n64RideSerial;
};

// ж������
struct NET_SIC_UnEquip_ride : public tag_net_message
{
	NET_SIC_UnEquip_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_UnEquip_ride");
		dw_size = sizeof(*this);
	}
	INT64 n64RideSerial;
};

struct NET_SIS_UnEquip_ride : public tag_net_message
{
	NET_SIS_UnEquip_ride()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_UnEquip_ride");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
	INT64 n64RideSerial;
};

#pragma  pack(pop)

#endif //__MSG_RIDE_H__
