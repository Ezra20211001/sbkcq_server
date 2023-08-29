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
*	@file		item_protocol.h
*	@author		lc
*	@date		2011/03/08	initial
*	@version	0.0.1.0
*	@brief		��Ʒ��װ����Ϣ
*/

#ifndef ITEM_PROTOCOL
#define ITEM_PROTOCOL

#include "protocol_common_errorcode.h"
#include "ItemDefine.h"
#include "AvatarAtt.h"

#pragma pack(push, 1)
//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum
{
	// �ò��ַŵ�protocol_common_errorcode.h�У��Ա��ģ��ͨ��
	E_Item_LevelLimit				= 9,		// �ȼ�������Ҫ��
	E_Item_SexLimit					= 10,		// �Ա�����Ҫ��
	E_Item_ClassLimit				= 11,		// ְҵ������Ҫ��
	E_Item_TalentLimit				= 12,		// ���ʲ�����Ҫ��
	E_Item_ClanRepLimit				= 13,		// ��������������Ҫ��
	E_Item_OtherRepLimit			= 14,		// ��������������Ҫ��
	E_Item_RoleStatusLimit			= 15,		// ���״̬(ս������ս��)������Ҫ��
	E_Item_AttA_Limit				= 16,		// һ�����Բ�����
	E_Item_Pk_Value_Limit			= 17,		// pkֵ������Χ

	E_Equip_OnFailed				= 100,		// װ��ʧ��
	E_Equip_NotRing					= 101,		// װ������ring
	E_Equip_InvalidPos				= 102,		// װ����λ��װ������Ҫ����λ����
	E_Equip_NotRingPos				= 103,		// װ����λ���ƶ���Ŀ��λ�ò���ring��λ
	E_Equip_SamePos					= 104,		// Ŀ��λ���뵱ǰλ��ͬ
	E_Equip_NotIdentify				= 105,		// װ��û�м���
	E_Equip_WeaponPos_Overlap		= 106,		// ����λ���ظ�
	E_Equip_Idendtifed				= 107,		// �����Ѽ�����
	E_Equip_Guard_DeadPunish		= 108,		// װ�����������ػ��������ԣ���ɫ����������
	E_Equip_Lock					= 109,		// ������Ʒ
	E_Equip_VocationLimit			= 110,		// ��ְҵ����װ����װ��
	E_Equip_Prictice				= 111,		// ���������в��ܻ�����

	E_BagPsd_Exist					= 150,		// ��������
	E_BagPsd_NoExist				= 151,		// δ������
	E_BagPsd_SafeCode_Error			= 152,		// ��ȫ�����
	E_BagPsd_Error					= 153,		// �������
	E_BagPsd_OK						= 154,		// ������ȷ

    E_Dye_OtherItem                 = 170,      // ֻ�ܶ�ʱװ����Ⱦɫ
    E_Dye_Exist                     = 171,      // ��ʱװ��Ϊ����ɫ������Ⱦɫ
    E_Dye_LvLimit                   = 172,      // Ⱦ�ϵȼ�����
	E_Dye_NotExist					= 173,		// װ������Ⱦ�ϲ�����

	E_Hang_NoCan_ChangeEquip		= 174,		// �һ��в��ܻ�װ


	E_Destory_Equip_Error			= 200,		// �󶴲��ܴݻ�װ��
};

//----------------------------------------------------------------------------
// װ�����������Ϣ(ע��ṹ���ֶ�˳����ñ�֤�ڴ����)
//----------------------------------------------------------------------------
// װ��
struct NET_SIC_equip : public tag_net_message
{
	NET_SIC_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip");
		dw_size = sizeof(NET_SIC_equip);
	}
	EEquipPos	ePosDst;		// װ����λ(ע���ָװ����λ���ͻ��������жϴ���)
	INT64		n64_serial;		// װ��64λ���к�
};

// ����װ����������Ӱ����������Ϣ����
struct NET_SIS_equip : public tag_net_message
{
	NET_SIS_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip");
		dw_size = sizeof(NET_SIS_equip);
	}
	DWORD		dw_error_code;
	INT64		n64_serial;		// װ��64λ���к�
};

struct NET_SIC_unequip : public tag_net_message
{
	NET_SIC_unequip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_unequip");
		dw_size = sizeof(NET_SIC_unequip);
	}
	INT16		n16PosDst;		// �����뱳����λ��
	INT16		n16Dummy;		// ������
	INT64		n64_serial;		// װ��64λ���к�
};

