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
*	@file		team_protocol.h
*	@author		lc
*	@date		2011/03/04	initial
*	@version	0.0.1.0
*	@brief		组队消息
*/


#ifndef TEAM_PROTOCOL
#define TEAM_PROTOCOL
 

#include "protocol_common_errorcode.h"
#include "group_define.h"
#include "ItemDefine.h"

#pragma pack(push, 1)

// 错误码
enum
{
	E_Team_Not_Leader					=	1,		// 邀请方不是队长
	E_Team_Target_Not_Exit				=	2,		// 目标不合法
	E_Team_Target_Have_Team				=	3,		// 被邀请者已在小队中
	E_Team_Member_Full					=	4,		// 小队成员以满
	E_Team_Role_Not_In_Team				=	5,		// 踢出的玩家不在本小队
	E_Team_Pick_Model_Not_Exit			=	6,		// 所设置的拾取模式不存在
	E_Team_Target_Busy					=	7,		// 被邀请者正忙
	E_Team_Target_Not_Online			=	8,		// 被邀请玩家不在线
	E_Team_Map_CanNot_Invite			=	9,		// 该地图内无法邀请队友组队
	E_Team_Map_CanNot_Leave				=	10,		// 该地图内无法离开小队
	E_Team_Map_CanNor_ChangeLeader		=	11,		// 该地图内无法移交队长
	E_Team_Map_CanNot_Kick				=	12,		// 该地图内无法踢人
	E_Team_Map_NoHave_Team				=   13,		// 没有队伍
	E_Team_Apply_Have_Team				=   14,		// 申请者已经在队伍中
	E_Team_Have_Apply					=   15,		// 已经申请过了
	E_Team_Apply_Not_Online				=   16,		// 申请玩家不在线
	E_Team_Leader_Not_Agree				=	17,		// 队长拒绝要求
	E_Team_Placard_Too_Loog				=	18,		// 公告太长
	E_Team_Placard_Same_Before			=	19,		// 和之前相同	
	E_Team_Quality_Not_Exist			=	20,		// 物品品质不合法
	E_Team_Sice_GroundItemError			=	21,		// 掷骰子时，地物异常
	E_Team_Sice_Cant_RequireSice		=	22,		// 掷骰子时，不能需求掷骰
	E_Team_Assign_Your_Baggage_Not_Enough = 23,		// 获取分配物品时，背包已满.
	E_Team_Target_InDuel = 24,					// 对方正在进行切磋。
};

//---------------------------------------------------------------------
//申请入队
//---------------------------------------------------------------------
struct NET_SIC_apply_join_team : public tag_net_message
{
	NET_SIC_apply_join_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_apply_join_team");
		dw_size = sizeof(NET_SIC_apply_join_team);
	}
	DWORD		dwApplyeeID;		// 申请者目标ID
};

struct NET_SIS_apply_join_team : public tag_net_message
{
	NET_SIS_apply_join_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_apply_join_team");
		dw_size = sizeof(NET_SIS_apply_join_team);
	}
	DWORD		dwError;
};

struct NET_SIS_apply_data : public tag_net_message
{
	NET_SIS_apply_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_apply_data");
		dw_size = sizeof(NET_SIS_apply_data);
	}
	tagApplyRoleData st_ApplyRoleData;
	tagEquipTeamInfo st_EquipTeamInfo;
};


//---------------------------------------------------------------------
//申请入队反馈
//---------------------------------------------------------------------
struct NET_SIC_apply_join_team_reply : public tag_net_message
{
	NET_SIC_apply_join_team_reply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_apply_join_team_reply");
		dw_size = sizeof(NET_SIC_apply_join_team_reply);
	}
	DWORD		dwDestRoleID;			// 申请人ID
	BOOL		bApply;					// 是否同意申请
};

struct NET_SIS_apply_join_team_reply : public tag_net_message
{
	NET_SIS_apply_join_team_reply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_apply_join_team_reply");
		dw_size = sizeof(NET_SIS_apply_join_team_reply);
	}
	DWORD		dwApplyRoleID;			// 申请人ID
	DWORD		dwError;
};


//---------------------------------------------------------------------
//自建队伍
//---------------------------------------------------------------------
struct NET_SIC_own_create_team : public tag_net_message
{
	NET_SIC_own_create_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_own_create_team");
		dw_size = sizeof(NET_SIC_own_create_team);
	}
};

struct NET_SIS_own_create_team : public tag_net_message
{
	NET_SIS_own_create_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_own_create_team");
		dw_size = sizeof(NET_SIS_own_create_team);
	}
	DWORD	dwError;
};


//---------------------------------------------------------------------
//解散队伍
//---------------------------------------------------------------------
struct NET_SIC_dismiss_team : public tag_net_message
{
	NET_SIC_dismiss_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_dismiss_team");
		dw_size = sizeof(NET_SIC_dismiss_team);
	}
};

