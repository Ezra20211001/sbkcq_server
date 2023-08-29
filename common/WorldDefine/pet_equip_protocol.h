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
*	@brief		宠物装备消息
*/

#ifndef PET_EQUIP_PROTOCOL
#define PET_EQUIP_PROTOCOL

#pragma pack(push,1)

#include "pet_define.h"
#include "pet_equip_define.h"
#include "protocol_common_errorcode.h"

// 宠物装备物品
struct NET_SIC_pet_equip : public tag_net_message
{
	NET_SIC_pet_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_equip");
		dw_size = sizeof(NET_SIC_pet_equip);
	}
	DWORD       dwPetID;        //!< 宠物ID
	INT8		n8DstPos;		//!< 宠物装备栏位置
	INT64       n64ItemID;      //!< 64位itemid
};

struct NET_SIS_pet_equip : public tag_net_message
{
	NET_SIS_pet_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_equip");
		dw_size = sizeof(NET_SIS_pet_equip);
	}
	DWORD               dwErrCode;      //!< 错误码
	DWORD               dwPetID;        //!< 宠物ID
	tagPetEquipMsgInfo  itemData;       //!< 返回装备信息
};


// 宠物卸装物品
struct NET_SIC_pet_unequip : public tag_net_message
{
	NET_SIC_pet_unequip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_unequip");
		dw_size = sizeof(NET_SIC_pet_unequip);
	}
	DWORD		dwPetID;
	INT16		n16PosDst;		//!< 待放入背包中位置
	INT64       n64ItemID;      //!< 64位itemid
};

struct NET_SIS_pet_unequip : public tag_net_message
{
	NET_SIS_pet_unequip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_unequip");
		dw_size = sizeof(NET_SIS_pet_unequip);
	}
	DWORD       dwErrCode;      //!< 错误码
	DWORD		dwPetID;
	INT64       n64ItemID;      //!< 64位itemid
};


// 宠物装备位置交换
struct NET_SIC_pet_equip_position_swap : public tag_net_message
{
	NET_SIC_pet_equip_position_swap()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_equip_position_swap");
		dw_size = sizeof(NET_SIC_pet_equip_position_swap);
	}
	DWORD		dwPetID;
	INT8		n8PosDst;		//!< 装备移动到的目的位置
	INT64       n64ItemID;      //!< 64位itemid
};

struct NET_SIS_pet_equip_position_swap : public tag_net_message
{
	NET_SIS_pet_equip_position_swap()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_equip_position_swap");
		dw_size = sizeof(NET_SIS_pet_equip_position_swap);
	}
	DWORD       dwErrCode;      //!< 错误码
	DWORD		dwPetID;
	INT8		n8PosDst;		//!< 装备移动到的目的位置
	INT8		n8PosSrc;		//!< 装备原位置
	INT64       n64ItemID;      //!< 64位itemid
};


#pragma pack(pop)
#endif