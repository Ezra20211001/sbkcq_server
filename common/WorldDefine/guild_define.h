/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/


/**
*	@file		guild_define.h
*	@author		mmz
*	@date		2010/10/11	initial
*	@version	0.0.1.0
*/


#pragma once
#include "protocol_common_errorcode.h"
#include "RoleDefine.h"
#include "ItemDefine.h"
#include <bitset>

#pragma pack(push, 1)

//-----------------------------------------------------------------------------
// 宏
//-----------------------------------------------------------------------------

// 可占领城镇数量=（帮派等级+3）/4
#define MGuildMaxHoldCityNum(by_guild_level)		((by_guild_level + 3) / 4)

// 最大成员数
#define MGuildMaxMember(by_guild_level)			(55 + 15 * (by_guild_level - 1))//gx modify 2013.9.6

// 资金
#define MGuildMaxFund(by_guild_level)				(0)//??

// 资材
#define MGuildMaxMaterial(by_guild_level)			(0)//??

// 每日维护费用(维护费用=1000×(帮派等级^3)×（2-帮派安定度/10000）)
#define MGuildDailyCost(by_guild_level, nGuildPeace)	(1000.0f * by_guild_level * by_guild_level * by_guild_level * (2.0f - nGuildPeace / 10000.0f))

// 每日安定度消耗
#define MGuildPeaceCost(by_guild_level)			(by_guild_level * 10)

// 当前俸禄标准
#define MGuildMemSalary()						(0)//??

// 堂 -- 帮众
#define MGuildPosTangZhongNum(by_guild_level)		(4 + 2 * (by_guild_level - 1))

// 基层 -- 精英帮众
#define MGuildPosJingZhongNum(by_guild_level)		(5 + 2 * (by_guild_level - 1))

// 基层 -- 普通帮众 = 总人数上限 - 当前帮派成员总数

// 帮派仓库当前空间
#define MGuildWareCurSpace(by_guild_level)		((by_guild_level + 1) / 2 * 35)

// 每日帮务发布最大次数
#define MGuildAffairTimes(by_guild_level)			((by_guild_level + 2) / 3)

// 帮派等级升级上限
#define MGuildSkillLevel(byAcademyLevel)		(20 + (2 * byAcademyLevel))

// 帮派建筑最大等级
#define MGuildMaxGradeLevel(by_guild_level)		(by_guild_level)

// 帮会战宣战资金
#define GUILDWARMONERY 1000000
//-----------------------------------------------------------------------------
// 常量
//-----------------------------------------------------------------------------

// 客户端显示成员信息页一页显示的成员个数
const INT32 MAX_GUILDMEM_DISPLAY_PERPAGE	= 26;

// 帮派组织属性常量
const INT32 MAX_GUILD_LEVEL			=	12;										// 帮派最大等级	
const INT32 MAX_GUILD_HOLDCITY		=	MGuildMaxHoldCityNum(MAX_GUILD_LEVEL);	// 帮派最大辖属城市
const INT32 MAX_GUILD_WARE_SPACE	=	MGuildWareCurSpace(MAX_GUILD_LEVEL);	// 帮派仓库最大容量
const INT32 MAX_GUILD_NAME			=	20;										// 帮派名称最大字节数
const INT32 MAX_GUILD_TENET			=	400;									// 帮派宗旨最大字节数
const INT32 MAX_GUILD_SIGN_NUM		=   12;										// 帮派最大签名人数量
const INT32 LEAVE_GUILD_TIME_LIMIT	=   5*60/*24 * 3600*/;								// 离开帮会时间限制
const FLOAT MAX_SIGN_DISTANCE		=   20 * 50.0f;								// 最大签名距离
const INT32 MAX_GUILD_POS_NAME_LEN      =   12;									// 家族职位名称最大字节数
const INT32 MAX_GUILD_UPLEVEL_TIME	= 5*60/*60 * 60*/;									// 帮会升级时间
const INT32 MAX_ENEMY_NUM			= 10;										// 最大敌对帮会数量
const INT32 DECLARE_WAIT_TIME		= 30 * 60;									// 宣战等待时间
const INT32 WAR_PREPARE_TIME		= 5 * 60;									// 战斗准备时间
const INT32 WAR_TIME_LIMIT			= 2 * 60 * 60;									// 战斗进行时间
const INT32 MAX_UNLEAGUE_TIME		= 5*60/*24 * 3600*/;								// 解除联盟时间限制
const INT32 MAX_GUILD_RELIVE_NUM	= 3;										// 帮会复活点最大数量
const INT32 MAX_GUILD_DELATE_END_TIME = 24 * 3600;								// 弹劾结束时间限制
const INT32 MAX_GUILD_DELATE_TIME	  = 24 * 3600;								// 弹劾时间
const INT32 MAX_LOBBY_DIS			= 1200;										// 修炼距离
const INT32 LOST_TRIPOD_TIME		= 24*60*60;									// 不能再次占领鼎炉时间

const INT32 MAX_GUILD_FUND				=	99999999;		// 帮派资金
const INT32 MAX_GUILD_PROSPERITY		=   99999999;		// 帮派繁荣度
const INT32 MAX_GUILD_MATERIAL			=	999999;			// 帮派资材
const INT16 MAX_GUILD_PEACE				=	100;			// 帮派安定度
const INT32 MAX_GUILD_REP				=	999999999;		// 帮派威望
const INT32 MAX_GUILD_GROUP_PURCHASE	=	100000;			// 帮派团购指数
const INT32 MAX_MEMBER_DKP				=   999999999;		// 成员DKP


// 帮派个人属性常量
const INT32 MAX_GUILDMEM_TOTALCONTRIB	=	999999999;	// 累计帮派贡献
const INT32 MAX_GUILDMEM_CURCONTRIB		=	999999999;	// 当前帮派贡献
const INT32 MAX_GUILDMEM_EXP			=	999999999;	// 帮派阅历
const INT32 MAX_GUILDMEM_EXPLOIT		=	999999999;	// 帮派功勋


