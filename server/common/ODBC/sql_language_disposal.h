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
*	@file		sql_language_disposal.h
*	@author		lc
*	@date		2011/01/20	initial
*	@version	0.0.1.0
*	@brief		
*/

// sql_language_disposal 存储sql语句

#ifndef SQL_LANGUAGE_DISPOSAL
#define SQL_LANGUAGE_DISPOSAL

#include "StdAfx.h"
#include "db_interface.h"

namespace odbc {

struct tag_mysql_connect;

class odbc_api sql_language_disposal
{
public:
	sql_language_disposal(INT n_default_size_=1024);
	virtual ~sql_language_disposal();

public:
	//--------------------------------------------------------------------------------------------------
	// 填充sql语句
	//--------------------------------------------------------------------------------------------------
	sql_language_disposal& write_string(const char* p, tag_mysql_connect* con=null);
	sql_language_disposal& write_string(const WCHAR* p, tag_mysql_connect* con=null);

	//--------------------------------------------------------------------------------------------------
	// 填充sql语句中二进制数据
	//--------------------------------------------------------------------------------------------------
	sql_language_disposal& write_blob(const void* p, INT n_size_, tag_mysql_connect* con);
	sql_language_disposal& write_blob(void* p, INT n_size_);	

	
	inline sql_language_disposal& operator << (const INT p);
	inline sql_language_disposal& operator << (const DWORD p);
	inline sql_language_disposal& operator << (const INT64 p);
	inline sql_language_disposal& operator << (const DOUBLE p);
	inline sql_language_disposal& operator << (const FLOAT p)		{ return operator << (static_cast<DOUBLE>(p)); }
	inline sql_language_disposal& operator << (const WORD p)		{ return operator << (static_cast<DWORD>(p));}
	inline sql_language_disposal& operator << (const BYTE p)		{ return operator << (static_cast<DWORD>(p));}

public:
	
	//--------------------------------------------------------------------------------------------------
	// 复制数据表
	//--------------------------------------------------------------------------------------------------
	inline sql_language_disposal& copy_table(const char* sz_table1_, const char* sz_select_item_, const char* sz_table2_)
	{

		clear();
		return (*this).write_string("insert into ").write_string(sz_table1_).write_string(" select ").write_string(sz_select_item_).write_string(" from ").write_string(sz_table2_);
	}

	inline sql_language_disposal& select_item(const char* sz_table_, const char* sz_select_item_)
	{

		clear();
		return (*this).write_string("select ").write_string(sz_select_item_).write_string(" from ").write_string(sz_table_);
	}

	inline sql_language_disposal& update_item(const char* sz_table_)
	{
		clear();
		return (*this).write_string("update ").write_string(sz_table_).write_string(" set ");
	}

	inline sql_language_disposal& insert_item(const char* sz_table_)
	{
		clear();
		return (*this).write_string("insert into ").write_string(sz_table_).write_string(" set ");
	}

	inline sql_language_disposal& insert_item(const char* sz_table_, const char* sz_affixation_)
	{
		clear();
		return (*this).write_string("insert into ").write_string(sz_table_).write_string(sz_affixation_).write_string(" set ");
	}

	inline sql_language_disposal& replace_item(const char* sz_table_)
	{
		clear();
		return (*this).write_string("replace into ").write_string(sz_table_).write_string(" set ");
	}

	inline sql_language_disposal& delete_item(const char* sz_table_)
	{
		clear();
		return (*this).write_string("delete from ").write_string(sz_table_);
	}

	inline sql_language_disposal& where_item()
	{
		return (*this).write_string(" where ");
	}

	inline sql_language_disposal& limit(INT n_num_, INT n_begin_ = 0)
	{
		(*this).write_string(" limit ");
		if( n_begin_ > 0 )
		{
			(*this) << n_begin_;
			(*this).write_string(",");
		}
		return (*this) << n_num_;
	}

public:
	inline void			increase(INT n_size_);
	inline BOOL			seek(INT n_pos_);
	inline void			end()					{ p_buffer[n_pos] = '\0'; }
	inline const char*	get_buffer() const			{ return p_buffer; }
	inline DWORD		get_buffer_length() const		{ return n_pos; }
	inline BOOL			is_empty() const			{ return n_pos == 0; }
	inline void			clear()					{ n_pos = 0; end(); }

private:
	sql_language_disposal(const sql_language_disposal&);
	sql_language_disposal& operator = (sql_language_disposal&);

private:
	char*		p_buffer;			// sql语句
	INT			n_buffer_length;	// sql语句长度
	INT			n_pos;				// sql语句当前写入的位置
	INT			n_default_size;		// sql语句默认长度
};

} // namespace odbc
#endif
