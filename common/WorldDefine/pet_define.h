#pragma once

#pragma pack(push, 1)

#define EVO_START_LEVEL 3
#define PET_MAX_LEVEL 7

const INT MAX_PETSOUL_NUM			= 12;	// 最多拥有宠物数量
const INT MAX_HAPPY_VALUE			= 300;	// 最大开心度

const INT PET_RETURN_MIN_TIME		= 18 * 60 * 60 ; // 回收宠物最小时间 			 
const INT PET_RETURN_MAX_TIME		= 19 * 60 * 60 ; // 回收宠物最大时间

const DWORD PET_JIEJING				= 5300007;	// 宠物结晶ID


const INT YUANBAO_LOVE_VALUE		= 1000;		// 一点元宝对应多少爱心值
//! 宠物模型形态数量
enum EPetModelType
{
    EPMT_Follow  =   0,  //!< 跟随
    EPMT_Mount,         //!< 骑乘
    //EPMT_Fly,	        //!< 飞行
    EPMT_NUM
};

//! 宠物状态
enum EPetState
{
	EPS_Called		= 1 << 0, //0x01,
	EPS_Working		= 1 << 1, //0x02,
	EPS_Preparing	= 1 << 2, //0x04,
	EPS_Mounting	= 1 << 3, //0x08,
	EPS_Ronghe		= 1 << 4, //0x16,
	EPS_Dead		= 1 << 5, //0x32,
	EPS_Xiulian		= 1 << 6, //0x64,
};

// 心情
enum EPetMood
{
	EPM_VerySad	=	-1,	//愤怒
	EPM_Sad		=	0,	//伤心
	EPM_NoHappy	=	1,	//不开心
	EPM_Happy	=	2	//开心
};

//! 食物种类
enum EPetFood
{
	EPF_fish	=	0x01,	//鱼
	FPF_Rou		=	0x02,	//肉
	FPF_Cai		=	0x04	//菜
};
enum EPetStateFlag
{
	EPSF_Mounting		= 0x0001,
	EPSF_UnMounting		= 0x0002,
	EPSF_Preparing		= 0x0004,
	EPSF_UnPreparing	= 0x0008,
	EPSF_Working		= 0x0010,
	EPSF_UnWorking		= 0x0020,
	EPSF_Called			= 0x0040,
	EPSF_UnCalled		= 0x0080,
	EPSF_Ronghe			= 0x0100,
	EPSF_UnRonghe		= 0x0200,	
	EPSF_Dead			= 0x0400,
	EPSF_UnDead			= 0x0800,	
	EPSF_Xiulian		= 0x1000,
	EPSF_UnXiulian		= 0x2000	
};


//! 宠物状态
union UPetState
{
	struct
	{
		bool bisCalled      : 1;
		bool bisWorking     : 1;
		bool bisPreparing   : 1;
		bool bisRiding      : 1;
		bool b_is_Ronghe :1;
		bool bDead:1;
		bool bDeposit:1;
	};
	BYTE	byPetState;
};


// 宠物初始化属性
struct tagPetInitAttr
{
    DWORD           dwID;                       //!< 当宠物出生时,在游戏世界生成的唯一ID
    DWORD           dw_data_id;                   //!< 宠物类型ID,对应tagPetProto中的ID
    UINT8           nQuality;                   //!< 品质
    INT16           nAptitude;                  //!< 资质
    INT				nSpiritMax;                 //!< 灵力最大值
    INT				nSpirit;                    //!< 灵力
    INT16           nPotential;                 //!< 潜能
    INT16           nWuXingEnergy;              //!< 五行力(最大9999)
    UINT8           nLevel;                     //!< 虚拟等级
    INT             nExpCurrent;                //!< 当前经验
    INT             nExpLevelUp;                //!< 升级经验
    INT             nMountSpeed;                //!< 骑乘速度
    INT             nBagGrid;                   //!< 行囊格数
    INT8            byPetState;                 //!< 宠物状态(EPetState)
    INT8            nMountNum;                  //!< 当前骑乘数目
    INT8            nMountNumMax;               //!< 最大骑乘数目
	bool			bLocked;					//!< 是否锁定
    INT8            nPetEquipNum;	            //!< 宠物装备数
    INT8            nPetSkillNum;	            //!< 宠物技能数
	INT8			nPetRenameCount;			//!< 宠物改名次数
	INT16			nPetHappyValue;				//!< 宠物开心度
	INT8			nPetColor;					//!< 宠物颜色
	INT				n_strength;					//!< 附加角色力量
	INT				n_agility;					//!< 附加角色敏捷
	INT				n_innerForce;				//!< 附加角色智力
	INT				n_att_point;				//!< 属性点
	DWORD			n_time_type;				//!< 寄养时间类型 
	DWORD			n_mode_type;				//!< 寄养模式类型
	DWORD			n_xiulian_time;				//!< 寄养时间

