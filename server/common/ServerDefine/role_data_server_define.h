/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#pragma once

#include "../../common/WorldDefine/base_define.h"
#include "../../common/WorldDefine/RoleDefine.h"
#include "../../common/WorldDefine/time.h"
#include "../../common/WorldDefine/talent_define.h"
#include "../../common/WorldDefine/currency_define.h"
#include "../ServerDefine/clandata_server_define.h"
#include "../../common/WorldDefine/container_define.h"
#include "../../common/WorldDefine/ItemDefine.h"
#include "../../common/WorldDefine/Raid_define.h"
#include "../ServerDefine/log_server_define.h"

#pragma pack(push, 1)

struct tagDWORDTime;


const INT MIN_ROLE_SAVE2DB_INTERVAL			= 60 * TICK_PER_SECOND;
const INT ROLE_TIME_STAT_INTERVAL			= 30 * 60 * TICK_PER_SECOND;
const INT ROLE_HANG_TIME					= 60;
const INT MAX_LEAVE_EXP						= 20000;
const INT MAX_LEAVE_BROTHER					= 50000;
const INT MAX_GIFT_NUM						= 4;				// 最大新手礼品数量
const INT32 MAX_ITEM_NEEDLOG_NUM			= 100000;


//! 随一级属性变化的二级属性
enum e_role_att_to_change
{
	erac_null = -1,

	erac_attack,
	earc_defense,
	earc_maxhp,
	earc_hit,
	earc_dodge,
	earc_block,
	earc_crit,
	earc_critvalue,
	earc_fancrit,
	earc_fancritvalue,
	earc_maxmp,
	earc_hp_reborn,
	earc_mp_reborn,

	earc_num
};

enum
{
	e_database_insert_role_name_exist		= 1,		// 创建角色，名称已存在(与其他角色或门派名称相同)
	e_database_insert_role_failed			= 2,		// 数据库中创建角色失败
	e_database_insert_friend_failed			= 3,		// 数据库中添加好友失败
	e_database_insert_enemy_failed			= 4,		// 数据库中添加仇敌失败
	e_database_insert_friendship_failed		= 5,		// 数据库中添加友好度失败
	e_database_insert_black_failed			= 6,		// 添加黑名单失败

	e_database_load_sim_role_failed			= 51,		// 该帐号下无角色，或读取帐号角色基本信息失败	
	e_database_load_role_data_failed		= 52,		// 从数据库中读取某个角色失败	
	e_database_load_skill_failed			= 53,		// 从数据库中读取技能列表失败	
	e_database_load_role_buff_failed		= 54,		// 从数据库中读取角色Buff失败	
	//E_DBLoad_TalentFailed					= 55,		// 从数据库中读取天资列表失败	
	e_database_load_title_failed			= 56,		// 从数据库中读取称号列表失败	
	e_database_load_item_Failed				= 57,		// 从数据库中读取物品列表失败
	e_database_load_equip_failed			= 58,		// 从数据库中读取装备列表失败	
	e_database_load_friend_failed			= 59,		// 从数据库中读取好友列表失败	
	e_database_load_enemy_failed			= 60,		// 从数据库中读取仇敌列表失败	
	e_database_load_quest_failed			= 61,		// 从数据库中读取任务列表失败	
	e_database_laod_quest_done_failed		= 62,		// 从数据库中读取已完成任务列表失败		
	e_database_load_sim_quest_failed		= 63,		// 从数据库中读取简易任务列表失败	
	e_database_laod_sim_quest_done_failed	= 64,		// 从数据库中读取已完成简易任务列表失败		
	e_database_friendship_failed			= 65,		// 从数据库中读取好友度列表失败	

	//	E_DBLoad_BaiBao_NoNewItem			= 65,		// 没有新的需要发放到百宝袋中的物品(装备)
	e_database_baibao_failed				= 66,
	e_database_load_item_need_log_failed	= 67,	
	e_database_save_role_failed				= 70,		// 数据库保存失败

	e_database_load_baibao_log_failed		= 71,		// 百宝袋历史记录读取失败

	e_backup_del_role_data_failed			= 80,		// 备份被删除角色相关数据失败
	e_backup_delete_item_failed				= 81,		// 备份被删除角色物品数据失败
	e_delete_role_data_failed				= 82,		// 删除角色属性相关数据失败
	e_record_delete_role_data_failed		= 83,		// 角色备份删除成功，但写role_del表失败

	//	E_DelItemFailed					= 90,		// 删除被删除角色物品数据失败
	//	E_DBDelete_RoleBuffFailed		= 91,		// 删除角色Buff数据失败
	e_database_delete_friend_failed			= 92,		// 删除好友失败
	e_database_delete_enemy_falied			= 93,		// 删除仇敌失败
	e_database_delete_role_failed			= 94,		// 删除角色失败
	e_database_delete_friendship_failed		= 95,		// 删除友好度失败
	e_database_delete_black_failed			= 96,		// 删除黑名单失败


	e_change_role_name_failed				= 100,		// 修改角色名称失败

	e_database_load_rep_rankdata_failed		= 120,		// 读取声望排名错误

};


//! 人物创建结构
struct s_create_role_info
{
	tagAvatarAtt	avatar;						// size = 16
	TCHAR			sz_role_name[X_SHORT_NAME];

	tagDWORDTime	create_time_;					// 创建时间
	DWORD			dw_map_id_;
	FLOAT			fX;
	FLOAT			fY;
	FLOAT			fZ;
	FLOAT			f_face_x_;
	FLOAT			f_face_y_;
	FLOAT			f_face_z_;
	EClassType		e_class_type_;
	BYTE			by_level_;
	BYTE			by_reserved_[3];

};


//! 实时保存数据库枚举
enum e_real_time_save_att
{
	ertsa_null			= -1,
	ertsa_exp			= 0,
	ertsa_level			= 1,
	ertsa_brotherhood	= 2,
	ertsa_love			= 3,
	ertsa_wuhuen		= 4
};


//! 离线玩家数据结构
struct s_role_info
{
	DWORD			dw_role_id;					// ID
	DWORD			dw_role_name_crc;				// 名称CRC
	DWORD			dw_account_id;				// 账户ID
	TCHAR			sz_role_name[X_SHORT_NAME];	// 名字
	DWORD			dw_map_id_;					// 所在地图
	tagDWORDTime	dw_time_last_logout_;		// 最后上线时间
	BYTE			by_level;					// 等级
	BYTE			by_sex_;					// 性别
	EClassType		e_class_type_;
	bool			b_online_;					// 玩家是否在线
	DWORD dw_amends_flag;			// 赔偿标志
	s_role_info()
	{
		memset(this, 0, sizeof(*this));
	}
};


