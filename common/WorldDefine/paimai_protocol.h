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
*	@file		paimai_protocol.h
*	@author		lc
*	@date		2011/03/16	initial
*	@version	0.0.1.0
*	@brief		拍卖数据，消息定义
*/

#ifndef PAIMAI_PROTOCOL
#define PAIMAI_PROTOCOL

#include "protocol_common_errorcode.h"
#include "../WorldDefine/ItemDefine.h"

#pragma pack(push, 1)

enum
{
	E_PaiMai_LevelNotEnough				= 1,		// 拍卖等级不足
	E_PaiMai_Item_NotExist				= 2,		// 拍卖物品不存在
	E_PaiMai_Item_IsBind				= 3,		// 绑定物品不能出售
	E_PaiMai_Chaw_Limit					= 4,		// 一口价超过限制
	E_PaiMai_bidup_Limit				= 5,		// 竞拍价格超过限制
	E_PaiMai_Keeping_NotEnough			= 6,		// 保管费不足
	E_PaiMai_TimeType_Limit				= 7,		// 时间类型不合法

	E_PaiMai_Not_paimai_Role			= 8,		// 不是拍卖者不能取消拍卖
	E_PaiMai_bidup_limit				= 9,		// 起拍价格非法
	E_PaiMai_chaw_limit					= 10,		// 一口价非法
	E_PaiMai_Money_Not_Enough			= 11,		// 金钱不足
	E_PaiMai_Num_Limit					= 12,		// 拍卖次数限制
	E_PaiMai_bidup_repeat				= 13,		// 竞价重复
	E_PaiMai_Only_JingPai				= 14,		// 没有一口价职能竞拍
	E_PaiMai_chaw_buy_limit				= 15,		// 一口价购买限制（竞拍价格超过一口价）
};

//---------------------------------------------------------------------------------------------
// 拍卖数据结构定义
//---------------------------------------------------------------------------------------------
//拍卖数据
struct tag_paimai
{
	DWORD				dw_paimai_id;				// 拍卖索引号
	DWORD				dw_bidup;					// 竞拍价格
	DWORD				dw_bidup_id;				// 竞拍人ID
	DWORD				dw_chaw;					// 一口价
	DWORD				dw_sell_id;					// 拍卖者id
	tagDWORDTime		dw_beigin_time;				// 拍卖起始时间
	BYTE				by_time_type;				// 拍卖时间类型
	BOOL				b_show_name;				// 是否匿名
	DWORD				dw_auto_index;				// 自动拍卖编号

	tag_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_bidup_id = INVALID_VALUE;
		dw_sell_id = INVALID_VALUE;
		dw_auto_index = INVALID_VALUE;
	}
};

// 自己的拍卖信息
struct tag_own_paimai_info
{
	DWORD				dw_paimai_id;			// 拍卖编号
	DWORD				dw_bidup_price;			// 起拍价格
	DWORD				dw_chaw_price;			// 一口价
	tagDWORDTime		dw_begin_time;			// 拍卖起始时间
	DWORD				dw_sell_id;				// 拍卖者id
	BYTE				by_time_type;			// 时间类型
	BOOL				b_show_name;			// 是否匿名
	tagEquipViewInfoEx	st_info;
};

// 拍卖查询类型
enum E_Query_Type
{
	EQT_ALL			=		1,			// 查询全部
	EQT_Name		=		2,			// 名称查询
	EQT_Type		=		3,			// 物品大类查询
	EQT_TypeEx		=		4,			// 物品扩充类型查询
	EQT_Reserved	=		5,			// 物品保留类型查询
};

//  查询结构
struct tag_paimai_query
{
	E_Query_Type		e_query_type;				// 查询类型
	DWORD				dw_type_id;					// 物品类型id
	INT					dw_item_type[3];				// 物品类型
};

/*******************************************************************************************************
*******************************************************************************************************
*******************************************************************************************************/

//---------------------------------------------------------------------------------------------
// 拍卖消息定义
//---------------------------------------------------------------------------------------------
// 开始拍卖
struct NET_SIC_begin_paimai : public tag_net_message
{
	NET_SIC_begin_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_begin_paimai");
		dw_size = sizeof(NET_SIC_begin_paimai);
	}

	INT64		n64_item_id;			// 物品id
	DWORD		dw_bidup_price;			// 起拍价格
	DWORD		dw_chaw_price;			// 一口价
	BYTE		by_time_type;			// 时间类型
	BOOL		b_show_name;			// 是否匿名
	DWORD		dw_safe_code;
};

struct NET_SIS_begin_paimai : public tag_net_message
{
	NET_SIS_begin_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_begin_paimai");
		dw_size = sizeof(NET_SIS_begin_paimai);
	}

	DWORD	dw_Error;
};

// 取消拍卖
struct NET_SIC_cancel_paimai : public tag_net_message
{
	NET_SIC_cancel_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_paimai");
		dw_size = sizeof(NET_SIC_cancel_paimai);
	}

	DWORD	dw_paimai_id;
};

