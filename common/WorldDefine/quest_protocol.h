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
*	@file		quest_protocol.h
*	@author		lc
*	@date		2011/03/10	initial
*	@version	0.0.1.0
*	@brief		������Ϣ
*/


#ifndef QUEST_PROTOCOL
#define QUEST_PROTOCOL

#include "protocol_common_errorcode.h"
#include "QuestDef.h"
#pragma pack(push, 1)

//�����ȡʧ��ԭ��
enum
{
	E_QUEST_NOT_EXIST								= 1,		//���񲻴���
	E_QUEST_NPC_NOT_EXIST							= 2,		//����NPC������
	E_QUEST_NPC_TOO_FAR								= 3,		//����NPC����Ҿ���̫Զ
	E_QUEST_FAILED_ADD 								= 4,        //��������ʧ��
	E_QUEST_FATIGUEGUARD							= 5,		//�����Ա���
	
	E_CanTakeQuest_FAILED_LOW_LEVEL					= 11,		//û���㹻�ĵȼ�
	E_CanTakeQuest_FAILED_LOW_REP					= 12,		//û���㹻������
	E_CanTakeQuest_ALREADY_DONE						= 13,		//�Ѿ������
	E_CanTakeQuest_ALREADY_TAKE						= 14,		//�Ѿ���ȡ��
	E_CanTakeQuest_FAILED_MISSING_ITEMS				= 15,		//û����������Ҫ����Ʒ
	E_CanTakeQuest_FAILED_MISSING_SKILLS			= 16,		//û����������Ҫ�ļ���
	E_CanTakeQuest_FAILED_MISSING_Att				= 17,		//û����������Ҫ����������
	E_CanTakeQuest_FAILED_WRONG_SEX					= 18,       //��������Ҫ���Ա�
	E_CanTakeQuest_FAILED_WRONG_CLASS				= 19,       //��������Ҫ��ְҵ
	E_CanTakeQuest_FAILED_NOT_ENOUGH_MONEY			= 20,       //û����������Ҫ�Ľ�Ǯ
	E_CanTakeQuest_FAILED_QUEST_NUM_FULL			= 21,		//�������ˣ������ٽ�
	E_CanTakeQuest_FAILED_WRONG_MAP 				= 22, 		//��ͼ����
	E_CanTakeQuest_FAILED_PREV 						= 23,      	//����ǰ�򲻶�
	E_CanTakeQuest_FAILED_NEXT 						= 24,      	//�����������
	E_CanTakeQuest_FAILED_WRONG_TIME 				= 25,       //����ʱ�䲻��
	E_CanTakeQuest_FAILED_WRONG_TIMES 				= 26,       //�����ȡ��������
	E_CanTakeQuest_FAILED_MISS_ITEM_OF_QUEST 		= 27,       //û��������Ʒ
	E_CanTakeQuest_FAILED_WRONG_TRIGGER 			= 28,       //���񴥷�������
	E_CanTakeQuest_FAILED_SCRIPT					= 29,		//�ű��ж�ʧ�ܣ��ͻ��˲��ṩ������ʾ��������ֱ�ӷ���

	E_CanCompleteQuest_FAILED_MISSING_Creature		= 30,		//û�������������Ҫ������
	E_CanCompleteQuest_FAILED_MISSING_NPC			= 31,		//û�������������Ҫ��NPC
	E_CanCompleteQuest_FAILED_MISSING_ITEMS			= 32,		//û�������������Ҫ����Ʒ
	E_CanCompleteQuest_FAILEDENOUGH_MONEY			= 33,		//û�������������Ҫ�Ľ�Ǯ
	E_CanCompleteQuest_BAG_FULL						= 34,		//����û�еط������ý�����Ʒ
	E_CanCompleteQuest_FALIED_SCRIPT				= 35,		//�ű��ж�ʧ�ܣ��ͻ��˲��ṩ������ʾ��������ֱ�ӷ���

	E_CanTakeQuest_Tomorrow							= 36,		//ÿ��ֻ�����һ��
	E_CanTakeQuest_Week								= 37,		//ֻ�������ڡ����

	E_CanUpdateQuest_Fail							= 40,		//���ܸ���

	E_TakeLoopQuest_Failed_Num_Full 				= 41,		//ѭ�������������
	
