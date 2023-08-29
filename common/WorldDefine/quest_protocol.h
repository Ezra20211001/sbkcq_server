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
*	@file		quest_protocol.h
*	@author		lc
*	@date		2011/03/10	initial
*	@version	0.0.1.0
*	@brief		任务消息
*/


#ifndef QUEST_PROTOCOL
#define QUEST_PROTOCOL

#include "protocol_common_errorcode.h"
#include "QuestDef.h"
#pragma pack(push, 1)

//任务接取失败原因
enum
{
	E_QUEST_NOT_EXIST								= 1,		//任务不存在
	E_QUEST_NPC_NOT_EXIST							= 2,		//任务NPC不存在
	E_QUEST_NPC_TOO_FAR								= 3,		//任务NPC与玩家距离太远
	E_QUEST_FAILED_ADD 								= 4,        //增加任务失败
	E_QUEST_FATIGUEGUARD							= 5,		//防沉迷保护
	
	E_CanTakeQuest_FAILED_LOW_LEVEL					= 11,		//没有足够的等级
	E_CanTakeQuest_FAILED_LOW_REP					= 12,		//没有足够的声望
	E_CanTakeQuest_ALREADY_DONE						= 13,		//已经完成了
	E_CanTakeQuest_ALREADY_TAKE						= 14,		//已经接取了
	E_CanTakeQuest_FAILED_MISSING_ITEMS				= 15,		//没有任务所需要的物品
	E_CanTakeQuest_FAILED_MISSING_SKILLS			= 16,		//没有任务所需要的技能
	E_CanTakeQuest_FAILED_MISSING_Att				= 17,		//没有任务所需要的人物属性
	E_CanTakeQuest_FAILED_WRONG_SEX					= 18,       //任务所需要的性别
	E_CanTakeQuest_FAILED_WRONG_CLASS				= 19,       //任务所需要的职业
	E_CanTakeQuest_FAILED_NOT_ENOUGH_MONEY			= 20,       //没有任务所需要的金钱
	E_CanTakeQuest_FAILED_QUEST_NUM_FULL			= 21,		//任务满了，不能再接
	E_CanTakeQuest_FAILED_WRONG_MAP 				= 22, 		//地图不对
	E_CanTakeQuest_FAILED_PREV 						= 23,      	//任务前序不对
	E_CanTakeQuest_FAILED_NEXT 						= 24,      	//任务后续不对
	E_CanTakeQuest_FAILED_WRONG_TIME 				= 25,       //任务时间不对
	E_CanTakeQuest_FAILED_WRONG_TIMES 				= 26,       //任务接取次数不对
	E_CanTakeQuest_FAILED_MISS_ITEM_OF_QUEST 		= 27,       //没有任务物品
	E_CanTakeQuest_FAILED_WRONG_TRIGGER 			= 28,       //任务触发器不对
	E_CanTakeQuest_FAILED_SCRIPT					= 29,		//脚本判断失败，客户端不提供错误提示，服务器直接发送

	E_CanCompleteQuest_FAILED_MISSING_Creature		= 30,		//没有任务完成所需要的生物
	E_CanCompleteQuest_FAILED_MISSING_NPC			= 31,		//没有任务完成所需要的NPC
	E_CanCompleteQuest_FAILED_MISSING_ITEMS			= 32,		//没有任务完成所需要的物品
	E_CanCompleteQuest_FAILEDENOUGH_MONEY			= 33,		//没有任务完成所需要的金钱
	E_CanCompleteQuest_BAG_FULL						= 34,		//背包没有地方，放置奖励物品
	E_CanCompleteQuest_FALIED_SCRIPT				= 35,		//脚本判断失败，客户端不提供错误提示，服务器直接发送

	E_CanTakeQuest_Tomorrow							= 36,		//每天只能完成一次
	E_CanTakeQuest_Week								= 37,		//只能在星期×完成

	E_CanUpdateQuest_Fail							= 40,		//不能更新

	E_TakeLoopQuest_Failed_Num_Full 				= 41,		//循环随机任务满了
	
