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
//生成类型
enum EProduceType
{
	EPCT_NULL			= 0,
	EPCT_Artisan		= 1,		//工匠1
	EPCT_DanTraining	= 2,		//练丹
	EPCT_Smith			= 3,		//打造
	EPCT_Casting		= 4,		//铸甲4
	EPCT_Dressmaker		= 5,		//裁缝5
	EPCT_Aechnics		= 6,		//工艺6
	EPCT_Smilt			= 7,		//材料合成
	EPCT_PointUp		= 8,		//分解
};
//合成类型(生成类型的子类)
enum EComposeType
{
	ECOMT_NULL = 0,
	ECOMT_WeaponMake		= 10,		//装备制造		
	ECOMT_LoricaeMake		= 20,		//防具制造				
	ECOMT_DecorateMake		= 30,		//饰品制造		
	ECOMT_Refine			= 40,		//材料合成
	ECOMT_EquipdDecompose	= 50,		//装备分解		
};	

//每项生产包含的合成子类数量
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

//合成配方类型
enum EFormulaType
{
	EFORMT_NULL	= 0,
	EFORMT_OreRefine,		//矿石提纯	1
	EFORMT_Glave,			//剑			
	EFORMT_Sword,			//刀			
	EFORMT_Halberd,			//长兵		
	EFORMT_Bow,				//弓			
	EFORMT_SmallOrgan,		//小型法器	
	EFORMT_BigOrgan,		//大型法器	
	EFORMT_Instrument,		//琴			
	EFORMT_Millstone,		//魔石		
	EFORMT_Armet,			//头盔		
	EFORMT_UpperLoricae,	//上身盔甲	
	EFORMT_LowerLoricae,	//下身盔甲	
	EFORMT_Armguard,		//护手		
	EFORMT_BattleShoe,		//战靴		
	EFORMT_Roll,			//鉴定卷		
	EFORMT_Cap,				//帽子		
	EFORMT_Jupe,			//上衣		
	EFORMT_Pants,			//下衣		
	EFORMT_Glove,			//手套		
	EFORMT_Shoe,			//鞋子		
	EFORMT_2Gem,			//二级宝石
	EFORMT_3Gem,			//三级宝石
	EFORMT_4Gem,			//四级宝石
};

//配方来源
enum EFormulaFrom
{
	EFormulaFrom_NULL			= 0,
	EFormulaFrom_Skill			= 1,			//技能
	EFormulaFrom_NPC			= 2,			//NPC
	EFormulaFrom_Item			= 3,			//物品
	EFormulaFrom_SkillorNPC		= 4,			//技能及NPC
	EFormulaFrom_SkillorItem	= 5,			//技能及物品
	EFormulaFrom_NPCorItem		= 6,			//NPC及物品
};

//装备强化类型
enum EConsolidateType
{
	ECliDateT_NULL 		= 0,		//无
	ECliDateT_Posy		= 1,		//铭纹
	ECliDateT_Engrave	= 2,		//镌刻
	ECliDateT_Quench,				//淬火
};

//强化铭纹属性
enum EPosyAtt
{
	EPosyAtt_NULL		= 0,	//无	
	EPosyAtt_MaxHP		= 1,    //最大体力
	EPosyAtt_MaxMP		= 2,	//最大真气
	EPosyAtt_ExAttack	= 3,	//外功攻击
	EPosyAtt_InAttack	= 4,	//内功攻击
	EPosyAtt_ExDefense	= 5,	//外功防御
	EPosyAtt_InDefense	= 6,	//内功防御

	EPosyAtt_End,
};
//强化镌刻属性
enum EEngraveAtt
{
	EEngraveAtt_NULL		= 0,	//无
	EEngraveAtt_WeaponDmg	= 1,	//武器伤害
	EEngraveAtt_WeaponSoul  = 2,	//武魂
	EEngraveAtt_Armor		= 3,	//防具护甲(防)
	EEngraveAtt_Deration	= 4,	//防具护甲(饰)
	EEngraveAtt_End,
};

//淬火类型
enum EQuenchType
{
	EEQuenchType_Metal		= 0,	//金淬
	EEQuenchType_Wood,				//木淬
	EEQuenchType_Water,				//水淬
	EEQuenchType_Fire,				//火淬
	EEQuenchType_Soil,				//土淬
};


