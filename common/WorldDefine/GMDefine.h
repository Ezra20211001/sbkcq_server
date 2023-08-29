/*******************************************************************************

	Copyright 2010 by tiankong Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef __GMDEFINE_H__
#define __GMDEFINE_H__

#pragma pack(push,1)

#ifndef MAX_MD5_ARRAY
	#define MAX_MD5_ARRAY 35
#endif // MAX_MD5_ARRAY

#ifndef GMAFFICHELEN
	#define  GMAFFICHELEN 200	// 服务器广播公告最大字符数
#endif // GMAFFICHELEN

#ifndef GMPERIODMAXINDEX 
	#define GMPERIODMAXINDEX 10 // 服务器自动广播公告最大数目
#endif // GMPERIODMAXINDEX

#ifndef MAX_GUIL_BUILD
	#define MAX_GUIL_BUILD 5
#endif //MAX_GUIL_BUILD

// DWORD 32bit 32种权限
enum EGMPrivilege
{
	EGMP_ONOFF						= 1 << 0, // 开/关
	EGMP_VIPLOOK					= 1 << 1, // 重点监控
	EGMP_FORBIDTALK			= 1 << 2, // 禁言<s>
	EGMP_KEYWORDS				= 1 << 3, // 关键词
	EGMP_KICKROLE					= 1 << 4, // 踢人<s>
	EGMP_FORBIDACCOUNT	= 1 << 5, // 封号<s>
	EGMP_AFFICHE					= 1 << 6, // 公告<s>
};

enum EServerType
{
	EST_GAMESERVER,
	EST_LOGINSERVER,
};

//! 不能修改值，必须和DB保持一致
enum EToolType
{
	ETTYPE_COMMON = 0,
	ETTYPE_CHATTOOL = 25,
	ETTYPE_EDITTOOL	= 255,
	ETTYPE_SERVERTOOL = 65535,
};

enum EGMDoubleType
{
	EGMDT_EXP		= 0,				//双倍经验
	EGMDT_ITEM		= 1,				//双倍物品
	EGMDT_Practice	= 2,				//双倍修炼
	EGMDT_Dacning	= 3,				//跳舞
	EGMDT_NUMBER	,
};
#define EDT_VALID(E)	((E) >= EGMDT_EXP && (E) < EGMDT_NUMBER)	

enum EGMLogicError
{
	EGMProof_Denied = 1,
	EGMForbidTalk_RoleNotExist,
	EGMForbidTalk_ServerNotExist,
	EGMForbidAccount_ServerNotExist,
	EGMForbidAccount_Forbidded,			// 账号已经被封
	EGMForbidAccount_Freed,				// 账号已经解封
	EGMForbidAccount_AccountNotExist,	// 账号不存在


//=================================================
//	错误码添加在此之上
//=================================================
	EGMMall_Init_Failed,
	EGMMall_LoadProto_Failed,
	EGMDatabase_Busy,

	EGMLE_MAX
};


struct tag_Role_Name_Info
{
	TCHAR sz_account_name[X_LONG_NAME];
	TCHAR sz_role_name[3][X_SHORT_NAME];
};

struct tag_Role_Del_List
{
	vector<tstring> v_role_del;
	vector<DWORD> v_role_id;
};

struct tag_role_sim_info
{
	DWORD dw_role_id;
	TCHAR sz_role_name[X_SHORT_NAME];
};

struct tag_time_bound
{
	BYTE start_month;
	BYTE start_day;
	BYTE end_month;
	BYTE end_day;
	tag_time_bound() { memset(this, 0, sizeof(*this)); }
	BOOL Check(){ return start_month <= end_month; }
};

struct tag_item_log
{
	DWORD cmd_id; // CMD<e_log_cmd_id>
	DWORD type_id;	// 道具TYPEID
	INT optnum; // 变化个数(+：表示获得；-：表示失去)
	INT64 serial;			// 64位ID
	INT container_type; // 容器类型
	INT result_num;		// 最终个数
	INT64 serial2;			// 64位ID
	INT container_type2; // 容器类型
	INT result_num2;	// 最终个数
	DWORD dw_role_relation; // 关联的角色id
	DWORD dwTime;	// 时间<tagDWORDTime>
	DWORD dw_role_id;// 角色ID
};

struct tag_money_log
{
	DWORD cmd_id; // CMD<e_log_cmd_id>
	INT container_type; // 容器类型
	INT number;				// 数量(+：表示存入；-：表示取出)
	INT64 total_number; // 指定类型容器中总量
	DWORD dw_role_relation; // 关联的角色id
	DWORD dwTime;			// 时间<tagDWORDTime>
};
struct tag_exploits_log
{
	DWORD cmd_id; // CMD<e_log_cmd_id>
	INT number;				// 数量(+：表示存入；-：表示取出)
	INT64 total_number; // 指定类型容器中总量
	DWORD dw_role_relation; // 关联的角色id
	DWORD dwTime;			// 时间<tagDWORDTime>
};

struct tag_yuanbao_log
{
	DWORD cmd_id; // CMD<e_log_cmd_id>
	INT container_type; // 容器类型
	INT number;				// 数量(+：表示存入；-：表示取出)
	INT64 total_number; // 指定类型容器中总量
	DWORD dw_role_relation; // 关联的角色id
	DWORD dwTime;// 时间<tagDWORDTime>
};

struct tag_bank_log
{
	DWORD	 seller_id; // 卖出者
	DWORD buyer_id; // 购买者
	DWORD bidup_id; // 竞拍者
	DWORD type;			// 竞拍类型
	DWORD bidup;		// 竞拍价格
	DWORD chaw;	//  一口价
	DWORD number;// 卖出数量
	DWORD time;//  成交时间
};

struct tag_paimai_log
{
	INT64 serial;
	DWORD	 seller_id; // 卖出者
	DWORD buyer_id; // 购买者
	DWORD bidup_id; // 竞拍者
	DWORD bidup;		// 竞拍价格
	DWORD chaw;	//  一口价
	DWORD time;//  成交时间
};

struct tag_gamaserver_info
{
	DWORD dwIP;			// ip int_ntoa
	INT mMaxNumber;
	INT mOnlineNumber;
	BOOL mStatus;
	BOOL mDBStatus;
	BOOL mDatebase;
	TCHAR szServerName[X_SHORT_NAME];
};

struct tag_affiche_cache
{
	DWORD dwCurTick;
	DWORD dwTickTimes;
	TCHAR szAfficheMsg[GMAFFICHELEN];
public:
	BOOL elapse() const { return dwCurTick>= dwTickTimes;}
	VOID reset() { dwCurTick = 0;}
	VOID update() { ++dwCurTick;}
};

struct tag_role_skill
{
	INT n_id;	// 技能ID
	INT bidden_level; // 可学习等级
	INT self_level;		// 单签等级
	INT proficiency;	// 熟练度
	INT cooldowm;	// CD
};

struct tag_role_pet
{
	DWORD dw_id; // 宠物ID
	DWORD dw_type_id; // 宠物类型ID
	INT quality;				// 宠物品质
	INT grade;					// 宠物品阶???<咨询lc>
	INT step;						// 
	INT state;						// 状态
	DWORD dw_cur_spirit;	// 寿命
	DWORD dw_happy_val; // 心情
	DWORD dw_skill_id[5]; // 宠物技能
	TCHAR sz_pet_name[X_SHORT_NAME];	// 名字
	INT		n_strength;				// 附加角色力量
	INT		n_agility;				// 附加角色敏捷
	INT		n_innerForce;			// 附加角色智力
	INT		n_att_point;			// 属性点
	void Init( ){memset(this, 0, sizeof(*this));}
};

struct tag_role_data
{
	DWORD dw_account_id; // 账号ID
	DWORD dw_role_id;		// 角色ID
	TCHAR sz_role_name[X_SHORT_NAME];	// 角色名字
	BYTE e_class; //职业 EClassType
	BYTE e_sex;//性别
	INT n_shengw;//声望
	INT n_level; // 等级
	INT n_cur_exp; // 当前经验
	INT n_hp;	// 血
	INT n_mp; // 魔法
	INT n_brotherhood; // 义气
	INT n_vigour;			// 元气
	INT n_pk;			// pk值
	DWORD dw_guild;	// 帮会ID
	DWORD dw_map;	// 地图ID
	DWORD dw_yuanbao;	// 身上的元宝数
	INT16			n16_bag_size;					// 背包大小
	INT				n_bag_gold;					// 背包中金子数
	INT				n_bag_silver;					// 背包中银子数
	INT				n_bag_copper;					// 背包中铜数
	INT				n_bag_bind_gold;				// 背包中绑定金子数
	INT				n_bag_bind_silver;				// 背包中绑定银子数
	INT				n_bag_bind_copper;				// 背包中绑定铜数
	INT				n_bag_tuanbao;					// 背包中元宝数

	INT16			n16_ware_size;				// 账号仓库大小
	INT				n_ware_gold;					// 账号仓库中金子数
	INT				n_ware_silver;				// 账号仓库中银子数
	INT				n_ware_copper;				// 账号仓库中铜数
	FLOAT			f_coordinate[3];			// 位置（x,y,z）
	INT				n_exploits;					// 战功
	INT				n_totalrecharge;			// 当前账号充值元宝总数 gx add 2013.11.05
	BOOL			b_gm;							// GM账号
	// 物品(/装备)->
	INT				n_item_num;					// 物品装备个数		-- tagItem,tagEquip
	INT				n_skill_num;					// 技能数 -- tag_role_skill
	INT				n_pets_num;					// 宠物数目
	BYTE by_data[1];
};


//! 被禁言角色
struct tag_forbid_talk_role
{
	DWORD dw_role_id;					// 角色ID
	DWORD dw_account_id;
	DWORD dw_forbid_time_start;			// 禁言开始时间
	DWORD dw_forbid_time_end;			// 禁言结束时间
	TCHAR sz_role_name[X_SHORT_NAME];	// 角色名字 
};

//! 被封停账号
struct tag_forbid_account
{
	DWORD dw_account_id;					//! 账号ID 
	DWORD dw_forbid_mask;					//!	被禁原因
	TCHAR sz_account_name[X_SHORT_NAME];	//!	账号
};


//! GM操作日志
struct tag_gm_log
{
	DWORD dw_ip; // gm所在IP ntoa
	DWORD dw_time; // gm操纵时间
	DWORD dw_account; // gm账号
	TCHAR sz_gm_cmd[X_HUGE_NAME]; // 操作记录
};

//! 帮会基本资料
struct tag_guild_basic
{
	DWORD dw_guild_id;
	DWORD dw_guild_level;
	TCHAR sz_guild_name[X_SHORT_NAME];
};

//! 帮会建筑
struct tag_guild_build
{
	DWORD dw_type;
	DWORD dw_level;
	DWORD dw_max_level;
	DWORD dw_holiness_step;
	DWORD dw_use_num;
	DWORD dw_use_time; // 开启时间
	tag_guild_build() { memset(this, 0, sizeof(*this));}
};
//! 帮会基础资料, 详细情况咨询"钟阳"老师
#include "guild_define.h"
struct tag_guild_data
{
	DWORD dw_guild_id;
	DWORD dw_creator_id;
	DWORD dw_create_time;
	DWORD dw_master_id;
	DWORD dw_member_num;
	//DWORD dw_member_max; //成员上限 计算
	DWORD dw_prosperity;
	// 维护费 计算
	// 鼎炉等级 == 帮会等级
	// 修炼效率 2 * 鼎炉等级
	// 逐鹿宝鼎 (无)
	INT32 n32_script_data[64];	// 帮会脚本数据	
	TCHAR sz_pos_name[X_GUILD_POS_NUM][MAX_GUILD_POS_NAME_LEN];
	tag_guild_build stData[MAX_GUIL_BUILD];
	tag_guild_data() { memset(this, 0, sizeof(*this));}
};

//! 帮会成员资料
struct tag_guild_member
{
	DWORD dw_role_id;
	DWORD dw_role_level;
	BYTE  by_class; //职业 EClassType	
	BYTE  by_position; // 职位 EGuildMemberPos
	DWORD dw_contribution; // 帮贡
	DWORD dw_last_login;	// 最后登陆
	TCHAR sz_role_name[X_SHORT_NAME];
};


//! 定义存储结构 请不要随意修改

//! 角色基础数据
struct tag_role_basic_save
{
	INT n_cur_exp;				// 当前经验
	INT n_level;			// 等级
	INT n_pk;					// pk值
	DWORD dw_yuanbao;			// 身上的元宝数
	
	INT	n_bag_gold;				// 背包中金子数
	INT	n_bag_silver;			// 背包中银子数
	INT	n_bag_copper;			// 背包中铜数
	
	INT	n_bag_bind_gold;		// 背包中绑定金子数
	INT	n_bag_bind_silver;		// 背包中绑定银子数
	INT	n_bag_bind_copper;		// 背包中绑定铜数

	INT	n_ware_gold;			// 账号仓库中金子数
	INT	n_ware_silver;			// 账号仓库中银子数
	INT	n_ware_copper;			// 账号仓库中铜数

	INT exploits;
	DWORD dw_bindyuanbao;		//礼券
};

//! 存储技能
struct tag_role_skill_save
{
	INT nSkillID;
	INT nSkillLevel;
	INT nProficiency;
	INT nCooldown;
};

//! 保存宠物
struct tag_role_pet_save
{
	DWORD dw_id; // 宠物ID
	INT nGrade; // nGrade 和 nStep 计算等级用 
	INT nStep;	// nGrade 和 nStep 计算等级用 
	DWORD dw_cur_spirit;	// 寿命
	DWORD dw_happy_val; // 心情
	INT		n_strength;				// 附加角色力量
	INT		n_agility;				// 附加角色敏捷
	INT		n_innerForce;			// 附加角色智力
	INT		n_att_point;			// 属性点
	//DWORD dw_skill_id[5]; // 宠物技能
};

//! 保存装备
struct tag_equip_save
{
	INT64 n64_serial;// 物品唯一序列号
	INT32 nLevel;			// 等级
	INT32 nCurLevelExp;	// 当前升级经验
	BYTE  bybind;			// 绑定类型
	BYTE  byTalentPoint;//已投天赋点
	BYTE  byMaxTalentPoint;//最大天赋点
	BYTE  byHoleNum;		// 空数
	DWORD dwHoleGemID[MAX_EQUIPHOLE_NUM]; // 镶嵌的宝石
	BYTE  byQuality;  //品质
	BYTE  byConsolidateLevel;//强化等级
	BYTE  byConsolidateLevelStar;//强化星数
	BYTE	byFlareVal;		// 光晕
	tagRoleAttEffect EquipAttitionalAtt[MAX_ADDITIONAL_EFFECT]; // 附加属性
};

//! 制造装备
struct tag_equip_create
{
	DWORD dw_data_id; // 基本物品种类编号
	BYTE  byBind;	  // 绑定状态
	BYTE  byQuality; //品级 EItemQuality
	INT32 nLevel;			// 等级
	INT32 nCurLevelExp;	// 当前升级经验
	BYTE  byTalentPoint;//已投天赋点
	BYTE  byMaxTalentPoint;//最大天赋点
	BYTE  byHoleNum;		// 空数
	DWORD dwHoleGemID[MAX_EQUIPHOLE_NUM]; // 镶嵌的宝石
	BYTE  byConsolidateLevel;//强化等级
	BYTE  byConsolidateLevelStar;//强化星数
	tagRoleAttEffect EquipAttitionalAtt[MAX_ADDITIONAL_EFFECT]; // 附加属性
	INT32				EquipAttitional[MAX_RAND_ATT];
	BYTE	byFlareVal;		// 光晕
};

//! 制造物品
struct tag_item_create
{
	DWORD dw_data_id; // 基本物品种类编号
	BYTE  byBind;	  // 绑定状态
	INT16 n16Number; // 数量
};
//! 描述非法IP gx add 2013.11.07
struct tag_Invalid_IP
{
	TCHAR sz_ip_name[X_SHORT_NAME];
	INT	  n_ip_num;//该IP对应的个数
public:
	tag_Invalid_IP()
	{
		ZeroMemory(sz_ip_name , X_SHORT_NAME*sizeof(TCHAR));
	}
};
#pragma pack(pop)

#endif //__GMDEFINE_H__
