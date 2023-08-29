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
*	@file		pet_protocol.h
*	@author		lc
*	@date		2011/03/08	initial
*	@version	0.0.1.0
*	@brief		������Ϣ
*/

#ifndef PET_PROTOCOL
#define PET_PROTOCOL

#pragma pack(push,1)

#include "pet_define.h"
#include "protocol_common_errorcode.h"

//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum 
{
	E_Pets_UnkownErr		=-1,
	E_Pets_Success			= 0,

	E_Pets_StateLimit               =   1,
	E_Pets_Soul_NotExist            =   2,
	E_Pets_Soul_AlreadyExist        =   3,
	E_Pets_Soul_PtrNotValid         =   4,
	E_Pets_Soul_NumExceed           =   5,
	E_Pets_Soul_PetEggErr           =   6,
	E_Pets_Soul_NameIllegal         =   7,
	E_Pets_Soul_MasterNotFound      =   8,
	E_Pets_Soul_RoleExpNotEnough    =   9,
	E_Pets_Soul_RoleMoneyNotEnough  =   10,
	E_Pets_Soul_GradeNotFit         =   11,

	E_Pets_Pet_CalledNumExceed      =   12,
	E_Pets_Pet_AlreadyCalled        =   13,
	E_Pets_Pet_NotCalled            =   14,
	E_Pets_Pet_NotExist             =   15,
	E_Pets_AlreadyMaxAptitude       =   16,
	E_Pets_QualityNotFit            =   17,
	E_Pets_EnhanceFailed            =   18,
	E_Pets_ItemNotValid             =   19,
	E_Pets_PetSkill_Master_NotExist =   21,
	E_Pets_PetSkill_InvalidSkillID  =   22,
	E_Pets_PetSkill_Skill_NotExist  =   23,
	E_Pets_PetSkill_AlreadyStarted  =   24,
	E_Pets_PetSkill_Learn_PetLvlLimit           =   25,
	E_Pets_PetSkill_Learn_HasHighLvlSkill       =   26,
	E_Pets_PetSkill_Learn_Type3NotFit           =   27,
	E_Pets_PetSkill_Learn_StageNotFit           =   28,
	E_Pets_PetSkill_Learn_LvlNotEnough          =   29,
	E_Pets_PetSkill_Learn_PotentialNotEnough    =   30,
	E_Pets_PetSkill_Learn_LvlNotRight           =   31,
	E_Pets_PetSkill_Learn_ItemInvalid           =   32,
	E_Pets_PetSkill_Learn_MaxLeanNum            =   33,
	E_Pets_PetSkill_Learn_StateLimit            =   34,
	E_Pets_PetSkill_Use_ItemNotExist            =   35,
	E_Pets_PetSkill_Use_CoolingDown             =   36,
	E_Pets_PetSkill_Use_WuXingEnergyNotEnough   =   37,
	E_Pets_PetSkill_Use_MaxTalentCount          =   38,
	E_Pets_PetSkill_Use_WorkCounting            =   39,
	E_Pets_PetSkill_Use_StateLimit              =   40,
	E_Pets_PetSkill_Use_NotActiveSkill          =   41,
	E_Pets_PetSkill_Use_SkillProtoInvalid       =   42,
	E_Pets_PetSkill_Use_SpiritNotEnough         =   43,
	E_Pets_PetSkill_Learn_NoPreSkill			=	44,
	E_Pets_PetSkill_Learn_Has_Skill				=	45,		// ������ѧ��
	E_Pets_PetSkill_Learn_NOT_SKILL				=	46,		// �ü��ܲ�����

	E_Pets_PetEquip_Soul_NotExist               =   50,
	E_Pets_PetEquip_Master_NotExist             =   51,
	E_Pets_PetEquip_BagIndexNotFree             =   52,
	E_Pets_PetEquip_BagFull                     =   53,
	E_Pets_PetEquip_PetEquipNotInBag            =   54,
	E_Pets_PetEquip_UnknownEquipProto           =   55,
	E_Pets_PetEquip_IsNotPetEquip               =   56,
	E_Pets_PetEquip_PetLevelNotEnough           =   57,
	E_Pets_PetEquip_EquipIsNotOnPet             =   58,
	E_Pets_PetEquip_EquipAlreadyInPos           =   59,
	E_Pets_PetEquip_InvalidDstPos               =   60,

    E_PetPourExpNotEnough                       =   70,
	E_PetRoleLvlNotEnough						=	71,
	E_Pets_Mount_DstRoleNotFound				=	72,
	E_Pets_Mount_MountSoulNotFound				=	73,
	E_Pets_Mount_SrcRoleNotFound				=	74,
	E_Pets_Mount_DstRoleRefuse					=	75,
	E_Pets_Lock_AlreadyLocked					=	76,
	E_Pets_Lock_NotLocked						=	77,
	E_Pets_Lock_Locked							=	78,
	E_Pets_Delete_HasEquip						=	79, // ����Я��װ�����޷�ɾ��
    E_Pets_Carrylevel_NotEnough                 =   80,
	E_Master_StateLimit							=	81, // ����״̬���ƣ�����PK״̬�������ٻ����
	
	E_Pets_rename_countnot						=	82,	// �Ѿ��Ĺ�������
	E_Pets_Food_NotEquip						=	83, // ������߲���װ��
	E_Pets_Food_NotInCalld						=	84,	// ����δ�ٻ�
	E_Pets_Food_NotEat							=	85,	// ���ﲻ�����ʳ��
	E_Pets_NotExpPocket_Item					=	86,	// ���ǳ����������
	E_Pets_NotCalldPet							=	87,	// û���ٻ��ĳ���
	E_Pets_pocketMax							=	88,	// ���������Ѿ����
	E_Pets_pocket_not_money						=	89,	// ûǮ����

	E_Pets_Not_Dead								=	90,	// ����û��

	E_Pets_PetSkill_Learn_Has_Active			=	91,	// ���������Դ���

	E_Pets_PetSkill_Forget_Fiel					=	92,	// ��������ʧ��
	E_Pets_PetSkill_Forget_cant					=	93, // �ü��ܲ�������
	
	E_Pets_Buy_LoveValue_not_yuanbao			=	100, // Ԫ������

	E_Pets_color_not_silver						=	120, // ��Ǯ����
	E_Pets_color_not_true						=	121, // ��ɫ����
	E_PetS_color_has_called						=	122, // ������Ϣ״̬

	E_PetS_Change_item_not						=	130, // �ɱ䵤������
	E_PetS_Change_level_not						=	131, // �ȼ����������ɱ�
	E_PetS_Change_item_level_not				=	132, // ��Ʒ�ȼ�����

	E_PetS_AddPoint_not_point					=	140, // ʣ���������

	E_Pets_Fusion_Quality_Not					=	150, // Ʒ�ʲ���
	E_Pets_Fusion_Is_Called						=	151, // ���ﲻ����Ϣ״̬
	E_Pets_Fusion_Not_Money						=	152, // ��Ҳ���
	E_Pets_Funion_fail							=	153, // �ں�ʧ��
	E_Pets_Funion_Level_Not						=	155, // ����ȼ�����
	
	E_Pets_Xiulian_Cant							=	160, // ��״̬���ܼ���
	E_Pets_Xiulian_Not_Sivler					=	161, // ��Ҳ���
	E_Pets_Xiulian_Not_Yuanbao					=	162, // Ԫ������
	E_Pets_Xiulian_Full							=	163, // ��λ����
	E_Pets_XiulianReturn_cant					=	164, // ���ڼ���,�����ջ�

    E_PetErrorEnd,
};



