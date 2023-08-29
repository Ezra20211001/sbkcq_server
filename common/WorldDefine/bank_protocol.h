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
*	@file		bank_protocol.h
*	@author		lc
*	@date		2011/03/22	initial
*	@version	0.0.1.0
*	@brief		Ǯׯ���ݣ���Ϣ����
*/

#ifndef BANK_PROTOCOL
#define BANK_PROTOCOL

#include "protocol_common_errorcode.h"

#pragma pack(push, 1)

const	INT		n_keeping[3] = {10, 30, 100};		// ���ܷ�
const	FLOAT	f_keeping[3] = {0.001, 0.002, 0.005};

const	INT		n_exchange[4] = {50, 100, 500, 2500};		// Ԫ���һ�����

enum
{
	E_bank_timetype_limit			= 1,		// ʱ����������
	E_bank_LevelNotEnough			= 2,		// �ȼ�����
	E_bank_Chaw_Limit				= 3,		// һ�ڼ۳�������
	E_bank_bidup_Limit				= 4,		// ���ļ۸�Ƿ�
	E_bank_Keeping_NotEnough		= 5,		// ���ܷѲ���
	E_bank_yuanbao_not_enough		= 6,		// Ԫ������
	E_bank_not_sell_role			= 7,		// ����������
	E_bank_bidup_repeat				= 8,		// �ظ�����
	E_bank_money_not_enough			= 9,		// ��Ϸ�Ҳ���
	E_bank_num_limit				= 10,		// ����������������
	E_bank_jing_limit				= 11,		// ���ܾ����Լ���������Ʒ
	E_bank_only_jingpai				= 12,		// û��һ�ڼ�ְ�ܾ���
	E_bank_chaw_buy_limit			= 13,		// ���ļ۸񳬹�һ�ڼۣ�ֻ�ܾ��ģ�
	E_bank_sell_num_limit			= 14,		// ������������

	E_bank_exchange_not_enough		= 50,		// Ԫ���һ�������
	E_bank_exchange_num_limit		= 51,		// Ԫ���һ���������
};

//---------------------------------------------------------------------------------------------
// Ǯׯ���ݽṹ����
//---------------------------------------------------------------------------------------------
struct tag_bank
{
	DWORD			dw_id;				// Ǯׯ���
	DWORD			dw_bidup;			// ���ļ۸�
	DWORD			dw_bidup_id;		// ������id
	BYTE			by_type;			// �������� 0 ��Ϸ�� 1 Ԫ��
	DWORD			dw_sell;			// ��������
	DWORD			dw_chaw;			// һ�ڼ�
	DWORD			dw_sell_id;			// ������id
	tagDWORDTime	dw_begin_time;		// ��ʼ����ʱ��
	BYTE			by_time_type;		// ʱ������

	tag_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_sell_id = INVALID_VALUE;
		dw_bidup_id = INVALID_VALUE;

	}
};

/**********************************************************************************************
**********************************************************************************************
**********************************************************************************************/

//---------------------------------------------------------------------------------------------
// Ǯׯ��Ϣ�ṹ����
//---------------------------------------------------------------------------------------------
// ��ʼǮׯ����
struct NET_SIC_begin_bank_paimai : public tag_net_message
{
	NET_SIC_begin_bank_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_begin_bank_paimai");
		dw_size = sizeof(NET_SIC_begin_bank_paimai);
	}
	DWORD			dw_bidup;			// ���ļ۸�
	BYTE			by_type;			// �������� 0 ��Ϸ�� 1 Ԫ��
	DWORD			dw_sell;			// ��������
	DWORD			dw_chaw;			// һ�ڼ�
	BYTE			by_time_type;		// ʱ������
	DWORD			dw_safe_code;		// ��ȫ��
};

struct NET_SIS_begin_bank_paimai : public tag_net_message
{
	NET_SIS_begin_bank_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_begin_bank_paimai");
		dw_size = sizeof(NET_SIS_begin_bank_paimai);
	}

	DWORD dw_error;
};

// ���ͽ�ɫǮׯ������Ϣ
struct NET_SIS_send_role_bank_paimai_info : public tag_net_message
{
	NET_SIS_send_role_bank_paimai_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_role_bank_paimai_info");
		dw_size = sizeof(NET_SIS_send_role_bank_paimai_info);
	}

	INT	n_duty;
	INT	n_num;
	tag_bank st_bank[1];
};

// ��ӽ�ɫǮׯ������Ϣ
struct NET_SIS_add_role_bank_paimai : public tag_net_message
{
	NET_SIS_add_role_bank_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_role_bank_paimai");
		dw_size = sizeof(NET_SIS_add_role_bank_paimai);
	}
	tag_bank	st_bank;
};

// ȡ����ɫǮׯ����
struct NET_SIC_cancel_role_bank_paimai : public tag_net_message
{
	NET_SIC_cancel_role_bank_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_role_bank_paimai");
		dw_size = sizeof(NET_SIC_cancel_role_bank_paimai);
	}

	DWORD	dw_bank_id;
};

