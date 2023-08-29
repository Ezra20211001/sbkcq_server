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
*	@file		pet_equip_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		����װ����Ϣ
*/

#ifndef PET_EQUIP_PROTOCOL
#define PET_EQUIP_PROTOCOL

#pragma pack(push,1)

#include "pet_define.h"
#include "pet_equip_define.h"
#include "protocol_common_errorcode.h"

// ����װ����Ʒ
struct NET_SIC_pet_equip : public tag_net_message
{
	NET_SIC_pet_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_equip");
		dw_size = sizeof(NET_SIC_pet_equip);
	}
	DWORD       dwPetID;        //!< ����ID
	INT8		n8DstPos;		//!< ����װ����λ��
	INT64       n64ItemID;      //!< 64λitemid
};

struct NET_SIS_pet_equip : public tag_net_message
{
	NET_SIS_pet_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_equip");
		dw_size = sizeof(NET_SIS_pet_equip);
	}
	DWORD               dwErrCode;      //!< ������
	DWORD               dwPetID;        //!< ����ID
	tagPetEquipMsgInfo  itemData;       //!< ����װ����Ϣ
};


// ����жװ��Ʒ
struct NET_SIC_pet_unequip : public tag_net_message
{
	NET_SIC_pet_unequip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_unequip");
		dw_size = sizeof(NET_SIC_pet_unequip);
	}
	DWORD		dwPetID;
	INT16		n16PosDst;		//!< �����뱳����λ��
	INT64       n64ItemID;      //!< 64λitemid
};

struct NET_SIS_pet_unequip : public tag_net_message
{
	NET_SIS_pet_unequip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_unequip");
		dw_size = sizeof(NET_SIS_pet_unequip);
	}
	DWORD       dwErrCode;      //!< ������
	DWORD		dwPetID;
	INT64       n64ItemID;      //!< 64λitemid
};


// ����װ��λ�ý���
struct NET_SIC_pet_equip_position_swap : public tag_net_message
{
	NET_SIC_pet_equip_position_swap()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_equip_position_swap");
		dw_size = sizeof(NET_SIC_pet_equip_position_swap);
	}
	DWORD		dwPetID;
	INT8		n8PosDst;		//!< װ���ƶ�����Ŀ��λ��
	INT64       n64ItemID;      //!< 64λitemid
};

struct NET_SIS_pet_equip_position_swap : public tag_net_message
{
	NET_SIS_pet_equip_position_swap()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_equip_position_swap");
		dw_size = sizeof(NET_SIS_pet_equip_position_swap);
	}
	DWORD       dwErrCode;      //!< ������
	DWORD		dwPetID;
	INT8		n8PosDst;		//!< װ���ƶ�����Ŀ��λ��
	INT8		n8PosSrc;		//!< װ��ԭλ��
	INT64       n64ItemID;      //!< 64λitemid
};


#pragma pack(pop)
#endif