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
 *	@file		GMRoleLogQueryProtocol
 *	@author		mwh
 *	@date		2011/07/11	initial
 *	@version	0.0.1.0
 *	@brief		gm工具查询角色资料
*/

#ifndef __GM_ROLE_LOG_QUERY_PROTOCOL_H__
#define __GM_ROLE_LOG_QUERY_PROTOCOL_H__

#pragma  pack(push,1)

#include "GMDefine.h"
#include "../common/WorldDefine/RoleDefine.h"

//! GM客户端->GM服务器
//根据平台账号ID进行查询 gx add 2013.11.05
struct NET_C2GMS_GetRoleListByThirdAccountID : public tag_net_message 
{ 
	NET_C2GMS_GetRoleListByThirdAccountID ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GetRoleListByThirdAccountID") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwThirdAccountID;//平台数字账号ID
	INT nThirdType;//平台类型
	TCHAR szServerName[X_SHORT_NAME];
}; 
//end
struct NET_C2GMS_GetRoleListByRoleID : public tag_net_message 
{ 
	NET_C2GMS_GetRoleListByRoleID ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GetRoleListByRoleID") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
}; 

struct NET_C2GMS_GetRoleListByAccountName : public tag_net_message 
{ 
	NET_C2GMS_GetRoleListByAccountName ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GetRoleListByAccountName") ;   
		dw_size = sizeof(*this) ; 
	} 
	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szAccountName[SHORT_STRING];
};

struct NET_C2GMS_GetRoleListByRoleName : public tag_net_message 
{ 
	NET_C2GMS_GetRoleListByRoleName ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GetRoleListByRoleName") ;   
		dw_size = sizeof(*this) ; 
	} 
	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szRoleName[SHORT_STRING];
}; 

struct NET_GMS2C_GetRoleList  : public tag_net_message
{
	NET_GMS2C_GetRoleList ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_GetRoleList") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwAccountID;
	tag_role_sim_info sRoleSimInfo[MAX_ROLENUM_ONEACCOUNT];//gx modify 2013.12.02合服需求
	TCHAR szAccountName[X_LONG_NAME];
	BOOL  bAccOL;
	DWORD dwThirdAccountID;//平台账号
	INT nThirdType;//平台类型
};

//! 查询删除角色列表
struct NET_C2GMS_GetDeleteRoleListByRoleID : public tag_net_message 
{ 
	NET_C2GMS_GetDeleteRoleListByRoleID ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GetDeleteRoleListByRoleID") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
}; 

struct NET_C2GMS_GetDeleteRoleListByAccountName : public tag_net_message 
{ 
	NET_C2GMS_GetDeleteRoleListByAccountName ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GetDeleteRoleListByAccountName") ;   
		dw_size = sizeof(*this) ; 
	} 
	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szAccountName[SHORT_STRING];
};

struct NET_C2GMS_GetDeleteRoleListByRoleName : public tag_net_message 
{ 
	NET_C2GMS_GetDeleteRoleListByRoleName ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GetDeleteRoleListByRoleName") ;   
		dw_size = sizeof(*this) ; 
	} 
	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szRoleName[SHORT_STRING];
}; 

struct NET_GMS2C_GetDeleteRoleList  : public tag_net_message
{
	NET_GMS2C_GetDeleteRoleList ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_GetDeleteRoleList") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	DWORD dwAccountID;
	tag_role_sim_info sRoleInfo[30];
};

//! 玩家资料
struct NET_C2GMS_GetRoleFullData : public tag_net_message 
{ 
	NET_C2GMS_GetRoleFullData ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GetRoleFullData") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
}; 

struct NET_GMS2C_GetRoleFullData  : public tag_net_message
{
	NET_GMS2C_GetRoleFullData ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_GetRoleFullData") ;   
		dw_size = sizeof(*this) ; 
	} 
	tag_role_data stData;
};

//! 被禁言角色列表
struct NET_C2GMS_GetForbidTalkRoleList : public tag_net_message 
{ 
	NET_C2GMS_GetForbidTalkRoleList ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GetForbidTalkRoleList") ;   
		dw_size = sizeof(*this) ; 
	} 
	TCHAR szServerName[X_SHORT_NAME];
}; 

