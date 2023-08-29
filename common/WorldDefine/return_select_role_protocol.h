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
*	@file		return_select_role_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		返回选人界面消息
*/

#ifndef RETURN_SELECT_ROLE_PROTOCOL
#define RETURN_SELECT_ROLE_PROTOCOL

#pragma pack(push, 1)

#include "protocol_common_errorcode.h"

//-----------------------------------------------------------------------------
// 返回角色选择界面
//-----------------------------------------------------------------------------
struct NET_SIC_return_role_select : public tag_net_message
{
	NET_SIC_return_role_select()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_return_role_select");
		dw_size = sizeof(NET_SIC_return_role_select);
	}
};

struct NET_SIS_return_role_select : public tag_net_message
{
	NET_SIS_return_role_select()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_return_role_select");
		dw_size = sizeof(NET_SIS_return_role_select);
	}
	DWORD		dw_error_code;		// 错误码
};


#pragma pack(pop)
#endif