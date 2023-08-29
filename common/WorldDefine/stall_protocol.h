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
*	@file		stall_protocol.h
*	@author		lc
*	@date		2011/03/10	initial
*	@version	0.0.1.0
*	@brief		摆摊消息
*/

#ifndef STALL_PROTOCOL
#define STALL_PROTOCOL
 

#include "stall_define.h"

#pragma pack(push, 1)
//-----------------------------------------------------------------------------
// 摆摊者发送的消息
//-----------------------------------------------------------------------------
// 打开摆摊界面
struct NET_SIC_stall_start : public tag_net_message
{
	NET_SIC_stall_start()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_start");
		dw_size = sizeof(NET_SIC_stall_start);
	}
	DWORD	dw_safe_code;
};

struct NET_SIS_stall_start : public tag_net_message
{
	NET_SIS_stall_start()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_start");
		dw_size = sizeof(NET_SIS_stall_start);
	}
	DWORD dw_error_code;
	BYTE  byMaxIndex;
	BYTE  byStallLevel;			// 摊位模型等级
};

// 商品上架
struct NET_SIC_stall_set_goods : public tag_net_message
{
	NET_SIC_stall_set_goods()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_set_goods");
		dw_size = sizeof(NET_SIC_stall_set_goods);
	}
	INT64	n64_serial;
	INT64	n64UnitPrice;
	BYTE	byIndex;				// 货架上的索引，从0开始
};

struct NET_SIS_stall_set_goods : public tag_net_message
{
	NET_SIS_stall_set_goods()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_set_goods");
		dw_size = sizeof(NET_SIS_stall_set_goods);
	}
	DWORD	dw_error_code;
};

// 商品下架
struct NET_SIC_stall_unset_goods : public tag_net_message
{
	NET_SIC_stall_unset_goods()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_unset_goods");
		dw_size = sizeof(NET_SIC_stall_unset_goods);
	}
	BYTE	byIndex;
};

struct NET_SIS_stall_unset_goods : public tag_net_message
{
	NET_SIS_stall_unset_goods()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_unset_goods");
		dw_size = sizeof(NET_SIS_stall_unset_goods);
	}
	DWORD	dw_error_code;
};

// 设置标题
struct NET_SIC_stall_set_title : public tag_net_message
{
	NET_SIC_stall_set_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_set_title");
		dw_size = sizeof(NET_SIC_stall_set_title);
	}
	TCHAR	szData[1];// 标题
};

struct NET_SIS_stall_set_title : public tag_net_message
{
	NET_SIS_stall_set_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_set_title");
		dw_size = sizeof(NET_SIS_stall_set_title);
	}
	DWORD	dw_error_code;
};

// 设置广告
struct NET_SIC_stall_set_advertisement : public tag_net_message
{
	NET_SIC_stall_set_advertisement()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_set_advertisement");
		dw_size = sizeof(NET_SIC_stall_set_advertisement);
	}
	TCHAR	szData[1];// 广告
};

struct NET_SIS_stall_set_advertisement : public tag_net_message
{
	NET_SIS_stall_set_advertisement()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_set_advertisement");
		dw_size = sizeof(NET_SIS_stall_set_advertisement);
	}
	DWORD	dw_error_code;
};

// 设置广告广播标志
struct NET_SIC_stall_set_advertisement_flag : public tag_net_message
{
	NET_SIC_stall_set_advertisement_flag()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_set_advertisement_flag");
		dw_size = sizeof(NET_SIC_stall_set_advertisement_flag);
	}
	bool	bFlag;					// 1表示广播；0表示不广播
};

struct NET_SIS_stall_set_advertisement_flag : public tag_net_message
{
	NET_SIS_stall_set_advertisement_flag()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_set_advertisement_flag");
		dw_size = sizeof(NET_SIS_stall_set_advertisement_flag);
	}
	DWORD	dw_error_code;
};

// 完成摆摊设置，告诉周围玩家
struct NET_SIC_stall_set_finish : public tag_net_message
{
	NET_SIC_stall_set_finish()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_set_finish");
		dw_size = sizeof(NET_SIC_stall_set_finish);
	}
};

struct NET_SIS_stall_set_finish : public tag_net_message
{
	NET_SIS_stall_set_finish()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_set_finish");
		dw_size = sizeof(NET_SIS_stall_set_finish);
	}
	DWORD	dw_error_code;
	DWORD	dw_role_id;				// 摆摊者ID
	BYTE	byStallLevel;			// 摊位模型等级
};

// 收摊
struct NET_SIC_stall_close : public tag_net_message
{
	NET_SIC_stall_close()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_close");
		dw_size = sizeof(NET_SIC_stall_close);
	}
};

struct NET_SIS_stall_close : public tag_net_message
{
	NET_SIS_stall_close()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_close");
		dw_size = sizeof(NET_SIS_stall_close);
	}
	DWORD	dw_error_code;
	DWORD	dwStallRoleID;			// 收摊者ID
};

