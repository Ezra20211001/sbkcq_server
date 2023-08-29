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
 *	@file		GMLogHelper
 *	@author		mwh
 *	@date		2011/04/14	initial
 *	@version	0.0.1.0
 *	@brief		注意不要多线程使用
*/

#ifndef __GMLOG_HELPER_H__
#define __GMLOG_HELPER_H__

enum{LOGBUFFERMAX=1024};
enum{LOADROLELOGBUFFER = 1024 * 1024 * 16};

extern TCHAR _G_LogFormat_Buffer[LOGBUFFERMAX];
const TCHAR* LogHelper(const TCHAR* pFmt,...);

//! common buffer
char* GetCommonBuffer();

#endif //__GMLOG_HELPER_H__