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
*	@file		map_protocol.h
*	@author		lc
*	@date		2011/03/08	initial
*	@version	0.0.1.0
*	@brief		��ͼ��Ϣ
*/

#ifndef MAP_PROTOCOL
#define MAP_PROTOCOL

#define ALARM_40		1
#define ALARM_50		2
#define ALARM_60		3	

#define QUEUE_1V1_YUANBAO	10
#define QUEUE_1V1_DAY_JOINE_NUM		15


#include "protocol_common_errorcode.h"
#include "guild_define.h"

#pragma pack(push, 1)

enum
{
	E_BindRebornMap_NPCInvalid	=	1,	// ְ��NPC�Ƿ�
	E_BindRebornMap_MapInvalid	=	2,	// ��ͼ�Ƿ���������ͨ��ͼ��
	E_BindRebornMap_Already		=	3,	// �Ѿ����ڸõ�ͼ
	E_BindRebornMap_NPCNotFound	=	4,	// û���ҵ�ָ����NPC
	E_BindRebornMap_TooFar		=	5,	// ����̫Զ

	E_Instance_Not_Exit			=	11,	// ����������
	E_Instance_Role_Not_Exit	=	12,	// ��Ҳ�����
	E_Instance_Role_Full		=	13,	// ���������ѵ�����
	E_Instance_Level_Down_Limit =	14,	// ������͵ȼ�����
	E_Instance_Level_Up_Limit	=	15,	// ������ߵȼ�����
	E_Instance_Not_Same_Team	=	16,	// ����ͬһС��
	E_Instance_Role_Lack		=	17,	// ��������δ������
	E_Instance_End_Delete		=	18,	// �����Ѿ����������Ѿ��ر�
	E_Instance_Already			=	19,	// �Ѿ���������������
	E_Instance_Full				=	20,	// ����������������
	E_Instance_Not_Same_Guild   =   21, // ���Ǳ����ɳ�Ա���ܽ�����
	E_Instance_GuildUp			=   22, // ��������������
	E_Instance_Guild_NotFormal  =   23, // ������ʽ����
	E_Instance_Not_Enemy_Guild  =   24,	// ����ս���ж԰��
	E_Instance_Prepare_NoMap	=   25, // ׼��ս��״̬���ܽ����ḱ��
	E_Instance_Lobby_Repair		=   26, // ���ܽ������������
	E_Instance_Act_NoBegin		=   27, // ���ڰ��ս��
	E_Instance_NoGuild			=   28,	// û�а��
	E_Instance_EnterNum_Limit	=	29,	// �����������

	E_Instance_not_teamleader	=   30,	// ���Ƕӳ��������ø���
	E_Instance_not_process		=   31,	// û�и�������
	E_Instance_not_normal		=	32, // ������ͨ������������
	E_Instance_have_role		=   33, // ���������˲�������
	E_Instance_diff_error		=   34,	// �����ѶȲ�ͬ
	E_Instance_team_error		=   35,	// ����в��ܽ�����������
	E_Instance_not_item			=   36, // û��Կ�ײ��ܽ��븱��
	E_Instance_RedName			=	37, // �������ܽ��븱��
	E_Instance_have_online_team =   38, // �ж�Ա���߲������ø���
	E_Instance_process_yuanbao_limit	=	39,		// ������������Ԫ������

	E_Instance_limit_not_exists		=	40,	// ����Ȩֵ������
	E_Instance_limit_yb_limit		=	41,	// ���ø���ȨֵԪ������

	E_Instance_pvp_level_limit	=	50,	// �����ս�����ȼ�����
	E_Instance_pvp_map_limit	=	51,	// �ڸ����в��ܽ���
	E_Instance_pvp_money_limit	=	52,	// ����PvP��Ǯ����
	E_Instance_pvp_state_limit	=	53,	// pvp״̬����
	E_Instance_pvp_in_guild_war	=	54,	// ���ڰ��ս

