#pragma once 

#include "base_define.h"
#include "AvatarAtt.h"

#pragma pack(push, 1)

const INT	MAX_ROLENUM_ONEACCOUNT				= 15;				// 帐号的最大角色数量
const INT	MAX_ROLECREATENUM_ONEACCOUNT		= 3;				// 帐号的最大创建角色数量
const INT	MAX_ROLE_LEVEL				= 150;				// 玩家可升到的最高级别
const DWORD MAX_SAFECODE_RESET_TIME		= (72 * 60 * 60);	// 安全码最大重置时间(72小时)

const INT	ROLE_LEVEL_LIMIT			= 100;				// 等级上限

const INT	ROLE_HELP_NUM				= 255;				// 人物帮助数量
const INT	TALK_DATA_NUM				= 255;				// 对话数据数量
const INT	MAX_KEY_NUM					= 70;				// 快捷键
const INT   ATTACK_UNMOUNT_PROB			= 1500;				// 打下马的几率(/10000)
const INT	ROLE_DAY_CLEAR_NUM			= 20;				// 每天清零数据

const INT	ROLE_PET_XIULIAN_SIZE		= 5;				// 宠物最大寄养数量

const INT	GUILD_WAR_CD_REBORN_TIME	= 20;				// 帮会战冷却复活时间(秒)

