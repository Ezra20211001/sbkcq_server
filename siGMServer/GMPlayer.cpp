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
*	@brief		GM客户端
*/

#include "StdAfx.h"
#include "GMPlayer.h"


GMPlayer::GMPlayer(DWORD dwID):
mID(dwID),mPrivilege(0),mIsConnected(FALSE),
mConnectLost(FALSE),mToolType(ETTYPE_COMMON)
{

}

GMPlayer::~GMPlayer()
{
	mID = 0; mIsConnected = FALSE;
}

BOOL GMPlayer::Init(const TCHAR* pAccount, const TCHAR* pPsd, DWORD dwPrivilege, const TCHAR* pIP)
{
	ASSERT(pIP != 0);
	ASSERT(pPsd != 0);
	ASSERT(pAccount != 0);

	mIP = pIP;
	mPassword = pPsd;
	mAccount = pAccount;
	mPrivilege = dwPrivilege;

	return TRUE;
}

INT GMPlayer::Update()
{
	return UpdateSession();
}

INT GMPlayer::UpdateSession()
{
	if(IsConnectLost())return CON_LOST;
	if(!IsConnected()) return 0;

	// 处理消息
	DWORD dwMsgSize = 0, dwTime = 0;
	INT nLeaveMsgNumber = 0;

	LPBYTE lpMsg = g_GMPlayerManager.GetMessage(GetID(),dwMsgSize, nLeaveMsgNumber);
	while(VALID_POINT(lpMsg) && IsConnected())
	{
		g_GMPlayerManager.HandleMessage(lpMsg, dwMsgSize, (DWORD)this);
		g_GMPlayerManager.ReturnMessage(GetID(), lpMsg);
		lpMsg = g_GMPlayerManager.GetMessage(GetID(),dwMsgSize, nLeaveMsgNumber);
	}

	return 0;
}

VOID GMPlayer::Destroy()
{
	/*mID = 0;*/ mIsConnected = FALSE;
	//mIP.clear(); mAccount.clear();
}
BOOL GMPlayer::Proof(const TCHAR* pPsd, const TCHAR* pIP, EToolType eToolType)
{
	return (mPassword == pPsd && mIP == pIP && mToolType == eToolType);
}

BOOL GMPlayer::OnLogin()
{
	if(mIsConnected) return FALSE;
	mConnectLost = FALSE;
	return (mIsConnected = TRUE);
}

BOOL GMPlayer::OnLogout()
{
	if(!mIsConnected) return FALSE;
	mConnectLost = TRUE;
	return !(mIsConnected = FALSE);
}