struct NET_SIS_unequip : public tag_net_message
{
	NET_SIS_unequip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_unequip");
		dw_size = sizeof(NET_SIS_unequip);
	}
	DWORD		dw_error_code;
	INT64		n64_serial;		// װ��64λ���к�
};

struct NET_SIC_swap_weapon : public tag_net_message
{
	NET_SIC_swap_weapon()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_swap_weapon");
		dw_size = sizeof(NET_SIC_swap_weapon);
	}
};

struct NET_SIS_swap_weapon : public tag_net_message
{
	NET_SIS_swap_weapon()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_swap_weapon");
		dw_size = sizeof(NET_SIS_swap_weapon);
	}
	DWORD		dw_error_code;
};

// ������۱仯
struct NET_SIS_avatar_equip_change : public tag_net_message
{
	NET_SIS_avatar_equip_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_avatar_equip_change");
		dw_size = sizeof(NET_SIS_avatar_equip_change);
	}
	DWORD			dw_role_id;
	tagEquipDisplay	EquipDisplay;	// װ�����
};

// ��������Ч���仯
struct NET_SIS_equip_effect_change : public tag_net_message
{
	NET_SIS_equip_effect_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_effect_change");
		dw_size = sizeof(NET_SIS_equip_effect_change);
	}
	DWORD			dw_role_id;
	BYTE			byDisplayPos;	// ģ��λ��
	BYTE			byEquipEffect;	// ����Ч��
};

// ��������
struct NET_SIC_identify_equip : public tag_net_message
{
	NET_SIC_identify_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_identify_equip");
		dw_size = sizeof(NET_SIC_identify_equip);
	}
	INT64		n64SerialReel;	// ��������
	INT64		n64SerialEquip;	// װ��
};

// ��������
struct NET_SIS_identify_equip : public tag_net_message
{
	NET_SIS_identify_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_identify_equip");
		dw_size = sizeof(NET_SIS_identify_equip);
	}
	DWORD		dw_error_code;
	INT64		n64_serial;
};

//װ��ά��
struct NET_SIC_equip_repair : public tag_net_message
{
	NET_SIC_equip_repair()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_repair");
		dw_size = sizeof(NET_SIC_equip_repair);
	}
	//INT64		n64SerialEquip;		//װ��
	DWORD		dwNPCID;			//NPCID
};

//װ��ά��
struct NET_SIS_equip_repair : public tag_net_message
{
	NET_SIS_equip_repair()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_repair");
		dw_size = sizeof(NET_SIS_equip_repair);
	}
	DWORD		dw_error_code;
};

struct NET_SIS_equip_change : public tag_net_message
{
	NET_SIS_equip_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_change");
		dw_size = sizeof(NET_SIS_equip_change);
	}
	INT64			n64_serial;
	tagEquipSpec	equipSpec;
};

// ��װ��Ч�ı�
struct NET_SIS_suit_effect : public tag_net_message
{
	NET_SIS_suit_effect()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_suit_effect");
		dw_size = sizeof(NET_SIS_suit_effect);
	}
	DWORD		dw_role_id;
	DWORD		dwSuitEffectID;
};

// ��װ�����ı�
struct NET_SIS_suit_num : public tag_net_message
{
	NET_SIS_suit_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_suit_num");
		dw_size = sizeof(NET_SIS_suit_num);
	}
	DWORD		dwSuitID;
	INT8		n8Num;
	INT8		n8Dummy[3];
};


//----------------------------------------------------------------------------
// ��Ʒλ�÷����仯
//----------------------------------------------------------------------------
// ��Ʒλ���ƶ� -- ͬһ��������
struct NET_SIC_item_position_change : public tag_net_message
{
	NET_SIC_item_position_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_item_position_change");
		dw_size = sizeof(NET_SIC_item_position_change);
	}
	EItemConType	eConType;		// ��������
	INT64			n64_serial;		// �ƶ�λ�õ���Ʒ
	INT16			n16Num;			// �ƶ���Ʒ�ĸ���(0��ʾȫ���ƶ�)
	INT16			n16PosDst;		// ��Ʒ�ƶ���Ŀ��λ��
	DWORD			dwNPCID;		// ְ��NPC ID(����ֻ�вֿ�ʹ��)
};

