//-----------------------------------------------------------------------------
//★Name				:   creature_define.h
//★Compiler			:	Microsoft Visual C++ 9.0Aslan
//★Version				:	1.00
//★Create Date			:	2008-08-25
//★LastModified		:	
//★Brief				:	怪物属性定义
//-----------------------------------------------------------------------------
#pragma once

#include "reputation.h"
#include "RoleDefine.h"
#include "NPCTeam_define.h"

//enum ENPCTeamOrder;

#define NORAML_SKILL_NUMBER 3
//----------------------------------------------------------------
// 游戏内生物种类
//----------------------------------------------------------------
enum ECreatureType
{
	ECT_NULL		=	0,
	ECT_Monster		=	1,		// 怪物
	ECT_GameObject	=	2,		// 可交互的地物
	ECT_NPC			=	3,		// 普通NPC
	ECT_Pet			=	4,		// 宠物
};

//----------------------------------------------------------------
// 动画类型
//----------------------------------------------------------------
enum EAniType
{
	EAT_None		=	0,		// 静态
	EAT_KeyFrame	=	1,		// 关键帧
	EAT_Skeleton	=   2,		// 骨骼动画
    EAT_Avatar      =   3,      // 可换装骨骼动画
};

//----------------------------------------------------------------
// 怪物种类
//----------------------------------------------------------------
enum EMonsterType
{
	EMTT_Normal		=	1,		// 普通
	EMTT_Nest		=	2,		// 巢穴
	EMTT_Team		=	10,		// 怪物小队队长
	EMTT_Tripod		=	11,		// 帮会普通地图鼎	
};

//----------------------------------------------------------------
// 普通NPC种类
//----------------------------------------------------------------
enum ENPCType
{
	ENPCT_Normal	=	0,		// 普通NPC
};

//-----------------------------------------------------------------
// 可交互地物种类
//-----------------------------------------------------------------
enum EGameObjectType
{
	EGOT_Normal		=	0,		// 普通地物
	EGOT_Gather		=	3,		// 可采集地物
	EGOT_Chest		=	4,		// 箱子
	EGOT_Flag		=	5,		// 阵旗
	EGOT_Door		=	6,		// 门
	EGOT_QuestInves =   7,      // 任务可调查地物
	EGOT_QuestTalk  =   8,      // 任务对话地物
	EGOT_CommonInves=	9,		// 非任务调查地物
	EGOT_Relive		=  10,		// 帮会战复活点
	EGOT_CommonInves_T=  11,	// 非任务调查地物(2)

};

//------------------------------------------------------------------
// 宠物种类
//------------------------------------------------------------------
enum EPetType
{
	EPT_Normal		=	0,		// 普通宠物
};

//------------------------------------------------------------------
// 帮会怪物种类
//------------------------------------------------------------------
enum EGuildType
{
	EGT_NULL				= -1,				// 无
	EGT_Lobby				= 0,				// 帮会大厅
	EGT_Bank				= 1,				// 帮会钱庄
	EGT_Leechdom			= 2,				// 帮会百草屋
	EGT_Factory				= 3,				// 帮会工房
	EGT_Maidan				= 4,				// 帮会练兵场
	EGT_Holiness			= 5,				// 帮会圣兽居	

	EGT_Bank_Sentinel		= 6,				// 帮会钱庄守卫
	EGT_Leechdom_Sentinel	= 7,				// 帮会百草屋守卫
	EGT_Factory_Sentinel	= 8,				// 帮会工房守卫
};

//------------------------------------------------------------------
// 职能类型
//------------------------------------------------------------------
enum EFunctionNPCType
{
	EFNPCT_Null		=	-1,		// 无
	EFNPCT_Shop		=	0,		// 商店
	EFNPCT_Dak		=	1,		// 驿站
	EFNPCT_Ware		=	2,		// 仓库
	EFNPCT_Compose	=	3,		// 合成
	EFNPCT_Guild	=	4,		// 门派
	EFNPCT_Guard	=	5,		// 卫兵
	EFNPCT_Yamun	=	6,		// 衙门
	EFNPCT_Quench	=	7,		// 淬火
	EFNPCT_Engrave	=	8,		// 镌刻
	EFNPCT_Posy		=	9,		// 铭文
	EFNPCT_Teacher	=	10,		// 技能授予者
	EFNPCT_Revive	=	11,		// 复活点
	EFNPCT_GuildMgr	=	12,		// 帮派管事
	EFNPCT_GuildWare=	13,		// 帮派仓库
	EFNPCT_CofC		=	14,		// 商会
	EFNPCT_Fusion	=	15,		// 武器融合
	EFNPCT_Purification=16,		// 武器净化
	EFNPCT_LoopQuest   =17,	    // 发放循环任务
	EFNPCT_Ride		   =18,		// 坐骑强化/镶装备/打磨装备
	EFNPCT_Master	   =19,		// 解除师徒关系
	EFNPCT_MailMan	   =20,		//邮箱
	EFNPCT_CircleQuest =21,		// 换随机任务
	EFNPCT_BANNER = 22,	// 切磋战旗
	EFNPCT_FISH			= 23,  // 钓鱼 
	EFNPCT_TeamCircleQst=24, // 组队刷随机任务
	EFNPCT_Earthy		= 25,	// 帮会种植土地
	EFNPCT_ReaAtt		= 26,	// 重置属性
	EFNPCT_Pet_Xiulian	= 27,	// 宠物寄养
	EFNPCT_DAMO			= 28,	// 原石打磨
};