struct NET_GMS2C_GetForbidTalkRoleList  : public tag_net_message
{
	NET_GMS2C_GetForbidTalkRoleList ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_GetForbidTalkRoleList") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_forbid_talk_role stData[1];
};

//! 被封停的账号列表
struct NET_C2GMS_GetForbidAccountList : public tag_net_message 
{ 
	NET_C2GMS_GetForbidAccountList ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GetForbidAccountList") ;   
		dw_size = sizeof(*this) ; 
	} 
	TCHAR szServerName[X_SHORT_NAME];
}; 

struct NET_GMS2C_GetForbidAccountList  : public tag_net_message
{
	NET_GMS2C_GetForbidAccountList ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_GetForbidAccountList") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_forbid_account stData[1];
};

//! 返回出生点
struct NET_C2GMS_RoleGoHome : public tag_net_message 
{ 
	NET_C2GMS_RoleGoHome ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_RoleGoHome") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
}; 
//! 日志查询结束
struct NET_GMS2C_QueryLogFinish : public tag_net_message 
{ 
	NET_GMS2C_QueryLogFinish ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryLogFinish") ;   
		dw_size = sizeof(*this) ; 
	} 
}; 

//! 道具log
struct NET_C2GMS_QueryRoleItemLog : public tag_net_message 
{ 
	NET_C2GMS_QueryRoleItemLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryRoleItemLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	tag_time_bound stTime;
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
}; 
struct NET_GMS2C_QueryRoleItemLog : public tag_net_message 
{ 
	NET_GMS2C_QueryRoleItemLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryRoleItemLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_item_log item_log[1];
}; 

//! 某一具体道具
struct NET_C2GMS_QueryOneItemLog : public tag_net_message 
{ 
	NET_C2GMS_QueryOneItemLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryOneItemLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT64 n64Serial;
	tag_time_bound stTime;
	TCHAR szServerName[X_SHORT_NAME];
}; 

struct NET_GMS2C_QueryOneItemLog : public tag_net_message 
{ 
	NET_GMS2C_QueryOneItemLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryOneItemLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_item_log item_log[1];
}; 

//! 金钱log
struct NET_C2GMS_QueryRoleMoneyLog : public tag_net_message 
{ 
	NET_C2GMS_QueryRoleMoneyLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryRoleMoneyLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	tag_time_bound stTime;
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
}; 
struct NET_GMS2C_QueryRoleMoneyLog : public tag_net_message 
{ 
	NET_GMS2C_QueryRoleMoneyLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryRoleMoneyLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_money_log money_log[1];
}; 

//! 元宝log
struct NET_C2GMS_QueryRoleYuanBaoLog : public tag_net_message 
{ 
	NET_C2GMS_QueryRoleYuanBaoLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryRoleYuanBaoLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	tag_time_bound stTime;
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
}; 
struct NET_GMS2C_QueryRoleYuanBaoLog : public tag_net_message 
{ 
	NET_GMS2C_QueryRoleYuanBaoLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryRoleYuanBaoLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_yuanbao_log yuanbao_log[1];
}; 

//! 战功log
struct NET_C2GMS_QueryRoleexploitsLog : public tag_net_message 
{ 
	NET_C2GMS_QueryRoleexploitsLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryRoleexploitsLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	tag_time_bound stTime;
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
}; 
struct NET_GMS2C_QueryRoleexploitsLog : public tag_net_message 
{ 
	NET_GMS2C_QueryRoleexploitsLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryRoleexploitsLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_exploits_log exploits_log[1];
};

