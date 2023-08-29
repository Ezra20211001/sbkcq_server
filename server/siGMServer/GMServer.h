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
 *	@brief		GM·þÎñÆ÷
*/

#ifndef __SI_GMSERVER_H__
#define __SI_GMSERVER_H__

#include "AutoMutex.h"

class GMServer
{
public:
	GMServer();
	~GMServer();
public:
	BOOL Init(HINSTANCE hInstance);
	VOID MainLoop();
	VOID Destroy();
public:
	UINT ThreadUpdate();
	static UINT WINAPI ThreadCall(LPVOID lpVoid);
public:
	inline VOID Lock();
	inline VOID UnLock();
	inline VOID ShutDown();
public:
	inline log_file* GetLogFile();
	inline file_system* GetConfigFile();
	inline file_container* GetConfig();
	inline thread_manager* GetThreadMan();
private:
	Mutex mMutex;
	log_file* mLog;
	file_system* mIniFile;
	file_container* mConfig;
	thread_manager* mThreadMan;
	volatile BOOL mTerminate;
};

inline VOID GMServer::Lock()
{ 
	mMutex.lock();
}

inline VOID GMServer::UnLock() 
{ 
	mMutex.unlock(); 
}

inline VOID GMServer::ShutDown()
{ 
	Interlocked_Exchange((LPLONG)&mTerminate, TRUE);
}

inline log_file* GMServer::GetLogFile()
{
	ASSERT(mLog != 0);
	return mLog;
}
inline file_system* GMServer::GetConfigFile()
{
	ASSERT(mIniFile != 0);
	return mIniFile;
}

inline file_container* GMServer::GetConfig()
{
	ASSERT(mConfig != 0);
	return mConfig;
}
inline thread_manager* GMServer::GetThreadMan()
{
	ASSERT(mThreadMan != 0);
	return mThreadMan;
}

extern GMServer g_GMServer;

#endif //__SI_GMSERVER_H__