//! 安全码
struct s_safe_code
{
	DWORD	dw_safe_code_crc;		// 安全码crc32，INVALID_VALUE表示没有设置过
	DWORD	dw_reset_time;		// 重置时间，INVALID_VALUE表示没有重置
};

//! accountrel表内相关属性
struct s_account_common
{
	s_safe_code	s_safe_code_;
	DWORD		dw_bag_password_crc_;
	INT			n_baibao_yuanbao_;
	INT64		n64_ware_silver_;
	INT16		n16_ware_size_;
	INT16		n16_ware_step;
	INT32		n_yuanbao_recharge;
	BOOL		b_receive;
	DWORD		dw_total_recharge;
	INT16		n16_receive_type;
	DWORD		dw_receive_type;
	DWORD		dw_web_type;
	INT32		n32_score;
	BOOL		b_Robort;

	VOID init()
	{
		s_safe_code_.dw_safe_code_crc = INVALID_VALUE;
		s_safe_code_.dw_reset_time	= INVALID_VALUE;

		dw_bag_password_crc_				= INVALID_VALUE;
		n64_ware_silver_			= 0;
		n_baibao_yuanbao_			= 0;
		n16_ware_size_				= 0;
		n16_ware_step				= 1;
		n_yuanbao_recharge			= 0;
		b_receive					= TRUE;
		dw_total_recharge			= 0;
		n16_receive_type			= 0;
		dw_receive_type				= 0;
		dw_web_type					= 0;
		n32_score					= 0;
	}
};

//! 新手礼包
struct s_new_role_gift_proto
{
	INT16	n_id_;
	DWORD	dw_gift_id_[MAX_GIFT_NUM];
	DWORD	dw_time_[MAX_GIFT_NUM];
	DWORD	dw_gift_num[MAX_GIFT_NUM];
};

//! 新手礼包
struct s_new_role_gift
{
	INT		n_id_;
	INT		n_step_;				// 阶段
	DWORD	dw_gift_id_;			// 礼物ID
	DWORD	dw_leave_time_;			// 剩余时间
	BOOL	b_get_;					// 是否可以获取
	BOOL	b_begin_time_;			// 是否开始计时 

	s_new_role_gift()
	{
		n_id_ = 0;
		n_step_ = 0;
		dw_gift_id_ = INVALID_VALUE;
		dw_leave_time_ = 0;
		b_get_ = FALSE;
		b_begin_time_ = FALSE;
	}

	VOID init(INT n_id, INT n_step, DWORD dw_gift_id, DWORD dw_leave_time, BOOL b_get)
	{
		this->n_id_ = n_id;
		this->n_step_ = n_step;
		this->dw_gift_id_ = dw_gift_id;
		this->dw_leave_time_ = dw_leave_time;
		this->b_get_ = b_get;
		b_begin_time_ = FALSE;
	}

	VOID set_get(BOOL b_get) { this->b_get_ = b_get; }

	VOID reset(INT n_id, INT n_step, DWORD dw_gift_id, DWORD dw_leave_time)
	{
		this->n_id_ = n_id;
		this->n_step_ = n_step;
		this->dw_gift_id_ = dw_gift_id;
		this->dw_leave_time_ = dw_leave_time;
		b_get_ = FALSE;
		b_begin_time_ = FALSE;
	}

};

struct s_1v1_score
{
	INT		n_cur_score;		// 当前积分
	INT		n_day_max_score;		// 当日最大积分
	INT		n_day_scroe_num;		// 当日进入次数
	INT16	n16_score_award;		// 积分竞技排名
};


//! 游戏服务器与数据库服务器存取的玩家数据结构
struct s_role_data_const
{
	DWORD			dw_role_name_crc;			// 名称CRC
	TCHAR			sz_role_name[X_SHORT_NAME];	// 名称
	tagAvatarAtt	avatar;						// 外观
	tagDWORDTime	create_time_;				// 创建时间
};

struct s_role_data_save
{
	tagDWORDTime	login_time_;				// 登入时间
	tagDWORDTime	logout_time_;				// 登出时间
	INT				n_online_time_;				// 总在线时常
	INT				n_cur_online_time_;			// 当次在线时常

	tagDWORDTime	leave_guild_time_;			// 离开帮会时间

	tagAvatarEquip	avatar_equip_;				// 装备外观
	tagDisplaySet	display_set_;				// 外观显示设置

	DWORD			dw_map_id_;					// 所在的地图的ID
	DWORD			dw_reborn_map_id_;			// 复活地图ID
	FLOAT			f_coordinate_[3];			// 位置（x,y,z）
	FLOAT			f_face_[3];					// 朝向（Vectro3）

	EClassType		e_class_;					// 职业
	EClassTypeEx	e_class_ex_;				// 扩展职业

	INT				n_level_;					// 玩家等级
	INT				n_cur_exp_;					// 玩家当前级别的升级经验

	INT				n_hp_;						// 体力
	INT				n_mp_;						// 真气
	INT				n_rage_;					// 怒气
	INT				n_endurance_;				// 持久力 改为神龛武魂
	INT				n_brotherhood_;				// 义气
	INT				n_injury_;					// 内伤 改为灵气值
	INT				n_knowledge_;				// 阅历
	INT				n_morale_;					// 士气
	INT				n_morality_;				// 道德 改为灵魂值
	INT				n_luck_;					// 武学修为 改成了幸运值
	INT				n_credit_;					// 信用度
	INT				n_identity_;				// 身份
	INT				n_vip_point_;				// 会员积分
	INT				n_vigour_;					// 元气

	INT				n_att_point_;				// 玩家可用的属性点
	INT				n_talent_point_;			// 玩家可用的天资点

	INT				n_att_point_add_[X_ERA_ATTA_NUM];// 玩家投放到各个一级属性中的值
	tagRoleTalent	talent_[X_MAX_TALENT_PER_ROLE];// 玩家的天资

	BOOL			b_safe_guard_;					// 是否被PK保护
	tagDWORDTime	close_safe_guard_time_;			// 上次关闭PK保护的时间
	INT				n_pk_value_;					// pk值
	