	E_Instance_1v1_have_apply	=	60,	// �Ѿ��������б���
	E_Instance_1v1_state_limit	=	61,	// ����״̬����
	E_Instance_1v1_map_limit	=	62,	// �����ͼ����
	E_Instance_1v1_level_limit	=	63, // ����ȼ�����
	E_Instance_1v1_yuanbao_limit=	64,	// Ԫ������
	E_Instance_1v1_nohane_apply	=	65,	// ���������б���
	E_Instance_1v1_no_start		=	66,	// 1v1δ����
	E_Instance_1v1_no_have_award	= 67, // û��1v1����
	E_Instance_1v1_Is_guild_war	=	68,	// ���ڰ��ս

	E_Instance_reservation_level_limit	=	70, // Լս�ȼ�����
	E_Instance_reservation_state_limit	=	71,	// Լս״̬����
	E_Instance_reservation_map_limit	=	72,	// Լս��ͼ����
	E_Instance_have_reservation			=	73,	// �Ѿ���Լս��
	E_Instance_beservation_no_line		=	74,	// Լս��������
	E_Instance_reservation_yuanbao_limit=	75, // Լս��Ԫ������
	E_Instance_bereservation_state_limit=	76,	// ��Լս��״̬����
	E_Instance_bereservation_yuanbao_limit	=	77,	// ��Լս��Ԫ������
	E_Instance_bereservation_have_1v1_apply	=	78,	// ��Լս���Ѿ��������б���
	E_Instance_reservation_time_limit		=	79,	// Լս��ʱ
	E_Instance_reservation_role_error		=	80,	// Լս�������
	E_Instance_bereservation_map_limit		=	81,	// ��Լս�˵�ͼ����

	E_Active_NotEnough						=	82,	// ��Ծ�Ȳ���
	E_Active_repeat_receive					=	83,	// ��Ծ�⽱���ظ���ȡ		
	E_Instance_is_guild_war					=	84,	// ��һ���ڰ��ս��


	// ������������
	E_Instance_Single_saodanging			=	100,// ɨ���в��ܽ���
	E_Instance_Single_qianzhinot			=	101,// ǰ��û��ͨ		
	E_Instance_Single_EnterMax				=	102,// ��������������
	// ������ɨ��������
	E_Instance_Saodang_nopass				=	103,// Ҫɨ���ĸ�����û����սͨ��
	E_Instance_Saodang_full					=	104,// ����ɨ���Ĵ�������
	E_Instance_Saodang_ing					=	105,// ���ڽ���ɨ����

	E_Instance_pvp_biwu_level_limit	=	110,	// ������丱���ȼ�����
	E_Instance_pvp_biwu_active_not_started	=	111,	// ����δ��ʼ
	E_Instance_pvp_biwu_active_is_started	=	112,	// �����Ѿ���ʼ

};

struct tagNPCLoading
{
	DWORD		dw_npc_id;
	DWORD		dw_Obj_id;
};

struct tag1v1
{
	DWORD	dw_role_id[2];
	DWORD	dw_instance_id;
	BOOL	b_delete;
	DWORD	dw_yuanbao;

	tag1v1()
	{
		memset(dw_role_id, INVALID_VALUE, sizeof(dw_role_id));
		dw_instance_id = INVALID_VALUE;
		b_delete = FALSE;
		dw_yuanbao = 0;
	}
};

//------------------------------------------------------------------------------
// �ȵ���ͼ������
//------------------------------------------------------------------------------
struct NET_SIC_role_map_trigger : public tag_net_message
{
	NET_SIC_role_map_trigger()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_map_trigger");
		dw_size = sizeof(NET_SIC_role_map_trigger);
	}
	DWORD	dwTriggerID;
	DWORD	dwMisc;			// �������ͨ������������������Ѷȣ�
};

//------------------------------------------------------------------------------
// ����������Ϣ
//------------------------------------------------------------------------------
struct NET_SIS_instance_limit_info : public tag_net_message
{
	NET_SIS_instance_limit_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_instance_limit_info");
		dw_size = sizeof(*this);
	}
	DWORD		dw_enter_num;
	DWORD		dw_max_enter_num;
};


