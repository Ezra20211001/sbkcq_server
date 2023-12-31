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
*	@file		guild_protocol.h
*	@author		lc
*	@date		2011/03/07	initial
*	@version	0.0.1.0
*	@brief		帮会消息
*/

#ifndef GUILD_PROTOCOL
#define GUILD_PROTOCOL


#include "protocol_common_errorcode.h"
#include "guild_define.h"


#pragma pack(push, 1)
//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum
{
	E_SBK_ERROR_1	=	1,		//没权限报名
	E_SBK_ERROR_2	=	2,		//已经报名了
	E_SBK_ERROR_3	=	3,		//沙巴克公会不用报名
	E_SBK_ERROR_4	=	4,		//帮会资金不足
	E_SBK_ERROR_5	=	5,		//不能重复领取沙巴克奖励
	E_SBK_ERROR_6	=	6,		//周二周五不能报名
	E_SBK_ERROR_7	=	7,		//背包已满不能领取
};

//----------------------------------------------------------------------------
// 创建帮派
//----------------------------------------------------------------------------
struct NET_SIC_guild_create : public tag_net_message
{
	NET_SIC_guild_create()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_create");
		dw_size = sizeof(NET_SIC_guild_create);
	}
	INT64		n64ItemID;
	TCHAR		szGuildName[1];
};

// 全服
struct NET_SIC_guild_create_broad : public tag_net_message
{
	NET_SIC_guild_create_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_create_broad");
		dw_size = sizeof(NET_SIC_guild_create_broad);
	}
	DWORD		dw_role_id;		// 创建者id
	DWORD		dwRoleNameID;	// 创建者名字id
	DWORD		dwGuildID;
	TCHAR		szName[1];		// 角色名+帮派名
};


//----------------------------------------------------------------------------
// 解散帮派
//----------------------------------------------------------------------------
struct NET_SIC_guild_dismiss : public tag_net_message
{
	NET_SIC_guild_dismiss()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_dismiss");
		dw_size = sizeof(NET_SIC_guild_dismiss);
	}
	DWORD		dwNPCID;
};

// 全服
struct NET_SIS_guild_dismiss_broad : public tag_net_message
{
	NET_SIS_guild_dismiss_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_dismiss_broad");
		dw_size = sizeof(NET_SIS_guild_dismiss_broad);
	}
	DWORD		dw_role_id;
	TCHAR		szGuildName[1];
};


//----------------------------------------------------------------------------
// 邀请加入
//----------------------------------------------------------------------------
// 玩家请求目标加入帮派
struct NET_SIC_guild_join_request : public tag_net_message
{
	NET_SIC_guild_join_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_join_request");
		dw_size = sizeof(NET_SIC_guild_join_request);
	}
	DWORD		dwDstRoleID;
};

// 玩家请求目标加入家族
struct NET_SIC_guild_join_request_by_name : public tag_net_message
{
	NET_SIC_guild_join_request_by_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_join_request_by_name");
		dw_size = sizeof(NET_SIC_guild_join_request_by_name);
	}
	DWORD 		dwNameCrc;
};

// 服务器将请求发送给目标玩家
struct NET_SIS_guild_join_request : public tag_net_message
{
	NET_SIS_guild_join_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_join_request");
		dw_size = sizeof(NET_SIS_guild_join_request);
	}
	DWORD		dwSrcRoleID;
	DWORD		dwGuildID;
	BOOL		b_sign;		// 0 普通邀请 1 帮会转正邀请
};

// 目标玩家反馈该请求
struct NET_SIC_guild_join_request_result : public tag_net_message
{
	NET_SIC_guild_join_request_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_join_request_result");
		dw_size = sizeof(NET_SIC_guild_join_request_result);
	}
	DWORD		dw_error_code;
	DWORD		dwDstRoleID;
	DWORD		dwDstGuildID;
};

// 服务器转发给目标玩家反馈
struct NET_SIS_guild_join_request_result : public tag_net_message
{
	NET_SIS_guild_join_request_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_join_request_result");
		dw_size = sizeof(NET_SIS_guild_join_request_result);
	}
	DWORD		dw_error_code;
	DWORD		dwInviterID;
	DWORD		dwInviteeID;
};

// 帮派内广播
struct NET_SIS_guild_join_broad : public tag_net_message
{
	NET_SIS_guild_join_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_join_broad");
		dw_size = sizeof(NET_SIS_guild_join_broad);
	}
	DWORD		dw_role_id;
	DWORD		dwRoleNameID;
	TCHAR		szRoleName[1];
};


//------------------------------------------------------------------------------
// 玩家离开帮派
//------------------------------------------------------------------------------
struct NET_SIC_guild_leave : public tag_net_message
{
	NET_SIC_guild_leave()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_leave");
		dw_size = sizeof(NET_SIC_guild_leave);
	}
};

struct NET_SIS_guild_leave_broad : public tag_net_message
{
	NET_SIS_guild_leave_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_leave_broad");
		dw_size = sizeof(NET_SIS_guild_leave_broad);
	}
	DWORD		dwSrcRoleID;
};


//------------------------------------------------------------------------------
// 开革玩家出帮
//------------------------------------------------------------------------------
struct NET_SIC_guild_kick : public tag_net_message
{
	NET_SIC_guild_kick()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_kick");
		dw_size = sizeof(NET_SIC_guild_kick);
	}
	DWORD		dw_role_id;
};

struct NET_SIS_guild_kick_broad : public tag_net_message
{
	NET_SIS_guild_kick_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_kick_broad");
		dw_size = sizeof(NET_SIS_guild_kick_broad);
	}
	DWORD		dwDstRoleID;
};


//------------------------------------------------------------------------------
// 移交帮主
//------------------------------------------------------------------------------
struct NET_SIC_guild_trunover : public tag_net_message
{
	NET_SIC_guild_trunover()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_trunover");
		dw_size = sizeof(NET_SIC_guild_trunover);
	}
	DWORD		dw_role_id;
	DWORD		dw_safe_code;
};

struct NET_SIS_guild_trunover_broad : public tag_net_message
{
	NET_SIS_guild_trunover_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_trunover_broad");
		dw_size = sizeof(NET_SIS_guild_trunover_broad);
	}
	DWORD		dwSrcRoleID;
	DWORD		dwDstRoleID;
};


//------------------------------------------------------------------------------
// 辞去职务
//------------------------------------------------------------------------------
struct NET_SIC_guild_demiss : public tag_net_message
{
	NET_SIC_guild_demiss()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_demiss");
		dw_size = sizeof(NET_SIC_guild_demiss);
	}
};

struct NET_SIS_guild_demiss_broad : public tag_net_message
{
	NET_SIS_guild_demiss_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_demiss_broad");
		dw_size = sizeof(NET_SIS_guild_demiss_broad);
	}
	DWORD		dw_role_id;
	INT8		n8OldGuildPos;
};


//------------------------------------------------------------------------------
// 任命玩家职位
//------------------------------------------------------------------------------
struct NET_SIC_guild_appoint : public tag_net_message
{
	NET_SIC_guild_appoint()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_appoint");
		dw_size = sizeof(NET_SIC_guild_appoint);
	}
	DWORD			dw_role_id;
	EGuildMemberPos	ePos;
};

struct NET_SIS_guild_appoint_broad : public tag_net_message
{
	NET_SIS_guild_appoint_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_appoint_broad");
		dw_size = sizeof(NET_SIS_guild_appoint_broad);
	}
	DWORD			dwSrcRoleID;
	DWORD			dwDstRoleID;
	EGuildMemberPos	ePos;
};


//------------------------------------------------------------------------------
// 修改宗旨
//------------------------------------------------------------------------------
struct NET_SIC_guild_tenet_change : public tag_net_message
{
	NET_SIC_guild_tenet_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_tenet_change");
		dw_size = sizeof(NET_SIC_guild_tenet_change);
	}
	TCHAR			szTenet[1];
};

