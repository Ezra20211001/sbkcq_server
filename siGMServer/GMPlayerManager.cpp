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
*	@brief		GM 管理器
*/

#include "stdafx.h"
#include "../common/WorldDefine/GMCMessage.h"
#include "GMPlayer.h"
#include "GMServer.h"
#include "GMPlayerManager.h"
#include "GMServerHanlder.h"

GMPlayerManager g_GMPlayerManager;

#define GMLOGNAME _T("gmlog")
#define GMLOGNAME_ANSI "gmlog"
#define GMMONEYNAME _T("gmmoney")
#define GMMONEYLOGNAME_ANSI "gmmoney"
#define GMYUANBAONAME _T("gmyuanbao")
#define GMYUANBAOLOGNAME_ANSI "gmyuanbao"

#define MakeDelegateOfThis(func) fastdelegate::MakeDelegate(this,func)

struct GMPlayerOP
{
	VOID operator()(GMPlayer* Val){ Val->Destroy(); }
};

GMPlayerManager::GMPlayerManager()
:mGMLogDB(0),mGMAccountDB(0),mNetSession(0),mUpdateAccountTick(0)
{
}

GMPlayerManager::~GMPlayerManager()
{
}

BOOL GMPlayerManager::Init(GMServer* pServer)
{
	ASSERT(pServer != 0);
	ASSERT(pServer->GetConfig());

	RegisterCmd();

	// 读取 GMAccountDB 
	INT xGMAccountDBPort =  pServer->GetConfig()->get_int(_T("db_port gmaccountdb"));
	const TCHAR* xGMAccountDBIP =  pServer->GetConfig()->get_string(_T("db_ip gmaccountdb"));
	const TCHAR* xGMAccountDBName =  pServer->GetConfig()->get_string(_T("db_name gmaccountdb"));
	const TCHAR* xGMAccountDBUser =  pServer->GetConfig()->get_string(_T("db_user gmaccountdb"));
	const TCHAR* xGMAccountDBPassword =  pServer->GetConfig()->get_string(_T("db_password gmaccountdb"));
	mGMAccountDB = new db_interface; 

	ASSERT(mGMAccountDB != 0);
	ASSERT(xGMAccountDBPort != 0);
	ASSERT(xGMAccountDBIP != 0);
	ASSERT(xGMAccountDBName != 0);
	ASSERT(xGMAccountDBUser != 0);
	ASSERT(xGMAccountDBPassword != 0);
	if(!mGMAccountDB->init_db(xGMAccountDBIP, 
							xGMAccountDBUser, 
							xGMAccountDBPassword, 
							xGMAccountDBName, 
							xGMAccountDBPort))
	{
		ErrMessage(_T("\n\nfatal error on connect gmaccountdb: %s\n\n"), xGMAccountDBName);
		return FALSE;
	}

	// 读取 GMLogDB
	INT xGMLogDBPort =  pServer->GetConfig()->get_int(_T("db_port gmlogdb"));
	const TCHAR* xGMLogDBIP =  pServer->GetConfig()->get_string(_T("db_ip gmlogdb"));
	const TCHAR* xGMLogDBName =  pServer->GetConfig()->get_string(_T("db_name gmlogdb"));
	const TCHAR* xGMLogDBUser =  pServer->GetConfig()->get_string(_T("db_user gmlogdb"));
	const TCHAR* xGMLogDBPassword =  pServer->GetConfig()->get_string(_T("db_password gmlogdb"));
	mGMLogDB = new db_interface; ASSERT(mGMLogDB != 0);

	ASSERT(mGMLogDB != 0);
	ASSERT(xGMLogDBPort != 0);
	ASSERT(xGMLogDBIP != 0);
	ASSERT(xGMLogDBName != 0);
	ASSERT(xGMLogDBUser != 0);
	ASSERT(xGMLogDBPassword != 0);
	if(!mGMLogDB->init_db(xGMLogDBIP, 
						xGMLogDBUser, 
						xGMLogDBPassword, 
						xGMLogDBName, 
						xGMLogDBPort))
	{
		ErrMessage(_T("\n\nfatal error on connect gmlogdb: %s\n\n"),xGMLogDBName);
		return FALSE;
	}


	// GMPlayerServer
	INT xServerPort = pServer->GetConfig()->get_int(_T("port gmplayersession"));
	mNetSession = new few_connect_server;

	ASSERT(xServerPort != 0);
	ASSERT(mNetSession != 0);

	mNetSession->init(MakeDelegateOfThis(&GMPlayerManager::LoginCallBack),
		MakeDelegateOfThis(&GMPlayerManager::LogoutCallBack),xServerPort);

	this->LoadAllGMAccount();

	return TRUE;
}

