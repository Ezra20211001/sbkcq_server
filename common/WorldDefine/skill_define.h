//-----------------------------------------------------------------------------
//★Name				:   skill_define.h
//★Compiler			:	Microsoft Visual C++ 9.0Aslan
//★Version				:	1.00
//★Create Date			:	2008-09-08
//★LastModified		:	
//★Brief				:	技能静态属性
//-----------------------------------------------------------------------------
#pragma once

#include "RoleDefine.h"
#include "buff_define.h"

#pragma pack(push, 1)

const INT MAX_CHANNEL_TIMES = 5;		// 管道攻击的最多次数
const INT MAX_BUFF_PER_SKILL = 3;		// 每个技能所带的最多buff数量
const INT MAX_BUFF_PER_ITEM = 3;		// 每个物品所带的最多buff数量

const INT MAX_ROLE_PRODUCE_NUM = 3;		// 每个玩家身上所学的最大生产技能的数量

const INT MAX_TARGET_NUM = 3;			// 每个技能影响的最大目标数
//------------------------------------------------------------------------------
// 技能类型
//------------------------------------------------------------------------------
enum ESkillType
{
	ESST_Null		=	0,
	ESST_Role		=	1,		// 角色技能
	ESST_Creature	=	2,		// 怪物技能
	ESST_Item		=	3,		// 物品技能
	ESST_Social		=	4,		// 社会技能
	ESST_Pet		=	5,		// 宠物技能
	ESST_Mount		=	6,		// 坐骑技能
};

enum ESkillTypeEx
{
	ESSTE_Null		=	0,
	ESSTE_Default	=	1,		// 普通攻击
	ESSTE_Sword		=	2,		// 战士
	ESSTE_Blade		=	3,		// 法师
	ESSTE_Wand		=	4,		// 道士
	ESSTE_Bow		=	5,		// 刺客
	ESSTE_Valor		=	6,		// 药师
	ESSTE_Supple	=	7,		// 合体技能
	ESSTE_Poison	=	8,		// 
	ESSTE_Swing		=	9,		// 音律
	ESSTE_Action	=	10,		// 战技
	ESSTE_Jugglery	=	11,		// 奇术
	ESSTE_Produce	=	12,		// 生产技能
	ESSTE_Guild		=	13,		// 帮派技能
	ESSTE_Valentine	=	14,		// 情侣技能
	ESSTE_Consort	=	15,		// 夫妻技能
	ESSTE_Brother	=	16,		// 兄弟技能
	ESSTE_Teacher	=	17,		// 师徒技能
	ESSTE_Monster	=	18,		// 怪物普通技能
	ESSTE_MonsterAI	=	19,		// 怪物AI技能
	ESSTE_ItemUse	=	20,		// 物品技能
	ESSTE_Equipment	=	21,		// 装备技能
	ESSTE_Society	=	23,		// 社会技能
	ESSTE_PetSkill	=	24,		// 宠物技能
};

// nType3字来判断生产技能类型
enum ESkillTypeEx2
{
	ESSTE2_NULL		= 0,		//
	ESSTE2_Mining	= 1,		//采矿
	ESSTE2_Harvestry,			//采药
	ESSTE2_Smilt,				//冶炼
	ESSTE2_Artisan,				//巧匠
	ESSTE2_DanTraining,			//炼丹
	ESSTE2_Smith,				//锻造
	ESSTE2_Casting,				//铸甲
	ESSTE2_Dressmaker,			//裁缝
	ESSTE2_Aechnics,			//工艺
	ESSTE2_PointUp,				//点化
	ESSTE2_ProduceEquip,		//NPC打造
	ESSTE2_Hidden,				//不显示的技能
	ESSTE2_Fishing,				// 钓鱼
	ESSTE2_Heti = 14,					//合体大招
};

//------------------------------------------------------------------------------
// 技能目标类型
//------------------------------------------------------------------------------
enum ESkillTargetType
{
	ESTT_Null		=	0,
	ESTT_Buff		=	1,		// 状态
	ESTT_Skill		=	2,		// 技能
	ESTT_Trigger	=	3,		// 触发器
	ESTT_Combat		=	4,		// 战斗目标
	ESTT_NoCombat	=	5,		// 非战斗目标
};

