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
*	@file		shop_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		�̵���Ϣ
*/


#ifndef SHOP_PROTOCOL
#define SHOP_PROTOCOL

#include "protocol_common_errorcode.h"

#pragma pack(push, 1)

//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum 
{
	E_Shop_NPCNotValid				= 1,	// NPC�Ƿ�
	E_Shop_NotValid					= 2,	// �̵�Ƿ�
	E_Shop_ItemNotFind				= 3,	// û���ҵ�ָ����Ʒ
	E_Shop_ItemCannotSell			= 4,	// ָ����Ʒ���ɳ���
	E_Shop_ItemNotEnough			= 5,	// ��Ʒ��������
	E_Shop_CreateItem_Failed		= 6,	// ����������Ʒʱʧ��(1.�ڴ�����ʧ��;2.û���ҵ���Ʒװ��ԭ��)
	E_Shop_Equip_Sold				= 7,	// ָ��װ���Ѿ�������
	E_Shop_CreateEquip_Failed		= 8,	// ����װ��ʱ,������װ��ʧ��(1.�ڴ�����ʧ��)
	E_Shop_NotEnough_SpaceInBag		= 9,	// ������û���㹻�洢�ռ�
	E_Shop_RepLevel_Low				= 10,	// �����׶β���
	E_Shop_NotEnough_SilverInBag	= 11,	// �����н�Ǯ����
	E_Shop_NotEnough_SpecCost		= 12,	// �������Ĳ���
	E_Shop_ItemMaxHold				= 13,	// ��Ʒ�ﵽ��ӵ������
	E_Shop_ItemNotActived			= 14,	// ���屦������Ʒû�м���
	E_Shop_ItemCannotSellXiulian	= 15,	// ������������������
	E_Shop_Exploits_Limit			= 16,	// ս���̵��������
};


//-----------------------------------------------------------------------------
// �õ��̵�����Ʒ�б�
//-----------------------------------------------------------------------------
struct NET_SIC_get_shop_item : public tag_net_message
{
	NET_SIC_get_shop_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_shop_item");
		dw_size = sizeof(NET_SIC_get_shop_item);
	}
	DWORD 			dwNPCID; 		// NPC ID
	BYTE			byShelf;		// ���ܺ�
};

struct NET_SIS_get_shop_item : public tag_net_message
{
	NET_SIS_get_shop_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_shop_item");
		dw_size = sizeof(NET_SIS_get_shop_item);
	}
	DWORD 			dwNPCID; 		// NPC ID
	DWORD			dwShopID;		// shop ID
	BYTE			byShelf;		// ���ܺ�
	BYTE			byDummy;		// ������
	INT16			n16RareItemNum;	// ϡ����Ʒ����
	INT				nShopExploitsNum;	// ս���������
	BYTE			byData[1];		// tagMsgShopItem
};

struct NET_SIC_get_shop_equip : public tag_net_message
{
	NET_SIC_get_shop_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_shop_equip");
		dw_size = sizeof(NET_SIC_get_shop_equip);
	}
	DWORD 			dwNPCID; 		// NPC ID
	BYTE			byShelf;		// ���ܺ�
};

struct NET_SIS_get_shop_equip : public tag_net_message
{
	NET_SIS_get_shop_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_shop_equip");
		dw_size = sizeof(NET_SIS_get_shop_equip);
	}
	DWORD 			dwNPCID; 		// NPC ID
	DWORD			dwShopID;		// shop ID
	BYTE			byShelf;		// ���ܺ�
	BYTE			byDummy;		// ������
	INT16			n16EquipNum;	// ����װ������
	BYTE			byData[1];		// tagMsgShopEquip
};


//-----------------------------------------------------------------------------
// ��Ҵ��̵�����Ʒ
//-----------------------------------------------------------------------------
struct NET_SIC_buy_shop_item : public tag_net_message
{
	NET_SIC_buy_shop_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_buy_shop_item");
		dw_size = sizeof(NET_SIC_buy_shop_item);
	}
	DWORD 			dwNPCID; 		// NPC ID
	BYTE			byShelf;		// ���ܺ�
	BYTE			byDummy;		// ������
	INT16			n16ItemNum;		// ��Ʒ����
	DWORD 			dw_data_id; 		// ���Ҫ�������ƷType ID
	DWORD			dw_safe_code;
};

struct NET_SIS_buy_shop_item : public tag_net_message
{
	NET_SIS_buy_shop_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_buy_shop_item");
		dw_size = sizeof(NET_SIS_buy_shop_item);
	}
	DWORD 			dwNPCID; 		// NPC ID
	BYTE			byShelf;		// ���ܺ�
	BYTE			byIndex;		// ��Ӧλ��
	INT16			n16RemainNum;	// ʣ�����(��ֵΪINVALID_VALUEʱ����ʾ����Ʒ������)
	DWORD 			dw_data_id;		// ���Ҫ�������ƷType ID
};

struct NET_SIC_buy_shop_equip : public tag_net_message
{
	NET_SIC_buy_shop_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_buy_shop_equip");
		dw_size = sizeof(NET_SIC_buy_shop_equip);
	}
	DWORD 			dwNPCID; 		// NPC ID
	INT64			n64_serial;		// Ҫ����װ����64λID
	DWORD			dw_data_id;		// ����װ����Type ID
	BYTE			byShelf;		// ���ܺ�
	DWORD			dw_safe_code;
};

struct NET_SIS_buy_shop_equip : public tag_net_message
{
	NET_SIS_buy_shop_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_buy_shop_equip");
		dw_size = sizeof(NET_SIS_buy_shop_equip);
	}
	DWORD 			dwNPCID; 		// NPC ID
	BYTE			byShelf;		// ���ܺ�
	BYTE			byIndex;		// ��Ӧλ��
	INT16			n16RemainNum;	// ʣ�����(��ֵΪINVALID_VALUEʱ����ʾ����Ʒ������)
	BYTE			byData[1];		// n16RemainNum != 0 && dw_error_code == E_Successʱ, �����µĴ���װ�� -- tagEquip
};


//-----------------------------------------------------------------------------
//	������̵�����Ʒ
//-----------------------------------------------------------------------------
struct NET_SIC_sell_to_shop : public tag_net_message
{
	NET_SIC_sell_to_shop()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_sell_to_shop");
		dw_size = sizeof(NET_SIC_sell_to_shop);
	}
	DWORD 			dwNPCID; 		// NPC ID
	int				nNumber;		// ����
	INT64			n64_serial[1]; 	// ���Ҫ����64λ��ƷID
};

//-----------------------------------------------------------------------------
// �̵������Ϣ����ʧ�ܺ�,�������ͻ��˵���Ϣ�ṹ
//-----------------------------------------------------------------------------
struct NET_SIS_feedback_from_shop : public tag_net_message
{
	NET_SIS_feedback_from_shop()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_feedback_from_shop");
		dw_size = sizeof(NET_SIS_feedback_from_shop);
	}
	DWORD			dw_error_code;
	DWORD 			dwNPCID; 		// NPC ID
};


#pragma pack(pop) 
#endif
