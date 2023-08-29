/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

******************************************************************************/

/**
*	@file		function_npc_protocol.h
*	@author		lc
*	@date		2011/03/03	initial
*	@version	0.0.1.0
*	@brief		npc职能消息
*/


#ifndef FUNCTION_NPC_PROTOCOL
#define FUNCTION_NPC_PROTOCOL

#include "protocol_common_errorcode.h"

#pragma pack(push, 1)
//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum
{	
	E_Dak_NPCNotFound		= 1,	// 没有找到指定NPC
	E_Dak_NPCNotValid		= 2,	// 不是驿站NPC
	E_Dak_TooFar			= 3,	// 距离驿站NPC太远
	E_Dak_NotExist			= 4,	// 在指定NPC身上没有找到驿站
	E_Dak_TargetMap_Invalid	= 5,	// 指定索引内map id和指定id不符
	E_Dak_NotEnough_Money	= 6,	// 消耗品不足
	E_Dak_ChangeMap_Failed	= 7,	// 传送时失败

	E_Ware_NPCNotValid		= 10,	// 不是角色仓库NPC
	
	E_Con_Cannot_Extend		= 50,	// 不可再扩容
	E_Con_Cannot_itemExtend = 51,	// 扩充道具不存在
	E_Con_exstep_low		= 52,	// 扩充道具等级太低
	E_Con_exstep_up			= 53,	// 扩充道具等级太高

	E_Silver_NotEnough		= 60,	// 金钱不足
	E_YuanBao_NotEnough		= 61,	// 元宝不足
};

//----------------------------------------------------------------------------
// 驿站&乾坤石
//----------------------------------------------------------------------------
struct NET_SIC_posthouse : public tag_net_message
{
	NET_SIC_posthouse()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_posthouse");
		dw_size = sizeof(NET_SIC_posthouse);
	}
	DWORD	dwNPCID;	// 职能NPC ID
	INT32	nIndex;		// 驿站目的地在该NPC处索引
	DWORD	dwPosID;	// 驿站id
	BYTE	by_type;	// 副本类型 0 普通 1 精英（如果传入普通地图此值添0）
	DWORD	dwMapID;	// 目的地Map ID
};

struct NET_SIS_posthouse : public tag_net_message
{
	NET_SIS_posthouse()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_posthouse");
		dw_size = sizeof(NET_SIS_posthouse);
	}
	DWORD	dw_error_code;
};

// 副本扫荡数据
struct NET_SIS_get_saodang_data : public tag_net_message
{
	NET_SIS_get_saodang_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_saodang_data");
		dw_size = sizeof(NET_SIS_get_saodang_data);
	}
	int		nIndex;		// 副本索引
	tagDWORDTime	dwBeginTime;	//开始时间
};

// 副本扫荡
struct NET_SIC_instance_saodang : public tag_net_message
{
	NET_SIC_instance_saodang()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_instance_saodang");
		dw_size = sizeof(NET_SIC_instance_saodang);
	}

	int		nIndex;		// 副本索引

};

struct NET_SIS_instance_saodang : public tag_net_message
{
	NET_SIS_instance_saodang()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_instance_saodang");
		dw_size = sizeof(NET_SIS_instance_saodang);
	}
	int		nIndex;		// 副本索引
	DWORD	dw_error_code;
};

// 结束扫荡
struct NET_SIC_saodang_over : public tag_net_message
{
	NET_SIC_saodang_over()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_saodang_over");
		dw_size = sizeof(NET_SIC_saodang_over);
	}

};

struct NET_SIS_saodang_over : public tag_net_message
{
	NET_SIS_saodang_over()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_saodang_over");
		dw_size = sizeof(NET_SIS_saodang_over);
	}
	DWORD	dw_error_code;
};

struct NET_SIC_ware_extend : public tag_net_message
{
	NET_SIC_ware_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_ware_extend");
		dw_size = sizeof(NET_SIC_ware_extend);
	}
	DWORD	dwNPCID;
	bool	bUseSilver;		// true: 使用游戏币；false:使用元宝
};

struct NET_SIS_ware_extend : public tag_net_message
{
	NET_SIS_ware_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_ware_extend");
		dw_size = sizeof(NET_SIS_ware_extend);
	}
	DWORD	dw_error_code;
	INT16	n16WareNum;
};

struct NET_SIC_bag_extend : public tag_net_message
{
	NET_SIC_bag_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_bag_extend");
		dw_size = sizeof(NET_SIC_bag_extend);
	}
	INT64	n64ItemSerial;
	INT32	n32_type;		// 0 包裹 1 仓库
};

struct NET_SIS_bag_extend : public tag_net_message
{
	NET_SIS_bag_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bag_extend");
		dw_size = sizeof(NET_SIS_bag_extend);
	}
	DWORD	dw_error_code;
	INT32	n32_type;		// 0 包裹 1 仓库
	INT16	n16BagNum;
};

//----------------------------------------------------------------------------
// 金钱&元宝
//----------------------------------------------------------------------------
struct NET_SIC_save_silver : public tag_net_message
{
	NET_SIC_save_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_save_silver");
		dw_size = sizeof(NET_SIC_save_silver);
	}
	DWORD	dwNPCID;
	INT64	n64SilverSave;
};

struct NET_SIS_save_silver : public tag_net_message
{
	NET_SIS_save_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_save_silver");
		dw_size = sizeof(NET_SIS_save_silver);
	}
	DWORD	dw_error_code;
};

struct NET_SIC_get_silver : public tag_net_message
{
	NET_SIC_get_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_silver");
		dw_size = sizeof(NET_SIC_get_silver);
	}
	DWORD	dwNPCID;
	INT64	n64SilverGet;
	DWORD	dw_safe_code;
};

struct NET_SIS_get_silver : public tag_net_message
{
	NET_SIS_get_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_silver");
		dw_size = sizeof(NET_SIS_get_silver);
	}
	DWORD	dw_error_code;
};

struct NET_SIS_save_yuan_bao : public tag_net_message
{
	NET_SIS_save_yuan_bao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_save_yuan_bao");
		dw_size = sizeof(NET_SIS_save_yuan_bao);
	}
	DWORD	dw_error_code;
};

// 从百宝袋中获取元宝
struct NET_SIC_get_yuan_bao : public tag_net_message
{
	NET_SIC_get_yuan_bao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_yuan_bao");
		dw_size = sizeof(NET_SIC_get_yuan_bao);
	}
	INT		nYuanBaoGet;
};



//----------------------------------------------------------------------------
// 使用磨石
//----------------------------------------------------------------------------
struct NET_SIC_abrase_stone : public tag_net_message
{
	NET_SIC_abrase_stone()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_abrase_stone");
		dw_size = sizeof(NET_SIC_abrase_stone);
	}
	INT64	n64AbraserSerial;	// 磨石64位id
	//INT64	n64WeaponSerial;	// 武器64位id
};

struct NET_SIS_abrase_stone : public tag_net_message
{
	NET_SIS_abrase_stone()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_abrase_stone");
		dw_size = sizeof(NET_SIS_abrase_stone);
	}
	DWORD	dw_error_code;
	//INT64	n64WeaponSerial;	// 武器64位id
	//INT		nAttackTimes;		// 更新后武器使用次数
};


//----------------------------------------------------------------------------
#pragma pack(pop)
#endif