struct NET_SIS_stall_buy_refresh : public tag_net_message
{
	NET_SIS_stall_buy_refresh()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_buy_refresh");
		dw_size = sizeof(NET_SIS_stall_buy_refresh);
	}
	DWORD	dwStallRoleID;			// 摆摊者ID
	INT16	n16Num;					// 更新后摊位上商品个数
	BYTE	byIndex;				// 摊位上商品的位置索引
};

// 商品上架广播
struct NET_SIS_stall_set_refresh : public tag_net_message
{
	NET_SIS_stall_set_refresh()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_set_refresh");
		dw_size = sizeof(NET_SIS_stall_set_refresh);
	}
	DWORD	dwStallRoleID;			// 摆摊者ID
	BYTE	byIndex;				// 摊位上商品的位置索引
};

// 商品下架广播
struct NET_SIS_stall_unset_refresh : public tag_net_message
{
	NET_SIS_stall_unset_refresh()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_unset_refresh");
		dw_size = sizeof(NET_SIS_stall_unset_refresh);
	}
	DWORD	dwStallRoleID;			// 摆摊者ID
	BYTE	byIndex;
};

struct NET_SIS_stall_buy_message : public tag_net_message
{
	NET_SIS_stall_buy_message()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_buy_message");
		dw_size = sizeof(NET_SIS_stall_buy_message);
	}
	DWORD dw_role_id;	//购买者ID
	DWORD dw_time;	//购买时间
	DWORD dw_data_id;//购买物品类型
	INT16 n16Number;//购买数量
	INT64 n64_price;//购买单价   gx add 2013.6.25
};


//-----------------------------------------------------------------------------
// 购买者发送的消息
//-----------------------------------------------------------------------------
struct NET_SIC_stall_get : public tag_net_message
{
	NET_SIC_stall_get()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_get");
		dw_size = sizeof(NET_SIC_stall_get);
	}
	DWORD	dwStallRoleID;			// 摆摊者ID
};

struct NET_SIS_stall_get : public tag_net_message
{
	NET_SIS_stall_get()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_get");
		dw_size = sizeof(NET_SIS_stall_get);
	}
	DWORD	dw_error_code;
	DWORD	dwStallRoleID;			// 摆摊者ID
	BYTE	byNum;					// 商品个数
	BYTE	byData[1];				// tagMsgStallGoods
};

struct NET_SIC_stall_get_title : public tag_net_message
{
	NET_SIC_stall_get_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_get_title");
		dw_size = sizeof(NET_SIC_stall_get_title);
	}
	INT nNumber;
	DWORD	dwStallRoleID[1];			// 摆摊者ID
};

struct NET_SIS_stall_get_title : public tag_net_message
{
	NET_SIS_stall_get_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_get_title");
		dw_size = sizeof(NET_SIS_stall_get_title);
	}
	DWORD	dw_error_code;
	DWORD	dwStallRoleID;			// 摆摊者ID
	TCHAR	szTitle[STALL_MAX_TITLE_NUM];
};

struct NET_SIC_stall_get_advertisement : public tag_net_message
{
	NET_SIC_stall_get_advertisement()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_get_advertisement");
		dw_size = sizeof(NET_SIC_stall_get_advertisement);
	}
	DWORD	dwStallRoleID;			// 摆摊者ID
};

struct NET_SIS_stall_get_advertisement : public tag_net_message
{
	NET_SIS_stall_get_advertisement()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_get_advertisement");
		dw_size = sizeof(NET_SIS_stall_get_advertisement);
	}
	DWORD	dw_error_code;
	DWORD	dwStallRoleID;			// 摆摊者ID
	TCHAR	szAd[STALL_AD_CHAR_MAX];
};

// 购买商品
struct NET_SIC_stall_buy : public tag_net_message
{
	NET_SIC_stall_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_buy");
		dw_size = sizeof(NET_SIC_stall_buy);
	}
	INT64	n64_serial;				// 要购买的商品64位ID
	INT64	n64UnitPrice;			// 商品单价(检查商品是否有过更新用)
	DWORD	dwStallRoleID;			// 摆摊者ID
	INT16	n16Num;					// 商品个数
	BYTE	byIndex;				// 所在摊位的格子索引(从0开始)
	DWORD	dw_safe_code;
};

struct NET_SIS_stall_buy : public tag_net_message
{
	NET_SIS_stall_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_buy");
		dw_size = sizeof(NET_SIS_stall_buy);
	}
	DWORD	dw_error_code;
};

// 获取指定摊位上的商品
struct NET_SIC_stall_get_special : public tag_net_message
{
	NET_SIC_stall_get_special()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_get_special");
		dw_size = sizeof(NET_SIC_stall_get_special);
	}
	DWORD	dwStallRoleID;			// 摆摊者ID
	BYTE	byIndex;				// 摊位上商品的位置索引
};

struct NET_SIS_stall_get_special : public tag_net_message
{
	NET_SIS_stall_get_special()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_get_special");
		dw_size = sizeof(NET_SIS_stall_get_special);
	}
	DWORD	dw_error_code;
	DWORD	dwStallRoleID;			// 摆摊者ID
	BYTE	byData[1];				// tagMsgStallGoods
};