VOID GMPlayerManager::Update()
{
	this->UpdateGMAccount();
	this->CreateGMLogTable();
	this->UpdateAllSession();
}

VOID GMPlayerManager::Destroy()
{
	GMPlayer* xGMPlayer = 0;
	mGMPlayer.reset_iterator();
	while(mGMPlayer.find_next(xGMPlayer))
		GMPlayerOP()(xGMPlayer);

	UnRegisterCmd();
	SAFE_DELETE(mNetSession);
}

VOID GMPlayerManager::DestroyPlayer()
{
	if(mDestoryPlayer.empty()) return ;

	DWORD dwID = 0;
	while(VALID_POINT((dwID = mDestoryPlayer.pop_front())))
	{
		GMPlayer* xGMPlayer = mGMPlayer.find(dwID);
		SAFE_DELETE(xGMPlayer); mGMPlayer.erase(dwID);
	}

	mDestoryPlayer.clear();
}

VOID GMPlayerManager::UpdateAllSession()
{
	GMPlayer* xGMPlayer = 0;
	mGMPlayer.reset_iterator();
	while(mGMPlayer.find_next(xGMPlayer))
	{
		INT xRet = xGMPlayer->Update();
 		if(xRet == CON_LOST)
 		{
			xGMPlayer->Reset( );
 			///mDestoryPlayer.push_back(xGMPlayer->GetID());
 			print_message(_T("\n%s %s connect lost!\n"), \
 				xGMPlayer->GetIP().c_str(), xGMPlayer->GetAccount().c_str());
 		}
	}
}

VOID GMPlayerManager::Kick(DWORD dwID)
{
	GMPlayer* xGMPlayer = GetGMPlayer(dwID);
	if(VALID_POINT(xGMPlayer))
	{
		mNetSession->kick_connect(dwID);
		print_message(_T("\n%s %s Be Kicked!\n"),
			xGMPlayer->GetIP().c_str(), xGMPlayer->GetAccount().c_str());
	}
}

VOID GMPlayerManager::RegisterCmd()
{
	g_GMLogicHandler.RegisterCmd();
}

VOID GMPlayerManager::UnRegisterCmd()
{
	g_GMLogicHandler.UnRegisterCmd();
}

DWORD GMPlayerManager::LoginCallBack(LPBYTE lpMsg, DWORD dwSize)
{
	NET_C2GMS_GMLogin* pMsg = (NET_C2GMS_GMLogin*)(lpMsg);
	g_GMServer.Lock();

	DWORD dwPlayerID = INVALID_VALUE;
	GMPlayer* xGMPlayer = GetGMPlayer(pMsg->szAccount);
	if(VALID_POINT(xGMPlayer))
	{
		if(!xGMPlayer->OnLogin())
		{
			g_GMServer.UnLock();
			return dwPlayerID;
		}
		dwPlayerID = xGMPlayer->GetID();
	}else{
		print_message(_T("\n\nUnknown GM Connected![name:%s]\n\n"), pMsg->szAccount);
	}

	g_GMServer.UnLock();
	return dwPlayerID;
}

DWORD GMPlayerManager::LogoutCallBack(DWORD dwParam)
{
	DWORD dwSessionID = dwParam;

	g_GMServer.Lock();

	GMPlayer* xGMPlayer = GetGMPlayer(dwSessionID);
	if(VALID_POINT(xGMPlayer))
	{
		xGMPlayer->OnLogout();
		SetLoginStatus(xGMPlayer->GetID(), 0);
		print_message(_T("\n%s %s Disconnected!\n"),
			xGMPlayer->GetIP().c_str(), xGMPlayer->GetAccount().c_str());
	}

	g_GMServer.UnLock();

	return 0;
}

VOID GMPlayerManager::SetLoginStatus(DWORD dwID, INT nStatus)
{
	ASSERT(mGMAccountDB != 0);

	odbc::sql_language_disposal* p_stream = mGMAccountDB->get_io();
	
	p_stream->update_item("gmaccount");
	p_stream->write_string("login_status=") << nStatus;

	if(dwID != 0)
	{
		p_stream->where_item();
		p_stream->write_string("id=") << dwID;
	}

	mGMAccountDB->sql_execute(p_stream);

	mGMAccountDB->return_io(p_stream);
}