//------------------------------------------------------------------------------

//! \struct  NET_SIC_get_pet_att
//! \brief   ��ó�������
struct NET_SIC_get_pet_att : public tag_net_message
{
	NET_SIC_get_pet_att()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_pet_att");
		dw_size = sizeof(NET_SIC_get_pet_att);
	}
	DWORD           dw_role_id;       //!< ��ɫID
	DWORD           dwPetID;        //!< ����ID(INVALID_VALUEʱΪȡ��������г���)
};


//! \struct  NET_SIS_get_pet_att
//! \brief   ��ó�������
struct NET_SIS_get_pet_att : public tag_net_message
{
	NET_SIS_get_pet_att()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_pet_att");
		dw_size = sizeof(NET_SIS_get_pet_att);
	}
	DWORD           dw_role_id;       //!< ���ID
	tagPetInitAttr	petAttr;        //!< ����ṹ
};


//! \struct  NET_SIC_delete_pet
//! \brief   ɾ������
struct NET_SIC_delete_pet : public tag_net_message
{
	NET_SIC_delete_pet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_pet");
		dw_size = sizeof(NET_SIC_delete_pet);
	}
	DWORD		dwPetID;        //!< ����id
	DWORD		dw_safe_code;
};

struct NET_SIS_delete_pet : public tag_net_message
{
	NET_SIS_delete_pet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_pet");
		dw_size = sizeof(NET_SIS_delete_pet);
	}
	DWORD           dwErrCode;      //!< ������
	DWORD           dwPetID;        //!< ����id
};