struct NET_SIS_dismiss_team : public tag_net_message
{
	NET_SIS_dismiss_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_dismiss_team");
		dw_size = sizeof(NET_SIS_dismiss_team);
	}
	DWORD	dwError;
};


//---------------------------------------------------------------------
//清空申请列表
//---------------------------------------------------------------------
struct NET_SIC_clean_apply : public tag_net_message
{
	NET_SIC_clean_apply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_clean_apply");
		dw_size = sizeof(NET_SIC_clean_apply);
	}
};

//---------------------------------------------------------------------
//队伍的一些提示消息
//---------------------------------------------------------------------
struct NET_SIS_Team_Msg : public tag_net_message
{
	NET_SIS_Team_Msg()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Team_Msg");
		dw_size = sizeof(NET_SIS_Team_Msg);
	}

	BYTE	byType; // 0:对方邀请你组队,但你有队伍了
	TCHAR	sz_role_name[X_SHORT_NAME];		// 对方名字
};


//---------------------------------------------------------------------
//队员重新上线
//---------------------------------------------------------------------
struct NET_SIS_member_online : public tag_net_message
{
	NET_SIS_member_online()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_member_online");
		dw_size = sizeof(NET_SIS_member_online);
	}
	DWORD dw_role_id;			// 上线队员ID
};

//---------------------------------------------------------------------
//队员邀请玩家组队
//---------------------------------------------------------------------
struct NET_SIC_member_invite_join_team : public tag_net_message
{
	NET_SIC_member_invite_join_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_member_invite_join_team");
		dw_size = sizeof(NET_SIC_member_invite_join_team);
	}
	DWORD		dwDestRoleID;			// 被邀请者ID
};

struct NET_SIS_member_invite_join_team : public tag_net_message
{
	NET_SIS_member_invite_join_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_member_invite_join_team");
		dw_size = sizeof(NET_SIS_member_invite_join_team);
	}
	DWORD		dwError;
};

struct NET_SIS_member_invite_join_team_to_leader : public tag_net_message
{
	NET_SIS_member_invite_join_team_to_leader()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_member_invite_join_team_to_leader");
		dw_size = sizeof(NET_SIS_member_invite_join_team_to_leader);
	}
	DWORD		dwDestRoleID;				// 被邀请者ID
	DWORD		dwTeamMemID;				// 提出邀请的队员ID
};

struct NET_SIC_member_invite_join_team_replay : public tag_net_message
{
	NET_SIC_member_invite_join_team_replay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_member_invite_join_team_replay");
		dw_size = sizeof(NET_SIC_member_invite_join_team_replay);
	}
	DWORD		dwTeamMemID;				// 提出邀请的队员ID
	DWORD		dwDestRoleID;				// 目标ID
	DWORD		bAgree;						// 是否同意
};

struct NET_SIS_member_invite_join_team_reply : public tag_net_message
{
	NET_SIS_member_invite_join_team_reply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_member_invite_join_team_reply");
		dw_size = sizeof(NET_SIS_member_invite_join_team_reply);
	}
	DWORD		dwDestRoleID;				// 队员邀请的目标ID
};

// 邀请组队
struct NET_SIC_invite_join_team : public tag_net_message
{
	NET_SIC_invite_join_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_invite_join_team");
		dw_size = sizeof(NET_SIC_invite_join_team);
	}
	DWORD		dwDestRoleID;		// 被邀请玩家	
};

// 邀请组队(返回给邀请者)
struct NET_SIS_invite_to_leader : public tag_net_message
{
	NET_SIS_invite_to_leader()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_to_leader");
		dw_size = sizeof(NET_SIS_invite_to_leader);
	}
	DWORD		dw_error_code;
};

// 邀请组队(返回给被邀请者)
struct NET_SIS_invite_join_team : public tag_net_message
{
	NET_SIS_invite_join_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_join_team");
		dw_size = sizeof(NET_SIS_invite_join_team);
	}
	DWORD					dwLeaderID;
	DWORD					dwDestRoleID;
};

// 玩家是否同意组队邀请
struct NET_SIC_invite_reply : public tag_net_message
{
	NET_SIC_invite_reply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_invite_reply");
		dw_size = sizeof(NET_SIC_invite_reply);
	}
	DWORD		dwLeaderID;
	BOOL		bAgree;				// 是否同意
};

struct NET_SIS_invite_reply : public tag_net_message
{
	NET_SIS_invite_reply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_reply");
		dw_size = sizeof(NET_SIS_invite_reply);
	}
	DWORD		dwTeamMemID[MAX_TEAM_NUM];
	BOOL		bAgree;
	DWORD		dw_error_code;
};

