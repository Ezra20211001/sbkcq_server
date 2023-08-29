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
*	@file		role_info_protocol.h
*	@author		lc
*	@date		2011/03/11	initial
*	@version	0.0.1.0
*	@brief		角色信息消息
*/

#ifndef ROLE_INFO_PROTOCOL
#define ROLE_INFO_PROTOCOL


#include "protocol_common_errorcode.h"

#pragma pack(push, 1)

// 得到某角色ID
struct NET_SIC_role_get_id : public tag_net_message
{
	NET_SIC_role_get_id()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_get_id");
		dw_size = sizeof(NET_SIC_role_get_id);
	}
	DWORD	dwRoleNameCrc;	// 角色名字crc32
};

// 返回某角色ID	
struct NET_SIS_role_get_id : public tag_net_message
{
	NET_SIS_role_get_id()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_get_id");
		dw_size = sizeof(NET_SIS_role_get_id);
	}
	DWORD	dwRoleNameCrc;	// 角色名称crc32
	DWORD	dw_role_id;		// 请求目标玩家的roleid, = INVALID_VALUE表示不存在
	TCHAR	szName[X_SHORT_NAME];	// name
};

// 得到name
struct NET_SIC_get_name_by_nameid : public tag_net_message
{
	NET_SIC_get_name_by_nameid()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_name_by_nameid");
		dw_size = sizeof(NET_SIC_get_name_by_nameid);
	}
	DWORD	dwNameID;			// NameID
};

// 返回name
struct NET_SIS_get_name_by_nameid : public tag_net_message
{
	NET_SIS_get_name_by_nameid()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_name_by_nameid");
		dw_size = sizeof(NET_SIS_get_name_by_nameid);
	}
	BOOL	bResult;				// TRUE = 成功
	DWORD	dwNameID;				// 请求NameID
	TCHAR	szName[X_SHORT_NAME];	// name
};


// 一次请求多个ID对应的名字
struct NET_SIC_role_set_some_name : public tag_net_message
{
	NET_SIC_role_set_some_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_set_some_name");
		dw_size = sizeof(NET_SIC_role_set_some_name);
	}
	INT		nUserData;
	INT		n_num;		// id的数量
	DWORD	dwAllID[1];	// 变长数组,存放dwNum个id
};


// 玩家ID和名字对应的结构
struct tagRoleIDName
{
	DWORD dwID;
	TCHAR szName[X_SHORT_NAME];
};

struct NET_SIS_role_get_some_name : public tag_net_message
{
	NET_SIS_role_get_some_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_get_some_name");
		dw_size = sizeof(NET_SIS_role_get_some_name);
	}
	INT				nUserData;
	INT				n_num;				// 名字数量
	tagRoleIDName	IdName[1];
};

// 得到某角色签名
struct NET_SIC_role_get_signature_name : public tag_net_message
{
	NET_SIC_role_get_signature_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_get_signature_name");
		dw_size = sizeof(NET_SIC_role_get_signature_name);
	}
	DWORD	dw_role_id;	// 角色ID
};

// 返回某角色签名	
struct NET_SIS_role_get_signature_name : public tag_net_message
{
	NET_SIS_role_get_signature_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_get_signature_name");
		dw_size = sizeof(NET_SIS_role_get_signature_name);
	}
	DWORD	dw_role_id;				// 请求目标玩家的roleid, = INVALID_VALUE表示不存在
	TCHAR	szName[X_SHORT_NAME];	// 签名
	byte	by_sex;					// 性别
	INT		nLevel;					// 等级
	INT		nClass;					// 职业
};

// 修改签名
struct NET_SIC_role_set_signature_name : public tag_net_message
{
	NET_SIC_role_set_signature_name()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_role_set_signature_name");
		dw_size = sizeof(NET_SIC_role_set_signature_name);
	}
	TCHAR	szName[X_SHORT_NAME];	// 签名
};

// 疑似加速,将被踢下线
struct NET_SIS_will_kick : public tag_net_message
{
	NET_SIS_will_kick()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_will_kick");
		dw_size = sizeof(NET_SIS_will_kick);
	}

	DWORD dwTime;		//多长时间被踢掉(毫秒)
};
#pragma pack(pop)
#endif



