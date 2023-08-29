#pragma once

#include "RoleDefine.h"
#include "container_define.h"
#include "../WorldDefine/skill_define.h"
#include "../WorldDefine/time.h"
#include "../WorldDefine/reputation.h"
#include "specfunc_define.h"

#pragma pack(push, 1)

class ItemScript;

//-----------------------------------------------------------------------------
// 常量定义
//-----------------------------------------------------------------------------
const INT MAX_ITEM_TYPE_NUM				= 100000;	// 静态表中，物品装备等最多条数

const INT MAX_ROLEATT_BASE_EFFECT		= 10;	// 装备原型中可填写的影响属性个数

const INT MAX_POSY_TIMES				= 20;	// 一件装备可以最多的铭文次数
const INT MAX_ROLEATT_POSY_EFFECT		= 4;	// 一件装备中铭文最多影响的属性个数

const INT MAX_ENGRAVE_TIMES				= 20;	// 一件装备可以最多的镌刻次数
const INT MAX_ROLEATT_ENGRAVE_EFFECT	= 4;	// 一件装备中镌刻最多影响的属性个数

const INT MAX_ROLEATT_ENHANCE_EFFECT	= 3;	// 强化装备的材料影响的属性个数
const INT MAX_EQUIPHOLE_NUM				= 5;	// 一件装备可以最多的镶嵌孔数数

const INT MAX_BASE_ATT					= 10;	// 基础属性个数
const INT MAX_RAND_ATT					= 5;	// 鉴定属性个数
const INT MAX_ADDITIONAL_EFFECT			= MAX_RAND_ATT+MAX_BASE_ATT;// 装备最大附加属性个数

const INT MAX_BRAND_LEVEL				= 10;	// 装备的烙印等级上限

const INT MAX_CONSOLIDATE_LEVEL			= 15;	// 升星等级上限
const float CONSOLIDATE_PARAM			= 1.15f;// 武器每次升星增加的属性百分比
const float WEAPON_LEVEL_PARAM			= 0.1f;// 武器等级每级影响的百分比

const INT ABRASION2USETIMES				= 450;	// 武器使用次数与崭新度进率.1点崭新度 = 使用1次
const INT ARMORABRASION2USETIMES		= 50;	// 防具使用次数与崭新度进率.1点崭新度 = 使用1次

const INT MAX_ITEM_DCTIME				= 7 * 24 * 60 * 60;	// 物品最长冷却时间(单位：秒)

const INT MAX_EQUIP_ATTACH_NUM          = 20;    // 装备挂载变形模型最大数量

const INT MAX_PEREQUIP_SUIT_NUM			= 3;	// 一件装备最多可属于3套套装

const INT MAX_EQUIP_BUFF_NUM			= 5;	// 装备上带有buff最大个数

const INT MAX_WEAPON_LEVEL				= 70;	// 装备可升等级

const INT MAX_EQUIP_SKILL_NUM			= 12;	// 装备最大技能数

const INT NPC_BIND_TIME					= 2 * 24 * 60 * 60;		// NPC绑定时间
const INT MOUNT_SKILL_NUM				= 1;
const INT BASE_REPIAR_PRICE				= 1;	// 基础修理价格

const INT EQUIP_SKILL_NUMBER			= 2;

// 装备出售价格品级修正系数
#define MCalPriceFactor(fFactor, nQlty)	\
	switch(nQlty)			\
{						\
	case 0:			\
	fFactor = 1.0f;		\
	break;				\
	case 1:			\
	fFactor = 1.5f;		\
	break;				\
	case 2:		\
	fFactor = 2.5f;		\
	break;				\
	case 3:		\
	fFactor = 3.5f;		\
	break;				\
	case 4:		\
	fFactor = 5.0f;		\
	break;				\
	default:				\
	fFactor = 0.1f;		\
	break;				\
}

//-----------------------------------------------------------------------------
// 枚举定义
//-----------------------------------------------------------------------------
//enum EItemType
//{
//	EIT_Null		= 0,
//	EIT_Expend		= 1,	// 消耗品
//	EIT_Unexpend	= 2,	// 非消耗品
//	EIT_Spec		= 3,	// 特殊物品
//	EIT_Pet			= 4,	// 宠物
//	EIT_Bag			= 5,	// 物品包
//	EIT_Mall		= 6,	// 商城道具
//
//	EIT_Weapon		= 7,	// 武器
//	EIT_ClothArmor	= 8,	// 布甲
//	EIT_Decoration	= 9,	// 饰品
//	EIT_Fashion		= 10,	// 时装
//	EIT_Armor		= 11,	// 铠甲
//};

enum EItemType
{
	EIT_Null		= 0,
	EIT_Equip		= 1,	// 装备
	EIT_QiangHua	= 2,	// 强化
	EIT_YaoPin		= 3,	// 药品
	EIT_CaiLiao		= 4,	// 材料
	EIT_Picture		= 5,	// 图纸
	EIT_Ride		= 6,	// 坐骑
	EIT_Pet			= 7,	// 宠物
	EIT_Features	= 8,	// 功能
	EIT_Other		= 9,	// 其他
	EIT_Quest		= 10	// 任务
};

//enum EItemTypeEx
//{
//	EITE_Null		= 0,
//	EITE_Resume		= 1,	// 恢复类
//	EITE_Advance	= 2,	// 强化类
//	EITE_Other		= 3,	// 其他
//	EITE_Material	= 4,	// 原材料
//	EITE_Capture	= 5,	// 战利品
//	EITE_Quest		= 6,	// 任务物品
//	EITE_Book		= 7,	// 秘籍
//	EITE_Pet		= 8,	// 宠物
//	EITE_Ride		= 9,	// 坐骑
//	EITE_Expend		= 10,	// 消耗
//	EITE_Time		= 11,	// 时限
//
//	EITE_Claymore		= 12,	// 双手轮(刺客)
//	EITE_Axe    = 13,	// 双手锤(猛将)
//	EITE_Wand		= 14,	// 长兵(少保)
//	EITE_Gun		= 15,	// 弓(游侠)
//	EITE_Book		= 16,	// 法器(药师)	
//};

enum EItemTypeEx
{
	EITE_Null		= 0,

	EITE_Advance	= 1,	// 强化石
	EITE_ShenShi	= 2,	// 神石
	EITE_DaKong		= 3,	// 打孔石
	EITE_Bind		= 4,	// 绑定石
	EITE_Ling		= 5,	// 灵石

	EITE_Resume		= 6,	// 恢复类
	EITE_QiangHua	= 7,	// 强化类

	EITE_KuangShi	= 8,	// 矿石
	EITE_CaoYao		= 9,	// 草药
	EITE_DaZhaoShui = 10,	// 打造药水
	EITE_PingZhiUp	= 11,	// 品质提升
	
	EITE_Axe    = 12,	// (斧头 ，兽人)
	EITE_Wand		= 13,	// (魔杖，火法师)
	EITE_Gun		= 14,	// (枪，赏金猎人)
	EITE_Claymore		= 15,	// (大剑,星灵)
	EITE_Book		= 16,	// (书，占星师)	
	
	EITE_Ride		= 17,	// 坐骑
	EITE_RideAdvance= 18,	// 坐骑强化
	EITE_RideShenShi= 19,	// 坐骑神石
	EITE_RideEquip	= 20,	// 坐骑装备
					  
	EITE_PetFood	= 21,	// 宠物食物
	EITE_PetSkillBook=22,	// 宠物技能书
					  
	EITE_Prictice	= 23,	// 武器修炼
	EITE_Master		= 24,	// 师傅
	EITE_Guild		= 25,	// 帮会
	EITE_Bag		= 26,	// 包裹扩充
	EITE_BaiTan		= 27,	// 摆摊
					  
	EITE_ZhuiSha	= 28,	// 追杀令
	EITE_ZhaoShu	= 29,	// 诏书
	EITE_Exp		= 30,	// 经验丹
	EITE_YiQi		= 31,	// 义气果


};

const INT32 X_WEAPON_TYPE_NUM = EITE_Book - EITE_Axe + 1;

#define M_WEAPON_TYPE_INDEX(X)    (  X   - EITE_Axe )
#define M_IS_VALID_WEAPON_TYPE(X) ( (X) >= EITE_Axe && (X) <= EITE_Book )

