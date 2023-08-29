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
*	@file		execute_result.h
*	@author		lc
*	@date		2011/01/19	initial
*	@version	0.0.1.0
*	@brief		
*/

//execute_result�� �ṩ�������ݿ��ѯ������ķ��ع���


#ifndef EXECUTE_RESULT
#define EXECUTE_RESULT

#include "StdAfx.h"
#include "data_support.h"

namespace odbc {

class Field;

class odbc_api execute_result
{
public:
	execute_result(mysql_res* result_, INT n_rows_, INT n_cols_);
	~execute_result();

	inline INT get_row_count() const		{ return n_rows; }
	inline INT get_col_count() const		{ return n_cols; }
	inline const data_support* fetch() const		{ return current_row; } 

	BOOL next_row();
	inline data_support& operator [] (INT nIndex) const { assert(nIndex >= 0 && nIndex < n_cols && current_row != null); return current_row[nIndex]; }
	inline data_support& operator [] (char* szFieldName) const;

private:
	data_support::E_date_type transition_type(enum_field_types mysqlType) const;
	
private:
	mysql_res*		st_result;			// mysql���صĽ����
	INT				n_rows;				// mysql���صĽ��������
	INT				n_cols;				// mysql���صĽ��������
	data_support*			current_row;		// mysql���صĵ�ǰ���м�

};

} // namespace odbc
#endif