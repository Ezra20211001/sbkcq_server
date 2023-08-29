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
*	@file		drop_protocol.h
*	@author		lc
*	@date		2011/03/08	initial
*	@version	0.0.1.0
*	@brief		������Ϣ
*/

#ifndef DROP_PROTOCOL
#define DROP_PROTOCOL


#include "protocol_common_errorcode.h"
#include "loot.h"

#pragma pack(push, 1)

enum
{
	E_Loot_BAG_NOT_ENOUGH_SPACE = 1,	//����û���㹻�ռ�
	E_Loot_Item_Not_Found		= 2,	//ʰȡ��Ʒû�ҵ�
	E_Loot_Role_Not_Found		= 3,	//ʰȡ���û�ҵ�
	E_Loot_Map_Not_Found		= 4,	//ʰȡ������ڵ�ͼû�ҵ�
	E_Loot_Add_Bag_Not_Success  = 5,	//���뱳�����ɹ�
	E_Loot_Disard_Item_Not_Success  = 6,	//���뱳�����ɹ�
	E_Loot_Pick_Up_Too_Far			= 7,	//��Ҿ�����Ʒ̫Զ,�޷�ʰȡ
	E_Loot_Belong_To_Team			= 8,	//ֻ�б�С��������Ҳ���ʰȡ
	E_Loot_Belong_To_Teammate		= 9,	//ֻ�б�С����ָ������Ҳ���ʰȡ
	E_Loot_Belong_To_You			= 10,	//����Ʒ��������
	E_Loot_WaitForAssign			= 11,	//�ȴ�����
};

//-----------------------------------------------------------------------------
//	��������ͬ��	S------>C
//-----------------------------------------------------------------------------
struct NET_SIS_synchronize_item : public tag_net_message
{
	NET_SIS_synchronize_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_item");
		dw_size = sizeof(NET_SIS_synchronize_item);
	}
	INT64	n64_serial;			// �������к�
	DWORD	dwPutDownUnitID;	// ������Ʒ��UintID
	DWORD	dwOwnerID;			// ������ɫ
	DWORD	dwTeamID;			// ����С��ID
	DWORD	dwGroupID;			// �����Ŷ�ID
	DWORD	dw_data_id;			// ����
	INT		n_num;				// ��Ŀ
	Vector3 vPos;				// ��Ʒ����λ��
	BOOL    bKilled;			// �����Ƿ񱻻�ɱ���������
	BYTE	byQuality;			// Ʒ��
};


//-----------------------------------------------------------------------------
//	����������ʧ---���������ʱ�䵽 �䳤  S------>C
//-----------------------------------------------------------------------------
struct NET_SIS_role_ground_item_disappear : public tag_net_message
{
	NET_SIS_role_ground_item_disappear()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_ground_item_disappear");
		dw_size = sizeof(NET_SIS_role_ground_item_disappear);
	}
	INT64	n64_serial[1];	// �������к�
};



//-----------------------------------------------------------------------------
//	��������������Ʒ---�������ٴ���Ʒ 
//-----------------------------------------------------------------------------
struct NET_SIC_role_putdown_item : public tag_net_message
{
	NET_SIC_role_putdown_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_putdown_item");
		dw_size = sizeof(NET_SIC_role_putdown_item);
	}
	INT64	n64_serial;	// �������к�
	BYTE	by_type;	// �������� 0 ���� 1 ����
	DWORD	dw_safe_code;
};

struct NET_SIS_role_putdown_item : public tag_net_message
{
	NET_SIS_role_putdown_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_putdown_item");
		dw_size = sizeof(NET_SIS_role_putdown_item);
	}
	INT64	n64_serial;	// �������к�
	DWORD	dw_error_code;	//���ش�����
};


//-----------------------------------------------------------------------------
//	ʰȡ��Ʒ
//-----------------------------------------------------------------------------
struct NET_SIC_role_pickup_item : public tag_net_message
{
	NET_SIC_role_pickup_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_pickup_item");
		dw_size = sizeof(NET_SIC_role_pickup_item);
	}
	INT64 n64_serial;		//��ƷID 
};

struct NET_SIS_role_pickup_item : public tag_net_message
{
	NET_SIS_role_pickup_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_pickup_item");
		dw_size = sizeof(NET_SIS_role_pickup_item);
	}
	DWORD dw_role_id;			// ʰȡ��ID
	INT64 n64_serial;        // ��Ʒ64λID
	DWORD dw_error_code;		// ���ش�����
};


#pragma pack(pop)
#endif