//enum EItemTypeReserved
//{
//	EITR_Null		= 0,
//	EITR_Yaopin		= 1,	// 药品
//	EITR_Shipin		= 2,	// 食品
//	EITR_Xiandan	= 3,	// 仙丹
//	EITR_Yinji		= 5,	// 印记
//	EITR_Baoshi		= 6,	// 宝石
//	EITR_Qizhen		= 7,	// 阵旗
//	EITR_Ranliao	= 8,	// 染料
//	EITR_Siliao		= 9,	// 饲料
//	EITR_Fuzhou		= 10,	// 符咒
//	EITR_Kuangshi	= 11,	// 矿石
//	EITR_Caoyao		= 12,	// 草药
//	EITR_ShiCai		= 13,	// 食材
//	EITR_Buliao		= 14,	// 布料
//	EITR_Mucai		= 15,	// 木材
//	EITR_Yinyuan	= 17,	// 印记原料
//
//	EITR_PETFOOD_Fish = 18,	// 鱼
//	EITR_PETFOOD_ROU  = 19,	// 肉
//	EITR_PETFOOD_Cai  = 20,	// 菜
//	EITR_PETFOOD_Siliao=21,	// 通用宠物饲料
//};

enum EItemTypeReserved
{
	//装备
	EITR_Null		= 0,
	EITR_Weapon		= 1,	// 武器
	EITR_Head		= 2,	// 头
	EITR_Body		= 3,	// 上身
	EITR_Hand		= 4,	// 头
	EITR_Feet		= 5,	// 脚
	EITR_Body0		= 6,	// 内甲
	EITR_Body1		= 7,	// 背部
	EITR_Wrist		= 8,	// 手腕
	EITR_Waist		= 9,	// 腰带
	EITR_Legs		= 10,	// 腿
	EITR_Neck		= 11,	// 项链
	EITR_Finger		= 12,	// 戒指
	EITR_Shipin		= 13,	// 饰品
	EITR_Fashion	= 14,	// 时装

	//灵石
	EITR_HP_LS		= 15,	// 生命
	EITR_Ack_LS		= 16,	// 攻击
	EITR_Def_LS		= 17,	// 防御
	EITR_Hit_LS		= 18,	// 命中
	EITR_ZJ_LS		= 19,	// 招架
	EITR_SB_LS		= 20,	// 闪避
	EITR_Crit_LS	= 21,	// 暴击
	EITR_CirtH_LS	= 22,	// 暴击伤害
	EITR_FanCrit_LS	= 23,	// 反暴击
	EITR_FanCritH_LS= 24,	// 反暴伤
	EITR_HPH_LS		= 25,	// 生命恢复
	EITR_LiLiang_LS	= 26,	// 力量
	EITR_MinJie_LS	= 27,	// 敏捷
	EITR_ZhiLi_LS	= 28,	// 智力
	EITR_NaiLi_LS	= 29,	// 耐力
	

	//扩充
	EITR_BeiBao		= 30,	// 背包扩充
	EITR_Cangku		= 31,	// 仓库扩充
	
	//宠物食品
	EITR_PETFOOD_Fish = 32,	// 鱼
	EITR_PETFOOD_ROU  = 33,	// 肉
	EITR_PETFOOD_Cai  = 34,	// 菜
	EITR_PETFOOD_Siliao=35,	// 通用宠物饲料

	EITR_PETFOOD_ADDHP = 36,// 宠物增加hp
	EITR_PETFOOD_REBORN = 37, // 宠物复活

	EITR_CHUTOU			= 38, // 工会采矿锄头
};

#define MISPETFOOD(pItemProto) ((pItemProto)->eTypeReserved >= EITR_PETFOOD_Fish && (pItemProto)->eTypeReserved <= EITR_PETFOOD_Siliao)

//enum EItemQuality
//{
//	EIQ_Start		= -1,
//
//	EIQ_Null		= -1,	// 未鉴定
//	EIQ_White		= 0,	// 白
//	EIQ_Blue		= 1,	// 蓝
//	EIQ_Yellow		= 2,	// 黄
//	EIQ_Orange		= 3,	// 橙
//	EIQ_Purple		= 4,	// 紫
//
//	EIQ_End			= 5,
//};

enum EItemQuality
{
	EIQ_Start			= -1,

	EIQ_Null			= -1,	// 未鉴定
	EIQ_Quality0		= 0,	// 白
	EIQ_Quality1		= 1,	// 绿
	EIQ_Quality2		= 2,	// 蓝
	EIQ_Quality3		= 3,	// 紫
	EIQ_Quality4		= 4,	// 橙
	EIQ_Quality5		= 5,	// 金

	EIQ_End			= 6,
};

const INT32 X_EQUIP_QUALITY_NUM = EIQ_End - EIQ_Start - 1;

enum EBindMode	// 绑定类型
{
	EBM_Null		= 0,	// 无

	EBM_Gain		= 1,	// 获得绑定
};

enum EBindStatus	// 绑定状态
{
	EBS_Unknown		= 0,	// 未知的，如商店中的商品
	EBS_Unbind		= 1,	// 未绑定
	EBS_Bind		= 2,	// 绑定
};

//enum ETimeMode		// 计时方式
//{
//	ETM_Null		= 0,
//	TEM_Create		= 1, // 生成计时
//	TEM_Online		= 2, // 线上计时
//	TEM_Battle		= 3, // 战斗计时
//	TEM_Quest		= 4, // 任务触发计时
//	TEM_Used		= 5, // 使用后计时
//	TEM_Get			= 6, // 获得计时
//};

enum ESexLimit		// 物品可使用的角色性别,要与AvatarAtt中性别对应
{
	ESL_Null		= -1,	// 不限制，即男女均可用
	ESL_Woman		= 0,	// 女限制，即女可用
	ESL_Man			= 1,	// 男限制，即男可用
};


enum EWuXing	// 五行属性
{
	EWX_Start		= -1,
	EWX_Null		= -1,

	EWX_Metal		= 0,
	EWX_Wood		= 1,
	EWX_Water		= 2,
	EWX_Fire		= 3,
	EWX_Soil		= 4,

	EWX_End			= 5,
};

const INT32 X_WUXING_TYPE_NUM = EWX_End - EWX_Start - 1;


enum EStuffType		// 材料类型
{
	EST_Null		= 0,	//无
	EST_Stone		= 1,	//石
	EST_Jade		= 2,	//玉
	EST_Iron		= 3,	//铁
	EST_Silver		= 4,	//银
	EST_Gold		= 5,	//金
	EST_ChunXinCao	= 6,	//春辛草
	EST_XiaKuCao	= 7,	//夏枯草
	EST_QiuBaiCao	= 8,	//秋白草
	EST_DongKuiCao	= 9,	//冬葵草
	EST_DongYangCao = 10,	//东阳草
	EST_Flax		= 11,	//麻布
	EST_Leather		= 12,	//皮革
	EST_Cotton		= 13,	//棉布
	EST_SilkOrgandy	= 14,	//素纱
	EST_Silk		= 15,	//丝绸
	EST_Chop		= 16,	//肉块
	EST_Dew			= 17,	//露水
	EST_Grain		= 18,	//谷物
	EST_Bone		= 19,	//骨头
	EST_Potherb		= 20,	//野菜
};

enum EItemCreateMode	// 物品&装备生产方式
{
	EICM_Null		= 0, // 没有记录
	EICM_GM			= 1, // GM命令生成
	EICM_Loot		= 2, // 怪物掉落
	EICM_Quest		= 3, // 任务奖励
	EICM_Product	= 4, // 玩家生产
	EICM_ShopNPC	= 5, // 商店NPC
	EICM_AccQuest	= 6, // 接任务
	EICM_Mall		= 7, // 商城
	EICM_Gift		= 8, // 礼品包
	EICM_ActTreasure= 9, // 激活氏族珍宝
	EICM_GMTool		= 10,// GM工具生成
	EICM_PetSkill	= 11,// 宠物技能
	EICM_VipNetBar	= 12,// 金牌网吧
	EICM_ReGet		= 13,// 道具恢复
	EICM_Activity	= 14,// 活动奖励
	EICM_Unbeset	= 15,// 拆嵌
	EICM_Guild		= 16,// 帮会
	EICM_Mail		= 17,// 邮件
	EICM_NewRoleGift = 18, //新手奖励
	EICM_Fishing	 = 19, // 钓鱼
	EICM_Product_picture	= 20, // 图纸生成
	EICM_Lottery	= 21,  // 彩票机
	EICM_Sign			=	22,		// 签到生成
	EICM_DAMO		= 23,	// 打磨

};

