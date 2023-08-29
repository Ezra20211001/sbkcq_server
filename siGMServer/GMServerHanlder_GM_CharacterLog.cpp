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
*	@file		GMServerHanlder_GM_Characterlog.cpp
*	@author		mwh
*	@date		2011/07/11	initial
*	@version	0.0.1.0
*	@brief		查询角色log
*/

#include "stdafx.h"
#include "GMServerHanlder.h"
#include "GMPlayer.h"
#include "LogDB.h"
#include "GMLogQueryManager.h"
#include "GMLogHelper.h"
#include "../common/WorldDefine/GMRoleLogQueryProtocol.h"

#define  SprintfT(Table, Month, Day)\
	char szTableName[128]={0};\
	sprintf_s(szTableName, sizeof(szTableName), "%s_%02d%02d", Table, Month, Day);

const static int MONTH_DAY[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
static int PostFixTableBuffer[7][2]={{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}};

INT CalcPosFixOfTable(tag_time_bound& InputTime)
{
	if(!InputTime.Check()) return 0;

	INT nPostFixNumber = 0; memset(PostFixTableBuffer, 0, sizeof(PostFixTableBuffer));
	if(InputTime.start_month == InputTime.end_month)
	{
		for(int n = InputTime.start_day;
			n <= InputTime.end_day && n <= MONTH_DAY[InputTime.end_month] && nPostFixNumber < 7;
			++n, ++nPostFixNumber)
		{ 
			PostFixTableBuffer[nPostFixNumber][0] = InputTime.end_month; 
			PostFixTableBuffer[nPostFixNumber][1] = n; 
		}
	}
	else
	{
		for(int n = InputTime.start_day;
			n <= MONTH_DAY[InputTime.start_month] && nPostFixNumber < 7;
			++n, ++nPostFixNumber)
		{ 
			PostFixTableBuffer[nPostFixNumber][0] = InputTime.start_month; 
			PostFixTableBuffer[nPostFixNumber][1] = n; 
		}

		for(int n = 1;
			n <= MONTH_DAY[InputTime.end_month] && n <= InputTime.end_day && nPostFixNumber < 7;
			++n, ++nPostFixNumber)
		{ 
			PostFixTableBuffer[nPostFixNumber][0] = InputTime.end_month; 
			PostFixTableBuffer[nPostFixNumber][1] = n; 
		}
	}
	return nPostFixNumber;
}


VOID SetDeleteRoleListPacket(const tag_Role_Del_List& crList,  NET_GMS2C_GetDeleteRoleList& rProtocol)
{
	rProtocol.nNumber = 0;
	for(int n = 0; n < (int)crList.v_role_del.size() && rProtocol.nNumber < _countof(rProtocol.sRoleInfo); ++n)
	{
		++rProtocol.nNumber;
		rProtocol.sRoleInfo->dw_role_id = crList.v_role_id[n];
		_tcsncpy(rProtocol.sRoleInfo->sz_role_name, crList.v_role_del[n].c_str(), X_SHORT_NAME);
	}
	rProtocol.dw_size -= ((_countof(rProtocol.sRoleInfo) - rProtocol.nNumber) * sizeof(tag_role_sim_info));
}
//=================================================
//	 查询账号角色
//=================================================
DWORD GMServerHanlder::HandleQueryRoleListByRoleID(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_GetRoleListByRoleID* xProtocol = (NET_C2GMS_GetRoleListByRoleID*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pDB)) 
	{
		NET_GMS2C_GetRoleList send;
		BOOL bAccOL = FALSE;
		DWORD dw_account_id = pDB->get_account_by_role_id(xProtocol->dwRoleID);
		if(!VALID_POINT(dw_account_id))
		{
			send.dwAccountID = 0;
			xGMPlayer->SendMessage(&send, send.dw_size);
			return INVALID_VALUE;
		}

		send.dwAccountID = dw_account_id;
		pDB->get_role_list(dw_account_id, send.sRoleSimInfo, MAX_ROLENUM_ONEACCOUNT);//gx add 2013.12.02合服后角色增加需求变更，下同

		LogDB* pAccountDB = g_LogQueryMgr.GetAccountDB( );
		if(VALID_POINT(pAccountDB)) pAccountDB->get_account_name_by_id(dw_account_id, send.szAccountName, send.bAccOL);
		if(VALID_POINT(pAccountDB)) pAccountDB->get_third_data_by_account_id(dw_account_id,send.dwThirdAccountID,send.nThirdType);
		xGMPlayer->SendMessage(&send, send.dw_size);
	}
	return 0;
}
//根据平台账号ID获得该账号下的角色信息 gx add 2013.11.05
DWORD GMServerHanlder::HandleQueryRoleListByThirdAccountID(tag_net_message* pMsg,DWORD dwParam)
{
	NET_C2GMS_GetRoleListByThirdAccountID* xProtocol = (NET_C2GMS_GetRoleListByThirdAccountID*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pAccountDB = g_LogQueryMgr.GetLoginLogDB();
	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pDB) && VALID_POINT(pAccountDB))
	{
		NET_GMS2C_GetRoleList send;
		DWORD dw_account_id = 0; 
		if(!pAccountDB->get_account_id_by_third_account_id(xProtocol->dwThirdAccountID,xProtocol->nThirdType,dw_account_id))
		{
			send.dwAccountID = 0;
			xGMPlayer->SendMessage(&send, send.dw_size);
			return INVALID_VALUE;
		}
		send.dwAccountID = dw_account_id;
		pDB->get_role_list(dw_account_id, send.sRoleSimInfo, MAX_ROLENUM_ONEACCOUNT);
		pAccountDB->get_account_name_by_id(dw_account_id, send.szAccountName, send.bAccOL);
		pAccountDB->get_third_data_by_account_id(dw_account_id,send.dwThirdAccountID,send.nThirdType);
		xGMPlayer->SendMessage(&send, send.dw_size);
	}
	return 0;
}
DWORD GMServerHanlder::HandleQueryRoleListByAccountName(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_GetRoleListByAccountName* xProtocol = (NET_C2GMS_GetRoleListByAccountName*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pAccountDB = g_LogQueryMgr.GetLoginLogDB();
	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pDB) && VALID_POINT(pAccountDB))
	{
		NET_GMS2C_GetRoleList send;
		DWORD dw_account_id = 0; BOOL bAccOL = FALSE;
		if(!pAccountDB->get_account_id_by_account_name(xProtocol->szAccountName, dw_account_id, bAccOL))
		{
			send.dwAccountID = 0;
			xGMPlayer->SendMessage(&send, send.dw_size);
			return INVALID_VALUE;
		}

		
		send.bAccOL = bAccOL;
		send.dwAccountID = dw_account_id;
		pDB->get_role_list(dw_account_id, send.sRoleSimInfo, MAX_ROLENUM_ONEACCOUNT);
		_tcscpy_s(send.szAccountName, SHORT_STRING, xProtocol->szAccountName);
		pAccountDB->get_third_data_by_account_id(dw_account_id,send.dwThirdAccountID,send.nThirdType);
		xGMPlayer->SendMessage(&send, send.dw_size);
	}
	return 0;
}

