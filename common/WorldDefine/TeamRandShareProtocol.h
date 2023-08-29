/*******************************************************************************

	Copyright 2010 by tiankong Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef _TEAM_RAND_SHARE_PROTOCOL_H_
#define _TEAM_RAND_SHARE_PROTOCOL_H_

#include "TeamRandShareDefine.h"

#pragma pack(push, 1)

enum
{
	ETSQ_MemberQuest_InProcess = 1,
	ETSQ_No_More_Quset = 2, //
	ETSQ_Not_JoinTeam  = 3,
	ETSQ_Leader_NotActive = 4,
	ETSQ_Leader_NeedReactive = 5,
};

// mwh 2011-09-06
struct NET_SIC_team_leader_set_share_circle_quest : public tag_net_message
{
	NET_SIC_team_leader_set_share_circle_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_team_leader_set_share_circle_quest");
		dw_size = sizeof(*this);
	}
	BOOL bFlag; 
};
struct NET_SIS_team_set_share_leader_circle_quest : public tag_net_message
{
	NET_SIS_team_set_share_leader_circle_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_team_set_share_leader_circle_quest");
		dw_size = sizeof(*this);
	}
	BOOL bFlag; 
	DWORD dwError;
};


// 请求下一个任务
struct NET_SIC_Get_Team_Share_Quest : public tag_net_message
{
	NET_SIC_Get_Team_Share_Quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Get_Team_Share_Quest");
		dw_size = sizeof(*this);
	}
	DWORD dwNPCID;
};

struct NET_SIS_Get_Team_Share_Quest : public tag_net_message
{
	NET_SIS_Get_Team_Share_Quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Get_Team_Share_Quest");
		dw_size = sizeof(*this);
	}
	UINT16 u16QuestID;
	DWORD dwError;
	INT serial;
	BOOL  bFlag;
};

#pragma pack(pop)

#endif /** _TEAM_RAND_SHARE_PROTOCOL_H_ */