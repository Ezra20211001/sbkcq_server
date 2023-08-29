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
*	@file		GMPlayerManager
*	@author		mwh
*	@date		2011/04/06	initial
*	@version	0.0.1.0
*	@brief		GM π‹¿Ì∆˜
*/

#ifndef __GMPLAYER_MANAGER_H__
#define __GMPLAYER_MANAGER_H__

class GMServer;
class GMPlayer;


#include "PlayerIDSetter.h"
#include "../../common/WorldDefine/time.h"
class GMPlayerManager
{
public:
	GMPlayerManager();
	~GMPlayerManager();
public:
	BOOL Init(GMServer* pServer);
	VOID Update();
	VOID Destroy();
	VOID Kick(DWORD dwID);
public:
	inline LPBYTE GetMessage(DWORD dwID, DWORD& dwMsgSize, INT& nRecvNumber);
	inline VOID ReturnMessage(DWORD dwID, LPVOID lpMsg);
	inline VOID HandleMessage(LPVOID lpMsg, DWORD dwSize, DWORD dwParam);
	inline VOID SendMessage(DWORD dwID, LPVOID lpMsg, DWORD dwSize);
	VOID SendMessageEX(DWORD PlayerTpye, LPVOID lpMsg, DWORD dwSize);
public:
	VOID UpdateGMAccount();
	VOID CreateGMLogTable();
	VOID WriteGMLog(DWORD dwAccountID, DWORD dwErrorCode, const TCHAR* pLogCmd);
	VOID WriteGMLog(GMPlayer* pPlayer, DWORD dwErrorCode, const TCHAR* pLogCmd);
	VOID WriteYuanBaoLog(GMPlayer* player, DWORD dw_account_id, INT nConType, INT nDiff, INT64 n64Total);
	VOID WriteMoneyLog(GMPlayer* player, DWORD dw_role_id, INT nConType, INT64 n64Diff, INT64 n64Total);
public:
	inline GMPlayer* GetGMPlayer(const TCHAR* szAccount);
	inline GMPlayer* GetGMPlayer(DWORD dwID);
	inline few_connect_server* GetNetSession();
	inline db_interface* GetGMLogDB();
	inline db_interface* GetGMAccountDB();
private:
	VOID DestroyPlayer();
	VOID UpdateAllSession();
	VOID RegisterCmd();
	VOID UnRegisterCmd();
public:
	VOID DoCreateGMLogTable(const TCHAR* pTableName, const char* pPostFix, odbc::sql_language_disposal* pStream);
public:
	VOID SetLoginStatus(DWORD dwID,  INT nStatus);
private:
	VOID LoadAllGMAccount();
	VOID InitGMAccount(odbc::execute_result* pResult);
	DWORD LoginCallBack(LPBYTE lpMsg, DWORD dwSize);
	DWORD LogoutCallBack(DWORD dwParam);
private:
	std::string mGMLogPostfix;
	tagDWORDTime mLogTime;
	db_interface* mGMLogDB;
	db_interface* mGMAccountDB;
	few_connect_server* mNetSession;
	DWORD mUpdateAccountTick;
	package_list<DWORD> mDestoryPlayer;
	package_map<DWORD, GMPlayer*> mGMPlayer;
	package_map<DWORD, DWORD> mGMPlayerID;
private:
	enum{CONVERTBUFFERLEN = 1024};
	TCHAR mConvertBuffer[CONVERTBUFFERLEN];
};

inline GMPlayer* GMPlayerManager::GetGMPlayer(const TCHAR* szAccount)
{
	return GetGMPlayer(mGMPlayerID.find(get_tool()->crc32(szAccount)));
}

inline GMPlayer* GMPlayerManager::GetGMPlayer(DWORD dwID)
{
	return mGMPlayer.find(dwID);
}

inline few_connect_server* GMPlayerManager::GetNetSession()
{
	return mNetSession;
}

inline db_interface* GMPlayerManager::GetGMLogDB()
{
	return mGMLogDB;
}

inline db_interface* GMPlayerManager::GetGMAccountDB()
{
	return mGMAccountDB;
}

inline LPBYTE GMPlayerManager::GetMessage(DWORD dwID, DWORD& dwMsgSize, INT& nRecvNumber)
{
	if(!VALID_POINT(mNetSession)) return NULL;
	return (LPBYTE)mNetSession->recv_msg(dwID, dwMsgSize, nRecvNumber);
}

inline VOID GMPlayerManager::ReturnMessage(DWORD dwID, LPVOID lpMsg)
{
	if(!VALID_POINT(mNetSession)) return;
	mNetSession->free_recv_msg(dwID, (BYTE*)lpMsg);
}

inline VOID GMPlayerManager::HandleMessage(LPVOID lpMsg, DWORD dwSize, DWORD dwParam)
{
	if(!VALID_POINT(mNetSession)) return;
	serverframe::net_command_manager::get_singleton().handle_message(static_cast<tag_net_message*>(lpMsg),
		dwSize, dwParam);
}

inline VOID GMPlayerManager::SendMessage(DWORD dwID, LPVOID lpMsg, DWORD dwSize)
{
	if(!VALID_POINT(mNetSession)) return;
	mNetSession->send_msg(dwID, lpMsg, dwSize);
}


extern GMPlayerManager g_GMPlayerManager;

#endif // __GMPLAYER_MANAGER_H__