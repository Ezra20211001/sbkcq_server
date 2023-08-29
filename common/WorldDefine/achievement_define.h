/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/



#ifndef _ACHIEVEMENT_H_
#define _ACHIEVEMENT_H_


#pragma pack(push, 1)
//-----------------------------------------------------------------------------
// 触发事件
//-----------------------------------------------------------------------------
enum e_achievement_event
{	
	ete_null						=-1,
	ete_begin						=0 ,	

	ete_kill_monster				=0 ,	// 击杀特定怪物
	//m_dwPara1		怪物id		
	//m_dwPara2		数量			
	ete_kill_role					=1 ,	// 击杀角色
	//m_dwPara1			
	//m_dwPara2		数量	
	ete_quest_complete				=2 ,	// 完成任务
	//m_dwPara1		任务id		
	//m_dwPara2		数量	
	ete_role_die					=3 ,	// 角色死亡
	//m_dwPara1				
	//m_dwPara2		次数	
	ete_role_skilled_by_role		=4 ,	// 角色被其他角色击杀
	//m_dwPara1			
	//m_dwPara2		次数	
	ete_role_level					=5,		// 角色达到级别
	//m_dwPara1			
	//m_dwPara2		级数	
	ete_composite_equip_success		=6 ,	// 合成装备成功
	//m_dwPara1		品质		
	//m_dwPara2		次数
	ete_use_item					=7,		// 角色使用道具
	//m_dwPara1		道具id		
	//m_dwPara2		次数
	ete_use_skill					=8,		// 角色使用技能
	//m_dwPara1		技能id		
	//m_dwPara2		次数
	ete_composite_achievement		=9,		// 完成成就
	//m_dwPara1		成就id				
	//m_dwPara2		
	ete_decomposite_three_seven		=10,	// 拆分出3个7
	//m_dwPara1						
	//m_dwPara2		次数
	eta_decomposite_feil			=11,	// 拆分出3个哭脸
	//m_dwPara1						
	//m_dwPara2		次数
	eta_decomposite_equip			=12,	// 拆分装备
	//m_dwPara1						
	//m_dwPara2		次数
	eta_skill_level_up				=13,	// 技能升级
	//m_dwPara1		技能id				
	//m_dwPara2		等级
	eta_fish_sucess					=14,	// 钓鱼成功
	//m_dwPara1						
	//m_dwPara2		次数
	eta_fish_field					=15,	// 钓鱼失败
	//m_dwPara1						
	//m_dwPara2		次数
	eta_roborn						=16,	// 复活
	//m_dwPara1		类型	0 完美原地 1 普通原地 2 完美回程 3 普通回城	4 冷却复活				
	//m_dwPara2		次数
	eta_add_friend					=17,	// 添加好友
	//m_dwPara1		
	//m_dwPara2		好友数量
	eta_send_mail					=18,	// 发送邮件
	//m_dwPara1		
	//m_dwPara2		数量
	eta_receive_mail				=19,	// 收到邮件
	//m_dwPara1		
	//m_dwPara2		数量
	eta_use_decree					=20,	// 昭告天下
	//m_dwPara1		
	//m_dwPara2		次数
	eta_use_world					=21,	// 世界频道
	//m_dwPara1		
	//m_dwPara2		次数
	eta_win_sice					=22,	// 骰子获胜
	//m_dwPara1		
	//m_dwPara2		次数
	eta_win_sice_yibai				=23,	// 骰子获胜 100 点
	//m_dwPara1		
	//m_dwPara2		次数
	eta_combat_miss					=24,	// 未命中
	//m_dwPara1		
	//m_dwPara2		次数
	eta_combat_dodge				=25,	// 闪躲
	//m_dwPara1		
	//m_dwPara2		次数
	eta_combat_crit					=26,	// 暴击
	//m_dwPara1		
	//m_dwPara2		次数
	eta_produce_item				=27,	// 炼丹
	//m_dwPara1		物品id
	//m_dwPara2		个数
	eta_bind_equip					=28,	// 绑定石绑定装备
	//m_dwPara1		
	//m_dwPara2		个数
	eta_unbind_equip_npc			=29,	// npc绑定
	//m_dwPara1		
	//m_dwPara2		个数
	eta_unbind_equip				=30,	// 解绑石
	//m_dwPara1		
	//m_dwPara2		个数
	eta_baitan_sell					=31,	// 摆摊卖出
	//m_dwPara1		
	//m_dwPara2		数量
	eta_exchange					=32,	// 交易成功
	//m_dwPara1		
	//m_dwPara2		次数
	eta_extendbag					=33,	// 扩从包裹
	//m_dwPara1		0 背包 1仓库
	//m_dwPara2		扩充到多少
	eta_bank_buy_success			=34,	// 钱庄购买成功
	//m_dwPara1		0 游戏币 1 元宝
	//m_dwPara2		数量
	eta_bank_sell_success			=35,	// 钱庄拍卖成功
	//m_dwPara1		0 游戏币 1 元宝
	//m_dwPara2		数量
	eta_paimai_buy_success			=36,	// 拍卖行购买成功
	//m_dwPara1		
	//m_dwPara2		数量
	eta_paimai_sell_success			=37,	// 拍卖行拍卖成功
	//m_dwPara1		
	//m_dwPara2		数量
	eta_paimai_sell_fail			=38,	// 拍卖行拍卖失败
	//m_dwPara1		
	//m_dwPara2		数量
	eta_duel_win					=39,	// 切磋胜利
	//m_dwPara1		
	//m_dwPara2		数量
	eta_duel_lost					=40,	// 切磋失败
	//m_dwPara1		
	//m_dwPara2		数量
	eta_duel						=41,	// 切磋
	//m_dwPara1		
	//m_dwPara2		数量
	eta_chisel						=42,	// 打孔
	//m_dwPara1		
	//m_dwPara2		孔数
	eta_inlay						=43,	// 镶嵌
	//m_dwPara1		
	//m_dwPara2		次数
	eta_pet_level					=44,	// 宠物升级
	//m_dwPara1		
	//m_dwPara2		等级
	ete_strengthen_weapon_success_2 =45,	// 强化2阶武器
	//m_dwPara1		
	//m_dwPara2		星级
	ete_strengthen_weapon_success_3	=46,	// 强化3阶武器
	//m_dwPara1		
	//m_dwPara2		星级
	ete_strengthen_weapon_success_4 =47,	// 强化4阶武器
	//m_dwPara1		
	//m_dwPara2		星级
	ete_strengthen_armor_success_2  =48,	// 强化2阶防具
	//m_dwPara1		
	//m_dwPara2		星级
	ete_strengthen_armor_success_3	=49,	// 强化3阶防具
	//m_dwPara1		
	//m_dwPara2		星级
	ete_strengthen_armor_success_4  =50,	// 强化4阶防具
	//m_dwPara1		
	//m_dwPara2		星级
	ete_strengthen_weapon_success_4_fail =51,	// 强化4阶武器失败
	//m_dwPara1		
	//m_dwPara2		次数
	ete_strengthen_armor_success_4_fail =52,	// 强化4阶防具失败
	//m_dwPara1		
	//m_dwPara2		次数
	eta_be_kill_monster					=53,	// 被怪物杀死
	//m_dwPara1		怪物id		
	//m_dwPara2		次数
	eta_load_baobao_yuanbao				=54,	// 冲元宝
	//m_dwPara1				
	//m_dwPara2		数量
	ete_strengthen_ride_success			=55,	// 坐骑强化
	//m_dwPara1		
	//m_dwPara2		星级
	ete_strengthen_ride_fail			=56,	// 坐骑强化失败
	//m_dwPara1		最低星级
	//m_dwPara2		次数
	ete_xiangqian_ride					=57,	// 坐骑镶嵌
	//m_dwPara1		
	//m_dwPara2		个数
	ete_xiulian							=58,	// 修炼武器
	//m_dwPara1		
	//m_dwPara2		等级
	ete_produce_equip_up_quality		=59,	// 使用打造提升品质几率物品
	//m_dwPara1		物品id
	//m_dwPara2		数量
	ete_consolidate_up_pro				=60,	// 使用强化提升几率物品
	//m_dwPara1		物品id
	//m_dwPara2		数量
	ete_into_area						=61,	// 进入区域
	//m_dwPara1		区域id
	//m_dwPara2		次数
	ete_graduates_num					=62,	// 出师人数达到
	//m_dwPara1		
	//m_dwPara2		数量
	ete_title_num						=63,	// 获得称号
	//m_dwPara1		
	//m_dwPara2		数量
	ete_strengthen_armor_success		=64,	// 强化防具到
	//m_dwPara1		
	//m_dwPara2		星数
	ete_fusion_equip					=65,	// 融合武器
	//m_dwPara1		
	//m_dwPara2		次数
	ete_set_bag_password				=66,	// 修改超级密码
	//m_dwPara1		
	//m_dwPara2		次数
	ete_join_guild						=67,	// 加入帮会
	//m_dwPara1		
	//m_dwPara2		次数
	ete_reatt_equip						=68,	// 洗装备属性
	//m_dwPara1		
	//m_dwPara2		次数
	ete_delete_item						=69,	// 摧毁装备
	//m_dwPara1		
	//m_dwPara2		次数	
	ete_make_master						=70,	// 拜师成功
	//m_dwPara1		
	//m_dwPara2		次数	
	ete_make_prentice					=71,	// 收徒成功
	//m_dwPara1		
	//m_dwPara2		次数	
	ete_into_prison						=72,	// 进监狱
	//m_dwPara1		
	//m_dwPara2		次数	
	ete_kill_red_role					=73,	// 杀红名玩家
	//m_dwPara1		
	//m_dwPara2		次数	
	ete_PKValue							=74,	// 罪恶值达到
	//m_dwPara1		
	//m_dwPara2		值
	ete_add_item						=75,	// 获得道具
	//m_dwPara1		id
	//m_dwPara2		数量
	ete_inlay_repeat					=76,	// 覆盖镶嵌
	//m_dwPara1		
	//m_dwPara2		次数
	ete_inlay_level						=77,	// 镶嵌高级宝石
	//m_dwPara1		宝石最低需求装备等级	
	//m_dwPara2		次数
	eta_use_common						=78,	// 普通频道
	//m_dwPara1		
	//m_dwPara2		次数
	eta_use_secret						=79,	// 密语频道
	//m_dwPara1		
	//m_dwPara2		次数
	eta_use_map							=80,	// 区域频道
	//m_dwPara1		
	//m_dwPara2		次数
	eta_use_team						=81,	// 队伍频道
	//m_dwPara1		
	//m_dwPara2		次数
	eta_use_guild						=82,	// 帮派频道
	//m_dwPara1		
	//m_dwPara2		次数
	eta_incbagsilver					=83,	// 获得金钱
	//m_dwPara1		
	//m_dwPara2		数量(不能超过4000G)
	eta_incbagbindsilver				=84,	// 获得绑定金钱
	//m_dwPara1		
	//m_dwPara2		数量(不能超过4000G)
	eta_decbagsilver					=85,	// 失去金钱
	//m_dwPara1		
	//m_dwPara2		数量(不能超过4000G)
	eta_decbagbindsilver				=86,	// 失去绑定金钱
	//m_dwPara1		
	//m_dwPara2		数量(不能超过4000G)
	eta_increase_contribution			=87,	// 获得帮贡
	//m_dwPara1		
	//m_dwPara2		数量
	eta_decrease_contribution			=88,	// 消费帮贡
	//m_dwPara1		
	//m_dwPara2		数量
	eta_loop_rand_quest					=89,	// 完成环随机
	//m_dwPara1		
	//m_dwPara2		次数
	eta_prentice_breakwith_master		=90,	// 徒弟脱离师父
	//m_dwPara1		
	//m_dwPara2		次数
	eta_master_fire_prentice			=91,	// 师父赶走徒弟
	//m_dwPara1		
	//m_dwPara2		次数
	eta_join_team						=92,	// 加入队伍
	//m_dwPara1		
	//m_dwPara2		次数
	eta_produce_item_fail				=93,	// 炼金失败
	//m_dwPara1		
	//m_dwPara2		次数
	eta_produce_item_bai				=94,	// 炼金百分百成功
	//m_dwPara1		
	//m_dwPara2		次数
	eta_produce_item_crit				=95,	// 炼金暴击
	//m_dwPara1		
	//m_dwPara2		次数
	eta_shipin_fumo						=96,	// 饰品附魔
	//m_dwPara1		
	//m_dwPara2		次数
	eta_shipin_fumo_crit				=97,	// 饰品附魔暴击
	//m_dwPara1		
	//m_dwPara2		次数
	eta_unbeset							=98,	// 拆嵌
	//m_dwPara1		
	//m_dwPara2		次数
	eta_unbind_equip_npc_all			=99,	// npc全身绑定
	//m_dwPara1		
	//m_dwPara2		次数
	eta_equip_xili						=100,	// 洗礼
	//m_dwPara1		类型	 0 所有 1 战功 2 2紫金币 3 10紫金币
	//m_dwPara2		次数
	eta_equip_reatt						=101,	// 属性重置
	//m_dwPara1		类型	 0  1  2  
	//m_dwPara2		次数
	eta_equip_qianghua_success			=102,	// 强化成功
	//m_dwPara1		 
	//m_dwPara2		次数
	eta_equip_qianghua_arm_fail			=103,	// 强化防具失败
	//m_dwPara1		 
	//m_dwPara2		次数
	eta_equip_xiuli						=104,	// 修理装备
	//m_dwPara1		 
	//m_dwPara2		次数
	ete_strengthen_ride					=105,	// 坐骑强化
	//m_dwPara1		
	//m_dwPara2		次数
	ete_xiangqian_ride_item				=106,	// 坐骑镶嵌某道具
	//m_dwPara1		道具id
	//m_dwPara2		个数
	ete_pet_paiqian						=107,	// 派遣宠物
	//m_dwPara1		
	//m_dwPara2		次数
	ete_pet_ranse						=108,	// 宠物染色
	//m_dwPara1		
	//m_dwPara2		次数
	ete_pet_have_quality				=109,	// 拥有宠物品级
	//m_dwPara1		
	//m_dwPara2		品级
	eta_pet_to_level					=110,	// 宠物升到等级多少次
	//m_dwPara1		等级
	//m_dwPara2		次数
	eta_guild_plant_tou					=111,	// 偷菜
	//m_dwPara1		
	//m_dwPara2		次数
	eta_stall_start						=112,	// 摆摊
	//m_dwPara1		
	//m_dwPara2		次数
	eta_stall_buy						=113,	// 摆摊买东西
	//m_dwPara1		
	//m_dwPara2		次数
	eta_paimai_jingpai					=114,	// 拍卖竞拍
	//m_dwPara1		
	//m_dwPara2		次数
	eta_bank_jingpai					=115,	// 钱庄竞拍
	//m_dwPara1		
	//m_dwPara2		次数
	eta_guild_cailiao					=116,	// 工会捐材料
	//m_dwPara1		
	//m_dwPara2		数量
	eta_guild_zijin						=117,	// 工会捐钱
	//m_dwPara1		
	//m_dwPara2		数量
	eta_equip_kaiguang					=118,	// 开光
	//m_dwPara1		0  1级 1  2级
	//m_dwPara2		次数
	eta_equip_kaiguang_get_nai			=119,	// 开光获得耐力
	//m_dwPara1		0  1级 1  2级
	//m_dwPara2		多少
	eta_equip_clear_talent				=120,	// 重置武器天赋
	//m_dwPara1		
	//m_dwPara2		次数
	eta_refresh_circle_quest			=121,	// 刷新区域赏金任务
	//m_dwPara1		
	//m_dwPara2		次数
	eta_SetShareLeaderCircleQuest		=122,	// 以队长的身份激活魔物赏金任务
	//m_dwPara1		
	//m_dwPara2		次数
	eta_quest_xuanshan_get				=123,	// 接取悬赏任务
	//m_dwPara1		
	//m_dwPara2		次数
	eta_quest_xuanshan_put				=124,	// 发布悬赏任务
	//m_dwPara1		
	//m_dwPara2		次数
	ete_kill_role_level					=125 ,	// 击杀特定等级角色
	//m_dwPara1		等级	
	//m_dwPara2		数量	
	ete_kill_role_class					=126 ,	// 击杀特定职业角色
	//m_dwPara1		职业
	//m_dwPara2		数量	
	ete_have_prentice					=127 ,	// 拥有徒弟
	//m_dwPara1		
	//m_dwPara2		数量	
	ete_1v1_win							=128 ,	// 竞技场获胜
	//m_dwPara1		
	//m_dwPara2		次数
	ete_1v1_lost						=129 ,	// 竞技场失败
	//m_dwPara1		
	//m_dwPara2		次数	
	ete_rank_pos						=130 ,	// 某种排行榜名次达到
	//m_dwPara1		0 人物等级榜 1 恶人排行榜 2 正义排行榜 3 1v1排行榜 4 噬魂排行榜 5 成就点数榜 6 成就数量榜
	//m_dwPara2		排名	
	ete_1v1_win_class					=131 ,	// 竞技场获胜某职业
	//m_dwPara1		职业
	//m_dwPara2		次数
	ete_1v1_win_level					=132 ,	// 竞技场赢了等级大于自己XX级的对手
	//m_dwPara1		等级差
	//m_dwPara2		次数
	eta_unbeset_level					=133 ,	// 拆嵌xx级宝石
	//m_dwPara1		最低镶嵌等级
	//m_dwPara2		次数
	ete_delete_item_level				=134,	// 摧毁xx等级装备
	//m_dwPara1		最低等级
	//m_dwPara2		次数	
	ete_chushi							=135,	// 出师
	//m_dwPara1		
	//m_dwPara2		次数	
	ete_duel_class						=136 ,	// 切磋获胜某职业
	//m_dwPara1		职业
	//m_dwPara2		次数
	ete_duel_level						=137 ,	// 切磋赢了等级大于自己XX级的对手
	//m_dwPara1		等级差
	//m_dwPara2		次数
	eta_team_rand_share_quest			=138,	// 完成魔物赏金任务
	//m_dwPara1		
	//m_dwPara2		次数
	eta_huoyue_yibai					=139,	// 领取100点活跃度(脚本判断的)
	//m_dwPara1		
	//m_dwPara2		次数
	eta_getwuhuen_yibai					=140,	// 100比例的武器神魂提取
	//m_dwPara1		
	//m_dwPara2		次数
	eta_shipin_fumo_level				=141,	// 饰品附魔到XX级
	//m_dwPara1		
	//m_dwPara2		等级
	ete_kill_role_level_sub				=142,	// 杀低于自己XX级的玩家
	//m_dwPara1		等级差
	//m_dwPara2		次数
	ete_title_get						=143,	// 获得称号
	//m_dwPara1		称号id
	//m_dwPara2		数量

