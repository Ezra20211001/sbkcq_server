//-----------------------------------------------------------------------------
//��Name				:   creature_define.h
//��Compiler			:	Microsoft Visual C++ 9.0Aslan
//��Version				:	1.00
//��Create Date			:	2008-08-25
//��LastModified		:	
//��Brief				:	�������Զ���
//-----------------------------------------------------------------------------
#pragma once

#include "reputation.h"
#include "RoleDefine.h"
#include "NPCTeam_define.h"

//enum ENPCTeamOrder;

#define NORAML_SKILL_NUMBER 3
//----------------------------------------------------------------
// ��Ϸ����������
//----------------------------------------------------------------
enum ECreatureType
{
	ECT_NULL		=	0,
	ECT_Monster		=	1,		// ����
	ECT_GameObject	=	2,		// �ɽ����ĵ���
	ECT_NPC			=	3,		// ��ͨNPC
	ECT_Pet			=	4,		// ����
};

//----------------------------------------------------------------
// ��������
//----------------------------------------------------------------
enum EAniType
{
	EAT_None		=	0,		// ��̬
	EAT_KeyFrame	=	1,		// �ؼ�֡
	EAT_Skeleton	=   2,		// ��������
    EAT_Avatar      =   3,      // �ɻ�װ��������
};

//----------------------------------------------------------------
// ��������
//----------------------------------------------------------------
enum EMonsterType
{
	EMTT_Normal		=	1,		// ��ͨ
	EMTT_Nest		=	2,		// ��Ѩ
	EMTT_Team		=	10,		// ����С�Ӷӳ�
	EMTT_Tripod		=	11,		// �����ͨ��ͼ��	
};

//----------------------------------------------------------------
// ��ͨNPC����
//----------------------------------------------------------------
enum ENPCType
{
	ENPCT_Normal	=	0,		// ��ͨNPC
};

//-----------------------------------------------------------------
// �ɽ�����������
//-----------------------------------------------------------------
enum EGameObjectType
{
	EGOT_Normal		=	0,		// ��ͨ����
	EGOT_Gather		=	3,		// �ɲɼ�����
	EGOT_Chest		=	4,		// ����
	EGOT_Flag		=	5,		// ����
	EGOT_Door		=	6,		// ��
	EGOT_QuestInves =   7,      // ����ɵ������
	EGOT_QuestTalk  =   8,      // ����Ի�����
	EGOT_CommonInves=	9,		// ������������
	EGOT_Relive		=  10,		// ���ս�����
	EGOT_CommonInves_T=  11,	// ������������(2)

};

//------------------------------------------------------------------
// ��������
//------------------------------------------------------------------
enum EPetType
{
	EPT_Normal		=	0,		// ��ͨ����
};

//------------------------------------------------------------------
// ����������
//------------------------------------------------------------------
enum EGuildType
{
	EGT_NULL				= -1,				// ��
	EGT_Lobby				= 0,				// ������
	EGT_Bank				= 1,				// ���Ǯׯ
	EGT_Leechdom			= 2,				// ���ٲ���
	EGT_Factory				= 3,				// ��Ṥ��
	EGT_Maidan				= 4,				// ���������
	EGT_Holiness			= 5,				// ���ʥ�޾�	

	EGT_Bank_Sentinel		= 6,				// ���Ǯׯ����
	EGT_Leechdom_Sentinel	= 7,				// ���ٲ�������
	EGT_Factory_Sentinel	= 8,				// ��Ṥ������
};

