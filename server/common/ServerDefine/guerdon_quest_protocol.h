/*******************************************************************************

	Copyright 2010 by tiankong Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef __GUERDON_QUEST_SERVER_PROTOCOL_H__
#define __GUERDON_QUEST_SERVER_PROTOCOL_H__

#include "../../common/WorldDefine/guerdon_quest_define.h"

#pragma pack(push,1)

#define LOADALLGDQUESTBUFFER_MAX 10*1024*1024
#define LOADALLGDQUESTREWARDBUFFER_MAX 10*1024*1024


// 所有悬赏+任务
struct NET_DB2S_LoadAllGuerdonQuest : public tag_net_message
{
	NET_DB2S_LoadAllGuerdonQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_LoadAllGuerdonQuest");
		dw_size = sizeof(*this);
	}
};
struct NET_DB2C_LoadAllGuerdonQuest : public tag_net_message
{
	NET_DB2C_LoadAllGuerdonQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_LoadAllGuerdonQuest");
		dw_size = sizeof(*this);
	}
	INT nNumber;
	guerdon_quest stData[1];
};

// 所有物品
struct NET_DB2S_LoadAllGuerdonReward : public tag_net_message
{
	NET_DB2S_LoadAllGuerdonReward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_LoadAllGuerdonReward");
		dw_size = sizeof(*this);
	}
};
struct NET_DB2C_LoadAllGuerdonReward : public tag_net_message
{
	NET_DB2C_LoadAllGuerdonReward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_LoadAllGuerdonReward");
		dw_size = sizeof(*this);
	}
	INT nNumber;
	BYTE byData[1];
};

// 
struct NET_DB2S_AddNewGuerdonQuest : public tag_net_message
{
	NET_DB2S_AddNewGuerdonQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_AddNewGuerdonQuest");
		dw_size = sizeof(*this);
	}
	guerdon_quest stData;
};

struct NET_DB2S_UpdateGuerdonQuest : public tag_net_message
{
	NET_DB2S_UpdateGuerdonQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_UpdateGuerdonQuest");
		dw_size = sizeof(*this);
	}
	// 64位ID
	INT64 n64Serial;
	// 接单者RoleID
	DWORD dwReciver;
	// 状态
	EGuerdonQuestState eState;
};

//
struct NET_DB2S_DelGuerdonQuest : public tag_net_message
{
	NET_DB2S_DelGuerdonQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_DelGuerdonQuest");
		dw_size = sizeof(*this);
	}
	// 64位ID
	INT64 n64Serial;
};

// 
struct NET_DB2S_SaveCreatureKillGD : public tag_net_message
{
	NET_DB2S_SaveCreatureKillGD()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_SaveCreatureKillGD");
		dw_size = sizeof(*this);
	}
	DWORD dwRoleID;
	UINT16 u16QuestID;
	INT16 n16MonsterNum[QUEST_CREATURES_COUNT];
};

//
struct NET_DB2S_UpdateRoleQuestFlag : public tag_net_message
{
	NET_DB2S_UpdateRoleQuestFlag()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_UpdateRoleQuestFlag");
		dw_size = sizeof(*this);
	}
	DWORD dwRoleID;
	UINT16 u16QuestID;
	DWORD dwFlag;
	DWORD dwFlagEx;
};

//
struct NET_DB2S_InsertQuestRewardItem : public tag_net_message
{
	NET_DB2S_InsertQuestRewardItem()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_InsertQuestRewardItem");
		dw_size = sizeof(*this);
	}
	DWORD dwSender;
	UINT16 u16QuestID;
	INT64 n64Serial; // 奖励物品
	BYTE  byContainerType; // 容器类型
};

//
struct NET_DB2S_DeleteQuestRewardItem : public tag_net_message
{
	NET_DB2S_DeleteQuestRewardItem()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_DeleteQuestRewardItem");
		dw_size = sizeof(*this);
	}
	DWORD dwOwner;
	DWORD dwAccountID;
	INT64 n64Serial; // 奖励物品
	BYTE  byContainerType; // 容器类型
};

#pragma pack(pop)

#endif //__GUERDON_QUEST_SERVER_PROTOCOL_H__