// ��Ʒλ���ƶ� -- ͬһ��������
struct NET_SIS_item_position_change : public tag_net_message
{
	NET_SIS_item_position_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_item_position_change");
		dw_size = sizeof(NET_SIS_item_position_change);
	}
	EItemConType	eConType;		// ��������
	INT64			n64Serial1;		// �ƶ�λ�õ���Ʒ1
	INT64			n64Serial2;		// ��Ӱ����Ʒ2, ��ΪINVALID_VALUEʱ, ��ʾ����Ʒ1�ƶ���һ����λ
	INT16			n16PosDst1;		// ��Ʒ1�ƶ���Ŀ��λ��
	INT16			n16PosDst2;		// ��Ʒ2�ƶ���Ŀ��λ��
	INT16			n16Num1;		// ��Ʒ1���ո��� -- ����ֵΪ0ʱ,�轫����Ʒɾ��,������������Ϣ
	INT16			n16Num2;		// ��Ʒ2���ո���
	BOOL			bCreateItem;	// n64Serial2�Ƿ�Ϊ�´�������Ʒ�� -- Ϊ�½���ʱ����ͻ��˴���������������Ϣ
};

// ��Ʒλ���ƶ� -- ��ͬ������
struct NET_SIC_item_position_change_extend : public tag_net_message
{
	NET_SIC_item_position_change_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_item_position_change_extend");
		dw_size = sizeof(NET_SIC_item_position_change_extend);
	}
	EItemConType	eConTypeSrc;	// Դ��������
	INT64			n64Serial1;		// �ƶ�λ�õ���Ʒ1
	EItemConType	eConTypeDst;	// Ŀ����������
	INT16			n16PosDst;		// ��Ʒ1�ƶ���Ŀ��λ��,ΪINVALID_VALUEʱ��ʾû��ָ��Ŀ��λ��
	INT16			n16Dummy;
	DWORD			dwNPCID;		// ְ��NPC ID(����ֻ�вֿ�ʹ��)
	DWORD			dw_safe_code;	// ��ȫ��
};

// ��Ʒλ���ƶ� -- ��ͬ������
struct NET_SIS_item_position_change_extend : public tag_net_message
{
	NET_SIS_item_position_change_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_item_position_change_extend");
		dw_size = sizeof(NET_SIS_item_position_change_extend);
	}
	EItemConType	eConTypeSrc1;	// �������� -- n64Serial1��ԭ����
	EItemConType	eConTypeSrc2;	// �������� -- n64Serial2��ԭ����
	EItemConType	eConTypeDst1;	// �������� -- n64Serial1��Ŀ������
	EItemConType	eConTypeDst2;	// �������� -- n64Serial2��Ŀ������
	INT16			n16PosDst1;		// ��Ʒ1�ƶ���Ŀ��λ��
	INT16			n16PosDst2;		// ��Ʒ2�ƶ���Ŀ��λ��
	INT64			n64Serial1;		// �ƶ�λ�õ���Ʒ1, ��ΪINVALID_VALUEʱ, ��ʾ��Ʒ2�ƶ���һ����λ
	INT64			n64Serial2;		// �ƶ�λ�õ���Ʒ2, ��ΪINVALID_VALUEʱ, ��ʾ��Ʒ1�ƶ���һ����λ
	INT16			n16Num1;		// ��Ʒ1���ո��� -- ����ֵΪ0ʱ,�轫����Ʒɾ��,������������Ϣ
	INT16			n16Num2;		// ��Ʒ2���ո���
};

// ��Ʒλ���ƶ� -- ��ͬ���� ��ȫ�����
struct NET_SIS_item_change_safe_code : public tag_net_message
{
	NET_SIS_item_change_safe_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_item_change_safe_code");
		dw_size = sizeof(*this);
	}
};

// ��������
struct NET_SIC_item_reorder : public tag_net_message
{
	NET_SIC_item_reorder()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_item_reorder");
		dw_size = sizeof(NET_SIC_item_reorder);
	}
	DWORD			dwNPCID;		// INVALID_VALUEʱ��Ϊ�ֿ���������Ϊ��������
	BYTE			by_type;		// 0 ���� 1 ����
	INT16			n16ItemNum;		// ��Ʒ����
	INT16			n16Index[1];	// ����ǰ��Ʒ�������е�λ�ã���ǰ�����±�Ϊ�����˳��
};

struct NET_SIS_item_reorder : public tag_net_message
{
	NET_SIS_item_reorder()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_item_reorder");
		dw_size = sizeof(NET_SIS_item_reorder);
	}
	DWORD			dw_error_code;
	EItemConType	eConType;		// ��������
	INT16			n16ItemNum;		// ��Ʒ����
	INT16			n16OldIndex[1];	// ��ǰ�����±�Ϊ�����˳��
};

// ��������
struct NET_SIC_item_reorder_extend : public tag_net_message
{
	NET_SIC_item_reorder_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_item_reorder_extend");
		dw_size = sizeof(NET_SIC_item_reorder_extend);
	}
	DWORD			dwNPCID;		// INVALID_VALUEʱ��Ϊ�ֿ���������Ϊ��������
	INT16			n16ItemNum;		// ��Ʒ����
	BYTE			byData[1];		// tagItemOrder
};

