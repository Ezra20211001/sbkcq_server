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
*	@file		ServerPlayerManager
*	@author		mwh
*	@date		2011/04/06	initial
*	@version	0.0.1.0
*	@brief		ServerPlayer 管理器
*/

#include "stdafx.h"
#include "../common/ServerDefine/GMServerMessage.h"
#include "ServerPlayer.h"
#include "ServerPlayerManager.h"
#include "GMServer.h"
#include "GMServerHanlder.h"
#include "../../common/WorldDefine/GMCMessage.h"

#define MakeDelegateOfThis(func) fastdelegate::MakeDelegate(this,func)

struct ServerPlayerOP
{
	VOID operator()(ServerPlayer* Val){ Val->Destroy(); }
};


tag_affiche_cache_list::tag_affiche_cache_list()
{
	aclist.resize(GMPERIODMAXINDEX);
}
tag_affiche_cache_list::~tag_affiche_cache_list()
{
	for(size_t n = 0; n < aclist.size(); ++n)
		if(VALID_POINT(aclist[n])) delete aclist[n];
	aclist.clear( );
}
VOID tag_affiche_cache_list::update(ServerPlayer* pServerPlayer)
{
	for(size_t n = 0; n < aclist.size(); ++n)
	{
		if(VALID_POINT(aclist[n]))
		{
			aclist[n]->update() ;
			if(aclist[n]->elapse( ))
			{
				aclist[n]->reset( );

				NET_GMS2S_Affiche send;
				send.dwSecond = 10;
				_tcscpy(send.szAfficheMsg, aclist[n]->szAfficheMsg);
				pServerPlayer->SendMessage(&send, send.dw_size);
			}
		}
	}
}
VOID tag_affiche_cache_list::delete_index(DWORD _index)
{
	if(_index >= aclist.size()) return;
	if(VALID_POINT(aclist[_index])) delete aclist[_index];
	aclist[_index] = NULL;
}

BOOL tag_affiche_cache_list::add_index(DWORD _index, DWORD _tick, const TCHAR* p)
{
	if(!VALID_POINT(p) || _index >= aclist.size())
		return FALSE;

	if(!VALID_POINT(aclist[_index]))
		aclist[_index] = new tag_affiche_cache;

	if(!VALID_POINT(aclist[_index])) return FALSE;

	aclist[_index]->dwCurTick = 0;
	aclist[_index]->dwTickTimes = _tick;
	_tcsncpy(aclist[_index]->szAfficheMsg, p, GMAFFICHELEN);
	return TRUE;
}

ServerPlayerManager g_ServerPlayerMgr;

ServerPlayerManager::ServerPlayerManager()
:mLoginServer(0),mNetSession(0)
{
	mNetSession = new few_connect_server;
}

ServerPlayerManager::~ServerPlayerManager()
{
	SAFE_DELETE(mLoginServer);
	SAFE_DELETE(mNetSession);
}

BOOL ServerPlayerManager::Init(GMServer* pServer)
{
	ASSERT(pServer != 0);
	ASSERT(pServer->GetConfig());

	RegisterCmd();

	tstringstream  xStream, xStream2;
	xStream.clear(); xStream << _T("accountdb");
	xStream2.clear(); xStream2 << _T("login");
	mLoginServer = new ServerPlayer;
	ASSERT(mLoginServer != 0);
	if(!mLoginServer->Init(LOGINSERVERID,
		pServer->GetConfig()->get_string(_T("login_name"),xStream2.str().c_str()),
		pServer->GetConfig()->get_string(_T("db_ip"),xStream.str().c_str()),
		pServer->GetConfig()->get_string(_T("db_user"),xStream.str().c_str()),
		pServer->GetConfig()->get_string(_T("db_password"),xStream.str().c_str()),
		pServer->GetConfig()->get_string(_T("db_name"),xStream.str().c_str()),
		pServer->GetConfig()->get_int(_T("db_port"),xStream.str().c_str())))
	{
		return FALSE;
	}

	INT xPort = pServer->GetConfig()->get_int(_T("port serverplayersession"));
	INT xGameServerNumber = pServer->GetConfig()->get_int(_T("num gameserver"));
	for(INT n = 0; n < xGameServerNumber; ++n)
	{
		ServerPlayer* lGameServer = new ServerPlayer;
		tstringstream  xStream1;
		xStream1.clear(); xStream1 << _T("gameserver") << n + 1;
		if( !lGameServer->Init(pServer->GetConfig()->get_string(_T("server_name"),xStream1.str().c_str()),
							   pServer->GetConfig()->get_string(_T("db_ip"),xStream1.str().c_str()),
							   pServer->GetConfig()->get_string(_T("db_user"),xStream1.str().c_str()),
							   pServer->GetConfig()->get_string(_T("db_password"),xStream1.str().c_str()),
							   pServer->GetConfig()->get_string(_T("db_name"),xStream1.str().c_str()),
							   pServer->GetConfig()->get_int(_T("db_port"),xStream1.str().c_str())))
		{
			return FALSE;
		}
		mGameServerPlayer.add( lGameServer->GetID(), lGameServer);
		tag_affiche_cache_list* p_cache_list = new tag_affiche_cache_list;
		if(VALID_POINT(p_cache_list)) mAfficheCache.add(lGameServer->GetID(), p_cache_list);
	}

	ASSERT(!mGameServerPlayer.empty());
	ASSERT(mNetSession != 0);

	mNetSession->init(MakeDelegateOfThis(&ServerPlayerManager::LoginCallBack),
					  MakeDelegateOfThis(&ServerPlayerManager::LogoutCallBack), xPort);

	return TRUE;
}