//------------------------------------------------------------------------------
// ���븱��
//------------------------------------------------------------------------------
struct NET_SIS_enter_instance : public tag_net_message
{
	NET_SIS_enter_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_enter_instance");
		dw_size = sizeof(NET_SIS_enter_instance);
	}
	DWORD	dwTimeLimit;	// ʱ�޸�����ʣʱ�䣬��λ����( ��ʱ�޸���ΪINVALID_VALUE��
	//DWORD	dwGuildSymbol;		// ����־
	//TCHAR	szText[2];			// ����־����
	//INT		n_family_name[NPC_NAME_NUM];		// ���npc��
	//INT		n_name[NPC_NAME_NUM];				// ���npc��
	DWORD	dw_error_code;
};


//------------------------------------------------------------------------------
//�뿪����
//------------------------------------------------------------------------------
struct NET_SIS_leave_instance : public tag_net_message
{
	NET_SIS_leave_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_leave_instance");
		dw_size = sizeof(NET_SIS_leave_instance);
	}
	INT		nType;		// 1.�����������
};


//-----------------------------------------------------------------------------
// ȥ�µ�ͼ
//-----------------------------------------------------------------------------
struct NET_SIS_goto_new_map : public tag_net_message
{
	NET_SIS_goto_new_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_goto_new_map");
		dw_size = sizeof(NET_SIS_goto_new_map);
	}
	DWORD	dwMapID;
	//int		nX;
	//int		nY;
	//int		nDirX;
	//int		nDirY;
	Vector3	pos;
	Vector3	faceTo;
};


//-----------------------------------------------------------------------------
// ֪ͨ��������Ƿ��ٻ�����
//-----------------------------------------------------------------------------
struct NET_SIS_instance_nofity : public tag_net_message
{
	NET_SIS_instance_nofity()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_instance_nofity");
		dw_size = sizeof(NET_SIS_instance_nofity);
	}
};

struct NET_SIC_instance_notify : public tag_net_message
{
	NET_SIC_instance_notify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_instance_notify");
		dw_size = sizeof(NET_SIC_instance_notify);
	}
	bool	bNotify;
};


//-----------------------------------------------------------------------------
// ֪ͨ���ж����Ƿ���븱��
//-----------------------------------------------------------------------------
struct NET_SIS_instance_agree : public tag_net_message
{
	NET_SIS_instance_agree()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_instance_agree");
		dw_size = sizeof(NET_SIS_instance_agree);
	}
	DWORD   dwInviterID;
	DWORD	dwMapID;
	DWORD	dwMisc;
};

struct NET_SIC_instance_agree : public tag_net_message
{
	NET_SIC_instance_agree()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_instance_agree");
		dw_size = sizeof(NET_SIC_instance_agree);
	}
	bool	bAgree;
};


//-----------------------------------------------------------------------------
// ��������������
//-----------------------------------------------------------------------------
struct NET_SIS_instance_complete : public tag_net_message
{
	NET_SIS_instance_complete()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_instance_complete");
		dw_size = sizeof(NET_SIS_instance_complete);
	}
};


//-----------------------------------------------------------------------------
// �����뿪����
//-----------------------------------------------------------------------------
struct NET_SIC_leave_instance : public tag_net_message
{	
	NET_SIC_leave_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_instance");
		dw_size = sizeof(NET_SIC_leave_instance);
	}
};


//-----------------------------------------------------------------------------
// ͬ����������ʱ
//-----------------------------------------------------------------------------
struct NET_SIS_synchronize_instance_time : public tag_net_message
{
	NET_SIS_synchronize_instance_time()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_instance_time");
		dw_size = sizeof(NET_SIS_synchronize_instance_time);
	}
	DWORD	dwTimeLeft;			// ����ʣ��ʱ�䣺��λ����
};

//-----------------------------------------------------------------------------
// �󶨸����
//-----------------------------------------------------------------------------
struct NET_SIC_bind_reborn_map : public tag_net_message
{
	NET_SIC_bind_reborn_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_bind_reborn_map");
		dw_size = sizeof(NET_SIC_bind_reborn_map);
	}
	DWORD	dwNPCID;		// ְ��NPCID
};

struct NET_SIS_bind_reborn_map : public tag_net_message
{
	NET_SIS_bind_reborn_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bind_reborn_map");
		dw_size = sizeof(NET_SIS_bind_reborn_map);
	}
	DWORD	dw_error_code;
	DWORD	dwBornMapID;
	Vector3	vBornPos;
};