//------------------------------------------------------------------------------

//! \struct  NET_SIC_get_pet_display_info
//! \brief   ���ĳһ�������ֵ��ʾ��Ϣ(��Ҫ���ػ�����)
struct NET_SIC_get_pet_display_info : public tag_net_message
{
	NET_SIC_get_pet_display_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_pet_display_info");
		dw_size = sizeof(NET_SIC_get_pet_display_info);
	}
	DWORD           dw_role_id;                   //!< ��ɫID
	DWORD           dwPetID;                    //!< ��ɫӵ�еĳ���ID
};

//! \struct  NET_SIS_get_pet_display_info
//! \brief   ͬ��,����
struct NET_SIS_get_pet_display_info : public tag_net_message
{
	NET_SIS_get_pet_display_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_pet_display_info");
		dw_size = sizeof(NET_SIS_get_pet_display_info);
	}
	DWORD           dwPetID;                    //!< ����ID
	tagPetDispInfo  DispData;                   //!< ��Ϣ
};


//! \struct  NET_SIS_pet_display_info_change
//! \brief   ����ͬ����ʾ��Ϣ����ʱ�ľŹ���㲥,��������,�ɳ��׶α��ʱ�㲥
struct NET_SIS_pet_display_info_change : public tag_net_message
{
	NET_SIS_pet_display_info_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_display_info_change");
		dw_size = sizeof(NET_SIS_pet_display_info_change);
	}
	DWORD           dwPetID;                    //!< ����ID
	tagPetDispInfo  DispData;                   //!< ��Ϣ
};

//-----------------------------------------------------------------------------
//  ���ؽ�ɫ�������
//-----------------------------------------------------------------------------
struct NET_SIC_use_pet_egg : public tag_net_message
{
	NET_SIC_use_pet_egg()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_use_pet_egg");
		dw_size = sizeof(NET_SIC_use_pet_egg);
	}
	INT64           n64ItemID;                  //!< ���ﵰid
	TCHAR           szPetName[X_SHORT_NAME];    //!< �����ĳ�����
};

struct NET_SIS_use_pet_egg : public tag_net_message
{
	NET_SIS_use_pet_egg()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_use_pet_egg");
		dw_size = sizeof(NET_SIS_use_pet_egg);
	}
	INT64           n64ItemID;                  //!< ���ﵰ64λid
	DWORD			dwErrCode;                  //!< ������
};

//! \struct  NET_SIS_pet_att_change
//! \brief   ͬ�����ؽ�ɫ������ֵ���Ա仯,���Ҫ��ʵʱ��ǿ�������ֶ�,ͨ�������������仯֪ͨ
struct NET_SIS_pet_att_change : public tag_net_message
{
	NET_SIS_pet_att_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_att_change");
		dw_size = sizeof(NET_SIS_pet_att_change);
	}
	DWORD           dwPetID;        //!< ����ID
	INT8            u8AttrType;     //!< �����������(ECSPetAtt)
	INT32           u32NewValue;    //!< ������ֵ
};


//! \struct NET_SIC_set_pet_state
struct NET_SIC_set_pet_state : public tag_net_message
{
	NET_SIC_set_pet_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_pet_state");
		dw_size = sizeof(NET_SIC_set_pet_state);
	}
	DWORD           dwPetID;        //!< ����ID
	UINT8           ePetState;      //!< ״̬����(EPetStateType)
	bool            bVal;           //!< ״ֵ̬
};


//! \struct NET_SIS_set_pet_state
struct NET_SIS_set_pet_state : public tag_net_message
{
	NET_SIS_set_pet_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_pet_state");
		dw_size = sizeof(NET_SIS_set_pet_state);
	}
	DWORD           dwPetID;        //!< ����ID
	UINT8           ePetState;      //!< ״̬����(EPetStateType)
	DWORD			dwErrCode;
};


