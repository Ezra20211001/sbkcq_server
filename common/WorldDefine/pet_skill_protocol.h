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
*	@brief		���＼����Ϣ
*/

#ifndef PET_SKILL_PROTOCOL
#define PET_SKILL_PROTOCOL

#pragma pack(push,1)

#include "pet_define.h"
#include "pet_skill_define.h"
#include "protocol_common_errorcode.h"

//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum EPetSkillMsgErrCode
{
    E_PetSkill_Success              =   E_Success,	// �ɹ�
	E_PetSkill_InUse				,				// ����ʹ��
	E_PetSkill_CoolDown				,				// ��ȴ��
    E_PetSkill_Unknown				,				// δ֪
};

//-----------------------------------------------------------------------------
// ��ӣ����£�ɾ�����＼��(ֻ�Ա�����ң������ڱ���)
//-----------------------------------------------------------------------------
struct NET_SIS_add_pet_skill : public tag_net_message
{
	NET_SIS_add_pet_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_pet_skill");
		dw_size = sizeof(NET_SIS_add_pet_skill);
	}
	DWORD               dwPetID;        //!< ����ID
	DWORD				dwSkillID;      //!< ��������
};

struct NET_SIS_remove_pet_skill : public tag_net_message
{
	NET_SIS_remove_pet_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_remove_pet_skill");
		dw_size = sizeof(NET_SIS_remove_pet_skill);
	}
	DWORD               dwPetID;        //!< ����ID
	DWORD               dwSkillID;      //!< ���＼��ID
};


//-----------------------------------------------------------------------------
// ʹ�ü���
//-----------------------------------------------------------------------------
struct NET_SIC_use_pet_skill : public tag_net_message
{
	NET_SIC_use_pet_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_use_pet_skill");
		dw_size = sizeof(NET_SIC_use_pet_skill);
	}
	DWORD               dwPetID;        //!< ����ID
	DWORD               dwSkillID;      //!< ���＼��ID
	BYTE				byData[1];		//!< ��������
};

struct NET_SIS_use_pet_skill : public tag_net_message
{
	NET_SIS_use_pet_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_use_pet_skill");
		dw_size = sizeof(NET_SIS_use_pet_skill);
	}
	DWORD               dwPetID;        //!< ����ID
	DWORD               dwSkillID;      //!< ���＼��ID
	DWORD				dwErrCode;		//!< ����ֵ
	BYTE				byData[1];		//!< ��������
};


//-----------------------------------------------------------------------------
// ѧϰ����
//-----------------------------------------------------------------------------
struct NET_SIC_pet_learn_skill : public tag_net_message
{
	NET_SIC_pet_learn_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_learn_skill");
		dw_size = sizeof(NET_SIC_pet_learn_skill);
	}
	DWORD               dwPetID;        //!< ����ID
	INT64				n64ItemID;      //!< ������id
};

struct NET_SIS_pet_learn_skill : public tag_net_message
{
	NET_SIS_pet_learn_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_learn_skill");
		dw_size = sizeof(NET_SIS_pet_learn_skill);
	}
	DWORD               dwPetID;        //!< ����ID
	INT64				n64ItemID;      //!< ������id
	DWORD				dwErrCode;		
};

// ��������
struct NET_SIC_pet_levelup_skill : public tag_net_message
{
	NET_SIC_pet_levelup_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_levelup_skill");
		dw_size = sizeof(NET_SIC_pet_levelup_skill);
	}
	DWORD               dwPetID;        //!< ����ID
	DWORD				dwSkillID;      //!< ����id
};

struct NET_SIS_pet_levelup_skill : public tag_net_message
{
	NET_SIS_pet_levelup_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_levelup_skill");
		dw_size = sizeof(NET_SIS_pet_levelup_skill);
	}
	DWORD               dwPetID;        //!< ����ID
	DWORD				dwSkillID;      //!< ����id
	DWORD				dwErrCode;		
};

//-----------------------------------------------------------------------------
// ��������
//-----------------------------------------------------------------------------
struct NET_SIC_pet_forget_skill : public tag_net_message
{
	NET_SIC_pet_forget_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_forget_skill");
		dw_size = sizeof(NET_SIC_pet_forget_skill);
	}
	DWORD               dwPetID;        //!< ����ID
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
	DWORD               dwPetID;        //!< ����ID
	DWORD				dwErrCode;		
};

#pragma pack(pop)
#endif