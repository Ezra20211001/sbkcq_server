
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//服务器记录log用的网络命令代码枚举

#pragma once

#pragma pack(push, 1)
//-----------------------------------------------------------------------------
// log用网络消息枚举 -- 一旦定义了最好不要修改(1.数据库已有相应记录；2.脚本可能已写死)
//-----------------------------------------------------------------------------
enum e_log_cmd_id
{
	elcid_null					= 0,	// 无

	// 商店相关
	elcid_shop_buy_item			= 1,	// 买物品(非装备)
	elcid_shop_buy_equip		= 2,	// 买装备
	elcid_shop_sell				= 3,	// 卖物品&装备
	
	// 技能消耗
	elcid_skill					= 5,	// 使用技能
	// PK保护相关
	elcid_open_safe_guard		= 11,	// 开启PK保护

	// 死亡惩罚
	elcid_dead_penalty			= 12,	// PK惩罚

	// 百宝袋相关
	elcid_baibao_load_from_db	= 20,	// 从item_baibao表中读取的物品
	elcid_baibao_bill_yuanbao	= 21,	// 元宝直冲

	// 行囊相关
	elcid_bag_pos_overlap		= 30,	// 初始化角色背包时，发现物品位置重叠

	// 洗点
	elcid_clear_att				= 40,	// 洗属性点
	elcid_clear_talent			= 41,	// 洗天资点


	// 角色仓库相关
	elcid_ware_pos_overlap		= 50,	// 初始化角色仓库时，发现物品位置重叠
	elcid_ware_save_silver		= 51,	// 存钱
	//elcid_ware_save_yuanbao		= 52,	// 存元宝
	elcid_ware_get_silver		= 53,	// 取钱
	elcid_ware_get_yuanbao		= 54,	// 取元宝

	// 商城
	elcid_mall_buy_item			= 60,	// 购买商城物品
	elcid_mall_buy_pack			= 61,	// 购买商城礼品包
	elcid_mall_free_item		= 62,	// 领取商城免费物品
	elcid_mall_buy_item_add		= 63,	// 购买商城物品时附带
	elcid_mall_buy_pack_add		= 64,	// 购买商城礼品包时附带
	elcid_mall_present_item		= 65,	// 赠送商城物品
	elcid_mall_present_pack		= 66,	// 赠送商城礼品包
	elcid_mall_present_item_add	= 67,	// 赠送商城物品时附带
	elcid_mall_present_pack_add	= 68,	// 赠送商城礼品包时附带

	// 元宝交易
	elcid_trade_save_yuanbao	= 70,	// 向交易账户存元宝
	elcid_trade_save_silver		= 71,	// 向交易账户存金钱
	elcid_trade_depossit_yuanbao= 72,	// 从交易账户取出元宝
	elcid_trade_deposit_silver	= 73,	// 从交易账户取出金钱
	elcid_trade_tax				= 74,	// 提交订单时扣除手续费
	elcid_trade_buy_lovevalue	= 75,	// 购买爱心值	
	// 商城 - 续
	elcid_mall_exchange_item	= 80,	// 兑换商城物品
	elcid_mall_exchange_pack	= 81,	// 兑换商城礼品包
	elcid_mall_exchange_item_add= 82,	// 兑换商城物品时附带
	elcid_mall_exchange_pack_add= 83,	// 兑换商城礼品包时附带

	// 团购
	elcid_group_purchase_faild		= 90,	// 团购失败返还所得 gx modify 结婚相关 2013.7.3
	elcid_group_purchase_buy_item	= 91,	// 团购购买商城物品
	elcid_group_purchase_buy_item_add= 92,	// 团购商城物品附带

	// 任务相关
	elcid_quest_loot			= 100,	// 任务掉落
	elcid_quest_complete		= 101,	// 完成任务
	elcid_quest_accept			= 102,	// 接取任务
	elcid_quest_discard			= 103,	// 放弃任务
	elcid_quest_rewards			= 104,  // 任务奖励
	elcid_buy_circle			= 105,  // 购买环随机任务

