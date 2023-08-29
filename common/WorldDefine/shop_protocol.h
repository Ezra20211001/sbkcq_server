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
*	@brief		商店消息
*/


#ifndef SHOP_PROTOCOL
#define SHOP_PROTOCOL

#include "protocol_common_errorcode.h"

#pragma pack(push, 1)

//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum 
{
	E_Shop_NPCNotValid				= 1,	// NPC非法
	E_Shop_NotValid					= 2,	// 商店非法
	E_Shop_ItemNotFind				= 3,	// 没有找到指定商品
	E_Shop_ItemCannotSell			= 4,	// 指定商品不可出售
	E_Shop_ItemNotEnough			= 5,	// 商品个数不足
	E_Shop_CreateItem_Failed		= 6,	// 创建出售商品时失败(1.内存申请失败;2.没有找到物品装备原型)
	E_Shop_Equip_Sold				= 7,	// 指定装备已经被出售
	E_Shop_CreateEquip_Failed		= 8,	// 出售装备时,创建新装备失败(1.内存申请失败)
	E_Shop_NotEnough_SpaceInBag		= 9,	// 背包中没有足够存储空间
	E_Shop_RepLevel_Low				= 10,	// 声望阶段不够
	E_Shop_NotEnough_SilverInBag	= 11,	// 背包中金钱不足
	E_Shop_NotEnough_SpecCost		= 12,	// 特殊消耗不足
	E_Shop_ItemMaxHold				= 13,	// 物品达到可拥有上限
	E_Shop_ItemNotActived			= 14,	// 氏族宝库中物品没有激活
	E_Shop_ItemCannotSellXiulian	= 15,	// 修炼过的武器不能卖
	E_Shop_Exploits_Limit			= 16,	// 战功商店次数限制
};


//-----------------------------------------------------------------------------
// 得到商店中商品列表
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
	BYTE			byShelf;		// 货架号
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
	BYTE			byShelf;		// 货架号
	BYTE			byDummy;		// 对齐用
	INT16			n16RareItemNum;	// 稀有物品个数
	INT				nShopExploitsNum;	// 战功购买次数
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
	BYTE			byShelf;		// 货架号
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
	BYTE			byShelf;		// 货架号
	BYTE			byDummy;		// 对齐用
	INT16			n16EquipNum;	// 所有装备个数
	BYTE			byData[1];		// tagMsgShopEquip
};


//-----------------------------------------------------------------------------
// 玩家从商店买商品
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
	BYTE			byShelf;		// 货架号
	BYTE			byDummy;		// 对齐用
	INT16			n16ItemNum;		// 物品个数
	DWORD 			dw_data_id; 		// 玩家要购买的物品Type ID
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
	BYTE			byShelf;		// 货架号
	BYTE			byIndex;		// 对应位置
	INT16			n16RemainNum;	// 剩余个数(该值为INVALID_VALUE时，表示该商品不限量)
	DWORD 			dw_data_id;		// 玩家要购买的物品Type ID
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
	INT64			n64_serial;		// 要购买装备的64位ID
	DWORD			dw_data_id;		// 将购装备的Type ID
	BYTE			byShelf;		// 货架号
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
	BYTE			byShelf;		// 货架号
	BYTE			byIndex;		// 对应位置
	INT16			n16RemainNum;	// 剩余个数(该值为INVALID_VALUE时，表示该商品不限量)
	BYTE			byData[1];		// n16RemainNum != 0 && dw_error_code == E_Success时, 生成新的待售装备 -- tagEquip
};


//-----------------------------------------------------------------------------
//	玩家向商店卖物品
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
	int				nNumber;		// 数量
	INT64			n64_serial[1]; 	// 玩家要卖的64位物品ID
};

//-----------------------------------------------------------------------------
// 商店相关消息处理失败后,反馈给客户端的消息结构
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