struct NET_SIC_stall_history_chat : public tag_net_message
{
	NET_SIC_stall_history_chat()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_history_chat");
		dw_size = sizeof(NET_SIC_stall_history_chat);
	}
	DWORD dwStallRoleID;
};	

struct NET_SIS_stall_history_chat : public tag_net_message
{
	NET_SIS_stall_history_chat()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_history_chat");
		dw_size = sizeof(NET_SIS_stall_history_chat);
	}
	DWORD dwStallRoleID;
	BYTE  byNumber;
	tagStallMessage stMessage[1];
};


//--------------------------------------------------------------------
// 摆摊者、购买者均可
//--------------------------------------------------------------------
struct NET_SIC_stall_chat : public tag_net_message
{
	NET_SIC_stall_chat()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_chat");
		dw_size = sizeof(NET_SIC_stall_chat);
	}
	DWORD dwStallRoleID;
	TCHAR cMessage[STALL_MESSAGE_CHAR_MAX];
};

struct NET_SIS_stall_chat : public tag_net_message
{
	NET_SIS_stall_chat()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_chat");
		dw_size = sizeof(NET_SIS_stall_chat);
	}
	DWORD dwSender;
	DWORD dwStallRoleID;
	TCHAR cMessage[STALL_MESSAGE_CHAR_MAX];
};


//-----------------------------------------------------------------------------
// VIP摊位消息
//-----------------------------------------------------------------------------
struct NET_SIC_get_all_vip_stall_info : public tag_net_message
{
	NET_SIC_get_all_vip_stall_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_all_vip_stall_info");
		dw_size = sizeof(NET_SIC_get_all_vip_stall_info);
	}
};

struct NET_SIS_get_all_vip_stall_info : public tag_net_message
{
	NET_SIS_get_all_vip_stall_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_all_vip_stall_info");
		dw_size = sizeof(NET_SIS_get_all_vip_stall_info);
	}
	DWORD		dw_error_code;
	DWORD		dwRequestTime;
	tagVIPStall	VIPStallInfo[VIP_STALL_MAX_NUM];
};

struct NET_SIC_update_vip_stall_info : public tag_net_message
{
	NET_SIC_update_vip_stall_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_update_vip_stall_info");
		dw_size = sizeof(NET_SIC_update_vip_stall_info);
	}
	DWORD		dwRequestTime;		// VIP摊位信息更新时间
};

struct NET_SIS_update_vip_stall_info : public tag_net_message
{
	NET_SIS_update_vip_stall_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_vip_stall_info");
		dw_size = sizeof(NET_SIS_update_vip_stall_info);
	}
	DWORD		dw_error_code;
	DWORD		dwRequestTime;		// VIP摊位信息更新时间
	INT32		nInfoNum;			// 更新摊位信息条目数
	tagVIPStall	VIPStallInfo[1];	// 更新信息
};

struct NET_SIC_apply_vip_stall : public tag_net_message
{
	NET_SIC_apply_vip_stall()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_apply_vip_stall");
		dw_size = sizeof(NET_SIC_apply_vip_stall);
	}
	INT32		nRent;				// 摊位租金
	BYTE		byIndex;			// 摊位序号
};

struct NET_SIS_apply_vip_stall : public tag_net_message
{
	NET_SIS_apply_vip_stall()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_apply_vip_stall");
		dw_size = sizeof(NET_SIS_apply_vip_stall);
	}
	DWORD		dw_error_code;
};

struct NET_SIC_special_vip_stall_get : public tag_net_message
{
	NET_SIC_special_vip_stall_get()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_special_vip_stall_get");
		dw_size = sizeof(NET_SIC_special_vip_stall_get);
	}
	BYTE		byIndex;			// VIP摊位序号
};

struct NET_SIS_special_vip_stall_get : public tag_net_message
{
	NET_SIS_special_vip_stall_get()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_special_vip_stall_get");
		dw_size = sizeof(NET_SIS_special_vip_stall_get);
	}
	DWORD		dw_error_code;
};

struct NET_SIC_vip_stall_buy : public tag_net_message
{
	NET_SIC_vip_stall_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_vip_stall_buy");
		dw_size = sizeof(NET_SIC_vip_stall_buy);
	}
	INT64	n64_serial;				// 要购买的商品64位ID
	INT64	n64UnitPrice;			// 商品单价(检查商品是否有过更新用)
	DWORD	dwStallRoleID;			// 摆摊者ID
	INT16	n16Num;					// 商品个数
	BYTE	byIndex;				// 所在摊位的格子索引(从0开始)
};

struct NET_SIS_vip_stall_buy : public tag_net_message
{
	NET_SIS_vip_stall_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_vip_stall_buy");
		dw_size = sizeof(NET_SIS_vip_stall_buy);
	}
	DWORD		dw_error_code;
};


//-----------------------------------------------------------------------------
#pragma pack(pop)
#endif