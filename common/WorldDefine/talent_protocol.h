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
*	@file		talent_protocol.h
*	@author		lc
*	@date		2011/03/10	initial
*	@version	0.0.1.0
*	@brief		天资消息
*/


#ifndef TALENT_PROTOCOL
#define TALENT_PROTOCOL

#include "protocol_common_errorcode.h"
#include "RoleDefine.h"
#include "skill_define.h"

#pragma pack(push, 1)

enum
{
	E_LearnSkill_Existed				=		1,		// 该技能已经存在
	E_LearnSkill_ProtoNotFound			=		2,		// 没有找到该技能对应的静态属性
	E_LearnSkill_NPCNotEixst			=		3,		// NPC不存在
	E_LearnSkill_NPCTooFar				=		4,		// NPC距离太远
	E_LearnSkill_NPCCanNotTeach			=		5,		// NPC不能教授该技能
	E_LearnSkill_ItemNotFound			=		6,		// 物品不存在
	E_LearnSkill_ItemInvalid			=		7,		// 物品不是技能书
	E_LearnSkill_NoPreSkill				=		8,		// 没有前置技能
	E_LearnSkill_NeedMoreLevel			=		9,		// 人物等级不足
	E_LearnSkill_NeedMoreTalentPoint	=		10,		// 该技能需要的天资点投放量不足
	E_LearnSkill_ClassLimit				=		11,		// 职业限制
	E_LearnSkill_NoTalentType			=		12,		// 该技能无天资类型
	E_LearnSkill_NoTalentPoint			=		13,		// 无天资点可投
	E_LearnSkill_ExceedTalentMaxNum		=		14,		// 超过人物可投的天资数量上限
	E_LearnSkill_ProduceSkillFull		=		15,		// 目前玩家身上的生产技能已满

	E_LevelUpSkill_NotExist				=		21,		// 技能不存在
	E_LevelUpSkill_NotFixed				=		22,		// 技能不是固定升级方式
	E_LevelUpSkill_NoPreSkill			=		23,		// 没有前置技能
	E_LevelUpSkill_ExceedMaxLevel		=		24,		// 超过技能等级上限
	E_LevelUpSkill_ExceedMaxLearnLevel	=		25,		// 超过技能可学上限
	E_LevelUpSkill_NeedMoreLevel		=		26,		// 人物等级不足
	E_LevelUpSkill_NeedMoreTalentPoint	=		27,		// 该技能需要的天资点投放量不足
	E_LevelUpSkill_ClassLimit			=		28,		// 职业限制
	E_LevelUpSkill_NoTalentType			=		29,		// 该技能无天资类型
	E_LevelUpSkill_NoTalentPoint		=		30,		// 无天资点可投
	E_LevelUpSkill_ProtoNotFound		=		31,		// 没有找到该技能对应的静态属性
	E_LevelUpSkill_NPCNotEixst			=		32,		// NPC不存在
	E_LevelUpSkill_NPCTooFar			=		33,		// NPC距离太远
	E_LevelUpSkill_NPCCanNotTeach		=		34,		// NPC不能教授该技能
	E_LevelUpSkill_NPCNotMoney			=		35,		// 金钱不足	

	E_ForgetSkill_NotExist				=		51,		// 技能不存在
	E_ForgetSkill_CanNotBeForgotten		=		52,		// 该种技能不能被遗忘
	E_ForgetSkill_NPCNotValid			=		53,		// NPC不合法

	E_ClearTalent_NoTalent				=		71,		// 人物没有该天资
	E_ClearTalent_NoItem				=		72,		// 无洗点物品
};


//------------------------------------------------------------------------------
// 学习一个新技能（可能为技能书，NPC处或技能书）
//------------------------------------------------------------------------------
struct NET_SIC_learn_skill : public tag_net_message
{
	NET_SIC_learn_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id  = message_id_crc("NET_SIC_learn_skill");
		dw_size = sizeof(NET_SIC_learn_skill);
	}
	DWORD	dwSkillID;				// 技能ID（大ID）
	DWORD	dwNPCID;				// NPC的全局ID（如果不是通过NPC则为INVALID_VALUE）
	INT64	n64ItemID;				// 技能书物品的64位ID（如果不是通过技能书，则为INVALID_VALUE）
};

struct NET_SIS_learn_skill : public tag_net_message
{
	NET_SIS_learn_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_learn_skill");
		dw_size = sizeof(NET_SIS_learn_skill);
	}
	DWORD	dw_error_code;			// 错误码
	DWORD	dwSkillID;				// 技能ID（大ID）
};

struct NET_SIS_add_skill : public tag_net_message
{
	NET_SIS_add_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_skill");
		dw_size = sizeof(NET_SIS_add_skill);
	}
	tagSkillMsgInfo	Skill;			// 添加一个技能
};

struct NET_SIC_equip_learn_skill : public tag_net_message
{
	NET_SIC_equip_learn_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_learn_skill");
		dw_size = sizeof(NET_SIC_equip_learn_skill);
	}
	INT64	n64EquipID;				// 装备ID
	DWORD	dwSkillID;				// 技能ID
};

struct NET_SIS_equip_learn_skill : public tag_net_message
{
	NET_SIS_equip_learn_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_learn_skill");
		dw_size = sizeof(NET_SIS_equip_learn_skill);
	}
	INT64	n64EquipID;				// 装备ID
	DWORD	dwSkillID;				// 技能ID
	DWORD	dw_error_code;			// 错误码
};

