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
*	@file		motion_protocol.h
*	@author		lc
*	@date		2011/03/08	initial
*	@version	0.0.1.0
*	@brief		��ɫ������Ϣ
*/

#ifndef MOTION_PROTOCOL
#define MOTION_PROTOCOL

#pragma pack(push, 1)

enum 
{
	E_Motion_Success			= 0,
	E_Motion_NotValid			= 1,	// ������Ч
	E_Motion_CanotActive		= 2,	// �޷����н���
	E_Motion_FriendValNotEnough	= 3,	// �ѺöȲ�����
	E_Motion_DistanceNotEnough	= 4,	// ���벻��
	E_Motion_RoleNotFround		= 5,	// ����û�ҵ�
	E_Motion_DstRoleRefuse		= 6,	// Ŀ����Ҿܾ�
};

/*******************************************************************************
�������̣�
	��֤�׶Σ�
		1.�ͻ��˷�NET_SIC_double_motion_invite���������
		2.�����������жϣ���ͨ������NET_SIS_double_motion_on_invite�����������
		3.���������ѡ���Ƿ���ܷ���NET_SIC_double_motion_on_invite��������
		4.����������NET_SIS_double_motion_invite��������ҽ��
	��ʼ������
		5.��������յ�NET_SIS_double_motion_invite���ܵ���������Ҵ�
		6.������������������NET_SIC_double_motion_start��ʼ˫�˶���
		7.�������㲥��˫�˶�����ʼ	
*******************************************************************************/

//------------------------------------------------------------------------------
// ������
//------------------------------------------------------------------------------
CONST INT MAX_MOTION_DIST	= 50 * 10;

//----------------------------------------------------------------------------
// �ͻ��˱��ݸ��Զ���
//----------------------------------------------------------------------------
struct NET_SIC_role_style_action : public tag_net_message
{
	NET_SIC_role_style_action()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_style_action");
		dw_size = sizeof(NET_SIC_role_style_action);
	}
	DWORD			dwActionID;
};

struct NET_SIS_role_style_action : public tag_net_message
{
	NET_SIS_role_style_action()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_style_action");
		dw_size = sizeof(NET_SIS_role_style_action);
	}
	DWORD			dw_role_id;
	DWORD			dwDstRoleID;
	DWORD			dwActionID;
};


//------------------------------------------------------------------------------
// ˫�˶��� �����������Ϣ
//------------------------------------------------------------------------------
struct NET_SIC_double_motion_invite : public tag_net_message
{
	NET_SIC_double_motion_invite()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_double_motion_invite");
		dw_size = sizeof(NET_SIC_double_motion_invite);
	}
	DWORD	dwDstRoleID;	// Ŀ�����id
	DWORD	dwActionID;		// ����id
};

struct NET_SIS_double_motion_invite : public tag_net_message
{
	NET_SIS_double_motion_invite()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_double_motion_invite");
		dw_size = sizeof(NET_SIS_double_motion_invite);
	}
	DWORD	dwErrCode;		// ������
};

//------------------------------------------------------------------------------
// ˫�˶��� ���������Ϣ
//------------------------------------------------------------------------------
struct NET_SIS_double_motion_on_invite : public tag_net_message
{
	NET_SIS_double_motion_on_invite()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_double_motion_on_invite");
		dw_size = sizeof(NET_SIS_double_motion_on_invite);
	}
	DWORD	dwSrcRoleID;	// �������id
	DWORD	dwActionID;		// ����id
};

struct NET_SIC_double_motion_on_invite : public tag_net_message
{
	NET_SIC_double_motion_on_invite()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_double_motion_on_invite");
		dw_size = sizeof(NET_SIC_double_motion_on_invite);
	}
	DWORD	dwSrcRoleID;	// �������id
	DWORD	dwActionID;		// ����id
	BOOL	bAccpet;		// �Ƿ�ͬ��
};

//------------------------------------------------------------------------------
// ˫�˶��� ��ʼ����
//------------------------------------------------------------------------------
struct NET_SIC_double_motion_start : public tag_net_message
{
	NET_SIC_double_motion_start()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_double_motion_start");
		dw_size = sizeof(NET_SIC_double_motion_start);
	}
	DWORD	dwDstRoleID;	// Ŀ�����id
	DWORD	dwActionID;		// ����id
};



#pragma pack(pop)
#endif