	// 装备强化相关
	elcid_compose_posy			= 150,	// 铭文
	elcid_compose_engrave		= 151,	// 绑定
	elcid_compose_enchase		= 152,	// 镶嵌
	elcid_compose_prictice		= 153,	// 武器修炼
	elcid_compose_reatt			= 154,	// 属性重置
	elcid_compose_produce		= 155,	// 合成
	elcid_compose_quench		= 156,	// 淬火
	elcid_compose_decompose		= 157,	// 点化,装备分解
	elcid_compose_chisel		= 158,	// 开凿
	elcid_compose_fusion		= 159,	// 武器融合
	elcid_compose_xili			= 130,	// 装备洗礼
	elcid_compose_tiqu			= 131,	// 提取武魂

	// 玩家间交易
	elcid_exchange_verify		= 160,	// 交易确认
	
	// gp商城
	elcid_exchange_lottey		= 170,	// 彩票机
	elcid_exchange_treasure		= 171,	//含概率性质的宝箱的开启消耗 gx add 2013.12.11

	// 原地复活
	elcid_revive_locus			= 180,
	elcid_revive_perfection		= 181,
	elcid_revive_return_city	= 182,

	// 摆摊
	elcid_stall_besold			= 190,	// 摆摊卖出
	elcid_stall_buy				= 191,	// 从摊位上购买

	// 换场景
	elcid_dak					= 200,

	// 物品
	elcid_item_use				= 300,	// 物品使用
	elcid_item_move				= 301,	// 同一容器内移动
	elcid_item_move_to_other	= 302,	// 不同容器间移动

	elcid_item_at_term			= 310,	// 有时限物品，到期删除

	// 装备
	elcid_equip_identify		= 350,	// 装备鉴定
	elcid_equip_reget			= 351,	// 装备恢复
	elcid_equip_newness_lost	= 352,	// 耐久度为0掉落

	// 新手
	elcid_first_online_item		= 380,	// 新手发放

	// 玩家吃从背包扔掉物品
	elcid_role_discard_item		= 401,

	// 玩家拾取物品
	elcid_pickup_item			= 402,
	elcid_pickup_money			= 403,

	// 给好友送礼物
	elcid_send_gift				= 410,

	// 礼品包
	elcid_gift_bag				= 420,

	// 职能NPC相关
	elcid_bag_extend			= 450,	// 扩充背包
	elcid_ware_extend			= 451,	// 角色仓库扩充
	elcid_cure_injure			= 452,	// npc治疗内伤
	
	// 普通掉落
	elcid_loot					= 500,	// 普通掉落

	// 帮派相关
	elcid_guild_create			= 600,	// 创建帮派
	elcid_guild_upgrade			= 601,	// 帮派设施升级
	elcid_guild_spread_affair	= 602,	// 发布帮务
	elcid_guild_daily_cost		= 603,	// 日常消耗
	elcid_guild_skill_research	= 604,	// 帮派技能升级
	elcid_guild_skill_learn		= 605,	// 学习帮派技能
	elcid_guild_commerce		= 606,	// 跑商
	elcid_guild_declarewar		= 607,	// 帮会宣战
	elcid_guild_trans			= 608,	// 帮会地图传送
	elcid_guild_win_war			= 609,	// 帮会战奖励
	elcid_guild_inc_fund		= 610,	// 帮会资金冲入
	elcid_guild_materimal		= 611,  // 材料回收

	// 聊天相关
	elcid_chat_world_channel		= 700,	//在世界频道发言
	elcid_show_equip_world_channel	= 701,	//在世界频道展示装备
	elcid_show_item_world_channel	= 702,	//在世界频道展示物品
	elcid_talk_decree				= 703,	//传音使用IM道具