enum EAIACTION
{
	AIAT_Attack		=	0,									// 攻击型
	AIAT_Guard		=	1,									// 防守型
	AIAT_Barbette	=	2,									// 炮塔型
	AIAT_SpaceOut	=	3,									// 风筝型
	AIAT_PetAttack  =	4,									// 宠物攻击型
	AIAT_Alert		=   5,									// 警戒型	by ljp [2010-03-26:10-03]
	AIAT_Hucheng	=	6,									// 护城型
};

//------------------------------------------------------------------
// 逃跑怪物AI类型的中间状态
//------------------------------------------------------------------
enum EFLEETIME
{
	EFT_NotEnter	=	0,									// 没有进入过逃跑状态
	EFT_FirstEnter	=	1,									// 第一次进入逃跑状态
	EFT_Enter		=	2,									// 进入逃跑状态
	EFT_CallHelp	=	3,									// 呼救状态
};

//------------------------------------------------------------------
// 职能ID
//------------------------------------------------------------------
typedef union
{
	DWORD	dwCommonID;					// 读取静态属性表时，使用该字段
	DWORD	dwShopID;					// 商店NPC所挂的商店ID
	INT		nProduceType;				// 合成NPC所对应的合成类型
	DWORD	dwDakID;					// 驿站NPC所挂的ID
} FunctionID;


//------------------------------------------------------------------
// 可采集地物类型
//------------------------------------------------------------------
enum EGatherType
{
	EGT_Mine		=	1,		// 矿物
	EGT_Herb		=	2,		// 草药
    EGT_Pool        =   3,      // 鱼塘
	EGT_Carry		=	4,		// 可搬运物
	EGT_Guild_Mine	=	5,		// 工会矿物
	EGT_Guild_Herb	=	6,		// 工会草药
};

//------------------------------------------------------------------
// 怪物级别
//------------------------------------------------------------------
enum ERank
{
	ER_Null,					// 无
	ER_FieldNormal,				// 普通怪
	ER_FieldElite,				// 野外精英
	ER_FieldWordBoss,			// 野外BOSS及世界BOSS
	ER_QuestBoss,				// 任务BOSS
	ER_InstNormal,				// 普通副本怪
	ER_InstNormalBoss,			// 普通副本BOSS
	ER_Indwelling,				// 留用
	ER_Guild,					// 帮会怪
	ER_InstHero,				// 精英副本怪
	ER_InstHeroBoss,			// 精英副本BOSS
};

//------------------------------------------------------------------
// 怪物阵营关系
//------------------------------------------------------------------
enum ECampConnection
{
	ECAC_Null			= 0,			// 无
	ECAC_Friend			= 1,			// 友好
	ECAC_Enemy			= 2,			// 敌对
	ECAC_Neutralism		= 3,			// 中立
};

//-------------------------------------------------------------------
// 巡逻类型
//-------------------------------------------------------------------
enum ECreaturePatrolType
{
	ECPT_Null = 0,
	ECPT_Stand,			// 站立
	ECPT_Range,			// 自由
	ECPT_Path,			// 路径
	ECPT_Wood,			// 木桩
	ECPT_Patrol,		// 按指定的路径漫游 by ljp [ 2010-03-29 ]
};

//-------------------------------------------------------------------
// 追击类型
//-------------------------------------------------------------------
enum ECreaturePursueType
{
	ECPST_Null = 0,
	ECPST_Flee,			// 逃跑
	ECPST_CallHelp,		// 呼救
	ECPST_BeHitCallHelp,// 被打呼救

};

