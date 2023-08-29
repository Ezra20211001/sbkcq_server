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
 *	@file		GMSaveProtocol
 *	@author		mwh
 *	@date		2011/09/01	initial
 *	@version	0.0.1.0
 *	@brief		保存协议
*/

#ifndef __GM_SAVE_PROTOCOL_H__
#define __GM_SAVE_PROTOCOL_H__


#pragma  pack(push,1)

#include "GMDefine.h"

//! 保存角色基础数据
struct NET_C2GMS_SaveRoleBasicData : public tag_net_message 
{ 
	NET_C2GMS_SaveRoleBasicData ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_SaveRoleBasicData") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	DWORD dwAccountID;
	tag_role_basic_save stRoleSaveBasic;
	TCHAR szServerName[X_SHORT_NAME];
}; 
struct NET_GMS2C_SaveRoleBasicData : public tag_net_message 
{ 
	NET_GMS2C_SaveRoleBasicData ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_SaveRoleBasicData") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	DWORD dwError;
}; 

//! 保存角色技能
struct NET_C2GMS_SaveRoleSkill : public tag_net_message 
{ 
	NET_C2GMS_SaveRoleSkill ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_SaveRoleSkill") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
	tag_role_skill_save stRoleSkillSave;
}; 
struct NET_GMS2C_SaveRoleSkill: public tag_net_message 
{ 
	NET_GMS2C_SaveRoleSkill ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_SaveRoleSkill") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	DWORD dwError;
}; 

//! 保存宠物
struct NET_C2GMS_SaveRolePet : public tag_net_message 
{ 
	NET_C2GMS_SaveRolePet ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_SaveRolePet") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
	tag_role_pet_save stRolePetSave;
}; 
struct NET_GMS2C_SaveRolePet: public tag_net_message 
{ 
	NET_GMS2C_SaveRolePet ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_SaveRolePet") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	DWORD dwError;
}; 
//! 保存装备
struct NET_C2GMS_SaveRoleEquip : public tag_net_message 
{ 
	NET_C2GMS_SaveRoleEquip ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_SaveRoleEquip") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
	tag_equip_save stRoleEquipSave;
}; 
struct NET_GMS2C_SaveRoleEquip: public tag_net_message 
{ 
	NET_GMS2C_SaveRoleEquip ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_SaveRoleEquip") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	DWORD dwError;
}; 

//! 制造装备
struct NET_C2GMS_GMCreateEquip : public tag_net_message 
{ 
	NET_C2GMS_GMCreateEquip ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GMCreateEquip") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
	tag_equip_create stEquipCreate;
}; 
struct NET_GMS2C_GMCreateEquip: public tag_net_message 
{ 
	NET_GMS2C_GMCreateEquip ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_GMCreateEquip") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT64 n64Serial; // 装备世界唯一标示
	DWORD dwRoleID;
	DWORD dwError;
}; 

//! 制造物品
struct NET_C2GMS_GMCreateItem : public tag_net_message
{
	NET_C2GMS_GMCreateItem ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GMCreateItem") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
	tag_item_create stItemCreate;
};
//批量制造道具 gx add 2013.11.05
struct NET_C2GMS_GMCreateItem_Serial : public tag_net_message
{
	NET_C2GMS_GMCreateItem_Serial ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GMCreateItem_Serial") ;   
		dw_size = sizeof(*this) ; 
	} 
	TCHAR szRoleName[SHORT_STRING];
	TCHAR szServerName[X_SHORT_NAME];
	tag_item_create stItemCreate;
};
//end
struct NET_GMS2C_GMCreateItem: public tag_net_message 
{ 
	NET_GMS2C_GMCreateItem ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_GMCreateItem") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT64 n64Serial; // 物品世界唯一标示
	DWORD dwTypeID;//gx add
	DWORD dwRoleID;
	DWORD dwError;
}; 
//! 删除道具
struct NET_C2GMS_DeleteItem : public tag_net_message
{
	NET_C2GMS_DeleteItem()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2GMS_DeleteItem");
		dw_size = sizeof(*this);
	}
	INT64  serial;
	DWORD dw_type_id;
	DWORD dw_role_id;
	TCHAR szServerName[X_SHORT_NAME];
};
struct NET_GMS2C_DeleteItem : public tag_net_message
{
	NET_GMS2C_DeleteItem()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2C_DeleteItem");
		dw_size = sizeof(*this);
	}
	INT64  serial;
	DWORD dw_role_id;
	BOOL bSuccess;
};

//! 删除宠物
struct NET_C2GMS_DeletePet : public tag_net_message
{
	NET_C2GMS_DeletePet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2GMS_DeletePet");
		dw_size = sizeof(*this);
	}
	DWORD dw_pet_id;
	DWORD dw_role_id;
	TCHAR szServerName[X_SHORT_NAME];
};
struct NET_GMS2C_DeletePet : public tag_net_message
{
	NET_GMS2C_DeletePet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2C_DeletePet");
		dw_size = sizeof(*this);
	}
	DWORD dw_pet_id;
	DWORD dw_role_id;
	BOOL bSuccess;
};
//! 删除角色技能
struct NET_C2GMS_DeleteRoleSkill : public tag_net_message
{
	NET_C2GMS_DeleteRoleSkill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2GMS_DeleteRoleSkill");
		dw_size = sizeof(*this);
	}
	DWORD dw_role_id;
	DWORD dw_skill_id;
	TCHAR szServerName[X_SHORT_NAME];
};
struct NET_GMS2C_DeleteRoleSkill : public tag_net_message
{
	NET_GMS2C_DeleteRoleSkill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2C_DeleteRoleSkill");
		dw_size = sizeof(*this);
	}
	DWORD dw_role_id;
	DWORD dw_skill_id;
	BOOL bSuccess;
};


//! 发钱或者元宝
struct NET_C2GMS_GMGiveMoney : public tag_net_message
{
	NET_C2GMS_GMGiveMoney ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GMGiveMoney") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
	DWORD dwYuanBao;
	DWORD dwMoney;
};

struct NET_GMS2C_GMGiveMoney: public tag_net_message 
{ 
	NET_GMS2C_GMGiveMoney ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_GMGiveMoney") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	DWORD dwError;
	DWORD dwYuanBao;
	DWORD dwMoney;
}; 

#pragma pack(pop)

#endif //__GM_SAVE_PROTOCOL_H__