enum EEnhanceEquipPos	// 可强化的装备类型
{
	EEEP_Hand		= 0x00000001,	// 武器
	EEEP_Head		= 0x00000002,	// 头部
	EEEP_Face		= 0x00000004,	// 面部
	EEEP_Body		= 0x00000008,	// 上身
	EEEP_Legs		= 0x00000010,	// 下身
	EEEP_Back		= 0x00000020,	// 背部
	EEEP_Wrist		= 0x00000040,	// 腕部
	EEEP_Feet		= 0x00000080,	// 足部
	EEEP_Finger		= 0x00000100,	// 戒指
	EEEP_Waist		= 0x00000200,	// 腰饰
	EEEP_Neck		= 0x00000400,	// 项链
};

enum EEquipMdlType     // 装备的模型类型
{
	EEMT_NULL	= 0,
	EEMT_FSKIN  = 1,   // 蒙皮
	EEMT_FAK    = 2,   // 关键帧
	EEMT_FSM    = 3,   // 静态模型
};

enum EEquipAttachPos    // 装备可变形部分的挂载位置
{
    EEAP_NULL     = 0,
    EEAP_HAA      = 1,  // 头部
    EEAP_HWR      = 2,  // 右手
    EEAP_SHR      = 3,  // 右肩
    EEAP_GRA      = 4,  // 右小臂
    EEAP_HWL      = 5,  // 左手
    EEAP_SHL      = 6,  // 左肩
    EEAP_GLA      = 7,  // 左小臂
    EEAP_CHM      = 8,  // 前胸
    EEAP_BAL      = 9,  // 背部披风
    EEAP_FLA      = 10, // 左脚
    EEAP_LLA      = 11, // 左小腿
    EEAP_FRA      = 12, // 右脚
    EEAP_LRA      = 13, // 右小腿
    EEAP_CHP      = 14, // 腰部
	EEAP_Num      = 15,
};



enum ECorlor		// 颜色贴图枚举
{
	EC_Null		= -1,

	EC_Start	= 0,
	EC_Val0		= 0,
	EC_Val1		= 1,
	EC_Val2		= 2,
	EC_Val3		= 3,
	EC_Val4		= 4,
	EC_Val5		= 5,
	EC_Val6		= 6,
	EC_Val7		= 7,
	EC_Val8		= 8,
	EC_Val9		= 9,
	EC_Val10	= 10,
	EC_Val11	= 11,
	EC_End		= 11,
};

const INT X_COLOR_NUM	= EC_End - EC_Start + 1;

//装备附加属性
enum EquipAddAtt
{
	EAA_NULL			= -1,
	EAA_Statr			= 0,

	EAA_ExAttackMin		= 0,		// 物攻下限
	EAA_ExAttackMax		= 1,		// 物攻上限
	EAA_InAttackMin		= 2,		// 魔攻下限
	EAA_InAttackMax		= 3,		// 魔攻上限
	EAA_ArmorEx			= 4,		// 道攻下限
	EAA_ArmorIn			= 5,		// 道攻上限
	EAA_ExAttack		= 6,		// 物防下限
	EAA_ExDef			= 7,		// 物防上限
	EAA_InAttack		= 8,		// 魔防下限
	EAA_InDefense		= 9,		// 魔防上限
	EAA_HitRate			= 10,		// 命中
	EAA_Dodge			= 11,		// 闪避
	EAA_Crit_Rate		= 12,		// 暴击
	EAA_UnCrit_Rate		= 13,		// 反暴击
	EAA_MaxHP			= 14,		// hp
	EAA_MaxMP			= 15,		// mp

	EAA_End				= 15,	
};

const INT16 ADDATT_TYPE_NUM = EAA_End-EAA_Statr+1;

//武器可随到的附加属性
enum WeaponRoleAtt
{
	WRA_Null				= -1,
	WRA_ExAttack			= 0,		// 近战攻击
	WRA_HitRate				= 1,		// 命中
	WRA_Ren					= 2,		// 招架
	WRA_Cirt				= 3,		// 暴击
	WRA_CirtNum				= 4,		// 暴击伤害
	WRA_Potence				= 5,		// 力量
	WRA_Agility				= 6,		// 敏捷
	WRA_Brains				= 7,		// 智力
	WRA_Stamina				= 8,		// 耐力
	WRA_NUM					= 9,
};

// 饰物可随到的附加属性
enum DecorationRoleAtt
{
	DRA_Null				= -1,
	DRA_ExAttack			= 0,		// 近战攻击
	DRA_HitRate				= 1,		// 命中
	DRA_Cirt				= 2,		// 暴击
	DRA_CirtNum				= 3,		// 暴击伤害
	DRA_Potence				= 4,		// 力量
	DRA_Agility				= 5,		// 敏捷
	DRA_Brains				= 6,		// 智力
	DRA_Stamina				= 7,		// 耐力
	DRA_NUM					= 8,		
};

//防具可随到的附加属性
enum ArmorRoleAtt
{
	ARA_Null				= -1,
	ARA_Dodge				= 0,			// 闪避
	ARA_ExDefense			= 1,			// 近战防御
	ARA_Potence				= 2,			// 力量
	ARA_Agility				= 3,			// 敏捷
	ARA_Brains				= 4,			// 智力
	ARA_Stamina				= 5,			// 耐力
	ARA_FanCirt				= 6,			// 反暴击率
	ARA_FanCirtNum			= 7,			// 反暴击伤害
	ARA_Ren					= 8,			// 招架

	ARA_Armor_NUM			= 9,
};

// 饰品可随到的附加属性
enum ShiPinRoleAtt
{
	SP_Null					= -1,
	SP_Potence				= 0,		// 力量
	SP_Agility				= 1,		// 敏捷
	SP_Brains				= 2,		// 智力
	SP_Dodge				= 3,		// 闪避
	SP_HitRate				= 4,		// 命中
	SP_Cirt					= 5,		// 暴击
	SP_CirtNum				= 6,		// 暴击伤害
	SP_Ren					= 7,		// 招架
	SP_FanCirt				= 8,		// 反暴击率
	SP_FanCirtNum			= 9,		// 反暴击伤害

	SP_NUM					= 10,		
};

enum RideEquipState
{
	ERES_Idle		= 0,
	ERES_Riding		= 1,
};



//-----------------------------------------------------------------------------
// 结构定义
//-----------------------------------------------------------------------------
struct tagRoleAttEffect
{
	ERoleAttribute	eRoleAtt;
	INT32			nValue;

	tagRoleAttEffect() { ZeroMemory(this, sizeof(*this)); eRoleAtt = ERA_Null; }
};

struct tagEquipQltyPct
{
	DWORD				dw_data_id;
	INT32				nEquipQltyPct[X_EQUIP_QUALITY_NUM];	// 品级生成几率
};

struct tagCDTime
{
	DWORD		dw_data_id;
	DWORD		dw_time;		// 冷却时间(单位：毫秒)
};

struct tagEquipLevelUpEffect
{
	INT		nExpLevelUp;		//升到下一级所需的经验值曾量
	INT		nExpLevelUpShipin;	//饰品升到下一级所需的经验值曾量
	INT16	n16TalentAvail;		//得到的可投天资点
};

/** struct	tagItemDisplayInfo
brief	物品显示结构
remarks	主要用于存储物品的名称、类型、描述、模型等等	
*/
struct tagItemDisplayInfo
{
	TCHAR				szType[X_SHORT_NAME];				// 显示类型
	TCHAR				szName[X_SHORT_NAME];				// 物品名称
	TCHAR				szDesc[X_HUGE_NAME];				// 物品描述
	TCHAR				szDescEx[X_LONG_NAME];				// 物品特性描述
	TCHAR				szMaleIcon[X_SHORT_NAME];			// 物品图标男版
	TCHAR				szFemaleIcon[X_SHORT_NAME];			// 物品图标女版
	TCHAR				szActionMod[X_SHORT_NAME];			// 物品使用动作编号
	TCHAR				szEffectMod[X_SHORT_NAME];			// 物品使用特效编号
	TCHAR				szSourceEffect[X_SHORT_NAME];		// 物品使用发起者特效编号
	TCHAR				szDestEffect[X_SHORT_NAME];			// 物品使用目标特效编号
	TCHAR				szPrepareMod[X_SHORT_NAME];			// 物品使用起手动作编号
    TCHAR				szPrepareEffect[X_SHORT_NAME];		// 物品使用起手特效编号
	TCHAR				szMaleRightMod[X_SHORT_NAME];		// 男模型编号1
	TCHAR				szFemaleRightMod[X_SHORT_NAME];		// 女模型编号1
	TCHAR				szMaleLeftMod[X_SHORT_NAME];		// 男模型编号2
	TCHAR				szFemaleLeftMod[X_SHORT_NAME];		// 女模型编号2
    TCHAR               szTexPostfix[X_SHORT_NAME];         // 贴图后缀
	TCHAR				szDropMod[X_SHORT_NAME];			// 掉落模型编号
	TCHAR				szPertainMod[X_SHORT_NAME];			// 附属模型编号
	TCHAR				szBladeFlareSFX[X_SHORT_NAME];		// 刀光特效编号
    TCHAR				szGlowSFX[X_LONG_NAME];		        // 光晕特效编号
	TCHAR				szMaleGlowSFX[X_LONG_NAME];		    // 男光晕特效编号
    TCHAR				szFemaleGlowSFX[X_LONG_NAME];		// 女光晕特效编号
    TCHAR				szAttachSFX[X_LONG_NAME];           // 挂载特效编号
    TCHAR               szMaleAttachSFX[X_LONG_NAME];       // 男模型挂载特效
    TCHAR               szFemaleAttachSFX[X_LONG_NAME];     // 女模型挂载特效

