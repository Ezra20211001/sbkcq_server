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
 *	@file		LogDBSave
 *	@author		mwh
 *	@date		2011/09/01	initial
 *	@version	0.0.1.0
 *	@brief		Edit Tool Save
*/

#include "StdAfx.h"
#include "GMServer.h"
#include "LogDB.h"
#include "../../common/WorldDefine/container_define.h"
#include "../../common/WorldDefine/ItemDefine.h"
#include "../../common/WorldDefine/GMSaveProtocol.h"

//! 保存角色基础属性
DWORD LogDB::save_role_basic(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne)
{
	return this->common_update_function(table_name, 
		fastdelegate::MakeDelegate(this,&LogDB::func_set_save_role_basic), in, dw_account, dw_role, nCount, nSzOne);
}

VOID LogDB::func_set_save_role_basic(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role)
{
	tag_role_basic_save* p = static_cast<tag_role_basic_save*>(in);

	p_stream->update_item(table_name);
	//p_stream->write_string("exp_cur_level=") << p->n_cur_exp;
	//p_stream->write_string(",level=") << p->n_level;
	//p_stream->write_string(",pk_value=") << p->n_pk;
	//p_stream->write_string(",exploits=") << p->exploits;

	p_stream->write_string("bag_gold=") << p->n_bag_gold;
	p_stream->write_string(",bag_silver=") << p->n_bag_silver;
	p_stream->write_string(",bag_copper=") << p->n_bag_copper;

	//p_stream->write_string(",bag_bind_gold=") << p->n_bag_bind_gold;
	//p_stream->write_string(",bag_bind_silver=") << p->n_bag_bind_silver;
	//p_stream->write_string(",bag_bind_copper=") << p->n_bag_bind_copper;

	//p_stream->write_string(",ware_gold=") << p->n_ware_gold;
	//p_stream->write_string(",ware_silver=") << p->n_ware_silver;
	//p_stream->write_string(",ware_copper=") << p->n_ware_copper;
	p_stream->write_string(",bag_yuanbao=") << p->dw_bindyuanbao;
	p_stream->where_item();
	p_stream->write_string("role_id=") << dw_role;
	p_stream->write_string(" AND account_id=") << dw_account;
}

//! 保存账号元宝
DWORD LogDB::save_account_yuanbao(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role)
{
	return this->common_update_function(table_name, 
		fastdelegate::MakeDelegate(this,&LogDB::func_set_save_account_yuanbao),in, dw_account, dw_role, 1, 0);
}

VOID LogDB::func_set_save_account_yuanbao(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role)
{
	tag_role_basic_save* p = static_cast<tag_role_basic_save*>(in);
	p_stream->update_item(table_name);
	p_stream->write_string("baibao_yuanbao=") << p->dw_yuanbao;
	p_stream->where_item();
	p_stream->write_string("account_id=") << dw_account;
}

