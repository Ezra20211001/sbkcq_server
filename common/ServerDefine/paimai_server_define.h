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
*	@file		paimai_server_define.h
*	@author		lc
*	@date		2011/03/16	initial
*	@version	0.0.1.0
*	@brief		拍卖服务器数据，消息定义
*/

#ifndef PAIMAI_SERVER_DEFINE
#define PAIMAI_SERVER_DEFINE

#include "../common/WorldDefine/paimai_protocol.h"
#include "../ServerDefine/item_server_define.h"

#pragma pack(push, 1)

const INT32 MAX_LOAD_PAI_BUFFER	= 10 * 1000 * 1000;	// 每次读取拍卖的最大字节
const INT32 MAX_LOAD_PAI_NUM	= 10 * 1000;		// 每次发送的拍卖数量
const INT32 TMP_PAI_BUFFER		= 100 * 1000;		// 拍卖临时缓冲

const INT32	PAIMAI_CONTEXT	=	100;

const DWORD AUTO_PAIMAI_TIME = TICK_PER_SECOND * 60;

struct tagAutoPaimai
{
	DWORD			dwID;					// 编号
	DWORD			dwItemID;				// 物品ID
	DWORD			dwBidup;				// 竞拍价格
	DWORD			dwChaw;					// 一口价
	DWORD			dwSellRoleID;			// 拍卖者ID
	BYTE			byTimeType;				// 拍卖时间类型
	DWORD			dwInventory;			// 库存量
	DWORD			dwComplement;			// 补量
	BOOL			bSell;					// 是否挂在到拍卖行
	DWORD			dwSellNum;				// 单次拍卖数量
	BOOL			bBind;					// 是否绑定
	BOOL			bOnline;				// 是否上架

	tagAutoPaimai()
	{
		ZeroMemory(this, sizeof(*this));
		dwID = INVALID_VALUE;
		dwItemID = INVALID_VALUE;
		dwSellRoleID = INVALID_VALUE;
	}
};

//---------------------------------------------------------------------------------------------
// 自动拍卖消息定义
//---------------------------------------------------------------------------------------------
// 读取所有自动拍卖数据
struct NET_S2DB_load_auto_paimai : public tag_net_message
{
	NET_S2DB_load_auto_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_load_auto_paimai");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2S_load_auto_paimai : public tag_net_message
{
	NET_DB2S_load_auto_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_auto_paimai");
		dw_size = sizeof(*this);
	}
	INT n_num;
	tagAutoPaimai	st_auto_paimai[1];
};

struct NET_DB2S_load_auto_paimai_end : public tag_net_message
{
	NET_DB2S_load_auto_paimai_end()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_auto_paimai_end");
		dw_size = sizeof(*this);
	}
};

// 检查是否已经拍卖
struct NET_S2DB_check_is_paimai : public tag_net_message
{
	NET_S2DB_check_is_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_check_is_paimai");
		dw_size = sizeof(*this);
	}
	DWORD dw_auto_paimai_id;
};

struct NET_DB2S_check_is_paimai : public tag_net_message
{
	NET_DB2S_check_is_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_check_is_paimai");
		dw_size = sizeof(*this);
	}

	DWORD dw_auto_paimai_id;
	BOOL  b_have;
};

// 自动拍卖初始化完成
struct NET_S2DB_auto_paimai_init_ok : public tag_net_message
{
	NET_S2DB_auto_paimai_init_ok()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_auto_paimai_init_ok");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2S_auto_paimai_init_ok : public tag_net_message
{
	NET_DB2S_auto_paimai_init_ok()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_auto_paimai_init_ok");
		dw_size = sizeof(*this);
	}
};

// 更新自动拍卖数据
struct NET_S2DB_update_auto_paimai : public tag_net_message
{
	NET_S2DB_update_auto_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_update_auto_paimai");
		dw_size = sizeof(*this);
	}
	tagAutoPaimai st_auto_paimai;
};

//---------------------------------------------------------------------------------------------
// 拍卖消息定义
//---------------------------------------------------------------------------------------------
//! 获取拍卖最大编号
struct NET_S2DB_load_paimai_max_id : public tag_net_message
{
	NET_S2DB_load_paimai_max_id()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_load_paimai_max_id");
		dw_size = sizeof(NET_S2DB_load_paimai_max_id);
	}
};

struct NET_DB2S_load_paimai_max_id : public tag_net_message
{
	NET_DB2S_load_paimai_max_id()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_paimai_max_id");
		dw_size = sizeof(NET_DB2S_load_paimai_max_id);
	}
	DWORD	dw_max_id;			// 最大拍卖编号
};

//! 更新拍卖物品
struct NET_S2DB_update_paimai_item : public tag_net_message
{
	NET_S2DB_update_paimai_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_update_paimai_item");
		dw_size = sizeof(NET_S2DB_update_paimai_item);
	}

	s_item_update st_item;
};

//! 保存拍卖信息
struct NET_S2DB_insert_paimai : public tag_net_message
{
	NET_S2DB_insert_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_insert_paimai");
		dw_size = sizeof(NET_S2DB_insert_paimai);
	}
	tag_paimai	st_paimai;
};

//! 删除拍卖纪录
struct NET_S2DB_delete_paimai : public tag_net_message
{
	NET_S2DB_delete_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_delete_paimai");
		dw_size = sizeof(NET_S2DB_delete_paimai);
	}

	DWORD	dw_paimai_id;
};

//! 更新竞拍纪录
struct NET_S2DB_update_paimai : public tag_net_message
{
	NET_S2DB_update_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_update_paimai");
		dw_size = sizeof(NET_S2DB_update_paimai);
	}
	tag_paimai	st_paimai;
};

//! 读取拍卖信息
struct NET_S2DB_load_all_paimai : public tag_net_message
{
	NET_S2DB_load_all_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_load_all_paimai");
		dw_size = sizeof(NET_S2DB_load_all_paimai);
	}
};

struct NET_DB2S_load_all_paimai : public tag_net_message
{
	NET_DB2S_load_all_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_all_paimai");
		dw_size = sizeof(NET_DB2S_load_all_paimai);
	}

	INT			n_num;
	tag_paimai	st_paimai[1];
};

struct NET_DB2S_load_all_paimai_end : public tag_net_message
{
	NET_DB2S_load_all_paimai_end()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_all_paimai_end");
		dw_size = sizeof(*this);
	}
};

//! 读取拍卖物品
struct NET_S2DB_load_paimai_item : public tag_net_message
{
	NET_S2DB_load_paimai_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_load_paimai_item");
		dw_size = sizeof(NET_S2DB_load_paimai_item);
	}

	DWORD	dw_paimai_id;
};

struct NET_DB2S_load_paimai_item : public tag_net_message
{
	NET_DB2S_load_paimai_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_paimai_item");
		dw_size = sizeof(NET_DB2S_load_paimai_item);
	}
	INT		n_count;
	BYTE	by_data_[1];
};	

struct NET_DB2S_load_paimai_item_end : public tag_net_message
{
	NET_DB2S_load_paimai_item_end()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_paimai_item_end");
		dw_size = sizeof(*this);
	}
};

#pragma pack(pop)

#endif