	EGDE_Put_Already								= 42,		// 已经发布悬赏
	EGDE_Put_Cant									= 43,		// 不能悬赏该任务
	EGDE_Put_OutOfNumber							= 44,		// 已经达到最大发数
	EGDE_Put_OutOfMoney								= 45,		// 钱不足以悬赏该任务
	EGDE_Put_OutOfYuanBao							= 46,		// 元宝不足
	EGDE_Put_CheckItem								= 47,		// 请检查奖励物品
	EGDE_Get_NotExist								= 48,		// 悬赏任务不存在
	EGDE_Get_BeTaked								= 49,		// 已经被接取
	EGDE_Get_Already								= 50,		// 已经接取同类悬赏任务
	EGDE_Get_OutOfNumber							= 51,		// 已经达到最大接取数
	EGDE_Get_OutOfMoney								= 52,		// 钱不足以接取该悬赏
	EGDE_NotBelongYou								= 53,		// 悬赏任务不属于你
	EGDE_CantGiveUp									= 54,		// 不能放弃悬赏
	EGDE_OnlyReciverComplete						= 55,		// 只有接取者才能完成悬赏任务
	EGDE_CantCancelPut								= 56,		// 不能取消发布悬赏
	EGDE_Get_OutOfVigour							= 57,		// 元气值不足
	EGDE_Get_OutOfLevel25						= 58,		// 等级低于25,不能接取悬赏

	E_FAILED_QUEST_FORBID_DELETE					= 60,		//不能删除
	E_Failed_Track_Number_Max						= 61,		// 不能追踪
	E_CanTakeQuest_FAILED_BAGFULL					= 62,		// 背包已满，无法接取该任务
	E_CanTakeQuest_FAILED_GUILD						= 63,		// 需要加入帮会 
	E_CanTakeQuest_FAILED_MASTER					= 64,		// 需要有师傅
	E_CanTakeQuest_FAILED_PRENTICE					= 65,		// 需要有徒弟
	E_CanTakeQuest_FAILED_OnlyBangZhu				= 66,		// 帮主才能接取

	E_CanCompleteQuest_NotCompleteAll				= 67,  		//未达成所有条件
	E_CanTakeQuest_FAILED_GUILD_LEVEL				= 68,		// 帮会没有足够等级

	EBuyFreshNumFull	=	69,
	EBuyFreshNumOutOfMoney	=	70,
	EBuyFreshNumOutOfNum	=	71,

	E_CanTakeQuest_FAILED_CantHasItem = 72,				// 拥有某个道具不能接取该任务
	E_CanTakeQuest_FAILED_VIP_LEVEL = 73,				// VIP等级不足

	E_Quset_Error_Max,
};
//-----------------------------------------------------------------------------
//	是否可以接取此任务
//-----------------------------------------------------------------------------
struct NET_SIC_npc_accept_quest : public tag_net_message
{
	NET_SIC_npc_accept_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id =  message_id_crc("NET_SIC_npc_accept_quest");
		dw_size = sizeof(NET_SIC_npc_accept_quest);
	}
	DWORD		dwNPCID;		// 接取任务NPC唯一ID 
	UINT16		u16QuestID;		// 任务ID
};


//-----------------------------------------------------------------------------
//	触发器接取任务
//-----------------------------------------------------------------------------
struct NET_SIC_trigger_accept_quest : public tag_net_message
{
	NET_SIC_trigger_accept_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_trigger_accept_quest");
		dw_size = sizeof(NET_SIC_trigger_accept_quest);
	}
	UINT16		u16QuestID;		// 任务ID
	DWORD		dwTriggerID;	// 触发器ID
};

struct NET_SIS_accept_quest : public tag_net_message
{
	NET_SIS_accept_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_accept_quest");
		dw_size = sizeof(NET_SIS_accept_quest);
	}
	UINT16		u16QuestID;		// 任务ID
	DWORD		dw_error_code;	// 错误码
};

struct NET_SIS_add_quest : public tag_net_message
{
	NET_SIS_add_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_quest");
		dw_size = sizeof(NET_SIS_add_quest);
	}
	UINT16		u16QuestID;							// 任务ID
	DWORD		dwFlag;								//任务是否被追踪
	//gx modify 2013.5.13
	/*INT16		n16ItemCount[QUEST_ITEMS_COUNT];	// 物品任务追踪数量
	tagQuestDynamicTarget	DynamicTarget;			// 动态目标任务才会发给客户端
	tagQuestDynamicReward	DynamicReward;			// 任务动态奖励
	tagScriptQuestVar		ScriptSetData;			// 脚本设置数据*/
	//end
};

