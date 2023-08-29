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
*	@file		guild_protocol.h
*	@author		lc
*	@date		2011/03/07	initial
*	@version	0.0.1.0
*	@brief		�����Ϣ
*/

#ifndef GUILD_PROTOCOL
#define GUILD_PROTOCOL


#include "protocol_common_errorcode.h"
#include "guild_define.h"


#pragma pack(push, 1)
//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum
{
	E_SBK_ERROR_1	=	1,		//ûȨ�ޱ���
	E_SBK_ERROR_2	=	2,		//�Ѿ�������
	E_SBK_ERROR_3	=	3,		//ɳ�Ϳ˹��᲻�ñ���
	E_SBK_ERROR_4	=	4,		//����ʽ���
	E_SBK_ERROR_5	=	5,		//�����ظ���ȡɳ�Ϳ˽���
	E_SBK_ERROR_6	=	6,		//�ܶ����岻�ܱ���
	E_SBK_ERROR_7	=	7,		//��������������ȡ
};

//----------------------------------------------------------------------------
// ��������
//----------------------------------------------------------------------------
struct NET_SIC_guild_create : public tag_net_message
{
	NET_SIC_guild_create()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_create");
		dw_size = sizeof(NET_SIC_guild_create);
	}
	INT64		n64ItemID;
	TCHAR		szGuildName[1];
};

// ȫ��
struct NET_SIC_guild_create_broad : public tag_net_message
{
	NET_SIC_guild_create_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_create_broad");
		dw_size = sizeof(NET_SIC_guild_create_broad);
	}
	DWORD		dw_role_id;		// ������id
	DWORD		dwRoleNameID;	// ����������id
	DWORD		dwGuildID;
	TCHAR		szName[1];		// ��ɫ��+������
};


//----------------------------------------------------------------------------
// ��ɢ����
//----------------------------------------------------------------------------
struct NET_SIC_guild_dismiss : public tag_net_message
{
	NET_SIC_guild_dismiss()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_dismiss");
		dw_size = sizeof(NET_SIC_guild_dismiss);
	}
	DWORD		dwNPCID;
};

// ȫ��
struct NET_SIS_guild_dismiss_broad : public tag_net_message
{
	NET_SIS_guild_dismiss_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_dismiss_broad");
		dw_size = sizeof(NET_SIS_guild_dismiss_broad);
	}
	DWORD		dw_role_id;
	TCHAR		szGuildName[1];
};


//----------------------------------------------------------------------------
// �������
//----------------------------------------------------------------------------
// �������Ŀ��������
struct NET_SIC_guild_join_request : public tag_net_message
{
	NET_SIC_guild_join_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_join_request");
		dw_size = sizeof(NET_SIC_guild_join_request);
	}
	DWORD		dwDstRoleID;
};

// �������Ŀ��������
struct NET_SIC_guild_join_request_by_name : public tag_net_message
{
	NET_SIC_guild_join_request_by_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_join_request_by_name");
		dw_size = sizeof(NET_SIC_guild_join_request_by_name);
	}
	DWORD 		dwNameCrc;
};

// �������������͸�Ŀ�����
struct NET_SIS_guild_join_request : public tag_net_message
{
	NET_SIS_guild_join_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_join_request");
		dw_size = sizeof(NET_SIS_guild_join_request);
	}
	DWORD		dwSrcRoleID;
	DWORD		dwGuildID;
	BOOL		b_sign;		// 0 ��ͨ���� 1 ���ת������
};

// Ŀ����ҷ���������
struct NET_SIC_guild_join_request_result : public tag_net_message
{
	NET_SIC_guild_join_request_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_join_request_result");
		dw_size = sizeof(NET_SIC_guild_join_request_result);
	}
	DWORD		dw_error_code;
	DWORD		dwDstRoleID;
	DWORD		dwDstGuildID;
};

// ������ת����Ŀ����ҷ���
struct NET_SIS_guild_join_request_result : public tag_net_message
{
	NET_SIS_guild_join_request_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_join_request_result");
		dw_size = sizeof(NET_SIS_guild_join_request_result);
	}
	DWORD		dw_error_code;
	DWORD		dwInviterID;
	DWORD		dwInviteeID;
};

// �����ڹ㲥
struct NET_SIS_guild_join_broad : public tag_net_message
{
	NET_SIS_guild_join_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_join_broad");
		dw_size = sizeof(NET_SIS_guild_join_broad);
	}
	DWORD		dw_role_id;
	DWORD		dwRoleNameID;
	TCHAR		szRoleName[1];
};


//------------------------------------------------------------------------------
// ����뿪����
//------------------------------------------------------------------------------
struct NET_SIC_guild_leave : public tag_net_message
{
	NET_SIC_guild_leave()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_leave");
		dw_size = sizeof(NET_SIC_guild_leave);
	}
};

struct NET_SIS_guild_leave_broad : public tag_net_message
{
	NET_SIS_guild_leave_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_leave_broad");
		dw_size = sizeof(NET_SIS_guild_leave_broad);
	}
	DWORD		dwSrcRoleID;
};


//------------------------------------------------------------------------------
// ������ҳ���
//------------------------------------------------------------------------------
struct NET_SIC_guild_kick : public tag_net_message
{
	NET_SIC_guild_kick()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_kick");
		dw_size = sizeof(NET_SIC_guild_kick);
	}
	DWORD		dw_role_id;
};

struct NET_SIS_guild_kick_broad : public tag_net_message
{
	NET_SIS_guild_kick_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_kick_broad");
		dw_size = sizeof(NET_SIS_guild_kick_broad);
	}
	DWORD		dwDstRoleID;
};


//------------------------------------------------------------------------------
// �ƽ�����
//------------------------------------------------------------------------------
struct NET_SIC_guild_trunover : public tag_net_message
{
	NET_SIC_guild_trunover()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_trunover");
		dw_size = sizeof(NET_SIC_guild_trunover);
	}
	DWORD		dw_role_id;
	DWORD		dw_safe_code;
};

struct NET_SIS_guild_trunover_broad : public tag_net_message
{
	NET_SIS_guild_trunover_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_trunover_broad");
		dw_size = sizeof(NET_SIS_guild_trunover_broad);
	}
	DWORD		dwSrcRoleID;
	DWORD		dwDstRoleID;
};


//------------------------------------------------------------------------------
// ��ȥְ��
//------------------------------------------------------------------------------
struct NET_SIC_guild_demiss : public tag_net_message
{
	NET_SIC_guild_demiss()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_demiss");
		dw_size = sizeof(NET_SIC_guild_demiss);
	}
};

struct NET_SIS_guild_demiss_broad : public tag_net_message
{
	NET_SIS_guild_demiss_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_demiss_broad");
		dw_size = sizeof(NET_SIS_guild_demiss_broad);
	}
	DWORD		dw_role_id;
	INT8		n8OldGuildPos;
};


//------------------------------------------------------------------------------
// �������ְλ
//------------------------------------------------------------------------------
struct NET_SIC_guild_appoint : public tag_net_message
{
	NET_SIC_guild_appoint()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_appoint");
		dw_size = sizeof(NET_SIC_guild_appoint);
	}
	DWORD			dw_role_id;
	EGuildMemberPos	ePos;
};

struct NET_SIS_guild_appoint_broad : public tag_net_message
{
	NET_SIS_guild_appoint_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_appoint_broad");
		dw_size = sizeof(NET_SIS_guild_appoint_broad);
	}
	DWORD			dwSrcRoleID;
	DWORD			dwDstRoleID;
	EGuildMemberPos	ePos;
};


//------------------------------------------------------------------------------
// �޸���ּ
//------------------------------------------------------------------------------
struct NET_SIC_guild_tenet_change : public tag_net_message
{
	NET_SIC_guild_tenet_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_tenet_change");
		dw_size = sizeof(NET_SIC_guild_tenet_change);
	}
	TCHAR			szTenet[1];
};

struct NET_SIS_guild_tenet_change_broad : public tag_net_message
{
	NET_SIS_guild_tenet_change_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_tenet_change_broad");
		dw_size = sizeof(NET_SIS_guild_tenet_change_broad);
	}
	DWORD			dw_role_id;
	TCHAR			szTenet[1];
};


