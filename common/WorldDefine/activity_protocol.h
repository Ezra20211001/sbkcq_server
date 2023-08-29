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
*	@file		activity_protocol.h
*	@author		lc
*	@date		2011/03/01	initial
*	@version	0.0.1.0
*	@brief		�Э��
*/

#ifndef ACTIVITY_PROTOCOL
#define ACTIVITY_PROTOCOL

#pragma pack(push, 1)

//-----------------------------------------------------------------------------
// �ű���ȱʡ��Ϣ��NET_SIC_default_request)�¼����Ͷ��壨�����Ͷ�����lua��ʹ�ã�
//-----------------------------------------------------------------------------
/*
dwEventType = 1				// �ͻ�������PVP�̶������ 
dwEventType = 2				// ��ѯ����ڹ̶���е�����
*/

enum 
{
	E_Open_Server_Has_Recv		=	1,  //�����Ѿ���ȡ
	E_Open_Server_Not_Free_Bag	=	2,	//�����ռ䲻��
	E_Open_Server_Not_Today		=	3,	//û����ȡʱ��
	E_Open_Server_Cant			=	4,	//û����ȡ����
};
//�� �㲥�״̬
struct NET_SIS_acitvity_state : public tag_net_message
{
	NET_SIS_acitvity_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_acitvity_state");
		dw_size = sizeof(NET_SIS_acitvity_state);
	}
	INT		nState;							// 0-������ʼ 1-��ʼ 2-�������� 3-���� 
	BYTE	byHour;
	BYTE	byMinute;
	DWORD	dwActivityID;
};

// ��ȡ���������
struct NET_SIC_get_server_acitvity : public tag_net_message
{
	NET_SIC_get_server_acitvity()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_server_acitvity");
		dw_size = sizeof(NET_SIC_get_server_acitvity);
	}

};

struct NET_SIS_get_server_acitvity : public tag_net_message
{
	NET_SIS_get_server_acitvity()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_server_acitvity");
		dw_size = sizeof(NET_SIS_get_server_acitvity);
	}
	
	INT nDay;		//��������

	// �Լ�����
	DWORD	dwSelf[7];

};

// ��ȡ���������
struct NET_SIC_get_server_acitvity_receive : public tag_net_message
{
	NET_SIC_get_server_acitvity_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_server_acitvity_receive");
		dw_size = sizeof(NET_SIC_get_server_acitvity_receive);
	}


	INT nDay;		//��һ��Ľ���
};

struct NET_SIS_get_server_acitvity_receive : public tag_net_message
{
	NET_SIS_get_server_acitvity_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_server_acitvity_receive");
		dw_size = sizeof(NET_SIS_get_server_acitvity_receive);
	}

	DWORD dw_error_code;
};

#pragma pack(pop)
#endif