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
*	@file		role_att_protocol.h
*	@author		lc
*	@date		2011/03/10	initial
*	@version	0.0.1.0
*	@brief		����������Ϣ
*/


#ifndef ROLE_ATT_PROTOCOL
#define ROLE_ATT_PROTOCOL

#include "protocol_common_errorcode.h"
#include "RoleDefine.h"
#include "talent_define.h"
#include "skill_define.h"
#include "buff_define.h"
#include "QuestDef.h"
#include "suit_define.h"
#include "SocialDef.h"
#include "pet_define.h"
#include "guild_define.h"
#pragma pack(push, 1)

#define DAY_HANG_GETEXP_TIME_MS (6*60*60*1000) // ms
#define COOLDOWN_REVIVE_CD (30) //s
#define GETEXP_TIME_TICK (10*TICK_PER_SECOND)
#define HUANG_DEC_VIGOUR_TICK (60*TICK_PER_SECOND)
#define HUANG_DEC_VIGOUR_VAL (1)
#define GETEXP_MIN_LEVEL (71)
enum
{
	E_BidAttPoint_PointInvalid			=	1,		// Ͷ�㲻�Ϸ�
	E_BidAttPoint_NoEnoughAttPoint		=	2,		// û���㹻�����Ե�

	E_ClearAttPoint_ItemNotValid		=	10,		// ʹ�õ���Ʒ���Ϸ�

	E_JoinHang_State					=	11,		// �Ѿ�����һ�״̬
	E_Hang_Area_Limit					=   12,		// �һ���������
	E_Hang_Equip_No_Exist				=	13,		// �һ�װ��������
	E_Hang_Item_No_Exist				=	14,		// �һ���Ʒ������
	E_Hang_Num_Limit					=   15,		// �һ���������
	E_Hang_NoHang_State					=	16,		// ���ڹһ�״̬
	E_Hang_State_Limit					=   17,		// ս��״̬���ܹһ�

	E_Gift_BagNoEnough					=   18,		// �����ռ䲻��
	E_Gift_NotGet						=   19,		// ����ʱ��δ�������ܻ�ȡ

	E_Hang_Yuanbao_No_Enough			=	20,		// �һ�Ԫ������	
	E_Hang_Level_No_Enough				=	21,		// �һ��ȼ�����

	E_Safe_Code_Error					= 22,		// ��ȫ�����


	E_HangGetExp_StateLimit				=	23,
	E_HangGetExp_OutOfTime				=	24,
	E_HangGetExp_OutOfLevel				=	25,
	E_HangGetExp_OutOfVigour			=	26,

};

enum ERoleInitType
{
	ERIT_Null = -1,

	ERIT_Att				=	0,			// �����������
	ERIT_Skill				=	1,			// ���＼��
	ERIT_Item				=	2,			// ������Ʒ
	ERIT_ClientConfig		=	3,			// �ͻ�������
	ERIT_FrindAndEnemy		=	4,			// �����к��ѵ�ͬ����,�Լ�����Щ��У�������
	ERIT_CompleteQuest		=	5,			// �Ѿ���ɵ�����
	ERIT_IncompleteQuest	=	6,			// û����ɵ�����
	ERIT_Money				=	7,			// ��Ǯ
	ERIT_Reputation			=	8,			// ����
	ERIT_Guild				=	9,			// ����
	ERIT_MasterPrentice		=	10,			// ʦͽ
	ERIT_paimai				=   11,			// ����
	ERIT_bank				=   12,			// Ǯׯ
	ERIT_Other				=   13,			// ��������
	ERIT_Pet_Sns_info		=	14,			// ����sns
	ERIT_Achievement		=	15,			// �ɾ�
	ERIT_End,
};

enum EClassErrorCode
{
    ECEC_Success            =   E_Success,

    ECEC_NotUpToLevel       =   1,          // ��ҵȼ�����
    ECEC_IsNotBaseClass     =   2,          // ֻ���������ܽ���ְҵר��
    ECEC_LackOfNewclassItem =   3,          // ȱ��ְҵר��ƾ֤����
    ECEC_LackOfReclassItem  =   4,          // ȱ�ٸ���ר��ְҵim����
	ECEC_IsNotBaseClassEx	=	5,			// �Ѿ�ְ��Ӣ��ְҵ
	ECEC_ClassNotMatch		=	6,			// Ӣ��ְҵ��ר��ְҵ��ƥ��
	ECEC_ClassNotSet		=	7,			// δ��ְר��ְҵ�����ɽ���ְҵת��
	ECEC_NPCError			=	8,			// NPC��Ч

    ECEC_End,
};

// Ԫ��ֵ����
enum EVigourRewardCode
{
    EVRC_FirstLogin_not_enough  = 1, // �����Ի���ٵ�½����
    EVRC_FirstLogin_Reward      = 2, // ������һ�ε���Ϸ�����У���������X��Ԫ��ֵ�������ѷ��������䣬����ա�
	EVRC_Online_not_enough		= 3,
    EVRC_Online_Reward          = 4, // Ԫ��ֵ���ã�������������X��Ԫ��ֵ����Ӧ�õĽ����ѷ��������䣬�����
};

//-----------------------------------------------------------------------------
// ״̬�ı�
//-----------------------------------------------------------------------------
struct NET_SIS_set_state : public tag_net_message
{
	NET_SIS_set_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_state");
		dw_size = sizeof(NET_SIS_set_state);
	}
	DWORD		dw_role_id;
	EState		eState;
};

struct NET_SIS_unset_state : public tag_net_message
{
	NET_SIS_unset_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_unset_state");
		dw_size = sizeof(NET_SIS_unset_state);
	}
	DWORD		dw_role_id;
	EState		eState;
};
//-----------------------------------------------------------------------------
// ���״̬�ı�
//-----------------------------------------------------------------------------
struct NET_SIS_set_role_state : public tag_net_message
{
	NET_SIS_set_role_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_role_state");
		dw_size = sizeof(NET_SIS_set_role_state);
	}
	DWORD		dw_role_id;						// ��ɫID
	ERoleState	eState;							// ״̬��־
};