//------------------------------------------------------------------------------
// �޸İ���־
//------------------------------------------------------------------------------
struct NET_SIC_guild_symbol : public tag_net_message
{
	NET_SIC_guild_symbol()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_symbol");
		dw_size = sizeof(NET_SIC_guild_symbol);
	}
	TCHAR			szText[1];
};

struct NET_SIS_guild_symbol_broad : public tag_net_message
{
	NET_SIS_guild_symbol_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_symbol_broad");
		dw_size = sizeof(NET_SIS_guild_symbol_broad);
	}
	DWORD			dw_role_id;
	TCHAR			szText[1];
};


//------------------------------------------------------------------------------
// ����ǩ��
//------------------------------------------------------------------------------
struct NET_SIC_invite_sign : public tag_net_message
{
	NET_SIC_invite_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_invite_sign");
		dw_size = sizeof(NET_SIC_invite_sign);
	}
	DWORD			dwInviteID;				// ������ID
	DWORD			dwBeInviteID;			// ��������ID
	INT64			n64ItemID;
};

struct NET_SIS_invite_sign : public tag_net_message
{
	NET_SIS_invite_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_sign");
		dw_size = sizeof(NET_SIS_invite_sign);
	}
	DWORD dwError;
};

struct NET_SIS_invite_sign_data : public tag_net_message
{
	NET_SIS_invite_sign_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_sign_data");
		dw_size = sizeof(NET_SIS_invite_sign_data);
	}
	DWORD			dwInviteID;				// ������ID
	tagGuildSignData st_GuildSignData;
};


//------------------------------------------------------------------------------
// ȡ��ǩ��
//------------------------------------------------------------------------------
struct NET_SIC_cancel_sign : public tag_net_message
{
	NET_SIC_cancel_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_sign");
		dw_size = sizeof(NET_SIC_cancel_sign);
	}
};

struct NET_SIS_cancel_sign : public tag_net_message
{
	NET_SIS_cancel_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_sign");
		dw_size = sizeof(NET_SIS_cancel_sign);
	}
};

//------------------------------------------------------------------------------
// ȷ��ǩ��
//------------------------------------------------------------------------------
struct NET_SIC_affirmance_sign : public tag_net_message
{
	NET_SIC_affirmance_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_affirmance_sign");
		dw_size = sizeof(NET_SIC_affirmance_sign);
	}
};

struct NET_SIS_affirmance_sign : public tag_net_message
{
	NET_SIS_affirmance_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_affirmance_sign");
		dw_size = sizeof(NET_SIS_affirmance_sign);
	}
	DWORD  dwSignID;			// ǩ����ID
};

struct NET_SIS_affirmance_sign_res : public tag_net_message
{
	NET_SIS_affirmance_sign_res()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_affirmance_sign_res");
		dw_size = sizeof(*this);
	}
};


//------------------------------------------------------------------------------
// �ύǩ��
//------------------------------------------------------------------------------
struct NET_SIC_refer_sign : public tag_net_message
{
	NET_SIC_refer_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_refer_sign");
		dw_size = sizeof(NET_SIC_refer_sign);
	}
	DWORD dwNPCID;				// NPCID
	INT64 n64ItemID;			
};

struct NET_SIS_refer_sign : public tag_net_message
{
	NET_SIS_refer_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_refer_sign");
		dw_size = sizeof(NET_SIS_refer_sign);
	}
	DWORD dwError;		
};


//------------------------------------------------------------------------------
// ��ȡ��������
//------------------------------------------------------------------------------
struct NET_SIC_get_guild_delate_data : public tag_net_message
{
	NET_SIC_get_guild_delate_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_delate_data");
		dw_size = sizeof(NET_SIC_get_guild_delate_data);
	}
};

struct NET_SIS_get_guild_delate_data : public tag_net_message
{
	NET_SIS_get_guild_delate_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_delate_data");
		dw_size = sizeof(NET_SIS_get_guild_delate_data);
	}
	tagGuildDelateBase stGuildDelateBase;
};

//------------------------------------------------------------------------------
// ��ȡ������������
//------------------------------------------------------------------------------
struct NET_SIC_get_guild_delate_content : public tag_net_message
{
	NET_SIC_get_guild_delate_content()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_delate_content");
		dw_size = sizeof(NET_SIC_get_guild_delate_content);
	}
};

struct NET_SIS_get_guild_delate_content : public tag_net_message
{
	NET_SIS_get_guild_delate_content()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_delate_content");
		dw_size = sizeof(NET_SIS_get_guild_delate_content);
	}
	TCHAR		szContent[1];
};


//------------------------------------------------------------------------------
// ��������
//------------------------------------------------------------------------------
struct NET_SIC_delate_leader : public tag_net_message
{
	NET_SIC_delate_leader()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delate_leader");
		dw_size = sizeof(NET_SIC_delate_leader);
	}
	INT64		n64ItemID;
	TCHAR		szContent[1];
};

struct NET_SIS_delate_leader : public tag_net_message
{
	NET_SIS_delate_leader()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delate_leader");
		dw_size = sizeof(NET_SIS_delate_leader);
	}
	DWORD		dwError;
};

//------------------------------------------------------------------------------
// ����ͶƱ
//------------------------------------------------------------------------------
struct NET_SIC_delate_ballot : public tag_net_message
{
	NET_SIC_delate_ballot()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delate_ballot");
		dw_size = sizeof(NET_SIC_delate_ballot);
	}
	BOOL		bAgree;
};

struct NET_SIS_delate_ballot : public tag_net_message
{
	NET_SIS_delate_ballot()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delate_ballot");
		dw_size = sizeof(NET_SIS_delate_ballot);
	}
	DWORD		dwError;
};


//------------------------------------------------------------------------------
// ����ʧ�ܷ���
//------------------------------------------------------------------------------
struct NET_SIS_guild_failed_disposal : public tag_net_message
{
	NET_SIS_guild_failed_disposal()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_failed_disposal");
		dw_size = sizeof(NET_SIS_guild_failed_disposal);
	}
	DWORD			dw_error_code;
};

//----------------------------------------------------------------------------
// ͬ��������Ϣ
//----------------------------------------------------------------------------
struct NET_SIC_synchronize_guild_info : public tag_net_message
{
	NET_SIC_synchronize_guild_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_synchronize_guild_info");
		dw_size = sizeof(NET_SIC_synchronize_guild_info);
	}
};

struct NET_SIS_synchronize_guild_info : public tag_net_message
{
	NET_SIS_synchronize_guild_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_guild_info");
		dw_size = sizeof(NET_SIS_synchronize_guild_info);
	}
	tagGuildBase	sGuildInfo;
};

// ͬ�����ս�����Ϣ
struct NET_SIC_synchronize_guild_war_info : public tag_net_message
{
	NET_SIC_synchronize_guild_war_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_synchronize_guild_war_info");
		dw_size = sizeof(NET_SIC_synchronize_guild_war_info);
	}
};

struct NET_SIS_synchronize_guild_war_info : public tag_net_message
{
	NET_SIS_synchronize_guild_war_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_guild_war_info");
		dw_size = sizeof(NET_SIS_synchronize_guild_war_info);
	}
	DWORD			dwMaxWarNum;	// �������
	DWORD			dwCurWarNum;	// ��ǰ����
	double			fMoneyParam;	// ��������
	EGuildWarState	eSatae;			// ��ǰ״̬
	DWORD			dwBeginTime;	// ��ʼʱ��
	DWORD			dwGulldID;		// �ж԰��id
	TCHAR			szGuildName[X_SHORT_NAME]; // �ж���
	BYTE			byEnemyLevel;	// �жԵȼ�
	BOOL			bDefenter;		// �Ƿ���ط�
	BOOL			bRelay;			// �Ƿ�׼�����
	DWORD				dwSymbolValue;				// ����־
	TCHAR				szText[2];					// �������

};


//----------------------------------------------------------------------------
// ������Ϣ
//----------------------------------------------------------------------------
struct NET_SIS_guild_info : public tag_net_message
{
	NET_SIS_guild_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_info");
		dw_size = sizeof(NET_SIS_guild_info);
	}
	tagGuildBase	sGuildInfo;
};


