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
*	@file		tool.h
*	@author		lc
*	@date		2011/02/21	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef TOOL
#define TOOL

#include <psapi.h>
#include <tlhelp32.h>

namespace serverbase {


#define CARDINAL_NUMBER	8192	//！ 随机数基数

const int MAX_FILE_NAME = 256;

class SERVERBASE_API tool
{
public:
	DWORD	get_idlesse_id();
	
	//! 随机数相关
	VOID	tool_randomize(DWORD dw_seed_);
	DWORD	get_rand_seed() { return n_rand_seed; }
	INT		tool_rand();

	//! 根据概率计算成功率
	BOOL	probability(INT n_radices_);
	//! 给定数值及上下浮动范围，算出浮动数
	FLOAT	fluctuate(FLOAT f_num_, FLOAT f_increase_, FLOAT f_decrease_);

	//! 给定最大，最小值，算出某个中间值
	INT		rand_in_range(INT n_min_, INT n_max_);
	
	__forceinline DWORD	crc32(LPCSTR sz_buffer_);	
	__forceinline DWORD	crc32(LPCTSTR sz_buffer_);	
	__forceinline DWORD	crc32(LPBYTE p_data_, INT n_byte_count_);
	
	WORD	crc16(PBYTE p_data_, INT n_byte_count_);

	__forceinline LPCSTR	unicode_to_unicode8(LPCTSTR sz_src_, LPSTR sz_out_=NULL);
	__forceinline LPCTSTR	unicode8_to_unicode(LPCSTR sz_src_, LPTSTR sz_out_=NULL);
	__forceinline LPCSTR	unicode_to_ansi(LPCTSTR sz_src_);
	__forceinline LPCTSTR	ansi_to_unicode(LPCSTR sz_src_);

	//! 删除tstring头尾的空格
	VOID cut_string_head_tail_space(tstring& string_);
	//! 解析字符串命令中的数值，并压入vector
	VOID string_to_vector(std::vector<tstring>& vector_, LPCWSTR sz_string_, WCHAR sz_separator_=_T(' '));

	//! 检查注册表中的指定键值是否存在 
	BOOL check_register(HKEY key_, LPCTSTR sz_subkey_);
	//!	按指定路径写入键值，如果指定路径，就在注册表中建立路径并写入键值
	BOOL write_register(LPCTSTR sz_register_path_, LPCTSTR sz_key_name_, LPCTSTR sz_string_);
	//! 读取注册表指定路径的指定键值
	BOOL read_rigister(LPCTSTR sz_register_path_, LPCTSTR sz_key_name_, DWORD& dw_key_value_);
	BOOL read_rigister(LPCTSTR sz_register_path_, LPCTSTR sz_key_name_, LPTSTR sz_out_);

	bool is_debug_present();

	INT get_cup_num();

public:
	//! 通过密匙对某段内存区域加密（内存区域必须满足8字节的整数倍）
	BOOL encrypt(VOID* p_in_, VOID* p_out_, const INT n_length_, UCHAR* p_key_);
	//! 通过密匙对某段内存区域解密（内存区域必须满足8字节的整数倍）
	BOOL decrypt(VOID* p_in_, VOID* p_out_, const INT n_length_, UCHAR* p_key_);
	//! 通过密匙数组中的索引对某个内存区域进行加密 
	BOOL encrypt(VOID* p_in_, VOID* p_out_, const INT n_length_, const INT n_index_, const INT n_mode_ = 0);
	//! 通过密匙数组中的索引对某个内存区域进行解密
	BOOL decrypt(VOID* p_in_, VOID* p_out_, const INT n_length_, const INT n_index_, const INT n_mode_ = 0);

private:
	//! 通用的加解密函数
	BOOL encrypt_and_decrypt(UCHAR* p_in_, UCHAR* p_out_, const INT n_length_, UCHAR* p_key_, bool b_encypt_=0);

public:
	VOID	md5_for_buffer(BYTE* p_buffer_, UINT n_buffer_length_, BYTE by_digest_[16]);
	VOID	md5_for_string(CHAR* sz_string_, BYTE by_digest_[16]);
	BOOL	md5_for_file(LPCTSTR sz_file_name_, BYTE by_digest_[16]);
	VOID	md5_to_string(std::string& string_, BYTE by_digest_[16]);

	tool();
	~tool();

private:

	CRITICAL_SECTION	_lock;

	DWORD	dw_id_seed;		
	INT		n_rand_seed;
	INT		n_rand_call_num;
	CHAR*	p_char_buffer;
	TCHAR*	p_tchar_buffer;


	typedef struct 
	{
		DWORD	_state[4];		
		DWORD	_count[2];		
		BYTE	_buffer[64];		
	} MD5_CONTEXT;
	MD5_CONTEXT	st_context;


	void	md5_init();
	void	md5_update(BYTE *p_in_, UINT n_in_length_);
	void	md5_final(BYTE by_digest_[16]);

	void	md5_transform (DWORD[4], unsigned char[64]);
	
	void	encode(BYTE* p_out_, DWORD* p_in_, unsigned int);
	
