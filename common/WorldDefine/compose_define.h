#pragma once

#include "ItemDefine.h"

#pragma pack(push, 1)

#define MAX_CONSOLIDATE_POS_QUANTITY 11
#define MAX_CONSOLIDATE_STUFF_QUANTITY 6
#define MAX_PRODUCE_STUFF_QUANTITY 4
#define MAX_CONSOLIDATE_ROLEATT 3
#define MAX_OUTPUT_QUANTITY	6
#define MAX_XIULIAN_ITEM_NUMBER 10
#define MAX_EQUIP_CHANGE_STUFF_QUANTITY 2

#define CHISEL_NEED_MONERY 5
//��������
enum EProduceType
{
	EPCT_NULL			= 0,
	EPCT_Artisan		= 1,		//����1
	EPCT_DanTraining	= 2,		//����
	EPCT_Smith			= 3,		//����
	EPCT_Casting		= 4,		//����4
	EPCT_Dressmaker		= 5,		//�÷�5
	EPCT_Aechnics		= 6,		//����6
	EPCT_Smilt			= 7,		//���Ϻϳ�
	EPCT_PointUp		= 8,		//�ֽ�
};
//�ϳ�����(�������͵�����)
enum EComposeType
{
	ECOMT_NULL = 0,
	ECOMT_WeaponMake		= 10,		//װ������		
	ECOMT_LoricaeMake		= 20,		//��������				
	ECOMT_DecorateMake		= 30,		//��Ʒ����		
	ECOMT_Refine			= 40,		//���Ϻϳ�
	ECOMT_EquipdDecompose	= 50,		//װ���ֽ�		
};	

//ÿ�����������ĺϳ���������
#define ArtisanSubTypeQuan		1
#define DanTrainingSubTypeQuan	1
#define SmithSubTypeQuan		1
#define CastingSubTypeQuan		1
#define DressmakerSubTypeQuan	1
#define AechnicsSubTypeQuan		1
#define SmiltSubTypeQuan		1
#define PointUpSubTypeQuan		1
#define GodArtisanSubTypeQuan	1
#define PetSubTypeQuan			1

//�ϳ��䷽����
enum EFormulaType
{
	EFORMT_NULL	= 0,
	EFORMT_OreRefine,		//��ʯ�ᴿ	1
	EFORMT_Glave,			//��			
	EFORMT_Sword,			//��			
	EFORMT_Halberd,			//����		
	EFORMT_Bow,				//��			
	EFORMT_SmallOrgan,		//С�ͷ���	
	EFORMT_BigOrgan,		//���ͷ���	
	EFORMT_Instrument,		//��			
	EFORMT_Millstone,		//ħʯ		
	EFORMT_Armet,			//ͷ��		
	EFORMT_UpperLoricae,	//�������	
	EFORMT_LowerLoricae,	//�������	
	EFORMT_Armguard,		//����		
	EFORMT_BattleShoe,		//սѥ		
	EFORMT_Roll,			//������		
	EFORMT_Cap,				//ñ��		
	EFORMT_Jupe,			//����		
	EFORMT_Pants,			//����		
	EFORMT_Glove,			//����		
	EFORMT_Shoe,			//Ь��		
	EFORMT_2Gem,			//������ʯ
	EFORMT_3Gem,			//������ʯ
	EFORMT_4Gem,			//�ļ���ʯ
};

//�䷽��Դ
enum EFormulaFrom
{
	EFormulaFrom_NULL			= 0,
	EFormulaFrom_Skill			= 1,			//����
	EFormulaFrom_NPC			= 2,			//NPC
	EFormulaFrom_Item			= 3,			//��Ʒ
	EFormulaFrom_SkillorNPC		= 4,			//���ܼ�NPC
	EFormulaFrom_SkillorItem	= 5,			//���ܼ���Ʒ
	EFormulaFrom_NPCorItem		= 6,			//NPC����Ʒ
};