//----------------------------------------------------------------------------
// ��ȡ�������г�Ա
//----------------------------------------------------------------------------
struct NET_SIC_guild_get_all_member : public tag_net_message
{
	NET_SIC_guild_get_all_member()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_get_all_member");
		dw_size = sizeof(NET_SIC_guild_get_all_member);
	}
};

struct NET_SIS_guild_get_all_member : public tag_net_message
{
	NET_SIS_guild_get_all_member()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_get_all_member");
		dw_size = sizeof(NET_SIS_guild_get_all_member);
	}
	DWORD		dw_error_code;
	INT16		n16Num;
	BYTE		byData[1];		// tagGuildMemInfo
};


//----------------------------------------------------------------------------
// ��ȡ����ָ����Ա��չ��Ϣ
//----------------------------------------------------------------------------
struct NET_SIC_guild_get_member_extend : public tag_net_message
{
	NET_SIC_guild_get_member_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_get_member_extend");
		dw_size = sizeof(NET_SIC_guild_get_member_extend);
	}
	DWORD		dw_role_id;
};

struct NET_SIS_guild_get_member_extend : public tag_net_message
{
	NET_SIS_guild_get_member_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_get_member_extend");
		dw_size = sizeof(NET_SIS_guild_get_member_extend);
	}
	DWORD				dw_role_id;
	tagGuildMemInfoEx	sGuildMemInfoEx;
};

//----------------------------------------------------------------------------
// ˢ�°���ָ����Ա��չ��Ϣ
//----------------------------------------------------------------------------
struct NET_SIC_guild_refresh_member : public tag_net_message
{
	NET_SIC_guild_refresh_member()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_refresh_member");
		dw_size = sizeof(NET_SIC_guild_refresh_member);
	}
	DWORD		dw_role_id;
};

struct NET_SIS_guild_refresh_member : public tag_net_message
{
	NET_SIS_guild_refresh_member()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_refresh_member");
		dw_size = sizeof(NET_SIS_guild_refresh_member);
	}
	tagGuildMemInfo		sGuildMemInfo;
	tagGuildMemInfoEx	sGuildMemInfoEx;
};


//------------------------------------------------------------------------------
// ���ɳ�Ա���ױ��
//------------------------------------------------------------------------------
struct NET_SIS_guild_contribution : public tag_net_message
{
	NET_SIS_guild_contribution()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_contribution");
		dw_size = sizeof(NET_SIS_guild_contribution);
	}
	DWORD		dw_role_id;
	INT32		nContribution;
	INT32		nTotalContribution;
};


//------------------------------------------------------------------------------
// ���ɳ�Ա��ѫ���
//------------------------------------------------------------------------------
struct NET_SIS_guild_exploit : public tag_net_message
{
	NET_SIS_guild_exploit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_exploit");
		dw_size = sizeof(NET_SIS_guild_exploit);
	}
	DWORD		dw_role_id;
	INT32		nExploit;
};

//------------------------------------------------------------------------------
// ��ȡ��������
//------------------------------------------------------------------------------
struct NET_SIC_get_guild_name : public tag_net_message
{
	NET_SIC_get_guild_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_name");
		dw_size = sizeof(NET_SIC_get_guild_name);
	}
	DWORD		dwGuildID;
};

struct NET_SIS_get_guild_name : public tag_net_message
{
	NET_SIS_get_guild_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_name");
		dw_size = sizeof(NET_SIS_get_guild_name);
	}
	DWORD		dwGuildID;
	TCHAR		szGuildName[1];
};


//-----------------------------------------------------------------------------
// ��ȡ������ּ��ֻ�û�ȡ�Լ����ɵģ�
//-----------------------------------------------------------------------------
struct NET_SIC_get_guild_tenet : public tag_net_message
{
	NET_SIC_get_guild_tenet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_tenet");
		dw_size = sizeof(NET_SIC_get_guild_tenet);
	}
};

struct NET_SIS_get_guild_tenet : public tag_net_message
{
	NET_SIS_get_guild_tenet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_tenet");
		dw_size = sizeof(NET_SIS_get_guild_tenet);
	}
	TCHAR		szGuildTenet[1];
};


//-----------------------------------------------------------------------------
// ��ȡ�����Ƹ����
//-----------------------------------------------------------------------------
struct NET_SIC_get_guild_symbol : public tag_net_message
{
	NET_SIC_get_guild_symbol()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_symbol");
		dw_size = sizeof(NET_SIC_get_guild_symbol);
	}
	DWORD	dwGuildID;
};

struct NET_SIS_get_guild_symbol : public tag_net_message
{
	NET_SIS_get_guild_symbol()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_symbol");
		dw_size = sizeof(NET_SIS_get_guild_symbol);
	}
	DWORD		dwGuildID;
	TCHAR		bySymbol[1];
};


//-----------------------------------------------------------------------------
// �޸ļ���ְλ����
//-----------------------------------------------------------------------------
struct NET_SIC_guild_position_name_change : public tag_net_message
{
	NET_SIC_guild_position_name_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_position_name_change");
		dw_size = sizeof(NET_SIC_guild_position_name_change);
	}
	TCHAR    szPosName[X_GUILD_POS_NUM][MAX_GUILD_POS_NAME_LEN];
};

struct NET_SIS_guild_position_name_change : public tag_net_message
{
	NET_SIS_guild_position_name_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_position_name_change");
		dw_size = sizeof(NET_SIS_guild_position_name_change);
	}
	DWORD	 dwGuildID;
	TCHAR    szPosName[X_GUILD_POS_NUM][MAX_GUILD_POS_NAME_LEN];
};


//-----------------------------------------------------------------------------
//�޸ļ���ְλȨ��
//-----------------------------------------------------------------------------
struct NET_SIC_guild_position_power_change : public tag_net_message
{
	NET_SIC_guild_position_power_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_position_power_change");
		dw_size = sizeof(NET_SIC_guild_position_power_change);
	}
	DWORD    dwPosPower[X_GUILD_POS_NUM];
};

struct NET_SIS_guild_position_power_change_broad : public tag_net_message
{
	NET_SIS_guild_position_power_change_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_position_power_change_broad");
		dw_size = sizeof(NET_SIS_guild_position_power_change_broad);
	}
	DWORD	 dwGuildID;
	DWORD    dwPosPower[X_GUILD_POS_NUM];
};


//-----------------------------------------------------------------------------
//�������ͼ
//-----------------------------------------------------------------------------
struct NET_SIC_enter_guild_map : public tag_net_message
{
	NET_SIC_enter_guild_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_enter_guild_map");
		dw_size = sizeof(NET_SIC_enter_guild_map);
	}
	DWORD dwNPCID;
	INT64 n64_ItemSerial;
	DWORD dwParam;			// 0 ���뱾��ḱ�� 1 ����ж԰�ḱ��
};


//-----------------------------------------------------------------------------
//��ȡDKP���� 
//-----------------------------------------------------------------------------
struct NET_SIC_get_dkp : public tag_net_message
{
	NET_SIC_get_dkp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_dkp");
		dw_size = sizeof(NET_SIC_get_dkp);
	}
};	

struct NET_SIS_get_dkp : public tag_net_message
{
	NET_SIS_get_dkp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_dkp");
		dw_size = sizeof(NET_SIS_get_dkp);
	}
	INT16	n16DKP[EDKP_END];
};

//-----------------------------------------------------------------------------
//����DKP���� 
//-----------------------------------------------------------------------------
struct NET_SIC_set_dkp : public tag_net_message
{
	NET_SIC_set_dkp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_dkp");
		dw_size = sizeof(NET_SIC_set_dkp);
	}
	INT16	n16DKP[EDKP_END];
};

struct NET_SIS_set_dkp : public tag_net_message
{
	NET_SIS_set_dkp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_dkp");
		dw_size = sizeof(NET_SIS_set_dkp);
	}
	DWORD	dwError;
};