//可强化装备部位
struct tagConsolidatePos
{
	EEquipPos ePos;
	BYTE	  byConsolidate;
};

//强化材料
struct tagConsolidateStuff
{
	DWORD				dwStuffID;			//材料ID
	EStuffType			eStuffType;			//材料类型
	DWORD				dwStuffNum;			//材料数量
};

//生产合成材料
struct tagProduceSutff
{
	DWORD				dwStuffID;			//材料ID
	//EStuffType			eStuffType;			//材料类型
	DWORD				dwStuffNum;			//材料数量	
};

//铭纹结构体
struct tagPosyProto
{

	DWORD				dwID;					//配方ID
	TCHAR				szName[X_SHORT_NAME];	//配方名称
	EPosyAtt			ePosyAtt;				//铭纹属性
	BYTE				byPosyTimes;			//铭纹次数
	INT					nSuccessRate;			//成功率
	DWORD				dwProduceTime;			//生产计时
	DWORD				dwPotValConsume;		//潜力值消耗
	DWORD				dwMoneyConsume;			//金钱消耗
	FLOAT 				fcoefficientA; 			//属性价值公式参数A
	FLOAT 				fcoefficientB; 			//属性价值公式参数B
	FLOAT 				fcoefficientC; 			//属性价值公式参数C
	tagConsolidateStuff	ConsolidateStuff[MAX_CONSOLIDATE_STUFF_QUANTITY]; //强化材料
	tagConsolidatePos   ConsolidatePos[MAX_CONSOLIDATE_POS_QUANTITY];	//可强化装备部位
};

//镌刻结构体
struct tagEngraveProto
{

	DWORD				dwID;					//配方ID
	TCHAR				szName[X_SHORT_NAME];	//配方名称
	EEngraveAtt			eEngraveAtt;			//镌刻属性
	BYTE				byEngraveTimes;			//镌刻次数
	INT					nSuccessRate;			//成功率
	DWORD				dwProduceTime;			//生产计时
	DWORD				dwPotValConsume;		//潜力值消耗
	DWORD				dwMoneyConsume;			//金钱消耗
	FLOAT 				fcoefficientA; 			//属性价值公式参数A
	FLOAT 				fcoefficientB; 			//属性价值公式参数B
	FLOAT 				fcoefficientC; 			//属性价值公式参数C
	tagConsolidateStuff	ConsolidateStuff[MAX_CONSOLIDATE_STUFF_QUANTITY]; //强化材料
	tagConsolidatePos   ConsolidatePos[MAX_CONSOLIDATE_POS_QUANTITY];	//可强化装备部位
};

//淬火属性
struct tagQuenchAtt
{
	EWuXing				eWuXing;
	INT					nWuXingValue;
};

//淬火结构体
struct tagQuenchProto
{
	DWORD				dwID;					//配方ID
	TCHAR				szName[X_SHORT_NAME];	//配方名称
	EQuenchType			eQuenchType;			//淬火类型
	tagQuenchAtt		srcQuenchAtt;			//原属性及属性值
	tagQuenchAtt		dstQuenchAtt;			//目标属性及属性值
	DWORD				dwPotValConsume;		//潜力值消耗
	DWORD				dwMoneyConsume;			//金钱消耗
	INT					nSuccessRate;			//成功率
	DWORD				dwProduceTime;			//生产计时
	tagConsolidateStuff	ConsolidateStuff[MAX_CONSOLIDATE_STUFF_QUANTITY]; //强化材料
};
enum EPClass
{
	EPC_NULL = 0,
	EPC_MJ ,  //猛将
	EPC_SB,
	EPC_YX,
	EPC_CK,
	EPC_YS,
};

