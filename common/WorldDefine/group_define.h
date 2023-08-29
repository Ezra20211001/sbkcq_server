//-----------------------------------------------------------------------------
//��Name				:   group_define.h
//��Version				:	1.00
//��Create Date			:	2008-11-20
//��Brief				:	�������Զ���
//-----------------------------------------------------------------------------
#pragma once

#include "..\WorldDefine\ItemDefine.h"

//------------------------------------------------------------------------
// ����ʰȡ����
//------------------------------------------------------------------------

const INT      MAX_TEAM_NUM					= 5;		// С���������
const DWORD    TEAM_SYN_TICK				= TICK_PER_SECOND * 5;
const DWORD    TEAM_DISPLAY_NUM				= 9;
const DWORD	   MAX_TEAM_PLACARD_LEN			= 20;		// ���鹫����󳤶�

enum EPickMode
{
	EPUM_Free,										// ����ʰȡ
	EPUM_Sice,										// ����ʰȡ
	EPUM_Leader,									// �ӳ�ʰȡ
};

enum EPickSiceMode
{
	EPSM_Null	= 0,		// ��������
	EPSM_Greed	= 1,		// ̰������
	EPSM_Require = 2,		// ��������
};

enum EGTAssignState
{
	EGTAS_Null					= 0,	//���÷���
	EGTAS_WaitForUmpirage		= 1,
	EGTAS_WaitForLeaderAssign	= 2,	//�ȴ��ӳ�����
	EGTAS_WaitForSice			= 3,	//�ȴ��������
	EGTAS_AssignFinish			= 4,	//�þ�������Ҫ����
};

struct tagLeaderRein
{
	INT				nLeaderRein;					// �ӳ�ͳ����
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
	EClassType		eClassEx;		// ְҵ
	BYTE		    bySex;
	INT				nLevel;
	DWORD			dwEquipTypeID[TEAM_DISPLAY_NUM];	
	tagAvatarAtt	AvatarAtt;
	tagEquipTeamInfo stEquipTeamInfo;
};

struct tagTeamMemberData
{
	DWORD			dw_role_id;		// ���ID
	DWORD			dwMapID;
	EClassType		eClassEx;		// ְҵ
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
// ��ͼ�ڶ�����Ϣ    add by gtj  10.11.09
//--------------------------------------------------------------
struct tagMapTeamInfo
{
	DWORD			LeaderID;
	INT				nLevel;
	EClassType    	eClassEx;
	INT				nTeamMemberNum;
	TCHAR			szTeamPlacard[MAX_TEAM_PLACARD_LEN];
};
//���ͷ������ͶƱ
struct tagAssignNotice
{
	EPickMode ePickMode;
	DWORD	dwMapID;
	DWORD	dwTeamID;
	INT64	n64GroundID;
};
//֪ͨͶƱ����/ͶƱ��ʱ
struct tagAssignFinish
{
	DWORD dwTeamID;
	INT64 n64GroundID;
};
// ͶƱ���
struct tagSiceResult
{
	DWORD dw_role_id;
	BYTE  byType;
	BYTE  byScore;
};