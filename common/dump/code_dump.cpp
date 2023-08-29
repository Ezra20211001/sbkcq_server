//-----------------------------------------------------------------------------
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
#include "code_dump.h"


#include "..\serverbase\file_io_manager.h"
#include "zip_file.h"

#include <psapi.h>		


namespace serverdump {
//TCHAR	throw_exception::sz_dump_file_name[1024] = _T("log\\serverdump");
TCHAR	throw_exception::sz_ftp_ip[256] = {0};
TCHAR	throw_exception::sz_ftp_user[256] = {0};
TCHAR	throw_exception::sz_ftp_password[256] = {0};


DUMP_API VOID si_translation(UINT u_code_, EXCEPTION_POINTERS* p_exp_)
{
	throw throw_exception(u_code_, p_exp_);
}

DUMP_API LONG WINAPI si_exception_filter(EXCEPTION_POINTERS* p_exp_)
{
	throw_exception(0, p_exp_);
	return EXCEPTION_CONTINUE_SEARCH;
}

#ifndef _M_IX86
#error "The following code only works for x86!"
#endif

DUMP_API VOID DisableSetUnhandledExceptionFilter()
{
	void *addr = (void*)GetProcAddress(LoadLibrary(_T("kernel32.dll")),
		"SetUnhandledExceptionFilter");
	if (addr) 
	{
		unsigned char code[16];
		int size = 0;
		//xor eax,eax;
		code[size++] = 0x33;
		code[size++] = 0xC0;
		//ret 4
		code[size++] = 0xC2;
		code[size++] = 0x04;
		code[size++] = 0x00;

		DWORD dwOldFlag, dwTempFlag;
		VirtualProtect(addr, size, PAGE_READWRITE, &dwOldFlag);
		WriteProcessMemory(GetCurrentProcess(), addr, code, size, NULL);
		VirtualProtect(addr, size, dwOldFlag, &dwTempFlag);
	}
}

throw_exception::throw_exception(UINT u_code_, EXCEPTION_POINTERS* p_exp_)
{
	TCHAR sz_log_time[MAX_PATH];
	TCHAR sz_dump_file_name[256] = _T("log\\serverdump");

	FILETIME st_current_time;
	GetSystemTimeAsFileTime(&st_current_time);
	sz_log_time[0] = _T('\0');
	WORD w_date, w_time;
	if (FileTimeToLocalFileTime(&st_current_time, &st_current_time) &&
		FileTimeToDosDateTime(&st_current_time, &w_date, &w_time))
	{
		wsprintf(sz_log_time, _T("[%d-%d-%d %02d-%02d-%02d %05d].dmp"),
			(w_date / 32) & 15, w_date & 31, (w_date / 512) + 1980,
			(w_time >> 11), (w_time >> 5) & 0x3F, (w_time & 0x1F) * 2, 
			GetCurrentProcessId());
		_tcscat(sz_dump_file_name, sz_log_time);
	}


	HANDLE h_file = ::CreateFile(sz_dump_file_name, GENERIC_WRITE, 
		FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	MINIDUMP_EXCEPTION_INFORMATION dump_exception_inof;
	dump_exception_inof.ThreadId = GetCurrentThreadId();
	dump_exception_inof.ExceptionPointers = p_exp_;
	dump_exception_inof.ClientPointers = FALSE;
	MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), h_file,  MiniDumpWithFullMemory , 
		&dump_exception_inof, NULL, NULL);

	//_tcsncpy(sz_file_name, sz_dump_file_name, 1024);

	//DWORD dw_size = ::GetFileSize(h_file, NULL);
	//::CloseHandle(h_file);
	//if( dw_size == 0 || dw_size == INVALID_VALUE )
	//	return;

	//LPTSTR p_result = _tcsrchr(sz_file_name, _T('.'));
	//if( p_result )
	//	_stprintf(p_result, _T(".zip"));

	//HZIP h_zip = NULL;
	//h_zip = CreateZip((LPVOID)(LPCTSTR)sz_file_name, 0, ZIP_FILENAME);
	//if( !h_zip )
	//	return;

	//ZRESULT zr = ZipAdd(h_zip, _T("dump.dmp"), (LPVOID)sz_dump_file_name, 0, ZIP_FILENAME);
	//if( zr != ZR_OK )
	//	return;

	//CloseZip(h_zip);

	//::DeleteFile( sz_dump_file_name );

	return;
}


} // namespace serverdump {