// 帮派职位人数上限
const INT32 MAX_GUILDPOS_BANGZHU		=	1;	// 帮主
const INT32 MAX_GUILDPOS_FUBANGZHU		=	1;	// 副帮主
const INT32 MAX_GUILDPOS_HONGHUFA		=	1;	// 红衣护法
const INT32 MAX_GUILDPOS_ZIHUFA			=	1;	// 紫衫护法
const INT32 MAX_GUILDPOS_TANGZHU		=	1;	// 堂主
const INT32 MAX_GUILDPOS_XIANGZHU		=	1;	// 香主


const INT MAX_UPGRADE_NEED_ITEM_TYPE	=	4;  // 帮派设施升级所需物品种类
const INT MIN_GUILD_UPGRADE_ROLE_LEVEL	=	20; // 帮派设施升级角色等级下限

const INT MAX_GUILD_UPGRADE_NUM			=	3;	// 每个帮会建筑最大数量

// 帮派技能最大等级
const INT MAX_GUILD_SKILL_LEVEL			=	40;

// 跑商相关常量
const INT MAX_COMMODITY_CAPACITY		=	10;		// 跑商任务容器容量
const INT MAX_COFC_GOODS_NUM			=	5;		// 商会出售商品最大数量
const INT MAX_COMMODITY_GOOD_NUM		=	255;	// 商货最大堆叠个数
const INT MAX_COMMERCE_RANK_INFO		=	10;		// 跑商排行榜列表长度
const INT MAX_COMMEND_PLAYER			=	3;		// 发放跑商嘉奖人数

const INT32 MAX_GUILD_SYMBOL_LEN		= 300;

// 帮会徽章相关常量
const INT MAX_SYMBOL_BG_TYPE            =   8;      // 底板样式数量
const INT MAX_SYMBOL_BG_COLOR           =   20;     // 底板颜色数量
const INT MAX_SYMBOL_SB_TYPE            =   8;      // 图案样式数量
const INT MAX_SYMBOL_SB_COLOR           =   20;     // 图案颜色数量
const INT MAX_SYMBOL_SB_FONT			=	4;		// 图案字体数量

const INT NPC_NAME_NUM					=   6;

const INT MAX_MATERIMAL_NUM				=	50;		// 每天最大材料捐献数量
// 帮会地图名称
const TCHAR szGuildMapName[20] = _T("m9");
const TCHAR szSBKHuangGong[20] = _T("d104");

const DWORD	LOBBY_USE_TIME = 10 * 3600;

// 种植数据个数
const INT MAX_PLANT_NUMBER				= 50;		

// 祷告者数量
const INT MAX_DAOGA_NUM					= 16;

// 沙巴克检查间隔
const INT SBKTICK						= 60 * TICK_PER_SECOND;
//-----------------------------------------------------------------------------
// 枚举
//-----------------------------------------------------------------------------

// 错误码
enum
{
	E_Guild_TangZhu_Full				= 1,	// 指定职位上成员已到上限
	E_Guild_XiangZhu_Full				= 2,	// 指定职位上成员已到上限
	E_Guild_TangMember_Full				= 3,	// 指定职位上成员已到上限
	E_Guild_Member_Full					= 4,	// 帮派成员已到上限
	E_Guild_Pos_Full					= 5,	// 指定职位上成员已到上限

	E_Guild_Power_NotEnough				= 10,	// 权限不够
	E_Guild_CanNot_Leave				= 11,	// 不可脱离帮派
	E_Guild_CanNot_Demiss				= 12,	// 不能够辞职
	E_Guild_RoleNotFind                 = 14,   // 未找到制定玩家      

	E_Guild_Join_AlreadyIn				= 20,	// 已加入帮派
	E_Guild_Join_LevelLimit				= 21,	// 等级不够
	E_Guild_Join_BeInvited				= 22,	// 已处于被邀请状态
	E_Guild_Join_NotBeInvited			= 23,	// 已未处于被邀请状态
	E_Guild_Join_BeRefused				= 24,	// 邀请被拒绝

	E_Guild_Create_LevelLimit			= 25,	// 等级不够
	E_Guild_Create_NameExist			= 26,	// 重名
	E_Guild_Create_Success				= 27,	// 创建成功
	E_Guild_Create_AlreadyIn			= 28,	// 已有帮派
	
	E_GuildSet_Tenet_Empty				= 30,	// 设置宗旨为空

	E_Guild_Appoint_SamePos				= 35,	// 任职前后职位相同
	E_Guild_Appoint_SexLimit			= 36,	// 性别要求不符

	E_Guild_NotExist					= 40,	// 指定帮派不存在
	E_Guild_MemberHasMore				= 41,	// 还有其他成员(成员个数>1)
	E_Guild_MemberNotIn					= 42,	// 没有找到指定成员
	E_Guild_Level_Limit					= 43,	// 帮派等级限制
	E_Guild_State_Limit					= 44,	// 帮派状态限制
	E_Guild_Fund_NotEnough				= 45,	// 帮派资金不足
	E_Guild_Material_NotEnough			= 46,	// 帮派资材不足
	E_Guild_HoldCity_Limit				= 47,	// 帮派占领城市限制

	E_GuildWare_NoChange				= 50,	// 帮派仓库无变化,不需要更新
	E_GuildWare_Power_NotEnough			= 51,	// 帮派仓库操作权限不够

	E_GuildUpgrade_Level_Limit			= 60,	// 设施达到等级上限
	E_GuildUpgrade_Item_NotEnough		= 61,	// 上缴的物品不符合升级需要
	E_GuildUpgrade_Role_Level           = 62,   // 角色等级不够，无法升级帮派

	E_GuildAffair_Times_Limit			= 70,	// 帮务发布次数限制

