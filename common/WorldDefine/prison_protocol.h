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
*	@file		prison_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		������Ϣ
*/

#ifndef PRISON_PROTOCOL
#define PRISON_PROTOCOL

#pragma pack(push, 1)
#include "protocol_common_errorcode.h"
//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum
{
	E_Prison_Success					= E_Success,	// �ɹ�
	E_Prison_UnknownError					,			// δ֪����
};

//-----------------------------------------------------------------------------
// �������
//-----------------------------------------------------------------------------
struct NET_SIS_send_to_prison : public tag_net_message
{
	NET_SIS_send_to_prison()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_to_prison");
		dw_size = sizeof(NET_SIS_send_to_prison);
	}
	DWORD			dwCaptorRoleID;			// Ϊ����������
	DWORD			dwCatchedRoleID;		// ��������������
};


#pragma pack(pop)
#endif