	EGDE_Put_Already								= 42,		// �Ѿ���������
	EGDE_Put_Cant									= 43,		// �������͸�����
	EGDE_Put_OutOfNumber							= 44,		// �Ѿ��ﵽ�����
	EGDE_Put_OutOfMoney								= 45,		// Ǯ���������͸�����
	EGDE_Put_OutOfYuanBao							= 46,		// Ԫ������
	EGDE_Put_CheckItem								= 47,		// ���齱����Ʒ
	EGDE_Get_NotExist								= 48,		// �������񲻴���
	EGDE_Get_BeTaked								= 49,		// �Ѿ�����ȡ
	EGDE_Get_Already								= 50,		// �Ѿ���ȡͬ����������
	EGDE_Get_OutOfNumber							= 51,		// �Ѿ��ﵽ����ȡ��
	EGDE_Get_OutOfMoney								= 52,		// Ǯ�����Խ�ȡ������
	EGDE_NotBelongYou								= 53,		// ��������������
	EGDE_CantGiveUp									= 54,		// ���ܷ�������
	EGDE_OnlyReciverComplete						= 55,		// ֻ�н�ȡ�߲��������������
	EGDE_CantCancelPut								= 56,		// ����ȡ����������
	EGDE_Get_OutOfVigour							= 57,		// Ԫ��ֵ����
	EGDE_Get_OutOfLevel25						= 58,		// �ȼ�����25,���ܽ�ȡ����

	E_FAILED_QUEST_FORBID_DELETE					= 60,		//����ɾ��
	E_Failed_Track_Number_Max						= 61,		// ����׷��
	E_CanTakeQuest_FAILED_BAGFULL					= 62,		// �����������޷���ȡ������
	E_CanTakeQuest_FAILED_GUILD						= 63,		// ��Ҫ������ 
	E_CanTakeQuest_FAILED_MASTER					= 64,		// ��Ҫ��ʦ��
	E_CanTakeQuest_FAILED_PRENTICE					= 65,		// ��Ҫ��ͽ��
	E_CanTakeQuest_FAILED_OnlyBangZhu				= 66,		// �������ܽ�ȡ

	E_CanCompleteQuest_NotCompleteAll				= 67,  		//δ�����������
	E_CanTakeQuest_FAILED_GUILD_LEVEL				= 68,		// ���û���㹻�ȼ�

	EBuyFreshNumFull	=	69,
	EBuyFreshNumOutOfMoney	=	70,
	EBuyFreshNumOutOfNum	=	71,

	E_CanTakeQuest_FAILED_CantHasItem = 72,				// ӵ��ĳ�����߲��ܽ�ȡ������
	E_CanTakeQuest_FAILED_VIP_LEVEL = 73,				// VIP�ȼ�����

	E_Quset_Error_Max,
};
//-----------------------------------------------------------------------------
//	�Ƿ���Խ�ȡ������
//-----------------------------------------------------------------------------
struct NET_SIC_npc_accept_quest : public tag_net_message
{
	NET_SIC_npc_accept_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id =  message_id_crc("NET_SIC_npc_accept_quest");
		dw_size = sizeof(NET_SIC_npc_accept_quest);
	}
	DWORD		dwNPCID;		// ��ȡ����NPCΨһID 
	UINT16		u16QuestID;		// ����ID
};


//-----------------------------------------------------------------------------
//	��������ȡ����
//-----------------------------------------------------------------------------
struct NET_SIC_trigger_accept_quest : public tag_net_message
{
	NET_SIC_trigger_accept_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_trigger_accept_quest");
		dw_size = sizeof(NET_SIC_trigger_accept_quest);
	}
	UINT16		u16QuestID;		// ����ID
	DWORD		dwTriggerID;	// ������ID
};

struct NET_SIS_accept_quest : public tag_net_message
{
	NET_SIS_accept_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_accept_quest");
		dw_size = sizeof(NET_SIS_accept_quest);
	}
	UINT16		u16QuestID;		// ����ID
	DWORD		dw_error_code;	// ������
};