	E_GuildSkill_NotResearch			= 80,	// 当前没有技能研究
	E_GuildSkill_Wrong_Item				= 81,	// 上缴物品非法
	E_GuildSkill_Level_Limit			= 82,	// 技能达到等级上限
	E_GuildSkill_NotExist				= 83,	// 技能不存在

	E_GuildMember_Contribution_Limit	= 90,	// 成员贡献限制
	E_GuildMember_Level_Limit			= 91,	// 成员等级限制

	E_GuildCommerce_Status_Error		= 100,	// 跑商状态错误
	E_GuildCommerce_Tael_NotEnough		= 101,	// 商银不足
	E_GuildCommerce_Commend_Error		= 102,	// 嘉奖已经开启或关闭

	E_GuildCommodity_NotEnough_Space	= 103,	// 跑商容器空间不足
	E_GuildCommodity_NotEnough_Tael		= 104,	// 商银不足
	E_GuildCommodity_ItemMaxHold		= 105,	// 商货达到可拥有上限

	E_CofC_NotExist						= 110,	// 商会非法
	E_CofC_ItemNotFind					= 111,	// 没有找到指定商货
	E_CofC_ItemCannotSell				= 112,	// 指定商货不可出售
	E_CofC_ItemNotEnough				= 113,	// 商货个数不足
	E_CofC_HoldCity_Limit				= 114,	// 没有占领指定城市

	E_Guild_Already_Formal				= 115,	// 已经是正式家族
	E_Guild_Distance_NotCan				= 116,	// 签名距离不合法
	E_Guild_LeaveTime_Limit				= 117,	// 离开帮派时间不合法
	E_Guild_SignIn_BlackList			= 118,	// 帮主在签名者的黑名单中
	E_Guild_Sign_Level_NotEnough		= 119,	// 签名者等级不足
	E_Guild_Own_Signing					= 120,	// 自己正在签名中
	E_Guild_Other_Signing				= 121,	// 对方正在签名中
	E_Guild_SignNum_NotEnough			= 122,	// 签名人数不足
	E_Guild_Bag_Full					= 123,  // 背包已满
	E_Guild_Sign_Item_Not				= 124,  // 签名物品不存在
	E_Guild_Enemy_Limit					= 125,  // 仇敌超限
	E_Guild_NoIs_Enemy					= 126,  // 不是敌人
	E_Guild_WarState_Limit			    = 127,  // 帮会战状态限制
	E_Guild_Declare_Level_Limit			= 128,  // 宣战等级限制
	E_Guild_Declare_Time_Limit			= 129,	// 宣战时间限制
	E_Guild_NoExist						= 130,  // 帮会不存在
	E_Guild_Leader_Not_Line				= 131,	// 帮主不在线
	E_Guild_NotEnough_peace				= 132,	// 本帮或对方安定度不够
	E_Guild_Have_League					= 133,	// 对方免战
	E_Guild_League_Not_Exist			= 134,  // 免战
	E_Guild_No_League					= 135,  // 不是联盟帮会
	E_Guild_Prosperity_NotEnouth		= 136,	// 繁荣度不足
	E_Guild_SignRole_HaveExist			= 137,	// 签名者已经存在

	E_Guild_Is_Leader					= 138,	// 自己是帮主不能被弹劾
	E_Guild_State_Delate				= 139,  // 帮会正在弹劾中
	E_Guild_Delate_Time_Limit			= 140,	// 弹劾时间限制
	E_Guild_Delate_Item_NoExists		= 141,	// 弹劾物品不存在
	E_Guild_State_NoDelate				= 142,	// 帮会没在弹劾中
	E_Guild_Have_Ballot					= 143,	// 已经投过票
	E_Guild_Kick_DelateRole				= 144,	// 不能踢出弹劾发起人
	E_Guild_ChangePos_DelateRole		= 145,	// 不能改变弹劾发起人职位
	E_Guild_AcceptWar_Limit				= 146,	// 应战限制

	E_Guild_ChangeDKP_Limit				= 147,	// 修改DKP限制

	E_Guild_SignRole_Full				= 148,	// 签名人数已满
	E_Guild_AlreadyIs_Enemy				= 149,	// 已经是敌对帮会
	E_Guild_UpLevel						= 150,	// 升级中
	E_Guild_Enemy_UpLevel				= 151,	// 敌对帮会升级中
	E_Guild_Waring_NotCan_UpLevel		= 152,	// 战斗流程不能升级
	E_Guild_Enemy_Level_Limit			= 153,  // 敌对帮会等级限制
	E_Guild_TargetLeague_Time_Limit		= 154,	// 被邀请联盟帮会时限
	E_Guild_Grade_Dead					= 155,	// 帮会建筑未修复
	E_Guild_Enemy_Grade_Dead			= 156,	// 敌对帮会建筑未修复
	E_Guild_League_NoCan_Enemy			= 157,	// 同盟帮会不能设置敌对
	E_Guild_Enemy_NoCan_League			= 158,	// 敌对帮会不能同盟
	E_Guild_Grade_UpLevel				= 159,	// 帮会建筑升级中

	E_Guild_recruit_have_exist			= 160,	// 已经在帮会招募榜中
	E_Guild_recruit_nohave_exist		= 161,	// 不在帮会招募榜中

	E_Guild_Practice_Already_Start		= 162,	// 帮会修炼已经开启
	E_Guild_Practiec_Num_Limit			= 163,	// 帮会修炼次数限制

	E_Guild_War_Not_Relay				= 164,	// 帮会战未在装备阶段
	E_Guild_War_Not_Accept				= 165,	// 没权限参加
	E_Guild_War_Not_Leader				= 166,	// 不是帮主,不能修改
	
	E_Guild_War_num_max					= 167,  // 人数上限了

	E_Guild_war_Num_Cant				= 168,	// 不能改成这个数
	E_Guild_war_Cant_Again				= 169,	// 已经向该帮会宣战过了