//-----------------------------------------------------------------------------
//	是否可以完成此任务
//-----------------------------------------------------------------------------
struct NET_SIC_complete_quest : public tag_net_message
{
	NET_SIC_complete_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_complete_quest");
		dw_size = sizeof(NET_SIC_complete_quest);
	}
	DWORD		dwNPCID;					// 完成任务NPC唯一ID 
	UINT16		u16QuestID;					// 任务ID
	INT32		nRewChoicesItemIndex;		// 可选奖励物品序号
	DWORD		dw_safe_code;
};

struct NET_SIS_complete_quest : public tag_net_message
{
	NET_SIS_complete_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_complete_quest");
		dw_size = sizeof(NET_SIS_complete_quest);
	}
	UINT16		u16QuestID;					// 任务ID
	DWORD		dw_error_code;				// 错误码
};


//-----------------------------------------------------------------------------
//	是否可以删除任务
//-----------------------------------------------------------------------------
struct NET_SIC_delete_quest : public tag_net_message
{
	NET_SIC_delete_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_quest");
		dw_size = sizeof(NET_SIC_delete_quest);
	}
	UINT16		u16QuestID;					// 删除任务ID
};

struct NET_SIS_delete_quest : public tag_net_message
{
	NET_SIS_delete_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_quest");
		dw_size = sizeof(NET_SIS_delete_quest);
	}
	UINT16		u16QuestID;					// 任务ID
	DWORD		dw_error_code;				// 错误码
};


//-----------------------------------------------------------------------------
//	更新任务NPC对话数据
//-----------------------------------------------------------------------------
struct NET_SIC_update_quest_npc_talk : public tag_net_message
{
	NET_SIC_update_quest_npc_talk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_update_quest_npc_talk");
		dw_size = sizeof(NET_SIC_update_quest_npc_talk);
	}
	DWORD		dwNPCID;						// 更新任务NPC唯一ID 
	UINT16		u16QuestID;						// 更新任务ID
};


//-----------------------------------------------------------------------------
//	更新杀怪任务数据
//-----------------------------------------------------------------------------
struct NET_SIS_quest_update_kill_creature : public tag_net_message
{
	NET_SIS_quest_update_kill_creature()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_update_kill_creature");
		dw_size = sizeof(NET_SIS_quest_update_kill_creature);
	}
	UINT16		u16QuestID;						// 任务ID
	INT			nCreatureIndex;					// 怪物序号
	INT16		n16NewKillNum;					// 更新过后的杀怪计数
};


//-----------------------------------------------------------------------------
//	更新物品任务数据
//-----------------------------------------------------------------------------
struct NET_SIS_quest_update_item : public tag_net_message
{
	NET_SIS_quest_update_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_update_item");
		dw_size = sizeof(NET_SIS_quest_update_item);
	}
	UINT16		u16QuestID;						// 任务ID
	INT			nItemIndex;						// 物品序号
	INT16		n16NewItemNum;					// 更新过后的物品计数
};

//-----------------------------------------------------------------------------
// 更新NPC对话任务数据
//-----------------------------------------------------------------------------
struct NET_SIS_quest_update_npc_talk : public tag_net_message
{
	NET_SIS_quest_update_npc_talk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_update_npc_talk");
		dw_size = sizeof(NET_SIS_quest_update_npc_talk);
	}
	UINT16		u16QuestID;						// 任务ID
	DWORD		dw_error_code;					// 错误码
	INT			nIndex;							// 某个索引
};

//-----------------------------------------------------------------------------
// 更新Trigger任务数据
//-----------------------------------------------------------------------------
struct NET_SIS_quest_update_trigger : public tag_net_message
{
	NET_SIS_quest_update_trigger()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_update_trigger");
		dw_size = sizeof(NET_SIS_quest_update_trigger);
	}
	UINT16		u16QuestID;						// 任务ID
	INT			nIndex;							// 某个索引
};