struct NET_SIS_add_quest : public tag_net_message
{
	NET_SIS_add_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_quest");
		dw_size = sizeof(NET_SIS_add_quest);
	}
	UINT16		u16QuestID;							// ����ID
	DWORD		dwFlag;								//�����Ƿ�׷��
	//gx modify 2013.5.13
	/*INT16		n16ItemCount[QUEST_ITEMS_COUNT];	// ��Ʒ����׷������
	tagQuestDynamicTarget	DynamicTarget;			// ��̬Ŀ������Żᷢ���ͻ���
	tagQuestDynamicReward	DynamicReward;			// ����̬����
	tagScriptQuestVar		ScriptSetData;			// �ű���������*/
	//end
};

//-----------------------------------------------------------------------------
//	�Ƿ������ɴ�����
//-----------------------------------------------------------------------------
struct NET_SIC_complete_quest : public tag_net_message
{
	NET_SIC_complete_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_complete_quest");
		dw_size = sizeof(NET_SIC_complete_quest);
	}
	DWORD		dwNPCID;					// �������NPCΨһID 
	UINT16		u16QuestID;					// ����ID
	INT32		nRewChoicesItemIndex;		// ��ѡ������Ʒ���
	DWORD		dw_safe_code;
};

struct NET_SIS_complete_quest : public tag_net_message
{
	NET_SIS_complete_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_complete_quest");
		dw_size = sizeof(NET_SIS_complete_quest);
	}
	UINT16		u16QuestID;					// ����ID
	DWORD		dw_error_code;				// ������
};


//-----------------------------------------------------------------------------
//	�Ƿ����ɾ������
//-----------------------------------------------------------------------------
struct NET_SIC_delete_quest : public tag_net_message
{
	NET_SIC_delete_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_quest");
		dw_size = sizeof(NET_SIC_delete_quest);
	}
	UINT16		u16QuestID;					// ɾ������ID
};

struct NET_SIS_delete_quest : public tag_net_message
{
	NET_SIS_delete_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_quest");
		dw_size = sizeof(NET_SIS_delete_quest);
	}
	UINT16		u16QuestID;					// ����ID
	DWORD		dw_error_code;				// ������
};


//-----------------------------------------------------------------------------
//	��������NPC�Ի�����
//-----------------------------------------------------------------------------
struct NET_SIC_update_quest_npc_talk : public tag_net_message
{
	NET_SIC_update_quest_npc_talk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_update_quest_npc_talk");
		dw_size = sizeof(NET_SIC_update_quest_npc_talk);
	}
	DWORD		dwNPCID;						// ��������NPCΨһID 
	UINT16		u16QuestID;						// ��������ID
};


//-----------------------------------------------------------------------------
//	����ɱ����������
//-----------------------------------------------------------------------------
struct NET_SIS_quest_update_kill_creature : public tag_net_message
{
	NET_SIS_quest_update_kill_creature()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_update_kill_creature");
		dw_size = sizeof(NET_SIS_quest_update_kill_creature);
	}
	UINT16		u16QuestID;						// ����ID
	INT			nCreatureIndex;					// �������
	INT16		n16NewKillNum;					// ���¹����ɱ�ּ���
};


//-----------------------------------------------------------------------------
//	������Ʒ��������
//-----------------------------------------------------------------------------
struct NET_SIS_quest_update_item : public tag_net_message
{
	NET_SIS_quest_update_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_update_item");
		dw_size = sizeof(NET_SIS_quest_update_item);
	}
	UINT16		u16QuestID;						// ����ID
	INT			nItemIndex;						// ��Ʒ���
	INT16		n16NewItemNum;					// ���¹������Ʒ����
};

//-----------------------------------------------------------------------------
// ����NPC�Ի���������
//-----------------------------------------------------------------------------
struct NET_SIS_quest_update_npc_talk : public tag_net_message
{
	NET_SIS_quest_update_npc_talk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_update_npc_talk");
		dw_size = sizeof(NET_SIS_quest_update_npc_talk);
	}
	UINT16		u16QuestID;						// ����ID
	DWORD		dw_error_code;					// ������
	INT			nIndex;							// ĳ������
};

//-----------------------------------------------------------------------------
// ����Trigger��������
//-----------------------------------------------------------------------------
struct NET_SIS_quest_update_trigger : public tag_net_message
{
	NET_SIS_quest_update_trigger()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_update_trigger");
		dw_size = sizeof(NET_SIS_quest_update_trigger);
	}
	UINT16		u16QuestID;						// ����ID
	INT			nIndex;							// ĳ������
};

