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
*	@file		enthrallment_protocol.h
*	@author		lc
*	@date		2011/03/03	initial
*	@version	0.0.1.0
*	@brief		��������Ϣ
*/

#ifndef ENTHRALLMENT_PROTOCOL
#define ENTHRALLMENT_PROTOCOL

#pragma pack(push, 1)

enum 
{
	E_FatigueLimit_None		= 0,
	E_FatigueLimit_Quest	= 1,
	E_FatigueLimit_Stall	= 2,
};

struct NET_SIS_enthrallment_limit : public tag_net_message
{
	NET_SIS_enthrallment_limit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_enthrallment_limit");
		dw_size = sizeof(NET_SIS_enthrallment_limit);
	}
	BYTE	byLimitCode;		// ����������
};

//----------------------------------------------------------------------------
// ���Ŀǰ��������Ϣ
//----------------------------------------------------------------------------
struct NET_SIC_enthrallment_info : public tag_net_message
{
	NET_SIC_enthrallment_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_enthrallment_info");
		dw_size = sizeof(NET_SIC_enthrallment_info);
	}
};

struct NET_SIS_enthrallment_info : public tag_net_message
{
	NET_SIS_enthrallment_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_enthrallment_info");
		dw_size = sizeof(NET_SIS_enthrallment_info);
	}
	BYTE			byState;		// ��ǰ״̬
	DWORD			dwCurOLSec;		// ��ǰ�ۼ�����ʱ��
};


#pragma pack(pop)
#endif