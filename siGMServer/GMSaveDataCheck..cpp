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
 *	@file		GMSaveDataCheck.
 *	@author		mwh
 *	@date		2011/09/01	initial
 *	@version	0.0.1.0
 *	@brief		���洢������
*/
#include "StdAfx.h"
#include "GMSaveDataCheck.h"

//! ��ֵ�жϺ�
#define NumberInRange(Var,MinV,OPMin,MaxV,OPMax,OPConnect,Ret) \
	if((((Var) OPMin (MinV))) OPConnect (((Var) OPMax (MaxV)))) return (Ret);

#define NumberNotInRange(Var,MinV,OPMin,MaxV,OPMax,OPConnect,Ret) \
	if(!((((Var) OPMin (MinV))) OPConnect (((Var) OPMax (MaxV))))) return (Ret);

#define NumberCompare(Var,OP,Val,Ret)\
	if(((Var) OP (Val))) return (Ret);

#define NumberCompareNot(Var,OP,Val,Ret)\
	if(!((Var) OP (Val))) return (Ret);

//! ����ɫ���������޸�
BOOL GMSaveDataChecker::Check(tag_role_basic_save* pSave)
{
	NumberCompare(pSave->n_cur_exp, <, 0, FALSE);
	//NumberCompare(pSave->n_level, <, 1, FALSE);
	//NumberCompare(pSave->n_level, >, 80, FALSE);
	//NumberCompare(pSave->n_pk, <, 0, FALSE);
	//NumberCompare(pSave->n_pk, >, 100, FALSE);
	NumberCompare(pSave->n_bag_silver, <, 0, FALSE);
	NumberCompare(pSave->n_bag_silver, >=, 1000, FALSE);
	NumberCompare(pSave->n_bag_copper, <, 0, FALSE);
	NumberCompare(pSave->n_bag_copper, >=, 1000, FALSE);

	NumberCompare(pSave->dw_bindyuanbao, <, 0, FALSE);
	NumberCompare(pSave->dw_bindyuanbao, >=, 1000, FALSE);
	//NumberCompare(pSave->n_bag_bind_silver, <, 0, FALSE);
	//NumberCompare(pSave->n_bag_bind_silver, >=, 1000, FALSE);
	//NumberCompare(pSave->n_bag_bind_copper, <, 0, FALSE);
	//NumberCompare(pSave->n_bag_bind_copper, >=, 1000, FALSE);
	//NumberCompare(pSave->n_ware_silver, <, 0, FALSE);
	//NumberCompare(pSave->n_ware_silver, >=, 1000, FALSE);
	//NumberCompare(pSave->n_ware_copper, <, 0, FALSE);
	//NumberCompare(pSave->n_ware_copper, >=, 1000, FALSE);

	return TRUE;
}

//! ����ɫ�����޸�
BOOL GMSaveDataChecker::Check(tag_role_skill_save* pSkill)
{
	NumberCompare(pSkill->nSkillLevel, <, 1, FALSE);
	NumberCompare(pSkill->nSkillID, <, 10000, FALSE);
	NumberCompare(pSkill->nSkillID, >, 99999, FALSE);
	return TRUE;
}

//! �������޸�
BOOL GMSaveDataChecker::Check(tag_role_pet_save* pPet)
{
	return TRUE;
}

//! ���װ���޸�
BOOL GMSaveDataChecker::Check(tag_equip_save* pEquip)
{
	return TRUE;
}

//! װ������
BOOL GMSaveDataChecker::Check(tag_equip_create* pEquip)
{
	return TRUE;
}