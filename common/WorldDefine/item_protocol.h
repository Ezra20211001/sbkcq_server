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
*	@brief		物品，装备消息
*/

#ifndef ITEM_PROTOCOL
#define ITEM_PROTOCOL

#include "protocol_common_errorcode.h"
#include "ItemDefine.h"
#include "AvatarAtt.h"

#pragma pack(push, 1)
//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum
{
	// 该部分放到protocol_common_errorcode.h中，以便各模块通用
	E_Item_LevelLimit				= 9,		// 等级不满足要求
	E_Item_SexLimit					= 10,		// 性别不满足要求
	E_Item_ClassLimit				= 11,		// 职业不满足要求
	E_Item_TalentLimit				= 12,		// 天资不满足要求
	E_Item_ClanRepLimit				= 13,		// 氏族声望不满足要求
	E_Item_OtherRepLimit			= 14,		// 其他声望不满足要求
	E_Item_RoleStatusLimit			= 15,		// 玩家状态(战斗，非战斗)不满足要求
	E_Item_AttA_Limit				= 16,		// 一级属性不满足
	E_Item_Pk_Value_Limit			= 17,		// pk值超出范围

	E_Equip_OnFailed				= 100,		// 装备失败
	E_Equip_NotRing					= 101,		// 装备不是ring
	E_Equip_InvalidPos				= 102,		// 装备栏位与装备类型要求栏位不符
	E_Equip_NotRingPos				= 103,		// 装备栏位中移动的目标位置不是ring栏位
	E_Equip_SamePos					= 104,		// 目标位置与当前位置同
	E_Equip_NotIdentify				= 105,		// 装备没有鉴定
	E_Equip_WeaponPos_Overlap		= 106,		// 武器位置重复
	E_Equip_Idendtifed				= 107,		// 武器已鉴定过
	E_Equip_Guard_DeadPunish		= 108,		// 装备具有死亡守护特殊属性，角色死亡不掉落
	E_Equip_Lock					= 109,		// 锁定物品
	E_Equip_VocationLimit			= 110,		// 该职业不能装备该装备
	E_Equip_Prictice				= 111,		// 武器修炼中不能换武器

	E_BagPsd_Exist					= 150,		// 已设密码
	E_BagPsd_NoExist				= 151,		// 未设密码
	E_BagPsd_SafeCode_Error			= 152,		// 安全码错误
	E_BagPsd_Error					= 153,		// 密码错误
	E_BagPsd_OK						= 154,		// 密码正确

    E_Dye_OtherItem                 = 170,      // 只能对时装进行染色
    E_Dye_Exist                     = 171,      // 该时装已为该颜色，不需染色
    E_Dye_LvLimit                   = 172,      // 染料等级不足
	E_Dye_NotExist					= 173,		// 装备或者染料不存在

	E_Hang_NoCan_ChangeEquip		= 174,		// 挂机中不能换装


	E_Destory_Equip_Error			= 200,		// 矿洞不能摧毁装备
};

//----------------------------------------------------------------------------
// 装备穿戴相关消息(注意结构中字段顺序最好保证内存对齐)
//----------------------------------------------------------------------------
// 装备
struct NET_SIC_equip : public tag_net_message
{
	NET_SIC_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip");
		dw_size = sizeof(NET_SIC_equip);
	}
	EEquipPos	ePosDst;		// 装备部位(注意戒指装备部位，客户端需做判断处理)
	INT64		n64_serial;		// 装备64位序列号
};

// 反回装备结果，相关影响由其他消息处理
struct NET_SIS_equip : public tag_net_message
{
	NET_SIS_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip");
		dw_size = sizeof(NET_SIS_equip);
	}
	DWORD		dw_error_code;
	INT64		n64_serial;		// 装备64位序列号
};

