#pragma once 

#include "base_define.h"
#include "AvatarAtt.h"

#pragma pack(push, 1)

const INT	MAX_ROLENUM_ONEACCOUNT				= 15;				// �ʺŵ�����ɫ����
const INT	MAX_ROLECREATENUM_ONEACCOUNT		= 3;				// �ʺŵ���󴴽���ɫ����
const INT	MAX_ROLE_LEVEL				= 150;				// ��ҿ���������߼���
const DWORD MAX_SAFECODE_RESET_TIME		= (72 * 60 * 60);	// ��ȫ���������ʱ��(72Сʱ)

const INT	ROLE_LEVEL_LIMIT			= 100;				// �ȼ�����

const INT	ROLE_HELP_NUM				= 255;				// �����������
const INT	TALK_DATA_NUM				= 255;				// �Ի���������
const INT	MAX_KEY_NUM					= 70;				// ��ݼ�
const INT   ATTACK_UNMOUNT_PROB			= 1500;				// �������ļ���(/10000)
const INT	ROLE_DAY_CLEAR_NUM			= 20;				// ÿ����������

const INT	ROLE_PET_XIULIAN_SIZE		= 5;				// ��������������

const INT	GUILD_WAR_CD_REBORN_TIME	= 20;				// ���ս��ȴ����ʱ��(��)

/*
	0 - ǩ�������Ƿ���ȡ
	1 - �����ʽ���״���(����)
	2 - ���ÿ���ʱ�ο���ѳ齱�Ĵ��� ��gx modify 2013.6.3��
	3 - �ճ�����֮ħ�����Դ�����gx modify 2013.8.17��
	4 - ��ҵ�������ɵĸ��ѳ齱�Ĵ��� ��gx modify 2013.6.5��
	5 - �ճ�����֮��������������gx modify 2013.8.17��
	6 - ������������
	7 - ��ÿ����ʹ�ô��� ��gx modify 2013.6.5)
	8 - ˫��	��gx modify 2013.6.27)
	9 - ���չ���ٺ»��ȡ������gx modify 2013.6.27)
	10- VIP�����ȡ������gx modify 2013.8.21��
	11- ����ɨ������
	12- �����������
	13-	����Ĥ�ݴ�����gx modify 2013.8.21��
	14-	��С�Ǹ������� gx add 2013.11.06
	15- ʦͽÿ�մ������� gx add 2013.12.05
*/
enum ERoleDayClearType
{
	ERDCT_Sign_Nubmer = 0,
	ERDCT_GuildFund = 1,
	ERDCT_FreeGamble_Number = 2,
	ERDCT_MoWuShouLie_Number = 3,//
	ERDCT_FinishedGamble_Number = 4,//
	ERDCT_QuestRefresh  = 5,//
	ERDCT_Tog_mounts  = 6,
	ERDCT_ItemWine_UseNumber= 7,
	ERDCT_ComPractice = 8,
	ERDCT_Officialsalary_GetTimes = 9,
	ERDCT_BUYREFRESHCIRCLE = 10,
	ERDCT_BUYLINGQI = 11,
	ERDCT_WANMEI_REBORN = 12,
	ERDCT_Xili_LIMIT_SOMETHING = 13,
	ERDCT_DXQ_INSTANCE_LIMIT = 14,
	ERDCT_Master_Practice = 15,
};

const INT	EQUIP_XILI_FREE				=	20;
const INT	EQUIP_XILI_LIMIT			=	30;

const INT	MAX_ACTIVE_DATA				= 20;				// ��Ծ���������
const INT	MAX_ACTIVE_RECEIVE			= 5;				// ��Ծ�Ƚ����������

const INT	MAX_GUILD_ACTIVE_RECEIVE			= 3;				// ��Ծ�Ƚ����������

const INT   HANG_TIME					= 60000;			// �һ�ʱ��60��

const INT	DELETE_ROLE_GUARD_SECOND	= 7 * 24 * 60 * 60; // ɾ����ɫ����ʱ��
const INT	CHANGE_NAME_COST_YUANBAO	= 300;				// ɾ����ɫ����Ԫ��
const INT	CHANGE_NAME_DIFF_SECOND		= 60 * 24 * 60 *60; // ��ɫ�������
const INT	SHOP_EXPLOITS_LIMIT			= 10;				// ս���̵�����

const INT	MAX_INSTANCE_NUM			= 32;				// ����������

const INT	MAX_DAILY_ACT_NUM			= 17;				//ÿ�ջ�ĸ��� gx add 2013.12.18

//��������
const INT G_RATING_ATT[][16] = {
	//�﹥���� �﹥���� ħ������ ħ������ �������� �������� ������� ������� ħ������ ħ������ ����   ����  ����  ������   hp  mp
	{ 900,	 1800,	 0,	    0,	   0,	  0,	 900,	1800,	900,   1800,  1400,1400,1400,1400,   150,150}, 		
	{ 0,	 0,		 900,	1800,  0,	  0,	 900,	1800,	900,   1800,  1400,1400,1400,1400,   150,150},
	{ 0,	 0,		 0,		0,	   900,	  1800,	 900,	1800,	900,   1800,  1400,1400,1400,1400,   150,150},
};

