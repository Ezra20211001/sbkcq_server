/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef _ACTIVITY_DEFINE_H_
#define _ACTIVITY_DEFINE_H_

#pragma pack(push, 1)


//!活动类别
enum e_act_mod
{
// 	eam_day,				
// 	eam_week,				
// 	eam_month,				
// 	eam_festival,
	//
	EAM_PERSIST,
	EAM_WEEK,
};

enum e_week_day
{
	ew_sunday = 0,
	ew_monday,
	ew_tuesday,
	ew_wednesday,
	ew_thursday,
	ew_friday,
	ew_saturday,
};
//!固定活动开始结束时间
struct s_act_time
{
	INT				nWeek;						
	tagDWORDTime	star_time;					// !开始时间
	tagDWORDTime	end_time;					// !结束时间
	BYTE			by_start_broad_h;			// !广播开始的时间（小时）
	BYTE			by_start_broad_m;			// !广播开始的时间（分钟）
	BYTE			by_interval;				// !广播的时间间隔
	BYTE			by_end_broad_h;				// !广播结束的时间（小时）
	BYTE			by_end_broad_m;				// !广播结束的时间（分钟）
};

struct s_act_info
{
	DWORD			dw_id;						// !活动ID
	e_act_mod		e_act_mode;					// !活动类型
	DWORD			dw_map_id;					// !活动地图ID
	s_act_time		act_time;					// !固定活动时间
	BYTE			by_start_h;
	BYTE			by_start_m;
	BYTE			by_end_h;
	BYTE			by_end_m;
	INT			min_level;
	INT			max_level;
	BOOL		b_sign;
	
};

#pragma pack(pop)

#endif



