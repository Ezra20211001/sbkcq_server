/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#pragma once

#include "StdAfx.h"
#include "data_support.h"

namespace odbc {

//----------------------------------------------------------------------------------------------------
// 提取数据库中字符串类型数据
//----------------------------------------------------------------------------------------------------
INT data_support::get_tchar(TCHAR* sz_value_, INT n_length) const
{
	if( null == sz_value_ || null == sz_value || EDT_BLOB == e_type || EDT_UNKNOWN == e_type )
		return 0;

#if defined _UNICODE

	return MultiByteToWideChar(CP_UTF8, 0, sz_value, -1, sz_value_, n_length);

#else

	if( n_length < u_length + 1 ) return 0;
	memcpy(sz_value_, sz_value, u_length+1);
	return u_length+1;

#endif
}


sstring data_support::get_unicode_string() const
{
	if( null == sz_value || EDT_BLOB == e_type || EDT_UNKNOWN == e_type )
		return sstring(_T(""));

#if defined _UNICODE

	INT n_desire_length = multi_byte_to_wide_char(CP_UTF8, 0, sz_value, -1, null, 0);
	if( n_desire_length == 0 ) return sstring(_T(""));

	TCHAR* sz_result_value = new TCHAR[n_desire_length];
	if( 0 == multi_byte_to_wide_char(CP_UTF8, 0, sz_value, -1, sz_result_value, n_desire_length) )
	{
		delete []sz_result_value;
		return sstring(_T(""));
	}

	sstring str(sz_result_value);
	delete[] sz_result_value;
	return str;

#else

	return sstring(sz_value);

#endif

}

//--------------------------------------------------------------------------------------------------------
// 提取数据库中blob类型数据
//--------------------------------------------------------------------------------------------------------
BOOL data_support::get_blob(void* buffer_, u_long n_length) const
{
	if( n_length < u_length ) return FALSE;

	memcpy(buffer_, sz_value, u_length);
	return TRUE;
}

} // namespace odbc