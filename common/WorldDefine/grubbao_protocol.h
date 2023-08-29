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
*	@file		grubbao_protocol.h
*	@author		lc
*	@date		2011/03/01	initial
*	@version	0.0.1.0
*	@brief		挖宝，开宝消息
*/

#ifndef GRUBBAO_PROTOCOL
#define GRUBBAO_PROTOCOL

#pragma pack(push, 1)

#include "protocol_common_errorcode.h"
#define MAX_CHEST_NUM 16

//普通藏宝图任务提示
enum ENormalTreasureMap 
{
	ENTM_NULL		= 1,
	ENTM_Nothing,					//一无所获
	ENTM_GainMoney,					//金钱奖励
	ENTM_ConfrontTrap,				//遭遇陷阱
	ENTM_Billiken,					//福神下凡
	ENTM_GainOlMap,					//获得古老藏宝图
	ENTM_GainKey,					//获得钥匙
	ENTM_GainOldChest,				//获得旧箱子
	ENTM_DriftBottle,				//漂流瓶
	ENTM_GainLoongSquamaChest,		//获得龙鳞宝箱
	ENTM_BadOldSeal,				//挖坏上古封印
	ENTM_Plutus,					//财神下凡
};

//古老藏宝图任务提示
enum EOldTreasureMap
{
	EOTM_NULL			=1,
	EOTM_Billiken,					//福神下凡
	EOTM_GainLoongSquamaChest,		//获得龙鳞宝箱
	EOTM_GainChest,					//获得箱子
	EOTM_GainLoongChest,			//获得玄龙宝箱
	EOTM_GainFourTreasures,			//获得文房四宝
	EOTM_GainKey,					//获得钥匙
	EOTM_GainRareTreaMap,			//获得绝世藏宝图
	EOTM_Plutus,					//挖到财神爷
	EOTM_DungeonEnter,				//发现密境入口
	EOTM_BadLoongPulse,				//掘断龙脉
	EOTM_BadOldSeal,				//挖坏上古封印
	EOTM_AwakenGods,				//唤醒上古之灵
};

//绝世藏宝图任务提示
enum ERareTreasureMap
{
	ERTM_NULL			= 1,
	ERTM_GainMoney,					//金钱奖励
	ERTM_GainRareStuff,				//获得稀有材料若干
	ERTM_GainDelicacyChest,			//获得精致的箱子
	ERTM_GainLoongChest,			//获得玄龙宝箱
	ERTM_GainLoongSquamaChest,		//获得龙鳞宝箱
	ERTM_GodsOfPractice,			//神之历练
	ERTM_MonsterAttackCity,			//开放怪物攻城活动
	ERTM_DungeonEnter,				//发现密境入口
	ERTM_AwakenGods,				//唤醒上古之灵
};

struct NET_SIC_grubbao : public tag_net_message
{
	NET_SIC_grubbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_grubbao");
		dw_size = sizeof(NET_SIC_grubbao);
	}
	DWORD				dwPlayerID;				//挖宝者ID
	DWORD				dwItemID;				//宝箱ID
	DWORD				dwItemTypdID;			//宝箱的TypeID
};

struct NET_SIS_grubbao : public tag_net_message
{
	NET_SIS_grubbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_grubbao");
		dw_size = sizeof(NET_SIS_grubbao);
	}
	DWORD				dw_error_code;			//错误码
	Vector3				v3Pos;					//宝箱的位置(宝箱消失后,播放特效)
};

//普通藏宝图任务消息
struct NET_SIS_normal_treasure_map : public tag_net_message
{
	NET_SIS_normal_treasure_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_normal_treasure_map");
		dw_size = sizeof(NET_SIS_normal_treasure_map);
	}
	ENormalTreasureMap	eType;					//普通藏宝图任务提示
};


//古老藏宝图任务消息
struct NET_SIS_old_treasure_map : public tag_net_message
{
	NET_SIS_old_treasure_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_old_treasure_map");
		dw_size = sizeof(NET_SIS_old_treasure_map);
	}
	EOldTreasureMap		eType;					//古老藏宝图任务提示
};


