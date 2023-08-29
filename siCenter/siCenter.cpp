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
*	@file		siCenter.cpp
*	@author		lc
*	@date		2011/03/15	initial
*	@version	0.0.1.0
*	@brief		中心服务器
*/


#include "stdafx.h"
#include "center_server.h"


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	memorysystem::init_new_protect();
	serverbase::init_network();
	serverbase::init_serverbase();

	_set_se_translator( serverdump::si_translation ); 

	try
	{
		if (g_center_server.Init(hInstance) == TRUE)
		{
			g_center_server.MainLoop();
		}
		g_center_server.Destroy();
	}
	catch( serverdump::throw_exception )
	{
		throw;
	}

	serverbase::destroy_serverbase();
	serverbase::destroy_network();

	return 0;
	return 0;
}



