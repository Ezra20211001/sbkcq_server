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
*	@file		paimai_protocol.h
*	@author		lc
*	@date		2011/03/16	initial
*	@version	0.0.1.0
*	@brief		�������ݣ���Ϣ����
*/

#ifndef PAIMAI_PROTOCOL
#define PAIMAI_PROTOCOL

#include "protocol_common_errorcode.h"
#include "../WorldDefine/ItemDefine.h"

#pragma pack(push, 1)

enum
{
	E_PaiMai_LevelNotEnough				= 1,		// �����ȼ�����
	E_PaiMai_Item_NotExist				= 2,		// ������Ʒ������
	E_PaiMai_Item_IsBind				= 3,		// ����Ʒ���ܳ���
	E_PaiMai_Chaw_Limit					= 4,		// һ�ڼ۳�������
	E_PaiMai_bidup_Limit				= 5,		// ���ļ۸񳬹�����
	E_PaiMai_Keeping_NotEnough			= 6,		// ���ܷѲ���
	E_PaiMai_TimeType_Limit				= 7,		// ʱ�����Ͳ��Ϸ�

	E_PaiMai_Not_paimai_Role			= 8,		// ���������߲���ȡ������
	E_PaiMai_bidup_limit				= 9,		// ���ļ۸�Ƿ�
	E_PaiMai_chaw_limit					= 10,		// һ�ڼ۷Ƿ�
	E_PaiMai_Money_Not_Enough			= 11,		// ��Ǯ����
	E_PaiMai_Num_Limit					= 12,		// ������������
	E_PaiMai_bidup_repeat				= 13,		// �����ظ�
	E_PaiMai_Only_JingPai				= 14,		// û��һ�ڼ�ְ�ܾ���
	E_PaiMai_chaw_buy_limit				= 15,		// һ�ڼ۹������ƣ����ļ۸񳬹�һ�ڼۣ�
};

//---------------------------------------------------------------------------------------------
// �������ݽṹ����
//---------------------------------------------------------------------------------------------
//��������
struct tag_paimai
{
	DWORD				dw_paimai_id;				// ����������
	DWORD				dw_bidup;					// ���ļ۸�
	DWORD				dw_bidup_id;				// ������ID
	DWORD				dw_chaw;					// һ�ڼ�
	DWORD				dw_sell_id;					// ������id
	tagDWORDTime		dw_beigin_time;				// ������ʼʱ��
	BYTE				by_time_type;				// ����ʱ������
	BOOL				b_show_name;				// �Ƿ�����
	DWORD				dw_auto_index;				// �Զ��������

	tag_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_bidup_id = INVALID_VALUE;
		dw_sell_id = INVALID_VALUE;
		dw_auto_index = INVALID_VALUE;
	}
};

// �Լ���������Ϣ
struct tag_own_paimai_info
{
	DWORD				dw_paimai_id;			// �������
	DWORD				dw_bidup_price;			// ���ļ۸�
	DWORD				dw_chaw_price;			// һ�ڼ�
	tagDWORDTime		dw_begin_time;			// ������ʼʱ��
	DWORD				dw_sell_id;				// ������id
	BYTE				by_time_type;			// ʱ������
	BOOL				b_show_name;			// �Ƿ�����
	tagEquipViewInfoEx	st_info;
};

// ������ѯ����
enum E_Query_Type
{
	EQT_ALL			=		1,			// ��ѯȫ��
	EQT_Name		=		2,			// ���Ʋ�ѯ
	EQT_Type		=		3,			// ��Ʒ�����ѯ
	EQT_TypeEx		=		4,			// ��Ʒ�������Ͳ�ѯ
	EQT_Reserved	=		5,			// ��Ʒ�������Ͳ�ѯ
};

//  ��ѯ�ṹ
struct tag_paimai_query
{
	E_Query_Type		e_query_type;				// ��ѯ����
	DWORD				dw_type_id;					// ��Ʒ����id
	INT					dw_item_type[3];				// ��Ʒ����
};

/*******************************************************************************************************
*******************************************************************************************************
*******************************************************************************************************/

//---------------------------------------------------------------------------------------------
// ������Ϣ����
//---------------------------------------------------------------------------------------------
// ��ʼ����
struct NET_SIC_begin_paimai : public tag_net_message
{
	NET_SIC_begin_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_begin_paimai");
		dw_size = sizeof(NET_SIC_begin_paimai);
	}

	INT64		n64_item_id;			// ��Ʒid
	DWORD		dw_bidup_price;			// ���ļ۸�
	DWORD		dw_chaw_price;			// һ�ڼ�
	BYTE		by_time_type;			// ʱ������
	BOOL		b_show_name;			// �Ƿ�����
	DWORD		dw_safe_code;
};

struct NET_SIS_begin_paimai : public tag_net_message
{
	NET_SIS_begin_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_begin_paimai");
		dw_size = sizeof(NET_SIS_begin_paimai);
	}

	DWORD	dw_Error;
};

// ȡ������
struct NET_SIC_cancel_paimai : public tag_net_message
{
	NET_SIC_cancel_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_paimai");
		dw_size = sizeof(NET_SIC_cancel_paimai);
	}

	DWORD	dw_paimai_id;
};