//绝世藏宝图任务消息
struct NET_SIS_rare_treasure_map : public tag_net_message
{
	NET_SIS_rare_treasure_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_rare_treasure_map");
		dw_size = sizeof(NET_SIS_rare_treasure_map);
	}
	ERareTreasureMap	eType;					//绝世藏宝图任务提示
};

//进入奇遇FB
struct NET_SIC_enter_adventure : public tag_net_message
{
	NET_SIC_enter_adventure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_enter_adventure");
		dw_size = sizeof(NET_SIC_enter_adventure);
	}
};

struct NET_SIS_enter_adventure : public tag_net_message
{
	NET_SIS_enter_adventure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_enter_adventure");
		dw_size = sizeof(NET_SIS_enter_adventure);
	}
};

//历练
struct NET_SIC_experience : public tag_net_message
{
	NET_SIC_experience()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_experience");
		dw_size = sizeof(NET_SIC_experience);
	}
};

struct NET_SIS_experience : public tag_net_message
{
	NET_SIS_experience()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_experience");
		dw_size = sizeof(NET_SIS_experience);
	}
};


//--------------------------------------------------------------------------------
//以下为开宝箱
//--------------------------------------------------------------------------------
enum EChestType
{
	EChestType_NULL			= 0,
	EChestType_LoongSquamaChest,		//龙鳞宝箱
	EChestType_WackeLoongChest,			//玄龙宝箱
	EChestType_GodLargessChest,			//天神赐福宝箱
	EChestType_DestinyBoxChest,			//命运宝箱
};

struct NET_SIC_treasure_chest : public tag_net_message
{
	NET_SIC_treasure_chest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_treasure_chest");
		dw_size = sizeof(NET_SIC_treasure_chest);
	}
	INT64			n64ChestID;			//宝箱(龙鳞宝箱或玄龙宝箱)
	INT64			n64KeyID;			//钥匙
};

struct NET_SIS_treasure_chest : public tag_net_message
{
	NET_SIS_treasure_chest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_treasure_chest");
		dw_size = sizeof(NET_SIS_treasure_chest);
	}
	DWORD			dwChestTypeID;				//宝箱的TypdID
	DWORD			dw_data_id[MAX_CHEST_NUM];	//物品ID
	INT				n_num[MAX_CHEST_NUM];		//开出的数量
	DWORD			dw_error_code;
};

struct NET_SIC_stop_treasure_chest : public tag_net_message
{
	NET_SIC_stop_treasure_chest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stop_treasure_chest");
		dw_size = sizeof(NET_SIC_stop_treasure_chest);
	}
	INT64			n64ChestID;			//宝箱
	INT64			n64KeyID;			//钥匙
};

struct NET_SIS_stop_treasure_chest : public tag_net_message
{
	NET_SIS_stop_treasure_chest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stop_treasure_chest");
		dw_size = sizeof(NET_SIS_stop_treasure_chest);
	}
	DWORD			dw_data_id;			//开出的物品
	INT				n_num;				//开出的数量
	DWORD			dw_error_code;
};

struct NET_SIC_repeat_treasure_chest : public tag_net_message
{	
	NET_SIC_repeat_treasure_chest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_repeat_treasure_chest");
		dw_size = sizeof(NET_SIC_repeat_treasure_chest);
	}
	INT64			n64ChestID;			//宝箱
	INT64			n64KeyID;			//钥匙
};

struct NET_SIS_repeat_treasure_chest : public tag_net_message
{
	NET_SIS_repeat_treasure_chest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_repeat_treasure_chest");
		dw_size = sizeof(NET_SIS_repeat_treasure_chest);
	}
	BYTE			byDestroy;			//毁坏为1,没毁坏为0
	DWORD			dw_error_code;
};

struct NET_SIC_get_treasure_item : public tag_net_message
{
	NET_SIC_get_treasure_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_treasure_item");
		dw_size = sizeof(NET_SIC_get_treasure_item);
	}
	DWORD			dw_data_id;
};

struct NET_SIS_get_treasure_item : public tag_net_message
{
	NET_SIS_get_treasure_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_treasure_item");
		dw_size = sizeof(NET_SIS_get_treasure_item);
	}
	DWORD			dw_error_code;
};

#pragma pack(pop)
#endif