//-----------------------------------------------------------------------------
// �ͻ��˼������
//-----------------------------------------------------------------------------
struct NET_SIC_load_complete : public tag_net_message
{
	NET_SIC_load_complete()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_load_complete");
		dw_size = sizeof(NET_SIC_load_complete);
	}
};

//-----------------------------------------------------------------------------
// ���ø�������
//-----------------------------------------------------------------------------
struct NET_SIC_reset_instance : public tag_net_message
{
	NET_SIC_reset_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reset_instance");
		dw_size = sizeof(NET_SIC_reset_instance);
	}

	DWORD	dw_map_id;			// ��ͼid
	INT		n_mode;				// ��ͼ�Ѷ�
};

struct NET_SIS_reset_instance : public tag_net_message
{
	NET_SIS_reset_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reset_instance");
		dw_size = sizeof(NET_SIS_reset_instance);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// ���ø���Ȩֵ
//-----------------------------------------------------------------------------
struct NET_SIC_reset_instance_limit : public tag_net_message
{
	NET_SIC_reset_instance_limit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reset_instance_limit");
		dw_size = sizeof(*this);
	}

	DWORD	dw_map_id;
};

struct NET_SIS_reset_instance_limit : public tag_net_message
{
	NET_SIS_reset_instance_limit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reset_instance_limit");
		dw_size = sizeof(*this);
	}

	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// �������رյ���ʱ
//-----------------------------------------------------------------------------
struct NET_SIS_ShutDown_Time : public tag_net_message
{
	NET_SIS_ShutDown_Time()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_ShutDown_Time");
		dw_size = sizeof(*this);
	}
	INT nTime;
};

//-----------------------------------------------------------------------------
// Ԥ����NPC
//-----------------------------------------------------------------------------
struct NET_SIS_NPC_Loading : public tag_net_message
{
	NET_SIS_NPC_Loading()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_NPC_Loading");
		dw_size = sizeof(*this);
	}

	INT32	n32_num;
	tagNPCLoading	st_NPCLoading[1];

};

//-----------------------------------------------------------------------------
// ������ս����
//-----------------------------------------------------------------------------
struct NET_SIC_enter_pvp_instance : public tag_net_message
{
	NET_SIC_enter_pvp_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_enter_pvp_instance");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_enter_pvp_instance : public tag_net_message
{
	NET_SIS_enter_pvp_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_enter_pvp_instance");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// �뿪��ս����
//-----------------------------------------------------------------------------
struct NET_SIC_leave_pvp_instance : public tag_net_message
{
	NET_SIC_leave_pvp_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_pvp_instance");
		dw_size = sizeof(*this);
	}
};

//-----------------------------------------------------------------------------
// ��ս���
//-----------------------------------------------------------------------------
struct NET_SIS_pvp_result : public tag_net_message
{
	NET_SIS_pvp_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pvp_result");
		dw_size = sizeof(*this);
	}

	TCHAR	sz_kill_name[X_SHORT_NAME];
	BOOL	b_win;
};

//-----------------------------------------------------------------------------
// ������丱��
//-----------------------------------------------------------------------------
struct NET_SIC_enter_pvp_biwu_instance : public tag_net_message
{
	NET_SIC_enter_pvp_biwu_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_enter_pvp_biwu_instance");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_enter_pvp_biwu_instance : public tag_net_message
{
	NET_SIS_enter_pvp_biwu_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_enter_pvp_biwu_instance");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// �뿪���丱��
//-----------------------------------------------------------------------------
struct NET_SIC_leave_pvp_biwu_instance : public tag_net_message
{
	NET_SIC_leave_pvp_biwu_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_pvp_instance");
		dw_size = sizeof(*this);
	}
};

//-----------------------------------------------------------------------------
// ������
//-----------------------------------------------------------------------------
struct NET_SIS_pvp_biwu_result : public tag_net_message
{
	NET_SIS_pvp_biwu_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pvp_biwu_result");
		dw_size = sizeof(*this);
	}

	TCHAR	sz_kill_name[X_SHORT_NAME];
	BOOL	b_win;
};

//-----------------------------------------------------------------------------
// 1v1����
//-----------------------------------------------------------------------------
struct NET_SIC_1v1_apply : public tag_net_message
{
	NET_SIC_1v1_apply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_1v1_apply");
		dw_size = sizeof(*this);
	}
	DWORD dw_safe_code; //��������
};

