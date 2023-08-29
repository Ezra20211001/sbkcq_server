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
*	@file		social_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		社交消息
*/

#ifndef SOCIAL_PROTOCOL
#define SOCIAL_PROTOCOL


#include "protocol_common_errorcode.h"

#pragma pack(push, 1)

// 错误码
enum
{
	E_Friend_Target_Not_Exist			=	1,		// 目标不存在
	E_Friend_Target_Not_Sel				=	2,		// 不能加自己为好友
	E_Friend_Target_Black_List			=	3,		// 黑名单内的玩家无法被添加为好友
	E_Friend_Target_Already_Exit		=	4,		// 该好友已存在于好友列表
	E_Friend_Max_Num					=	5,		// 好友列表名单是否达到上限100人
	E_Friend_Group_Not_Exit				=	6,		// 分组不存在
	E_Friend_Not_Friend					=	7,		// 不是该玩家好友

	E_Black_Targer_Not_Sel				=	20,		// 不能加自己到黑名单
	E_Black_Max_Num						=	21,		// 黑名单已满
	E_Black_Target_Already_Exit			=	22,		// 玩家已在黑名单中
	E_Black_Target_Not_Exit				=	23,		// 玩家不在黑名单中
	
	E_Enemy_Target_Not_Exit				=   24,		// 玩家不在仇人中
	E_Enemy_No_OnLine					=   25,		// 仇人不在线

	E_Gift_Not_Exit						=	30,		// 礼物不存在
	E_Gift_Not_Both_Friend				=	31,		// 不是双向好友
	E_Gift_Friend_Not_Online			=	32,		// 好友不在线
	E_Gift_Not_Gift						=	33,		// 所送的物品不是礼物

	E_Compractice_No_OnLine				=	34,		//被邀请方不在线
	E_Compractice_Local_InPractice		=	35,		//本地玩家正在双修中
	E_Compractice_Remote_InPractice		=	36,		//远程玩家正在双修中
	E_Compractice_InStall				=	37,		//玩家处于摆摊中
	E_Compractice_Local_Practice_Full	=	38,		//邀请方今日双修次数已满
	E_Compractice_Remote_Practice_Full	=	39,		//被邀请方今日双修次数已满
	E_Compractice_Disagree				=	40,		//被邀请方不同意
	E_Compractice_Long					=	41,		//距离太远

	E_Propose_Male_Married				=	42,		//男方已有配偶
	E_Propose_Female_Married			=	43,		//女方已有配偶
	E_Propose_Female_Disagree			=	44,		//女方不同意结婚
	E_Propose_Marray_Level				=	45,		//玩家结婚等级不足
	E_Propose_Marry_Lack_Item			=	46,		//缺少婚戒
	E_Divorce_Lack_Yuanbao				=	47,		//离婚元宝不足
	E_Propose_No_Team					=	48,		//必须男女双方组成一队
	E_Propose_No_Map					=	49,		//必须在特定地图结婚

	E_Compractice_Level					=	50,		//双修的玩家必须大于20级
	E_Compractice_Sex					=	51,		//必须是异性双修
	E_Compractice_NotSafearea			=	52,		//双修双方均需在安全区内

	E_Comparctice_Role_Invited			=	53,		//玩家正在被邀请中
	
	E_QBJJ_LEVEL_Min_Woman				=	54,		//女方等级不足 gx add 2013.10.25
	E_QBJJ_LEVEL_MIN_Man				=	55,		//男方等级不足		
	E_QBJJ_RED_NO						=	56,		//女方未获得红唇认证
	E_QBJJ_RED_NO_REWARD				=	57,		//当前没有要领取的奖励
};

// 玩家上线时通知好友
struct NET_SIS_login_to_friend : public tag_net_message
{
	NET_SIS_login_to_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_login_to_friend");
		dw_size = sizeof(NET_SIS_login_to_friend);
	}
	DWORD	dw_role_id;
};

// 玩家下线时通知好友
struct NET_SIS_logout_to_friend : public tag_net_message
{
	NET_SIS_logout_to_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_logout_to_friend");
		dw_size = sizeof(NET_SIS_logout_to_friend);
	}
	DWORD	dw_role_id;
};

// 想和谁结交为好友
struct NET_SIC_role_make_friend : public tag_net_message
{
	NET_SIC_role_make_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_make_friend");
		dw_size = sizeof(NET_SIC_role_make_friend);
	}
	DWORD	dwDestRoleID;	
};

