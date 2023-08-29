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
*	@file		map_protocol.h
*	@author		lc
*	@date		2011/03/08	initial
*	@version	0.0.1.0
*	@brief		地图消息
*/

#ifndef MAP_PROTOCOL
#define MAP_PROTOCOL

#define ALARM_40		1
#define ALARM_50		2
#define ALARM_60		3	

#define QUEUE_1V1_YUANBAO	10
#define QUEUE_1V1_DAY_JOINE_NUM		15


#include "protocol_common_errorcode.h"
#include "guild_define.h"

#pragma pack(push, 1)

enum
{
	E_BindRebornMap_NPCInvalid	=	1,	// 职能NPC非法
	E_BindRebornMap_MapInvalid	=	2,	// 地图非法（不是普通地图）
	E_BindRebornMap_Already		=	3,	// 已经绑定在该地图
	E_BindRebornMap_NPCNotFound	=	4,	// 没有找到指定的NPC
	E_BindRebornMap_TooFar		=	5,	// 距离太远

	E_Instance_Not_Exit			=	11,	// 副本不存在
	E_Instance_Role_Not_Exit	=	12,	// 玩家不存在
	E_Instance_Role_Full		=	13,	// 副本人数已到上限
	E_Instance_Level_Down_Limit =	14,	// 副本最低等级限制
	E_Instance_Level_Up_Limit	=	15,	// 副本最高等级限制
	E_Instance_Not_Same_Team	=	16,	// 不是同一小队
	E_Instance_Role_Lack		=	17,	// 副本人数未到下限
	E_Instance_End_Delete		=	18,	// 副本已经结束或者已经关闭
	E_Instance_Already			=	19,	// 已经创建了其它副本
	E_Instance_Full				=	20,	// 副本创建数量已满
	E_Instance_Not_Same_Guild   =   21, // 不是本帮派成员不能进副本
	E_Instance_GuildUp			=   22, // 帮派正在升级中
	E_Instance_Guild_NotFormal  =   23, // 不是正式家族
	E_Instance_Not_Enemy_Guild  =   24,	// 不是战斗敌对帮会
	E_Instance_Prepare_NoMap	=   25, // 准备战斗状态不能进入帮会副本
	E_Instance_Lobby_Repair		=   26, // 不能进入或人数满了
	E_Instance_Act_NoBegin		=   27, // 正在帮会战中
	E_Instance_NoGuild			=   28,	// 没有帮会
	E_Instance_EnterNum_Limit	=	29,	// 进入次数限制

	E_Instance_not_teamleader	=   30,	// 不是队长不能重置副本
	E_Instance_not_process		=   31,	// 没有副本进度
	E_Instance_not_normal		=	32, // 不是普通副本不能重置
	E_Instance_have_role		=   33, // 副本中有人不能重置
	E_Instance_diff_error		=   34,	// 副本难度不同
	E_Instance_team_error		=   35,	// 组队中不能进入其他副本
	E_Instance_not_item			=   36, // 没有钥匙不能进入副本
	E_Instance_RedName			=	37, // 红名不能进入副本
	E_Instance_have_online_team =   38, // 有队员离线不能重置副本
	E_Instance_process_yuanbao_limit	=	39,		// 副本进度重置元宝不足

	E_Instance_limit_not_exists		=	40,	// 副本权值不存在
	E_Instance_limit_yb_limit		=	41,	// 重置副本权值元宝不足

	E_Instance_pvp_level_limit	=	50,	// 进入混战副本等级不足
	E_Instance_pvp_map_limit	=	51,	// 在副本中不能进入
	E_Instance_pvp_money_limit	=	52,	// 进入PvP金钱不足
	E_Instance_pvp_state_limit	=	53,	// pvp状态限制
	E_Instance_pvp_in_guild_war	=	54,	// 正在帮会战