//-----------------------------------------------------------------------------
// ���µ��������������
//-----------------------------------------------------------------------------
struct NET_SIS_quest_update_inveset : public tag_net_message
{
	NET_SIS_quest_update_inveset()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_update_inveset");
		dw_size = sizeof(NET_SIS_quest_update_inveset);
	}
	UINT16		u16QuestID;
	INT			nIndex;
};


//-----------------------------------------------------------------------------
// �������������Ϣ
//-----------------------------------------------------------------------------
struct NET_SIS_quest_faild_message : public tag_net_message
{
	NET_SIS_quest_faild_message()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_faild_message");
		dw_message_id = sizeof(NET_SIS_quest_faild_message);
	}
	UINT16		u16QuestID;						// ����ID
	TCHAR		szMsg[1];						// ����������Ϣ
};

struct NET_SIS_quest_faild : public tag_net_message
{
	NET_SIS_quest_faild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_faild");
		dw_size = sizeof(NET_SIS_quest_faild);
	}
	UINT16 u16QuestID;
};

struct NET_SIS_quest_var_value : public tag_net_message
{
	NET_SIS_quest_var_value()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_var_value");
		dw_size = sizeof(NET_SIS_quest_var_value);
	}
	UINT16 u16QuestID;
	UINT16 VarID;
	INT16  VarValue;
};

// ����׷������
struct NET_SIC_set_quest_track : public tag_net_message
{
	NET_SIC_set_quest_track()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_quest_track");
		dw_size = sizeof(NET_SIC_set_quest_track);
	}
	UINT16 u16QuestID;
	BYTE  byTrack;
};
struct NET_SIS_set_quest_track : public tag_net_message
{
	NET_SIS_set_quest_track()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_quest_track");
		dw_size = sizeof(NET_SIS_set_quest_track);
	}
	UINT16 u16QuestID;
	DWORD dwCode; // E_Failed_Track_Number_Max or E_SUCCESS
};

// ����������û�л����Ʒ
struct NET_SIS_quest_inves_faild : public tag_net_message
{
	NET_SIS_quest_inves_faild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_quest_inves_faild");
		dw_size = sizeof(NET_SIS_quest_inves_faild);
	}
};
// ����������б�
struct NET_SIC_CircleQuestList : public tag_net_message
{
	NET_SIC_CircleQuestList()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_CircleQuestList");
		dw_size = sizeof(NET_SIC_CircleQuestList);
	}
	DWORD dwNpcID;
};

struct NET_SIS_CircleQuestList : public tag_net_message
{
	NET_SIS_CircleQuestList()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_CircleQuestList");
		dw_size = sizeof(NET_SIS_CircleQuestList);
	}
	BYTE byNumber;
	BYTE byRefreshLeft;
	BYTE byCircleNumberLeft;
	BYTE byCircleNumberBuyLeft;
	UINT16 u16QuestID[CIRCLEQUESTMAXNUMBER];
};

//! ˢ�»����
struct NET_SIC_RefreshCircleQuest : public tag_net_message
{
	NET_SIC_RefreshCircleQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_RefreshCircleQuest");
		dw_size = sizeof(*this);
	}
	DWORD dwNpcID;
	UINT16 u16QuestID;
};

//! ����ˢ�´���
struct NET_SIC_BuyRefreshCircleQuest : public tag_net_message
{
	NET_SIC_BuyRefreshCircleQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_BuyRefreshCircleQuest");
		dw_size = sizeof(*this);
	}
	DWORD dwNpcID;
};

struct NET_SIS_BuyRefreshCircleQuest : public tag_net_message
{
	NET_SIS_BuyRefreshCircleQuest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_BuyRefreshCircleQuest");
		dw_size = sizeof(*this);
	}
	DWORD dwError; // 0 ; �ɹ� 1:�ﵽ�����
};

//! �����������
struct NET_SIC_BuyCircleQuestPerdayNumber : public tag_net_message
{
	NET_SIC_BuyCircleQuestPerdayNumber()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_BuyCircleQuestPerdayNumber");
		dw_size = sizeof(*this);
	}
	DWORD dwNpcID;
};


#pragma pack(pop)
#endif
