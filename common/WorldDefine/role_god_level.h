#pragma once

#include "RoleDefine.h"

#pragma pack(push, 1)

// 错误码
enum 
{
	E_GOD_LEVEL_UP_IS_ZERO	=	1,	// 0级不能升级
	E_GOD_LEVEL_NOT_PROTO	=	2,	// 该等级不存在或达到最大了
	E_GOD_LEVEL_UP_NOT_CON	=	3,	// 升级条件不符
};


// 条件类型
enum E_GOD_LEVEL_CONDITION
{
	EGLC_ROLE_LEVEL			= 0,		// 角色等级
	EGLC_WEAPON_LEVEL		= 1,		// 武器等级
	EGLC_HUIZHANG_LEVEL		= 2,		// 徽章等级
	EGLC_YAPPEI_LEVEL		= 3,		// 腰佩等级
	EGLC_PET_LEVEL			= 4,		// 宠物等级
	EGLC_HUENLIAN_TIME		= 5,		// 魂练次数
	EGLC_HUENJIN_LEVEL		= 6,		// 魂精等级

	EGLC_NUM			
};

// 提升神级条件
struct tagGodLevelProto
{
	INT		nID;	
	INT		nCondition[EGLC_NUM];	//条件
	DWORD	dwSkill[5][2];				//学习的技能
};


//////////////////////////////////////////////////////////////////////////////////////////////
//提升神级
struct NET_SIC_god_level_up : public tag_net_message
{
	NET_SIC_god_level_up()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_god_level_up");
		dw_size = sizeof(NET_SIC_god_level_up);
	}
};

struct NET_SIS_god_level_up : public tag_net_message
{
	NET_SIS_god_level_up()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_god_level_up");
		dw_size = sizeof(NET_SIS_god_level_up);
	}
	INT		nLevel;
	DWORD dw_error_code;
};

struct NET_SIS_god_level_update : public tag_net_message
{
	NET_SIS_god_level_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_god_level_update");
		dw_size = sizeof(NET_SIS_god_level_update);
	}
	INT		nLevel;
};


#pragma pack(pop)