DWORD GMServerHanlder::HandleQueryRoleListByRoleName(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_GetRoleListByRoleName* xProtocol = (NET_C2GMS_GetRoleListByRoleName*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	DWORD dw_account_id = 0;
	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pDB))
	{
		NET_GMS2C_GetRoleList send;
		dw_account_id = pDB->get_account_by_role_name(get_tool()->crc32(xProtocol->szRoleName));
		if(!VALID_POINT(dw_account_id))
		{
			send.dwAccountID = 0;
			xGMPlayer->SendMessage(&send, send.dw_size);
			return INVALID_VALUE;
		}
		
		send.dwAccountID = dw_account_id;
		pDB->get_role_list(dw_account_id, send.sRoleSimInfo, MAX_ROLENUM_ONEACCOUNT);
		LogDB* pAccountDB = g_LogQueryMgr.GetAccountDB( );
		if(VALID_POINT(pAccountDB)) pAccountDB->get_account_name_by_id(dw_account_id, send.szAccountName, send.bAccOL);
		if(VALID_POINT(pAccountDB)) pAccountDB->get_third_data_by_account_id(dw_account_id,send.dwThirdAccountID,send.nThirdType);
		xGMPlayer->SendMessage(&send, send.dw_size);
	}
	return 0;
}

// 取得删除角色列表
DWORD GMServerHanlder::HandleQueryDeleteRoleListByRoleID(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_GetDeleteRoleListByRoleID* xProtocol = (NET_C2GMS_GetDeleteRoleListByRoleID*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pDB)) 
	{
		NET_GMS2C_GetDeleteRoleList send;
		DWORD dw_account_id = pDB->get_account_by_role_id(xProtocol->dwRoleID);
		if(!VALID_POINT(dw_account_id))
		{
			send.dwAccountID = 0;
			xGMPlayer->SendMessage(&send, send.dw_size);
			return INVALID_VALUE;
		}
		send.dwAccountID = dw_account_id;

		tag_Role_Del_List slist; 
		pDB->get_role_del_list(dw_account_id, slist);
		SetDeleteRoleListPacket(slist, send);
		xGMPlayer->SendMessage(&send, send.dw_size);
	}
	return 0;
}