struct NET_SIS_item_reorder_extend : public tag_net_message
{
	NET_SIS_item_reorder_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_item_reorder_extend");
		dw_size = sizeof(NET_SIS_item_reorder_extend);
	}
	DWORD			dw_error_code;
	EItemConType	eConType;		// ��������
	INT16			n16ItemNum;		// ��Ʒ����
	BYTE			byData[1];		// tagItemOrder
};

// װ������
struct NET_SIC_equip_destroy : public tag_net_message
{
	NET_SIC_equip_destroy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_destroy");
		dw_size = sizeof(*this);
	}
	INT64	dw_item_serial;
	DWORD	dw_safe_code;
};

struct NET_SIS_equip_destroy : public tag_net_message
{
	NET_SIS_equip_destroy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_destroy");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//�ѵ���Ʒ
struct NET_SIC_stack_item : public tag_net_message
{
	NET_SIC_stack_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stack_item");
		dw_size = sizeof(NET_SIC_stack_item);
	}
	EItemConType	eConType;		// ��������
};

struct NET_SIS_stack_item : public tag_net_message
{
	NET_SIS_stack_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stack_item");
		dw_size = sizeof(NET_SIS_stack_item);
	}
	EItemConType	eConType;		// ��������
};

//----------------------------------------------------------------------------
// ��Ʒλ�÷����仯
//----------------------------------------------------------------------------
struct NET_SIC_ground_item : public tag_net_message
{
	NET_SIC_ground_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_ground_item");
		dw_size = sizeof(NET_SIC_ground_item);
	}
	INT64			n64_serial;
};

struct NET_SIS_item_add : public tag_net_message
{
	NET_SIS_item_add()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_item_add");
		dw_size = sizeof(NET_SIS_item_add);
	}
	//	DWORD			dw_error_code;
	INT64			n64_serial;
	EItemConType	eConType;
	INT16			n16Index;		// ������λ���±�
	INT16			n16Num;			// ����ǿɶѵ���Ʒ,��Ϊ�ö�����
	bool			bOverlap;		// �ص���Ʒ�Ƿ�������жѣ����true���迼���ͷ��ڴ�
	EItemCreateMode	eCreateMode;	// ��Ʒ&װ�����ɷ�ʽ gx add 2013.8.1Ϊ��ʶ��齱�õ�����Ʒ
};

struct NET_SIS_new_item_add : public tag_net_message
{
	NET_SIS_new_item_add()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_new_item_add");
		dw_size = sizeof(NET_SIS_new_item_add);
	}
	tagItem			Item;
};

struct NET_SIS_new_equip_add : public tag_net_message
{
	NET_SIS_new_equip_add()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_new_equip_add");
		dw_size = sizeof(NET_SIS_new_equip_add);
	}
	tagEquip		Equip;
	BOOL			bPickUp;
};

struct NET_SIC_item_remove : public tag_net_message
{
	NET_SIC_item_remove()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_item_remove");
		dw_size = sizeof(NET_SIC_item_remove);
	}
	EItemConType	eConType;
	INT64			n64_serial;
};

struct NET_SIS_item_remove : public tag_net_message
{
	NET_SIS_item_remove()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_item_remove");
		dw_size = sizeof(NET_SIS_item_remove);
	}
	//	DWORD			dw_error_code;
	EItemConType	eConType;
	INT64			n64_serial;
	INT16			n16Index;
	INT16			n16Num;			// ����ǿɶѵ���Ʒ,��Ϊʣ�����,Ϊ0��ʾȫ��ɾ��
	DWORD			dwCmdID;		// ͨ��ʲôɾ����,Ŀǰֻ������������ 153 Ϊ����
};

struct NET_SIS_item_cd_update : public tag_net_message
{
	NET_SIS_item_cd_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_item_cd_update");
		dw_size = sizeof(NET_SIS_item_cd_update);
	}
	DWORD			dw_data_id;
	DWORD			dwCDTime;
};


//----------------------------------------------------------------------------
// ���Ҽ������
//----------------------------------------------------------------------------
// ��������
struct NET_SIC_set_bag_password : public tag_net_message
{
	NET_SIC_set_bag_password()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_bag_password");
		dw_size = sizeof(NET_SIC_set_bag_password);
	}
	DWORD	dwBagPsdCrc;	// �����õ���������crcֵ
};