	ete_max_event_num,					// 事件数目
	ete_end								=ete_max_event_num,
};


//-----------------------------------------------------------------------------
// 称号条件类型
//-----------------------------------------------------------------------------
enum e_condition_type
{
	ect_count						= 0,	// 计数条件
	ect_value						= 1,	// 阈值条件
	ect_check						= 2,	// 特殊检查条件
};

// 成就所属纹章
enum e_achievement_signet
{
	eas_chuanqi = 0,		// 传奇
	eas_war,				// 战争
	eas_zanmei,				// 赞美
	eas_tianqi,				// 天启
	eas_totle,				// 总

	eas_number
};

//-----------------------------------------------------------------------------
// 成就原型
//-----------------------------------------------------------------------------
struct AchievementEntry
{
	DWORD				m_ID;
	DWORD				m_refAchievement;			// 对应成就ID,有的成就条件是完成其他成就
	UINT32				m_point;					// 成就点数
	e_achievement_signet m_signet;					// 所属纹章
	UINT32				m_count;					// 需要完成的条件数量
	DWORD				m_nTitleID;					// 获得称号id
};

// 成就条件
struct AchievementCriteriaEntry
{
	DWORD				m_ID;                                          
	DWORD				m_referredAchievement;    // 对应成就id             					

	e_condition_type 	m_CondType;				// 条件类型
	e_achievement_event	m_Events;				// 事件类型