//---------------------------------------------------------------------------
// ���ݱ仯״̬,���ݿⱣ�����
//---------------------------------------------------------------------------
enum EUpdateDBStatus
{
	EUDBS_Null			= 0, // ������(Ĭ��״̬)
	EUDBS_Insert		= 1, // ������¼
	EUDBS_Remove		= 2, // ɾ��
	EUDBS_Update		= 3, // ���ݸ���
};

//---------------------------------------------------------------------------
// �Ա�
//---------------------------------------------------------------------------
enum ESex
{
	ES_Null			= -1,
	ES_Woman		= 0,	// Ů���ƣ���Ů����
	ES_Man			= 1,	// �����ƣ����п���
};

//----------------------------------------------------------------------------
// ְҵ����
//----------------------------------------------------------------------------
//enum EClassType
//{
//	ECT_Start		= -1,
//
//	ECT_Null		= -1,
//	ECT_Hobo		= 0,	// ����
//	ECT_Sword		= 1,	// ����
//	ECT_Blade		= 2,	// ����
//	ECT_Wand		= 3,	// �ȿ�
//	ECT_Bow			= 4,	// ����
//	ECT_Valor		= 5,	// ��ʦ
//	ECT_Supple		= 6,	// ��ʦ
//	ECT_Apothecary	= 7,	// ҩʦ
//	ECT_Musician	= 8,	// ��ʦ
//	ECT_Stabber		= 9,	// �̿�
//
//	ECT_End			= 10,
//};
//
//const INT32 X_ClASS_TYPE_NUM = ECT_End - ECT_Start - 1;

//---------------------------------------------------------------------------
// ְҵ������չ
//---------------------------------------------------------------------------
//enum EClassTypeEx
//{
//	ECTE_Base		= 0x1,	// ����ְҵ
//
//	ECTE_JianXian	= 0x2,	// ����
//	ECTE_XieWu		= 0x4,	// а��
//
//	ECTE_BaDao		= 0x2,	// �Ե�
//	ECTE_GangRen	= 0x4,	// ���
//
//	ECTE_ZongZhang	= 0x2,	// ����
//	ECTE_DiMo		= 0x4,	// ��ī
//
//	ECTE_TianJian	= 0x2,	// ���
//	ECTE_MoLing		= 0x4,	// ħ��
//
//	ECTE_XuXing		= 0x2,	// ����
//	ECTE_GuiQi		= 0x4,	// ����
//
//	ECTE_XuangWang	= 0x2,	// ����
//	ECTE_MiZong		= 0x4,	// ����
//
//	ECTE_XianYi		= 0x2,	// ��ҽ
//	ECTE_DuYin		= 0x4,	// ����
//n 
//	ECTE_YuSheng	= 0x2,	// ��ʥ
//	ECTE_HuanYin	= 0x4,	// ����
//
//	ECTE_YingWu		= 0x2,	// Ӱ��
//	ECTE_GuiWu		= 0x4,	// ����
//};

//---------------------------------------------------------------
// ר��ְҵ
//---------------------------------------------------------------
enum EClassType				 
{
	EV_Begin = -1,
    EV_Null  = 0,
	//modify 2013.4.3
	EV_Warrior,			// սʿ
	EV_Mage,				// ��ʦ
	EV_Taoist,			// ��ʿ
	//end

	EV_End,
};

const INT32 X_ClASS_TYPE_NUM = EV_End - EV_Begin - 2;
//--------------------------------------------------------------
// Ӣ��ְҵ
//--------------------------------------------------------------
enum EClassTypeEx
{
	EHV_Begin = -1,

	EHV_Base = 0,		// ����ְҵ��δѡ��Ӣ��ְҵ

	EHV_JianXian,		// �ɽ�
	EHV_XieWu,			// а��

	EHV_BaDao,			// �Ե�
	EHV_YingWu,			// Ӱ��
	
	EHV_JinGang,		// ���
	EHV_KuangZhan,		// ��ս
	
	EHV_TianJian,		// ���
	EHV_MoLing,			// ħ��
	
	EHV_XuanHuang,		// ����
	EHV_MiaoFa,			// �
	
	EHV_MingWang,		// ڤ��
	EHV_XuKong,			// ���
	
	EHV_XianYi,			// ��ҽ
	EHV_DuYin,			// ����
	
	EHV_YueSheng,		// ��ʥ
	EHV_HuanYin,		// ����

	EHV_End,
};

//--------------------------------------------------------------------------
// ��������
//--------------------------------------------------------------------------
enum ETalentType
{
	ETT_Start		= -1,
	ETT_Null		= -1,

