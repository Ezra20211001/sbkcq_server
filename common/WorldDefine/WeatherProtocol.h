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
 *	@file		WeatherProtocol
 *	@author		mwh
 *	@date		2012/04/25	initial
 *	@version	0.0.1.0
 *	@brief		天气
*/

#ifndef __WEATHER_H___
#define __WEATHER_H___


enum EWeatherType{
	EWT_UNKNOWN,
	EWT_SUNNY,
	EWT_RAIN,
	EWT_END
};

#pragma  pack(push,1)

// 通知需要改变超级密码
struct NET_SIS_change_Weather: public tag_net_message
{
	NET_SIS_change_Weather()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_Weather");
		dw_size = sizeof(*this);
	}

	DWORD dwMapID;
	DWORD dwInstanceID;
	DWORD dwWeather;
};


#pragma  pack(pop)

#endif /** __WEATHER_H___ */