	// 宠物相关
	elcid_pet_item_create_pet		= 800,	// 生成宠物
	elcid_pet_item_feed_pet			= 801,	// 宠物喂食
	elcid_pet_item_pet_learnskill	= 802,	// 宠物学习技能
	elcid_pet_item_pet_revive		= 803,	// 宠物复活
	elcid_pet_item_pet_equip		= 804,	// 宠物装备
	elcid_role_pour_exp_pet			= 805,	// 灌注经验
	elcid_pet_item_pet_enhance		= 806,	// 宠物装备
	elcid_pet_item_pet_lock			= 807,	// 宠物锁定
	elcid_pet_item_pet_unlock		= 808,	// 宠物解锁
	elcid_pet_item_pet_food			= 809,	// 宠物食物
	elcid_pet_item_pet_spe			= 810,	// 宠物特殊道具
	elcid_pet_color					= 811,	// 宠物染色
	elcid_pet_item_fusion			= 812,	// 宠物融合	
	elcid_pet_size_change			= 813,  // 宠物栏扩充
	elcid_pet_xiulian_size_change	= 814,  // 宠物寄养栏扩充
	elcid_pet_xiulian				= 815,  // 宠物寄养

	// 氏族相关
	elcid_act_treasure				= 900,	// 激活氏族珍宝获得

	//固定活动相关
	elcid_wu_se_shi					= 1000, // 固定活动删除五色石
	elcid_pvp						= 1001, // pvp固定活动

	// VIP摊位相关
	elcid_vip_stall_rent			= 1100,	// VIP摊位租赁

	// vip网吧
	elcid_vip_netbar				= 1200,	// vip网吧
	
	elcid_npc_repair				= 1201, //装备维修
	elcid_npc_hole					= 1202, //装备打孔
	elcid_npc_unbeset				= 1203, //装备拆嵌
	elcid_npc_shengxin				= 1204,	//装备升星
	elcid_guild_delate				= 1205,	//帮会弹劾
	elcid_npc_fusion				= 1206,	//武器融合
	elcid_npc_inlay					= 1207,	//镶嵌
	elcid_npc_daomo					= 1208, //打磨

	elcid_npc_mail					= 1212, //邮件

	elcid_gdquest_putout			= 1300, //发布悬赏任务
	elcid_xsquest_accept			= 1301, //接取悬赏任务

	elcid_upgrade_ride				= 1302, //强化坐骑
	elcid_remove_ride_inlay			= 1303,	//坐骑打磨
	elcid_riad_inlay				= 1304, //坐骑镶嵌

	elcid_call_in_master			= 1305, //召请师傅

	//学习技能
	elcid_learn_skill				= 1400, //学习技能

	elcid_leave_hang				= 1401,	// 离线挂机

	// PK惩罚
	elcid_pk_penalty				= 1501, //PK惩罚

	// 新手在线奖励
	elcid_new_role_gift				= 1502,	// 新手在线奖励

	// 拍卖物品
	elcid_paimai_item				= 1503,	// 拍卖物品

	// 钱庄
	elcid_bank						= 1504,	// 钱庄拍卖

	// 脚本
	elcid_script					= 1505,	// 脚本

	// 钓鱼
	elcid_fishing					=	1506, // 钓鱼

	// 副本
	elcid_instance					=	1507,	// 副本

	// 元宝兑换
	elcid_bank_exchange				=	1508,	// 元宝兑换

	// 挂机
	elcid_hang						=	1509,	// 挂机

	// 装备销毁
	elcid_equip_destroy				=	1510,	// 装备销毁

	// 补偿元宝
	elcid_compensate_yuanbao		=	1511,	// 赔偿元宝

	// 礼包元宝
	elcid_pack_yuanbao				=	1512,	// 礼包元宝

	// 1v1竞技场
	elcid_1v1						=	1513,	// 1v1竞技场

	// 约战竞技场
	elcid_reservation				=	1514,	// 约战竞技场

	// 改名字
	elcid_changename				=	1600,	// 角色更名
	

	// 离线修炼
	elci_leave_pracitce				=	1515,	// 离线修炼

	// 活跃度
	elci_active						=	1516,	// 活跃度
	
	// 踢人相关
	elci_kick_role_vercation		=	1600,	// 验证码踢人
	elci_kick_role_move_fast		=	1601,	// 移动太快

