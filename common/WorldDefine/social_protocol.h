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
*	@file		social_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		�罻��Ϣ
*/

#ifndef SOCIAL_PROTOCOL
#define SOCIAL_PROTOCOL


#include "protocol_common_errorcode.h"

#pragma pack(push, 1)

// ������
enum
{
	E_Friend_Target_Not_Exist			=	1,		// Ŀ�겻����
	E_Friend_Target_Not_Sel				=	2,		// ���ܼ��Լ�Ϊ����
	E_Friend_Target_Black_List			=	3,		// �������ڵ�����޷������Ϊ����
	E_Friend_Target_Already_Exit		=	4,		// �ú����Ѵ����ں����б�
	E_Friend_Max_Num					=	5,		// �����б������Ƿ�ﵽ����100��
	E_Friend_Group_Not_Exit				=	6,		// ���鲻����
	E_Friend_Not_Friend					=	7,		// ���Ǹ���Һ���

	E_Black_Targer_Not_Sel				=	20,		// ���ܼ��Լ���������
	E_Black_Max_Num						=	21,		// ����������
	E_Black_Target_Already_Exit			=	22,		// ������ں�������
	E_Black_Target_Not_Exit				=	23,		// ��Ҳ��ں�������
	
	E_Enemy_Target_Not_Exit				=   24,		// ��Ҳ��ڳ�����
	E_Enemy_No_OnLine					=   25,		// ���˲�����

	E_Gift_Not_Exit						=	30,		// ���ﲻ����
	E_Gift_Not_Both_Friend				=	31,		// ����˫�����
	E_Gift_Friend_Not_Online			=	32,		// ���Ѳ�����
	E_Gift_Not_Gift						=	33,		// ���͵���Ʒ��������

	E_Compractice_No_OnLine				=	34,		//�����뷽������
	E_Compractice_Local_InPractice		=	35,		//�����������˫����
	E_Compractice_Remote_InPractice		=	36,		//Զ���������˫����
	E_Compractice_InStall				=	37,		//��Ҵ��ڰ�̯��
	E_Compractice_Local_Practice_Full	=	38,		//���뷽����˫�޴�������
	E_Compractice_Remote_Practice_Full	=	39,		//�����뷽����˫�޴�������
	E_Compractice_Disagree				=	40,		//�����뷽��ͬ��
	E_Compractice_Long					=	41,		//����̫Զ

	E_Propose_Male_Married				=	42,		//�з�������ż
	E_Propose_Female_Married			=	43,		//Ů��������ż
	E_Propose_Female_Disagree			=	44,		//Ů����ͬ����
	E_Propose_Marray_Level				=	45,		//��ҽ��ȼ�����
	E_Propose_Marry_Lack_Item			=	46,		//ȱ�ٻ��
	E_Divorce_Lack_Yuanbao				=	47,		//���Ԫ������
	E_Propose_No_Team					=	48,		//������Ů˫�����һ��
	E_Propose_No_Map					=	49,		//�������ض���ͼ���

	E_Compractice_Level					=	50,		//˫�޵���ұ������20��
	E_Compractice_Sex					=	51,		//����������˫��
	E_Compractice_NotSafearea			=	52,		//˫��˫�������ڰ�ȫ����

	E_Comparctice_Role_Invited			=	53,		//������ڱ�������
	
	E_QBJJ_LEVEL_Min_Woman				=	54,		//Ů���ȼ����� gx add 2013.10.25
	E_QBJJ_LEVEL_MIN_Man				=	55,		//�з��ȼ�����		
	E_QBJJ_RED_NO						=	56,		//Ů��δ��ú촽��֤
	E_QBJJ_RED_NO_REWARD				=	57,		//��ǰû��Ҫ��ȡ�Ľ���
};

// �������ʱ֪ͨ����
struct NET_SIS_login_to_friend : public tag_net_message
{
	NET_SIS_login_to_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_login_to_friend");
		dw_size = sizeof(NET_SIS_login_to_friend);
	}
	DWORD	dw_role_id;
};

// �������ʱ֪ͨ����
struct NET_SIS_logout_to_friend : public tag_net_message
{
	NET_SIS_logout_to_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_logout_to_friend");
		dw_size = sizeof(NET_SIS_logout_to_friend);
	}
	DWORD	dw_role_id;
};

// ���˭�ύΪ����
struct NET_SIC_role_make_friend : public tag_net_message
{
	NET_SIC_role_make_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_make_friend");
		dw_size = sizeof(NET_SIC_role_make_friend);
	}
	DWORD	dwDestRoleID;	
};