	TCHAR				szMaleShoulderMode[X_LONG_NAME];   //男披风模型
	TCHAR				szFemaleShoulderMode[X_LONG_NAME]; //女披风模型

	EWeaponPos			ePertainModPos;						// 附属模型挂载位置
	EEquipMdlType       eModelType;							// 模型类型
	EEquipAttachPos     eAttachModelPos[MAX_EQUIP_ATTACH_NUM];  // 挂载变形模型的位置
	BOOL				bActionBlend;						// 是否上下身分开
	
	tagItemDisplayInfo(){ZeroMemory(this, sizeof(*this));}
};

struct tagItemProto
{
	DWORD				dw_data_id;		// 基本物品种类编号(同种物品相同)

	EItemType			eType;			// 基本类性
	EItemTypeEx			eTypeEx;		// 扩展类型
	EItemTypeReserved	eTypeReserved;	// 保留类型

	EStuffType			eStuffType;		// 材料类型，合成用

 	DWORD				dwQuestID;		// 任务编号
	INT32				nBasePrice;		// 基础价格

	INT32				nGemNess;		// 镶嵌物的耐久度
	INT32				nMaxUseTimes;	// 最多使用次数
	INT16				n16MaxLapNum;	// 最大叠放数量
	INT16				n16MaxHoldNum;	// 最大拥有数量

	DWORD				dwTimeLimit;	// 有时限物品(秒)

	INT16				n16Enmity;		// 仇恨

	BYTE				byMinUseLevel;	// 等级限制
	BYTE				byMaxUseLevel;	// 等级上限
	ESexLimit			eSexLimit;		// 性别限制
	DWORD				dwVocationLimit;// 职业限制

	//EReputationType		eClanRepute;	// 氏族声望类型值
	//INT32				nClanReputeVal;	// 氏族声望值
	//EReputationType		eOtherClanRepute;	// 其他声望类型值
	//INT32				nOtherClanReputeVal;// 其他声望值

	EItemSpecFunc		eSpecFunc;		// 物品特殊功用类型
	INT32				nSpecFuncVal1;
	INT32				nSpecFuncVal2;

	ESkillOPType		eOPType;							// 作用类型
	FLOAT				fOPDist;							// 作用距离（世界单位）
	FLOAT				fOPRadius;							// 作用范围（世界单位）
	INT32				nPrepareTime;						// 起手时间（毫秒）
	DWORD				dwCooldownTime;						// 技能冷却时间(单位：ms)
	INT32				nInterruptSkillOrdRate;				// 普通技能打断几率[0,10000]
	DWORD				dwSpecBuffLimitID;					// 自身BUFF限制ID
	DWORD				dwStateLimit;						// 自身状态标志位限制
	DWORD				dwTargetLimit;						// 对象限制
	BOOL				bMoveable;							// 是否可以移动使用			
	bool				bInterruptMove;						// 是否移动打断

	BYTE				byLevel;			// 物品等级
	BYTE				byQuality;			// 物品品级

	BYTE				byBindType;			// 绑定类型

	DWORD				dwTriggerID0;		// 触发条件
	DWORD				dwBuffID0;			// Buff
	
	DWORD				dwTriggerID1;		// 触发器ID1
	DWORD				dwBuffID1;			// 状态ID1

	DWORD				dwTransTriggerID;	// 变形触发类型ID
	DWORD				dwTransID;			// 变形后ID

	bool				bNeedBroadcast;		// 是否广播(0，不广播；1，广播)
	bool				bCanSell;			// 是否不可出售(0，可出售；1，不可出售)

	bool				bNeedLog;			// 是否需要做log(该属性有运营通过数据表item_needlog编辑)
	BYTE				byLogMinQlty;		// 记录log物品的最低品级

	bool				bDeadLoot;			// 死亡掉落
	
	tagItemDisplayInfo*	pDisplayInfo;		// 物品显示结构，客户端用

	INT					n_keeping;			// 物品拍卖保管费
	BOOL				bCantDrop;
	
	tagItemProto(){ZeroMemory(this,sizeof(*this));}
	tagItemProto(DWORD dwID){ZeroMemory(this,sizeof(*this)); dw_data_id = dwID;}
};

struct tagEquipProto: public tagItemProto
{
	ETalentType			eTalentType;							// 天资类型

	DWORD				dwSuitID[MAX_PEREQUIP_SUIT_NUM];		// 套装编号
	BYTE				bySuitMinQlty[MAX_PEREQUIP_SUIT_NUM];	// 最低品级要求
	//bool				bCanDye;								// 时装是否可染色

	//INT16				n16AttALimit[X_ERA_ATTA_NUM];			// 属性限制
	
	DWORD				dwVocationLimitWear;					// 穿戴职业限制
	DWORD				dwPkValueLimit;							// pk值不能大于

	EEquipPos			eEquipPos;		// 装备位置
	//EWeaponPos			eWeaponPos;		// 武器位置

	INT16				n16MinDmg;		// 武器最小伤害
	INT16				n16MaxDmg;		// 器最大伤害
	//INT16				n16MinDmgIn;	// 远程武器最小伤害
	//INT16				n16MaxDmgIn;	// 远程武器最大伤害
	INT16				n16Armor;		// 防具护甲
	//INT16				n16ArmorIn;		// 远程防具护甲

	//INT32				nMaxPotVal;		// 装备最大潜力值
	//INT32				nPotVal;		// 装备潜力值

	tagRoleAttEffect	BaseEffect[MAX_ROLEATT_BASE_EFFECT];// 加工前，影响的属性(和品级无关)
	tagRoleAttEffect	RandEffect[MAX_BASE_ATT];			// 附加属性固定值
	DWORD				dwRandEffectPro[MAX_BASE_ATT];		// 附加属性出现几率
	//BYTE				byClassLimit[X_ClASS_TYPE_NUM];		// 职业限制(指定职业可用)//??

	DWORD				dwTriggerID2;		// 触发器ID1
	DWORD				dwBuffID2;			// 状态ID1
	
	//附加技能
	DWORD				dwSkillID[EQUIP_SKILL_NUMBER];

	//DWORD				dwColor;			// 颜色

	INT16				n16Newness;			// 耐久度

	//bool				bIdentifyProduct;	// 生产鉴定状态
	//bool				bIdentifyLoot;		// 掉落鉴定状态
	
	//INT16				n16HolePrice;		//装备打孔价格
	
	//INT16				n16HolePriceDiff;	//打孔价格浮动系数
	
	DWORD				dwPetID;			// 骑乘ID
	
	CHAR				byLuck;				// 幸运
	
	BYTE				bySuitTriggerCount;	// 套装触发器触发次数

	tagEquipProto(){ZeroMemory(this,sizeof(*this));}
	tagEquipProto(DWORD dwID){ZeroMemory(this, sizeof(*this)); dw_data_id = dwID;}
};

#define MArmorMaxUseTimes(pEquipProto)	((pEquipProto)->n16Newness * ARMORABRASION2USETIMES)
#define MEquipMaxUseTimes(pEquipProto)	((pEquipProto)->n16Newness * ABRASION2USETIMES)
#define MEquipIsRide(pItemProto) ((pItemProto)->eTypeEx == EITE_Ride )
#define MIsWeapon(pItemProto) ((pItemProto)->eTypeReserved == EITR_Weapon && (pItemProto)->eType == EIT_Equip)
//struct tagGemProto		// 强化物品原型
//{
//	DWORD				dw_data_id;		// 物品原型编号
//
//	INT16				n16PotValNeed;	// 需要消耗的装备潜力值
//	INT16				n16SuccessPct;	// 成功率
//
//	tagRoleAttEffect	BaseEffect[MAX_ROLEATT_ENHANCE_EFFECT];	// 装备强化影响
//
//	INT32				nEnhanceFlg;	// 按位记录 -- EEnhanceEquipPos
//
//	tagGemProto() { ZeroMemory(this, sizeof(*this)); }
//};