// 踢玩家出队
struct NET_SIC_kick_member : public tag_net_message
{
	NET_SIC_kick_member()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_kick_member");
		dw_size = sizeof(NET_SIC_kick_member);
	}
	DWORD		dwSrcRoleID;		// 队长	
	DWORD		dwDestRoleID;		// 被踢玩家
};

struct NET_SIS_kick_member : public tag_net_message
{
	NET_SIS_kick_member()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_kick_member");
		dw_size = sizeof(NET_SIS_kick_member);
	}
	DWORD		dwDestRoleID;
	DWORD		dw_error_code;
};

// 离开队伍
struct NET_SIC_leave_team : public tag_net_message
{
	NET_SIC_leave_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_team");
		dw_size = sizeof(NET_SIC_leave_team);
	}
};

// 包括主动离开和掉线
struct NET_SIS_leave_team : public tag_net_message
{
	NET_SIS_leave_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_leave_team");
		dw_size = sizeof(NET_SIS_leave_team);
	}
	BOOL		bLeaveLine;			
	DWORD		dw_role_id;
	DWORD		dwLeaderID;			// 队长ID
	DWORD		dw_error_code;
};

struct NET_SIC_set_pick_mode : public tag_net_message
{
	NET_SIC_set_pick_mode()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_pick_mode");
		dw_size = sizeof(NET_SIC_set_pick_mode);
	}
	EPickMode	ePickMode;			// 拾取模式
};

struct NET_SIS_set_pick_mode : public tag_net_message
{
	NET_SIS_set_pick_mode()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_pick_mode");
		dw_size = sizeof(NET_SIS_set_pick_mode);
	}
	EPickMode	ePickMode;
	DWORD		dw_error_code;
};

struct NET_SIC_change_leader : public tag_net_message
{
	NET_SIC_change_leader()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_change_leader");
		dw_size = sizeof(NET_SIC_change_leader);
	}
	DWORD		dwNewLeader;
};

struct NET_SIS_change_leader : public tag_net_message
{
	NET_SIS_change_leader()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_leader");
		dw_size = sizeof(NET_SIS_change_leader);
	}
	DWORD		dwLeaderID;
	DWORD		dwNewLeaderID;
	DWORD		dw_error_code;
};

struct NET_SIS_role_state_to_team : public tag_net_message
{
	NET_SIS_role_state_to_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_state_to_team");
		dw_size = sizeof(NET_SIS_role_state_to_team);
	}
	DWORD			dw_role_id;		// 玩家ID
	DWORD			dwMapID;
	EClassType		eClassEx;		// 职业
	BYTE		    bySex;
	INT				nLevel;
	INT				nMaxHP;
	INT				nHP;
	INT				nMaxMP;
	INT				nMP;
	FLOAT			fX;
	FLOAT			fZ;
	DWORD			dwEquipTypeID[TEAM_DISPLAY_NUM];	
	tagAvatarAtt	AvatarAtt;
	tagEquipTeamInfo st_EquipTeamInfo;
	BOOL			b_online;
	BOOL			b_leader;
};

struct NET_SIS_role_state_to_invitee : public tag_net_message
{
	NET_SIS_role_state_to_invitee()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_state_to_invitee");
		dw_size = sizeof(NET_SIS_role_state_to_invitee);
	}
	DWORD			dw_role_id;		// 玩家ID
	DWORD			dwMapID;
	EClassType    eClassEx;		// 职业
	BYTE		    bySex;
	INT				nLevel;
	INT				nMaxHP;
	INT				nHP;
	INT				nMaxMP;
	INT				nMP;
	FLOAT			fX;
	FLOAT			fZ;
	DWORD			dwEquipTypeID[TEAM_DISPLAY_NUM];	
	tagAvatarAtt	AvatarAtt;
	tagEquipTeamInfo st_EquipTeamInfo;
};


struct NET_SIS_role_position_to_team : public tag_net_message
{
	NET_SIS_role_position_to_team()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_position_to_team");
		dw_size = sizeof(NET_SIS_role_position_to_team);
	}
	DWORD		dw_role_id;
	DWORD		dwMapID;
	FLOAT		fX;
	FLOAT		fZ;
};

struct NET_SIS_get_team_id : public tag_net_message
{
	NET_SIS_get_team_id()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_team_id");
		dw_size = sizeof(NET_SIS_get_team_id);
	}
	DWORD		dwTeamID;
	EPickMode	ePickMode;
	TCHAR		szTeamPlacard[MAX_TEAM_PLACARD_LEN];
};

//---------------------------------------------------------------------
// 修改小队公告    add by gtj  10.11.09
//---------------------------------------------------------------------
struct NET_SIC_change_team_placard : public tag_net_message
{
	NET_SIC_change_team_placard()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_change_team_placard");
		dw_size = sizeof(NET_SIC_change_team_placard);
	}
	TCHAR			szTeamPlacard[1];
};