//! 保存技能
DWORD LogDB::save_role_skill(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne)
{
	return this->common_update_function(table_name, 
		fastdelegate::MakeDelegate(this,&LogDB::func_set_save_role_skill), in, dw_account, dw_role, nCount, nSzOne);
}
VOID LogDB::func_set_save_role_skill(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role)
{
	tag_role_skill_save* p = static_cast<tag_role_skill_save*>(in);

	p_stream->replace_item(table_name);
	p_stream->write_string("id=") << p->nSkillID;
	p_stream->write_string(",role_id=") << dw_role;
	p_stream->write_string(",self_level=") << p->nSkillLevel;
	p_stream->write_string(",proficiency=") << p->nProficiency;
	p_stream->write_string(",cooldown=") << p->nCooldown;
}
//! 保存宠物
DWORD LogDB::save_role_pet(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne)
{
	return this->common_update_function("pet_data", 
		fastdelegate::MakeDelegate(this,&LogDB::func_set_save_pet_basic), in, dw_account, dw_role, nCount, nSzOne);
}
VOID LogDB::func_set_save_pet_basic(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role)
{
	tag_role_pet_save* p = static_cast<tag_role_pet_save*>(in);
	p_stream->update_item(table_name);
	p_stream->write_string("cur_spirit=") << p->dw_cur_spirit;
	p_stream->write_string(",happy_value=") << p->dw_happy_val;
	p_stream->write_string(",grade=") << p->nGrade;
	p_stream->write_string(",step=") << p->nStep;
	p_stream->write_string(",strength=") << p->n_strength;
	p_stream->write_string(",agility=") << p->n_agility;
	p_stream->write_string(",innerforce=") << p->n_innerForce;
	p_stream->write_string(",attpoint=") << p->n_att_point;
	p_stream->where_item();
	p_stream->write_string("pet_id=") << p->dw_id;
	p_stream->write_string(" AND master_id=") << dw_role;
}
//! 保存宠物技能
DWORD LogDB::save_role_pet_skill(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne)
{
	tag_role_pet_save* p = static_cast<tag_role_pet_save*>(in);
	
	//! 先删除所有技能？
//	common_update_function("pet_skill", 
//		fastdelegate::MakeDelegate(this,&LogDB::func_set_delete_pet_skill), in, dw_account, p->dw_id, nCount, nSzOne);

	//! 最后在添加
//	return common_update_function("pet_skill", 
//		fastdelegate::MakeDelegate(this,&LogDB::func_set_save_pet_skill), p->dw_skill_id, dw_account, p->dw_id, _countof(p->dw_skill_id), sizeof(DWORD));
	return 0;
}
VOID LogDB::func_set_delete_pet_skill(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role)
{
	p_stream->delete_item(table_name);
	p_stream->where_item();
	p_stream->write_string("pet_id=") << dw_role;
}
VOID LogDB::func_set_save_pet_skill(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role)
{
	DWORD* pSkillID = static_cast<DWORD*>(in);
	if(*pSkillID != 0)
	{
		p_stream->insert_item(table_name);
		p_stream->write_string("pet_skill_type_id=") << (*pSkillID);
		p_stream->write_string(",pet_id=") << dw_role;
	}
}
//! 保存装备
DWORD LogDB::save_role_equip(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne)
{
	DWORD dwRet1 =  this->common_update_function("equip", 
		fastdelegate::MakeDelegate(this,&LogDB::func_set_save_role_equip), in, dw_account, dw_role, nCount, nSzOne);

	DWORD dwRet2 =  this->common_update_function("item", 
		fastdelegate::MakeDelegate(this,&LogDB::func_set_save_role_equip_bind), in, dw_account, dw_role, nCount, nSzOne);

	return (dwRet1 == E_Success && dwRet2 == E_Success);
}
VOID LogDB::func_set_save_role_equip(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role)
{
	odbc::tag_mysql_connect* p_conn = m_p_db_interface->get_idlesse_connect();
	tag_equip_save* p = static_cast<tag_equip_save*>(in);
	p_stream->update_item("equip");
	p_stream->write_string("level=")<<p->nLevel;
	p_stream->write_string(",exp=")<<p->nCurLevelExp;
	p_stream->write_string(",talent_point=")<<p->byTalentPoint;
	p_stream->write_string(",max_talent_point=")<<p->byMaxTalentPoint;
	p_stream->write_string(",hole_num=")<<p->byHoleNum;
	p_stream->write_string(",quality=") << p->byQuality;
	p_stream->write_string(",consolidate_level=")<<p->byConsolidateLevel;
	p_stream->write_string(",consolidate_level_star=")<<p->byConsolidateLevelStar;
	p_stream->write_string(",flare_val=")<<p->byFlareVal;
	p_stream->write_string(",equip_add_att='").write_blob(p->EquipAttitionalAtt, sizeof(p->EquipAttitionalAtt), p_conn);
	p_stream->write_string("',hole_gem_id='").write_blob(p->dwHoleGemID, sizeof(p->dwHoleGemID), p_conn);
	p_stream->write_string("'");
	p_stream->write_string(",skill_list=NULL");
	p_stream->where_item();
	p_stream->write_string("serial=") << p->n64_serial;
}

