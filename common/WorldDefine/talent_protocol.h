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
*	@brief		������Ϣ
*/


#ifndef TALENT_PROTOCOL
#define TALENT_PROTOCOL

#include "protocol_common_errorcode.h"
#include "RoleDefine.h"
#include "skill_define.h"

#pragma pack(push, 1)

enum
{
	E_LearnSkill_Existed				=		1,		// �ü����Ѿ�����
	E_LearnSkill_ProtoNotFound			=		2,		// û���ҵ��ü��ܶ�Ӧ�ľ�̬����
	E_LearnSkill_NPCNotEixst			=		3,		// NPC������
	E_LearnSkill_NPCTooFar				=		4,		// NPC����̫Զ
	E_LearnSkill_NPCCanNotTeach			=		5,		// NPC���ܽ��ڸü���
	E_LearnSkill_ItemNotFound			=		6,		// ��Ʒ������
	E_LearnSkill_ItemInvalid			=		7,		// ��Ʒ���Ǽ�����
	E_LearnSkill_NoPreSkill				=		8,		// û��ǰ�ü���
	E_LearnSkill_NeedMoreLevel			=		9,		// ����ȼ�����
	E_LearnSkill_NeedMoreTalentPoint	=		10,		// �ü�����Ҫ�����ʵ�Ͷ��������
	E_LearnSkill_ClassLimit				=		11,		// ְҵ����
	E_LearnSkill_NoTalentType			=		12,		// �ü�������������
	E_LearnSkill_NoTalentPoint			=		13,		// �����ʵ��Ͷ
	E_LearnSkill_ExceedTalentMaxNum		=		14,		// ���������Ͷ��������������
	E_LearnSkill_ProduceSkillFull		=		15,		// Ŀǰ������ϵ�������������

	E_LevelUpSkill_NotExist				=		21,		// ���ܲ�����
	E_LevelUpSkill_NotFixed				=		22,		// ���ܲ��ǹ̶�������ʽ
	E_LevelUpSkill_NoPreSkill			=		23,		// û��ǰ�ü���
	E_LevelUpSkill_ExceedMaxLevel		=		24,		// �������ܵȼ�����
	E_LevelUpSkill_ExceedMaxLearnLevel	=		25,		// �������ܿ�ѧ����
	E_LevelUpSkill_NeedMoreLevel		=		26,		// ����ȼ�����
	E_LevelUpSkill_NeedMoreTalentPoint	=		27,		// �ü�����Ҫ�����ʵ�Ͷ��������
	E_LevelUpSkill_ClassLimit			=		28,		// ְҵ����
	E_LevelUpSkill_NoTalentType			=		29,		// �ü�������������
	E_LevelUpSkill_NoTalentPoint		=		30,		// �����ʵ��Ͷ
	E_LevelUpSkill_ProtoNotFound		=		31,		// û���ҵ��ü��ܶ�Ӧ�ľ�̬����
	E_LevelUpSkill_NPCNotEixst			=		32,		// NPC������
	E_LevelUpSkill_NPCTooFar			=		33,		// NPC����̫Զ
	E_LevelUpSkill_NPCCanNotTeach		=		34,		// NPC���ܽ��ڸü���
	E_LevelUpSkill_NPCNotMoney			=		35,		// ��Ǯ����	

	E_ForgetSkill_NotExist				=		51,		// ���ܲ�����
	E_ForgetSkill_CanNotBeForgotten		=		52,		// ���ּ��ܲ��ܱ�����
	E_ForgetSkill_NPCNotValid			=		53,		// NPC���Ϸ�

	E_ClearTalent_NoTalent				=		71,		// ����û�и�����
	E_ClearTalent_NoItem				=		72,		// ��ϴ����Ʒ
};


//------------------------------------------------------------------------------
// ѧϰһ���¼��ܣ�����Ϊ�����飬NPC�������飩
//------------------------------------------------------------------------------
struct NET_SIC_learn_skill : public tag_net_message
{
	NET_SIC_learn_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id  = message_id_crc("NET_SIC_learn_skill");
		dw_size = sizeof(NET_SIC_learn_skill);
	}
	DWORD	dwSkillID;				// ����ID����ID��
	DWORD	dwNPCID;				// NPC��ȫ��ID���������ͨ��NPC��ΪINVALID_VALUE��
	INT64	n64ItemID;				// ��������Ʒ��64λID���������ͨ�������飬��ΪINVALID_VALUE��
};

struct NET_SIS_learn_skill : public tag_net_message
{
	NET_SIS_learn_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_learn_skill");
		dw_size = sizeof(NET_SIS_learn_skill);
	}
	DWORD	dw_error_code;			// ������
	DWORD	dwSkillID;				// ����ID����ID��
};