//-------------------------------------------------------------------
// 重生类型
//-------------------------------------------------------------------
enum ECreatureRespawnType
{
	ECRT_Normal,			// 普通重生方式
};

//-------------------------------------------------------------------
// 怪物攻击所属类型（经验，声望）
//-------------------------------------------------------------------
enum ECreatureTaggedType
{
	ECTT_NULL = 0,
	ECTT_Hit,					// 命中
	ECTT_Kill,					// 击杀
	ECTT_All,					// 全体
	ECTT_NOTALL					// 全体不能
};

//-------------------------------------------------------------------
// 怪物AI生成类型
//-------------------------------------------------------------------
enum EAICreateType
{
	EACT_Null			=		-1,			// 无AI
	EACT_NoAI			=		0,			// 无AI数据
	EACT_Indicate		=		1,			// 指定
	EACT_Random			=		2,			// 完全随机
	EACT_GroupRandom	=		3,			// 在组ID范围内随机
};

//---------------------------------------------------------------------
// AI特殊行为
//---------------------------------------------------------------------
enum EAIFlag
{
	EAIF_Flee			=		1,			// 逃跑
	EAIF_Call			=		2,			// 召唤队友
};

//---------------------------------------------------------------------
// 呼救类型
//---------------------------------------------------------------------
enum EHelpType
{
	EHT_Stand			=      1,		// 原地呼救
	EHT_Flee			=	   2,		// 逃跑呼救
};

//---------------------------------------------------------------------
// 地图显示类型
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
//NPC攻击属性
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
// 巢穴属性结构
//---------------------------------------------------------------------
const INT MAX_SPAWN_CREATURE_NUM = 10;		// 巢穴最大可刷新的怪物数量

struct tagNestProto
{
	ENPCTeamOrder		eOrderType;								// 小队队形
	FLOAT				fSpace;									// 怪物小队成员间的间距
	INT					nSpawnRadius;							// 刷新怪物的范围
	INT					nCreatureNum;							// 刷新的怪物数量
	DWORD				dwSpawnID[MAX_SPAWN_CREATURE_NUM];		// 巢穴刷新怪物的ID
	INT					nSpawnMax[MAX_SPAWN_CREATURE_NUM];		// 巢穴刷新每种怪物的最大数量
};

//-------------------------------------------------------------------
// 怪物，NPC，地物，宠物属性结构
//-------------------------------------------------------------------
struct tagCreatureProto
{
	// 基本
	DWORD					dw_data_id;					// 属性ID
	ECreatureType			eType;						// 怪物类别
	INT						nType2;						// 怪物子类别
	INT						nType3;						// 怪物类别3
	INT						nFamily;					// 怪物种类
	EGuildType				eGuildType;					// 帮会建筑类型
	ECamp					eCamp;						// 怪物阵营
	BYTE					bySex;						// 性别
	BYTE					byReserved[3];				// 保留字3字节
	ERank					eLite;						// 级别
	INT						nLevel;						// 等级
	Vector3					vSize;						// 包裹盒大小
	Vector3				vLookAt;						//看向点
	Vector3				vLookFrom;					//摄像机位置
	BOOL					bUsePic;						//是否用图片头像
	float						fRtAngle;						//旋转的角度
	INT32					nDoorCloseTime;				// 门自动关闭时间
	BOOL					bCanInWater;				// 是否能进水
	INT						nPursueTime;				// 追击时间
	INT						nNoAttackTime;				// 无技能释放脱战时间
	INT						nPursueRadius;				// 追击半径
	INT						nInstPoint;					// 副本分数
	BOOL					bLoading;					// 是否预加载NPC
	DWORD				dwRidePetID;			// 骑乘的坐骑petid
	DWORD				dwRideLevel;				//坐骑的强化等级
	DWORD				dwCarryID;					// 搬运物品ID
	DWORD				dwSortType;					// 通过这个排序
	// 移动及战斗
	ECreaturePatrolType		ePatrolType;				// 移动类型
	INT						nPatrolRadius;				// 的移动半径
	ECreaturePursueType		ePursueType;				// 追击类型
	//DWORD					dwNormalSkillIDMelee;		// 普通攻击技能ID
	//DWORD					dwNormalSkillIDRanged;		// 远程攻击技能ID
	DWORD					dwNormalSkill[NORAML_SKILL_NUMBER];			// 3个攻击技能id
	INT						nAttackInterTick;			// 怪物攻击间隔
	BOOL					bCanAttack;					// 是否可攻击
	BOOL					bCanBeAttack;				// 是否可被攻击
	BOOL					bVisble;					// 是否可见
	BOOL					bCanHitFly;					// 是否可以被击飞
	BOOL					bCanKill;					// 是否可被杀
	BOOL					bRedNameCanTalk;			// 红名是否可对话	add by hejiang
	BOOL					bCantka;					// 是否不能卡怪
	// 刷新
	ECreatureRespawnType	eRespawnType;				// 重生模式
	INT						nRespawnTick;				// 重生时间（单位：tick）
	INT						nRespawnTickAdd;			// 重生时间增量
	INT						nLiveTick;					// 生存时间

