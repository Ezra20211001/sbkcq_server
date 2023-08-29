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
*	@file		bank_protocol.h
*	@author		lc
*	@date		2011/03/22	initial
*	@version	0.0.1.0
*	@brief		钱庄数据，消息定义
*/

#ifndef BANK_PROTOCOL
#define BANK_PROTOCOL

#include "protocol_common_errorcode.h"

#pragma pack(push, 1)

const	INT		n_keeping[3] = {10, 30, 100};		// 保管费
const	FLOAT	f_keeping[3] = {0.001, 0.002, 0.005};

const	INT		n_exchange[4] = {50, 100, 500, 2500};		// 元宝兑换类型

enum
{
	E_bank_timetype_limit			= 1,		// 时间类型限制
	E_bank_LevelNotEnough			= 2,		// 等级不足
	E_bank_Chaw_Limit				= 3,		// 一口价超出限制
	E_bank_bidup_Limit				= 4,		// 竞拍价格非法
	E_bank_Keeping_NotEnough		= 5,		// 保管费不足
	E_bank_yuanbao_not_enough		= 6,		// 元宝不足
	E_bank_not_sell_role			= 7,		// 不是拍卖者
	E_bank_bidup_repeat				= 8,		// 重复竞价
	E_bank_money_not_enough			= 9,		// 游戏币不足
	E_bank_num_limit				= 10,		// 单日拍卖次数限制
	E_bank_jing_limit				= 11,		// 不能竞拍自己卖出的商品
	E_bank_only_jingpai				= 12,		// 没有一口价职能竞拍
	E_bank_chaw_buy_limit			= 13,		// 竞拍价格超过一口价（只能竞拍）
	E_bank_sell_num_limit			= 14,		// 卖出数量限制

	E_bank_exchange_not_enough		= 50,		// 元宝兑换数不足
	E_bank_exchange_num_limit		= 51,		// 元宝兑换次数限制
};

//---------------------------------------------------------------------------------------------
// 钱庄数据结构定义
//---------------------------------------------------------------------------------------------
struct tag_bank
{
	DWORD			dw_id;				// 钱庄编号
	DWORD			dw_bidup;			// 竞拍价格
	DWORD			dw_bidup_id;		// 竞拍者id
	BYTE			by_type;			// 拍卖类型 0 游戏币 1 元宝
	DWORD			dw_sell;			// 卖出数量
	DWORD			dw_chaw;			// 一口价
	DWORD			dw_sell_id;			// 卖出者id
	tagDWORDTime	dw_begin_time;		// 开始拍卖时间
	BYTE			by_time_type;		// 时间类型

	tag_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_sell_id = INVALID_VALUE;
		dw_bidup_id = INVALID_VALUE;

	}
};

/**********************************************************************************************
**********************************************************************************************
**********************************************************************************************/

//---------------------------------------------------------------------------------------------
// 钱庄消息结构定义
//---------------------------------------------------------------------------------------------
// 开始钱庄拍卖
struct NET_SIC_begin_bank_paimai : public tag_net_message
{
	NET_SIC_begin_bank_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_begin_bank_paimai");
		dw_size = sizeof(NET_SIC_begin_bank_paimai);
	}
	DWORD			dw_bidup;			// 竞拍价格
	BYTE			by_type;			// 拍卖类型 0 游戏币 1 元宝
	DWORD			dw_sell;			// 卖出数量
	DWORD			dw_chaw;			// 一口价
	BYTE			by_time_type;		// 时间类型
	DWORD			dw_safe_code;		// 安全码
};

struct NET_SIS_begin_bank_paimai : public tag_net_message
{
	NET_SIS_begin_bank_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_begin_bank_paimai");
		dw_size = sizeof(NET_SIS_begin_bank_paimai);
	}

	DWORD dw_error;
};

// 发送角色钱庄拍卖信息
struct NET_SIS_send_role_bank_paimai_info : public tag_net_message
{
	NET_SIS_send_role_bank_paimai_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_role_bank_paimai_info");
		dw_size = sizeof(NET_SIS_send_role_bank_paimai_info);
	}

	INT	n_duty;
	INT	n_num;
	tag_bank st_bank[1];
};

// 添加角色钱庄拍卖信息
struct NET_SIS_add_role_bank_paimai : public tag_net_message
{
	NET_SIS_add_role_bank_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_role_bank_paimai");
		dw_size = sizeof(NET_SIS_add_role_bank_paimai);
	}
	tag_bank	st_bank;
};

// 取消角色钱庄拍卖
struct NET_SIC_cancel_role_bank_paimai : public tag_net_message
{
	NET_SIC_cancel_role_bank_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_role_bank_paimai");
		dw_size = sizeof(NET_SIC_cancel_role_bank_paimai);
	}

	DWORD	dw_bank_id;
};

