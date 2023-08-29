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
*	@brief		宠物消息
*/

#ifndef PET_PROTOCOL
#define PET_PROTOCOL

#pragma pack(push,1)

#include "pet_define.h"
#include "protocol_common_errorcode.h"

//----------------------------------------------------------------------------
// 错误码枚举
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
	E_Pets_PetSkill_Learn_Has_Skill				=	45,		// 技能已学会
	E_Pets_PetSkill_Learn_NOT_SKILL				=	46,		// 该技能不存在

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
	E_Pets_Delete_HasEquip						=	79, // 宠物携带装备，无法删除
    E_Pets_Carrylevel_NotEnough                 =   80,
	E_Master_StateLimit							=	81, // 主人状态限制（处于PK状态，不能召唤宠物）
	
	E_Pets_rename_countnot						=	82,	// 已经改过名字了
	E_Pets_Food_NotEquip						=	83, // 赠与道具不是装备
	E_Pets_Food_NotInCalld						=	84,	// 宠物未召唤
	E_Pets_Food_NotEat							=	85,	// 宠物不吃这个食物
	E_Pets_NotExpPocket_Item					=	86,	// 不是宠物特殊道具
	E_Pets_NotCalldPet							=	87,	// 没有召唤的宠物
	E_Pets_pocketMax							=	88,	// 宠物栏数已经最大
	E_Pets_pocket_not_money						=	89,	// 没钱扩充

	E_Pets_Not_Dead								=	90,	// 宠物没死

	E_Pets_PetSkill_Learn_Has_Active			=	91,	// 主动技能以存在

	E_Pets_PetSkill_Forget_Fiel					=	92,	// 遗忘技能失败
	E_Pets_PetSkill_Forget_cant					=	93, // 该技能不能遗忘
	
	E_Pets_Buy_LoveValue_not_yuanbao			=	100, // 元宝不够

	E_Pets_color_not_silver						=	120, // 金钱不足
	E_Pets_color_not_true						=	121, // 颜色不符
	E_PetS_color_has_called						=	122, // 不在休息状态

	E_PetS_Change_item_not						=	130, // 蜕变丹不存在
	E_PetS_Change_level_not						=	131, // 等级不够不能蜕变
	E_PetS_Change_item_level_not				=	132, // 物品等级不足

	E_PetS_AddPoint_not_point					=	140, // 剩余点数不足

	E_Pets_Fusion_Quality_Not					=	150, // 品质不符
	E_Pets_Fusion_Is_Called						=	151, // 宠物不在休息状态
	E_Pets_Fusion_Not_Money						=	152, // 金币不足
	E_Pets_Funion_fail							=	153, // 融合失败
	E_Pets_Funion_Level_Not						=	155, // 宠物等级不符
	
	E_Pets_Xiulian_Cant							=	160, // 该状态不能寄养
	E_Pets_Xiulian_Not_Sivler					=	161, // 金币不足
	E_Pets_Xiulian_Not_Yuanbao					=	162, // 元宝需求
	E_Pets_Xiulian_Full							=	163, // 栏位满了
	E_Pets_XiulianReturn_cant					=	164, // 不在寄养,不能收回

    E_PetErrorEnd,
};



//------------------------------------------------------------------------------

//! \struct  NET_SIC_get_pet_att
//! \brief   获得宠物属性
struct NET_SIC_get_pet_att : public tag_net_message
{
	NET_SIC_get_pet_att()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_pet_att");
		dw_size = sizeof(NET_SIC_get_pet_att);
	}
	DWORD           dw_role_id;       //!< 角色ID
	DWORD           dwPetID;        //!< 宠物ID(INVALID_VALUE时为取此玩家所有宠物)
};


//! \struct  NET_SIS_get_pet_att
//! \brief   获得宠物属性
struct NET_SIS_get_pet_att : public tag_net_message
{
	NET_SIS_get_pet_att()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_pet_att");
		dw_size = sizeof(NET_SIS_get_pet_att);
	}
	DWORD           dw_role_id;       //!< 玩家ID
	tagPetInitAttr	petAttr;        //!< 宠物结构
};


//! \struct  NET_SIC_delete_pet
//! \brief   删除宠物
struct NET_SIC_delete_pet : public tag_net_message
{
	NET_SIC_delete_pet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_pet");
		dw_size = sizeof(NET_SIC_delete_pet);
	}
	DWORD		dwPetID;        //!< 宠物id
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
	DWORD           dwErrCode;      //!< 错误码
	DWORD           dwPetID;        //!< 宠物id
};


//------------------------------------------------------------------------------

