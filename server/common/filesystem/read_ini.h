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
*	@file		read_ini.h
*	@author		lc
*	@date		2011/02/15	initial
*	@version	0.0.1.0
*	@brief		
*/

//! 提供INI文件读取功能

#ifndef READ_INI
#define READ_INI

namespace filesystem {

class file_system;
class file_container;

class read_ini
{
public:
	BOOL load_file(file_system* p_vfs, LPCTSTR sz_file_name_, const INT n_mode_ = INVALID_VALUE);	
	VOID free_file();	

	PBYTE read_value(DWORD& dw_size_, LPCTSTR sz_key_, LPCTSTR sz_section_);
	
	INT get_row_count() { return map_data_offset.size(); }

	BOOL lay_container(file_container* p_container_);

	read_ini();~read_ini();

private:
	file_system*			p_file_system;

	typedef std::vector<DWORD>	vec_dowrd;
	typedef	std::map<DWORD, vec_dowrd>	map_dword;

	std::map<DWORD, map_dword>		map_data_offset;
	std::map<DWORD, tstring>		map_section_name;
	PBYTE							p_file_data; 
	DWORD							dw_file_data_size; 

};

}	// namespace filesystem
#endif