struct NET_SIS_guild_tenet_change_broad : public tag_net_message
{
	NET_SIS_guild_tenet_change_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_tenet_change_broad");
		dw_size = sizeof(NET_SIS_guild_tenet_change_broad);
	}
	DWORD			dw_role_id;
	TCHAR			szTenet[1];
};


//------------------------------------------------------------------------------
// 修改帮会标志
//------------------------------------------------------------------------------
struct NET_SIC_guild_symbol : public tag_net_message
{
	NET_SIC_guild_symbol()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_symbol");
		dw_size = sizeof(NET_SIC_guild_symbol);
	}
	TCHAR			szText[1];
};

struct NET_SIS_guild_symbol_broad : public tag_net_message
{
	NET_SIS_guild_symbol_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_symbol_broad");
		dw_size = sizeof(NET_SIS_guild_symbol_broad);
	}
	DWORD			dw_role_id;
	TCHAR			szText[1];
};


//------------------------------------------------------------------------------
// 邀请签名
//------------------------------------------------------------------------------
struct NET_SIC_invite_sign : public tag_net_message
{
	NET_SIC_invite_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_invite_sign");
		dw_size = sizeof(NET_SIC_invite_sign);
	}
	DWORD			dwInviteID;				// 邀请者ID
	DWORD			dwBeInviteID;			// 被邀请者ID
	INT64			n64ItemID;
};

struct NET_SIS_invite_sign : public tag_net_message
{
	NET_SIS_invite_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_sign");
		dw_size = sizeof(NET_SIS_invite_sign);
	}
	DWORD dwError;
};

struct NET_SIS_invite_sign_data : public tag_net_message
{
	NET_SIS_invite_sign_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_sign_data");
		dw_size = sizeof(NET_SIS_invite_sign_data);
	}
	DWORD			dwInviteID;				// 邀请者ID
	tagGuildSignData st_GuildSignData;
};


//------------------------------------------------------------------------------
// 取消签名
//------------------------------------------------------------------------------
struct NET_SIC_cancel_sign : public tag_net_message
{
	NET_SIC_cancel_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_sign");
		dw_size = sizeof(NET_SIC_cancel_sign);
	}
};

struct NET_SIS_cancel_sign : public tag_net_message
{
	NET_SIS_cancel_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_sign");
		dw_size = sizeof(NET_SIS_cancel_sign);
	}
};

//------------------------------------------------------------------------------
// 确认签名
//------------------------------------------------------------------------------
struct NET_SIC_affirmance_sign : public tag_net_message
{
	NET_SIC_affirmance_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_affirmance_sign");
		dw_size = sizeof(NET_SIC_affirmance_sign);
	}
};

struct NET_SIS_affirmance_sign : public tag_net_message
{
	NET_SIS_affirmance_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_affirmance_sign");
		dw_size = sizeof(NET_SIS_affirmance_sign);
	}
	DWORD  dwSignID;			// 签名者ID
};

struct NET_SIS_affirmance_sign_res : public tag_net_message
{
	NET_SIS_affirmance_sign_res()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_affirmance_sign_res");
		dw_size = sizeof(*this);
	}
};


//------------------------------------------------------------------------------
// 提交签名
//------------------------------------------------------------------------------
struct NET_SIC_refer_sign : public tag_net_message
{
	NET_SIC_refer_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_refer_sign");
		dw_size = sizeof(NET_SIC_refer_sign);
	}
	DWORD dwNPCID;				// NPCID
	INT64 n64ItemID;			
};

struct NET_SIS_refer_sign : public tag_net_message
{
	NET_SIS_refer_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_refer_sign");
		dw_size = sizeof(NET_SIS_refer_sign);
	}
	DWORD dwError;		
};


//------------------------------------------------------------------------------
// 获取弹劾数据
//------------------------------------------------------------------------------
struct NET_SIC_get_guild_delate_data : public tag_net_message
{
	NET_SIC_get_guild_delate_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_delate_data");
		dw_size = sizeof(NET_SIC_get_guild_delate_data);
	}
};

struct NET_SIS_get_guild_delate_data : public tag_net_message
{
	NET_SIS_get_guild_delate_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_delate_data");
		dw_size = sizeof(NET_SIS_get_guild_delate_data);
	}
	tagGuildDelateBase stGuildDelateBase;
};

//------------------------------------------------------------------------------
// 获取弹劾内容数据
//------------------------------------------------------------------------------
struct NET_SIC_get_guild_delate_content : public tag_net_message
{
	NET_SIC_get_guild_delate_content()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_delate_content");
		dw_size = sizeof(NET_SIC_get_guild_delate_content);
	}
};

struct NET_SIS_get_guild_delate_content : public tag_net_message
{
	NET_SIS_get_guild_delate_content()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_delate_content");
		dw_size = sizeof(NET_SIS_get_guild_delate_content);
	}
	TCHAR		szContent[1];
};


//------------------------------------------------------------------------------
// 弹劾帮主
//------------------------------------------------------------------------------
struct NET_SIC_delate_leader : public tag_net_message
{
	NET_SIC_delate_leader()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delate_leader");
		dw_size = sizeof(NET_SIC_delate_leader);
	}
	INT64		n64ItemID;
	TCHAR		szContent[1];
};

struct NET_SIS_delate_leader : public tag_net_message
{
	NET_SIS_delate_leader()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delate_leader");
		dw_size = sizeof(NET_SIS_delate_leader);
	}
	DWORD		dwError;
};

//------------------------------------------------------------------------------
// 弹劾投票
//------------------------------------------------------------------------------
struct NET_SIC_delate_ballot : public tag_net_message
{
	NET_SIC_delate_ballot()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delate_ballot");
		dw_size = sizeof(NET_SIC_delate_ballot);
	}
	BOOL		bAgree;
};

struct NET_SIS_delate_ballot : public tag_net_message
{
	NET_SIS_delate_ballot()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delate_ballot");
		dw_size = sizeof(NET_SIS_delate_ballot);
	}
	DWORD		dwError;
};


//------------------------------------------------------------------------------
// 操作失败反馈
//------------------------------------------------------------------------------
struct NET_SIS_guild_failed_disposal : public tag_net_message
{
	NET_SIS_guild_failed_disposal()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_failed_disposal");
		dw_size = sizeof(NET_SIS_guild_failed_disposal);
	}
	DWORD			dw_error_code;
};

//----------------------------------------------------------------------------
// 同步帮派信息
//----------------------------------------------------------------------------
struct NET_SIC_synchronize_guild_info : public tag_net_message
{
	NET_SIC_synchronize_guild_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_synchronize_guild_info");
		dw_size = sizeof(NET_SIC_synchronize_guild_info);
	}
};

struct NET_SIS_synchronize_guild_info : public tag_net_message
{
	NET_SIS_synchronize_guild_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_guild_info");
		dw_size = sizeof(NET_SIS_synchronize_guild_info);
	}
	tagGuildBase	sGuildInfo;
};

// 同步帮会战相关信息
struct NET_SIC_synchronize_guild_war_info : public tag_net_message
{
	NET_SIC_synchronize_guild_war_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_synchronize_guild_war_info");
		dw_size = sizeof(NET_SIC_synchronize_guild_war_info);
	}
};

struct NET_SIS_synchronize_guild_war_info : public tag_net_message
{
	NET_SIS_synchronize_guild_war_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_guild_war_info");
		dw_size = sizeof(NET_SIS_synchronize_guild_war_info);
	}
	DWORD			dwMaxWarNum;	// 最大人数
	DWORD			dwCurWarNum;	// 当前人数
	double			fMoneyParam;	// 发奖比例
	EGuildWarState	eSatae;			// 当前状态
	DWORD			dwBeginTime;	// 开始时间
	DWORD			dwGulldID;		// 敌对帮会id
	TCHAR			szGuildName[X_SHORT_NAME]; // 敌对名
	BYTE			byEnemyLevel;	// 敌对等级
	BOOL			bDefenter;		// 是否防守方
	BOOL			bRelay;			// 是否准备完毕
	DWORD				dwSymbolValue;				// 帮会标志
	TCHAR				szText[2];					// 帮会文字

};


