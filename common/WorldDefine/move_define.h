#pragma once

#pragma pack(push, 1)

//--------------------------------------------------------------------
// �ƶ�״̬
//--------------------------------------------------------------------
enum EMoveState
{
	EMS_Stand			= 0,					// վ��
	EMS_Walk			= 1,					// ����
	EMS_Fear			= 8,					// �־�����

	EMS_CreaturePatrol	= 9,					// ����Ѳ��
	EMS_CreatureWalk	= 10,					// ��������
	EMS_CreatureFlee	= 11,					// ��������
	EMS_CreatureRun		= 12,					// �����ܲ�
	EMS_HitFly			= 13,					// ����
};

// ���߷���
enum EWalkDir
{
	EWalkDir_Left,
	EWalkDir_Right,
	EWalkDir_Front,
	EWalkDir_Back,
	EWalkDir_LeftFront,
	EWalkDir_LeftBack,
	EWalkDir_RightFront,
	EWalkDir_RightBack
};

//---------------------------------------------------------------------
// �����ƶ�����
//---------------------------------------------------------------------
enum ESpecialMoveType
{
	ESMT_Repel,			// ����
	ESMT_Assault,		// ���
	ESMT_Teleport,		// ˲��
	ESMT_Pull,          // ��ק
};

//---------------------------------------------------------------------
// �ٶȳ���
//---------------------------------------------------------------------
const FLOAT X_DEF_XZ_SPEED			=	180.0f;						// XZ�����ٶ�
const FLOAT X_DEF_Y_SPEED			=	680.0f;						// Y�����ٶ�
const FLOAT X_DEF_DROP_XZ_SPEED		=	250.0f;						// ����ʱ��XZ�����ٶ�
const FLOAT X_DEF_SLIDE_SPEED		=	600.0f;						// ����ʱ���ٶ�
const FLOAT X_DEF_HIT_FLY_XZ_SPEED	=	800.0f;						// ����ʱXZ�����ٶ�
const FLOAT X_DEF_HIT_FLY_Y_SPEED	=	800.0f;						// ����ʱY�����ٶ�
const FLOAT X_DEF_REPEL_SPEED		=	X_DEF_XZ_SPEED * 2.0f;		// �����ٶ�
const FLOAT X_DEF_ASSAULT_SPEED		=	X_DEF_XZ_SPEED * 5.0f;		// ����ٶ�
const FLOAT X_DEF_PULL_SPEED		=	X_DEF_XZ_SPEED * 5.0f;		// ��ק�ٶ�


//---------------------------------------------------------------------
// ����Ĭ�ϰ����д�С
//---------------------------------------------------------------------
const FLOAT X_DEF_ROLE_SIZE_X		=	85.0f;			// X��С
const FLOAT X_DEF_ROLE_SIZE_Y		=	175.0f;			// Y��С
const FLOAT X_DEF_ROLE_SIZE_Z		=	85.0f;			// Z��С

//---------------------------------------------------------------------
// ����Ĭ�ϰ����д�С
//---------------------------------------------------------------------
const FLOAT X_DEF_CREATURE_SIZE_X	=	50.0f;			// X��С
const FLOAT X_DEF_CREATURE_SIZE_Y	=	50.0f;			// Y��С
const FLOAT X_DEF_CREATURE_SIZE_Z	=	50.0f;			// Z��С


#pragma pack(pop)