	E_Instance_1v1_have_apply	=	60,	// 已经在申请列表中
	E_Instance_1v1_state_limit	=	61,	// 人物状态限制
	E_Instance_1v1_map_limit	=	62,	// 人物地图限制
	E_Instance_1v1_level_limit	=	63, // 人物等级限制
	E_Instance_1v1_yuanbao_limit=	64,	// 元宝不足
	E_Instance_1v1_nohane_apply	=	65,	// 不在申请列表中
	E_Instance_1v1_no_start		=	66,	// 1v1未开启
	E_Instance_1v1_no_have_award	= 67, // 没有1v1奖励
	E_Instance_1v1_Is_guild_war	=	68,	// 正在帮会战

	E_Instance_reservation_level_limit	=	70, // 约战等级不足
	E_Instance_reservation_state_limit	=	71,	// 约战状态限制
	E_Instance_reservation_map_limit	=	72,	// 约战地图限制
	E_Instance_have_reservation			=	73,	// 已经在约战中
	E_Instance_beservation_no_line		=	74,	// 约战对象不在线
	E_Instance_reservation_yuanbao_limit=	75, // 约战人元宝不足
	E_Instance_bereservation_state_limit=	76,	// 被约战人状态限制
	E_Instance_bereservation_yuanbao_limit	=	77,	// 被约战人元宝不足
	E_Instance_bereservation_have_1v1_apply	=	78,	// 被约战人已经在申请列表中
	E_Instance_reservation_time_limit		=	79,	// 约战超时
	E_Instance_reservation_role_error		=	80,	// 约战对象错误
	E_Instance_bereservation_map_limit		=	81,	// 被约战人地图限制

	E_Active_NotEnough						=	82,	// 活跃度不足
	E_Active_repeat_receive					=	83,	// 活跃库奖励重复领取		
	E_Instance_is_guild_war					=	84,	// 有一方在帮会战中


	// 镇妖塔错误码
	E_Instance_Single_saodanging			=	100,// 扫荡中不能进入
	E_Instance_Single_qianzhinot			=	101,// 前置没打通		
	E_Instance_Single_EnterMax				=	102,// 当天进入次数上限
	// 镇妖塔扫荡错误码
	E_Instance_Saodang_nopass				=	103,// 要扫荡的副本还没有挑战通过
	E_Instance_Saodang_full					=	104,// 今日扫荡的次数已满
	E_Instance_Saodang_ing					=	105,// 正在进行扫荡中

	E_Instance_pvp_biwu_level_limit	=	110,	// 进入比武副本等级不足
	E_Instance_pvp_biwu_active_not_started	=	111,	// 比武活动未开始
	E_Instance_pvp_biwu_active_is_started	=	112,	// 比武活动已经开始

};

struct tagNPCLoading
{
	DWORD		dw_npc_id;
	DWORD		dw_Obj_id;
};

struct tag1v1
{
	DWORD	dw_role_id[2];
	DWORD	dw_instance_id;
	BOOL	b_delete;
	DWORD	dw_yuanbao;

	tag1v1()
	{
		memset(dw_role_id, INVALID_VALUE, sizeof(dw_role_id));
		dw_instance_id = INVALID_VALUE;
		b_delete = FALSE;
		dw_yuanbao = 0;
	}
};

//------------------------------------------------------------------------------
// 踩到地图触发器
//------------------------------------------------------------------------------
struct NET_SIC_role_map_trigger : public tag_net_message
{
	NET_SIC_role_map_trigger()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_map_trigger");
		dw_size = sizeof(NET_SIC_role_map_trigger);
	}
	DWORD	dwTriggerID;
	DWORD	dwMisc;			// 如果是普通或随机副本，代表副本难度；
};

//------------------------------------------------------------------------------
// 副本限制信息
//------------------------------------------------------------------------------
struct NET_SIS_instance_limit_info : public tag_net_message
{
	NET_SIS_instance_limit_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_instance_limit_info");
		dw_size = sizeof(*this);
	}
	DWORD		dw_enter_num;
	DWORD		dw_max_enter_num;
};


//------------------------------------------------------------------------------
// 进入副本
//------------------------------------------------------------------------------
struct NET_SIS_enter_instance : public tag_net_message
{
	NET_SIS_enter_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_enter_instance");
		dw_size = sizeof(NET_SIS_enter_instance);
	}
	DWORD	dwTimeLimit;	// 时限副本所剩时间，单位是秒( 非时限副本为INVALID_VALUE）
	//DWORD	dwGuildSymbol;		// 帮会标志
	//TCHAR	szText[2];			// 帮会标志文字
	//INT		n_family_name[NPC_NAME_NUM];		// 帮会npc姓
	//INT		n_name[NPC_NAME_NUM];				// 帮会npc名
	DWORD	dw_error_code;
};