	DWORD			dw_destory_equip_count;			// 摧毁装备次数
	INT16			n16_bag_size_;					// 背包大小
	INT				n_bag_gold_;					// 背包中金子数
	INT				n_bag_silver_;					// 背包中银子数
	INT				n_bag_copper_;					// 背包中铜数
	INT				n_bag_bind_gold_;				// 背包中绑定金子数
	INT				n_bag_bind_silver_;				// 背包中绑定银子数
	INT				n_bag_bind_copper_;				// 背包中绑定铜数
	INT				n_bag_tuanbao_;					// 背包中元宝数
	INT				n_ex_volume_;					// 角色赠点数
	
	INT16			n16_pet_packet_size_;			// 宠物栏数量
	INT16			n16WareSize;				// 账号仓库大小
	INT				nWareGold;					// 账号仓库中金子数
	INT				nWareSilver;				// 账号仓库中银子数
	INT				nWareCopper;				// 账号仓库中铜数
	//INT				nWareYuanBao;				// 账号仓库中元宝数

	DWORD			dw_guild_id;					// 帮派id
	DWORD			dw_team_id_;					// 队伍ID
	
	INT				n_total_tax_;					// 缴税总额

	tagRemoteOpenSet s_remote_open_set_;			// 对远端玩家公开信息设置
	UINT16			u16_active_title_id[3];			// 当前称号

	DWORD			dw_time_get_mall_free_;			// 上次从商城领取免费物品时间

	INT	 			n_skill_num_;					// 技能个数			-- tagSkillSave
	INT				n_buff_num_;					// 状态个数			-- tagBuffSave

	INT				n_title_num_;					// 称号个数			-- tagTitleSave

	INT				n_item_num_;					// 物品装备个数		-- tagItem,tagEquip
	INT				n_friend_num_;					// 好友个数			-- 读: tagFriendSave, 存: 实时,即单独发消息
	INT				n_enemy_num_;					// 仇敌个数			-- 读: DWORD dwEnemyID, 存: 实时,即单独发消息
	INT				n_quest_num_;					// 任务列表个数		-- tagQuestSave
	INT				n_quest_done_num;				// 已完成的任务个数 -- 读：tagQuestDoneSave，存：实时
	INT				n_item_cd_time_num_;			// 物品冷却时间		-- tagCDTime
	INT				n_friendship_num_;				// 友好度			-- tagFriendshipSave
	INT				n_black_num_;					// 黑名单			-- DWORD
	BOOL			b_clan_data_chg_;				// 氏族数据是否改变
	INT				n_pets_num_;					// 宠物数目
	tagScriptData<ESD_Role>	data_;					// 玩家脚本数据
	INT				n_treasure_sum_;				// 玩家开启宝箱数
	INT				n_map_limit_num_;				// 进入地图限制数量
	INT				n_achievement_num_;				// 完成成就个数
	INT				n_achievement_criteria_num_;	// 进行中的成就条件个数

	DWORD			dw_last_stall_time_;			// 摊位最近更新时间
	INT32			n_stall_daily_exp_;				// 摊位当日经验
	INT32			n_stall_cur_exp_;				// 摊位当前等级经验
	BYTE			by_stall_level_;				// 摊位等级
	BOOL			h_has_left_msg_;				// 有留言
	
	// 禁言状态
	DWORD	dw_forbid_talk_start_;
	DWORD	dw_forbid_talk_end_;

	INT16			n16_hang_num_;					// 挂机次数
	BOOL			b_exp_;							// 是否使用经验丹
	BOOL			b_brotherhood_;					// 是否使用义气丹
	INT				n_leave_exp_;					// 离线经验
	INT				n_leave_brotherhood_;			// 离线义气

	INT				n_total_mater_moral_;			// 师德值

	INT				n_send_mail_num_;				// 发送邮件的数量

	DWORD		 dw_master_id_;					//师傅
	DWORD        dw_master_prentice_forbid_time_;		//禁止收徒或拜师时间

	DWORD		 dw_own_instance_id_;				// 所在副本ID
	DWORD		 dw_own_instance_map_id_;			// 所在副本地图ID
	tagDWORDTime dw_instance_create_time_;			// 副本创建时间

	BYTE		 by_role_help_[ROLE_HELP_NUM];		// 人物帮助数据
	BYTE		 by_talk_data_[TALK_DATA_NUM];		// 人物对话数据
	//tagKeyInfo   st_key_info_[MAX_KEY_NUM];			// 快捷键数据
	roleOnlineState st_key_info_;

	BYTE		 by_role_day_clear[ROLE_DAY_CLEAR_NUM];	// 每天清零数据

	INT			n_kill_num_;						// 杀人数

	INT		n_gift_id_;								// 礼物组ID	
	INT		n_gift_step_;								// 阶段
	DWORD	dw_gift_id_;								// 礼物ID
	DWORD	dw_gift_leave_time_;						// 剩余时间
	BOOL	b_gift_get_;								// 是否可以获取

	ECamp	e_role_camp;								// 人物阵营

	INT		n_paimai_limit;								// 人物拍卖数量限制
	
	INT		n_bank_limit;								// 人物钱庄拍卖数量限制

	INT		n_shop_exploits_limit;						// 战功商店限制

	DWORD	dw_today_online_tick_;						// 今日在线时间
	DWORD	dw_history_vigour_cost_;					// 元气值消耗
	DWORD	dw_perday_get_vigour_total;	

	INT16	n16_exbag_step;								// 扩充包裹阶段
	INT16	n16_exware_step;							// 扩充仓库阶段

	INT		n_yuanbao_exchange_num;						// 元宝兑换次数
	INT		n_achievement_point;						// 成就点数
	INT		n_achievement_num;							// 成就数量

	TCHAR	sz_signature_name[X_SHORT_NAME];			// 签名 
	CircleQuestMan	circle_quest_man_;					// 环随机任务
	INT n_graduates_num;				// 是否出师

	s_1v1_score		st_1v1_score;		// 积分竞技

	INT		n_inst_process_num;							// 副本进度数量

