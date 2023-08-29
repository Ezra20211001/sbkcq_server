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
*	@file		GMPlayer
*	@author		mwh
*	@date		2011/04/06	initial
*	@version	0.0.1.0
*	@brief		GM¿Í»§¶Ë
*/

#ifndef __GMPLAYER_H__
#define __GMPLAYER_H__

#include "../common/WorldDefine/GMDefine.h"
#include "GMPlayerManager.h"

class GMPlayer
{
public:
	GMPlayer(DWORD dwID);
	~GMPlayer();
public:
	BOOL Init(const TCHAR* pAccount = _T(""), const TCHAR* pPsd = _T(""), DWORD dwPrivilege = 0, const TCHAR* pIP = _T(""));
	INT Update();
	VOID Destroy();
public:
	BOOL OnLogin();
	BOOL OnLogout();
	BOOL Proof(const TCHAR* pPsd, const TCHAR* pIP, EToolType eToolType);
public:
	inline VOID SendMessage(LPVOID lpMsg, DWORD dwSize);
public:
	inline DWORD GetID() const;
	inline BOOL  IsConnectLost() const;
	inline BOOL  IsConnected() const;
	inline DWORD GetPrivilege() const;
	inline const tstring& GetIP() const;
	inline const tstring& GetAccount() const;
	inline const tstring& GetPassword() const;
	inline VOID SetType(EToolType eType);
	inline EToolType GetType() const;
	inline BOOL HasPrivilege( unsigned flag);
public:
	inline VOID Reset( );
	inline VOID SetIP(const TCHAR* pIP);
	inline VOID SetAccount(const TCHAR* pAccount);
	inline VOID SetPassword(const TCHAR* pPassw);
	inline VOID SetPrivilege(const DWORD dwPrivilege);
private:
	INT UpdateSession();
private:
	DWORD mID;
	DWORD mPrivilege;
	tstring mIP;
	tstring mAccount;
	tstring mPassword;
	EToolType mToolType;
	volatile BOOL mConnectLost;
	volatile BOOL mIsConnected;
};
inline VOID GMPlayer::Reset(){ mIsConnected = FALSE; mConnectLost = FALSE; }
inline VOID GMPlayer::SetIP(const TCHAR* pIP){ mIP = pIP; }
inline VOID GMPlayer::SetAccount(const TCHAR* pAccount){ mAccount = pAccount; }
inline VOID GMPlayer::SetPassword(const TCHAR* pPassw) { mPassword = pPassw; }
inline VOID GMPlayer::SetPrivilege(const DWORD dwPrivilege){ mPrivilege = dwPrivilege; }
inline VOID GMPlayer::SendMessage(LPVOID lpMsg, DWORD dwSize)
{
	if(IsConnectLost() || !IsConnected()) return;
	g_GMPlayerManager.SendMessage(GetID(), lpMsg, dwSize);
}
inline DWORD GMPlayer::GetID() const { return mID; }
inline BOOL GMPlayer::IsConnectLost() const { return mConnectLost; }
inline BOOL GMPlayer::IsConnected() const { return mIsConnected; }
inline const tstring& GMPlayer::GetIP() const { return mIP; }
inline const tstring& GMPlayer::GetAccount() const { return mAccount; }
inline const tstring& GMPlayer::GetPassword() const { return mPassword; }
inline DWORD GMPlayer::GetPrivilege() const { return mPrivilege; }
inline VOID GMPlayer::SetType(EToolType eType){ mToolType = eType;}
inline EToolType GMPlayer::GetType() const{ return mToolType; }
inline BOOL GMPlayer::HasPrivilege( unsigned flag){ return (mPrivilege & flag);}

#endif // __GMPLAYER_H__