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
 *	@file		ServerPlayer
 *	@author		mwh
 *	@date		2011/04/06	initial
 *	@version	0.0.1.0
 *	@brief		GameServer/LoginServer 
*/

#ifndef __SERVERPLAYER_H__
#define __SERVERPLAYER_H__


#include "ServerPlayerManager.h"
#include "../common/ServerDefine/login_server_define.h"

class ServerPlayer
{
public:
	ServerPlayer();
	~ServerPlayer();
public:
	BOOL Init(const TCHAR* pSeverName, const TCHAR* pDBIP, 
				const TCHAR* pDBUser = _T("root"), const TCHAR* pDBPsw = _T("123456"), const TCHAR* pDBName = _T("gamedb"), INT dbPort = 3306);
	BOOL Init(DWORD dwID, const TCHAR* pSeverName, const TCHAR* pDBIP, 
		const TCHAR* pDBUser = _T("root"), const TCHAR* pDBPsw = _T("123456"), const TCHAR* pDBName = _T("gamedb"), INT dbPort = 3306);
	INT  Update();
	VOID Destroy();
public:
	BOOL OnLogin();
	BOOL OnLogout();
public:
	inline INT GetOnlineNumber() const;
	inline VOID SetOnlineNumber(INT val);
	inline INT GetMaxOnlineNumber() const;
	inline VOID SetMaxOnlineNumber(INT val);
	inline E_world_status GetStatus() const;
	inline VOID SetStatus(E_world_status val);
	inline E_world_status GetDBStatus() const;
	inline VOID SetDBStatus(E_world_status val);
	inline BOOL GetKicked() const;
	inline VOID SetKicked(BOOL b);
	inline VOID SetIP(DWORD dwIP);
	inline DWORD GetIP() const;
	inline VOID SetPort(INT nPort);
	inline INT GetPort() const;
	inline BOOL GetDatabaseOK() const;
	inline VOID SetDatabaseOK(BOOL b);
public:
	inline VOID SendMessage(LPVOID lpMsg, DWORD dwSize);
public:
	inline BOOL IsConnectLost() const;
	inline BOOL IsConnected() const;
	inline DWORD GetID() const;
	inline const TCHAR* GetName() const;
private:
	INT UpdateSession();
private:
	DWORD mID;
	DWORD mIP;
	INT mPort;
	INT mOnlineNumber;
	INT mMaxOnlineNumber;
	BOOL mIsConnected;
	BOOL mConnectLost;
	BOOL mDatabaseOK;
	E_world_status mStatus;
	E_world_status mDBStatus;
	TCHAR mName[X_SHORT_NAME];
	db_interface* mDBInterface;
};

//=================================================
//	Global variable 
//=================================================
extern ServerPlayerManager g_ServerPlayerMgr;

//=================================================
//	inline function
//=================================================
inline VOID ServerPlayer::SendMessage(LPVOID lpMsg, DWORD dwSize)
{ 
	if(IsConnectLost() || !IsConnected()) return;
	g_ServerPlayerMgr.SendMessage( GetID(), lpMsg, dwSize);
}
inline BOOL ServerPlayer::IsConnectLost() const{ return mConnectLost; }
inline BOOL ServerPlayer::IsConnected() const{ return mIsConnected; }
inline DWORD ServerPlayer::GetID() const{ return mID; }
inline const TCHAR* ServerPlayer::GetName() const{ return mName; }
inline INT ServerPlayer::GetOnlineNumber() const { return mOnlineNumber; }
inline VOID ServerPlayer::SetOnlineNumber(INT val) { mOnlineNumber = val; }
inline INT ServerPlayer::GetMaxOnlineNumber() const { return mMaxOnlineNumber; }
inline VOID ServerPlayer::SetMaxOnlineNumber(INT val) { mMaxOnlineNumber = val; }
inline E_world_status ServerPlayer::GetStatus() const { return mStatus; }
inline VOID ServerPlayer::SetStatus(E_world_status val) { mStatus = val; }
inline E_world_status ServerPlayer::GetDBStatus() const{ return mDBStatus;}
inline VOID ServerPlayer::SetDBStatus(E_world_status val){ mDBStatus = val;}
inline VOID ServerPlayer::SetIP(DWORD dwIP){ mIP = dwIP;}
inline DWORD ServerPlayer::GetIP() const{ return mIP;}
inline VOID ServerPlayer::SetPort(INT nPort){mPort = nPort;}
inline INT ServerPlayer::GetPort() const{ return mPort; }
inline VOID ServerPlayer::SetDatabaseOK(BOOL b){mDatabaseOK = b;}
inline BOOL ServerPlayer::GetDatabaseOK() const{ return mDatabaseOK;}
#endif //__SERVERPLAYER_H__