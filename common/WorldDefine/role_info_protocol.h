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
*	@file		role_info_protocol.h
*	@author		lc
*	@date		2011/03/11	initial
*	@version	0.0.1.0
*	@brief		��ɫ��Ϣ��Ϣ
*/

#ifndef ROLE_INFO_PROTOCOL
#define ROLE_INFO_PROTOCOL


#include "protocol_common_errorcode.h"

#pragma pack(push, 1)

// �õ�ĳ��ɫID
struct NET_SIC_role_get_id : public tag_net_message
{
	NET_SIC_role_get_id()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_get_id");
		dw_size = sizeof(NET_SIC_role_get_id);
	}
	DWORD	dwRoleNameCrc;	// ��ɫ����crc32
};

// ����ĳ��ɫID	
struct NET_SIS_role_get_id : public tag_net_message
{
	NET_SIS_role_get_id()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_get_id");
		dw_size = sizeof(NET_SIS_role_get_id);
	}
	DWORD	dwRoleNameCrc;	// ��ɫ����crc32
	DWORD	dw_role_id;		// ����Ŀ����ҵ�roleid, = INVALID_VALUE��ʾ������
	TCHAR	szName[X_SHORT_NAME];	// name
};

// �õ�name
struct NET_SIC_get_name_by_nameid : public tag_net_message
{
	NET_SIC_get_name_by_nameid()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_name_by_nameid");
		dw_size = sizeof(NET_SIC_get_name_by_nameid);
	}
	DWORD	dwNameID;			// NameID
};

// ����name
struct NET_SIS_get_name_by_nameid : public tag_net_message
{
	NET_SIS_get_name_by_nameid()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_name_by_nameid");
		dw_size = sizeof(NET_SIS_get_name_by_nameid);
	}
	BOOL	bResult;				// TRUE = �ɹ�
	DWORD	dwNameID;				// ����NameID
	TCHAR	szName[X_SHORT_NAME];	// name
};


// һ��������ID��Ӧ������
struct NET_SIC_role_set_some_name : public tag_net_message
{
	NET_SIC_role_set_some_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_set_some_name");
		dw_size = sizeof(NET_SIC_role_set_some_name);
	}
	INT		nUserData;
	INT		n_num;		// id������
	DWORD	dwAllID[1];	// �䳤����,���dwNum��id
};


// ���ID�����ֶ�Ӧ�Ľṹ
struct tagRoleIDName
{
	DWORD dwID;
	TCHAR szName[X_SHORT_NAME];
};

struct NET_SIS_role_get_some_name : public tag_net_message
{
	NET_SIS_role_get_some_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_get_some_name");
		dw_size = sizeof(NET_SIS_role_get_some_name);
	}
	INT				nUserData;
	INT				n_num;				// ��������
	tagRoleIDName	IdName[1];
};

// �õ�ĳ��ɫǩ��
struct NET_SIC_role_get_signature_name : public tag_net_message
{
	NET_SIC_role_get_signature_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_get_signature_name");
		dw_size = sizeof(NET_SIC_role_get_signature_name);
	}
	DWORD	dw_role_id;	// ��ɫID
};

// ����ĳ��ɫǩ��	
struct NET_SIS_role_get_signature_name : public tag_net_message
{
	NET_SIS_role_get_signature_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_get_signature_name");
		dw_size = sizeof(NET_SIS_role_get_signature_name);
	}
	DWORD	dw_role_id;				// ����Ŀ����ҵ�roleid, = INVALID_VALUE��ʾ������
	TCHAR	szName[X_SHORT_NAME];	// ǩ��
	byte	by_sex;					// �Ա�
	INT		nLevel;					// �ȼ�
	INT		nClass;					// ְҵ
};

// �޸�ǩ��
struct NET_SIC_role_set_signature_name : public tag_net_message
{
	NET_SIC_role_set_signature_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_set_signature_name");
		dw_size = sizeof(NET_SIC_role_set_signature_name);
	}
	TCHAR	szName[X_SHORT_NAME];	// ǩ��
};

// ���Ƽ���,����������
struct NET_SIS_will_kick : public tag_net_message
{
	NET_SIS_will_kick()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_will_kick");
		dw_size = sizeof(NET_SIS_will_kick);
	}

	DWORD dwTime;		//�೤ʱ�䱻�ߵ�(����)
};
#pragma pack(pop)
#endif



