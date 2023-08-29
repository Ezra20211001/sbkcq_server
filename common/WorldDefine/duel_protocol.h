/*******************************************************************************

	Copyright 2010 by Shengshi Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	Shengshi Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	Shengshi Interactive  Co., Ltd.

*******************************************************************************/

/**
 *	@file		duel_protocol
 *	@author		mwh
 *	@date		2011/05/17	initial
 *	@version	0.0.1.0
 *	@brief		�д�ϵͳ
*/

#ifndef __DUEL_PROTOCOL_H__
#define __DUEL_PROTOCOL_H__

#pragma pack(push,1)

enum
{
	ASKDISTANCEMAX = 10 * 100, //  ����ʱ��������(cm)
	ASKTIMEOUTTIME = 10*1000, //  ����ʱʱ��10��
	ASKTIMEOUTTIMETICK = 10 * TICK_PER_SECOND, // ����ʱtick��
	DUELMAXDISTANCESQ = 2500 * 2500, // �д���������ƽ��
	FINISHHPRESTOREPER	= 500, // Ѫ���ָ��ٷֱ�(/10000)
	DUELBANNERTYPEID = 1000002, // ����TypeID
};

enum
{
	EAskForDuel_OutOfDistance = 1,	// �д�˫���ľ����Զ���޷������д衣
	EAskForDuel_RedNameYourSelf,	// ��Ŀǰ�Ǻ���״̬�����ܽ����д衣
	EAskForDuel_RedNameTarget,		// �������Ǻ�����ң����ܽ������롣
	EAskForDuel_StateLimitYourSelf,	// ��ǰ״̬��ֹ�����д�
	EAskForDuel_StateLimitTarget,   // �Է�״̬���ܽ����д�
	EAskForDuel_TargetRefuse,		// �Է��ܾ�������д����롣
	EAskForDuel_AlreadyAskFor,		// ���ѷ����д����룬��ȴ��Է���Ӧ��
	EAskForDuel_AlreadyInDuel,		// ���Ѿ��ڽ����д衣
	EAskForDuel_TargetAlreadyInDuel,// �Է����ڽ����д衣
	ETarget_NotExistOrOffline,		// Ŀ�겻���ڻ��Ѿ�����
	EDuel_Breakout,							// �д豻�ж�
};

// �����д�
struct NET_SIC_AskForDuel : public tag_net_message
{
	NET_SIC_AskForDuel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_AskForDuel");
		dw_size = sizeof(*this);
	}
	DWORD dwTarget;
};

// �����д��Ӧ
struct NET_SIS_AskForDuel : public tag_net_message
{
	NET_SIS_AskForDuel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_AskForDuel");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
	DWORD dwTarget;
};

// ת�������Ŀ��
struct NET_SIS_AskForDuelTransfer : public tag_net_message
{
	NET_SIS_AskForDuelTransfer()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_AskForDuelTransfer");
		dw_size = sizeof(*this);
	}
	DWORD dwTarget;
};

// �������˻�Ӧ
struct NET_SIC_AskForDuelResponse : public tag_net_message
{
	NET_SIC_AskForDuelResponse()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_AskForDuelResponse");
		dw_size = sizeof(*this);
	}
	BYTE  byAck; // 0:�ܾ� 1:ͬ��
	DWORD dwTarget;
};

struct NET_SIS_AskForDuelResponse : public tag_net_message
{
	NET_SIS_AskForDuelResponse()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_AskForDuelResponse");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
	DWORD dwTarget;
};

// �д迪ʼ
struct NET_SIS_DuelStart : public tag_net_message
{
	NET_SIS_DuelStart()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_DuelStart");
		dw_size = sizeof(*this);
	}
	DWORD dwTargetID;
	Vector3 bannerPos;
};

// �д����
struct NET_SIS_DuelFinish : public tag_net_message
{
	NET_SIS_DuelFinish()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_DuelFinish");
		dw_size = sizeof(*this);
	}
	DWORD dwTargetID;
	DWORD dwError;
};

// �д����㲥
struct NET_SIS_DuelResultBroad : public tag_net_message
{
	NET_SIS_DuelResultBroad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_DuelResultBroad");
		dw_size = sizeof(*this);
	}
	DWORD dwLoser;
	DWORD dwWinner;
};

#pragma pack(pop)

#endif //__DUEL_PROTOCOL_H__
