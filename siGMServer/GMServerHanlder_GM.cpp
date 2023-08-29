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
 *	@file		GMServerHanlder_GMPlayer
 *	@author		mwh
 *	@date		2011/04/07	initial
 *	@version	0.0.1.0
 *	@brief		GM客户端与GM服务器之间的逻辑处理
*/

#include "stdafx.h"
#include "GMServerHanlder.h"
#include "GMPlayer.h"
#include "ServerPlayer.h"
#include "GMLogHelper.h"
#include "LogDB.h"
#include "GMLogQueryManager.h"
#include "../common/WorldDefine/GMCMessage.h"
#include "../common/ServerDefine/GMServerMessage.h"


#define MSG_HANDLER_PRIVILEGE(Player, Pri, Warning, Ret)\
	if(!((Player)->HasPrivilege(Pri))){print_message(_T("%s Can't Excute %s\n"), (Player)->GetAccount( ).c_str( ), Warning); return (Ret); }

const TCHAR* DoubleTypeString(EGMDoubleType eType)
{
	switch(eType)
	{
	case EGMDT_EXP:  return _T("经验");
	case EGMDT_ITEM:return _T("掉落");
	case EGMDT_Practice:return _T("修炼");
	}
	return _T("未知");
}

//=================================================
//	GM 登陆
//=================================================
DWORD GMServerHanlder::HandleGMLogin(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_GMLogin* xProtocol = (NET_C2GMS_GMLogin*)(pMsg);
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	NET_GMS2C_GMLogin send;
	TCHAR szIP[MAX_PATH] = {0}; sockaddr_in laddr;
	g_GMPlayerManager.GetNetSession()->get_client_sock_name(&laddr, xGMPlayer->GetID());
#ifdef _UNICODE
	MultiByteToWideChar(CP_ACP,NULL,inet_ntoa(laddr.sin_addr),-1,szIP,MAX_PATH);
#else
	_tcscpy(szIP, inet_ntoa(laddr.sin_addr));
#endif

	BOOL bProofOk = xGMPlayer->Proof(xProtocol->szPsd, szIP, xProtocol->eToolType);
	send.dwErrorCode = bProofOk ? E_Success : EGMProof_Denied;
	send.dwPrivilege = bProofOk ? xGMPlayer->GetPrivilege() : 0;
	xGMPlayer->SendMessage(&send, send.dw_size);

	print_message(_T("\n\nGM: %s [%s | %u | %s] %s Login!!\n\n"),
		szIP, xGMPlayer->GetAccount().c_str(), xGMPlayer->GetID( ), xProtocol->szAccount, bProofOk ?  _T("") :  _T("Be Denied To "));

	if(!bProofOk)
	{
		xGMPlayer->OnLogout( );
		print_message(_T("\n[PSW:%d][IP:%d][TYPE:%d]!\n"), xProtocol->szPsd == xGMPlayer->GetPassword(),
			szIP == xGMPlayer->GetIP(), xProtocol->eToolType == xGMPlayer->GetType());
	}
	else g_GMPlayerManager.SetLoginStatus(xGMPlayer->GetID(), 1);

	return 0;
}
//=================================================
//	禁言 发往GameServer
//=================================================
DWORD GMServerHanlder::HandleForbiTalk(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_ForbidTalk* xProtocol = (NET_C2GMS_ForbidTalk*)(pMsg);
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	MSG_HANDLER_PRIVILEGE(xGMPlayer, EGMP_FORBIDTALK, _T("ForbidTalk"), 0);

	ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pServerPlayer))
	{
		NET_GMS2S_forbid_Talk send;
		send.b_forbid = xProtocol->bForbid;
		send.dw_client_id = xGMPlayer->GetID();
		send.dwSecond = xProtocol->dwSecond;
		_tcscpy(send.szRoleName, xProtocol->szRoleName);
		pServerPlayer->SendMessage(&send, send.dw_size);
		g_GMPlayerManager.WriteGMLog(xGMPlayer->GetID(), 0,
			LogHelper(_T("[%s]服务器[%s]角色[%s][%d]分钟,[%s]!"), xProtocol->bForbid ? _T("禁言") : _T("解禁"),
			xProtocol->szServerName, xProtocol->szRoleName, xProtocol->dwSecond / 60, xProtocol->szReason ));
	}
	else
	{
		NET_GMS2C_ForbidTalk send;
		send.dwErrorCode = EGMForbidTalk_ServerNotExist;
		xGMPlayer->SendMessage(&send, send.dw_size);
	}

	return 0;
}
//=================================================
//	检索数据库，将非法的IP干掉 gx add 2013.11.07
//=================================================
DWORD GMServerHanlder::HandleFuckWorkRoom(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_FuckWorkRoom* xProtocol = (NET_C2GMS_FuckWorkRoom*)(pMsg);
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	MSG_HANDLER_PRIVILEGE(xGMPlayer, EGMP_FORBIDACCOUNT, _T("ForbidAccount"), 0);
	std::vector<tag_Invalid_IP> ip_data_vec;
	LogDB* pDB = g_LogQueryMgr.GetAccountDB();
	if (VALID_POINT(pDB))
	{
		DWORD dw_client_id = xGMPlayer->GetID();
		if (xProtocol->nTrustConsider)
		{
			pDB->func_get_invalid_ip_section(ip_data_vec,xProtocol->nIPNum,xProtocol->szTrustIP);
		}
		else
		{
			pDB->func_get_invalid_ip_section(ip_data_vec,xProtocol->nIPNum,NULL);
		}
		size_t count = ip_data_vec.size();//得到这个大区下所有非法IP
		//是否封号
		if (xProtocol->nForbid)
		{
			//得到这个非法IP下的所有account_name
			for (size_t i = 0;i < count;i++)
			{
				pDB->func_get_account_name_by_ip(g_GMForbidAccMgr.get_account_studio(),ip_data_vec[i].sz_ip_name,xProtocol->szServerName,dw_client_id);
			}
		}
		//是否将这些号踢掉
		if (xProtocol->nKick)
		{
			//根据server_name找到对应的GameDB
			LogDB* pGameDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
			if (VALID_POINT(pGameDB))
			{
				GMForbidAccMgr::ACCOUNT_STU_VEC& account_Vec = g_GMForbidAccMgr.get_account_studio();
				//得到这个非法的account_name对应的角色role_name
				for (size_t i = 0;i < account_Vec.size();i++)
				{
					pGameDB->fun_get_rolename_by_accountname(g_GMForbidAccMgr.get_kick_studio(),account_Vec[i].dw_account_id,xProtocol->szServerName);
				}
			}
		}
		//向运维工具发消息
		for (size_t i = 0;i < count;i++)
		{
			NET_GMS2C_FuckWorkRoom cmd;
			cmd.nIPNums = ip_data_vec[i].n_ip_num;
			memcpy(cmd.szServerName,xProtocol->szServerName,sizeof(xProtocol->szServerName));
			memcpy(cmd.szIPName,ip_data_vec[i].sz_ip_name,sizeof(TCHAR)*X_SHORT_NAME);
			xGMPlayer->SendMessage(&cmd, cmd.dw_size);
		}
		//没有查到也要给工具一个回馈
		if (0 == count)
		{
			NET_GMS2C_FuckWorkRoom cmd;
			cmd.nIPNums = -1;
			xGMPlayer->SendMessage(&cmd, cmd.dw_size);
		}
	}
	return 0;
}
//根据异常IP，手动一个一个地处理
DWORD GMServerHanlder::HandleFuckWorkRoom_OBO(tag_net_message* pMsg,DWORD dwParam)
{
	NET_C2GMS_HandleIP_OBO* xProtocol = (NET_C2GMS_HandleIP_OBO*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	MSG_HANDLER_PRIVILEGE(xGMPlayer, EGMP_FORBIDACCOUNT, _T("ForbidAccount"), 0);
	
	LogDB* pDB = g_LogQueryMgr.GetAccountDB();
	if (VALID_POINT(pDB))
	{
		DWORD dw_client_id = xGMPlayer->GetID();
		//是否封号
		if (xProtocol->nForbid)
		{
			//得到这个非法IP下的所有account_name
			pDB->func_get_account_name_by_ip(g_GMForbidAccMgr.get_account_studio(),xProtocol->szInvalidIP,xProtocol->szServerName,dw_client_id);
		}
		//是否将这些号踢掉
		if (xProtocol->nKick)
		{
			//根据server_name找到对应的GameDB
			LogDB* pGameDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
			if (VALID_POINT(pGameDB))
			{
				GMForbidAccMgr::ACCOUNT_STU_VEC& account_Vec = g_GMForbidAccMgr.get_account_studio();
				//得到这个非法的account_name对应的角色role_name
				for (size_t i = 0;i < account_Vec.size();i++)
				{
					pGameDB->fun_get_rolename_by_accountname(g_GMForbidAccMgr.get_kick_studio(),account_Vec[i].dw_account_id,xProtocol->szServerName);
				}
			}
		}
		//向运维工具发消息
		{
			NET_GMS2C_HandleIP_OBO cmd;
			cmd.dw_result = E_Success;
			xGMPlayer->SendMessage(&cmd, cmd.dw_size);
		}
	}
	return 0;
}
//=================================================
//	封停账号 发往LoginServer
//=================================================
DWORD GMServerHanlder::HandleForbiAccount(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_ForbidAccount* xProtocol = (NET_C2GMS_ForbidAccount*)(pMsg);
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	MSG_HANDLER_PRIVILEGE(xGMPlayer, EGMP_FORBIDACCOUNT, _T("ForbidAccount"), 0);

	NET_GMS2S_forbid_account send;
	send.b_forbid = xProtocol->bForbid;
	send.dw_client_id = xGMPlayer->GetID();
	_tcscpy(send.sz_account, xProtocol->szAccount);
	_tcscpy(send.sz_world, xProtocol->szServerName);
	if(xProtocol->bForbid)
	{
		send.dwTimeStart = GetCurrentDWORDTime( );
		send.dwTimeEnd = xProtocol->dwSeconds ? IncreaseTime(send.dwTimeStart, xProtocol->dwSeconds) : 0xFFFFFFFF;
	}
	else send.dwTimeStart = send.dwTimeEnd = 0;
	g_ServerPlayerMgr.SendLoginServerMsg(&send, send.dw_size);
	g_GMPlayerManager.WriteGMLog(xGMPlayer, 0,
		LogHelper(_T("[%s]服务器[%s]账号[%s],[%d]分钟,[%s]!"), xProtocol->bForbid ? _T("封停"): _T("解封"),
		xProtocol->szServerName, xProtocol->szAccount, xProtocol->dwSeconds / 60, xProtocol->szReason));
	return 0;
}
DWORD GMServerHanlder::HandleForbiAccountByAccountID(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_ForbidAccountByAccountID* xProtocol = (NET_C2GMS_ForbidAccountByAccountID*)(pMsg);
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pAccountDB = g_LogQueryMgr.GetAccountDB( );
	if(!VALID_POINT(pAccountDB)) return 0;
	MSG_HANDLER_PRIVILEGE(xGMPlayer, EGMP_FORBIDACCOUNT, _T("ForbidAccount"), 0);

	BOOL bOL;
	NET_GMS2S_forbid_account send;
	send.b_forbid = xProtocol->bForbid;
	send.dw_client_id = xGMPlayer->GetID();
	_tcscpy(send.sz_world, xProtocol->szServerName);
	pAccountDB->get_account_name_by_id(xProtocol->dwAccountID, send.sz_account, bOL);
	if(xProtocol->bForbid)
	{
		send.dwTimeStart = GetCurrentDWORDTime( );
		send.dwTimeEnd = xProtocol->dwSeconds ? IncreaseTime(send.dwTimeStart, xProtocol->dwSeconds) : 0xFFFFFFFF;
	}
	else send.dwTimeStart = send.dwTimeEnd = 0;
	g_ServerPlayerMgr.SendLoginServerMsg(&send, send.dw_size);

	g_GMPlayerManager.WriteGMLog(xGMPlayer, 0,
		LogHelper(_T("[%s]服务器[%s]账号[%s],[%d]分钟,[%s]!"), xProtocol->bForbid ? _T("封停"): _T("解封"),
		xProtocol->szServerName,  send.sz_account, xProtocol->dwSeconds/ 60, xProtocol->szReason));

	return 0;
}
//=================================================
//	发往GameServer的公告
//=================================================
DWORD GMServerHanlder::HandleAfficheMsg(tag_net_message *pMsg, DWORD dwParam)
{
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	NET_C2GMS_Affiche* xProtocol = (NET_C2GMS_Affiche*)pMsg;
	MSG_HANDLER_PRIVILEGE(xGMPlayer, EGMP_AFFICHE, _T("AfficheMsg"), 0);
	ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pServerPlayer))
	{
		NET_GMS2S_Affiche send;
		send.dwSecond = xProtocol->dwSecond;
		_tcscpy(send.szAfficheMsg, xProtocol->szAfficheMsg);
		pServerPlayer->SendMessage(&send, send.dw_size);

		g_GMPlayerManager.WriteGMLog(xGMPlayer->GetID(), 0,
			LogHelper(_T("向服务器[%s]发布公告[%s]!"), xProtocol->szServerName, xProtocol->szAfficheMsg));
	}
	return 0;
}

