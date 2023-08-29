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
*	@file		pet_skill_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		宠物技能消息
*/

#ifndef PET_SKILL_PROTOCOL
#define PET_SKILL_PROTOCOL

#pragma pack(push,1)

#include "pet_define.h"
#include "pet_skill_define.h"
#include "protocol_common_errorcode.h"

//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum EPetSkillMsgErrCode
{
    E_PetSkill_Success              =   E_Success,	// 成功
	E_PetSkill_InUse				,				// 正在使用
	E_PetSkill_CoolDown				,				// 冷却中
    E_PetSkill_Unknown				,				// 未知
};

//-----------------------------------------------------------------------------
// 添加，更新，删除宠物技能(只对本地玩家，缓冲于本地)
//-----------------------------------------------------------------------------
struct NET_SIS_add_pet_skill : public tag_net_message
{
	NET_SIS_add_pet_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_pet_skill");
		dw_size = sizeof(NET_SIS_add_pet_skill);
	}
	DWORD               dwPetID;        //!< 宠物ID
	DWORD				dwSkillID;      //!< 技能数据
};

struct NET_SIS_remove_pet_skill : public tag_net_message
{
	NET_SIS_remove_pet_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_remove_pet_skill");
		dw_size = sizeof(NET_SIS_remove_pet_skill);
	}
	DWORD               dwPetID;        //!< 宠物ID
	DWORD               dwSkillID;      //!< 宠物技能ID
};


//-----------------------------------------------------------------------------
// 使用技能
//-----------------------------------------------------------------------------
struct NET_SIC_use_pet_skill : public tag_net_message
{
	NET_SIC_use_pet_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_use_pet_skill");
		dw_size = sizeof(NET_SIC_use_pet_skill);
	}
	DWORD               dwPetID;        //!< 宠物ID
	DWORD               dwSkillID;      //!< 宠物技能ID
	BYTE				byData[1];		//!< 其它数据
};

struct NET_SIS_use_pet_skill : public tag_net_message
{
	NET_SIS_use_pet_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_use_pet_skill");
		dw_size = sizeof(NET_SIS_use_pet_skill);
	}
	DWORD               dwPetID;        //!< 宠物ID
	DWORD               dwSkillID;      //!< 宠物技能ID
	DWORD				dwErrCode;		//!< 返回值
	BYTE				byData[1];		//!< 其它数据
};


//-----------------------------------------------------------------------------
// 学习技能
//-----------------------------------------------------------------------------
struct NET_SIC_pet_learn_skill : public tag_net_message
{
	NET_SIC_pet_learn_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_learn_skill");
		dw_size = sizeof(NET_SIC_pet_learn_skill);
	}
	DWORD               dwPetID;        //!< 宠物ID
	INT64				n64ItemID;      //!< 技能书id
};

struct NET_SIS_pet_learn_skill : public tag_net_message
{
	NET_SIS_pet_learn_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_learn_skill");
		dw_size = sizeof(NET_SIS_pet_learn_skill);
	}
	DWORD               dwPetID;        //!< 宠物ID
	INT64				n64ItemID;      //!< 技能书id
	DWORD				dwErrCode;		
};

// 升级技能
struct NET_SIC_pet_levelup_skill : public tag_net_message
{
	NET_SIC_pet_levelup_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_levelup_skill");
		dw_size = sizeof(NET_SIC_pet_levelup_skill);
	}
	DWORD               dwPetID;        //!< 宠物ID
	DWORD				dwSkillID;      //!< 技能id
};

struct NET_SIS_pet_levelup_skill : public tag_net_message
{
	NET_SIS_pet_levelup_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_levelup_skill");
		dw_size = sizeof(NET_SIS_pet_levelup_skill);
	}
	DWORD               dwPetID;        //!< 宠物ID
	DWORD				dwSkillID;      //!< 技能id
	DWORD				dwErrCode;		
};

//-----------------------------------------------------------------------------
// 遗忘技能
//-----------------------------------------------------------------------------
struct NET_SIC_pet_forget_skill : public tag_net_message
{
	NET_SIC_pet_forget_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_forget_skill");
		dw_size = sizeof(NET_SIC_pet_forget_skill);
	}
	DWORD               dwPetID;        //!< 宠物ID
	DWORD				dwSkillID;
};

struct NET_SIS_pet_forget_skill : public tag_net_message
{
	NET_SIS_pet_forget_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_forget_skill");
		dw_size = sizeof(NET_SIS_pet_forget_skill);
	}
	DWORD               dwPetID;        //!< 宠物ID
	DWORD				dwErrCode;		
};

#pragma pack(pop)
#endif