struct NET_SIS_role_make_friend : public tag_net_message
{
	NET_SIS_role_make_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_make_friend");
		dw_size = sizeof(NET_SIS_role_make_friend);
	}
	DWORD	dwDestRoleID;
	BOOL	bOnline;
	INT		nLevel;				// 角色等级
	EClassType eClassType;
	BYTE	by_sex;					// 性别
	DWORD	dw_error_code;
};

// 取消好友关系
struct NET_SIC_role_cancel_friend : public tag_net_message
{
	NET_SIC_role_cancel_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_cancel_friend");
		dw_size = sizeof(NET_SIC_role_cancel_friend);
	}
	DWORD   dwDestRoleID;
};

struct NET_SIS_role_cancel_friend : public tag_net_message
{
	NET_SIS_role_cancel_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_cancel_friend");
		dw_size = sizeof(NET_SIS_role_cancel_friend);
	}
	DWORD   dwDestRoleID;
	BYTE	byGroup;
	DWORD	dw_error_code;
};

// 好友分组
struct NET_SIC_update_friend_group : public tag_net_message
{
	NET_SIC_update_friend_group()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_update_friend_group");
		dw_size = sizeof(NET_SIC_update_friend_group);
	}
	DWORD	dwDestRoleID;
	BYTE	byGroup;
};

struct NET_SIS_update_friend_group : public tag_net_message
{
	NET_SIS_update_friend_group()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_friend_group");
		dw_size = sizeof(NET_SIS_update_friend_group);
	}
	DWORD	dwDestRoleID;
	BYTE	byOldGroup;			// 1-4：好友列表
	BYTE	byNewGroup;
	DWORD	dw_error_code;
};

// 加入玩家到黑名单
struct NET_SIC_move_to_black_list : public tag_net_message
{
	NET_SIC_move_to_black_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_move_to_black_list");
		dw_size = sizeof(NET_SIC_move_to_black_list);
	}
	DWORD	dwDestRoleID;
};

struct NET_SIS_move_to_black_list : public tag_net_message
{
	NET_SIS_move_to_black_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_move_to_black_list");
		dw_size = sizeof(NET_SIS_move_to_black_list);
	}
	DWORD	dwDestRoleID;
	BYTE	byOldGroup;
	BOOL	bOnline;
	INT		nLevel;				// 角色等级
	EClassType eClassType;
	BYTE	by_sex;	
	DWORD	dw_error_code;
};

// 将玩家从黑名单删除
struct NET_SIC_delete_black_list : public tag_net_message
{
	NET_SIC_delete_black_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_black_list");
		dw_size = sizeof(NET_SIC_delete_black_list);
	}
	DWORD	dwDestRoleID;
};

struct NET_SIS_delete_black_list : public tag_net_message
{
	NET_SIS_delete_black_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_black_list");
		dw_size = sizeof(NET_SIS_delete_black_list);
	}
	DWORD	dwDestRoleID;
	DWORD	dw_error_code;
};


// 删除仇人
struct NET_SIC_delete_enemy_list : public tag_net_message
{
	NET_SIC_delete_enemy_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_enemy_list");
		dw_size = sizeof(NET_SIC_delete_enemy_list);
	}
	DWORD	dwDestRoleID;
};

struct NET_SIS_delete_enemy_list : public tag_net_message
{
	NET_SIS_delete_enemy_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_enemy_list");
		dw_size = sizeof(NET_SIS_delete_enemy_list);
	}
	DWORD	dwDestRoleID;
	DWORD	dw_error_code;
};


// 获取仇人位置
struct NET_SIC_get_enemy_position : public tag_net_message
{
	NET_SIC_get_enemy_position()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_enemy_position");
		dw_size = sizeof(NET_SIC_get_enemy_position);
	}
	DWORD	dwDestRoleID;
};

struct NET_SIS_get_enemy_position : public tag_net_message
{
	NET_SIS_get_enemy_position()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_enemy_position");
		dw_size = sizeof(NET_SIS_get_enemy_position);
	}
	FLOAT	fx;
	FLOAT	fz;
	DWORD	dw_role_id;
	DWORD	dwMapID;
	DWORD	dw_error_code;
};


// 添加仇人
struct NET_SIC_add_enemy : public tag_net_message
{
	NET_SIC_add_enemy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_add_enemy");
		dw_size = sizeof(NET_SIC_add_enemy);
	}
	DWORD	dwDestRoleID;
};

