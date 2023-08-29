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
*	@brief		��Ǯ��Ϣ
*/

#ifndef CURRENCY_PROTOCOL
#define CURRENCY_PROTOCOL

#include "protocol_common_errorcode.h"

#pragma pack(push, 1)
//----------------------------------------------------------------------------
// ������ö��
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
	INT64		n64CurSilver;		// ��ǰ�ܵĽ�Ǯ
	INT64		n64ChangeSilver;	// �仯�Ľ�Ǯ(��: ���; ��: ʧȥ)
	BOOL		bBind;				// 0 Ϊ�ǰ󶨱� 1 Ϊ�󶨱�
};

struct NET_SIS_ware_silver : public tag_net_message
{
	NET_SIS_ware_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_ware_silver");
		dw_size = sizeof(NET_SIS_ware_silver);
	}
	INT64		n64CurSilver;		// ��ǰ�ܵĽ�Ǯ
	INT64		n64ChangeSilver;	// �仯�Ľ�Ǯ(��: ���; ��: ʧȥ)
};

struct NET_SIS_bag_yuanbao : public tag_net_message
{
	NET_SIS_bag_yuanbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bag_yuanbao");
		dw_size = sizeof(NET_SIS_bag_yuanbao);
	}
	INT32		nCurYuanBao;		// ��ǰ�ܵ�Ԫ��
	INT32		nChangeYuanBao;		// �仯��Ԫ��
};

struct NET_SIS_baibao_yuanbao : public tag_net_message
{
	NET_SIS_baibao_yuanbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_baibao_yuanbao");
		dw_size = sizeof(NET_SIS_baibao_yuanbao);
	}
	INT32		nCurYuanBao;		// ��ǰ�ܵ�Ԫ��
	INT32		nChangeYuanBao;		// �仯��Ԫ��
	BOOL		bBillYuanbao;		// �Ƿ��ǳ�ֵ��
};

struct NET_SIS_present_point : public tag_net_message
{
	NET_SIS_present_point()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_present_point");
		dw_size = sizeof(NET_SIS_present_point);
	}
	INT32		nCurExVolume;		// ��ǰ�ܵ�����
	INT32		nChangeExVolume;	// �仯������
};

struct NET_SIS_gens_contribute : public tag_net_message
{
	NET_SIS_gens_contribute()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_gens_contribute");
		dw_size = sizeof(NET_SIS_gens_contribute);
	}
	BYTE		byClanType;			// ��������
	INT32		nCurClanCon;		// ��ǰ�ܵĹ���
	INT32		nChangeClanCon;		// �仯�Ĺ���
};


//----------------------------------------------------------------------------
#pragma pack(pop)
#endif