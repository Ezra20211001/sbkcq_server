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
*	@file		thread_manager.h
*	@author		lc
*	@date		2011/02/18	initial
*	@version	0.0.1.0
*	@brief		
*/

#include "stdafx.h"
#include "thread_manager.h"


namespace serverframe {

thread_manager::thread_manager()
{
	map_thread_handle.clear();
}

thread_manager::~thread_manager()
{
	ASSERT(map_thread_handle.size() == 0);
}

//-----------------------------------------------------------------------------
// ! 创建线程
//-----------------------------------------------------------------------------
BOOL thread_manager::create_thread(LPCTSTR sz_thread_name_, THREAD_PROC fn_, LPVOID p_param_)
{
	DWORD dw_id = get_tool()->crc32(sz_thread_name_);
	if( map_thread_handle.is_exist(dw_id) )
	{
		ERROR_CLUE_ON(_T("same name %s  thread is already exist"), sz_thread_name_);
		return FALSE;
	}

	HANDLE h_handle = (HANDLE)_beginthreadex
		(NULL, 0, fn_, p_param_, 0, NULL);
	
	if( 0 == h_handle )	
	{
		return FALSE;
	}

	map_thread_handle.add(dw_id, h_handle);
	return TRUE;
}


//-----------------------------------------------------------------------------
// ! 等待线程销毁
//-----------------------------------------------------------------------------
BOOL thread_manager::waitfor_thread_destroy(LPCTSTR sz_thread_name_, DWORD dw_wait_time_)
{
	DWORD dw_id = get_tool()->crc32(sz_thread_name_);
	if( FALSE == map_thread_handle.is_exist(dw_id) )
	{
		ERROR_CLUE_ON(_T("thread %s is not exist"), sz_thread_name_);
		return FALSE;
	}

	HANDLE h_handle = map_thread_handle.find(dw_id);
	DWORD dw_result = 0;
	if( h_handle )
	{
		dw_result = ::WaitForSingleObject( h_handle, dw_wait_time_ );
		switch( dw_result )
		{
		case WAIT_OBJECT_0:
			SAFE_CLOSE_HANDLE( h_handle );
			map_thread_handle.erase( dw_id );
			return TRUE;
			break;

		case WAIT_TIMEOUT:
			ERROR_CLUE_ON(_T("waitfor thread %s destroy time out"), sz_thread_name_);
			break;

		default:
			ERROR_CLUE_ON(_T("error waitfor thread %s to destroy"), sz_thread_name_);
			break;
		}
	}

	return FALSE;
}


//-----------------------------------------------------------------------------
//！ 永久等待所有线程销毁
//-----------------------------------------------------------------------------
VOID thread_manager::waitfor_all_thread_destroy()
{
	std::list<HANDLE> list_handle;
	INT n_thread_num = map_thread_handle.copy_value_to_list(list_handle);
	
	for(INT n=0; n<n_thread_num; n++)
	{
		HANDLE h_handle = list_handle.front();
		list_handle.pop_front();
		if( h_handle )
		{
			::WaitForSingleObject( h_handle, INFINITE );
		}
	}

	map_thread_handle.clear();
}


//-----------------------------------------------------------------------------
//！ 检测线程是否正在运行
//-----------------------------------------------------------------------------
BOOL thread_manager::is_thread_active(LPCTSTR sz_thread_name_)
{
	DWORD dw_id = get_tool()->crc32(sz_thread_name_);
	if( FALSE == map_thread_handle.is_exist(dw_id) )
		return FALSE;

	HANDLE h_handle = map_thread_handle.find(dw_id);
	DWORD dw_result = 0;
	if( h_handle )
	{
		dw_result = ::WaitForSingleObject( h_handle, 0 );
		switch( dw_result )
		{
		case WAIT_OBJECT_0:
			return FALSE;
			break;

		case WAIT_TIMEOUT:
			return TRUE;
			break;

		default:
			return FALSE;
			break;
		}
	}

	return FALSE;
}


//-----------------------------------------------------------------------------
// ! 获得指定线程句柄
//-----------------------------------------------------------------------------
HANDLE thread_manager::get_thread_handle(LPCTSTR sz_thread_name_)
{ 
	return map_thread_handle.find(get_tool()->crc32(sz_thread_name_)); 
}

} // namespace serverframe {
