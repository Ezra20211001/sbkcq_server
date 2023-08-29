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
*	@file		role_title_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		��ɫ�ƺ���Ϣ
*/

#ifndef ROLE_TITLE_PROTOCOL
#define ROLE_TITLE_PROTOCOL

#pragma pack(push, 1)
#include "protocol_common_errorcode.h"
//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum
{
	E_Title_Success					= E_Success,	// �ɹ�
	E_Title_NotVisible				= 1,			// �ƺŲ��ɼ�
	E_Title_TitleNotObtained		= 2,			// �ƺ���δ���
	E_Title_NoTitleActived			= 3,			// ��ɫ��δ����ƺ�
	E_Title_TitleActivateFailed		= 4,			// ����ƺ�ʧ��
	E_Title_UnknownError			= 5,			// δ֪����

	E_Title_Buy_Not_Find			= 6,			// �ƺ�δ�ҵ�
	E_Title_Buy_Not_point			= 7,			// �ɾ͵�������
	E_Title_Buy_Not_level			= 8,			// �ȼ�����	
	E_Titel_Buy_Not_Before			= 9,			// ��ǰ�õȼ��ƺ�
	E_Title_Buy_Realy_Have			= 10,			// �ƺ��Ѿ�����
	E_Title_Buy_Cannot_buy			= 11,			// �óƺŲ��ܹ���
	E_Title_Buy_Account_level_not	= 12,			// �˺ų�ֵ������
	E_Title_Buy_Achievement_level_not= 13,			// ����ɾ����µȼ�����
	E_Title_Buy_Has_Color			= 14,			// �õȼ��ƺ�����

	E_Title_Return_Cannot			= 20,			// �óƺŲ��ܹ黹
};

// �ƺ�����
struct tagTitleData
{
	DWORD dwTitleID;	// �ƺ�id
	DWORD dwTime;		// ���ʱ��
};

//-----------------------------------------------------------------------------
// ���ý�ɫʹ��ĳ�ƺţ�u16TitleID��Чʱ����ʾ��ʹ�óƺţ�
//-----------------------------------------------------------------------------
struct NET_SIC_use_role_title : public tag_net_message
{
	NET_SIC_use_role_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_use_role_title");
		dw_size = sizeof(NET_SIC_use_role_title);
	}
	DWORD			dw_role_id;		// ��ɫID
	DWORD			u16TitleID;		// ��ǰʹ�õĳƺ�ID
	int				nIndex;
};

struct NET_SIS_use_role_title : public tag_net_message
{
	NET_SIS_use_role_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_use_role_title");
		dw_size = sizeof(NET_SIS_use_role_title);
	}
	DWORD			dw_error_code;	// ������
	DWORD			dw_role_id;		// ��ɫID
	DWORD			u16TitleID;		// �ƺ�ID
	int				nIndex;			
};

//-----------------------------------------------------------------------------
// �����ý�ɫ����ʹ�õĳƺ�
//-----------------------------------------------------------------------------
struct NET_SIC_get_using_titile : public tag_net_message
{
	NET_SIC_get_using_titile()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_using_titile");
		dw_size = sizeof(NET_SIC_get_using_titile);
	}
	DWORD			dw_role_id;		// ��ɫID
};

//-----------------------------------------------------------------------------
// ���ػ�ý�ɫ����ʹ�õĳƺ�
//-----------------------------------------------------------------------------
struct NET_SIS_get_using_title : public tag_net_message
{
	NET_SIS_get_using_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_using_title");
		dw_size = sizeof(NET_SIS_get_using_title);
	}
	DWORD			dw_error_code;	// ������
	DWORD			dw_role_id;		// ��ɫID
	DWORD			u16TitleID;		// title ID
};

//-----------------------------------------------------------------------------
// �����ý�ɫӵ�е����гƺ�
//-----------------------------------------------------------------------------
struct NET_SIC_get_role_titles : public tag_net_message
{
	NET_SIC_get_role_titles()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_role_titles");
		dw_size = sizeof(NET_SIC_get_role_titles);
	}
	DWORD			dw_role_id;		// ��ɫID
};