//----------------------------------------------------------------------------
// 帮派信息
//----------------------------------------------------------------------------
struct NET_SIS_guild_info : public tag_net_message
{
	NET_SIS_guild_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_info");
		dw_size = sizeof(NET_SIS_guild_info);
	}
	tagGuildBase	sGuildInfo;
};


//----------------------------------------------------------------------------
// 获取帮派所有成员
//----------------------------------------------------------------------------
struct NET_SIC_guild_get_all_member : public tag_net_message
{
	NET_SIC_guild_get_all_member()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_get_all_member");
		dw_size = sizeof(NET_SIC_guild_get_all_member);
	}
};

struct NET_SIS_guild_get_all_member : public tag_net_message
{
	NET_SIS_guild_get_all_member()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_get_all_member");
		dw_size = sizeof(NET_SIS_guild_get_all_member);
	}
	DWORD		dw_error_code;
	INT16		n16Num;
	BYTE		byData[1];		// tagGuildMemInfo
};


//----------------------------------------------------------------------------
// 获取帮派指定成员扩展信息
//----------------------------------------------------------------------------
struct NET_SIC_guild_get_member_extend : public tag_net_message
{
	NET_SIC_guild_get_member_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_get_member_extend");
		dw_size = sizeof(NET_SIC_guild_get_member_extend);
	}
	DWORD		dw_role_id;
};

struct NET_SIS_guild_get_member_extend : public tag_net_message
{
	NET_SIS_guild_get_member_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_get_member_extend");
		dw_size = sizeof(NET_SIS_guild_get_member_extend);
	}
	DWORD				dw_role_id;
	tagGuildMemInfoEx	sGuildMemInfoEx;
};

//----------------------------------------------------------------------------
// 刷新帮派指定成员扩展信息
//----------------------------------------------------------------------------
struct NET_SIC_guild_refresh_member : public tag_net_message
{
	NET_SIC_guild_refresh_member()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_refresh_member");
		dw_size = sizeof(NET_SIC_guild_refresh_member);
	}
	DWORD		dw_role_id;
};

struct NET_SIS_guild_refresh_member : public tag_net_message
{
	NET_SIS_guild_refresh_member()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_refresh_member");
		dw_size = sizeof(NET_SIS_guild_refresh_member);
	}
	tagGuildMemInfo		sGuildMemInfo;
	tagGuildMemInfoEx	sGuildMemInfoEx;
};


//------------------------------------------------------------------------------
// 帮派成员贡献变更
//------------------------------------------------------------------------------
struct NET_SIS_guild_contribution : public tag_net_message
{
	NET_SIS_guild_contribution()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_contribution");
		dw_size = sizeof(NET_SIS_guild_contribution);
	}
	DWORD		dw_role_id;
	INT32		nContribution;
	INT32		nTotalContribution;
};


//------------------------------------------------------------------------------
// 帮派成员功勋变更
//------------------------------------------------------------------------------
struct NET_SIS_guild_exploit : public tag_net_message
{
	NET_SIS_guild_exploit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_exploit");
		dw_size = sizeof(NET_SIS_guild_exploit);
	}
	DWORD		dw_role_id;
	INT32		nExploit;
};

//------------------------------------------------------------------------------
// 获取帮派名称
//------------------------------------------------------------------------------
struct NET_SIC_get_guild_name : public tag_net_message
{
	NET_SIC_get_guild_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_name");
		dw_size = sizeof(NET_SIC_get_guild_name);
	}
	DWORD		dwGuildID;
};

struct NET_SIS_get_guild_name : public tag_net_message
{
	NET_SIS_get_guild_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_name");
		dw_size = sizeof(NET_SIS_get_guild_name);
	}
	DWORD		dwGuildID;
	TCHAR		szGuildName[1];
};


//-----------------------------------------------------------------------------
// 获取帮派遵旨（只用获取自己帮派的）
//-----------------------------------------------------------------------------
struct NET_SIC_get_guild_tenet : public tag_net_message
{
	NET_SIC_get_guild_tenet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_tenet");
		dw_size = sizeof(NET_SIC_get_guild_tenet);
	}
};

struct NET_SIS_get_guild_tenet : public tag_net_message
{
	NET_SIS_get_guild_tenet()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_tenet");
		dw_size = sizeof(NET_SIS_get_guild_tenet);
	}
	TCHAR		szGuildTenet[1];
};


//-----------------------------------------------------------------------------
// 获取帮会招聘公告
//-----------------------------------------------------------------------------
struct NET_SIC_get_guild_symbol : public tag_net_message
{
	NET_SIC_get_guild_symbol()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_symbol");
		dw_size = sizeof(NET_SIC_get_guild_symbol);
	}
	DWORD	dwGuildID;
};

struct NET_SIS_get_guild_symbol : public tag_net_message
{
	NET_SIS_get_guild_symbol()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_symbol");
		dw_size = sizeof(NET_SIS_get_guild_symbol);
	}
	DWORD		dwGuildID;
	TCHAR		bySymbol[1];
};


//-----------------------------------------------------------------------------
// 修改家族职位名称
//-----------------------------------------------------------------------------
struct NET_SIC_guild_position_name_change : public tag_net_message
{
	NET_SIC_guild_position_name_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_position_name_change");
		dw_size = sizeof(NET_SIC_guild_position_name_change);
	}
	TCHAR    szPosName[X_GUILD_POS_NUM][MAX_GUILD_POS_NAME_LEN];
};

struct NET_SIS_guild_position_name_change : public tag_net_message
{
	NET_SIS_guild_position_name_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_position_name_change");
		dw_size = sizeof(NET_SIS_guild_position_name_change);
	}
	DWORD	 dwGuildID;
	TCHAR    szPosName[X_GUILD_POS_NUM][MAX_GUILD_POS_NAME_LEN];
};


//-----------------------------------------------------------------------------
//修改家族职位权限
//-----------------------------------------------------------------------------
struct NET_SIC_guild_position_power_change : public tag_net_message
{
	NET_SIC_guild_position_power_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_position_power_change");
		dw_size = sizeof(NET_SIC_guild_position_power_change);
	}
	DWORD    dwPosPower[X_GUILD_POS_NUM];
};

struct NET_SIS_guild_position_power_change_broad : public tag_net_message
{
	NET_SIS_guild_position_power_change_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_position_power_change_broad");
		dw_size = sizeof(NET_SIS_guild_position_power_change_broad);
	}
	DWORD	 dwGuildID;
	DWORD    dwPosPower[X_GUILD_POS_NUM];
};


//-----------------------------------------------------------------------------
//进入帮会地图
//-----------------------------------------------------------------------------
struct NET_SIC_enter_guild_map : public tag_net_message
{
	NET_SIC_enter_guild_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_enter_guild_map");
		dw_size = sizeof(NET_SIC_enter_guild_map);
	}
	DWORD dwNPCID;
	INT64 n64_ItemSerial;
	DWORD dwParam;			// 0 进入本帮会副本 1 进入敌对帮会副本
};


//-----------------------------------------------------------------------------
//获取DKP数据 
//-----------------------------------------------------------------------------
struct NET_SIC_get_dkp : public tag_net_message
{
	NET_SIC_get_dkp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_dkp");
		dw_size = sizeof(NET_SIC_get_dkp);
	}
};	

struct NET_SIS_get_dkp : public tag_net_message
{
	NET_SIS_get_dkp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_dkp");
		dw_size = sizeof(NET_SIS_get_dkp);
	}
	INT16	n16DKP[EDKP_END];
};

//-----------------------------------------------------------------------------
//设置DKP数据 
//-----------------------------------------------------------------------------
struct NET_SIC_set_dkp : public tag_net_message
{
	NET_SIC_set_dkp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_dkp");
		dw_size = sizeof(NET_SIC_set_dkp);
	}
	INT16	n16DKP[EDKP_END];
};

struct NET_SIS_set_dkp : public tag_net_message
{
	NET_SIS_set_dkp()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_dkp");
		dw_size = sizeof(NET_SIS_set_dkp);
	}
	DWORD	dwError;
};