	void	decode(DWORD* p_out_, BYTE* p_in_, unsigned int);

};


#define CHAR_BUFFER_SIZE	1024*64
#define SI_MASKBITS 0x3F
#define SI_MASKBYTE 0x80
#define SI_MASK2BYTES 0xC0
#define SI_MASK3BYTES 0xE0

LPCSTR tool::unicode_to_unicode8(LPCTSTR sz_src_, LPSTR sz_out_)
{
	if( !sz_out_ )
		sz_out_ = p_char_buffer;
	LPSTR sz_dest = sz_out_;

	while( *sz_src_ )
	{
		if(*sz_src_ < 0x80)	
		{
			*sz_dest++ = (BYTE)*sz_src_;
		}
		else if( *sz_src_ < 0x800 )	
		{
			*sz_dest++ = ((byte)(SI_MASK2BYTES | *sz_src_ >> 6));
			*sz_dest++ = ((byte)(SI_MASKBYTE | *sz_src_ & SI_MASKBITS));
		}
		else	
		{
			*sz_dest++ = ((byte)(SI_MASK3BYTES | *sz_src_ >> 12));
			*sz_dest++ = ((byte)(SI_MASKBYTE | *sz_src_ >> 6 & SI_MASKBITS));
			*sz_dest++ = ((byte)(SI_MASKBYTE | *sz_src_ & SI_MASKBITS));
		}
		++sz_src_;
	}

	*sz_dest = 0; 
	return sz_out_;
}

LPCTSTR	tool::unicode8_to_unicode(LPCSTR sz_src_, LPTSTR sz_out_)
{
	if( !sz_out_ )
		sz_out_ = p_tchar_buffer;

	LPTSTR sz_dest = sz_out_;

	while( *sz_src_ )
	{
		if( !(*sz_src_ & SI_MASKBYTE) )	
		{
			*sz_dest++ = *sz_src_++;
		}
		else if( (*sz_src_ & SI_MASK3BYTES) == SI_MASK3BYTES )	
		{
			*sz_dest++ = ((*sz_src_ & 0x0F) << 12) | ((*(sz_src_+1) & SI_MASKBITS) << 6) | (*(sz_src_+2) & SI_MASKBITS);
			++sz_src_;
			++sz_src_;
			++sz_src_;
		}
		else if( (*sz_src_ & SI_MASK2BYTES) == SI_MASK2BYTES )	
		{
			*sz_dest++ = ((*sz_src_ & 0x1F) << 6) | (*(sz_src_+1) & SI_MASKBITS);
			++sz_src_;
			++sz_src_;
		}
	}

	*sz_dest = 0; 
	return sz_out_;
}

LPCSTR tool::unicode_to_ansi(LPCTSTR sz_src_)
{
	p_char_buffer[0] = 0;
	WideCharToMultiByte(CP_ACP, 0, sz_src_, -1, p_char_buffer, CHAR_BUFFER_SIZE, NULL, NULL);
	return p_char_buffer;
}

LPCTSTR tool::ansi_to_unicode(LPCSTR sz_src_)
{
	p_char_buffer[0] = 0;
	MultiByteToWideChar(CP_ACP, 0, sz_src_, -1, p_tchar_buffer, CHAR_BUFFER_SIZE);
	return p_tchar_buffer;
}

DWORD tool::crc32(LPCSTR sz_buffer_)
{
	LPBYTE p_data = (LPBYTE)sz_buffer_;
	if( 0 == p_data[0] ) 
		return (DWORD)INVALID_VALUE;

	UINT n_result = *p_data++ << 24;
	if( *p_data )
	{
		n_result |= *p_data++ << 16;
		if( *p_data )
		{
			n_result |= *p_data++ << 8;
			if( *p_data ) n_result |= *p_data++;
		}
	}
	n_result = ~ n_result;
	while( *p_data )
	{
		n_result = (n_result << 8 | *p_data) ^ crc32_table[n_result >> 24];
		p_data++;
	}
	return ~n_result;
}

DWORD tool::crc32(LPCTSTR sz_buffer_)
{
	LPBYTE p_data = (LPBYTE)sz_buffer_;
	if( !(*p_data || *(p_data+1)) ) 
		return (DWORD)INVALID_VALUE;

	UINT n_result = *p_data++ << 24;
	n_result |= *p_data++ << 16;
	if( *p_data || *(p_data+1) )
	{
		n_result |= *p_data++ << 8;
		n_result |= *p_data++;
	}
	n_result = ~ n_result;
	INT n_count = 0;
	while( (n_count&1) ? true : (*p_data || *(p_data+1)) )
	{
		n_result = (n_result << 8 | *p_data) ^ crc32_table[n_result >> 24];
		++p_data;
		++n_count;
	}

	return ~n_result;
}

DWORD tool::crc32(LPBYTE p_data_, INT n_byte_count_)
{
	if( n_byte_count_ <= 0 )
		return (DWORD)INVALID_VALUE;

	UINT n_result = *p_data_++ << 24;
	if( --n_byte_count_ > 0 )
	{
		n_result |= *p_data_++ << 16;
		if( --n_byte_count_ > 0 )
		{
			n_result |= *p_data_++ << 8;
			if( --n_byte_count_ > 0 ) n_result |= *p_data_++;
		}
	}
	n_result = ~ n_result;
	while( --n_byte_count_ > 0 )
	{
		n_result = (n_result << 8 | *p_data_) ^ crc32_table[n_result >> 24];
		p_data_++;
	}

	return ~n_result;
}


} // namespace serverbase {
#endif
