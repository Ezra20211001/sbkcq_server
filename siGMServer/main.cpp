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
 *	@file		main
 *	@author		mwh
 *	@date		2011/04/07	initial
 *	@version	0.0.1.0
 *	@brief		GMServer
*/

#include "stdafx.h"
#include "GMServer.h"

INT APIENTRY _tWinMain(HINSTANCE hInst, HINSTANCE, LPTSTR, INT)
{
	// 禁止电源管理
	::SystemParametersInfo(SPI_SETLOWPOWERTIMEOUT, 0, NULL, 0);
	::SystemParametersInfo(SPI_SETPOWEROFFTIMEOUT, 0, NULL, 0);

	// 禁止屏保
	::SystemParametersInfo(SPI_SETSCREENSAVETIMEOUT, 0, NULL, 0);

	::SetThreadPriority( GetCurrentThread(), THREAD_PRIORITY_IDLE);
	memorysystem::init_new_protect();
	serverbase::init_network();
	serverbase::init_serverbase();

	THROW_EXCEPTION

	if(g_GMServer.Init(hInst))
	{
		g_GMServer.MainLoop();
		print_message(_T("\nsiGMServer is running!!\n"));
	}
	g_GMServer.Destroy();

	serverbase::destroy_serverbase();
	serverbase::destroy_network();

	return 0;
}