//װ��ǿ������
enum EConsolidateType
{
	ECliDateT_NULL 		= 0,		//��
	ECliDateT_Posy		= 1,		//����
	ECliDateT_Engrave	= 2,		//�Կ�
	ECliDateT_Quench,				//���
};

//ǿ����������
enum EPosyAtt
{
	EPosyAtt_NULL		= 0,	//��	
	EPosyAtt_MaxHP		= 1,    //�������
	EPosyAtt_MaxMP		= 2,	//�������
	EPosyAtt_ExAttack	= 3,	//�⹦����
	EPosyAtt_InAttack	= 4,	//�ڹ�����
	EPosyAtt_ExDefense	= 5,	//�⹦����
	EPosyAtt_InDefense	= 6,	//�ڹ�����

	EPosyAtt_End,
};
//ǿ���Կ�����
enum EEngraveAtt
{
	EEngraveAtt_NULL		= 0,	//��
	EEngraveAtt_WeaponDmg	= 1,	//�����˺�
	EEngraveAtt_WeaponSoul  = 2,	//���
	EEngraveAtt_Armor		= 3,	//���߻���(��)
	EEngraveAtt_Deration	= 4,	//���߻���(��)
	EEngraveAtt_End,
};

//�������
enum EQuenchType
{
	EEQuenchType_Metal		= 0,	//���
	EEQuenchType_Wood,				//ľ��
	EEQuenchType_Water,				//ˮ��
	EEQuenchType_Fire,				//���
	EEQuenchType_Soil,				//����
};


//��ǿ��װ����λ
struct tagConsolidatePos
{
	EEquipPos ePos;
	BYTE	  byConsolidate;
};

//ǿ������
struct tagConsolidateStuff
{
	DWORD				dwStuffID;			//����ID
	EStuffType			eStuffType;			//��������
	DWORD				dwStuffNum;			//��������
};

//�����ϳɲ���
struct tagProduceSutff
{
	DWORD				dwStuffID;			//����ID
	//EStuffType			eStuffType;			//��������
	DWORD				dwStuffNum;			//��������	
};

//���ƽṹ��
struct tagPosyProto
{

	DWORD				dwID;					//�䷽ID
	TCHAR				szName[X_SHORT_NAME];	//�䷽����
	EPosyAtt			ePosyAtt;				//��������
	BYTE				byPosyTimes;			//���ƴ���
	INT					nSuccessRate;			//�ɹ���
	DWORD				dwProduceTime;			//������ʱ
	DWORD				dwPotValConsume;		//Ǳ��ֵ����
	DWORD				dwMoneyConsume;			//��Ǯ����
	FLOAT 				fcoefficientA; 			//���Լ�ֵ��ʽ����A
	FLOAT 				fcoefficientB; 			//���Լ�ֵ��ʽ����B
	FLOAT 				fcoefficientC; 			//���Լ�ֵ��ʽ����C
	tagConsolidateStuff	ConsolidateStuff[MAX_CONSOLIDATE_STUFF_QUANTITY]; //ǿ������
	tagConsolidatePos   ConsolidatePos[MAX_CONSOLIDATE_POS_QUANTITY];	//��ǿ��װ����λ
};

//�Կ̽ṹ��
struct tagEngraveProto
{

	DWORD				dwID;					//�䷽ID
	TCHAR				szName[X_SHORT_NAME];	//�䷽����
	EEngraveAtt			eEngraveAtt;			//�Կ�����
	BYTE				byEngraveTimes;			//�Կ̴���
	INT					nSuccessRate;			//�ɹ���
	DWORD				dwProduceTime;			//������ʱ
	DWORD				dwPotValConsume;		//Ǳ��ֵ����
	DWORD				dwMoneyConsume;			//��Ǯ����
	FLOAT 				fcoefficientA; 			//���Լ�ֵ��ʽ����A
	FLOAT 				fcoefficientB; 			//���Լ�ֵ��ʽ����B
	FLOAT 				fcoefficientC; 			//���Լ�ֵ��ʽ����C
	tagConsolidateStuff	ConsolidateStuff[MAX_CONSOLIDATE_STUFF_QUANTITY]; //ǿ������
	tagConsolidatePos   ConsolidatePos[MAX_CONSOLIDATE_POS_QUANTITY];	//��ǿ��װ����λ
};