	// 掉落
	ECreatureTaggedType		eTaggedType;				// 所属权类型
	INT						nExpGive;					// 给予经验
	EReputationType			eRepType1;					// 所给声望1类型
	INT						nRepNum1;					// 所给声望1值
	EReputationType			eRepType2;					// 所给声望2类型
	INT						nRepNum2;					// 所给声望2值
	DWORD					dwLootID;					// 物品掉落编号
	INT						nExploits;					// 给予战功
	BOOL					b_save_process;				// 是否保存副本进度

	// AI
	EAICreateType			eAICreateType;				// AI生成模式
	DWORD					dwAIID;						// AIID
	EAIACTION				eAIAction;					// AI行为方式

	// 职能
	EFunctionNPCType		eFunctionType;				// 职能类型
	FunctionID				uFunctionID;				// 职能ID
	BOOL					bVipPriceOff;				// 使用VIP折扣
	bool						b_boss_display;				//是否显示为boss
	// 属性
	INT						nBaseAtt[ERA_End];			// 基本属性
	
	// add by ljp [ 2010-03-26:15-11 ]
	DWORD					nAlertDis;					// 警戒范围
	FLOAT					fChangeAct;					// 逃跑or求救几率	[0.0,1.0]
	FLOAT					fChangleActHP;				// 逃跑or求救时生命百分比 [0.0,1.0]
	DWORD					dwHelpRange;				// 怪物求助范围
	INT16					nHelpNum;					// 怪物呼救数量
	EHelpType				eHelpType;					// 怪物呼救类型
	DWORD					dw_help_time;				// 怪物呼救or逃跑间隔时间

	// 任务
	UINT16					u16QuestID;					// 可调查地物所属的任务ID
	BYTE					byReserved2[2];				// 保留字

	// 巢穴指针
	tagNestProto*			pNest;						// 巢穴指针
	
	// 种植成熟时间(秒)
	DWORD					dwMatureTime;	
	// 工会采矿所需的锄头id
	DWORD					dwChutouID;		

	// 地图显示  add by hejiang[ 2010.12.20 ]
	EMapShowType			eMapShowType;
	ENpcElements			eElements;
	INT						nPos_x;
	INT						nPos_y;

    BOOL                    bCanShake;                  // 受击时是否颤抖 by zhaopeng 2011.04.08
    DWORD                   dwHitFlySpeedFactor;        // 击飞速度系数

    BOOL                    bCanSelect;                 // 是否能被选中 by zhaopeng 2011.11.09
	BOOL					bShowName;					// 是否显示名字	add by gtj	12.12.11

	// 其他
	EAniType				eAnimationType;
	TCHAR					szModelName[X_LONG_NAME];	// 模型名称
    TCHAR					szTexPostfix[X_SHORT_NAME]; // 贴图后缀
	TCHAR					szName[X_SHORT_NAME];		// 怪物名称
	TCHAR					szFunction[X_SHORT_NAME];	// 怪物职能描述
	TCHAR					szTitle[X_SHORT_NAME];		// 称号
	DWORD					szTitleClr;//!称号颜色，add by slash
	TCHAR					szTitleIcon[X_SHORT_NAME];	// 称号贴图
	TCHAR					szFunctionIcon[X_SHORT_NAME];// 职能图标
	TCHAR					szEffect[X_SHORT_NAME];		// 特效编号
	TCHAR					szIdleSpeech[X_LONG_NAME];	// 悠闲喊话
	TCHAR					szCombatSpeech[X_LONG_NAME];// 战斗喊话
	TCHAR					szSkillSpeech[X_LONG_NAME];	// 技能喊话
	TCHAR					szDeathSpeech[X_LONG_NAME];	// 死亡喊话

