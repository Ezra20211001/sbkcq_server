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

//=================================================
// 1.一个游戏服务器绑定一个数据库	
// 2.一个登陆服务器不绑定数据库
//=================================================

#include "StdAfx.h"
#include "ServerPlayer.h"
#include "../common/ServerDefine/GMServerMessage.h"

ServerPlayer::ServerPlayer()
:mID(0),mIP(0),mPort(0),mIsConnected(FALSE),mConnectLost(FALSE)
,mDBInterface(0),mOnlineNumber(0),mMaxOnlineNumber(0),mDatabaseOK(TRUE)
{
	ZeroMemory(mName,sizeof(TCHAR)*X_SHORT_NAME);
}

ServerPlayer::~ServerPlayer()
{
	SAFE_DELETE(mDBInterface);
}

BOOL ServerPlayer::Init(const TCHAR* pSeverName, const TCHAR* pDBIP, const TCHAR* pDBUser, const TCHAR* pDBPsw, const TCHAR* pDBName, INT dbPort)
{
	ASSERT(pSeverName != 0);
	ASSERT(pDBIP != 0);
	ASSERT(pDBUser != 0);
	ASSERT(pDBPsw != 0);
	ASSERT(pDBName != 0);
	ASSERT(dbPort != 0);

	_stprintf(mName, _T("%s"), pSeverName);
	mID = get_tool()->crc32(pSeverName);

	mDBInterface = new db_interface;
	ASSERT(mDBInterface != 0);
	if( !mDBInterface->init_db(pDBIP, pDBUser, pDBPsw, pDBName, dbPort))
	{
		ErrMessage(_T("\n\nfatal error on connect db: %s\n\n"), pDBName);
		return FALSE;
	}

	return TRUE;
}

BOOL ServerPlayer::Init(DWORD dwID, const TCHAR* pSeverName, const TCHAR* pDBIP, 
						const TCHAR* pDBUser, const TCHAR* pDBPsw, const TCHAR* pDBName, INT dbPort)
{
	ASSERT(dwID != 0);
	ASSERT(pSeverName != 0);
	mID = dwID;
	_stprintf(mName, _T("%s"), pSeverName);

	mDBInterface = new db_interface;
	ASSERT(mDBInterface != 0);
	if( !mDBInterface->init_db(pDBIP, pDBUser, pDBPsw, pDBName, dbPort))
	{
		ErrMessage(_T("\n\nfatal error on connect db: %s\n\n"),pDBName);
		return FALSE;
	}

	return TRUE;
}

BOOL ServerPlayer::OnLogin()
{
	if(IsConnected()) return FALSE;
	mIsConnected = TRUE;
	mConnectLost = FALSE;
	return TRUE;
}

BOOL ServerPlayer::OnLogout()
{
	if(!IsConnected()) return FALSE;
	mIsConnected = FALSE;
	mConnectLost = TRUE;
	return TRUE;
}

INT ServerPlayer::Update()
{
	return UpdateSession();
}

INT ServerPlayer::UpdateSession()
{
	if(IsConnectLost())return CON_LOST;
	if(!IsConnected()) return 0;

	// 处理消息
	DWORD dwMsgSize = 0, dwTime = 0;
	INT nLeaveMsgNumber = 0;

	LPBYTE lpMsg = g_ServerPlayerMgr.GetMessage(GetID(),dwMsgSize, nLeaveMsgNumber);
	while(VALID_POINT(lpMsg) && IsConnected())
	{
		g_ServerPlayerMgr.HandleMessage(lpMsg, dwMsgSize, (DWORD)this);
		g_ServerPlayerMgr.ReturnMessage(GetID(), lpMsg);
		lpMsg = g_ServerPlayerMgr.GetMessage(GetID(),dwMsgSize, nLeaveMsgNumber);
	}

	return 0;
}

VOID ServerPlayer::Destroy()
{
	mID = 0;
	mIsConnected = FALSE;
}