struct NET_SIS_role_make_friend : public tag_net_message
{
	NET_SIS_role_make_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_make_friend");
		dw_size = sizeof(NET_SIS_role_make_friend);
	}
	DWORD	dwDestRoleID;
	BOOL	bOnline;
	INT		nLevel;				// ��ɫ�ȼ�
	EClassType eClassType;
	BYTE	by_sex;					// �Ա�
	DWORD	dw_error_code;
};

// ȡ�����ѹ�ϵ
struct NET_SIC_role_cancel_friend : public tag_net_message
{
	NET_SIC_role_cancel_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_cancel_friend");
		dw_size = sizeof(NET_SIC_role_cancel_friend);
	}
	DWORD   dwDestRoleID;
};

struct NET_SIS_role_cancel_friend : public tag_net_message
{
	NET_SIS_role_cancel_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_cancel_friend");
		dw_size = sizeof(NET_SIS_role_cancel_friend);
	}
	DWORD   dwDestRoleID;
	BYTE	byGroup;
	DWORD	dw_error_code;
};

// ���ѷ���
struct NET_SIC_update_friend_group : public tag_net_message
{
	NET_SIC_update_friend_group()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_update_friend_group");
		dw_size = sizeof(NET_SIC_update_friend_group);
	}
	DWORD	dwDestRoleID;
	BYTE	byGroup;
};

struct NET_SIS_update_friend_group : public tag_net_message
{
	NET_SIS_update_friend_group()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_friend_group");
		dw_size = sizeof(NET_SIS_update_friend_group);
	}
	DWORD	dwDestRoleID;
	BYTE	byOldGroup;			// 1-4�������б�
	BYTE	byNewGroup;
	DWORD	dw_error_code;
};

// ������ҵ�������
struct NET_SIC_move_to_black_list : public tag_net_message
{
	NET_SIC_move_to_black_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_move_to_black_list");
		dw_size = sizeof(NET_SIC_move_to_black_list);
	}
	DWORD	dwDestRoleID;
};

struct NET_SIS_move_to_black_list : public tag_net_message
{
	NET_SIS_move_to_black_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_move_to_black_list");
		dw_size = sizeof(NET_SIS_move_to_black_list);
	}
	DWORD	dwDestRoleID;
	BYTE	byOldGroup;
	BOOL	bOnline;
	INT		nLevel;				// ��ɫ�ȼ�
	EClassType eClassType;
	BYTE	by_sex;	
	DWORD	dw_error_code;
};

// ����ҴӺ�����ɾ��
struct NET_SIC_delete_black_list : public tag_net_message
{
	NET_SIC_delete_black_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_black_list");
		dw_size = sizeof(NET_SIC_delete_black_list);
	}
	DWORD	dwDestRoleID;
};

struct NET_SIS_delete_black_list : public tag_net_message
{
	NET_SIS_delete_black_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_black_list");
		dw_size = sizeof(NET_SIS_delete_black_list);
	}
	DWORD	dwDestRoleID;
	DWORD	dw_error_code;
};


// ɾ������
struct NET_SIC_delete_enemy_list : public tag_net_message
{
	NET_SIC_delete_enemy_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_enemy_list");
		dw_size = sizeof(NET_SIC_delete_enemy_list);
	}
	DWORD	dwDestRoleID;
};

struct NET_SIS_delete_enemy_list : public tag_net_message
{
	NET_SIS_delete_enemy_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_enemy_list");
		dw_size = sizeof(NET_SIS_delete_enemy_list);
	}
	DWORD	dwDestRoleID;
	DWORD	dw_error_code;
};


// ��ȡ����λ��
struct NET_SIC_get_enemy_position : public tag_net_message
{
	NET_SIC_get_enemy_position()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_enemy_position");
		dw_size = sizeof(NET_SIC_get_enemy_position);
	}
	DWORD	dwDestRoleID;
};

struct NET_SIS_get_enemy_position : public tag_net_message
{
	NET_SIS_get_enemy_position()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_enemy_position");
		dw_size = sizeof(NET_SIS_get_enemy_position);
	}
	FLOAT	fx;
	FLOAT	fz;
	DWORD	dw_role_id;
	DWORD	dwMapID;
	DWORD	dw_error_code;
};


// ��ӳ���
struct NET_SIC_add_enemy : public tag_net_message
{
	NET_SIC_add_enemy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_add_enemy");
		dw_size = sizeof(NET_SIC_add_enemy);
	}
	DWORD	dwDestRoleID;
};

