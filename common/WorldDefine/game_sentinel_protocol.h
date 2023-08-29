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
*	@file		game_sentinel_protocol.h
*	@author		lc
*	@date		2011/03/04	initial
*	@version	0.0.1.0
*	@brief		反外挂
*/

#ifndef GAME_SENTINEL_PROTOCOL
#define GAME_SENTINEL_PROTOCOL

#pragma pack(push, 1)

//----------------------------------------------------------------------------
// 反外挂消息
//----------------------------------------------------------------------------
struct NET_SIC_game_sentinel : public tag_net_message
{	
	NET_SIC_game_sentinel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_game_sentinel");
		dw_size = sizeof(NET_SIC_game_sentinel);
	}
	INT16	nLen;
	char	chCmd;
	char	chData[1];
};

struct NET_SIS_game_sentinel : public tag_net_message
{
	NET_SIS_game_sentinel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_game_sentinel");
		dw_size = sizeof(NET_SIS_game_sentinel);
	}
	INT16	nLen;
	char	chCmd;
	char	chData[1];
};


#pragma pack(pop)
#endif