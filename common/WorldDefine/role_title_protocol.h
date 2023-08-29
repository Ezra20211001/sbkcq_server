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
*	@file		role_title_protocol.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		角色称号消息
*/

#ifndef ROLE_TITLE_PROTOCOL
#define ROLE_TITLE_PROTOCOL

#pragma pack(push, 1)
#include "protocol_common_errorcode.h"
//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum
{
	E_Title_Success					= E_Success,	// 成功
	E_Title_NotVisible				= 1,			// 称号不可见
	E_Title_TitleNotObtained		= 2,			// 称号尚未获得
	E_Title_NoTitleActived			= 3,			// 角色尚未激活称号
	E_Title_TitleActivateFailed		= 4,			// 激活称号失败
	E_Title_UnknownError			= 5,			// 未知错误

	E_Title_Buy_Not_Find			= 6,			// 称号未找到
	E_Title_Buy_Not_point			= 7,			// 成就点数不足
	E_Title_Buy_Not_level			= 8,			// 等级不足	
	E_Titel_Buy_Not_Before			= 9,			// 无前置等级称号
	E_Title_Buy_Realy_Have			= 10,			// 称号已经有了
	E_Title_Buy_Cannot_buy			= 11,			// 该称号不能购买
	E_Title_Buy_Account_level_not	= 12,			// 账号充值数不足
	E_Title_Buy_Achievement_level_not= 13,			// 需求成就纹章等级不符
	E_Title_Buy_Has_Color			= 14,			// 该等级称号已有

	E_Title_Return_Cannot			= 20,			// 该称号不能归还
};

// 称号数据
struct tagTitleData
{
	DWORD dwTitleID;	// 称号id
	DWORD dwTime;		// 获得时间
};

//-----------------------------------------------------------------------------
// 设置角色使用某称号（u16TitleID无效时，表示不使用称号）
//-----------------------------------------------------------------------------
struct NET_SIC_use_role_title : public tag_net_message
{
	NET_SIC_use_role_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_use_role_title");
		dw_size = sizeof(NET_SIC_use_role_title);
	}
	DWORD			dw_role_id;		// 角色ID
	DWORD			u16TitleID;		// 当前使用的称号ID
	int				nIndex;
};

struct NET_SIS_use_role_title : public tag_net_message
{
	NET_SIS_use_role_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_use_role_title");
		dw_size = sizeof(NET_SIS_use_role_title);
	}
	DWORD			dw_error_code;	// 错误码
	DWORD			dw_role_id;		// 角色ID
	DWORD			u16TitleID;		// 称号ID
	int				nIndex;			
};

//-----------------------------------------------------------------------------
// 请求获得角色正在使用的称号
//-----------------------------------------------------------------------------
struct NET_SIC_get_using_titile : public tag_net_message
{
	NET_SIC_get_using_titile()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_using_titile");
		dw_size = sizeof(NET_SIC_get_using_titile);
	}
	DWORD			dw_role_id;		// 角色ID
};

//-----------------------------------------------------------------------------
// 返回获得角色正在使用的称号
//-----------------------------------------------------------------------------
struct NET_SIS_get_using_title : public tag_net_message
{
	NET_SIS_get_using_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_using_title");
		dw_size = sizeof(NET_SIS_get_using_title);
	}
	DWORD			dw_error_code;	// 错误码
	DWORD			dw_role_id;		// 角色ID
	DWORD			u16TitleID;		// title ID
};

//-----------------------------------------------------------------------------
// 请求获得角色拥有的所有称号
//-----------------------------------------------------------------------------
struct NET_SIC_get_role_titles : public tag_net_message
{
	NET_SIC_get_role_titles()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_role_titles");
		dw_size = sizeof(NET_SIC_get_role_titles);
	}
	DWORD			dw_role_id;		// 角色ID
};

//-----------------------------------------------------------------------------
// 返回角色拥有的所有称号(变长列表)
//-----------------------------------------------------------------------------
struct NET_SIS_get_role_titles : public tag_net_message
{
	NET_SIS_get_role_titles()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_role_titles");
		dw_size = sizeof(NET_SIS_get_role_titles);
	}
	DWORD			dw_error_code;	// 错误码
	DWORD			dw_role_id;		// 角色ID
	DWORD			u16TitleNum;	// 当前本地角色已获得的称号数量
	tagTitleData	byData[1];		// 当前本地角色已获得的称号ID
};

//-----------------------------------------------------------------------------
// 角色获得新称号(用来通知客户端)
//-----------------------------------------------------------------------------
struct NET_SIS_net_titles : public tag_net_message
{
	NET_SIS_net_titles()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_net_titles");
		dw_size = sizeof(NET_SIS_net_titles);
	}
	DWORD			dw_role_id;		// 角色ID
	DWORD			dw_title_id;	// 新获得称号
	DWORD			dw_time;		// 获得时间
};

//-----------------------------------------------------------------------------
// 删除称号
//-----------------------------------------------------------------------------
struct NET_SIS_delete_title : public tag_net_message
{
	NET_SIS_delete_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_title");
		dw_size = sizeof(NET_SIS_delete_title);
	}
	DWORD			dw_role_id;		// 角色ID
	DWORD			dw_title_id;	// 删除的称号
};


//-----------------------------------------------------------------------------
// 角色正在使用称号发生改变，给周围玩家广播
//-----------------------------------------------------------------------------
struct NET_SIS_role_title_change_broad : public tag_net_message
{
	NET_SIS_role_title_change_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_title_change_broad");
		dw_size = sizeof(NET_SIS_role_title_change_broad);
	}
	DWORD			dw_role_id;
	int				nIndex;
	DWORD			dwTitleID;		// 若玩家选择隐藏称号，该字段为INVALID_VALUE
};

// 购买称号
struct NET_SIC_role_title_buy : public tag_net_message
{
	struct NET_SIC_role_title_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_title_buy");
		dw_size = sizeof(NET_SIC_role_title_buy);
	}
	DWORD			dw_title_id;	// 称号id
};

// 购买称号
struct NET_SIS_role_title_buy : public tag_net_message
{
	struct NET_SIS_role_title_buy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_title_buy");
		dw_size = sizeof(NET_SIS_role_title_buy);
	}
	DWORD			dwErrorCode;	// 错误码
};

// 归还称号
struct NET_SIC_role_title_return : public tag_net_message
{
	struct NET_SIC_role_title_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_title_return");
		dw_size = sizeof(NET_SIC_role_title_return);
	}
	DWORD			dw_title_id;	// 称号id
};

// 归还称号
struct NET_SIS_role_title_return : public tag_net_message
{
	struct NET_SIS_role_title_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_title_return");
		dw_size = sizeof(NET_SIS_role_title_return);
	}
	DWORD			dw_title_id;	// 称号id
	DWORD			dwErrorCode;	// 错误码
};

//-----------------------------------------------------------------------------
//通知服务器是否显示当前激活的称号 gx add 2013.10.31
//-----------------------------------------------------------------------------
struct NET_SIC_show_active_title : public tag_net_message
{
	struct NET_SIC_show_active_title()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_show_active_title");
		dw_size = sizeof(NET_SIC_show_active_title);
	}
	INT bshow_title[3];//记录激活的三个称号是否显示给其他玩家
};

#pragma pack(pop)
#endif