//-------------------------------------------------------------------------------
// 技能距离类型
//-------------------------------------------------------------------------------
enum ESkillDistType
{
	ESDT_Null		=	0,
	ESDT_Melee		=	1,		// 近身
	ESDT_Ranged		=	2,		// 远程
	ESDT_Inner		=	3,		// 内功
};

//-------------------------------------------------------------------------------
// 技能施展类型
//-------------------------------------------------------------------------------
enum ESkillUseType
{
	ESUT_Null		=	0,
	ESUT_Active		=	1,		// 主动
	ESUT_Passive	=	2,		// 被动
};

//-------------------------------------------------------------------------------
// 技能作用类型
//-------------------------------------------------------------------------------
enum ESkillOPType
{
	ESOPT_NUll		=	0,
	ESOPT_Rect		=	1,		// 矩形
	ESOPT_Explode	=	2,		// 爆炸
	ESOPT_Sector	=   3,		//球锥
	ESOPT_Persist	=	4,		//持续型
};

//--------------------------------------------------------------------------------
// 技能伤害类型
//--------------------------------------------------------------------------------
enum ESkillDmgType
{
	ESDGT_Null		=	0,
	ESDGT_Ordinary	=	1,		// 物理
	ESDGT_Soil		=	2,		// 法术
	ESDGT_Gold		=	3,		// 道术
	ESDGT_Wood		=	4,		// 风系伤害类型
	ESDGT_Fire		=	5,		// 火系伤害类型
	ESDGT_Water		=	6,		// 雷系伤害类型
	//ESDGT_Injury	=	7,		// 内损伤害类型
	//ESDGT_Stunt		=	8,		// 绝技伤害类型
};

//---------------------------------------------------------------------------------
// 技能消耗类型
//---------------------------------------------------------------------------------
enum ESkillCostType
{
	ESCT_HP			=	0,		// 体力
	ESCT_MP			=	1,		// 真气
	ESCT_Love		=	2,		// 爱心值
	ESCT_End
};

//---------------------------------------------------------------------------------
// 技能升级类型
//---------------------------------------------------------------------------------
enum ESkillLevelUpType
{
	ESLUT_Fixed		=	0,		// 固定
	ESLUT_Exp		=	1,		// 熟练度
	ESLUT_Book		=	2,		// 技能书
};

//---------------------------------------------------------------------------------
// 技能性别使用限制
//---------------------------------------------------------------------------------
enum ESkillSexLimit
{
	ESSL_Null		=	0,
	ESSL_Man		=	1,
	ESSL_Woman		=	2,
};

//---------------------------------------------------------------------------------
// 技能职业使用限制
//---------------------------------------------------------------------------------
//enum ESkillClassLimit
//{
//
//};

//---------------------------------------------------------------------------------
// 技能武器限制
//---------------------------------------------------------------------------------
enum ESkillWeaponLimit
{

};

//---------------------------------------------------------------------------------
// 技能位置限制
//---------------------------------------------------------------------------------
enum ESkillPosType
{
	ESPT_NUll		=	0,		// 无限制
	ESPT_Front		=	1,		// 在身前
	ESPT_Back		=	2,		// 在身后
};


/**
*宠物加载人身上的技能分类
*/
enum e_pet_skill_display_type
{
	epsdt_null = 0,
	epsdt_normal,			//普通技能
	epsdt_soul_link,			//合体技能
	epsdt_soul_power,	//合体大招
};

//---------------------------------------------------------------------------------
// 技能静态属性
//----------------------------------------------------------------------------------
struct tagSkillProto 
{
	DWORD				dwID;								// 技能ID
	ESkillType			eType;								// 技能类型
	INT					nType2;								// 技能子类型
	INT					nType3;								// 技能子类型
	//DWORD				dwMainSkillID;						// 主技能ID（如果本身为主技能，则该项目不填写）
	ETalentType			eTalentType;						// 天资类型
	BOOL				bPoint;								// 定点释放技能