struct NET_SIS_change_team_placard : public tag_net_message
{
	NET_SIS_change_team_placard()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_team_placard");
		dw_size = sizeof(NET_SIS_change_team_placard);
	}
	DWORD			dw_role_id;
	TCHAR			szTeamPlacard[1];
};

struct NET_SIS_change_team_placard_fail : public tag_net_message
{
	NET_SIS_change_team_placard_fail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_change_team_placard_fail");
		dw_size = sizeof(NET_SIS_change_team_placard_fail);
	}
	DWORD		dw_error_code;
};


//--------------------------------------------------------------------
// 取得所在地图内所有队伍信息    add by gtj  10.11.09
//--------------------------------------------------------------------
struct NET_SIC_get_map_team_info : public tag_net_message
{
	NET_SIC_get_map_team_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_map_team_info");
		dw_size = sizeof(NET_SIC_get_map_team_info);
	}
};

struct NET_SIS_send_map_team_info : public tag_net_message
{
	NET_SIS_send_map_team_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_map_team_info");
		dw_size = sizeof(NET_SIS_send_map_team_info);
	}
	INT				nTeamNum;
	BYTE 			byData[1];
};


//--------------------------------------------------------------------
// 队伍分配  
//--------------------------------------------------------------------
//设置装备最低等级
struct NET_SIC_set_assign_quality : public tag_net_message
{
	NET_SIC_set_assign_quality()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_set_assign_quality");
		dw_size = sizeof(NET_SIC_set_assign_quality);
	}
	BYTE byQuality; //EItemQuality
};

struct NET_SIS_set_assign_quality : public tag_net_message
{
	NET_SIS_set_assign_quality()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_set_assign_quality");
		dw_size = sizeof(NET_SIS_set_assign_quality);
	}
	BYTE  byQuality; //EItemQuality
	DWORD dwError;
};

//队长分配
struct NET_SIC_team_lead_assign : public tag_net_message
{
	NET_SIC_team_lead_assign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_team_lead_assign");
		dw_size = sizeof(NET_SIC_team_lead_assign);
	}
	INT64 n64GroundID;
	DWORD dwMember;
};

struct NET_SIS_team_leader_assign : public tag_net_message
{
	NET_SIS_team_leader_assign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_team_leader_assign");
		dw_size = sizeof(NET_SIS_team_leader_assign);
	}
	INT64 n64GroundID;
	BYTE byQuality;
	DWORD dw_data_id;
	tagEquipViewInfo stEquipInfo;
};


//掷骰子
struct NET_SIS_team_assign_sicefor : public tag_net_message
{
	NET_SIS_team_assign_sicefor()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_team_assign_sicefor");
		dw_size = sizeof(NET_SIS_team_assign_sicefor);
	}
	INT64 n64GroundID;
	BYTE byQuality;
	DWORD dw_data_id;
	tagEquipViewInfo stEquipInfo;
};

struct NET_SIC_team_assign_sice : public tag_net_message
{
	NET_SIC_team_assign_sice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_team_assign_sice");
		dw_size = sizeof(NET_SIC_team_assign_sice);
	}
	BYTE  bySiceType;
	INT64 n64GroundID;	
};


//掷骰子结果
struct NET_SIS_team_assign_sice_result : public tag_net_message
{
	NET_SIS_team_assign_sice_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_team_assign_sice_result");
		dw_size = sizeof(NET_SIS_team_assign_sice_result);
	}
	INT64 n64GroundID;
	BYTE  byNumber;
	tagSiceResult stResult[MAX_TEAM_NUM];
};

struct NET_SIS_team_assign_error : public tag_net_message
{
	NET_SIS_team_assign_error()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_team_assign_error");
		dw_size = sizeof(NET_SIS_team_assign_error);
	}
	DWORD dwError;
};


//通知某人得到物品
struct NET_SIS_team_member_obtain_ground_item : public tag_net_message
{
	NET_SIS_team_member_obtain_ground_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_team_member_obtain_ground_item");
		dw_size = sizeof(NET_SIS_team_member_obtain_ground_item);
	}
	DWORD dw_role_id;
	INT64 n64GroundID;
	BYTE  byScore;
	BYTE  byType;//EPickSiceMode
};

// 队长广播
struct NET_SIS_team_leader_set : public tag_net_message
{
	NET_SIS_team_leader_set()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_team_leader_set");
		dw_size = sizeof(NET_SIS_team_leader_set);
	}
	DWORD dwRoleID;
	DWORD dwTeamID;
	BOOL  bLeader;
};
#pragma pack(pop)
#endif