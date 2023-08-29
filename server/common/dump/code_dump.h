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
*	@file		code_dump.h
*	@author		lc
*	@date		2011/02/11	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef CODE_DUMP
#define CODE_DUMP

namespace serverdump {
typedef unsigned long ULONG3264, *PULONG3264, DWORD3264, *PDWORD3264;

DUMP_API VOID si_translation(UINT u_code_, EXCEPTION_POINTERS* p_exp_);
DUMP_API LONG WINAPI si_exception_filter(EXCEPTION_POINTERS* p_exp_);
DUMP_API VOID DisableSetUnhandledExceptionFilter();

#define THROW_EXCEPTION_START	_set_se_translator( serverdump::si_translation ); try{
#define THROW_EXCEPTION_END	} catch(serverdump::throw_exception){}

// THROW_EXCEPTION_START和THROW_EXCEPTION_END组合使用
#define THROW_EXCEPTION ::SetUnhandledExceptionFilter(serverdump::si_exception_filter); DisableSetUnhandledExceptionFilter();


class DUMP_API throw_exception
{
public:

	throw_exception(UINT u_code_, EXCEPTION_POINTERS* p_exp_);

private:
	
	//static TCHAR	sz_dump_file_name[1024];
	static TCHAR	sz_ftp_ip[256];
	static TCHAR	sz_ftp_user[256];
	static TCHAR	sz_ftp_password[256];


};

}	// namespace serverdump {
#endif