//------------------------------------------------------------------
// ְ������
//------------------------------------------------------------------
enum EFunctionNPCType
{
	EFNPCT_Null		=	-1,		// ��
	EFNPCT_Shop		=	0,		// �̵�
	EFNPCT_Dak		=	1,		// ��վ
	EFNPCT_Ware		=	2,		// �ֿ�
	EFNPCT_Compose	=	3,		// �ϳ�
	EFNPCT_Guild	=	4,		// ����
	EFNPCT_Guard	=	5,		// ����
	EFNPCT_Yamun	=	6,		// ����
	EFNPCT_Quench	=	7,		// ���
	EFNPCT_Engrave	=	8,		// �Կ�
	EFNPCT_Posy		=	9,		// ����
	EFNPCT_Teacher	=	10,		// ����������
	EFNPCT_Revive	=	11,		// �����
	EFNPCT_GuildMgr	=	12,		// ���ɹ���
	EFNPCT_GuildWare=	13,		// ���ɲֿ�
	EFNPCT_CofC		=	14,		// �̻�
	EFNPCT_Fusion	=	15,		// �����ں�
	EFNPCT_Purification=16,		// ��������
	EFNPCT_LoopQuest   =17,	    // ����ѭ������
	EFNPCT_Ride		   =18,		// ����ǿ��/��װ��/��ĥװ��
	EFNPCT_Master	   =19,		// ���ʦͽ��ϵ
	EFNPCT_MailMan	   =20,		//����
	EFNPCT_CircleQuest =21,		// ���������
	EFNPCT_BANNER = 22,	// �д�ս��
	EFNPCT_FISH			= 23,  // ���� 
	EFNPCT_TeamCircleQst=24, // ���ˢ�������
	EFNPCT_Earthy		= 25,	// �����ֲ����
	EFNPCT_ReaAtt		= 26,	// ��������
	EFNPCT_Pet_Xiulian	= 27,	// �������
	EFNPCT_DAMO			= 28,	// ԭʯ��ĥ
};

enum EAIACTION
{
	AIAT_Attack		=	0,									// ������
	AIAT_Guard		=	1,									// ������
	AIAT_Barbette	=	2,									// ������
	AIAT_SpaceOut	=	3,									// ������
	AIAT_PetAttack  =	4,									// ���﹥����
	AIAT_Alert		=   5,									// ������	by ljp [2010-03-26:10-03]
	AIAT_Hucheng	=	6,									// ������
};

//------------------------------------------------------------------
// ���ܹ���AI���͵��м�״̬
//------------------------------------------------------------------
enum EFLEETIME
{
	EFT_NotEnter	=	0,									// û�н��������״̬
	EFT_FirstEnter	=	1,									// ��һ�ν�������״̬
	EFT_Enter		=	2,									// ��������״̬
	EFT_CallHelp	=	3,									// ����״̬
};

//------------------------------------------------------------------
// ְ��ID
//------------------------------------------------------------------
typedef union
{
	DWORD	dwCommonID;					// ��ȡ��̬���Ա�ʱ��ʹ�ø��ֶ�
	DWORD	dwShopID;					// �̵�NPC���ҵ��̵�ID
	INT		nProduceType;				// �ϳ�NPC����Ӧ�ĺϳ�����
	DWORD	dwDakID;					// ��վNPC���ҵ�ID
} FunctionID;


//------------------------------------------------------------------
// �ɲɼ���������
//------------------------------------------------------------------
enum EGatherType
{
	EGT_Mine		=	1,		// ����
	EGT_Herb		=	2,		// ��ҩ
    EGT_Pool        =   3,      // ����
	EGT_Carry		=	4,		// �ɰ�����
	EGT_Guild_Mine	=	5,		// �������
	EGT_Guild_Herb	=	6,		// �����ҩ
};

//------------------------------------------------------------------
// ���Ｖ��
//------------------------------------------------------------------
enum ERank
{
	ER_Null,					// ��
	ER_FieldNormal,				// ��ͨ��
	ER_FieldElite,				// Ұ�⾫Ӣ
	ER_FieldWordBoss,			// Ұ��BOSS������BOSS
	ER_QuestBoss,				// ����BOSS
	ER_InstNormal,				// ��ͨ������
	ER_InstNormalBoss,			// ��ͨ����BOSS
	ER_Indwelling,				// ����
	ER_Guild,					// ����
	ER_InstHero,				// ��Ӣ������
	ER_InstHeroBoss,			// ��Ӣ����BOSS
};

