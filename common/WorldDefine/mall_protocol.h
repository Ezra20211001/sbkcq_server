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
*	@file		mall_protocol.h
*	@author		lc
*	@date		2011/03/08	initial
*	@version	0.0.1.0
*	@brief		商城消息
*/

#ifndef MALL_PROTOCOL
#define MALL_PROTOCOL

#pragma pack(push, 1)

#include "protocol_common_errorcode.h"
#include "mall_define.h"

//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum
{
	//E_Mall_				= ,	// 
	E_Mall_Close						= 1,	// 商城关闭

	E_Mall_Item_NotEnough				= 10,	// 物品个数不足购买个数
	E_Mall_Pack_NotEnough				= 11,	// 礼品包个数不足购买个数

	E_Mall_ID_Error						= 12,	// ID不正确
	E_Mall_YuanBao_Error				= 13,	// 元宝单价不正确
	E_Mall_Free_NotExist				= 14,	// 不存在免费物品
	E_Mall_ExVolume_Error				= 15,	// 赠点单价不正确
	E_Mall_Exchange_NotAllowable		= 16,	// 商品不可兑换

	E_Mall_CreateItem_Failed			= 20,	// 商品创建失败
	E_Mall_CreatePres_Failed			= 21,	// 赠品创建失败

	E_Mall_Free_AlreadyGet				= 25,	// 免费物品已领取

	// 元宝交易
	E_Trade_BagYB_NotEnough				= 40,	// 背包中元宝不够
	E_Trade_BagSilver_NotEnough			= 41,	// 背包中金钱不够
	E_Trade_AccountYB_NotEnough			= 42,	// 账户中元宝不够
	E_Trade_AccountSilver_NotEnough		= 43,	// 账户中金钱不够
	E_Trade_SellOrder_Exit				= 44,	// 只能提交一份元宝出售订单
	E_Trade_BuyOrder_Exit				= 45,	// 只能提交一份元宝收购订单
	E_Trade_Tax_NotEnough				= 46,	// 交易手续费不足

	// 帮派团购 
	E_GroupPurchase_NotMember			= 50,	// 不是本帮派成员 
	E_GroupPurchase_ItemNotAllowable	= 51,	// 该商品不可进行团购 //已过促销期
	E_GroupPurchase_NotInGuild			= 52,	// 玩家没有加入帮派   
	E_GroupPurchase_AlreadyInitiate		= 53,	// 已经对该物品发起过团购
	E_GroupPurchase_IsInitiate			= 54,	// 不可响应自己发起的团购
	E_GroupPurchase_AlreadyRespond		= 55,	// 已经响应过该团购
	E_GroupPurchase_AlreadyEnd			= 56,	// 团购已经结束
	E_GroupPurchase_NoInfo				= 57,	// 团购信息不存在
	E_GroupPurchase_ServerBusy			= 58,	// 服务器忙

	//gx modify 2013.11.22
	E_MALL_SALE_START				= 59,	//该商品还未上架
	E_MALL_SALE_END					= 60,	//该商品已经下架
	
};

//-----------------------------------------------------------------------------
// 传输用结构
//-----------------------------------------------------------------------------
struct tagSimGPInfo
{
	DWORD			dwGuildID;
	DWORD			dw_role_id;
	DWORD			dwMallID;
	INT32			nPrice;				//团购价格
	INT16			nParticipatorNum;	//响应人数
	INT16			nRequireNum;		//团购所需人数
	DWORD			dwRemainTime;		//剩余时间
};

//----------------------------------------------------------------------------
// 消息
//----------------------------------------------------------------------------

//--同步数据
struct NET_SIS_open_mall : public tag_net_message
{
	NET_SIS_open_mall()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_open_mall");
		dw_size = sizeof(NET_SIS_open_mall);
	}
	DWORD		dw_error_code;
	DWORD		dwMallTime;
};

//向服务器询问是否可以打开商城
struct NET_SIC_mall_get : public tag_net_message
{
	NET_SIC_mall_get()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_get");
		dw_size = sizeof(NET_SIC_mall_get);
	}
};

struct NET_SIS_mall_item : public tag_net_message
{
	NET_SIS_mall_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_item");
		dw_size = sizeof(NET_SIS_mall_item);
	}
	INT			nItemNum;
	BYTE		byData[1];				// tagMallItemProto
};