	// 目标类型
	ESkillTargetType	eTargetType;						// 目标对象类型
	DWORD				dwTargetSkillID[MAX_TARGET_NUM];	// 技能目标ID（只是针对于目标对象类型为技能）
	DWORD				dwTargetBuffID;						// 状态目标ID（只是针对与目标对象类型为状态）
	DWORD				dwTargetTriggerID;					// 触发器目标ID（只是针对与目标对象类型为技能的触发器）

	// 技能敌我判断标志
	BOOL				bFriendly;							// 对友方使用
	BOOL				bHostile;							// 对敌方使用
	BOOL				bIndependent;						// 对中立方使用

	// 攻击判定
	ESkillDistType		eDistType;							// 攻击距离类型（近身，远程）
	ESkillUseType		eUseType;							// 施展类型（主动，被动）
	ESkillOPType		eOPType;							// 作用类型
	FLOAT				fOPDist;							// 作用距离（世界单位）
	FLOAT				fOPRadius;							// 作用范围（世界单位）
	BOOL				bInterruptMove;						// 是否移动打断起手
	INT					nInterruptSkillOrdRate;				// 普通技能打断几率
	INT					nInterruptSkillSpecRate;			// 特殊技能打断几率
	INT					nPrepareTime;						// 起手时间（毫秒）
	INT					nCoolDown;							// 冷却时间（毫秒）
	INT					nMaxCoolDown;						// 冷却时间超过多少不能使用（毫秒）
	ESkillDmgType		eDmgType;							// 伤害类型
	INT					nEnmity;							// 技能仇恨
	FLOAT				fEnmityParam;						// 仇恨系数
	INT					nHit;								// 技能命中率
	INT					nCrit;								// 技能致命率
	BOOL				bMoveable;							// 是否可以移动施放
	BOOL				bMoveCancel;						// 是否移动中断伤害计算
	INT					nHitFlyPro;							// 击飞概率
	BOOL				bCollide;							// 是否被阻挡
	INT					nHitNumber;							// 攻击单位数量

	INT					nPilotTime;							// 引导技能时间  add by guohui
	INT					nPilotNum;							// 引导技能打击的次数

	// 管道
	INT					nChannelDmg[MAX_CHANNEL_TIMES];		// 管道伤害每一次的伤害量
	INT					nChannelTime[MAX_CHANNEL_TIMES];	// 管道伤害每一次的时间
	INT					nDmgTimes;							// 管道伤害总次数

	// 状态
	DWORD				dwBuffID[MAX_BUFF_PER_SKILL];		// 技能所带buff
	DWORD				dwTriggerID[MAX_BUFF_PER_SKILL];		// 技能所带的buff触发器

	// 消耗
	DWORD				dwCostItemID;						// 消耗物品ID
	INT					nCostItemNum;						// 消耗物品数量
	INT					nSkillCost[ESCT_End];				// 技能消耗

	// 升级
	INT					nLevel;								// 技能等级
	ESkillLevelUpType	eLevelUpType;						// 升级类型（固定，熟练度）
	INT					nLevelUpExp;						// 需要熟练度（针对于以熟练度升级的技能）
	DWORD				dwPreLevelSkillID;					// 前置技能属性ID
	INT					nMaxLevel;							// 等级上限
	INT					nMaxLearnLevel;						// 技能可学上限（小于等于等级上限）
	INT					nNeedRoleLevel;						// 技能升级的玩家等级限制
	INT					nNeedTalentPoint;					// 技能升级需要的玩家当前天资投点数
	EClassType			eNeedClassType;						// 技能升级需要的职业类型

	// 学习技能
	DWORD				dwLearnVocationLimit;				// 学习技能的职业限制
	DWORD				dwMoneyConsume;						// 金钱消耗

