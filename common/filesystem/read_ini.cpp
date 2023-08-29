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


#include "stdafx.h"
#include "read_ini.h"

#include "file_system.h"
#include "file_container.h"

namespace filesystem {

read_ini::read_ini()
{
	map_data_offset.clear();
	map_section_name.clear();
	p_file_data = NULL;
	dw_file_data_size = 0;
}


read_ini::~read_ini()
{
	free_file();
}

BOOL read_ini::load_file( file_system* p_vfs, LPCTSTR sz_file_name_, const INT n_mode_)
{
	if( p_file_data )
		free_file();

	p_file_system = p_vfs;

	//! 读入ini文件
	dw_file_data_size = p_file_system->get_size(sz_file_name_);
	if( INVALID_VALUE == dw_file_data_size )
		return FALSE;

	p_file_data = (BYTE*)malloc(dw_file_data_size+sizeof(TCHAR)*2);
	if( NULL == p_file_data )
		return FALSE;

	dw_file_data_size = p_file_system->load_file(p_file_data, sz_file_name_);
	if( INVALID_VALUE == dw_file_data_size )
		return FALSE;

	//！ 如果是加密文件，前四个字节为密匙，需要解密
	if( VALID_VALUE(n_mode_) )
	{
		ASSERT(1 == n_mode_ || 0 == n_mode_);
		get_tool()->decrypt(p_file_data+sizeof(INT), p_file_data, dw_file_data_size-sizeof(INT), *(INT*)p_file_data, n_mode_);
		*(DWORD*)( p_file_data + dw_file_data_size - sizeof(TCHAR)*2) = 0x0a000d00; 
	}

	//！ 在文件结尾添加换行符
	*(DWORD*)( p_file_data + dw_file_data_size ) = 0x0a000d00; 

	std::map<DWORD, vec_dowrd> map_section;
	tstring str_temp, str_section_name;
	INT n_offset_section = INVALID_VALUE, n_offset_value = INVALID_VALUE, n_offset_key = 0; 
	INT	n_key_size = 0;
	INT n_explain_start = INVALID_VALUE;
	TCHAR* p_data = (TCHAR*)p_file_data;

	for( DWORD n=0; n<(dw_file_data_size+4)/sizeof(TCHAR); n++ )
	{
		switch( *(p_data+n) )
		{
		case _T('['):	
			if( INVALID_VALUE != n_explain_start )
				continue;
			if( false == str_section_name.empty() )
			{
				
				DWORD dw_id = get_tool()->crc32( str_section_name.c_str() );
				
				ASSERT( map_section_name.find( dw_id ) == map_section_name.end() );
				map_section_name.insert(
					std::pair<DWORD,tstring>(dw_id, str_section_name) );
				map_data_offset.insert( 
					std::pair<DWORD, map_dword>(dw_id, map_section) );
				map_section.clear();
			}
			n_offset_section = n+1;
			n_offset_key = INVALID_VALUE;
			n_offset_value = INVALID_VALUE;
			break;

		case _T(']'):	
			if( INVALID_VALUE != n_explain_start )
				continue;

			
			if( n_offset_section != INVALID_VALUE && n - n_offset_section > 0 )
				str_section_name.assign(p_data+n_offset_section,n-n_offset_section);

			n_offset_section = INVALID_VALUE;
			break;

		case _T('='):	
			if( INVALID_VALUE != n_explain_start )
				continue;
			if( INVALID_VALUE != n_offset_key )
			{
				if( n - n_offset_key > 0 )	
				{
					n_key_size = n - n_offset_key;
					n_offset_value = n+1;
				}
				else
					n_offset_key = INVALID_VALUE;
			}
			break;

		case _T(';'):	
			n_explain_start = n;
			break;

		case 0x0a:	
			if( INVALID_VALUE != n_offset_key && INVALID_VALUE != n_offset_value )
			{
				
				std::vector<DWORD> vec;	
				vec.push_back( n_offset_key );
				vec.push_back( n_key_size );
				vec.push_back( n_offset_value );
				if( INVALID_VALUE != n_explain_start )
					vec.push_back( n_explain_start - n_offset_value );
				else
					vec.push_back( n-1 - n_offset_value );
				
				str_temp.assign(p_data+n_offset_key, n_key_size);
				
				while( str_temp.find(_T('\t')) != str_temp.npos )
					str_temp.replace(str_temp.find(_T('\t')), 1, 1, _T(' '));
				
				if( str_temp.find_first_not_of(_T(' ')) != -1 )
					str_temp.assign(str_temp,str_temp.find_first_not_of(_T(' ')),
						str_temp.find_last_not_of(_T(' '))-str_temp.find_first_not_of(_T(' '))+1);
				DWORD dw_id = get_tool()->crc32((LPCTSTR)str_temp.c_str());
				
				ASSERT( map_section.find( dw_id ) == map_section.end() );
				map_section.insert(std::pair<DWORD, vec_dowrd>(dw_id, vec));
			}

			n_offset_section = n_offset_value = INVALID_VALUE;
			n_offset_key = n+1;
			n_explain_start = INVALID_VALUE;
			break;
		}
	}

	if( false == str_section_name.empty() )
	{
		DWORD dw_id = get_tool()->crc32( str_section_name.c_str() );
		map_section_name.insert(std::pair<DWORD,tstring>(dw_id, str_section_name));
		map_data_offset.insert(std::pair<DWORD, map_dword>(dw_id, map_section));
	}

	return TRUE;
}

VOID read_ini::free_file()
{
	free(p_file_data);

	map_data_offset.clear();
	map_section_name.clear();
	p_file_data = NULL;
	dw_file_data_size = 0;
}

PBYTE read_ini::read_value(DWORD& dw_size_, LPCTSTR sz_key_, LPCTSTR sz_section_)
{
	ASSERT( sz_key_ );
	ASSERT( sz_section_ );

	if( NULL == p_file_data )
		return NULL;

	std::map<DWORD, map_dword>::iterator iter = map_data_offset.begin();
	iter = map_data_offset.find(get_tool()->crc32(sz_section_));
	if( iter == map_data_offset.end() )
		return NULL;

	std::map<DWORD, vec_dowrd>::iterator iter_key;
	iter_key = iter->second.find(get_tool()->crc32(sz_key_));
	if( iter_key == iter->second.end() )
			return NULL;

	if( iter_key->second.size() < 4 )	
		return NULL;

	dw_size_ = (iter_key->second)[3];	
	return (p_file_data+(iter_key->second)[2]); 
}

BOOL read_ini::lay_container(file_container* p_container_)
{
	if( !p_container_ )
		return FALSE;

	DWORD dw_key_size = 0, dw_value_size = 0;
	tstring str_key, str_value;
	std::map<DWORD, map_dword>::iterator iter;
	std::map<DWORD, vec_dowrd>::iterator iter_key;
	std::map<DWORD, tstring>::iterator iter_section;
	TCHAR* p_data = (TCHAR*)p_file_data;

	for( iter=map_data_offset.begin(); iter!=map_data_offset.end(); ++iter )
	{
		iter_section = map_section_name.find( iter->first );
		if( iter_section == map_section_name.end() )
			return FALSE;	

		for( iter_key=iter->second.begin(); iter_key!=iter->second.end(); ++iter_key )
		{
			dw_key_size = (iter_key->second)[1];	
			
			str_key.assign((LPCTSTR)(p_data+(iter_key->second)[0]), dw_key_size);

			while( str_key.find(_T('\t')) != str_key.npos )
				str_key.replace(str_key.find(_T('\t')), 1, 1, _T(' '));
			
			get_tool()->cut_string_head_tail_space(str_key);
			
			str_key += _T(" ") + iter_section->second;	
			
			dw_value_size = (iter_key->second)[3];	
			str_value.assign((LPCTSTR)(p_data+(iter_key->second)[2]), dw_value_size);

			while( str_value.find(_T('\t')) != str_value.npos )
				str_value.replace(str_value.find(_T('\t')), 1, 1, _T(' '));
			
			get_tool()->cut_string_head_tail_space(str_value);
			
			p_container_->add_element(str_value.c_str(), str_key.c_str());
		}
	}

	return TRUE;
}




}	// namespace filesystem {