//------------------------------------------------------------------------------
//离开副本
//------------------------------------------------------------------------------
struct NET_SIS_leave_instance : public tag_net_message
{
	NET_SIS_leave_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_leave_instance");
		dw_size = sizeof(NET_SIS_leave_instance);
	}
	INT		nType;		// 1.副本进度完成
};


//-----------------------------------------------------------------------------
// 去新地图
//-----------------------------------------------------------------------------
struct NET_SIS_goto_new_map : public tag_net_message
{
	NET_SIS_goto_new_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_goto_new_map");
		dw_size = sizeof(NET_SIS_goto_new_map);
	}
	DWORD	dwMapID;
	//int		nX;
	//int		nY;
	//int		nDirX;
	//int		nDirY;
	Vector3	pos;
	Vector3	faceTo;
};


//-----------------------------------------------------------------------------
// 通知本地玩家是否召唤队友
//-----------------------------------------------------------------------------
struct NET_SIS_instance_nofity : public tag_net_message
{
	NET_SIS_instance_nofity()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_instance_nofity");
		dw_size = sizeof(NET_SIS_instance_nofity);
	}
};

struct NET_SIC_instance_notify : public tag_net_message
{
	NET_SIC_instance_notify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_instance_notify");
		dw_size = sizeof(NET_SIC_instance_notify);
	}
	bool	bNotify;
};


//-----------------------------------------------------------------------------
// 通知所有队友是否进入副本
//-----------------------------------------------------------------------------
struct NET_SIS_instance_agree : public tag_net_message
{
	NET_SIS_instance_agree()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_instance_agree");
		dw_size = sizeof(NET_SIS_instance_agree);
	}
	DWORD   dwInviterID;
	DWORD	dwMapID;
	DWORD	dwMisc;
};

struct NET_SIC_instance_agree : public tag_net_message
{
	NET_SIC_instance_agree()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_instance_agree");
		dw_size = sizeof(NET_SIC_instance_agree);
	}
	bool	bAgree;
};


//-----------------------------------------------------------------------------
// 副本完成条件达成
//-----------------------------------------------------------------------------
struct NET_SIS_instance_complete : public tag_net_message
{
	NET_SIS_instance_complete()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_instance_complete");
		dw_size = sizeof(NET_SIS_instance_complete);
	}
};


//-----------------------------------------------------------------------------
// 请求离开副本
//-----------------------------------------------------------------------------
struct NET_SIC_leave_instance : public tag_net_message
{	
	NET_SIC_leave_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_instance");
		dw_size = sizeof(NET_SIC_leave_instance);
	}
};


//-----------------------------------------------------------------------------
// 同步副本倒计时
//-----------------------------------------------------------------------------
struct NET_SIS_synchronize_instance_time : public tag_net_message
{
	NET_SIS_synchronize_instance_time()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_instance_time");
		dw_size = sizeof(NET_SIS_synchronize_instance_time);
	}
	DWORD	dwTimeLeft;			// 副本剩余时间：单位毫秒
};

//-----------------------------------------------------------------------------
// 绑定复活点
//-----------------------------------------------------------------------------
struct NET_SIC_bind_reborn_map : public tag_net_message
{
	NET_SIC_bind_reborn_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_bind_reborn_map");
		dw_size = sizeof(NET_SIC_bind_reborn_map);
	}
	DWORD	dwNPCID;		// 职能NPCID
};

struct NET_SIS_bind_reborn_map : public tag_net_message
{
	NET_SIS_bind_reborn_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bind_reborn_map");
		dw_size = sizeof(NET_SIS_bind_reborn_map);
	}
	DWORD	dw_error_code;
	DWORD	dwBornMapID;
	Vector3	vBornPos;
};