/*
	0 - 签到奖励是否领取
	1 - 工会资金捐献次数(上香)
	2 - 玩家每天分时段可免费抽奖的次数 （gx modify 2013.6.3）
	3 - 日常任务之魔物狩猎次数（gx modify 2013.8.17）
	4 - 玩家当天已完成的付费抽奖的次数 （gx modify 2013.6.5）
	5 - 日常任务之修罗试炼次数（gx modify 2013.8.17）
	6 - 坐骑培养次数
	7 - 酒每日已使用次数 （gx modify 2013.6.5)
	8 - 双修	（gx modify 2013.6.27)
	9 - 今日国王俸禄领取次数（gx modify 2013.6.27)
	10- VIP礼包领取次数（gx modify 2013.8.21）
	11- 副本扫荡次数
	12- 完美复活次数
	13-	雕像膜拜次数（gx modify 2013.8.21）
	14-	大小乔副本次数 gx add 2013.11.06
	15- 师徒每日传功次数 gx add 2013.12.05
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

const INT	MAX_ACTIVE_DATA				= 20;				// 活跃度最大数据
const INT	MAX_ACTIVE_RECEIVE			= 5;				// 活跃度奖励最大数据

const INT	MAX_GUILD_ACTIVE_RECEIVE			= 3;				// 活跃度奖励最大数据

const INT   HANG_TIME					= 60000;			// 挂机时间60秒

const INT	DELETE_ROLE_GUARD_SECOND	= 7 * 24 * 60 * 60; // 删除角色保护时间
const INT	CHANGE_NAME_COST_YUANBAO	= 300;				// 删除角色所需元宝
const INT	CHANGE_NAME_DIFF_SECOND		= 60 * 24 * 60 *60; // 角色更名间隔
const INT	SHOP_EXPLOITS_LIMIT			= 10;				// 战功商店限制

const INT	MAX_INSTANCE_NUM			= 32;				// 副本最大个数

const INT	MAX_DAILY_ACT_NUM			= 17;				//每日活动的个数 gx add 2013.12.18

//属性评分
const INT G_RATING_ATT[][16] = {
	//物攻下限 物攻上限 魔攻下限 魔攻上限 道攻下限 道攻上限 物防下限 物防上限 魔防下限 魔防上限 命中   闪避  暴击  反暴击   hp  mp
	{ 900,	 1800,	 0,	    0,	   0,	  0,	 900,	1800,	900,   1800,  1400,1400,1400,1400,   150,150}, 		
	{ 0,	 0,		 900,	1800,  0,	  0,	 900,	1800,	900,   1800,  1400,1400,1400,1400,   150,150},
	{ 0,	 0,		 0,		0,	   900,	  1800,	 900,	1800,	900,   1800,  1400,1400,1400,1400,   150,150},
};

//---------------------------------------------------------------------------
// 数据变化状态,数据库保存相关
//---------------------------------------------------------------------------
enum EUpdateDBStatus
{
	EUDBS_Null			= 0, // 不保存(默认状态)
	EUDBS_Insert		= 1, // 需插入记录
	EUDBS_Remove		= 2, // 删除
	EUDBS_Update		= 3, // 数据更新
};

//---------------------------------------------------------------------------
// 性别
//---------------------------------------------------------------------------
enum ESex
{
	ES_Null			= -1,
	ES_Woman		= 0,	// 女限制，即女可用
	ES_Man			= 1,	// 男限制，即男可用
};

//----------------------------------------------------------------------------
// 职业类型
//----------------------------------------------------------------------------
//enum EClassType
//{
//	ECT_Start		= -1,
//
//	ECT_Null		= -1,
//	ECT_Hobo		= 0,	// 浪人
//	ECT_Sword		= 1,	// 剑客
//	ECT_Blade		= 2,	// 刀客
//	ECT_Wand		= 3,	// 杖客
//	ECT_Bow			= 4,	// 灵羽
//	ECT_Valor		= 5,	// 气师
//	ECT_Supple		= 6,	// 玄师
//	ECT_Apothecary	= 7,	// 药师
//	ECT_Musician	= 8,	// 乐师
//	ECT_Stabber		= 9,	// 刺客
//
//	ECT_End			= 10,
//};
//
//const INT32 X_ClASS_TYPE_NUM = ECT_End - ECT_Start - 1;

//---------------------------------------------------------------------------
// 职业类型扩展
//---------------------------------------------------------------------------
//enum EClassTypeEx
//{
//	ECTE_Base		= 0x1,	// 基础职业
//
//	ECTE_JianXian	= 0x2,	// 剑仙
//	ECTE_XieWu		= 0x4,	// 邪舞
//
//	ECTE_BaDao		= 0x2,	// 霸刀
//	ECTE_GangRen	= 0x4,	// 罡刃
//
//	ECTE_ZongZhang	= 0x2,	// 宗杖
//	ECTE_DiMo		= 0x4,	// 地墨
//
//	ECTE_TianJian	= 0x2,	// 天箭
//	ECTE_MoLing		= 0x4,	// 魔翎
//
//	ECTE_XuXing		= 0x2,	// 虚行
//	ECTE_GuiQi		= 0x4,	// 鬼气
//
//	ECTE_XuangWang	= 0x2,	// 玄王
//	ECTE_MiZong		= 0x4,	// 密宗
//
//	ECTE_XianYi		= 0x2,	// 仙医
//	ECTE_DuYin		= 0x4,	// 毒隐
//n 
//	ECTE_YuSheng	= 0x2,	// 乐圣
//	ECTE_HuanYin	= 0x4,	// 幻音
//
//	ECTE_YingWu		= 0x2,	// 影武
//	ECTE_GuiWu		= 0x4,	// 鬼武
//};

//---------------------------------------------------------------
// 专精职业
//---------------------------------------------------------------
enum EClassType				 
{
	EV_Begin = -1,
    EV_Null  = 0,
	//modify 2013.4.3
	EV_Warrior,			// 战士
	EV_Mage,				// 法师
	EV_Taoist,			// 道士
	//end

	EV_End,
};

const INT32 X_ClASS_TYPE_NUM = EV_End - EV_Begin - 2;
//--------------------------------------------------------------
// 英雄职业
//--------------------------------------------------------------
enum EClassTypeEx
{
	EHV_Begin = -1,

	EHV_Base = 0,		// 基础职业，未选择英雄职业

	EHV_JianXian,		// 仙剑
	EHV_XieWu,			// 邪舞

	EHV_BaDao,			// 霸刀
	EHV_YingWu,			// 影舞
	
	EHV_JinGang,		// 金刚
	EHV_KuangZhan,		// 狂战
	
	EHV_TianJian,		// 天箭
	EHV_MoLing,			// 魔翎
	
	EHV_XuanHuang,		// 玄皇
	EHV_MiaoFa,			// 妙法
	
	EHV_MingWang,		// 冥王
	EHV_XuKong,			// 虚空
	
	EHV_XianYi,			// 仙医
	EHV_DuYin,			// 毒隐
	
	EHV_YueSheng,		// 乐圣
	EHV_HuanYin,		// 幻音

	EHV_End,
};

//--------------------------------------------------------------------------
// 天资类型
//--------------------------------------------------------------------------
enum ETalentType
{
	ETT_Start		= -1,
	ETT_Null		= -1,

	ETT_Hammer		= 0, // 猛将武器1 锤
	ETT_Ax			= 1, // 猛将武器2 斧
	ETT_Stick		= 2, // 少保武器1 枪
	ETT_Halberd		= 3, // 少保武器2 戟
	ETT_HornBow		= 4, // 游侠武器1 牛角弓
	ETT_IronBow		= 5, // 游侠武器2 铁弓
	ETT_Thorn		= 6, // 刺客武器1 拳刺
	ETT_Round		= 7, // 刺客武器2 月轮
	ETT_Wood		= 8, // 药师武器1 木杖
	ETT_Glass		= 9, // 药师武器2 琉璃杖

	ETT_End			= 10,
};

const INT32 X_TALENT_TYPE_NUM = ETT_End - ETT_Start - 1;

//--------------------------------------------------------------------------
// 能量类型
//--------------------------------------------------------------------------
enum EPowers
{
	EPower_Mana		= 0, //魔法
	EPower_Rage		= 1, //怒气
	EPower_Point	= 2, //点数
	EPower_Energy	= 3, //能量
	Epower_Focus	= 4	 //集中点数
};

const INT32 X_MAX_POWERS = 5;


//--------------------------------------------------------------------------
// 声望类型（可能会有两种类型的声望）
//--------------------------------------------------------------------------
// enum EReputationType
// {
// 	ERT_Start		= -1,
// 	ERT_Null		= -1,
// 
// 	ERT_End			= 0,
// };

//--------------------------------------------------------------------------
// 角色与生物公有状态标示
//--------------------------------------------------------------------------
enum EState
{
	ES_Dead			=	0,	// 死亡
	ES_Dizzy		=	1,	// 眩晕
	ES_Tie			=	2,	// 定身
	ES_Spor			=	3,	// 昏睡
	ES_Invincible	=	4,	// 无敌
	ES_Lurk			=	5,	// 隐身
	ES_DisArm		=	6,	// 缴械
	ES_NoSkill		=	7,	// 封技
	ES_Special		=	8,  // 特殊状态，这样叫为了是能通用一些[但不知道是否能通用]
	ES_Feat			=	9,	// 恐惧
	ES_Combat		=	10,	// 战备(战斗)
	ES_Occupied		=	11,	// 被占领

	ES_End			=	12,
};

//------------------------------------------------------------------
// 角色与怪物共有阵营
//------------------------------------------------------------------
enum ECamp
{
	ECA_Null				= -1,				// 无

	ECA_WaGang			= 0,				// 瓦岗
	ECA_Tang			= 1,				// 唐朝
	ECA_Sui				= 2,				// 隋朝
	ECA_Normal			= 3,				// 野外生物
	ECA_Common			= 4,				// 角色公共势力
	ECA_Battle_a		= 5,				// 战场势力a
	ECA_Battle_b		= 6,				// 战场势力b
	ECA_XueMo			= 7,				// 血魔
	ECA_TianShi			= 8,				// 天市教
	ECA_Role			= 9,				// 野外人形怪

	ECA_End				= 10,				
};

//--------------------------------------------------------------------------
// 角色状态标识 -- 该状态改变，需要向周围玩家广播
//--------------------------------------------------------------------------
const  INT64 ERS_Safeguard	= 0x0001;	// 被保护
const  INT64 ERS_Combat		= 0x0002;	// 战斗姿态
const  INT64 ERS_PK			= 0x0004;	// 行凶状态
const  INT64 ERS_Arena		= 0x0008;	// 擂台(用于PVP活动或战场，该状态由脚本设置）

const  INT64 ERS_SafeArea	= 0x0010;	// 安全区
const  INT64 ERS_PVPArea		= 0x0020;	// PVP区
const  INT64 ERS_StallArea	= 0x0040;	// 摆摊区
const  INT64 ERS_PVP			= 0x0080;	// PVP状态

const  INT64 ERS_Shop		= 0x0100;	// 商店交易
const  INT64 ERS_Exchange	= 0x0200;	// 玩家间直接交易
const  INT64 ERS_Stall		= 0x0400;	// 摆摊交易
const  INT64 ERS_StallSet	= 0x0800;	// 设置摆摊物品

const  INT64 ERS_PrisonArea	= 0x1000;	// 牢狱状态
const  INT64 ERS_Mount		= 0x2000;	// 骑乘
const  INT64 ERS_WaterWalk   = 0x4000;   // 水上行走
const  INT64 ERS_Mount2		= 0x8000;	// 骑乘2

const  INT64 ERS_Commerce	= 0x10000;	// 跑商中	
const  INT64 ERS_PetExchange	= 0x20000;	// 宠物交易
const  INT64 ERS_Prictice	= 0x40000;	// 修炼武器	
const  INT64 ERS_KongFu		= 0x80000;  // 练武

const  INT64 ERS_CommonArea	= 0x100000;	// 普通区域
const  INT64 ERS_RealSafeArea= 0x200000;	// 绝对安全区
const  INT64 ERS_GuildBattle = 0x400000;	// 帮会战区
const  INT64 ERS_NoPunishArea= 0x800000; // 无惩罚区

const  INT64 ERS_ComPractice = 0x1000000;	// 双修 gx modify 2013.6.27
const  INT64 ERS_HangArea   = 0x2000000;	// 挂机区
const  INT64 ERS_Hang	   = 0x4000000; // 挂机状态
const  INT64 ERS_Fishing	   = 0x8000000; // 钓鱼

const  INT64 ERS_Carry	   = 0x10000000; // 搬运
const  INT64 ERS_Comprehend = 0x20000000; // 神悟
const  INT64 ERS_Dancing	   = 0x40000000; // 跳舞

const  INT64 ERS_KongFuArea	  = 0x80000000; // 练武区域

const  INT64 ERS_ComprehendArea = 0x100000000; // 神悟区域
const  INT64 ERS_DancingArea	   = 0x200000000; // 跳舞区域

const  INT64 ERS_End		   = 0x400000000;

typedef INT64 ERoleState;

//--------------------------------------------------------------------------
// 角色状态标识 -- 该状态改变，只需要通知玩家本人
//--------------------------------------------------------------------------
enum ERoleStateEx
{
	ERSE_BagPsdPass		= 0x1,	// 行囊密码验证已通过
	ERSE_BagPsdExist	= 0x2,	// 行囊密码存在
};

//--------------------------------------------------------------------------
// 角色PK模式
//--------------------------------------------------------------------------
enum ERolePKState
{
	ERolePK_Peace	= 0,		// 和平模式
	ERolePK_Guild,				// 帮会模式
	ERolePK_All,				// 全体模式

	ERPKS_End,
};

//-------------------------------------------------------------------------------
// PK模式
//-------------------------------------------------------------------------------
enum EBattleMode
{
	EBM_Peace		= 0,		// 和平模式
	EBM_Guild		= 1,		// 帮会模式
	EBM_Group		= 2,		// 组队模式
	EBM_Whole		= 3,		// 全体模式
};

//-------------------------------------------------------------------------------
// 人物基本属性枚举(该处枚举顺序、个数调整,可能会影响到数据库装备表)
//-------------------------------------------------------------------------------
enum ERoleAttribute
{
	ERA_Null					=	-1,		//
	
	// 一级属性
	ERA_AttA_Start				=	0,
	ERA_Physique				=	0,		// 	体质
	ERA_Strength				=	1,		// 	力量
	ERA_InnerForce				=	2,		//  智慧	
	ERA_Agility					=	3,		// 	敏捷
	ERA_Pneuma					=	4,		// 	--废弃
	ERA_Technique				=	5,		// 	--废弃
	ERA_AttA_End				=	5,

	// 玩家的点数
	ERA_AttPoint				=	6,		// 当前属性点数
	ERA_TalentPoint				=	7,		// 当前天资点数

	// 二级属性
	ERA_AttB_Start				=	8,
	ERA_MaxHP					=	8,		// 最大生命
	ERA_HP						=	9,		// 当前生命
	ERA_MaxMP					=	10,		// 最大魔力
	ERA_MP						=	11,		// 当前魔力
	ERA_ExAttack				=	12,		// 最小物理防御
	ERA_ExDefense				=	13,		// 最大物理防御
	ERA_InAttack				=	14,		// 最小魔法防御
	ERA_InDefense				=	15,		// 最大魔法防御
	ERA_HitRate					=	16,		// 命中率
	ERA_Dodge					=	17,		// 闪避率
	ERA_ShenAttack				=	18,		// 神术攻击
	ERA_Crit_Rate				=	19,		// 暴击率
	ERA_Crit_Amount				=	20,		// 暴击量
	ERA_UnCrit_Rate				=	21,		// 反暴击
	ERA_UnCrit_Amount			=	22,		// 反暴伤
	ERA_HPRegainRate			=	23,		// 体力恢复速度
	ERA_MPRegainRate			=	24,		// 真气恢复速度
	ERA_AttB_End				=	24,

	// 固有属性
	ERA_Love					=	25,		// 爱心值
	ERA_Brotherhood				=	26,		// 义气值
	ERA_MaxBrotherhood			=	27,		// 最大义气
	ERA_Wuhuen					=	28,		// 神龛武魂值
	ERA_Speed_XZ				=	29,		// XZ平面速度速度
	ERA_Speed_Y					=	30,		// Y方向速度
	ERA_Speed_Swim				=	31,		// 游泳的XZ速度
	ERA_Speed_Mount				=	32,		// 骑乘的XZ速度

	// 攻击属性
	ERA_EngraveAtt_Start		=	33,		
	ERA_ExAttackMin				=	33,		// 最小物理攻击
	ERA_ExAttackMax				=	34,		// 最大物理攻击
	ERA_InAttackMin				=	35,		// 最小魔法攻击
	ERA_InAttackMax				=	36,		// 最大魔法攻击
	ERA_ArmorEx					=	37,		// 最小道术攻击
	ERA_ArmorIn					=	38,		// 最大道术攻击
	ERA_EngraveAtt_End			=	38,		


	ERA_Derate_Ordinary			=	39,		// 普通伤害减免	

	ERA_Derate_Start			=	40,
	ERA_Derate_Soil				=	40,		// 地伤害减免
	ERA_Derate_Gold				=	41,		// 水伤害减免
	ERA_Derate_Wood				=	42,		// 风伤害减免
	ERA_Derate_Fire				=	43,		// 火伤害减免
	ERA_Derate_Water			=	44,		// 雷伤害减免
	ERA_Derate_End				=	44,

	ERA_Derate_Injury			=	45,		// 内损伤害减免
	ERA_Derate_Stunt			=	46,		// 绝技伤害减免
	ERA_Derate_ExAttack			=	47,		// 近战伤害减免
	ERA_Derate_InAttack			=	48,		// 远程伤害减免
	ERA_Derate_ALL				=	49,		// 所有伤害减免
	

	ERA_ExDamage				=	50,		// 额外伤害
	ERA_ExDamage_Absorb			=	51,		// 额外伤害吸收

	ERA_Resist_Bleeding			=	52,		// 出血抗性——命中几率
	ERA_Resist_Weak				=	53,		// 虚弱抗性——命中几率
	ERA_Resist_Choas			=	54,		// 混乱抗性——命中几率
	ERA_Resist_Special			=	55,		// 特殊抗性——命中几率
	ERA_Regain_Addtion			=	56,		// 恢复量加成

	ERA_Attack_MissRate			=	57,		// 攻击失误率
	ERA_CloseAttack_DodgeRate	=	58,		// 近战躲避率加成
	ERA_RemoteAttack_DodgeRate	=	59,		// 特殊几率,游侠能量值被打退几率

	ERA_Inspiration				=	60,		// 灵感
	ERA_Luck					=	61,		// 幸运值
	ERA_Savvy					=	62,		// 悟性
	ERA_Morale					=	63,		// 士气
	ERA_Injury					=	64,		// 灵气值
	ERA_Enmity_Degree			=	65,		// 仇恨度
	ERA_Shape					=	66,		// 体型
	ERA_Exp_Add_Rate			=	67,		// 经验获得加成		原经验/金钱/掉率 * (1+加成/10000)
	ERA_Money_Add_Rate			=	68,		// 金钱获得加成
	ERA_Loot_Add_Rate			=	69,		// 物品掉落几率加成

	// 社会属性
	ERA_Fortune					=	70,		// 元气
	ERA_Appearance				=	71,		// 仪容
	ERA_Rein					=	72,		// 统御
	ERA_Knowledge				=	73,		// 声望 gx modify 2013.7.2(阅历)
	ERA_Morality				=	74,		// 灵魂值
	ERA_Culture					=	75,		// 修为

	ERA_End						=	76,
	// 玩家的姓名，声望，投放属性点，已经投放的天资点没有放到基本属性中
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
// 远程玩家的属性枚举
//--------------------------------------------------------------------------------------
enum ERemoteRoleAtt
{
	ERRA_Null		=	-1,		//

	ERRA_MaxHP		=	0,		// 最大体力
	ERRA_HP			=	1,		// 当前体力
	ERRA_MaxMP		=	2,		// 最大真气
	ERRA_MP			=	3,		// 当前真气
	ERRA_Rage		=	4,		// 爱心
	ERRA_Speed_XZ	=	5,		// XZ平面速度
	ERRA_Speed_Y	=	6,		// Y平面速度
	ERRA_Speed_Swim	=	7,		// 游泳速度
	ERRA_Speed_Mount=	8,		// 骑乘速度
	ERRA_Shape		=	9,		// 体型
	//gx add 2013.5.31 查看远程玩家属性
	ERRA_HitRate	=	10,		// 命中率
	ERRA_Dodge		=	11,		// 闪避率
	ERRA_Crit_Rate	=	12,		// 暴击率
	ERRA_UnCrit_Rate	=	13,		// 反暴击
	ERRA_ExAttackMin	=	14,		// 最小物理攻击
	ERRA_ExAttackMax	=	15,		// 最大物理攻击
	ERRA_InAttackMin	=	16,		// 最小魔法攻击
	ERRA_InAttackMax	=	17,		// 最大魔法攻击
	ERRA_ArmorEx	=	18,		// 最小道术攻击
	ERRA_ArmorIn	=	19,		// 最大道术攻击
	ERRA_ExAttack	=	20,		// 最小物理防御
	ERRA_ExDefense	=	21,		// 最大物理防御
	ERRA_InAttack	=	22,		// 最小魔法防御
	ERRA_InDefense	=	23,		// 最大魔法防御
	ERRA_Luck		=	24,		// 幸运值
	ERRA_ShengW		=	25,		//声望值
	//end
	ERRA_End		=	26,
};

//-----------------------------------------------------------------------------------------
// 目标类型标示位
//-----------------------------------------------------------------------------------------
enum ETargetFlag
{
	ETF_Self				=	0x00000001,	// 自身
	ETF_Teammate			=	0x00000002,	// 队友
	ETF_Guildmate			=	0x00000004,	// 同门
	ETF_Lover				=	0x00000008,	// 情侣
	ETF_Couple				=	0x00000010,	// 配偶
	ETF_Brother				=	0x00000020,	// 结拜
	ETF_Teacher				=	0x00000040,	// 师徒
	ETF_Player				=	0x00000080,	// 玩家

	ETF_Pet					=	0x00000100,	// 宠物
	ETF_NPC					=	0x00000200,	// NPC
	ETF_NormalMonster		=	0x00000400,	// 普通怪物
	ETF_Boss				=	0x00000800,	// Boss
	ETF_Nest				=	0x00001000,	// 巢穴
	ETF_NatuRes				=	0x00002000,	// 矿物
	ETF_ManRes				=	0x00004000,	// 草药
	ETF_Door				=	0x00008000,	// 城门
	ETF_Building			=	0x00010000,	// 建筑
	ETF_NormalGameObject	=	0x00020000,	// 普通可交互地物
	ETF_InvesGameObject		=	0x00040000,	// 可调查地物
	ETF_QuestTalkGameObject	=	0x00080000,	// 任务对话地物
    ETF_GuildGameObject     =   0x00100000, // 帮派相关地物 (比如帮派复活点?)
};

//-----------------------------------------------------------------------------------------
// 状态标示位
//-----------------------------------------------------------------------------------------
enum EStateFlag
{
	ESF_Dead			=	0x00000001,	// 死亡
	ESF_NoDead			=	0x00000002,	// 非死亡
	ESF_Dizzy			=	0x00000004,	// 眩晕
	ESF_NoDizzy			=	0x00000008,	// 非眩晕
	ESF_Spor			=	0x00000010,	// 昏睡
	ESF_NoSpor			=	0x00000020,	// 非昏睡
	ESF_Tie				=	0x00000040,	// 定身
	ESF_NoTie			=	0x00000080,	// 非定身
	ESF_Invincible		=	0x00000100,	// 无敌
	ESF_NoInvincible	=	0x00000200,	// 非无敌
	ESF_NoSkill			=	0x00000400,	// 封技
	ESF_NoNoSkill		=	0x00000800, // 非封技
	ESF_DisArm			=	0x00001000,	// 缴械
	ESF_NoDisArm		=	0x00002000,	// 非缴械
	ESF_Lurk			=	0x00004000,	// 隐身
	ESF_NoLurk			=	0x00008000,	// 非隐身
	ESF_Mount			=	0x00010000,	// 骑乘
	ESF_NoMount			=	0x00020000, // 非骑乘
	ESF_Prison			=	0x00040000,	// 牢狱
	ESF_NoPrison		=	0x00080000,	// 非牢狱
	ESF_Mount2			=	0x00100000,	// 骑乘2
	ESF_NoMount2		=	0x00200000, // 非骑乘2
	ESF_Commerce		=	0x00400000,	// 跑商中
	ESF_NoCommerce		=	0x00800000,	// 非跑商中
	ESF_Prictice		=	0x01000000,	// 修炼武器
	ESF_NoPrictice		=	0x02000000,	// 非修炼武器
	ESF_Hang			=   0x04000000, // 挂机
	ESF_NoHang			=   0x08000000,	// 非挂机

};
//Ares 请不要修改此行，RoleDefine.h 和 QuestDef.h相互包含
#include "QuestDef.h" 
//-----------------------------------------------------------------------------------------
// 人物生物基本属性的默认值及最大最小值
//-----------------------------------------------------------------------------------------
struct tagAttDefMinMax
{
	INT		nDefRole;			// 人物初始化默认值
	INT		nDefCreature;		// 生物初始化默认值
	INT		nMin;				// 属性最小值
	INT		nMax;				// 属性最大值
};

////---------------------------------------------------------------------------------------
//// 客户端本地玩家同步数据消息结构（未完成）
////---------------------------------------------------------------------------------------
//struct tagRoleData
//{
//	DWORD			dwID;						// 玩家ID
//	DWORD			dwRoleNameCrc;				// 名称CRC
//	TCHAR			sz_role_name[X_SHORT_NAME];	// 名称
//
//	DWORD			dwMapID;					// 所在的地图的ID
//	FLOAT			fPos[3];					// 位置
//	FLOAT			fFaceTo[3];					// 朝向
//
//	tagAvatarAtt	Avatar;						// 外观
//	tagAvatarEquip	AvatarEquip;				// 装备外观
//	tagDisplaySet	DisplaySet;					// 外观显示设置
//	INT				nAtt[ERA_End];				// 当前人物属性
//
//	INT				nAttPointAdd[X_ERA_ATTA_NUM];// 玩家投放到各个一级属性中的值
//
//	EClassType		eClass;						// 职业
//	EClassTypeEx	eClassEx;					// 扩展职业
//
//	INT16			n16MaxBagSize;				// 背包大小
//	INT16			n16MaxWareSize;				// 账号仓库大小
//
//	INT				nSkillNum;					// 技能个数
//	INT				nBuffNum;					// 状态个数
//	INT				nTitleNum;					// 称号个数
//	INT				nItemNum;					// 物品个数
//	INT				nEquipNum;					// 装备个数
//	INT				nFriendNum;					// 好友个数
//	INT				nEnemyNum;					// 仇敌个数
//	INT				nQuestNum;					// 任务列表个数
//	INT				nQuestDoneNum;				// 已完成的任务个数
//
//	/*********************************************************************************************************
//	 *技能列表，状态列表，称号列表，物品列表，装备列表，好友列表，仇敌列表，任务列表，已完成任务列表
//	 *必须按顺序拷贝
//	 *********************************************************************************************************/
//	//任务列表
//	DWORD			dwIncompleteQuestID[QUEST_MAX_COUNT];			// 在当前玩家身上未完成的任务 30上限
//	DWORD			dwIncompleteQuestTakeTime[QUEST_MAX_COUNT];		// 在当前玩家身上当前任务的接取时间 30上限
//	//任务列表
//	
//
//	BYTE			byData[1];
//};