//! \struct NET_SIC_pet_pour_exp
//! \brief  ��ע����
struct NET_SIC_get_pet_pour_exp_money_need : public tag_net_message
{
	NET_SIC_get_pet_pour_exp_money_need()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_pet_pour_exp_money_need");
		dw_size = sizeof(NET_SIC_get_pet_pour_exp_money_need);
	}
	DWORD           dwPetID;        //!< ����ID
};


//! \struct tagPetNS_PourExp
struct NET_SIS_get_pet_pour_exp_money_need : public tag_net_message
{
	NET_SIS_get_pet_pour_exp_money_need()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_pet_pour_exp_money_need");
		dw_size = sizeof(NET_SIS_get_pet_pour_exp_money_need);
	}
	DWORD           dwPetID;        //!< ����id
	INT64			n64MoneyNeed;
};


//! \struct NET_SIC_pet_pour_exp
//! \brief  ��ע����
struct NET_SIC_pet_pour_exp : public tag_net_message
{
	NET_SIC_pet_pour_exp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_pour_exp");
		dw_size = sizeof(NET_SIC_pet_pour_exp);
	}
	DWORD           dwPetID;        //!< ����ID
	INT64			n64ItemID;		//!< 64λ��ƷID
};


//! \struct NET_SIS_pet_pour_exp
struct NET_SIS_pet_pour_exp : public tag_net_message
{
	NET_SIS_pet_pour_exp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_pour_exp");
		dw_size = sizeof(NET_SIS_pet_pour_exp);
	}
	DWORD           dwErrCode;      //!< ������
	DWORD           dwPetID;        //!< ����id
};

// ��һ�οͻ��˷�n64itemid��Ч
// ��һ�η�������ndststep��ndststep��Ч
// �ڶ��οͻ��˷�ndststep��ndststep��Ч n64itemid��Ч
//! \struct NET_SIC_pet_up_step
//! \brief  ����
struct NET_SIC_pet_up_step : public tag_net_message
{
	NET_SIC_pet_up_step()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_up_step");
		dw_size = sizeof(NET_SIC_pet_up_step);
	}
	INT64			n64ItemID;
	INT				nDstStep;
	DWORD			dwSkillID;
};


//! \struct NET_SIC_pet_up_step
struct NET_SIS_pet_up_step : public tag_net_message
{
	NET_SIS_pet_up_step()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_up_step");
		dw_size = sizeof(NET_SIS_pet_up_step);
	}
	DWORD           dwErrCode;      //!< ������
	INT64			n64ItemID;
	INT				nDstStep;
	DWORD			dwSkillID;
};



//! \struct NET_SIC_pet_enhance
//! \brief  ��������
struct NET_SIC_pet_enhance : public tag_net_message
{
	NET_SIC_pet_enhance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_enhance");
		dw_size = sizeof(NET_SIC_pet_enhance);
	}
	INT64			n64ItemID;
};

//! \struct NET_SIS_pet_enhance
struct NET_SIS_pet_enhance : public tag_net_message
{
	NET_SIS_pet_enhance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_enhance");
		dw_size = sizeof(NET_SIS_pet_enhance);
	}
	DWORD           dwErrCode;      //!< ������
	INT64			n64ItemID;
};


//! \struct NET_SIC_pet_food
//! \brief  ιʳ
struct NET_SIC_pet_food : public tag_net_message
{
	NET_SIC_pet_food()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_food");
		dw_size = sizeof(NET_SIC_pet_food);
	}
	INT64			n64ItemID;
	DWORD			dwFoodType;		// 0:ιʳ 1���������� 2:��������
};


//! \struct NET_SIS_pet_food
struct NET_SIS_pet_food : public tag_net_message
{
	NET_SIS_pet_food()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_food");
		dw_size = sizeof(NET_SIS_pet_food);
	}
	DWORD           dwErrCode;      //!< ������
	INT64			n64ItemID;
};


//! \struct NET_SIS_mount
//! \���
struct NET_SIS_mount : public tag_net_message
{
	NET_SIS_mount()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mount");
		dw_size = sizeof(NET_SIS_mount);
	}
	DWORD	dw_role_id;
	DWORD	dwPetTypeID;
	DWORD	dwPetID;
};


//! \struct NET_SIS_mount2
//! \�ڶ������
struct NET_SIS_mount2 : public tag_net_message
{
	NET_SIS_mount2()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mount2");
		dw_size = sizeof(NET_SIS_mount2);
	}
	DWORD	dwPetID;
	DWORD	dw_role_id;
};