VOID ServerPlayerManager::Update()
{
	ServerPlayer* xServerPlayer = 0;
	if(VALID_POINT(mLoginServer)) mLoginServer->Update();
	mGameServerPlayer.reset_iterator();
	while(mGameServerPlayer.find_next(xServerPlayer))
	{
		INT xRet = xServerPlayer->Update();
		if(xRet == CON_LOST)
		{// 此处不能delete ServerPlayer
			print_message(_T("\n%s connect lost!\n"), xServerPlayer->GetName());
		}
	}
	UpdateAffichePeriodicity( );
}

VOID ServerPlayerManager::Destroy()
{
	ServerPlayer* xServerPlayer = 0;
	mGameServerPlayer.reset_iterator();
	while(mGameServerPlayer.find_next(xServerPlayer))
		ServerPlayerOP()(xServerPlayer);

	tag_affiche_cache_list* p;
	mAfficheCache.reset_iterator( );
	while(mAfficheCache.find_next(p)) delete p;
	mAfficheCache.clear();


	UnRegisterCmd();
}

VOID ServerPlayerManager::Kick(DWORD dwID)
{
	ServerPlayer* xServerPlayer = GetServerPlayer(dwID);
	if(VALID_POINT(xServerPlayer))
	{
		mNetSession->kick_connect(dwID);
		print_message(_T("\n%s %s Be Kicked!\n"), \
			dwID == LOGINSERVERID ? _T("LoginServer") : _T("GameServer"), xServerPlayer->GetName());
	}
}

VOID ServerPlayerManager::RegisterCmd()
{
	g_GMLogicHandler.RegisterCmd();
}

VOID ServerPlayerManager::UnRegisterCmd()
{
	g_GMLogicHandler.UnRegisterCmd();
}

DWORD ServerPlayerManager::LoginCallBack(LPBYTE lpMsg, DWORD dwSize)
{
	NET_S2GMS_SeverLogin* pMsg = (NET_S2GMS_SeverLogin*)(lpMsg);
	g_GMServer.Lock();
	
	DWORD dwServerID = INVALID_VALUE;

	ServerPlayer* xServerPlayer = GetServerPlayer(pMsg->e_type == EST_LOGINSERVER ? 
													LOGINSERVERID : pMsg->dw_crc);
	if(VALID_POINT(xServerPlayer))
	{
		xServerPlayer->OnLogin();
		dwServerID = xServerPlayer->GetID();
		print_message(_T("\n%s %s Connected!\n"), 
			pMsg->e_type == EST_LOGINSERVER ? _T("LoginServer") : _T("GameServer"),xServerPlayer->GetName());
	}else{
		print_message(_T("\n\nUnknown Server Connected![id:%04u]\n\n"), pMsg->dw_crc);
	}

	g_GMServer.UnLock();
	return dwServerID;
}

DWORD ServerPlayerManager::LogoutCallBack(DWORD dwParam)
{
	DWORD dwSessionID = dwParam;

	g_GMServer.Lock();

	ServerPlayer* xServerPlayer = GetServerPlayer(dwSessionID);
	if(VALID_POINT(xServerPlayer))
	{
		xServerPlayer->OnLogout();
		print_message(_T("\n%s %s Disconnected!\n"), 
			dwSessionID == LOGINSERVERID ? _T("LoginServer") : _T("GameServer"), xServerPlayer->GetName());
	}

	g_GMServer.UnLock();

	return 0;
}

VOID ServerPlayerManager::SendLoginServerMsg(LPVOID lpMsg, DWORD dwSize)
{
	ASSERT(mNetSession != 0);
	ASSERT(mLoginServer != 0);
	mNetSession->send_msg(mLoginServer->GetID(), lpMsg, dwSize);
}

INT ServerPlayerManager::GetTotalOnline()
{
	INT nTotalOnline = 0;
	ServerPlayer* xServerPlayer;
	mGameServerPlayer.reset_iterator();
	while(mGameServerPlayer.find_next(xServerPlayer))
		nTotalOnline += xServerPlayer->GetOnlineNumber();
	return nTotalOnline;
}
VOID ServerPlayerManager::UpdateAffichePeriodicity( )
{
	ServerPlayer* xServerPlayer = 0;
	mGameServerPlayer.reset_iterator();
	while(mGameServerPlayer.find_next(xServerPlayer))
	{
		tag_affiche_cache_list* p_cache_list = mAfficheCache.find(xServerPlayer->GetID());
		if(VALID_POINT(p_cache_list)) p_cache_list->update(xServerPlayer);
	}
}
VOID ServerPlayerManager::AddAfficheCache(DWORD dw_world_crc, 
										  DWORD dw_index, DWORD dwTickTimes, const TCHAR* p)
{
	ServerPlayer* pServerPlayer = this->GetGameServerPlayer(dw_world_crc);
	if(!VALID_POINT(pServerPlayer)) return ;

	tag_affiche_cache_list* p_cache_list = mAfficheCache.find(dw_world_crc);
	if(!VALID_POINT(p_cache_list)) return;
	p_cache_list->add_index(dw_index, dwTickTimes, p);
}
VOID ServerPlayerManager::DelAfficheCache(DWORD dw_world_crc, DWORD dw_index)
{
	ServerPlayer* pServerPlayer = this->GetGameServerPlayer(dw_world_crc);
	if(!VALID_POINT(pServerPlayer)) return ;
	
	tag_affiche_cache_list* p_cache_list = mAfficheCache.find(dw_world_crc);
	if(!VALID_POINT(p_cache_list)) return;

	p_cache_list->delete_index(dw_index);
}