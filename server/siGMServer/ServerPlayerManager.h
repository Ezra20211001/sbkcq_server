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
*	@brief		ServerPlayer π‹¿Ì∆˜
*/

#ifndef __SERVERPLAYER_MANAGER_H__
#define __SERVERPLAYER_MANAGER_H__

#include "PlayerIDSetter.h"

class GMServer;
class ServerPlayer;
struct tag_affiche_cache;

struct tag_affiche_cache_list
{
	std::vector<tag_affiche_cache*> aclist;
public:
	tag_affiche_cache_list();
	~tag_affiche_cache_list();
public:
	VOID update(ServerPlayer* p);
	VOID delete_index(DWORD _index);
	BOOL add_index(DWORD _index, DWORD _tick, const TCHAR* p);
};


class ServerPlayerManager
{
public:
	ServerPlayerManager();
	~ServerPlayerManager();
public:
	BOOL Init(GMServer* pServer);
	VOID Update();
	VOID Destroy();
	VOID Kick(DWORD dwID);
public:
	INT GetTotalOnline();
public:
	VOID AddAfficheCache(DWORD dw_world_crc, DWORD dw_index, DWORD dwTickTimes, const TCHAR* p);
	VOID DelAfficheCache(DWORD dw_world_crc, DWORD dw_index);
public:
	inline LPBYTE GetMessage(DWORD dwID, DWORD& dwMsgSize, INT& nRecvNumber);
	inline VOID ReturnMessage(DWORD dwID, LPVOID lpMsg);
	inline VOID HandleMessage(LPVOID lpMsg, DWORD dwSize, DWORD dwParam);
	inline VOID SendMessage(DWORD dwID, LPVOID lpMsg, DWORD dwSize);
	VOID SendLoginServerMsg(LPVOID lpMsg, DWORD dwSize);
public:
	inline ServerPlayer* GetServerPlayer(DWORD dwID);
	inline ServerPlayer* GetLoginServerPlayer();
	inline ServerPlayer* GetGameServerPlayer(DWORD dwID);
	inline few_connect_server* GetNetSession();
	inline package_map<DWORD, ServerPlayer*>& GetServerPlayerMap();
private:
	VOID RegisterCmd();
	VOID UnRegisterCmd();
private:
	DWORD LoginCallBack(LPBYTE lpMsg, DWORD dwSize);
	DWORD LogoutCallBack(DWORD dwParam);
private:
	VOID UpdateAffichePeriodicity( );
private:
	ServerPlayer* mLoginServer;
	few_connect_server* mNetSession;
	package_map<DWORD, tag_affiche_cache_list*> mAfficheCache;
	package_map<DWORD, ServerPlayer*> mGameServerPlayer;
};

inline ServerPlayer* ServerPlayerManager::GetServerPlayer(DWORD dwID)
{
	if(dwID == LOGINSERVERID) return mLoginServer;
	return mGameServerPlayer.find(dwID);
}

inline ServerPlayer* ServerPlayerManager::GetLoginServerPlayer()
{
	return mLoginServer;
}

inline ServerPlayer* ServerPlayerManager::GetGameServerPlayer(DWORD dwID)
{
	return mGameServerPlayer.find(dwID);
}

inline few_connect_server* ServerPlayerManager::GetNetSession()
{
	return mNetSession;
}

inline package_map<DWORD, ServerPlayer*>& ServerPlayerManager::GetServerPlayerMap() 
{
	return mGameServerPlayer;
}

inline LPBYTE ServerPlayerManager::GetMessage(DWORD dwID, DWORD& dwMsgSize, INT& nRecvNumber)
{
	ASSERT(mNetSession != 0);
	return (LPBYTE)mNetSession->recv_msg(dwID, dwMsgSize, nRecvNumber);
}

inline VOID ServerPlayerManager::ReturnMessage(DWORD dwID, LPVOID lpMsg)
{
	ASSERT(mNetSession != 0);
	mNetSession->free_recv_msg(dwID, (BYTE*)lpMsg);
}

inline VOID ServerPlayerManager::HandleMessage(LPVOID lpMsg, DWORD dwSize, DWORD dwParam)
{
	ASSERT(mNetSession != 0);
	serverframe::net_command_manager::get_singleton().handle_message(static_cast<tag_net_message*>(lpMsg),
				dwSize, dwParam);
}

inline VOID ServerPlayerManager::SendMessage(DWORD dwID, LPVOID lpMsg, DWORD dwSize)
{
	ASSERT(mNetSession != 0);
	mNetSession->send_msg(dwID, lpMsg, dwSize);
}

extern ServerPlayerManager g_ServerPlayerMgr;

#endif //__SERVERPLAYER_MANAGER_H__
