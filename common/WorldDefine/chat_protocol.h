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
*	@file		chat_protocol.h
*	@author		lc
*	@date		2011/02/28	initial
*	@version	0.0.1.0
*	@brief		角色聊天消息
*/


#ifndef CHAR_PROTOCOL
#define CHAR_PROTOCOL

#include "protocol_common_errorcode.h"

#define MAX_NOTICE_TITLE	8
#define MAX_NOTICE_MSG_LEN	1024


#pragma pack(push, 1)

//在世界频道 发言 展示物品和装备 扣元气值
#define WORLD_CHANNEL_DEC_Fortune 1

//chat错误代码
enum
{
	E_RoleChat_ForbidChat				= 1,				//禁止发言
	E_RoleChat_ServerNotReady			= 2,				//服务器没有准备好
	E_RoleChat_TooLength				= 3,				//消息长度过长(超过100个字)

	E_RoleChat_Decree_OutOfYuanBao			= 10,				//诏告天下,元宝不足

	E_RoleChat_World_NoItem				= 20,				//世界,没有道具
	E_RoleChat_World_Frequently			= 21,				//世界,发言过快
	E_RoleChat_World_NoFortune			= 22,				//世界,元气不够
	E_RoleChat_World_RoleNo10			= 23,				//世界,人物没满10级

	E_RoleChat_Secret_RemoteRoleLeave	= 30,				//密语,对方不在线
	E_RoleChat_Secret_NoRoleName		= 31,				//密语,没有目标玩家 
	E_RoleChat_Secret_NoSelf			= 32,				//密语,自己不能与自己密语

	E_RoleChat_Map_Frequently			= 35,				//区域,发言过快
	E_RoleChat_Map_RoleNo10				= 36,				//区域,人物没满10级

	E_RoleChat_Guild_NoJoin				= 40,				//帮会,没有门派

	E_RoleChat_Team_NoJoin				= 50,				//队伍,没有队伍

	E_RoleChat_Common_Frequently		= 60,				//普通,发言过快
	E_RoleChat_Quest_Bag_Full			= 70,				//任务物品背包已满
	E_RoleChat_Not_GM					= 80,				//发言人不是GM

};

const DWORD MAX_CHAT_LEN = 200;						//客户端输入框最大输入

//! 向某人对话
struct NET_SIC_role_char : public tag_net_message
{
	NET_SIC_role_char()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_char");
		dw_size = sizeof(NET_SIC_role_char);
	}
	DWORD	dwDestRoleID;	//！向谁对话
	BYTE	byChannel;		//！频道
	BYTE	byAutoReply;	//！是否自动回复 0：不是 1：是
	DWORD	dw_safe_code;
	TCHAR	szMsg[1];		//！对话内容   
};

//! 某人和你对话
struct NET_SIS_role_char :public tag_net_message
{
	NET_SIS_role_char()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_char");
		dw_size = sizeof(NET_SIS_role_char);
	}
	DWORD	dw_error_code;	
	DWORD	dwSrcRoleID;	//！谁和你说话（INVALID_VALUE系统发送）
	DWORD	dwDestRoleID;	//！对谁说话
	BYTE	byChannel;		//！频道
	BYTE	byAutoReply;	//！是否自动回复 0:不是 1:是
	BYTE  bGM;
	TCHAR	szMsg[1];		//！对话内容
};

//！获取留言
struct NET_SIC_leave_word : public tag_net_message
{
	NET_SIC_leave_word()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_word");
		dw_size = sizeof(NET_SIC_leave_word);
	}
};

//! 自动公告
struct NET_SIS_auto_placard : public tag_net_message
{
	NET_SIS_auto_placard()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_auto_placard");
		dw_size = sizeof(NET_SIS_auto_placard);
	}
	INT				nType;							//! 字体颜色
	INT				nCirInterval;					//！循环间隔时间
	TCHAR			szContent[1];					//！公告内容
};


//! 右下角公告
struct NET_SIS_right_placard : public tag_net_message
{
	NET_SIS_right_placard()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_right_placard");
		dw_size = sizeof(NET_SIS_right_placard);
	}
	INT				nTitleLen;						//！标题长度
	INT				nLinkLen;						//！连接长度
	INT				nContentLen;					//！内容长度
	TCHAR			szContent[1];
};


#pragma pack(pop)
#endif