//------------------------------------------------------------------
// ������Ӫ��ϵ
//------------------------------------------------------------------
enum ECampConnection
{
	ECAC_Null			= 0,			// ��
	ECAC_Friend			= 1,			// �Ѻ�
	ECAC_Enemy			= 2,			// �ж�
	ECAC_Neutralism		= 3,			// ����
};

//-------------------------------------------------------------------
// Ѳ������
//-------------------------------------------------------------------
enum ECreaturePatrolType
{
	ECPT_Null = 0,
	ECPT_Stand,			// վ��
	ECPT_Range,			// ����
	ECPT_Path,			// ·��
	ECPT_Wood,			// ľ׮
	ECPT_Patrol,		// ��ָ����·������ by ljp [ 2010-03-29 ]
};

//-------------------------------------------------------------------
// ׷������
//-------------------------------------------------------------------
enum ECreaturePursueType
{
	ECPST_Null = 0,
	ECPST_Flee,			// ����
	ECPST_CallHelp,		// ����
	ECPST_BeHitCallHelp,// �������

};

//-------------------------------------------------------------------
// ��������
//-------------------------------------------------------------------
enum ECreatureRespawnType
{
	ECRT_Normal,			// ��ͨ������ʽ
};

//-------------------------------------------------------------------
// ���﹥���������ͣ����飬������
//-------------------------------------------------------------------
enum ECreatureTaggedType
{
	ECTT_NULL = 0,
	ECTT_Hit,					// ����
	ECTT_Kill,					// ��ɱ
	ECTT_All,					// ȫ��
	ECTT_NOTALL					// ȫ�岻��
};

//-------------------------------------------------------------------
// ����AI��������
//-------------------------------------------------------------------
enum EAICreateType
{
	EACT_Null			=		-1,			// ��AI
	EACT_NoAI			=		0,			// ��AI����
	EACT_Indicate		=		1,			// ָ��
	EACT_Random			=		2,			// ��ȫ���
	EACT_GroupRandom	=		3,			// ����ID��Χ�����
};

//---------------------------------------------------------------------
// AI������Ϊ
//---------------------------------------------------------------------
enum EAIFlag
{
	EAIF_Flee			=		1,			// ����
	EAIF_Call			=		2,			// �ٻ�����
};

//---------------------------------------------------------------------
// ��������
//---------------------------------------------------------------------
enum EHelpType
{
	EHT_Stand			=      1,		// ԭ�غ���
	EHT_Flee			=	   2,		// ���ܺ���
};

//---------------------------------------------------------------------
// ��ͼ��ʾ����
//---------------------------------------------------------------------
enum EMapShowType
{
	EMST_Null			=		0,
	EMST_NorMonster		=		1,
	EMST_SuperMonster	=		2,
	EMST_NorNPC			=		3,
	EMST_FunNPC			=		4,
	EMST_TransNPC		=		5,
	EMST_WorldBoss		=		6,
};

//--------------------------------------------------------------------
//NPC��������
//--------------------------------------------------------------------
enum ENpcElements
{
	ENET_Null			=		0,
	ENET_Gold			=		1,
	ENET_Wood			=		2,
	ENET_Water			=		3,
	ENET_Fire			=		4,
	ENET_Soil			=		5,
};

//---------------------------------------------------------------------
// ��Ѩ���Խṹ
//---------------------------------------------------------------------
const INT MAX_SPAWN_CREATURE_NUM = 10;		// ��Ѩ����ˢ�µĹ�������

struct tagNestProto
{
	ENPCTeamOrder		eOrderType;								// С�Ӷ���
	FLOAT				fSpace;									// ����С�ӳ�Ա��ļ��
	INT					nSpawnRadius;							// ˢ�¹���ķ�Χ
	INT					nCreatureNum;							// ˢ�µĹ�������
	DWORD				dwSpawnID[MAX_SPAWN_CREATURE_NUM];		// ��Ѩˢ�¹����ID
	INT					nSpawnMax[MAX_SPAWN_CREATURE_NUM];		// ��Ѩˢ��ÿ�ֹ�����������
};