//-----------------------------------------------------------------------------
//DKPȷ��
//-----------------------------------------------------------------------------
struct NET_SIC_dkp_affirmance : public tag_net_message
{
	NET_SIC_dkp_affirmance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_dkp_affirmance");
		dw_size = sizeof(NET_SIC_dkp_affirmance);
	}
	INT16	n16DKP;
};

struct NET_SIS_dkp_affirmance : public tag_net_message
{
	NET_SIS_dkp_affirmance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_dkp_affirmance");
		dw_size = sizeof(NET_SIS_dkp_affirmance);
	}
	DWORD dwError;
};

//-----------------------------------------------------------------------------
//���õж԰��
//-----------------------------------------------------------------------------
struct NET_SIC_set_enemy_guild : public tag_net_message
{
	NET_SIC_set_enemy_guild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_enemy_guild");
		dw_size = sizeof(NET_SIC_set_enemy_guild);
	}
	DWORD dwEnemyGuildID;
};

struct NET_SIS_set_enemy_guild : public tag_net_message
{
	NET_SIS_set_enemy_guild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_enemy_guild");
		dw_size = sizeof(NET_SIS_set_enemy_guild);
	}
	DWORD dwError;
};

struct NET_SIS_view_enemy : public tag_net_message
{
	NET_SIS_view_enemy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_view_enemy");
		dw_size = sizeof(NET_SIS_view_enemy);
	}
	DWORD dwGuildID;
	DWORD dwGuildEnemyID;
};

struct NET_SIS_add_enemy_guild : public tag_net_message
{
	NET_SIS_add_enemy_guild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_enemy_guild");
		dw_size = sizeof(NET_SIS_add_enemy_guild);
	}
	DWORD dwGuildEnemyID;
	BOOL  bAdd;
};


//-----------------------------------------------------------------------------
//����ͬ��
//-----------------------------------------------------------------------------
struct NET_SIC_invite_league : public tag_net_message
{
	NET_SIC_invite_league()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_invite_league");
		dw_size = sizeof(NET_SIC_invite_league);
	}
	DWORD  dwLeagueGuildID;
};

struct NET_SIS_invite_league : public tag_net_message
{
	NET_SIS_invite_league()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_league");
		dw_size = sizeof(NET_SIS_invite_league);
	}
	DWORD dwError;
};

struct NET_SIS_send_invite_league : public tag_net_message
{
	NET_SIS_send_invite_league()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_invite_league");
		dw_size = sizeof(NET_SIS_send_invite_league);
	}
	DWORD dwInviteGuildID;
};


//-----------------------------------------------------------------------------
//����ͬ�˻ظ�
//-----------------------------------------------------------------------------
struct NET_SIC_invite_league_result : public tag_net_message
{
	NET_SIC_invite_league_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_invite_league_result");
		dw_size = sizeof(NET_SIC_invite_league_result);
	}
	DWORD	dwInviteGuildID;
	BOOL	bAgree; 
};

struct NET_SIS_invite_league_result : public tag_net_message
{
	NET_SIS_invite_league_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_league_result");
		dw_size = sizeof(NET_SIS_invite_league_result);
	}
	DWORD dwError;
};

struct NET_SIS_send_invite_league_result : public tag_net_message
{
	NET_SIS_send_invite_league_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_invite_league_result");
		dw_size = sizeof(NET_SIS_send_invite_league_result);
	}
	DWORD	dwInviteGuildID;
	DWORD	dwResGuildID;
	BOOL	bAgree; 
};

//-----------------------------------------------------------------------------
//���ͬ��
//-----------------------------------------------------------------------------
struct NET_SIC_relieve_league : public tag_net_message
{
	NET_SIC_relieve_league()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_relieve_league");
		dw_size = sizeof(NET_SIC_relieve_league);
	}
	DWORD dwGuildID;
};

struct NET_SIS_relieve_league : public tag_net_message
{
	NET_SIS_relieve_league()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_relieve_league");
		dw_size = sizeof(NET_SIS_relieve_league);
	}
	DWORD dwError;
};

struct NET_SIS_send_relieve_league : public tag_net_message
{
	NET_SIS_send_relieve_league()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_relieve_league");
		dw_size = sizeof(NET_SIS_send_relieve_league);
	}
	DWORD dwRelieveID;
	DWORD dwBeRelieveID;
};

//-----------------------------------------------------------------------------
//ɾ���ж԰��
//-----------------------------------------------------------------------------
struct NET_SIC_delete_enemy_guild : public tag_net_message
{
	NET_SIC_delete_enemy_guild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_enemy_guild");
		dw_size = sizeof(NET_SIC_delete_enemy_guild);
	}
	DWORD dwEnemyGuildID;
};

struct NET_SIS_delete_enemy_guild : public tag_net_message
{
	NET_SIS_delete_enemy_guild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_enemy_guild");
		dw_size = sizeof(NET_SIS_delete_enemy_guild);
	}
	DWORD dwError;
};

struct NET_SIS_unview_enemy : public tag_net_message
{
	NET_SIS_unview_enemy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_unview_enemy");
		dw_size = sizeof(NET_SIS_unview_enemy);
	}
	DWORD dwGuildID;
	DWORD dwGuildEnemyID;
};


//-----------------------------------------------------------------------------
//��ȡ�ж�����
//-----------------------------------------------------------------------------
struct NET_SIC_get_enemy_data : public tag_net_message
{
	NET_SIC_get_enemy_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_enemy_data");
		dw_size = sizeof(NET_SIC_get_enemy_data);
	}
};

struct NET_SIS_get_enemy_data : public tag_net_message
{
	NET_SIS_get_enemy_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_enemy_data");
		dw_size = sizeof(NET_SIS_get_enemy_data);
	}
	DWORD				dwDeclareGuildID;		// ��ս���ID
	DWORD				dwBeDeclareGuildID;		// ��ս���ID;
	DWORD				dwWarGuildID;			// ս����ID
	tagDWORDTime		dwDeclareBeginTime;		// ��ս��ʼʱ��
	tagDWORDTime		dwPrepareBeginTime;		// ս��׼��ʱ��
	tagDWORDTime		dwWarBeginTime;			// ս����ʼʱ��
	tagDWORDTime		dwCurrTime;				// ��������ǰʱ��
	EGuildWarState		eGuildWarState;			// ��ǰ���ս״̬
	INT					n_num;
	tagGuildEnemyData	st_EnemyData[1];		// �ж԰������
};


//-----------------------------------------------------------------------------
//�����ս
//-----------------------------------------------------------------------------
struct NET_SIC_guild_declare_war : public tag_net_message
{
	NET_SIC_guild_declare_war()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_declare_war");
		dw_size = sizeof(NET_SIC_guild_declare_war);
	}
	DWORD dwGuildID;
};

struct NET_SIS_guild_declare_war : public tag_net_message
{
	NET_SIS_guild_declare_war()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_declare_war");
		dw_size = sizeof(NET_SIS_guild_declare_war);
	}
	DWORD dwError;
};

// ����ս
struct NET_SIS_guild_bedeclare_war : public tag_net_message
{
	NET_SIS_guild_bedeclare_war()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_bedeclare_war");
		dw_size = sizeof(NET_SIS_guild_bedeclare_war);
	}

	DWORD dwGuildID;
	BYTE dwLevel;
	TCHAR szGuildName[X_SHORT_NAME];
	TCHAR szLeaderName[X_SHORT_NAME];
};
//-----------------------------------------------------------------------------
//�����ս�ظ�
//-----------------------------------------------------------------------------
struct NET_SIC_guild_declare_war_result : public tag_net_message
{
	NET_SIC_guild_declare_war_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_declare_war_result");
		dw_size = sizeof(NET_SIC_guild_declare_war_result);
	}
	DWORD dwGuildID;
	BOOL  bAccept;
};

struct NET_SIS_guild_declare_war_result : public tag_net_message
{
	NET_SIS_guild_declare_war_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_declare_war_result");
		dw_size = sizeof(NET_SIS_guild_declare_war_result);
	}
	DWORD dwError;
};

// �޸Ĳ�ս����
struct NET_SIC_guild_war_num : public tag_net_message
{
	NET_SIC_guild_war_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_war_num");
		dw_size = sizeof(NET_SIC_guild_war_num);
	}
	DWORD dwNum;
};

