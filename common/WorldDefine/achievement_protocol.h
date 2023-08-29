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
*	@file		achievement_protocol.h
*	@author		lc
*	@date		2011/07/21	initial
*	@version	0.0.1.0
*	@brief		�ɾ�ϵͳ��Ϣ
*/

#ifndef _ACHIVEEMENT_PROTOCOL_H_
#define	_ACHIVEEMENT_PROTOCOL_H_


//#include "achievement_define.h"

#pragma pack(push, 1)


// ����ɵĳɾ�
struct tagCompletedAchievementData
{
	DWORD	ID;				// �ɾ�id
	DWORD	date;			// ���ʱ��
};

// ������Ϣ�ṹ
struct tagCriteriaProgress
{
	DWORD	ID;				// ����id
	DWORD	date;			// ʱ��
	DWORD	counter;		// ����
};


//! ��ʼ������ɳɾ��б�
struct NET_SIS_init_achievement : public tag_net_message
{
	NET_SIS_init_achievement()
	{ 
		ZeroMemory(this, sizeof(*this)); 
		dw_message_id = message_id_crc("NET_SIS_init_achievement");
		dw_size = sizeof(NET_SIS_init_achievement);
	}
	INT		n_num;		  // ����
	tagCompletedAchievementData	completeAchData[1];
};

//! ��ʼ���ɾ������б�
struct NET_SIS_init_achievement_criteria : public tag_net_message
{
	NET_SIS_init_achievement_criteria()
	{ 
		ZeroMemory(this, sizeof(*this)); 
		dw_message_id = message_id_crc("NET_SIS_init_achievement_criteria");
		dw_size = sizeof(NET_SIS_init_achievement_criteria);
	}
	INT		n_num;		  // ����
	tagCriteriaProgress	criteriaProgress[1];
};


//! ���ĳ���ɾ�
struct NET_SIS_complate_achievement : public tag_net_message
{
	NET_SIS_complate_achievement()
	{ 
		ZeroMemory(this, sizeof(*this)); 
		dw_message_id = message_id_crc("NET_SIS_complate_achievement");
		dw_size = sizeof(NET_SIS_complate_achievement);
	}
	DWORD dw_id;		  // id
	DWORD dw_date;		  // ���ʱ��
};

//! �ɾͽ��ȸ���
struct NET_SIS_updata_achievement_progress : public tag_net_message
{
	NET_SIS_updata_achievement_progress()
	{ 
		ZeroMemory(this, sizeof(*this)); 
		dw_message_id = message_id_crc("NET_SIS_updata_achievement_progress");
		dw_size = sizeof(NET_SIS_updata_achievement_progress);
	}
	DWORD dw_id;		// id
	DWORD dw_count;		// ����
	BOOL b_fail;		// �Ƿ�ʧ��
};


// !�ɾ͵����ı�
struct NET_SIS_achievement_point_change : public tag_net_message
{
	NET_SIS_achievement_point_change()
	{ 
		ZeroMemory(this, sizeof(*this)); 
		dw_message_id = message_id_crc("NET_SIS_achievement_point_change");
		dw_size = sizeof(NET_SIS_achievement_point_change);
	}
	INT nNewValue;	//�µ�ֵ
};

#pragma pack(pop)


#endif