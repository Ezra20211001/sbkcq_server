
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//登陆服务器相关数据结构

#pragma once

#include "../../common/WorldDefine/time.h"

#pragma pack(push, 1)


//! world状态
enum E_world_status
{
	ews_well			=	0,		// 良好
	ews_init_not_done	=	1,		// 未初始化完毕
	ews_system_error	=	2,		// 系统出现故障
	ews_proof_error		=	3,		// 验证服务器故障
};


//! 认证类型
enum E_proof_policy
{
	epp_null	=	-1,
	epp_test	=	0,		// 测试专用
	epp_own		=	1,		// 自己公司验证策略
	epp_facebook =	2,		// facebook

	epp_end		=	3		
};


//! 玩家登录时的状态
enum  E_player_login_status
{
	epls_null		=	-1,		// 无效
	epls_off_line	=	0,		// 离线
	epls_online		=	1,		// 在线
	epls_loging		=	2,		// 登录中
	epls_unknown	=	3,		// 未知
};

//! 玩家封停类型  
enum  E_player_frobid_mask
{
	eplm_member_center	=	0x01,		// 会员中心
	eplm_gm_tool		=	0x02,		// GM工具
	eplm_cell_phone		=	0x04,		// 手机锁
	eplm_mibao			=	0x08,		// 密保卡封停
	eplm_waigua			=	0x10		// 反外挂自动封停
};

//! 验证结果结构
struct s_proof_result
{
	DWORD					dw_client_id;		// 客户端ID
	DWORD					dw_account_id;		// 帐号ID
	BOOL					b_guard;			// 防沉迷
	INT						n_guard_accu_time;	// 防沉迷累积时间
	E_player_login_status	e_login_status;		// 登陆状态
	DWORD					dw_world_name_crc;	// 当前登陆的游戏世界
	DWORD					dw_frobid_mask;		// 封停掩码 每1位对应一种封停类型
	BYTE					by_privilege;		// 权限
	bool					b_need_mibao;		// 是否使用密保
	DWORD					dw_pre_login_ip;	// 上次登录ip
	tagDWORDTime			dw_pre_login_time;	// 上次登录时间
	BYTE					by_SpecialAccount;	// 是否特殊账号<ZF>
	BYTE					by_reserved;		// 保留，对齐

	s_proof_result()
	{
		dw_client_id		=	INVALID_VALUE;
		dw_account_id		=	INVALID_VALUE;
		b_guard			=	FALSE;
		n_guard_accu_time	=	0;
		e_login_status	=	epls_off_line;
		by_privilege		=	0;
		b_need_mibao		=	false;
		dw_frobid_mask	=   0;
		dw_pre_login_ip    =	0;
		dw_pre_login_time	=   0;
		by_SpecialAccount = 0;
	}
};

struct s_proof_result_third
{
	s_proof_result result;
	CHAR szAccount[X_SHORT_NAME];
};

struct s_proof_result_full : public s_proof_result
{
	BYTE by_Type;
	CHAR szAccount[X_SHORT_NAME];
	INT n_ret;		// 返回结果
};

//! 验证回调函数
typedef fastdelegate::FastDelegate2<INT, VOID*, UINT> PROOFCALLBACK;

#pragma pack(pop)