struct NET_SIS_cancel_paimai : public tag_net_message
{
	NET_SIS_cancel_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_paimai");
		dw_size = sizeof(NET_SIS_cancel_paimai);
	}
	DWORD	dw_paimai_id;
	DWORD	dw_error;
};

// 通知竞拍者取消拍卖
struct NET_SIS_send_cancel_paimai : public tag_net_message
{
	NET_SIS_send_cancel_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_cancel_paimai");
		dw_size = sizeof(NET_SIS_send_cancel_paimai);
	}

	DWORD	dw_paimai_id;
};

// 拍卖成功通知添加新的拍卖物品
struct NET_SIS_add_paimai_info : public tag_net_message
{
	NET_SIS_add_paimai_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_paimai_info");
		dw_size = sizeof(NET_SIS_add_paimai_info);
	}
	DWORD				dw_paimai_id;			// 拍卖ID
	DWORD				dw_bidup_price;			// 起拍价格
	DWORD				dw_chaw_price;			// 一口价
	tagDWORDTime		dw_begin_time;			// 拍卖起始时间
	BOOL				b_show_name;			// 是否匿名
	BYTE				by_time_type;			// 时间类型
	tagEquipViewInfoEx	st_info;
};

// 角色登陆发送自己的拍卖信息
struct NET_SIS_send_own_paimai_info : public tag_net_message
{
	NET_SIS_send_own_paimai_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_own_paimai_info");
		dw_size = sizeof(NET_SIS_send_own_paimai_info);
	}

	INT	 n_duty;
	INT	 n_num;
	tag_own_paimai_info st_own_paimai[1];
};

// 角色登陆发送自己的竞拍信息
struct NET_SIS_send_own_jingpai_info : public tag_net_message
{
	NET_SIS_send_own_jingpai_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_own_jingpai_info");
		dw_size = sizeof(NET_SIS_send_own_jingpai_info);
	}
	INT	 n_num;
	tag_own_paimai_info st_own_paimai[1];
};

// 发起竞拍
struct NET_SIC_jingpai : public tag_net_message
{
	NET_SIC_jingpai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_jingpai");
		dw_size = sizeof(NET_SIC_jingpai);
	}
	DWORD	dw_paimai_id;
	DWORD	dw_safe_code;
};

struct NET_SIS_jingpai : public tag_net_message
{
	NET_SIS_jingpai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_jingpai");
		dw_size = sizeof(NET_SIS_jingpai);
	}
	DWORD dw_error;
};

// 添加竞拍信息
struct NET_SIS_add_jingpai : public tag_net_message
{
	NET_SIS_add_jingpai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_jingpai");
		dw_size = sizeof(NET_SIS_add_jingpai);
	}
	tag_own_paimai_info	st_paimai_info;
};

// 删除竞拍信息
struct NET_SIS_delete_jingpai : public tag_net_message
{
	NET_SIS_delete_jingpai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_jingpai");
		dw_size = sizeof(NET_SIS_delete_jingpai);
	}
	DWORD	dw_paimai_id;
};

// 更新竞拍信息
struct NET_SIS_update_jingpai : public tag_net_message
{
	NET_SIS_update_jingpai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_jingpai");
		dw_size = sizeof(NET_SIS_update_jingpai);
	}
	DWORD	dw_paimai_id;
	DWORD	dw_bidup;
};

// 一口价购买
struct NET_SIC_chaw_buy : public tag_net_message
{
	NET_SIC_chaw_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_chaw_buy");
		dw_size = sizeof(NET_SIC_chaw_buy);
	}
	DWORD	dw_paimai_id;
	DWORD	dw_safe_code;
};

struct NET_SIS_chaw_buy : public tag_net_message
{
	NET_SIS_chaw_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_chaw_buy");
		dw_size = sizeof(NET_SIS_chaw_buy);
	}
	DWORD	dw_error;
};

// 删除拍卖信息
struct NET_SIS_delete_paimai : public tag_net_message
{
	NET_SIS_delete_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_paimai");
		dw_size = sizeof(NET_SIS_delete_paimai);
	}
	DWORD	dw_paimai_id;
};

// 拍卖查询
struct NET_SIC_paimai_query : public tag_net_message
{
	NET_SIC_paimai_query()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_paimai_query");
		dw_size = sizeof(NET_SIC_paimai_query);
	}

	tag_paimai_query	st_paimai_query;
};

struct NET_SIS_paimai_query : public tag_net_message
{
	NET_SIS_paimai_query()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_paimai_query");
		dw_size = sizeof(NET_SIS_paimai_query);
	}
	INT						n_page_num;				// 页数
	INT						n_num;					// 信息数量
	tag_own_paimai_info		st_own_paimai[1];
};

// 拍卖翻页
struct NET_SIC_paimai_change_page : public tag_net_message
{
	NET_SIC_paimai_change_page()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_paimai_change_page");
		dw_size = sizeof(NET_SIC_paimai_change_page);
	}

	INT		n_page;
};


#pragma pack(pop)

#endif