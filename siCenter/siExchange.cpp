/*******************************************************************************

Copyright 2010 by Shengshi Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
Shengshi Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
Shengshi Interactive  Co., Ltd.

*******************************************************************************/

/**
*	@file		siExchange.cpp
*	@author		wmr
*	@date		2011/03/15	initial
*	@version	0.0.1.0
*	@brief		交易服务器
*/


#include "stdafx.h"
#include "pai_server.h"


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
		if (g_pai_server.Init(hInstance) == TRUE)
		{
			g_pai_server.MainLoop();
		}
		g_pai_server.Destroy();
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



