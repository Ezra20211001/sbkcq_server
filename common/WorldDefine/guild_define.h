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
*	@file		guild_define.h
*	@author		mmz
*	@date		2010/10/11	initial
*	@version	0.0.1.0
*/


#pragma once
#include "protocol_common_errorcode.h"
#include "RoleDefine.h"
#include "ItemDefine.h"
#include <bitset>

#pragma pack(push, 1)

//-----------------------------------------------------------------------------
// ��
//-----------------------------------------------------------------------------

// ��ռ���������=�����ɵȼ�+3��/4
#define MGuildMaxHoldCityNum(by_guild_level)		((by_guild_level + 3) / 4)

// ����Ա��
#define MGuildMaxMember(by_guild_level)			(55 + 15 * (by_guild_level - 1))//gx modify 2013.9.6

// �ʽ�
#define MGuildMaxFund(by_guild_level)				(0)//??

// �ʲ�
#define MGuildMaxMaterial(by_guild_level)			(0)//??

// ÿ��ά������(ά������=1000��(���ɵȼ�^3)����2-���ɰ�����/10000��)
#define MGuildDailyCost(by_guild_level, nGuildPeace)	(1000.0f * by_guild_level * by_guild_level * by_guild_level * (2.0f - nGuildPeace / 10000.0f))

// ÿ�հ���������
#define MGuildPeaceCost(by_guild_level)			(by_guild_level * 10)

// ��ǰٺ»��׼
#define MGuildMemSalary()						(0)//??

// �� -- ����
#define MGuildPosTangZhongNum(by_guild_level)		(4 + 2 * (by_guild_level - 1))

// ���� -- ��Ӣ����
#define MGuildPosJingZhongNum(by_guild_level)		(5 + 2 * (by_guild_level - 1))

// ���� -- ��ͨ���� = ���������� - ��ǰ���ɳ�Ա����

// ���ɲֿ⵱ǰ�ռ�
#define MGuildWareCurSpace(by_guild_level)		((by_guild_level + 1) / 2 * 35)

// ÿ�հ��񷢲�������
#define MGuildAffairTimes(by_guild_level)			((by_guild_level + 2) / 3)

// ���ɵȼ���������
#define MGuildSkillLevel(byAcademyLevel)		(20 + (2 * byAcademyLevel))

// ���ɽ������ȼ�
#define MGuildMaxGradeLevel(by_guild_level)		(by_guild_level)

// ���ս��ս�ʽ�
#define GUILDWARMONERY 1000000
//-----------------------------------------------------------------------------
// ����
//-----------------------------------------------------------------------------

// �ͻ�����ʾ��Ա��Ϣҳһҳ��ʾ�ĳ�Ա����
const INT32 MAX_GUILDMEM_DISPLAY_PERPAGE	= 26;

// ������֯���Գ���
const INT32 MAX_GUILD_LEVEL			=	12;										// �������ȼ�	
const INT32 MAX_GUILD_HOLDCITY		=	MGuildMaxHoldCityNum(MAX_GUILD_LEVEL);	// �������Ͻ������
const INT32 MAX_GUILD_WARE_SPACE	=	MGuildWareCurSpace(MAX_GUILD_LEVEL);	// ���ɲֿ��������
const INT32 MAX_GUILD_NAME			=	20;										// ������������ֽ���
const INT32 MAX_GUILD_TENET			=	400;									// ������ּ����ֽ���
const INT32 MAX_GUILD_SIGN_NUM		=   12;										// �������ǩ��������
const INT32 LEAVE_GUILD_TIME_LIMIT	=   5*60/*24 * 3600*/;								// �뿪���ʱ������
const FLOAT MAX_SIGN_DISTANCE		=   20 * 50.0f;								// ���ǩ������
const INT32 MAX_GUILD_POS_NAME_LEN      =   12;									// ����ְλ��������ֽ���
const INT32 MAX_GUILD_UPLEVEL_TIME	= 5*60/*60 * 60*/;									// �������ʱ��
const INT32 MAX_ENEMY_NUM			= 10;										// ���ж԰������
const INT32 DECLARE_WAIT_TIME		= 30 * 60;									// ��ս�ȴ�ʱ��
const INT32 WAR_PREPARE_TIME		= 5 * 60;									// ս��׼��ʱ��
const INT32 WAR_TIME_LIMIT			= 2 * 60 * 60;									// ս������ʱ��
const INT32 MAX_UNLEAGUE_TIME		= 5*60/*24 * 3600*/;								// �������ʱ������
const INT32 MAX_GUILD_RELIVE_NUM	= 3;										// ��Ḵ����������
const INT32 MAX_GUILD_DELATE_END_TIME = 24 * 3600;								// ��������ʱ������
const INT32 MAX_GUILD_DELATE_TIME	  = 24 * 3600;								// ����ʱ��
const INT32 MAX_LOBBY_DIS			= 1200;										// ��������
const INT32 LOST_TRIPOD_TIME		= 24*60*60;									// �����ٴ�ռ�춦¯ʱ��

const INT32 MAX_GUILD_FUND				=	99999999;		// �����ʽ�
const INT32 MAX_GUILD_PROSPERITY		=   99999999;		// ���ɷ��ٶ�
const INT32 MAX_GUILD_MATERIAL			=	999999;			// �����ʲ�
const INT16 MAX_GUILD_PEACE				=	100;			// ���ɰ�����
const INT32 MAX_GUILD_REP				=	999999999;		// ��������
const INT32 MAX_GUILD_GROUP_PURCHASE	=	100000;			// �����Ź�ָ��
const INT32 MAX_MEMBER_DKP				=   999999999;		// ��ԱDKP


// ���ɸ������Գ���
const INT32 MAX_GUILDMEM_TOTALCONTRIB	=	999999999;	// �ۼư��ɹ���
const INT32 MAX_GUILDMEM_CURCONTRIB		=	999999999;	// ��ǰ���ɹ���
const INT32 MAX_GUILDMEM_EXP			=	999999999;	// ��������
const INT32 MAX_GUILDMEM_EXPLOIT		=	999999999;	// ���ɹ�ѫ