struct NET_SIS_mall_free_item : public tag_net_message
{
	NET_SIS_mall_free_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_free_item");
		dw_size = sizeof(NET_SIS_mall_free_item);
	}
	tagMallFreeItem		freeItem;
};

struct NET_SIS_mall_pack : public tag_net_message
{
	NET_SIS_mall_pack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_pack");
		dw_size = sizeof(NET_SIS_mall_pack);
	}
	INT			nPackNum;
	BYTE		byData[1];
};


//--更新
struct NET_SIC_mall_update : public tag_net_message
{
	NET_SIC_mall_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_update");
		dw_size = sizeof(NET_SIC_mall_update);
	}
	DWORD		dwMallTime;
};

struct NET_SIS_mall_update : public tag_net_message
{
	NET_SIS_mall_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_update");
		dw_size = sizeof(NET_SIS_mall_update);
	}
	DWORD		 dwMallTime;
};

struct NET_SIS_mall_update_item : public tag_net_message
{
	NET_SIS_mall_update_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_update_item");
		dw_size = sizeof(NET_SIS_mall_update_item);
	}
	INT			nItemNum;
	BYTE		byData[1];
};

struct NET_SIS_mall_update_pack : public tag_net_message
{
	NET_SIS_mall_update_pack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_update_pack");
		dw_size = sizeof(NET_SIS_mall_update_pack);
	}
	INT			nItemNum;
	BYTE		byData[1];
};

//--购买
struct NET_SIC_mall_buy_item : public tag_net_message
{
	NET_SIC_mall_buy_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_buy_item");
		dw_size = sizeof(NET_SIC_mall_buy_item);
	}
	DWORD		dw_data_id;				// 商城商品ID
	INT			nPrice;					// 商品价格(玩家购买时的单价)
	INT16		n16BuyNum;				// 购买个数
	BYTE		byIndexInServer;		// 在服务器中的位置		
};

struct NET_SIS_mall_buy_item : public tag_net_message
{
	NET_SIS_mall_buy_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_buy_item");
		dw_size = sizeof(NET_SIS_mall_buy_item);
	}
	DWORD		dw_error_code;
};

struct NET_SIC_mall_buy_pack : public tag_net_message
{
	NET_SIC_mall_buy_pack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_buy_pack");
		dw_size = sizeof(NET_SIC_mall_buy_pack);
	}
	DWORD		dw_data_id;				// 商城商品ID
	INT			nPrice;					// 商品价格(玩家购买时的单价)
	INT16		n16BuyNum;				// 购买个数
	BYTE		byIndexInServer;		// 在服务器中的位置		
};

struct NET_SIS_mall_buy_pack : public tag_net_message
{
	NET_SIS_mall_buy_pack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_buy_pack");
		dw_size = sizeof(NET_SIS_mall_buy_pack);
	}
	DWORD		dw_error_code;
};

//--赠送
struct NET_SIC_mall_present_item : public tag_net_message
{
	NET_SIC_mall_present_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_present_item");
		dw_size = sizeof(NET_SIC_mall_present_item);
	}
	DWORD		dw_data_id;				// 商城商品ID
	INT			nPrice;					// 商品价格(玩家购买时的单价)
	DWORD		dwRoleTgtID;			// 要送的玩家ID
	INT16		n16BuyNum;				// 购买个数
	BYTE		byIndexInServer;		// 在服务器中的位置		
	TCHAR		szLeave[Max_LeaveWord_Length];
};

struct NET_SIS_mall_present_item : public tag_net_message
{
	NET_SIS_mall_present_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_present_item");
		dw_size = sizeof(NET_SIS_mall_present_item);
	}
	DWORD		dw_error_code;
};

struct NET_SIC_mall_present_pack : public tag_net_message
{
	NET_SIC_mall_present_pack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_present_pack");
		dw_size = sizeof(NET_SIC_mall_present_pack);
	}
	DWORD		dw_data_id;				// 商城商品ID
	INT			nPrice;					// 商品价格(玩家购买时的单价)
	DWORD		dwRoleTgtID;			// 要送的玩家ID
	INT16		n16BuyNum;				// 购买个数
	BYTE		byIndexInServer;		// 在服务器中的位置		
	TCHAR		szLeave[Max_LeaveWord_Length];
};

struct NET_SIS_mall_present_pack : public tag_net_message
{
	NET_SIS_mall_present_pack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_present_pack");
		dw_size = sizeof(NET_SIS_mall_present_pack);
	}
	DWORD		dw_error_code;
};