//! GM 工具
struct NET_C2GMS_QueryGMLog : public tag_net_message 
{ 
	NET_C2GMS_QueryGMLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryGMLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	tag_time_bound stTime;
	DWORD dwGMAccountID; // 0: 查询所有gm , 非0: 插叙指定gm
}; 
struct NET_C2GMS_QueryGMLogByAccount : public tag_net_message 
{ 
	NET_C2GMS_QueryGMLogByAccount ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryGMLogByAccount") ;   
		dw_size = sizeof(*this) ; 
	} 
	tag_time_bound stTime;
	TCHAR sz_account_name[X_SHORT_NAME]; // 指定gm账号 
};
struct NET_GMS2C_QueryGMLog : public tag_net_message 
{ 
	NET_GMS2C_QueryGMLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryGMLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_gm_log gm_log[1];
}; 

//! bank log
struct NET_C2GMS_QueryRoleBankLog : public tag_net_message 
{ 
	NET_C2GMS_QueryRoleBankLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryRoleBankLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	tag_time_bound stTime;
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
}; 
struct NET_GMS2C_QueryRoleBankLog : public tag_net_message 
{ 
	NET_GMS2C_QueryRoleBankLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryRoleBankLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_bank_log bank_log[1];
}; 

//! paimai log
struct NET_C2GMS_QueryRolePaiMaiLog : public tag_net_message 
{ 
	NET_C2GMS_QueryRolePaiMaiLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryRolePaiMaiLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	tag_time_bound stTime;
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
}; 
struct NET_GMS2C_QueryRolePaiMaiLog : public tag_net_message 
{ 
	NET_GMS2C_QueryRolePaiMaiLog ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryRolePaiMaiLog") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_paimai_log paimai_log[1];
}; 

//! item number
struct NET_C2GMS_QueryItemNumberByType : public tag_net_message 
{ 
	NET_C2GMS_QueryItemNumberByType ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryItemNumberByType") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwTypeID;
	TCHAR szServerName[X_SHORT_NAME];
}; 
struct NET_GMS2C_QueryItemNumberByType : public tag_net_message 
{ 
	NET_GMS2C_QueryItemNumberByType ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryItemNumberByType") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
}; 

//! 查询全服帮会列表
struct NET_C2GMS_QueryGuildList : public tag_net_message 
{ 
	NET_C2GMS_QueryGuildList ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryGuildList") ;   
		dw_size = sizeof(*this) ; 
	} 
	TCHAR szServerName[X_SHORT_NAME];
}; 
struct NET_GMS2C_QueryGuildList : public tag_net_message 
{ 
	NET_GMS2C_QueryGuildList ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryGuildList") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_guild_basic stData[1];
}; 

//! 查询帮会基础资料
struct NET_C2GMS_QueryGuildData : public tag_net_message 
{ 
	NET_C2GMS_QueryGuildData ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryGuildData") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dw_guild_id;
	TCHAR szServerName[X_SHORT_NAME];
}; 
struct NET_GMS2C_QueryGuildData : public tag_net_message 
{ 
	NET_GMS2C_QueryGuildData ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryGuildData") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_guild_data stData;
}; 

//! 查询帮会角色列表
struct NET_C2GMS_QueryGuildMember : public tag_net_message 
{ 
	NET_C2GMS_QueryGuildMember ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_QueryGuildMember") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dw_guild_id;
	TCHAR szServerName[X_SHORT_NAME];
}; 
struct NET_GMS2C_QueryGuildMember : public tag_net_message 
{ 
	NET_GMS2C_QueryGuildMember ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_QueryGuildMember") ;   
		dw_size = sizeof(*this) ; 
	} 
	INT nNumber;
	tag_guild_member stData[1];
}; 

//! 修复悬赏任务的标志
struct NET_C2GMS_VerifyGDQuestFlag : public tag_net_message
{
	NET_C2GMS_VerifyGDQuestFlag()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2GMS_VerifyGDQuestFlag");
		dw_size = sizeof(*this);
	}
	DWORD dwRoleID;
	TCHAR szServerName[X_SHORT_NAME];
};

struct NET_GMS2C_VerifyGDQuestFlag : public tag_net_message
{
	NET_GMS2C_VerifyGDQuestFlag()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2C_VerifyGDQuestFlag");
		dw_size = sizeof(*this);
	}
	DWORD dwError;
};

#pragma pack(pop)

#endif //__GM_ROLE_LOG_QUERY_PROTOCOL_H__