// �������
// ����Ԧ��->������	NET_SIC_mount_invite 
// ������->��������	NET_SIS_mount_on_invite
// ��������->������	NET_SIC_mount_on_invite
// ������->����Ԧ��	NET_SIS_mount_invite

//! \struct NET_SIS_mount_invite
//! \������
struct NET_SIS_mount_on_invite : public tag_net_message
{
	NET_SIS_mount_on_invite()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mount_on_invite");
		dw_size = sizeof(NET_SIS_mount_on_invite);
	}
	DWORD	dwSrcRoleID;
};

struct NET_SIC_mount_on_invite : public tag_net_message
{
	NET_SIC_mount_on_invite()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mount_on_invite");
		dw_size = sizeof(NET_SIC_mount_on_invite);
	}
	DWORD	dwSrcRoleID;
	BOOL	bReceive;
};


//! \struct NET_SIS_mount_invite
//! \����
struct NET_SIC_mount_invite : public tag_net_message
{
	NET_SIC_mount_invite()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mount_invite");
		dw_size = sizeof(NET_SIC_mount_invite);
	}
	DWORD	dwDstRoleID;
};

struct NET_SIS_mount_invite : public tag_net_message
{
	NET_SIS_mount_invite()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mount_invite");
		dw_size = sizeof(NET_SIS_mount_invite);
	}
	DWORD	dwDstRoleID;
	DWORD	dwErrCode;
};


//! \struct NET_SIS_pet_set_lock
//! \����
struct NET_SIC_pet_set_lock : public tag_net_message
{
	NET_SIC_pet_set_lock()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_set_lock");
		dw_size = sizeof(NET_SIC_pet_set_lock);
	}
	DWORD	dwPetID;
	INT64	n64ItemID;
	bool	bSet;
};

struct NET_SIS_pet_set_lock : public tag_net_message
{
	NET_SIS_pet_set_lock()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_set_lock");
		dw_size = sizeof(NET_SIS_pet_set_lock);
	}
	DWORD	dwPetID;
	DWORD	dwErrCode;
};


// �������
struct NET_SIC_pet_rename : public tag_net_message
{
	NET_SIC_pet_rename()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_rename");
		dw_size = sizeof(NET_SIC_pet_rename);
	}
	DWORD	dwPetID;
	TCHAR   szPetName[X_SHORT_NAME];    //!< �����ĳ�����
};

struct NET_SIS_pet_rename : public tag_net_message
{
	NET_SIS_pet_rename()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_rename");
		dw_size = sizeof(NET_SIS_pet_rename);
	}
	DWORD	dwPetID;
	TCHAR   szPetName[X_SHORT_NAME];    //!< �����ĳ�����
	DWORD	dwErrCode;
};


// ʹ�ó���ϵͳ�������
struct NET_SIC_use_special_pet_item : public tag_net_message
{
	NET_SIC_use_special_pet_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_use_special_pet_item");
		dw_size = sizeof(NET_SIC_use_special_pet_item);
	}
	INT64	n64ItemID;
};

struct NET_SIS_use_special_pet_item : public tag_net_message
{
	NET_SIS_use_special_pet_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_use_special_pet_item");
		dw_size = sizeof(NET_SIS_use_special_pet_item);
	}
	DWORD           dwErrCode;      //!< ������
	INT64			n64ItemID;
};

//�������
struct NET_SIC_reborn_pet : public tag_net_message
{
	NET_SIC_reborn_pet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reborn_pet");
		dw_size = sizeof(NET_SIC_reborn_pet);
	}
	DWORD	dwPetID;
	INT64   dw64ItemID;
};

struct NET_SIS_reborn_pet : public tag_net_message
{
	NET_SIS_reborn_pet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reborn_pet");
		dw_size = sizeof(NET_SIS_reborn_pet);
	}

	DWORD           dwErrCode;      //!< ������
};

//������ֵ
struct NET_SIC_buy_love_vaule : public tag_net_message
{
	NET_SIC_buy_love_vaule()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_buy_love_vaule");
		dw_size = sizeof(NET_SIC_buy_love_vaule);
	}
	INT32			dw_yuanbao;		//! ������Ԫ��
	DWORD	dw_safe_code;
};

struct NET_SIS_buy_love_vaule : public tag_net_message
{
	NET_SIS_buy_love_vaule()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_buy_love_vaule");
		dw_size = sizeof(NET_SIS_buy_love_vaule);
	}
	DWORD			dwErrCode;		// ������
};

