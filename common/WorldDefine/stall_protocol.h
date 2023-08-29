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
*	@file		stall_protocol.h
*	@author		lc
*	@date		2011/03/10	initial
*	@version	0.0.1.0
*	@brief		��̯��Ϣ
*/

#ifndef STALL_PROTOCOL
#define STALL_PROTOCOL
 

#include "stall_define.h"

#pragma pack(push, 1)
//-----------------------------------------------------------------------------
// ��̯�߷��͵���Ϣ
//-----------------------------------------------------------------------------
// �򿪰�̯����
struct NET_SIC_stall_start : public tag_net_message
{
	NET_SIC_stall_start()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_start");
		dw_size = sizeof(NET_SIC_stall_start);
	}
	DWORD	dw_safe_code;
};

struct NET_SIS_stall_start : public tag_net_message
{
	NET_SIS_stall_start()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_start");
		dw_size = sizeof(NET_SIS_stall_start);
	}
	DWORD dw_error_code;
	BYTE  byMaxIndex;
	BYTE  byStallLevel;			// ̯λģ�͵ȼ�
};

// ��Ʒ�ϼ�
struct NET_SIC_stall_set_goods : public tag_net_message
{
	NET_SIC_stall_set_goods()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_set_goods");
		dw_size = sizeof(NET_SIC_stall_set_goods);
	}
	INT64	n64_serial;
	INT64	n64UnitPrice;
	BYTE	byIndex;				// �����ϵ���������0��ʼ
};

struct NET_SIS_stall_set_goods : public tag_net_message
{
	NET_SIS_stall_set_goods()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_set_goods");
		dw_size = sizeof(NET_SIS_stall_set_goods);
	}
	DWORD	dw_error_code;
};

// ��Ʒ�¼�
struct NET_SIC_stall_unset_goods : public tag_net_message
{
	NET_SIC_stall_unset_goods()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_unset_goods");
		dw_size = sizeof(NET_SIC_stall_unset_goods);
	}
	BYTE	byIndex;
};

struct NET_SIS_stall_unset_goods : public tag_net_message
{
	NET_SIS_stall_unset_goods()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_unset_goods");
		dw_size = sizeof(NET_SIS_stall_unset_goods);
	}
	DWORD	dw_error_code;
};

// ���ñ���
struct NET_SIC_stall_set_title : public tag_net_message
{
	NET_SIC_stall_set_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_set_title");
		dw_size = sizeof(NET_SIC_stall_set_title);
	}
	TCHAR	szData[1];// ����
};

struct NET_SIS_stall_set_title : public tag_net_message
{
	NET_SIS_stall_set_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_set_title");
		dw_size = sizeof(NET_SIS_stall_set_title);
	}
	DWORD	dw_error_code;
};

// ���ù��
struct NET_SIC_stall_set_advertisement : public tag_net_message
{
	NET_SIC_stall_set_advertisement()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_set_advertisement");
		dw_size = sizeof(NET_SIC_stall_set_advertisement);
	}
	TCHAR	szData[1];// ���
};

struct NET_SIS_stall_set_advertisement : public tag_net_message
{
	NET_SIS_stall_set_advertisement()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_set_advertisement");
		dw_size = sizeof(NET_SIS_stall_set_advertisement);
	}
	DWORD	dw_error_code;
};

// ���ù��㲥��־
struct NET_SIC_stall_set_advertisement_flag : public tag_net_message
{
	NET_SIC_stall_set_advertisement_flag()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_set_advertisement_flag");
		dw_size = sizeof(NET_SIC_stall_set_advertisement_flag);
	}
	bool	bFlag;					// 1��ʾ�㲥��0��ʾ���㲥
};

struct NET_SIS_stall_set_advertisement_flag : public tag_net_message
{
	NET_SIS_stall_set_advertisement_flag()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_set_advertisement_flag");
		dw_size = sizeof(NET_SIS_stall_set_advertisement_flag);
	}
	DWORD	dw_error_code;
};

// ��ɰ�̯���ã�������Χ���
struct NET_SIC_stall_set_finish : public tag_net_message
{
	NET_SIC_stall_set_finish()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_set_finish");
		dw_size = sizeof(NET_SIC_stall_set_finish);
	}
};

struct NET_SIS_stall_set_finish : public tag_net_message
{
	NET_SIS_stall_set_finish()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_set_finish");
		dw_size = sizeof(NET_SIS_stall_set_finish);
	}
	DWORD	dw_error_code;
	DWORD	dw_role_id;				// ��̯��ID
	BYTE	byStallLevel;			// ̯λģ�͵ȼ�
};

// ��̯
struct NET_SIC_stall_close : public tag_net_message
{
	NET_SIC_stall_close()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_close");
		dw_size = sizeof(NET_SIC_stall_close);
	}
};

struct NET_SIS_stall_close : public tag_net_message
{
	NET_SIS_stall_close()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_close");
		dw_size = sizeof(NET_SIS_stall_close);
	}
	DWORD	dw_error_code;
	DWORD	dwStallRoleID;			// ��̯��ID
};