	ETT_Hammer		= 0, // �ͽ�����1 ��
	ETT_Ax			= 1, // �ͽ�����2 ��
	ETT_Stick		= 2, // �ٱ�����1 ǹ
	ETT_Halberd		= 3, // �ٱ�����2 �
	ETT_HornBow		= 4, // ��������1 ţ�ǹ�
	ETT_IronBow		= 5, // ��������2 ����
	ETT_Thorn		= 6, // �̿�����1 ȭ��
	ETT_Round		= 7, // �̿�����2 ����
	ETT_Wood		= 8, // ҩʦ����1 ľ��
	ETT_Glass		= 9, // ҩʦ����2 ������

	ETT_End			= 10,
};

const INT32 X_TALENT_TYPE_NUM = ETT_End - ETT_Start - 1;

//--------------------------------------------------------------------------
// ��������
//--------------------------------------------------------------------------
enum EPowers
{
	EPower_Mana		= 0, //ħ��
	EPower_Rage		= 1, //ŭ��
	EPower_Point	= 2, //����
	EPower_Energy	= 3, //����
	Epower_Focus	= 4	 //���е���
};

const INT32 X_MAX_POWERS = 5;


//--------------------------------------------------------------------------
// �������ͣ����ܻ����������͵�������
//--------------------------------------------------------------------------
// enum EReputationType
// {
// 	ERT_Start		= -1,
// 	ERT_Null		= -1,
// 
// 	ERT_End			= 0,
// };

//--------------------------------------------------------------------------
// ��ɫ�����﹫��״̬��ʾ
//--------------------------------------------------------------------------
enum EState
{
	ES_Dead			=	0,	// ����
	ES_Dizzy		=	1,	// ѣ��
	ES_Tie			=	2,	// ����
	ES_Spor			=	3,	// ��˯
	ES_Invincible	=	4,	// �޵�
	ES_Lurk			=	5,	// ����
	ES_DisArm		=	6,	// ��е
	ES_NoSkill		=	7,	// �⼼
	ES_Special		=	8,  // ����״̬��������Ϊ������ͨ��һЩ[����֪���Ƿ���ͨ��]
	ES_Feat			=	9,	// �־�
	ES_Combat		=	10,	// ս��(ս��)
	ES_Occupied		=	11,	// ��ռ��

	ES_End			=	12,
};

//------------------------------------------------------------------
// ��ɫ����ﹲ����Ӫ
//------------------------------------------------------------------
enum ECamp
{
	ECA_Null				= -1,				// ��

	ECA_WaGang			= 0,				// �߸�
	ECA_Tang			= 1,				// �Ƴ�
	ECA_Sui				= 2,				// �峯
	ECA_Normal			= 3,				// Ұ������
	ECA_Common			= 4,				// ��ɫ��������
	ECA_Battle_a		= 5,				// ս������a
	ECA_Battle_b		= 6,				// ս������b
	ECA_XueMo			= 7,				// Ѫħ
	ECA_TianShi			= 8,				// ���н�
	ECA_Role			= 9,				// Ұ�����ι�

	ECA_End				= 10,				
};

//--------------------------------------------------------------------------
// ��ɫ״̬��ʶ -- ��״̬�ı䣬��Ҫ����Χ��ҹ㲥
//--------------------------------------------------------------------------
const  INT64 ERS_Safeguard	= 0x0001;	// ������
const  INT64 ERS_Combat		= 0x0002;	// ս����̬
const  INT64 ERS_PK			= 0x0004;	// ����״̬
const  INT64 ERS_Arena		= 0x0008;	// ��̨(����PVP���ս������״̬�ɽű����ã�

const  INT64 ERS_SafeArea	= 0x0010;	// ��ȫ��
const  INT64 ERS_PVPArea		= 0x0020;	// PVP��
const  INT64 ERS_StallArea	= 0x0040;	// ��̯��
const  INT64 ERS_PVP			= 0x0080;	// PVP״̬

const  INT64 ERS_Shop		= 0x0100;	// �̵꽻��
const  INT64 ERS_Exchange	= 0x0200;	// ��Ҽ�ֱ�ӽ���
const  INT64 ERS_Stall		= 0x0400;	// ��̯����
const  INT64 ERS_StallSet	= 0x0800;	// ���ð�̯��Ʒ

const  INT64 ERS_PrisonArea	= 0x1000;	// ����״̬
const  INT64 ERS_Mount		= 0x2000;	// ���
const  INT64 ERS_WaterWalk   = 0x4000;   // ˮ������
const  INT64 ERS_Mount2		= 0x8000;	// ���2

const  INT64 ERS_Commerce	= 0x10000;	// ������	
const  INT64 ERS_PetExchange	= 0x20000;	// ���ｻ��
const  INT64 ERS_Prictice	= 0x40000;	// ��������	
const  INT64 ERS_KongFu		= 0x80000;  // ����

