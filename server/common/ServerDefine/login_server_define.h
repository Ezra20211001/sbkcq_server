
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//��½������������ݽṹ

#pragma once

#include "../../common/WorldDefine/time.h"

#pragma pack(push, 1)


//! world״̬
enum E_world_status
{
	ews_well			=	0,		// ����
	ews_init_not_done	=	1,		// δ��ʼ�����
	ews_system_error	=	2,		// ϵͳ���ֹ���
	ews_proof_error		=	3,		// ��֤����������
};


//! ��֤����
enum E_proof_policy
{
	epp_null	=	-1,
	epp_test	=	0,		// ����ר��
	epp_own		=	1,		// �Լ���˾��֤����
	epp_facebook =	2,		// facebook

	epp_end		=	3		
};


//! ��ҵ�¼ʱ��״̬
enum  E_player_login_status
{
	epls_null		=	-1,		// ��Ч
	epls_off_line	=	0,		// ����
	epls_online		=	1,		// ����
	epls_loging		=	2,		// ��¼��
	epls_unknown	=	3,		// δ֪
};

//! ��ҷ�ͣ����  
enum  E_player_frobid_mask
{
	eplm_member_center	=	0x01,		// ��Ա����
	eplm_gm_tool		=	0x02,		// GM����
	eplm_cell_phone		=	0x04,		// �ֻ���
	eplm_mibao			=	0x08,		// �ܱ�����ͣ
	eplm_waigua			=	0x10		// ������Զ���ͣ
};

//! ��֤����ṹ
struct s_proof_result
{
	DWORD					dw_client_id;		// �ͻ���ID
	DWORD					dw_account_id;		// �ʺ�ID
	BOOL					b_guard;			// ������
	INT						n_guard_accu_time;	// �������ۻ�ʱ��
	E_player_login_status	e_login_status;		// ��½״̬
	DWORD					dw_world_name_crc;	// ��ǰ��½����Ϸ����
	DWORD					dw_frobid_mask;		// ��ͣ���� ÿ1λ��Ӧһ�ַ�ͣ����
	BYTE					by_privilege;		// Ȩ��
	bool					b_need_mibao;		// �Ƿ�ʹ���ܱ�
	DWORD					dw_pre_login_ip;	// �ϴε�¼ip
	tagDWORDTime			dw_pre_login_time;	// �ϴε�¼ʱ��
	BYTE					by_SpecialAccount;	// �Ƿ������˺�<ZF>
	BYTE					by_reserved;		// ����������

	s_proof_result()
	{
		dw_client_id		=	INVALID_VALUE;
		dw_account_id		=	INVALID_VALUE;
		b_guard			=	FALSE;
		n_guard_accu_time	=	0;
		e_login_status	=	epls_off_line;
		by_privilege		=	0;
		b_need_mibao		=	false;
		dw_frobid_mask	=   0;
		dw_pre_login_ip    =	0;
		dw_pre_login_time	=   0;
		by_SpecialAccount = 0;
	}
};

struct s_proof_result_third
{
	s_proof_result result;
	CHAR szAccount[X_SHORT_NAME];
};

struct s_proof_result_full : public s_proof_result
{
	BYTE by_Type;
	CHAR szAccount[X_SHORT_NAME];
	INT n_ret;		// ���ؽ��
};

//! ��֤�ص�����
typedef fastdelegate::FastDelegate2<INT, VOID*, UINT> PROOFCALLBACK;

#pragma pack(pop)