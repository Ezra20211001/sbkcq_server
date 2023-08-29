#pragma once
#include "base_define.h"

#define TILE_SCALE 48
#define	VIS_DIST 64	// ���ӵ�ש�Ĵ�С��64�����ӣ�

//-----------------------------------------------------------------------------
// ��ͼ����
//-----------------------------------------------------------------------------
enum EMapType
{
	EMT_Normal				=	0,		// ��ͨ��ͼ
	EMT_Instance			=	1,		// ��ͨ�����������������������������
	EMT_System				=	2,		// ϵͳ�������ȶ��������������£����ִ壩
	EMT_PVP					=	3,		// PVP�͸���
	EMT_Build				=	4,		// ��������
	EMT_ScriptCreate		=	5,		// �ű������ĸ���
	EMT_Guild				=   6,		// ���帱��
	EMT_1v1					=	7,		// 1v1����
	EMT_SBK					=	8,		// ɳ�Ϳ�
	EMT_PVP_BIWU			=	9,		// PVP�ͱ��丱��
	EMT_Battle				=	10,		// ս��
};

enum EMapOpenType
{
	EMOT_Normal				=	0,		// �ɴ򿪡���Ѱ·
	EMOT_OnlyOpen			=	1,		// ֻ�ܴ�
	EMOT_Non				=	2,		// ���ɴ�Ҳ����Ѱ·
};

//-----------------------------------------------------------------------------
// ��ͼ������
//-----------------------------------------------------------------------------
enum ENormalMapType
{
	ENMT_Normal			=	0,		// Ұ��
	ENMT_City			=	1,		// ����
	ENMT_Dragon			=	2,		// ���³�
	ENMT_Activity		=	3,		// �����
	// ��ճǣ�
};


//-----------------------------------------------------------------------------
// ����������
//-----------------------------------------------------------------------------
enum EInstanceMapType
{
	EIMT_Normal			=	0,		// ��ͨ
	EIMT_Rand			=	1,		// ��� ���ڱ�Ǵ�С�Ǹ���
	EIMT_PVP			=	2,		// PVP
	EIMT_Preface		=	3,		// ����
	EIMT_Build			=	4,		// ����
	EIMT_Single			=	5,		// ����
};

//------------------------------------------------------------------------------
// �����Ѷ�
//------------------------------------------------------------------------------
enum EInstanceHardMode
{
	EIHM_NULL			=  -1,
	EIHM_Normal			=	0,		// ��ͨ
	EIHM_Elite			=	1,		// ��Ӣ
	EIHM_Devil			=	2,		// ħ��
};


//------------------------------------------------------------------------------
// �������ݹ���
//------------------------------------------------------------------------------
enum EInstanceCreateMode
{
	EICM_Appoint		=	0,		// ָ��
	EICM_AvgLevel		=	1,		// ����ƽ���ȼ�
	EICM_LeaderLevel	=	2,		// �ӳ��ȼ�
	EICM_MaxLevel		=	3,		// С����ߵȼ�
	EICM_MinLevel		=	4,		// С����͵ȼ�
};

//------------------------------------------------------------------------------
// ��������
//------------------------------------------------------------------------------
enum EEnterLimit
{
	EEL_NULL			=	0,		// ��
	EEL_Week			=	1,		// ������
	EEL_Day				=	2,		// ������
};

//------------------------------------------------------------------------------
// ��������
//------------------------------------------------------------------------------
enum EExportMode
{
	EEM_Born			=	0,		// ������
	EEM_Reborn			=	1,		// �����
	EEM_Appoint			=	2,		// ָ������
	EEM_Current			=	3,		// ԭ��
};

//------------------------------------------------------------------------------
// �����¼�
//------------------------------------------------------------------------------
enum ERebornMode
{
	EDE_NULL			=	0,		
	EDE_Leave			=	1,		// �������뿪����
	EDE_Current			=	2,		// �Զ�ԭ�ظ���
	EDE_Appoint			=	3,		// �Զ�ָ���ظ���
};

