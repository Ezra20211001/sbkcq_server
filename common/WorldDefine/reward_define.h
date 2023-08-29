// �������

#pragma once


#include "RoleDefine.h"


#pragma pack(push, 1)
	
const int MAX_REWARD_NUMBER = 12;

// ������Դ
enum E_REWARDFROM
{
	RF_CHONGZHI			= 0, // ��ֵ����
	RF_FENGLU			= 1, // �ʼ�ٺ»
	RF_SHANCI			= 2, // �����ʹ�
	RF_ACTIVE_GONGCHENG = 3, // ���ǽ���
	RF_ACTIVE_ZHANCHANG = 4, // ����ս��
	RF_ACTIVE_BIWU		= 5, // ����
	RF_TIAOZHANFUBEN	= 6, // ��ս����
	RF_ZHENYAOTA		= 7, // ������

	RF_NUM,

};
struct tagRewardData
{
	DWORD			dwItemDataID;		//������Ʒid
	DWORD			dwNumber;			//��������
	E_REWARDFROM	nType;				//��Դ
};


//////////////////////////////////////////////////////////////////////////
//���ͽ�Ʒ����
struct NET_SIC_get_reward_data : public tag_net_message
{
	NET_SIC_get_reward_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_reward_data");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_reward_data : public tag_net_message
{
	NET_SIS_get_reward_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_reward_data");
		dw_size = sizeof(*this);
	}

	tagRewardData st_data[RF_NUM][MAX_REWARD_NUMBER];
};

// ��ȡ����
struct NET_SIC_receive_reward : public tag_net_message
{
	NET_SIC_receive_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_receive_reward");
		dw_size = sizeof(*this);
	}

	E_REWARDFROM byType;
	BYTE		byIndex;
};

struct NET_SIS_receive_reward : public tag_net_message
{
	NET_SIS_receive_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_receive_reward");
		dw_size = sizeof(*this);
	}
	E_REWARDFROM byType;
	BYTE byIndex;
	DWORD dwErrorCode;
};

// �콱���ݸ���
struct NET_SIS_update_reward_data : public tag_net_message
{
	NET_SIS_update_reward_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_reward_data");
		dw_size = sizeof(*this);
	}
	
	E_REWARDFROM byType;
	BYTE byIndex;
	tagRewardData st_data;
};
#pragma pack(pop)