//--免费领取
struct NET_SIC_mall_free_get_item : public tag_net_message
{
	NET_SIC_mall_free_get_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_free_get_item");
		dw_size = sizeof(NET_SIC_mall_free_get_item);
	}
	DWORD		dw_data_id;
};

struct NET_SIS_mall_free_get_item : public tag_net_message
{
	NET_SIS_mall_free_get_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_free_get_item");
		dw_size = sizeof(NET_SIS_mall_free_get_item);
	}
	DWORD		dw_error_code;
};


//--帮派团购
struct NET_SIC_launch_group_purchase : public tag_net_message
{
	NET_SIC_launch_group_purchase()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_launch_group_purchase");
		dw_size = sizeof(NET_SIC_launch_group_purchase);
	}
	DWORD		dw_data_id;				// 商城商品ID
	INT			nPrice;					// 商品价格(玩家购买时的单价)
	BYTE		byScope;				// 团购规模
	BYTE		byIndexInServer;		// 在服务器中的位置
};

struct NET_SIS_launch_group_purchase : public tag_net_message
{
	NET_SIS_launch_group_purchase()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_launch_group_purchase");
		dw_size = sizeof(NET_SIS_launch_group_purchase);
	}
	DWORD		dw_error_code;
};

struct NET_SIC_respond_group_purchase : public tag_net_message
{
	NET_SIC_respond_group_purchase()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_respond_group_purchase");
		dw_size = sizeof(NET_SIC_respond_group_purchase);
	}
	DWORD		dwGuildID;				// 团购信息所属帮派
	DWORD		dw_data_id;				// 商城商品ID
	DWORD		dw_role_id;				// 发起者ID
	INT			nPrice;					// 商品价格(团购总价格)
};

struct NET_SIS_respond_group_purchase : public tag_net_message
{
	NET_SIS_respond_group_purchase()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_respond_group_purchase");
		dw_size = sizeof(NET_SIS_respond_group_purchase);
	}
	DWORD		dw_error_code;
	INT64		nGroupPurchaseKey;		// 团购信息键值(RoleID<<32 | MallID)
};

struct NET_SIC_guild_buy_info : public tag_net_message
{
	NET_SIC_guild_buy_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_buy_info");
		dw_size = sizeof(NET_SIC_guild_buy_info);
	}
};

struct NET_SIS_guild_buy_info : public tag_net_message
{
	NET_SIS_guild_buy_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_buy_info");
		dw_size = sizeof(NET_SIS_guild_buy_info);
	}
	DWORD				dw_error_code;
	INT32				nGroupPurchase;		// 帮派团购指数
	INT					nGPInfoNum;			// 团购信息数量
	tagSimGPInfo		simData[1];			// 回馈的团购信息
};

struct NET_SIC_get_participators : public tag_net_message
{
	NET_SIC_get_participators()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_participators");
		dw_size = sizeof(NET_SIC_get_participators);
	}
	DWORD		dwGuildID;				// 团购信息所属帮派
	DWORD		dw_data_id;				// 商城商品ID
	DWORD		dw_role_id;				// 发起者ID	
};

struct NET_SIS_get_participators : public tag_net_message
{
	NET_SIS_get_participators()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_participators");
		dw_size = sizeof(NET_SIS_get_participators);
	}
	DWORD		dw_error_code;
	INT64		nGroupPurchaseKey;		// 团购信息键值(RoleID<<32 | MallID)
	INT			nParticipatorNum;		// 响应者数量
	DWORD		dwParticipators[1];		// 响应者列表
};


enum ERespondBroadCast
{
	ERespondBroadCast_NULL		= 0,
	ERespondBroadCast_Launch,
	ERespondBroadCast_Success,
	ERespondBroadCast_Lose,
};

struct NET_SIS_respond_broad : public tag_net_message
{
	NET_SIS_respond_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_respond_broad");
		dw_size = sizeof(NET_SIS_respond_broad);
	}
	ERespondBroadCast	eType;
	DWORD				dw_role_id;
	DWORD				dw_data_id;			//物品TypeID
};