	INT32	n32_exploits;				// 战功
	INT	n_circle_quest_fresh;		// 环随机刷新次数
	INT	n_circle_quest_freshMax;		// 环随机刷新次数
	INT n_circle_quest_perdaynum;			// 任务个数
	BOOL b_PurpureDec;
	INT n_CoolDownReviveCD;
	INT n_PerDayHangGetExpTimeMS;
	INT32	n32_active_num;							// 活跃度
	INT32	n32_active_data[MAX_ACTIVE_DATA];		// 活跃度数据
	BOOL	b_active_receive[MAX_ACTIVE_RECEIVE];	// 活跃度领奖数据
	
	INT32	n32_guild_active_num;						// 帮会活跃度
	INT32	n32_guild_active_data[MAX_ACTIVE_DATA];		// 帮会活跃度数据
	BOOL	b_guild_active_receive[MAX_ACTIVE_RECEIVE];	// 帮会活跃度领奖数据

	INT32	n32_rating;			// 战斗力
	DWORD			dw_shihun;			// 噬魂
	INT16	n16_pet_xiulian_size;			// 宠物寄养数量
	INT				n_god_level_;					// 神级

	INT32	nInstanceData;		//  副本是否打过了
	tagDWORDTime nInstanceShaodang;	//	扫荡开始时间
	INT32	nSaodangIndex;		//  扫荡的副本索引
	DWORD	dwSpouseID;			//	配偶ID
	INT dwVIPLevel;				//	vip等级
	tagDWORDTime dwVIP_Deadline;//  vip截止日期
	/*********************************************************************************************************
	*技能列表，状态列表，称号列表，称号条件列表，物品列表，装备列表，好友列表，仇敌列表，任务列表，已完成任务列表，
	*物品冷却时间表, 友好度表，角色名帖(自定义)
	*必须按顺序拷贝
	*********************************************************************************************************/

	BYTE			by_data[1];
};

struct s_role_data_load
{
	DWORD				dw_size;					// 玩家信息大小
	s_role_data_const	role_data_const_;
	s_role_data_save	role_data_save_;
};

struct s_record_del // 删除的相关信息(两次保存间)
{
	INT	 	n_skill_num_;		// 技能个数(dwSkillID):  所有原因产生的技能遗失,如果先遗忘后再学,此处也会记录
	INT		n_buff_num_;		// 状态个数(dwBuffID):    从玩家身上消失过的所有状态
//	INT		nTalentNum;		// 天资列表(ETalentType): 洗点产生的
//	INT		n_item_num;		// 物品个数(n64_serial):   需摧毁的，即需从数据库中删除的 -- 实时
//	INT		nEquipNum;		// 装备个数(n64_serial):   需摧毁的，即需从数据库中删除的 -- 实时
	INT		n_quest_num_;		// 任务个数(dwQuestID):   包括删除的和完成的

	/*********************************************************************************************************
	*技能列表，状态列表，物品列表，装备列表，任务列表
	*必须按顺序拷贝
	*********************************************************************************************************/
	BYTE	by_data_[1];		// 记录类型
};

//! 人物技能
struct s_skill_save
{
	DWORD	dw_id;				// 技能ID
	INT		n_self_level_;		// 自身等级
	INT		n_learn_level_;		// 投点等级
	INT		n_cool_down_;		// 技能还需要的冷却时间
	INT     n_proficiency_;		// 技能熟练度
};

//! 人物buff的基本信息
struct s_buff_save
{
	DWORD		dw_buff_id_;					// ID
	INT32		n_persist_tick_;				// 当前持续时间

	INT8		n_level_;						// 等级
	INT8		n_cur_lap_times_;				// 当前叠加次数
	INT8		n_modifier_num_;				// 影响它的技能个数
	INT8		n_dummy_[1];

	DWORD		dw_src_unit_id_;				// 源Unit的ID
	DWORD		dw_src_skill_id_;				// 由哪个技能产生（大ID）
	INT64		n_serial_;						// 由哪个物品或装备产生
	DWORD		dw_item_type_id_;				// 物品或装备的属性ID

	BYTE		by_data_[1];
};

//! 好友
struct s_friend_save
{
	DWORD		dw_friend_id_;		// 好友id
	INT32		n_group_id_;		// 分组
};

struct s_friendship_save
{
	DWORD		dw_friend_id_;		// 好友id
	INT32		n_frival_;		// 友好度
};


//! 玩家各个级别所对应的基本属性及升到该级得到天资和升到下一级所需的经验增量 -- 从xml中读入
struct s_level_up_effect
{
	DWORD	dw_level_up_id_;	// 升级属性id 由职业和等级决定
	INT		n_exp_level_up_;	// 升到下一级所需的经验增量
	INT16	n_role_att_[10];	// 最大最小攻击 物理 魔法 道术
	//INT16	n16RoleAttAvail;	// 得到的可投属性点
	INT16	n_talent_avail_;	// 得到的可投天资点
	INT		n_hp_;				// 当前级别血量
	INT		n_mp_;				// 当前级别真气量
	INT		n_rating;			// 当前级别基础战力
	INT16	n_dummy_;

	s_level_up_effect() { ZeroMemory(this, sizeof(*this)); n_exp_level_up_ = INVALID_VALUE; }
};

//! 玩家一级属性对二级属性转换表
struct s_role_att_change
{
	DWORD	dw_id_;						//id 职业与一级属性的组合
	INT16	n_att_change_[earc_num];		//对应二级属性变化
};

//! 玩家脚本数据类型定义
enum e_role_script_data
{
	drsd_injury			=	0,				// 0用作内伤治疗状态
	drsd_end			=	100,
};

//! 进入地图限制
struct s_enter_map_limit
{
	DWORD				dw_map_id_;				// 地图ID
	DWORD				dw_enter_num_;			// 权值
	INT					e_enter_limit_;			// 副本条件
};


// 验证码
struct s_verification_code
{
	DWORD	dw_id;
	tstring	dw_code;
};

#define MAX_INST_DOOR_NUM	50
#define MAX_INST_CREATURE_NUM	1000

struct s_inst_door_state
{
	DWORD	dw_door_id;
	BOOL	b_open;
};
// ! 副本进度
struct s_inst_process
{
	DWORD	dw_map_id;						// 地图ID
	INT16	n_mode;						// 难度类型
	INT16	n_type;						// 副本类型
	s_inst_door_state st_door_state[MAX_INST_DOOR_NUM];		// 门进度
	DWORD	dw_creature_id[MAX_INST_CREATURE_NUM];	// 怪物进度
};

//! 心跳
struct NET_heartbeat : public tag_net_message
{  
	NET_heartbeat ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_heartbeat" ) ;
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dwGoldenCode;  // 服务器金色代码
	DWORD dwHeartbeat;   // 服务器心跳次数 
};  