	// 副本进度重置
	elci_process					=	1602,	// 重置副本进度

	// 副本权值重置
	elci_inst_limit					=	1603,	// 重置副本权值

	elci_kick_role_move_fast1		=	1604,	// 移动太快
	// 签到
	elci_sign						=	1605,	// 签到

	// 买灵气
	elci_buy_lingqi					=	1606,
	
	// 混炼
	elci_huenlian					=	1607,

	elci_kick_role_move_fast2		=	1608,	// 移动太快

	elci_KillBadage					=	1701,	//通缉某人

	

	// 脚本加的元宝
	elcid_script_add_yuanbao_1		=	3000,	// 帮会BOSS元宝奖励

	// 其他相关在此处之上加
	
	// GM命令
	elcid_gm_clear_bag				= 1000000,	// 清理背包
	elcid_gm_create_item			= 1000001,	// 创建物品/装备/时装
	elcid_gm_get_money				= 1000002,	// 获得金钱
	elcid_gm_get_yuanbao			= 1000003,	// 获得元宝
	elcid_gm_get_exvolume			= 1000004,	// 获得赠点
	elcid_gm_getfund				= 1000005,	// 获得帮派资金
	elcid_gm_get_material			= 1000006,	// 获得帮派资材
	elcid_gm_get_contribute			= 1000007,	// 获得帮派个人贡献
};


struct s_log_silver				// 金钱变化
{
	DWORD	dw_account_id;
	DWORD	dw_role_id;
	DWORD	dw_cmd_id;
	DWORD	dw_role_id_rel;
	INT64	n64_silver;			// +：获得；-：失去
	INT64	n64_total_silver;	// 对应容器中总量
	INT8	n8_log_con_type;	// 背包，仓库
};

struct s_log_yuanbao			// 元宝变化
{
	DWORD	dw_account_id;
	DWORD	dw_role_id;
	DWORD	dw_cmd_id;
	DWORD	dw_role_id_rel;
	INT		n_yuanbao;			// +：获得；-：失去
	INT		n_total_yuanbao;	// 对应容器中总量
	INT8	n8_log_con_type;	// 背包，百宝袋
};

struct s_log_ex_volume			// 赠点变化
{
	DWORD	dw_account_id;
	DWORD	dw_role_id;
	DWORD	dw_cmd_id;
	INT		n_ex_volume;		// +：获得；-：失去
	INT		n_total_ex_volume;	// 对应容器中总量
};

struct s_log_exploits	// 战功变化
{
	DWORD dw_account_id;
	DWORD dw_role_id;
	DWORD dw_cmd_id;
	INT32 n_exploits;
	INT32 n_total_exploits;
};

struct s_log_time_stat			// 在线玩家定时统计
{
	DWORD	dw_account_id;
	DWORD	dw_role_id;
	INT64	n64_bag_silver;
	INT64	n64_ware_silver;
	INT		n_bag_yuanbao;
	INT		n_baibao_yuanbao;
	INT		n_ex_volume;
};

// 需要记log物品的结构
struct s_need_log_item
{
	DWORD	dw_data_id;
	BYTE	by_quality;
};


struct s_log_item				// 物品log结构
{
	DWORD		dw_role_id;
	DWORD		dw_data_id;

	INT64		n64_serial1;
	INT64		n64_serial2;
	INT8		n8_con_type1;
	INT8		n8_con_type2;
	INT16		n16_res_num1;
	INT16		n16_res_num2;

	INT16		n16_opt_num;		// 变化个数(+：表示获得；-：表示失去)
	DWORD		dw_cmd_id;
	DWORD		dw_role_id_rel;
};

struct s_log_mall_sell			// 商城出售物品log结构
{
	INT64		n64_serial;
	DWORD		dw_data_id;
	DWORD		dw_role_id;		// 购买者
	DWORD		dw_to_role_id;		// 获得物品者
	DWORD		dw_first_gain_time;
	DWORD		dw_exist_item;
	INT			n_max_use_times;
	INT			n_cost_yuanbao;
	INT			n_cost_ex_volume;
	DWORD		dw_cmd_id;
	INT16		n16_num_sell;
};

