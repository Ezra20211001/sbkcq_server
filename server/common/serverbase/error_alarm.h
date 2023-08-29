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

#ifndef ERROR_ALARM
#define ERROR_ALARM

namespace serverbase {


#define ERROR_CLUE_ON				g_palarm->error_export


#undef ASSERT
#ifdef _DEBUG
	#define ASSERT(f)	if( !(f) ) g_palarm->error_export( \
		_T("Ê§°Ü:%s\r\nÎÄ¼þ:%s\r\nÐÐºÅ:%d"), _T(#f), _T(__FILE__), __LINE__)
#else
	#define ASSERT(f)	((void)0)
#endif


class SERVERBASE_API error_alarm
{
public:
	
	INT  error_export(LPCTSTR sz_format, ...);
};



} // serverbase
#endif