struct NET_SIS_unset_role_state : public tag_net_message
{
	NET_SIS_unset_role_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_unset_role_state");
		dw_size = sizeof(NET_SIS_unset_role_state);
	}
	DWORD		dw_role_id;						// ��ɫID
	ERoleState	eState;							// ״̬��־
};

struct NET_SIS_set_role_state_extend : public tag_net_message
{
	NET_SIS_set_role_state_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_role_state_extend");
		dw_size = sizeof(NET_SIS_set_role_state_extend);
	}
	ERoleStateEx	eState;							// ״̬��־
};

struct NET_SIS_unset_role_state_extend : public tag_net_message
{
	NET_SIS_unset_role_state_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_unset_role_state_extend");
		dw_size = sizeof(NET_SIS_unset_role_state_extend);
	}
	ERoleStateEx	eState;							// ״̬��־
};

//-----------------------------------------------------------------------------
// �����ʾ���øı�
//-----------------------------------------------------------------------------
// ����ʱװģʽ
struct NET_SIC_fashion : public tag_net_message
{
	NET_SIC_fashion()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_fashion");
		dw_size = sizeof(NET_SIC_fashion);
	}
	BOOL			bFashion;	// �Ƿ�ʹ��ʹװģʽ
};

// ��ǰ���
struct NET_SIS_avatar_equip : public tag_net_message
{
	NET_SIS_avatar_equip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_avatar_equip");
		dw_size = sizeof(NET_SIS_avatar_equip);
	}
	DWORD			dw_role_id;
	tagAvatarEquip	sAvatarEquip;
	BOOL			bFashion;	// �Ƿ�ʹ��ʹװģʽ
};

// ���ò�λ��ʾ����
struct NET_SIC_role_set_display : public tag_net_message
{
	NET_SIC_role_set_display()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_set_display");
		dw_size = sizeof(NET_SIC_role_set_display);
	}
	tagDisplaySet	sDisplaySet;
};

struct NET_SIS_role_set_display : public tag_net_message
{
	NET_SIS_role_set_display()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_set_display");
		dw_size = sizeof(NET_SIS_role_set_display);
	}
	DWORD			dw_role_id;
	tagDisplaySet	sDisplaySet;
};


//-----------------------------------------------------------------------------
// ��Ҹ������øı�
//-----------------------------------------------------------------------------
// �޸ı�����ҵĸ�������
struct NET_SIC_change_personal_setting : public tag_net_message
{
	NET_SIC_change_personal_setting()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_change_personal_setting");
		dw_size = sizeof(NET_SIC_change_personal_setting);
	}
	tagDWPlayerPersonalSet	PersonalSet;
};

struct NET_SIS_change_personal_setting : public tag_net_message
{
	NET_SIS_change_personal_setting()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_personal_setting");
		dw_size = sizeof(NET_SIS_change_personal_setting);
	}
	tagDWPlayerPersonalSet	PersonalSet;
};

//-----------------------------------------------------------------------------
// ��ȡ������ҳ�ʼ�ṹ
//-----------------------------------------------------------------------------
struct NET_SIC_get_role_init_state : public tag_net_message
{
	NET_SIC_get_role_init_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_role_init_state");
		dw_size = sizeof(NET_SIC_get_role_init_state);
	}
	ERoleInitType eType;					// �ͻ�����Ҫ�õ���������
};


//-----------------------------------------------------------------------------
// ���������ʼ����
//-----------------------------------------------------------------------------
struct NET_SIS_get_role_init_state_att : public tag_net_message
{
	NET_SIS_get_role_init_state_att()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_init_state_att");
		dw_size = sizeof(NET_SIS_get_role_init_state_att);
	}
	tagAvatarAtt	Avatar;							// ���
	tagAvatarEquip	AvatarEquip;					// װ�����
	tagDisplaySet	DisplaySet;						// �����ʾ����
	INT				nAtt[ERA_End];					// ��ǰ��������
	//INT				nAttPointAdd[X_ERA_ATTA_NUM];	// ���Ͷ�ŵ�����һ�������е�ֵ
	INT				nLevel;							// �ȼ�
	INT				nCurLevelExp;					// ��ǰ��������
	//INT				nCredit;						// ���ö�
	//INT				nIdentity;						// ���
	INT				nVIPPoint;						// ��Ա����
	DWORD			dwState;						// ״̬��־λ
	DWORD			n64RoleState;					// ��Ҷ���״̬��־λ -- ��㲥����Χ���
	DWORD			dwRoleStateEx;					// ��Ҷ���״̬��־λ -- ֻ���Լ�֪��
	ERolePKState	ePKState;						// PK״̬
	INT				iPKValue;						// PKֵ
	//DWORD			dwRebornMapID;					// �����ͼID
	//int				nRebornX;						// �����
	//int				nRebornY;						// �����
	//Vector3			vRebornPoint;					// �����
	DWORD			dwGuildID;						// ����id
	UINT16			u16ActTitleID[3];				// ��ǰ����ƺ�ID
	INT				nBuffNum;						// ״̬����
	//BOOL			bHasLeftMsg;					// ������
	EClassType      eClassType;                     // ר��ְҵ
	//EClassTypeEx    eClassTypeEx;                   // Ӣ��ְҵ(δ����)
	//DWORD			dwMasterID;						// ʦ��ID��
	//INT16			n16PetPocketNum;				// ����������
	//INT				nTotalMasterMoral;				// ��ʦ��ֵ
	INT				nKillNum;						// ɱ����
	//ECamp			e_role_camp;					// ��ɫ��Ӫ
	//ECamp			e_temp_role_camp;				// ��ɫ��ʱ��Ӫ
	//INT16			n16_exbag_step;					// ��������׶�
	//INT16			n16_exware_step;				// �ֿ�����׶�
	BYTE			byRoleHelp[ROLE_HELP_NUM];		// ��ɫ��������
	//INT				n_achievement_point;			// �ɾ͵���
	INT				n_total_recharge;				// ��ֵ�ۼ�
	//DWORD			dw_destory_equip_count;			// �ݻ�װ������
	INT32			n32CurExploits;					// ������
	//BOOL			bIsPurpureDec;
	INT32			nEquipRating;
	//INT32			nCoolDownReviveCD;			
	INT				nVIPLevel;
	DWORD			dwVIPDeadline;					//VIP��ֹ���� gx add 2013.9.3
	//INT16			n16PetXiulianSize;				// �������������
	INT				n_sign_level;					// ǩ���ȼ�
	DWORD			dwSpouseID;						//��żID
	DWORD			nMeiLi;							//����ֵ gx add
	INT32			nInstanceData;					//�����Ƿ����� gx add 2013.8.28
	DWORD			dwRedZuiFlag;					//�촽��� gx add 2013.10.25
	TCHAR			sz_role_name[X_SHORT_NAME];		// ����
	tagBuffMsgInfo	Buff[1];						// ״̬�б�
};


