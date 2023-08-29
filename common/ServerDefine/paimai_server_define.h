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
*	@file		paimai_server_define.h
*	@author		lc
*	@date		2011/03/16	initial
*	@version	0.0.1.0
*	@brief		�������������ݣ���Ϣ����
*/

#ifndef PAIMAI_SERVER_DEFINE
#define PAIMAI_SERVER_DEFINE

#include "../common/WorldDefine/paimai_protocol.h"
#include "../ServerDefine/item_server_define.h"

#pragma pack(push, 1)

const INT32 MAX_LOAD_PAI_BUFFER	= 10 * 1000 * 1000;	// ÿ�ζ�ȡ����������ֽ�
const INT32 MAX_LOAD_PAI_NUM	= 10 * 1000;		// ÿ�η��͵���������
const INT32 TMP_PAI_BUFFER		= 100 * 1000;		// ������ʱ����

const INT32	PAIMAI_CONTEXT	=	100;

const DWORD AUTO_PAIMAI_TIME = TICK_PER_SECOND * 60;

struct tagAutoPaimai
{
	DWORD			dwID;					// ���
	DWORD			dwItemID;				// ��ƷID
	DWORD			dwBidup;				// ���ļ۸�
	DWORD			dwChaw;					// һ�ڼ�
	DWORD			dwSellRoleID;			// ������ID
	BYTE			byTimeType;				// ����ʱ������
	DWORD			dwInventory;			// �����
	DWORD			dwComplement;			// ����
	BOOL			bSell;					// �Ƿ���ڵ�������
	DWORD			dwSellNum;				// ������������
	BOOL			bBind;					// �Ƿ��
	BOOL			bOnline;				// �Ƿ��ϼ�

	tagAutoPaimai()
	{
		ZeroMemory(this, sizeof(*this));
		dwID = INVALID_VALUE;
		dwItemID = INVALID_VALUE;
		dwSellRoleID = INVALID_VALUE;
	}
};

//---------------------------------------------------------------------------------------------
// �Զ�������Ϣ����
//---------------------------------------------------------------------------------------------
// ��ȡ�����Զ���������
struct NET_S2DB_load_auto_paimai : public tag_net_message
{
	NET_S2DB_load_auto_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_load_auto_paimai");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2S_load_auto_paimai : public tag_net_message
{
	NET_DB2S_load_auto_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_auto_paimai");
		dw_size = sizeof(*this);
	}
	INT n_num;
	tagAutoPaimai	st_auto_paimai[1];
};

struct NET_DB2S_load_auto_paimai_end : public tag_net_message
{
	NET_DB2S_load_auto_paimai_end()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_auto_paimai_end");
		dw_size = sizeof(*this);
	}
};

// ����Ƿ��Ѿ�����
struct NET_S2DB_check_is_paimai : public tag_net_message
{
	NET_S2DB_check_is_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_check_is_paimai");
		dw_size = sizeof(*this);
	}
	DWORD dw_auto_paimai_id;
};

struct NET_DB2S_check_is_paimai : public tag_net_message
{
	NET_DB2S_check_is_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_check_is_paimai");
		dw_size = sizeof(*this);
	}

	DWORD dw_auto_paimai_id;
	BOOL  b_have;
};

// �Զ�������ʼ�����
struct NET_S2DB_auto_paimai_init_ok : public tag_net_message
{
	NET_S2DB_auto_paimai_init_ok()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_auto_paimai_init_ok");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2S_auto_paimai_init_ok : public tag_net_message
{
	NET_DB2S_auto_paimai_init_ok()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_auto_paimai_init_ok");
		dw_size = sizeof(*this);
	}
};

// �����Զ���������
struct NET_S2DB_update_auto_paimai : public tag_net_message
{
	NET_S2DB_update_auto_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_update_auto_paimai");
		dw_size = sizeof(*this);
	}
	tagAutoPaimai st_auto_paimai;
};

//---------------------------------------------------------------------------------------------
// ������Ϣ����
//---------------------------------------------------------------------------------------------
//! ��ȡ���������
struct NET_S2DB_load_paimai_max_id : public tag_net_message
{
	NET_S2DB_load_paimai_max_id()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_load_paimai_max_id");
		dw_size = sizeof(NET_S2DB_load_paimai_max_id);
	}
};

struct NET_DB2S_load_paimai_max_id : public tag_net_message
{
	NET_DB2S_load_paimai_max_id()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_paimai_max_id");
		dw_size = sizeof(NET_DB2S_load_paimai_max_id);
	}
	DWORD	dw_max_id;			// ����������
};

//! ����������Ʒ
struct NET_S2DB_update_paimai_item : public tag_net_message
{
	NET_S2DB_update_paimai_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_update_paimai_item");
		dw_size = sizeof(NET_S2DB_update_paimai_item);
	}

	s_item_update st_item;
};

//! ����������Ϣ
struct NET_S2DB_insert_paimai : public tag_net_message
{
	NET_S2DB_insert_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_insert_paimai");
		dw_size = sizeof(NET_S2DB_insert_paimai);
	}
	tag_paimai	st_paimai;
};

//! ɾ��������¼
struct NET_S2DB_delete_paimai : public tag_net_message
{
	NET_S2DB_delete_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_delete_paimai");
		dw_size = sizeof(NET_S2DB_delete_paimai);
	}

	DWORD	dw_paimai_id;
};

//! ���¾��ļ�¼
struct NET_S2DB_update_paimai : public tag_net_message
{
	NET_S2DB_update_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_update_paimai");
		dw_size = sizeof(NET_S2DB_update_paimai);
	}
	tag_paimai	st_paimai;
};

//! ��ȡ������Ϣ
struct NET_S2DB_load_all_paimai : public tag_net_message
{
	NET_S2DB_load_all_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_load_all_paimai");
		dw_size = sizeof(NET_S2DB_load_all_paimai);
	}
};

struct NET_DB2S_load_all_paimai : public tag_net_message
{
	NET_DB2S_load_all_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_all_paimai");
		dw_size = sizeof(NET_DB2S_load_all_paimai);
	}

	INT			n_num;
	tag_paimai	st_paimai[1];
};

struct NET_DB2S_load_all_paimai_end : public tag_net_message
{
	NET_DB2S_load_all_paimai_end()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_all_paimai_end");
		dw_size = sizeof(*this);
	}
};

//! ��ȡ������Ʒ
struct NET_S2DB_load_paimai_item : public tag_net_message
{
	NET_S2DB_load_paimai_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_load_paimai_item");
		dw_size = sizeof(NET_S2DB_load_paimai_item);
	}

	DWORD	dw_paimai_id;
};

struct NET_DB2S_load_paimai_item : public tag_net_message
{
	NET_DB2S_load_paimai_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_paimai_item");
		dw_size = sizeof(NET_DB2S_load_paimai_item);
	}
	INT		n_count;
	BYTE	by_data_[1];
};	

struct NET_DB2S_load_paimai_item_end : public tag_net_message
{
	NET_DB2S_load_paimai_item_end()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_paimai_item_end");
		dw_size = sizeof(*this);
	}
};

#pragma pack(pop)

#endif