// ����ְλ��������
const INT32 MAX_GUILDPOS_BANGZHU		=	1;	// ����
const INT32 MAX_GUILDPOS_FUBANGZHU		=	1;	// ������
const INT32 MAX_GUILDPOS_HONGHUFA		=	1;	// ���»���
const INT32 MAX_GUILDPOS_ZIHUFA			=	1;	// ��������
const INT32 MAX_GUILDPOS_TANGZHU		=	1;	// ����
const INT32 MAX_GUILDPOS_XIANGZHU		=	1;	// ����


const INT MAX_UPGRADE_NEED_ITEM_TYPE	=	4;  // ������ʩ����������Ʒ����
const INT MIN_GUILD_UPGRADE_ROLE_LEVEL	=	20; // ������ʩ������ɫ�ȼ�����

const INT MAX_GUILD_UPGRADE_NUM			=	3;	// ÿ����Ὠ���������

// ���ɼ������ȼ�
const INT MAX_GUILD_SKILL_LEVEL			=	40;

// ������س���
const INT MAX_COMMODITY_CAPACITY		=	10;		// ����������������
const INT MAX_COFC_GOODS_NUM			=	5;		// �̻������Ʒ�������
const INT MAX_COMMODITY_GOOD_NUM		=	255;	// �̻����ѵ�����
const INT MAX_COMMERCE_RANK_INFO		=	10;		// �������а��б���
const INT MAX_COMMEND_PLAYER			=	3;		// �������̼ν�����

const INT32 MAX_GUILD_SYMBOL_LEN		= 300;

// ��������س���
const INT MAX_SYMBOL_BG_TYPE            =   8;      // �װ���ʽ����
const INT MAX_SYMBOL_BG_COLOR           =   20;     // �װ���ɫ����
const INT MAX_SYMBOL_SB_TYPE            =   8;      // ͼ����ʽ����
const INT MAX_SYMBOL_SB_COLOR           =   20;     // ͼ����ɫ����
const INT MAX_SYMBOL_SB_FONT			=	4;		// ͼ����������

const INT NPC_NAME_NUM					=   6;

const INT MAX_MATERIMAL_NUM				=	50;		// ÿ�������Ͼ�������
// ����ͼ����
const TCHAR szGuildMapName[20] = _T("m9");
const TCHAR szSBKHuangGong[20] = _T("d104");

const DWORD	LOBBY_USE_TIME = 10 * 3600;

// ��ֲ���ݸ���
const INT MAX_PLANT_NUMBER				= 50;		

// ����������
const INT MAX_DAOGA_NUM					= 16;

// ɳ�Ϳ˼����
const INT SBKTICK						= 60 * TICK_PER_SECOND;
//-----------------------------------------------------------------------------
// ö��
//-----------------------------------------------------------------------------

// ������
enum
{
	E_Guild_TangZhu_Full				= 1,	// ָ��ְλ�ϳ�Ա�ѵ�����
	E_Guild_XiangZhu_Full				= 2,	// ָ��ְλ�ϳ�Ա�ѵ�����
	E_Guild_TangMember_Full				= 3,	// ָ��ְλ�ϳ�Ա�ѵ�����
	E_Guild_Member_Full					= 4,	// ���ɳ�Ա�ѵ�����
	E_Guild_Pos_Full					= 5,	// ָ��ְλ�ϳ�Ա�ѵ�����

	E_Guild_Power_NotEnough				= 10,	// Ȩ�޲���
	E_Guild_CanNot_Leave				= 11,	// �����������
	E_Guild_CanNot_Demiss				= 12,	// ���ܹ���ְ
	E_Guild_RoleNotFind                 = 14,   // δ�ҵ��ƶ����      

	E_Guild_Join_AlreadyIn				= 20,	// �Ѽ������
	E_Guild_Join_LevelLimit				= 21,	// �ȼ�����
	E_Guild_Join_BeInvited				= 22,	// �Ѵ��ڱ�����״̬
	E_Guild_Join_NotBeInvited			= 23,	// ��δ���ڱ�����״̬
	E_Guild_Join_BeRefused				= 24,	// ���뱻�ܾ�

	E_Guild_Create_LevelLimit			= 25,	// �ȼ�����
	E_Guild_Create_NameExist			= 26,	// ����
	E_Guild_Create_Success				= 27,	// �����ɹ�
	E_Guild_Create_AlreadyIn			= 28,	// ���а���
	
	E_GuildSet_Tenet_Empty				= 30,	// ������ּΪ��

	E_Guild_Appoint_SamePos				= 35,	// ��ְǰ��ְλ��ͬ
	E_Guild_Appoint_SexLimit			= 36,	// �Ա�Ҫ�󲻷�

	E_Guild_NotExist					= 40,	// ָ�����ɲ�����
	E_Guild_MemberHasMore				= 41,	// ����������Ա(��Ա����>1)
	E_Guild_MemberNotIn					= 42,	// û���ҵ�ָ����Ա
	E_Guild_Level_Limit					= 43,	// ���ɵȼ�����
	E_Guild_State_Limit					= 44,	// ����״̬����
	E_Guild_Fund_NotEnough				= 45,	// �����ʽ���
	E_Guild_Material_NotEnough			= 46,	// �����ʲĲ���
	E_Guild_HoldCity_Limit				= 47,	// ����ռ���������

	E_GuildWare_NoChange				= 50,	// ���ɲֿ��ޱ仯,����Ҫ����
	E_GuildWare_Power_NotEnough			= 51,	// ���ɲֿ����Ȩ�޲���

	E_GuildUpgrade_Level_Limit			= 60,	// ��ʩ�ﵽ�ȼ�����
	E_GuildUpgrade_Item_NotEnough		= 61,	// �Ͻɵ���Ʒ������������Ҫ
	E_GuildUpgrade_Role_Level           = 62,   // ��ɫ�ȼ��������޷���������

	E_GuildAffair_Times_Limit			= 70,	// ���񷢲���������

	E_GuildSkill_NotResearch			= 80,	// ��ǰû�м����о�
	E_GuildSkill_Wrong_Item				= 81,	// �Ͻ���Ʒ�Ƿ�
	E_GuildSkill_Level_Limit			= 82,	// ���ܴﵽ�ȼ�����
	E_GuildSkill_NotExist				= 83,	// ���ܲ�����

	E_GuildMember_Contribution_Limit	= 90,	// ��Ա��������
	E_GuildMember_Level_Limit			= 91,	// ��Ա�ȼ�����

	E_GuildCommerce_Status_Error		= 100,	// ����״̬����
	E_GuildCommerce_Tael_NotEnough		= 101,	// ��������
	E_GuildCommerce_Commend_Error		= 102,	// �ν��Ѿ�������ر�

	E_GuildCommodity_NotEnough_Space	= 103,	// ���������ռ䲻��
	E_GuildCommodity_NotEnough_Tael		= 104,	// ��������
	E_GuildCommodity_ItemMaxHold		= 105,	// �̻��ﵽ��ӵ������

	E_CofC_NotExist						= 110,	// �̻�Ƿ�
	E_CofC_ItemNotFind					= 111,	// û���ҵ�ָ���̻�
	E_CofC_ItemCannotSell				= 112,	// ָ���̻����ɳ���
	E_CofC_ItemNotEnough				= 113,	// �̻���������
	E_CofC_HoldCity_Limit				= 114,	// û��ռ��ָ������

	E_Guild_Already_Formal				= 115,	// �Ѿ�����ʽ����
	E_Guild_Distance_NotCan				= 116,	// ǩ�����벻�Ϸ�
	E_Guild_LeaveTime_Limit				= 117,	// �뿪����ʱ�䲻�Ϸ�
	E_Guild_SignIn_BlackList			= 118,	// ������ǩ���ߵĺ�������
	E_Guild_Sign_Level_NotEnough		= 119,	// ǩ���ߵȼ�����
	E_Guild_Own_Signing					= 120,	// �Լ�����ǩ����
	E_Guild_Other_Signing				= 121,	// �Է�����ǩ����
	E_Guild_SignNum_NotEnough			= 122,	// ǩ����������
	E_Guild_Bag_Full					= 123,  // ��������
	E_Guild_Sign_Item_Not				= 124,  // ǩ����Ʒ������
	E_Guild_Enemy_Limit					= 125,  // ��г���
	E_Guild_NoIs_Enemy					= 126,  // ���ǵ���
	E_Guild_WarState_Limit			    = 127,  // ���ս״̬����
	E_Guild_Declare_Level_Limit			= 128,  // ��ս�ȼ�����
	E_Guild_Declare_Time_Limit			= 129,	// ��սʱ������
	E_Guild_NoExist						= 130,  // ��᲻����
	E_Guild_Leader_Not_Line				= 131,	// ����������
	E_Guild_NotEnough_peace				= 132,	// �����Է������Ȳ���
	E_Guild_Have_League					= 133,	// �Է���ս
	E_Guild_League_Not_Exist			= 134,  // ��ս
	E_Guild_No_League					= 135,  // �������˰��
	E_Guild_Prosperity_NotEnouth		= 136,	// ���ٶȲ���
	E_Guild_SignRole_HaveExist			= 137,	// ǩ�����Ѿ�����

	E_Guild_Is_Leader					= 138,	// �Լ��ǰ������ܱ�����
	E_Guild_State_Delate				= 139,  // ������ڵ�����
	E_Guild_Delate_Time_Limit			= 140,	// ����ʱ������
	E_Guild_Delate_Item_NoExists		= 141,	// ������Ʒ������
	E_Guild_State_NoDelate				= 142,	// ���û�ڵ�����
	E_Guild_Have_Ballot					= 143,	// �Ѿ�Ͷ��Ʊ
	E_Guild_Kick_DelateRole				= 144,	// �����߳�����������
	E_Guild_ChangePos_DelateRole		= 145,	// ���ܸı䵯��������ְλ
	E_Guild_AcceptWar_Limit				= 146,	// Ӧս����

	E_Guild_ChangeDKP_Limit				= 147,	// �޸�DKP����

	E_Guild_SignRole_Full				= 148,	// ǩ����������
	E_Guild_AlreadyIs_Enemy				= 149,	// �Ѿ��ǵж԰��
	E_Guild_UpLevel						= 150,	// ������
	E_Guild_Enemy_UpLevel				= 151,	// �ж԰��������
	E_Guild_Waring_NotCan_UpLevel		= 152,	// ս�����̲�������
	E_Guild_Enemy_Level_Limit			= 153,  // �ж԰��ȼ�����
	E_Guild_TargetLeague_Time_Limit		= 154,	// ���������˰��ʱ��
	E_Guild_Grade_Dead					= 155,	// ��Ὠ��δ�޸�
	E_Guild_Enemy_Grade_Dead			= 156,	// �ж԰�Ὠ��δ�޸�
	E_Guild_League_NoCan_Enemy			= 157,	// ͬ�˰�᲻�����õж�
	E_Guild_Enemy_NoCan_League			= 158,	// �ж԰�᲻��ͬ��
	E_Guild_Grade_UpLevel				= 159,	// ��Ὠ��������

	E_Guild_recruit_have_exist			= 160,	// �Ѿ��ڰ����ļ����
	E_Guild_recruit_nohave_exist		= 161,	// ���ڰ����ļ����

	E_Guild_Practice_Already_Start		= 162,	// ��������Ѿ�����
	E_Guild_Practiec_Num_Limit			= 163,	// ���������������

	E_Guild_War_Not_Relay				= 164,	// ���սδ��װ���׶�
	E_Guild_War_Not_Accept				= 165,	// ûȨ�޲μ�
	E_Guild_War_Not_Leader				= 166,	// ���ǰ���,�����޸�
	
	E_Guild_War_num_max					= 167,  // ����������

	E_Guild_war_Num_Cant				= 168,	// ���ܸĳ������
	E_Guild_war_Cant_Again				= 169,	// �Ѿ���ð����ս����

	E_Guild_Role_Silver_Not_Enough		= 180,	// ��Ǯ����
	E_Guild_Role_Silver_Full			= 181,	// �ʽ�����
	E_Guild_BaoMin_Full					= 182,  // �������������ܴ����ѱ�������

	E_Guild_Material_Not_time			= 190,	// �����������
	E_Guild_Material_Not_Enough			= 191,	// ��Ʒ��������	
	E_Guild_Material_Not_Money			= 192,	// ��Ǯ����	
};	

// ״̬
enum EGuildSpecState
{
	EGDSS_NULL				= 0x0000,
	EGDSS_Shortage			= 0x0001,			// �ʽ��ȱ
	EGDSS_Distress			= 0x0002,			// ƶ��
	EGDSS_Chaos				= 0x0004,			// ����
	EGDSS_Warfare			= 0x0008,			// ��ս
	EGDSS_Primacy			= 0x0010,			// ����
	EGDSS_Refulgence		= 0x0020,			// �Ի�
	EGDSS_UpLevel			= 0x0040,			// ����
	EGDSS_Delate			= 0x0080,			// ����
	EGDSS_DelateEnd			= 0x0100,			// ��������

	EGDSS_End				= 0xffff
};

// ����ս״̬
enum EGuildWarState
{
	EGWS_NULL               = 0,		
	EGWS_Declare			= 1,			// ��ս
	EGWS_BeDeclare			= 2,			// ����ս
	EGWS_Prepare			= 3,			// ׼��
	EGWS_WAR_relay			= 4,			// ׼����ս
	EGWS_WAR				= 5,			// ��ս
};

// ְλ
enum EGuildMemberPos
{
	EGMP_Null			= -1,
	EGMP_Start			= 0,

	EGMP_BangZhong		= 0,	//��ͨ���ڣ���ͨ���ڵ�enumֵ������0	
	EGMP_BangZhu		= 1,	//�峤  ,�峤��enumֵ������1������client��Խ��
	EGMP_FuBangZhu		= 2,	//���峤 
	EGMP_OFFICER_1      = 3,    //��Ա
	EGMP_OFFICER_2      = 4,    
	EGMP_OFFICER_3      = 5,    
	EGMP_OFFICER_4      = 6,    
	EGMP_OFFICER_5      = 7,    
	EGMP_OFFICER_6      = 8,    
	EGMP_OFFICER_7      = 9,   

	EGMP_End			= EGMP_OFFICER_7,

	EGMP_Num
};

const INT32 X_GUILD_POS_NUM		= EGMP_End - EGMP_Start + 1;

// ��
enum EGuildTangType
{
	EGTT_Null			= -1,
	EGTT_Start			= 0,

	EGTT_QingLong		= 0,	// ������
	EGTT_ZhuQue			= 1,	// ��ȸ��
	EGTT_BaiHu			= 2,	// �׻���
	EGTT_XuanWu			= 3,	// ������

	EGTT_End			= 3,
};

const INT32 X_GUILD_TANG_NUM	= EGTT_End - EGTT_Start + 1;

// ����ְλ
enum ETangMemberPos
{
	ETMP_Null			= -1,

	ETMP_TangZhu		= 0,	// ����
	ETMP_XiangZhu		= 1,	// ����
	ETMP_BangZhong		= 2,	// ����
};

// DKP
enum EDKP
{
	EDKP_KillEnemy			= 0,			//ɱ���а��Ա
	EDKP_CrossInst			= 1,			//ͨ�ذ�ḱ��
	EDKP_KillBoss			= 2,			//ɱ��Boss
	EDKP_Beachhead			= 3,			//�ݻپݵ�
	EDKP_GuildQuest			= 4,			//��ɰ������
	EDKP_HelpQuest			= 5,			//��ɷ�������

	EDKP_END				= 5,
};


// ս������
enum EWarHistoryTyep
{
	EWHT_Offensive_Win		=	0,		// ������ʤ��
	EWHT_Offensive_Fail		=	1,		// ������ʧ��
	EWHT_Defent_Win			=	2,		// ����ʤ��
	EWHT_Defent_Fail		=	3,		// ������ʧ��
	EWHT_DUIFANG_JUJUE		=	4,		// �Է��ܾ�
	EWHT_JUJUE				=	5,		// �ҷ��ܾ�
};
//-----------------------------------------------------------------------------
// ö�ٺϷ��Լ��໥��ת������
//-----------------------------------------------------------------------------

static BOOL IsGuildPosValid(EGuildMemberPos ePos)
{
	return (ePos >= EGMP_Start && ePos <= EGMP_End);
}

//enum EGuildMemberAtt
//{
//	EGMA_Start				= 0,
//
//	EGMA_TotalContrib		= 0,	//�ۼư��ɹ���
//	EGMA_Contribution		= 1,	//��ǰ���ɹ���
//	EGMA_Exploit			= 2,	//��ǰ���ɹ�ѫ
//	EGMA_Salary				= 3,	//��ǰٺ»��׼
//
//	EGMA_End				= 3,
//};
//
//const INT32 X_GUILD_MEMBER_ATT_NUM		= EGMA_End - EGMA_Start + 1;

//-----------------------------------------------------------------------------
// �ṹ
//-----------------------------------------------------------------------------
struct tagGuildBase
{
	DWORD			dwID;								//����ID -- ��ֵ�ð�������CRC32ֵ
	DWORD			dwFounderNameID;					//���ɴ�ʼ������ID
	DWORD			dwLeaderRoleID;						//���ɰ�����ɫID
	DWORD			dwSpecState;						//���ɵ�ǰ����״̬
	BYTE			byLevel;							//���ɵ�ǰ�ȼ�
	BYTE			byHoldCity[MAX_GUILD_HOLDCITY];		//���ɵ�ǰϽ�����б�ţ���������ɵȼ��ı䣬��Ҫ���¿����ڴ��������

	INT32			nApplyLevel;						//����ȼ�
	INT32			nFund;								//���ɵ�ǰ�ʽ�
	INT32			nMaterial;							//���ɵ�ǰ����
	INT32			nReputation;						//���ɵ�ǰ����
	INT32			nGroupPurchase;						//�����Ź�ָ��
	INT16			n16Peace;							//���ɵ�ǰ������
	INT16			n16MemberNum;						//���ɵ�ǰ��Ա����	
	INT16			n16Rank;							//���ɵ�ǰ����
	BYTE			byMinJoinLevel;						//��ͼ���ȼ�
	BYTE			byAffairRemainTimes;				//��������ʣ�෢������
	BOOL			bCommendation;						//�������̼ν�״̬
	INT32			nDailyCost;							//����ÿ��ά������
	INT32			nProsperity;						//���ɷ��ٶ�

	BOOL			bFormal;							//�Ƿ���ʽ����
	BYTE			bySignatoryNum;						//ǩ������
	DWORD			dwSignRoleID[MAX_GUILD_SIGN_NUM];	//����ǩ����
	tagDWORDTime	dwCreateTime;						//��������ʱ��

	tagDWORDTime	dwMianzhanTime;						//��ս��ʼʱ��
	tagDWORDTime	dwJujueTime;						//�ܾ���սʱ��

	////tagDWORDTime	dwChangeSymbolTime;					// ����־����ʱ��

	TCHAR           szPosName[X_GUILD_POS_NUM][MAX_GUILD_POS_NAME_LEN];   //����ְλ����
	DWORD           dwPosPower[X_GUILD_POS_NUM];                          //����ְλȨ��

	DWORD			dwEnemyID[MAX_ENEMY_NUM];							  // �ж԰��

	DWORD			dwLeagueID;											  // ͬ�˰��

	tagDWORDTime	dwUnLeagueBeginTime;								  // ���ͬ����ʼʱ��

	INT16			n16DKP[EDKP_END];									 // DKP

	BOOL			bSignUpAttact;											// �Ƿ����μӹ���ս

	DWORD			dwValue;											// ����־ֵ
	TCHAR			szText[1];												// �������

	INT32			n32ScriptData[64];									// ���ű�����	

	INT				n_family_name[NPC_NAME_NUM];										// npc��
	INT				n_name[NPC_NAME_NUM];												// npc��
	
	BOOL			b_hasOpenServerReceive;								// �Ƿ���ȡ�����᳤����
	//BOOL			bDaogao[MAX_DAOGA_NUM];								//������

	tagGuildBase()	{ ZeroMemory(this, sizeof(*this)); };
};

// ���ɳ�Ա
struct tagGuildMember
{
	DWORD			dw_role_id;						//���ɳ�Ա��ɫID
	EGuildMemberPos	eGuildPos;						//��ɫ����ְλ

	INT32			nTotalContribution;				//�ۼư��ɹ���
	INT32			nContribution;					//��ǰ���ɹ���
	INT32			nExploit;						//��ǰ���ɹ�ѫ
	INT32			nSalary;						//��ǰٺ»��׼

	BOOL			bUseGuildWare;					//ʹ�ð��ɲֿ�Ȩ��

	BOOL			bBallot;						// �Ƿ��Ѿ���ȡ���ǽ���
	
	BOOL			bWar;							// �Ƿ�μӰ�ս

	INT32			nDKP;							// DKP

	tagDWORDTime	dwJoinTime;						// ���ʱ��
	
	INT32			nTotalFund;						// �ʽ���

	tagGuildMember() {}
	
	tagGuildMember(DWORD dw_role_id, EGuildMemberPos ePos, DWORD dwJoinTime = 0,
					INT32 nTotalContrib = 0, INT32 nContrib = 0, 
					INT32 nExploit = 0, INT32 nSalary = 0, BOOL bUseGuildWare = FALSE,
					BOOL bBallot = TRUE, BOOL bWar = FALSE, INT32 nDKP = 0, INT32 nTotalFund = 0)
	{
		assert(::IsGuildPosValid(ePos));

		this->dw_role_id				= dw_role_id;
		this->eGuildPos				= ePos;

		this->nTotalContribution	= nTotalContrib;
		this->nContribution			= nContrib;
		this->nExploit				= nExploit;
		this->nSalary				= nSalary;

		this->bUseGuildWare			= bUseGuildWare;

		this->bBallot				= bBallot;
		
		this->bWar					= bWar;

		this->nDKP					= nDKP;

		this->dwJoinTime			= dwJoinTime;
		this->nTotalFund			= nTotalFund;
	}

	tagGuildMember(const tagGuildMember& sGuildMember)
	{
		assert(::IsGuildPosValid(sGuildMember.eGuildPos));

		this->dw_role_id				= sGuildMember.dw_role_id;
		this->eGuildPos				= sGuildMember.eGuildPos;

		this->nTotalContribution	= sGuildMember.nTotalContribution;
		this->nContribution			= sGuildMember.nContribution;
		this->nExploit				= sGuildMember.nExploit;
		this->nSalary				= sGuildMember.nSalary;

		this->bUseGuildWare			= sGuildMember.bUseGuildWare;

		this->nDKP					= sGuildMember.nDKP;

		this->dwJoinTime			= sGuildMember.dwJoinTime;

		this->nTotalFund			= sGuildMember.nTotalFund;
	}
};

// ��ɫһ����Ϣ
struct tagRoleCommon
{
	INT16			n16RoleLevel;					//��ǰ��ҵȼ�
	BYTE			byRoleSex;						//��ǰ����Ա�
	bool			bOnline;						//��ǰ�Ƿ�����
	EClassType		eRoleClass;						//��ǰ���ְҵ
	DWORD			dwOfflineTime;					//��ǰ����ʱ��
	INT32			nKnowledge;						//��ǰ��Ұ�������
};