struct NET_SIS_add_enemy : public tag_net_message
{
	NET_SIS_add_enemy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_add_enemy");
		dw_size = sizeof(NET_SIS_add_enemy);
	}
	DWORD	dwDestRoleID;
	INT		nLevel;
	EClassType eClassType;
	BOOL	bOnline;
	BYTE	by_sex;	
};
//gx modify 2013.6.27
// 送礼物
struct NET_SIC_send_gift : public tag_net_message
{
	NET_SIC_send_gift()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_send_gift");
		dw_size = sizeof(NET_SIC_send_gift);
	}
	DWORD	dwDestRoleID;		// 礼物接收者
	//INT64	n64ItemID;			// 礼物ID
	BYTE	byLevel;			//送花等级	1代表1朵，2代表9朵，3代表99朵
};

struct NET_SIS_send_gift_to_friend : public tag_net_message
{
	NET_SIS_send_gift_to_friend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_gift_to_friend");
		dw_size = sizeof(NET_SIS_send_gift_to_friend);
	}
	DWORD	dwSrcRoleID;		// 礼物发送者
	//DWORD	dw_data_id;			// 物品类型ID
	BYTE	byLevel;			//送花等级
	DWORD   byAddValue;			//增加的魅力值
	DWORD	dw_error_code;		//错误信息
};
//end
// 收礼物
struct NET_SIS_send_gift_to_sender : public tag_net_message
{
	NET_SIS_send_gift_to_sender()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_gift_to_sender");
		dw_size = sizeof(NET_SIS_send_gift_to_sender);
	}
	DWORD	dw_error_code;
};

// 收到礼物后回复
struct NET_SIC_send_gift_reply : public tag_net_message
{
	NET_SIC_send_gift_reply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_gift_reply");
		dw_size = sizeof(NET_SIC_send_gift_reply);
	}
	DWORD	dwSrcRoleID;		// 礼物发送者
	DWORD	dw_data_id;			// 礼物TypeID
	BOOL	bResult;			// 是否接收
};

// 广播
struct NET_SIS_send_gift_broad : public tag_net_message
{
	NET_SIS_send_gift_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_gift_broad");
		dw_size = sizeof(NET_SIS_send_gift_broad);
	}
	DWORD	dwSrcRoleID;
	DWORD	dwDestRoleID;
	DWORD	dw_data_id;
	BOOL	bResult;
};


struct NET_SIC_update_friend_state : public tag_net_message
{
	NET_SIC_update_friend_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_update_friend_state");
		dw_size = sizeof(NET_SIC_update_friend_state);
	}
};

struct NET_SIS_update_friend_state : public tag_net_message
{
	NET_SIS_update_friend_state()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_friend_state");
		dw_size = sizeof(NET_SIS_update_friend_state);
	}
	INT				n_num;
	tagFriUpdate	FriUpdate[1];
};

struct NET_SIS_make_friend_notice : public tag_net_message
{
	NET_SIS_make_friend_notice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_make_friend_notice");
		dw_size = sizeof(NET_SIS_make_friend_notice);
	}
	DWORD	dw_role_id;
};

struct NET_SIS_update_friend_value : public tag_net_message
{
	NET_SIS_update_friend_value()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_friend_value");
		dw_size = sizeof(NET_SIS_update_friend_value);
	}
	DWORD   dw_role_id;
	INT		nFriVal;
};
//双修相关消息定义 gx add 2013.6.27
// 邀请玩家进行双修
struct NET_SIC_invite_practice: public tag_net_message
{
	NET_SIC_invite_practice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_invite_practice");
		dw_size = sizeof(NET_SIC_invite_practice);
	}
	DWORD		dwDestRoleID;		// 被邀请玩家	
};
// 邀请双修(返回给双方)
struct NET_SIS_invite_practice_to_both: public tag_net_message
{
	NET_SIS_invite_practice_to_both()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_practice_to_both");
		dw_size = sizeof(NET_SIS_invite_practice_to_both);
	}
	DWORD		dwSrcRoleID;//邀请人ID
	DWORD		dw_error_code;
};
// 被邀请人回复邀请双修
struct NET_SIC_invite_practice_reply: public tag_net_message
{
	NET_SIC_invite_practice_reply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_invite_practice_reply");
		dw_size = sizeof(NET_SIC_invite_practice_reply);
	}
	DWORD		dwSrcRoleID;//邀请人ID
	BOOL		bAgree;				// 是否同意
};
// 被邀请人回复邀请后给邀请人的回复
struct NET_SIS_invite_practice_to_src: public tag_net_message
{
	NET_SIS_invite_practice_to_src()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_invite_practice_to_src");
		dw_size = sizeof(NET_SIS_invite_practice_to_src);
	}
	DWORD		dwSrcRoleID;//邀请人ID
	DWORD		dwDesRoleID;//被邀请人ID
	DWORD		dw_error_code;
};