struct tagItem
{
	INT64			n64_serial;		// 物品唯一序列号(不同堆叠物品不同)
	DWORD			dw_data_id;		// 基本物品种类编号(同种物品相同)

	INT16			n16Num;			// 物品个数
	bool			bLock	: 1;	// 锁定标志
	bool			bUsing	: 1;	// 是否在对该物品进行其他操作
	bool			bCreateBind;	// 生成的时候是否绑定
	BYTE			byBind;			// 绑定状态
	INT32			nUseTimes;		// 物品上技能使用次数

	DWORD			dw_account_id;	// 玩家账号ID, 百宝袋和角色仓库用(同一帐号下角色共享)
	DWORD			dwOwnerID;		// 拥有者, INVALID_VALUE表示没有拥有者

	EItemConType	eConType;		// 物品所在容器类型
	INT16			n16Index;		// 物品在容器中的位置
	INT16			n16Dummy;		// 内存对齐用

	EItemCreateMode	eCreateMode;	// 物品&装备生成方式
	DWORD			dwCreateID;		// 外部生成该物品的ID，如：GMID，QuestID等, 界面上不显示
	
	DWORD			dwCreatorID;	// 物品制作者，INVALID_VALUE表示系统生产, 界面上显示
	tagDWORDTime	dwCreateTime;	// 制作物品的时间

	DWORD			dwNameID;		// 珍宝名字ID

	tagDWORDTime	dw1stGainTime;	// 第一个玩家获得时间
	
	tagDWORDTime	dwBindTime;	// 绑定时间

	EUpdateDBStatus	eStatus;		// 记录物品是否需要进行数据库操作

	union
	{
		const tagItemProto	*pProtoType;	// 指向物品基本属性
		const tagEquipProto	*pEquipProto;	// 执行装备基本属性
	};

	const ItemScript		*pScript;		// 脚本指针
	DWORD			dw_script_data[2];		// 脚本数据
	
	tagItem() { ZeroMemory(this, sizeof(*this)); }
	VOID SetOwner(DWORD dwNewOwnerID, DWORD dwNewAccountID) { dwOwnerID = dwNewOwnerID; dw_account_id = dwNewAccountID; }
	VOID SetPos(EItemConType eNewCon, INT16 n16NewIndex) { eConType = eNewCon; n16Index = n16NewIndex; }
	VOID SetIndex(INT16 n16NewIndex) { n16Index = n16NewIndex; }
	VOID SetUsing(bool bUsingState) { bUsing = bUsingState; }
	VOID SetUpdate(EUpdateDBStatus eNewUpdateStatus) { eStatus = eNewUpdateStatus; }
	INT64 GetKey() const { return n64_serial; }
	INT16 GetNum() const { return n16Num; }
	BOOL CanOverlap() const { return (VALID_POINT(pProtoType) ? pProtoType->n16MaxLapNum > 1 : FALSE); }
	VOID IncUseTimes(INT32 nUse) { nUseTimes += nUse; SetUpdate(EUDBS_Update); }
	BYTE GetQuality() const { return pProtoType->byQuality; }
 
	// 得到某个索引对应的BuffID
	DWORD GetBuffID(INT nIndex)
	{
		switch(nIndex)
		{
		case 0:
			return pProtoType->dwBuffID0;
		case 1:
			return pProtoType->dwBuffID1;
		case 2:
			return pProtoType->dwTransID;
		default:
			return INVALID_VALUE;
		}
	}

	// 得到某个索引对应的TriggerID
	DWORD GetTriggerID(INT nIndex)
	{
		switch(nIndex)
		{
		case 0:
			return pProtoType->dwTriggerID0;
		case 1:
			return pProtoType->dwTriggerID1;
		case 2:
			return pProtoType->dwTransTriggerID;
		default:
			return INVALID_VALUE;
		}
	}

	//VOID Bind()
	//{
	//	SI_ASSERT(VALID_POINT(pProtoType));
	//	switch(pProtoType->byBindType)
	//	{
	//	case EBM_Null:
	//		byBind = EBS_Unbind;
	//		break;
	//	case EBM_Gain:
	//		byBind = EBS_Bind;
	//		break;
	//	}
	//}

	VOID SetBind(EBindStatus bindtype)
	{
		if (byBind == bindtype)
			return;

		byBind = bindtype;
		SetUpdate(EUDBS_Update);	
	}

	VOID SetBindTime(DWORD bindtime)
	{
		dwBindTime = bindtime;
	}

	VOID SetBindTime(const tagDWORDTime& bindtime)
	{
		dwBindTime = bindtime;
		SetUpdate(EUDBS_Update);
	}

	VOID UpdateBind(EBindStatus bindtype , DWORD bindtime)
	{
		byBind = bindtype;
		dwBindTime = bindtime;
	}

	BOOL IsBind() const { return EBS_Unbind != byBind && EBS_Unknown != byBind; }
	BOOL IsLock() const { return bLock;}
	BOOL IsLevelLimit(BYTE byRoleLevel) const
	{
		return pProtoType->byMinUseLevel > byRoleLevel || pProtoType->byMaxUseLevel < byRoleLevel;
	}

	BOOL is_time_limit() const { return pProtoType->dwTimeLimit != INVALID_VALUE; }

};

struct tagEquipSpec
{
	/******武器升级相关******/
	//INT32					nLevel;			// 等级
	//INT32					nCurLevelExp;	// 当前升级经验

	///******装备鉴定时确定******/
	//INT16				n16MinDmg;		// 近战武器最小伤害
	//INT16				n16MaxDmg;		// 近战武器最大伤害
	//INT16				n16Armor;		// 近战防具护甲
	//
	// 附加属性
	tagRoleAttEffect	EquipAttitionalAtt[MAX_ADDITIONAL_EFFECT];	
	// 洗点属性
	INT32				EquipAttitional[MAX_RAND_ATT];

	CHAR				byLuck;
	// 特殊属性
	//BYTE				bySpecAtt;
	
	/******武器技能天赋******/
	//BYTE				byTalentPoint;//已投天赋点
	//BYTE				byMaxTalentPoint;//最大天赋点
	//INT8				byAddTalentPoint;//附加天赋点
	//DWORD				dwSkillList[MAX_EQUIP_SKILL_NUM];//技能列表

	// 使用等级限制(便于外部因素作用)
	//BYTE				byMinUseLevel;
	//BYTE				byMaxUseLevel;

	// 品级
	BYTE				byQuality;
	INT					nRating;

	/******装备强化时修改******/
	//BYTE				byFlareVal;		// 光晕

	BYTE				byHoleNum;
	BYTE				byConsolidateLevel;//强化等级

	DWORD				dwHoleGemID[MAX_EQUIPHOLE_NUM];

	/******方法******/
	tagEquipSpec() { ZeroMemory(this, sizeof(*this));}

	DWORD getGemNum() const
	{ 
		DWORD dwNum = 0;
		for (int i = 0; i < MAX_EQUIPHOLE_NUM; i++)
		{
			if ( dwHoleGemID[i] != 0 && dwHoleGemID[i] != -1)
			{
				dwNum++;
			}
		}
		return dwNum;
	}
};

struct tagEquip: public tagItem
{
	tagEquipSpec	equipSpec;

	BOOL ExpChange(INT nValue);
	static INT16 GetAddTalent(INT32 beginLevel, INT32 endLevel);
	//VOID LevelChange(INT nValue)
	//{
	//	if( nValue < 0 || nValue > pEquipProto->byMaxLevel )
	//		return;

	//	if( equipSpec.nLevel == nValue ) return;

	//	equipSpec.nLevel = nValue;
	//	equipSpec.nCurLevelExp = 0;
	//}

	//VOID SetFlareVal(BYTE byFlareVal)
	//{
	//	equipSpec.byFlareVal = byFlareVal;
	//}

	//VOID ChangeFlareVal(BYTE byFlareVal)
	//{
	//	equipSpec.byFlareVal += byFlareVal;
	//	equipSpec.byFlareVal = (equipSpec.byFlareVal > 100) ? 100 : equipSpec.byFlareVal;
	//	equipSpec.byFlareVal = (equipSpec.byFlareVal < 0 ) ? 0 : equipSpec.byFlareVal;
	//}

	//VOID ChangePotVal(INT nValue)
	//{
	//	INT nOrgPotVal = equipSpec.nPotVal;
	//	equipSpec.nPotVal += nValue;