struct NET_SIC_unequip : public tag_net_message
{
	NET_SIC_unequip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_unequip");
		dw_size = sizeof(NET_SIC_unequip);
	}
	INT16		n16PosDst;		// 待放入背包中位置
	INT16		n16Dummy;		// 对齐用
	INT64		n64_serial;		// 装备64位序列号
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
	INT64		n64_serial;		// 装备64位序列号
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

// 武器外观变化
struct NET_SIS_avatar_equip_change : public tag_net_message
{
	NET_SIS_avatar_equip_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_avatar_equip_change");
		dw_size = sizeof(NET_SIS_avatar_equip_change);
	}
	DWORD			dw_role_id;
	tagEquipDisplay	EquipDisplay;	// 装备外观
};

// 武器挂载效果变化
struct NET_SIS_equip_effect_change : public tag_net_message
{
	NET_SIS_equip_effect_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_effect_change");
		dw_size = sizeof(NET_SIS_equip_effect_change);
	}
	DWORD			dw_role_id;
	BYTE			byDisplayPos;	// 模型位置
	BYTE			byEquipEffect;	// 挂载效果
};

// 武器鉴定
struct NET_SIC_identify_equip : public tag_net_message
{
	NET_SIC_identify_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_identify_equip");
		dw_size = sizeof(NET_SIC_identify_equip);
	}
	INT64		n64SerialReel;	// 鉴定卷轴
	INT64		n64SerialEquip;	// 装备
};

// 武器鉴定
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

//装备维修
struct NET_SIC_equip_repair : public tag_net_message
{
	NET_SIC_equip_repair()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_repair");
		dw_size = sizeof(NET_SIC_equip_repair);
	}
	//INT64		n64SerialEquip;		//装备
	DWORD		dwNPCID;			//NPCID
};

//装备维修
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

// 套装特效改变
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

// 套装个数改变
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
// 物品位置发生变化
//----------------------------------------------------------------------------
// 物品位置移动 -- 同一个容器内
struct NET_SIC_item_position_change : public tag_net_message
{
	NET_SIC_item_position_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_item_position_change");
		dw_size = sizeof(NET_SIC_item_position_change);
	}
	EItemConType	eConType;		// 容器类型
	INT64			n64_serial;		// 移动位置的物品
	INT16			n16Num;			// 移动物品的个数(0表示全部移动)
	INT16			n16PosDst;		// 物品移动的目标位置
	DWORD			dwNPCID;		// 职能NPC ID(现在只有仓库使用)
};

// 物品位置移动 -- 同一个容器内
struct NET_SIS_item_position_change : public tag_net_message
{
	NET_SIS_item_position_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_item_position_change");
		dw_size = sizeof(NET_SIS_item_position_change);
	}
	EItemConType	eConType;		// 容器类型
	INT64			n64Serial1;		// 移动位置的物品1
	INT64			n64Serial2;		// 受影响物品2, 当为INVALID_VALUE时, 表示将物品1移动到一个空位
	INT16			n16PosDst1;		// 物品1移动的目标位置
	INT16			n16PosDst2;		// 物品2移动的目标位置
	INT16			n16Num1;		// 物品1最终个数 -- 当该值为0时,需将该物品删除,服务器不另发消息
	INT16			n16Num2;		// 物品2最终个数
	BOOL			bCreateItem;	// n64Serial2是否为新创建的物品堆 -- 为新建堆时，需客户端处理，服务器不另发消息
};

// 物品位置移动 -- 不同容器内
struct NET_SIC_item_position_change_extend : public tag_net_message
{
	NET_SIC_item_position_change_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_item_position_change_extend");
		dw_size = sizeof(NET_SIC_item_position_change_extend);
	}
	EItemConType	eConTypeSrc;	// 源容器类型
	INT64			n64Serial1;		// 移动位置的物品1
	EItemConType	eConTypeDst;	// 目的容器类型
	INT16			n16PosDst;		// 物品1移动的目标位置,为INVALID_VALUE时表示没有指定目标位置
	INT16			n16Dummy;
	DWORD			dwNPCID;		// 职能NPC ID(现在只有仓库使用)
	DWORD			dw_safe_code;	// 安全码
};