struct NET_SIS_guild_war_num : public tag_net_message
{
	NET_SIS_guild_war_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_num");
		dw_size = sizeof(NET_SIS_guild_war_num);
	}
	DWORD dw_error_code;
};

struct NET_SIS_guild_war_maxnum_change : public tag_net_message
{
	NET_SIS_guild_war_maxnum_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_maxnum_change");
		dw_size = sizeof(NET_SIS_guild_war_maxnum_change);
	}
	DWORD dwNumber;
};

// �޸ķ�������
struct NET_SIC_guild_war_money_param : public tag_net_message
{
	NET_SIC_guild_war_money_param()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_war_money_param");
		dw_size = sizeof(NET_SIC_guild_war_money_param);
	}
	double fParam;
};

struct NET_SIS_guild_war_money_param : public tag_net_message
{
	NET_SIS_guild_war_money_param()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_money_param");
		dw_size = sizeof(NET_SIS_guild_war_money_param);
	}
	DWORD dw_error_code;
};

struct NET_SIS_guild_war_money_param_change : public tag_net_message
{
	NET_SIS_guild_war_money_param_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_money_param_change");
		dw_size = sizeof(NET_SIS_guild_war_money_param_change);
	}
	double fParam;
};

//-----------------------------------------------------------------------------
//���ܾ���սȫ���㲥
//-----------------------------------------------------------------------------
struct NET_SIS_refuse_declare_broad : public tag_net_message
{
	NET_SIS_refuse_declare_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_refuse_declare_broad");
		dw_size = sizeof(NET_SIS_refuse_declare_broad);
	}
	DWORD dwDeclareGuildID;
	DWORD dwRefuseGuildID;
	TCHAR	szDeclareGuildName[X_SHORT_NAME];
	TCHAR	szRefuseGuildName[X_SHORT_NAME];
};

//-----------------------------------------------------------------------------
//���սʱ����ʾ
//-----------------------------------------------------------------------------
struct NET_SIS_guild_war_broad : public tag_net_message
{
	NET_SIS_guild_war_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_broad");
		dw_size = sizeof(NET_SIS_guild_war_broad);
	}
	DWORD	dwGuildID;
	DWORD   dwEnemyGuildID;
	EGuildWarState eGuildWarState;
	byte	byTime;		//3:45���� 2: 30���� 1:15����
};


//-----------------------------------------------------------------------------
//���ս�������
//-----------------------------------------------------------------------------
struct NET_SIS_guild_war_outcome_broad : public tag_net_message
{
	NET_SIS_guild_war_outcome_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_outcome_broad");
		dw_size = sizeof(NET_SIS_guild_war_outcome_broad);
	}
	DWORD	dwWinGuild;			
	DWORD	dwAbortGuild;
	BOOL	bEqual;				// �Ƿ�ƽ��
	BOOL	bTripodLost;		// ��¯�Ƿ�����
	BOOL	bDefenter;	
	DWORD	dwDaogao;			// ����������
	INT32	nFund;				// ����ʽ�
	TCHAR	szWinGuildName[X_SHORT_NAME];
	TCHAR	szAbortGuildName[X_SHORT_NAME];
};

//-----------------------------------------------------------------------------
//������ս�ʸ�
//-----------------------------------------------------------------------------
struct NET_SIC_guild_war_qualify : public tag_net_message
{
	NET_SIC_guild_war_qualify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_war_qualify");
		dw_size = sizeof(NET_SIC_guild_war_qualify);
	}

	BOOL	bJoin;		// 0.�뿪 1,����
};

struct NET_SIS_guild_war_qualify : public tag_net_message
{
	NET_SIS_guild_war_qualify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_qualify");
		dw_size = sizeof(NET_SIS_guild_war_qualify);
	}

	DWORD		dw_error_code;
};

//-----------------------------------------------------------------------------
//ȡ����Ա���ս�ʸ�
//-----------------------------------------------------------------------------
struct NET_SIC_guild_war_dis_qualify : public tag_net_message
{
	NET_SIC_guild_war_dis_qualify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_war_dis_qualify");
		dw_size = sizeof(NET_SIC_guild_war_dis_qualify);
	}
	DWORD		dw_role_id;
};

struct NET_SIS_guild_war_dis_qualify : public tag_net_message
{
	NET_SIS_guild_war_dis_qualify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_dis_qualify");
		dw_size = sizeof(NET_SIS_guild_war_dis_qualify);
	}
	DWORD		dw_error_code;
};

// ���ս��Ա�б��仯
struct NET_SIS_guild_war_member_change : public tag_net_message
{
	NET_SIS_guild_war_member_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_member_change");
		dw_size = sizeof(NET_SIS_guild_war_member_change);
	}
	DWORD		dw_role_id;
	BOOL		m_bAdd;	   // false �뿪 true ����
};

//-----------------------------------------------------------------------------
// ��ȡ���ɲֿ���Ʒ��Ϣ
//-----------------------------------------------------------------------------
struct NET_SIC_get_guild_ware : public tag_net_message
{
	NET_SIC_get_guild_ware()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_ware");
		dw_size = sizeof(NET_SIC_get_guild_ware);
	}
	DWORD		dwNPCID;
	DWORD		dwLastUpdateTime;
};

struct NET_SIS_get_guild_ware : public tag_net_message
{
	NET_SIS_get_guild_ware()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_ware");
		dw_size = sizeof(NET_SIS_get_guild_ware);
	}
	DWORD		dw_error_code;
	DWORD		dwLastUpdateTime;
	INT16		nSzGuildWare;
	INT			nItemNum;
	BYTE		byData[1];
};

//-----------------------------------------------------------------------------
// ��ȡ�������ɲֿ�Ȩ���б�
//-----------------------------------------------------------------------------
struct NET_SIC_get_guild_ware_power_list : public tag_net_message
{
	NET_SIC_get_guild_ware_power_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_ware_power_list");
		dw_size = sizeof(NET_SIC_get_guild_ware_power_list);
	}
	DWORD		dwNPCID;
};

struct NET_SIS_get_guild_ware_power_list : public tag_net_message
{
	NET_SIS_get_guild_ware_power_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_ware_power_list");
		dw_size = sizeof(NET_SIS_get_guild_ware_power_list);
	}
	INT32			n_num;				// �б�������
	tagGuildWarePri	sGuildWarePri[1];	// Ȩ����Ϣ
};


//-----------------------------------------------------------------------------
// ����������ɲֿ�Ȩ��
//-----------------------------------------------------------------------------
struct NET_SIC_change_guild_ware_power : public tag_net_message
{
	NET_SIC_change_guild_ware_power()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_change_guild_ware_power");
		dw_size = sizeof(NET_SIC_change_guild_ware_power);
	}
	DWORD		dwNPCID;
	DWORD		dw_role_id;
	BOOL		bCanUse;
};

struct NET_SIS_change_guild_ware_power : public tag_net_message
{
	NET_SIS_change_guild_ware_power()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_guild_ware_power");
		dw_size = sizeof(NET_SIS_change_guild_ware_power);
	}
	DWORD		dw_role_id;
	BOOL		bCanUse;
};


//-----------------------------------------------------------------------------
// ����״̬�ı�
//-----------------------------------------------------------------------------
struct NET_SIS_guild_set_state : public tag_net_message
{
	NET_SIS_guild_set_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_set_state");
		dw_size = sizeof(NET_SIS_guild_set_state);
	}
	EGuildSpecState	eState;
};

struct NET_SIS_guild_unset_state : public tag_net_message
{
	NET_SIS_guild_unset_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_unset_state");
		dw_size = sizeof(NET_SIS_guild_unset_state);
	}
	EGuildSpecState	eState;
};

//-----------------------------------------------------------------------------
// ��ȡ������ʩ������Ϣ
//-----------------------------------------------------------------------------
struct NET_SIC_get_guild_upgreae_info : public tag_net_message
{
	NET_SIC_get_guild_upgreae_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_upgreae_info");
		dw_size = sizeof(NET_SIC_get_guild_upgreae_info);
	}
	//DWORD					dwNPCID;
	EFacilitiesType			eFacType;
};