	E_Guild_Role_Silver_Not_Enough		= 180,	// 金钱不足
	E_Guild_Role_Silver_Full			= 181,	// 资金上限
	E_Guild_BaoMin_Full					= 182,  // 最大参与人数不能大于已报名人数

	E_Guild_Material_Not_time			= 190,	// 当天回收上线
	E_Guild_Material_Not_Enough			= 191,	// 物品数量不足	
	E_Guild_Material_Not_Money			= 192,	// 金钱不足	
};	

// 状态
enum EGuildSpecState
{
	EGDSS_NULL				= 0x0000,
	EGDSS_Shortage			= 0x0001,			// 资金短缺
	EGDSS_Distress			= 0x0002,			// 贫困
	EGDSS_Chaos				= 0x0004,			// 混乱
	EGDSS_Warfare			= 0x0008,			// 征战
	EGDSS_Primacy			= 0x0010,			// 王者
	EGDSS_Refulgence		= 0x0020,			// 辉煌
	EGDSS_UpLevel			= 0x0040,			// 升级
	EGDSS_Delate			= 0x0080,			// 弹劾
	EGDSS_DelateEnd			= 0x0100,			// 弹劾结束

	EGDSS_End				= 0xffff
};

// 帮派战状态
enum EGuildWarState
{
	EGWS_NULL               = 0,		
	EGWS_Declare			= 1,			// 宣战
	EGWS_BeDeclare			= 2,			// 被宣战
	EGWS_Prepare			= 3,			// 准备
	EGWS_WAR_relay			= 4,			// 准备开战
	EGWS_WAR				= 5,			// 开战
};

// 职位
enum EGuildMemberPos
{
	EGMP_Null			= -1,
	EGMP_Start			= 0,

	EGMP_BangZhong		= 0,	//普通帮众，普通帮众的enum值必须是0	
	EGMP_BangZhu		= 1,	//族长  ,族长的enum值必须是1，否则client会越界
	EGMP_FuBangZhu		= 2,	//副族长 
	EGMP_OFFICER_1      = 3,    //官员
	EGMP_OFFICER_2      = 4,    
	EGMP_OFFICER_3      = 5,    
	EGMP_OFFICER_4      = 6,    
	EGMP_OFFICER_5      = 7,    
	EGMP_OFFICER_6      = 8,    
	EGMP_OFFICER_7      = 9,   

	EGMP_End			= EGMP_OFFICER_7,

	EGMP_Num
};

const INT32 X_GUILD_POS_NUM		= EGMP_End - EGMP_Start + 1;

// 堂
enum EGuildTangType
{
	EGTT_Null			= -1,
	EGTT_Start			= 0,

	EGTT_QingLong		= 0,	// 青龙堂
	EGTT_ZhuQue			= 1,	// 朱雀堂
	EGTT_BaiHu			= 2,	// 白虎堂
	EGTT_XuanWu			= 3,	// 玄武堂

	EGTT_End			= 3,
};

const INT32 X_GUILD_TANG_NUM	= EGTT_End - EGTT_Start + 1;

// 堂内职位
enum ETangMemberPos
{
	ETMP_Null			= -1,

	ETMP_TangZhu		= 0,	// 堂主
	ETMP_XiangZhu		= 1,	// 香主
	ETMP_BangZhong		= 2,	// 帮众
};

// DKP
enum EDKP
{
	EDKP_KillEnemy			= 0,			//杀死敌帮成员
	EDKP_CrossInst			= 1,			//通关帮会副本
	EDKP_KillBoss			= 2,			//杀死Boss
	EDKP_Beachhead			= 3,			//摧毁据点
	EDKP_GuildQuest			= 4,			//完成帮会任务
	EDKP_HelpQuest			= 5,			//完成扶持任务

	EDKP_END				= 5,
};


// 战绩类型
enum EWarHistoryTyep
{
	EWHT_Offensive_Win		=	0,		// 进攻方胜利
	EWHT_Offensive_Fail		=	1,		// 进攻方失败
	EWHT_Defent_Win			=	2,		// 防御胜利
	EWHT_Defent_Fail		=	3,		// 防御方失败
	EWHT_DUIFANG_JUJUE		=	4,		// 对方拒绝
	EWHT_JUJUE				=	5,		// 我方拒绝
};
//-----------------------------------------------------------------------------
// 枚举合法性及相互间转化方法
//-----------------------------------------------------------------------------

static BOOL IsGuildPosValid(EGuildMemberPos ePos)
{
	return (ePos >= EGMP_Start && ePos <= EGMP_End);
}

//enum EGuildMemberAtt
//{
//	EGMA_Start				= 0,
//
//	EGMA_TotalContrib		= 0,	//累计帮派贡献
//	EGMA_Contribution		= 1,	//当前帮派贡献
//	EGMA_Exploit			= 2,	//当前帮派功勋
//	EGMA_Salary				= 3,	//当前俸禄标准
//
//	EGMA_End				= 3,
//};
//
//const INT32 X_GUILD_MEMBER_ATT_NUM		= EGMA_End - EGMA_Start + 1;

//-----------------------------------------------------------------------------
// 结构
//-----------------------------------------------------------------------------
struct tagGuildBase
{
	DWORD			dwID;								//帮派ID -- 该值用帮派名称CRC32值
	DWORD			dwFounderNameID;					//帮派创始人名称ID
	DWORD			dwLeaderRoleID;						//帮派帮主角色ID
	DWORD			dwSpecState;						//帮派当前特殊状态
	BYTE			byLevel;							//帮派当前等级
	BYTE			byHoldCity[MAX_GUILD_HOLDCITY];		//帮派当前辖属城市编号，如果最大帮派等级改变，需要重新考虑内存对齐问题

