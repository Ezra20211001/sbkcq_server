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
*	@brief		掉落消息
*/

#ifndef DROP_PROTOCOL
#define DROP_PROTOCOL


#include "protocol_common_errorcode.h"
#include "loot.h"

#pragma pack(push, 1)

enum
{
	E_Loot_BAG_NOT_ENOUGH_SPACE = 1,	//背包没有足够空间
	E_Loot_Item_Not_Found		= 2,	//拾取物品没找到
	E_Loot_Role_Not_Found		= 3,	//拾取玩家没找到
	E_Loot_Map_Not_Found		= 4,	//拾取玩家所在地图没找到
	E_Loot_Add_Bag_Not_Success  = 5,	//加入背包不成功
	E_Loot_Disard_Item_Not_Success  = 6,	//加入背包不成功
	E_Loot_Pick_Up_Too_Far			= 7,	//玩家距离物品太远,无法拾取
	E_Loot_Belong_To_Team			= 8,	//只有本小队所有玩家才能拾取
	E_Loot_Belong_To_Teammate		= 9,	//只有本小队内指定的玩家才能拾取
	E_Loot_Belong_To_You			= 10,	//该物品不属于您
	E_Loot_WaitForAssign			= 11,	//等待分配
};

//-----------------------------------------------------------------------------
//	地面物体同步	S------>C
//-----------------------------------------------------------------------------
struct NET_SIS_synchronize_item : public tag_net_message
{
	NET_SIS_synchronize_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_item");
		dw_size = sizeof(NET_SIS_synchronize_item);
	}
	INT64	n64_serial;			// 物体序列号
	DWORD	dwPutDownUnitID;	// 掉落物品的UintID
	DWORD	dwOwnerID;			// 归属角色
	DWORD	dwTeamID;			// 归属小队ID
	DWORD	dwGroupID;			// 归属团队ID
	DWORD	dw_data_id;			// 类型
	INT		n_num;				// 数目
	Vector3 vPos;				// 物品掉落位置
	BOOL    bKilled;			// 怪物是否被击杀或玩家死亡
	BYTE	byQuality;			// 品质
};


//-----------------------------------------------------------------------------
//	地面物体消失---被捡起或者时间到 变长  S------>C
//-----------------------------------------------------------------------------
struct NET_SIS_role_ground_item_disappear : public tag_net_message
{
	NET_SIS_role_ground_item_disappear()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_ground_item_disappear");
		dw_size = sizeof(NET_SIS_role_ground_item_disappear);
	}
	INT64	n64_serial[1];	// 物体序列号
};



//-----------------------------------------------------------------------------
//	人物主动掉落物品---就是销毁此物品 
//-----------------------------------------------------------------------------
struct NET_SIC_role_putdown_item : public tag_net_message
{
	NET_SIC_role_putdown_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_putdown_item");
		dw_size = sizeof(NET_SIC_role_putdown_item);
	}
	INT64	n64_serial;	// 物体序列号
	BYTE	by_type;	// 容器类型 0 包裹 1 人物
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
	INT64	n64_serial;	// 物体序列号
	DWORD	dw_error_code;	//返回错误码
};


//-----------------------------------------------------------------------------
//	拾取物品
//-----------------------------------------------------------------------------
struct NET_SIC_role_pickup_item : public tag_net_message
{
	NET_SIC_role_pickup_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_pickup_item");
		dw_size = sizeof(NET_SIC_role_pickup_item);
	}
	INT64 n64_serial;		//物品ID 
};

struct NET_SIS_role_pickup_item : public tag_net_message
{
	NET_SIS_role_pickup_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_pickup_item");
		dw_size = sizeof(NET_SIS_role_pickup_item);
	}
	DWORD dw_role_id;			// 拾取人ID
	INT64 n64_serial;        // 物品64位ID
	DWORD dw_error_code;		// 返回错误码
};


#pragma pack(pop)
#endif