struct NET_SIS_add_enemy : public tag_net_message
{
	NET_SIS_add_enemy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_enemy");
		dw_size = sizeof(NET_SIS_add_enemy);
	}
	DWORD	dwDestRoleID;
	INT		nLevel;
	EClassType eClassType;
	BOOL	bOnline;
	BYTE	by_sex;	
};
//gx modify 2013.6.27
// ������
struct NET_SIC_send_gift : public tag_net_message
{
	NET_SIC_send_gift()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_send_gift");
		dw_size = sizeof(NET_SIC_send_gift);
	}
	DWORD	dwDestRoleID;		// ���������
	//INT64	n64ItemID;			// ����ID
	BYTE	byLevel;			//�ͻ��ȼ�	1����1�䣬2����9�䣬3����99��
};

struct NET_SIS_send_gift_to_friend : public tag_net_message
{
	NET_SIS_send_gift_to_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_gift_to_friend");
		dw_size = sizeof(NET_SIS_send_gift_to_friend);
	}
	DWORD	dwSrcRoleID;		// ���﷢����
	//DWORD	dw_data_id;			// ��Ʒ����ID
	BYTE	byLevel;			//�ͻ��ȼ�
	DWORD   byAddValue;			//���ӵ�����ֵ
	DWORD	dw_error_code;		//������Ϣ
};
//end
// ������
struct NET_SIS_send_gift_to_sender : public tag_net_message
{
	NET_SIS_send_gift_to_sender()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_gift_to_sender");
		dw_size = sizeof(NET_SIS_send_gift_to_sender);
	}
	DWORD	dw_error_code;
};

// �յ������ظ�
struct NET_SIC_send_gift_reply : public tag_net_message
{
	NET_SIC_send_gift_reply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_gift_reply");
		dw_size = sizeof(NET_SIC_send_gift_reply);
	}
	DWORD	dwSrcRoleID;		// ���﷢����
	DWORD	dw_data_id;			// ����TypeID
	BOOL	bResult;			// �Ƿ����
};

// �㲥
struct NET_SIS_send_gift_broad : public tag_net_message
{
	NET_SIS_send_gift_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_gift_broad");
		dw_size = sizeof(NET_SIS_send_gift_broad);
	}
	DWORD	dwSrcRoleID;
	DWORD	dwDestRoleID;
	DWORD	dw_data_id;
	BOOL	bResult;
};


struct NET_SIC_update_friend_state : public tag_net_message
{
	NET_SIC_update_friend_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_update_friend_state");
		dw_size = sizeof(NET_SIC_update_friend_state);
	}
};

struct NET_SIS_update_friend_state : public tag_net_message
{
	NET_SIS_update_friend_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_friend_state");
		dw_size = sizeof(NET_SIS_update_friend_state);
	}
	INT				n_num;
	tagFriUpdate	FriUpdate[1];
};

struct NET_SIS_make_friend_notice : public tag_net_message
{
	NET_SIS_make_friend_notice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_make_friend_notice");
		dw_size = sizeof(NET_SIS_make_friend_notice);
	}
	DWORD	dw_role_id;
};

struct NET_SIS_update_friend_value : public tag_net_message
{
	NET_SIS_update_friend_value()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_friend_value");
		dw_size = sizeof(NET_SIS_update_friend_value);
	}
	DWORD   dw_role_id;
	INT		nFriVal;
};
//˫�������Ϣ���� gx add 2013.6.27
// ������ҽ���˫��
struct NET_SIC_invite_practice: public tag_net_message
{
	NET_SIC_invite_practice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_invite_practice");
		dw_size = sizeof(NET_SIC_invite_practice);
	}
	DWORD		dwDestRoleID;		// ���������	
};
// ����˫��(���ظ�˫��)
struct NET_SIS_invite_practice_to_both: public tag_net_message
{
	NET_SIS_invite_practice_to_both()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_practice_to_both");
		dw_size = sizeof(NET_SIS_invite_practice_to_both);
	}
	DWORD		dwSrcRoleID;//������ID
	DWORD		dw_error_code;
};
// �������˻ظ�����˫��
struct NET_SIC_invite_practice_reply: public tag_net_message
{
	NET_SIC_invite_practice_reply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_invite_practice_reply");
		dw_size = sizeof(NET_SIC_invite_practice_reply);
	}
	DWORD		dwSrcRoleID;//������ID
	BOOL		bAgree;				// �Ƿ�ͬ��
};
// �������˻ظ������������˵Ļظ�
struct NET_SIS_invite_practice_to_src: public tag_net_message
{
	NET_SIS_invite_practice_to_src()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_practice_to_src");
		dw_size = sizeof(NET_SIS_invite_practice_to_src);
	}
	DWORD		dwSrcRoleID;//������ID
	DWORD		dwDesRoleID;//��������ID
	DWORD		dw_error_code;
};

