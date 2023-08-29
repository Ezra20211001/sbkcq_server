//-----------------------------------------------------------------------------
//★Name				:   group_define.h
//★Version				:	1.00
//★Create Date			:	2008-11-20
//★Brief				:	队伍属性定义
//-----------------------------------------------------------------------------
#pragma once

#include "..\WorldDefine\ItemDefine.h"

//------------------------------------------------------------------------
// 队伍拾取规则
//------------------------------------------------------------------------

const INT      MAX_TEAM_NUM					= 5;		// 小队最大人数
const DWORD    TEAM_SYN_TICK				= TICK_PER_SECOND * 5;
const DWORD    TEAM_DISPLAY_NUM				= 9;
const DWORD	   MAX_TEAM_PLACARD_LEN			= 20;		// 队伍公告最大长度

enum EPickMode
{
	EPUM_Free,										// 自由拾取
	EPUM_Sice,										// 掷骰拾取
	EPUM_Leader,									// 队长拾取
};

enum EPickSiceMode
{
	EPSM_Null	= 0,		// 不需掷骰
	EPSM_Greed	= 1,		// 贪婪掷骰
	EPSM_Require = 2,		// 需求掷骰
};

enum EGTAssignState
{
	EGTAS_Null					= 0,	//不用分配
	EGTAS_WaitForUmpirage		= 1,
	EGTAS_WaitForLeaderAssign	= 2,	//等待队长分配
	EGTAS_WaitForSice			= 3,	//等待大家掷骰
	EGTAS_AssignFinish			= 4,	//裁决结束需要发送
};

struct tagLeaderRein
{
	INT				nLeaderRein;					// 队长统御力
};

struct tagAllRoleBuff
{
	DWORD			dwBuffTypeID;							
};

struct tagCreateTeam
{
	DWORD			dwSrcRoleID;
	DWORD			dwDesRoleID;
};

struct tagAddTeamMember
{
	DWORD			dwTeamID;
	DWORD			dwDesRoleID;
};

struct tagApplyRoleData
{
	DWORD			dw_role_id;
	EClassType		eClassEx;		// 职业
	BYTE		    bySex;
	INT				nLevel;
	DWORD			dwEquipTypeID[TEAM_DISPLAY_NUM];	
	tagAvatarAtt	AvatarAtt;
	tagEquipTeamInfo stEquipTeamInfo;
};

struct tagTeamMemberData
{
	DWORD			dw_role_id;		// 玩家ID
	DWORD			dwMapID;
	EClassType		eClassEx;		// 职业
	BYTE		    bySex;
	INT				nLevel;
	INT				nMaxHP;
	INT				nHP;
	INT				nMaxMP;
	INT				nMP;
	FLOAT			fX;
	FLOAT			fZ;
	DWORD			dwEquipTypeID[TEAM_DISPLAY_NUM];	
	tagAvatarAtt	AvatarAtt;
	tagEquipTeamInfo st_EquipTeamInfo;
};

//--------------------------------------------------------------
// 地图内队伍信息    add by gtj  10.11.09
//--------------------------------------------------------------
struct tagMapTeamInfo
{
	DWORD			LeaderID;
	INT				nLevel;
	EClassType    	eClassEx;
	INT				nTeamMemberNum;
	TCHAR			szTeamPlacard[MAX_TEAM_PLACARD_LEN];
};
//发送分配或者投票
struct tagAssignNotice
{
	EPickMode ePickMode;
	DWORD	dwMapID;
	DWORD	dwTeamID;
	INT64	n64GroundID;
};
//通知投票结束/投票超时
struct tagAssignFinish
{
	DWORD dwTeamID;
	INT64 n64GroundID;
};
// 投票结果
struct tagSiceResult
{
	DWORD dw_role_id;
	BYTE  byType;
	BYTE  byScore;
};