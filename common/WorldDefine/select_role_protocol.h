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
*	@file		select_role_protocol.h
*	@author		lc
*	@date		2011/03/11	initial
*	@version	0.0.1.0
*	@brief		ѡ����Ϣ
*/


#ifndef SELECT_ROLE_PROTOCOL
#define SELECT_ROLE_PROTOCOL

#pragma pack(push)
#pragma pack(1)

#include "protocol_common_errorcode.h"
#include "RoleDefine.h"
#define MAX_ROLE_NUM		3
enum										// ���ﴴ����ɾ����ѡ����صĴ������
{
	E_JoinGame_AccountOnline			=	1,
	E_JoinGame_VerifyCodeError			=	2,

	E_CreateRole_RoleCreating			=	11,
	E_CreateRole_RoleEnumNotDone		=	12,
	E_CreateRole_RoleDeleting			=	13,
	E_CreateRole_RoleNumFull			=	14,
	E_CreateRole_NameExist				=	15,
	E_CreateRole_NameInvalid			=	16,
	E_CreateRole_SafeCodeInvalid		=	17,
	E_CreateRole_InWorld				=	18,
	E_CreateRole_RoleLoading			=	19,
	E_CreateRole_RoleEnumNotSuccess		=	20,

	E_DelRole_RoleNotExist				=	21,
	E_DelRole_RoleDeleting				=	22,
	E_DelRole_RoleEnumNotDone			=	23,
	E_DelRole_RoleCreating				=	24,
	E_DelRole_SafeCodeIncorrect			=	25,
	E_DelRole_InWorld					=	26,
	E_DelRole_RoleLoading				=	27,
	E_DelRole_LeaveGuild1st				=	28,	// �����������
	E_DelRole_InDelGuardTime			=	29,
	E_DelRole_RoleChangeNaming			=	30,

	E_EnumRole_RoleEnumed				=	31,
	E_EnumRole_RoleEnuming				=	32,
	E_EnumRole_InWorld					=	33,

	E_SelectRole_RoleEnumNotDone		=	41,
	E_SelectRole_RoleCreating			=	42,
	E_SelectRole_RoleDeleting			=	43,
	E_SelectRole_RoleNotExist			=	44,
	E_SelectRole_InWorld				=	45,
	E_SelectRole_RoleLoading			=	46,

	E_Account_Reward_Receive			=	47,
	E_Account_Reward_Receive_Limit		=	48,

	E_SelectRole_Not_Join_Game			=	49,
	E_SelectRole_VerificationError		=	50,	// ��֤�����
	E_SelectRole_RoleChangNaming		=	51,
	E_SelectRole_RoleInDelGuard			=	52,
	E_CreateRole_RoleChangNaming		=	60,
	E_CreateRole_RoleCancelDelGuardTime	=	61,

	E_DelRole_RoleCancelDelGuardTime	=	70,
	E_DelRole_RoleInLeavePractice		=	71,

	E_ChangeRoleName_InWorld				=	80,
	E_ChangeRoleName_RoleEnumNotDone		=	81,
	E_ChangeRoleName_RoleCreating			=	82,
	E_ChangeRoleName_RoleDeleting			=	83,
	E_ChangeRoleName_RoleLoading			=	84,
	E_ChangeRoleName_RoleChangNaming		=	85,
	E_ChangeRoleName_RoleNotExist			=	86,
	E_ChangeRoleName_NameExist				=	87,
	E_ChangeRoleName_InDelGuard				=	88,
	E_ChangeRoleName_Cant60Days				=	89,
	E_ChangeRoleName_OutOfYuanBao			=	90,
	E_ChangeRoleName_BagPasswordError		=	91,	
	E_ChangeRoleName_RoleCancelDelGuardTime	=	92,

	
	E_CancelRoleDelGuardTime_InWorld				=	110,
	E_CancelRoleDelGuardTime_RoleEnumNotDone		=	111,
	E_CancelRoleDelGuardTime_RoleCreating			=	112,
	E_CancelRoleDelGuardTime_RoleDeleting			=	113,
	E_CancelRoleDelGuardTime_RoleLoading			=	114,
	E_CancelRoleDelGuardTime_RoleChangNaming		=	115,
	E_CancelRoleDelGuardTime_RoleNotExist			=	116,
	E_CancelRoleDelGuardTime_NameExist				=	117,
	E_CancelRoleDelGuardTime_NotInDelGuard			=	118,	
	E_CancelRoleDelGuardTime_RoleCancelDelGuardTime =	119,