//�������
struct tagQuenchAtt
{
	EWuXing				eWuXing;
	INT					nWuXingValue;
};

//���ṹ��
struct tagQuenchProto
{
	DWORD				dwID;					//�䷽ID
	TCHAR				szName[X_SHORT_NAME];	//�䷽����
	EQuenchType			eQuenchType;			//�������
	tagQuenchAtt		srcQuenchAtt;			//ԭ���Լ�����ֵ
	tagQuenchAtt		dstQuenchAtt;			//Ŀ�����Լ�����ֵ
	DWORD				dwPotValConsume;		//Ǳ��ֵ����
	DWORD				dwMoneyConsume;			//��Ǯ����
	INT					nSuccessRate;			//�ɹ���
	DWORD				dwProduceTime;			//������ʱ
	tagConsolidateStuff	ConsolidateStuff[MAX_CONSOLIDATE_STUFF_QUANTITY]; //ǿ������
};
enum EPClass
{
	EPC_NULL = 0,
	EPC_MJ ,  //�ͽ�
	EPC_SB,
	EPC_YX,
	EPC_CK,
	EPC_YS,
};

enum EPPart
{
	EPPA_Null =0,
	EPP_Weapon1,   //����һ
	EPP_Weapon2,			//������
	EPP_Head,		 //3		
	EPP_InnerArmor,
	EPP_Smock,    //����
	EPP_Armor,
	EPP_Cuff,        //����
	EPP_Glove,
	EPP_Belt,
	EPP_Leg,
	EPP_Shoe,
	EPP_Neck,
	EPP_Ring,

	EPP_WeaponStart = 100,
	EPP_Hammer,
	EPP_Axe,
	EPP_Spear = 201,
	EPP_Halbert,     //�
	EPP_HornBow = 301,
	EPP_Bow,
	EPP_IronFist = 401,
	EPP_RingBlade,
	EPP_Wood = 501,      //ľ��
	EPP_Glass,		//������
};
struct tagProduceDisplayInfo
{
	DWORD			id;								//�䷽id
	EProduceType		eProType;				//��������
	TCHAR				szName[X_SHORT_NAME];	//�䷽����
	std::vector<tstring>  upper_layer_name;      //����νṹ����
};
//�����ϳ�
struct tagProduceProto
{
	DWORD				dwID;					//�䷽ID
	TCHAR				szName[X_SHORT_NAME];	//�䷽����
	EProduceType		eProType;				//��������
	EComposeType		eComType;				//�ϳ�����
	EFormulaType		eFormType;				//�䷽����
	EFormulaFrom		eFormFrom;				//�䷽��Դ
	DWORD				dwFormLvl;				//�䷽�ȼ�
	DWORD				dwProItemTypeID;		//�ϳɵ���Ʒ
	DWORD				dwProQuantity;			//�ϳɵ�����
	INT					nSuccessRate;			//�ɹ���
	DWORD				dwProduceTime;			//������ʱ
	DWORD				dwMasterIncre;			//����������
	DWORD				dwMoneyConsume;			//��Ǯ����
	EPPart					eComPart;			//�ϳ��ﲿλ����
	EPClass					eClass;				//�ϳ���ְҵ����
	tagProduceSutff		ProduceStuff[MAX_PRODUCE_STUFF_QUANTITY];//��������
	INT					nQualiyNum[EIQ_End];	//����Ʒ�����������
	INT					nQualiyPro[EIQ_End];	//����Ʒ�������
};


//ǿ������ǿ��������
struct tagConsolidateRoleAtt
{
	ERoleAttribute		eRoleAtt;
	INT					nAttVal;
};

