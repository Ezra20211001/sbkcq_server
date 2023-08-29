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
*	@file		rank_define.h
*	@author		liuchi
*	@date		2010/12/21	initial
*	@version	0.0.1.0
*	@brief		排行榜结构定义
*/

#pragma once


#define FIRSTLEVLETITLE 0

#define FIRSTZHANSHI 3
#define FIRSTFASHI 4
#define FIRSTDAOSHI 5

#define OTHERZHANSHI 8
#define OTHERFASHI 9
#define OTHERDAOSHI 10

#define FIRSTNAN 6
#define FIRSTNV 7
//gx add 2013.12.10
#define MASTERRANK1 19  //一代宗师
#define MASTERRANK2 20	//举世皆知
#define MASTERRANK3 21	//闻名遐迩
#define MASTERRANK4 22	//德高望重
//end
#pragma pack(push, 1)

struct tagLevelRankInfo
{
	DWORD			dw_role_id;			// 人物ID
	INT				nLevel;				// 人物等级
	EClassType		eClass;				// 职业
	DWORD			dwGuildID;			// 帮会ID
};

struct tagEquipRankInfo
{
	DWORD	dw_data_id;				// 物品ID
	INT		nLevel;					// 等级
	INT		nScore;					// 分数
	DWORD	dw_role_id;				// 所有者
};

struct tagGuildRankInfo
{
	DWORD	dwGuildID;			// 帮会ID
	INT		nLevel;				// 帮会等级
	INT		nProsperity;		// 帮会资金
	DWORD	dwLeaderID;			// 帮主ID
};

struct tagKillRankInfo
{
	DWORD	dw_role_id;
	INT		nLevel;
	INT		nKillNum;
	DWORD	dwGuildID;
};

struct tagJusticeRankInfo
{
	DWORD		dw_role_id;		// 角色id
	INT			nLevel;			// 等级
	INT32		n32Justice;		// 战力
	EClassType	e_class;		// 职业
};

struct tag1v1RankInfo
{
	DWORD	dw_role_id;
	INT		nLevel;
	EClassType e_class;
	INT		nScore;
};


struct tagmeiliRankInfo
{
	DWORD		dw_role_id;
	INT			n_level_;
	EClassType		e_class;
	DWORD		dw_shihun;
	BYTE		by_sex;
};

struct tagAchPointRankInfo
{
	DWORD		dw_role_id;
	INT			n_level_;
	DWORD		dw_point;
};

struct tagAchNumberRankInfo
{
	DWORD		dw_role_id;
	INT			n_level_;
	DWORD		dw_number;
};
struct tagMasterGraduateRankInfo
{
	DWORD dw_role_id;
	INT n_Graduates;//出师人数
	INT			n_level_;
	EClassType		e_class;
	BYTE		by_Sex;
	BYTE		by_online;
};
#pragma pack(pop)