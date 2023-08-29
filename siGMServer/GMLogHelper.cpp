/*******************************************************************************

	Copyright 2010 by tiankong Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	tiankong Interactive  Co., Ltd.

*******************************************************************************/
#include "StdAfx.h"
#include "GMLogHelper.h"

TCHAR _G_LogFormat_Buffer[LOGBUFFERMAX];
//! format function
const TCHAR* LogHelper(const TCHAR* pFmt,...)
{
	ZeroMemory(_G_LogFormat_Buffer,sizeof(_G_LogFormat_Buffer));

	try
	{
		va_list argp;
		va_start(argp,pFmt);
		_vstprintf_s(_G_LogFormat_Buffer, _countof(_G_LogFormat_Buffer), pFmt, argp);
		va_end(argp);
	}
	catch(...)
	{
		_G_LogFormat_Buffer[0] = 0;
	}

	return _G_LogFormat_Buffer;
}
//! 
char* GetCommonBuffer()
{
	const static std::auto_ptr<char> _GCBUFHOLDER(new char[LOADROLELOGBUFFER]);
	return _GCBUFHOLDER.get();
}
