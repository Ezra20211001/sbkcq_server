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
*	@file		script_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		�ű���Ϣ
*/

#ifndef SCRIPT_PROTOCOL
#define SCRIPT_PROTOCOL

#pragma pack(push, 1)

enum EMsgUnitType;
enum EDlgOption;

//-----------------------------------------------------------------------------
// NS_ScriptBroad��dwMisc�ֶε�λ���Ͷ���
//-----------------------------------------------------------------------------
struct NET_SIS_message_blob : public tag_net_message
{
	NET_SIS_message_blob()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_message_blob");
		dw_size = sizeof(NET_SIS_message_blob);
	}
	BYTE byData[1];
};

//-----------------------------------------------------------------------------
// �ͻ��˶Ի��򷢸������ȱʡ��Ϣ
//-----------------------------------------------------------------------------
struct NET_SIC_dialog_default_message : public tag_net_message
{
	NET_SIC_dialog_default_message()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_dialog_default_message");
		dw_size = sizeof(NET_SIC_dialog_default_message);
	}
	EMsgUnitType	eDlgTarget;				// �ͻ��˶Ի����������Ӧ��Ŀ�꣨������Ʒ�� ��ң�
	DWORD			dwTargetID;				// Ŀ��ID
	EDlgOption		eDlgOption;				// ��ҷ��صĶԻ���ѡ��
};

//ֻ�е�RoleID
struct NET_SIS_message_broab_blob : public tag_net_message
{
	NET_SIS_message_broab_blob()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_message_broab_blob");
		dw_size = sizeof(NET_SIS_message_broab_blob);
	}
	BYTE byData[1];
};

//-----------------------------------------------------------------------------
// �ͻ��˴����������ű���ȱʡ��Ϣ
//-----------------------------------------------------------------------------
struct NET_SIC_default_request : public tag_net_message
{
	NET_SIC_default_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_default_request");
		dw_size = sizeof(NET_SIC_default_request);
	}
	EMsgUnitType	eDlgTarget;				// �����������ű��Ķ�ӦĿ�꣨�̶����
	DWORD			dwTargetID;				// Ŀ��ID
	DWORD			dwEventType;			// �������¼�����
};


#pragma pack(pop)
#endif