const  INT64 ERS_CommonArea	= 0x100000;	// ��ͨ����
const  INT64 ERS_RealSafeArea= 0x200000;	// ���԰�ȫ��
const  INT64 ERS_GuildBattle = 0x400000;	// ���ս��
const  INT64 ERS_NoPunishArea= 0x800000; // �޳ͷ���

const  INT64 ERS_ComPractice = 0x1000000;	// ˫�� gx modify 2013.6.27
const  INT64 ERS_HangArea   = 0x2000000;	// �һ���
const  INT64 ERS_Hang	   = 0x4000000; // �һ�״̬
const  INT64 ERS_Fishing	   = 0x8000000; // ����

const  INT64 ERS_Carry	   = 0x10000000; // ����
const  INT64 ERS_Comprehend = 0x20000000; // ����
const  INT64 ERS_Dancing	   = 0x40000000; // ����

const  INT64 ERS_KongFuArea	  = 0x80000000; // ��������

const  INT64 ERS_ComprehendArea = 0x100000000; // ��������
const  INT64 ERS_DancingArea	   = 0x200000000; // ��������

const  INT64 ERS_End		   = 0x400000000;

typedef INT64 ERoleState;

//--------------------------------------------------------------------------
// ��ɫ״̬��ʶ -- ��״̬�ı䣬ֻ��Ҫ֪ͨ��ұ���
//--------------------------------------------------------------------------
enum ERoleStateEx
{
	ERSE_BagPsdPass		= 0x1,	// ����������֤��ͨ��
	ERSE_BagPsdExist	= 0x2,	// �����������
};

//--------------------------------------------------------------------------
// ��ɫPKģʽ
//--------------------------------------------------------------------------
enum ERolePKState
{
	ERolePK_Peace	= 0,		// ��ƽģʽ
	ERolePK_Guild,				// ���ģʽ
	ERolePK_All,				// ȫ��ģʽ

	ERPKS_End,
};

//-------------------------------------------------------------------------------
// PKģʽ
//-------------------------------------------------------------------------------
enum EBattleMode
{
	EBM_Peace		= 0,		// ��ƽģʽ
	EBM_Guild		= 1,		// ���ģʽ
	EBM_Group		= 2,		// ���ģʽ
	EBM_Whole		= 3,		// ȫ��ģʽ
};

//-------------------------------------------------------------------------------
// �����������ö��(�ô�ö��˳�򡢸�������,���ܻ�Ӱ�쵽���ݿ�װ����)
//-------------------------------------------------------------------------------
enum ERoleAttribute
{
	ERA_Null					=	-1,		//
	
	// һ������
	ERA_AttA_Start				=	0,
	ERA_Physique				=	0,		// 	����
	ERA_Strength				=	1,		// 	����
	ERA_InnerForce				=	2,		//  �ǻ�	
	ERA_Agility					=	3,		// 	����
	ERA_Pneuma					=	4,		// 	--����
	ERA_Technique				=	5,		// 	--����
	ERA_AttA_End				=	5,

	// ��ҵĵ���
	ERA_AttPoint				=	6,		// ��ǰ���Ե���
	ERA_TalentPoint				=	7,		// ��ǰ���ʵ���

	// ��������
	ERA_AttB_Start				=	8,
	ERA_MaxHP					=	8,		// �������
	ERA_HP						=	9,		// ��ǰ����
	ERA_MaxMP					=	10,		// ���ħ��
	ERA_MP						=	11,		// ��ǰħ��
	ERA_ExAttack				=	12,		// ��С��������
	ERA_ExDefense				=	13,		// �����������
	ERA_InAttack				=	14,		// ��Сħ������
	ERA_InDefense				=	15,		// ���ħ������
	ERA_HitRate					=	16,		// ������
	ERA_Dodge					=	17,		// ������
	ERA_ShenAttack				=	18,		// ��������
	ERA_Crit_Rate				=	19,		// ������
	ERA_Crit_Amount				=	20,		// ������
	ERA_UnCrit_Rate				=	21,		// ������
	ERA_UnCrit_Amount			=	22,		// ������
	ERA_HPRegainRate			=	23,		// �����ָ��ٶ�
	ERA_MPRegainRate			=	24,		// �����ָ��ٶ�
	ERA_AttB_End				=	24,

	// ��������
	ERA_Love					=	25,		// ����ֵ
	ERA_Brotherhood				=	26,		// ����ֵ
	ERA_MaxBrotherhood			=	27,		// �������
	ERA_Wuhuen					=	28,		// �������ֵ
	ERA_Speed_XZ				=	29,		// XZƽ���ٶ��ٶ�
	ERA_Speed_Y					=	30,		// Y�����ٶ�
	ERA_Speed_Swim				=	31,		// ��Ӿ��XZ�ٶ�
	ERA_Speed_Mount				=	32,		// ��˵�XZ�ٶ�

	// ��������
	ERA_EngraveAtt_Start		=	33,		
	ERA_ExAttackMin				=	33,		// ��С��������
	ERA_ExAttackMax				=	34,		// �����������
	ERA_InAttackMin				=	35,		// ��Сħ������
	ERA_InAttackMax				=	36,		// ���ħ������
	ERA_ArmorEx					=	37,		// ��С��������
	ERA_ArmorIn					=	38,		// ����������
	ERA_EngraveAtt_End			=	38,		


	ERA_Derate_Ordinary			=	39,		// ��ͨ�˺�����	

	ERA_Derate_Start			=	40,
	ERA_Derate_Soil				=	40,		// ���˺�����
	ERA_Derate_Gold				=	41,		// ˮ�˺�����
	ERA_Derate_Wood				=	42,		// ���˺�����
	ERA_Derate_Fire				=	43,		// ���˺�����
	ERA_Derate_Water			=	44,		// ���˺�����
	ERA_Derate_End				=	44,

	ERA_Derate_Injury			=	45,		// �����˺�����
	ERA_Derate_Stunt			=	46,		// �����˺�����
	ERA_Derate_ExAttack			=	47,		// ��ս�˺�����
	ERA_Derate_InAttack			=	48,		// Զ���˺�����
	ERA_Derate_ALL				=	49,		// �����˺�����
	

	ERA_ExDamage				=	50,		// �����˺�
	ERA_ExDamage_Absorb			=	51,		// �����˺�����

	ERA_Resist_Bleeding			=	52,		// ��Ѫ���ԡ������м���
	ERA_Resist_Weak				=	53,		// �������ԡ������м���
	ERA_Resist_Choas			=	54,		// ���ҿ��ԡ������м���
	ERA_Resist_Special			=	55,		// ���⿹�ԡ������м���
	ERA_Regain_Addtion			=	56,		// �ָ����ӳ�

	ERA_Attack_MissRate			=	57,		// ����ʧ����
	ERA_CloseAttack_DodgeRate	=	58,		// ��ս����ʼӳ�
	ERA_RemoteAttack_DodgeRate	=	59,		// ���⼸��,��������ֵ�����˼���

	ERA_Inspiration				=	60,		// ���
	ERA_Luck					=	61,		// ����ֵ
	ERA_Savvy					=	62,		// ����
	ERA_Morale					=	63,		// ʿ��
	ERA_Injury					=	64,		// ����ֵ
	ERA_Enmity_Degree			=	65,		// ��޶�
	ERA_Shape					=	66,		// ����
	ERA_Exp_Add_Rate			=	67,		// �����üӳ�		ԭ����/��Ǯ/���� * (1+�ӳ�/10000)
	ERA_Money_Add_Rate			=	68,		// ��Ǯ��üӳ�
	ERA_Loot_Add_Rate			=	69,		// ��Ʒ���伸�ʼӳ�

	// �������
	ERA_Fortune					=	70,		// Ԫ��
	ERA_Appearance				=	71,		// ����
	ERA_Rein					=	72,		// ͳ��
	ERA_Knowledge				=	73,		// ���� gx modify 2013.7.2(����)
	ERA_Morality				=	74,		// ���ֵ
	ERA_Culture					=	75,		// ��Ϊ

	ERA_End						=	76,
	// ��ҵ�������������Ͷ�����Ե㣬�Ѿ�Ͷ�ŵ����ʵ�û�зŵ�����������
};

const INT32	X_ERA_ATTA_NUM		= ERA_AttA_End - ERA_AttA_Start + 1;
#define MTransERAAttA2Index(ERAAttA)		((ERAAttA) - ERA_AttA_Start)
#define MTransIndex2ERAATTA(Index)			((Index) + ERA_AttA_Start)

const INT32 X_ERA_AttB_NUM		= ERA_AttB_End - ERA_AttB_Start;
#define MTransERAAttB2Index(ERAAttB)		((ERAAttB) - ERA_AttB_Start)
#define MTransIndex2ERAATTB(Index)			((Index) + ERA_AttB_Start)

const INT32	X_ERA_DERATE_NUM	= ERA_Derate_End - ERA_Derate_Start + 1;
#define MTransERADerate2Index(ERADerate)	((ERADerate) - ERA_Derate_Start)
#define MTransIndex2ERADerate(Index)		((Index) + ERA_Derate_Start)

//--------------------------------------------------------------------------------------
// Զ����ҵ�����ö��
//--------------------------------------------------------------------------------------
enum ERemoteRoleAtt
{
	ERRA_Null		=	-1,		//