//------------------------------------------------------------------------------------------
// 在选人界面要看到的人物信息
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
// 是否对远端玩家公开相关信息 -- 注：数据库表记录用32位
//------------------------------------------------------------------------------------------
struct tagRemoteOpenSet
{
	DWORD	bTitle		: 1,	// 称号
			bVCard		: 1,	// 名帖
			bRoleAtt	: 1,	// 角色属性
			bDummy		: 29;	// 占位用

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
// 玩家信息的公开类型
//------------------------------------------------------------------------------------------
enum EPlayerPersonlInfoOpenType
{
	EPIS_Private,  // 完全保密
	EPIS_Friend,   // 仅对互为好友的玩家公开
	EPIS_Public,   // 完全公开
	EPIS_End,
};

//------------------------------------------------------------------------------------------
// 玩家的个人设置
//------------------------------------------------------------------------------------------
struct tagDWPlayerPersonalSet
{
	DWORD	bAcceptTeamInvite		: 1,	// 是否接受组队邀请
			bAcceptFactionInvite	: 1,	// 是否接受帮派邀请
			bAllowFriendAdd			: 1,	// 是否允许其他人添加自己为好友
			bAcceptTradeRequest		: 1,	// 是否接受交易请求
			eInfoOpenType           : 4,    // 信息的公开类型
			bDummy					: 24;	// 占位用

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
// 快捷键信息
//-------------------------------------------------------------------------------------------
struct tagKeyInfo
{
    DWORD		dwID;
    DWORD		dwKey;			// 快捷键1
	DWORD		dwKeyTwo;		// 快捷键2
};

struct roleOnlineState
{
	INT64 hpID;
	INT64 traID;
	int open[7];
}; 

// 元气值
enum EVigourBase
{
	EVB_VALUE = 50, // 初始值
	EVB_DELTA = 50, // 最大值与最小值的差值
};

#define VigourMin(Level) (Level)
#define VigourMax(Level) (100 + Level)

struct tagRolePvP
{
	DWORD	dw_pvp_id;
	INT		nIndex;
	BOOL	b1v1;	// TRUE 1v1竞技场 FALSE 约战竞技场

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
	// 根据职业获得属性抗性
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
	
	// 获取开启宠物寄养栏所需金钱
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
	
	// 寄养时间消耗金币
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

	// 寄养模式消耗元宝
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
	// 寄养模式每分钟获得经验
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
	
	// 寄养时间
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