//-------------------------------------------------------------------
// ���NPC������������Խṹ
//-------------------------------------------------------------------
struct tagCreatureProto
{
	// ����
	DWORD					dw_data_id;					// ����ID
	ECreatureType			eType;						// �������
	INT						nType2;						// ���������
	INT						nType3;						// �������3
	INT						nFamily;					// ��������
	EGuildType				eGuildType;					// ��Ὠ������
	ECamp					eCamp;						// ������Ӫ
	BYTE					bySex;						// �Ա�
	BYTE					byReserved[3];				// ������3�ֽ�
	ERank					eLite;						// ����
	INT						nLevel;						// �ȼ�
	Vector3					vSize;						// �����д�С
	Vector3				vLookAt;						//�����
	Vector3				vLookFrom;					//�����λ��
	BOOL					bUsePic;						//�Ƿ���ͼƬͷ��
	float						fRtAngle;						//��ת�ĽǶ�
	INT32					nDoorCloseTime;				// ���Զ��ر�ʱ��
	BOOL					bCanInWater;				// �Ƿ��ܽ�ˮ
	INT						nPursueTime;				// ׷��ʱ��
	INT						nNoAttackTime;				// �޼����ͷ���սʱ��
	INT						nPursueRadius;				// ׷���뾶
	INT						nInstPoint;					// ��������
	BOOL					bLoading;					// �Ƿ�Ԥ����NPC
	DWORD				dwRidePetID;			// ��˵�����petid
	DWORD				dwRideLevel;				//�����ǿ���ȼ�
	DWORD				dwCarryID;					// ������ƷID
	DWORD				dwSortType;					// ͨ���������
	// �ƶ���ս��
	ECreaturePatrolType		ePatrolType;				// �ƶ�����
	INT						nPatrolRadius;				// ���ƶ��뾶
	ECreaturePursueType		ePursueType;				// ׷������
	//DWORD					dwNormalSkillIDMelee;		// ��ͨ��������ID
	//DWORD					dwNormalSkillIDRanged;		// Զ�̹�������ID
	DWORD					dwNormalSkill[NORAML_SKILL_NUMBER];			// 3����������id
	INT						nAttackInterTick;			// ���﹥�����
	BOOL					bCanAttack;					// �Ƿ�ɹ���
	BOOL					bCanBeAttack;				// �Ƿ�ɱ�����
	BOOL					bVisble;					// �Ƿ�ɼ�
	BOOL					bCanHitFly;					// �Ƿ���Ա�����
	BOOL					bCanKill;					// �Ƿ�ɱ�ɱ
	BOOL					bRedNameCanTalk;			// �����Ƿ�ɶԻ�	add by hejiang
	BOOL					bCantka;					// �Ƿ��ܿ���
	// ˢ��
	ECreatureRespawnType	eRespawnType;				// ����ģʽ
	INT						nRespawnTick;				// ����ʱ�䣨��λ��tick��
	INT						nRespawnTickAdd;			// ����ʱ������
	INT						nLiveTick;					// ����ʱ��

	// ����
	ECreatureTaggedType		eTaggedType;				// ����Ȩ����
	INT						nExpGive;					// ���辭��
	EReputationType			eRepType1;					// ��������1����
	INT						nRepNum1;					// ��������1ֵ
	EReputationType			eRepType2;					// ��������2����
	INT						nRepNum2;					// ��������2ֵ
	DWORD					dwLootID;					// ��Ʒ������
	INT						nExploits;					// ����ս��
	BOOL					b_save_process;				// �Ƿ񱣴渱������

	// AI
	EAICreateType			eAICreateType;				// AI����ģʽ
	DWORD					dwAIID;						// AIID
	EAIACTION				eAIAction;					// AI��Ϊ��ʽ

	// ְ��
	EFunctionNPCType		eFunctionType;				// ְ������
	FunctionID				uFunctionID;				// ְ��ID
	BOOL					bVipPriceOff;				// ʹ��VIP�ۿ�
	bool						b_boss_display;				//�Ƿ���ʾΪboss
	// ����
	INT						nBaseAtt[ERA_End];			// ��������
	
