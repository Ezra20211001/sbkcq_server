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
*	@file		GMServer
*	@author		mwh
*	@date		2011/04/06	initial
*	@version	0.0.1.0
*	@brief		GM服务器
*/

#include "stdafx.h"
#include "GMServer.h"
#include "ServerPlayerManager.h"
#include "GMPlayerManager.h"
#include "GMLogQueryManager.h"
#include "GMForibAccMgr.h"

#define GMSERVER_INI _T("server_config\\gm\\gm")

GMServer g_GMServer;

GMServer::GMServer()
:mLog(0),mConfig(0),mThreadMan(0),mTerminate(FALSE)
{
	mLog = new log_file; ASSERT(mLog != 0);
	mConfig = new file_container; ASSERT(mConfig != 0);
	mIniFile = new file_system; ASSERT(mIniFile != 0);
	mThreadMan = new thread_manager; ASSERT(mThreadMan != 0);
}

GMServer::~GMServer()
{
	SAFE_DELETE(mLog);
	SAFE_DELETE(mConfig);
	SAFE_DELETE(mIniFile);
	SAFE_DELETE(mThreadMan);
}

BOOL GMServer::Init(HINSTANCE hInstance)
{
	///* 定时关服务器
	tagDWORDTime dwShutDownTime;
	ZeroMemory(&dwShutDownTime, sizeof(dwShutDownTime));
	dwShutDownTime.year = SHUT_DOWN_YEAY;
	dwShutDownTime.month = SHUT_DOWN_MONTH;

	DWORD dwCurTime = GetCurrentDWORDTime();

	if (dwCurTime > dwShutDownTime)
		return false;
	//*/

	mLog->create_log();

	TCHAR szPath[MAX_PATH] = {0};
	if(!get_file_io_mgr()->get_ini_path(szPath, GMSERVER_INI)||
	   !mConfig->load(mIniFile, szPath))
	{
		ErrMessage(_T("\n\nfatal error read server_config\\gm\\gm.ini!!\n\n"));
		return FALSE;
	}

	LONG xWindowW = mConfig->get_dword(_T("width display"));
	LONG xWindowH = mConfig->get_dword(_T("height display"));
	get_window()->init( xWindowW, xWindowH, TRUE);
	get_window()->create_window(_T("GMServer"), hInstance);

	// 逻辑层初始化
	if(!g_ServerPlayerMgr.Init(this))
	{
		ErrMessage(_T("\n\nfatal error on g_ServerPlayerMgr.Init!!\n\n"));
		return FALSE;
	}

	if(!g_GMPlayerManager.Init(this))
	{
		ErrMessage(_T("\n\nfatal error on g_GMPlayerManager.Init!!\n\n"));
		return FALSE;
	}


	if( !mThreadMan->create_thread(_T("ThreadUpdate_GMSever"), 
									GMServer::ThreadCall, this))
	{
		ErrMessage(_T("\n\n fatal error  create logic thread!!\n\n"));
		return FALSE;
	}

	if(!g_LogQueryMgr.Init())
	{
		ErrMessage(_T("\n\nfatal error on g_LogQueryMgr.Init!!\n\n"));
		return FALSE;
	}

	//! 一定要等待所有数据库连接上才能执行此管理器的初始化
	if(!g_GMForbidAccMgr.Init( ))
	{
		ErrMessage(_T("\n\nfatal error on g_GMForbidAccMgr.Init!!\n\n"));
		return FALSE;
	}

	return TRUE;
}

VOID GMServer::MainLoop()
{
	DWORD dwMessage, dwParam1, dwParam2;
	static DWORD _S_Current_Time = timeGetTime();

	while ( FALSE == get_window()->message_loop() && FALSE == mTerminate )
	{
		if( FALSE == get_window()->is_window_active() )
		{
			Sleep(30);
			continue;
		}


		while( get_window()->peek_window_message( dwMessage, dwParam1, dwParam2 ) )
		{
			if( dwMessage == WM_QUIT )
			{
				return;
			}
			if(dwMessage == WM_MYSELF_USER)
			{
				if(dwParam1 == 1)
				{
					get_window()->print_list();
				}
			}
		}
		Sleep(50);
	}
}

VOID GMServer::Destroy()
{
	Interlocked_Exchange((LPLONG)&mTerminate, TRUE);
	mThreadMan->waitfor_all_thread_destroy();

	// 销毁逻辑层
	g_ServerPlayerMgr.Destroy();
	g_GMPlayerManager.Destroy();
	g_GMForbidAccMgr.Destroy();

	get_window()->destroy();
}

UINT GMServer::ThreadUpdate()
{
	DWORD dwTime = 0;
	
	//! 让gmserver挂掉抛出dump
	_set_se_translator(serverdump::si_translation);

	try
	{
		while(mTerminate == FALSE)
		{
			dwTime = timeGetTime();

			Lock();

			// 逻辑层Update
			g_ServerPlayerMgr.Update();
			g_GMPlayerManager.Update();
			g_GMForbidAccMgr.Update();
			g_GMForbidAccMgr.Update_studio();//gx add 2013.11.07
			
			UnLock();

			dwTime = timeGetTime() - dwTime;
			if( dwTime < TICK_TIME )
				Sleep(TICK_TIME - dwTime);
		}
	}
	catch(...)
	{
		ShutDown();
	}

	_endthreadex(0);

	return 0;
}

UINT GMServer::ThreadCall(LPVOID lpVoid)
{
	ASSERT(lpVoid != 0);
	return static_cast<GMServer*>(lpVoid)->ThreadUpdate();
}
