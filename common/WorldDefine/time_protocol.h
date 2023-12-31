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
*	@file		time_protocol.h
*	@author		lc
*	@date		2011/03/10	initial
*	@version	0.0.1.0
*	@brief		ʱ����Ϣ
*/

#ifndef TIME_PROTOCOL
#define TIME_PROTOCOL

#pragma pack(push,1)

struct NET_SIS_synchronize_time : public tag_net_message
{
	NET_SIS_synchronize_time()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_time");
		dw_size = sizeof(NET_SIS_synchronize_time);
	}
	DWORD dw_time;
};


#pragma pack(pop)
#endif