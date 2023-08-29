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


//!����
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
//!�̶����ʼ����ʱ��
struct s_act_time
{
	INT				nWeek;						
	tagDWORDTime	star_time;					// !��ʼʱ��
	tagDWORDTime	end_time;					// !����ʱ��
	BYTE			by_start_broad_h;			// !�㲥��ʼ��ʱ�䣨Сʱ��
	BYTE			by_start_broad_m;			// !�㲥��ʼ��ʱ�䣨���ӣ�
	BYTE			by_interval;				// !�㲥��ʱ����
	BYTE			by_end_broad_h;				// !�㲥������ʱ�䣨Сʱ��
	BYTE			by_end_broad_m;				// !�㲥������ʱ�䣨���ӣ�
};

struct s_act_info
{
	DWORD			dw_id;						// !�ID
	e_act_mod		e_act_mode;					// !�����
	DWORD			dw_map_id;					// !���ͼID
	s_act_time		act_time;					// !�̶��ʱ��
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



