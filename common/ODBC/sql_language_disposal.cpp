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
#include "sql_language_disposal.h"

namespace odbc
{

sql_language_disposal::sql_language_disposal(INT n_default_size_)
	: n_buffer_length(n_default_size_), n_default_size(n_default_size_), n_pos(0)
{
	p_buffer = new char[n_default_size];
	if( null == p_buffer ) { abort(); }
	p_buffer[0] = 0;
}


sql_language_disposal::~sql_language_disposal()
{
	SAFE_DELETE_ARRAY(p_buffer);
}

//----------------------------------------------------------------------------
// 将游标移动到字符串的指定位置
//----------------------------------------------------------------------------
BOOL sql_language_disposal::seek(INT n_pos_)
{
	if( n_pos_ <= n_buffer_length - 1 )
	{
		n_pos = n_pos_;
		end();
		return TRUE;
	}
	return FALSE;
}

//-----------------------------------------------------------------------------
// 空间不足时扩充buffer
//-----------------------------------------------------------------------------
void sql_language_disposal::increase(INT n_size_)
{
	if( n_size_ <= 0 ) n_size_ = n_default_size;

	if( n_pos + n_size_ <= n_buffer_length - 1 )
		return;

	INT nTmpLen = n_buffer_length  + n_size_;
	char* pTmp = new char[nTmpLen];

	if(p_buffer)
	{
		memcpy(pTmp, p_buffer, n_buffer_length);
		SAFE_DELETE_ARRAY(p_buffer);
	}

	p_buffer = pTmp;
	n_buffer_length = nTmpLen;
}

sql_language_disposal& sql_language_disposal::operator << (const INT p)
{
	char szBuf[64] = {0};
	_itoa_s(p, szBuf, 10);

	INT nLen = strlen(szBuf);
	increase(nLen);
	memcpy(p_buffer + n_pos, szBuf, nLen);
	n_pos += nLen;
	end();
	return *this;
}

sql_language_disposal& sql_language_disposal::operator << (const DWORD p)
{
	char szBuf[64] = {0};
	_ultoa_s(p, szBuf, 10);

	INT nLen = strlen(szBuf);
	increase(nLen);
	memcpy(p_buffer + n_pos, szBuf, nLen);
	n_pos += nLen;
	end();
	return *this;

}

sql_language_disposal& sql_language_disposal::operator << (const INT64 p)
{
	char szBuf[96] = {0};
	_i64toa_s(p, szBuf, 96, 10);

	INT nLen = strlen(szBuf);
	increase(nLen);
	memcpy(p_buffer + n_pos, szBuf, nLen);
	n_pos += nLen;
	end();
	return *this;

}

sql_language_disposal& sql_language_disposal::operator << (const DOUBLE p)
{
	char szBuf[_CVTBUFSIZE] = {0};
	_gcvt_s(szBuf, p, 5);

	INT nLen = strlen(szBuf);
	increase(nLen);
	memcpy(p_buffer + n_pos, szBuf, nLen);
	n_pos += nLen;
	end();
	return *this;
}

//----------------------------------------------------------------------------
// 写入非Unicode语句
//----------------------------------------------------------------------------
sql_language_disposal& sql_language_disposal::write_string(const char* p, tag_mysql_connect* con/* = null */)
{
	if( null == p || '\0' == p[0] ) return (*this);

	if( null != con )
	{
		INT nStrlen = strlen(p);
		INT nGrowSize = nStrlen*2 + 1;
		increase(nGrowSize);
		char* pRet = p_buffer + n_pos;
		memset(pRet, 0, nGrowSize);
		INT nLen = mysql_real_escape_string(con->_mysql, pRet, p, nStrlen);	
		n_pos += nLen;
		end();
	}
	else
	{
		INT nLen = strlen(p);
		increase(nLen);
		char* pRet = p_buffer + n_pos;
		strcat(pRet, p);
		n_pos += nLen;
		end();
	}

	return *this;
}

//------------------------------------------------------------------------------
// 写入Unicode语句
//------------------------------------------------------------------------------
sql_language_disposal& sql_language_disposal::write_string(const WCHAR* p, tag_mysql_connect* con/* =null */)
{
	if( null == p || 0 == p[0] ) return (*this);

	INT nDesiredLen = wide_char_to_multi_byte(CP_UTF8, 0, p, -1, null, 0, null, null);
	if( 0 == nDesiredLen ) return (*this);

	char* szTemp = new char[nDesiredLen];
	if( 0 == wide_char_to_multi_byte(CP_UTF8, 0, p, -1, szTemp, nDesiredLen, null, null) )
	{
		SAFE_DELETE_ARRAY(szTemp);
		return (*this);
	}

	write_string(szTemp, con);

	SAFE_DELETE_ARRAY(szTemp);

	return (*this);
}


//------------------------------------------------------------------------------
// 写入blob数据
//------------------------------------------------------------------------------
sql_language_disposal& sql_language_disposal::write_blob(const void* p, INT n_size_, tag_mysql_connect* con/* =null */)
{
	if( null == p || n_size_ <= 0 )	return (*this);

	if( null == con ) return (*this);

	INT nGrowSize = n_size_*2 + 1;
	increase(nGrowSize);
	char* pRet = p_buffer + n_pos;
	memset(pRet, 0, nGrowSize);
	INT nLen = mysql_real_escape_string(con->_mysql, pRet, (char*)p, n_size_);
	n_pos += nLen;
	end();

	return *this;
}

//------------------------------------------------------------------------------
// 写入blob数据
//------------------------------------------------------------------------------
sql_language_disposal& sql_language_disposal::write_blob(void* p, INT n_size_)
{
	increase(n_size_);
	memcpy(p_buffer + n_pos, p, n_size_);
	n_pos += n_size_;
	end();

	return *this;
}

} // namespace odbc