struct NET_SIS_add_skill : public tag_net_message
{
	NET_SIS_add_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_skill");
		dw_size = sizeof(NET_SIS_add_skill);
	}
	tagSkillMsgInfo	Skill;			// ���һ������
};

struct NET_SIC_equip_learn_skill : public tag_net_message
{
	NET_SIC_equip_learn_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_learn_skill");
		dw_size = sizeof(NET_SIC_equip_learn_skill);
	}
	INT64	n64EquipID;				// װ��ID
	DWORD	dwSkillID;				// ����ID
};

struct NET_SIS_equip_learn_skill : public tag_net_message
{
	NET_SIS_equip_learn_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_learn_skill");
		dw_size = sizeof(NET_SIS_equip_learn_skill);
	}
	INT64	n64EquipID;				// װ��ID
	DWORD	dwSkillID;				// ����ID
	DWORD	dw_error_code;			// ������
};

//-------------------------------------------------------------------------------
// ����һ������
//-------------------------------------------------------------------------------
struct NET_SIC_level_up_skill : public tag_net_message
{
	NET_SIC_level_up_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_level_up_skill");
		dw_size = sizeof(NET_SIC_level_up_skill);
	}
	DWORD	dwSkillID;				// ����ID����ID��
	DWORD	dwNPCID;				// NPC��ȫ��ID���������ͨ��NPC��ΪINVALID_VALUE��
	INT64	n64ItemID;				// ��������Ʒ��64λID���������ͨ�������飬��ΪINVALID_VALUE��
};

struct NET_SIS_level_up_skill : public tag_net_message
{
	NET_SIS_level_up_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_level_up_skill");
		dw_size = sizeof(NET_SIS_level_up_skill);
	}
	DWORD	dw_error_code;			// ������
	DWORD	dwSkillID;				// ����ID����ID��
};

struct NET_SIS_update_skill : public tag_net_message
{
	NET_SIS_update_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_skill");
		dw_size = sizeof(NET_SIS_update_skill);
	}
	tagSkillMsgInfo	Skill;			// ����
};

struct NET_SIS_update_skill_cool_down : public tag_net_message
{
	NET_SIS_update_skill_cool_down()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_skill_cool_down");
		dw_size = sizeof(NET_SIS_update_skill_cool_down);
	}
	DWORD			dwSkillID;		// ����ID
	INT				nCoolDown;		// �µ���ȴʱ��
};

struct NET_SIC_equip_level_up_skill : public tag_net_message
{
	NET_SIC_equip_level_up_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_level_up_skill");
		dw_size = sizeof(NET_SIC_equip_level_up_skill);
	}
	INT64	n64EquipID;				// װ��ID
	DWORD	dwSkillID;				// ����ID
};

struct NET_SIS_equip_level_up_skill : public tag_net_message
{
	NET_SIS_equip_level_up_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_level_up_skill");
		dw_size = sizeof(NET_SIS_equip_level_up_skill);
	}
	INT64	n64EquipID;				// װ��ID
	DWORD	dwSkillID;				// ����ID
	DWORD	dw_error_code;			// ������
};


//-------------------------------------------------------------------------------
// ��ʼ����CD
//-------------------------------------------------------------------------------
struct NET_SIS_start_public_cd : public tag_net_message
{
	NET_SIS_start_public_cd()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_start_public_cd");
		dw_size = sizeof(NET_SIS_start_public_cd);
	}
	DWORD			dwSkillID;		// ����ID
	DWORD			dwCoolTime;		// ��ȴʱ��
};


//-------------------------------------------------------------------------------
// ����һ������
//-------------------------------------------------------------------------------
struct NET_SIC_forget_skill : public tag_net_message
{
	NET_SIC_forget_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_forget_skill");
		dw_size = sizeof(NET_SIC_forget_skill);
	}
	DWORD	dwSkillID;		// ����ID����ID��
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
	DWORD	dw_error_code;	// ������
	DWORD	dwSkillID;		// ����ID����ID��
};


//-------------------------------------------------------------------------------
// ϴ��
//-------------------------------------------------------------------------------
struct NET_SIC_clear_talent : public tag_net_message
{
	NET_SIC_clear_talent()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_clear_talent");
		dw_size = sizeof(NET_SIC_clear_talent);
	}
	ETalentType	eType;		// ��������
	INT64		n64ItemID;	// ʹ�õĵ���
};

struct NET_SIS_clear_talent : public tag_net_message
{	
	NET_SIS_clear_talent()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_clear_talent");
		dw_size = sizeof(NET_SIS_clear_talent);
	}
	DWORD		dw_error_code;// ������
	ETalentType	eType;		// ��������
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
// ����һ������
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
// ɾ��һ������
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
// ����һ������
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