// ȡ������
struct NET_SIC_unset_bag_password : public tag_net_message
{
	NET_SIC_unset_bag_password()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_unset_bag_password");
		dw_size = sizeof(NET_SIC_unset_bag_password);
	}
	DWORD	dwSafeCodeCrc;	// ��ȫ���crcֵ
};

// ������
struct NET_SIC_old_bag_password : public tag_net_message
{
	NET_SIC_old_bag_password()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_old_bag_password");
		dw_size = sizeof(NET_SIC_old_bag_password);
	}
	DWORD	dwOldBagPsdCrc;
};

// �޸�����
struct NET_SIC_reset_bag_password : public tag_net_message
{
	NET_SIC_reset_bag_password()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reset_bag_password");
		dw_size = sizeof(NET_SIC_reset_bag_password);
	}
	DWORD	dwOldBagPsdCrc;
	DWORD	dwNewBagPsdCrc;
};

// �����ܣ��򿪱���ʱ���ȷ��͸���Ϣ
struct NET_SIC_open_bag_password : public tag_net_message
{
	NET_SIC_open_bag_password()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_open_bag_password");
		dw_size = sizeof(NET_SIC_open_bag_password);
	}
	DWORD	dwBagPsdCrc;
};


// �������������Ϣ����
struct NET_SIS_bag_password : public tag_net_message
{
	NET_SIS_bag_password()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bag_password");
		dw_size = sizeof(NET_SIS_bag_password);
	}
	DWORD	dw_error_code;
	//DWORD	dwRoleStateEx;	// ֻ������Լ�֪����״̬
};


//----------------------------------------------------------------------------
// ո�¶ȸ���
//----------------------------------------------------------------------------
struct NET_SIS_newess_change : public tag_net_message
{
	NET_SIS_newess_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_newess_change");
		dw_size = sizeof(NET_SIS_newess_change);
	}
	INT64		n64EquipSerial;		//װ��ID
	INT32		nAttackTimes;		//װ����ǰʹ�ô��� 
};


//----------------------------------------------------------------------------
// �����͸���
//----------------------------------------------------------------------------
struct NET_SIS_bind_change : public tag_net_message
{
	NET_SIS_bind_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bind_change");
		dw_size = sizeof(NET_SIS_bind_change);
	}
	INT64		n64EquipSerial;		//װ��ID
	BYTE		byBind;				//������
	tagDWORDTime time;				//��ʱ��
	EItemConType dwConType;			//�������� 
};

//----------------------------------------------------------------------------
// ʹ��Ⱦ��Ϊʱװ��ɫ���
//----------------------------------------------------------------------------
struct NET_SIC_dye_fashion : public tag_net_message
{
	NET_SIC_dye_fashion()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_dye_fashion");
		dw_size = sizeof(NET_SIC_dye_fashion);
	}
	INT64   n64DyeSN;       // Ⱦ��64λid
	INT64   n64EquipSerial; // ʱװװ��64λid
};

struct NET_SIS_dye_fashion : public tag_net_message
{	
	NET_SIS_dye_fashion()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_dye_fashion");
		dw_size = sizeof(NET_SIS_dye_fashion);
	}
	DWORD   dwErrCode;      // ������
};


//----------------------------------------------------------------------------
// �ٱ�����¼���
//----------------------------------------------------------------------------
// ����������ͳ�ʼ���ٱ�����¼����
struct NET_SIC_init_baibao_record : public tag_net_message
{
	NET_SIC_init_baibao_record()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_init_baibao_record");
		dw_size = sizeof(NET_SIC_init_baibao_record);
	}
};

// �������������е���Ϣ
struct NET_SIS_init_baibao_record : public tag_net_message
{
	NET_SIS_init_baibao_record()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_init_baibao_record");
		dw_size = sizeof(NET_SIS_init_baibao_record);
	}
	INT16	n16Num;				// ��¼����
	BYTE	byData[1];			// tagBaiBaoRecord�����ȼ���ȡn16Size����Ҫ��sizeof
};

// �������ʱ�����������͵����ٱ�����¼
struct NET_SIS_single_baobao_record : public tag_net_message
{
	NET_SIS_single_baobao_record()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_single_baobao_record");
		dw_size = sizeof(NET_SIS_single_baobao_record);
	}
	tagBaiBaoRecord	sRecord;	// ������¼
};

// ���Ͷ���װ������ͬ����Ϣ
struct NET_SIS_Team_Equip_Info : public tag_net_message
{
	NET_SIS_Team_Equip_Info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Team_Equip_Info");
		dw_size = sizeof(*this);
	}

	DWORD			 dw_RoleID;
	tagEquipTeamInfo st_EquipTeamInfo;
};


#pragma pack(pop)
#endif