//-----------------------------------------------------------------------------
//DKP确认
//-----------------------------------------------------------------------------
struct NET_SIC_dkp_affirmance : public tag_net_message
{
	NET_SIC_dkp_affirmance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_dkp_affirmance");
		dw_size = sizeof(NET_SIC_dkp_affirmance);
	}
	INT16	n16DKP;
};

struct NET_SIS_dkp_affirmance : public tag_net_message
{
	NET_SIS_dkp_affirmance()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_dkp_affirmance");
		dw_size = sizeof(NET_SIS_dkp_affirmance);
	}
	DWORD dwError;
};

//-----------------------------------------------------------------------------
//设置敌对帮会
//-----------------------------------------------------------------------------
struct NET_SIC_set_enemy_guild : public tag_net_message
{
	NET_SIC_set_enemy_guild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_enemy_guild");
		dw_size = sizeof(NET_SIC_set_enemy_guild);
	}
	DWORD dwEnemyGuildID;
};

struct NET_SIS_set_enemy_guild : public tag_net_message
{
	NET_SIS_set_enemy_guild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_enemy_guild");
		dw_size = sizeof(NET_SIS_set_enemy_guild);
	}
	DWORD dwError;
};

struct NET_SIS_view_enemy : public tag_net_message
{
	NET_SIS_view_enemy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_view_enemy");
		dw_size = sizeof(NET_SIS_view_enemy);
	}
	DWORD dwGuildID;
	DWORD dwGuildEnemyID;
};

struct NET_SIS_add_enemy_guild : public tag_net_message
{
	NET_SIS_add_enemy_guild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_enemy_guild");
		dw_size = sizeof(NET_SIS_add_enemy_guild);
	}
	DWORD dwGuildEnemyID;
	BOOL  bAdd;
};


//-----------------------------------------------------------------------------
//邀请同盟
//-----------------------------------------------------------------------------
struct NET_SIC_invite_league : public tag_net_message
{
	NET_SIC_invite_league()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_invite_league");
		dw_size = sizeof(NET_SIC_invite_league);
	}
	DWORD  dwLeagueGuildID;
};

struct NET_SIS_invite_league : public tag_net_message
{
	NET_SIS_invite_league()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_league");
		dw_size = sizeof(NET_SIS_invite_league);
	}
	DWORD dwError;
};

struct NET_SIS_send_invite_league : public tag_net_message
{
	NET_SIS_send_invite_league()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_invite_league");
		dw_size = sizeof(NET_SIS_send_invite_league);
	}
	DWORD dwInviteGuildID;
};


//-----------------------------------------------------------------------------
//邀请同盟回复
//-----------------------------------------------------------------------------
struct NET_SIC_invite_league_result : public tag_net_message
{
	NET_SIC_invite_league_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_invite_league_result");
		dw_size = sizeof(NET_SIC_invite_league_result);
	}
	DWORD	dwInviteGuildID;
	BOOL	bAgree; 
};

struct NET_SIS_invite_league_result : public tag_net_message
{
	NET_SIS_invite_league_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_league_result");
		dw_size = sizeof(NET_SIS_invite_league_result);
	}
	DWORD dwError;
};

struct NET_SIS_send_invite_league_result : public tag_net_message
{
	NET_SIS_send_invite_league_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_invite_league_result");
		dw_size = sizeof(NET_SIS_send_invite_league_result);
	}
	DWORD	dwInviteGuildID;
	DWORD	dwResGuildID;
	BOOL	bAgree; 
};

//-----------------------------------------------------------------------------
//解除同盟
//-----------------------------------------------------------------------------
struct NET_SIC_relieve_league : public tag_net_message
{
	NET_SIC_relieve_league()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_relieve_league");
		dw_size = sizeof(NET_SIC_relieve_league);
	}
	DWORD dwGuildID;
};

struct NET_SIS_relieve_league : public tag_net_message
{
	NET_SIS_relieve_league()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_relieve_league");
		dw_size = sizeof(NET_SIS_relieve_league);
	}
	DWORD dwError;
};

struct NET_SIS_send_relieve_league : public tag_net_message
{
	NET_SIS_send_relieve_league()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_relieve_league");
		dw_size = sizeof(NET_SIS_send_relieve_league);
	}
	DWORD dwRelieveID;
	DWORD dwBeRelieveID;
};

//-----------------------------------------------------------------------------
//删除敌对帮会
//-----------------------------------------------------------------------------
struct NET_SIC_delete_enemy_guild : public tag_net_message
{
	NET_SIC_delete_enemy_guild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_enemy_guild");
		dw_size = sizeof(NET_SIC_delete_enemy_guild);
	}
	DWORD dwEnemyGuildID;
};

struct NET_SIS_delete_enemy_guild : public tag_net_message
{
	NET_SIS_delete_enemy_guild()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_enemy_guild");
		dw_size = sizeof(NET_SIS_delete_enemy_guild);
	}
	DWORD dwError;
};

struct NET_SIS_unview_enemy : public tag_net_message
{
	NET_SIS_unview_enemy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_unview_enemy");
		dw_size = sizeof(NET_SIS_unview_enemy);
	}
	DWORD dwGuildID;
	DWORD dwGuildEnemyID;
};


//-----------------------------------------------------------------------------
//获取敌对数据
//-----------------------------------------------------------------------------
struct NET_SIC_get_enemy_data : public tag_net_message
{
	NET_SIC_get_enemy_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_enemy_data");
		dw_size = sizeof(NET_SIC_get_enemy_data);
	}
};

struct NET_SIS_get_enemy_data : public tag_net_message
{
	NET_SIS_get_enemy_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_enemy_data");
		dw_size = sizeof(NET_SIS_get_enemy_data);
	}
	DWORD				dwDeclareGuildID;		// 宣战帮会ID
	DWORD				dwBeDeclareGuildID;		// 宣战帮会ID;
	DWORD				dwWarGuildID;			// 战斗方ID
	tagDWORDTime		dwDeclareBeginTime;		// 宣战起始时间
	tagDWORDTime		dwPrepareBeginTime;		// 战斗准备时间
	tagDWORDTime		dwWarBeginTime;			// 战斗开始时间
	tagDWORDTime		dwCurrTime;				// 服务器当前时间
	EGuildWarState		eGuildWarState;			// 当前帮会战状态
	INT					n_num;
	tagGuildEnemyData	st_EnemyData[1];		// 敌对帮会数据
};


//-----------------------------------------------------------------------------
//帮会宣战
//-----------------------------------------------------------------------------
struct NET_SIC_guild_declare_war : public tag_net_message
{
	NET_SIC_guild_declare_war()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_declare_war");
		dw_size = sizeof(NET_SIC_guild_declare_war);
	}
	DWORD dwGuildID;
};

struct NET_SIS_guild_declare_war : public tag_net_message
{
	NET_SIS_guild_declare_war()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_declare_war");
		dw_size = sizeof(NET_SIS_guild_declare_war);
	}
	DWORD dwError;
};

// 被宣战
struct NET_SIS_guild_bedeclare_war : public tag_net_message
{
	NET_SIS_guild_bedeclare_war()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_bedeclare_war");
		dw_size = sizeof(NET_SIS_guild_bedeclare_war);
	}

	DWORD dwGuildID;
	BYTE dwLevel;
	TCHAR szGuildName[X_SHORT_NAME];
	TCHAR szLeaderName[X_SHORT_NAME];
};
//-----------------------------------------------------------------------------
//帮会宣战回复
//-----------------------------------------------------------------------------
struct NET_SIC_guild_declare_war_result : public tag_net_message
{
	NET_SIC_guild_declare_war_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_declare_war_result");
		dw_size = sizeof(NET_SIC_guild_declare_war_result);
	}
	DWORD dwGuildID;
	BOOL  bAccept;
};

struct NET_SIS_guild_declare_war_result : public tag_net_message
{
	NET_SIS_guild_declare_war_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_declare_war_result");
		dw_size = sizeof(NET_SIS_guild_declare_war_result);
	}
	DWORD dwError;
};

