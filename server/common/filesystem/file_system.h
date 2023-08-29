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
*	@file		file_system.h
*	@author		lc
*	@date		2011/02/15	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef FILE_SYSTEM
#define FILE_SYSTEM

namespace filesystem{

class FILE_API file_system
{
public:
	
	DWORD	open_file(LPCTSTR sz_file_name_);
	BOOL	close_file(DWORD dw_handle_);
	DWORD	read_file(PVOID p_data_out_, DWORD dw_size, DWORD dw_handle_);
	DWORD	seek_file(DWORD dw_hangle_, INT n_offset_, DWORD dw_origin_);
	DWORD	tell_file(DWORD dw_handle_);

	DWORD	get_size(LPCTSTR sz_file_name_);	
	
	DWORD	load_file(LPVOID p_data_out_, LPCTSTR sz_file_name_);

	file_system();
	~file_system();

};



}
#endif