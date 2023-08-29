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
*	@file		script_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		脚本消息
*/

#ifndef SCRIPT_PROTOCOL
#define SCRIPT_PROTOCOL

#pragma pack(push, 1)

enum EMsgUnitType;
enum EDlgOption;

//-----------------------------------------------------------------------------
// NS_ScriptBroad中dwMisc字段的位类型定义
//-----------------------------------------------------------------------------
struct NET_SIS_message_blob : public tag_net_message
{
	NET_SIS_message_blob()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_message_blob");
		dw_size = sizeof(NET_SIS_message_blob);
	}
	BYTE byData[1];
};

//-----------------------------------------------------------------------------
// 客户端对话框发给服务的缺省消息
//-----------------------------------------------------------------------------
struct NET_SIC_dialog_default_message : public tag_net_message
{
	NET_SIC_dialog_default_message()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_dialog_default_message");
		dw_size = sizeof(NET_SIC_dialog_default_message);
	}
	EMsgUnitType	eDlgTarget;				// 客户端对话框操作所对应的目标（任务，物品， 玩家）
	DWORD			dwTargetID;				// 目标ID
	EDlgOption		eDlgOption;				// 玩家返回的对话框选项
};

//只有单RoleID
struct NET_SIS_message_broab_blob : public tag_net_message
{
	NET_SIS_message_broab_blob()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_message_broab_blob");
		dw_size = sizeof(NET_SIS_message_broab_blob);
	}
	BYTE byData[1];
};

//-----------------------------------------------------------------------------
// 客户端触发服务器脚本的缺省消息
//-----------------------------------------------------------------------------
struct NET_SIC_default_request : public tag_net_message
{
	NET_SIC_default_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_default_request");
		dw_size = sizeof(NET_SIC_default_request);
	}
	EMsgUnitType	eDlgTarget;				// 触发服务器脚本的对应目标（固定活动）
	DWORD			dwTargetID;				// 目标ID
	DWORD			dwEventType;			// 触发的事件类型
};


#pragma pack(pop)
#endif