DWORD GMServerHanlder::HandleGMKick(tag_net_message* pMsg,	DWORD dwParam)
{
	GMPlayer* xGMPlayer = PlayerCast<DWORD, GMPlayer>(dwParam);
	NET_C2GMS_Kick* xProtocol = (NET_C2GMS_Kick*)pMsg;
	MSG_HANDLER_PRIVILEGE(xGMPlayer, EGMP_KICKROLE, _T("KickRole"), 0);

	ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pServerPlayer))
	{
		NET_GMS2S_Kick send;
		_tcsncpy(send.szRoleName, xProtocol->szRoleName, X_SHORT_NAME);
		pServerPlayer->SendMessage(&send, send.dw_size);

		g_GMPlayerManager.WriteGMLog(xGMPlayer->GetID(), 0,
			LogHelper(_T("通知服务器[%s]踢人[%s]!"), xProtocol->szServerName, xProtocol->szRoleName));
	}

	return 0;
}

DWORD GMServerHanlder::HandleShutDown(tag_net_message* pMsg, DWORD dwParam)
{
	GMPlayer* xGMPlayer = PlayerCast<DWORD, GMPlayer>(dwParam);
	NET_C2GMS_ShutDown* xProtocol = (NET_C2GMS_ShutDown*)pMsg;

	ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pServerPlayer))
	{
		NET_GMS2S_ShutDown send;
		send.nTime = xProtocol->nTime;
		pServerPlayer->SendMessage(&send, send.dw_size);

		g_GMPlayerManager.WriteGMLog(xGMPlayer->GetID(), 0,
			LogHelper(_T("通知服务器[%s]关闭，倒计时[%d]分钟!"), xProtocol->szServerName, xProtocol->nTime));
	}
	return 0;
}


