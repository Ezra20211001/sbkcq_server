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
*	@file		currency_protocol.h
*	@author		lc
*	@date		2011/03/01	initial
*	@version	0.0.1.0
*	@brief		金钱消息
*/

#ifndef CURRENCY_PROTOCOL
#define CURRENCY_PROTOCOL

#include "protocol_common_errorcode.h"

#pragma pack(push, 1)
//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum
{

};

struct NET_SIS_exploits : public tag_net_message
{
	NET_SIS_exploits()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exploits");
		dw_size = sizeof(*this);
	}
	INT32 n32CurExploits;
	INT32 n32ChangeExploits;
};

struct NET_SIS_bag_silver : public tag_net_message
{
	NET_SIS_bag_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bag_silver");
		dw_size = sizeof(NET_SIS_bag_silver);
	}
	INT64		n64CurSilver;		// 当前总的金钱
	INT64		n64ChangeSilver;	// 变化的金钱(正: 获得; 负: 失去)
	BOOL		bBind;				// 0 为非绑定币 1 为绑定币
};

struct NET_SIS_ware_silver : public tag_net_message
{
	NET_SIS_ware_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_ware_silver");
		dw_size = sizeof(NET_SIS_ware_silver);
	}
	INT64		n64CurSilver;		// 当前总的金钱
	INT64		n64ChangeSilver;	// 变化的金钱(正: 获得; 负: 失去)
};

struct NET_SIS_bag_yuanbao : public tag_net_message
{
	NET_SIS_bag_yuanbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bag_yuanbao");
		dw_size = sizeof(NET_SIS_bag_yuanbao);
	}
	INT32		nCurYuanBao;		// 当前总的元宝
	INT32		nChangeYuanBao;		// 变化的元宝
};

struct NET_SIS_baibao_yuanbao : public tag_net_message
{
	NET_SIS_baibao_yuanbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_baibao_yuanbao");
		dw_size = sizeof(NET_SIS_baibao_yuanbao);
	}
	INT32		nCurYuanBao;		// 当前总的元宝
	INT32		nChangeYuanBao;		// 变化的元宝
	BOOL		bBillYuanbao;		// 是否是充值的
};

struct NET_SIS_present_point : public tag_net_message
{
	NET_SIS_present_point()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_present_point");
		dw_size = sizeof(NET_SIS_present_point);
	}
	INT32		nCurExVolume;		// 当前总的赠点
	INT32		nChangeExVolume;	// 变化的赠点
};

struct NET_SIS_gens_contribute : public tag_net_message
{
	NET_SIS_gens_contribute()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_gens_contribute");
		dw_size = sizeof(NET_SIS_gens_contribute);
	}
	BYTE		byClanType;			// 氏族类型
	INT32		nCurClanCon;		// 当前总的贡献
	INT32		nChangeClanCon;		// 变化的贡献
};


//----------------------------------------------------------------------------
#pragma pack(pop)
#endif