// 修改参战人数
struct NET_SIC_guild_war_num : public tag_net_message
{
	NET_SIC_guild_war_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_war_num");
		dw_size = sizeof(NET_SIC_guild_war_num);
	}
	DWORD dwNum;
};

struct NET_SIS_guild_war_num : public tag_net_message
{
	NET_SIS_guild_war_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_num");
		dw_size = sizeof(NET_SIS_guild_war_num);
	}
	DWORD dw_error_code;
};

struct NET_SIS_guild_war_maxnum_change : public tag_net_message
{
	NET_SIS_guild_war_maxnum_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_maxnum_change");
		dw_size = sizeof(NET_SIS_guild_war_maxnum_change);
	}
	DWORD dwNumber;
};

// 修改发奖比例
struct NET_SIC_guild_war_money_param : public tag_net_message
{
	NET_SIC_guild_war_money_param()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_war_money_param");
		dw_size = sizeof(NET_SIC_guild_war_money_param);
	}
	double fParam;
};

struct NET_SIS_guild_war_money_param : public tag_net_message
{
	NET_SIS_guild_war_money_param()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_money_param");
		dw_size = sizeof(NET_SIS_guild_war_money_param);
	}
	DWORD dw_error_code;
};

struct NET_SIS_guild_war_money_param_change : public tag_net_message
{
	NET_SIS_guild_war_money_param_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_money_param_change");
		dw_size = sizeof(NET_SIS_guild_war_money_param_change);
	}
	double fParam;
};

//-----------------------------------------------------------------------------
//帮会拒绝宣战全服广播
//-----------------------------------------------------------------------------
struct NET_SIS_refuse_declare_broad : public tag_net_message
{
	NET_SIS_refuse_declare_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_refuse_declare_broad");
		dw_size = sizeof(NET_SIS_refuse_declare_broad);
	}
	DWORD dwDeclareGuildID;
	DWORD dwRefuseGuildID;
	TCHAR	szDeclareGuildName[X_SHORT_NAME];
	TCHAR	szRefuseGuildName[X_SHORT_NAME];
};

//-----------------------------------------------------------------------------
//帮会战时间提示
//-----------------------------------------------------------------------------
struct NET_SIS_guild_war_broad : public tag_net_message
{
	NET_SIS_guild_war_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_broad");
		dw_size = sizeof(NET_SIS_guild_war_broad);
	}
	DWORD	dwGuildID;
	DWORD   dwEnemyGuildID;
	EGuildWarState eGuildWarState;
	byte	byTime;		//3:45分钟 2: 30分钟 1:15分钟
};


//-----------------------------------------------------------------------------
//帮会战结果公告
//-----------------------------------------------------------------------------
struct NET_SIS_guild_war_outcome_broad : public tag_net_message
{
	NET_SIS_guild_war_outcome_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_outcome_broad");
		dw_size = sizeof(NET_SIS_guild_war_outcome_broad);
	}
	DWORD	dwWinGuild;			
	DWORD	dwAbortGuild;
	BOOL	bEqual;				// 是否平局
	BOOL	bTripodLost;		// 鼎炉是否无主
	BOOL	bDefenter;	
	DWORD	dwDaogao;			// 祷告者数量
	INT32	nFund;				// 获得资金
	TCHAR	szWinGuildName[X_SHORT_NAME];
	TCHAR	szAbortGuildName[X_SHORT_NAME];
};

//-----------------------------------------------------------------------------
//申请帮会战资格
//-----------------------------------------------------------------------------
struct NET_SIC_guild_war_qualify : public tag_net_message
{
	NET_SIC_guild_war_qualify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_war_qualify");
		dw_size = sizeof(NET_SIC_guild_war_qualify);
	}

	BOOL	bJoin;		// 0.离开 1,加入
};

struct NET_SIS_guild_war_qualify : public tag_net_message
{
	NET_SIS_guild_war_qualify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_qualify");
		dw_size = sizeof(NET_SIS_guild_war_qualify);
	}

	DWORD		dw_error_code;
};

//-----------------------------------------------------------------------------
//取消成员帮会战资格
//-----------------------------------------------------------------------------
struct NET_SIC_guild_war_dis_qualify : public tag_net_message
{
	NET_SIC_guild_war_dis_qualify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_war_dis_qualify");
		dw_size = sizeof(NET_SIC_guild_war_dis_qualify);
	}
	DWORD		dw_role_id;
};

struct NET_SIS_guild_war_dis_qualify : public tag_net_message
{
	NET_SIS_guild_war_dis_qualify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_dis_qualify");
		dw_size = sizeof(NET_SIS_guild_war_dis_qualify);
	}
	DWORD		dw_error_code;
};

// 帮会战成员列表变化
struct NET_SIS_guild_war_member_change : public tag_net_message
{
	NET_SIS_guild_war_member_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_war_member_change");
		dw_size = sizeof(NET_SIS_guild_war_member_change);
	}
	DWORD		dw_role_id;
	BOOL		m_bAdd;	   // false 离开 true 添加
};

//-----------------------------------------------------------------------------
// 获取帮派仓库物品信息
//-----------------------------------------------------------------------------
struct NET_SIC_get_guild_ware : public tag_net_message
{
	NET_SIC_get_guild_ware()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_ware");
		dw_size = sizeof(NET_SIC_get_guild_ware);
	}
	DWORD		dwNPCID;
	DWORD		dwLastUpdateTime;
};

struct NET_SIS_get_guild_ware : public tag_net_message
{
	NET_SIS_get_guild_ware()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_ware");
		dw_size = sizeof(NET_SIS_get_guild_ware);
	}
	DWORD		dw_error_code;
	DWORD		dwLastUpdateTime;
	INT16		nSzGuildWare;
	INT			nItemNum;
	BYTE		byData[1];
};

//-----------------------------------------------------------------------------
// 获取操作帮派仓库权限列表
//-----------------------------------------------------------------------------
struct NET_SIC_get_guild_ware_power_list : public tag_net_message
{
	NET_SIC_get_guild_ware_power_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_ware_power_list");
		dw_size = sizeof(NET_SIC_get_guild_ware_power_list);
	}
	DWORD		dwNPCID;
};

struct NET_SIS_get_guild_ware_power_list : public tag_net_message
{
	NET_SIS_get_guild_ware_power_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_ware_power_list");
		dw_size = sizeof(NET_SIS_get_guild_ware_power_list);
	}
	INT32			n_num;				// 列表中人数
	tagGuildWarePri	sGuildWarePri[1];	// 权限信息
};


//-----------------------------------------------------------------------------
// 变更操作帮派仓库权限
//-----------------------------------------------------------------------------
struct NET_SIC_change_guild_ware_power : public tag_net_message
{
	NET_SIC_change_guild_ware_power()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_change_guild_ware_power");
		dw_size = sizeof(NET_SIC_change_guild_ware_power);
	}
	DWORD		dwNPCID;
	DWORD		dw_role_id;
	BOOL		bCanUse;
};

struct NET_SIS_change_guild_ware_power : public tag_net_message
{
	NET_SIS_change_guild_ware_power()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_guild_ware_power");
		dw_size = sizeof(NET_SIS_change_guild_ware_power);
	}
	DWORD		dw_role_id;
	BOOL		bCanUse;
};


//-----------------------------------------------------------------------------
// 帮派状态改变
//-----------------------------------------------------------------------------
struct NET_SIS_guild_set_state : public tag_net_message
{
	NET_SIS_guild_set_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_set_state");
		dw_size = sizeof(NET_SIS_guild_set_state);
	}
	EGuildSpecState	eState;
};

struct NET_SIS_guild_unset_state : public tag_net_message
{
	NET_SIS_guild_unset_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_unset_state");
		dw_size = sizeof(NET_SIS_guild_unset_state);
	}
	EGuildSpecState	eState;
};

//-----------------------------------------------------------------------------
// 获取帮派设施升级信息
//-----------------------------------------------------------------------------
struct NET_SIC_get_guild_upgreae_info : public tag_net_message
{
	NET_SIC_get_guild_upgreae_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_upgreae_info");
		dw_size = sizeof(NET_SIC_get_guild_upgreae_info);
	}
	//DWORD					dwNPCID;
	EFacilitiesType			eFacType;
};