//--兑换
struct NET_SIC_mall_item_exchange : public tag_net_message
{
	NET_SIC_mall_item_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_item_exchange");
		dw_size = sizeof(NET_SIC_mall_item_exchange);
	}
	DWORD		dwMallID;				// 商城商品ID
	INT			nPrice;					// 单个物品所需赠点数量
	INT16		n16BuyNum;				// 兑换个数
	BYTE		byIndexInServer;		// 在服务器中的位置		
};

struct NET_SIS_mall_item_exchange : public tag_net_message
{
	NET_SIS_mall_item_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_item_exchange");
		dw_size = sizeof(NET_SIS_mall_item_exchange);
	}
	DWORD		dw_error_code;
};

struct NET_SIC_mall_pack_exchange : public tag_net_message
{
	NET_SIC_mall_pack_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_pack_exchange");
		dw_size = sizeof(NET_SIC_mall_pack_exchange);
	}
	DWORD		dwMallID;				// 商城商品ID
	INT			nPrice;					// 所需赠点数量
	BYTE		byIndexInServer;		// 在服务器中的位置	
};

struct NET_SIS_mall_pack_exchange : public tag_net_message
{
	NET_SIS_mall_pack_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_pack_exchange");
		dw_size = sizeof(NET_SIS_mall_pack_exchange);
	}
	DWORD		dw_error_code;
};

//----------------------------------------------------------------------------
// 元宝交易
//----------------------------------------------------------------------------
// 同步交易账户的元宝数
struct NET_SIS_synchronize_account_yuanbao : public tag_net_message
{
	NET_SIS_synchronize_account_yuanbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_account_yuanbao");
		dw_size = sizeof(NET_SIS_synchronize_account_yuanbao);
	}
	INT			nYuanBao;
};

// 同步交易账户的金钱数
struct NET_SIS_synchronize_account_silver : public tag_net_message
{
	NET_SIS_synchronize_account_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_account_silver");
		dw_size = sizeof(NET_SIS_synchronize_account_silver);
	}
	INT64		nSilver;
};

// 同步交易账户
struct NET_SIS_synchronize_account : public tag_net_message
{
	NET_SIS_synchronize_account()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_account");
		dw_size = sizeof(NET_SIS_synchronize_account);
	}
	INT			nYuanBao;
	INT			nSilver;
};

// 玩家向交易账户存元宝
struct NET_SIC_save_yuanbao_to_account : public tag_net_message
{
	NET_SIC_save_yuanbao_to_account()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_save_yuanbao_to_account");
		dw_size = sizeof(NET_SIC_save_yuanbao_to_account);
	}
	INT			n_num;					// 元宝数量
};

struct NET_SIS_save_yuanbao_to_account : public tag_net_message
{
	NET_SIS_save_yuanbao_to_account()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_save_yuanbao_to_account");
		dw_size = sizeof(NET_SIS_save_yuanbao_to_account);
	}
	DWORD		dw_error_code;
};

// 玩家向交易账户存金钱
struct NET_SIC_save_silver_to_account : public tag_net_message
{
	NET_SIC_save_silver_to_account()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_save_silver_to_account");
		dw_size = sizeof(NET_SIC_save_silver_to_account);
	}
	INT64		n_num;
};

struct NET_SIS_save_silver_to_account : public tag_net_message
{
	NET_SIS_save_silver_to_account()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_save_silver_to_account");
		dw_size = sizeof(NET_SIS_save_silver_to_account);
	}
	DWORD		dw_error_code;
};

// 从交易账户提取元宝
struct NET_SIC_deposit_account_yuanbao : public tag_net_message
{
	NET_SIC_deposit_account_yuanbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_deposit_account_yuanbao");
		dw_size = sizeof(NET_SIC_deposit_account_yuanbao);
	}
	INT			n_num;
};

struct NET_SIS_deposit_account_yuanbao : public tag_net_message
{
	NET_SIS_deposit_account_yuanbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_deposit_account_yuanbao");
		dw_size = sizeof(NET_SIS_deposit_account_yuanbao);
	}
	DWORD		dw_error_code;
};

// 从交易账户提取金钱
struct NET_SIC_deposit_account_silver : public tag_net_message
{
	NET_SIC_deposit_account_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_deposit_account_silver");
		dw_size = sizeof(NET_SIC_deposit_account_silver);
	}
	INT64		n_num;
};

struct NET_SIS_deposit_account_silver : public tag_net_message
{
	NET_SIS_deposit_account_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_deposit_account_silver");
		dw_size = sizeof(NET_SIS_deposit_account_silver);
	}
	DWORD		dw_error_code;
};