//------------------------------------------------------------------------------
// �������
//------------------------------------------------------------------------------
enum ECompleteConditionNor
{
	// ��ͨ�Ѷ�
	ECC_NorInsistTime		=	0,		// ���ʱ��
	// dwCompleteVal1: ʱ��
	// dwCompleteVal2: ����
	ECC_NorRoleNum			=	1,		// �������
	// dwCompleteVal1: ʱ��
	// dwCompleteVal2: ����
	ECC_NorKillAllMon		=	2,		// ��չ���
	ECC_NorKillBoss			=	3,		// ��ɱָ������
	// dwCompleteVal1: ����ID
	// dwCompleteVal2: ����
	ECC_NorGetItem			=	4,		// ���ָ����Ʒ
	// dwCompleteVal1: ��ƷID
	// dwCompleteVal2: ����
};

enum ECompleteConditionEli
{
	// ��Ӣ�Ѷ�
	ECC_EliteInsistTime		=	0,		// ���ʱ��
	ECC_EliteRoleNum		=	1,		// �������
	ECC_EliteKillAllMon		=	2,		// ��չ���
	ECC_EliteKillBoss		=	3,		// ��ɱָ������
	ECC_EliteGetItem		=	4,		// ���ָ����Ʒ
};

enum ECompleteConditionDev
{
	// ħ���Ѷ�
	ECC_DevilInsistTime		=	0,		// ���ʱ��
	ECC_DevilRoleNum		=	1,		// �������
	ECC_DevilKillAllMon		=	2,		// ��չ���
	ECC_DevilKillBoss		=	3,		// ��ɱָ������
	ECC_DevileGetItem		=	4,		// ���ָ����Ʒ
};

//------------------------------------------------------------------------------
// ����������¼�
//------------------------------------------------------------------------------
enum ECompleteEvent
{
	ECE_NULL				=	0,	
	ECE_LeaveInstance		=	1,		// �뿪����
};

//--��ײ����ֵ����---------------------------------------------------------
enum ENavResult
{
	ENR_Failed=0,				//����ʧ�ܣ��������ϲ��߼�������
	ENR_Arrive,					//�����յ�
	ENR_Blocking,				//����ס
	ENR_ToBeContinued,			//���Լ�����ײ
};


//--Map�ļ�ͷ----------------------------------------------------------------------------
const char* const MapObjFileMagic ="GMB";
struct tagMapHeaderOld
{
	DWORD				dwMagic;
	DWORD				dwVer;

	DWORD				dwGlobalID;			//ȫ��ΨһID
	TCHAR				szSkyBoxTopTex[X_LONG_NAME];		// ��պ���������
	TCHAR				szSkyBoxFrontRightTex[X_LONG_NAME];	// ��պ�ǰ������
	TCHAR				szSkyBoxBackLeftTex[X_LONG_NAME];	// ��պк�������
	FLOAT				fSkyBoxXsize;		//��պ�X��С
	FLOAT				fSkyBoxYsize;		//��պ�Y��С
	FLOAT				fSkyBoxZsize;		//��պ�Z��С

	INT					nNumNPC;
	DWORD				dwNpcOffset;

	INT					nNumStaticObj;
	DWORD				dwStaticObjOffset;

	BYTE				byDistFog[16];
	BYTE				bySunLight[104];

	INT					nNumWayPoint;
	DWORD				dwWayPointOffset;

	INT					nNumTrigger;
	DWORD				dwTriggerOffset;

	INT					nNumSound;
	DWORD				dwSoundOffset;

	INT					nNumPointLight;		//���Դ����
	DWORD				dwPointLightOffset;	//���Դ���ļ��е�ƫ��λ��

	FLOAT				fSkyBoxOffX;		//��պ�Xƫ��
	FLOAT				fSkyBoxOffY;		//��պ�Yƫ��
	FLOAT				fSkyBoxOffZ;		//��պ�Zƫ��

	INT					nNumMapRect;		//��ͼ����ĸ���
	DWORD				dwMapRectOffset;	//��ͼ���������е�ƫ��λ��
	
	FLOAT				fSunModulus;		//̫������ǿϵ��
	FLOAT				fSkyYaw;			//��պ���ת��ɫ

	INT					nNumPathPoint;		//Ѱ·���������
	DWORD				dwPathPointOffset;	//Ѱ·���������ļ��е�ƫ��λ��

	INT					nNumSpawnPoint;		//ˢ�ֵ����
	DWORD				dwSpawnPointOffset; //ˢ�ֵ����ļ��е�ƫ��λ��

	INT					nNumDynamicBlock;	//��̬�ϰ������
	DWORD				dwDynamicBlockOffset;//��̬�ϰ������ļ��е�ƫ��λ��

	INT					nNumEventTrigger;	//�¼�����������
	DWORD				dwEventTriggerOffset;//�¼����������ļ��е�ƫ��λ��

	INT					nNumNPCNav;			//npc ���ӵ���ͼ����������
	DWORD				dwNPCNavOffset;

	INT					nNumPlayerNav;		//��Ҹ��ӵ���ͼ�������
	DWORD				dwPlayerNavOffset;

	BYTE				bySkyCol[16];

	BYTE				byRenderSkyShade;  //�Ƿ���ʾ�������
	DWORD               dwSkyShadeCol;     //������ֵ���ɫ

	INT					nNumMapDoor;		//��
	DWORD				dwMapDoorOffset;

	INT					nNumMapCarrier;
	DWORD				dwMapCarrierOffset;

	DWORD				dwDynamicDiffCol; // ��̬ƽ�й�diffuse
	DWORD				dwDynamicAmbCol;  // ��̬ƽ�й�Ambient
	DWORD				dwDynamicSpecCol; // ��̬ƽ�й�Specular

	INT					nNumMapTriggerEffect;		//������Ч
	DWORD				dwMapTriggerEffectOffset;

	DWORD				dwPlayDynamicDiff; // ���ﶯ̬ƽ�й�diffuse
	DWORD				dwPlayDynamicAmb;  // ���ﶯ̬ƽ�й�Ambient
	DWORD				dwPlayDynamicSpec; // ���ﶯ̬ƽ�й�Specular

	BYTE				byReserve[200-12-8-4-4-8-8-8-8-16-16-1-4-8-8-8-12-8-12];//12�Ǻ�ӵ���պ�ƫ�ƣ�-8Ϊ��ͼ��������, -4Ϊ̫������ǿϵ����-8ΪѰ·�����������ƫ��,-8Ϊˢ�ֵ����
														//-8Ϊ��̬�ϰ��� -8Ϊ�¼�������,16Ϊnpc ��Ҹ��ӵ���ͼ�������,-16���,-1�Ƿ���ʾ�������,-4������ֵ���ɫ,-8��,-8�ؾ�,-12��̬ƽ�й���ɫ
														//-8������Ч

	tagMapHeaderOld()
	{
		memset(this,0,sizeof(tagMapHeaderOld));
	}
};

#pragma pack(push)
#pragma pack(1)
#define SI_MAPOBJ_MAGIC_NUMBER	0x6A626F6D
#define SI_MAPOBJ_VERSION		55
struct tagMapHeader
{
	DWORD				dwMagic;
	DWORD				dwVer;

	DWORD				dwGlobalID;							//ȫ��ΨһID
	
	//! ��ͼ��������.
	TCHAR				szSkyBoxTopTex[X_LONG_NAME];		// ��պ���������
	TCHAR				szSkyBoxFrontRightTex[X_LONG_NAME];	// ��պ�ǰ������
	TCHAR				szSkyBoxBackLeftTex[X_LONG_NAME];	// ��պк�������
	FLOAT				fSkyBoxXsize;						// ��պ�X��С
	FLOAT				fSkyBoxYsize;						// ��պ�Y��С
	FLOAT				fSkyBoxZsize;						// ��պ�Z��С
	FLOAT				fSkyYaw;							// ��պ���ת��ɫ
	BYTE				bySkyCol[16];
	BYTE				byRenderSkyShade;  					// �Ƿ���ʾ�������
	DWORD               dwSkyShadeCol;     					// ������ֵ���ɫ
	FLOAT				fSkyBoxOffX;						// ��պ�Xƫ��
	FLOAT				fSkyBoxOffY;						// ��պ�Yƫ��
	FLOAT				fSkyBoxOffZ;						// ��պ�Zƫ��
	BYTE				bySunLight[104];
	FLOAT				fSunModulus;						// ̫������ǿϵ��
	BYTE				byDistFog[16];
	DWORD				dwDynamicDiffCol; 					// ��̬ƽ�й�diffuse
	DWORD				dwDynamicAmbCol;  					// ��̬ƽ�й�Ambient
	DWORD				dwDynamicSpecCol; 					// ��̬ƽ�й�Specular
	DWORD				dwPlayDynamicDiff; 					// ���ﶯ̬ƽ�й�diffuse
	DWORD				dwPlayDynamicAmb;  					// ���ﶯ̬ƽ�й�Ambient
	DWORD				dwPlayDynamicSpec; 					// ���ﶯ̬ƽ�й�Specular

