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
*	@file		grubbao_protocol.h
*	@author		lc
*	@date		2011/03/01	initial
*	@version	0.0.1.0
*	@brief		�ڱ���������Ϣ
*/

#ifndef GRUBBAO_PROTOCOL
#define GRUBBAO_PROTOCOL

#pragma pack(push, 1)

#include "protocol_common_errorcode.h"
#define MAX_CHEST_NUM 16

//��ͨ�ر�ͼ������ʾ
enum ENormalTreasureMap 
{
	ENTM_NULL		= 1,
	ENTM_Nothing,					//һ������
	ENTM_GainMoney,					//��Ǯ����
	ENTM_ConfrontTrap,				//��������
	ENTM_Billiken,					//�����·�
	ENTM_GainOlMap,					//��ù��ϲر�ͼ
	ENTM_GainKey,					//���Կ��
	ENTM_GainOldChest,				//��þ�����
	ENTM_DriftBottle,				//Ư��ƿ
	ENTM_GainLoongSquamaChest,		//������۱���
	ENTM_BadOldSeal,				//�ڻ��Ϲŷ�ӡ
	ENTM_Plutus,					//�����·�
};

//���ϲر�ͼ������ʾ
enum EOldTreasureMap
{
	EOTM_NULL			=1,
	EOTM_Billiken,					//�����·�
	EOTM_GainLoongSquamaChest,		//������۱���
	EOTM_GainChest,					//�������
	EOTM_GainLoongChest,			//�����������
	EOTM_GainFourTreasures,			//����ķ��ı�
	EOTM_GainKey,					//���Կ��
	EOTM_GainRareTreaMap,			//��þ����ر�ͼ
	EOTM_Plutus,					//�ڵ�����ү
	EOTM_DungeonEnter,				//�����ܾ����
	EOTM_BadLoongPulse,				//�������
	EOTM_BadOldSeal,				//�ڻ��Ϲŷ�ӡ
	EOTM_AwakenGods,				//�����Ϲ�֮��
};

//�����ر�ͼ������ʾ
enum ERareTreasureMap
{
	ERTM_NULL			= 1,
	ERTM_GainMoney,					//��Ǯ����
	ERTM_GainRareStuff,				//���ϡ�в�������
	ERTM_GainDelicacyChest,			//��þ��µ�����
	ERTM_GainLoongChest,			//�����������
	ERTM_GainLoongSquamaChest,		//������۱���
	ERTM_GodsOfPractice,			//��֮����
	ERTM_MonsterAttackCity,			//���Ź��﹥�ǻ
	ERTM_DungeonEnter,				//�����ܾ����
	ERTM_AwakenGods,				//�����Ϲ�֮��
};

struct NET_SIC_grubbao : public tag_net_message
{
	NET_SIC_grubbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_grubbao");
		dw_size = sizeof(NET_SIC_grubbao);
	}
	DWORD				dwPlayerID;				//�ڱ���ID
	DWORD				dwItemID;				//����ID
	DWORD				dwItemTypdID;			//�����TypeID
};

struct NET_SIS_grubbao : public tag_net_message
{
	NET_SIS_grubbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_grubbao");
		dw_size = sizeof(NET_SIS_grubbao);
	}
	DWORD				dw_error_code;			//������
	Vector3				v3Pos;					//�����λ��(������ʧ��,������Ч)
};

//��ͨ�ر�ͼ������Ϣ
struct NET_SIS_normal_treasure_map : public tag_net_message
{
	NET_SIS_normal_treasure_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_normal_treasure_map");
		dw_size = sizeof(NET_SIS_normal_treasure_map);
	}
	ENormalTreasureMap	eType;					//��ͨ�ر�ͼ������ʾ
};


//���ϲر�ͼ������Ϣ
struct NET_SIS_old_treasure_map : public tag_net_message
{
	NET_SIS_old_treasure_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_old_treasure_map");
		dw_size = sizeof(NET_SIS_old_treasure_map);
	}
	EOldTreasureMap		eType;					//���ϲر�ͼ������ʾ
};