struct NET_SIS_cancel_role_bank_paimai : public tag_net_message
{
	NET_SIS_cancel_role_bank_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_role_bank_paimai");
		dw_size = sizeof(NET_SIS_cancel_role_bank_paimai);
	}
	DWORD	dw_error;
};

// 删除角色钱庄拍卖信息
struct NET_SIS_delete_role_bank_paimai : public tag_net_message
{
	NET_SIS_delete_role_bank_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_role_bank_paimai");
		dw_size = sizeof(NET_SIS_delete_role_bank_paimai);
	}
	DWORD	dw_bank_id;
};

// 开始竞价
struct NET_SIC_begin_bank_jing : public tag_net_message
{
	NET_SIC_begin_bank_jing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_begin_bank_jing");
		dw_size = sizeof(NET_SIC_begin_bank_jing);
	}
	DWORD	dw_bank_id;
	DWORD	dw_safe_code;
};

struct NET_SIS_begin_bank_jing : public tag_net_message
{
	NET_SIS_begin_bank_jing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_begin_bank_jing");
		dw_size = sizeof(NET_SIS_begin_bank_jing);
	}
	DWORD	dw_error;
};

struct NET_SIS_update_bank_jing : public tag_net_message
{
	NET_SIS_update_bank_jing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_bank_jing");
		dw_size = sizeof(NET_SIS_update_bank_jing);
	}
	DWORD	dw_bank_id;
	DWORD	dw_new_bidup;
};

// 一口价购买
struct NET_SIC_bank_chaw_buy : public tag_net_message
{
	NET_SIC_bank_chaw_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_bank_chaw_buy");
		dw_size = sizeof(NET_SIC_bank_chaw_buy);
	}

	DWORD	dw_bank_id;
	DWORD	dw_safe_code;
};

struct NET_SIS_bank_chaw_buy : public tag_net_message
{
	NET_SIS_bank_chaw_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bank_chaw_buy");
		dw_size = sizeof(NET_SIS_bank_chaw_buy);
	}
	DWORD	dw_error;
};

// 查询钱庄信息
struct NET_SIC_query_bank : public tag_net_message
{
	NET_SIC_query_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_query_bank");
		dw_size = sizeof(NET_SIC_query_bank);
	}
	BYTE	by_type;		// 查询类型 0 游戏币 1 元宝
};

struct NET_SIS_query_bank : public tag_net_message
{
	NET_SIS_query_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_query_bank");
		dw_size = sizeof(NET_SIS_query_bank);
	}
	INT			n_page_num;		// 页数
	INT			n_num;
	BYTE		by_type;
	tag_bank	st_bank[1];
};

// 拍卖翻页
struct NET_SIC_bank_change_page : public tag_net_message
{
	NET_SIC_bank_change_page()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_bank_change_page");
		dw_size = sizeof(NET_SIC_bank_change_page);
	}
	BYTE	by_type;	// 查询类型 0 游戏币 1 元宝
	INT		n_page;
};

struct NET_SIS_bank_exchange_info : public tag_net_message
{
	NET_SIS_bank_exchange_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bank_exchange_info");
		dw_size = sizeof(NET_SIS_bank_exchange_info);
	}
	BYTE		by_type;		// 竞拍成功 0 一口价成功 1
	tag_bank	st_bank;
};

// 获取元宝兑换次数
struct NET_SIC_get_yuanbao_exchange_num : public tag_net_message
{
	NET_SIC_get_yuanbao_exchange_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_yuanbao_exchange_num");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_yuanbao_exchange_num : public tag_net_message
{
	NET_SIS_yuanbao_exchange_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_yuanbao_exchange_num");
		dw_size = sizeof(*this);
	}
	INT n_num;
};

// 获取汇率
struct NET_SIC_get_bank_radio : public tag_net_message
{
	NET_SIC_get_bank_radio()
	{
		ZeroMemory(this, sizeof(*this));;
		dw_message_id = message_id_crc("NET_SIC_get_bank_radio");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_bank_radio : public tag_net_message
{
	NET_SIS_get_bank_radio()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_bank_radio");
		dw_size = sizeof(*this);
	}
	INT n_bank_radio;
};

// 元宝兑换
struct NET_SIC_yuanban_exchange : public tag_net_message
{
	NET_SIC_yuanban_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_yuanban_exchange");
		dw_size = sizeof(*this);
	}

	BYTE	by_type;
	DWORD	dw_safe_code;
};

struct NET_SIS_yuanbao_exchange : public tag_net_message
{
	NET_SIS_yuanbao_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_yuanban_exchange");
		dw_size = sizeof(*this);
	}

	DWORD dw_error;
};

#pragma pack(pop)

#endif