DWORD GMServerHanlder::HandleQueryDeleteRoleListByAccountName(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_GetDeleteRoleListByAccountName* xProtocol = (NET_C2GMS_GetDeleteRoleListByAccountName*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pAccountDB = g_LogQueryMgr.GetLoginLogDB();
	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pDB) && VALID_POINT(pAccountDB))
	{
		NET_GMS2C_GetDeleteRoleList send;
		DWORD dw_account_id = 0; BOOL bOL;
		if(!pAccountDB->get_account_id_by_account_name(xProtocol->szAccountName, dw_account_id, bOL))
		{
			send.dwAccountID = 0;
			xGMPlayer->SendMessage(&send, send.dw_size);
			return INVALID_VALUE;
		}

		send.dwAccountID = dw_account_id;

		tag_Role_Del_List slist; 
		pDB->get_role_del_list(dw_account_id, slist);
		SetDeleteRoleListPacket(slist, send);
		xGMPlayer->SendMessage(&send, send.dw_size);
	}
	return 0;
}

DWORD GMServerHanlder::HandleQueryDeleteRoleListByRoleName(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_GetDeleteRoleListByRoleName* xProtocol = (NET_C2GMS_GetDeleteRoleListByRoleName*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	DWORD dw_account_id = 0;
	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pDB))
	{
		NET_GMS2C_GetDeleteRoleList send;
		dw_account_id = pDB->get_account_by_role_name(get_tool()->crc32(xProtocol->szRoleName));
		if(!VALID_POINT(dw_account_id))
		{
			send.dwAccountID = 0;
			xGMPlayer->SendMessage(&send, send.dw_size);
			return INVALID_VALUE;
		}

		send.dwAccountID = dw_account_id;

		tag_Role_Del_List slist; 
		pDB->get_role_del_list(dw_account_id, slist);
		SetDeleteRoleListPacket(slist, send);
		xGMPlayer->SendMessage(&send, send.dw_size);
	}
	return 0;
}
DWORD GMServerHanlder::HandleQueryRoleData(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_GetRoleFullData* xProtocol = (NET_C2GMS_GetRoleFullData*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pDB))
	{
		NET_GMS2C_GetRoleFullData temp;
		NET_GMS2C_GetRoleFullData* pSend = (NET_GMS2C_GetRoleFullData*)GetCommonBuffer();
		if(!VALID_POINT(pSend)) return -1;
		pSend->dw_size = temp.dw_size - sizeof(BYTE);
		pSend->dw_message_id = temp.dw_message_id;
		pDB->get_role_full_data(xProtocol->dwRoleID, pSend);

		LogDB* pAccountDB = g_LogQueryMgr.GetLoginLogDB();
		pSend->stData.b_gm = !VALID_POINT(pAccountDB) ?  FALSE :
				pAccountDB->is_gm_account(pSend->stData.dw_account_id);

		xGMPlayer->SendMessage(pSend, pSend->dw_size);
	}
	return 0;
}
//!
DWORD GMServerHanlder::HandleRoleGoHome(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_RoleGoHome* xProtocol = (NET_C2GMS_RoleGoHome*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pDB)) pDB->role_go_home(xProtocol->dwRoleID);
	return 0;
}
//! 查询角色log
DWORD GMServerHanlder::HandleQueryRoleItemLog(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryRoleItemLog* xProtocol = (NET_C2GMS_QueryRoleItemLog*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetLogDB(get_tool()->crc32(xProtocol->szServerName));
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_QueryRoleItemLog temp;
	NET_GMS2C_QueryRoleItemLog* pSend = (NET_GMS2C_QueryRoleItemLog*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;
	
	INT nPostfixNumber = CalcPosFixOfTable(xProtocol->stTime);

	for(INT n = 0; n < nPostfixNumber; ++n)
	{
		pSend->nNumber = 0; 
		pSend->dw_message_id = temp.dw_message_id;
		pSend->dw_size = temp.dw_size - sizeof(tag_item_log);
		
		SprintfT("log_item", PostFixTableBuffer[n][0], PostFixTableBuffer[n][1]); 
		VOID* p_buffer = pSend->item_log;
		pDB->get_item_log(szTableName, p_buffer, -1, xProtocol->dwRoleID, pSend->dw_size, pSend->nNumber);
		xGMPlayer->SendMessage(pSend, pSend->dw_size);
	}

	NET_GMS2C_QueryLogFinish send;
	xGMPlayer->SendMessage(&send, send.dw_size);

	return 0;
}
DWORD GMServerHanlder::HandleQueryRoleMoneyLog(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryRoleMoneyLog* xProtocol = (NET_C2GMS_QueryRoleMoneyLog*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetLogDB(get_tool()->crc32(xProtocol->szServerName));
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_QueryRoleMoneyLog temp;
	NET_GMS2C_QueryRoleMoneyLog* pSend = (NET_GMS2C_QueryRoleMoneyLog*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	INT nPostfixNumber = CalcPosFixOfTable(xProtocol->stTime);

	for(INT n = 0; n < nPostfixNumber; ++n)
	{
		pSend->nNumber = 0; 
		pSend->dw_message_id = temp.dw_message_id;
		pSend->dw_size = temp.dw_size - sizeof(tag_money_log);

		SprintfT("log_money", PostFixTableBuffer[n][0], PostFixTableBuffer[n][1]); 
		VOID* p_buffer = pSend->money_log;
		pDB->get_money_log(szTableName, p_buffer, -1, xProtocol->dwRoleID, pSend->dw_size, pSend->nNumber);
		xGMPlayer->SendMessage(pSend, pSend->dw_size);
	}

	NET_GMS2C_QueryLogFinish send;
	xGMPlayer->SendMessage(&send, send.dw_size);

	return 0;
}
DWORD GMServerHanlder::HandleQueryRoleExploitsLog(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryRoleexploitsLog* xProtocol = (NET_C2GMS_QueryRoleexploitsLog*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetLogDB(get_tool()->crc32(xProtocol->szServerName));
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_QueryRoleexploitsLog temp;
	NET_GMS2C_QueryRoleexploitsLog* pSend = (NET_GMS2C_QueryRoleexploitsLog*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	INT nPostfixNumber = CalcPosFixOfTable(xProtocol->stTime);

	for(INT n = 0; n < nPostfixNumber; ++n)
	{
		pSend->nNumber = 0; 
		pSend->dw_message_id = temp.dw_message_id;
		pSend->dw_size = temp.dw_size - sizeof(tag_money_log);

		SprintfT("log_money", PostFixTableBuffer[n][0], PostFixTableBuffer[n][1]); 
		VOID* p_buffer = pSend->exploits_log;
		pDB->get_exploits_log(szTableName, p_buffer, -1, xProtocol->dwRoleID, pSend->dw_size, pSend->nNumber);
		xGMPlayer->SendMessage(pSend, pSend->dw_size);
	}

	NET_GMS2C_QueryLogFinish send;
	xGMPlayer->SendMessage(&send, send.dw_size);

	return 0;
}
DWORD GMServerHanlder::HandleQueryRoleYuanBaoLog(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryRoleYuanBaoLog* xProtocol = (NET_C2GMS_QueryRoleYuanBaoLog*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetLogDB(get_tool()->crc32(xProtocol->szServerName));
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_QueryRoleYuanBaoLog temp;
	NET_GMS2C_QueryRoleYuanBaoLog* pSend = (NET_GMS2C_QueryRoleYuanBaoLog*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	INT nPostfixNumber = CalcPosFixOfTable(xProtocol->stTime);

	for(INT n = 0; n < nPostfixNumber; ++n)
	{
		pSend->nNumber = 0; 
		pSend->dw_message_id = temp.dw_message_id;
		pSend->dw_size = temp.dw_size - sizeof(tag_yuanbao_log);

		SprintfT("log_yuanbao", PostFixTableBuffer[n][0], PostFixTableBuffer[n][1]); 
		VOID* p_buffer = pSend->yuanbao_log;
		pDB->get_yuanbao_log(szTableName, p_buffer, -1, xProtocol->dwRoleID, pSend->dw_size, pSend->nNumber);
		xGMPlayer->SendMessage(pSend, pSend->dw_size);
	}

	NET_GMS2C_QueryLogFinish send;
	xGMPlayer->SendMessage(&send, send.dw_size);

	return 0;
}

DWORD GMServerHanlder::HandleQueryOneItemLog(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryOneItemLog* xProtocol = (NET_C2GMS_QueryOneItemLog*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetLogDB(get_tool()->crc32(xProtocol->szServerName));
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_QueryOneItemLog temp;
	NET_GMS2C_QueryOneItemLog* pSend = (NET_GMS2C_QueryOneItemLog*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	INT nPostfixNumber = CalcPosFixOfTable(xProtocol->stTime);

	for(INT n = 0; n < nPostfixNumber; ++n)
	{
		pSend->nNumber = 0; 
		pSend->dw_message_id = temp.dw_message_id;
		pSend->dw_size = temp.dw_size - sizeof(tag_item_log);

		SprintfT("log_item", PostFixTableBuffer[n][0], PostFixTableBuffer[n][1]); 
		VOID* p_buffer = pSend->item_log;
		pDB->get_item_log_by_serial(szTableName, p_buffer, xProtocol->n64Serial >> 32, 
													xProtocol->n64Serial & 0xFFFFFFFF, pSend->dw_size, pSend->nNumber);
		xGMPlayer->SendMessage(pSend, pSend->dw_size);
	}

	NET_GMS2C_QueryLogFinish send;
	xGMPlayer->SendMessage(&send, send.dw_size);

	return 0;
}
DWORD GMServerHanlder::HandleQueryBankLog(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryRoleBankLog* xProtocol = (NET_C2GMS_QueryRoleBankLog*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetLogDB(get_tool()->crc32(xProtocol->szServerName));
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_QueryRoleBankLog temp;
	NET_GMS2C_QueryRoleBankLog* pSend = (NET_GMS2C_QueryRoleBankLog*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	INT nPostfixNumber = CalcPosFixOfTable(xProtocol->stTime);

	for(INT n = 0; n < nPostfixNumber; ++n)
	{
		pSend->nNumber = 0; 
		pSend->dw_message_id = temp.dw_message_id;
		pSend->dw_size = temp.dw_size - sizeof(tag_bank_log);

		SprintfT("log_bank", PostFixTableBuffer[n][0], PostFixTableBuffer[n][1]); 
		VOID* p_buffer = pSend->bank_log;
		pDB->get_bank_log(szTableName, p_buffer, -1, xProtocol->dwRoleID, pSend->dw_size, pSend->nNumber);
		xGMPlayer->SendMessage(pSend, pSend->dw_size);
	}

	NET_GMS2C_QueryLogFinish send;
	xGMPlayer->SendMessage(&send, send.dw_size);

	return 0;
}
DWORD GMServerHanlder::HandleQueryPaiMaiLog(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryRolePaiMaiLog* xProtocol = (NET_C2GMS_QueryRolePaiMaiLog*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetLogDB(get_tool()->crc32(xProtocol->szServerName));
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_QueryRolePaiMaiLog temp;
	NET_GMS2C_QueryRolePaiMaiLog* pSend = (NET_GMS2C_QueryRolePaiMaiLog*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	INT nPostfixNumber = CalcPosFixOfTable(xProtocol->stTime);

	for(INT n = 0; n < nPostfixNumber; ++n)
	{
		pSend->nNumber = 0; 
		pSend->dw_message_id = temp.dw_message_id;
		pSend->dw_size = temp.dw_size - sizeof(tag_paimai_log);

		SprintfT("log_paimai", PostFixTableBuffer[n][0], PostFixTableBuffer[n][1]); 
		VOID* p_buffer = pSend->paimai_log;
		pDB->get_paimai_log(szTableName, p_buffer, -1, xProtocol->dwRoleID, pSend->dw_size, pSend->nNumber);
		xGMPlayer->SendMessage(pSend, pSend->dw_size);
	}

	NET_GMS2C_QueryLogFinish send;
	xGMPlayer->SendMessage(&send, send.dw_size);

	return 0;
}
//! 服务器某一物品数量
DWORD GMServerHanlder::HandleQueryItemNumber(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryItemNumberByType* xProtocol = (NET_C2GMS_QueryItemNumberByType*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_QueryItemNumberByType send;
	send.nNumber = pDB->get_item_number(xProtocol->dwTypeID);
	xGMPlayer->SendMessage(&send, send.dw_size);
	return 0;
}
//! 查询被禁言列表
DWORD GMServerHanlder::HandleGetForbidTalkRoleList(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_GetForbidTalkRoleList* xProtocol = (NET_C2GMS_GetForbidTalkRoleList*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_GetForbidTalkRoleList temp;
	NET_GMS2C_GetForbidTalkRoleList* pSend = (NET_GMS2C_GetForbidTalkRoleList*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	pSend->nNumber = 0;
	pSend->dw_message_id = temp.dw_message_id;
	pSend->dw_size = temp.dw_size - sizeof(tag_forbid_talk_role);
	VOID* p_buffer = pSend->stData;
	pDB->get_forbid_talk_list("role_data", p_buffer, INVALID_VALUE, INVALID_VALUE, pSend->dw_size, pSend->nNumber);
	xGMPlayer->SendMessage(pSend, pSend->dw_size);
	return 0;
}
//! 查询被封号列表
DWORD GMServerHanlder::HandleGetForbidAccountList(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_GetForbidAccountList* xProtocol = (NET_C2GMS_GetForbidAccountList*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetAccountDB();
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_GetForbidAccountList temp;
	NET_GMS2C_GetForbidAccountList* pSend = (NET_GMS2C_GetForbidAccountList*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	pSend->nNumber = 0;
	pSend->dw_message_id = temp.dw_message_id;
	pSend->dw_size = temp.dw_size - sizeof(tag_forbid_account);
	VOID* p_buffer = pSend->stData;
	pDB->get_forbid_account_list("account", p_buffer, INVALID_VALUE, INVALID_VALUE, pSend->dw_size, pSend->nNumber);
	xGMPlayer->SendMessage(pSend, pSend->dw_size);
	return 0;
}

//! 查询GM日志
DWORD GMServerHanlder::HandleQueryGMLog(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryGMLog* xProtocol = (NET_C2GMS_QueryGMLog*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* p_aux_db = g_LogQueryMgr.GetAccountDB( );
	if(!VALID_POINT(p_aux_db)) return -1;

	db_interface* p_real_db= g_GMPlayerManager.GetGMLogDB( );
	if(!VALID_POINT(p_real_db)) return -1;


	NET_GMS2C_QueryGMLog temp;
	NET_GMS2C_QueryGMLog* pSend = (NET_GMS2C_QueryGMLog*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	INT nPostfixNumber = CalcPosFixOfTable(xProtocol->stTime);

	for(INT n = 0; n < nPostfixNumber; ++n)
	{
		pSend->nNumber = 0; 
		pSend->dw_message_id = temp.dw_message_id;
		pSend->dw_size = temp.dw_size - sizeof(tag_gm_log);

		SprintfT("gmlog", PostFixTableBuffer[n][0], PostFixTableBuffer[n][1]); 
		VOID* p_buffer = pSend->gm_log;
		p_aux_db->get_gm_log(p_real_db,szTableName, p_buffer, xProtocol->dwGMAccountID, INVALID_VALUE, pSend->dw_size, pSend->nNumber);
		xGMPlayer->SendMessage(pSend, pSend->dw_size);
	}

	NET_GMS2C_QueryLogFinish send;
	xGMPlayer->SendMessage(&send, send.dw_size);
	return 0;
}

DWORD GMServerHanlder::HandleQueryGMLogByAccount(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryGMLogByAccount* xProtocol = (NET_C2GMS_QueryGMLogByAccount*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* p_aux_db = g_LogQueryMgr.GetAccountDB( );
	if(!VALID_POINT(p_aux_db)) return -1;

	db_interface* p_real_db= g_GMPlayerManager.GetGMLogDB( );
	if(!VALID_POINT(p_real_db)) return -1;

	DWORD dw_gmaccount_id = 0;
	p_aux_db->get_gm_tool_account_id(p_real_db, xProtocol->sz_account_name);
	if(!VALID_POINT(dw_gmaccount_id)) return -1;

	NET_GMS2C_QueryGMLog temp;
	NET_GMS2C_QueryGMLog* pSend = (NET_GMS2C_QueryGMLog*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	INT nPostfixNumber = CalcPosFixOfTable(xProtocol->stTime);

	for(INT n = 0; n < nPostfixNumber; ++n)
	{
		pSend->nNumber = 0; 
		pSend->dw_message_id = temp.dw_message_id;
		pSend->dw_size = temp.dw_size - sizeof(tag_gm_log);

		SprintfT("gmlog", PostFixTableBuffer[n][0], PostFixTableBuffer[n][1]); 
		VOID* p_buffer = pSend->gm_log;
		p_aux_db->get_gm_log(p_real_db,szTableName, p_buffer, dw_gmaccount_id, INVALID_VALUE, pSend->dw_size, pSend->nNumber);
		xGMPlayer->SendMessage(pSend, pSend->dw_size);
	}

	NET_GMS2C_QueryLogFinish send;
	xGMPlayer->SendMessage(&send, send.dw_size);
	return 0;
}
//! 查询帮会列表
DWORD GMServerHanlder::HandleQueryGuildList(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryGuildList* xProtocol = (NET_C2GMS_QueryGuildList*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_QueryGuildList temp;
	NET_GMS2C_QueryGuildList* pSend = (NET_GMS2C_QueryGuildList*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	pSend->nNumber = 0;
	pSend->dw_message_id = temp.dw_message_id;
	pSend->dw_size = temp.dw_size - sizeof(tag_guild_basic);
	
	VOID* p_buffer = pSend->stData;
	pDB->get_guild_basic_list("guild", p_buffer, INVALID_VALUE, INVALID_VALUE, pSend->dw_size, pSend->nNumber);
	xGMPlayer->SendMessage(pSend, pSend->dw_size);

	return 0;
}
//! 帮会基础资料
DWORD GMServerHanlder::HandleQueryGuildData(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryGuildData* xProtocol = (NET_C2GMS_QueryGuildData*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_QueryGuildData temp;
	NET_GMS2C_QueryGuildData* pSend = (NET_GMS2C_QueryGuildData*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	pSend->nNumber = 0;
	pSend->dw_message_id = temp.dw_message_id;
	pSend->dw_size = temp.dw_size;

	INT nNumber; DWORD dwSize;
	VOID* p_buffer = &pSend->stData;
	//! 基本资料
	pDB->get_guild_data("guild", p_buffer, xProtocol->dw_guild_id, INVALID_VALUE, dwSize, nNumber);
	//! 成员数量
	pSend->stData.dw_member_num = pDB->get_guild_member_number(xProtocol->dw_guild_id);
	//! 建筑资料
	p_buffer = pSend->stData.stData;
	pDB->get_guild_build("guild_upgrade", p_buffer, xProtocol->dw_guild_id, INVALID_VALUE, dwSize, nNumber);

	xGMPlayer->SendMessage(pSend, pSend->dw_size);

	return 0;
}

//! 帮会成员列表
DWORD GMServerHanlder::HandleQueryGuildMember(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryGuildMember* xProtocol = (NET_C2GMS_QueryGuildMember*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(!VALID_POINT(pDB)) return -1;

	NET_GMS2C_QueryGuildMember temp;
	NET_GMS2C_QueryGuildMember* pSend = (NET_GMS2C_QueryGuildMember*)GetCommonBuffer();
	if(!VALID_POINT(pSend)) return -1;

	pSend->nNumber = 0;
	pSend->dw_message_id = temp.dw_message_id;
	pSend->dw_size = temp.dw_size - sizeof(tag_guild_member);

	VOID* p_buffer = &pSend->stData;
	pDB->get_guild_member("", p_buffer, xProtocol->dw_guild_id, INVALID_VALUE, pSend->dw_size, pSend->nNumber);
	xGMPlayer->SendMessage(pSend, pSend->dw_size);

	return 0;
}

//=================================================
//	修复悬赏任务标志
//=================================================
DWORD GMServerHanlder::HandleVerifyGDQuestFlag(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_VerifyGDQuestFlag* xProtocol = (NET_C2GMS_VerifyGDQuestFlag*)(pMsg);
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	NET_GMS2C_VerifyGDQuestFlag send;
	send.dwError = -1;
	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pDB))
	{
		if(pDB->verify_gdquest_data(xProtocol->dwRoleID))
			send.dwError = E_Success;
	}

	xGMPlayer->SendMessage(&send, send.dw_size);
	return 0;
}