struct NET_retification : public tag_net_message 
{   
	NET_retification ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_retification" ) ;
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_golden_code_;
	TCHAR sz_world_name_[X_SHORT_NAME];
};  

struct NET_DB2C_world_shutdown : public tag_net_message 
{   
	NET_DB2C_world_shutdown ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_world_shutdown" ) ;   
		dw_size = sizeof ( * this ) ;   
	}   
};  

struct NET_DB2S_world_shutdown : public tag_net_message 
{  
	NET_DB2S_world_shutdown ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_world_shutdown" ) ;
		dw_size = sizeof ( * this ) ;    
	} 
};  


struct NET_DB2C_load_all_role_info : public tag_net_message 
{   
	NET_DB2C_load_all_role_info ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_all_role_info" ) ;  
		dw_size = sizeof ( * this ) ;    
	}
};  

struct NET_DB2S_load_all_role_info : public tag_net_message
{  
	NET_DB2S_load_all_role_info ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_all_role_info" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_error_code;   
	INT32 n_count; 
	s_role_info role_info_[1];
};  

struct NET_DB2C_load_sim_role : public tag_net_message 
{   
	NET_DB2C_load_sim_role ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_sim_role" ) ;  
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_account_id; 
	CHAR sz_account[X_SHORT_NAME];
};  

struct NET_DB2S_load_simrole : public tag_net_message 
{  
	NET_DB2S_load_simrole ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_simrole" ) ; 
		dw_size = sizeof ( * this ) ;    
	} 
	DWORD dw_error_code;   
	DWORD dw_account_id;   
	INT32 n_count;  
	s_account_common s_account_common_;
	tagSimRole sim_role_[MAX_ROLENUM_ONEACCOUNT];  
};  

struct NET_DB2C_create_role : public tag_net_message 
{   
	NET_DB2C_create_role ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_create_role" ) ;   
		dw_size = sizeof ( * this ) ;    
	}   
	DWORD dw_account_id; 
	s_create_role_info s_role_info_;   
};  

struct NET_DB2S_create_role : public tag_net_message 
{  
	NET_DB2S_create_role ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2S_create_role" ) ;   
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_error_code;  
	DWORD dw_account_id;
	tagSimRole s_sim_role_;  
	s_role_info s_role_info_;  
};  

struct NET_DB2C_delete_role : public tag_net_message 
{   
	NET_DB2C_delete_role ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_role" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_account_id;  
	DWORD dw_role_id;
	DWORD dw_time;  
	TCHAR sz_role_name[X_SHORT_NAME]; 
	CHAR sz_ip[X_IP_LEN];  
};  


struct NET_DB2S_delete_role : public tag_net_message 
{   
	NET_DB2S_delete_role ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2S_delete_role" ) ;   
		dw_size = sizeof ( * this ) ;    
	} 
	DWORD dw_error_code; 
	DWORD dw_role_id;  
	DWORD dw_account_id;    
};  
//!
struct NET_DB2C_delete_role_guard_time_set : public tag_net_message 
{   
	NET_DB2C_delete_role_guard_time_set ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_role_guard_time_set" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_account_id;  
	DWORD dw_role_id;
	DWORD dw_delGuardTime;
}; 

struct NET_DB2S_delete_role_guard_time_set : public tag_net_message 
{   
	NET_DB2S_delete_role_guard_time_set ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_delete_role_guard_time_set" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_error_code;
	DWORD dw_account_id;  
	DWORD dw_role_id;
	DWORD dw_delGuardTime;
}; 


struct NET_DB2C_load_role : public tag_net_message 
{   
	NET_DB2C_load_role ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_role" ) ;  
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_account_id;
	DWORD dw_role_id;    
};  

//! 注意该消息结构大小需重新计算
struct NET_DB2S_load_role : public tag_net_message 
{   
	NET_DB2S_load_role ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_role" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_error_code; 
	DWORD dw_account_id;  
	DWORD dw_role_id; 
	s_role_data_load RoleData;   
};  

struct NET_DB2C_load_serial_reward : public tag_net_message
{
	NET_DB2C_load_serial_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_serial_reward");
		dw_size = sizeof(*this);
	}
	//DWORD dw_account_id;
	DWORD dw_role_id;
	CHAR sz_serial[X_SHORT_NAME];
};

struct NET_DB2S_load_serial_reward : public tag_net_message
{
	NET_DB2S_load_serial_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_serial_reward");
		dw_size = sizeof(*this);
	}
	/*DWORD dw_account_id;
	INT		n_num;
	BYTE by_data_[1];  */
	DWORD dw_role_id;
	BOOL b_exists;
	CHAR sz_serial[X_SHORT_NAME];
	INT	 n_type;
};


struct NET_DB2C_resume_role : public tag_net_message 
{ 
	NET_DB2C_resume_role ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_resume_role" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
};  


