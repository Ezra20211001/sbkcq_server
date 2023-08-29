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
 *	@file		GMSaveDataCheck
 *	@author		mwh
 *	@date		2011/09/01	initial
 *	@version	0.0.1.0
 *	@brief		GM Edit Tool's Data Checker
*/

#ifndef __GM_SAVE_DATA_CHECK_H__
#define __GM_SAVE_DATA_CHECK_H__

#include "../common/WorldDefine/GMDefine.h"

//! 我们只能做简单的检查
class GMSaveDataChecker
{
public:
	static GMSaveDataChecker& Instance()
	{
		static GMSaveDataChecker _InnerOBJ;
		return _InnerOBJ;
	}
public:
	template<typename T>
	BOOL CheckDelegate(T* );
private:
	BOOL Check(tag_role_basic_save* pSave);
	BOOL Check(tag_role_skill_save* pSkill);
	BOOL Check(tag_role_pet_save* pPet);
	BOOL Check(tag_equip_save* pEquip);
	BOOL Check(tag_equip_create* pEquip);
	// 暂时注释这个，让编译器做检查
	// BOOL Check(VOID* pVoid){return TRUE;};
private:
	GMSaveDataChecker(){};
	~GMSaveDataChecker(){};
	GMSaveDataChecker& operator=(const GMSaveDataChecker&);
};

template<typename T>
inline BOOL GMSaveDataChecker::CheckDelegate(T*  pData)
{
	return Check(pData);
}

#ifndef EditToolDataCheck
	#define EditToolDataCheck GMSaveDataChecker::Instance().CheckDelegate
#endif // EditToolDataCheck

#endif // __GM_SAVE_DATA_CHECK_H__