	//! ��ͼ�������.
	INT					nNumStaticObj;
	DWORD				dwStaticObjOffset;

	INT					nNumNPC;
	DWORD				dwNpcOffset;

	INT					nNumWayPoint;
	DWORD				dwWayPointOffset;

	INT					nNumTrigger;
	DWORD				dwTriggerOffset;

	INT					nNumSound;
	DWORD				dwSoundOffset;

	INT					nNumPointLight;			// ���Դ����
	DWORD				dwPointLightOffset;		// ���Դ���ļ��е�ƫ��λ��

	INT					nNumMapRect;			// ��ͼ����ĸ���
	DWORD				dwMapRectOffset;		// ��ͼ���������е�ƫ��λ��

	INT					nNumPathPoint;			// Ѱ·���������
	DWORD				dwPathPointOffset;		// Ѱ·���������ļ��е�ƫ��λ��

	INT					nNumSpawnPoint;			// ˢ�ֵ����
	DWORD				dwSpawnPointOffset; 	// ˢ�ֵ����ļ��е�ƫ��λ��

	INT					nNumDynamicBlock;		// ��̬�ϰ������
	DWORD				dwDynamicBlockOffset;	// ��̬�ϰ������ļ��е�ƫ��λ��

	INT					nNumEventTrigger;		// �¼�����������
	DWORD				dwEventTriggerOffset;	// �¼����������ļ��е�ƫ��λ��

	INT					nNumNPCNav;				// npc ���ӵ���ͼ����������
	DWORD				dwNPCNavOffset;

	INT					nNumPlayerNav;			// ��Ҹ��ӵ���ͼ�������
	DWORD				dwPlayerNavOffset;

	INT					nNumMapDoor;			// ��
	DWORD				dwMapDoorOffset;

	INT					nNumMapCarrier;
	DWORD				dwMapCarrierOffset;

	INT					nNumMapTriggerEffect;	//������Ч
	DWORD				dwMapTriggerEffectOffset;

	DWORD				dwSpawnPointExtInfoOffset;	//! ˢ�ֵ㸽����Ϣƫ��, 0 ��ʾû�и�����, �������ݵĸ�����ˢ�ֵ�ĸ���������.

	BYTE				byReserve[60];

	tagMapHeader()
	{
		memset(this,0,sizeof(tagMapHeader));
	}
};
#pragma pack(pop)

//--��̬����----------------------------------------------------------------------------
struct tagStaticMapObj
{
	DWORD				dwMapID;			//��������map�е�id
	TCHAR				szMdlPath[MAX_PATH];//ģ��
	FLOAT				fPos[3];
	FLOAT				fRotate[3];
	FLOAT				fScale[3];

	TCHAR				szScriptName[32];	//���鴥����������ű�����
	DWORD				dwPickItemID;		//����֮����Լ������ƷID

	bool				bLock;				//�ж��Ƿ�������,��ͼ�༭��ʹ��
	bool				bFlag;
	bool				bShowMiniMap;		//�Ƿ���С��ͼ����ʾ
	bool				bLightMap;			//LightMap���أ���ʽ��bool��ȱʡֵ��true
	bool				bGenLightMap;		//! �Ƿ�������ɹ���ͼ.
	BYTE				byReserved[7];		//bool	bHighLight;			//�߹�Ч�����أ���ʽ��bool��ȱʡֵ��true
											//FLOAT	fHiLightIntensity;	//�߹�ǿ�ȣ���ʽ��float��ȱʡֵ��1.4
	BYTE				byViewLevel;		//��Ұ���룬��ʽ��byte��ȱʡֵ��0	0-�Զ����� 1-�� 2-�� 3-Զ
	bool				bPathfinding;		//�Ƿ��Զ�Ѱ��
	BYTE				bSurfaceType;		//�������ͣ������ڲ�����Ч��
	float				fMtlDiffuseFactor;	//�����������ǿϵ��
	bool				bNoShadow;			//��������Ӱ ȱʡֵ:false������Ӱ true��������Ӱ
	bool				bNotSupportNPCNavMap;//��֧��NPC���ӵ���ͼ