VOID GMPlayerManager::LoadAllGMAccount()
{
	ASSERT(mGMAccountDB != 0);

	this->SetLoginStatus(0, 0);

	odbc::sql_language_disposal* p_stream = mGMAccountDB->get_io();
	p_stream->select_item("gmaccount", "id,name,password,privilege,ip,type");

	odbc::execute_result* pResult = mGMAccountDB->sql_query(p_stream);
	if(VALID_POINT(pResult)) this->InitGMAccount(pResult);
	//this->AddServerToolPlayer();

	mGMAccountDB->return_io(p_stream);
	mGMAccountDB->free_result_query(pResult);
}

VOID GMPlayerManager::InitGMAccount(odbc::execute_result* pResult)
{
	ASSERT(VALID_POINT(pResult));
	if(!VALID_POINT(pResult)) return;

	for(INT n = 0; n < pResult->get_row_count(); ++n)
	{
		DWORD dwPlayerID = (*pResult)[0].get_dword();
		GMPlayer* NewPlayer = mGMPlayer.find(dwPlayerID);
		if(!VALID_POINT(NewPlayer)) NewPlayer = new GMPlayer(dwPlayerID);
#ifdef _UNICODE
		ZeroMemory(mConvertBuffer, sizeof(TCHAR)*CONVERTBUFFERLEN);
		MultiByteToWideChar(CP_ACP,NULL,(*pResult)[1].get_string(),(*pResult)[1].get_length(),mConvertBuffer,CONVERTBUFFERLEN);
		NewPlayer->SetAccount(mConvertBuffer);

		ZeroMemory(mConvertBuffer, sizeof(TCHAR)*CONVERTBUFFERLEN);
		MultiByteToWideChar(CP_ACP,NULL,(*pResult)[2].get_string(),(*pResult)[2].get_length(),mConvertBuffer,CONVERTBUFFERLEN);
		NewPlayer->SetPassword(mConvertBuffer);

		ZeroMemory(mConvertBuffer, sizeof(TCHAR)*CONVERTBUFFERLEN);
		MultiByteToWideChar(CP_ACP,NULL,(*pResult)[4].get_string(),(*pResult)[4].get_length(),mConvertBuffer,CONVERTBUFFERLEN);
		NewPlayer->SetIP(mConvertBuffer);

		NewPlayer->SetPrivilege((*pResult)[3].get_dword());
#else
		NewPlayer->Init((*pResult)[1].get_string(), (*pResult)[2].get_string(),
			(*pResult)[3].get_dword(), (*pResult)[4].get_string());
#endif
		NewPlayer->SetType((EToolType)(*pResult)[5].get_dword());

		mGMPlayer.add(NewPlayer->GetID(), NewPlayer);
		mGMPlayerID.add(get_tool()->crc32(NewPlayer->GetAccount().c_str()), NewPlayer->GetID());
		pResult->next_row();
	}

	//print_message(_T("\n\nRead %04u GMAccounts from gmdb!!\n\n"), pResult->get_row_count());
}

VOID GMPlayerManager::UpdateGMAccount()
{
	ASSERT(mGMAccountDB != 0);

	if(++mUpdateAccountTick < 3 * TICK_PER_SECOND * 60)
		return ;

	mUpdateAccountTick = 0;
	odbc::sql_language_disposal* p_stream = mGMAccountDB->get_io();
	p_stream->select_item("gmaccount", "id,name,password,privilege,ip,type");
	p_stream->where_item();
	p_stream->write_string("login_status=0");

	odbc::execute_result* pResult = mGMAccountDB->sql_query(p_stream);
	if(VALID_POINT(pResult)) this->InitGMAccount(pResult);

	mGMAccountDB->return_io(p_stream);
	mGMAccountDB->free_result_query(pResult);
}

