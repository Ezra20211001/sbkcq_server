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
*	@file		world_manager.h
*	@author		lc
*	@date		2011/02/23	initial
*	@version	0.0.1.0
*	@brief		
*/


#include "StdAfx.h"
#include "world_manager.h"
#include "world_server.h"
#include "bill_server.h"

#include "../common/ServerDefine/bill_message_server.h"

world_manager::world_manager(void)
{
	p_session = new few_connect_server;
}

world_manager::~world_manager(void)
{
	SAFE_DELETE(p_session);
}

BOOL world_manager::init()
{

	INT n_world_num = bill_server::p_var->get_dword(_T("num zone_server"));

	for(INT n = 0; n < n_world_num; ++n)
	{
		world_server* p_world = new world_server;

		if( FALSE == p_world->init(n) )
		{
			SAFE_DELETE(p_world);
			return FALSE;
		}
		map_world.add(p_world->get_id(), p_world);
	}

	if( map_world.empty() )
		return FALSE;

	register_net_message();

	INT n_port = bill_server::p_var->get_int(_T("port"), _T("zone_session"));
	p_session->init(fastdelegate::MakeDelegate(this, &world_manager::login_call_back),
		fastdelegate::MakeDelegate(this, &world_manager::logout_call_back), n_port);

	return TRUE;
}

VOID world_manager::destroy()
{
	world_server* p_world = NULL;

	map_world.reset_iterator();
	while( map_world.find_next(p_world) )
	{
		SAFE_DELETE(p_world);
	}
	map_world.clear();

	p_session->destory();

	unregister_net_message();
}

VOID world_manager::update()
{
	world_server* p_world = NULL;

	map_world.reset_iterator();
	while( map_world.find_next(p_world) )
	{
		p_world->update();
	}
}

VOID world_manager::register_net_message()
{
	REGISTER_NET_MSG("NWB_Login",	world_manager,	handle_login,		_T("NWB_Login") );
}

VOID world_manager::unregister_net_message()
{
	UNREGISTER_NET_MSG("NWB_Login",	world_manager,	handle_login);
}

DWORD world_manager::login_call_back(LPBYTE p_byte_, DWORD dw_size_)
{
	tagNWB_Login* p_receive = (tagNWB_Login*)p_byte_;

	g_billserver.lock_update();

	DWORD dw_name_crc = get_tool()->crc32(p_receive->sz_world_name);

	world_server* p_world = get_world(dw_name_crc);
	if( !VALID_POINT(p_world) )
	{
		print_message(_T("sigameserver login faild, name<%s> not register\r\n"), p_receive->sz_world_name);

		g_billserver.unlock_update();

		return INVALID_VALUE;
	}

	if( !p_world->world_login() )
	{
		print_message(_T("sigameserver<%s>have exist\r\n"), p_receive->sz_world_name);

		g_billserver.unlock_update();

		return INVALID_VALUE;
	}

	print_message(_T("sigameserver<%s>login ok\r\n"),p_receive->sz_world_name);

	g_billserver.unlock_update();

	return dw_name_crc;
}

DWORD world_manager::logout_call_back(DWORD dw_param_)
{
	DWORD dw_world_id = dw_param_;

	g_billserver.lock_update();

	world_server* p_world = get_world(dw_world_id);
	if( !VALID_POINT(p_world) )
	{
		g_billserver.unlock_update();

		return 0; 
	}

	p_world->world_logout();
	print_message(_T("sigameserver<%s>logout\r\n"), p_world->get_name());

	g_billserver.unlock_update();

	return 0;
}

DWORD world_manager::handle_login(tag_net_message* p_message_, world_server* p_world_)
{
	tagNBW_Login send;
	send.dw_error_code = E_Success;
	p_session->send_msg(p_world_->get_id(), &send, send.dw_size);

	return E_Success;
}