//! 注意该消息结构大小需重新计算
struct NET_DB2C_save_role : public tag_net_message
{  
	NET_DB2C_save_role ( ) 
	{
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_save_role" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;  
	s_role_data_save RoleData;
};  
//gx add 玩家新增奖励信息后，都要将所有奖励信息存数据库 2013.9.17
struct NET_DB2C_update_role_reward_data : public tag_net_message
{
	NET_DB2C_update_role_reward_data()
	{
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_role_reward_data" ) ; 
		dw_size = sizeof ( * this ) ; 
	}
	DWORD dw_role_id;
	BYTE  by_data[1];//tagRewardData
};
//end

//! 改名
struct NET_DB2C_change_role_name : public tag_net_message 
{   
	NET_DB2C_change_role_name ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_role_name" ) ; 
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_account_id; 
	DWORD dw_role_id; 
	DWORD dw_change_time;
	DWORD dw_name_crc;
	TCHAR sz_new_role_name[X_SHORT_NAME]; 
};  

struct NET_DB2S_change_role_name : public tag_net_message 
{   
	NET_DB2S_change_role_name ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_change_role_name" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_error_code;  
	DWORD dw_account_id;  
	DWORD dw_role_id; 
	DWORD dw_change_time;
	DWORD dw_name_crc;
	TCHAR sz_new_role_name[X_SHORT_NAME];  
}; 

//! 恢复删除保护
struct NET_DB2C_cancel_role_del_guard_time : public tag_net_message 
{   
	NET_DB2C_cancel_role_del_guard_time ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_cancel_role_del_guard_time" ) ; 
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_account_id; 
	DWORD dw_role_id; 
}; 

struct NET_DB2S_cancel_role_del_guard_time : public tag_net_message 
{   
	NET_DB2S_cancel_role_del_guard_time ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_cancel_role_del_guard_time" ) ; 
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_error;
	DWORD dw_role_id; 
	DWORD dw_account_id;
};  

//
struct NET_DB2C_change_role_guild : public tag_net_message 
{  
	NET_DB2C_change_role_guild ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_change_role_guild" ) ;   
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_role_id;  
	DWORD dw_guild_id;  
};  

struct NET_DB2C_change_role_leave_guild_time : public tag_net_message 
{  
	NET_DB2C_change_role_leave_guild_time ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_role_leave_guild_time" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;
	tagDWORDTime dw_leave_guild_time_;  
};  
//gx add 2013.8.14
struct NET_DB2C_change_role_VIP_Info:public tag_net_message
{
	NET_DB2C_change_role_VIP_Info ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_role_VIP_Info" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;
	INT16 n_VIP_Level;
	tagDWORDTime dw_VIP_deadline;  
};
struct NET_C2DB_clear_role_VIP_info:public tag_net_message
{
	NET_C2DB_clear_role_VIP_info ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_C2DB_clear_role_VIP_info" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;
};
struct NET_DB2C_insert_friend : public tag_net_message 
{  
	NET_DB2C_insert_friend ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_insert_friend" ) ;
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_role_id; 
	s_friend_save s_friend_save_;    
};  

struct NET_DB2C_delete_friend : public tag_net_message 
{  
	NET_DB2C_delete_friend ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_friend" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id; 
	DWORD dw_friend_id_;  
};  

struct NET_DB2C_update_friend : public tag_net_message 
{  
	NET_DB2C_update_friend ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_update_friend" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_role_id;  
	s_friend_save s_friend_save_; 
};  


//! 注意：向DBServer发送友好度相关消息时，应dw_role_id < dwFriendID
struct NET_DB2C_delete_frival : public tag_net_message 
{  
	NET_DB2C_delete_frival ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_delete_frival" ) ;   
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_role_id;  
	DWORD dw_friend_id_; 
};  


//! 删除角色时，删除数据库里所有相关好友信息
struct NET_DB2C_delete_all_friend : public tag_net_message 
{ 
	NET_DB2C_delete_all_friend ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_all_friend" ) ;
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_role_id;  
};  


//! 删除角色时，删除数据库里所有相关好友度信息
struct NET_DB2C_delete_all_friend_value : public tag_net_message 
{   
	NET_DB2C_delete_all_friend_value ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_all_friend_value" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_role_id;  
};  

struct NET_DB2C_insert_friend_value : public tag_net_message 
{   
	NET_DB2C_insert_friend_value ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_insert_friend_value" ) ; 
		dw_size = sizeof ( * this ) ; 
	}   
	DWORD dw_role_id;  
	s_friendship_save s_friendship_save_;
};  

struct NET_DB2C_update_friend_value : public tag_net_message 
{   
	NET_DB2C_update_friend_value ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_friend_value" ) ;
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_role_id; 
	s_friendship_save s_friendship_save_;    
};  

//CMD_START(NDBS_DeleteFriend)
//	DWORD		dw_error_code;
//	DWORD		dw_role_id;
//	DWORD		dwFriendID;
//CMD_END;


//! 黑名单
struct NET_DB2C_insert_black : public tag_net_message 
{  
	NET_DB2C_insert_black ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_insert_black" ) ;   
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_role_id; 
	DWORD dw_black_id_;  
};  

struct NET_DB2C_delete_black : public tag_net_message 
{   
	NET_DB2C_delete_black ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_delete_black" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_role_id;  
	DWORD dw_black_id_; 
};  

struct NET_DB2C_insert_enemy : public tag_net_message 
{  
	NET_DB2C_insert_enemy ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_insert_enemy" ) ;
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_role_id;
	DWORD dw_enemy_id_;  
};  

struct NET_DB2S_insert_enemy : public tag_net_message
{   
	NET_DB2S_insert_enemy ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_insert_enemy" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_error_code;
	DWORD dw_role_id;  
	DWORD dw_enemy_id_;  
};  

struct NET_DB2C_delete_enemy : public tag_net_message 
{   
	NET_DB2C_delete_enemy ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_enemy" ) ;
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_role_id;  
	DWORD dw_enemy_id_;   
};  

struct NET_DB2S_delete_enemy : public tag_net_message
{  
	NET_DB2S_delete_enemy ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_delete_enemy" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_error_code; 
	DWORD dw_role_id; 
	DWORD dw_enemy_id;    
};  


//! 百宝袋中有空位时,请求读取新物品消息
struct NET_DB2C_load_baibao : public tag_net_message 
{   
	NET_DB2C_load_baibao ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_baibao" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_account_id;  
	INT32 n_free_space_size_; 	// 百宝袋中空位数目
	INT64 n64_serial;  // 读取指定ID的物品(不指定设为INVALID_VALUE)
};  

struct NET_DB2S_load_baibao : public tag_net_message 
{  
	NET_DB2S_load_baibao ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_baibao" ) ;
		dw_size = sizeof ( * this ) ;    
	} 
	DWORD dw_error_code; 
	DWORD dw_account_id;  
	INT32 n_ret_num_; // 读取到的物品(装备)个数
	BYTE by_data_[SPACE_BAIBAO_BAG * sizeof(tagEquip)]; 
};  

// 获取网页领奖标志
struct NET_DB2C_load_web_receive : public tag_net_message
{
	NET_DB2C_load_web_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_web_receive");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
};

struct NET_DB2S_load_web_receive : public tag_net_message
{
	NET_DB2S_load_web_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_web_receive");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
	DWORD	dw_web_receive;
};


struct NET_DB2C_load_baibao_yuanbao : public tag_net_message 
{   
	NET_DB2C_load_baibao_yuanbao ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_load_baibao_yuanbao" ) ;   
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_account_id;  
	DWORD dw_recharge_num;
};  

struct NET_DB2S_load_baobao_yuanbao : public tag_net_message
{   
	NET_DB2S_load_baobao_yuanbao ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_baobao_yuanbao" ) ;  
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_account_id; 
	INT32 n_baibao_yaunbao_;   
}; 