// ����Ⱦɫ
struct NET_SIC_pet_color : public tag_net_message
{
	NET_SIC_pet_color()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_color");
		dw_size = sizeof(NET_SIC_pet_color);
	}

	DWORD	dwPetID;
	INT		nColor;
};

struct NET_SIS_pet_color : public tag_net_message
{
	NET_SIS_pet_color()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_color");
		dw_size = sizeof(NET_SIS_pet_color);
	}

	DWORD	dw_error_code;
};

// �ɱ�
struct NET_SIC_pet_change : public tag_net_message
{
	NET_SIC_pet_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_change");
		dw_size = sizeof(NET_SIC_pet_change);
	}

	DWORD	dwPetID;
	INT64	n64ItemID;
};

struct NET_SIS_pet_change : public tag_net_message
{
	NET_SIS_pet_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_change");
		dw_size = sizeof(NET_SIS_pet_change);
	}

	DWORD	dw_error_code;
};


// ������
struct NET_SIC_pet_add_point : public tag_net_message
{
	NET_SIC_pet_add_point()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_add_point");
		dw_size = sizeof(NET_SIC_pet_add_point);
	}
	DWORD	dwPetID;
	INT		nAttValue[3]; //0 ����  1 ���� 2���� �ӵ���ֵ
};

struct NET_SIS_pet_add_point : public tag_net_message
{
	NET_SIS_pet_add_point()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_add_point");
		dw_size = sizeof(NET_SIS_pet_add_point);
	}

	DWORD	dw_error_code;
};

//�����ں�
struct NET_SIC_pet_fusion : public tag_net_message
{
	NET_SIC_pet_fusion()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_fusion");
		dw_size = sizeof(NET_SIC_pet_fusion);
	}
	DWORD	dwPetID1;			//����
	DWORD	dwPetID2;			//����
	INT64   dw64ItemID1;		//�ȶ�ҩ��
	//INT64   dw64ItemID2;		//��Ԫ��
	//DWORD   dwItemID3;			//��Ԫ��
	//DWORD	dwItem3Num;			//��Ԫ������
};

struct NET_SIS_pet_fusion : public tag_net_message
{
	NET_SIS_pet_fusion()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_fusion");
		dw_size = sizeof(NET_SIS_pet_fusion);
	}
	DWORD	dw_error_code;
};


//-----------------------------------------------------------------------------
// �������������λ
//-----------------------------------------------------------------------------
struct NET_SIC_pet_xiulian_size_change : public tag_net_message
{
	NET_SIC_pet_xiulian_size_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_xiulian_size_change");
		dw_size = sizeof(NET_SIC_pet_xiulian_size_change);
	}

	DWORD dwNPCID;
};


struct NET_SIS_pet_xiulian_size_change : public tag_net_message
{
	NET_SIS_pet_xiulian_size_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_xiulian_size_change");
		dw_size = sizeof(NET_SIS_pet_xiulian_size_change);
	}
	DWORD dwErrorCode;
	INT16 n16NewSize;
};

// �������
struct NET_SIC_pet_xiulian : public tag_net_message
{
	NET_SIC_pet_xiulian()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_xiulian");
		dw_size = sizeof(NET_SIC_pet_xiulian);
	}

	DWORD dwPetId;			// ����id
	DWORD dwNPCID;			// npcid
	DWORD dwTimeType;		// ʱ������ 0 1 2 3
	DWORD dwModeType;		// ģʽ���� 0 1 2 3 4
	DWORD dw_safe_code;		//��������
};

struct NET_SIS_pet_xiulian : public tag_net_message
{
	NET_SIS_pet_xiulian()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_xiulian");
		dw_size = sizeof(NET_SIS_pet_xiulian);
	}

	DWORD dwPetId;			// ����id
	DWORD dwErrorCode;		// ������
};

// ��������ջ�
struct NET_SIC_pet_xiulian_return : public tag_net_message
{
	NET_SIC_pet_xiulian_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_xiulian_return");
		dw_size = sizeof(NET_SIC_pet_xiulian_return);
	}

	DWORD dwPetId;			// ����id
};

struct NET_SIS_pet_xiulian_return : public tag_net_message
{
	NET_SIS_pet_xiulian_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_xiulian_return");
		dw_size = sizeof(NET_SIS_pet_xiulian_return);
	}

	DWORD dwPetId;			// ����id
	DWORD dwErrorCode;		// ������
};


#pragma pack(pop)
#endif
