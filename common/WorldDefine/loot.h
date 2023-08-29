//-----------------------------------------------------------------------------
//★Name				:   loot.h
//★Compiler			:	Microsoft Visual C++ 9.0Aslan
//★Version				:	1.00
//★Create Date			:	2008-08-10
//★LastModified		:	2008-10-22
//★Brief				:	掉落静态属性
//-----------------------------------------------------------------------------
#pragma once
#include "ItemDefine.h"
//------------------------------------------------------------------------
// 掉落操作类型
//------------------------------------------------------------------------
enum ELootOpType
{
	ELOT_Common		= 0,	// 普通掉落（几件）
	ELOT_OnlyOne	= 1,	// 单一掉落（一件）
};

//------------------------------------------------------------------------
// 掉落模式
//------------------------------------------------------------------------
enum ELootMode
{
	ELM_LootToGround = 0,		// 实体掉落
	ELM_LootToBag    = 1,		// 直接获得
};

//------------------------------------------------------------------------
// 掉落类型
//------------------------------------------------------------------------
enum ELootType
{
	ELT_Item = 0,		// 物品
	ELT_Set  = 1,		// 集合
};

//------------------------------------------------------------------------
// 拾取范围
//------------------------------------------------------------------------
const float X_DEF_PICKUP_DIST = 40.0f*100.0f;		// 拾取范围，40米
const float X_DEF_PICKUP_DIST_SQ = 25.0f*100.0f * 25.0f*100.0f;
const float X_DEF_AUTO_PICKUP_DIST = 20.0f*100.0f;	// 自动拾取范围，20米

//------------------------------------------------------------------------
// 掉落物品集合
//------------------------------------------------------------------------
const INT MAX_ITEM_SET_NUM = 50;	// 物品集合中存有物品数量

struct tagItemSet
{
	DWORD dwItemID; 	//物品ID
	INT   nItemNum;    //物品数量
	FLOAT fChance;		// 概率
	INT32 nEquipQltyPct[X_EQUIP_QUALITY_NUM];	// 品级生成几率
};

struct tagLootItemSet
{
	DWORD  dwSetID;							//集合id
	tagItemSet ItemSet[MAX_ITEM_SET_NUM];	//物品集合
};

//------------------------------------------------------------------------
// 掉落任务物品
//------------------------------------------------------------------------
const INT MAX_LOOT_QUEST_ITEM_NUM = 10;	// 掉落任务物品数量

struct tagQuestItem
{
	DWORD  dwQuestItemID;	//任务物品ID
	FLOAT  fChance;			//任务物品掉率
	FLOAT  fTeamChance;		//小队任务物品掉率
};

struct tagLootQuestItem
{
	DWORD  dwCreatureID;								//怪物ID
	tagQuestItem QuestItem[MAX_LOOT_QUEST_ITEM_NUM];	//任务物品	
};

//-----------------------------------------------------------------------
// 掉落的基本结构，适用于怪物、宝箱以及物品等等的掉落方式
//-----------------------------------------------------------------------
struct tagLoot
{
	DWORD		dwItemID;		// 物品ID（如果掉落类型为集合，则为集合ID）
	ELootType	eLootType;      // 掉落类型
	INT			nMin;			// 物品的最小数量
	INT			nMax;			// 物品的最大数量
	FLOAT		fChance;		// 掉落几率
	INT32		nEquipQltyPct[X_EQUIP_QUALITY_NUM];	// 品级生成几率
};

//------------------------------------------------------------------------
// 怪物掉落结构
//------------------------------------------------------------------------
const INT MAX_CREATURE_LOOT_NUM = 30;	// 怪物掉落的最多物品数量

struct tagCreatureLoot
{
	DWORD		dwLootID;						// 掉落ID
	ELootOpType		eOpType;						// 操作类型
	ELootMode	eLootMode;						// 掉落模式
	INT			nMinMoney;						// 掉落最小金钱
	INT			nMaxMoney;						// 掉落最大金钱
	INT			nMoneyNumMin;					// 掉落金币数量最小
	INT			nMoneyNumMax;					// 掉落金币数量最大
	FLOAT		fMoneyChance;					// 掉落金币几率
	tagLoot		Loot[MAX_CREATURE_LOOT_NUM];	// 掉落的物品数组
};