//-------------------------------------------------------------------------------
// 升级一个技能
//-------------------------------------------------------------------------------
struct NET_SIC_level_up_skill : public tag_net_message
{
	NET_SIC_level_up_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_level_up_skill");
		dw_size = sizeof(NET_SIC_level_up_skill);
	}
	DWORD	dwSkillID;				// 技能ID（大ID）
	DWORD	dwNPCID;				// NPC的全局ID（如果不是通过NPC则为INVALID_VALUE）
	INT64	n64ItemID;				// 技能书物品的64位ID（如果不是通过技能书，则为INVALID_VALUE）
};

struct NET_SIS_level_up_skill : public tag_net_message
{
	NET_SIS_level_up_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_level_up_skill");
		dw_size = sizeof(NET_SIS_level_up_skill);
	}
	DWORD	dw_error_code;			// 错误码
	DWORD	dwSkillID;				// 技能ID（大ID）
};

struct NET_SIS_update_skill : public tag_net_message
{
	NET_SIS_update_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_skill");
		dw_size = sizeof(NET_SIS_update_skill);
	}
	tagSkillMsgInfo	Skill;			// 技能
};

struct NET_SIS_update_skill_cool_down : public tag_net_message
{
	NET_SIS_update_skill_cool_down()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_skill_cool_down");
		dw_size = sizeof(NET_SIS_update_skill_cool_down);
	}
	DWORD			dwSkillID;		// 技能ID
	INT				nCoolDown;		// 新的冷却时间
};

struct NET_SIC_equip_level_up_skill : public tag_net_message
{
	NET_SIC_equip_level_up_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_level_up_skill");
		dw_size = sizeof(NET_SIC_equip_level_up_skill);
	}
	INT64	n64EquipID;				// 装备ID
	DWORD	dwSkillID;				// 技能ID
};

struct NET_SIS_equip_level_up_skill : public tag_net_message
{
	NET_SIS_equip_level_up_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_level_up_skill");
		dw_size = sizeof(NET_SIS_equip_level_up_skill);
	}
	INT64	n64EquipID;				// 装备ID
	DWORD	dwSkillID;				// 技能ID
	DWORD	dw_error_code;			// 错误码
};


//-------------------------------------------------------------------------------
// 开始公共CD
//-------------------------------------------------------------------------------
struct NET_SIS_start_public_cd : public tag_net_message
{
	NET_SIS_start_public_cd()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_start_public_cd");
		dw_size = sizeof(NET_SIS_start_public_cd);
	}
	DWORD			dwSkillID;		// 技能ID
	DWORD			dwCoolTime;		// 冷却时间
};


//-------------------------------------------------------------------------------
// 遗忘一个技能
//-------------------------------------------------------------------------------
struct NET_SIC_forget_skill : public tag_net_message
{
	NET_SIC_forget_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_forget_skill");
		dw_size = sizeof(NET_SIC_forget_skill);
	}
	DWORD	dwSkillID;		// 技能ID（大ID）
	DWORD	dwNPCID;		// NPCID
};

struct NET_SIS_forget_skill : public tag_net_message
{
	NET_SIS_forget_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_forget_skill");
		dw_size = sizeof(NET_SIS_forget_skill);
	}
	DWORD	dw_error_code;	// 错误码
	DWORD	dwSkillID;		// 技能ID（大ID）
};


//-------------------------------------------------------------------------------
// 洗点
//-------------------------------------------------------------------------------
struct NET_SIC_clear_talent : public tag_net_message
{
	NET_SIC_clear_talent()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_clear_talent");
		dw_size = sizeof(NET_SIC_clear_talent);
	}
	ETalentType	eType;		// 天资类型
	INT64		n64ItemID;	// 使用的道具
};

struct NET_SIS_clear_talent : public tag_net_message
{	
	NET_SIS_clear_talent()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_clear_talent");
		dw_size = sizeof(NET_SIS_clear_talent);
	}
	DWORD		dw_error_code;// 错误码
	ETalentType	eType;		// 天资类型
};

struct NET_SIS_remove_skill : public tag_net_message
{
	NET_SIS_remove_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_remove_skill");
		dw_size = sizeof(NET_SIS_remove_skill);
	}
	DWORD	dwSkillID;
};


//-------------------------------------------------------------------------------
// 增加一个天资
//------------------------------------------------------------------------------
struct NET_SIS_add_talent : public tag_net_message
{
	NET_SIS_add_talent()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_talent");
		dw_size = sizeof(NET_SIS_add_talent);
	}
	ETalentType	eType;
	INT			nPoint;
};

//------------------------------------------------------------------------------
// 删除一个天资
//------------------------------------------------------------------------------
struct NET_SIS_remove_talent : public tag_net_message
{
	NET_SIS_remove_talent()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_remove_talent");
		dw_size = sizeof(NET_SIS_remove_talent);
	}
	ETalentType	eType;
};


//------------------------------------------------------------------------------
// 更新一个天资
//-----------------------------------------------------------------------------
struct NET_SIS_update_talent : public tag_net_message
{
	NET_SIS_update_talent()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_talent");
		dw_size = sizeof(NET_SIS_update_talent);
	}
	ETalentType	eType;
	INT			nPoint;
};


#pragma pack(pop)
#endif