	// add by ljp [ 2010-03-26:15-11 ]
	DWORD					nAlertDis;					// ���䷶Χ
	FLOAT					fChangeAct;					// ����or��ȼ���	[0.0,1.0]
	FLOAT					fChangleActHP;				// ����or���ʱ�����ٷֱ� [0.0,1.0]
	DWORD					dwHelpRange;				// ����������Χ
	INT16					nHelpNum;					// �����������
	EHelpType				eHelpType;					// �����������
	DWORD					dw_help_time;				// �������or���ܼ��ʱ��

	// ����
	UINT16					u16QuestID;					// �ɵ����������������ID
	BYTE					byReserved2[2];				// ������

	// ��Ѩָ��
	tagNestProto*			pNest;						// ��Ѩָ��
	
	// ��ֲ����ʱ��(��)
	DWORD					dwMatureTime;	
	// ����ɿ�����ĳ�ͷid
	DWORD					dwChutouID;		

	// ��ͼ��ʾ  add by hejiang[ 2010.12.20 ]
	EMapShowType			eMapShowType;
	ENpcElements			eElements;
	INT						nPos_x;
	INT						nPos_y;

    BOOL                    bCanShake;                  // �ܻ�ʱ�Ƿ���� by zhaopeng 2011.04.08
    DWORD                   dwHitFlySpeedFactor;        // �����ٶ�ϵ��

    BOOL                    bCanSelect;                 // �Ƿ��ܱ�ѡ�� by zhaopeng 2011.11.09
	BOOL					bShowName;					// �Ƿ���ʾ����	add by gtj	12.12.11

	// ����
	EAniType				eAnimationType;
	TCHAR					szModelName[X_LONG_NAME];	// ģ������
    TCHAR					szTexPostfix[X_SHORT_NAME]; // ��ͼ��׺
	TCHAR					szName[X_SHORT_NAME];		// ��������
	TCHAR					szFunction[X_SHORT_NAME];	// ����ְ������
	TCHAR					szTitle[X_SHORT_NAME];		// �ƺ�
	DWORD					szTitleClr;//!�ƺ���ɫ��add by slash
	TCHAR					szTitleIcon[X_SHORT_NAME];	// �ƺ���ͼ
	TCHAR					szFunctionIcon[X_SHORT_NAME];// ְ��ͼ��
	TCHAR					szEffect[X_SHORT_NAME];		// ��Ч���
	TCHAR					szIdleSpeech[X_LONG_NAME];	// ���к���
	TCHAR					szCombatSpeech[X_LONG_NAME];// ս������
	TCHAR					szSkillSpeech[X_LONG_NAME];	// ���ܺ���
	TCHAR					szDeathSpeech[X_LONG_NAME];	// ��������

    TCHAR                   szHeadIcon[X_LONG_NAME];    // ͷ��ͼƬ
    TCHAR					szChestMesh[X_LONG_NAME];	    // ����ģ��
    TCHAR					szChestTexPostfix[X_SHORT_NAME];// ������ͼ��׺
    TCHAR					szHeadMesh[X_LONG_NAME];	    // ͷ��ģ��
    TCHAR					szHeadTexPostfix[X_SHORT_NAME];	// ͷ����ͼ��׺
    TCHAR					szFaceMesh[X_LONG_NAME];	    // ����ģ��
    TCHAR					szFaceTexPostfix[X_SHORT_NAME];	// ������ͼ��׺
    TCHAR					szFeetMesh[X_LONG_NAME];	    // �Ų�ģ��
    TCHAR					szFeetTexPostfix[X_SHORT_NAME];	// �Ų���ͼ��׺
    TCHAR					szGlovesMesh[X_LONG_NAME];	    // �ֲ�ģ��
    TCHAR					szGlovesTexPostfix[X_SHORT_NAME];// �ֲ���ͼ��׺
    EAniType				eBackModelType;                 // ����ģ������
    TCHAR					szBackMesh[X_LONG_NAME];	    // ����ģ��    
    TCHAR                   szBackTagName[X_SHORT_NAME];    // �������ص�
    TCHAR					szBackTexPostfix[X_SHORT_NAME];	// ������ͼ��׺    
    EAniType				eWeaponModelType;               // ����ģ������
    TCHAR					szWeaponMesh[X_LONG_NAME];	    // ����ģ��
    TCHAR                   szWeaponTagName[X_SHORT_NAME];  // �������ص�
    TCHAR					szWeaponTexPostfix[X_SHORT_NAME];// ����ģ�ͺ�׺
    EAniType				eWeapon2ModelType;               // ����2ģ������
    TCHAR					szWeapon2Mesh[X_LONG_NAME];	    // ����2ģ��
    TCHAR                   szWeapon2TagName[X_SHORT_NAME];  // ����2���ص�
    TCHAR					szWeapon2TexPostfix[X_SHORT_NAME];// ����2ģ�ͺ�׺
    TCHAR                   szEaseEffect[X_SHORT_NAME];     // ���ж���ʱ������Ч

