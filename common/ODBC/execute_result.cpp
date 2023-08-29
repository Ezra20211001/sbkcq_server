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
#include "execute_result.h"
#include "data_support.h"

namespace odbc {


execute_result::execute_result(mysql_res* result_, INT n_rows_, INT n_cols_)
: st_result(result_), n_rows(n_rows_), n_cols(n_cols_)
{
	assert(st_result != null && n_rows >= 0 && n_cols > 0);

	current_row = new data_support[n_cols];
	assert( current_row != null );

	mysql_field* field = mysql_fetch_fields(st_result);
	for(INT n = 0; n < n_cols; n++)
	{
		current_row[n].set_all(field[n].name, transition_type(field[n].type), field[n].max_length);
	}
}

execute_result::~execute_result()
{
	delete[] current_row;
	if( st_result ) mysql_free_result(st_result);
}

//-----------------------------------------------------------------------------------------------------
// 得到结果集的下一行
// 创建execute_result时，要立刻调用next_row，得到结果集的第一行
//-----------------------------------------------------------------------------------------------------
BOOL execute_result::next_row()
{
	mysql_row row = mysql_fetch_row(st_result);
	if( null == row )
		return FALSE;

	u_long* uLen = mysql_fetch_lengths(st_result);
	for(INT n = 0; n < n_cols; n++)
	{
		current_row[n].set_value(row[n]);
		current_row[n].set_length(uLen[n]);
	}

	return TRUE;
}

//-----------------------------------------------------------------------------------------------------
// 将mysql的内部类型转换为自定义类型
//-----------------------------------------------------------------------------------------------------
data_support::E_date_type execute_result::transition_type(enum_field_types mysqlType) const
{
	switch (mysqlType)
	{
	case FIELD_TYPE_TIMESTAMP:
	case FIELD_TYPE_DATE:
	case FIELD_TYPE_TIME:
	case FIELD_TYPE_DATETIME:
	case FIELD_TYPE_YEAR:
	case FIELD_TYPE_STRING:
	case FIELD_TYPE_VAR_STRING:
	case FIELD_TYPE_SET:
	case FIELD_TYPE_NULL:
		return data_support::EDT_STRING;

	case FIELD_TYPE_TINY:
	case FIELD_TYPE_SHORT:
	case FIELD_TYPE_LONG:
	case FIELD_TYPE_INT24:
	case FIELD_TYPE_LONGLONG:
	case FIELD_TYPE_ENUM:
		return data_support::EDT_INTEGER;

	case FIELD_TYPE_DECIMAL:
	case FIELD_TYPE_FLOAT:
	case FIELD_TYPE_DOUBLE:
		return data_support::EDT_FLOAT;
		
	case FIELD_TYPE_BLOB:
		return data_support::EDT_BLOB;

	default:
		return data_support::EDT_UNKNOWN;
	}
}

} // namespace odbc