// 获取所有帮派设施信息
struct NET_SIS_get_guild_upgreade_info : public tag_net_message
{
	NET_SIS_get_guild_upgreade_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_upgreade_info");
		dw_size = sizeof(NET_SIS_get_guild_upgreade_info);
	}
	tagGuildFacilitiesInfo	sFacilitiesInfo[MAX_GUILD_FACILITIES_TYPE];
};

// 更新某一个帮派设施信息
struct NET_SIS_update_facilities_info : public tag_net_message
{
	NET_SIS_update_facilities_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_facilities_info");
		dw_size = sizeof(NET_SIS_update_facilities_info);
	}
	tagGuildFacilitiesInfo	sFacilitiesInfo;
};


//-----------------------------------------------------------------------------
// 上缴帮派设施升级所需物品
//-----------------------------------------------------------------------------
struct NET_SIC_turn_in_item : public tag_net_message
{
	NET_SIC_turn_in_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_turn_in_item");
		dw_size = sizeof(NET_SIC_turn_in_item);
	}
	DWORD					dwNPCID;
	EFacilitiesType			eType;
};


//-----------------------------------------------------------------------------
// 帮派设施升级
//-----------------------------------------------------------------------------
struct NET_SIC_upgrede_level : public tag_net_message
{
	NET_SIC_upgrede_level()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_upgrede_level");
		dw_size = sizeof(NET_SIC_upgrede_level);
	}
	EFacilitiesType			eType;
};


//-----------------------------------------------------------------------------
// 广播设施升级消息
//-----------------------------------------------------------------------------
struct NET_SIS_guild_upgrade : public tag_net_message
{
	NET_SIS_guild_upgrade()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_upgrade");
		dw_size = sizeof(NET_SIS_guild_upgrade);
	}
	EFacilitiesType			eType;
	BYTE					byNewLevel;
};


//-----------------------------------------------------------------------------
// 帮派事务发布消息
//-----------------------------------------------------------------------------
struct NET_SIC_issuance_guild_affair : public tag_net_message
{
	NET_SIC_issuance_guild_affair()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_issuance_guild_affair");
		dw_size = sizeof(NET_SIC_issuance_guild_affair);
	}
	DWORD					dwBuffID;
};

struct NET_SIS_issuance_guild_affair : public tag_net_message
{
	NET_SIS_issuance_guild_affair()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_issuance_guild_affair");
		dw_size = sizeof(NET_SIS_issuance_guild_affair);
	}
	DWORD					dwRole;			// 发布者
	DWORD					dwBuffID;
	BYTE					byRemainTimes;	// 每日剩余发布次数
};


//-----------------------------------------------------------------------------
// 帮派技能消息
//-----------------------------------------------------------------------------
struct NET_SIC_get_guild_skill_info : public tag_net_message
{
	NET_SIC_get_guild_skill_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_guild_skill_info");
		dw_size = sizeof(NET_SIC_get_guild_skill_info);
	}
};

struct NET_SIS_get_guild_skill_info : public tag_net_message
{
	NET_SIS_get_guild_skill_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_guild_skill_info");
		dw_size = sizeof(NET_SIS_get_guild_skill_info);
	}
	DWORD			dwCurSkillID;		// 当前研究技能
	INT16			n16Progress;		// 当前研究进度
	INT				nSkillNum;			// 帮派技能数量
	DWORD			dwSkillInfo[1];		// 帮派技能等级
};

struct NET_SIC_guild_skill_upgrade : public tag_net_message
{
	NET_SIC_guild_skill_upgrade()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_skill_upgrade");
		dw_size = sizeof(NET_SIC_guild_skill_upgrade);
	}
	INT64			n64ItemSerial;		// 上缴典籍64位ID
};

// 当前研究技能是否存在通过NET_SIS_set_research_skill发送
struct NET_SIS_guild_skill_upgrade : public tag_net_message
{
	NET_SIS_guild_skill_upgrade()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_skill_upgrade");
		dw_size = sizeof(NET_SIS_guild_skill_upgrade);
	}
	DWORD			dwSkillID;			// 升级技能ID
	INT16			n16Progress;		// 升级进度
};

struct NET_SIS_guild_skill_level_up : public tag_net_message
{
	NET_SIS_guild_skill_level_up()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_skill_level_up");
		dw_size = sizeof(NET_SIS_guild_skill_level_up);
	}
	DWORD			dwSkillID;
};

struct NET_SIC_learn_guild_skill : public tag_net_message
{
	NET_SIC_learn_guild_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_learn_guild_skill");
		dw_size = sizeof(NET_SIC_learn_guild_skill);
	}
	DWORD			dwSkillID;			// 欲学技能类型ID
};

struct NET_SIS_learn_guild_skill : public tag_net_message
{
	NET_SIS_learn_guild_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_learn_guild_skill");
		dw_size = sizeof(NET_SIS_learn_guild_skill);
	}
	DWORD			dw_error_code;		// 帮派与技能错误码枚举重叠,单独设置此消息
	DWORD			dwSkillID;			// 学习技能的ID
};

struct NET_SIC_research_skill : public tag_net_message
{
	NET_SIC_research_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_research_skill");
		dw_size = sizeof(NET_SIC_research_skill);
	}
	DWORD			dwSkillID;			// 设置当前研究技能,取消研究为INVALID_VALUE
};

struct NET_SIS_set_research_skill : public tag_net_message
{
	NET_SIS_set_research_skill()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_research_skill");
		dw_size = sizeof(NET_SIS_set_research_skill);
	}
	DWORD			dwSkillID;			// 返回当前研究技能ID
	INT16			n16Progress;		// 升级进度
};


//-----------------------------------------------------------------------------
// 帮派跑商相关
//-----------------------------------------------------------------------------
// 获取玩家商货信息
struct NET_SIC_get_commodity_info : public tag_net_message
{
	NET_SIC_get_commodity_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_commodity_info");
		dw_size = sizeof(NET_SIC_get_commodity_info);
	}
};

struct NET_SIS_get_commodity_info : public tag_net_message
{
	NET_SIS_get_commodity_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_commodity_info");
		dw_size = sizeof(NET_SIS_get_commodity_info);
	}
	INT32				nCurTael;		// 当前商银数量
	INT					nLevel;			// 接取跑商时的等级
	INT					nGoodNum;		// 商货数量
	tagCommerceGoodInfo	sGoodInfo[1];	// 商货信息
};

// 获取跑商初始信息
struct NET_SIC_get_tael_info : public tag_net_message
{
	NET_SIC_get_tael_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_tael_info");
		dw_size = sizeof(NET_SIC_get_tael_info);
	}
};

struct NET_SIS_get_tael_info : public tag_net_message
{
	NET_SIS_get_tael_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_tael_info");
		dw_size = sizeof(NET_SIS_get_tael_info);
	}
	INT				nLevel;				// 接取时玩家等级
};

// 获取跑商排名
struct NET_SIC_get_commerce_rank : public tag_net_message
{
	NET_SIC_get_commerce_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_commerce_rank");
		dw_size = sizeof(NET_SIC_get_commerce_rank);
	}
};

struct NET_SIS_get_commerce_rank : public tag_net_message
{
	NET_SIS_get_commerce_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_commerce_rank");
		dw_size = sizeof(NET_SIS_get_commerce_rank);
	}
	BOOL			bCommend;			// 嘉奖状态
	INT				nRankNum;			// 上榜人数
	tagCommerceRank	sRankInfo[1];		// 排名信息
};

// 接收跑商
struct NET_SIC_accept_commerce : public tag_net_message
{
	NET_SIC_accept_commerce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_accept_commerce");
		dw_size = sizeof(NET_SIC_accept_commerce);
	}
};

struct NET_SIS_accept_commerce : public tag_net_message
{
	NET_SIS_accept_commerce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_accept_commerce");
		dw_size = sizeof(NET_SIS_accept_commerce);
	}
	INT32			nBeginningTael;		// 初始商银
};