	INT32			nApplyLevel;						//申请等级
	INT32			nFund;								//帮派当前资金
	INT32			nMaterial;							//帮派当前材料
	INT32			nReputation;						//帮派当前威望
	INT32			nGroupPurchase;						//帮派团购指数
	INT16			n16Peace;							//帮派当前安宁度
	INT16			n16MemberNum;						//帮派当前成员数量	
	INT16			n16Rank;							//帮派当前排名
	BYTE			byMinJoinLevel;						//最低加入等级
	BYTE			byAffairRemainTimes;				//帮派事务剩余发布次数
	BOOL			bCommendation;						//帮派跑商嘉奖状态
	INT32			nDailyCost;							//帮派每日维护费用
	INT32			nProsperity;						//帮派繁荣度

	BOOL			bFormal;							//是否正式家族
	BYTE			bySignatoryNum;						//签名数量
	DWORD			dwSignRoleID[MAX_GUILD_SIGN_NUM];	//帮派签名人
	tagDWORDTime	dwCreateTime;						//建立帮派时间

	tagDWORDTime	dwMianzhanTime;						//免战开始时间
	tagDWORDTime	dwJujueTime;						//拒绝帮战时间

	////tagDWORDTime	dwChangeSymbolTime;					// 帮会标志更新时间

	TCHAR           szPosName[X_GUILD_POS_NUM][MAX_GUILD_POS_NAME_LEN];   //家族职位名称
	DWORD           dwPosPower[X_GUILD_POS_NUM];                          //家族职位权限

	DWORD			dwEnemyID[MAX_ENEMY_NUM];							  // 敌对帮会

	DWORD			dwLeagueID;											  // 同盟帮会

	tagDWORDTime	dwUnLeagueBeginTime;								  // 解除同盟起始时间

	INT16			n16DKP[EDKP_END];									 // DKP

	BOOL			bSignUpAttact;											// 是否报名参加工会战

	DWORD			dwValue;											// 帮会标志值
	TCHAR			szText[1];												// 帮会文字

	INT32			n32ScriptData[64];									// 帮会脚本数据	

	INT				n_family_name[NPC_NAME_NUM];										// npc姓
	INT				n_name[NPC_NAME_NUM];												// npc名
	
	BOOL			b_hasOpenServerReceive;								// 是否领取开服会长奖励
	//BOOL			bDaogao[MAX_DAOGA_NUM];								//祷告者

	tagGuildBase()	{ ZeroMemory(this, sizeof(*this)); };
};

// 帮派成员
struct tagGuildMember
{
	DWORD			dw_role_id;						//帮派成员角色ID
	EGuildMemberPos	eGuildPos;						//角色帮派职位

	INT32			nTotalContribution;				//累计帮派贡献
	INT32			nContribution;					//当前帮派贡献
	INT32			nExploit;						//当前帮派功勋
	INT32			nSalary;						//当前俸禄标准

	BOOL			bUseGuildWare;					//使用帮派仓库权限

	BOOL			bBallot;						// 是否已经领取攻城奖励
	
	BOOL			bWar;							// 是否参加帮战

	INT32			nDKP;							// DKP

	tagDWORDTime	dwJoinTime;						// 入会时间
	
	INT32			nTotalFund;						// 资金贡献

	tagGuildMember() {}
	
	tagGuildMember(DWORD dw_role_id, EGuildMemberPos ePos, DWORD dwJoinTime = 0,
					INT32 nTotalContrib = 0, INT32 nContrib = 0, 
					INT32 nExploit = 0, INT32 nSalary = 0, BOOL bUseGuildWare = FALSE,
					BOOL bBallot = TRUE, BOOL bWar = FALSE, INT32 nDKP = 0, INT32 nTotalFund = 0)
	{
		assert(::IsGuildPosValid(ePos));

		this->dw_role_id				= dw_role_id;
		this->eGuildPos				= ePos;

		this->nTotalContribution	= nTotalContrib;
		this->nContribution			= nContrib;
		this->nExploit				= nExploit;
		this->nSalary				= nSalary;

		this->bUseGuildWare			= bUseGuildWare;

		this->bBallot				= bBallot;
		
		this->bWar					= bWar;

		this->nDKP					= nDKP;

		this->dwJoinTime			= dwJoinTime;
		this->nTotalFund			= nTotalFund;
	}

	tagGuildMember(const tagGuildMember& sGuildMember)
	{
		assert(::IsGuildPosValid(sGuildMember.eGuildPos));

		this->dw_role_id				= sGuildMember.dw_role_id;
		this->eGuildPos				= sGuildMember.eGuildPos;

		this->nTotalContribution	= sGuildMember.nTotalContribution;
		this->nContribution			= sGuildMember.nContribution;
		this->nExploit				= sGuildMember.nExploit;
		this->nSalary				= sGuildMember.nSalary;

		this->bUseGuildWare			= sGuildMember.bUseGuildWare;

		this->nDKP					= sGuildMember.nDKP;

		this->dwJoinTime			= sGuildMember.dwJoinTime;

		this->nTotalFund			= sGuildMember.nTotalFund;
	}
};

// 角色一般信息
struct tagRoleCommon
{
	INT16			n16RoleLevel;					//当前玩家等级
	BYTE			byRoleSex;						//当前玩家性别
	bool			bOnline;						//当前是否在线
	EClassType		eRoleClass;						//当前玩家职业
	DWORD			dwOfflineTime;					//当前离线时间
	INT32			nKnowledge;						//当前玩家帮派阅历
};


// 帮派成员信息
struct tagGuildMemInfo
{
	DWORD		dw_role_id;			// 成员名称
	INT8		n8GuildPos;			// 成员职位
	BYTE		byLevel;			// 成员等级
	BYTE		bySex;				// 成员性别
	BYTE		byClass;			// 成员职业
	INT32		nCurContrib;		// 成员当前帮派贡献
	INT32		nDKP;				// 成员DKP
	DWORD		dwTimeLastLogout;	// 成员最后下线时间
	bool		bOnline;			// 是否在线
	tagDWORDTime	dwJoinTime;		// 加入帮会时间
	DWORD		dwMapID;			// 地图ID
	bool		bInWar;				// 是否参加帮战
	INT32		n32_Rating;			// 装备总评分
	INT32		nTotalFund;			// 资金总贡献
};

