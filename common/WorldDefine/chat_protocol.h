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
*	@file		chat_protocol.h
*	@author		lc
*	@date		2011/02/28	initial
*	@version	0.0.1.0
*	@brief		��ɫ������Ϣ
*/


#ifndef CHAR_PROTOCOL
#define CHAR_PROTOCOL

#include "protocol_common_errorcode.h"

#define MAX_NOTICE_TITLE	8
#define MAX_NOTICE_MSG_LEN	1024


#pragma pack(push, 1)

//������Ƶ�� ���� չʾ��Ʒ��װ�� ��Ԫ��ֵ
#define WORLD_CHANNEL_DEC_Fortune 1

//chat�������
enum
{
	E_RoleChat_ForbidChat				= 1,				//��ֹ����
	E_RoleChat_ServerNotReady			= 2,				//������û��׼����
	E_RoleChat_TooLength				= 3,				//��Ϣ���ȹ���(����100����)

	E_RoleChat_Decree_OutOfYuanBao			= 10,				//گ������,Ԫ������

	E_RoleChat_World_NoItem				= 20,				//����,û�е���
	E_RoleChat_World_Frequently			= 21,				//����,���Թ���
	E_RoleChat_World_NoFortune			= 22,				//����,Ԫ������
	E_RoleChat_World_RoleNo10			= 23,				//����,����û��10��

	E_RoleChat_Secret_RemoteRoleLeave	= 30,				//����,�Է�������
	E_RoleChat_Secret_NoRoleName		= 31,				//����,û��Ŀ����� 
	E_RoleChat_Secret_NoSelf			= 32,				//����,�Լ��������Լ�����

	E_RoleChat_Map_Frequently			= 35,				//����,���Թ���
	E_RoleChat_Map_RoleNo10				= 36,				//����,����û��10��

	E_RoleChat_Guild_NoJoin				= 40,				//���,û������

	E_RoleChat_Team_NoJoin				= 50,				//����,û�ж���

	E_RoleChat_Common_Frequently		= 60,				//��ͨ,���Թ���
	E_RoleChat_Quest_Bag_Full			= 70,				//������Ʒ��������
	E_RoleChat_Not_GM					= 80,				//�����˲���GM

};

const DWORD MAX_CHAT_LEN = 200;						//�ͻ���������������

//! ��ĳ�˶Ի�
struct NET_SIC_role_char : public tag_net_message
{
	NET_SIC_role_char()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_char");
		dw_size = sizeof(NET_SIC_role_char);
	}
	DWORD	dwDestRoleID;	//����˭�Ի�
	BYTE	byChannel;		//��Ƶ��
	BYTE	byAutoReply;	//���Ƿ��Զ��ظ� 0������ 1����
	DWORD	dw_safe_code;
	TCHAR	szMsg[1];		//���Ի�����   
};

//! ĳ�˺���Ի�
struct NET_SIS_role_char :public tag_net_message
{
	NET_SIS_role_char()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_char");
		dw_size = sizeof(NET_SIS_role_char);
	}
	DWORD	dw_error_code;	
	DWORD	dwSrcRoleID;	//��˭����˵����INVALID_VALUEϵͳ���ͣ�
	DWORD	dwDestRoleID;	//����˭˵��
	BYTE	byChannel;		//��Ƶ��
	BYTE	byAutoReply;	//���Ƿ��Զ��ظ� 0:���� 1:��
	BYTE  bGM;
	TCHAR	szMsg[1];		//���Ի�����
};

//����ȡ����
struct NET_SIC_leave_word : public tag_net_message
{
	NET_SIC_leave_word()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_word");
		dw_size = sizeof(NET_SIC_leave_word);
	}
};

//! �Զ�����
struct NET_SIS_auto_placard : public tag_net_message
{
	NET_SIS_auto_placard()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_auto_placard");
		dw_size = sizeof(NET_SIS_auto_placard);
	}
	INT				nType;							//! ������ɫ
	INT				nCirInterval;					//��ѭ�����ʱ��
	TCHAR			szContent[1];					//����������
};


//! ���½ǹ���
struct NET_SIS_right_placard : public tag_net_message
{
	NET_SIS_right_placard()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_right_placard");
		dw_size = sizeof(NET_SIS_right_placard);
	}
	INT				nTitleLen;						//�����ⳤ��
	INT				nLinkLen;						//�����ӳ���
	INT				nContentLen;					//�����ݳ���
	TCHAR			szContent[1];
};


#pragma pack(pop)
#endif