//=================================================
//	发往GameServer添加物品
//=================================================
DWORD GMServerHanlder::HandleAddItem(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_Add_item* xProtocol = (NET_C2GMS_Add_item*)(pMsg);
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pServerPlayer))
	{
		NET_GMS2S_Add_Item send;
		send.dw_client_id = xGMPlayer->GetID( );
		send.dw_item_data_id = xProtocol->dw_item_data_id;
		send.n16Num = xProtocol->n16Num;
		send.nQlty = xProtocol->nQlty;
		send.bBind = xProtocol->bBind;
		_tcscpy(send.szRoleName, xProtocol->szRoleName);
		pServerPlayer->SendMessage(&send, send.dw_size);

		g_GMPlayerManager.WriteGMLog(xGMPlayer->GetID(), 0,
			LogHelper(_T("给[%s]增加道具[%d],[%d]个,品质[%d]!"), xProtocol->szRoleName, send.dw_item_data_id, xProtocol->n16Num, xProtocol->nQlty));

	}

	return 0;
}

//=================================================
//! 服务器管理
//=================================================
DWORD GMServerHanlder::HandleQueryLoginStatus(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryLoginStatus* xProtocol = (NET_C2GMS_QueryLoginStatus*)(pMsg);
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetLoginServerPlayer( );
	if(VALID_POINT(pServerPlayer))
	{
		NET_GMS2C_QueryLoginStatus send;
		send.dwIP = pServerPlayer->GetIP( );
		send.bOK = pServerPlayer->IsConnected();
		send.nOnlinNumber = g_ServerPlayerMgr.GetTotalOnline();
		_tcscpy(send.szServerName, pServerPlayer->GetName());
		xGMPlayer->SendMessage(&send, send.dw_size);
	}
	return 0;
}
DWORD GMServerHanlder::HandleQueryGameSeverStatus(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_QueryGameServerList* xProtocol = (NET_C2GMS_QueryGameServerList*)(pMsg);
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	package_map<DWORD, ServerPlayer*>& _ServerMap = g_ServerPlayerMgr.GetServerPlayerMap();
	
	INT n = 0;
	NET_GMS2C_QueryGameServerList send; send.nNumber = 0; 
	ServerPlayer* xServerPlayer = NULL; _ServerMap.reset_iterator();
	while(_ServerMap.find_next(xServerPlayer) && n  < 64)
	{
		send.info[n].dwIP = xServerPlayer->GetIP();
		send.info[n].mStatus = xServerPlayer->IsConnected();
		send.info[n].mDBStatus = (xServerPlayer->GetDBStatus() == ews_well);
		send.info[n].mMaxNumber = xServerPlayer->GetMaxOnlineNumber();
		send.info[n].mOnlineNumber = xServerPlayer->GetOnlineNumber();
		send.info[n].mDatebase = xServerPlayer->GetDatabaseOK( );
		_tcscpy(send.info[n].szServerName, xServerPlayer->GetName( ));
		++n; ++send.nNumber;
	}

	send.dw_size -= ((64 - send.nNumber) *  sizeof(tag_gamaserver_info));
	xGMPlayer->SendMessage(&send, send.dw_size);

	return 0;
}