//-----------------------------------------------------------------------------
// 更新调查地物任务数据
//-----------------------------------------------------------------------------
struct NET_SIS_quest_update_inveset : public tag_net_message
{
	NET_SIS_quest_update_inveset()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_update_inveset");
		dw_size = sizeof(NET_SIS_quest_update_inveset);
	}
	UINT16		u16QuestID;
	INT			nIndex;
};


//-----------------------------------------------------------------------------
// 任务错误屏显信息
//-----------------------------------------------------------------------------
struct NET_SIS_quest_faild_message : public tag_net_message
{
	NET_SIS_quest_faild_message()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_faild_message");
		dw_message_id = sizeof(NET_SIS_quest_faild_message);
	}
	UINT16		u16QuestID;						// 任务ID
	TCHAR		szMsg[1];						// 错误屏显信息
};

struct NET_SIS_quest_faild : public tag_net_message
{
	NET_SIS_quest_faild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_faild");
		dw_size = sizeof(NET_SIS_quest_faild);
	}
	UINT16 u16QuestID;
};

struct NET_SIS_quest_var_value : public tag_net_message
{
	NET_SIS_quest_var_value()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_var_value");
		dw_size = sizeof(NET_SIS_quest_var_value);
	}
	UINT16 u16QuestID;
	UINT16 VarID;
	INT16  VarValue;
};

// 任务追踪设置
struct NET_SIC_set_quest_track : public tag_net_message
{
	NET_SIC_set_quest_track()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_quest_track");
		dw_size = sizeof(NET_SIC_set_quest_track);
	}
	UINT16 u16QuestID;
	BYTE  byTrack;
};
struct NET_SIS_set_quest_track : public tag_net_message
{
	NET_SIS_set_quest_track()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_quest_track");
		dw_size = sizeof(NET_SIS_set_quest_track);
	}
	UINT16 u16QuestID;
	DWORD dwCode; // E_Failed_Track_Number_Max or E_SUCCESS
};

// 任务调查地物没有获得物品
struct NET_SIS_quest_inves_faild : public tag_net_message
{
	NET_SIS_quest_inves_faild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_inves_faild");
		dw_size = sizeof(NET_SIS_quest_inves_faild);
	}
};
// 换随机任务列表
struct NET_SIC_CircleQuestList : public tag_net_message
{
	NET_SIC_CircleQuestList()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_CircleQuestList");
		dw_size = sizeof(NET_SIC_CircleQuestList);
	}
	DWORD dwNpcID;
};

struct NET_SIS_CircleQuestList : public tag_net_message
{
	NET_SIS_CircleQuestList()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_CircleQuestList");
		dw_size = sizeof(NET_SIS_CircleQuestList);
	}
	BYTE byNumber;
	BYTE byRefreshLeft;
	BYTE byCircleNumberLeft;
	BYTE byCircleNumberBuyLeft;
	UINT16 u16QuestID[CIRCLEQUESTMAXNUMBER];
};

//! 刷新环随机
struct NET_SIC_RefreshCircleQuest : public tag_net_message
{
	NET_SIC_RefreshCircleQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_RefreshCircleQuest");
		dw_size = sizeof(*this);
	}
	DWORD dwNpcID;
	UINT16 u16QuestID;
};

//! 购买刷新次数
struct NET_SIC_BuyRefreshCircleQuest : public tag_net_message
{
	NET_SIC_BuyRefreshCircleQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_BuyRefreshCircleQuest");
		dw_size = sizeof(*this);
	}
	DWORD dwNpcID;
};

struct NET_SIS_BuyRefreshCircleQuest : public tag_net_message
{
	NET_SIS_BuyRefreshCircleQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_BuyRefreshCircleQuest");
		dw_size = sizeof(*this);
	}
	DWORD dwError; // 0 ; 成功 1:达到最次数
};

//! 购买任务次数
struct NET_SIC_BuyCircleQuestPerdayNumber : public tag_net_message
{
	NET_SIC_BuyCircleQuestPerdayNumber()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_BuyCircleQuestPerdayNumber");
		dw_size = sizeof(*this);
	}
	DWORD dwNpcID;
};


#pragma pack(pop)
#endif