//��Ƕ(ǿ������)
struct tagConsolidateItem
{
	DWORD					dwID;						//���ߵ�ID
	//DWORD					dwPotValConsume;			//Ǳ��ֵ����
	//INT					nSuccessRate;				//�ɹ���
	INT						nMoney;						//��Ǩ���Ľ�Ǯ
	INT						nDamoMonery;				//��ĥ���Ľ�Ǯ
	DWORD					dwLeftItem;					//��Ǩ��������Ƭid
	DWORD					dwDamoItem;					//ԭʯ��ĥid
	tagConsolidateRoleAtt	tagRoleAtt[MAX_CONSOLIDATE_ROLEATT];		//ǿ������	
	tagConsolidatePos   ConsolidatePos[MAX_CONSOLIDATE_POS_QUANTITY];	//��ǿ��װ����λ
};

//  �ֽ�㻯�����Ʒ
struct tagOutputStuff
{
	DWORD				dwStuffTypeID;			//�������TypeID
	//INT				nPerMinVal;				//������С����
	//INT				nPerMaxVal;				//�����������
	INT					nSucMinVal;				//�ɹ���С����
	INT					nSucMaxVal;				//�ɹ��������
	INT					nRate;					//����
};

// �ֽ�㻯
struct tagDeComposeProto
{
	DWORD				dwID;					//�䷽ID
	TCHAR				szName[X_SHORT_NAME];	//�䷽����
	EComposeType		eComType;				//�ϳ�����
	BYTE				byLevel;				//װ���ȼ�
	BYTE				byQuality;				//װ��Ʒ��
	EItemType			eType;					//װ������
	EItemTypeEx			eTypeEx;				//��������
	EEquipPos			ePos;					//װ��λ��
	DWORD				dwFormLvl;				//�䷽�ȼ�
	EFormulaFrom		eFormFrom;				//�䷽��Դ
	INT					nSuccessRate;			//�ɹ���
	DWORD				dwProduceTime;			//������ʱ
	//DWORD				dwVitalityConsume;		//��������
	DWORD				dwMasterIncre;			//����������
	DWORD				dwMoneyConsume;			//��Ǯ����
	INT					nOutStuffNum;			//�����������
	std::vector<tagOutputStuff>	OutputStuff;	//�������
	tagOutputStuff		OutPerStuff;			//��������
	//tagOutputStuff		OutputStuff[MAX_OUTPUT_QUANTITY];			//�������		
};


// װ���仯
struct tagEquipChange
{
	DWORD			dwID;
	DWORD			dwTargetID;
	tagProduceSutff	sSutff[3];	// 0.1Ϊ��ͨ��Ʒ 2Ϊ������Ʒ
};

class ComposeHelper
{
public:
	//��ȡ����ÿ���ȼ�Ӱ��Ʒ�ʼ���
	static INT32 GetProduceSkillLevelParam(BYTE byQuality)
	{
		switch (byQuality)
		{
		case EIQ_Quality1:
			return -770;
			break;
		case EIQ_Quality2:
			return 500;
			break;
		case EIQ_Quality3:
			return 270;
			break;
		case EIQ_Quality4:
			return 0;
			break;
		}
		return 0;
	}
	
	//��������Ǯ���ļӳ�
	static FLOAT GeProduceBoxMoneyParam()
	{
		return 1.15f;
	}
	//����ÿ��Ӱ��ļ���
	static INT GetAlchemyLevelPro(INT nLevel)
	{
		if (nLevel >= 0 && nLevel <= 10)
		{
			return nLevel*200;
		}
		return 0;
	}

	//����ÿ�����ɸ���
	static VOID GetAlchemyLevelNum(INT nLevel, INT& nMin, INT& nMax)
	{
		switch(nLevel)
		{
		case 1:
		case 2:
			nMin = 1;
			nMax = 2;
			break;
		case 3:
		case 4:
		case 5:
			nMin = 1;
			nMax = 3;
			break;
		case 6:
		case 7:
		case 8:
			nMin = 1;
			nMax = 4;
			break;
		case 9:
		case 10:
			nMin = 2;
			nMax = 4;
			break;
		default:
			nMin = 0;
			nMax = 0;
			break;
		}
	}
};
#pragma pack(pop)