enum EPPart
{
	EPPA_Null =0,
	EPP_Weapon1,   //武器一
	EPP_Weapon2,			//武器二
	EPP_Head,		 //3		
	EPP_InnerArmor,
	EPP_Smock,    //披风
	EPP_Armor,
	EPP_Cuff,        //护腕
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
	EPP_Halbert,     //戟
	EPP_HornBow = 301,
	EPP_Bow,
	EPP_IronFist = 401,
	EPP_RingBlade,
	EPP_Wood = 501,      //木杖
	EPP_Glass,		//琉璃仗
};
struct tagProduceDisplayInfo
{
	DWORD			id;								//配方id
	EProduceType		eProType;				//生产类型
	TCHAR				szName[X_SHORT_NAME];	//配方名称
	std::vector<tstring>  upper_layer_name;      //树层次结构名称
};
//生产合成
struct tagProduceProto
{
	DWORD				dwID;					//配方ID
	TCHAR				szName[X_SHORT_NAME];	//配方名称
	EProduceType		eProType;				//生产类型
	EComposeType		eComType;				//合成类型
	EFormulaType		eFormType;				//配方类型
	EFormulaFrom		eFormFrom;				//配方来源
	DWORD				dwFormLvl;				//配方等级
	DWORD				dwProItemTypeID;		//合成的物品
	DWORD				dwProQuantity;			//合成的数量
	INT					nSuccessRate;			//成功率
	DWORD				dwProduceTime;			//生产计时
	DWORD				dwMasterIncre;			//熟练度增加
	DWORD				dwMoneyConsume;			//金钱消耗
	EPPart					eComPart;			//合成物部位归类
	EPClass					eClass;				//合成物职业归类
	tagProduceSutff		ProduceStuff[MAX_PRODUCE_STUFF_QUANTITY];//生产材料
	INT					nQualiyNum[EIQ_End];	//提升品质物最大数量
	INT					nQualiyPro[EIQ_End];	//提升品质物概率
};


//强化道具强化的属性
struct tagConsolidateRoleAtt
{
	ERoleAttribute		eRoleAtt;
	INT					nAttVal;
};

//镶嵌(强化道具)
struct tagConsolidateItem
{
	DWORD					dwID;						//道具的ID
	//DWORD					dwPotValConsume;			//潜力值消耗
	//INT					nSuccessRate;				//成功率
	INT						nMoney;						//拆迁消耗金钱
	INT						nDamoMonery;				//打磨消耗金钱
	DWORD					dwLeftItem;					//拆迁出来的碎片id
	DWORD					dwDamoItem;					//原石打磨id
	tagConsolidateRoleAtt	tagRoleAtt[MAX_CONSOLIDATE_ROLEATT];		//强化属性	
	tagConsolidatePos   ConsolidatePos[MAX_CONSOLIDATE_POS_QUANTITY];	//可强化装备部位
};

//  分解点化输出物品
struct tagOutputStuff
{
	DWORD				dwStuffTypeID;			//输出材料TypeID
	//INT				nPerMinVal;				//完美最小数量
	//INT				nPerMaxVal;				//完美最大数量
	INT					nSucMinVal;				//成功最小数量
	INT					nSucMaxVal;				//成功最大数量
	INT					nRate;					//几率
};

// 分解点化
struct tagDeComposeProto
{
	DWORD				dwID;					//配方ID
	TCHAR				szName[X_SHORT_NAME];	//配方名称
	EComposeType		eComType;				//合成类型
	BYTE				byLevel;				//装备等级
	BYTE				byQuality;				//装备品级
	EItemType			eType;					//装备类型
	EItemTypeEx			eTypeEx;				//武器类型
	EEquipPos			ePos;					//装备位置
	DWORD				dwFormLvl;				//配方等级
	EFormulaFrom		eFormFrom;				//配方来源
	INT					nSuccessRate;			//成功率
	DWORD				dwProduceTime;			//生产计时
	//DWORD				dwVitalityConsume;		//活力消耗
	DWORD				dwMasterIncre;			//熟练度增加
	DWORD				dwMoneyConsume;			//金钱消耗
	INT					nOutStuffNum;			//输出材料数量
	std::vector<tagOutputStuff>	OutputStuff;	//输出材料
	tagOutputStuff		OutPerStuff;			//完美材料
	//tagOutputStuff		OutputStuff[MAX_OUTPUT_QUANTITY];			//输出材料		
};


// 装备变化
struct tagEquipChange
{
	DWORD			dwID;
	DWORD			dwTargetID;
	tagProduceSutff	sSutff[3];	// 0.1为普通物品 2为特殊物品
};

class ComposeHelper
{
public:
	//获取打造每级等级影响品质几率
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
	
	//随身打造金钱消耗加成
	static FLOAT GeProduceBoxMoneyParam()
	{
		return 1.15f;
	}
	//炼丹每级影响的几率
	static INT GetAlchemyLevelPro(INT nLevel)
	{
		if (nLevel >= 0 && nLevel <= 10)
		{
			return nLevel*200;
		}
		return 0;
	}

	//炼丹每级生成个数
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