struct s_log_mall_sell_pack		// 商城出售礼品包log结构
{
	DWORD		dw_pack_id;
	DWORD		dw_buy_role_id;
	DWORD		dw_to_role_id;
	INT			n_cost_yuanbao;
};

struct s_log_item_times			// 物品使用次数log结构
{
	DWORD		dw_role_id;
	DWORD		dw_cmd_id;

	INT64		n64_serial;
	DWORD		dw_data_id;
	INT			n_used_times;
	INT			n_max_use_times;
	INT8		n8_con_type;
};

struct tagLogFund
{
	DWORD		dw_guild_id;
	DWORD		dw_account_id;
	DWORD		dw_role_id;
	DWORD		dw_cmd_id;

	INT			n_fund;
	INT			n_total_funk;
};

struct tagLogMaterial
{
	DWORD		dw_guild_id;
	DWORD		dw_account_id;
	DWORD		dw_role_id;
	DWORD		dw_cmd_id;

	INT			n_material;
	INT			n_total_material;
};

struct tagLogReputation
{
	DWORD		dw_guild_id;
	DWORD		dw_account_id;
	DWORD		dw_role_id;
	DWORD		dw_cmd_id;

	INT			n_reputation;
	INT			n_total_reputation;
};

struct tagLogGMCmd
{
	DWORD		dw_role_id;
	TCHAR		sz_gm_cmd[LONG_STRING];
	DWORD		dw_error_code;
};

struct tagLogBank
{
	DWORD dw_sell_id;
	DWORD dw_buy_id;
	DWORD dw_bidup_id;
	BYTE  by_type;
	DWORD dw_bidup;
	DWORD dw_chaw;
	DWORD dw_sell;
};

struct tagLogPaimai
{
	INT64	n64_serial;
	DWORD	dw_sell_id;
	DWORD	dw_buy_id;
	DWORD	dw_bidup_id;
	DWORD	dw_bidup;
	DWORD	dw_chaw;
};

struct tagLogLeavePractice
{
	DWORD	dw_role_id;
	DWORD	dw_drop_love;
	DWORD	dw_cur_love;
};

struct tagLogSerialReward
{
	DWORD	dw_account_id;
	INT		n_type;
	CHAR	sz_serial[X_SHORT_NAME];
};

struct tagLogReward
{
	DWORD dw_account_id;
	DWORD dw_role_id;
	DWORD dw_type;
};

struct tagKickRole
{
	DWORD dw_account_id;
	DWORD dw_role_id;
	DWORD dw_cmd_id;
};

struct tagLotteryLog
{
	DWORD dw_account_id;
	DWORD dw_role_id;
	DWORD dw_item_id;
	DWORD dw_type;
	DWORD dw_index;
};
//! 金钱变化
struct NET_DB2C_log_silver : public tag_net_message 
{  
	NET_DB2C_log_silver ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_log_silver" ) ;
		dw_size = sizeof ( * this ) ;    
	}  
	s_log_silver s_log_silver_;  
};  

//! 元宝变化
struct NET_DB2C_log_yuanbao : public tag_net_message 
{  
	NET_DB2C_log_yuanbao ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_log_yuanbao" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	s_log_yuanbao s_log_yuanbao_; 
};  

//! 赠点变化
struct NET_DB2C_log_exvolume : public tag_net_message 
{ 
	NET_DB2C_log_exvolume ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_log_exvolume" ) ;  
		dw_size = sizeof ( * this ) ;     
	}   
	s_log_ex_volume s_log_ex_volume_;   
};  

//! 战功变化
struct NET_DB2C_log_exploits : public tag_net_message
{
	NET_DB2C_log_exploits()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_exploits");
		dw_size = sizeof(*this);
	}
	s_log_exploits s_log_exploits;
};

//! 定时统计
struct NET_DB2C_log_time_stat : public tag_net_message 
{  
	NET_DB2C_log_time_stat ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_log_time_stat" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	s_log_time_stat s_log_times_stat_; 
};  


