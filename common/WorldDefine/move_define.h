#pragma once

#pragma pack(push, 1)

//--------------------------------------------------------------------
// 移动状态
//--------------------------------------------------------------------
enum EMoveState
{
	EMS_Stand			= 0,					// 站立
	EMS_Walk			= 1,					// 行走
	EMS_Fear			= 8,					// 恐惧逃跑

	EMS_CreaturePatrol	= 9,					// 怪物巡逻
	EMS_CreatureWalk	= 10,					// 怪物行走
	EMS_CreatureFlee	= 11,					// 怪物逃跑
	EMS_CreatureRun		= 12,					// 怪物跑步
	EMS_HitFly			= 13,					// 击飞
};

// 行走方向
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
// 特殊移动类型
//---------------------------------------------------------------------
enum ESpecialMoveType
{
	ESMT_Repel,			// 击退
	ESMT_Assault,		// 冲锋
	ESMT_Teleport,		// 瞬移
	ESMT_Pull,          // 拖拽
};

//---------------------------------------------------------------------
// 速度常量
//---------------------------------------------------------------------
const FLOAT X_DEF_XZ_SPEED			=	180.0f;						// XZ方向速度
const FLOAT X_DEF_Y_SPEED			=	680.0f;						// Y方向速度
const FLOAT X_DEF_DROP_XZ_SPEED		=	250.0f;						// 掉落时的XZ方向速度
const FLOAT X_DEF_SLIDE_SPEED		=	600.0f;						// 滑落时的速度
const FLOAT X_DEF_HIT_FLY_XZ_SPEED	=	800.0f;						// 击飞时XZ方向速度
const FLOAT X_DEF_HIT_FLY_Y_SPEED	=	800.0f;						// 击飞时Y方向速度
const FLOAT X_DEF_REPEL_SPEED		=	X_DEF_XZ_SPEED * 2.0f;		// 击退速度
const FLOAT X_DEF_ASSAULT_SPEED		=	X_DEF_XZ_SPEED * 5.0f;		// 冲锋速度
const FLOAT X_DEF_PULL_SPEED		=	X_DEF_XZ_SPEED * 5.0f;		// 拖拽速度


//---------------------------------------------------------------------
// 人物默认包裹盒大小
//---------------------------------------------------------------------
const FLOAT X_DEF_ROLE_SIZE_X		=	85.0f;			// X大小
const FLOAT X_DEF_ROLE_SIZE_Y		=	175.0f;			// Y大小
const FLOAT X_DEF_ROLE_SIZE_Z		=	85.0f;			// Z大小

//---------------------------------------------------------------------
// 怪物默认包裹盒大小
//---------------------------------------------------------------------
const FLOAT X_DEF_CREATURE_SIZE_X	=	50.0f;			// X大小
const FLOAT X_DEF_CREATURE_SIZE_Y	=	50.0f;			// Y大小
const FLOAT X_DEF_CREATURE_SIZE_Z	=	50.0f;			// Z大小


#pragma pack(pop)