// ��ҽ���˫�޺���Ұ��Ϣ
struct NET_SIS_practice_to_all: public tag_net_message
{
	NET_SIS_practice_to_all()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_practice_to_all");
		dw_size = sizeof(NET_SIS_practice_to_all);
	}
	DWORD		dwSrcRoleID;//������ID
	DWORD		dwDesRoleID;//��������ID
};
//�������ȡ��˫��
struct NET_SIC_cancel_practice: public tag_net_message
{
	NET_SIC_cancel_practice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_practice");
		dw_size = sizeof(NET_SIC_cancel_practice);
	}
	DWORD dwPartnerID;//��֮˫�޵Ľ�ɫID
};
struct NET_SIS_cancel_practice: public tag_net_message
{
	NET_SIS_cancel_practice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_practice");
		dw_size = sizeof(NET_SIS_cancel_practice);
	}
	DWORD dw_error_code;
};
//end by gx 
////��������Ϣ���� gx add 2013.7.3
// ���������Ů��������
struct NET_SIC_male_propose: public tag_net_message
{
	NET_SIC_male_propose()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_male_propose");
		dw_size = sizeof(NET_SIC_male_propose);
	}
	DWORD		dwDestRoleID;		// Ů�����	
};
// ���(���ظ�˫��)
struct NET_SIS_propose_to_both: public tag_net_message
{
	NET_SIS_propose_to_both()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_propose_to_both");
		dw_size = sizeof(NET_SIS_propose_to_both);
	}
	DWORD		dwSrcRoleID;//�����ID
	DWORD		dw_error_code;
};
// ������˻ظ�����������
struct NET_SIC_propose_reply: public tag_net_message
{
	NET_SIC_propose_reply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_propose_reply");
		dw_size = sizeof(NET_SIC_propose_reply);
	}
	DWORD		dwSrcRoleID;//���Խ�ɫID
	BOOL		bAgree;				// Ů������Ƿ�ͬ��
};
// ������˻ظ����������˫���Ļظ�
struct NET_SIS_propose_reply_to_both: public tag_net_message
{
	NET_SIS_propose_reply_to_both()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_propose_reply_to_both");
		dw_size = sizeof(NET_SIS_propose_reply_to_both);
	}
	DWORD		dwSrcRoleID;//���Խ�ɫID
	DWORD		dwDesRoleID;//Ů�Խ�ɫID
	DWORD		dw_error_code;
};
//���
struct NET_SIC_role_divorce: public tag_net_message
{
	NET_SIC_role_divorce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_divorce");
		dw_size = sizeof(NET_SIC_role_divorce);
	}
};
//
struct NET_SIS_role_divorce_to_both: public tag_net_message
{
	NET_SIS_role_divorce_to_both()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_divorce_to_both");
		dw_size = sizeof(NET_SIS_role_divorce_to_both);
	}
	DWORD	dw_SrcRole_ID;//�����������һ��ID	
	DWORD	dw_error_code;
};
//��ȡ��Ƚ�ά gx add 2013.10.25
struct NET_SIC_get_qbjj_reward:public tag_net_message
{
	NET_SIC_get_qbjj_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_qbjj_reward");
		dw_size = sizeof(NET_SIC_get_qbjj_reward);
	}
};
struct NET_SIS_get_qbjj_reward:public tag_net_message
{
	NET_SIS_get_qbjj_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_qbjj_reward");
		dw_size = sizeof(NET_SIS_get_qbjj_reward);
	}
	DWORD dw_error_code;
};
//�������߷�����һ�� gx add 2013.10.29
struct NET_SIS_login_to_spouse:public tag_net_message
{
	NET_SIS_login_to_spouse()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_login_to_spouse");
		dw_size = sizeof(NET_SIS_login_to_spouse);
	}
};
//�������߷�����һ��
struct NET_SIS_logout_to_spouse:public tag_net_message
{
	NET_SIS_logout_to_spouse()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_logout_to_spouse");
		dw_size = sizeof(NET_SIS_logout_to_spouse);
	}
};
#pragma pack(pop)
#endif