// 帮派成员信息扩展
struct tagGuildMemInfoEx
{
	// 个性化头像：同名帖界面中的头像 -- 发名帖相关消息
	INT32		nTotalContrib;		// 累计贡献：角色总帮派贡献
	INT32		nExploit;			// 帮派功勋
	INT32		nKnowledge;			// 帮派阅历: 不在线角色为-1
};


struct tagGuildMemberClient
{
	BOOL				bGetInfo;		// 是否以获取扩展信息
	tagGuildMemInfoEx	sInfoEx;		// 扩展信息
	tagGuildMemInfo		sInfo;			// 普通信息

	tagGuildMemberClient()
	{
		ZeroMemory(this, sizeof(tagGuildMemberClient));
	}
	tagGuildMemberClient(const tagGuildMemInfo& sMemInfo)
	{
		memcpy(&sInfo, &sMemInfo, sizeof(tagGuildMemInfo));
		ZeroMemory(&sInfoEx, sizeof(tagGuildMemInfoEx));
		bGetInfo = FALSE;
	}
	VOID Modify(const tagGuildMemInfoEx& sMemInfoEx)
	{
		memcpy(&sInfoEx, &sMemInfoEx, sizeof(tagGuildMemInfoEx));
		bGetInfo = TRUE;
	}
	VOID Modify(const tagGuildMemInfo& sMemInfo, const tagGuildMemInfoEx& sMemInfoEx)
	{
		memcpy(&sInfo, &sMemInfo, sizeof(tagGuildMemInfo));
		memcpy(&sInfoEx, &sMemInfoEx, sizeof(tagGuildMemInfoEx));
		bGetInfo = TRUE;
	}
};

//-----------------------------------------------------------------------------
// 结构 -- 操作权限，构造函数初始化为0，默认生成NullObject(服务器端见guild_mgr.h)
//-----------------------------------------------------------------------------
// 帮派职能
struct tagGuildPower
{
	DWORD	bDismissGuild		: 1,		// 解散帮派
			bInviteJoin			: 1,		// 邀请成员加入
			bTurnoverLeader		: 1,		// 移交帮主
			bLeaveGuild			: 1,		// 离开帮派
			bDemissPostion		: 1,		// 辞去帮中职务
			bModifyTenet		: 1,		// 修改宗旨
			bModifySgin			: 1,		// 修改标志
			bWareRights		    : 1,		// 家族仓库操作权限
			bSetWareRights		: 1,		// 设置帮派仓库操作权限
			bUpgrade			: 1,		// 帮派设施升级
			bCommerce			: 1,		// 帮派跑商
			bSetCommend			: 1,		// 设置跑商嘉奖状态
			bAffair				: 1,		// 帮派事务发布
			bSetSkill			: 1,		// 设置帮派升级技能
			bAdvSkill			: 1,		// 帮派技能额外升级
			bModifyPosName		: 1,		// 修改家族职位名称
			bModifyPosPower		: 1,		// 修改家族职位权限
			bKickMember         : 1,        // 开革家族成员   
			bAppointMember      : 1,        // 任命家族成员    
			bRecvMessage		: 1,		// 接收帮派发言
			bSendMessage		: 1,		// 帮派发言
			bSendMail			: 1,		// 发送邮件
			bLevelUp			: 1,		// 帮会升级
		    bDeclareWar         : 1,        // 家族宣战
			bAcceptWar			: 1,        // 接受宣战
			bModifyDKP			: 1,        // 修改DKP
			bUnSay				: 1,		// 解除禁言
			bLeague				: 1,		// 开启鼎炉
			bUnLeague			: 1,		// 解除同盟
			bEnemy				: 1,		// 设定敌对帮派
			bWar				: 1;		// 参加帮会战

	tagGuildPower()
	{
		ZeroMemory(this, sizeof(*this));
	}
};

//-----------------------------------------------------------------------------
// 结构 -- 帮派配置
//-----------------------------------------------------------------------------
struct tagGuildCfg
{
	// 创建&加入最低等级
	INT32		nCreateRoleMinLevel;
	INT32		nJoinRoleMinLevel;
	
	// 签名玩家最小等级
	INT32		nSignRoleMinLevel;

	// 创建所需金钱
	INT32		nGoldCreateNeeded;

	// 帮会宣战所需的金钱
	INT32		nGoldGuildWarNeeded;

	// 创建后属性
	BYTE		byGuildLevelBegin;
	BYTE		byDummy;
	INT16		n16GuildPeaceBegin;
	INT32		nGuildRepBegin;
	INT32		nGuildFundBegin;
	INT32		nGuildProsperityBegin;
	INT32		nGuildMaterialBegin;
	INT32		nGuildGroupPurchaseBegin;
	INT			nGuildMinNpcNameNum;
	INT			nGuildMaxNpcNameNum;
};


// 帮派仓库更新类型
enum EGuildWareUpdate
{
	EGWU_Null			= -1,

	EGWU_Change			= 0,	// 物品变更
	EGWU_Delete			= 1,	// 物品消失

	EGWU_End
};

//-----------------------------------------------------------------------------
// 结构 -- 帮派仓库更新单位
//-----------------------------------------------------------------------------
struct tagGuildWareUpdate
{
	EGuildWareUpdate	eType;
	INT16				nIndex;
	BYTE				byData[1];

	tagGuildWareUpdate()
	{
		ZeroMemory(this, sizeof(*this));
		eType = EGWU_Null;
	}