// ���ɳ�Ա��Ϣ
struct tagGuildMemInfo
{
	DWORD		dw_role_id;			// ��Ա����
	INT8		n8GuildPos;			// ��Աְλ
	BYTE		byLevel;			// ��Ա�ȼ�
	BYTE		bySex;				// ��Ա�Ա�
	BYTE		byClass;			// ��Աְҵ
	INT32		nCurContrib;		// ��Ա��ǰ���ɹ���
	INT32		nDKP;				// ��ԱDKP
	DWORD		dwTimeLastLogout;	// ��Ա�������ʱ��
	bool		bOnline;			// �Ƿ�����
	tagDWORDTime	dwJoinTime;		// ������ʱ��
	DWORD		dwMapID;			// ��ͼID
	bool		bInWar;				// �Ƿ�μӰ�ս
	INT32		n32_Rating;			// װ��������
	INT32		nTotalFund;			// �ʽ��ܹ���
};

// ���ɳ�Ա��Ϣ��չ
struct tagGuildMemInfoEx
{
	// ���Ի�ͷ��ͬ���������е�ͷ�� -- �����������Ϣ
	INT32		nTotalContrib;		// �ۼƹ��ף���ɫ�ܰ��ɹ���
	INT32		nExploit;			// ���ɹ�ѫ
	INT32		nKnowledge;			// ��������: �����߽�ɫΪ-1
};


struct tagGuildMemberClient
{
	BOOL				bGetInfo;		// �Ƿ��Ի�ȡ��չ��Ϣ
	tagGuildMemInfoEx	sInfoEx;		// ��չ��Ϣ
	tagGuildMemInfo		sInfo;			// ��ͨ��Ϣ

	tagGuildMemberClient()
	{
		ZeroMemory(this, sizeof(tagGuildMemberClient));
	}
	tagGuildMemberClient(const tagGuildMemInfo& sMemInfo)
	{
		memcpy(&sInfo, &sMemInfo, sizeof(tagGuildMemInfo));
		ZeroMemory(&sInfoEx, sizeof(tagGuildMemInfoEx));
		bGetInfo = FALSE;
	}
	VOID Modify(const tagGuildMemInfoEx& sMemInfoEx)
	{
		memcpy(&sInfoEx, &sMemInfoEx, sizeof(tagGuildMemInfoEx));
		bGetInfo = TRUE;
	}
	VOID Modify(const tagGuildMemInfo& sMemInfo, const tagGuildMemInfoEx& sMemInfoEx)
	{
		memcpy(&sInfo, &sMemInfo, sizeof(tagGuildMemInfo));
		memcpy(&sInfoEx, &sMemInfoEx, sizeof(tagGuildMemInfoEx));
		bGetInfo = TRUE;
	}
};

//-----------------------------------------------------------------------------
// �ṹ -- ����Ȩ�ޣ����캯����ʼ��Ϊ0��Ĭ������NullObject(�������˼�guild_mgr.h)
//-----------------------------------------------------------------------------
// ����ְ��
struct tagGuildPower
{
	DWORD	bDismissGuild		: 1,		// ��ɢ����
			bInviteJoin			: 1,		// �����Ա����
			bTurnoverLeader		: 1,		// �ƽ�����
			bLeaveGuild			: 1,		// �뿪����
			bDemissPostion		: 1,		// ��ȥ����ְ��
			bModifyTenet		: 1,		// �޸���ּ
			bModifySgin			: 1,		// �޸ı�־
			bWareRights		    : 1,		// ����ֿ����Ȩ��
			bSetWareRights		: 1,		// ���ð��ɲֿ����Ȩ��
			bUpgrade			: 1,		// ������ʩ����
			bCommerce			: 1,		// ��������
			bSetCommend			: 1,		// �������̼ν�״̬
			bAffair				: 1,		// �������񷢲�
			bSetSkill			: 1,		// ���ð�����������
			bAdvSkill			: 1,		// ���ɼ��ܶ�������
			bModifyPosName		: 1,		// �޸ļ���ְλ����
			bModifyPosPower		: 1,		// �޸ļ���ְλȨ��
			bKickMember         : 1,        // ��������Ա   
			bAppointMember      : 1,        // ���������Ա    
			bRecvMessage		: 1,		// ���հ��ɷ���
			bSendMessage		: 1,		// ���ɷ���
			bSendMail			: 1,		// �����ʼ�
			bLevelUp			: 1,		// �������
		    bDeclareWar         : 1,        // ������ս
			bAcceptWar			: 1,        // ������ս
			bModifyDKP			: 1,        // �޸�DKP
			bUnSay				: 1,		// �������
			bLeague				: 1,		// ������¯
			bUnLeague			: 1,		// ���ͬ��
			bEnemy				: 1,		// �趨�ж԰���
			bWar				: 1;		// �μӰ��ս

	tagGuildPower()
	{
		ZeroMemory(this, sizeof(*this));
	}
};

//-----------------------------------------------------------------------------
// �ṹ -- ��������
//-----------------------------------------------------------------------------
struct tagGuildCfg
{
	// ����&������͵ȼ�
	INT32		nCreateRoleMinLevel;
	INT32		nJoinRoleMinLevel;
	
	// ǩ�������С�ȼ�
	INT32		nSignRoleMinLevel;

	// ���������Ǯ
	INT32		nGoldCreateNeeded;

	// �����ս����Ľ�Ǯ
	INT32		nGoldGuildWarNeeded;

	// ����������
	BYTE		byGuildLevelBegin;
	BYTE		byDummy;
	INT16		n16GuildPeaceBegin;
	INT32		nGuildRepBegin;
	INT32		nGuildFundBegin;
	INT32		nGuildProsperityBegin;
	INT32		nGuildMaterialBegin;
	INT32		nGuildGroupPurchaseBegin;
	INT			nGuildMinNpcNameNum;
	INT			nGuildMaxNpcNameNum;
};


// ���ɲֿ��������
enum EGuildWareUpdate
{
	EGWU_Null			= -1,

	EGWU_Change			= 0,	// ��Ʒ���
	EGWU_Delete			= 1,	// ��Ʒ��ʧ

	EGWU_End
};

//-----------------------------------------------------------------------------
// �ṹ -- ���ɲֿ���µ�λ
//-----------------------------------------------------------------------------
struct tagGuildWareUpdate
{
	EGuildWareUpdate	eType;
	INT16				nIndex;
	BYTE				byData[1];

	tagGuildWareUpdate()
	{
		ZeroMemory(this, sizeof(*this));
		eType = EGWU_Null;
	}

