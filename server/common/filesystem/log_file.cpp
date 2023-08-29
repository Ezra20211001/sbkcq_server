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
*	@file		log_file.h
*	@author		lc
*	@date		2011/02/15	initial
*	@version	0.0.1.0
*	@brief		
*/

#include "stdafx.h"
#include "log_file.h"

#include "..\serverbase\file_io_manager.h"

namespace filesystem {
#define MAX_BUFFER_SIZE 10240

log_file::log_file()
{
	dw_file_handle = FILE_HANDLE_INVALID;
}

log_file::~log_file()
{
	close_file();
}


//-----------------------------------------------------------------------------
//! 生成Log文件
//-----------------------------------------------------------------------------
BOOL log_file::create_log(LPCTSTR sz_file_name_)
{
	if( dw_file_handle != FILE_HANDLE_INVALID )
		get_file_io_mgr()->close( dw_file_handle );

	// 如果没有新的文件名，就使用默认的文件名
	if( NULL == sz_file_name_ )
	{
		TCHAR sz_log_time[MAX_PATH], sz_temp[MAX_PATH];
		GetModuleFileName(NULL, sz_temp, MAX_PATH);

		TCHAR *sz_result = _tcsrchr(sz_temp, _T('\\'));
		sz_result = sz_result ?	sz_result+1 :	sz_result = (TCHAR *)sz_temp;
		_stprintf(sz_log_file_name, _T("log\\%s"), sz_result);
		
		sz_result = _tcsrchr(sz_log_file_name, _T('.'));
		if( sz_result )
			*sz_result = '\0';	
		
		FILETIME st_current_time;
		GetSystemTimeAsFileTime(&st_current_time);
		sz_log_time[0] = _T('\0');
		WORD w_date, w_time;
		if (FileTimeToLocalFileTime(&st_current_time, &st_current_time) &&
				FileTimeToDosDateTime(&st_current_time, &w_date, &w_time))
		{
			wsprintf(sz_log_time, _T("[%d-%d-%d %02d-%02d-%02d %05d].log"),
					(w_date / 32) & 15, w_date & 31, (w_date / 512) + 1980,
					(w_time >> 11), (w_time >> 5) & 0x3F, (w_time & 0x1F) * 2, 
					GetCurrentProcessId());
			_tcscat(sz_log_file_name, sz_log_time);
		}
	
		sz_file_name_ = sz_log_file_name;
	}
	else
	{
		wsprintf(sz_log_file_name, sz_file_name_);
	}


	dw_file_handle = get_file_io_mgr()->create(sz_file_name_, GENERIC_WRITE, 
		FILE_SHARE_READ, NULL, CREATE_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, NULL);

	if( FILE_HANDLE_INVALID != dw_file_handle )
	{
		BYTE by_io[2] = {0xFF, 0xFE};
		DWORD dw_write = 0;
		get_file_io_mgr()->write(dw_file_handle, by_io, sizeof(by_io), &dw_write, NULL);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

VOID log_file::close_file()
{
	if( dw_file_handle != FILE_HANDLE_INVALID )
	{
		get_file_io_mgr()->close( dw_file_handle );
		dw_file_handle = FILE_HANDLE_INVALID;
	}
}

//-----------------------------------------------------------------------------
//！ 写入log
//-----------------------------------------------------------------------------
BOOL log_file::write_log(LPCTSTR sz_format_, ...)
{
	if( FILE_HANDLE_INVALID == dw_file_handle )
		return FALSE;

	TCHAR sz_buffer[MAX_BUFFER_SIZE];

	ZeroMemory(sz_buffer, sizeof(sz_buffer));
	va_list argptr = NULL;
	va_start(argptr, sz_format_);
	_vstprintf_s(sz_buffer, sizeof(sz_buffer)/sizeof(TCHAR), sz_format_, argptr);
	va_end(argptr);

	get_file_io_mgr()->seek( dw_file_handle, 0, FILE_SEEK_END );
	return get_file_io_mgr()->write(dw_file_handle, sz_buffer, lstrlen(sz_buffer)*2);
}


exception_log_file::exception_log_file()
{
	dw_file_handle = FILE_HANDLE_INVALID;
}

exception_log_file::~exception_log_file()
{
	close_file();
}


//-----------------------------------------------------------------------------
//! 生成Log文件
//-----------------------------------------------------------------------------
BOOL exception_log_file::create_log()
{
	if( dw_file_handle != FILE_HANDLE_INVALID )
		get_file_io_mgr()->close( dw_file_handle );

	TCHAR sz_log_time[MAX_PATH], sz_temp[MAX_PATH];
	GetModuleFileName(NULL, sz_temp, MAX_PATH);

	TCHAR *sz_result = _tcsrchr(sz_temp, _T('\\'));
	sz_result = sz_result ?	sz_result+1 :	sz_result = (TCHAR *)sz_temp;
	_stprintf(sz_log_file_name, _T("log\\%s"), sz_result);
	sz_result = _tcsrchr(sz_log_file_name, _T('.'));
	if( sz_result )
		*sz_result = '\0';	
	
	FILETIME st_current_time;
	GetSystemTimeAsFileTime(&st_current_time);
	sz_log_time[0] = _T('\0');
	WORD w_date, w_time;
	if (FileTimeToLocalFileTime(&st_current_time, &st_current_time) &&
			FileTimeToDosDateTime(&st_current_time, &w_date, &w_time))
	{
		wsprintf(sz_log_time, _T("[%d-%d-%d %02d-%02d-%02d %05d]dump.log"),
				(w_date / 32) & 15, w_date & 31, (w_date / 512) + 1980,
				(w_time >> 11), (w_time >> 5) & 0x3F, (w_time & 0x1F) * 2, 
				GetCurrentProcessId());
		_tcscat(sz_log_file_name, sz_log_time);
	}
	
	dw_file_handle = get_file_io_mgr()->create(sz_log_file_name, GENERIC_WRITE, 
		FILE_SHARE_READ, NULL, CREATE_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL, NULL);

	return ( FILE_HANDLE_INVALID != dw_file_handle );
}

VOID exception_log_file::close_file()
{
	if( dw_file_handle != FILE_HANDLE_INVALID )
	{
		get_file_io_mgr()->close( dw_file_handle );
		dw_file_handle = FILE_HANDLE_INVALID;
	}
}

BOOL exception_log_file::write_log(LPCSTR sz_format_, ...)
{
	if( FILE_HANDLE_INVALID == dw_file_handle )
		return FALSE;

	CHAR sz_buffer[MAX_BUFFER_SIZE];
	ZeroMemory(sz_buffer, sizeof(sz_buffer));
	va_list argptr = NULL;
	va_start(argptr, sz_format_);
	vsprintf_s(sz_buffer, MAX_BUFFER_SIZE, sz_format_, argptr);
	va_end(argptr);

	get_file_io_mgr()->seek( dw_file_handle, 0, FILE_SEEK_END );
	return get_file_io_mgr()->write(dw_file_handle, sz_buffer, strlen(sz_buffer));
}
} // namespace filesystem {



