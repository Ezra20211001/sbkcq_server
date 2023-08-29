#pragma once

#include "ItemDefine.h"
#include "pet_define.h"

#pragma pack(push,1)

//-----------------------------------------------------------------------------
// 技能id转换的宏
//-----------------------------------------------------------------------------
#define MTransPetSkillTypeID(skillId, lv) (DWORD)(skillId * 100 + lv)
#define MTransPetSkillID(skillTypeId) (DWORD)(skillTypeId / 100)
#define MTransPetSkillLevel(skillTypeId) (INT)(skillTypeId % 100)

//-----------------------------------------------------------------------------
// 宠物最大技能数
//-----------------------------------------------------------------------------
const INT MAX_PET_SKILL_NUM		= 12;

//-----------------------------------------------------------------------------
// 技能类型
//-----------------------------------------------------------------------------
enum EPetskillType
{
	EPT_Null			=-1,	
	EPT_Gather			= 0,	//派遣采集
	EPT_PickUp			= 1,	//自动拾取
	EPT_MedicineFeed	= 2,	//自动喂药
	EPT_Forage			= 3,	//自动觅食
	EPT_Experience		= 4,	//灵兽训练 
	EPT_Deliver			= 5,	//灵兽邮差
	EPT_Sale			= 6,	//灵兽小贩
	EPT_StoreHouse		= 7,	//灵兽仓管
	EPT_Strengthen		= 8,	//强身    
	EPT_Buff			= 9,	//状态技能
	EPT_WuXing			=10,    //天赋
	EPT_MountAdd		=11,    //骑乘负载
	EPT_Specialty		=12		//特长(合体)
};

//-----------------------------------------------------------------------------
// 技能类型2
//-----------------------------------------------------------------------------
enum EPetskillType2
{
	EPT2_Null		=   0,
	EPT2_Active		=	1,		// 主动
	EPT2_Passive	=	2,		// 被动

	
	//EPT2_Work       =   1,
	//EPT2_Instant    =   2,
	//EPT2_Continue   =   3
};

//-----------------------------------------------------------------------------
// 技能类型3
//-----------------------------------------------------------------------------
enum EPetskillType3
{
    EPT3_All        =   0,  //!< 所有
    EPT3_Horse      =   1,  //!< 马
    EPT3_Mule       =   2   //!< 骡
};

//-----------------------------------------------------------------------------
// 技能施放类型
//-----------------------------------------------------------------------------
enum EPetskillCastType
{
	EPCT_Passive    =   0,	// 被动
    EPCT_Active		=	1,	// 主动
	EPCT_Enhance	=	2,	// 自身强化
};

//-----------------------------------------------------------------------------
// 技能施放状态
//-----------------------------------------------------------------------------
enum EPetskillCastCondition
{
    EPCC_NULL       =   0,  // 无
    EPCC_Called     =   1,  // 召唤
    EPCC_Rest       =   2   // 休息
};

//-----------------------------------------------------------------------------
// 宠物技能传送客户端的消息结构
//-----------------------------------------------------------------------------
struct tagPetSkillMsgInfo
{
    DWORD	dw_data_id;							// TypeID(带等级)
    INT     nCurrCoolDown;                      // 当前冷却时间
    INT     nMaxCoolDown;                       // 最大冷却时间
};

//-----------------------------------------------------------------------------
// 采集表物品种类数目
//-----------------------------------------------------------------------------
const INT NUM_ITEMS_PET_GATHER			= 5;
const INT NUM_RARE_ITEMS_PET_GATHER		= 5;

//-----------------------------------------------------------------------------
// 宠物采集表
//-----------------------------------------------------------------------------
struct tagPetGatherProto
{
	DWORD	dw_data_id;
	DWORD	dwItemTypeID[NUM_ITEMS_PET_GATHER];
	INT		nMin[NUM_RARE_ITEMS_PET_GATHER];
	INT		nMax[NUM_RARE_ITEMS_PET_GATHER];

	DWORD	dwRareItemID[NUM_RARE_ITEMS_PET_GATHER];
	INT		nProb[NUM_RARE_ITEMS_PET_GATHER];
};

//-----------------------------------------------------------------------------
// 技能消息可变结构
//-----------------------------------------------------------------------------

//! 自动拾取
struct tagPetPickUpData
{
    INT64       n64GroundSerial;      //!< tbc:试图拾取的物品ID 不应该用物品id，应该用地物唯一序列号
	BOOL		bFengJie;			  // 是否分解
};

//! 自动喂药
enum E_Pet_Supply_Type
{
    EPST_Health,        //!< 体力
    EPST_Power,         //!< 真气
    EPST_Toughness,     //!< 持久力
    EPST_Energy,        //!< 活力
};
struct tagPetSupplyData
{
    E_Pet_Supply_Type   eSupplyType;    //!< 自动喂药类型
    INT64               n64ItemID;      //!< 药品ID
};

//! 自动觅食
struct tagPetForageData
{
    INT64       n64ItemID;          //!< 药品ID
};

struct tagPetWuXingItem
{
	DWORD		dwItemTypeID;
	INT			n_num;
};

#pragma pack(pop)