struct NET_SIS_stall_buy_refresh : public tag_net_message
{
	NET_SIS_stall_buy_refresh()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_buy_refresh");
		dw_size = sizeof(NET_SIS_stall_buy_refresh);
	}
	DWORD	dwStallRoleID;			// ��̯��ID
	INT16	n16Num;					// ���º�̯λ����Ʒ����
	BYTE	byIndex;				// ̯λ����Ʒ��λ������
};

// ��Ʒ�ϼܹ㲥
struct NET_SIS_stall_set_refresh : public tag_net_message
{
	NET_SIS_stall_set_refresh()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_set_refresh");
		dw_size = sizeof(NET_SIS_stall_set_refresh);
	}
	DWORD	dwStallRoleID;			// ��̯��ID
	BYTE	byIndex;				// ̯λ����Ʒ��λ������
};

// ��Ʒ�¼ܹ㲥
struct NET_SIS_stall_unset_refresh : public tag_net_message
{
	NET_SIS_stall_unset_refresh()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_unset_refresh");
		dw_size = sizeof(NET_SIS_stall_unset_refresh);
	}
	DWORD	dwStallRoleID;			// ��̯��ID
	BYTE	byIndex;
};

struct NET_SIS_stall_buy_message : public tag_net_message
{
	NET_SIS_stall_buy_message()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_buy_message");
		dw_size = sizeof(NET_SIS_stall_buy_message);
	}
	DWORD dw_role_id;	//������ID
	DWORD dw_time;	//����ʱ��
	DWORD dw_data_id;//������Ʒ����
	INT16 n16Number;//��������
	INT64 n64_price;//���򵥼�   gx add 2013.6.25
};


//-----------------------------------------------------------------------------
// �����߷��͵���Ϣ
//-----------------------------------------------------------------------------
struct NET_SIC_stall_get : public tag_net_message
{
	NET_SIC_stall_get()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_get");
		dw_size = sizeof(NET_SIC_stall_get);
	}
	DWORD	dwStallRoleID;			// ��̯��ID
};

struct NET_SIS_stall_get : public tag_net_message
{
	NET_SIS_stall_get()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_get");
		dw_size = sizeof(NET_SIS_stall_get);
	}
	DWORD	dw_error_code;
	DWORD	dwStallRoleID;			// ��̯��ID
	BYTE	byNum;					// ��Ʒ����
	BYTE	byData[1];				// tagMsgStallGoods
};

struct NET_SIC_stall_get_title : public tag_net_message
{
	NET_SIC_stall_get_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_get_title");
		dw_size = sizeof(NET_SIC_stall_get_title);
	}
	INT nNumber;
	DWORD	dwStallRoleID[1];			// ��̯��ID
};

struct NET_SIS_stall_get_title : public tag_net_message
{
	NET_SIS_stall_get_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_get_title");
		dw_size = sizeof(NET_SIS_stall_get_title);
	}
	DWORD	dw_error_code;
	DWORD	dwStallRoleID;			// ��̯��ID
	TCHAR	szTitle[STALL_MAX_TITLE_NUM];
};

struct NET_SIC_stall_get_advertisement : public tag_net_message
{
	NET_SIC_stall_get_advertisement()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_get_advertisement");
		dw_size = sizeof(NET_SIC_stall_get_advertisement);
	}
	DWORD	dwStallRoleID;			// ��̯��ID
};

struct NET_SIS_stall_get_advertisement : public tag_net_message
{
	NET_SIS_stall_get_advertisement()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_get_advertisement");
		dw_size = sizeof(NET_SIS_stall_get_advertisement);
	}
	DWORD	dw_error_code;
	DWORD	dwStallRoleID;			// ��̯��ID
	TCHAR	szAd[STALL_AD_CHAR_MAX];
};

// ������Ʒ
struct NET_SIC_stall_buy : public tag_net_message
{
	NET_SIC_stall_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_buy");
		dw_size = sizeof(NET_SIC_stall_buy);
	}
	INT64	n64_serial;				// Ҫ�������Ʒ64λID
	INT64	n64UnitPrice;			// ��Ʒ����(�����Ʒ�Ƿ��й�������)
	DWORD	dwStallRoleID;			// ��̯��ID
	INT16	n16Num;					// ��Ʒ����
	BYTE	byIndex;				// ����̯λ�ĸ�������(��0��ʼ)
	DWORD	dw_safe_code;
};

struct NET_SIS_stall_buy : public tag_net_message
{
	NET_SIS_stall_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_buy");
		dw_size = sizeof(NET_SIS_stall_buy);
	}
	DWORD	dw_error_code;
};

// ��ȡָ��̯λ�ϵ���Ʒ
struct NET_SIC_stall_get_special : public tag_net_message
{
	NET_SIC_stall_get_special()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_get_special");
		dw_size = sizeof(NET_SIC_stall_get_special);
	}
	DWORD	dwStallRoleID;			// ��̯��ID
	BYTE	byIndex;				// ̯λ����Ʒ��λ������
};

struct NET_SIS_stall_get_special : public tag_net_message
{
	NET_SIS_stall_get_special()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_get_special");
		dw_size = sizeof(NET_SIS_stall_get_special);
	}
	DWORD	dw_error_code;
	DWORD	dwStallRoleID;			// ��̯��ID
	BYTE	byData[1];				// tagMsgStallGoods
};