//-----------------------------------------------------------------------------
// �������＼���б�
//-----------------------------------------------------------------------------
struct NET_SIS_get_role_init_state_skill : public tag_net_message
{
	NET_SIS_get_role_init_state_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_init_state_skill");
		dw_size = sizeof(NET_SIS_get_role_init_state_skill);
	}
	INT					n_num;							// ���ܸ���
	tagSkillMsgInfo		Skill[1];						// �����б�
};

//-----------------------------------------------------------------------------
// �Ѿ���ɵ����� ������
//-----------------------------------------------------------------------------
struct NET_SIS_get_role_init_state_complete_quest : public tag_net_message
{
	NET_SIS_get_role_init_state_complete_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_init_state_complete_quest");
		dw_size = sizeof(NET_SIS_get_role_init_state_complete_quest);
	}
	INT					n_num;						// �������
	tagCompleteQuestMsgInfo completeQuest[1];
};

//-----------------------------------------------------------------------------
// ��ǰ����
//-----------------------------------------------------------------------------
struct NET_SIS_get_role_init_state_incomplete_quest : public tag_net_message
{
	NET_SIS_get_role_init_state_incomplete_quest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_init_state_incomplete_quest");
		dw_size = sizeof(NET_SIS_get_role_init_state_incomplete_quest);
	}
	INT					n_num;						// �������
	tagIncompleteQuestMsgInfo incompleteQuest[1];
};


//-----------------------------------------------------------------------------
// ������Ʒװ��
//-----------------------------------------------------------------------------
struct NET_SIS_get_role_init_state_item : public tag_net_message
{
	NET_SIS_get_role_init_state_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_init_state_item");
		dw_size = sizeof(NET_SIS_get_role_init_state_item);
	}
	INT16	n16SzBag;					// ������С
	INT16	n16SzRoleWare;				// �ֿ��С
	INT		n_num;						// ��Ʒװ������
	BYTE	byData[1];					// �����б�
};


//-----------------------------------------------------------------------------
// ��װ
//-----------------------------------------------------------------------------
struct NET_SIS_get_role_init_state_suit : public tag_net_message
{
	NET_SIS_get_role_init_state_suit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_init_state_suit");
		dw_size = sizeof(NET_SIS_get_role_init_state_suit);
	}
	INT		nSuitNum;
	BYTE	byData[1];					// tagSuitInit
};


//-----------------------------------------------------------------------------
// ������Ʒ��ȴʱ��
//-----------------------------------------------------------------------------
struct NET_SIS_get_role_init_state_itemcdtime : public tag_net_message
{
	NET_SIS_get_role_init_state_itemcdtime()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_init_state_itemcdtime");
		dw_size = sizeof(NET_SIS_get_role_init_state_itemcdtime);
	}
	INT		n_num;						// ��ȴʱ����Ʒ(TypeID)����
	BYTE	byData[1];					// tagCDTime
};

//-----------------------------------------------------------------------------
// ���н�Ǯ
//-----------------------------------------------------------------------------
struct NET_SIS_get_role_init_state_money : public tag_net_message
{
	NET_SIS_get_role_init_state_money()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_init_state_money");
		dw_size = sizeof(NET_SIS_get_role_init_state_money);
	}
	INT32	nBagYuanBao;
	INT64	n64BagSilver;
	INT64	n64BagBindSilver;
	INT64	n64WareSilver;
	INT32	nBaiBaoYuanBao;
	INT32	nExchangeVolume;
	//INT32	nCurClanCon[ECLT_NUM];
	INT32   n32Exploit;
};

//-----------------------------------------------------------------------------
// ��������
//-----------------------------------------------------------------------------
struct NET_SIS_get_role_init_state_reputation : public tag_net_message
{
	NET_SIS_get_role_init_state_reputation()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_init_state_reputation");
		dw_size = sizeof(NET_SIS_get_role_init_state_reputation);
	}
	INT		nReputation[ECLT_NUM];
	BYTE    nActiveCount[ECLT_NUM];
	BYTE    bisFame[ECLT_NUM];
};

//-----------------------------------------------------------------------------
// ���ڰ�����Ϣ��������Ϣ
//-----------------------------------------------------------------------------
struct NET_SIS_get_role_init_state_guild : public tag_net_message
{
	NET_SIS_get_role_init_state_guild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_init_state_guild");
		dw_size = sizeof(NET_SIS_get_role_init_state_guild);
	}
	tagGuildBase	sGuildBase;			// ���ɻ�������
	tagGuildMember	sGuildMember;		// ������Ϣ
};

//------------------------------------------------------------------------------
// ��ȡԶ����ҵ�ǰ����
//------------------------------------------------------------------------------
struct NET_SIC_get_remote_role_state : public tag_net_message
{
	NET_SIC_get_remote_role_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_remote_role_state");
		dw_size = sizeof(NET_SIC_get_remote_role_state);
	}
	INT		nRoleNum;
	DWORD	dw_role_id[1];	// ������Զ�����Ҳ������Զ�̹��һ�η������50��
};