struct NET_DB2C_update_yuanbao_recharge : public tag_net_message
{
	NET_DB2C_update_yuanbao_recharge()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_yuanbao_recharge");
		dw_size = sizeof(NET_DB2C_update_yuanbao_recharge);
	}
	DWORD	dw_account_id;
	INT32	n32_yuanbao;
};

struct NET_DB2C_update_total_recharge : public tag_net_message
{
	NET_DB2C_update_total_recharge()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_total_recharge");
		dw_size = sizeof(*this);
	}

	DWORD		dw_account_id;
	INT32		n32_yuanbao;
};

//! 请求读取百宝袋历史记录
struct NET_DB2C_load_baobao_log : public tag_net_message 
{  
	NET_DB2C_load_baobao_log ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_baobao_log" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_account_id; 
};  

struct NET_DB2S_load_baibao_log : public tag_net_message
{   
	NET_DB2S_load_baibao_log ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2S_load_baibao_log" ) ; 
		dw_size = sizeof ( * this ) ; 
	}
	DWORD dw_error_code; 
	DWORD dw_account_id;  
	INT32 n_log_num_;  // 读取到的记录条数
	BYTE by_data_[1];    // Log记录数据
};  

//! 请求追加一条记录
struct NET_DB2C_add_baibao_log : public tag_net_message 
{   
	NET_DB2C_add_baibao_log ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_add_baibao_log" ) ;   
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_account_id; 
	tagBaiBaoRecord log_info_;  
};  

struct NET_DB2C_load_item_need_log : public tag_net_message
{  
	NET_DB2C_load_item_need_log ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_item_need_log" ) ;  
		dw_size = sizeof ( * this ) ; 
	} 
};  

struct NET_DB2S_load_item_need_log : public tag_net_message
{   
	NET_DB2S_load_item_need_log ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_item_need_log" ) ;   
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_error_code;  
	INT32 n_item_num; 
	s_need_log_item	sNeedLogItem[MAX_ITEM_NEEDLOG_NUM];
	//DWORD dw_data_id[MAX_ITEM_NEEDLOG_NUM];   
};  


//! GameServer向DBServer发送的初始化完成的确认消息	
struct NET_DB2C_world_init_ok : public tag_net_message
{  
	NET_DB2C_world_init_ok ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_world_init_ok" ) ;   
		dw_size = sizeof ( * this ) ; 
	}
};  

struct NET_DB2S_world_init_ok : public tag_net_message 
{  
	NET_DB2S_world_init_ok ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_world_init_ok" ) ; 
		dw_size = sizeof ( * this ) ;   
	}    
};  

struct NET_DB2C_clear_role_dress_mdid : public tag_net_message 
{  
	NET_DB2C_clear_role_dress_mdid ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_clear_role_dress_mdid" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_role_id;  
	WORD w_new_val;  
};  

//! 读取物品&装备(压力测试用)
struct NET_DB2C_test_load_role_item : public tag_net_message
{  
	NET_DB2C_test_load_role_item ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_test_load_role_item" ) ;
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_account_id;   
	DWORD dw_role_id;     
};  

struct NET_DB2C_test_load_role : public tag_net_message
{   
	NET_DB2C_test_load_role ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_test_load_role" ) ;  
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_account_id;  
	DWORD dw_role_id;    
};  

//!	开启宝箱计数相关
struct NET_DB2C_update_treasure_sum : public tag_net_message 
{   
	NET_DB2C_update_treasure_sum ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_update_treasure_sum" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_role_id;
	INT n_sum_;    
};  

struct NET_DB2S_update_treasure_sum : public tag_net_message 
{   
	NET_DB2S_update_treasure_sum ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_update_treasure_sum" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;   
	INT n_sum_;   
};  

//! 保存玩家经验
struct NET_DB2C_update_role_att : public tag_net_message
{   
	NET_DB2C_update_role_att ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_role_att" ) ;
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;
	INT n_type_; 
	INT n_value_;
};  

//! 清空人物离线经验
struct NET_DB2C_clean_role_leave_exp : public tag_net_message 
{  
	NET_DB2C_clean_role_leave_exp ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_clean_role_leave_exp" ) ;
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_role_id;
};  

//! 清空人物离线义气
struct NET_DB2C_clean_role_leave_brother : public tag_net_message 
{  
	NET_DB2C_clean_role_leave_brother ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_clean_role_leave_brother" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id;  
};  

//! 清空挂机次数
struct NET_DB2C_clean_role_hang_num : public tag_net_message 
{   
	NET_DB2C_clean_role_hang_num ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_clean_role_hang_num" ) ; 
		dw_size = sizeof ( * this ) ; 
	}    
};  
// 清空元宝兑换次数
struct NET_DB2C_clean_role_yuanbao_exchange_num : public tag_net_message
{
	NET_DB2C_clean_role_yuanbao_exchange_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_clean_role_yuanbao_exchange_num");
		dw_size = sizeof(*this);
	}
};
//! 清空配偶信息 gx add 2013.7.3
struct NET_C2DB_clean_role_spouse_id : public tag_net_message 
{   
	NET_C2DB_clean_role_spouse_id ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_C2DB_clean_role_spouse_id" ) ; 
		dw_size = sizeof ( * this ) ; 
	}    
	DWORD dw_role_id; 
};
//! 清空拍卖次数
struct NET_C2DB_CleanRolePaiMaiNum : public tag_net_message
{
	NET_C2DB_CleanRolePaiMaiNum()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_CleanRolePaiMaiNum");
		dw_size = sizeof(NET_C2DB_CleanRolePaiMaiNum);
	}
};

//！清空签到数据
struct NET_C2DB_clean_role_sign_data : public tag_net_message
{
	NET_C2DB_clean_role_sign_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_sign_data");
		dw_size = sizeof(*this);
	}
};

//! 清空幸运值
struct NET_C2DB_clean_role_luck : public tag_net_message
{
	NET_C2DB_clean_role_luck()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_luck");
		dw_size = sizeof(NET_C2DB_clean_role_luck);
	}

};

//! 增加环随机刷新次数
struct NET_C2DB_UpdateCircleRefreshNumberAndQuestNum : public tag_net_message
{
	NET_C2DB_UpdateCircleRefreshNumberAndQuestNum()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_UpdateCircleRefreshNumberAndQuestNum");
		dw_size = sizeof(*this);
	}

	INT nDelta;
	INT nPerDayNum;
	INT nRefreshMax;
};


