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
*	@file		remove_role_protocol.h
*	@author		lc
*	@date		2011/03/10	initial
*	@version	0.0.1.0
*	@brief		移除人物消息
*/


#ifndef REMOVE_ROLE_PROTOCOL
#define REMOVE_ROLE_PROTOCOL

#include "protocol_common_errorcode.h"

#pragma pack(push, 1)

//----------------------------------------------------------
// 通知客户端删除某个远程玩家或怪物
//----------------------------------------------------------
struct NET_SIS_remove_remote : public tag_net_message
{
	NET_SIS_remove_remote()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_remove_remote");
		dw_size = sizeof(NET_SIS_remove_remote);
	}
	DWORD	dw_role_id[1];
};


#pragma pack(pop)
#endif