//-----------------------------------------------------------------------------
// 客户端加载完成
//-----------------------------------------------------------------------------
struct NET_SIC_load_complete : public tag_net_message
{
	NET_SIC_load_complete()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_load_complete");
		dw_size = sizeof(NET_SIC_load_complete);
	}
};

//-----------------------------------------------------------------------------
// 重置副本进度
//-----------------------------------------------------------------------------
struct NET_SIC_reset_instance : public tag_net_message
{
	NET_SIC_reset_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reset_instance");
		dw_size = sizeof(NET_SIC_reset_instance);
	}

	DWORD	dw_map_id;			// 地图id
	INT		n_mode;				// 地图难度
};

struct NET_SIS_reset_instance : public tag_net_message
{
	NET_SIS_reset_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reset_instance");
		dw_size = sizeof(NET_SIS_reset_instance);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// 重置副本权值
//-----------------------------------------------------------------------------
struct NET_SIC_reset_instance_limit : public tag_net_message
{
	NET_SIC_reset_instance_limit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reset_instance_limit");
		dw_size = sizeof(*this);
	}

	DWORD	dw_map_id;
};

struct NET_SIS_reset_instance_limit : public tag_net_message
{
	NET_SIS_reset_instance_limit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reset_instance_limit");
		dw_size = sizeof(*this);
	}

	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// 服务器关闭倒计时
//-----------------------------------------------------------------------------
struct NET_SIS_ShutDown_Time : public tag_net_message
{
	NET_SIS_ShutDown_Time()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_ShutDown_Time");
		dw_size = sizeof(*this);
	}
	INT nTime;
};

//-----------------------------------------------------------------------------
// 预加载NPC
//-----------------------------------------------------------------------------
struct NET_SIS_NPC_Loading : public tag_net_message
{
	NET_SIS_NPC_Loading()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_NPC_Loading");
		dw_size = sizeof(*this);
	}

	INT32	n32_num;
	tagNPCLoading	st_NPCLoading[1];

};

//-----------------------------------------------------------------------------
// 进入乱战副本
//-----------------------------------------------------------------------------
struct NET_SIC_enter_pvp_instance : public tag_net_message
{
	NET_SIC_enter_pvp_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_enter_pvp_instance");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_enter_pvp_instance : public tag_net_message
{
	NET_SIS_enter_pvp_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_enter_pvp_instance");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// 离开乱战副本
//-----------------------------------------------------------------------------
struct NET_SIC_leave_pvp_instance : public tag_net_message
{
	NET_SIC_leave_pvp_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_pvp_instance");
		dw_size = sizeof(*this);
	}
};

//-----------------------------------------------------------------------------
// 乱战结果
//-----------------------------------------------------------------------------
struct NET_SIS_pvp_result : public tag_net_message
{
	NET_SIS_pvp_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pvp_result");
		dw_size = sizeof(*this);
	}

	TCHAR	sz_kill_name[X_SHORT_NAME];
	BOOL	b_win;
};

//-----------------------------------------------------------------------------
// 进入比武副本
//-----------------------------------------------------------------------------
struct NET_SIC_enter_pvp_biwu_instance : public tag_net_message
{
	NET_SIC_enter_pvp_biwu_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_enter_pvp_biwu_instance");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_enter_pvp_biwu_instance : public tag_net_message
{
	NET_SIS_enter_pvp_biwu_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_enter_pvp_biwu_instance");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// 离开比武副本
//-----------------------------------------------------------------------------
struct NET_SIC_leave_pvp_biwu_instance : public tag_net_message
{
	NET_SIC_leave_pvp_biwu_instance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_pvp_instance");
		dw_size = sizeof(*this);
	}
};

//-----------------------------------------------------------------------------
// 比武结果
//-----------------------------------------------------------------------------
struct NET_SIS_pvp_biwu_result : public tag_net_message
{
	NET_SIS_pvp_biwu_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pvp_biwu_result");
		dw_size = sizeof(*this);
	}

	TCHAR	sz_kill_name[X_SHORT_NAME];
	BOOL	b_win;
};

//-----------------------------------------------------------------------------
// 1v1申请
//-----------------------------------------------------------------------------
struct NET_SIC_1v1_apply : public tag_net_message
{
	NET_SIC_1v1_apply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_1v1_apply");
		dw_size = sizeof(*this);
	}
	DWORD dw_safe_code; //超级密码
};

