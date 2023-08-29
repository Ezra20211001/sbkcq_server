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
*	@file		reputation_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		������Ϣ
*/

#ifndef REPUTATION_PROTOCOL
#define REPUTATION_PROTOCOL

#pragma pack(push,1)

#include "reputation.h"

//----------------------------------------------------------------------------
// ��ȡ��ɫ������Ϣ
//----------------------------------------------------------------------------
struct NET_SIC_get_reputation : public tag_net_message
{
	NET_SIC_get_reputation()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_reputation");
		dw_size = sizeof(NET_SIC_get_reputation);
	}
	DWORD					dw_role_id;		//��ɫID
};

struct NET_SIS_get_reputation : public tag_net_message
{
	NET_SIS_get_reputation()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_reputation");
		dw_size = sizeof(NET_SIS_get_reputation);
	}
	DWORD					dw_role_id;		//��ɫID
	tagReputationData		ReputeData;		//��������
};


#pragma pack(pop)
#endif