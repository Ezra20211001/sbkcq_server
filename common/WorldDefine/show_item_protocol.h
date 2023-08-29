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
*	@file		show_item_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		չʾ��Ʒ��Ϣ
*/


#ifndef SHOW_ITEM_PROTOCOL
#define SHOW_ITEM_PROTOCOL

#include "protocol_common_errorcode.h"
#include "ItemDefine.h"
#include "container_define.h"

#pragma pack(push, 1)

//������
enum
{
	E_RoleShowItem_ForbidChat			    = 1,				//��ֹչʾ
	E_RoleShowItem_ServerNotReady			= 2,				//������û��׼����
	E_RoleShowItem_SendFailure			    = 3,				//������Ʒʧ��
	E_RoleShowItem_Frequently			    = 4,				//չʾ����

	E_RoleShowItem_World_NoItem				= 20,				//����,û�е���
	E_RoleShowItem_World_NoMoney			= 21,				//����,û���㹻����

	E_RoleShowItem_Pvt_RemoteRoleLeave		= 30,				//˽��,�Է�������
	E_RoleShowItem_Pvt_NoRoleName			= 31,				//˽��,û��Ŀ����� 
	E_RoleShowItem_Pvt_NoSelf				= 32,				//˽��,�Լ��������Լ�˽��

	E_RoleShowItem_Guild_NoJoin				= 40,				//����,û������

	E_RoleShowItem_Troop_NoJoin				= 50,				//����,û�ж���
};

//-----------------------------------------------------------------------------
//	չʾװ��
//-----------------------------------------------------------------------------
struct NET_SIC_role_show_equip : public tag_net_message
{
	NET_SIC_role_show_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_show_equip");
		dw_size = sizeof(NET_SIC_role_show_equip);
	}
	DWORD		 dwDestRoleID;	// ��˭չʾ
	BYTE		 byChannel;		// չʾƵ��
	EItemConType eConType;      // װ��λ��(�����ȵ�)
	INT64		 n64_serial;		// װ��64λID
	TCHAR		 szMsg[1];
};

struct NET_SIS_role_show_equip : public tag_net_message
{
	NET_SIS_role_show_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_show_equip");
		dw_size = sizeof(NET_SIS_role_show_equip);
	}
	DWORD		dwSrcRoleID;	// ��˭չʾ INVALID_VALUE����ϵͳ����
	DWORD		dwDestRoleID;	// �Ƕ�˭չʾ
	BYTE		byChannel;		// չʾƵ��
	BYTE		bGM;
	DWORD		dw_error_code;	// ������
	SHORT		sEquipSize;		// װ����Ϣ
	SHORT		sMsgSize;		// ������Ϣ
	BYTE	    byBuffer[1];	// װ���ṹ tagEquip
};


//-----------------------------------------------------------------------------
//	չʾ��Ʒ
//-----------------------------------------------------------------------------
struct NET_SIC_role_show_item : public tag_net_message
{
	NET_SIC_role_show_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_show_item");
		dw_size = sizeof(NET_SIC_role_show_item);
	}
	DWORD		 dwDestRoleID;	// ��˭չʾ
	BYTE		 byChannel;		// չʾƵ��
	EItemConType eConType;		// ��Ʒλ��(�����ȵ�)
	INT64		 n64_serial;		// ��Ʒ64λID
	TCHAR		 szMsg[1];
};

struct NET_SIS_role_show_item : public tag_net_message
{
	NET_SIS_role_show_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_show_item");
		dw_size = sizeof(NET_SIS_role_show_item);
	}
	DWORD		dwSrcRoleID;	// ��˭չʾ INVALID_VALUE����ϵͳ����
	DWORD		dwDestRoleID;	// �Ƕ�˭չʾ
	BYTE		byChannel;		// չʾƵ��
	BYTE		bGM;
	DWORD		dw_error_code;	// ������
	DWORD	    dw_data_id;		// ��ƷTypeID tagItem
	TCHAR		szMsg[1];
};


#pragma pack(pop)
#endif