	ERRA_MaxHP		=	0,		// �������
	ERRA_HP			=	1,		// ��ǰ����
	ERRA_MaxMP		=	2,		// �������
	ERRA_MP			=	3,		// ��ǰ����
	ERRA_Rage		=	4,		// ����
	ERRA_Speed_XZ	=	5,		// XZƽ���ٶ�
	ERRA_Speed_Y	=	6,		// Yƽ���ٶ�
	ERRA_Speed_Swim	=	7,		// ��Ӿ�ٶ�
	ERRA_Speed_Mount=	8,		// ����ٶ�
	ERRA_Shape		=	9,		// ����
	//gx add 2013.5.31 �鿴Զ���������
	ERRA_HitRate	=	10,		// ������
	ERRA_Dodge		=	11,		// ������
	ERRA_Crit_Rate	=	12,		// ������
	ERRA_UnCrit_Rate	=	13,		// ������
	ERRA_ExAttackMin	=	14,		// ��С��������
	ERRA_ExAttackMax	=	15,		// �����������
	ERRA_InAttackMin	=	16,		// ��Сħ������
	ERRA_InAttackMax	=	17,		// ���ħ������
	ERRA_ArmorEx	=	18,		// ��С��������
	ERRA_ArmorIn	=	19,		// ����������
	ERRA_ExAttack	=	20,		// ��С��������
	ERRA_ExDefense	=	21,		// �����������
	ERRA_InAttack	=	22,		// ��Сħ������
	ERRA_InDefense	=	23,		// ���ħ������
	ERRA_Luck		=	24,		// ����ֵ
	ERRA_ShengW		=	25,		//����ֵ
	//end
	ERRA_End		=	26,
};

//-----------------------------------------------------------------------------------------
// Ŀ�����ͱ�ʾλ
//-----------------------------------------------------------------------------------------
enum ETargetFlag
{
	ETF_Self				=	0x00000001,	// ����
	ETF_Teammate			=	0x00000002,	// ����
	ETF_Guildmate			=	0x00000004,	// ͬ��
	ETF_Lover				=	0x00000008,	// ����
	ETF_Couple				=	0x00000010,	// ��ż
	ETF_Brother				=	0x00000020,	// ���
	ETF_Teacher				=	0x00000040,	// ʦͽ
	ETF_Player				=	0x00000080,	// ���

	ETF_Pet					=	0x00000100,	// ����
	ETF_NPC					=	0x00000200,	// NPC
	ETF_NormalMonster		=	0x00000400,	// ��ͨ����
	ETF_Boss				=	0x00000800,	// Boss
	ETF_Nest				=	0x00001000,	// ��Ѩ
	ETF_NatuRes				=	0x00002000,	// ����
	ETF_ManRes				=	0x00004000,	// ��ҩ
	ETF_Door				=	0x00008000,	// ����
	ETF_Building			=	0x00010000,	// ����
	ETF_NormalGameObject	=	0x00020000,	// ��ͨ�ɽ�������
	ETF_InvesGameObject		=	0x00040000,	// �ɵ������
	ETF_QuestTalkGameObject	=	0x00080000,	// ����Ի�����
    ETF_GuildGameObject     =   0x00100000, // ������ص��� (������ɸ����?)
};

//-----------------------------------------------------------------------------------------
// ״̬��ʾλ
//-----------------------------------------------------------------------------------------
enum EStateFlag
{
	ESF_Dead			=	0x00000001,	// ����
	ESF_NoDead			=	0x00000002,	// ������
	ESF_Dizzy			=	0x00000004,	// ѣ��
	ESF_NoDizzy			=	0x00000008,	// ��ѣ��
	ESF_Spor			=	0x00000010,	// ��˯
	ESF_NoSpor			=	0x00000020,	// �ǻ�˯
	ESF_Tie				=	0x00000040,	// ����
	ESF_NoTie			=	0x00000080,	// �Ƕ���
	ESF_Invincible		=	0x00000100,	// �޵�
	ESF_NoInvincible	=	0x00000200,	// ���޵�
	ESF_NoSkill			=	0x00000400,	// �⼼
	ESF_NoNoSkill		=	0x00000800, // �Ƿ⼼
	ESF_DisArm			=	0x00001000,	// ��е
	ESF_NoDisArm		=	0x00002000,	// �ǽ�е
	ESF_Lurk			=	0x00004000,	// ����
	ESF_NoLurk			=	0x00008000,	// ������
	ESF_Mount			=	0x00010000,	// ���
	ESF_NoMount			=	0x00020000, // �����
	ESF_Prison			=	0x00040000,	// ����
	ESF_NoPrison		=	0x00080000,	// ������
	ESF_Mount2			=	0x00100000,	// ���2
	ESF_NoMount2		=	0x00200000, // �����2
	ESF_Commerce		=	0x00400000,	// ������
	ESF_NoCommerce		=	0x00800000,	// ��������
	ESF_Prictice		=	0x01000000,	// ��������
	ESF_NoPrictice		=	0x02000000,	// ����������
	ESF_Hang			=   0x04000000, // �һ�
	ESF_NoHang			=   0x08000000,	// �ǹһ�

};
//Ares �벻Ҫ�޸Ĵ��У�RoleDefine.h �� QuestDef.h�໥����
#include "QuestDef.h" 
//-----------------------------------------------------------------------------------------
// ��������������Ե�Ĭ��ֵ�������Сֵ
//-----------------------------------------------------------------------------------------
struct tagAttDefMinMax
{
	INT		nDefRole;			// �����ʼ��Ĭ��ֵ
	INT		nDefCreature;		// �����ʼ��Ĭ��ֵ
	INT		nMin;				// ������Сֵ
	INT		nMax;				// �������ֵ
};