	INT Size()
	{
		INT nSize = sizeof(EGuildWareUpdate) + sizeof(INT16);

		switch (eType)
		{
		case EGWU_Change:
			{
				// 上层保证byData值有效
				tagItem* pItem = (tagItem*)byData;
				if (MIsEquipment(pItem->dw_data_id))
				{
					nSize += sizeof(tagEquip);
				}
				else
				{
					nSize += sizeof(tagItem);
				}
			}
			break;

		case EGWU_Delete:
			break;

		default:
			nSize = 0;
			break;
		}

		return nSize;
	}
};

//-----------------------------------------------------------------------------
// 结构 -- 帮派仓库权限列表单位
//-----------------------------------------------------------------------------
struct tagGuildWarePri 
{
	DWORD	dw_role_id;
	BOOL	bCanUse;
};

//-----------------------------------------------------------------------------
// 帮派设施类型
//-----------------------------------------------------------------------------
enum EFacilitiesType
{
	EFT_Null		= -1,

	EFT_Lobby		= 0,		// 帮会雕像
	EFT_Bank		= 1,		// 帮会居民
	EFT_Leechdom	= 2,		// 帮会商店
	EFT_Factory		= 3,		// 帮会工房
	EFT_Maidan		= 4,		// 帮会练兵场
	EFT_Holiness	= 5,		// 帮会圣兽居	

	EFT_End
};

const INT MAX_GUILD_FACILITIES_TYPE = EFT_End - EFT_Null - 1;

//-----------------------------------------------------------------------------
// 结构 -- 帮派设施信息
//-----------------------------------------------------------------------------
struct tagGuildFacilitiesInfo
{
	EFacilitiesType	eType;
	INT16	nProgress;
	INT16	nFulfill;
	DWORD	dwItemID[MAX_UPGRADE_NEED_ITEM_TYPE];
	INT32	nNeedNum[MAX_UPGRADE_NEED_ITEM_TYPE];
	INT32	nNeedFund;
	INT32	nMaterial;
	BYTE	byLevel;
	BYTE    byMaxLevel;
	tagDWORDTime dwBeginUpTime;
	BOOL	bUpLevel;
	DWORD	nUpLevelLimit;
	INT32	nDecProsperity;
	INT32	nDayDecProsperity;
	DWORD   dwFacilitiesID[MAX_GUILD_UPGRADE_NUM];
	BOOL	bDead;
	tagDWORDTime	dwDeadBeginTime;
	DWORD	dwReliveTimeLimit;
	BYTE	byUseType;			// 0 可使用 1 使用中
	BYTE	byUseNum;
	tagDWORDTime	dwUseTime;
	BYTE	byStep;

	tagGuildFacilitiesInfo()
	{
		ZeroMemory(this, sizeof(*this));
	}

	BOOL IsLevelUp()
	{
		return bUpLevel ? TRUE : FALSE;/*nProgress >= nFulfill;*/
	}

	BOOL IsDestory()
	{
		return bDead ? TRUE : FALSE;
	}

	VOID ResetItemInfo()
	{
		for (int n=0; n<MAX_UPGRADE_NEED_ITEM_TYPE; n++)
		{
			dwItemID[n]	= INVALID_VALUE;
			nNeedNum[n] = 0;
		}
	}
};

//-----------------------------------------------------------------------------
// 结构 -- 帮派技能升级信息
//-----------------------------------------------------------------------------
struct tagGuildSkill 
{
	DWORD		dwSkillID;
	INT16		n16Progress;
	INT16		n16Fulfill;
	INT32		nResearchFund;
	INT32		nResearchMaterial;

	INT32		nLearnSilver;
	INT32		nLearnContribution;
	INT32		nLearnFund;
	INT32		nLearnMaterial;

	INT			nLevel;

	tagGuildSkill()
	{
		ZeroMemory(this, sizeof(*this));
	}
	tagGuildSkill(const tagGuildSkill &rhs)
	{
		memcpy(this, &rhs, sizeof(*this));
	}
};

//-----------------------------------------------------------------------------
// 结构 -- 帮派跑商初始信息
//-----------------------------------------------------------------------------
struct tagTaelInfo 
{
	INT32	nDeposit;		// 保证金
	INT32	nBeginningTael;	// 初始商银
	INT32	nPurposeTael;	// 指标商银
	INT32	nMaxTael;		// 商银上限
};

//-----------------------------------------------------------------------------
// 结构 -- 帮派跑商排行榜
//-----------------------------------------------------------------------------
struct tagCommerceRank 
{
	DWORD		dw_role_id;
	INT			nTimes;
	INT32		nTael;
};

//-----------------------------------------------------------------------------
// 结构 -- 帮派跑商商货
//-----------------------------------------------------------------------------
struct tagCommerceGoodInfo
{
	DWORD	dwGoodID;
	INT32	nCost;
	BYTE	byGoodNum;

	tagCommerceGoodInfo()
	{
		dwGoodID	= INVALID_VALUE;
		nCost		= 0;
		byGoodNum	= 0;
	}

	BOOL IsValid()
	{
		if (!VALID_VALUE(dwGoodID) || (dwGoodID == 0) || (byGoodNum == 0))
		{
			return FALSE;
		}

		return TRUE;
	}
};

//-----------------------------------------------------------------------------
// 结构 -- 签名单结构
//-----------------------------------------------------------------------------
struct tagGuildSignData
{
	DWORD			dwGuildID;							//帮派ID
	tagDWORDTime	dwCreateGuildTime;					//创建帮派时间
	DWORD			dwSignRoleID[MAX_GUILD_SIGN_NUM];	//帮派签名人
};

//-----------------------------------------------------------------------------
// 结构 -- 敌对数据
//-----------------------------------------------------------------------------
struct tagGuildEnemyData
{
	DWORD				dwGuildID;				// 敌对帮会ID
	EGuildWarState		eGuildWarState;			// 敌对帮会状态
};