	//	if(equipSpec.nPotVal < 0)		equipSpec.nPotVal = 0;

	//	if(equipSpec.nPotVal > pEquipProto->nMaxPotVal)
	//		equipSpec.nPotVal = pEquipProto->nMaxPotVal;

	//	if(nValue < 0)
	//		equipSpec.nPotValUsed += (nOrgPotVal - equipSpec.nPotVal);
	//}
	
	// 当前耐久
	int GetEquipNewness()
	{
		if (pEquipProto->eEquipPos == EEP_RightHand)
		{
			return pEquipProto->n16Newness - nUseTimes / ABRASION2USETIMES;
		}
		else
		{
			return pEquipProto->n16Newness - nUseTimes / ARMORABRASION2USETIMES;
		}
	}
	
	VOID ChangeNewness(INT16 nValue)
	{
		if (pEquipProto->eEquipPos == EEP_RightHand)
		{
			nUseTimes -= (nValue * ABRASION2USETIMES);

			if (nUseTimes > pEquipProto->n16Newness * ABRASION2USETIMES)
			{
				nUseTimes = pEquipProto->n16Newness * ABRASION2USETIMES;
			}
		}
		else
		{
			nUseTimes -= (nValue * ARMORABRASION2USETIMES);

			if (nUseTimes > pEquipProto->n16Newness * ARMORABRASION2USETIMES)
			{
				nUseTimes = pEquipProto->n16Newness * ARMORABRASION2USETIMES;
			}

		}

		if (nUseTimes < 0)
		{
			nUseTimes = 0;
		}
		
	}
	VOID IncAttackTimes()
	{		
		++nUseTimes;

		if(eStatus != EUDBS_Update)
		{
			SetUpdate(EUDBS_Update);
		}
	}

	VOID DecAttackTimes(INT nTimes)
	{
		nUseTimes = min(MEquipMaxUseTimes(pEquipProto), nUseTimes);
		nUseTimes = max(0, nUseTimes - nTimes);

		if(eStatus != EUDBS_Update)
		{
			SetUpdate(EUDBS_Update);
		}
	}

	BOOL IsNewessChange(INT &nCurAttackTimes)
	{

		nCurAttackTimes = MEquipMaxUseTimes(pEquipProto);
		if(nUseTimes > nCurAttackTimes)
		{
			nUseTimes = nCurAttackTimes;
			return FALSE;
		}

		nCurAttackTimes = nUseTimes;
		if(nUseTimes % ABRASION2USETIMES == 0)
		{
			return TRUE;
		}

		return FALSE;
	}
	
	BOOL IsArmorNewessChange(INT &nCurAttackTimes)
	{
		nCurAttackTimes = MArmorMaxUseTimes(pEquipProto);
		if(nUseTimes > nCurAttackTimes)
		{
			nUseTimes = nCurAttackTimes;
			return FALSE;
		}

		nCurAttackTimes = nUseTimes;
		if(nUseTimes % ARMORABRASION2USETIMES == 0)
		{
			return TRUE;
		}

		return FALSE;
	}

	VOID GetTriggerIDBuffID(OUT DWORD &dwTriggerID, OUT DWORD &dwBuffID, IN INT nIndex)
	{
		dwTriggerID = dwBuffID = INVALID_VALUE;

		if(!VALID_POINT(pEquipProto))
		{
			assert(0);
			return;
		}

		switch(nIndex)
		{
		case 0:
			dwTriggerID = pEquipProto->dwTriggerID0;
			dwBuffID	= pEquipProto->dwBuffID0;
			break;
		case 1:
			dwTriggerID = pEquipProto->dwTriggerID1;
			dwBuffID	= pEquipProto->dwBuffID1;
			break;
		case 2:
			dwTriggerID = pEquipProto->dwTriggerID2;
			dwBuffID	= pEquipProto->dwBuffID2;
			break;
		default:
			break;
		}
	}
	

	// 掉了多少耐久
	INT16 GetNewess() const
	{
		if (pEquipProto->eEquipPos == EEP_RightHand)
		{
			return nUseTimes / ABRASION2USETIMES;
		}
		else
		{
			return nUseTimes / ARMORABRASION2USETIMES;
		}
		
	}
	
	INT16 GetMaxNewess() const
	{
		return pEquipProto->n16Newness;
	}

	//INT16 GetArmorNewess()
	//{
	//	return nUseTimes / ARMORABRASION2USETIMES;
	//}
	
	//得到售价
	INT64	GetPrice() const 
	{
		INT64 n64Price = pProtoType->nBasePrice * n16Num;
		FLOAT fFactor = 1.0f;
		MCalPriceFactor(fFactor, equipSpec.byQuality);
		n64Price = (INT64)(n64Price * fFactor);
		if(n64Price < 0)
		{
			assert(0);
			n64Price = 0;
		}
		return n64Price;
	}

	//得到修理价格
	INT64	GetRepairPrice() 
	{
		/*FLOAT fp = BASE_REPIAR_PRICE * GetRepairPosParam() * 
			pEquipProto->byLevel * 
			GetRepairQualityParam();*/


		//（装备等级*装备等级*(装备品质)/2+装备等级*装备等级/1*（能力等级+镶嵌宝石数））^(MAX(1,0.7+装备等级*0.005）+1
		double fp = pEquipProto->byLevel * pEquipProto->byLevel * (equipSpec.byQuality + 1)/2 + 
			pEquipProto->byLevel * pEquipProto->byLevel * (equipSpec.byConsolidateLevel + equipSpec.getGemNum());
		
		fp = pow(fp, max(1, 0.7 + pEquipProto->byLevel*0.005)) + 1;

		fp = fp / 1600 * GetNewess();

		return (INT64)fp;
	}
	
	FLOAT GetRepairPosParam()
	{
		FLOAT fParam = 0.0f;
		switch (pEquipProto->eEquipPos)
		{
		case EEP_RightHand: fParam = 1.5f; break;
		case EEP_Head: fParam = 1.0f; break;
		case EEP_Body: fParam = 1.3f; break;
		case EEP_Wrist1: fParam = 0.8f; break;
		case EEP_Wrist2: fParam = 0.8f; break;
		case EEP_Waist: fParam = 0.7f; break;
		case EEP_Feet: fParam = 1.0f; break;
		case EEP_Body1: fParam = 1.0f; break;
		case EEP_Neck: fParam = 0.8f; break;
		}

		return fParam;
	}

	FLOAT GetRepairQualityParam()
	{
		FLOAT fParam = 0.0f;
		switch(equipSpec.byQuality)
		{
		case EIQ_Quality0: fParam = 1.0f; break;
		case EIQ_Quality1: fParam = 1.1f; break;
		case EIQ_Quality2: fParam = 1.2f; break;
		case EIQ_Quality3: fParam = 1.3f; break;
		case EIQ_Quality4: fParam = 1.5f; break;
		}

		return fParam;
	}

	VOID ZeroEuqipUseTimes()
	{
		nUseTimes = 0;
		if(eStatus != EUDBS_Update)
		{
			SetUpdate(EUDBS_Update);
		}
	}

	//BOOL HasSkill(DWORD dwSkillID)
	//{
	//	for (int i = 0; i < MAX_EQUIP_SKILL_NUM; i++)
	//	{
	//		if ( dwSkillID == (equipSpec.dwSkillList[i] / 100))
	//			return TRUE;
	//	}
	//	return FALSE;
	//}

	//INT GetSkillLevel(DWORD dwSkillID)
	//{
	//	for (int i = 0; i < MAX_EQUIP_SKILL_NUM; i++)
	//	{
	//		if ( dwSkillID == (equipSpec.dwSkillList[i] / 100))
	//			return equipSpec.dwSkillList[i] % 100;
	//	}

	//	return INVALID_VALUE;
	//}

	//BOOL AddSkill(DWORD dwSkillTypeID)
	//{
	//	if (HasSkill(dwSkillTypeID/100))
	//		return FALSE;

	//	for (int i = 0; i < MAX_EQUIP_SKILL_NUM; i++)
	//	{
	//		if ( equipSpec.dwSkillList[i] == 0)
	//		{
	//			equipSpec.dwSkillList[i] = dwSkillTypeID;
	//			return TRUE;
	//		}
	//	}
	//	return FALSE;
	//}

	//BOOL LevelUpSkill(DWORD dwSkillID)
	//{
	//	for (int i = 0; i < MAX_EQUIP_SKILL_NUM; i++)
	//	{
	//		if ( dwSkillID == (equipSpec.dwSkillList[i] / 100))
	//		{
	//			equipSpec.dwSkillList[i]++;
	//			return TRUE;
	//		}
	//	}
	//	return TRUE;
	//}