//! 清空摧毁装备次数
struct NET_C2DB_clean_role_destroy_equip_count : public tag_net_message
{
	NET_C2DB_clean_role_destroy_equip_count()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_destroy_equip_count");
		dw_size = sizeof(NET_C2DB_clean_role_destroy_equip_count);
	}

};


//! 清空钱庄拍卖次数
struct NET_C2DB_clean_role_bank_num : public tag_net_message
{
	NET_C2DB_clean_role_bank_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_bank_num");
		dw_size = sizeof(NET_C2DB_clean_role_bank_num);
	}
};

// 清空战功商店购买次数
struct NET_C2DB_clean_role_exploits_num : public tag_net_message
{
	NET_C2DB_clean_role_exploits_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_exploits_num");
		dw_size = sizeof(*this);
	}
};

// 清除活跃度数据
struct NET_C2DB_clean_role_active_data : public tag_net_message
{
	NET_C2DB_clean_role_active_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_active_data");
		dw_size = sizeof(*this);
	}
};

// 清除每日清零数据
struct NET_C2DB_clean_role_day : public tag_net_message
{
	NET_C2DB_clean_role_day()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_day");
		dw_size = sizeof(*this);
	}
};


// 清除每日清零数据
struct NET_C2DB_reset_role_value_at_0 : public tag_net_message
{
	NET_C2DB_reset_role_value_at_0()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_reset_role_value_at_0");
		dw_size = sizeof(*this);
	}
	INT nPerDayHangGetExpTimeMS;
	INT nCoolDownReviveCD;
};

// 清除在线奖励数据
struct NET_C2DB_reset_role_online_reward : public tag_net_message
{
	NET_C2DB_reset_role_online_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_reset_role_online_reward");
		dw_size = sizeof(*this);
	}

	DWORD	dw_gift_id_;								// 礼物ID
	DWORD	dw_gift_leave_time_;						// 剩余时间

};

//! 更新每日1v1积分
struct NET_C2DB_update_day_1v1_score : public tag_net_message
{
	NET_C2DB_update_day_1v1_score()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_update_day_1v1_score");
		dw_size = sizeof(NET_C2DB_update_day_1v1_score);
	}
};

// !更新1v1周积分
struct NET_C2DB_update_week_1v1_score : public tag_net_message
{
	NET_C2DB_update_week_1v1_score()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_update_week_1v1_score");
		dw_size = sizeof(*this);
	}
};

// ! 更新1v1领奖标志
struct NET_C2DB_update_1v1_award : public tag_net_message
{
	NET_C2DB_update_1v1_award()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_update_1v1_award");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	INT16	n16_award;
};

// 更新噬魂
struct NET_C2DB_update_shihun : public tag_net_message
{
	NET_C2DB_update_shihun()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_update_shihun");
		dw_size = sizeof(*this);
	}
};

//! 保存玩家属性点
struct NET_DB2C_update_role_att_point : public tag_net_message 
{   
	NET_DB2C_update_role_att_point ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_role_att_point" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_role_id;
	INT n_att_point_add_[X_ERA_ATTA_NUM];   
	INT n_att_point_left_;    
};  

//! 保存玩家天资点
struct NET_DB2C_update_role_talent_point : public tag_net_message 
{   
	NET_DB2C_update_role_talent_point ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_role_talent_point" ) ;
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_role_id;
	tagRoleTalent s_talent_; 
	INT n_index_;  
	INT n_talent_point_;  
};  

//! 清除玩家地图限制
struct NET_DB2C_delete_role_map_limit : public tag_net_message 
{  
	NET_DB2C_delete_role_map_limit ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_role_map_limit" ) ;
		dw_size = sizeof ( * this ) ;   
	}   
	INT n_type;  
};  

// 清除玩家副本进度
struct NET_DB2C_delete_role_map_process : public tag_net_message
{
	NET_DB2C_delete_role_map_process()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_delete_role_map_process");
		dw_size = sizeof(*this);
	}
	INT n_type;
};

//! 移除玩家地图限制
struct NET_DB2C_remove_role_map_limit : public tag_net_message 
{  
	NET_DB2C_remove_role_map_limit ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_remove_role_map_limit" ) ; 
		dw_size = sizeof ( * this ) ; 
	}   
	DWORD dw_role_id; 
};  

struct NET_DB2C_insert_role_map_limit : public tag_net_message 
{ 
	NET_DB2C_insert_role_map_limit ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_insert_role_map_limit" ) ;   
		dw_size = sizeof ( * this ) ;   
	}   DWORD dw_role_id;  
	s_enter_map_limit st_enter_map_limit_;     
};  


//! 增加技能
struct NET_DB2C_add_skill : public tag_net_message 
{   
	NET_DB2C_add_skill ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_add_skill" ) ;
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_role_id;  
	s_skill_save s_skill_;  
};  

//! 保存技能
struct NET_DB2C_update_skill : public tag_net_message 
{  
	NET_DB2C_update_skill ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_skill" ) ;  
		dw_size = sizeof ( * this ) ; 
	}   
	DWORD dw_role_id;  
	s_skill_save s_skill_;  
};  


//! 删除技能
struct NET_DB2C_remove_skill : public tag_net_message 
{ 
	NET_DB2C_remove_skill ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_remove_skill" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id;  
	DWORD dw_skill_id;  
};  

// 重置玩家元气值
struct NET_DB2C_reset_vigour : public tag_net_message
{
	NET_DB2C_reset_vigour ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_reset_vigour" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
};

// 更新角色竞技积分
struct NET_DB2C_update_role_1v1_score : public tag_net_message
{
	NET_DB2C_update_role_1v1_score()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_role_1v1_score");
		dw_size = sizeof(*this);
	}

	DWORD	dw_role_id;
	INT		nScroe;
	INT		nJoinNum;
};

// 更新离线角色竞技积分
struct NET_DB2C_update_noline_role_1v1_score : public tag_net_message
{
	NET_DB2C_update_noline_role_1v1_score()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_noline_role_1v1_score");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	INT		nScore;
};

// 更新坐骑数据
struct NET_DB2C_update_mounts : public tag_net_message
{
	NET_DB2C_update_mounts()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_mounts");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	s_mounts_save sMounts;
};
#pragma pack(pop)