//-----------------------------------------------------------------------------
// 结构 -- 弹劾数据
//-----------------------------------------------------------------------------
struct tagGuildDelateBase
{
	DWORD			dwGuildID;							// 帮会ID
	DWORD			dwInitiateRoleID;					// 发起人ID
	DWORD			dwBeDelateRoleID;					// 被弹劾人ID
	INT				nAgreeNum;							// 同意人数
	INT				nOpposeNum;							// 反对人数
	tagDWORDTime	dwDelateBeginTime;					// 弹劾起始时间
	tagDWORDTime	dwDelateEneTime;					// 弹劾结束时间
	BOOL			bSucceed;							// 是否成功

	tagGuildDelateBase() { ZeroMemory(this, sizeof(*this)); }
};

struct tagGuildDelate : public tagGuildDelateBase
{
	tstring  content;

	tagGuildDelate(): tagGuildDelateBase()	{}

	VOID Init(DWORD dwGuildID)
	{
		this->dwGuildID = dwGuildID;
		dwInitiateRoleID = INVALID_VALUE;
		dwBeDelateRoleID = INVALID_VALUE;
	}

};

//-----------------------------------------------------------------------------
// 结构 -- 徽章属性
//-----------------------------------------------------------------------------
struct tagGuildSymbol
{
    union {        
        struct {            
            DWORD byBGType   : 5;  // 底板样式
            DWORD byBGColor1 : 5;  // 底板颜色1
            DWORD byBGColor2 : 5;  // 底板颜色2
            DWORD bySBType   : 5;  // 图案样式
            DWORD bySBColor  : 5;  // 图案颜色
			DWORD byFont	 : 5;  // 文字字体
            DWORD byCustom   : 1;  // 是否自定义图案
            DWORD byReserved : 1;  // 
        }     Cfg;
        DWORD dwValue;
    };
	TCHAR szWord[2];

    tagGuildSymbol(DWORD val = 0) : dwValue(val) {  }
    bool IsEqual(const tagGuildSymbol& other) const { return this->dwValue == other.dwValue && this->szWord[1] == other.szWord[1]; }
    bool operator==(const tagGuildSymbol& other) const { return IsEqual( other );  }
    bool operator!=(const tagGuildSymbol& other) const { return !IsEqual( other ); }
    bool operator<(const tagGuildSymbol& other) const { return IsLess( other ); }
	bool IsLess(const tagGuildSymbol& other) const 
	{ 
		if(this->dwValue != other.dwValue)
			return this->dwValue < other.dwValue;
		else
		{
			if(_tcscmp(this->szWord,other.szWord)<0)
				return true;
			else
				return false;
		}
	}
};

// 帮会招募榜信息
struct tag_guild_recrguit_info
{
	DWORD		dw_role_id;
	INT			n_level;
	EClassType	e_class;
	BOOL		b_line;
};

// 帮会战战绩数据
struct tagGuildWarHistory
{
	DWORD		dw_guild_id;		
	DWORD		dw_enemy_leader_id;	// 对方帮主id
	DWORD		dw_enemy_id;
	tagDWORDTime		dw_time;
	EWarHistoryTyep		e_war_history_type;
};

// 材料回收
struct tagGuildMaterialReceive
{
	DWORD		dw_item_id;			// 物品id
	INT32		n_contribution;		// 获得帮贡
	INT32		n_material;			// 获得材料点
	BYTE		byLevel;			// 等级
	BYTE		byType;				// 类型
};

// 种植数据
struct tagPlantData
{
	DWORD		dw_npc_id;			// 植物id
	INT			n_num;				// 剩余数量
	DWORD		dw_master_id;		// 所有者id
	DWORD		dw_plant_time;		// 种植的时间
};

// 帮会简单数据
struct tagGuildWarInfo
{
	DWORD			dwGuildID;
	BYTE			byLevel;							//帮派当前等级	
	INT32			nMemberNumber;						//帮会当前人数
	INT32			nApplyLevel;						//申请等级
	//INT32			nFund;								//帮派当前资金
	//INT32			nProsperity;						//帮派繁荣度
	//DWORD			dwDaogaoNum;						//祷告者数量
	INT				nRank;								//排名
	BOOL			bAttack;							//是否报名攻城战
	TCHAR			szGuildName[X_SHORT_NAME];			//帮会名
	TCHAR			szLeaderName[X_SHORT_NAME];			//帮主名
};

// 沙巴克数据
struct tagGuildSBKData
{
	DWORD	dwData[6];		// 数据
	//0 DWORD	dwGuildID;		// 沙巴克行会id
	//1 DWORD	dwLeaderID;		// 会长id
	//2 DWORD	dwFuLeaderID;	// 副会长id
	//3 DWORD	dwChengXiangID;	// 大丞相id
	//4 DWORD	dwYuanShuaiID;	// 大元帅id
	//5 DWORD	dwYuShiID;		// 大御史id
};

class GuildHelper
{
public:
	static INT32 getLevelUpNeedFund(byte byLevel)
	{
		switch (byLevel)
		{
		case 1:
			return 10000;
		case 2:
			return 20000;
		case 3:
			return 40000;
		case 4:
			return 80000;
		case 5:
			return 160000;
		case 6:
			return 320000;
		case 7:
			return 640000;
		case 8:
			return 1280000;
		case 9:
			return 2560000;
		case 10:
			return 5120000;
		case 11:
			return 10240000;

		default:
			return 0;
		}
	}
	static double getMoneyToFanlong(byte byLevel)
	{
		if (byLevel < 7)
		{
			return 0.05 * byLevel;
		}
		else
		{
			return 0.4;
		}
	}
	// 帮会战所需资金
	static INT32 getGuildWarFund(byte byLevel)
	{
		switch (byLevel)
		{
		case 3:
			return 40000000;
		case 4:
			return 60000000;
		case 5:
			return 110000000;
		case 6:
			return 130000000;
		case 7:
			return 150000000;
		default:
			return 0;
		}

		return 0;
	}
};

//-----------------------------------------------------------------------------
#pragma pack(pop)