struct NET_SIS_cancel_role_bank_paimai : public tag_net_message
{
	NET_SIS_cancel_role_bank_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_role_bank_paimai");
		dw_size = sizeof(NET_SIS_cancel_role_bank_paimai);
	}
	DWORD	dw_error;
};

// ɾ����ɫǮׯ������Ϣ
struct NET_SIS_delete_role_bank_paimai : public tag_net_message
{
	NET_SIS_delete_role_bank_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_role_bank_paimai");
		dw_size = sizeof(NET_SIS_delete_role_bank_paimai);
	}
	DWORD	dw_bank_id;
};

// ��ʼ����
struct NET_SIC_begin_bank_jing : public tag_net_message
{
	NET_SIC_begin_bank_jing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_begin_bank_jing");
		dw_size = sizeof(NET_SIC_begin_bank_jing);
	}
	DWORD	dw_bank_id;
	DWORD	dw_safe_code;
};

struct NET_SIS_begin_bank_jing : public tag_net_message
{
	NET_SIS_begin_bank_jing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_begin_bank_jing");
		dw_size = sizeof(NET_SIS_begin_bank_jing);
	}
	DWORD	dw_error;
};

struct NET_SIS_update_bank_jing : public tag_net_message
{
	NET_SIS_update_bank_jing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_bank_jing");
		dw_size = sizeof(NET_SIS_update_bank_jing);
	}
	DWORD	dw_bank_id;
	DWORD	dw_new_bidup;
};

// һ�ڼ۹���
struct NET_SIC_bank_chaw_buy : public tag_net_message
{
	NET_SIC_bank_chaw_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_bank_chaw_buy");
		dw_size = sizeof(NET_SIC_bank_chaw_buy);
	}

	DWORD	dw_bank_id;
	DWORD	dw_safe_code;
};

struct NET_SIS_bank_chaw_buy : public tag_net_message
{
	NET_SIS_bank_chaw_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bank_chaw_buy");
		dw_size = sizeof(NET_SIS_bank_chaw_buy);
	}
	DWORD	dw_error;
};

// ��ѯǮׯ��Ϣ
struct NET_SIC_query_bank : public tag_net_message
{
	NET_SIC_query_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_query_bank");
		dw_size = sizeof(NET_SIC_query_bank);
	}
	BYTE	by_type;		// ��ѯ���� 0 ��Ϸ�� 1 Ԫ��
};

struct NET_SIS_query_bank : public tag_net_message
{
	NET_SIS_query_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_query_bank");
		dw_size = sizeof(NET_SIS_query_bank);
	}
	INT			n_page_num;		// ҳ��
	INT			n_num;
	BYTE		by_type;
	tag_bank	st_bank[1];
};

// ������ҳ
struct NET_SIC_bank_change_page : public tag_net_message
{
	NET_SIC_bank_change_page()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_bank_change_page");
		dw_size = sizeof(NET_SIC_bank_change_page);
	}
	BYTE	by_type;	// ��ѯ���� 0 ��Ϸ�� 1 Ԫ��
	INT		n_page;
};

struct NET_SIS_bank_exchange_info : public tag_net_message
{
	NET_SIS_bank_exchange_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bank_exchange_info");
		dw_size = sizeof(NET_SIS_bank_exchange_info);
	}
	BYTE		by_type;		// ���ĳɹ� 0 һ�ڼ۳ɹ� 1
	tag_bank	st_bank;
};

// ��ȡԪ���һ�����
struct NET_SIC_get_yuanbao_exchange_num : public tag_net_message
{
	NET_SIC_get_yuanbao_exchange_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_yuanbao_exchange_num");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_yuanbao_exchange_num : public tag_net_message
{
	NET_SIS_yuanbao_exchange_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_yuanbao_exchange_num");
		dw_size = sizeof(*this);
	}
	INT n_num;
};

// ��ȡ����
struct NET_SIC_get_bank_radio : public tag_net_message
{
	NET_SIC_get_bank_radio()
	{
		ZeroMemory(this, sizeof(*this));;
		dw_message_id = message_id_crc("NET_SIC_get_bank_radio");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_bank_radio : public tag_net_message
{
	NET_SIS_get_bank_radio()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_bank_radio");
		dw_size = sizeof(*this);
	}
	INT n_bank_radio;
};

// Ԫ���һ�
struct NET_SIC_yuanban_exchange : public tag_net_message
{
	NET_SIC_yuanban_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_yuanban_exchange");
		dw_size = sizeof(*this);
	}

	BYTE	by_type;
	DWORD	dw_safe_code;
};

struct NET_SIS_yuanbao_exchange : public tag_net_message
{
	NET_SIS_yuanbao_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_yuanban_exchange");
		dw_size = sizeof(*this);
	}

	DWORD dw_error;
};

#pragma pack(pop)

#endif