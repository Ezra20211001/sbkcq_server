/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/


#include "stdafx.h"
#include "bill_server.h"

//-----------------------------------------------------------------------------
// 控制台程序入口点
//-----------------------------------------------------------------------------
INT APIENTRY _tWinMain(HINSTANCE hInst, HINSTANCE, LPTSTR, INT)
{
	memorysystem::init_new_protect();
	serverbase::init_network();
	serverbase::init_serverbase();

	_set_se_translator( serverdump::si_translation ); 

	try
	{
		if (g_billserver.init(hInst) == TRUE)
		{
			g_billserver.main_loop();
		}
		g_billserver.destroy();

	}
	catch( serverdump::throw_exception )
	{
		throw;
	}
	
	serverbase::destroy_serverbase();
	serverbase::destroy_network();

	return 0;
}