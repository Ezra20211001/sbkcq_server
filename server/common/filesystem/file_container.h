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
*	@file		file_container.h
*	@author		lc
*	@date		2011/02/15	initial
*	@version	0.0.1.0
*	@brief
*/

#ifndef FILE_CONTAINER
#define FILE_CONTAINER

namespace filesystem {

	class FILE_API file_container
	{
	public:

		__forceinline  BOOL	add_element(tstring& string_, tstring& str_name_);

		__forceinline BOOL	add_element(LPCTSTR p_string_, LPCTSTR sz_name_);
		__forceinline BOOL	add_element(DWORD dw_data_, LPCTSTR sz_name_);
		__forceinline BOOL	add_element(FLOAT f_data_, LPCTSTR sz_name_);


		__forceinline LPCTSTR get_string(LPCTSTR sz_name_);
		__forceinline DWORD	get_dword(LPCTSTR sz_name_);
		__forceinline DOUBLE get_float(LPCTSTR sz_name_);
		__forceinline INT32	get_int(LPCTSTR sz_name_);

		__forceinline LPCTSTR get_string(LPCTSTR sz_name_, LPCTSTR sz_section_);
		__forceinline DWORD	get_dword(LPCTSTR sz_name_, LPCTSTR sz_section_);
		__forceinline DOUBLE get_float(LPCTSTR sz_name_, LPCTSTR sz_section_);
		__forceinline INT32	get_int(LPCTSTR sz_name_, LPCTSTR sz_section_);

		__forceinline LPCTSTR get_string(LPCTSTR sz_name_, LPCTSTR sz_section_, LPCTSTR sz_default_);
		__forceinline DWORD	get_dword(LPCTSTR sz_name_, LPCTSTR sz_section_, DWORD dw_default_);
		__forceinline DOUBLE get_float(LPCTSTR sz_name_, LPCTSTR sz_section_, FLOAT f_default_);
		__forceinline INT32	get_int(LPCTSTR sz_name_, LPCTSTR sz_section_, INT32 n_default_);

		__forceinline LPCTSTR get_string(LPCTSTR sz_name_, LPCTSTR sz_postfix_, LPCTSTR sz_section_, LPCTSTR sz_default_);
		__forceinline DWORD	get_dword(LPCTSTR sz_name_, LPCTSTR sz_postfix_, LPCTSTR sz_section_, DWORD dw_default_);
		__forceinline DOUBLE get_float(LPCTSTR sz_name_, LPCTSTR sz_postfix_, LPCTSTR sz_section_, FLOAT f_default_);
		__forceinline INT32	get_int(LPCTSTR sz_name_, LPCTSTR sz_postfix_, LPCTSTR sz_section_, INT32 n_default_);


		BOOL	set_element(LPCTSTR sz_value_, LPCTSTR sz_name_);
		BOOL	set_element(DWORD dw_value_, LPCTSTR sz_name_);
		BOOL	set_element(FLOAT f_value_, LPCTSTR sz_name_);


		BOOL	erase_element(LPCTSTR sz_name_);
		BOOL	erase_element(LPCTSTR sz_name_, LPCTSTR sz_section_);
		VOID	clear() { map_data.clear(); map_name.clear(); }


		DWORD	get_element_num() { return map_data.size(); }
		std::list<tstring>&	get_element_name();

		BOOL load(file_system* p_vfs, LPCTSTR sz_file_name_, LPCSTR sz_key_name_ = "name", std::list<tstring>* p_section_list_ = NULL);
		BOOL save(LPCTSTR sz_file_name_);


		VOID set_save(BOOL b_save_) { b_save = b_save_; }

		int	getXMLRow() { return m_xmlRow; }

		file_container()
		{
			b_save = FALSE;
			m_xmlRow = 0;
		}
		~file_container()
		{

		}

	private:

		std::map<DWORD, tstring>	map_data;

		BOOL						b_save;
		std::map<DWORD, tstring>	map_name;
		std::list<tstring>			list_name;
		int							m_xmlRow;
	};


	BOOL file_container::add_element(tstring& string_, tstring& str_name_)
	{
		DWORD dw_id = get_tool()->crc32(str_name_.c_str());
		if (map_data.insert(std::pair<DWORD, tstring>(dw_id, string_)).second == NULL)
			ERROR_CLUE_ON(_T("Couldn't add <%s> container, element repeat"), str_name_.c_str());

		if (b_save)
			map_name.insert(std::pair<DWORD, tstring>(dw_id, str_name_));
		return TRUE;
	}

	BOOL file_container::add_element(LPCTSTR p_string_, LPCTSTR sz_name_)
	{
		DWORD dw_id = get_tool()->crc32(sz_name_);
		tstring str = p_string_;

		if (NULL == map_data.insert(std::pair<DWORD, tstring>(dw_id, str)).second)
			ERROR_CLUE_ON(_T("Couldn't add <%s> container, element repeat"), sz_name_);

		if (b_save)
		{
			tstring strName = sz_name_;
			map_name.insert(std::pair<DWORD, tstring>(dw_id, strName));
		}

		return TRUE;
	}


	BOOL file_container::add_element(DWORD dw_data_, LPCTSTR sz_name_)
	{
		TCHAR sz_temp[LONG_STRING];
		_itot(dw_data_, sz_temp, 10);
		return this->add_element(sz_temp, sz_name_);
	}

	BOOL file_container::add_element(FLOAT f_data_, LPCTSTR sz_name_)
	{
		CHAR c_temp[LONG_STRING];
		_gcvt(f_data_, 6, c_temp);
		return this->add_element(get_tool()->unicode8_to_unicode(c_temp), sz_name_);
	}