// 玩家进入双修后发视野消息
struct NET_SIS_practice_to_all: public tag_net_message
{
	NET_SIS_practice_to_all()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_practice_to_all");
		dw_size = sizeof(NET_SIS_practice_to_all);
	}
	DWORD		dwSrcRoleID;//邀请人ID
	DWORD		dwDesRoleID;//被邀请人ID
};
//玩家主动取消双修
struct NET_SIC_cancel_practice: public tag_net_message
{
	NET_SIC_cancel_practice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_cancel_practice");
		dw_size = sizeof(NET_SIC_cancel_practice);
	}
	DWORD dwPartnerID;//与之双修的角色ID
};
struct NET_SIS_cancel_practice: public tag_net_message
{
	NET_SIS_cancel_practice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_cancel_practice");
		dw_size = sizeof(NET_SIS_cancel_practice);
	}
	DWORD dw_error_code;
};
//end by gx 
////结婚相关消息定义 gx add 2013.7.3
// 男性玩家向女性玩家求婚
struct NET_SIC_male_propose: public tag_net_message
{
	NET_SIC_male_propose()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_male_propose");
		dw_size = sizeof(NET_SIC_male_propose);
	}
	DWORD		dwDestRoleID;		// 女性玩家	
};
// 求婚(返回给双方)
struct NET_SIS_propose_to_both: public tag_net_message
{
	NET_SIS_propose_to_both()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_propose_to_both");
		dw_size = sizeof(NET_SIS_propose_to_both);
	}
	DWORD		dwSrcRoleID;//求婚人ID
	DWORD		dw_error_code;
};
// 被求婚人回复男性玩家求婚
struct NET_SIC_propose_reply: public tag_net_message
{
	NET_SIC_propose_reply()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_propose_reply");
		dw_size = sizeof(NET_SIC_propose_reply);
	}
	DWORD		dwSrcRoleID;//男性角色ID
	BOOL		bAgree;				// 女性玩家是否同意
};
// 被求婚人回复求婚邀请后给双方的回复
struct NET_SIS_propose_reply_to_both: public tag_net_message
{
	NET_SIS_propose_reply_to_both()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_propose_reply_to_both");
		dw_size = sizeof(NET_SIS_propose_reply_to_both);
	}
	DWORD		dwSrcRoleID;//男性角色ID
	DWORD		dwDesRoleID;//女性角色ID
	DWORD		dw_error_code;
};
//离婚
struct NET_SIC_role_divorce: public tag_net_message
{
	NET_SIC_role_divorce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_divorce");
		dw_size = sizeof(NET_SIC_role_divorce);
	}
};
//
struct NET_SIS_role_divorce_to_both: public tag_net_message
{
	NET_SIS_role_divorce_to_both()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_divorce_to_both");
		dw_size = sizeof(NET_SIS_role_divorce_to_both);
	}
	DWORD	dw_SrcRole_ID;//主动提出离婚的一方ID	
	DWORD	dw_error_code;
};
//领取情比金坚奖 gx add 2013.10.25
struct NET_SIC_get_qbjj_reward:public tag_net_message
{
	NET_SIC_get_qbjj_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_qbjj_reward");
		dw_size = sizeof(NET_SIC_get_qbjj_reward);
	}
};
struct NET_SIS_get_qbjj_reward:public tag_net_message
{
	NET_SIS_get_qbjj_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_qbjj_reward");
		dw_size = sizeof(NET_SIS_get_qbjj_reward);
	}
	DWORD dw_error_code;
};
//伴侣上线发给另一方 gx add 2013.10.29
struct NET_SIS_login_to_spouse:public tag_net_message
{
	NET_SIS_login_to_spouse()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_login_to_spouse");
		dw_size = sizeof(NET_SIS_login_to_spouse);
	}
};
//伴侣下线发给另一方
struct NET_SIS_logout_to_spouse:public tag_net_message
{
	NET_SIS_logout_to_spouse()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_logout_to_spouse");
		dw_size = sizeof(NET_SIS_logout_to_spouse);
	}
};
#pragma pack(pop)
#endif