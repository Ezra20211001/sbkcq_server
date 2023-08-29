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
 *	@file		GMServerHanlder_ServerPlayer
 *	@author		mwh
 *	@date		2011/04/07	initial
 *	@version	0.0.1.0
 *	@brief		服务器与GM服务器之间的逻辑处理
*/

#include "stdafx.h"
#include "GMServerHanlder.h"
#include "ServerPlayer.h"
#include "GMPlayerManager.h"
#include "GMLogHelper.h"
//#include "GMForibAccMgr.h"
#include "GMLogQueryManager.h"
#include "LogDB.h"
#include "../common/ServerDefine/GMServerMessage.h"
#include "../common/WorldDefine/GMSaveProtocol.h"
#include "../common/WorldDefine/GMCMessage.h"

//=================================================
//	服务器登陆
//=================================================
DWORD GMServerHanlder::HandleServerLogin(tag_net_message* pMsg, DWORD dwParam)
{
	ASSERT(dwParam);

	ServerPlayer* xServerPlayer = PlayerCast<DWORD,ServerPlayer>(dwParam);

	print_message(_T("\n%s %u %s\n"),xServerPlayer->GetName(),
									xServerPlayer->GetID(), _T(__FUNCTION__));
	NET_GMS2S_SeverLogin send;
	xServerPlayer->SendMessage(&send, send.dw_size);

	sockaddr_in addr;
	g_ServerPlayerMgr.GetNetSession()->get_client_sock_name(&addr, 
		xServerPlayer->GetID());

	xServerPlayer->SetIP(addr.sin_addr.s_addr);
	xServerPlayer->SetPort(::ntohs(addr.sin_port));

	return 0;
}

//=================================================
//	服务器报告身体状态
//=================================================
DWORD GMServerHanlder::HandleServerInfo(tag_net_message* pMsg, DWORD dwParam)
{
	ASSERT(dwParam);
	NET_S2GMS_ServerInfo* xProtocol = (NET_S2GMS_ServerInfo*)pMsg;
	PlayerCast<DWORD,ServerPlayer>(dwParam)->SetStatus(xProtocol->e_status);
	PlayerCast<DWORD,ServerPlayer>(dwParam)->SetOnlineNumber(xProtocol->n_online_num);
	PlayerCast<DWORD,ServerPlayer>(dwParam)->SetMaxOnlineNumber(xProtocol->n_max_online_num);
	PlayerCast<DWORD,ServerPlayer>(dwParam)->SetDBStatus(xProtocol->e_db_status);
	PlayerCast<DWORD,ServerPlayer>(dwParam)->SetDatabaseOK(xProtocol->is_database_ok);

	return 0;
}

//=================================================
//	GameServer 回应禁言/解禁
//=================================================
DWORD GMServerHanlder::HandleGSForbiTalk(tag_net_message* pMsg, DWORD dwParam)
{
	ASSERT(dwParam);
	NET_S2GMS_forbid_Talk* xProtocol = (NET_S2GMS_forbid_Talk*)pMsg;

	NET_GMS2C_ForbidTalk send;
	send.dwErrorCode = xProtocol->dw_error_code;
	g_GMPlayerManager.SendMessage(xProtocol->dw_client_id, &send, send.dw_size);
//	g_GMPlayerManager.WriteGMLog(xProtocol->dw_client_id,xProtocol->dw_error_code,
//		LogHelper(_T("禁言/解禁 角色[%s]"), xProtocol->szRoleName));
	return 0;
}
//=================================================
//	LoginServer 回应封停/解封账号
//=================================================
DWORD GMServerHanlder::HandleLSForbiAccount(tag_net_message* pMsg, DWORD dwParam)
{
	ASSERT(dwParam);
	NET_S2GMS_forbid_account* xProtocol = (NET_S2GMS_forbid_account*)pMsg;

 	NET_GMS2C_ForbidAccount send;
	send.dwErrorCode = xProtocol->dw_error_code;
	g_GMPlayerManager.SendMessage(xProtocol->dw_client_id, &send, send.dw_size);

	if(xProtocol->dw_error_code == E_Success)
	{
		LogDB* pAccountDB = g_LogQueryMgr.GetAccountDB( );
		if(VALID_POINT(pAccountDB))
		{
			DWORD dw_account_id; BOOL bOL;
			if(pAccountDB->get_account_id_by_account_name(xProtocol->sz_account, dw_account_id, bOL))
			{
				if(!xProtocol->b_forbid)  g_GMForbidAccMgr.Remove(dw_account_id);
				else g_GMForbidAccMgr.AddNew(dw_account_id, xProtocol->dw_world_crc);
			}
		}
	}

	return 0;
}
//=================================================
//	gameserver 回应制造装备
//=================================================
DWORD GMServerHanlder::HandleGMCreateEquipResult(tag_net_message* pMsg, DWORD dwParam)
{
	ASSERT(dwParam);
	NET_S2GMS_GMCreateEquip* xProtocol = (NET_S2GMS_GMCreateEquip*)pMsg;

	NET_GMS2C_GMCreateEquip send;
	send.n64Serial = xProtocol->n64Serial;
	send.dwRoleID = xProtocol->dwRoleID;
	send.dwError = xProtocol->dwError;
	g_GMPlayerManager.SendMessage(xProtocol->dwClientID, &send, send.dw_size);

	if(xProtocol->dwError == E_Success)
	{
		g_GMPlayerManager.WriteGMLog(xProtocol->dwClientID,xProtocol->dwError,
			LogHelper(_T("gm制造装备[%I64d],获取者[%u]"), xProtocol->n64Serial, xProtocol->dwRoleID));
	}
	return 0;
}
//=================================================
//	gameserver 回应制造物品
//=================================================
DWORD GMServerHanlder::HandleGMCreateItemResult(tag_net_message* pMsg, DWORD dwParam)
{
	ASSERT(dwParam);
	NET_S2GMS_GMCreateItem* xProtocol = (NET_S2GMS_GMCreateItem*)pMsg;

	NET_GMS2C_GMCreateItem send;
	send.n64Serial = xProtocol->n64Serial;
	send.dwTypeID = xProtocol->dwTypeID;
	send.dwRoleID = xProtocol->dwRoleID;
	send.dwError = xProtocol->dwError;
	g_GMPlayerManager.SendMessage(xProtocol->dwClientID, &send, send.dw_size);
	if(xProtocol->dwError == E_Success)
	{
		g_GMPlayerManager.WriteGMLog(xProtocol->dwClientID,xProtocol->dwError,
			LogHelper(_T("gm制造物品[%I64d],获取者[%u]"), xProtocol->n64Serial, xProtocol->dwRoleID));
	}
	return 0;
}