	//VOID ClearSkill()
	//{
	//	for (int i = 0; i < MAX_EQUIP_SKILL_NUM; i++)
	//	{
	//		equipSpec.dwSkillList[i] = 0;
	//	}
	//}
	BYTE GetQuality() const { return equipSpec.byQuality; }

	INT GetRating() const;

	//计算强化等级影响
	INT CalConsolidate(INT16 nBaseValue, BYTE byConLevel, float fParam) const
	{
		if (nBaseValue == 0)
			return 0;

		float result = nBaseValue * pow(fParam, byConLevel);

		/*for (BYTE i = 0; i < byConLevel; ++i)
		{
			result = result + (result * fParam);
		}*/

		//result += byConLevel;

		return (int)result;
	}

	//INT GetMinDmg() const 
	//{
	//	//武器修炼=初始攻击*武器等级/5+武器等级*武器等级/24+4
	//	if (equipSpec.n16MinDmg == 0)
	//		return 0;
	//	
	//	INT	nMinDmg = equipSpec.n16MinDmg;
	//	if (pEquipProto->eEquipPos == EEP_RightHand)
	//	{
	//		nMinDmg =static_cast<INT>(equipSpec.n16MinDmg * equipSpec.nLevel/5.0f + equipSpec.nLevel * equipSpec.nLevel / 24.0f +4.0f) ;
	//	}

	//	/*if (equipSpec.nLevel <=1)
	//	{
	//		nMinDmg = equipSpec.n16MinDmg;
	//	}*/

	//	nMinDmg = CalConsolidate(nMinDmg, equipSpec.byConsolidateLevel, CONSOLIDATE_PARAM) + equipSpec.byConsolidateLevel;
	//	return nMinDmg;
	//}

	//INT GetMaxDmg() const 
	//{
	//	if (equipSpec.n16MaxDmg == 0)
	//		return 0;
	//	
	//	INT nMaxDmg = equipSpec.n16MaxDmg;
	//	if (pEquipProto->eEquipPos == EEP_RightHand)
	//	{
	//		nMaxDmg = static_cast<INT>(equipSpec.n16MaxDmg * equipSpec.nLevel/5.0f + equipSpec.nLevel * equipSpec.nLevel / 24.0f +4.0f);
	//	}
	//	
	//	/*if (equipSpec.nLevel <=1)
	//	{
	//		nMaxDmg = equipSpec.n16MaxDmg;
	//	}*/

	//	nMaxDmg = CalConsolidate(nMaxDmg, equipSpec.byConsolidateLevel, CONSOLIDATE_PARAM) + equipSpec.byConsolidateLevel;
	//	return nMaxDmg;
	//}

	//INT GetArmor() const 
	//{
	//	//  护甲=护甲*(1.15^强化等级)+强化等级*5
	//	if (equipSpec.n16Armor == 0)
	//		return 0;

	//	INT nArmor = CalConsolidate(equipSpec.n16Armor, equipSpec.byConsolidateLevel, CONSOLIDATE_PARAM)+equipSpec.byConsolidateLevel*5;
	//	return nArmor;
	//}
};

// 销毁物品&装备(避免在tagItem中使用虚析构函数)
static VOID Destroy(tagItem *&pItem)
{
	if(!VALID_POINT(pItem))
	{
		return;
	}
	
	if(MIsEquipment(pItem->dw_data_id))
	{
		delete ((tagEquip*)pItem);
	}
	else
	{
		delete pItem;
	}

	pItem = NULL;
}

// 销毁物品&装备(避免在tagItem中使用虚析构函数)
static VOID Destroy(tagEquip *&pEquip)
{
	if(!VALID_POINT(pEquip))
	{
		return;
	}

	SAFE_DELETE(pEquip);
}

//-----------------------------------------------------------------------------
// 常量定义 -- 和结构相关
//-----------------------------------------------------------------------------
const INT SIZE_ITEM						= sizeof(tagItem);
const INT SIZE_EQUIP					= sizeof(tagEquip);
const INT SIZE_EQUIPSPEC				= sizeof(tagEquipSpec);

struct tagEquipLevelPctProto
{
	INT16				n16Index;			//等级编号
	FLOAT				fLevelPct;			//属性加成系数 随机属性
	FLOAT				fLevelPct2;			//固定属性系数
	INT					nDerateMin;			//随机抗性最小值
	INT					nDerateMax;			//随机抗性最大值	
	FLOAT				fPosPct[EEP_MaxEquip];//装备部位系数
	INT					nMaxAttValue;		//属性最大值

	tagEquipLevelPctProto(){ZeroMemory(this, sizeof(*this));}
};

//-----------------------------------------------------------------------------
// 装备显示信息
//-----------------------------------------------------------------------------
struct tagEquipViewInfo
{
	DWORD				dw_data_id;
	INT32				nLevel;												//gx modify 含义改为战斗力
	BYTE				byConsolidateLevel;									// 强化等级
	BYTE				byConsolidateLevelStar;								// 强化星级 gx modify 含义改为品质
	BYTE				byBind;												// 绑定状态
	BYTE				byHoldNum;											// 镶嵌孔数
	INT32				nUseTimes;											// 使用次数
	tagRoleAttEffect	EquipAttitionalAtt[MAX_ADDITIONAL_EFFECT];			// 附加属性
	DWORD				dwHoleGemID[MAX_EQUIPHOLE_NUM];
	INT16				n16MinDmg;											// 近战武器最小伤害
	INT16				n16MaxDmg;											// 近战武器最大伤害
	INT16				n16Armor;											// 防具护甲 
};

struct tagEquipViewInfoEx : public tagEquipViewInfo
{
	INT16		n_num;
};


// 物品系统相关函数
class ItemHelper
{
public:
	// 获取强化基础几率
	static INT GetUpstarsPro(BYTE byLevel)
	{
		INT fpro = 0;
		switch (byLevel)
		{
		case 0:
		case 1:
		case 2:
			fpro = 10000;
			break;
		case 3:
			fpro = 8000;
			break;
		case 4:
			fpro = 6000;
			break;
		case 5:
			fpro = 4000;
			break;
		case 6:
			fpro = 2000;
			break;
		case 7:
		case 8:
			fpro = 1000;
			break;
		case 9:
			fpro = 100;
			break;
		}

		return fpro;
	}

	static INT GetUpstarsAddPro(INT number, BYTE byConsolidateLevel)
	{
		
		if (byConsolidateLevel < 0 || byConsolidateLevel >= MAX_CONSOLIDATE_LEVEL)
			return 0;

		INT nParam[] = {2500, 2000, 1500, 1500, 1100, 700, 300, 800, 600, 400, 200, 400, 300, 200, 100};
		
		return nParam[byConsolidateLevel] * number;
	}

	//取得打孔石id
	static DWORD GetChiselTypeID(INT nCurHoldNum)
	{
		DWORD dwTypeID = 0;
		switch(nCurHoldNum)
		{
		case 0: dwTypeID = 4121001; break;
		case 1: dwTypeID = 4121002; break;
		case 2: dwTypeID = 4121003; break;
		case 3: dwTypeID = 4121004; break;
		case 4: dwTypeID = 4121005; break;
		case 5: dwTypeID = 4121006; break;
		default: break;
		}
		return dwTypeID;
	}

	//取得强化石id
	static DWORD GetQiangHuaStoneTypeID(INT nCurLevel, bool bAttack )
	{
		if(bAttack)
		{
			if	   (nCurLevel <= 10)	return 4111101;
			else if(nCurLevel <= 20)	return 4111102;
			else if(nCurLevel <= 30)	return 4111103;
			else if(nCurLevel <= 40)	return 4111104;
			else if(nCurLevel <= 50)	return 4111105;
			else if(nCurLevel <= 60)	return 4111106;
			else if(nCurLevel <= 70)	return 4111107;
			else if(nCurLevel <= 80)	return 4111108;
			else if(nCurLevel <= 90)	return 4111109;
			else if(nCurLevel <= 100)	return 4111110;
			else return 0;
		}
		else
		{
			if	   (nCurLevel <= 10)	return 4111201;
			else if(nCurLevel <= 20)	return 4111202;
			else if(nCurLevel <= 30)	return 4111203;
			else if(nCurLevel <= 40)	return 4111204;
			else if(nCurLevel <= 50)	return 4111205;
			else if(nCurLevel <= 60)	return 4111206;
			else if(nCurLevel <= 70)	return 4111207;
			else if(nCurLevel <= 80)	return 4111208;
			else if(nCurLevel <= 90)	return 4111209;
			else if(nCurLevel <= 100)	return 4111210;
			else return 0;
		}
	}