//-------------------------------------------------------------------------------------------
// �ͻ���Զ�����ͬ��������Ϣ�ṹ
//-------------------------------------------------------------------------------------------
struct tagRemoteRoleData
{
	DWORD				dwID;						// ���ID
	INT					nLevel;						// �ȼ�
	FLOAT				fPos[3];					// λ��
	FLOAT				fFaceTo[3];					// ����
	DWORD				dwState;					// ״̬��־λ
	INT64				n64RoleState;				// ��ɫ����״̬��־λ
	ERolePKState		ePKState;					// PK״̬
	INT					iPKValue;					// PKֵ
	//BOOL				bIsPurpureDec;
	//BOOL				bIsGrayName;				// �Ƿ����
	DWORD				dwGuildID;					// ����id(INVALID_VALUE��ʾû�м������)
	DWORD				dwTeamID;					// ����id(INVALID_VALUE��ʾû�м������)
	//INT8				n8GuildPos;					// ����ְλ
	UINT16				u16CurActTitleID[3];		// ����ƺ�(INVALID_VALUE��ʾû�м���ƺ�)
	//BYTE				byStallLevel;				// ̯λģ�͵ȼ�
	//DWORD				dwMountPetID;				// ��˳���id
	//DWORD				dwMountPetTypeID;			// ��˳���typeid
	tagDisplaySet		sDisplaySet;				// װ�������ʾ����
	tagAvatarAtt		Avatar;						// ���
	tagAvatarEquip		AvatarEquip;				// װ�����
	INT					nAtt[ERRA_End];				// Զ����һ�������
	//tagRemoteOpenSet	sRemoteOpenSet;				// ��Զ����ҹ�����Ϣ����
    EClassType          eClassType;                 // ר��ְҵ
    //EClassTypeEx        eClassTypeEx;               // Ӣ��ְҵ
	//tagDWORDTime		dwChangeSymbolTime;			// ����־�ı�ʱ��
	//DWORD				dwSymbolValue;				// ����־
	//TCHAR				szText[2];					// �������

	DWORD				dwMountRideTypeID;			//���typeid
	BYTE				bySolidateLevel;			//ǿ���ȼ�

	//DWORD				dwMasterID;					//ʦ��ID
	//DWORD				dwCarryID;					

	//ECamp				e_role_camp;				// ��ɫ��Ӫ
	//ECamp				e_temp_role_camp;			// ��ɫ��ʱ��Ӫ

	//INT32				n32CurExploits;				// ս��
	BYTE				byLeader;					// �Ƿ�ӳ�
	DWORD				dwTargetID;					// Ŀ��ID
	DWORD				dwEquipRating;				// װ������
	//INT					n_god_level;				// ��
	INT					nBuffNum;					// ״̬����
	DWORD				dwCompracticePartner;		// ˫�޶��� gx add 2013.6.28
	INT					nVIPLevel;					//VIP�ȼ� gx add 2013.8.15
	DWORD				dwRedZuiFlag;				//�촽���
	tagBuffMsgInfo		Buff[1];					// ״̬�б�
};

struct NET_SIS_get_remote_role_state : public tag_net_message
{
	NET_SIS_get_remote_role_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_remote_role_state");
		dw_size = sizeof(NET_SIS_get_remote_role_state);
	}
	tagRemoteRoleData		RoleData;		// Զ����ҽṹ�����ܵ�����Ҳ���ɲ������ṹ
};

//---------------------------------------------------------------------
// Զ���������Խṹ
//---------------------------------------------------------------------
struct tagRemoteCreatureData
{
	DWORD			dwID;						// ����ID
	DWORD			dw_data_id;					// ����ID
	INT				nLevel;						// �ȼ�
	DWORD			dwState;					// ״̬��־λ
	FLOAT			fPos[3];					// λ��
	FLOAT			fFaceTo[3];					// ����
	INT				nAtt[ERRA_End];				// Զ����һ�������
	//DWORD			dwMapObjID;					// ��ͼ����ID
	//BOOL			bOpen;						// �ų�ʼ״̬
	DWORD			dwGuildID;					// �������ID
	DWORD			dwTaggedOwner;				//
	//BOOL			bCanBeAttack;				// �Ƿ�ɱ�����
	ECreatureType	eCreType;					// ����
	DWORD			dwTargetID;					// Ŀ��id
	INT				nBuffNum;					// ״̬����
	//TCHAR			szPlantRole[X_SHORT_NAME];	// ��ֲ������
	//DWORD			dwPlantYield;				// ��ֲ��ǰ����
	//DWORD			dwPlantMaxYield;			// ��ֲ������
	//DWORD			dwPlantTime;				// ��ֲʱ��
	BOOL			bDynamic;					// �Ƿ�̬����	
	tagBuffMsgInfo	Buff[1];					// ״̬�б�
};

struct NET_SIS_get_remote_creature_state : public tag_net_message
{
	NET_SIS_get_remote_creature_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_remote_creature_state");
		dw_size = sizeof(NET_SIS_get_remote_creature_state);
	}
	tagRemoteCreatureData	CreatureData;		// Զ������ṹ
};


//---------------------------------------------------------------------
// Զ�̳������Խṹ
//---------------------------------------------------------------------
struct tagRemotePetData
{
    DWORD           dw_role_id;                   // ���������Ľ�ɫid��Ϊ-1ʱ����������
	DWORD			dwID;						// ����ID
	DWORD			dwProtoID;					// ԭ��ID
	UPetState		uState;						// ��̬
	INT				nShape;						// ����
	INT				nColor;						// ��ɫ
	INT				nLevel;						// �ȼ�
	INT				nQuality;					// Ʒ��
};

struct NET_SIS_get_remote_pet_state : public tag_net_message
{
	NET_SIS_get_remote_pet_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_remote_pet_state");
		dw_size = sizeof(NET_SIS_get_remote_pet_state);
	}
	tagRemotePetData	PetData;
};

//---------------------------------------------------------------------
// Զ�̴�����Ϣ
//---------------------------------------------------------------------
struct NET_SIS_get_remote_state_error : public tag_net_message
{
	NET_SIS_get_remote_state_error()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_remote_state_error");
		dw_size = sizeof(*this);
	}
	INT n_num;
	DWORD dw_role_id[1];
};

//------------------------------------------------------------------------------
// ����������Ըı�
//------------------------------------------------------------------------------
struct NET_SIS_single_role_att_change : public tag_net_message
{
	NET_SIS_single_role_att_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_single_role_att_change");
		dw_size = sizeof(NET_SIS_single_role_att_change);
	}
	ERoleAttribute	eType;
	INT				nValue;
};


struct tagRoleAttValue
{
	ERoleAttribute	eType;
	INT				nValue;
};