	LPCTSTR file_container::get_string(LPCTSTR sz_name_)
	{
		std::map<DWORD, tstring>::iterator iter;
		DWORD dw_id = get_tool()->crc32(sz_name_);

		iter = map_data.find(dw_id);
		if (iter == map_data.end())
		{
			ERROR_CLUE_ON(_T("Couldn't find <%s> in container"), sz_name_);
			return NULL;
		}

		LPCTSTR sz_return = iter->second.c_str();
		return sz_return;
	}


	DWORD file_container::get_dword(LPCTSTR sz_name_)
	{
		LPCTSTR sz_value = this->get_string(sz_name_);
		return _tcstol(sz_value, NULL, 10);
	}

	DOUBLE file_container::get_float(LPCTSTR sz_name_)
	{
		LPCTSTR sz_value = this->get_string(sz_name_);
		return (DOUBLE)_tstof(sz_value);
	}

	INT32 file_container::get_int(LPCTSTR sz_name_)
	{
		LPCTSTR sz_value = this->get_string(sz_name_);
		return (INT32)_tcstol(sz_value, NULL, 10);
	}

	LPCTSTR file_container::get_string(LPCTSTR sz_name_, LPCTSTR sz_section_)
	{
		tstring string = sz_name_;
		string.append(_T(" "));
		string.append(sz_section_);
		return get_string(string.c_str());
	}

	DWORD file_container::get_dword(LPCTSTR sz_name_, LPCTSTR sz_section_)
	{
		tstring string = sz_name_;
		string.append(_T(" "));
		string.append(sz_section_);
		return get_dword(string.c_str());
	}

	DOUBLE file_container::get_float(LPCTSTR sz_name_, LPCTSTR sz_section_)
	{
		tstring string = sz_name_;
		string.append(_T(" "));
		string.append(sz_section_);
		return get_float(string.c_str());
	}

	INT32 file_container::get_int(LPCTSTR sz_name_, LPCTSTR sz_section_)
	{
		tstring string = sz_name_;
		string.append(_T(" "));
		string.append(sz_section_);
		return get_int(string.c_str());
	}

	LPCTSTR file_container::get_string(LPCTSTR sz_name_, LPCTSTR sz_section_, LPCTSTR sz_default_)
	{
		std::map<DWORD, tstring>::iterator iter;
		TCHAR sz_Temp[LONG_STRING];

		_tcscpy(sz_Temp, sz_name_);
		if (VALID_POINT(sz_section_))
		{
			_tcscat(sz_Temp, _T(" "));
			_tcscat(sz_Temp, sz_section_);
		}

		DWORD dw_id = get_tool()->crc32(sz_Temp);
		iter = map_data.find(dw_id);
		if (iter == map_data.end())
			return sz_default_;

		return iter->second.c_str();
	}

	DWORD file_container::get_dword(LPCTSTR sz_name_, LPCTSTR sz_section_, DWORD dw_default_)
	{
		LPCTSTR sz_return = this->get_string(sz_name_, sz_section_, NULL);
		if (NULL == sz_return)
			return dw_default_;

		return _tcstol(sz_return, NULL, 10);
	}

	DOUBLE file_container::get_float(LPCTSTR sz_name_, LPCTSTR sz_section_, FLOAT f_default_)
	{
		LPCTSTR sz_return = this->get_string(sz_name_, sz_section_, NULL);
		if (NULL == sz_return)
			return f_default_;

		return (DOUBLE)_tstof(sz_return);
	}

	INT32 file_container::get_int(LPCTSTR sz_name_, LPCTSTR sz_section_, INT32 n_default_)
	{
		LPCTSTR sz_return = this->get_string(sz_name_, sz_section_, NULL);
		if (NULL == sz_return)
			return n_default_;

		return (INT32)_tcstol(sz_return, NULL, 10);
	}


	LPCTSTR	file_container::get_string(LPCTSTR sz_name_, LPCTSTR sz_postfix_, LPCTSTR sz_section_, LPCTSTR sz_default_)
	{
		std::map<DWORD, tstring>::iterator iter;
		tstring string = sz_name_;
		string += sz_postfix_;
		if (VALID_POINT(sz_section_))
		{
			string.append(_T(" "));
			string.append(sz_section_);
		}

		DWORD dw_id = get_tool()->crc32(string.c_str());
		iter = map_data.find(dw_id);
		if (iter == map_data.end())
			return sz_default_;

		return iter->second.c_str();
	}

	DWORD file_container::get_dword(LPCTSTR sz_name_, LPCTSTR sz_postfix_, LPCTSTR sz_section_, DWORD dw_default_)
	{
		LPCTSTR sz_return = this->get_string(sz_name_, sz_postfix_, sz_section_, NULL);
		if (NULL == sz_return)
			return dw_default_;

		return _tcstol(sz_return, NULL, 10);
	}

	DOUBLE file_container::get_float(LPCTSTR sz_name_, LPCTSTR sz_postfix_, LPCTSTR sz_section_, FLOAT f_default_)
	{
		LPCTSTR sz_return = this->get_string(sz_name_, sz_postfix_, sz_section_, NULL);
		if (NULL == sz_return)
			return f_default_;

		return (DOUBLE)_tstof(sz_return);
	}

	INT32 file_container::get_int(LPCTSTR sz_name_, LPCTSTR sz_postfix_, LPCTSTR sz_section_, INT32 n_default_)
	{
		LPCTSTR sz_return = this->get_string(sz_name_, sz_postfix_, sz_section_, NULL);
		if (NULL == sz_return)
			return n_default_;

		return (INT32)_tcstol(sz_return, NULL, 10);
	}



} // namespace filesystem {
#endif