// 物品位置移动 -- 不同容器内
struct NET_SIS_item_position_change_extend : public tag_net_message
{
	NET_SIS_item_position_change_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_item_position_change_extend");
		dw_size = sizeof(NET_SIS_item_position_change_extend);
	}
	EItemConType	eConTypeSrc1;	// 容器类型 -- n64Serial1的原容器
	EItemConType	eConTypeSrc2;	// 容器类型 -- n64Serial2的原容器
	EItemConType	eConTypeDst1;	// 容器类型 -- n64Serial1的目标容器
	EItemConType	eConTypeDst2;	// 容器类型 -- n64Serial2的目标容器
	INT16			n16PosDst1;		// 物品1移动的目标位置
	INT16			n16PosDst2;		// 物品2移动的目标位置
	INT64			n64Serial1;		// 移动位置的物品1, 当为INVALID_VALUE时, 表示物品2移动到一个空位
	INT64			n64Serial2;		// 移动位置的物品2, 当为INVALID_VALUE时, 表示物品1移动到一个空位
	INT16			n16Num1;		// 物品1最终个数 -- 当该值为0时,需将该物品删除,服务器不另发消息
	INT16			n16Num2;		// 物品2最终个数
};

// 物品位置移动 -- 不同容器 安全码错误
struct NET_SIS_item_change_safe_code : public tag_net_message
{
	NET_SIS_item_change_safe_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_item_change_safe_code");
		dw_size = sizeof(*this);
	}
};

// 行囊整理
struct NET_SIC_item_reorder : public tag_net_message
{
	NET_SIC_item_reorder()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_item_reorder");
		dw_size = sizeof(NET_SIC_item_reorder);
	}
	DWORD			dwNPCID;		// INVALID_VALUE时，为仓库整理；否则为背包整理
	BYTE			by_type;		// 0 包裹 1 人物
	INT16			n16ItemNum;		// 物品个数
	INT16			n16Index[1];	// 排序前物品在容器中的位置，当前数组下标为排序后顺序
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
	EItemConType	eConType;		// 容器类型
	INT16			n16ItemNum;		// 物品个数
	INT16			n16OldIndex[1];	// 当前数组下标为排序后顺序
};

// 行囊整理
struct NET_SIC_item_reorder_extend : public tag_net_message
{
	NET_SIC_item_reorder_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_item_reorder_extend");
		dw_size = sizeof(NET_SIC_item_reorder_extend);
	}
	DWORD			dwNPCID;		// INVALID_VALUE时，为仓库整理；否则为背包整理
	INT16			n16ItemNum;		// 物品个数
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
	EItemConType	eConType;		// 容器类型
	INT16			n16ItemNum;		// 物品个数
	BYTE			byData[1];		// tagItemOrder
};

// 装备销毁
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

//堆叠物品
struct NET_SIC_stack_item : public tag_net_message
{
	NET_SIC_stack_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stack_item");
		dw_size = sizeof(NET_SIC_stack_item);
	}
	EItemConType	eConType;		// 容器类型
};

struct NET_SIS_stack_item : public tag_net_message
{
	NET_SIS_stack_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stack_item");
		dw_size = sizeof(NET_SIS_stack_item);
	}
	EItemConType	eConType;		// 容器类型
};

//----------------------------------------------------------------------------
// 物品位置发生变化
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
	INT16			n16Index;		// 容器中位置下标
	INT16			n16Num;			// 如果是可堆叠物品,则为该堆总数
	bool			bOverlap;		// 重叠物品是否放入已有堆，如果true，需考虑释放内存
	EItemCreateMode	eCreateMode;	// 物品&装备生成方式 gx add 2013.8.1为了识别抽奖得到的物品
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
	INT16			n16Num;			// 如果是可堆叠物品,则为剩余个数,为0表示全部删除
	DWORD			dwCmdID;		// 通过什么删除的,目前只用于武器修炼 153 为修炼
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
// 行囊加密相关
//----------------------------------------------------------------------------
// 设置密码
struct NET_SIC_set_bag_password : public tag_net_message
{
	NET_SIC_set_bag_password()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_bag_password");
		dw_size = sizeof(NET_SIC_set_bag_password);
	}
	DWORD	dwBagPsdCrc;	// 欲设置的行囊密码crc值
};