////---------------------------------------------------------------------------------------
//// �ͻ��˱������ͬ��������Ϣ�ṹ��δ��ɣ�
////---------------------------------------------------------------------------------------
//struct tagRoleData
//{
//	DWORD			dwID;						// ���ID
//	DWORD			dwRoleNameCrc;				// ����CRC
//	TCHAR			sz_role_name[X_SHORT_NAME];	// ����
//
//	DWORD			dwMapID;					// ���ڵĵ�ͼ��ID
//	FLOAT			fPos[3];					// λ��
//	FLOAT			fFaceTo[3];					// ����
//
//	tagAvatarAtt	Avatar;						// ���
//	tagAvatarEquip	AvatarEquip;				// װ�����
//	tagDisplaySet	DisplaySet;					// �����ʾ����
//	INT				nAtt[ERA_End];				// ��ǰ��������
//
//	INT				nAttPointAdd[X_ERA_ATTA_NUM];// ���Ͷ�ŵ�����һ�������е�ֵ
//
//	EClassType		eClass;						// ְҵ
//	EClassTypeEx	eClassEx;					// ��չְҵ
//
//	INT16			n16MaxBagSize;				// ������С
//	INT16			n16MaxWareSize;				// �˺Ųֿ��С
//
//	INT				nSkillNum;					// ���ܸ���
//	INT				nBuffNum;					// ״̬����
//	INT				nTitleNum;					// �ƺŸ���
//	INT				nItemNum;					// ��Ʒ����
//	INT				nEquipNum;					// װ������
//	INT				nFriendNum;					// ���Ѹ���
//	INT				nEnemyNum;					// ��и���
//	INT				nQuestNum;					// �����б�����
//	INT				nQuestDoneNum;				// ����ɵ��������
//
//	/*********************************************************************************************************
//	 *�����б���״̬�б����ƺ��б�����Ʒ�б���װ���б��������б�������б��������б�������������б�
//	 *���밴˳�򿽱�
//	 *********************************************************************************************************/
//	//�����б�
//	DWORD			dwIncompleteQuestID[QUEST_MAX_COUNT];			// �ڵ�ǰ�������δ��ɵ����� 30����
//	DWORD			dwIncompleteQuestTakeTime[QUEST_MAX_COUNT];		// �ڵ�ǰ������ϵ�ǰ����Ľ�ȡʱ�� 30����
//	//�����б�
//	
//
//	BYTE			byData[1];
//};

//------------------------------------------------------------------------------------------
// ��ѡ�˽���Ҫ������������Ϣ
//------------------------------------------------------------------------------------------
struct tagSimRole								// size = 64
{
	tagAvatarAtt	Avatar;						// size = 16
	tagAvatarEquip	AvatarEquip;				// size = (2 * 9 + 1) * 4
	TCHAR			szRoleName[X_SHORT_NAME];

	DWORD			dw_role_id;
	DWORD			dwMapID;
	BYTE			byLevel;
	EClassType		eClassType;
	tagDisplaySet	sDisplaySet;
	tagDWORDTime	dwLoginTime;
	tagDWORDTime	dwDelGuardTime;
	tagDWORDTime	dwChangeNameTime;
	BYTE			byReserved[2];
};

//------------------------------------------------------------------------------------------
// �Ƿ��Զ����ҹ��������Ϣ -- ע�����ݿ����¼��32λ
//------------------------------------------------------------------------------------------
struct tagRemoteOpenSet
{
	DWORD	bTitle		: 1,	// �ƺ�
			bVCard		: 1,	// ����
			bRoleAtt	: 1,	// ��ɫ����
			bDummy		: 29;	// ռλ��

	tagRemoteOpenSet() { ZeroMemory(this, sizeof(*this)); }
	
	tagRemoteOpenSet& operator = (DWORD dw)
	{
		return *this = *(tagRemoteOpenSet*)&dw;
	}

	operator DWORD()
	{
		return *(DWORD*)this;
	}
};


//------------------------------------------------------------------------------------------
// �����Ϣ�Ĺ�������
//------------------------------------------------------------------------------------------
enum EPlayerPersonlInfoOpenType
{
	EPIS_Private,  // ��ȫ����
	EPIS_Friend,   // ���Ի�Ϊ���ѵ���ҹ���
	EPIS_Public,   // ��ȫ����
	EPIS_End,
};

//------------------------------------------------------------------------------------------
// ��ҵĸ�������
//------------------------------------------------------------------------------------------
struct tagDWPlayerPersonalSet
{
	DWORD	bAcceptTeamInvite		: 1,	// �Ƿ�����������
			bAcceptFactionInvite	: 1,	// �Ƿ���ܰ�������
			bAllowFriendAdd			: 1,	// �Ƿ����������������Լ�Ϊ����
			bAcceptTradeRequest		: 1,	// �Ƿ���ܽ�������
			eInfoOpenType           : 4,    // ��Ϣ�Ĺ�������
			bDummy					: 24;	// ռλ��

	tagDWPlayerPersonalSet() { ZeroMemory(this, sizeof(*this)); }

	tagDWPlayerPersonalSet& operator = (DWORD dw)
	{
		return *this = *(tagDWPlayerPersonalSet*)&dw;
	}

	operator DWORD()
	{
		return *(DWORD*)this;
	}
};
//-------------------------------------------------------------------------------------------
// ��ݼ���Ϣ
//-------------------------------------------------------------------------------------------
struct tagKeyInfo
{
    DWORD		dwID;
    DWORD		dwKey;			// ��ݼ�1
	DWORD		dwKeyTwo;		// ��ݼ�2
};

struct roleOnlineState
{
	INT64 hpID;
	INT64 traID;
	int open[7];
}; 

// Ԫ��ֵ
enum EVigourBase
{
	EVB_VALUE = 50, // ��ʼֵ
	EVB_DELTA = 50, // ���ֵ����Сֵ�Ĳ�ֵ
};

#define VigourMin(Level) (Level)
#define VigourMax(Level) (100 + Level)

struct tagRolePvP
{
	DWORD	dw_pvp_id;
	INT		nIndex;
	BOOL	b1v1;	// TRUE 1v1������ FALSE Լս������

	tagRolePvP()
	{
		dw_pvp_id = INVALID_VALUE;
		nIndex = 0;
		b1v1 = TRUE;
	}

	VOID Init(DWORD dw_pvp_id_, INT nIndex_, BOOL b1v1_ = TRUE)
	{
		dw_pvp_id = dw_pvp_id_;
		nIndex = nIndex_;
		b1v1 = b1v1_;
	}

	VOID Reset()
	{
		dw_pvp_id = INVALID_VALUE;
		nIndex = 0;
		b1v1 = TRUE;
	}
};

class RoleHelper
{
public:
	// ����ְҵ������Կ���
	static VOID Class2EAR(EClassType eClass, ERoleAttribute& att1, ERoleAttribute& att2)
	{
		switch(eClass)
		{
		case EV_Warrior:
			att1 = ERA_Derate_Wood;
			att2 = ERA_Derate_Fire;
			break;
		case EV_Mage:
			att1 = ERA_Derate_Wood;
			att2 = ERA_Derate_Water;
			break;
		case EV_Taoist:
			att1 = ERA_Derate_Gold;
			att2 = ERA_Derate_Water;
			break;
		//case EV_Blader:
		//	att1 = ERA_Derate_Soil;
		//	att2 = ERA_Derate_Gold;
		//	break;
		//case EV_Astrologer:
		//	att1 = ERA_Derate_Soil;
		//	att2 = ERA_Derate_Fire;
		//	break;
		default:
			att1 = ERA_Derate_Ordinary;
			att2 = ERA_Derate_Ordinary;
			break;
		}
	}
	
	// ��ȡ������������������Ǯ
	static INT64 GetPetXiulianSiver(INT nIndex)
	{
		switch (nIndex)
		{
		case 1:
			return 0;
		case 2:
			return 1000000;
		case 3:
			return 2000000;
		case 4:
			return 4000000;
		case 5:
			return 8000000;

		}

		return 0;
	}
	
	// ����ʱ�����Ľ��
	static INT64 GetPetXiulianTimeSilver(DWORD dwType)
	{
		switch(dwType)
		{
		case 0:
			return 10000;
		case 1:
			return 30000;
		case 2:
			return 90000;
		case 3:
			return 300000;
		}

		return 0;
	}

	// ����ģʽ����Ԫ��
	static INT32 GetPetXiulianModeYuanbao(DWORD dwType)
	{
		switch (dwType)
		{
		case 0:
			return 0;
		case 1:
			return 10;
		case 2:
			return 30;
		case 3:
			return 150;
		case 4:
			return 500;
		}
		return 0;
	}
	// ����ģʽÿ���ӻ�þ���
	static INT32 GetPetXiulianModeExp(DWORD dwType)
	{
		switch (dwType)
		{
		case 0:
			return 2;
		case 1:
			return 10;
		case 2:
			return 30;
		case 3:
			return 150;
		case 4:
			return 300;
		}
		return 0;
	}
	
	// ����ʱ��
	static DWORD GetPetXiulianTime(DWORD dwType)
	{
		DWORD dwTime = 0;
		switch (dwType)
		{
		case 0:
			dwTime = 2 * 60;
			break;
		case 1:
			dwTime = 4 * 60;
			break;
		case 2:
			dwTime = 8 * 60;
			break;
		case 3:
			dwTime = 24 * 60;
			break;
		default:
			break;
		}

		return dwTime;

	}
	
};
#pragma pack(pop)