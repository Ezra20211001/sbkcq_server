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
*	@file		net_command_manager.h
*	@author		lc
*	@date		2011/02/16
*	@version	
*	@brief		
*/
#include "Stdafx.h"
#include "net_command_manager.h"

namespace serverframe {

net_command_manager::net_command_manager()
{

}

net_command_manager::~net_command_manager()
{
    map_command.reset_iterator();
    tag_command* p_command = NULL;
    while( map_command.find_next(p_command) )
    {
        delete(p_command);
    }

    map_command.clear();
}

BOOL net_command_manager::register_message(LPCSTR sz_command_, NET_MESSAGE_PROC fn_, LPCTSTR sz_description_)
{
	DWORD dw_id = get_tool()->crc32(sz_command_);
	tag_command* pCmd = map_command.find(dw_id);
	if( VALID_POINT(pCmd) )
	{
		if( pCmd->str_command != sz_command_ )
		{
			ASSERT(0);	
			return FALSE;
		}

		ASSERT(!pCmd->list_command_fn.is_exist(fn_));	
		pCmd->list_command_fn.push_back(fn_);
	}
	else
	{
		pCmd = new tag_command;
		pCmd->dw_disposal_num = 0;
		pCmd->list_command_fn.push_back(fn_);
		pCmd->str_command = sz_command_;
		pCmd->str_description = sz_description_;
		map_command.add(dw_id, pCmd);
	}
	return TRUE;
}

BOOL net_command_manager::unregister_message(LPCSTR sz_command_, NET_MESSAGE_PROC fn_)
{
	DWORD dw_id = get_tool()->crc32(sz_command_);
	tag_command* p_command = map_command.find(dw_id);
	if( !VALID_POINT(p_command) )
		return FALSE;

	if( FALSE == p_command->list_command_fn.erase(fn_) )
		return FALSE;
	
	if( p_command->list_command_fn.size() <= 0 )
	{
		SAFE_DELETE(p_command);
		map_command.erase(dw_id);
	}

	return TRUE;
}

BOOL net_command_manager::handle_message(tag_net_message* p_message_, DWORD dw_message_size_, DWORD dw_param_)
{
	tag_command* p_command = map_command.find(p_message_->dw_message_id);
	if( !VALID_POINT(p_command) )
	{
		print_message(_T("unknown net command recved[<command_id>%u <size>%d]\r\n"), p_message_->dw_message_id, dw_message_size_);
		return FALSE;
	}

	if( p_message_->dw_size != dw_message_size_ )
	{
		print_message(_T("unlawful net command size[<command_id>%s <size>%d]\r\n"), 
			get_tool()->unicode8_to_unicode(p_command->str_command.c_str()), p_message_->dw_size);
		return FALSE;
	}

	++p_command->dw_disposal_num;

	NET_MESSAGE_PROC fp = NULL;
	p_command->list_command_fn.reset_iterator();
	while(p_command->list_command_fn.find_next(fp))
		(fp)(p_message_, dw_param_);
	return TRUE;
}

}; //namespace serverframe