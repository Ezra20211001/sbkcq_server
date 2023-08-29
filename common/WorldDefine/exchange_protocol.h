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
*	@file		exchange_protocol.h
*	@author		lc
*	@date		2011/03/02	initial
*	@version	0.0.1.0
*	@brief		��ɫ������Ϣ
*/


#ifndef EXCHANGE_PROTOCOL
#define EXCHANGE_PROTOCOL

#include "protocol_common_errorcode.h"
#include "ItemDefine.h"

#pragma pack(push, 1)
//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum
{
	E_Exchange_Accept				= E_Success,	// �Է�ͬ�⽻��
	E_Exchange_Refuse				= 1,	// �Է��ܾ�		
	E_Exchange_NotEnough_BagSpace	= 2,	// �����ռ䲻��
	E_Exchange_RoleBusy				= 3,	// �����뷽æ	
	E_Exchange_WithMore				= 4,	// ���ܺͶ���ͬʱ����
	E_Exchange_OutOfRange			= 5,	// ���׾��뷶Χ֮��
	E_Exchange_NotInSame_Map		= 6,	// ����ͬһ����
	E_Exchange_ItemCanNot_Exchange	= 7,	// ��Ʒ���ܽ���
	E_Exchange_ItemCanNot_Find		= 8,	// û���ҵ�ָ����������Ʒ
	E_Exchange_NotEnough_Money		= 9,	// ���׵Ľ�Ǯ����
	E_Exchange_ApplicantTgt_Change	= 10,	// ��������Ľ���Ŀ�귢���仯
	E_Exchange_NotAnswer			= 11,	// �Է�û����Ӧ
	E_Exchange_SelfBusy				= 12,	// ����Լ�æ
	E_Exchange_Trage_InDuel = 13, // �Է����ڽ����д衣
	E_Exchange_NotInSafearea = 14,//����˫������ڰ�ȫ����
};



// ������󽻻���Ʒ
struct NET_SIC_exchange_request : public tag_net_message
{
	NET_SIC_exchange_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_exchange_request");
		dw_size = sizeof(NET_SIC_exchange_request);
	}
	DWORD	dwDstID;	// ��ϢĿ��ID
};

struct NET_SIS_exchange_request : public tag_net_message
{
	NET_SIS_exchange_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_request");
		dw_size = sizeof(NET_SIS_exchange_request);
	}
	DWORD	dwSrcID;	// ��Ϣ������ID
};

// Ŀ����ҽ���������
struct NET_SIC_exchange_request_result : public tag_net_message
{
	NET_SIC_exchange_request_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_exchange_request_result");
		dw_size = sizeof(NET_SIC_exchange_request_result);
	}
	DWORD	dw_error_code;
	DWORD	dwDstID;
};

// ������ת����Ŀ����ҽ���������
struct NET_SIS_exchange_request_result : public tag_net_message
{
	NET_SIS_exchange_request_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_request_result");
		dw_size = sizeof(NET_SIS_exchange_request_result);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;
	DWORD	dwDstID;
};

// ��ӽ��׵���Ʒװ��
struct NET_SIC_add_exchange : public tag_net_message
{
	NET_SIC_add_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_add_exchange");
		dw_size = sizeof(NET_SIC_add_exchange);
	}
	INT64	n64_serial;	// ֻ��Ҫ64λ���,�����������ʼ����Ʒ������Ϣ
};

struct NET_SIS_add_exchange_to_src : public tag_net_message
{
	NET_SIS_add_exchange_to_src()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_exchange_to_src");
		dw_size = sizeof(NET_SIS_add_exchange_to_src);
	}
	DWORD	dw_error_code;
	DWORD	dwDstID;
	INT64	n64_serial;
	INT32	nIndex;
};

struct NET_SIS_add_exchange_to_dest : public tag_net_message
{
	NET_SIS_add_exchange_to_dest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_exchange_to_dest");
		dw_size = sizeof(NET_SIS_add_exchange_to_dest);
	}
	DWORD	dwSrcID;
	INT32	nIndex;
	BYTE	byData[SIZE_EQUIP];	// ��Ʒ��װ��(��Ҫ֪ͨ�Է�װ������ϸ��Ϣ)
};

// ȡ�����׵���Ʒװ��
struct NET_SIC_cancel_exchange_item : public tag_net_message
{
	NET_SIC_cancel_exchange_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_exchange_item");
		dw_size = sizeof(NET_SIC_cancel_exchange_item);
	}
	INT64	n64_serial;
};

struct NET_SIS_cancel_exchange_item : public tag_net_message
{
	NET_SIS_cancel_exchange_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_exchange_item");
		dw_size = sizeof(NET_SIS_cancel_exchange_item);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;
	DWORD	dwDstID;
	INT64	n64_serial;
};

struct NET_SIC_exchange_money : public tag_net_message
{
	NET_SIC_exchange_money()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_exchange_money");
		dw_size = sizeof(NET_SIC_exchange_money);
	}
	INT64	n64Money;
};

struct NET_SIS_exchange_money : public tag_net_message
{
	NET_SIS_exchange_money()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_money");
		dw_size = sizeof(NET_SIS_exchange_money);
	}
	DWORD	dw_error_code;	
	INT64	n64Money;
	DWORD	dwSrcID;
};

struct NET_SIC_exchange_item_lock : public tag_net_message
{
	NET_SIC_exchange_item_lock()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_exchange_item_lock");
		dw_size = sizeof(NET_SIC_exchange_item_lock);
	}
};

struct NET_SIS_exchange_item_lock : public tag_net_message
{
	NET_SIS_exchange_item_lock()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_item_lock");
		dw_size = sizeof(NET_SIS_exchange_item_lock);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;
};

// ȡ������
struct NET_SIC_exchange_cancel : public tag_net_message
{
	NET_SIC_exchange_cancel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_exchange_cancel");
		dw_size = sizeof(NET_SIC_exchange_cancel);
	}
};

struct NET_SIS_exchange_cancel : public tag_net_message
{
	NET_SIS_exchange_cancel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_cancel");
		dw_size = sizeof(NET_SIS_exchange_cancel);
	}
	DWORD	dwSrcID;
};

// ���ȷ�Ͻ���
struct NET_SIC_exchange_verify : public tag_net_message
{
	NET_SIC_exchange_verify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_exchange_verify");
		dw_size = sizeof(NET_SIC_exchange_verify);
	}
	DWORD	dw_safe_code;
};

// �������
struct NET_SIS_exchange_finish : public tag_net_message
{
	NET_SIS_exchange_finish()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_finish");
		dw_size = sizeof(NET_SIS_exchange_finish);
	}
	DWORD	dw_error_code;
	DWORD	dwFailedRoleID;		// ����ʧ����ID
};


//----------------------------------------------------------------------------
#pragma pack(pop)
#endif