struct NET_SIS_1v1_apply : public tag_net_message
{
	NET_SIS_1v1_apply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_1v1_apply");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// �뿪1v1����
//-----------------------------------------------------------------------------
struct NET_SIC_1v1_leave : public tag_net_message
{
	NET_SIC_1v1_leave()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_1v1_leave");
		dw_size = sizeof(*this);
	}
};

//-----------------------------------------------------------------------------
// �뿪1v1����
//-----------------------------------------------------------------------------
struct NET_SIC_1v1_leave_queue : public tag_net_message
{
	NET_SIC_1v1_leave_queue()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_1v1_leave_queue");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_1v1_leave_queue : public tag_net_message
{
	NET_SIS_1v1_leave_queue()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_1v1_leave_queue");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// 1v1ʤ�����
//-----------------------------------------------------------------------------
struct NET_SIS_1v1_result : public tag_net_message
{
	NET_SIS_1v1_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_1v1_result");
		dw_size = sizeof(*this);
	}
	
	TCHAR	sz_win_name[X_SHORT_NAME];
	TCHAR	sz_faile_name[X_SHORT_NAME];
};

//-----------------------------------------------------------------------------
// 1v1����ʤ�����
//-----------------------------------------------------------------------------
struct NET_SIS_1v1_score_result : public tag_net_message
{
	NET_SIS_1v1_score_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_1v1_score_result");
		dw_size = sizeof(*this);
	}
	BOOL	bWin;
	INT		nScore;				// ��ǰ����
	INT		nJoinNum;			// �������
	INT		nMaxScore;			// �������
	BOOL	bAward;				// �Ƿ�����콱				
};

//-----------------------------------------------------------------------------
// 1v1�����콱
//-----------------------------------------------------------------------------
struct NET_SIC_get_1v1_score_award : public tag_net_message
{
	NET_SIC_get_1v1_score_award()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_1v1_score_award");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_1v1_score_award : public tag_net_message
{
	NET_SIS_get_1v1_score_award()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_1v1_score_award");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// 1v1������Ϣ
//-----------------------------------------------------------------------------
struct NET_SIS_1v1_score_info : public tag_net_message
{
	NET_SIS_1v1_score_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_1v1_score_info");
		dw_size = sizeof(*this);
	}
	INT		nScore;				// ��ǰ����
	INT		nJoinNum;			// �������
	INT		nMaxScore;			// �������
	BOOL	bAward;				// �Ƿ�����콱		
};

//-----------------------------------------------------------------------------
// Լս����
//-----------------------------------------------------------------------------
struct NET_SIC_reservation_apply : public tag_net_message
{
	NET_SIC_reservation_apply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reservation_apply");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;		// ��Լ��id
	DWORD	dw_safe_code; //��������
};

struct NET_SIS_reservation_apply_notify : public tag_net_message
{
	NET_SIS_reservation_apply_notify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reservation_apply_notify");
		dw_size = sizeof(*this);
	}

	DWORD	dw_role_id;		// Լս��id
	EClassType	eClass;
	INT		nLevel;
	INT		nYuanbao;
	INT		n_Equip_Scroe;
};

struct NET_SIS_reservation_apply : public tag_net_message
{
	NET_SIS_reservation_apply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reservation_apply");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// Լս�ظ�
//-----------------------------------------------------------------------------
struct NET_SIC_reservation_result : public tag_net_message
{
	NET_SIC_reservation_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reservation_result");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	BOOL	b_ok;
	DWORD	dw_safe_code; //��������
};

struct NET_SIS_reservation_cancel : public tag_net_message
{
	NET_SIS_reservation_cancel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reservation_cancel");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_reservation_timeout : public tag_net_message
{
	NET_SIS_reservation_timeout()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reservation_timeout");
		dw_size = sizeof(*this);
		
	}
};

struct NET_SIS_reservation_result : public tag_net_message
{
	NET_SIS_reservation_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reservation_result");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// ��ȡԼս������Ϣ
//-----------------------------------------------------------------------------
struct NET_SIC_get_reservation_info : public tag_net_message
{
	NET_SIC_get_reservation_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_reservation_info");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
};

struct NET_SIS_get_reservation_info : public tag_net_message
{
	NET_SIS_get_reservation_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_reservation_info");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
	EClassType	eClass;
	INT			nLevel;
	INT			nEquipScore;
};

// ��ȡ��Ծ����Ϣ
struct NET_SIC_get_active_info : public tag_net_message
{
	NET_SIC_get_active_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_active_info");
		dw_size = sizeof(*this);
	}
};

// ��ȡ��Ծ����Ϣ
struct NET_SIC_get_guild_active_info : public tag_net_message
{
	NET_SIC_get_guild_active_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_active_info");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_active_info : public tag_net_message
{
	NET_SIS_get_active_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_active_info");
		dw_size = sizeof(*this);
	}