	BYTE				byBoxSize;			//�������ɵ���ײ�д�С
	TCHAR				name[16];			//��̬���������.
	DWORD				mirrorFlag;			// ������.
	DWORD				collideFlag;		// ��ײ���.
    bool                bFixTerrain;        //�Ƿ��ںϵ���    [2010.08.04 zhaopeng]
	float				animSpeed;			// �������ŵ��ٶ�.
	BYTE				byReserve[83 - 16*sizeof(TCHAR) - sizeof(DWORD) - sizeof(DWORD) - sizeof(bool)];

	tagStaticMapObj()
	{
		memset(this,0,sizeof(*this));
		fScale[0]=fScale[1]=fScale[2]=1.0f;
		fMtlDiffuseFactor=1.5f;
		byBoxSize = 0;
		animSpeed = 1.0f;
	}
};

//--�¼�������-----------------------------------------------------------------
enum ETiggerCondition						//��������
{
	ETC_Null=0,
};

enum ETiggerResult							//�������
{
	ETR_Null=0,
};

struct tagMapEventTrigger			
{
	DWORD				dwObjID;
	ETiggerCondition	eCondition;			//����
	DWORD				dwConditionParam1;	//��������1
	DWORD 				dwConditionParam2;	//��������2
	ETiggerResult		eResult;			//���
	DWORD				dwResultParam1;		//�������1
	DWORD				dwResultParam2;		//�������2

	bool				bLock;
	bool				bFlag;
	BYTE				byReserve[128];

	tagMapEventTrigger(){ memset(this, 0, sizeof(*this)); }
};

//--������---------------------------------------------------------------------
enum EMapTrigger							//����������
{
	EMT_Null=0,
	EMT_GotoNewMap,							//�����л�����
	EMT_Script,								//�ű�����
	EMT_GotoSBK,							//ɳ�Ϳ˻ʹ�����
};

struct tagMapTrigger
{
	DWORD 				dwObjID;
	EMapTrigger			eType;				//����
	FLOAT				fHeight;			//�߶�
	TCHAR				szMapName[X_LONG_NAME];		//EMT_GotoNewMap ��Ŀ���ͼ
	TCHAR				szWayPoint[X_SHORT_NAME];    	//EMT_GotoNewMap ��Ŀ���ͼλ��
	TCHAR				szScriptName[X_SHORT_NAME];	//EMT_Script �Ľű�����
	DWORD				dwParam;			//����

	bool				bLock;
	bool				bFlag;
	DWORD				dwQuestSerial;
	BYTE				byReserve[124];

	tagMapTrigger() 
	{ 
		dwObjID = 0;
		eType = EMT_Null;
		fHeight = 0.0f;
		memset(szMapName, 0, sizeof(szMapName));
		memset(szWayPoint, 0, sizeof(szWayPoint));
		memset(szScriptName, 0, sizeof(szScriptName));
		dwParam = 0;
		bLock = false;
		bFlag = false;
		memset(byReserve, 0, sizeof(byReserve));
	}	
};

enum EAppearAreaType
{
	EAAT_World = 0,
	EAAT_Area ,
};
//--��ͼ����------------------------------------------------------------------
enum EMapArea								//��ͼ��������
{
	EMA_Null=0,
	EMA_PVP,								//PVP����
	EMA_Safe,								//��ȫ����
	EMA_Stall,								//��̯����
	EMA_Prison,								//��������
	EMA_Display,							//��ʾ����
	EMA_Script,								//�ű�����
	EMA_Common,								//��ͨ��
	EMA_RealSafe,							//���԰�ȫ��
	EMA_GuildBattle,						//���ս��
	EMA_NoPunish,							//�޳ͷ���
	EMA_Hang,								//�һ���
	EMA_UnDuel,								//PK��ֹ����
	EMA_KongFu,								//����
	EMA_Comprehend,							//����
	EMA_Dancing,							//��ֹ���
};

struct tagMapArea					
{
	DWORD 				dwObjID;
	EMapArea			eType;				//����
	FLOAT				fHeight;			//�߶�

	bool				bLock;
	bool				bFlag;
	DWORD               dwMiniMapSize;      //����ͼ��С
	bool                bDistFog;           //�Ƿ񵥶�������
	BYTE				byDistFog[16];      //��
	BYTE				byReserve[107];

	tagMapArea() 
	{ 
		dwObjID = 0;
		eType = EMA_Null;
		fHeight = 0.0f;
		bLock = false;
		bFlag = false;
		dwMiniMapSize=0;
		bDistFog=false;
		memset(byDistFog, 0, sizeof(byDistFog));
		memset(byReserve, 0, sizeof(byReserve));
	}
};


//--������------------------------------------------------------------------
struct tagMapWayPoint
{
	DWORD 				dwObjID;			
	Vector3				vPos;				//���ӵײ���������
	Vector3				vRange;				//��Χ	
	TCHAR				szName[X_SHORT_NAME];//����������
	BYTE				byIndex;			//����ֵ

	bool				bLock;
	bool				bFlag;
	FLOAT				fSuspend;			//�ؾ�ͣ��ʱ�� add xtian 2009-4-14
	FLOAT				fYaw;				// ����, ��λ�Ƕ�.
	BYTE 				byReserve[32-4-4];	//-4�ؾ�ͣ��ʱ��,-4����.

	tagMapWayPoint() { memset(this, 0 ,sizeof(*this)); }
};

//--NPC---------------------------------------------------------------------
struct tagMapNPC
{
	DWORD 				dwObjID;
	DWORD 				dw_data_id;			//����ID
	Vector3				vPos;				//��ʼ����
	FLOAT 				fYaw;				//��ʼ����
	TCHAR				szName[X_SHORT_NAME];//Ѳ�ߵ���������
	bool				bCollide;			//ʹ����ײ��

	bool				bLock;
	bool				bFlag;
	FLOAT				fRadius;			//��Ѩ�뾶
	BYTE				byReserve[32-5];	//-5Ϊ��Ѩ�뾶

	tagMapNPC() { memset(this, 0 ,sizeof(*this)); }
};

//--Ѱ·������--------------------------------------------------------------
struct tagMapPathPoint
{
	DWORD 				dwObjID;
	Vector3 			vPos;				//����
	//FLOAT 				fRange;				//��Χ
	BYTE				byReserve1[4];

	bool				bLock;
	bool				bFlag;
	BYTE				byReserve[32];

	tagMapPathPoint() { memset(this, 0 ,sizeof(*this)); }
};


//--ˢ�ֵ�------------------------------------------------------------------
struct tagMapSpawnPoint
{
	DWORD 				dwObjID;
	Vector3				vPos;				//����

	bool				bLock;				
	bool				bFlag;
	bool				bCollide;			//�Ƿ���ײ add by xtian 2008-12-29
	DWORD				dwGroupID;			//������ID add by xtian 2008-12-29
	INT					nLevelInc;			//�����������ȼ�������
	char				navName[7];			//����������.


	tagMapSpawnPoint() { memset(this, 0 ,sizeof(*this)); }
};

struct tagMapSpawnPointExtInfo 
{
	DWORD				dwSpawnPointGroupID;	//! ˢ�ֵ���ID.
	FLOAT				fAngle;					//! ˢ�ֵ㷽��. ��λ�Ƕ�
	BYTE				byReserve[28];

	tagMapSpawnPointExtInfo() { memset( this, 0, sizeof(*this) ); }
};

//--��̬�ϰ���--------------------------------------------------------------
struct tagMapDynamicBlock
{
	DWORD				dwObjID;
	Vector3				vPos;				//����
	FLOAT				fYaw;				//����	
	FLOAT				fScale[3];			//����
	TCHAR				szModelPath[X_LONG_NAME];//ģ���ļ�·��

	bool				bLock;				
	bool				bFlag;
	BYTE				byReserve[128];

	tagMapDynamicBlock() { memset(this, 0 ,sizeof(*this)); }
};