//! 物品log
struct NET_DB2C_log_item : public tag_net_message
{ 
	NET_DB2C_log_item ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_log_item" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	s_log_item s_log_item_;    
};  

//! 物品log
struct NET_DB2C_log_item_times : public tag_net_message 
{  
	NET_DB2C_log_item_times ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_log_item_times" ) ;  
		dw_size = sizeof ( * this ) ;  
	}
	s_log_item_times s_log_item_times_;  
};  



//! 商城出售物品log
struct NET_DB2C_log_mall_sell : public tag_net_message 
{   
	NET_DB2C_log_mall_sell ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_log_mall_sell" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	s_log_mall_sell s_log_mall_sell_;   
};  


//! 商城出售礼品包log
struct NET_DB2C_log_mall_sell_pack : public tag_net_message
{  
	NET_DB2C_log_mall_sell_pack ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_log_mall_sell_pack" ) ;   
		dw_size = sizeof ( * this ) ;
	}  
	s_log_mall_sell_pack s_log_mall_sell_pack_; 
};  


//! 帮派LOG记录
struct NET_DB2C_log_fund : public tag_net_message
{  
	NET_DB2C_log_fund ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_log_fund" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	tagLogFund s_log_fund_; 
};  

struct NET_DB2C_log_material : public tag_net_message 
{  
	NET_DB2C_log_material ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_log_material" ) ; 
		dw_size = sizeof ( * this ) ;
	}   
	tagLogMaterial s_log_material_;  
};  

struct NET_DB2C_log_reputation : public tag_net_message
{   
	NET_DB2C_log_reputation ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_log_reputation" ) ;   
		dw_size = sizeof ( * this ) ; 
	}  
	tagLogReputation s_log_reputation_;    
};  

//! 帮派LOG记录
struct NET_DB2C_log_gm_cmd : public tag_net_message 
{ 
	NET_DB2C_log_gm_cmd ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_log_gm_cmd" ) ;   
		dw_size = sizeof ( * this ) ; 
	} 
	tagLogGMCmd s_log_gm_cmd_;  
};  

// 钱庄log
struct NET_DB2C_log_bank : public tag_net_message
{
	NET_DB2C_log_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_bank");
		dw_size = sizeof(*this);
	}
	tagLogBank s_log_bank;
};

// 拍卖log
struct NET_DB2C_log_paimai : public tag_net_message
{
	NET_DB2C_log_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_paimai");
		dw_size = sizeof(*this);
	}
	tagLogPaimai s_log_paimai;
};

// 离线修炼log
struct NET_DB2C_log_leave_practice : public tag_net_message
{
	NET_DB2C_log_leave_practice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_leave_practice");
		dw_size = sizeof(*this);
	}
	tagLogLeavePractice s_log_leave_pracitce;
};

// 序列号礼包LOG
struct NET_DB2C_log_serial_reward : public tag_net_message
{
	NET_DB2C_log_serial_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_serial_reward");
		dw_size = sizeof(*this);
	}
	tagLogSerialReward s_log_serial_reward;
};

// 礼包log
struct NET_DB2C_log_reward : public tag_net_message
{
	NET_DB2C_log_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_reward");
		dw_size = sizeof(*this);
	}

	tagLogReward s_log_reward;
};
// 踢人log
struct NET_DB2C_log_kick : public tag_net_message
{
	NET_DB2C_log_kick()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_kick");
		dw_size = sizeof(*this);
	}
	tagKickRole s_log_kick;
};

// 彩票log
struct NET_DB2C_log_lottery : public tag_net_message
{
	NET_DB2C_log_lottery()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_lottery");
		dw_size = sizeof(*this);
	}
	tagLotteryLog s_log;
};

// 更新在线人数
struct NET_DB2C_update_online_num : public tag_net_message
{
	NET_DB2C_update_online_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_online_num");
		dw_size = sizeof(*this);
	}
	CHAR szName[X_SHORT_NAME];
	INT	nNum;
};
//-----------------------------------------------------------------------------
#pragma pack(pop)