struct NET_SIS_mutiple_role_att_change : public tag_net_message
{
	NET_SIS_mutiple_role_att_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mutiple_role_att_change");
		dw_size = sizeof(NET_SIS_mutiple_role_att_change);
	}
	INT				n_num;
	tagRoleAttValue	value[1];
};

//-------------------------------------------------------------------------------
// Զ������Լ�Զ���������Ըı�
//------------------------------------------------------------------------------
struct NET_SIS_single_remote_att_change : public tag_net_message
{
	NET_SIS_single_remote_att_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_single_remote_att_change");
		dw_size = sizeof(NET_SIS_single_remote_att_change);
	}
	DWORD			dw_role_id;
	ERemoteRoleAtt	eType;
	INT				nValue;
};


struct tagRemoteAttValue
{
	ERemoteRoleAtt	eType;
	INT				nValue;
};

struct NET_SIS_mutiple_remote_att_change : public tag_net_message
{
	NET_SIS_mutiple_remote_att_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mutiple_remote_att_change");
		dw_size = sizeof(NET_SIS_mutiple_remote_att_change);
	}
	DWORD				dw_role_id;
	INT					n_num;
	tagRemoteAttValue	value[1];
};


//--------------------------------------------------------------------------------
// ��Ҿ���ı�
//--------------------------------------------------------------------------------
struct NET_SIS_change_role_exp : public tag_net_message
{
	NET_SIS_change_role_exp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_role_exp");
		dw_size = sizeof(NET_SIS_change_role_exp);
	}
	INT		nExp;				// ��ǰ
	INT		nChange;			// �仯����
	BOOL	bKill;				// �Ƿ�ͨ����ɱ������
	INT     nSpecial;			//������;����ʶ��1�������ã��������������� gx add 2013.11.22
};

struct NET_SIS_role_exp_share_num : public tag_net_message
{
	NET_SIS_role_exp_share_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_exp_share_num");
		dw_size = sizeof(NET_SIS_role_exp_share_num);
	}
	INT		nShareNum;			// ��Ӿ��鹲������
};

//--------------------------------------------------------------------------------
// �������
//--------------------------------------------------------------------------------
struct NET_SIS_change_role_repute : public tag_net_message
{
	NET_SIS_change_role_repute()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_role_repute");
		dw_size = sizeof(NET_SIS_change_role_repute);
	}
	BYTE	byClanType;			// ����
	INT		nRepute;			// ��ǰ
	INT		nChange;			// �仯����
};

//-----------------------------------------------------------------------------
// ����״̬�ı�
//-----------------------------------------------------------------------------
struct NET_SIS_becomeframe : public tag_net_message
{
	NET_SIS_becomeframe()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_becomeframe");
		dw_size = sizeof(NET_SIS_becomeframe);
	}
	 BYTE    eClanType;
};

//-----------------------------------------------------------------------------
// Զ����Ұ�����Ϣ�仯
//-----------------------------------------------------------------------------
struct NET_SIS_remote_role_guild_info_change : public tag_net_message
{
	NET_SIS_remote_role_guild_info_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_remote_role_guild_info_change");
		dw_size = sizeof(NET_SIS_remote_role_guild_info_change);
	}
	DWORD	dw_role_id;
	DWORD	dwGuildID;					// ����id(INVALID_VALUE��ʾû�м������)
	INT8	n8GuildPos;					// ����ְλ
};


//-----------------------------------------------------------------------------
// �����䱦��������ı�
//-----------------------------------------------------------------------------
struct NET_SIS_change_treasure_act_count : public tag_net_message
{
	NET_SIS_change_treasure_act_count()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_treasure_act_count");
		dw_size = sizeof(NET_SIS_change_treasure_act_count);
	}
	BYTE    eClanType;
	BYTE    nActCount;
};

//-----------------------------------------------------------------------------
// ���幱�״ﵽ����
//-----------------------------------------------------------------------------
struct NET_SIS_gens_contribute_upper_limit : public tag_net_message
{
	NET_SIS_gens_contribute_upper_limit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_gens_contribute_upper_limit");
		dw_size = sizeof(NET_SIS_gens_contribute_upper_limit);
	}
	BYTE    eClanType;
};

//--------------------------------------------------------------------------------
// ��ҵȼ��ı�
//--------------------------------------------------------------------------------
struct NET_SIS_change_role_level : public tag_net_message
{
	NET_SIS_change_role_level()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_role_level");
		dw_size = sizeof(NET_SIS_change_role_level);
	}
	DWORD	dw_role_id;
	INT		nLevel;
	BOOL	bKill;				// �Ƿ���Ϊ��ɱ��������仯
};


//--------------------------------------------------------------------------------
// �������Ͷ��
//--------------------------------------------------------------------------------
struct NET_SIC_role_att_point : public tag_net_message
{
	NET_SIC_role_att_point()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_att_point");
		dw_size = sizeof(NET_SIC_role_att_point);
	}
	INT	nAttPointAdd[X_ERA_ATTA_NUM];
};

struct NET_SIS_role_att_point : public tag_net_message
{
	NET_SIS_role_att_point()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_att_point");
		dw_size = sizeof(NET_SIS_role_att_point);
	}
	DWORD dw_error_code;	// ������
};

//---------------------------------------------------------------------------------
// �������ϴ��
//---------------------------------------------------------------------------------
struct NET_SIC_clear_att_point : public tag_net_message
{
	NET_SIC_clear_att_point()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_clear_att_point");
		dw_size = sizeof(NET_SIC_clear_att_point);
	}
	INT64 n64ItemID;				// ϴ�����
};

struct NET_SIS_clear_att_point : public tag_net_message
{
	NET_SIS_clear_att_point()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_clear_att_point");
		dw_size = sizeof(NET_SIS_clear_att_point);
	}
	DWORD dw_error_code;				// ������
};

//---------------------------------------------------------------------------------
// ��Ҹ���һ������Ͷ��ֵ�ı�
//---------------------------------------------------------------------------------
struct NET_SIS_add_change_role_att_point : public tag_net_message
{
	NET_SIS_add_change_role_att_point()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_change_role_att_point");
		dw_size = sizeof(NET_SIS_add_change_role_att_point);
	}
	INT	nAttPointAdd[X_ERA_ATTA_NUM];
};