struct NET_SIS_cancel_paimai : public tag_net_message
{
	NET_SIS_cancel_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_paimai");
		dw_size = sizeof(NET_SIS_cancel_paimai);
	}
	DWORD	dw_paimai_id;
	DWORD	dw_error;
};

// ֪ͨ������ȡ������
struct NET_SIS_send_cancel_paimai : public tag_net_message
{
	NET_SIS_send_cancel_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_cancel_paimai");
		dw_size = sizeof(NET_SIS_send_cancel_paimai);
	}

	DWORD	dw_paimai_id;
};

// �����ɹ�֪ͨ����µ�������Ʒ
struct NET_SIS_add_paimai_info : public tag_net_message
{
	NET_SIS_add_paimai_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_paimai_info");
		dw_size = sizeof(NET_SIS_add_paimai_info);
	}
	DWORD				dw_paimai_id;			// ����ID
	DWORD				dw_bidup_price;			// ���ļ۸�
	DWORD				dw_chaw_price;			// һ�ڼ�
	tagDWORDTime		dw_begin_time;			// ������ʼʱ��
	BOOL				b_show_name;			// �Ƿ�����
	BYTE				by_time_type;			// ʱ������
	tagEquipViewInfoEx	st_info;
};

// ��ɫ��½�����Լ���������Ϣ
struct NET_SIS_send_own_paimai_info : public tag_net_message
{
	NET_SIS_send_own_paimai_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_own_paimai_info");
		dw_size = sizeof(NET_SIS_send_own_paimai_info);
	}

	INT	 n_duty;
	INT	 n_num;
	tag_own_paimai_info st_own_paimai[1];
};

// ��ɫ��½�����Լ��ľ�����Ϣ
struct NET_SIS_send_own_jingpai_info : public tag_net_message
{
	NET_SIS_send_own_jingpai_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_own_jingpai_info");
		dw_size = sizeof(NET_SIS_send_own_jingpai_info);
	}
	INT	 n_num;
	tag_own_paimai_info st_own_paimai[1];
};

// ������
struct NET_SIC_jingpai : public tag_net_message
{
	NET_SIC_jingpai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_jingpai");
		dw_size = sizeof(NET_SIC_jingpai);
	}
	DWORD	dw_paimai_id;
	DWORD	dw_safe_code;
};

struct NET_SIS_jingpai : public tag_net_message
{
	NET_SIS_jingpai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_jingpai");
		dw_size = sizeof(NET_SIS_jingpai);
	}
	DWORD dw_error;
};

// ��Ӿ�����Ϣ
struct NET_SIS_add_jingpai : public tag_net_message
{
	NET_SIS_add_jingpai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_jingpai");
		dw_size = sizeof(NET_SIS_add_jingpai);
	}
	tag_own_paimai_info	st_paimai_info;
};

// ɾ��������Ϣ
struct NET_SIS_delete_jingpai : public tag_net_message
{
	NET_SIS_delete_jingpai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_jingpai");
		dw_size = sizeof(NET_SIS_delete_jingpai);
	}
	DWORD	dw_paimai_id;
};

// ���¾�����Ϣ
struct NET_SIS_update_jingpai : public tag_net_message
{
	NET_SIS_update_jingpai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_jingpai");
		dw_size = sizeof(NET_SIS_update_jingpai);
	}
	DWORD	dw_paimai_id;
	DWORD	dw_bidup;
};

// һ�ڼ۹���
struct NET_SIC_chaw_buy : public tag_net_message
{
	NET_SIC_chaw_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_chaw_buy");
		dw_size = sizeof(NET_SIC_chaw_buy);
	}
	DWORD	dw_paimai_id;
	DWORD	dw_safe_code;
};

struct NET_SIS_chaw_buy : public tag_net_message
{
	NET_SIS_chaw_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_chaw_buy");
		dw_size = sizeof(NET_SIS_chaw_buy);
	}
	DWORD	dw_error;
};

// ɾ��������Ϣ
struct NET_SIS_delete_paimai : public tag_net_message
{
	NET_SIS_delete_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_paimai");
		dw_size = sizeof(NET_SIS_delete_paimai);
	}
	DWORD	dw_paimai_id;
};

// ������ѯ
struct NET_SIC_paimai_query : public tag_net_message
{
	NET_SIC_paimai_query()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_paimai_query");
		dw_size = sizeof(NET_SIC_paimai_query);
	}

	tag_paimai_query	st_paimai_query;
};

struct NET_SIS_paimai_query : public tag_net_message
{
	NET_SIS_paimai_query()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_paimai_query");
		dw_size = sizeof(NET_SIS_paimai_query);
	}
	INT						n_page_num;				// ҳ��
	INT						n_num;					// ��Ϣ����
	tag_own_paimai_info		st_own_paimai[1];
};

// ������ҳ
struct NET_SIC_paimai_change_page : public tag_net_message
{
	NET_SIC_paimai_change_page()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_paimai_change_page");
		dw_size = sizeof(NET_SIC_paimai_change_page);
	}

	INT		n_page;
};


#pragma pack(pop)

#endif