/*******************************************************************************

	Copyright 2010 by tiankong Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef _TEAMSHAREQUST_SERVER_DEFINE_H_
#define _TEAMSHAREQUST_SERVER_DEFINE_H_

#pragma pack(push, 1)

// 获取钱庄最大编号
struct NET_S2DB_DelAllTeamShareQuest : public tag_net_message
{
	NET_S2DB_DelAllTeamShareQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_DelAllTeamShareQuest");
		dw_size = sizeof(*this);
	}
	INT32 nNewFlag;
};

#pragma pack(pop)

#endif /** _TEAMSHAREQUST_SERVER_DEFINE_H_ */