// 上缴商银
struct NET_SIC_complete_commerce : public tag_net_message
{
	NET_SIC_complete_commerce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_complete_commerce");
		dw_size = sizeof(NET_SIC_complete_commerce);
	}
};

// 上缴成功
struct NET_SIS_complete_commerce : public tag_net_message
{
	NET_SIS_complete_commerce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_complete_commerce");
		dw_size = sizeof(NET_SIS_complete_commerce);
	}
	DWORD			dw_role_id;			// 上缴人
	INT32			nFund;				// 贡献资金
};

// 放弃跑商
struct NET_SIC_abandon_commerce : public tag_net_message
{
	NET_SIC_abandon_commerce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_abandon_commerce");
		dw_size = sizeof(NET_SIC_abandon_commerce);
	}
};

// 成功放弃
struct NET_SIS_abandon_commerce : public tag_net_message
{
	NET_SIS_abandon_commerce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_abandon_commerce");
		dw_size = sizeof(NET_SIS_abandon_commerce);
	}
};

// 开关跑商嘉奖
struct NET_SIC_switch_commendation : public tag_net_message
{
	NET_SIC_switch_commendation()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_switch_commendation");
		dw_size = sizeof(NET_SIC_switch_commendation);
	}
	BOOL			bSwitchON;
};

// 广播嘉奖状态
struct NET_SIS_switch_commendation : public tag_net_message
{
	NET_SIS_switch_commendation()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_switch_commendation");
		dw_size = sizeof(NET_SIS_switch_commendation);
	}
	DWORD			dw_role_id;			// 设置人
	BOOL			bSwitchON;			// 嘉奖状态
};


//-----------------------------------------------------------------------------
// 跑商商会
//-----------------------------------------------------------------------------
// 获取商会商货信息
struct NET_SIC_get_chamber_goods_info : public tag_net_message
{
	NET_SIC_get_chamber_goods_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_chamber_goods_info");
		dw_size = sizeof(NET_SIC_get_chamber_goods_info);
	}
	DWORD				dwNPCID;		// 商会ID
};

struct NET_SIS_get_chamber_goods_info : public tag_net_message
{
	NET_SIS_get_chamber_goods_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_chamber_goods_info");
		dw_size = sizeof(NET_SIS_get_chamber_goods_info);
	}
	DWORD				dwCofCID;		// 商会ID
	BYTE				byHoldCity;		// 特产商会(0表示一般商会)
	INT					nGoodNum;		// 售卖商货数量
	tagCommerceGoodInfo	sGoodInfo[1];	// 商货信息
};

// 关闭商会
struct NET_SIC_colse_chamber : public tag_net_message
{
	NET_SIC_colse_chamber()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_colse_chamber");
		dw_size = sizeof(NET_SIC_colse_chamber);
	}
	DWORD				dwNPCID;		// 商会NPCID
};

struct NET_SIC_buy_chamber_goods : public tag_net_message
{
	NET_SIC_buy_chamber_goods()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_buy_chamber_goods");
		dw_size = sizeof(NET_SIC_buy_chamber_goods);
	}
	DWORD			dwNPCID;			// 商会NPCID
	DWORD			dwGoodID;			// 商货ID
	BYTE			byBuyNum;			// 购买数量
};

struct NET_SIC_sell_chamber_goods : public tag_net_message
{
	NET_SIC_sell_chamber_goods()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_sell_chamber_goods");
		dw_size = sizeof(NET_SIC_sell_chamber_goods);
	}
	DWORD			dwNPCID;
	DWORD			dwGoodID;
	BYTE			bySellNum;
};


//-----------------------------------------------------------------------------
// 通知离开帮会地图
//-----------------------------------------------------------------------------
struct NET_SIS_inform_leave_guild_map : public tag_net_message
{
	NET_SIS_inform_leave_guild_map()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_inform_leave_guild_map");
		dw_size = sizeof(NET_SIS_inform_leave_guild_map);
	}
	BYTE	byType;			// 1.升级 2.战斗准备 3.战斗结束 4.帮会降级 5.帮战死亡
};

//------------------------------------------------------------------------------

// 加入帮会招募榜
struct NET_SIC_join_guild_recruit : public tag_net_message
{
	NET_SIC_join_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_join_guild_recruit");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	DWORD	dw_guild_id;
};

struct NET_SIS_join_guild_recruit : public tag_net_message
{
	NET_SIS_join_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_join_guild_recruit");
		dw_size = sizeof(*this);
	}
	DWORD	dw_guild_id;
	DWORD dw_error;
};

// 离开帮会招募榜
struct NET_SIC_leave_guild_recruit : public tag_net_message
{
	NET_SIC_leave_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_guild_recruit");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
};

struct NET_SIS_leave_guild_recruit : public tag_net_message
{
	NET_SIS_leave_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_leave_guild_recruit");
		dw_size = sizeof(*this);
	}
	DWORD dw_error;
};

// 查询帮会招募榜信息
struct NET_SIC_query_guild_recruit : public tag_net_message
{
	NET_SIC_query_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_query_guild_recruit");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_query_guild_recruit : public tag_net_message
{
	NET_SIS_query_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_query_guild_recruit");
		dw_size = sizeof(*this);
	}
	//BOOL b_register;
	//INT	n_page;
	INT n_num;
	tag_guild_recrguit_info p_data[1];
};

// 查询某页帮会招募榜信息
struct NET_SIC_query_page_guild_recruit : public tag_net_message
{
	NET_SIC_query_page_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_query_page_guild_recruit");
		dw_size = sizeof(*this);
	}
	INT n_page;
};

//角色死亡帮会广播
struct NET_SIS_Role_Dead_broad : public tag_net_message
{
	NET_SIS_Role_Dead_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Role_Dead_broad");
		dw_size = sizeof(*this);
	}
	DWORD	dw_kill_id;
	DWORD	dw_dead_id;
};

// 开启帮会修炼
struct NET_SIC_Start_Guild_Practice : public tag_net_message
{
	NET_SIC_Start_Guild_Practice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Start_Guild_Practice");
		dw_size = sizeof(*this);
	}

	DWORD		dw_npc_id;
};

struct NET_SIS_Start_Guild_Practice : public tag_net_message
{
	NET_SIS_Start_Guild_Practice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Start_Guild_Practice");
		dw_size = sizeof(*this);
	}
	DWORD	dw_error;
};

struct NET_SIS_Guild_Practice_Broad : public tag_net_message
{
	NET_SIS_Guild_Practice_Broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_Practice_Broad");
		dw_size = sizeof(*this);
	}

	BOOL	b_Start;		// TRUE 开启 FALSE 关闭
};

// 获取帮会占领鼎信息
struct NET_SIC_Guild_Tripod_Info : public tag_net_message
{
	NET_SIC_Guild_Tripod_Info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Guild_Tripod_Info");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_Guild_Tripod_Info : public tag_net_message
{
	NET_SIS_Guild_Tripod_Info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_Tripod_Info");
		dw_size = sizeof(*this);
	}

	DWORD	dw_tripod_id;
	DWORD	dw_map_id;
};

// 获取帮会资金和帮主是否在线
struct NET_SIC_Get_Guild_Fund : public tag_net_message
{
	NET_SIC_Get_Guild_Fund()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Get_Guild_Fund");
		dw_size = sizeof(*this);
	}

	DWORD	dw_guild_id;
};

// 获取帮会资金和帮主是否在线
struct NET_SIS_Get_Guild_Fund : public tag_net_message
{
	NET_SIS_Get_Guild_Fund()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Get_Guild_Fund");
		dw_size = sizeof(*this);
	}

	DWORD	dw_error_code;
	DWORD	dw_guild_id;
	DWORD	dw_fund;
	BOOL	b_online;
	INT32	nOnlineNum;
	DWORD	dw_leader_id;
	BYTE	dw_guild_level;
};


