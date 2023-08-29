//-----------------------------------------------------------------------------
//��Name				:   func_npc_define.h
//��Compiler			:	Microsoft Visual C++ 9.0
//��Version				:	1.00
//��Create Date			:	2008-11-10
//��LastModified		:	
//��Brief				:	ְ��NPC���ԭ�Ͷ���
//-----------------------------------------------------------------------------
#pragma once

#include "cost_type_define.h"

/****************************** ��վ&Ǭ��ʯ��� *****************************/

//-----------------------------------------------------------------------------
// ����
//-----------------------------------------------------------------------------
const INT32 MAX_DAK_SITE_NUM		= 20;	// ��վ�ܹ����͵���Ŀ�ĵظ���

//-----------------------------------------------------------------------------
// �ṹ
//-----------------------------------------------------------------------------
struct tagDakSite
{
	DWORD			dwMapID;	// map���
	DWORD			dwWayPointID;
	ECurCostType	eCostType;	// ��������
	INT32			nCostVal;	// ����ֵ

	tagDakSite() { ZeroMemory(this, sizeof(*this)); dwMapID = INVALID_VALUE; }
};

struct tagDakProto
{
	DWORD		dwID;		// ��վ���
	tagDakSite	dakSite[MAX_DAK_SITE_NUM];
};