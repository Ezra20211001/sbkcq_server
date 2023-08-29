/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef __GUERDON_QUEST_PROTOCOL_H__
#define __GUERDON_QUEST_PROTOCOL_H__

#include "quest_protocol.h"
#include "guerdon_quest_define.h"

#pragma pack(push,1)

// ��������<�����˷���>
struct NET_SIC_PutGDQuest : public tag_net_message
{
	NET_SIC_PutGDQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_PutGDQuest");
		dw_size = sizeof(*this);
	}
	UINT16 u16QuestID;
	BYTE byHour;
	BYTE byYuanBao;
	BOOL bGuildFix;
	INT64 n64Item0;
	INT64 n64Item1;
	DWORD dw_safe_code;
};

// ��������<��Ӧ������>
struct NET_SIS_PutGDQuest : public tag_net_message
{
	NET_SIS_PutGDQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_PutGDQuest");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
	UINT16 u16QuestID;
};
// �·�������������<��������ʱ����>
struct NET_SIS_NewGuerdonQuest : public tag_net_message
{
	NET_SIS_NewGuerdonQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_NewGuerdonQuest");
		dw_size = sizeof(*this);
	}
	guerdon_quest_data stData;
};
// ȡ������<�����˷���>
struct NET_SIC_CancelPutGDQuest : public tag_net_message
{
	NET_SIC_CancelPutGDQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_CancelPutGDQuest");
		dw_size = sizeof(*this);
	}
	INT64 n64Serial;
};

// ȡ������<��Ӧ������>
struct NET_SIS_CancelPutGDQuest : public tag_net_message
{
	NET_SIS_CancelPutGDQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_CancelPutGDQuest");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
	UINT16 u16QuestID;
	INT64 n64Serial;
};

// ��ȡ����<��ȡ��>
struct NET_SIC_GetGDQuest : public tag_net_message
{
	NET_SIC_GetGDQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_GetGDQuest");
		dw_size = sizeof(*this);
	}
	INT64 n64Serial;
};
struct NET_SIS_GetGDQuest : public tag_net_message
{
	NET_SIS_GetGDQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_GetGDQuest");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
	INT64 n64Serial;
};

//// ��������<�ͻ��˲�Ҫ��������ʹ��ԭ�з���������Ϣ>
//struct NET_SIC_GiveUpGDQuest : public tag_net_message
//{
//	NET_SIC_GiveUpGDQuest()
//	{
//		ZeroMemory(this, sizeof(*this));
//		dw_message_id = message_id_crc("NET_SIC_GiveUpGDQuest");
//		dw_size = sizeof(*this);
//	}
//	UINT16 u16QuestID;
//};
//  ��������<��ȡ�ˡ�������>
struct NET_SIS_GiveUpGDQuest : public tag_net_message
{
	NET_SIS_GiveUpGDQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_GiveUpGDQuest");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
	INT64 n64Serial;
};

// �������<�ͻ��˲�Ҫ��������ʹ��ԭ�����������Ϣ>
struct NET_SIC_CompleteGDQuest : public tag_net_message
{
	NET_SIC_CompleteGDQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_CompleteGDQuest");
		dw_size = sizeof(*this);
	}
	UINT16 u16QuestID;
	INT choice_index;
	DWORD dwNPCID;
};
// �������<��ȡ�����>
struct NET_SIS_CompleteGDQuest : public tag_net_message
{
	NET_SIS_CompleteGDQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_CompleteGDQuest");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
	INT64 n64Serial;
};

// ֪ͨ���������<������>
struct NET_SIS_GDQuestCompleteByReciver : public tag_net_message
{
	NET_SIS_GDQuestCompleteByReciver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_GDQuestCompleteByReciver");
		dw_size = sizeof(*this);
	}
	UINT16 u16QuestID;
	INT64 n64Serial;
};

// ���͹���<��ȡ�ˡ�������>
struct NET_SIS_GDQuestTimeOut : public tag_net_message
{
	NET_SIS_GDQuestTimeOut()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_GDQuestTimeOut");
		dw_size = sizeof(*this);
	}
	UINT16 u16QuestID;
	INT64 n64Serial;
};

// ȡ��һҳ����<�κ���>
struct NET_SIC_GetOnePageGuerdonQuest : public tag_net_message
{
	NET_SIC_GetOnePageGuerdonQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_GetOnePageGuerdonQuest");
		dw_size = sizeof(*this);
	}
	BYTE byPage;
};

struct NET_SIS_GetOnePageGuerdonQuest : public tag_net_message
{
	NET_SIS_GetOnePageGuerdonQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_GetOnePageGuerdonQuest");
		dw_size = sizeof(*this);
	}
	INT nNumber;
	BOOL bHasNext;
	BYTE  byPage;
	guerdon_quest_data stData[1];
};

// �����ҷ���������
struct NET_SIC_UpdateMyPutGuerdonQuest : public tag_net_message
{
	NET_SIC_UpdateMyPutGuerdonQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_UpdateMyPutGuerdonQuest");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_UpdateMyPutGuerdonQuest : public tag_net_message
{
	NET_SIS_UpdateMyPutGuerdonQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_UpdateMyPutGuerdonQuest");
		dw_size = sizeof(*this);
	}
	BYTE byNumber; // stData����
	guerdon_quest_data stData[MAXGDQUEST];
};

// �����ҽ�ȡ������
struct NET_SIC_UpdateMyGetGuerdonQuest : public tag_net_message
{
	NET_SIC_UpdateMyGetGuerdonQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_UpdateMyGetGuerdonQuest");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_UpdateMyGetGuerdonQuest : public tag_net_message
{
	NET_SIS_UpdateMyGetGuerdonQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_UpdateMyGetGuerdonQuest");
		dw_size = sizeof(*this);
	}
	BYTE byNumber; // stData����
	guerdon_quest_data stData[MAXGDQUEST];
};

//  ��������״̬flag
struct NET_SIS_UpdateQuestFlag : public tag_net_message
{
	NET_SIS_UpdateQuestFlag()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_UpdateQuestFlag");
		dw_size = sizeof(*this);
	}
	UINT16 u16QuestID;
	DWORD dwFlag;
};


#pragma pack(pop)


#endif //__GUERDON_QUEST_PROTOCOL_H__
