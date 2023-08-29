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
*	@file		world_server.h
*	@author		lc
*	@date		2011/02/22	initial
*	@version	0.0.1.0
*	@brief		
*/

#include "StdAfx.h"
#include "world_server.h"
#include "bill_server.h"
#include "..\common\filesystem\file_container.h"

world_server::world_server(void) : data_(), dw_time_(0)
{
}

world_server::~world_server(void)
{
	destroy();
}

BOOL world_server::init(INT n_index_)
{
	if( n_index_ < 0 ) return FALSE;

	dw_time_	=	timeGetTime();

	TCHAR sz_temp[X_SHORT_NAME] = {_T('\0')};
	_stprintf(sz_temp, _T("zone%d"), n_index_);

	tstring str_world_name = bill_server::p_var->get_string(_T("name"), sz_temp);
	if( str_world_name.empty() ) return FALSE;

	data_.b_connect			=	FALSE;
	data_.dw_name_crc		=	get_tool()->crc32(str_world_name.c_str());
	data_.dw_ip				=	0;
	data_.n_port			=	0;
	_tcsncpy(data_.sz_name, str_world_name.c_str(), X_SHORT_NAME);
	
	return TRUE;
}

VOID world_server::update()
{
	if( is_connect() )
	{
		update_session();
	}
}

VOID world_server::destroy()
{

}

BOOL world_server::world_login()
{
	if( is_connect() ) return FALSE;	

	data_.b_connect			=	TRUE;

	return TRUE;
}

BOOL world_server::world_logout()
{
	if( !is_connect() ) return FALSE;	

	data_.b_connect			=	FALSE;
	data_.dw_ip				=	0;
	data_.n_port			=	0;

	return TRUE;
}

VOID world_server::update_session()
{
	LPBYTE	p_receive		=	NULL;
	DWORD	dw_size		=	0;
	INT		n_unrecv		=	0;
	DWORD	dw_time		=	0;

	p_receive = g_billserver.get_world_manager().recv_message(data_.dw_name_crc, dw_size, n_unrecv);

	while( VALID_POINT(p_receive) )
	{
		g_billserver.get_world_manager().handle_command((tag_net_message*)p_receive, dw_size, (DWORD)this);

		g_billserver.get_world_manager().return_message(data_.dw_name_crc, p_receive);

		p_receive = g_billserver.get_world_manager().recv_message(data_.dw_name_crc, dw_size, n_unrecv);
	}
}