    TCHAR                   szTrackIdle[X_SHORT_NAME];      // ��ͨ����
    TCHAR                   szTrackRun[X_SHORT_NAME];       // ��
    TCHAR                   szTrackWalk[X_SHORT_NAME];      // ��
    TCHAR                   szTrackLie[X_SHORT_NAME];       // ����
    TCHAR                   szTrackAttack[X_SHORT_NAME];    // ��ͨ����
    TCHAR                   szTrackReady[X_SHORT_NAME];     // ս������
    TCHAR                   szTrackBeAttack[X_SHORT_NAME];  // ������
	TCHAR					szTrackDazzy[X_SHORT_NAME];     // ����
	TCHAR					szTrackDead[X_SHORT_NAME];      // ����
	TCHAR					szTrackHitFly[X_SHORT_NAME];    // ����

	tagCreatureProto()
	{
		memset(this, 0, sizeof(*this));
		pNest = NULL;
	}

	~tagCreatureProto()
	{
		if( pNest )
			delete pNest;
	}

	BOOL is_boss()const
	{
		return  eLite == ER_FieldWordBoss || eLite == ER_QuestBoss || eLite == ER_InstNormalBoss || eLite == ER_InstHeroBoss;
	}
};

//---------------------------------------------------------------------
// �������Ӫ��ϵ
//---------------------------------------------------------------------
struct tagCreatureCamp
{
	ECamp					eCamp;						// ��Ӫ
	ECampConnection			eCampConnection[ECA_End];	// ��Ӫ��ϵ
};

//---------------------------------------------------------------------
// �����AI�ṹ
//---------------------------------------------------------------------
const INT X_MAX_CREATURE_AI_BUFF	=	3;	// ����AI���������Buff����
const INT X_MAX_CREATURE_AI_SKILL	=	5;	// ����AI��������༼������

struct tagCreatureAI
{
	DWORD		dwID;										// AI ID;
	EAIACTION	eAIAction;									// AI��Ϊ����
	DWORD		dwGroupID;									// AI��ID
	DWORD		dwBuffTypeID[X_MAX_CREATURE_AI_BUFF];		// ��ʼ��3��buff ID
	DWORD		dwTriggerID[X_MAX_CREATURE_AI_SKILL];		// 5��������
	DWORD		dwSkillTypeID[X_MAX_CREATURE_AI_SKILL];		// 5������ID
	INT			nTargetType[X_MAX_CREATURE_AI_SKILL];		// ���ܶ�Ӧ��Ŀ������
};

const INT	X_MAX_FLEE_RADIUS			=	2000;				// �����������뾶
const INT	X_MIN_FLEE_RADIUS			=	1500;				// ����������С�뾶
const INT	X_RANGE_FLEE_RADIUS			=	X_MAX_FLEE_RADIUS - X_MIN_FLEE_RADIUS;			// ���ܰ뾶��ֵ
const FLOAT X_MAX_SOS_RADIUS			=	10000;				// ����״̬��������ܾ���
const FLOAT	X_MAX_SOS_RADIUS_SQ			=	X_MAX_SOS_RADIUS * X_MAX_SOS_RADIUS;
	