	INT Size()
	{
		INT nSize = sizeof(EGuildWareUpdate) + sizeof(INT16);

		switch (eType)
		{
		case EGWU_Change:
			{
				// �ϲ㱣֤byDataֵ��Ч
				tagItem* pItem = (tagItem*)byData;
				if (MIsEquipment(pItem->dw_data_id))
				{
					nSize += sizeof(tagEquip);
				}
				else
				{
					nSize += sizeof(tagItem);
				}
			}
			break;

		case EGWU_Delete:
			break;

		default:
			nSize = 0;
			break;
		}

		return nSize;
	}
};

//-----------------------------------------------------------------------------
// �ṹ -- ���ɲֿ�Ȩ���б�λ
//-----------------------------------------------------------------------------
struct tagGuildWarePri 
{
	DWORD	dw_role_id;
	BOOL	bCanUse;
};

//-----------------------------------------------------------------------------
// ������ʩ����
//-----------------------------------------------------------------------------
enum EFacilitiesType
{
	EFT_Null		= -1,

	EFT_Lobby		= 0,		// ������
	EFT_Bank		= 1,		// ������
	EFT_Leechdom	= 2,		// ����̵�
	EFT_Factory		= 3,		// ��Ṥ��
	EFT_Maidan		= 4,		// ���������
	EFT_Holiness	= 5,		// ���ʥ�޾�	

	EFT_End
};

const INT MAX_GUILD_FACILITIES_TYPE = EFT_End - EFT_Null - 1;

//-----------------------------------------------------------------------------
// �ṹ -- ������ʩ��Ϣ
//-----------------------------------------------------------------------------
struct tagGuildFacilitiesInfo
{
	EFacilitiesType	eType;
	INT16	nProgress;
	INT16	nFulfill;
	DWORD	dwItemID[MAX_UPGRADE_NEED_ITEM_TYPE];
	INT32	nNeedNum[MAX_UPGRADE_NEED_ITEM_TYPE];
	INT32	nNeedFund;
	INT32	nMaterial;
	BYTE	byLevel;
	BYTE    byMaxLevel;
	tagDWORDTime dwBeginUpTime;
	BOOL	bUpLevel;
	DWORD	nUpLevelLimit;
	INT32	nDecProsperity;
	INT32	nDayDecProsperity;
	DWORD   dwFacilitiesID[MAX_GUILD_UPGRADE_NUM];
	BOOL	bDead;
	tagDWORDTime	dwDeadBeginTime;
	DWORD	dwReliveTimeLimit;
	BYTE	byUseType;			// 0 ��ʹ�� 1 ʹ����
	BYTE	byUseNum;
	tagDWORDTime	dwUseTime;
	BYTE	byStep;

	tagGuildFacilitiesInfo()
	{
		ZeroMemory(this, sizeof(*this));
	}

	BOOL IsLevelUp()
	{
		return bUpLevel ? TRUE : FALSE;/*nProgress >= nFulfill;*/
	}

	BOOL IsDestory()
	{
		return bDead ? TRUE : FALSE;
	}

	VOID ResetItemInfo()
	{
		for (int n=0; n<MAX_UPGRADE_NEED_ITEM_TYPE; n++)
		{
			dwItemID[n]	= INVALID_VALUE;
			nNeedNum[n] = 0;
		}
	}
};

//-----------------------------------------------------------------------------
// �ṹ -- ���ɼ���������Ϣ
//-----------------------------------------------------------------------------
struct tagGuildSkill 
{
	DWORD		dwSkillID;
	INT16		n16Progress;
	INT16		n16Fulfill;
	INT32		nResearchFund;
	INT32		nResearchMaterial;

	INT32		nLearnSilver;
	INT32		nLearnContribution;
	INT32		nLearnFund;
	INT32		nLearnMaterial;

	INT			nLevel;

	tagGuildSkill()
	{
		ZeroMemory(this, sizeof(*this));
	}
	tagGuildSkill(const tagGuildSkill &rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
	}
};

//-----------------------------------------------------------------------------
// �ṹ -- �������̳�ʼ��Ϣ
//-----------------------------------------------------------------------------
struct tagTaelInfo 
{
	INT32	nDeposit;		// ��֤��
	INT32	nBeginningTael;	// ��ʼ����
	INT32	nPurposeTael;	// ָ������
	INT32	nMaxTael;		// ��������
};

//-----------------------------------------------------------------------------
// �ṹ -- �����������а�
//-----------------------------------------------------------------------------
struct tagCommerceRank 
{
	DWORD		dw_role_id;
	INT			nTimes;
	INT32		nTael;
};

//-----------------------------------------------------------------------------
// �ṹ -- ���������̻�
//-----------------------------------------------------------------------------
struct tagCommerceGoodInfo
{
	DWORD	dwGoodID;
	INT32	nCost;
	BYTE	byGoodNum;

	tagCommerceGoodInfo()
	{
		dwGoodID	= INVALID_VALUE;
		nCost		= 0;
		byGoodNum	= 0;
	}

	BOOL IsValid()
	{
		if (!VALID_VALUE(dwGoodID) || (dwGoodID == 0) || (byGoodNum == 0))
		{
			return FALSE;
		}

		return TRUE;
	}
};

//-----------------------------------------------------------------------------
// �ṹ -- ǩ�����ṹ
//-----------------------------------------------------------------------------
struct tagGuildSignData
{
	DWORD			dwGuildID;							//����ID
	tagDWORDTime	dwCreateGuildTime;					//��������ʱ��
	DWORD			dwSignRoleID[MAX_GUILD_SIGN_NUM];	//����ǩ����
};

//-----------------------------------------------------------------------------
// �ṹ -- �ж�����
//-----------------------------------------------------------------------------
struct tagGuildEnemyData
{
	DWORD				dwGuildID;				// �ж԰��ID
	EGuildWarState		eGuildWarState;			// �ж԰��״̬
};