	// 使用限制
	INT					nUseHPPctLimit;						// 体力百分比限制
	INT					nUseMPPctLimit;						// 真气百分比限制
	ESkillSexLimit		eSexLimit;							// 性别限制
	//EClassType		eClassLimit;						// 职业限制
	INT					nWeaponLimit;						// 武器限制
	ESkillPosType		ePosType;							// 位置限制
	DWORD				dwTargetLimit;						// 目标对象限制
	DWORD				dwSelfStateLimit;					// 自身状态限制
	DWORD				dwTargetStateLimit;					// 目标状态限制
	BOOL				bInterCombat;						// 使用后是否进入备战
	DWORD				dwBuffLimitID;						// 自身特殊状态限制ID
	DWORD				dwTargetBuffLimitID;				// 目标特殊状态限制ID
	DWORD				dwVocationLimit;					// 职业限制
	INT					nTargetLevelLimit;					// 目标等级限制
	BOOL				bHasPet;							// 带宠限制
	BOOL				bPublicCD;							// 是否公共CD
	BOOL				bPublicCDLimit;						// 是否处理公共CD限制

	// 触发器加成
	INT					nTriggerEventMisc1Add;				// 事件触发值1加成
	INT					nTriggerEventMisc2Add;				// 事件触发值2加成
	INT					nTriggerStateMisc1Add;				// 状态触发值1加成
	INT					nTriggerStateMisc2Add;				// 状态触发值2加成
	INT					nTriggerPropAdd;					// 触发几率加成

	// 状态加成
	INT					nBuffPersistTimeAdd;				// 持续时间加成（毫秒）
	INT					nBuffWarpTimesAdd;					// 叠加次数上限加成
	INT					nBuffInterruptResistAdd;			// 攻击消除抗性加成
	EBuffEffectMode		eModBuffMode;						// 影响Buff的哪个特殊效果阶段
	INT					nBuffMisc1Add;						// 特殊效果值加成
	INT					nBuffMisc2Add;						// 特殊效果值加成
	INT					nBuffEffectAttMod[EBEA_End];		// 影响的某个阶段的人物当前属性

	// 人物属性影响
	mutable package_map<ERoleAttribute, INT>	mapRoleAttMod;		// 人物属性影响
	mutable package_map<ERoleAttribute, INT>	mapRoleAttModPct;	// 人物属性百分比影响
	// 所有的字符串属性没有添加在里面，这些属性有：
	// 名称，描述，动画编号，特效编号，图标编号，起手动作编号

};

//--------------------------------------------------------------------------------
// 技能传送客户端的消息结构
//--------------------------------------------------------------------------------
struct tagSkillMsgInfo
{
	DWORD	dwID;							// 技能ID
	INT		nLevel;							// 当前等级
	INT		nCoolDown;						// 冷却
	INT		nProficiency;					// 熟练度
	FLOAT	fOpDist;						// 作用距离
	//INT		nChannelDmg[MAX_CHANNEL_TIMES];	// 伤害
	//INT		nCost[ESCT_End];				// 消耗
};