//=================================================
//! 服务器设置
//=================================================
DWORD GMServerHanlder::HandleSetServerMaxPlayer(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_SetServerMaxPlayerNumber* xProtocol = (NET_C2GMS_SetServerMaxPlayerNumber*)(pMsg);
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	ServerPlayer* pServerPlayerLogin = g_ServerPlayerMgr.GetLoginServerPlayer( );
	ServerPlayer* pGameServer =  g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pServerPlayerLogin) && VALID_POINT(pGameServer))
	{
#define MAXONLINENUMBER 3000
		NET_GMS2S_SetMaxPlayerNumber send;
		send.nMaxPlayerNumber = min(xProtocol->nMaxPlayerNumber, MAXONLINENUMBER);
		send.dwWorldNameCRC = pGameServer->GetID( );
		pServerPlayerLogin->SendMessage(&send, send.dw_size);
		pGameServer->SendMessage(&send, send.dw_size);
		g_GMPlayerManager.WriteGMLog(xGMPlayer, 0,
			LogHelper(_T("设置[%s]最大人数至[%d]"), xProtocol->szServerName, xProtocol->nMaxPlayerNumber) );
	}
	return 0;
}
DWORD GMServerHanlder::HandleSetDoublePolicy(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_SetDoublePolicy* xProtocol = (NET_C2GMS_SetDoublePolicy*)(pMsg);
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pServerPlayer))
	{
		CHAR tTimeBuffer[128] = {0}; 
		DwordTime2DataTime(tTimeBuffer, 128, GetCurrentDWORDTime());

		NET_GMS2S_SetDoublePolicy send;
		send.dwValue =min(max(100, xProtocol->dwValue), 1500); // [1, 15]
		send.eType = xProtocol->eType;
		send.dwStartTime = xProtocol->dwStartTime;
		send.dwPersistSeconds = xProtocol->dwPersistSeconds;
		pServerPlayer->SendMessage(&send, send.dw_size);
		g_GMPlayerManager.WriteGMLog(xGMPlayer, 0,
			LogHelper(_T("设置[%s][%s]倍率至[%d | %d]倍, 从[%s]持续时间[%d]分钟"), xProtocol->szServerName, DoubleTypeString(xProtocol->eType),
			xProtocol->dwValue/100, send.dwValue / 100,  get_tool()->ansi_to_unicode(tTimeBuffer), xProtocol->dwPersistSeconds/60) );
	}
	return 0;
}