// 获取所有元宝交易价格的列表和交易账户信息
struct NET_SIC_synchronize_yuanbao_trade_info : public tag_net_message
{
	NET_SIC_synchronize_yuanbao_trade_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_synchronize_yuanbao_trade_info");
		dw_size = sizeof(NET_SIC_synchronize_yuanbao_trade_info);
	}
};

struct NET_SIS_get_sell_price_list : public tag_net_message
{
	NET_SIS_get_sell_price_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_sell_price_list");
		dw_size = sizeof(NET_SIS_get_sell_price_list);
	}
	INT				nListNum;
	tagYBPriceList	YBPriceList[1];
};

struct NET_SIS_get_buy_price_list : public tag_net_message
{
	NET_SIS_get_buy_price_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_buy_price_list");
		dw_size = sizeof(NET_SIS_get_buy_price_list);
	}
	INT				nListNum;
	tagYBPriceList	YBPriceList[1];
};

// 获得元宝交易账户
struct NET_SIS_get_yuanbao_account : public tag_net_message
{
	NET_SIS_get_yuanbao_account()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_yuanbao_account");
		dw_size = sizeof(NET_SIS_get_yuanbao_account);
	}
	DWORD			dw_role_id;			// 玩家ID
	INT				nYuanBao;			// 元宝数量
	INT64			nSilver;			// 金钱数量
	BOOL			bSellOrder;			// 是否有出售订单
	BOOL			bBuyOrder;			// 是否有收购订单
};

// 同步出售价格列表
struct NET_SIS_synchronize_price_list : public tag_net_message
{
	NET_SIS_synchronize_price_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_price_list");
		dw_size = sizeof(NET_SIS_synchronize_price_list);
	}
	INT				nPrice;
	INT				n_num;
};

// 同步购买价格列表
struct NET_SIS_synchronize_buy_price_list : public tag_net_message
{
	NET_SIS_synchronize_buy_price_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_buy_price_list");
		dw_size = sizeof(NET_SIS_synchronize_buy_price_list);
	}
	INT				nPrice;
	INT				n_num;
};

// 提交元宝出售订单
struct NET_SIC_submit_sell_order : public tag_net_message
{
	NET_SIC_submit_sell_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_submit_sell_order");
		dw_size = sizeof(NET_SIC_submit_sell_order);
	}
	INT				n_num;				// 元宝数量
	INT				nPrice;				// 单价
};

struct NET_SIS_submit_sell_order : public tag_net_message
{
	NET_SIS_submit_sell_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_submit_sell_order");
		dw_size = sizeof(NET_SIS_submit_sell_order);
	}
	DWORD			dw_error_code;
};

// 提交元宝收购订单
struct NET_SIC_submit_buy_order : public tag_net_message
{
	NET_SIC_submit_buy_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_submit_buy_order");
		dw_size = sizeof(NET_SIC_submit_buy_order);
	}
	INT				n_num;
	INT				nPrice;
};

struct NET_SIS_submit_buy_order : public tag_net_message
{
	NET_SIS_submit_buy_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_submit_buy_order");
		dw_size = sizeof(NET_SIS_submit_buy_order);
	}
	DWORD			dw_error_code;
};

 // 获得玩家订单
struct NET_SIC_get_yuanbao_order : public tag_net_message
{
	NET_SIC_get_yuanbao_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_yuanbao_order");
		dw_size = sizeof(NET_SIC_get_yuanbao_order);
	}
};

struct NET_SIS_get_yuanbao_order : public tag_net_message
{
	NET_SIS_get_yuanbao_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_yuanbao_order");
		dw_size = sizeof(NET_SIS_get_yuanbao_order);
	}
	INT             n_num;               // 订单数量
	tagYuanBaoOrder Orders[1];
};

// 删除订单
struct NET_SIC_delete_order : public tag_net_message
{
	NET_SIC_delete_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_order");
		dw_size = sizeof(NET_SIC_delete_order);
	}
	DWORD			dwOrderID;			// 订单ID
	EYBOTYPE		eYBOType;			// 订单类型
};

struct NET_SIS_delete_order : public tag_net_message
{
	NET_SIS_delete_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_order");
		dw_size = sizeof(NET_SIS_delete_order);
	}
	DWORD			dw_error_code;
};


#pragma pack(pop)
#endif