	E_SerialReward_not_init			=		130,		// ���к����û�г�ʼ�����
	E_SerialReward_SerialNotExists	=		131,		// ���к����������
	E_SerialReward_BagNotSpace		=		132,		// ���û���㹻�İ����ռ�
	E_SerialReward_rep_receive		=		133,		// �Ѿ���ȡͬ�����
};

//-----------------------------------------------------------------------------
// ���Ƽ��
//-----------------------------------------------------------------------------
struct NET_SIC_check_name : public tag_net_message
{
	NET_SIC_check_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_check_name");
		dw_size = sizeof(NET_SIC_check_name);
	}
	TCHAR			szRoleName[X_SHORT_NAME];
};

struct NET_SIS_check_name : public tag_net_message
{
	NET_SIS_check_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_check_name");
		dw_size = sizeof(NET_SIS_check_name);
	}
	DWORD	dwError;
};

//-----------------------------------------------------------------------------
// ������Ϸ
//-----------------------------------------------------------------------------
struct NET_SIC_join_game : public tag_net_message
{
	NET_SIC_join_game()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_join_game");
		dw_size = sizeof(NET_SIC_join_game);
	}
	DWORD		dw_account_id;		// �ʺ�ID
	DWORD		dwVerifyCode;		// ��½���������͸��ͻ��˵���֤��
};

struct NET_SIS_join_game : public tag_net_message
{
	NET_SIS_join_game()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_join_game");
		dw_size = sizeof(NET_SIS_join_game);
	}
	DWORD		dw_error_code;
	INT			nGMPrivilege;		// GMȨ��
};

//-----------------------------------------------------------------------------
// �����ɫ�б�
//-----------------------------------------------------------------------------
struct NET_SIC_enum_role : public tag_net_message
{
	NET_SIC_enum_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_enum_role");
		dw_size = sizeof(NET_SIC_enum_role);
	}
};

struct NET_SIS_enum_role : public tag_net_message
{
	NET_SIS_enum_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_enum_role");
		dw_size = sizeof(NET_SIS_enum_role);
	}
	DWORD			dw_error_code;
	DWORD			dwSafeCodeCrc;
	tagDWORDTime	dwTimeReset;
	tagDWORDTime	dwTimeLastLogin;	//�ϴε�¼ʱ��
	DWORD			dwIPLast;			//�ϴε�¼IP
	DWORD			dw_ip;				//���ε�¼IP
	INT				n_num;
	BOOL			b_need_verify;		//�Ƿ���Ҫ��֤
	INT				dwYuanBao;
	BYTE			bySimpleInfo[1];
};


//������ȫ��
struct NET_SIC_safe_code : public tag_net_message
{
	NET_SIC_safe_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_safe_code");
		dw_size = sizeof(NET_SIC_safe_code);
	}
	DWORD			dwSafeCode;
};

struct NET_SIS_safe_code : public tag_net_message
{
	NET_SIS_safe_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_safe_code");
		dw_size = sizeof(NET_SIS_safe_code);
	}
	DWORD			dw_error_code;
};

//���ð�ȫ��
struct NET_SIC_reset_safe_code : public tag_net_message
{
	NET_SIC_reset_safe_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reset_safe_code");
		dw_size = sizeof(NET_SIC_reset_safe_code);
	}
};

struct NET_SIS_reset_safe_code : public tag_net_message
{
	NET_SIS_reset_safe_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reset_safe_code");
		dw_size = sizeof(NET_SIS_reset_safe_code);
	}
	tagDWORDTime	dwTimeReset;
};


//ȡ����ȫ��
struct NET_SIC_cancel_safe_code_reset : public tag_net_message
{
	NET_SIC_cancel_safe_code_reset()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_safe_code_reset");
		dw_size = sizeof(NET_SIC_cancel_safe_code_reset);
	}
};

struct NET_SIS_cancel_safe_code_reset : public tag_net_message
{
	NET_SIS_cancel_safe_code_reset()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_safe_code_reset");
		dw_size = sizeof(NET_SIS_cancel_safe_code_reset);
	}
	DWORD			dw_error_code;
};

//-----------------------------------------------------------------------------
// ������ɫ
//-----------------------------------------------------------------------------
struct NET_SIC_create_role : public tag_net_message
{
	NET_SIC_create_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_create_role");
		dw_size = sizeof(NET_SIC_create_role);
	}
	TCHAR			szRoleName[X_SHORT_NAME];
	EPreChapStatus	eStatus;
	tagAvatarAtt	AvatarAtt;
	EClassType		eClassType;
};

struct NET_SIS_create_role : public tag_net_message
{
	NET_SIS_create_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_create_role");
		dw_size = sizeof(NET_SIS_create_role);
	}
	DWORD			dw_error_code;
	BYTE			bySimRoleInfo[1];
};