//--------------------------------------------------------------------------------
// 技能模板结构客户端版
//--------------------------------------------------------------------------------*/
struct tagSkillProtoClient : public tagSkillProto
{
	TCHAR					szName[X_SHORT_NAME];			// 技能名称
	TCHAR					szDesc[X_HUGE_NAME];			// 技能描述
	TCHAR					szDescEx[X_HUGE_NAME];			// 技能描述扩展
	TCHAR					szIcon[X_SHORT_NAME];			// 技能图标
	TCHAR					szActionMod[X_SHORT_NAME];		// 技能使用动作模型
	TCHAR					szPrepareMod[X_SHORT_NAME];		// 技能使用起手动作模型
	TCHAR					szNextDesc[X_HUGE_NAME];		// 下一级技能描述
	TCHAR					szSound[X_LONG_NAME];			// 技能攻击音效
    std::vector<tstring>    vecPreSfx;                      // 起手特效
	std::vector<tstring>	vecTagPreSfx;					// 起手特效挂载点或骨骼名称	
    std::vector<tstring>    vecAtkSfx;                      // 攻击特效
	std::vector<tstring>	vecTagAtkSfx;					// 攻击特效挂载点或骨骼名称
	TCHAR					szLchSfx[X_SHORT_NAME];			// 发射特效
	TCHAR					szTagLchSfx[X_SHORT_NAME];		// 发射特效挂载点或骨骼名称
	TCHAR					szLchDesTag[X_SHORT_NAME];	// 发射特效命中点骨骼名称
	TCHAR					szBatkSfx[X_SHORT_NAME];		// 被攻击特效基本编号
	TCHAR					szBatDesTag[X_SHORT_NAME]; //给攻击特效挂点
	INT						nNumBatkSfx;					// 被攻击特效数量
    TCHAR                   szBladeFlareSfx[X_SHORT_NAME];  // 刀光特效
	TCHAR					szInstantEffect[X_SHORT_NAME];	// 人物攻击时刻的瞬时特效，不和动作挂钩
	BOOL					bActionBlend;					// 技能动作是否上下身分开
	BOOL					bAutoNormalAttack;				// 技能是否自动接普通攻击
    BOOL                    bEffectOtherPlayerCamera;       // 技能特效震屏效果对技能释放者之外的其他玩家也起作用
	DWORD					dwAttackTime;					//技能伤害时间段
    DWORD                   dwHitFlyXZSpeed;                // 技能击飞XZ速度
    DWORD                   dwHitFlyYSpeed;                 // 技能击飞Y速度
	DWORD					dwCancelBuffID;					// 取消的buffID
	int						nNumActionTrack;					//攻击动作总数
	e_pet_skill_display_type  pet_skill_display_type;		//宠物技能显示类别
};

//----------------------------------------------------------------------------------
// 技能学些列表
//----------------------------------------------------------------------------------
struct tagLearnSkill
{
	DWORD				dwID;
	std::set<DWORD>		setLearnSkill;
};

//----------------------------------------------------------------------------------
// 普通攻击
//----------------------------------------------------------------------------------
//const INT X_NORMAL_ATTACK_SKILL_NUM = 6;
//
//const DWORD NORMAL_ATTACK_SKILL_ID[X_NORMAL_ATTACK_SKILL_NUM] = // 普通攻击技能ID（大ID）
//{
//	10000,					// 徒手普通攻击
//	10200,					// 暗器普通攻击
//	10100,					// 双持普通攻击
//	10400,					// 长兵普通攻击
//	10300,					// 弓普通攻击
//	10500,					// 法器普通攻击
//};

//-----------------------------------------------------------------------------------
// 某个技能的TypeID是不是普通攻击技能
//-----------------------------------------------------------------------------------
//inline BOOL IsNormalAttackSkill(DWORD dwSkillID)
//{
//	for(INT n = 0; n < X_NORMAL_ATTACK_SKILL_NUM; n++)
//	{
//		if( NORMAL_ATTACK_SKILL_ID[n] == dwSkillID )
//			return TRUE;
//	}
//
//	return FALSE;
//}

//-----------------------------------------------------------------------------------
// 采集类技能
//-----------------------------------------------------------------------------------
const DWORD GATHER_SKILL_MINING		= 90000;	// 采集矿石
const DWORD GATHER_SKILL_HARVEST	= 90001;	// 采集草药
const DWORD GATHER_SKILL_GMINING	= 91000;	// 工会采集矿石
const DWORD GATHER_SKILL_GHARVEST	= 91001;	// 工会采集草药

//-----------------------------------------------------------------------------------
// 调查地物技能tbc:inves
//-----------------------------------------------------------------------------------
const DWORD INVES_SKILL				= 90010;
const DWORD INVES_SKILL_OTHER		= 90011;

//npc打造技能
const DWORD NPC_PRODUCE_SKILL		= 90030;
//炼丹
const DWORD NPC_ALCHEMY_SKILL		= 90040;
//分解
const DWORD DECOM_SKILL				= 90020;

// 成就纹章对应技能
const DWORD ACHIEVEMENT_SIGNET_SKILL[4] = { 70002, 70003, 70004, 70005};

#pragma pack(pop)
