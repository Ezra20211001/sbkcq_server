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
*	@file		data_support.h
*	@author		lc
*	@date		2011/01/19	initial
*	@version	0.0.1.0
*	@brief		
*/

// data_support �ṩ���ݿ����ݼ��е�ǰ�С��е�����
// ���԰�ָ��������ȡ���ݣ���blob���ݵ�������
// ���Բ�ѯ�����ԣ���ǰ���г��ȣ�����
// ��unicode�ַ��ṩ֧�֣� ��֤�洢�����ݱ��е��ַ���Ϊutf8����

#ifndef DATA_SUPPORT
#define DATA_SUPPORT

#include "StdAfx.h"

namespace odbc {


class odbc_api data_support
{
public:

	// �Զ�����������
	typedef enum						
	{
		EDT_UNKNOWN		= 0,			// δ֪
		EDT_INTEGER		= 1,			// ����
		EDT_STRING		= 2,			// �ַ�����
		EDT_FLOAT		= 3,			// ������
		EDT_BLOB		= 4				// ����������
	} E_date_type;

	data_support();
	data_support(char* sz_value_, char* sz_name_, u_long u_len_, u_long u_max_len_, E_date_type e_type_);
	data_support(data_support& data_support);
	
	~data_support() {}

	inline BOOL is_null() const { return sz_value == null; }

	inline const char* get_name()	const	{ return sz_name; }
	inline E_date_type get_type() const		{ return e_type; }
	inline u_long get_length() const			{ return u_length; }
	inline u_long get_max_length() const		{ return u_max_length; }
	INT get_tchar(TCHAR* sz_value_, INT n_length) const;
	BOOL get_blob(void* buffer_, u_long n_length) const;
	sstring get_unicode_string() const;
	inline const char* get_string() const 		{ return sz_value; }
	inline BOOL get_bool()	const				{ return sz_value ? atol(sz_value) : 0; }
	inline INT get_int() const					{ return sz_value ? static_cast<INT>(atoi(sz_value)) : 0; }
	inline DWORD get_dword() const				{ return sz_value ? static_cast<DWORD>(_atoi64(sz_value)) : 0; }
	inline INT64 get_long() const				{ return sz_value ? static_cast<LONG64>(_atoi64(sz_value)) : 0; }
	inline BYTE get_byte() const				{ return sz_value ? static_cast<BYTE>(_atoi64(sz_value)) : 0; }
	inline SHORT get_short() const				{ return sz_value ? static_cast<SHORT>(_atoi64(sz_value)) : 0; }
	inline FLOAT get_float() const				{ return sz_value ? static_cast<FLOAT>(atof(sz_value)) : 0.0f; }
	inline DOUBLE get_double() const			{ return sz_value ? static_cast<DOUBLE>(atof(sz_value)) : 0.0;}

	inline void set_value(char* sz_value_)	{ sz_value = sz_value_; }
	inline void set_name(char* sz_name_)		{ sz_name = sz_name_; }	
	inline void set_type(E_date_type e_type_)		{ e_type = e_type_; }
	inline void set_length(u_long u_length_)			{ u_length = u_length_; }
	inline void set_max_length(u_long u_max_length_)		{ u_max_length = u_max_length_; }
	inline void set_all(char* sz_name_, E_date_type e_type_, u_long u_max_length)
	{
		set_name(sz_name_); set_type(e_type_); set_max_length(u_max_length);
	}

private:
	
	E_date_type			e_type;					// ���ݿ����������
	u_long				u_length;				// ĳ�и��е�blog���ݳ���
	u_long				u_max_length;			// ���ݿ��ĳ�е���󳤶�
	char*				sz_value;				// ���ݿ��ĳ�е�ֵ
	char*				sz_name;				// ���ݿ��ĳ�е�����
};


//------------------------------------------------------------------------------------------------------
// ���캯��
//------------------------------------------------------------------------------------------------------
inline data_support::data_support() 
: sz_value(null), sz_name(null), e_type(EDT_UNKNOWN), u_length(0), u_max_length(0)
{

}

inline data_support::data_support(data_support& data_support) 
:sz_value(data_support.sz_value), sz_name(data_support.sz_name), e_type(data_support.e_type), u_length(data_support.u_length), u_max_length(data_support.u_max_length)
{

}

inline data_support::data_support(char* sz_value_, char* sz_name_, u_long u_len_, u_long u_max_len_, E_date_type e_type_)
: sz_value(sz_value_), sz_name(sz_name_), e_type(e_type_), u_length(u_len_), u_max_length(u_max_len_)
{

}

} // namespace odbc
#endif

