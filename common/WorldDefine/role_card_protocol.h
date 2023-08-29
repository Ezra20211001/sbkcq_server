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
*	@file		role_card_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		��ɫ��Ƭ
*/

#ifndef ROLE_CARD_PROTOCOL
#define ROLE_CARD_PROTOCOL

#pragma pack(push, 1)

#include "vcard_define.h"


//----------------------------------------------------------------------------
// ��ȡ��ɫ������Ϣ
//----------------------------------------------------------------------------
struct NET_SIC_get_role_card : public tag_net_message
{
	NET_SIC_get_role_card()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_role_card");
		dw_size = sizeof(NET_SIC_get_role_card);
	}
	DWORD			dw_role_id;			// ��ɫID
};

struct NET_SIS_get_role_card : public tag_net_message
{
	NET_SIS_get_role_card()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_card");
		dw_size = sizeof(NET_SIS_get_role_card);
	}
	DWORD			dw_error_code;		// ������
	DWORD			dw_role_id;			// ��ɫID
	BYTE			pData[1];				// ��������
};

//----------------------------------------------------------------------------
// ���ý�ɫ������Ϣ
//----------------------------------------------------------------------------
struct NET_SIC_set_role_card : public tag_net_message
{
	NET_SIC_set_role_card()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_role_card");
		dw_size = sizeof(NET_SIC_set_role_card);
	}
	DWORD				dw_role_id;			// ��ɫID
	tagCustomVCardData	customVCardData;	// �Զ�����Ϣ
};

struct NET_SIS_set_role_card : public tag_net_message
{
	NET_SIS_set_role_card()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_role_card");
		dw_size = sizeof(NET_SIS_set_role_card);
	}
	DWORD			dw_error_code;		// ������
	DWORD			dw_role_id;			// ��ɫID
};

//----------------------------------------------------------------------------
// ��ý�ɫͷ��URL��Ϣ
//----------------------------------------------------------------------------
struct NET_SIC_get_role_head_picture : public tag_net_message
{
	NET_SIC_get_role_head_picture()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_role_head_picture");
		dw_size = sizeof(NET_SIC_get_role_head_picture);
	}
	 DWORD           dw_role_id;           //!< ��ɫID
};

struct NET_SIS_get_role_head_picture : public tag_net_message
{
	NET_SIS_get_role_head_picture()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_head_picture");
		dw_size = sizeof(NET_SIS_get_role_head_picture);
	}
	DWORD           dw_role_id;
	BYTE            byHeadUrlSize;      //!< ͷ��ߴ�(byte����)
	BYTE            byData[1];          //!< ͷ��URL������'\0'����
};

#pragma pack(pop)
#endif