	//取得神石ID
	static DWORD GetShenStoneTypeID(INT nCurLevel)
	{
		if	   (nCurLevel <= 30)	return 4112101;
		else if(nCurLevel <= 50)	return 4112102;
		else if(nCurLevel <= 70)	return 4112103;
		else return 0;
	}

	//取得固星石ID
	static DWORD GetGuxingShiTypeID(INT nCurLevel)
	{
		if	   (nCurLevel < 3)		return NULL;
		else if(nCurLevel == 3)		return 4112201;
		else if(nCurLevel == 4)		return 4112202;
		else if(nCurLevel == 5)		return 4112202;
		else if(nCurLevel == 6)		return 4112203;
		else if(nCurLevel == 7)		return 4112204;
		else if(nCurLevel == 8)		return 4112204;
		else if(nCurLevel == 9)		return 4112205;
		else if(nCurLevel == 10)	return NULL;
		else return 0;
	}

	//取得npc打造概率提升道具id
	static DWORD GetProduceQualityID(INT nCurLevel, BYTE byQuality)
	{
		if (nCurLevel <= 30)		
		{
			switch(byQuality)
			{
			case 2: return 3420201;
			case 3: return 3420206;
			}
		}
		else if(nCurLevel <= 40)	
		{
			switch(byQuality)
			{
			case 2: return 3420202;
			case 3: return 3420207;
			}
		}
		else if(nCurLevel <= 50)
		{
			switch(byQuality)
			{
			case 2: return 3420203;
			case 3: return 3420208;
			}
		}
		else if(nCurLevel <= 60)
		{
			switch(byQuality)
			{
			case 2: return 3420204;
			case 3: return 3420209;
			}
		}
		else if(nCurLevel <= 70)
		{
			switch(byQuality)
			{
			case 2: return 3420205;
			case 3: return 3420210;
			}
		}
		return 0;
	}
	//取得npc打造概率提升道具提升属性
	static INT GetProduceQualityAttValue(INT nCurLevel, BYTE byQuality)
	{
		if (nCurLevel <= 30)		
		{
			switch(byQuality)
			{
			case 2: return 1;
			case 3: return 2;
			}
		}
		else if(nCurLevel <= 40)	
		{
			switch(byQuality)
			{
			case 2: return 2;
			case 3: return 3;
			}
		}
		else if(nCurLevel <= 50)
		{
			switch(byQuality)
			{
			case 2: return 3;
			case 3: return 4;
			}
		}
		else if(nCurLevel <= 60)
		{
			switch(byQuality)
			{
			case 2: return 4;
			case 3: return 5;
			}
		}
		else if(nCurLevel <= 70)
		{
			switch(byQuality)
			{
			case 2: return 5;
			case 3: return 6;
			}
		}
		return 0;
	}
	//取得npc打造概率提升道具提升属性最大值
	static INT GetProduceQualityAttValueMax(INT nCurLevel)
	{
		if (nCurLevel < 20)
			return 1;
		else if (nCurLevel < 30)
			return 2;
		else if (nCurLevel < 40)
			return 3;
		else if (nCurLevel < 50)
			return 4;
		else if (nCurLevel < 60)
			return 7;
		else if (nCurLevel < 70)
			return 9;

		return 11;
	}

	// 取得坐骑强化灵魂石ID
	static DWORD GetRideUpgradeSoulStoneTypeID( INT nCurLevel )
	{
		switch(nCurLevel)
		{
		case 0:
		case 1:
		case 2:
			return 4211001;
			break;
		case 3:
		case 4:
		case 5:
			return 4211002;
			break;
		case 6:
		case 7:
		case 8:
			return 4211003;
			break;
		case 9: return 4211004; break;
		default: return 4211004; break;
		}
	}

	// 获得武器融合丹id
	static DWORD GetFusionDanTypeID( /*INT nCurLevel*/ )
	{
		return 4150001;
	}

	// 取得坐骑神石ID
	static DWORD GetRideUpgradeGodStoneTypeID()
	{
		return 4212001;
	}

	static BYTE GetQuality(const tagItem* pItem) 
	{
		if (MIsEquipment(pItem->dw_data_id))
		{
			return ((const tagEquip*)pItem)->GetQuality();
		}
		return pItem->GetQuality();
	}
	
	// 获取装备重置属性元宝需求
	static INT GetEquipReattYuanbao(INT nLevel)
	{
		if (nLevel>=45 && nLevel <= 50)
		{
			return 50;
		}
		if (nLevel>50 && nLevel <= 55)
		{
			return 250;
		}
		if (nLevel>55 && nLevel <= 60)
		{
			return 450;
		}
		if (nLevel>60 && nLevel <= 65)
		{
			return 650;
		}
		if (nLevel>65 && nLevel <= 70)
		{
			return 850;
		}
		return 0;
	}

	// 获取装备重置属性强化需求
	static INT GetEquipReattStar(INT nLevel)
	{
		if (nLevel>=45 && nLevel <= 50)
		{
			return 0;
		}
		if (nLevel>50 && nLevel <= 55)
		{
			return 4;
		}
		if (nLevel>55 && nLevel <= 60)
		{
			return 7;
		}
		if (nLevel>60 && nLevel <= 65)
		{
			return 7;
		}
		if (nLevel>65 && nLevel <= 70)
		{
			return 7;
		}
		return 0;
	}

	// 洗礼战功消耗
	static INT32 GetXiliExplios(BYTE byEquipLevel)
	{
		if (byEquipLevel >= 30 && byEquipLevel < 40)
		{
			return 50;
		}
		if (byEquipLevel >= 40 && byEquipLevel < 50)
		{
			return 200;
		}
		if (byEquipLevel >= 50 && byEquipLevel < 60)
		{
			return 800;
		}
		if (byEquipLevel >= 60 && byEquipLevel < 70)
		{
			return 1500;
		}
		if (byEquipLevel >= 70)
		{
			return 2000;
		}
		return 0;
	}

	static double getQianghuaQualityParam(BYTE byQuality)
	{
		return pow(2.0, byQuality*1.0);
	}

	static int getQianghuaParam(BYTE byStar)
	{
		if (byStar >= 0 && byStar <=2)
		{
			return 10;
		}
		if (byStar >= 3 && byStar <=5)
		{
			return 20;
		}
		if (byStar >= 6 && byStar <=8)
		{
			return 30;
		}
		if (byStar >= 9)
		{
			return 100;
		}

		return 0;
	}

	// 附魔各个属性增长值
	static int getShipinFumoAttAdd(ERoleAttribute era)
	{
		INT nParam = 1;
		if ((era >= ERA_Physique && era <= ERA_Agility) || era == ERA_ExDefense)
		{
			return 1 * nParam;
		}
		else if (era == ERA_ExAttack)
		{
			return 10 * nParam;
		}
		else
		{
			return 2 * nParam;
		}
	}

	// 附魔暴击各个品质增长值
	static VOID getShipinFumoAttCritAdd(BYTE byQuality, INT& nMin, INT& nMax)
	{
		switch(byQuality)
		{
		case 1:
			{
				nMin = 1;
				nMax = 2;
			}
			
			break;
		case 2:
			{
				nMin = 1;
				nMax = 3;
			}
			break;
		case 3:
			{
				nMin = 2;
				nMax = 4;
			}
			break;
		}
	}

	static INT32 getConsolidateAtt(INT32 nAttValue, BYTE byConsolidate)
	{
		if (byConsolidate<=0 || byConsolidate > MAX_CONSOLIDATE_LEVEL)
			return 0;

		INT nParam[] = {300, 600, 900, 1400, 1900, 2400, 2900, 3500, 4100, 4700, 5300, 5900, 6500, 7200, 8000};
	
		return max(byConsolidate, nAttValue * (nParam[byConsolidate - 1] / 10000.0));
	}
};

// 组队装备信息
struct tagEquipTeamInfo
{
	INT32 n32_ConsolidateNum;		// 装备总强化星数
	INT32 n32_InlayNum;				// 装备总镶嵌星数
	INT32 n32_Rating;				// 装备总评分
};
//
static INT GetMountSpellTimeDelta( BYTE bySolidateLevel )
{
	if(bySolidateLevel < 4) return 0;
	if(bySolidateLevel < 7) return -500;
	if(bySolidateLevel < 10) return -1000;
	return -1500;
}
//-----------------------------------------------------------------------------
#pragma pack(pop)