VOID GMPlayerManager::CreateGMLogTable()
{
	ASSERT(VALID_POINT(mGMLogDB));
	if(GetCurrentDWORDTime().day == mLogTime.day)
		return;

	char Postfix[8] = {0};
	tagDWORDTime dw_time = mLogTime = GetCurrentDWORDTime();
	sprintf_s(Postfix, sizeof(Postfix), "_%02d%02d", dw_time.month, dw_time.day);
	mGMLogPostfix = Postfix;

	//! 创建log表
	odbc::sql_language_disposal* pStream = mGMLogDB->get_io();

	this->DoCreateGMLogTable(GMLOGNAME, Postfix, pStream);
	this->DoCreateGMLogTable(GMMONEYNAME, Postfix, pStream);
	this->DoCreateGMLogTable(GMYUANBAONAME, Postfix, pStream);

	mGMLogDB->return_io(pStream);
}
VOID GMPlayerManager::DoCreateGMLogTable(const TCHAR* pTableName, const char* pPostFix, odbc::sql_language_disposal* pStream)
{
	ASSERT(VALID_POINT(pStream));
	if(!VALID_POINT(pStream)) return;
	pStream->clear();
	pStream->write_string(_T("CREATE TABLE IF NOT EXISTS "));
	pStream->write_string(pTableName);
	pStream->write_string(pPostFix);
	pStream->write_string(_T(" LIKE "));
	pStream->write_string(pTableName);

	BOOL bCreateLogTable = mGMLogDB->sql_execute(pStream);
	print_message(_T("\n\nCreate %s%s table %s!!\n\n"),pTableName, 
		get_tool()->unicode8_to_unicode(pPostFix), bCreateLogTable ? _T("Successful") : _T("Failed"));
}
VOID GMPlayerManager::WriteGMLog(GMPlayer* pPlayer, DWORD dwErrorCode, const TCHAR* pLogCmd)
{
	if(!VALID_POINT(pPlayer) || !VALID_POINT(pLogCmd)) return;

	odbc::sql_language_disposal* pStream = mGMLogDB->get_io();
	ASSERT(VALID_POINT(pStream));
	pStream->clear();

	pStream->insert_item(GMLOGNAME_ANSI, mGMLogPostfix.c_str());
	pStream->write_string("gm_accountid=") << pPlayer->GetID();
	pStream->write_string(",gm_cmd='").write_string(pLogCmd).write_string("'");
	pStream->write_string(",ip='").write_string(pPlayer->GetIP().c_str()).write_string("'");
	pStream->write_string(",error_code=") << dwErrorCode;
	pStream->write_string(",time=now()");

	mGMLogDB->add_asynchronism_query(pStream);
}
VOID GMPlayerManager::WriteGMLog(DWORD dwAccountID, DWORD dwErrorCode, const TCHAR* pLogCmd)
{
	GMPlayer* xGMPlayer = GetGMPlayer(dwAccountID);
	if(VALID_POINT(xGMPlayer)) WriteGMLog(xGMPlayer, dwErrorCode, pLogCmd);
}

VOID GMPlayerManager::WriteYuanBaoLog(GMPlayer* pPlayer, DWORD dw_account_id, INT nConType, INT nDiff, INT64 n64Total)
{
	if(!VALID_POINT(pPlayer) || nDiff == 0) return;

	odbc::sql_language_disposal* pStream = mGMLogDB->get_io();
	ASSERT(VALID_POINT(pStream));
	
	pStream->clear();
	pStream->insert_item(GMYUANBAOLOGNAME_ANSI, mGMLogPostfix.c_str());
	pStream->write_string("gm_accountid=") << pPlayer->GetID();
	pStream->write_string(",ip='").write_string(pPlayer->GetIP().c_str()).write_string("'");
	pStream->write_string(",account_id_ref=") << dw_account_id;
	pStream->write_string(",container_type=") << (BYTE)nConType;
	pStream->write_string(",num=") << nDiff;
	pStream->write_string(",total_num=") << n64Total;
	pStream->write_string(",time=now()");

	mGMLogDB->add_asynchronism_query(pStream);
}

VOID GMPlayerManager::WriteMoneyLog(GMPlayer* pPlayer, DWORD dw_role_id, INT nConType, INT64 n64Diff, INT64 n64Total)
{
	if(!VALID_POINT(pPlayer) || n64Diff == 0) return;

	odbc::sql_language_disposal* pStream = mGMLogDB->get_io();
	ASSERT(VALID_POINT(pStream));

	pStream->clear();
	pStream->insert_item(GMMONEYLOGNAME_ANSI, mGMLogPostfix.c_str());
	pStream->write_string("gm_accountid=") << pPlayer->GetID();
	pStream->write_string(",ip='").write_string(pPlayer->GetIP().c_str()).write_string("'");
	pStream->write_string(",role_id_ref=") << dw_role_id;
	pStream->write_string(",container_type=") << (BYTE)nConType;
	pStream->write_string(",num=") << n64Diff;
	pStream->write_string(",total_num=") << n64Total;
	pStream->write_string(",time=now()");

	mGMLogDB->add_asynchronism_query(pStream);
}

VOID GMPlayerManager::SendMessageEX(DWORD PlayerTpye, LPVOID lpMsg, DWORD dwSize)
{
	if(!VALID_POINT(mNetSession)) 
		return;

	GMPlayer* xGMPlayer;
	mGMPlayer.reset_iterator( );
	while (mGMPlayer.find_next(xGMPlayer))
	{
		if(xGMPlayer->GetType() == PlayerTpye)
			xGMPlayer->SendMessage(lpMsg, dwSize);
	}
}