    BYTE			byData[1];                  //!< 依次为所有装备结构tagPetEquipMsgInfo,所有技能结构tagPetSkillMsgInfo
};

// 需缓冲本地的宠物信息
struct tagPetDispInfo
{
    TCHAR           szName[X_SHORT_NAME];       //!< 宠物名
    DWORD	        dw_data_id;                 //!< 宠物原型id
	INT16			n_color;					//!< 颜色
	BYTE			byQuality;					// 品质 
};

// 宠物sns信息
struct tagPetSNSInfo
{
	DWORD			dw_pet_id;			// 宠物ID
	DWORD			dw_master_id;		// 主人ID
	DWORD			dw_friend_id;		// 好友ID
	DWORD			dw_begin_time;		// 派遣时间	

	tagPetSNSInfo() { memset(this, 0, sizeof(*this)); }
};

// 通讯用宠物属性枚举
enum ECSPetAtt
{
	ECSPA_Null				= -1,
	ECSPA_Begin				= 0,

	ECSPA_nQuality          = 0,    //!< 品质
	ECSPA_nAptitude         = 1,    //!< 资质
    ECSPA_nSpiritMax        = 2,    //!< 最大灵力
	ECSPA_nSpirit           = 3,    //!< 灵力
    ECSPA_nPotential        = 4,    //!< 潜能
	ECSPA_nWuXingEnergy     = 5,    //!< 五行力
	ECSPA_nLevel            = 6,    //!< 虚拟等级
	ECSPA_nExpCurrent       = 7,    //!< 当前经验
	ECSPA_nExpLevelUp       = 8,    //!< 升级经验
	ECSPA_nMountSpeed       = 9,    //!< 骑乘速度
    ECSPA_BagGrid           = 10,   //!< 行囊格数
	ECSPA_PetState          = 11,   //!< 宠物状态(EPetState)
	ECSPA_nMountNum			= 12,	//!< 当前骑乘人数
	ECSPA_nMountNumMax		= 13,	//!< 最大骑乘人数
	ECSPA_bLocked			= 14,	//!< 是否锁定
	ECSPA_nHappyValue		= 15,	//!< 开心度 2:开心 1:不开心 0:伤心
	ECSPA_nRenameCount		= 16,	//!< 改名次数
	ECSPA_nColor			= 17,	//!< 改名颜色
	ECSPA_nstrength			= 18,	//!< 附加角色力量
	ECSPA_nagility			= 19,	//!< 附加角色敏捷
	ECSPA_ninnerForce		= 20,	//!< 附加角色智力
	ECSPA_natt_point		= 21,	//!< 属性点
	ECSPA_time_type			= 22,	//!< 寄养时间类型
	ECSPA_mode_type			= 23,	//!< 寄养模式类型
	ECSPA_xiulian_time		= 24,	//!< 寄养开始时间

	ECSPA_End,
};

// 宠物升级获得技能最大数目
CONST INT MAX_PET_STEP_UPGRADE_SKILL_NUM		= 6;


// 宠物升级原型
struct tagPetLvlUpProto
{
	DWORD	dwVLevel;
	INT		nStep;
	INT		nGrade;
	INT		nExpLvlUpNeed;
	INT		nMoneyRatePourExpNeed;
};

// 宠物升阶道具表
struct tagPetLvlUpItemProto
{
	DWORD	dw_data_id;
	INT		dwSkillIDs[MAX_PET_STEP_UPGRADE_SKILL_NUM];
};

