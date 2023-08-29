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
*	@file		error_alarm.h
*	@author		lc
*	@date		2011/02/22	initial
*	@version	0.0.1.0
*	@brief		
*/

#include "stdafx.h"
#include "error_alarm.h"

namespace serverbase {

INT error_alarm::error_export(LPCTSTR sz_format, ...)
{
	TCHAR sz_buffer[1024];
	LPVOID p_message_buffer;
	DWORD dw_error;
	INT n_result;

	p_message_buffer = NULL;

	dw_error = ::GetLastError();

	va_list argptr;
	va_start(argptr, sz_format);
	_vstprintf_s(sz_buffer, sizeof(sz_buffer)/sizeof(TCHAR), sz_format, argptr);
	va_end(argptr);

	if( dw_error != 0 )	
	{
		FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS, NULL, dw_error,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
			(LPTSTR) &p_message_buffer, 0, NULL);
		wsprintf(sz_buffer, _T("%s\r\n系统错误码:%lu 错误信息:%s"), sz_buffer, dw_error, (CONST PTCHAR)p_message_buffer);
		LocalFree( p_message_buffer );
	}

	lstrcat(sz_buffer, _T("\r\n是否继续?"));
	n_result = ::MessageBox(NULL, sz_buffer, _T(" 错误警告:"), MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON1);
	if( IDNO == n_result )	
	{
		CONST UINT EXCEPTION_CODE	= 0xe06d7363;
		RaiseException(EXCEPTION_CODE, 0, 0, NULL);
	}

	return n_result;
}




}	// serverbase
