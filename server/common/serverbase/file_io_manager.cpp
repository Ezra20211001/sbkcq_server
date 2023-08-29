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

#include "stdafx.h"
#include "file_io_manager.h"


namespace serverbase{
//-----------------------------------------------------------------------------
// open or create a file
//-----------------------------------------------------------------------------
	DWORD file_io_manager::create(LPCTSTR sz_file_name_, DWORD dw_desired_access_, DWORD dw_share_mode_, 
		VOID* p_security_attributes_, DWORD dw_creation_disposition_, 
		DWORD dw_flags_and_attributes_, DWORD dw_template_file_)
{
	ASSERT(sz_file_name_);

	return (DWORD)::CreateFile(sz_file_name_, dw_desired_access_, dw_share_mode_,
		(LPSECURITY_ATTRIBUTES)p_security_attributes_, dw_creation_disposition_,
		dw_flags_and_attributes_, (HANDLE)dw_template_file_);
}




//-----------------------------------------------------------------------------
// open or create a file mapping
//-----------------------------------------------------------------------------
	DWORD file_io_manager::create_mapping(DWORD dw_file_handle_, VOID* p_attrib_, DWORD dw_protect_,
		DWORD dw_max_size_, LPCTSTR sz_name_)
{
	return (DWORD)::CreateFileMapping((HANDLE)dw_file_handle_, 
		(LPSECURITY_ATTRIBUTES)p_attrib_, dw_protect_, 0, dw_max_size_, sz_name_);
}


//-----------------------------------------------------------------------------
// close a file mapping handle
//-----------------------------------------------------------------------------
DWORD file_io_manager::close_mapping_handle(DWORD dw_file_mapping_handle_)
{
	ASSERT(dw_file_mapping_handle_ != FILEMAP_HANDLE_INVALID);
	return ::CloseHandle((HANDLE)dw_file_mapping_handle_); 

}




//-----------------------------------------------------------------------------
// map view of file, return the base address
//-----------------------------------------------------------------------------
void* file_io_manager::map_file(DWORD dw_file_mapping_handle_, DWORD dw_desired_access_, 
						  DWORD dw_file_offset_, DWORD dw_number_of_bytes_to_map_)
{
	return ::MapViewOfFile((HANDLE)dw_file_mapping_handle_, dw_desired_access_,
		0, dw_file_offset_, dw_number_of_bytes_to_map_);
}



//-----------------------------------------------------------------------------
// Unmap view of file, require the base address
//-----------------------------------------------------------------------------
BOOL file_io_manager::unmap_file(LPCVOID p_base_address_)
{
	return ::UnmapViewOfFile(p_base_address_);
}




//-----------------------------------------------------------------------------
// do file read
//-----------------------------------------------------------------------------
BOOL file_io_manager::read(DWORD dw_file_handle_, LPVOID p_buffer_, DWORD dw_number_of_bytes_to_read_,
					 DWORD* p_number_of_bytes_read_, VOID* p_overlapped_)
{
	ASSERT(!is_file_handle_invalid(dw_file_handle_));
	ASSERT(p_buffer_);

	return ::ReadFile((HANDLE)dw_file_handle_, p_buffer_, dw_number_of_bytes_to_read_,
		p_number_of_bytes_read_, (LPOVERLAPPED)p_overlapped_);

}




//-----------------------------------------------------------------------------
// do file read
//-----------------------------------------------------------------------------
DWORD file_io_manager::read(DWORD dw_file_handle_, LPVOID p_buffer_, DWORD dw_number_of_bytes_to_read_)
{
	DWORD dw_number_of_bytes_read = 0;
	BOOL b_result = FALSE;

	ASSERT(!is_file_handle_invalid(dw_file_handle_));
	ASSERT(p_buffer_);

	b_result = ::ReadFile((HANDLE)dw_file_handle_, p_buffer_, dw_number_of_bytes_to_read_,
		&dw_number_of_bytes_read, NULL);

	return dw_number_of_bytes_read;
}



//-----------------------------------------------------------------------------
// do file write
//-----------------------------------------------------------------------------
BOOL file_io_manager::write(DWORD dw_file_handle_, LPCVOID p_buffer_, DWORD dw_number_of_bytes_to_write_,
					  DWORD* p_number_of_bytes_written_, VOID* p_overlapped_)
{
	return WriteFile((HANDLE)dw_file_handle_, p_buffer_, dw_number_of_bytes_to_write_,
			p_number_of_bytes_written_, (LPOVERLAPPED)p_overlapped_);
}




//-----------------------------------------------------------------------------
// do file write
//-----------------------------------------------------------------------------
BOOL file_io_manager::write(DWORD dw_file_handle_, LPCVOID p_buffer_, DWORD dw_number_of_bytes_to_write_)
{
	DWORD dw_number_of_bytes_written = 0;
	BOOL b_result = FALSE;

	ASSERT(!is_file_handle_invalid(dw_file_handle_));
	ASSERT(p_buffer_);

	b_result = ::WriteFile((HANDLE)dw_file_handle_, p_buffer_, dw_number_of_bytes_to_write_,
		&dw_number_of_bytes_written, NULL) == TRUE;
	if (dw_number_of_bytes_written != dw_number_of_bytes_to_write_)
		ERROR_CLUE_ON(_T("文件写入错误！"));

	return b_result;

}




//-----------------------------------------------------------------------------
// close the file
//-----------------------------------------------------------------------------
BOOL file_io_manager::close(DWORD dw_file_handle_)
{
	ASSERT(!is_file_handle_invalid(dw_file_handle_));
	return CloseHandle((HANDLE)dw_file_handle_);

}



//-----------------------------------------------------------------------------
// set file pointer
//-----------------------------------------------------------------------------
DWORD file_io_manager::seek(DWORD dw_file_handle_, DWORD dw_distance_to_move_, DWORD dw_move_method_)
{
	ASSERT(!is_file_handle_invalid(dw_file_handle_));
	LARGE_INTEGER st_li, st_liout;
	st_li.HighPart = 0;
	st_li.LowPart = dw_distance_to_move_;
	st_liout.HighPart = 0;
	st_liout.LowPart = dw_distance_to_move_;
	SetFilePointerEx((HANDLE)dw_file_handle_, st_li, &st_liout, dw_move_method_);
	return st_liout.LowPart;
}



//-----------------------------------------------------------------------------
// set file pointer from beginning of the file
//-----------------------------------------------------------------------------
DWORD file_io_manager::seek(DWORD dw_file_handle_, DWORD dw_offset_from_start_)
{
	ASSERT(!is_file_handle_invalid(dw_file_handle_));
	LARGE_INTEGER st_li, st_liout;
	st_li.HighPart = 0;
	st_li.LowPart = dw_offset_from_start_;
	st_liout.HighPart = 0;
	st_liout.LowPart = dw_offset_from_start_;
	SetFilePointerEx((HANDLE)dw_file_handle_, st_li, &st_liout, FILE_BEGIN);
	return st_liout.LowPart;
}


//-----------------------------------------------------------------------------
// set file pointer
//-----------------------------------------------------------------------------
BOOL file_io_manager::seek_extend(DWORD dw_file_handle_, INT64 n64_distance_to_move_, DWORD dw_move_method_)
{
	ASSERT(!is_file_handle_invalid(dw_file_handle_));
	return SetFilePointerEx((HANDLE)dw_file_handle_, *(LARGE_INTEGER*)&n64_distance_to_move_, NULL, dw_move_method_);
}



//-----------------------------------------------------------------------------
// get length of the file
//-----------------------------------------------------------------------------
DWORD file_io_manager::get_size(LPCTSTR sz_file_name_)
{
	DWORD dw_file_size = 0;
	HANDLE h_file_handle = ::CreateFile(sz_file_name_, GENERIC_READ,
		FILE_SHARE_READ, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS, NULL);
			
	if( h_file_handle == INVALID_HANDLE_VALUE )
		return INVALID_VALUE;	
			
	dw_file_size = ::GetFileSize(h_file_handle, NULL);
	CloseHandle(h_file_handle);
	return dw_file_size;
}




//-----------------------------------------------------------------------------
// get length of the file
//-----------------------------------------------------------------------------
DWORD file_io_manager::get_size(DWORD dw_file_handle_)
{
	ASSERT(!is_file_handle_invalid(dw_file_handle_));
	return ::GetFileSize((HANDLE)dw_file_handle_, NULL);

}

//-----------------------------------------------------------------------------
// get length of the file
//-----------------------------------------------------------------------------
BOOL file_io_manager::get_size_extend(DWORD dw_file_handle_, INT64* p_size_)
{
	ASSERT(!is_file_handle_invalid(dw_file_handle_));
	return ::GetFileSizeEx((HANDLE)dw_file_handle_, (PLARGE_INTEGER)p_size_);
}



//-----------------------------------------------------------------------------
// the file may be truncate or extend, if succeeds, return nonzero
//-----------------------------------------------------------------------------
DWORD file_io_manager::set_end_of_file(DWORD dw_file_handle_)
{
	ASSERT(!is_file_handle_invalid(dw_file_handle_));
	return ::SetEndOfFile((HANDLE)dw_file_handle_);
}


//-----------------------------------------------------------------------------
// check the file whether exsit
//-----------------------------------------------------------------------------
BOOL file_io_manager::is_file_exist(LPCTSTR sz_file_name_)
{		
	ASSERT(sz_file_name_);
	WIN32_FIND_DATA st_find_data;
	BOOL b_result = TRUE;

	HANDLE h_handle = ::FindFirstFile(sz_file_name_, &st_find_data);
	if( h_handle == INVALID_HANDLE_VALUE )
		return FALSE;
			
	if( st_find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
		b_result = FALSE;

	::FindClose(h_handle);
	return b_result;
}




//-----------------------------------------------------------------------------
// is filename refer to a directory
//-----------------------------------------------------------------------------
BOOL file_io_manager::is_dir(LPCTSTR sz_file_name_)
{
	ASSERT(sz_file_name_);
	WIN32_FIND_DATA st_find_data;
	BOOL b_result = FALSE;

	HANDLE h_handle = ::FindFirstFile(sz_file_name_, &st_find_data);
	if( h_handle == INVALID_HANDLE_VALUE )
		return FALSE;
			
	if( st_find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
		b_result = TRUE;

	::FindClose(h_handle);
	return b_result;
}




//-----------------------------------------------------------------------------
// 使用此函数比使用open\read要快速
//-----------------------------------------------------------------------------
DWORD file_io_manager::load_to_memory(VOID* p_memory_, LPCTSTR sz_file_name_)
{
	ASSERT(sz_file_name_);

	HANDLE h_handle = ::CreateFile(sz_file_name_, GENERIC_READ, FILE_SHARE_READ, 
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | 
		FILE_FLAG_RANDOM_ACCESS, NULL);

	if( h_handle == INVALID_HANDLE_VALUE )
		return (DWORD)INVALID_VALUE;

	DWORD dw_size = ::GetFileSize(h_handle, NULL);
	if( dw_size == INVALID_VALUE )
	{ 
		ERROR_CLUE_ON(_T("无法获取文件大小 : %s"), sz_file_name_);
		CloseHandle(h_handle);
		return (DWORD)INVALID_VALUE;
	}

	if( NULL == p_memory_ )	
	{
		CloseHandle(h_handle);
		return dw_size;
	}

	DWORD dwBytesRead = 0;
	BOOL b_result = ::ReadFile(h_handle, p_memory_, dw_size, &dwBytesRead, NULL);
	if( b_result == FALSE || dwBytesRead != dw_size )
	{
		ERROR_CLUE_ON(_T("无法读取文件 : %s"), sz_file_name_);
		CloseHandle(h_handle);
		return INVALID_VALUE;
	}

	CloseHandle(h_handle);
	return dw_size;
}



//-----------------------------------------------------------------------------
// find 
//-----------------------------------------------------------------------------
DWORD file_io_manager::find_first_file(LPCTSTR sz_file_name_, VOID* p_find_data_)
{
	ASSERT(sz_file_name_);
	ASSERT(p_find_data_);

	HANDLE h_handle = ::FindFirstFile(sz_file_name_, (LPWIN32_FIND_DATA)p_find_data_);
	if (h_handle == INVALID_HANDLE_VALUE)
		return INVALID_VALUE;

	return (DWORD)h_handle;


}



//-----------------------------------------------------------------------------
// find next
//-----------------------------------------------------------------------------
BOOL file_io_manager::find_next_file(DWORD dw_file_handle_, VOID* p_find_data_)
{
	ASSERT(dw_file_handle_ != FILE_HANDLE_INVALID);
	ASSERT(p_find_data_);

	return ::FindNextFile((HANDLE)dw_file_handle_, (LPWIN32_FIND_DATA)p_find_data_);
}



//-----------------------------------------------------------------------------
// close find handle
//-----------------------------------------------------------------------------
BOOL file_io_manager::find_close(DWORD dw_file_handle_)
{
	ASSERT(dw_file_handle_ != FILE_HANDLE_INVALID);
	return ::FindClose((HANDLE)dw_file_handle_); 
}




//-----------------------------------------------------------------------------
// get_file_num_indir
//-----------------------------------------------------------------------------
DWORD file_io_manager::get_file_num_indir(LPCTSTR sz_file_name_, DWORD& dw_total_bytes_)
{
	DWORD dw_file_num = 0;
	ASSERT(sz_file_name_ != NULL);

	get_file_num_indir(sz_file_name_, dw_file_num, dw_total_bytes_);
	return dw_file_num;
}


//-----------------------------------------------------------------------------
// 注意!此函数存在问题,需要修正!
//-----------------------------------------------------------------------------
VOID file_io_manager::get_file_num_indir(LPCTSTR sz_file_name_, DWORD& dw_file_num_, DWORD& dw_bytes_)
{
	TCHAR sz_buffer[MAX_PATH];
	WIN32_FIND_DATA st_find_data;
	HANDLE h_handle = INVALID_HANDLE_VALUE;
	
	dw_file_num_++;
	lstrcpy(sz_buffer, sz_file_name_);
	lstrcat(sz_buffer, _T("\\*.*"));
	h_handle = ::FindFirstFile(sz_buffer, &st_find_data);
	if( h_handle != INVALID_HANDLE_VALUE)
	{
		while (0 != ::FindNextFile(h_handle, &st_find_data))
		{
			if (st_find_data.cFileName[0] != _T('.'))
			{
				lstrcpy(sz_buffer, sz_file_name_);
				lstrcat(sz_buffer, _T("\\"));
				lstrcat(sz_buffer, st_find_data.cFileName);
				get_file_num_indir(sz_buffer, dw_file_num_, dw_bytes_);
			}
		}

		::FindClose(h_handle);
	}
}


//-------------------------------------------------------------------------------
// 得到磁盘的剩余空间
//-------------------------------------------------------------------------------
INT64 file_io_manager::get_drive_free_space(LPCTSTR sz_driver_name_)
{
	INT64 n64_free_bytes_use = 0;
	typedef INT( WINAPI *GET_DISK_FREE_SPACE_PROC)(LPCTSTR, PULARGE_INTEGER, PULARGE_INTEGER, PULARGE_INTEGER);
	GET_DISK_FREE_SPACE_PROC p_get_disk_free_space = 
		(GET_DISK_FREE_SPACE_PROC)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "GetDiskFreeSpaceExA");

	if( p_get_disk_free_space )
	{
		ULARGE_INTEGER st_total_number_of_bytes;
		ULARGE_INTEGER st_total_number_of_free_bytes;

		BOOL bRet = (p_get_disk_free_space)(sz_driver_name_,
			(PULARGE_INTEGER)&n64_free_bytes_use,
			(PULARGE_INTEGER)&st_total_number_of_bytes,
			(PULARGE_INTEGER)&st_total_number_of_free_bytes);
	}
	else 
	{
		DWORD dw_sectors_per_cluster = 0;
		DWORD dw_bytes_per_sector = 0;
		DWORD dw_number_of_free_cluster = 0;
		DWORD dw_total_number_of_cluster = 0;

		BOOL bRet = GetDiskFreeSpace (sz_driver_name_, 
			&dw_sectors_per_cluster, 
			&dw_bytes_per_sector,
			&dw_number_of_free_cluster, 
			&dw_total_number_of_cluster);

		n64_free_bytes_use = dw_number_of_free_cluster * dw_bytes_per_sector * dw_sectors_per_cluster;
	}

	return n64_free_bytes_use;
}

//-----------------------------------------------------------------------
// 生成正确的配置文件名称
//-----------------------------------------------------------------------
BOOL file_io_manager::get_ini_path( LPTSTR sz_file_name_, LPTSTR sz_file_path_ )
{
	_tcscpy(sz_file_name_, sz_file_path_);
	_tcscat(sz_file_name_, _T(".ini"));
	if (is_file_exist(sz_file_name_))
	{
		return TRUE;
	}

	_tcscpy(sz_file_name_, sz_file_path_);
	_tcscat(sz_file_name_, _T(".inc"));
	if (is_file_exist(sz_file_name_))
	{
		return TRUE;
	}

	return FALSE;
}


} // namespace serverbase{