//�����ر�ͼ������Ϣ
struct NET_SIS_rare_treasure_map : public tag_net_message
{
	NET_SIS_rare_treasure_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_rare_treasure_map");
		dw_size = sizeof(NET_SIS_rare_treasure_map);
	}
	ERareTreasureMap	eType;					//�����ر�ͼ������ʾ
};

//��������FB
struct NET_SIC_enter_adventure : public tag_net_message
{
	NET_SIC_enter_adventure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_enter_adventure");
		dw_size = sizeof(NET_SIC_enter_adventure);
	}
};

struct NET_SIS_enter_adventure : public tag_net_message
{
	NET_SIS_enter_adventure()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_enter_adventure");
		dw_size = sizeof(NET_SIS_enter_adventure);
	}
};

//����
struct NET_SIC_experience : public tag_net_message
{
	NET_SIC_experience()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_experience");
		dw_size = sizeof(NET_SIC_experience);
	}
};

struct NET_SIS_experience : public tag_net_message
{
	NET_SIS_experience()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_experience");
		dw_size = sizeof(NET_SIS_experience);
	}
};


//--------------------------------------------------------------------------------
//����Ϊ������
//--------------------------------------------------------------------------------
enum EChestType
{
	EChestType_NULL			= 0,
	EChestType_LoongSquamaChest,		//���۱���
	EChestType_WackeLoongChest,			//��������
	EChestType_GodLargessChest,			//����͸�����
	EChestType_DestinyBoxChest,			//���˱���
};

struct NET_SIC_treasure_chest : public tag_net_message
{
	NET_SIC_treasure_chest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_treasure_chest");
		dw_size = sizeof(NET_SIC_treasure_chest);
	}
	INT64			n64ChestID;			//����(���۱������������)
	INT64			n64KeyID;			//Կ��
};

struct NET_SIS_treasure_chest : public tag_net_message
{
	NET_SIS_treasure_chest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_treasure_chest");
		dw_size = sizeof(NET_SIS_treasure_chest);
	}
	DWORD			dwChestTypeID;				//�����TypdID
	DWORD			dw_data_id[MAX_CHEST_NUM];	//��ƷID
	INT				n_num[MAX_CHEST_NUM];		//����������
	DWORD			dw_error_code;
};

struct NET_SIC_stop_treasure_chest : public tag_net_message
{
	NET_SIC_stop_treasure_chest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stop_treasure_chest");
		dw_size = sizeof(NET_SIC_stop_treasure_chest);
	}
	INT64			n64ChestID;			//����
	INT64			n64KeyID;			//Կ��
};

struct NET_SIS_stop_treasure_chest : public tag_net_message
{
	NET_SIS_stop_treasure_chest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stop_treasure_chest");
		dw_size = sizeof(NET_SIS_stop_treasure_chest);
	}
	DWORD			dw_data_id;			//��������Ʒ
	INT				n_num;				//����������
	DWORD			dw_error_code;
};

struct NET_SIC_repeat_treasure_chest : public tag_net_message
{	
	NET_SIC_repeat_treasure_chest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_repeat_treasure_chest");
		dw_size = sizeof(NET_SIC_repeat_treasure_chest);
	}
	INT64			n64ChestID;			//����
	INT64			n64KeyID;			//Կ��
};

struct NET_SIS_repeat_treasure_chest : public tag_net_message
{
	NET_SIS_repeat_treasure_chest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_repeat_treasure_chest");
		dw_size = sizeof(NET_SIS_repeat_treasure_chest);
	}
	BYTE			byDestroy;			//�ٻ�Ϊ1,û�ٻ�Ϊ0
	DWORD			dw_error_code;
};

struct NET_SIC_get_treasure_item : public tag_net_message
{
	NET_SIC_get_treasure_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_treasure_item");
		dw_size = sizeof(NET_SIC_get_treasure_item);
	}
	DWORD			dw_data_id;
};

struct NET_SIS_get_treasure_item : public tag_net_message
{
	NET_SIS_get_treasure_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_treasure_item");
		dw_size = sizeof(NET_SIS_get_treasure_item);
	}
	DWORD			dw_error_code;
};

#pragma pack(pop)
#endif