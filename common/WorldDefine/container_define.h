//--------------------------------------------------------------------------------------------
//★Name				:   container_define.h
//★Compiler			:	Microsoft Visual C++ 9.0
//★Version				:	1.00
//★Create Date			:	2008-8-4
//★LastModified		:	
//★Brief				:	人物装备栏、行囊、仓库等相关定义
//--------------------------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
// 常量定义
//-----------------------------------------------------------------------------
const INT32 MAX_BAG_NUM				= 1;							// 背包最大页数
const INT32 SPACE_ONE_BAG			= 80;							// 单个背包格数
const INT32 SPACE_ALL_BAG			= SPACE_ONE_BAG * MAX_BAG_NUM;	// 最大背包格数

const INT32 SPACE_QUEST_BAG			= 110;							// 任务物品栏最大格数	
const INT32 SPACE_BAIBAO_BAG		= 20;							// 百宝袋最大格数

const INT32 MAX_BAIBAO_LOG_NUM		= 40;							// 百宝袋最大Log数

const INT32 MAX_WARE_NUM			= 1;							// 仓库最大页数
const INT32 SPACE_ONE_WARE			= 80;							// 单个仓库格数
const INT32 SPACE_ALL_WARE			= SPACE_ONE_WARE * MAX_WARE_NUM;// 最大仓库格数

const INT32 MIN_PASSWORD_NUM		= 6;							// 密码最小长度
const INT32 MAX_PASSWORD_NUM		= 14;							// 密码最大长度

const INT32 SPACE_WARE_PER_EXTEND	= 6;							// 角色仓库一次扩充格子数
const INT32 SPACE_BAG_PER_EXTEND	= 5;							// 背包一次扩充格子数

const INT32 MAX_WARE_EX_TIMES_SILVER= 4;							// 使用游戏币最多能扩充的仓库次数
const INT32 MAX_BAG_EX_TIMES_SILVER	= 4;							// 使用游戏币最多能扩充的背包次数

const INT32 MAX_GUILDWARE_NUM       =   5;                          // 帮派仓库最大页数
const INT32 SPACE_ONE_GUILDWARE     =   35;                         // 单个帮派仓库格数
const INT32 SPACE_ALL_GUILDWARE     =   SPACE_ONE_GUILDWARE * MAX_GUILDWARE_NUM;

const INT32 BAG_EXTERN_BEGIN_NUM	= 30;							// 背包扩充开始格子数	
//-----------------------------------------------------------------------------
// 枚举定义
//-----------------------------------------------------------------------------
// 容器类型
enum EItemConType
{
	EICT_Start		= 0,
	EICT_Null		= 0,

	EICT_Bag		= 1, // 背包
	EICT_Quest		= 2, // 任务物品栏
	EICT_Baibao		= 3, // 百宝袋
	EICT_RoleWare	= 4, // 角色仓库
	EICT_Equip		= 5, // 装备栏

	EICT_Shop		= 6, // 商店
	EICT_Ground		= 7, // 掉落

    EICT_PetEquip   = 8, // 宠物装备栏

	EICT_GuildWare	= 9, // 帮派仓库

	EICT_GDQuest	= 10, //悬赏任务类型

	EICT_MailItem	= 11,	// 邮件物品栏

	EICT_PaiMai		= 12,	// 拍卖

	EICT_End		= 13,
};

// 装备栏
//enum EEquipPos	// 装备部位
//{
//	EEP_Null			= -1,
//	EEP_Start			= -1, 
//
//	EEP_Equip_Start		= 0,
//	EEP_Head			= 0, // 头部
//	EEP_Face			= 1, // 面部
//	EEP_Body			= 2, // 上身
//	EEP_Legs			= 3, // 下身
//	EEP_Back			= 4, // 背部
//	EEP_Wrist			= 5, // 腕部
//	EEP_Feet			= 6, // 足部
//
//	EEP_Finger1			= 7, // 戒指
//	EEP_Finger2			= 8, // 戒指
//	EEP_Waist			= 9, // 腰饰
//	EEP_Neck			= 10, // 项链
//
//	EEP_RightHand		= 11, // 主手武器
//	EEP_LeftHand		= 12, // 副手武器
//	EEP_Equip_End		= 12,
//
//	EEP_MaxEquip		= 13, // 装备栏栏位数
//
//	EEP_FashionHead		= 13, // 头部
//	EEP_FashionFace		= 14, // 面部
//	EEP_FashionBody		= 15, // 上身
//	EEP_FashionLegs		= 16, // 下身
//	EEP_FashionBack		= 17, // 背部
//	EEP_FashionWrist	= 18, // 腕部
//	EEP_FashionFeet		= 19, // 足部
//
//	EEP_End				= 20,
//
//};
enum EEquipPos	// 装备部位
{
	EEP_Null			= -1,
	EEP_Start			= -1, 

	EEP_Equip_Start		= 0,