    TCHAR                   szHeadIcon[X_LONG_NAME];    // 头像图片
    TCHAR					szChestMesh[X_LONG_NAME];	    // 身体模型
    TCHAR					szChestTexPostfix[X_SHORT_NAME];// 身体贴图后缀
    TCHAR					szHeadMesh[X_LONG_NAME];	    // 头部模型
    TCHAR					szHeadTexPostfix[X_SHORT_NAME];	// 头部贴图后缀
    TCHAR					szFaceMesh[X_LONG_NAME];	    // 脸部模型
    TCHAR					szFaceTexPostfix[X_SHORT_NAME];	// 脸部贴图后缀
    TCHAR					szFeetMesh[X_LONG_NAME];	    // 脚部模型
    TCHAR					szFeetTexPostfix[X_SHORT_NAME];	// 脚部贴图后缀
    TCHAR					szGlovesMesh[X_LONG_NAME];	    // 手部模型
    TCHAR					szGlovesTexPostfix[X_SHORT_NAME];// 手部贴图后缀
    EAniType				eBackModelType;                 // 背部模型类型
    TCHAR					szBackMesh[X_LONG_NAME];	    // 背部模型    
    TCHAR                   szBackTagName[X_SHORT_NAME];    // 背部挂载点
    TCHAR					szBackTexPostfix[X_SHORT_NAME];	// 背部贴图后缀    
    EAniType				eWeaponModelType;               // 武器模型类型
    TCHAR					szWeaponMesh[X_LONG_NAME];	    // 武器模型
    TCHAR                   szWeaponTagName[X_SHORT_NAME];  // 武器挂载点
    TCHAR					szWeaponTexPostfix[X_SHORT_NAME];// 武器模型后缀
    EAniType				eWeapon2ModelType;               // 武器2模型类型
    TCHAR					szWeapon2Mesh[X_LONG_NAME];	    // 武器2模型
    TCHAR                   szWeapon2TagName[X_SHORT_NAME];  // 武器2挂载点
    TCHAR					szWeapon2TexPostfix[X_SHORT_NAME];// 武器2模型后缀
    TCHAR                   szEaseEffect[X_SHORT_NAME];     // 悠闲动作时播放特效

    TCHAR                   szTrackIdle[X_SHORT_NAME];      // 普通待机
    TCHAR                   szTrackRun[X_SHORT_NAME];       // 跑
    TCHAR                   szTrackWalk[X_SHORT_NAME];      // 走
    TCHAR                   szTrackLie[X_SHORT_NAME];       // 悠闲
    TCHAR                   szTrackAttack[X_SHORT_NAME];    // 普通攻击
    TCHAR                   szTrackReady[X_SHORT_NAME];     // 战斗待机
    TCHAR                   szTrackBeAttack[X_SHORT_NAME];  // 被攻击
	TCHAR					szTrackDazzy[X_SHORT_NAME];     // 击晕
	TCHAR					szTrackDead[X_SHORT_NAME];      // 死亡
	TCHAR					szTrackHitFly[X_SHORT_NAME];    // 击飞

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
// 怪物的阵营关系
//---------------------------------------------------------------------
struct tagCreatureCamp
{
	ECamp					eCamp;						// 阵营
	ECampConnection			eCampConnection[ECA_End];	// 阵营关系
};

//---------------------------------------------------------------------
// 怪物的AI结构
//---------------------------------------------------------------------
const INT X_MAX_CREATURE_AI_BUFF	=	3;	// 怪物AI所带的最多Buff数量
const INT X_MAX_CREATURE_AI_SKILL	=	5;	// 怪物AI所带的最多技能数量

struct tagCreatureAI
{
	DWORD		dwID;										// AI ID;
	EAIACTION	eAIAction;									// AI行为类型
	DWORD		dwGroupID;									// AI组ID
	DWORD		dwBuffTypeID[X_MAX_CREATURE_AI_BUFF];		// 初始的3个buff ID
	DWORD		dwTriggerID[X_MAX_CREATURE_AI_SKILL];		// 5个触发器
	DWORD		dwSkillTypeID[X_MAX_CREATURE_AI_SKILL];		// 5个技能ID
	INT			nTargetType[X_MAX_CREATURE_AI_SKILL];		// 技能对应的目标类型
};

const INT	X_MAX_FLEE_RADIUS			=	2000;				// 怪物逃跑最大半径
const INT	X_MIN_FLEE_RADIUS			=	1500;				// 怪物逃跑最小半径
const INT	X_RANGE_FLEE_RADIUS			=	X_MAX_FLEE_RADIUS - X_MIN_FLEE_RADIUS;			// 逃跑半径差值
const FLOAT X_MAX_SOS_RADIUS			=	10000;				// 呼救状态的最大逃跑距离
const FLOAT	X_MAX_SOS_RADIUS_SQ			=	X_MAX_SOS_RADIUS * X_MAX_SOS_RADIUS;
	