//! \struct  NET_SIC_get_pet_display_info
//! \brief   获得某一宠物非数值显示信息(需要本地缓冲上)
struct NET_SIC_get_pet_display_info : public tag_net_message
{
	NET_SIC_get_pet_display_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_pet_display_info");
		dw_size = sizeof(NET_SIC_get_pet_display_info);
	}
	DWORD           dw_role_id;                   //!< 角色ID
	DWORD           dwPetID;                    //!< 角色拥有的宠物ID
};

//! \struct  NET_SIS_get_pet_display_info
//! \brief   同上,返回
struct NET_SIS_get_pet_display_info : public tag_net_message
{
	NET_SIS_get_pet_display_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_pet_display_info");
		dw_size = sizeof(NET_SIS_get_pet_display_info);
	}
	DWORD           dwPetID;                    //!< 宠物ID
	tagPetDispInfo  DispData;                   //!< 信息
};


//! \struct  NET_SIS_pet_display_info_change
//! \brief   宠物同屏显示信息更改时的九宫格广播,即宠物名,成长阶段变更时广播
struct NET_SIS_pet_display_info_change : public tag_net_message
{
	NET_SIS_pet_display_info_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_display_info_change");
		dw_size = sizeof(NET_SIS_pet_display_info_change);
	}
	DWORD           dwPetID;                    //!< 宠物ID
	tagPetDispInfo  DispData;                   //!< 信息
};

//-----------------------------------------------------------------------------
//  本地角色宠物相关
//-----------------------------------------------------------------------------
struct NET_SIC_use_pet_egg : public tag_net_message
{
	NET_SIC_use_pet_egg()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_use_pet_egg");
		dw_size = sizeof(NET_SIC_use_pet_egg);
	}
	INT64           n64ItemID;                  //!< 宠物蛋id
	TCHAR           szPetName[X_SHORT_NAME];    //!< 玩家起的宠物名
};

struct NET_SIS_use_pet_egg : public tag_net_message
{
	NET_SIS_use_pet_egg()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_use_pet_egg");
		dw_size = sizeof(NET_SIS_use_pet_egg);
	}
	INT64           n64ItemID;                  //!< 宠物蛋64位id
	DWORD			dwErrCode;                  //!< 错误码
};

//! \struct  NET_SIS_pet_att_change
//! \brief   同步本地角色宠物数值属性变化,针对要求实时性强的数据字段,通过服务器主动变化通知
struct NET_SIS_pet_att_change : public tag_net_message
{
	NET_SIS_pet_att_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_att_change");
		dw_size = sizeof(NET_SIS_pet_att_change);
	}
	DWORD           dwPetID;        //!< 宠物ID
	INT8            u8AttrType;     //!< 宠物属性类别(ECSPetAtt)
	INT32           u32NewValue;    //!< 属性新值
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
	DWORD           dwPetID;        //!< 宠物ID
	UINT8           ePetState;      //!< 状态类型(EPetStateType)
	bool            bVal;           //!< 状态值
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
	DWORD           dwPetID;        //!< 宠物ID
	UINT8           ePetState;      //!< 状态类型(EPetStateType)
	DWORD			dwErrCode;
};


//! \struct NET_SIC_pet_pour_exp
//! \brief  灌注经验
struct NET_SIC_get_pet_pour_exp_money_need : public tag_net_message
{
	NET_SIC_get_pet_pour_exp_money_need()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_pet_pour_exp_money_need");
		dw_size = sizeof(NET_SIC_get_pet_pour_exp_money_need);
	}
	DWORD           dwPetID;        //!< 宠物ID
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
	DWORD           dwPetID;        //!< 宠物id
	INT64			n64MoneyNeed;
};


//! \struct NET_SIC_pet_pour_exp
//! \brief  灌注经验
struct NET_SIC_pet_pour_exp : public tag_net_message
{
	NET_SIC_pet_pour_exp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_pour_exp");
		dw_size = sizeof(NET_SIC_pet_pour_exp);
	}
	DWORD           dwPetID;        //!< 宠物ID
	INT64			n64ItemID;		//!< 64位物品ID
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
	DWORD           dwErrCode;      //!< 错误码
	DWORD           dwPetID;        //!< 宠物id
};

// 第一次客户端发n64itemid有效
// 第一次服务器回ndststep和ndststep有效
// 第二次客户端发ndststep和ndststep有效 n64itemid无效
//! \struct NET_SIC_pet_up_step
//! \brief  升阶
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
	DWORD           dwErrCode;      //!< 错误码
	INT64			n64ItemID;
	INT				nDstStep;
	DWORD			dwSkillID;
};



