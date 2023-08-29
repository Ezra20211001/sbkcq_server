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
 *	@file		auto_kill_protocol
 *	@author		mwh
 *	@date		2011/08/01	initial
 *	@version	0.0.1.0
 *	@brief		自动打怪处理
*/


#ifndef __AUTO_KILL_PROTOCOL_H__
#define __AUTO_KILL_PROTOCOL_H__

#pragma pack(push, 1)

const INT AUTO_KILL_LEVEL_MIN = 40;
const INT AUTO_DEC_VIGOUR = -1;
const INT AUTO_KILL_DEC_VIGOUR_TICK = TICK_PER_SECOND * 60;
enum
{
	EAutoKill_OutOfVigour = 1, // 元气值不足
	EAutoKill_OutOfLevel40 = 2, // 等级不足40级
};

// 开始自动打怪
struct NET_SIC_Auto_Kill_Start : public tag_net_message
{
	NET_SIC_Auto_Kill_Start()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Auto_Kill_Start");
		dw_size = sizeof(*this);
	}

	DWORD dw_safe_code; //安全码
};

struct NET_SIS_Auto_Kill_Start : public tag_net_message
{
	NET_SIS_Auto_Kill_Start()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Auto_Kill_Start");
		dw_size = sizeof(*this);
	}
	DWORD dwErrorCode;
};

// 结束自动打怪
struct NET_SIC_Auto_Kill_End : public tag_net_message
{
	NET_SIC_Auto_Kill_End()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Auto_Kill_End");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_Auto_Kill_End : public tag_net_message
{
	NET_SIS_Auto_Kill_End()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Auto_Kill_End");
		dw_size = sizeof(*this);
	}
	DWORD dwErrorCode;
};


#pragma pack(pop)


#endif // __AUTO_KILL_PROTOCOL_H__