//---------------------------------------------------------------------------------
// ��Һ���
//---------------------------------------------------------------------------------
struct NET_SIS_send_friend_list : public tag_net_message
{
	NET_SIS_send_friend_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_friend_list");
		dw_size = sizeof(NET_SIS_send_friend_list);
	}
	INT				n_num;		  // ��������
	tagFriendInfo	FriendInfo[1];
};

//---------------------------------------------------------------------------------
// ��Һ�����
//---------------------------------------------------------------------------------
struct NET_SIS_send_black_list : public tag_net_message
{
	NET_SIS_send_black_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_black_list");
		dw_size = sizeof(NET_SIS_send_black_list);
	}
	INT				n_num;
	tagBlackInfo	BlackInfo[1];
};

//---------------------------------------------------------------------------------
// ��ҳ���
//---------------------------------------------------------------------------------
struct NET_SIS_send_enemy_list : public tag_net_message
{
	NET_SIS_send_enemy_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_enemy_list");
		dw_size = sizeof(NET_SIS_send_enemy_list);
	}
	INT				n_num;
	tagEnemyInfo	EnemyInfo[1];
};

//---------------------------------------------------------------------------------
// ��/����
//---------------------------------------------------------------------------------
struct NET_SIS_open_door : public tag_net_message
{
	NET_SIS_open_door()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_open_door");
		dw_size = sizeof(NET_SIS_open_door);
	}
	DWORD			dw_role_id;
};

struct NET_SIS_close_door : public tag_net_message
{
	NET_SIS_close_door()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_close_door");
		dw_size = sizeof(NET_SIS_close_door);
	}
	DWORD			dw_role_id;
};

//---------------------------------------------------------------------------------
// ���������ı�
//---------------------------------------------------------------------------------
struct NET_SIS_change_creuture_adscription : public tag_net_message
{
	NET_SIS_change_creuture_adscription()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_creuture_adscription");
		dw_size = sizeof(NET_SIS_change_creuture_adscription);
	}
	DWORD			dwCreatureID;
	DWORD			dwTaggedOwner;
};

//---------------------------------------------------------------------------------
// NPC�Ի�
//---------------------------------------------------------------------------------
struct NET_SIC_npc_talk : public tag_net_message
{
	NET_SIC_npc_talk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_npc_talk");
		dw_size = sizeof(NET_SIC_npc_talk);
	}
	DWORD			dwNPCId;
};


//----------------------------------------------------------------------------------
// �����������Է���װ��
//----------------------------------------------------------------------------------
struct NET_SIC_get_remote_role_equip_info : public tag_net_message
{
	NET_SIC_get_remote_role_equip_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_remote_role_equip_info");
		dw_size = sizeof(NET_SIC_get_remote_role_equip_info);
	}
	DWORD			dw_role_id;
};
//gx modify 2013.6.5
//����Զ����һ�����������
struct NET_SIS_get_remote_role_equip_info : public tag_net_message
{
	NET_SIS_get_remote_role_equip_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_remote_role_equip_info");
		dw_size = sizeof(NET_SIS_get_remote_role_equip_info);
	}
	DWORD			dw_role_id;
	INT				nEquipNum;					//װ������
	//add
	INT				nLevel;						//��ҵȼ�
	INT				nAtt[ERRA_End];				//Զ����һ�������
	DWORD			dwGuildID;					//�л�ID
	DWORD			dwSpouseID;					//��ż
	BYTE			byClass;					//ְҵ
	BYTE			bySex;						//�Ա�
	//gx add 2013.8.19
	INT32			nFightLi;					//ս����
	DWORD			dwMeili;					//����ֵ
	INT32			nRongyu;					//������
	INT				nPKvalue;					//pkֵ
	//end
	tagAvatarEquip	AvatarEquip;				//װ�����
	//end
	BYTE			byEquip[1];					//װ��
};

//gx add 2013.6.6
//�������Զ����Ҳ����ߣ����͸���Ϣ
struct NET_SIS_get_remote_role_equip_info_offline : public tag_net_message
{
	NET_SIS_get_remote_role_equip_info_offline()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_remote_role_equip_info_offline");
		dw_size = sizeof(NET_SIS_get_remote_role_equip_info_offline);
	}
};

//-----------------------------------------------------------------------------
// ��ʼ�һ�
//-----------------------------------------------------------------------------
struct NET_SIC_start_hang : public tag_net_message
{
	NET_SIC_start_hang()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_start_hang");
		dw_size = sizeof(NET_SIC_start_hang);
	}
	DWORD	dw_safe_code;
};

struct NET_SIS_start_hang : public tag_net_message
{
	NET_SIS_start_hang()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_start_hang");
		dw_size = sizeof(NET_SIS_start_hang);
	}
	DWORD dwError;
};

//-----------------------------------------------------------------------------
// ȡ���һ�
//-----------------------------------------------------------------------------
struct NET_SIC_cancel_hang : public tag_net_message
{
	NET_SIC_cancel_hang()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_hang");
		dw_size = sizeof(NET_SIC_cancel_hang);
	}
};

struct NET_SIS_cancel_hang : public tag_net_message
{
	NET_SIS_cancel_hang()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_hang");
		dw_size = sizeof(NET_SIS_cancel_hang);
	}
	DWORD dwError;
};

//-----------------------------------------------------------------------------
// ���߹ػ�����
//-----------------------------------------------------------------------------
struct NET_SIC_set_leave_line_hang : public tag_net_message
{
	NET_SIC_set_leave_line_hang()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_leave_line_hang");
		dw_size = sizeof(NET_SIC_set_leave_line_hang);
	}
	BOOL		bExp;				// �Ƿ�ʹ�þ��鵤
	BOOL		bBrotherhood;		// �Ƿ�ʹ��������
};

//-----------------------------------------------------------------------------
// ��ȡ���߾���
//-----------------------------------------------------------------------------
struct NET_SIC_get_leave_exp : public tag_net_message
{
	NET_SIC_get_leave_exp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_leave_exp");
		dw_size = sizeof(NET_SIC_get_leave_exp);
	}
};