	INT32	n32_active_num;							// ��Ծ��
	INT32	n32_active_data[MAX_ACTIVE_DATA];		// ��Ծ������
	BOOL	b_active_receive[MAX_ACTIVE_RECEIVE];	// ��Ծ���콱����
};

struct NET_SIS_get_guild_active_info : public tag_net_message
{
	NET_SIS_get_guild_active_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_active_info");
		dw_size = sizeof(*this);
	}

	INT32	n32_active_num;							// ��Ծ��
	INT32	n32_active_data[MAX_ACTIVE_DATA];		// ��Ծ������
	BOOL	b_active_receive[MAX_ACTIVE_RECEIVE];	// ��Ծ���콱����
};

// ��Ծ�ȱ��
struct NET_SIS_change_role_active_num : public tag_net_message
{
	NET_SIS_change_role_active_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_role_active_num");
		dw_size = sizeof(*this);
	}

	INT		n_index;			// ������ȡ�����ĵ�һ��λ��
	INT32	n32_active_num;
};

struct NET_SIS_change_guild_active_num : public tag_net_message
{
	NET_SIS_change_guild_active_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_guild_active_num");
		dw_size = sizeof(*this);
	}

	INT		n_index;			// ������ȡ�����ĵ�һ��λ��
	INT32	n32_active_num;
};

// ��ȡ��Ծ�Ƚ���
struct NET_SIC_role_active_receive : public tag_net_message
{
	NET_SIC_role_active_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_active_receive");
		dw_size = sizeof(*this);
	}
	INT	nIndex;
};

struct NET_SIC_guild_active_receive : public tag_net_message
{
	NET_SIC_guild_active_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_active_receive");
		dw_size = sizeof(*this);
	}
	INT	nIndex;
};

struct NET_SIS_role_active_receive : public tag_net_message
{
	NET_SIS_role_active_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_active_receive");
		dw_size = sizeof(*this);
	}
	INT nIndex;
	DWORD dw_error;
};

struct NET_SIS_guild_active_receive : public tag_net_message
{
	NET_SIS_guild_active_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_active_receive");
		dw_size = sizeof(*this);
	}
	INT nIndex;
	DWORD dw_error;
};


// һ����ɻ�Ծ��
struct NET_SIC_active_done : public tag_net_message
{
	NET_SIC_active_done()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_active_done");
		dw_size = sizeof(*this);
	}

	INT nIndex;
	INT nBeishu;//gx add ���񷭱���ɶ���
};


// һ����ɻ�Ծ��
struct NET_SIS_active_done : public tag_net_message
{
	NET_SIS_active_done()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_active_done");
		dw_size = sizeof(*this);
	}
	INT nIndex;
	DWORD dw_erroe_code;
};
// ÿ�ջһ������ gx add 2013.12.18
struct NET_SIC_daily_act_transmit:public tag_net_message
{
	NET_SIC_daily_act_transmit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_daily_act_transmit");
		dw_size = sizeof(*this);
	}
	INT nIndex;//�����
};

// ���ѽ���
struct NET_SIS_get_ConsumeReward : public tag_net_message
{
	NET_SIS_get_ConsumeReward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_ConsumeReward");
		dw_size = sizeof(*this);
	}

	DWORD	dwConsumeRewardConut;	//��������
	DWORD	dwConsumeRewardData;	//��ȡ���
};




#pragma pack(pop)
#endif