struct NET_SIS_1v1_apply : public tag_net_message
{
	NET_SIS_1v1_apply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_1v1_apply");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// 离开1v1副本
//-----------------------------------------------------------------------------
struct NET_SIC_1v1_leave : public tag_net_message
{
	NET_SIC_1v1_leave()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_1v1_leave");
		dw_size = sizeof(*this);
	}
};

//-----------------------------------------------------------------------------
// 离开1v1队列
//-----------------------------------------------------------------------------
struct NET_SIC_1v1_leave_queue : public tag_net_message
{
	NET_SIC_1v1_leave_queue()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_1v1_leave_queue");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_1v1_leave_queue : public tag_net_message
{
	NET_SIS_1v1_leave_queue()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_1v1_leave_queue");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// 1v1胜负结果
//-----------------------------------------------------------------------------
struct NET_SIS_1v1_result : public tag_net_message
{
	NET_SIS_1v1_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_1v1_result");
		dw_size = sizeof(*this);
	}
	
	TCHAR	sz_win_name[X_SHORT_NAME];
	TCHAR	sz_faile_name[X_SHORT_NAME];
};

//-----------------------------------------------------------------------------
// 1v1积分胜负结果
//-----------------------------------------------------------------------------
struct NET_SIS_1v1_score_result : public tag_net_message
{
	NET_SIS_1v1_score_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_1v1_score_result");
		dw_size = sizeof(*this);
	}
	BOOL	bWin;
	INT		nScore;				// 当前积分
	INT		nJoinNum;			// 进入次数
	INT		nMaxScore;			// 最大上限
	BOOL	bAward;				// 是否可以领奖				
};

//-----------------------------------------------------------------------------
// 1v1积分领奖
//-----------------------------------------------------------------------------
struct NET_SIC_get_1v1_score_award : public tag_net_message
{
	NET_SIC_get_1v1_score_award()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_1v1_score_award");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_1v1_score_award : public tag_net_message
{
	NET_SIS_get_1v1_score_award()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_1v1_score_award");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// 1v1积分信息
//-----------------------------------------------------------------------------
struct NET_SIS_1v1_score_info : public tag_net_message
{
	NET_SIS_1v1_score_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_1v1_score_info");
		dw_size = sizeof(*this);
	}
	INT		nScore;				// 当前积分
	INT		nJoinNum;			// 进入次数
	INT		nMaxScore;			// 最大上限
	BOOL	bAward;				// 是否可以领奖		
};

//-----------------------------------------------------------------------------
// 约战申请
//-----------------------------------------------------------------------------
struct NET_SIC_reservation_apply : public tag_net_message
{
	NET_SIC_reservation_apply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reservation_apply");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;		// 被约人id
	DWORD	dw_safe_code; //超级密码
};

struct NET_SIS_reservation_apply_notify : public tag_net_message
{
	NET_SIS_reservation_apply_notify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reservation_apply_notify");
		dw_size = sizeof(*this);
	}

	DWORD	dw_role_id;		// 约战人id
	EClassType	eClass;
	INT		nLevel;
	INT		nYuanbao;
	INT		n_Equip_Scroe;
};

struct NET_SIS_reservation_apply : public tag_net_message
{
	NET_SIS_reservation_apply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reservation_apply");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// 约战回复
//-----------------------------------------------------------------------------
struct NET_SIC_reservation_result : public tag_net_message
{
	NET_SIC_reservation_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_reservation_result");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	BOOL	b_ok;
	DWORD	dw_safe_code; //超级密码
};

struct NET_SIS_reservation_cancel : public tag_net_message
{
	NET_SIS_reservation_cancel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reservation_cancel");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_reservation_timeout : public tag_net_message
{
	NET_SIS_reservation_timeout()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reservation_timeout");
		dw_size = sizeof(*this);
		
	}
};

struct NET_SIS_reservation_result : public tag_net_message
{
	NET_SIS_reservation_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_reservation_result");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

//-----------------------------------------------------------------------------
// 获取约战对象信息
//-----------------------------------------------------------------------------
struct NET_SIC_get_reservation_info : public tag_net_message
{
	NET_SIC_get_reservation_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_reservation_info");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
};

struct NET_SIS_get_reservation_info : public tag_net_message
{
	NET_SIS_get_reservation_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_reservation_info");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
	EClassType	eClass;
	INT			nLevel;
	INT			nEquipScore;
};

// 获取活跃度信息
struct NET_SIC_get_active_info : public tag_net_message
{
	NET_SIC_get_active_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_active_info");
		dw_size = sizeof(*this);
	}
};

// 获取活跃度信息
struct NET_SIC_get_guild_active_info : public tag_net_message
{
	NET_SIC_get_guild_active_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_active_info");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_active_info : public tag_net_message
{
	NET_SIS_get_active_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_active_info");
		dw_size = sizeof(*this);
	}