// ��ȡ���а�����ʩ��Ϣ
struct NET_SIS_get_guild_upgreade_info : public tag_net_message
{
	NET_SIS_get_guild_upgreade_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_upgreade_info");
		dw_size = sizeof(NET_SIS_get_guild_upgreade_info);
	}
	tagGuildFacilitiesInfo	sFacilitiesInfo[MAX_GUILD_FACILITIES_TYPE];
};

// ����ĳһ��������ʩ��Ϣ
struct NET_SIS_update_facilities_info : public tag_net_message
{
	NET_SIS_update_facilities_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_facilities_info");
		dw_size = sizeof(NET_SIS_update_facilities_info);
	}
	tagGuildFacilitiesInfo	sFacilitiesInfo;
};


//-----------------------------------------------------------------------------
// �Ͻɰ�����ʩ����������Ʒ
//-----------------------------------------------------------------------------
struct NET_SIC_turn_in_item : public tag_net_message
{
	NET_SIC_turn_in_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_turn_in_item");
		dw_size = sizeof(NET_SIC_turn_in_item);
	}
	DWORD					dwNPCID;
	EFacilitiesType			eType;
};


//-----------------------------------------------------------------------------
// ������ʩ����
//-----------------------------------------------------------------------------
struct NET_SIC_upgrede_level : public tag_net_message
{
	NET_SIC_upgrede_level()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_upgrede_level");
		dw_size = sizeof(NET_SIC_upgrede_level);
	}
	EFacilitiesType			eType;
};


//-----------------------------------------------------------------------------
// �㲥��ʩ������Ϣ
//-----------------------------------------------------------------------------
struct NET_SIS_guild_upgrade : public tag_net_message
{
	NET_SIS_guild_upgrade()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_upgrade");
		dw_size = sizeof(NET_SIS_guild_upgrade);
	}
	EFacilitiesType			eType;
	BYTE					byNewLevel;
};


//-----------------------------------------------------------------------------
// �������񷢲���Ϣ
//-----------------------------------------------------------------------------
struct NET_SIC_issuance_guild_affair : public tag_net_message
{
	NET_SIC_issuance_guild_affair()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_issuance_guild_affair");
		dw_size = sizeof(NET_SIC_issuance_guild_affair);
	}
	DWORD					dwBuffID;
};

struct NET_SIS_issuance_guild_affair : public tag_net_message
{
	NET_SIS_issuance_guild_affair()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_issuance_guild_affair");
		dw_size = sizeof(NET_SIS_issuance_guild_affair);
	}
	DWORD					dwRole;			// ������
	DWORD					dwBuffID;
	BYTE					byRemainTimes;	// ÿ��ʣ�෢������
};


//-----------------------------------------------------------------------------
// ���ɼ�����Ϣ
//-----------------------------------------------------------------------------
struct NET_SIC_get_guild_skill_info : public tag_net_message
{
	NET_SIC_get_guild_skill_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_skill_info");
		dw_size = sizeof(NET_SIC_get_guild_skill_info);
	}
};

struct NET_SIS_get_guild_skill_info : public tag_net_message
{
	NET_SIS_get_guild_skill_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_skill_info");
		dw_size = sizeof(NET_SIS_get_guild_skill_info);
	}
	DWORD			dwCurSkillID;		// ��ǰ�о�����
	INT16			n16Progress;		// ��ǰ�о�����
	INT				nSkillNum;			// ���ɼ�������
	DWORD			dwSkillInfo[1];		// ���ɼ��ܵȼ�
};

struct NET_SIC_guild_skill_upgrade : public tag_net_message
{
	NET_SIC_guild_skill_upgrade()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_skill_upgrade");
		dw_size = sizeof(NET_SIC_guild_skill_upgrade);
	}
	INT64			n64ItemSerial;		// �Ͻɵ伮64λID
};

// ��ǰ�о������Ƿ����ͨ��NET_SIS_set_research_skill����
struct NET_SIS_guild_skill_upgrade : public tag_net_message
{
	NET_SIS_guild_skill_upgrade()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_skill_upgrade");
		dw_size = sizeof(NET_SIS_guild_skill_upgrade);
	}
	DWORD			dwSkillID;			// ��������ID
	INT16			n16Progress;		// ��������
};

struct NET_SIS_guild_skill_level_up : public tag_net_message
{
	NET_SIS_guild_skill_level_up()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_skill_level_up");
		dw_size = sizeof(NET_SIS_guild_skill_level_up);
	}
	DWORD			dwSkillID;
};

struct NET_SIC_learn_guild_skill : public tag_net_message
{
	NET_SIC_learn_guild_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_learn_guild_skill");
		dw_size = sizeof(NET_SIC_learn_guild_skill);
	}
	DWORD			dwSkillID;			// ��ѧ��������ID
};

struct NET_SIS_learn_guild_skill : public tag_net_message
{
	NET_SIS_learn_guild_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_learn_guild_skill");
		dw_size = sizeof(NET_SIS_learn_guild_skill);
	}
	DWORD			dw_error_code;		// �����뼼�ܴ�����ö���ص�,�������ô���Ϣ
	DWORD			dwSkillID;			// ѧϰ���ܵ�ID
};

struct NET_SIC_research_skill : public tag_net_message
{
	NET_SIC_research_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_research_skill");
		dw_size = sizeof(NET_SIC_research_skill);
	}
	DWORD			dwSkillID;			// ���õ�ǰ�о�����,ȡ���о�ΪINVALID_VALUE
};

struct NET_SIS_set_research_skill : public tag_net_message
{
	NET_SIS_set_research_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_research_skill");
		dw_size = sizeof(NET_SIS_set_research_skill);
	}
	DWORD			dwSkillID;			// ���ص�ǰ�о�����ID
	INT16			n16Progress;		// ��������
};


//-----------------------------------------------------------------------------
// �����������
//-----------------------------------------------------------------------------
// ��ȡ����̻���Ϣ
struct NET_SIC_get_commodity_info : public tag_net_message
{
	NET_SIC_get_commodity_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_commodity_info");
		dw_size = sizeof(NET_SIC_get_commodity_info);
	}
};

struct NET_SIS_get_commodity_info : public tag_net_message
{
	NET_SIS_get_commodity_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_commodity_info");
		dw_size = sizeof(NET_SIS_get_commodity_info);
	}
	INT32				nCurTael;		// ��ǰ��������
	INT					nLevel;			// ��ȡ����ʱ�ĵȼ�
	INT					nGoodNum;		// �̻�����
	tagCommerceGoodInfo	sGoodInfo[1];	// �̻���Ϣ
};

// ��ȡ���̳�ʼ��Ϣ
struct NET_SIC_get_tael_info : public tag_net_message
{
	NET_SIC_get_tael_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_tael_info");
		dw_size = sizeof(NET_SIC_get_tael_info);
	}
};

struct NET_SIS_get_tael_info : public tag_net_message
{
	NET_SIS_get_tael_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_tael_info");
		dw_size = sizeof(NET_SIS_get_tael_info);
	}
	INT				nLevel;				// ��ȡʱ��ҵȼ�
};

// ��ȡ��������
struct NET_SIC_get_commerce_rank : public tag_net_message
{
	NET_SIC_get_commerce_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_commerce_rank");
		dw_size = sizeof(NET_SIC_get_commerce_rank);
	}
};

struct NET_SIS_get_commerce_rank : public tag_net_message
{
	NET_SIS_get_commerce_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_commerce_rank");
		dw_size = sizeof(NET_SIS_get_commerce_rank);
	}
	BOOL			bCommend;			// �ν�״̬
	INT				nRankNum;			// �ϰ�����
	tagCommerceRank	sRankInfo[1];		// ������Ϣ
};

// ��������
struct NET_SIC_accept_commerce : public tag_net_message
{
	NET_SIC_accept_commerce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_accept_commerce");
		dw_size = sizeof(NET_SIC_accept_commerce);
	}
};

struct NET_SIS_accept_commerce : public tag_net_message
{
	NET_SIS_accept_commerce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_accept_commerce");
		dw_size = sizeof(NET_SIS_accept_commerce);
	}
	INT32			nBeginningTael;		// ��ʼ����
};