	DWORD				m_dwPara1;
	DWORD				m_dwPara2;

	DWORD				m_dwTimeLimit;			// 时间限制(多长时间内完成)
};

// 进行中的条件
struct CriteriaProgress
{
	DWORD	m_ID; 
	DWORD	m_date;					// 时间
	DWORD	m_counter;				// 计数
	bool	m_changed;				// 是否改变,记录数据库用
	bool	m_bTimedCriteriaFailed;	//是否已经超时
};


// 已完成的成就
struct CompletedAchievementData
{
	DWORD	m_ID; 
	DWORD	m_date;			// 时间
	bool	m_changed;		// 是否改变,记录数据库用
};


class AchievementHelper
{
public:
	// 获取对应纹章等级
	static INT GetSignetLevel(e_achievement_signet eType, INT nComplateNum)
	{
		switch (eType)
		{
		case eas_chuanqi:
			break;
		case eas_war:
			break;
		case eas_zanmei:
			break;
		case eas_tianqi:
			break;
		case eas_totle:
			break;
		default:
			break;
		}
		if(nComplateNum < 20)
			return 1;
		else if(nComplateNum >= 20 && nComplateNum < 50)
			return 2;
		else if(nComplateNum >= 50 && nComplateNum < 90)
			return 3;
		else if(nComplateNum >= 90 && nComplateNum < 140)
			return 4;
		else if(nComplateNum >= 140 && nComplateNum < 200)
			return 5;
		else if(nComplateNum >= 200)
			return 6;
		else
			return 1;
	}