	INT32	n32_active_num;							// 活跃度
	INT32	n32_active_data[MAX_ACTIVE_DATA];		// 活跃度数据
	BOOL	b_active_receive[MAX_ACTIVE_RECEIVE];	// 活跃度领奖数据
};

struct NET_SIS_get_guild_active_info : public tag_net_message
{
	NET_SIS_get_guild_active_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_active_info");
		dw_size = sizeof(*this);
	}

	INT32	n32_active_num;							// 活跃度
	INT32	n32_active_data[MAX_ACTIVE_DATA];		// 活跃度数据
	BOOL	b_active_receive[MAX_ACTIVE_RECEIVE];	// 活跃度领奖数据
};

// 活跃度变更
struct NET_SIS_change_role_active_num : public tag_net_message
{
	NET_SIS_change_role_active_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_role_active_num");
		dw_size = sizeof(*this);
	}

	INT		n_index;			// 可以领取奖励的第一个位置
	INT32	n32_active_num;
};

struct NET_SIS_change_guild_active_num : public tag_net_message
{
	NET_SIS_change_guild_active_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_guild_active_num");
		dw_size = sizeof(*this);
	}

	INT		n_index;			// 可以领取奖励的第一个位置
	INT32	n32_active_num;
};

// 领取活跃度奖励
struct NET_SIC_role_active_receive : public tag_net_message
{
	NET_SIC_role_active_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_active_receive");
		dw_size = sizeof(*this);
	}
	INT	nIndex;
};

struct NET_SIC_guild_active_receive : public tag_net_message
{
	NET_SIC_guild_active_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_active_receive");
		dw_size = sizeof(*this);
	}
	INT	nIndex;
};

struct NET_SIS_role_active_receive : public tag_net_message
{
	NET_SIS_role_active_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_active_receive");
		dw_size = sizeof(*this);
	}
	INT nIndex;
	DWORD dw_error;
};

struct NET_SIS_guild_active_receive : public tag_net_message
{
	NET_SIS_guild_active_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_active_receive");
		dw_size = sizeof(*this);
	}
	INT nIndex;
	DWORD dw_error;
};


// 一键完成活跃度
struct NET_SIC_active_done : public tag_net_message
{
	NET_SIC_active_done()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_active_done");
		dw_size = sizeof(*this);
	}

	INT nIndex;
	INT nBeishu;//gx add 任务翻倍完成而用
};


// 一键完成活跃度
struct NET_SIS_active_done : public tag_net_message
{
	NET_SIS_active_done()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_active_done");
		dw_size = sizeof(*this);
	}
	INT nIndex;
	DWORD dw_erroe_code;
};
// 每日活动一键传送 gx add 2013.12.18
struct NET_SIC_daily_act_transmit:public tag_net_message
{
	NET_SIC_daily_act_transmit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_daily_act_transmit");
		dw_size = sizeof(*this);
	}
	INT nIndex;//活动索引
};

// 消费奖励
struct NET_SIS_get_ConsumeReward : public tag_net_message
{
	NET_SIS_get_ConsumeReward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_ConsumeReward");
		dw_size = sizeof(*this);
	}

	DWORD	dwConsumeRewardConut;	//花费总数
	DWORD	dwConsumeRewardData;	//领取标记
};




#pragma pack(pop)
#endif

