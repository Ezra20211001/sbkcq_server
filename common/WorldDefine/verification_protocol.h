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
*	@file		verification_protocol.h
*	@author		lc
*	@date		2012/02/06	initial
*	@version	0.0.1.0
*	@brief		������֤����Ϣ
*/


#ifndef VERIFICATION_PROTOCOL
#define VERIFICATION_PROTOCOL

#pragma pack(push, 1)


// ��֤������
enum 
{
	E_VERIFICATION_OK			=	0,		// ��֤�ɹ�

	E_VERIFICATION_ERROR		=	1,		// ��֤�����
};

//������֤��
struct NET_SIC_reset_verification_code : public tag_net_message
{
	NET_SIC_reset_verification_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reset_verification_code");
		dw_size = sizeof(NET_SIC_reset_verification_code);
	}
};

struct NET_SIS_reset_verification_code : public tag_net_message
{
	NET_SIS_reset_verification_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reset_verification_code");
		dw_size = sizeof(NET_SIS_reset_verification_code);
	}
	//DWORD	dwVerificationCodeKey;
	//BYTE	byStrCode[8];			// ��֤����ܺ�
	BYTE	byVerificationCodeIndex;
	DWORD	dwType;					// �������� 0:���ַ� 1:�������� 2:��ͬ��
	INT		n_verify_code_size;
	BYTE	by_code[1];
};


// ��Ҫ��֤��
struct NET_SIS_need_verification : public tag_net_message
{
	NET_SIS_need_verification()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_need_verification");
		dw_size = sizeof(NET_SIS_need_verification);
	}
	//DWORD	dwVerificationCodeKey;	// ��֤��key
	//BYTE	byStrCode[8];			// ��֤����ܺ�
	//BYTE	byVerificationCodeIndex;// ��֤�������
	BYTE	byCount;				// ��֤ʣ�����
	DWORD	dwTime;					// ��֤ʣ��ʱ��
};


// ��֤�ظ�
struct NET_SIC_need_verification_return : public tag_net_message
{
	NET_SIC_need_verification_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_need_verification_return");
		dw_size = sizeof(NET_SIC_need_verification_return);
	}
	DWORD	dwVerificationCodeCrc;
};

struct NET_SIS_need_verification_return : public tag_net_message
{
	NET_SIS_need_verification_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_need_verification_return");
		dw_size = sizeof(NET_SIS_need_verification_return);
	}
	DWORD	dw_error_code;
	//DWORD	dw_new_key;
	//BYTE	byStrCode[8];	// ��֤����ܺ�
	//BYTE	by_new_index;
};

// ������֤׼���׶�
struct NET_SIS_relay_verification : public tag_net_message
{
	NET_SIS_relay_verification()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_relay_verification");
		dw_size = sizeof(NET_SIS_relay_verification);
	}

	DWORD	dwTime;					// ��֤׼��ʣ��ʱ��
};


// ������ʽ��֤
struct NET_SIC_goto_verification : public tag_net_message
{
	NET_SIC_goto_verification()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_goto_verification");
		dw_size = sizeof(NET_SIC_goto_verification);
	}
};

#pragma pack(pop)

#endif