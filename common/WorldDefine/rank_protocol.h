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
*	@file		rank_protocol.h
*	@author		lc
*	@date		2010/12/21	initial
*	@version	0.0.1.0
*	@brief		排行榜消息
*/

#ifndef RANK_PROTOCOL
#define RANK_PROTOCOL

#include "../WorldDefine/rank_define.h"
#include "../WorldDefine/ItemDefine.h"

#pragma pack(push, 1)

// 获取等级排行榜
struct NET_SIC_get_level_rank : public tag_net_message
{
	NET_SIC_get_level_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_level_rank");
		dw_size = sizeof(NET_SIC_get_level_rank);
	}
};

struct NET_SIS_get_level_rank : public tag_net_message
{
	NET_SIS_get_level_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_level_rank");
		dw_size = sizeof(NET_SIS_get_level_rank);
	}
	INT		n_num;
	tagLevelRankInfo st_LevelRank[100];
};

struct NET_SIS_get_level_rand_result : public tag_net_message
{
	NET_SIS_get_level_rand_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_level_rand_result");
		dw_size = sizeof(NET_SIS_get_level_rand_result);
	}
	DWORD	dwError;
};

// 获取恶人排行榜
struct NET_SIC_get_skill_rank : public tag_net_message
{
	NET_SIC_get_skill_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_skill_rank");
		dw_size = sizeof(NET_SIC_get_skill_rank);
	}
};

struct NET_SIS_get_skill_rank : public tag_net_message
{
	NET_SIS_get_skill_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_skill_rank");
		dw_size = sizeof(NET_SIS_get_skill_rank);
	}
	INT		n_num;
	tagKillRankInfo st_KillRank[100];
};

struct NET_SIS_get_skill_rank_result : public tag_net_message
{
	NET_SIS_get_skill_rank_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_skill_rank_result");
		dw_size = sizeof(NET_SIS_get_skill_rank_result);
	}
	DWORD	dwError;
};

// 获取魅力排行榜
struct NET_SIC_get_meili_rank : public tag_net_message
{
	NET_SIC_get_meili_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_meili_rank");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_meili_rank : public tag_net_message
{
	NET_SIS_get_meili_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_meili_rank");
		dw_size = sizeof(*this);
	}
	INT		n_num;
	tagmeiliRankInfo st_ShihunRank[100];
	DWORD   dw_shihun;
};

struct NET_SIS_get_meili_rank_result : public tag_net_message
{
	NET_SIS_get_meili_rank_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_meili_rank_result");
		dw_size = sizeof(*this);
	}
	DWORD dw_error;
};

// 获取成就
struct NET_SIC_get_ach_point_rank : public tag_net_message
{
	NET_SIC_get_ach_point_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_ach_point_rank");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_ach_point_rank : public tag_net_message
{
	NET_SIS_get_ach_point_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_ach_point_rank");
		dw_size = sizeof(*this);
	}
	INT		n_num;
	tagAchPointRankInfo st_achpointRank[100];
	DWORD   dw_point;
};

struct NET_SIS_get_ach_point_rank_result : public tag_net_message
{
	NET_SIS_get_ach_point_rank_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_ach_point_rank_result");
		dw_size = sizeof(*this);
	}
	DWORD dw_error;
};

struct NET_SIC_get_ach_number_rank : public tag_net_message
{
	NET_SIC_get_ach_number_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_ach_number_rank");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_ach_number_rank : public tag_net_message
{
	NET_SIS_get_ach_number_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_ach_number_rank");
		dw_size = sizeof(*this);
	}
	INT		n_num;
	tagAchNumberRankInfo st_achnumberRank[100];
	DWORD   dw_number;
};

struct NET_SIS_get_ach_number_rank_result : public tag_net_message
{
	NET_SIS_get_ach_number_rank_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_ach_number_rank_result");
		dw_size = sizeof(*this);
	}
	DWORD dw_error;
};


// 获取正义榜
struct NET_SIC_get_justice_rank : public tag_net_message
{
	NET_SIC_get_justice_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_justice_rank");
		dw_size = sizeof(*this);
	}
};


