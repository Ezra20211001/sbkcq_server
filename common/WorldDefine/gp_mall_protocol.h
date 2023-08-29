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
*	@file		gp_mall_protocol.h
*	@author		lc
*	@date		2012/07/018	initial
*	@version	0.0.1.0
*	@brief		gp商城协议
*/

#ifndef _GP_MALL_PROTOCOL_H_
#define _GP_MALL_PROTOCOL_H_

#include "..\common\WorldDefine\gp_mall_define.h"

#pragma pack(push, 1)

//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum
{
	E_LOTTERY_NOT_GP			=	1,	// gp不足 //付费抽奖次数已满
	E_LOTTERY_NOT_BAG			=	2,	// 背包空间不足
	E_LOTTERY_NOT_KEY			=	3,	// 没钥匙 //既没有抽奖道具也没有规定数目的指定元宝
	E_LOTTERY_NOT_PP			=	4,  // pp不足
	E_LOTTERY_NOT_SILVER		=	5,  // 金币不足
};

//----------------------------------------------------------------------------
// 抽奖
//----------------------------------------------------------------------------
struct NET_SIC_get_lottery : public tag_net_message
{
	NET_SIC_get_lottery()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_lottery");
		dw_size = sizeof(NET_SIC_get_lottery);
	}
	BYTE	byType; //0:A型  1:B型
	
};

struct NET_SIS_get_lottery : public tag_net_message
{
	NET_SIS_get_lottery()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_lottery");
		dw_size = sizeof(NET_SIS_get_lottery);
	}
	DWORD	dwItemIndex;//获得物品的索引ID
	//DWORD dwItemID;		// 获得物品id
	BYTE	byType;		//0:A型  1:B型
	DWORD dwErrorCode;  // 错误码
	BYTE  bItemNum;		//物品数量
};



#pragma pack(pop)
#endif