struct NET_SIS_get_leave_exp : public tag_net_message
{
	NET_SIS_get_leave_exp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_leave_exp");
		dw_size = sizeof(NET_SIS_get_leave_exp);
	}
	INT			nExp;
	//INT			nBrotherHand;
	//INT16		n16HangNum;
};


//-----------------------------------------------------------------------------
// ��ȡ���߾���
//-----------------------------------------------------------------------------
struct NET_SIC_pickup_leave_exp : public tag_net_message
{
	NET_SIC_pickup_leave_exp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pickup_leave_exp");
		dw_size = sizeof(NET_SIC_pickup_leave_exp);
	}
	INT16		n16Type;
	INT16		nLeaveTime;//gx add
	//DWORD	dw_safe_code;
};

struct NET_SIS_pickup_leave_exp : public tag_net_message
{
	NET_SIS_pickup_leave_exp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pickup_leave_exp");
		dw_size = sizeof(NET_SIS_pickup_leave_exp);
	}
	INT			nExp;
	DWORD		dwError;
};

//-----------------------------------------------------------------------------
// ���߾���������ʾ
//-----------------------------------------------------------------------------
struct NET_SIS_leave_exp_clueon : public tag_net_message
{
	NET_SIS_leave_exp_clueon()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_leave_exp_clueon");
		dw_size = sizeof(NET_SIS_leave_exp_clueon);
	}
	INT			nExp;				// ���߾���
	//INT			nBrother;			// ��������
	//INT			nExpItem;			// ���ľ��鵤����
	//INT			nBrotherItem;		// ��������������
	INT		dw_logout_time;		// ����ʱ��
};

//-----------------------------------------------------------------------------
// ���¹һ������һ�
//-----------------------------------------------------------------------------
struct NET_SIS_change_hang_num : public tag_net_message
{
	NET_SIS_change_hang_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_hang_num");
		dw_size = sizeof(NET_SIS_change_hang_num);
	}
	INT16 n16HangNum;
};

//-----------------------------------------------------------------------------
// �����������仯
//-----------------------------------------------------------------------------
struct NET_SIC_pet_pocket_size_change : public tag_net_message
{
	NET_SIC_pet_pocket_size_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_pocket_size_change");
		dw_size = sizeof(NET_SIC_pet_pocket_size_change);
	}
};

struct NET_SIS_pet_pocket_size_change : public tag_net_message
{
	NET_SIS_pet_pocket_size_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_pocket_size_change");
		dw_size = sizeof(NET_SIS_pet_pocket_size_change);
	}
	DWORD dwErrorCode;
	INT16 n16NewSize;
};

//-----------------------------------------------------------------------------
// ��������
//-----------------------------------------------------------------------------
struct NET_SIS_role_help : public tag_net_message
{
	NET_SIS_role_help()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_help");
		dw_size = sizeof(NET_SIS_role_help);
	}
	BYTE byRoleHelp[ROLE_HELP_NUM];
};

//-----------------------------------------------------------------------------
// ÿ����������
//-----------------------------------------------------------------------------
struct NET_SIS_role_day_claer : public tag_net_message
{
	NET_SIS_role_day_claer()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_day_claer");
		dw_size = sizeof(NET_SIS_role_day_claer);
	}
	BYTE byDayClear[ROLE_DAY_CLEAR_NUM];
};

//-----------------------------------------------------------------------------
// �޸İ�������
//-----------------------------------------------------------------------------
struct NET_SIC_modify_role_help : public tag_net_message
{
	NET_SIC_modify_role_help()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_modify_role_help");
		dw_size = sizeof(NET_SIC_modify_role_help);
	}
	BYTE	byIndex;
};


//-----------------------------------------------------------------------------
// ����Ի�����
//-----------------------------------------------------------------------------
struct NET_SIS_role_talk : public tag_net_message
{
	NET_SIS_role_talk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_talk");
		dw_size = sizeof(NET_SIS_role_talk);
	}
	BYTE	byRoleTalk[TALK_DATA_NUM];
};

//-----------------------------------------------------------------------------
// �޸�����Ի�����
//-----------------------------------------------------------------------------
struct NET_SIC_modify_role_talk : public tag_net_message
{
	NET_SIC_modify_role_talk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_modify_role_talk");
		dw_size = sizeof(NET_SIC_modify_role_talk);
	}
	BYTE	byIndex;
	BYTE	byState;
};

//-----------------------------------------------------------------------------
// �����ݼ�����
//-----------------------------------------------------------------------------
struct NET_SIC_key_info : public tag_net_message
{
	NET_SIC_key_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_key_info");
		dw_size = sizeof(NET_SIC_key_info);
	}
};

struct NET_SIS_key_info : public tag_net_message
{
	NET_SIS_key_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_key_info");
		dw_size = sizeof(NET_SIS_key_info);
	}
	roleOnlineState stKeyInfo;
};

//-----------------------------------------------------------------------------
// �޸������ݼ�����
//-----------------------------------------------------------------------------
struct NET_SIC_modify_key_info : public tag_net_message
{
	NET_SIC_modify_key_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_modify_key_info");
		dw_size = sizeof(NET_SIC_modify_key_info);
	}
	roleOnlineState stKeyInfo;
};


//-----------------------------------------------------------------------------
// ��ʼ���ֽ�����ʱ
//-----------------------------------------------------------------------------
struct NET_SIC_begin_role_gift_time : public tag_net_message
{
	NET_SIC_begin_role_gift_time()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_begin_role_gift_time");
		dw_size = sizeof(NET_SIC_begin_role_gift_time);
	}
};

//-----------------------------------------------------------------------------
// �������ֽ�������
//-----------------------------------------------------------------------------
struct NET_SIS_new_role_gift : public tag_net_message
{
	NET_SIS_new_role_gift()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_new_role_gift");
		dw_size = sizeof(NET_SIS_new_role_gift);
	}
	DWORD		dwGiftID;				// ������ƷID
	DWORD		dwNumber;				// ������Ʒ����
	DWORD		dwLeavingTime;			// ʣ��ʱ��
	BOOL		bCal;					// �Ƿ�����
};