// 取消密码
struct NET_SIC_unset_bag_password : public tag_net_message
{
	NET_SIC_unset_bag_password()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_unset_bag_password");
		dw_size = sizeof(NET_SIC_unset_bag_password);
	}
	DWORD	dwSafeCodeCrc;	// 安全码的crc值
};

// 旧密码
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

// 修改密码
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

// 若加密，打开背包时需先发送该消息
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


// 行囊密码相关消息反馈
struct NET_SIS_bag_password : public tag_net_message
{
	NET_SIS_bag_password()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bag_password");
		dw_size = sizeof(NET_SIS_bag_password);
	}
	DWORD	dw_error_code;
	//DWORD	dwRoleStateEx;	// 只需玩家自己知道的状态
};


//----------------------------------------------------------------------------
// 崭新度更新
//----------------------------------------------------------------------------
struct NET_SIS_newess_change : public tag_net_message
{
	NET_SIS_newess_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_newess_change");
		dw_size = sizeof(NET_SIS_newess_change);
	}
	INT64		n64EquipSerial;		//装备ID
	INT32		nAttackTimes;		//装备当前使用次数 
};


//----------------------------------------------------------------------------
// 绑定类型更新
//----------------------------------------------------------------------------
struct NET_SIS_bind_change : public tag_net_message
{
	NET_SIS_bind_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bind_change");
		dw_size = sizeof(NET_SIS_bind_change);
	}
	INT64		n64EquipSerial;		//装备ID
	BYTE		byBind;				//绑定类型
	tagDWORDTime time;				//绑定时间
	EItemConType dwConType;			//容器类型 
};

//----------------------------------------------------------------------------
// 使用染料为时装上色相关
//----------------------------------------------------------------------------
struct NET_SIC_dye_fashion : public tag_net_message
{
	NET_SIC_dye_fashion()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_dye_fashion");
		dw_size = sizeof(NET_SIC_dye_fashion);
	}
	INT64   n64DyeSN;       // 染料64位id
	INT64   n64EquipSerial; // 时装装备64位id
};

struct NET_SIS_dye_fashion : public tag_net_message
{	
	NET_SIS_dye_fashion()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_dye_fashion");
		dw_size = sizeof(NET_SIS_dye_fashion);
	}
	DWORD   dwErrCode;      // 错误码
};


//----------------------------------------------------------------------------
// 百宝袋记录相关
//----------------------------------------------------------------------------
// 向服务器发送初始化百宝袋记录请求
struct NET_SIC_init_baibao_record : public tag_net_message
{
	NET_SIC_init_baibao_record()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_init_baibao_record");
		dw_size = sizeof(NET_SIC_init_baibao_record);
	}
};

// 服务器返回所有的消息
struct NET_SIS_init_baibao_record : public tag_net_message
{
	NET_SIS_init_baibao_record()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_init_baibao_record");
		dw_size = sizeof(NET_SIS_init_baibao_record);
	}
	INT16	n16Num;				// 记录数量
	BYTE	byData[1];			// tagBaiBaoRecord，长度计算取n16Size，不要用sizeof
};

// 玩家在线时，服务器发送单条百宝袋记录
struct NET_SIS_single_baobao_record : public tag_net_message
{
	NET_SIS_single_baobao_record()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_single_baobao_record");
		dw_size = sizeof(NET_SIS_single_baobao_record);
	}
	tagBaiBaoRecord	sRecord;	// 单条记录
};

// 发送队伍装备数据同步消息
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