struct NET_SIS_get_justice_rank : public tag_net_message
{
	NET_SIS_get_justice_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_justice_rank");
		dw_size = sizeof(*this);
	}
	INT n_num;
	tagJusticeRankInfo st_JusticeRank[100];
};

struct NET_SIS_get_justice_rank_result : public tag_net_message
{
	NET_SIS_get_justice_rank_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_justice_rank_result");
		dw_size = sizeof(*this);
	}
	DWORD	dwError;
};

struct NET_SIS_justice_newvalue : public tag_net_message
{
	NET_SIS_justice_newvalue()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_justice_newvalue");
		dw_size = sizeof(*this);
	}
	DWORD dwRoleID;
	INT32 nJustice;
};

// 获取装备排行榜
struct NET_SIC_get_equip_rank : public tag_net_message
{
	NET_SIC_get_equip_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_equip_rank");
		dw_size = sizeof(NET_SIC_get_equip_rank);
	}
};

struct NET_SIS_get_equip_rank : public tag_net_message
{
	NET_SIS_get_equip_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_equip_rank");
		dw_size = sizeof(NET_SIS_get_equip_rank);
	}
	INT		n_num;
	tagEquipRankInfo	st_EquipRank[100];
};

struct NET_SIS_get_equip_rank_result : public tag_net_message
{
	NET_SIS_get_equip_rank_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_equip_rank_result");
		dw_size = sizeof(NET_SIS_get_equip_rank_result);
	}
	DWORD		dwError;
};

struct NET_SIS_equip_view_info : public tag_net_message
{
	NET_SIS_equip_view_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_view_info");
		dw_size = sizeof(NET_SIS_equip_view_info);
	}
	INT n_num;
	tagEquipViewInfo st_EquipViewInfo[100];
};

// 获取帮会排行榜
struct NET_SIC_get_guild_rank : public tag_net_message
{
	NET_SIC_get_guild_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_rank");
		dw_size = sizeof(NET_SIC_get_guild_rank);
	}
};

struct NET_SIS_get_guild_rank : public tag_net_message
{
	NET_SIS_get_guild_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_rank");
		dw_size = sizeof(NET_SIS_get_guild_rank);
	}
	INT n_num;
	tagGuildRankInfo st_GuildRank[100];
};

struct NET_SIS_get_guild_rank_result : public tag_net_message
{
	NET_SIS_get_guild_rank_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_rank_result");
		dw_size = sizeof(NET_SIS_get_guild_rank_result);
	}
	DWORD		dwError;
};

// 获取1v1排行榜
struct NET_SIC_get_1v1_rank : public tag_net_message
{
	NET_SIC_get_1v1_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_1v1_rank");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_1v1_rank : public tag_net_message
{
	NET_SIS_get_1v1_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_1v1_rank");
		dw_size = sizeof(*this);
	}
	INT n_num;
	tag1v1RankInfo st_1v1ScoreRank[100];
};

struct NET_SIS_get_1v1_rank_result : public tag_net_message
{
	NET_SIS_get_1v1_rank_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_1v1_rank_result");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

// 发送雕像名字
struct NET_SIS_get_diaoxiang_name : public tag_net_message
{
	NET_SIS_get_diaoxiang_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_diaoxiang_name");
		dw_size = sizeof(*this);
	}
	
	TCHAR	szDiaoName[6][X_SHORT_NAME];
};
//gx add 师徒榜
// 获取师徒排行榜
struct NET_SIC_get_master_rank : public tag_net_message
{
	NET_SIC_get_master_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_master_rank");
		dw_size = sizeof(NET_SIC_get_master_rank);
	}
};
struct NET_SIS_get_master_rank : public tag_net_message
{
	NET_SIS_get_master_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_master_rank");
		dw_size = sizeof(NET_SIS_get_master_rank);
	}
	INT		n_num;
	tagMasterGraduateRankInfo st_MasterRank[100];
};

struct NET_SIS_get_master_rand_result : public tag_net_message
{
	NET_SIS_get_master_rand_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_master_rand_result");
		dw_size = sizeof(NET_SIS_get_master_rand_result);
	}
	DWORD	dwError;
};
#pragma pack(pop)
#endif