	//通过等级取得最大点数
	static INT GetMaxPoint(INT nLevel)
	{
		if(nLevel == 1)
		{
			return 20;
		}
		else if(nLevel == 2)
		{
			return 50;
		}
		else if(nLevel == 3)
		{
			return 90;
		}
		else if(nLevel == 4)
		{
			return 140;
		}
		else if(nLevel == 5)
		{
			return 200;
		}
		else if(nLevel == 6)
		{
			return 500;
		}
		return 10;
	}

	// 获取成就纹章等级
	static INT GetAchievementLevel(INT nAchievementNum)
	{
		if (nAchievementNum >= 620)
		{
			return 6;
		}
		if (nAchievementNum >= 430)
		{
			return 5;
		}
		if (nAchievementNum >= 280)
		{
			return 4;
		}
		if (nAchievementNum >= 160)
		{
			return 3;
		}
		if (nAchievementNum >= 60)
		{
			return 2;
		}
		return 1;
	}

	// 获取当前等级最大值
	static INT GetMaxNumByLevel(INT nLevel)
	{
		if (nLevel == 1)
		{
			return 60;
		}
		if (nLevel == 2)
		{
			return 160;
		}
		if (nLevel == 3)
		{
			return 280;
		}
		if (nLevel == 4)
		{
			return 430;
		}
		if (nLevel == 5)
		{
			return 620;
		}
		if (nLevel == 6)
		{
			return 1000;
		}
		return 60;
	}
};
#pragma pack(pop)


#endif