VOID LogDB::func_set_save_role_equip_bind(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role)
{
	odbc::tag_mysql_connect* p_conn = m_p_db_interface->get_idlesse_connect();
	tag_equip_save* p = static_cast<tag_equip_save*>(in);
	p_stream->update_item("item");
	p_stream->write_string("bind=") << p->bybind;
	p_stream->where_item();
	p_stream->write_string("serial=") << p->n64_serial;
}
BOOL LogDB::delete_role_item(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne)
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();
	if(!VALID_POINT(pStream)) return FALSE;

	BOOL ret = TRUE;
	NET_C2GMS_DeleteItem* xProtocol = (NET_C2GMS_DeleteItem*)in;

	pStream->clear( );
	pStream->delete_item("item");
	pStream->where_item();
	pStream->write_string("serial=") << xProtocol->serial;
	ret = m_p_db_interface->sql_execute(pStream);
	if(!ret) goto EXIT;

EXIT:
	m_p_db_interface->return_io(pStream);
	return ret;
}
BOOL LogDB::delete_role_equip(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne)
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();
	if(!VALID_POINT(pStream)) return FALSE;

	BOOL ret = TRUE;
	NET_C2GMS_DeleteItem* xProtocol = (NET_C2GMS_DeleteItem*)in;

	//! 先备份
	pStream->copy_table("equip_del", "*", "equip");
	pStream->where_item();
	pStream->write_string("serial=") << xProtocol->serial;
	ret = m_p_db_interface->sql_execute(pStream);
	if(!ret) goto EXIT;

	//!
	pStream->clear( );
	pStream->copy_table("item_del", "*", "item");
	pStream->where_item();
	pStream->write_string("serial=") << xProtocol->serial;
	ret = m_p_db_interface->sql_execute(pStream);
	if(!ret) goto EXIT;

	//! 开始删除
	pStream->clear( );
	pStream->delete_item("item");
	pStream->where_item();
	pStream->write_string("serial=") << xProtocol->serial;
	ret = m_p_db_interface->sql_execute(pStream);
	if(!ret) goto EXIT;

	pStream->clear( );
	pStream->delete_item("equip");
	pStream->where_item();
	pStream->write_string("serial=") << xProtocol->serial;
	ret =  m_p_db_interface->sql_execute(pStream);
	if(!ret) goto EXIT;

EXIT:
	m_p_db_interface->return_io(pStream);
	return ret;
}
BOOL LogDB::delete_role_pet(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne)
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();
	if(!VALID_POINT(pStream)) return FALSE;

	BOOL ret = TRUE;
	NET_C2GMS_DeletePet* xProtocol = (NET_C2GMS_DeletePet*)in;

	pStream->clear( );
	pStream->delete_item("pet_skill");
	pStream->where_item();
	pStream->write_string("pet_id=")<< xProtocol->dw_pet_id;
	ret = m_p_db_interface->sql_execute(pStream);
	if(!ret) goto EXIT;

	pStream->clear( );
	pStream->delete_item("item");
	pStream->where_item();
	pStream->write_string("owner_id=") << xProtocol->dw_pet_id;
	pStream->write_string(" and (container_type_id!=") << EICT_RoleWare;
	pStream->write_string(" or (container_type_id=") << EICT_RoleWare;
	pStream->write_string(" and bind=") << EBS_Bind;
	pStream->write_string("))");
	ret = m_p_db_interface->sql_execute(pStream);
	if(!ret) goto EXIT;

	pStream->clear( );
	pStream->delete_item("pet_data");
	pStream->where_item();
	pStream->write_string("pet_id=") << xProtocol->dw_pet_id;
	ret = m_p_db_interface->sql_execute(pStream);
	if(!ret) goto EXIT;

EXIT:
	m_p_db_interface->return_io(pStream);
	return ret;
}

BOOL LogDB::delete_role_skill(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne)
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();
	if(!VALID_POINT(pStream)) return FALSE;

	BOOL ret = TRUE;
	NET_C2GMS_DeleteRoleSkill* xProtocol = (NET_C2GMS_DeleteRoleSkill*)in;

	pStream->delete_item("skill");
	pStream->where_item();
	pStream->write_string("role_id=") << xProtocol->dw_role_id;
	pStream->write_string(" and id=") << xProtocol->dw_skill_id;
	ret = m_p_db_interface->sql_execute(pStream);
	if(!ret) goto EXIT;

EXIT:
	m_p_db_interface->return_io(pStream);
	return ret;
}