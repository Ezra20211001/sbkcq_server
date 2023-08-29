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
*	@file		achievement_protocol.h
*	@author		lc
*	@date		2011/07/21	initial
*	@version	0.0.1.0
*	@brief		成就系统消息
*/

#ifndef _ACHIVEEMENT_PROTOCOL_H_
#define	_ACHIVEEMENT_PROTOCOL_H_


//#include "achievement_define.h"

#pragma pack(push, 1)


// 已完成的成就
struct tagCompletedAchievementData
{
	DWORD	ID;				// 成就id
	DWORD	date;			// 完成时间
};

// 条件消息结构
struct tagCriteriaProgress
{
	DWORD	ID;				// 条件id
	DWORD	date;			// 时间
	DWORD	counter;		// 计数
};


//! 初始化已完成成就列表
struct NET_SIS_init_achievement : public tag_net_message
{
	NET_SIS_init_achievement()
	{ 
		ZeroMemory(this, sizeof(*this)); 
		dw_message_id = message_id_crc("NET_SIS_init_achievement");
		dw_size = sizeof(NET_SIS_init_achievement);
	}
	INT		n_num;		  // 数量
	tagCompletedAchievementData	completeAchData[1];
};

//! 初始化成就条件列表
struct NET_SIS_init_achievement_criteria : public tag_net_message
{
	NET_SIS_init_achievement_criteria()
	{ 
		ZeroMemory(this, sizeof(*this)); 
		dw_message_id = message_id_crc("NET_SIS_init_achievement_criteria");
		dw_size = sizeof(NET_SIS_init_achievement_criteria);
	}
	INT		n_num;		  // 数量
	tagCriteriaProgress	criteriaProgress[1];
};


//! 完成某个成就
struct NET_SIS_complate_achievement : public tag_net_message
{
	NET_SIS_complate_achievement()
	{ 
		ZeroMemory(this, sizeof(*this)); 
		dw_message_id = message_id_crc("NET_SIS_complate_achievement");
		dw_size = sizeof(NET_SIS_complate_achievement);
	}
	DWORD dw_id;		  // id
	DWORD dw_date;		  // 完成时间
};

//! 成就进度更新
struct NET_SIS_updata_achievement_progress : public tag_net_message
{
	NET_SIS_updata_achievement_progress()
	{ 
		ZeroMemory(this, sizeof(*this)); 
		dw_message_id = message_id_crc("NET_SIS_updata_achievement_progress");
		dw_size = sizeof(NET_SIS_updata_achievement_progress);
	}
	DWORD dw_id;		// id
	DWORD dw_count;		// 计数
	BOOL b_fail;		// 是否失败
};


// !成就点数改变
struct NET_SIS_achievement_point_change : public tag_net_message
{
	NET_SIS_achievement_point_change()
	{ 
		ZeroMemory(this, sizeof(*this)); 
		dw_message_id = message_id_crc("NET_SIS_achievement_point_change");
		dw_size = sizeof(NET_SIS_achievement_point_change);
	}
	INT nNewValue;	//新的值
};

#pragma pack(pop)


#endif