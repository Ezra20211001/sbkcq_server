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
*	@file		file_system.h
*	@author		lc
*	@date		2011/02/15	initial
*	@version	0.0.1.0
*	@brief		
*/


#include "stdafx.h"
#include "file_system.h"

#include "..\serverbase\file_io_manager.h"


namespace filesystem{

file_system::file_system()
{
	
}
file_system::~file_system()
{
	
}


DWORD file_system::open_file(LPCTSTR sz_file_name_)
{
	DWORD dw_handle = FILE_HANDLE_INVALID;

	dw_handle = get_file_io_mgr()->create(sz_file_name_,	GENERIC_READ,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS, NULL);

	if( dw_handle == FILE_HANDLE_INVALID )
		dw_handle = (DWORD)INVALID_VALUE;
	

	return dw_handle;
}


BOOL file_system::close_file(DWORD dw_handle_)
{
	ASSERT(dw_handle_);
	BOOL b_result = FALSE;

	b_result = get_file_io_mgr()->close(dw_handle_);
	
	return b_result;
}

DWORD file_system::read_file(PVOID p_data_out_, DWORD dw_size, DWORD dw_handle_)
{
	ASSERT(p_data_out_);
	ASSERT(dw_handle_);
	DWORD dw_result = 0;

	dw_result = get_file_io_mgr()->read(dw_handle_, p_data_out_, dw_size);
	
	return dw_result;
}



DWORD file_system::seek_file(DWORD dw_hangle_, INT n_offset_, DWORD dw_origin_)
{
	ASSERT(dw_hangle_);
	DWORD dw_result = 0;
	
	dw_result = get_file_io_mgr()->seek(dw_hangle_, n_offset_, dw_origin_);
	
	return dw_result;
}



DWORD file_system::tell_file(DWORD dw_handle_)
{
	ASSERT(dw_handle_);
	DWORD dw_result = 0;

	dw_result = get_file_io_mgr()->seek(dw_handle_, 0, FILE_SEEK_CURRENT);

	return dw_result;
}

DWORD file_system::get_size(LPCTSTR sz_file_name_)
{
	ASSERT(sz_file_name_);
	DWORD dw_result = 0;

	dw_result = get_file_io_mgr()->get_size(sz_file_name_);
	
	return dw_result;
}


DWORD file_system::load_file(LPVOID p_data_out_, LPCTSTR sz_file_name_)
{
	ASSERT(sz_file_name_);
	DWORD dw_result = 0;
	
	dw_result = get_file_io_mgr()->load_to_memory(p_data_out_, sz_file_name_);
	
	return dw_result;
}

}