DWORD GMServerHanlder::HandleAffichePeriodicity(tag_net_message* pMsg, DWORD dwParam)
{
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	NET_C2GMS_Affiche_Periodicity* xProtocol = (NET_C2GMS_Affiche_Periodicity*) pMsg;
	MSG_HANDLER_PRIVILEGE(xGMPlayer, EGMP_AFFICHE, _T("AfficheMsg"), 0);
	g_ServerPlayerMgr.AddAfficheCache(get_tool()->crc32(xProtocol->szServerName),
		xProtocol->dwIndex, xProtocol->dwSecond * TICK_PER_SECOND, xProtocol->szAfficheMsg);

	return 0;
}
DWORD GMServerHanlder::HandleCancelAffichePeriodicity(tag_net_message* pMsg, DWORD dwParam)
{
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	NET_C2GMS_Cancel_Affiche_Periodicity* xProtocol = (NET_C2GMS_Cancel_Affiche_Periodicity*)pMsg;

	MSG_HANDLER_PRIVILEGE(xGMPlayer, EGMP_AFFICHE, _T("CancelAfficheMsg"), 0);
	g_ServerPlayerMgr.DelAfficheCache(get_tool()->crc32(xProtocol->szServerName), xProtocol->dwIndex);
	return 0;
}

DWORD GMServerHanlder::HandleGMValidate(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_validate* xProtocol = (NET_C2GMS_validate*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pServerPlayer))
	{
		NET_GMS2S_validate send;
		send.bOpen = xProtocol->bOpen;
		send.dwClientID = xGMPlayer->GetID( );
		pServerPlayer->SendMessage(&send, send.dw_size);
		g_GMPlayerManager.WriteGMLog(xGMPlayer, 0,
			LogHelper(_T("[%s]服务器[%s]验证码策略"), xProtocol->bOpen ? _T("开启") : _T("关闭"),
			xProtocol->szServerName));

	}
	return 0;
}