//-----------------------------------------------------------------------------
// �ṹ -- ��������
//-----------------------------------------------------------------------------
struct tagGuildDelateBase
{
	DWORD			dwGuildID;							// ���ID
	DWORD			dwInitiateRoleID;					// ������ID
	DWORD			dwBeDelateRoleID;					// ��������ID
	INT				nAgreeNum;							// ͬ������
	INT				nOpposeNum;							// ��������
	tagDWORDTime	dwDelateBeginTime;					// ������ʼʱ��
	tagDWORDTime	dwDelateEneTime;					// ��������ʱ��
	BOOL			bSucceed;							// �Ƿ�ɹ�

	tagGuildDelateBase() { ZeroMemory(this, sizeof(*this)); }
};

struct tagGuildDelate : public tagGuildDelateBase
{
	tstring  content;

	tagGuildDelate(): tagGuildDelateBase()	{}

	VOID Init(DWORD dwGuildID)
	{
		this->dwGuildID = dwGuildID;
		dwInitiateRoleID = INVALID_VALUE;
		dwBeDelateRoleID = INVALID_VALUE;
	}

};

//-----------------------------------------------------------------------------
// �ṹ -- ��������
//-----------------------------------------------------------------------------
struct tagGuildSymbol
{
    union {        
        struct {            
            DWORD byBGType   : 5;  // �װ���ʽ
            DWORD byBGColor1 : 5;  // �װ���ɫ1
            DWORD byBGColor2 : 5;  // �װ���ɫ2
            DWORD bySBType   : 5;  // ͼ����ʽ
            DWORD bySBColor  : 5;  // ͼ����ɫ
			DWORD byFont	 : 5;  // ��������
            DWORD byCustom   : 1;  // �Ƿ��Զ���ͼ��
            DWORD byReserved : 1;  // 
        }     Cfg;
        DWORD dwValue;
    };
	TCHAR szWord[2];

    tagGuildSymbol(DWORD val = 0) : dwValue(val) {  }
    bool IsEqual(const tagGuildSymbol& other) const { return this->dwValue == other.dwValue && this->szWord[1] == other.szWord[1]; }
    bool operator==(const tagGuildSymbol& other) const { return IsEqual( other );  }
    bool operator!=(const tagGuildSymbol& other) const { return !IsEqual( other ); }
    bool operator<(const tagGuildSymbol& other) const { return IsLess( other ); }
	bool IsLess(const tagGuildSymbol& other) const 
	{ 
		if(this->dwValue != other.dwValue)
			return this->dwValue < other.dwValue;
		else
		{
			if(_tcscmp(this->szWord,other.szWord)<0)
				return true;
			else
				return false;
		}
	}
};

// �����ļ����Ϣ
struct tag_guild_recrguit_info
{
	DWORD		dw_role_id;
	INT			n_level;
	EClassType	e_class;
	BOOL		b_line;
};

// ���սս������
struct tagGuildWarHistory
{
	DWORD		dw_guild_id;		
	DWORD		dw_enemy_leader_id;	// �Է�����id
	DWORD		dw_enemy_id;
	tagDWORDTime		dw_time;
	EWarHistoryTyep		e_war_history_type;
};

// ���ϻ���
struct tagGuildMaterialReceive
{
	DWORD		dw_item_id;			// ��Ʒid
	INT32		n_contribution;		// ��ðﹱ
	INT32		n_material;			// ��ò��ϵ�
	BYTE		byLevel;			// �ȼ�
	BYTE		byType;				// ����
};

// ��ֲ����
struct tagPlantData
{
	DWORD		dw_npc_id;			// ֲ��id
	INT			n_num;				// ʣ������
	DWORD		dw_master_id;		// ������id
	DWORD		dw_plant_time;		// ��ֲ��ʱ��
};

// ��������
struct tagGuildWarInfo
{
	DWORD			dwGuildID;
	BYTE			byLevel;							//���ɵ�ǰ�ȼ�	
	INT32			nMemberNumber;						//��ᵱǰ����
	INT32			nApplyLevel;						//����ȼ�
	//INT32			nFund;								//���ɵ�ǰ�ʽ�
	//INT32			nProsperity;						//���ɷ��ٶ�
	//DWORD			dwDaogaoNum;						//����������
	INT				nRank;								//����
	BOOL			bAttack;							//�Ƿ�������ս
	TCHAR			szGuildName[X_SHORT_NAME];			//�����
	TCHAR			szLeaderName[X_SHORT_NAME];			//������
};

// ɳ�Ϳ�����
struct tagGuildSBKData
{
	DWORD	dwData[6];		// ����
	//0 DWORD	dwGuildID;		// ɳ�Ϳ��л�id
	//1 DWORD	dwLeaderID;		// �᳤id
	//2 DWORD	dwFuLeaderID;	// ���᳤id
	//3 DWORD	dwChengXiangID;	// ��ة��id
	//4 DWORD	dwYuanShuaiID;	// ��Ԫ˧id
	//5 DWORD	dwYuShiID;		// ����ʷid
};

class GuildHelper
{
public:
	static INT32 getLevelUpNeedFund(byte byLevel)
	{
		switch (byLevel)
		{
		case 1:
			return 10000;
		case 2:
			return 20000;
		case 3:
			return 40000;
		case 4:
			return 80000;
		case 5:
			return 160000;
		case 6:
			return 320000;
		case 7:
			return 640000;
		case 8:
			return 1280000;
		case 9:
			return 2560000;
		case 10:
			return 5120000;
		case 11:
			return 10240000;

		default:
			return 0;
		}
	}
	static double getMoneyToFanlong(byte byLevel)
	{
		if (byLevel < 7)
		{
			return 0.05 * byLevel;
		}
		else
		{
			return 0.4;
		}
	}
	// ���ս�����ʽ�
	static INT32 getGuildWarFund(byte byLevel)
	{
		switch (byLevel)
		{
		case 3:
			return 40000000;
		case 4:
			return 60000000;
		case 5:
			return 110000000;
		case 6:
			return 130000000;
		case 7:
			return 150000000;
		default:
			return 0;
		}

		return 0;
	}
};

//-----------------------------------------------------------------------------
#pragma pack(pop)