struct NET_SIC_stall_history_chat : public tag_net_message
{
	NET_SIC_stall_history_chat()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_history_chat");
		dw_size = sizeof(NET_SIC_stall_history_chat);
	}
	DWORD dwStallRoleID;
};	

struct NET_SIS_stall_history_chat : public tag_net_message
{
	NET_SIS_stall_history_chat()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_history_chat");
		dw_size = sizeof(NET_SIS_stall_history_chat);
	}
	DWORD dwStallRoleID;
	BYTE  byNumber;
	tagStallMessage stMessage[1];
};


//--------------------------------------------------------------------
// ��̯�ߡ������߾���
//--------------------------------------------------------------------
struct NET_SIC_stall_chat : public tag_net_message
{
	NET_SIC_stall_chat()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stall_chat");
		dw_size = sizeof(NET_SIC_stall_chat);
	}
	DWORD dwStallRoleID;
	TCHAR cMessage[STALL_MESSAGE_CHAR_MAX];
};

struct NET_SIS_stall_chat : public tag_net_message
{
	NET_SIS_stall_chat()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_stall_chat");
		dw_size = sizeof(NET_SIS_stall_chat);
	}
	DWORD dwSender;
	DWORD dwStallRoleID;
	TCHAR cMessage[STALL_MESSAGE_CHAR_MAX];
};


//-----------------------------------------------------------------------------
// VIP̯λ��Ϣ
//-----------------------------------------------------------------------------
struct NET_SIC_get_all_vip_stall_info : public tag_net_message
{
	NET_SIC_get_all_vip_stall_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_all_vip_stall_info");
		dw_size = sizeof(NET_SIC_get_all_vip_stall_info);
	}
};

struct NET_SIS_get_all_vip_stall_info : public tag_net_message
{
	NET_SIS_get_all_vip_stall_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_all_vip_stall_info");
		dw_size = sizeof(NET_SIS_get_all_vip_stall_info);
	}
	DWORD		dw_error_code;
	DWORD		dwRequestTime;
	tagVIPStall	VIPStallInfo[VIP_STALL_MAX_NUM];
};

struct NET_SIC_update_vip_stall_info : public tag_net_message
{
	NET_SIC_update_vip_stall_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_update_vip_stall_info");
		dw_size = sizeof(NET_SIC_update_vip_stall_info);
	}
	DWORD		dwRequestTime;		// VIP̯λ��Ϣ����ʱ��
};

struct NET_SIS_update_vip_stall_info : public tag_net_message
{
	NET_SIS_update_vip_stall_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_vip_stall_info");
		dw_size = sizeof(NET_SIS_update_vip_stall_info);
	}
	DWORD		dw_error_code;
	DWORD		dwRequestTime;		// VIP̯λ��Ϣ����ʱ��
	INT32		nInfoNum;			// ����̯λ��Ϣ��Ŀ��
	tagVIPStall	VIPStallInfo[1];	// ������Ϣ
};

struct NET_SIC_apply_vip_stall : public tag_net_message
{
	NET_SIC_apply_vip_stall()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_apply_vip_stall");
		dw_size = sizeof(NET_SIC_apply_vip_stall);
	}
	INT32		nRent;				// ̯λ���
	BYTE		byIndex;			// ̯λ���
};

struct NET_SIS_apply_vip_stall : public tag_net_message
{
	NET_SIS_apply_vip_stall()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_apply_vip_stall");
		dw_size = sizeof(NET_SIS_apply_vip_stall);
	}
	DWORD		dw_error_code;
};

struct NET_SIC_special_vip_stall_get : public tag_net_message
{
	NET_SIC_special_vip_stall_get()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_special_vip_stall_get");
		dw_size = sizeof(NET_SIC_special_vip_stall_get);
	}
	BYTE		byIndex;			// VIP̯λ���
};

struct NET_SIS_special_vip_stall_get : public tag_net_message
{
	NET_SIS_special_vip_stall_get()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_special_vip_stall_get");
		dw_size = sizeof(NET_SIS_special_vip_stall_get);
	}
	DWORD		dw_error_code;
};

struct NET_SIC_vip_stall_buy : public tag_net_message
{
	NET_SIC_vip_stall_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_vip_stall_buy");
		dw_size = sizeof(NET_SIC_vip_stall_buy);
	}
	INT64	n64_serial;				// Ҫ�������Ʒ64λID
	INT64	n64UnitPrice;			// ��Ʒ����(�����Ʒ�Ƿ��й�������)
	DWORD	dwStallRoleID;			// ��̯��ID
	INT16	n16Num;					// ��Ʒ����
	BYTE	byIndex;				// ����̯λ�ĸ�������(��0��ʼ)
};

struct NET_SIS_vip_stall_buy : public tag_net_message
{
	NET_SIS_vip_stall_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_vip_stall_buy");
		dw_size = sizeof(NET_SIS_vip_stall_buy);
	}
	DWORD		dw_error_code;
};


//-----------------------------------------------------------------------------
#pragma pack(pop)
#endif