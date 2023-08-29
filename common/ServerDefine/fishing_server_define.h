/*******************************************************************************

	Copyright 2010 by Shengshi Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	Shengshi Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	Shengshi Interactive  Co., Ltd.

*******************************************************************************/

/**
 *	@file		fishing_server_define
 *	@author		mwh
 *	@date		2011/06/28	initial
 *	@version	0.0.1.0
 *	@brief		钓鱼定义
*/

#ifndef __FISHING_SERVER_DEFINE_H__
#define __FISHING_SERVER_DEFINE_H__
#pragma pack(push,1)

struct tagFishItem
{
	DWORD dwItemID;					// TYPEID
	DWORD dwItemProb;				// 概率
	DWORD dwSkillProficiency;		// 需求技能熟练度
};

struct tagNpcFishingProto
{
	INT nMinLevel;					// 最小等级
	INT nSkillLevel;					// 最小技能等级
	DWORD dwID;						// 地图名CRC
	DWORD dwNullGetProb;			// 掉空几率
	std::vector<tagFishItem> outs;	// 鱼
	std::vector<tagFishItem> outs_sp; // 特殊鱼
};

#pragma pack(pop)
#endif // __FISHING_SERVER_DEFINE_H__