//-----------------------------------------------------------------------------
// ���ؽ�ɫӵ�е����гƺ�(�䳤�б�)
//-----------------------------------------------------------------------------
struct NET_SIS_get_role_titles : public tag_net_message
{
	NET_SIS_get_role_titles()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_titles");
		dw_size = sizeof(NET_SIS_get_role_titles);
	}
	DWORD			dw_error_code;	// ������
	DWORD			dw_role_id;		// ��ɫID
	DWORD			u16TitleNum;	// ��ǰ���ؽ�ɫ�ѻ�õĳƺ�����
	tagTitleData	byData[1];		// ��ǰ���ؽ�ɫ�ѻ�õĳƺ�ID
};

//-----------------------------------------------------------------------------
// ��ɫ����³ƺ�(����֪ͨ�ͻ���)
//-----------------------------------------------------------------------------
struct NET_SIS_net_titles : public tag_net_message
{
	NET_SIS_net_titles()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_net_titles");
		dw_size = sizeof(NET_SIS_net_titles);
	}
	DWORD			dw_role_id;		// ��ɫID
	DWORD			dw_title_id;	// �»�óƺ�
	DWORD			dw_time;		// ���ʱ��
};

//-----------------------------------------------------------------------------
// ɾ���ƺ�
//-----------------------------------------------------------------------------
struct NET_SIS_delete_title : public tag_net_message
{
	NET_SIS_delete_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_title");
		dw_size = sizeof(NET_SIS_delete_title);
	}
	DWORD			dw_role_id;		// ��ɫID
	DWORD			dw_title_id;	// ɾ���ĳƺ�
};


//-----------------------------------------------------------------------------
// ��ɫ����ʹ�óƺŷ����ı䣬����Χ��ҹ㲥
//-----------------------------------------------------------------------------
struct NET_SIS_role_title_change_broad : public tag_net_message
{
	NET_SIS_role_title_change_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_title_change_broad");
		dw_size = sizeof(NET_SIS_role_title_change_broad);
	}
	DWORD			dw_role_id;
	int				nIndex;
	DWORD			dwTitleID;		// �����ѡ�����سƺţ����ֶ�ΪINVALID_VALUE
};

// ����ƺ�
struct NET_SIC_role_title_buy : public tag_net_message
{
	struct NET_SIC_role_title_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_title_buy");
		dw_size = sizeof(NET_SIC_role_title_buy);
	}
	DWORD			dw_title_id;	// �ƺ�id
};

// ����ƺ�
struct NET_SIS_role_title_buy : public tag_net_message
{
	struct NET_SIS_role_title_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_title_buy");
		dw_size = sizeof(NET_SIS_role_title_buy);
	}
	DWORD			dwErrorCode;	// ������
};

// �黹�ƺ�
struct NET_SIC_role_title_return : public tag_net_message
{
	struct NET_SIC_role_title_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_title_return");
		dw_size = sizeof(NET_SIC_role_title_return);
	}
	DWORD			dw_title_id;	// �ƺ�id
};

// �黹�ƺ�
struct NET_SIS_role_title_return : public tag_net_message
{
	struct NET_SIS_role_title_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_title_return");
		dw_size = sizeof(NET_SIS_role_title_return);
	}
	DWORD			dw_title_id;	// �ƺ�id
	DWORD			dwErrorCode;	// ������
};

//-----------------------------------------------------------------------------
//֪ͨ�������Ƿ���ʾ��ǰ����ĳƺ� gx add 2013.10.31
//-----------------------------------------------------------------------------
struct NET_SIC_show_active_title : public tag_net_message
{
	struct NET_SIC_show_active_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_show_active_title");
		dw_size = sizeof(NET_SIC_show_active_title);
	}
	INT bshow_title[3];//��¼����������ƺ��Ƿ���ʾ���������
};

#pragma pack(pop)
#endif