const INT ECSPA_Num = ECSPA_End - ECSPA_Begin;

#define EPATOERPA(n)	(ECSPetAtt)(n)

// 阶
const INT MIN_PET_STEP	= 0;								// 宠物最小阶
const INT MAX_PET_STEP	= 0;								// 宠物最大阶
const INT NUM_PET_STEP	= MAX_PET_STEP - MIN_PET_STEP + 1;	// 宠物阶数
#define IS_PET_STEP(nlvl)	((nlvl) >= MIN_PET_STEP && (nLvl) <= MAX_PET_STEP)

// 等
const INT MIN_PET_GRADE	= 1;								// 宠物最小等
const INT MAX_PET_GRADE	= 7;								// 宠物最大等
const INT NUM_PET_GRADE	= MAX_PET_GRADE - MIN_PET_GRADE + 1;// 宠物等数
#define IS_PET_GRADE(nlvl)	((nlvl) >= MIN_PET_GRADE && (nLvl) <= MAX_PET_GRADE)

// 虚拟等级
const INT MIN_PET_VLEVEL	= 1;
const INT MAX_PET_VLEVEL	= 7;
const INT NUM_PET_VLEVEL	= MAX_PET_VLEVEL - MIN_PET_VLEVEL + 1;// 宠物虚拟等级
#define IS_PET_VLEVEL(nlvl)	((nlvl) >= MIN_PET_VLEVEL && (nLvl) <= MAX_PET_VLEVEL)

// 需要蜕变才能升级
const INT MIN_CHANGE_LEVEL = 3;

#define MMID(val, min, max)		((val) = ((val) > (max)) ? (max) : (((val) < (min)) ? (min) : val))
// 虚拟等级到阶等的转换
inline VOID TransVLevel2StepGrade( INT nVLevel, INT &nStep, INT &nGrade )
{
	MMID(nVLevel, MIN_PET_VLEVEL, MAX_PET_VLEVEL);
	nVLevel -= 1;
	nStep	= nVLevel / NUM_PET_GRADE;
	nGrade	= nVLevel % NUM_PET_GRADE + 1;
}
// 阶等到虚拟等级的转换
inline VOID TransStepGrade2VLevel( INT nStep, INT nGrade, INT &nVLevel )
{
	MMID(nStep, MIN_PET_STEP, MAX_PET_STEP);
	MMID(nGrade, MIN_PET_GRADE, MAX_PET_GRADE);
	nGrade	-= 1;
	nVLevel = nStep * NUM_PET_GRADE + nGrade;
	nVLevel += 1;
}
#undef MMID

// 最远被邀请骑乘距离
const FLOAT MAX_MOUNTINVITE_DISTANCE = 10 * 50.0f;	


// 宠物融合成功率
class PetHelper
{
public:
	//融合成功率
	static INT getFusionPro(INT nQuality)
	{
		switch (nQuality)
		{
		case 0:
			return 10000;
		case 1:
			return 6000;
		case 2:
			return 4000;
		case 3:
			return 2000;
		default:
			return 0;
		}
	}

	//每个培元丹提升概率
	static INT getFusionProPeiYuan(INT nQuality)
	{
		switch (nQuality)
		{
		case 0:
			return 300;
		case 1:
			return 200;
		case 2:
			return 150;
		case 3:
			return 150;
		default:
			return 0;
		}
	}

	static INT getChangeSizeMoney(INT nSize)
	{
		switch(nSize)
		{
		case 1:
			return 0;
		case 2:
			return 50000;
		case 3:
			return 100000;
		case 4:
			return 500000;
		case 5:
			return 1000000;
		case 6:
			return 2000000;
		default:
			return 5000000;
		}
		return 0;
	}

	static INT getAddpoint(BYTE byQuality)
	{
		switch (byQuality)
		{
		case 0:
			return 3;
		case 1:
			return 4;
		case 2:
			return 6;
		case 3:
			return 10;
		case 4:
			return 16;
		default:
			return 0;
		}

		return 0;
	}
};

#pragma pack(pop)