DWORD GMServerHanlder::HandleGMGiveMoneyResult(tag_net_message* pMsg, DWORD dwParam)
{
	ASSERT(dwParam);
	NET_S2GMS_GMGiveMoney* xProtocol = (NET_S2GMS_GMGiveMoney*)pMsg;

	NET_GMS2C_GMGiveMoney send;
	send.dwError = xProtocol->dwError;
	send.dwMoney = xProtocol->dwMoney;
	send.dwYuanBao = xProtocol->dwYuanBao;
	send.dwRoleID = xProtocol->dwRoleID;
	g_GMPlayerManager.SendMessage(xProtocol->dwClientID, &send, send.dw_size);

	if(xProtocol->dwError == E_Success)
	{
		g_GMPlayerManager.WriteGMLog(xProtocol->dwClientID, xProtocol->dwError,
			LogHelper(_T("给[%d],发送元宝[%d],非绑定金币[%d]!"), send.dwRoleID, send.dwYuanBao, send.dwMoney));
	}
	return 0;
}
DWORD GMServerHanlder::HandleServerChatTransmit(tag_net_message* pMsg, DWORD dwParam)
{
	NET_S2GMS_ChatTransmit* xProtocol = (NET_S2GMS_ChatTransmit*)pMsg;
	ServerPlayer* xServerPlayer = PlayerCast<DWORD,ServerPlayer>(dwParam);

	NET_GMS2C_ChatTransmit send;
	send.dwRoleID = xProtocol->dwRoleID;
	send.dwAccountID = xProtocol->dwAccountID;
	send.byChannel = xProtocol->byChannel;
	_tcscpy(send.szServerName, xServerPlayer->GetName( ));
	_tcscpy(send.szRoleName, xProtocol->szRoleName);

	int destsize =  _countof(send.szMsg) * sizeof(TCHAR);
	int dynamsize = xProtocol->dw_size - sizeof(NET_S2GMS_ChatTransmit) + sizeof(TCHAR);
	int copy_size =  min(destsize, dynamsize);
	int last_index = min(copy_size/ sizeof(TCHAR), _countof(send.szMsg));
	memcpy_s(send.szMsg, destsize, xProtocol->szMsg, copy_size);

	send.dw_size -= destsize;
	send.dw_size += copy_size;
	
	g_GMPlayerManager.SendMessageEX(ETTYPE_CHATTOOL, &send, send.dw_size);

	return 0;
}

DWORD GMServerHanlder::HandleValidateResult(tag_net_message* pMsg, DWORD dwParam)
{
	NET_S2GMS_validate* xProtocol = (NET_S2GMS_validate*)pMsg;
	ServerPlayer* xServerPlayer = PlayerCast<DWORD,ServerPlayer>(dwParam);

	NET_GMS2C_validate send;
	send.dwError = E_Success;
	send.bOpen = xProtocol->bOpen;
	_tcsncpy(send.szServerName, xServerPlayer->GetName(), X_SHORT_NAME);
	g_GMPlayerManager.SendMessage(xProtocol->dwClientID, &send, send.dw_size);

	return E_Success;
}