//-----------------------------------------------------------------------------
// �������ֽ���
//-----------------------------------------------------------------------------
struct NET_SIC_start_new_role_gift : public tag_net_message
{
	NET_SIC_start_new_role_gift()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_start_new_role_gift");
		dw_size = sizeof(NET_SIC_start_new_role_gift);
	}
};

//-----------------------------------------------------------------------------
// ��ȡ���ֽ���
//-----------------------------------------------------------------------------
struct NET_SIC_get_new_role_gift : public tag_net_message
{
	NET_SIC_get_new_role_gift()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_new_role_gift");
		dw_size = sizeof(NET_SIC_get_new_role_gift);
	}
};

struct NET_SIS_get_new_role_gift : public tag_net_message
{
	NET_SIS_get_new_role_gift()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_new_role_gift");
		dw_size = sizeof(NET_SIS_get_new_role_gift);
	}
	DWORD	 dwError;
};

//-----------------------------------------------------------------------------
// �ӳ�
//-----------------------------------------------------------------------------
struct NET_SIC_get_delay : public tag_net_message
{
	NET_SIC_get_delay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_delay");
		dw_size = sizeof(NET_SIC_get_delay);
	}
};

struct NET_SIS_get_delay : public tag_net_message
{
	NET_SIS_get_delay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_delay");
		dw_size = sizeof(NET_SIS_get_delay);
	}
};

//-----------------------------------------------------------------------------
// ������Ӫ�ı�
//-----------------------------------------------------------------------------
struct NET_SIS_change_role_camp : public tag_net_message
{
	NET_SIS_change_role_camp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_role_camp");
		dw_size = sizeof(NET_SIS_change_role_camp);
	}
	ECamp		e_role_camp;
	ECamp		e_temp_role_camp;
};

struct NET_SIS_vigour_reward : public tag_net_message
{
	NET_SIS_vigour_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_vigour_reward");
		dw_size = sizeof(NET_SIS_vigour_reward);
	}
	DWORD dwVigourCost;
	EVigourRewardCode e_code;
};

//Ŀ��ı�
struct NET_SIC_target_change : public tag_net_message
{
	NET_SIC_target_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_target_change");
		dw_size = sizeof(NET_SIC_target_change);
	}
	DWORD dw_target_id;
};

struct NET_SIS_target_change : public tag_net_message
{
	NET_SIS_target_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_target_change");
		dw_size = sizeof(NET_SIS_target_change);
	}

	DWORD dw_unit_id;
	DWORD dw_target_id;
};


struct NET_SIS_delay_send : public tag_net_message
{
	NET_SIS_delay_send()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delay_send");
		dw_size = sizeof(*this);
	}
	BYTE	by_delay;
};

// ֪ͨ��Ҫ�ı䳬������
struct NET_SIS_change_code : public tag_net_message
{
	NET_SIS_change_code()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_code");
		dw_size = sizeof(*this);
	}
};

// ���������Ƿ���֤ͨ��
struct NET_SIS_code_check_ok : public tag_net_message
{
	NET_SIS_code_check_ok()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_code_check_ok");
		dw_size = sizeof(*this);
	}

	BOOL	bSuccess;	// �Ƿ�ͨ��
};

// ������֤��������
struct NET_SIC_code_check_ok : public tag_net_message
{
	NET_SIC_code_check_ok()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_code_check_ok");
		dw_size = sizeof(*this);
	}
	DWORD		dw_safe_code;
};


// ����һ��þ���
struct NET_SIC_start_hang_get_exp : public tag_net_message
{
	NET_SIC_start_hang_get_exp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_start_hang_get_exp");
		dw_size = sizeof(*this);
	}
	INT type; // 1,kongfu;2,Comprehend;Dancing;
};

struct NET_SIS_start_hang_get_exp : public tag_net_message
{
	NET_SIS_start_hang_get_exp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_start_hang_get_exp");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
};

struct NET_SIS_start_hang_time_left : public tag_net_message
{
	NET_SIS_start_hang_time_left()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_start_hang_time_left");
		dw_size = sizeof(*this);
	}
	DWORD dwLeftMilliseconds;
};

// �˳�����һ��þ���
struct NET_SIC_stop_hang_get_exp : public tag_net_message
{
	NET_SIC_stop_hang_get_exp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_stop_hang_get_exp");
		dw_size = sizeof(*this);
	}
};

// ���ڿ�����ʾ����
struct NET_SIS_show_consume_reward_frame : public tag_net_message
{
	NET_SIS_show_consume_reward_frame()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_show_consume_reward_frame");
		dw_size = sizeof(*this);
	}
	INT reserved;
};

// ���ڿ�����ʾ����
struct NET_SIC_get_consume_reward : public tag_net_message
{
	NET_SIC_get_consume_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_consume_reward");
		dw_size = sizeof(*this);
	}
	INT index;
};
// ��һ��VIP����
struct NET_SIS_get_vip_level:public tag_net_message
{
	NET_SIS_get_vip_level()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_vip_level");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	BYTE	vip_level;
	DWORD	dw_VIPDeadLine;
};
// ���ʧȥVIP����
struct NET_SIS_unset_vip_level:public tag_net_message
{
	NET_SIS_unset_vip_level()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_unset_vip_level");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
};
// ��Ҹ���ͨ�����ݷ����仯 gx add 2013.8.28
struct NET_SIS_set_instance_data:public tag_net_message
{
	NET_SIS_set_instance_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_instance_data");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	INT32	nInstanceData;//������ͨ��������Ϣ
};
//����ǩ���ȼ� gx add 2013.10.28
struct NET_SIS_update_sign_level:public tag_net_message
{
	NET_SIS_update_sign_level()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_sign_level");
		dw_size = sizeof(*this);
	}
	INT nSignLevel;//ǩ���ȼ�
};
//���½ű����ݣ����庬��ͻ��˸������ gx add 2013.10.29
struct NET_SIS_update_role_script_data:public tag_net_message
{
	NET_SIS_update_role_script_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_role_script_data");
		dw_size = sizeof(*this);
	}
	DWORD dw_role_id;//��ɫID����ֹ�쳣
	INT nindex;//�ű���������ֵ
	DWORD dwvalue;//������ֵ��Ӧ�Ľű�����
};
#pragma pack(pop)
#endif