//--���Դ------------------------------------------------------------------
struct tagMapPointLight
{
	DWORD				dwID;
	FLOAT				fPos[3];
	FLOAT				ambient[4];			//������
	FLOAT				diffuse[4];			//������
	FLOAT				specular[4];		//�����
	FLOAT				range;				//Ӱ�췶Χ
	FLOAT				attenuation[3];		//1, D, D^2;
	bool				bLock;
	bool				bFlag;
	bool				bDynamicPL;			//��̬��Դ bool Ĭ���Ƕ�̬��Դ
	FLOAT				fIncModulus;		//��ǿϵ�� float Ĭ��1.0�������ڴ���0�ķ�Χ�ڵ���
	FLOAT				fnoBlockRange;		//���ڵ���Χ
	BYTE				byReserve[20-5-4];

	tagMapPointLight() { memset(this, 0 ,sizeof(*this)); }
};

//--��ʾ���������Ϣ--------------------------------------------------------
struct tagMapAreaEx
{
	DWORD				dwObjID;
	tstring				strTitle;			//������ʾͼƬ����
	tstring				strMusic[3];		//���Ÿ�������
	WORD				wInterval;			//���Ÿ���ʱ����
	BYTE				byVol;				//���Ÿ�������ϵ��
	BYTE				byPriority;			//���ȼ�
};

//--3D��Ч------------------------------------------------------------------
struct tagMapSound
{
	DWORD				dwObjID;
	FLOAT				fPos[3];				//λ��
	FLOAT				fRange;					//��Χ
	TCHAR				szFileName[X_LONG_NAME];//��Ч�ļ�·��
	FLOAT				fVolume;				//����
	FLOAT				fNoAtteRange;			//û��˥���ķ�Χ

	bool				bLock;
	bool				bFlag;

	DWORD				dwInterval;				//�೤ʱ�䲥��һ����Ч

	BYTE				byReserve[28];

	tagMapSound() { memset(this, 0 ,sizeof(*this)); }
};

//--NPC���ӵ���ͼ�������-----------------------------------------------------
struct tagNPCNavMapBuildStartPoint
{
	DWORD 				dwObjID;
	Vector3 			vPos;				//����

	bool				bLock;
	bool				bFlag;
	BYTE				byReserve[32];

	tagNPCNavMapBuildStartPoint() { memset(this, 0 ,sizeof(*this)); }
};

//--���Ѱ·����ͼ�������-----------------------------------------------------
struct tagPlayerNavMapBuildStartPoint
{
	DWORD 				dwObjID;
	Vector3 			vPos;				//����

	bool				bLock;
	bool				bFlag;
	BYTE				byReserve[32];

	tagPlayerNavMapBuildStartPoint() { memset(this, 0 ,sizeof(*this)); }
};

//-------------------------------------------------------------------------------
// ������Ϣ
//-------------------------------------------------------------------------------
struct tagInstance
{
	DWORD					dwMapID;						// ��ͼID

	DWORD					dwEndTime;						// �ȴ��ر�ʱ��
	DWORD					dwTimeLimit;					// ʱ������

	EInstanceMapType		eInstanceMapType;				// ��������
	EInstanceCreateMode		eInstanceCreateMode;			// �������ݹ���

	INT						nIndex;							// ����������
	EEnterLimit				eInstanceEnterLimit;			// ��������
	DWORD					dwEnterNumLimit;					// ���ƽ������
	BOOL					bClearNumLimit;					// �Ƿ�����Ȩֵ

	DWORD					dwItemID;						// ������Ʒ
	DWORD					dwLgnoreItemID;					// ���Եȼ���ƷID

	INT						nProcessYB;						// ���ø�������Ԫ��
	INT						nResetLimitYB;					// ���ø���ȨֵԪ��
	
	bool					bAskEnter;						// �����Ƿ�Ѱ��
	bool					bSelectHard;					// �Ƿ�ѡ���Ѷ�
	bool					bSelectNormal;					// �Ƿ��ѡ��ͨ
	bool					bSelectElite;					// �Ƿ��ѡ��Ӣ
	bool					bSelectDevil;					// �Ƿ��ѡħ��
	bool					bNoticeTeamate;					// �Ƿ�֪ͨ����

	INT						nNumDownLimit;					// ��������	
	INT						nNumUpLimit;					// ��������
	INT						nLevelDownLimit;				// �ȼ�����
	INT						nLevelUpLimit;					// �ȼ�����

	INT						nLevelEliteDownLimit;			// ��Ӣ�ȼ�����
	INT						nLevelEliteUpLimit;				// ��Ӣ�ȼ�����

	INT						nLevelDevilDownLimit;				// ħ���ȼ�����
	INT						nLevelDevilUpLimit;				// ħ���ȼ�����

	DWORD					coolDownReviveID;
	EExportMode				eExportMode;					// ��������
	DWORD					dwExportMapID;					// ���ڵ�ͼID
	DWORD					dwExportWayPoint;				// ���ڵ�����ID
	DWORD					dwEnterWayPoint;				// ���뵼����ID
	DWORD					dwEnemyEnterPoint;				// ���˽��뵼����ID
	//Vector3					vExportPos;						// ��������
	//Vector3					vEnterPos;						// �������������
	//Vector3					vEnemyEnterPos;					// �����ڵ����������
	DWORD					dwRelivePos[3];					//�����������

	DWORD					dwTargetLimit;					// �ɹ���Ŀ������
	bool					bCombat;						// �Ƿ��ս��
	bool					bPK;							// �Ƿ��PK
	bool					bLoseSafeguard;					// �Ƿ�PK����ʧЧ
	bool					bPKPenalty;						// �Ƿ���PK�ͷ�
	bool					bDeadPenalty;					// �Ƿ��������ͷ�
	bool					bMount;							// �Ƿ�����
	bool					bTransmit;						// �Ƿ�ɴ���
	ERebornMode				eRebornMode;					// ���ʽ

	ECompleteConditionNor	eCompleteNor;					// ��ͨ�������
	DWORD					dwCompleteNorVal1;
	DWORD					dwCompleteNorVal2;	

	ECompleteConditionEli	eCompleteEli;					// ��Ӣ�������
	DWORD					dwCompleteEliVal1;
	DWORD					dwCompleteEliVal2;

	ECompleteConditionDev	eCompleteDev;					// ħ���������
	DWORD					dwCompleteDevVal1;
	DWORD					dwCompleteDevVal2;

	ECompleteEvent			eCompleteEvent;					// ����������¼�

	INT						nActID;							// �ID

	BYTE					byConsolidateLevelMin;			// ������Сǿ���ȼ�

	DWORD					dw_guild_flag;					// ������ĵ�����
};


//--��--------------------------------------------------------------
struct tagMapDoor
{
	DWORD				dwObjID;
	Vector3				vPos;				//����
	FLOAT				fYaw;				//����	
	FLOAT				fScale[3];			//����
	TCHAR				szModelPath[X_LONG_NAME];//ģ���ļ�·��
	BOOL				bInitState;			//��ʼ״̬��TRUE�򿪣�FALSE�ر�		
	BOOL				bBlockingTileNPC;	//�Ƿ��赲���ӵ���NPC
	bool				bLock;				
	bool				bFlag;
	DWORD				dw_data_id;			//�ŵ�typeid
	BYTE				byReserve[124];

	tagMapDoor() { memset(this, 0 ,sizeof(*this)); }
};


//--�ؾ�-------------------------------------------------------------
struct tagMapCarrier
{
	DWORD				dwObjID;
	TCHAR				szModelPath[X_LONG_NAME];	//ģ���ļ�·��
	TCHAR				szWayPoint[X_SHORT_NAME];	//����������
	FLOAT				fYaw;						//����	
	BYTE				bSurfaceType;				//�������ͣ������ڲ�����Ч��
	FLOAT				fSpeed;						//�ƶ��ٶ�

	bool				bLock;				
	bool				bFlag;
	BYTE				byReserve[128];

	tagMapCarrier() { memset(this, 0 ,sizeof(*this)); }
};

//--������Ч----------------------------------------------------------
struct tagMapTriggerEffect
{
	DWORD				dwObjID;				//��������map�е�id
	TCHAR				szMdlPath[MAX_PATH];	//��Ч·�����ļ�
	FLOAT				fPos[3];
	FLOAT				fRotate[3];
	FLOAT				fScale[3];

	bool				bLock;				
	bool				bFlag;
	BYTE				byReserve[64];			//�����ֽ�

	tagMapTriggerEffect()
	{
		memset(this,0,sizeof(*this));
		fScale[0]=fScale[1]=fScale[2]=1.0f;
	}
};

