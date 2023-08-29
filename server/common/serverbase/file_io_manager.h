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
*	@file		file_io_manager.h
*	@author		lc
*	@date		2011/02/22	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef FILE_IO_MANAGER
#define FILE_IO_MANAGER

namespace serverbase{


#ifndef FILE_HANDLE_INVALID
#define FILE_HANDLE_INVALID		((DWORD)INVALID_HANDLE_VALUE)
#endif

#ifndef FILEMAP_HANDLE_INVALID
#define FILEMAP_HANDLE_INVALID	((DWORD)INVALID_HANDLE_VALUE)
#endif

class SERVERBASE_API file_io_manager
{
public:

	DWORD create(LPCTSTR sz_file_name_, DWORD dw_desired_access_, DWORD dw_share_mode_, 
					VOID* p_security_attributes_, DWORD dw_creation_disposition_, 
					DWORD dw_flags_and_attributes_, DWORD dw_template_file_);

	DWORD create_mapping(DWORD dw_file_handle_, VOID* p_attrib_, DWORD dw_protect_,
						   DWORD dw_max_size_, LPCTSTR sz_name_);
	DWORD close_mapping_handle(DWORD dw_file_mapping_handle_);

	VOID* map_file(DWORD dw_file_mapping_handle_, DWORD dw_desired_access_, 
					  DWORD dw_file_offset_, DWORD dw_number_of_bytes_to_map_);
	BOOL  unmap_file(LPCVOID p_base_address_);
	
	BOOL  read(DWORD dw_file_handle_, LPVOID p_buffer_, DWORD dw_number_of_bytes_to_read_,
				  DWORD* p_number_of_bytes_read_, VOID* p_overlapped_);
	DWORD  read(DWORD dw_file_handle_, LPVOID p_buffer_, DWORD dw_number_of_bytes_to_read_);

	BOOL  write(DWORD dw_file_handle_, LPCVOID p_buffer_, DWORD dw_number_of_bytes_to_write_,
				   DWORD* p_number_of_bytes_written_, VOID* p_overlapped_);
	BOOL  write(DWORD dw_file_handle_, LPCVOID p_buffer_, DWORD dw_number_of_bytes_to_write_);
	BOOL  close(DWORD dw_file_handle_);

	DWORD seek(DWORD dw_file_handle_, DWORD dw_distance_to_move_, DWORD dw_move_method_);
	DWORD seek(DWORD dw_file_handle_, DWORD dw_offset_from_start_);
	BOOL seek_extend(DWORD dw_file_handle_, INT64 n64_distance_to_move_, DWORD dw_move_method_);

	DWORD get_size(LPCTSTR sz_file_name_);	
	DWORD get_size(DWORD dw_file_handle_);
	BOOL  get_size_extend(DWORD dw_file_handle_, INT64* p_size_);
	DWORD set_end_of_file(DWORD dw_file_handle_);

	BOOL  is_file_exist(LPCTSTR sz_file_name_);
	BOOL  is_dir(LPCTSTR sz_file_name_);
	DWORD  load_to_memory(VOID* p_memory_, LPCTSTR sz_file_name_);

	DWORD find_first_file(LPCTSTR sz_file_name_, VOID* p_find_data_);
	BOOL  find_next_file(DWORD dw_file_handle_, VOID* p_find_data_);
	BOOL  find_close(DWORD dw_file_handle_);
	
	DWORD get_file_num_indir(LPCTSTR sz_file_name_, DWORD& dw_total_bytes_);
	VOID  get_file_num_indir(LPCTSTR sz_file_name_, DWORD& dw_file_num_, DWORD& dw_bytes_);

	INT64 get_drive_free_space(LPCTSTR sz_driver_name_);

	BOOL get_ini_path( LPTSTR sz_file_name_, LPTSTR sz_file_path_ );

	__forceinline BOOL is_file_handle_invalid(DWORD dw_handle_)
	{ return (dw_handle_ == FILE_HANDLE_INVALID); }

};



} // namespace serverbase{
#endif
