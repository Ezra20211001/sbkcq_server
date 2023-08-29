// 奖励相关

#pragma once


#include "RoleDefine.h"


#pragma pack(push, 1)
	
const int MAX_REWARD_NUMBER = 12;

// 奖励来源
enum E_REWARDFROM
{
	RF_CHONGZHI			= 0, // 充值赠礼
	RF_FENGLU			= 1, // 皇家俸禄
	RF_SHANCI			= 2, // 国王赏赐
	RF_ACTIVE_GONGCHENG = 3, // 攻城奖励
	RF_ACTIVE_ZHANCHANG = 4, // 妖月战场
	RF_ACTIVE_BIWU		= 5, // 比武
	RF_TIAOZHANFUBEN	= 6, // 挑战副本
	RF_ZHENYAOTA		= 7, // 镇妖塔

	RF_NUM,

};
struct tagRewardData
{
	DWORD			dwItemDataID;		//奖励物品id
	DWORD			dwNumber;			//奖励数量
	E_REWARDFROM	nType;				//来源
};


//////////////////////////////////////////////////////////////////////////
//发送奖品数据
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

// 领取奖励
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

// 领奖数据更新
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