// �Ͻ�����
struct NET_SIC_complete_commerce : public tag_net_message
{
	NET_SIC_complete_commerce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_complete_commerce");
		dw_size = sizeof(NET_SIC_complete_commerce);
	}
};

// �Ͻɳɹ�
struct NET_SIS_complete_commerce : public tag_net_message
{
	NET_SIS_complete_commerce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_complete_commerce");
		dw_size = sizeof(NET_SIS_complete_commerce);
	}
	DWORD			dw_role_id;			// �Ͻ���
	INT32			nFund;				// �����ʽ�
};

// ��������
struct NET_SIC_abandon_commerce : public tag_net_message
{
	NET_SIC_abandon_commerce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_abandon_commerce");
		dw_size = sizeof(NET_SIC_abandon_commerce);
	}
};

// �ɹ�����
struct NET_SIS_abandon_commerce : public tag_net_message
{
	NET_SIS_abandon_commerce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_abandon_commerce");
		dw_size = sizeof(NET_SIS_abandon_commerce);
	}
};

// �������̼ν�
struct NET_SIC_switch_commendation : public tag_net_message
{
	NET_SIC_switch_commendation()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_switch_commendation");
		dw_size = sizeof(NET_SIC_switch_commendation);
	}
	BOOL			bSwitchON;
};

// �㲥�ν�״̬
struct NET_SIS_switch_commendation : public tag_net_message
{
	NET_SIS_switch_commendation()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_switch_commendation");
		dw_size = sizeof(NET_SIS_switch_commendation);
	}
	DWORD			dw_role_id;			// ������
	BOOL			bSwitchON;			// �ν�״̬
};


//-----------------------------------------------------------------------------
// �����̻�
//-----------------------------------------------------------------------------
// ��ȡ�̻��̻���Ϣ
struct NET_SIC_get_chamber_goods_info : public tag_net_message
{
	NET_SIC_get_chamber_goods_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_chamber_goods_info");
		dw_size = sizeof(NET_SIC_get_chamber_goods_info);
	}
	DWORD				dwNPCID;		// �̻�ID
};

struct NET_SIS_get_chamber_goods_info : public tag_net_message
{
	NET_SIS_get_chamber_goods_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_chamber_goods_info");
		dw_size = sizeof(NET_SIS_get_chamber_goods_info);
	}
	DWORD				dwCofCID;		// �̻�ID
	BYTE				byHoldCity;		// �ز��̻�(0��ʾһ���̻�)
	INT					nGoodNum;		// �����̻�����
	tagCommerceGoodInfo	sGoodInfo[1];	// �̻���Ϣ
};

// �ر��̻�
struct NET_SIC_colse_chamber : public tag_net_message
{
	NET_SIC_colse_chamber()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_colse_chamber");
		dw_size = sizeof(NET_SIC_colse_chamber);
	}
	DWORD				dwNPCID;		// �̻�NPCID
};

struct NET_SIC_buy_chamber_goods : public tag_net_message
{
	NET_SIC_buy_chamber_goods()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_buy_chamber_goods");
		dw_size = sizeof(NET_SIC_buy_chamber_goods);
	}
	DWORD			dwNPCID;			// �̻�NPCID
	DWORD			dwGoodID;			// �̻�ID
	BYTE			byBuyNum;			// ��������
};

struct NET_SIC_sell_chamber_goods : public tag_net_message
{
	NET_SIC_sell_chamber_goods()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_sell_chamber_goods");
		dw_size = sizeof(NET_SIC_sell_chamber_goods);
	}
	DWORD			dwNPCID;
	DWORD			dwGoodID;
	BYTE			bySellNum;
};


//-----------------------------------------------------------------------------
// ֪ͨ�뿪����ͼ
//-----------------------------------------------------------------------------
struct NET_SIS_inform_leave_guild_map : public tag_net_message
{
	NET_SIS_inform_leave_guild_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_inform_leave_guild_map");
		dw_size = sizeof(NET_SIS_inform_leave_guild_map);
	}
	BYTE	byType;			// 1.���� 2.ս��׼�� 3.ս������ 4.��ή�� 5.��ս����
};

//------------------------------------------------------------------------------

// ��������ļ��
struct NET_SIC_join_guild_recruit : public tag_net_message
{
	NET_SIC_join_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_join_guild_recruit");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	DWORD	dw_guild_id;
};

struct NET_SIS_join_guild_recruit : public tag_net_message
{
	NET_SIS_join_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_join_guild_recruit");
		dw_size = sizeof(*this);
	}
	DWORD	dw_guild_id;
	DWORD dw_error;
};

// �뿪�����ļ��
struct NET_SIC_leave_guild_recruit : public tag_net_message
{
	NET_SIC_leave_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_guild_recruit");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
};

struct NET_SIS_leave_guild_recruit : public tag_net_message
{
	NET_SIS_leave_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_leave_guild_recruit");
		dw_size = sizeof(*this);
	}
	DWORD dw_error;
};

// ��ѯ�����ļ����Ϣ
struct NET_SIC_query_guild_recruit : public tag_net_message
{
	NET_SIC_query_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_query_guild_recruit");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_query_guild_recruit : public tag_net_message
{
	NET_SIS_query_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_query_guild_recruit");
		dw_size = sizeof(*this);
	}
	//BOOL b_register;
	//INT	n_page;
	INT n_num;
	tag_guild_recrguit_info p_data[1];
};

// ��ѯĳҳ�����ļ����Ϣ
struct NET_SIC_query_page_guild_recruit : public tag_net_message
{
	NET_SIC_query_page_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_query_page_guild_recruit");
		dw_size = sizeof(*this);
	}
	INT n_page;
};

//��ɫ�������㲥
struct NET_SIS_Role_Dead_broad : public tag_net_message
{
	NET_SIS_Role_Dead_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Role_Dead_broad");
		dw_size = sizeof(*this);
	}
	DWORD	dw_kill_id;
	DWORD	dw_dead_id;
};

// �����������
struct NET_SIC_Start_Guild_Practice : public tag_net_message
{
	NET_SIC_Start_Guild_Practice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Start_Guild_Practice");
		dw_size = sizeof(*this);
	}

	DWORD		dw_npc_id;
};

struct NET_SIS_Start_Guild_Practice : public tag_net_message
{
	NET_SIS_Start_Guild_Practice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Start_Guild_Practice");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

struct NET_SIS_Guild_Practice_Broad : public tag_net_message
{
	NET_SIS_Guild_Practice_Broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_Practice_Broad");
		dw_size = sizeof(*this);
	}

	BOOL	b_Start;		// TRUE ���� FALSE �ر�
};

// ��ȡ���ռ�춦��Ϣ
struct NET_SIC_Guild_Tripod_Info : public tag_net_message
{
	NET_SIC_Guild_Tripod_Info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Guild_Tripod_Info");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_Guild_Tripod_Info : public tag_net_message
{
	NET_SIS_Guild_Tripod_Info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_Tripod_Info");
		dw_size = sizeof(*this);
	}

	DWORD	dw_tripod_id;
	DWORD	dw_map_id;
};

// ��ȡ����ʽ�Ͱ����Ƿ�����
struct NET_SIC_Get_Guild_Fund : public tag_net_message
{
	NET_SIC_Get_Guild_Fund()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Get_Guild_Fund");
		dw_size = sizeof(*this);
	}

	DWORD	dw_guild_id;
};

// ��ȡ����ʽ�Ͱ����Ƿ�����
struct NET_SIS_Get_Guild_Fund : public tag_net_message
{
	NET_SIS_Get_Guild_Fund()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Get_Guild_Fund");
		dw_size = sizeof(*this);
	}

	DWORD	dw_error_code;
	DWORD	dw_guild_id;
	DWORD	dw_fund;
	BOOL	b_online;
	INT32	nOnlineNum;
	DWORD	dw_leader_id;
	BYTE	dw_guild_level;
};


