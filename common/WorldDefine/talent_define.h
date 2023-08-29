//-----------------------------------------------------------------------------
//��Name				:   talent_define.h
//��Compiler			:	Microsoft Visual C++ 9.0Aslan
//��Version				:	1.00
//��Create Date			:	2008-10-20
//��LastModified		:	
//��Brief				:	��������̬����
//-----------------------------------------------------------------------------
#pragma once

#include "RoleDefine.h"

#pragma pack(push, 1)

//-----------------------------------------------------------------------------
// CONSTS
//-----------------------------------------------------------------------------
const INT32 X_MAX_TALENT_PER_ROLE		=		4;		// һ����ҿ���࿪������������
const INT32 X_MAIN_TALENT_START			=		0;		// �����ʵ���ʼλ�ã�0
const INT32	X_ASS_TALENT_START			=		2;		// �������ʵ���ʼλ�ã�2


//-----------------------------------------------------------------------------
// ���ʽṹ
//-----------------------------------------------------------------------------
struct tagRoleTalent
{
	ETalentType		eType;		// ��������
	INT32			nPoint;		// �����ʵ���Ͷ����
};

#pragma pack(pop)