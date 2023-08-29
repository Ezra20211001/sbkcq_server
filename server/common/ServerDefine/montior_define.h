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


//!  Game World 的 server 类型
enum E_server_type 
{
	est_world,		//游戏世界服务器
	est_db,			//游戏世界数据库服务器
	est_login,		//游戏大区login服务器	
};

//! 客户端权限
enum EPrivilege
{
	ep_null		=	-1,		// 未初始化
	ep_pri_gm_d	=	0,		// 1级权限
	ep_pri_gm_c	=	1,		// 2级权限
	ep_pri_gm_b	=	2,		// 3级权限
	ep_pri_gm_a	=	3,		// 4级权限
	ep_pri_gm_s	=	4,		// 5级权限
	ep_pri_rt_b	=	5,		// 6级权限
	ep_pri_rt_a	=	6,		// 7级权限(6 7级为远程监控使用)
	ep_pri_rt_c	=	7,		// 8级权限(调整服务器人数上限用)
	ep_pri_rt_d	=	8,		// 9级权限(更新商城用)
	ep_end		=	9
};

#define M_is_gm_tool_pri(ePri)	((ePri) >= ep_pri_gm_d && (ePri) <= ep_pri_gm_s)
#define M_is_rt_client_pri(ePri)	((ePri) >= ep_pri_rt_b && (ePri) <= ep_pri_rt_d)

#define M_is_gm_op_gm(root, gm)		(M_is_gm_tool_pri(root)		&& M_is_gm_tool_pri(gm) )
#define M_is_rt_op_rt(root, rt)		(M_is_rt_client_pri(root)		&& M_is_rt_client_pri(rt) )