//! \struct NET_SIC_pet_enhance
//! \brief  资质提升
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
	DWORD           dwErrCode;      //!< 错误码
	INT64			n64ItemID;
};


//! \struct NET_SIC_pet_food
//! \brief  喂食
struct NET_SIC_pet_food : public tag_net_message
{
	NET_SIC_pet_food()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_food");
		dw_size = sizeof(NET_SIC_pet_food);
	}
	INT64			n64ItemID;
	DWORD			dwFoodType;		// 0:喂食 1：道具赠与 2:增加生命
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
	DWORD           dwErrCode;      //!< 错误码
	INT64			n64ItemID;
};


//! \struct NET_SIS_mount
//! \骑乘
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
//! \第二人骑乘
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

// 邀请骑乘
// 主驾驭者->服务器	NET_SIC_mount_invite 
// 服务器->被邀请者	NET_SIS_mount_on_invite
// 被邀请者->服务器	NET_SIC_mount_on_invite
// 服务器->主驾驭者	NET_SIS_mount_invite

//! \struct NET_SIS_mount_invite
//! \被邀请
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
//! \邀请
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
//! \邀请
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


// 宠物改名
struct NET_SIC_pet_rename : public tag_net_message
{
	NET_SIC_pet_rename()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_rename");
		dw_size = sizeof(NET_SIC_pet_rename);
	}
	DWORD	dwPetID;
	TCHAR   szPetName[X_SHORT_NAME];    //!< 玩家起的宠物名
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
	TCHAR   szPetName[X_SHORT_NAME];    //!< 玩家起的宠物名
	DWORD	dwErrCode;
};


// 使用宠物系统特殊道具
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
	DWORD           dwErrCode;      //!< 错误码
	INT64			n64ItemID;
};

//复活宠物
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

	DWORD           dwErrCode;      //!< 错误码
};

//购买爱心值
struct NET_SIC_buy_love_vaule : public tag_net_message
{
	NET_SIC_buy_love_vaule()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_buy_love_vaule");
		dw_size = sizeof(NET_SIC_buy_love_vaule);
	}
	INT32			dw_yuanbao;		//! 花多少元宝
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
	DWORD			dwErrCode;		// 错误码
};

// 宠物染色
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

// 蜕变
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


// 点属性
struct NET_SIC_pet_add_point : public tag_net_message
{
	NET_SIC_pet_add_point()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_add_point");
		dw_size = sizeof(NET_SIC_pet_add_point);
	}
	DWORD	dwPetID;
	INT		nAttValue[3]; //0 力量  1 敏捷 2智力 加的数值
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

//宠物融合
struct NET_SIC_pet_fusion : public tag_net_message
{
	NET_SIC_pet_fusion()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_fusion");
		dw_size = sizeof(NET_SIC_pet_fusion);
	}
	DWORD	dwPetID1;			//主宠
	DWORD	dwPetID2;			//副宠
	INT64   dw64ItemID1;		//稳定药剂
	//INT64   dw64ItemID2;		//固元丹
	//DWORD   dwItemID3;			//培元丹
	//DWORD	dwItem3Num;			//培元丹数量
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
// 开启宠物寄养栏位
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

// 宠物寄养
struct NET_SIC_pet_xiulian : public tag_net_message
{
	NET_SIC_pet_xiulian()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_xiulian");
		dw_size = sizeof(NET_SIC_pet_xiulian);
	}

	DWORD dwPetId;			// 宠物id
	DWORD dwNPCID;			// npcid
	DWORD dwTimeType;		// 时间类型 0 1 2 3
	DWORD dwModeType;		// 模式类型 0 1 2 3 4
	DWORD dw_safe_code;		//超级密码
};

struct NET_SIS_pet_xiulian : public tag_net_message
{
	NET_SIS_pet_xiulian()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_xiulian");
		dw_size = sizeof(NET_SIS_pet_xiulian);
	}

	DWORD dwPetId;			// 宠物id
	DWORD dwErrorCode;		// 错误码
};

// 宠物寄养收回
struct NET_SIC_pet_xiulian_return : public tag_net_message
{
	NET_SIC_pet_xiulian_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_xiulian_return");
		dw_size = sizeof(NET_SIC_pet_xiulian_return);
	}

	DWORD dwPetId;			// 宠物id
};

struct NET_SIS_pet_xiulian_return : public tag_net_message
{
	NET_SIS_pet_xiulian_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_xiulian_return");
		dw_size = sizeof(NET_SIS_pet_xiulian_return);
	}

	DWORD dwPetId;			// 宠物id
	DWORD dwErrorCode;		// 错误码
};


#pragma pack(pop)
#endif