	EEP_RightHand		= 0,//主手	武器			可见
	EEP_Head			= 1, //头	头盔			不可见
	EEP_Body			= 2, //躯干	铠甲			可见
	EEP_Feet			= 3, //脚	鞋子			可见
	EEP_Body1			= 4, //背部 披风			可见
	EEP_Wrist1			= 5, //腕	护腕			不可见
	EEP_Wrist2			= 6, //腕	护腕			不可见
	EEP_Waist			= 7, //腰	腰带			不可见
	EEP_Dress_End		= 8, //防具总数


	EEP_Neck			= 8, //颈	项链			不可见
	EEP_Finger1			= 9,//戒指1	戒指1		不可见
	EEP_Finger2			= 10,//戒指2	戒指2		不可见
	EEP_Shipin1			= 11,//饰品1	徽章		 	不可见

	EEP_Fashion			= 12, // 时装

	EEP_Equip_End		= 12,
	EEP_MaxEquip		= 13, // 装备栏栏位数

	

	EEP_Ride			= 13, // 坐骑

	EEP_End				

};
const INT32 X_EQUIP_BAR_SIZE = EEP_End - EEP_Start - 1;
#define MIsInEquipPos(n16Pos)	(n16Pos > EEP_Start && n16Pos < EEP_End)

//攻击类装备 项链，戒指，披风
#define MIsAttackEquip(n16Pos) ( n16Pos == EEP_RightHand ||  n16Pos == EEP_Body1 || n16Pos == EEP_Neck || n16Pos == EEP_Finger1 || n16Pos == EEP_Finger2)
//防御类装备 头盔，铠甲，护腕，护腿，护手，内甲，腰带，鞋子
#define MIsDefEquip(n16Pos) (n16Pos == EEP_Head || n16Pos == EEP_Body || n16Pos == EEP_Waist || n16Pos == EEP_Feet)
//时装
#define MIsFashion(n16Pos) (n16Pos == EEP_Fashion)
// 武器装备部位
enum EWeaponPos
{
	EWP_NULL			= 0,	// 无
    EWP_DRing		    = 1,	// 双手轮(刺客)
    EWP_DHummer         = 2,	// 双手锤(猛将)
    EWP_Wand		    = 3,	// 长兵(少保)
    EWP_Bow		        = 4,	// 弓(游侠)
    EWP_Faqi		    = 5,	// 法器(药师)	
};

const INT32 X_WEAPONPOS_NUM = EWP_Faqi + 1;

// 百宝袋记录类型
enum EBaiBaoRecordType
{
	EBBRT_System,			// 系统划拨
	EBBRT_Mall,				// 商城赠品
	EBBRT_Friend,			// 好友赠送
	EBBRT_Myself,			// 自己领取
	EBBRT_GroupPurchase,	// 帮派团购
	EBBRT_VipNetBarGift,	// 金牌网吧礼品
};

//修理类型
enum ERepair
{
	ERE_None = -1, 
	ERE_Normal,		//普通
	ERE_Spe,		//全部修理
	ERE_Spe_Mall	//商城道具
};

//-----------------------------------------------------------------------------
// 结构
//-----------------------------------------------------------------------------
// 自动整理
struct tagItemOrder
{
	INT16	n16OldIndex;
	INT16	n16NewIndex;
};

// 百宝袋记录
struct tagBaiBaoRecord
{
	INT16	n16Size;		// 单条记录长度
	INT16	n16Type;		// EBaiBaoRecordType
	DWORD	dw_data_id;		// 物品的TypeID
	DWORD	dw_role_id;		// 操作玩家的ID，INVALID_VALUE为系统划拨
	DWORD	dw_time;			// 操作时间 tagDWORDTime
	TCHAR	szWords[1];		// 赠言
};

//-----------------------------------------------------------------------------
// 宏
//-----------------------------------------------------------------------------

// 仓库扩容次数=（当前仓库以开放栏位数-24）/6
#define MCalWareExTimes(n16CurWareSpace)	((n16CurWareSpace - 24) / 6)

// 若使用游戏币扩充，收费=（仓库扩容次数+1）^2×3000[单位游戏币]
#define MCalWareExSilver(nExTimes)	((nExTimes + 1) * (nExTimes + 1) * 3000)

// 若使用元宝扩充，则收费=（仓库扩容次数+1）×5[单位元宝]
#define MCalWareExYuanBao(nExTimes)	((nExTimes + 1) * 5)


// 行囊扩容次数=（当前行囊以开放栏位数-20）/5
#define MCalBagExTimes(n16CurBagSpace)	((n16CurBagSpace - 20) / 5)

// 若使用游戏币扩充，则收费=（行囊扩容次数+1）^2×8000[单位游戏币]
#define MCalBagExSilver(nExTimes)	((nExTimes + 1) * (nExTimes + 1) * 8000)

// 若使用元宝扩充，则收费=（行囊扩容次数+1）×10[单位元宝]
#define MCalBagExYuanBao(nExTimes)	((nExTimes + 1) * 10)