// ��ȡ���ս��
struct NET_SIC_Guild_War_History : public tag_net_message
{
	NET_SIC_Guild_War_History()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Guild_War_History");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_Guild_War_History : public tag_net_message
{
	NET_SIS_Guild_War_History()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_War_History");
		dw_size = sizeof(*this);
	}	
	INT		n_num;
	tagGuildWarHistory st_guild_war_history[1];
};

// ���ս׼�����
struct NET_SIC_Guild_War_Relay : public tag_net_message
{
	NET_SIC_Guild_War_Relay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Guild_War_Relay");
		dw_size = sizeof(*this);
	}
};


struct NET_SIS_Guild_War_Relay : public tag_net_message
{
	NET_SIS_Guild_War_Relay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_War_Relay");
		dw_size = sizeof(*this);
	}
	DWORD dw_error_code;
	BOOL bEenemy;   // �Ƿ��ǶԷ�׼������
};


// �������ʽ�
struct NET_SIC_Guild_increase_fund : public tag_net_message
{
	NET_SIC_Guild_increase_fund()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Guild_increase_fund");
		dw_size = sizeof(*this);
	}
	INT32 nFund;
};

struct NET_SIS_Guild_increase_fund : public tag_net_message
{
	NET_SIS_Guild_increase_fund()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_increase_fund");
		dw_size = sizeof(*this);
	}
	INT32 nCurFund;
	DWORD dw_error_code;
};


// ��սʱ����˫������
struct NET_SIS_Guil_war_member_number_update : public tag_net_message
{
	NET_SIS_Guil_war_member_number_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guil_war_member_number_update");
		dw_size = sizeof(*this);
	}

	DWORD dw_number;
	DWORD dw_enemy_number;
};

// ���ս״̬�л�
struct NET_SIS_Guil_war_state_change : public tag_net_message
{
	NET_SIS_Guil_war_state_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guil_war_state_change");
		dw_size = sizeof(*this);
	}

	EGuildWarState eState;
	BOOL	bDefenter;
	BOOL	bUseMianzhan;
	TCHAR	szEnemyGuildName[X_SHORT_NAME]; // �ж԰���� ֻ�н��뱨��ʱ�ᷢ
};

// ͬ����Ѹ������
struct NET_SIS_War_Reborn_time : public tag_net_message
{
	NET_SIS_War_Reborn_time()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_War_Reborn_time");
		dw_size = sizeof(*this);
	}

	BYTE byTime;
};

// ռ�춦¯ȫ����Ϣ
struct NET_SIS_Guild_Tripod : public tag_net_message
{
	NET_SIS_Guild_Tripod()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_Tripod");
		dw_size = sizeof(*this);
	}
	TCHAR	szGuildName[X_SHORT_NAME]; 
};

// ���ϻ���
struct NET_SIC_Material_receive : public tag_net_message
{
	NET_SIC_Material_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Material_receive");
		dw_size = sizeof(*this);
	}

	DWORD	dw_item_id;
	INT		n_number;
};

struct NET_SIS_Material_receive : public tag_net_message
{
	NET_SIS_Material_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Material_receive");
		dw_size = sizeof(*this);
	}

	DWORD	dw_error_code;
};

// �ʽ����
struct NET_SIC_Guild_donate_fund : public tag_net_message
{
	NET_SIC_Guild_donate_fund()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Guild_donate_fund");
		dw_size = sizeof(*this);
	}
	BYTE byType; // 0:̴ľ�� 1:��ˮ�� 2:�����
};

struct NET_SIS_Guild_donate_fund : public tag_net_message
{
	NET_SIS_Guild_donate_fund()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_donate_fund");
		dw_size = sizeof(*this);
	}
	DWORD dw_error_code;
};

//-----------------------------------------------------------------------------
// ��ȡ���а����Ϣ
//-----------------------------------------------------------------------------
struct NET_SIC_get_all_guild_info : public tag_net_message
{
	NET_SIC_get_all_guild_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_all_guild_info");
		dw_size = sizeof(NET_SIC_get_all_guild_info);
	}

	BOOL	bSBKList;	//�Ƿ��ǹ����б�

};

struct NET_SIS_get_all_guild_info : public tag_net_message
{
	NET_SIS_get_all_guild_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_all_guild_info");
		dw_size = sizeof(NET_SIS_get_all_guild_info);
	}
	INT nNum;
	tagGuildWarInfo s_guildInfo[1];
};

// ʹ����ս��
struct NET_SIC_guild_mianzhan : public tag_net_message
{
	NET_SIC_guild_mianzhan()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_mianzhan");
		dw_size = sizeof(NET_SIC_guild_mianzhan);
	}
	INT64 n64ItemID;	//��ս��
};

struct NET_SIS_guild_mianzhan : public tag_net_message
{
	NET_SIS_guild_mianzhan()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_mianzhan");
		dw_size = sizeof(NET_SIS_guild_mianzhan);
	}
	DWORD dw_error_code;
};


// ͨ�ð����Ϣ
struct NET_SIS_Guild_msg : public tag_net_message
{
	NET_SIS_Guild_msg()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_msg");
		dw_size = sizeof(*this);
	}
	//TCHAR		szName[X_SHORT_NAME];
	//TCHAR		szTargetName[X_SHORT_NAME];
	INT32		nChangeValue;
	BYTE		byType;	// 1:�ʽ� 
};

struct NET_SIS_GuildMap_kill_role: public tag_net_message
{
	NET_SIS_GuildMap_kill_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_GuildMap_kill_role");
		dw_size = sizeof(*this);
	}

	DWORD dwKillerID;
	DWORD dwDeadID;
	DWORD dwMapID;
	float x;
	float z;

};

// �޸�����ȼ�
struct NET_SIC_Modify_ApplyLevel : public tag_net_message
{
	NET_SIC_Modify_ApplyLevel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Modify_ApplyLevel");
		dw_size = sizeof(*this);
	}

	int		nLevel;
};

struct NET_SIS_Modify_ApplyLevel : public tag_net_message
{
	NET_SIS_Modify_ApplyLevel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Modify_ApplyLevel");
		dw_size = sizeof(*this);
	}

	int		nLevel;
	DWORD	dwErrorCode;
};


// ͬ�����
struct NET_SIC_agree_join : public tag_net_message
{
	NET_SIC_agree_join()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_agree_join");
		dw_size = sizeof(*this);
	}

	DWORD	dwRoleID;
};

struct NET_SIS_agree_join : public tag_net_message
{
	NET_SIS_agree_join()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_agree_join");
		dw_size = sizeof(*this);
	}
	DWORD	dwRoleID;
	DWORD	dwErrorCode;
};

// �ܾ�����
struct NET_SIC_noagree_join : public tag_net_message
{
	NET_SIC_noagree_join()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_noagree_join");
		dw_size = sizeof(*this);
	}

	DWORD	dwRoleID;
};

struct NET_SIS_noagree_join : public tag_net_message
{
	NET_SIS_noagree_join()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_noagree_join");
		dw_size = sizeof(*this);
	}
	DWORD	dwRoleID;
	DWORD	dwErrorCode;
};

//�����μӹ���ս
struct NET_SIC_sign_up_attack : public tag_net_message
{
	NET_SIC_sign_up_attack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_sign_up_attack");
		dw_size = sizeof(*this);
	}

};

struct NET_SIS_sign_up_attack : public tag_net_message
{
	NET_SIS_sign_up_attack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_sign_up_attack");
		dw_size = sizeof(*this);
	}
	DWORD dw_error_code;
};


// ����ɳ�Ϳ�����
struct NET_SIC_get_SBK_data : public tag_net_message
{
	NET_SIC_get_SBK_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_SBK_data");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_SBK_data : public tag_net_message
{
	NET_SIS_get_SBK_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_SBK_data");
		dw_size = sizeof(*this);
	}

	tagGuildSBKData	s_sbk_data;
};

// ��ȡɳ�Ϳ˽���
struct NET_SIC_get_SBK_reward : public tag_net_message
{
	NET_SIC_get_SBK_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_SBK_reward");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_SBK_reward : public tag_net_message
{
	NET_SIS_get_SBK_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_SBK_reward");
		dw_size = sizeof(*this);
	}

	DWORD	dw_error_code;
};

#pragma pack(pop)
#endif