// 获取帮会战绩
struct NET_SIC_Guild_War_History : public tag_net_message
{
	NET_SIC_Guild_War_History()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Guild_War_History");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_Guild_War_History : public tag_net_message
{
	NET_SIS_Guild_War_History()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_War_History");
		dw_size = sizeof(*this);
	}	
	INT		n_num;
	tagGuildWarHistory st_guild_war_history[1];
};

// 帮会战准备完毕
struct NET_SIC_Guild_War_Relay : public tag_net_message
{
	NET_SIC_Guild_War_Relay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Guild_War_Relay");
		dw_size = sizeof(*this);
	}
};


struct NET_SIS_Guild_War_Relay : public tag_net_message
{
	NET_SIS_Guild_War_Relay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_War_Relay");
		dw_size = sizeof(*this);
	}
	DWORD dw_error_code;
	BOOL bEenemy;   // 是否是对方准备好了
};


// 冲入帮会资金
struct NET_SIC_Guild_increase_fund : public tag_net_message
{
	NET_SIC_Guild_increase_fund()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Guild_increase_fund");
		dw_size = sizeof(*this);
	}
	INT32 nFund;
};

struct NET_SIS_Guild_increase_fund : public tag_net_message
{
	NET_SIS_Guild_increase_fund()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_increase_fund");
		dw_size = sizeof(*this);
	}
	INT32 nCurFund;
	DWORD dw_error_code;
};


// 帮战时更新双方人数
struct NET_SIS_Guil_war_member_number_update : public tag_net_message
{
	NET_SIS_Guil_war_member_number_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guil_war_member_number_update");
		dw_size = sizeof(*this);
	}

	DWORD dw_number;
	DWORD dw_enemy_number;
};

// 帮会战状态切换
struct NET_SIS_Guil_war_state_change : public tag_net_message
{
	NET_SIS_Guil_war_state_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guil_war_state_change");
		dw_size = sizeof(*this);
	}

	EGuildWarState eState;
	BOOL	bDefenter;
	BOOL	bUseMianzhan;
	TCHAR	szEnemyGuildName[X_SHORT_NAME]; // 敌对帮会名 只有进入报名时会发
};

// 同步免费复活次数
struct NET_SIS_War_Reborn_time : public tag_net_message
{
	NET_SIS_War_Reborn_time()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_War_Reborn_time");
		dw_size = sizeof(*this);
	}

	BYTE byTime;
};

// 占领鼎炉全服消息
struct NET_SIS_Guild_Tripod : public tag_net_message
{
	NET_SIS_Guild_Tripod()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_Tripod");
		dw_size = sizeof(*this);
	}
	TCHAR	szGuildName[X_SHORT_NAME]; 
};

// 材料回收
struct NET_SIC_Material_receive : public tag_net_message
{
	NET_SIC_Material_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Material_receive");
		dw_size = sizeof(*this);
	}

	DWORD	dw_item_id;
	INT		n_number;
};

struct NET_SIS_Material_receive : public tag_net_message
{
	NET_SIS_Material_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Material_receive");
		dw_size = sizeof(*this);
	}

	DWORD	dw_error_code;
};

// 资金捐献
struct NET_SIC_Guild_donate_fund : public tag_net_message
{
	NET_SIC_Guild_donate_fund()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Guild_donate_fund");
		dw_size = sizeof(*this);
	}
	BYTE byType; // 0:檀木香 1:沉水香 2:奇楠香
};

struct NET_SIS_Guild_donate_fund : public tag_net_message
{
	NET_SIS_Guild_donate_fund()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_donate_fund");
		dw_size = sizeof(*this);
	}
	DWORD dw_error_code;
};

//-----------------------------------------------------------------------------
// 获取所有帮会信息
//-----------------------------------------------------------------------------
struct NET_SIC_get_all_guild_info : public tag_net_message
{
	NET_SIC_get_all_guild_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_all_guild_info");
		dw_size = sizeof(NET_SIC_get_all_guild_info);
	}

	BOOL	bSBKList;	//是否是攻城列表

};

struct NET_SIS_get_all_guild_info : public tag_net_message
{
	NET_SIS_get_all_guild_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_all_guild_info");
		dw_size = sizeof(NET_SIS_get_all_guild_info);
	}
	INT nNum;
	tagGuildWarInfo s_guildInfo[1];
};

// 使用免战牌
struct NET_SIC_guild_mianzhan : public tag_net_message
{
	NET_SIC_guild_mianzhan()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_mianzhan");
		dw_size = sizeof(NET_SIC_guild_mianzhan);
	}
	INT64 n64ItemID;	//免战牌
};

struct NET_SIS_guild_mianzhan : public tag_net_message
{
	NET_SIS_guild_mianzhan()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_mianzhan");
		dw_size = sizeof(NET_SIS_guild_mianzhan);
	}
	DWORD dw_error_code;
};


// 通用帮会信息
struct NET_SIS_Guild_msg : public tag_net_message
{
	NET_SIS_Guild_msg()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Guild_msg");
		dw_size = sizeof(*this);
	}
	//TCHAR		szName[X_SHORT_NAME];
	//TCHAR		szTargetName[X_SHORT_NAME];
	INT32		nChangeValue;
	BYTE		byType;	// 1:资金 
};

struct NET_SIS_GuildMap_kill_role: public tag_net_message
{
	NET_SIS_GuildMap_kill_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_GuildMap_kill_role");
		dw_size = sizeof(*this);
	}

	DWORD dwKillerID;
	DWORD dwDeadID;
	DWORD dwMapID;
	float x;
	float z;

};

// 修改申请等级
struct NET_SIC_Modify_ApplyLevel : public tag_net_message
{
	NET_SIC_Modify_ApplyLevel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Modify_ApplyLevel");
		dw_size = sizeof(*this);
	}

	int		nLevel;
};

struct NET_SIS_Modify_ApplyLevel : public tag_net_message
{
	NET_SIS_Modify_ApplyLevel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Modify_ApplyLevel");
		dw_size = sizeof(*this);
	}

	int		nLevel;
	DWORD	dwErrorCode;
};


// 同意加入
struct NET_SIC_agree_join : public tag_net_message
{
	NET_SIC_agree_join()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_agree_join");
		dw_size = sizeof(*this);
	}

	DWORD	dwRoleID;
};

struct NET_SIS_agree_join : public tag_net_message
{
	NET_SIS_agree_join()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_agree_join");
		dw_size = sizeof(*this);
	}
	DWORD	dwRoleID;
	DWORD	dwErrorCode;
};

// 拒绝加入
struct NET_SIC_noagree_join : public tag_net_message
{
	NET_SIC_noagree_join()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_noagree_join");
		dw_size = sizeof(*this);
	}

	DWORD	dwRoleID;
};

struct NET_SIS_noagree_join : public tag_net_message
{
	NET_SIS_noagree_join()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_noagree_join");
		dw_size = sizeof(*this);
	}
	DWORD	dwRoleID;
	DWORD	dwErrorCode;
};

//报名参加攻城战
struct NET_SIC_sign_up_attack : public tag_net_message
{
	NET_SIC_sign_up_attack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_sign_up_attack");
		dw_size = sizeof(*this);
	}

};

struct NET_SIS_sign_up_attack : public tag_net_message
{
	NET_SIS_sign_up_attack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_sign_up_attack");
		dw_size = sizeof(*this);
	}
	DWORD dw_error_code;
};


// 请求沙巴克数据
struct NET_SIC_get_SBK_data : public tag_net_message
{
	NET_SIC_get_SBK_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_SBK_data");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_SBK_data : public tag_net_message
{
	NET_SIS_get_SBK_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_SBK_data");
		dw_size = sizeof(*this);
	}

	tagGuildSBKData	s_sbk_data;
};

// 领取沙巴克奖励
struct NET_SIC_get_SBK_reward : public tag_net_message
{
	NET_SIC_get_SBK_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_SBK_reward");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_SBK_reward : public tag_net_message
{
	NET_SIS_get_SBK_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_SBK_reward");
		dw_size = sizeof(*this);
	}

	DWORD	dw_error_code;
};

#pragma pack(pop)
#endif