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
*	@file		bank_server_define.h
*	@author		lc
*	@date		2011/03/22	initial
*	@version	0.0.1.0
*	@brief		钱庄数据，消息定义
*/

#ifndef BANK_SERVER_DEFINE
#define BANK_SERVER_DEFINE
#include "../../common/WorldDefine/bank_protocol.h"

#pragma pack(push, 1)

const INT32 MAX_LOAD_BANK_BUFFER	= 10 * 1000 * 1000;	// 每次读取钱庄的最大字节
const INT32 MAX_LOAD_BANK_NUM	= 10 * 1000;		// 每次发送的钱庄数量
const INT32 TMP_BANK_BUFFER		= 100 * 1000;		// 钱庄临时缓冲

//---------------------------------------------------------------------------------------------
// 钱庄消息定义
//---------------------------------------------------------------------------------------------
// 获取钱庄最大编号
struct NET_S2DB_get_max_bank_id : public tag_net_message
{
	NET_S2DB_get_max_bank_id()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_get_max_bank_id");
		dw_size = sizeof(NET_S2DB_get_max_bank_id);
	}
};

struct NET_DB2S_get_max_bank_id : public tag_net_message
{
	NET_DB2S_get_max_bank_id()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_get_max_bank_id");
		dw_size = sizeof(NET_DB2S_get_max_bank_id);
	}

	DWORD	dw_max_id;			// 钱庄最大编号
};

// 保存钱庄信息
struct NET_S2DB_insert_bank : public tag_net_message
{
	NET_S2DB_insert_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_insert_bank");
		dw_size = sizeof(NET_S2DB_insert_bank);
	}
	tag_bank	st_bank;
};

// 删除钱庄纪录
struct NET_S2DB_delete_bank : public tag_net_message
{
	NET_S2DB_delete_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_delete_bank");
		dw_size = sizeof(NET_S2DB_delete_bank);
	}
	DWORD	dw_bank_id;
};

// 更新竞拍纪录
struct NET_S2DB_update_bank : public tag_net_message
{
	NET_S2DB_update_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_update_bank");
		dw_size = sizeof(NET_S2DB_update_bank);
	}
	tag_bank	st_bank;
};

// 读取钱庄信息
struct NET_S2DB_load_all_bank : public tag_net_message
{
	NET_S2DB_load_all_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_load_all_bank");
		dw_size = sizeof(NET_S2DB_load_all_bank);
	}
};

struct NET_DB2S_load_all_bank : public tag_net_message
{
	NET_DB2S_load_all_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_all_bank");
		dw_size = sizeof(NET_DB2S_load_all_bank);
	}
	INT			n_num;
	tag_bank	st_bank[1];
};


#pragma pack(pop)

#endif