//-----------------------------------------------------------------------------
// ɾ����ɫ
//-----------------------------------------------------------------------------
struct NET_SIC_delete_role : public tag_net_message
{
	NET_SIC_delete_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_role");
		dw_size = sizeof(NET_SIC_delete_role);
	}
	DWORD			dw_role_id;						
	DWORD			dwSafeCodeCrc;
};

struct NET_SIS_delete_role : public tag_net_message
{
	NET_SIS_delete_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_role");
		dw_size = sizeof(NET_SIS_delete_role);
	}
	DWORD			dw_error_code;
	DWORD			dw_role_id;
};

struct NET_SIS_delete_role_guard_set : public tag_net_message
{
	NET_SIS_delete_role_guard_set()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_role_guard_set");
		dw_size =  sizeof(*this);
	}
	DWORD			dw_error_code;
	DWORD			dw_role_id;
	DWORD			dw_delGuardTime;
};

//-----------------------------------------------------------------------------
// ��ɫ�ָ�<>
//-----------------------------------------------------------------------------
struct NET_SIC_delete_role_guard_Cancel : public tag_net_message
{
	NET_SIC_delete_role_guard_Cancel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_role_guard_Cancel");
			dw_size = sizeof(*this);
	}
	DWORD			dw_role_id;
};

struct NET_SIS_delete_role_guard_Cancel : public tag_net_message
{
	NET_SIS_delete_role_guard_Cancel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_role_guard_Cancel");
		dw_size = sizeof(*this);
	}
	DWORD dw_error;
	DWORD dw_role_id;
};

//-----------------------------------------------------------------------------
// ��ɫ����
//-----------------------------------------------------------------------------
struct NET_SIC_change_role_name : public tag_net_message 
{   
	NET_SIC_change_role_name ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_SIC_change_role_name" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id; 
	TCHAR sz_new_role_name[X_SHORT_NAME];  
	DWORD		dw_safe_code;
}; 

struct NET_SIS_change_role_name : public tag_net_message 
{   
	NET_SIS_change_role_name ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_SIS_change_role_name" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_error_code;  
	DWORD dw_role_id; 
	DWORD dw_change_time;
	TCHAR sz_new_role_name[X_SHORT_NAME];  
}; 

//------------------------------------------------------------------------------
// ѡ���ɫ
//------------------------------------------------------------------------------
struct NET_SIC_select_role : public tag_net_message
{
	NET_SIC_select_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_select_role");
		dw_size = sizeof(NET_SIC_select_role);
	}
	DWORD			dw_role_id;
	DWORD			dw_verification_code_crc;	// ��֤��crc
};

struct NET_SIS_select_role : public tag_net_message
{
	NET_SIS_select_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_select_role");
		dw_size = sizeof(NET_SIS_select_role);
	}
	DWORD			dw_error_code;
	DWORD			dw_role_id;
};

//------------------------------------------------------------------------------
// ��ȡ���к����
//------------------------------------------------------------------------------
struct NET_SIC_receive_serial_reward : public tag_net_message
{
	NET_SIC_receive_serial_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_receive_serial_reward");
		dw_size = sizeof(*this);
	}

	CHAR	sz_serial[X_SHORT_NAME];
};

struct NET_SIS_receive_serial_reward : public tag_net_message
{
	NET_SIS_receive_serial_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_receive_serial_reward");
		dw_size = sizeof(*this);
	}

	DWORD dw_error;
};

//------------------------------------------------------------------------------
// ��ȡ�˺Ž���
//------------------------------------------------------------------------------
struct NET_SIC_receive_account_reward : public tag_net_message
{
	NET_SIC_receive_account_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_receive_account_reward");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_receive_account_reward : public tag_net_message
{
	NET_SIS_receive_account_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_receive_account_reward");
		dw_size = sizeof(*this);
	}

	DWORD		dw_error;
};

//------------------------------------------------------------------------------
// ��ȡ�˺Ž���
//------------------------------------------------------------------------------
struct NET_SIC_receive_account_reward_ex : public tag_net_message
{
	NET_SIC_receive_account_reward_ex()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_receive_account_reward_ex");
		dw_size = sizeof(*this);
	}
	EReceiveState eReceiveState;
};

struct NET_SIS_receive_account_reward_ex : public tag_net_message
{
	NET_SIS_receive_account_reward_ex()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_receive_account_reward_ex");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

struct NET_SIS_send_receive_account_reward_ex : public tag_net_message
{
	NET_SIS_send_receive_account_reward_ex()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_receive_account_reward_ex");
		dw_size = sizeof(*this);
	}

	DWORD	dw_receive_type;
};

//--------------------------------------------------------------
// ����
//--------------------------------------------------------------

#pragma pack(pop)
#endif
