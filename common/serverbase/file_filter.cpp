/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#include "stdafx.h"
#include "file_filter.h"


#include "minilzo\minilzo.h"
#include "zlib\zlib.h"

namespace serverbase{


#define LZO_HEAP_ALLOC(var,size) \
	long __LZO_MMODEL var [((size)+(sizeof(long)-1))/sizeof(long)]
static LZO_HEAP_ALLOC(p_lzo_memory, LZO1X_1_MEM_COMPRESS);


file_filter::file_filter()
{
	init_file_filter(EFLT_MiniLzo);	
}

file_filter::~file_filter()
{}


BOOL file_filter::init_file_filter(E_FILTER_TYPE e_filter_type_)
{
	INT n_result = 0;
	switch(e_filter_type_)
	{
	case EFLT_MiniLzo:
		n_result = lzo_init();
		if( LZO_E_OK!=n_result )
			return FALSE;
		
		break;
	}

	return TRUE;
}

DWORD file_filter::get_filter_extra_space(DWORD dw_src_size_, E_FILTER_TYPE e_filter_type_)
{
	DWORD dw_add = 0;
	switch(e_filter_type_)
	{
	case EFLT_MiniLzo:
		dw_add = (dw_src_size_/64) + 16 + 3;
		break;

	case EFLT_ZLib:
	case EFLT_ZLibChapfallen:
		dw_add = (dw_src_size_/1000) + 12;
		break;
	}

	return dw_add;
}


BOOL file_filter::check_extra_space(DWORD dw_in_size_, DWORD dw_out_size_, E_FILTER_TYPE e_filter_type_)
{
	DWORD dw_add = get_filter_extra_space(dw_in_size_, e_filter_type_);

	if( dw_out_size_ < dw_in_size_ + dw_add )
		return FALSE;
	else
		return TRUE;
}

VOID file_filter::filter_file(tag_file_filter_param* p_filter_param_)
{
	ASSERT(p_filter_param_);
	switch(p_filter_param_->e_filter_type)
	{
	case EFLT_Changeless:
		memcpy(p_filter_param_->p_memory_out, p_filter_param_->p_memory_in, p_filter_param_->dw_in_data_size);
		p_filter_param_->dw_out_data_size = p_filter_param_->dw_in_data_size;
		p_filter_param_->b_success = TRUE;
		break;

	case EFLT_MiniLzo:
		filter_minilzo(p_filter_param_);
		break;

	case EFLT_ZLib:
		filter_zlib(p_filter_param_);
		break;

	case EFLT_ZLibChapfallen:	
		filter_zlib_chapfallen(p_filter_param_);
		break;

	default:
		ASSERT(0);
		break;
	}

}

VOID file_filter::filter_minilzo(tag_file_filter_param* p_filter_param_)
{
	INT n_result = 0;
	if( p_filter_param_->b_compress )	
	{
		n_result = lzo1x_1_compress((lzo_byte*)p_filter_param_->p_memory_in,
			p_filter_param_->dw_in_data_size,
			(lzo_byte*)p_filter_param_->p_memory_out,
			(lzo_uint*)&(p_filter_param_->dw_out_data_size),
			p_lzo_memory);
		if (n_result == LZO_E_OK)
			p_filter_param_->b_success = TRUE;
		else
		{
			p_filter_param_->b_success = FALSE;
			ERROR_CLUE_ON(_T("LZOÑ¹ËõÊ§°Ü : %d\n"), n_result);
		}
	}
	else	// minilzo decompress
	{
		n_result = lzo1x_decompress((lzo_byte*)p_filter_param_->p_memory_in,
			p_filter_param_->dw_in_data_size,
			(lzo_byte*)p_filter_param_->p_memory_out,
			(lzo_uint*)&(p_filter_param_->dw_out_data_size),
			NULL);
		if( n_result == LZO_E_OK )
			p_filter_param_->b_success = TRUE;
		else
			p_filter_param_->b_success = FALSE;
	}
}

VOID file_filter::filter_zlib(tag_file_filter_param* p_filter_param_)
{
	INT n_result = 0;
	if( p_filter_param_->b_compress ) 
	{
		n_result = ::compress((PBYTE)p_filter_param_->p_memory_out, &(p_filter_param_->dw_out_data_size),
			(PBYTE)p_filter_param_->p_memory_in, p_filter_param_->dw_in_data_size);
		
		if( n_result == Z_OK )
			p_filter_param_->b_success = TRUE;
		else
		{
			p_filter_param_->b_success = FALSE;
			ERROR_CLUE_ON(_T("ZLIBÑ¹ËõÊ§°Ü."));
		}
	}
	else	
	{	
		n_result = ::uncompress((PBYTE)p_filter_param_->p_memory_out, &(p_filter_param_->dw_out_data_size),
			(PBYTE)p_filter_param_->p_memory_in, p_filter_param_->dw_in_data_size);
		
		if( n_result == Z_OK )
			p_filter_param_->b_success = TRUE;
		else
		{	
			p_filter_param_->b_success = FALSE;
			ERROR_CLUE_ON(_T("ZLIB½âÑ¹Ê§°Ü."));
		}
	}
}

VOID file_filter::filter_zlib_chapfallen(tag_file_filter_param* p_filter_param_)
{
	ASSERT( !p_filter_param_->b_compress ); 
	
	INT n_error;
	z_stream st_stream; 
	
	memset(&st_stream,0,sizeof(st_stream));
	st_stream.zalloc = (alloc_func)0;
	st_stream.zfree	= (free_func)0;
	st_stream.opaque = (voidpf)0;
	
	st_stream.next_in  = (Bytef*)p_filter_param_->p_memory_in;
	st_stream.avail_in = p_filter_param_->dw_in_buffer_size;
	
	n_error = inflateInit2(&st_stream,-MAX_WBITS);
	if( n_error != Z_OK )
	{
		p_filter_param_->b_success = FALSE;
		ERROR_CLUE_ON(_T("ZIP½âÑ¹Ê§°Ü£¨inflateInit2£©"));
		return; 
	}
	
	for ( ;; )
	{
		st_stream.next_out  = (Bytef*)p_filter_param_->p_memory_out;
		st_stream.avail_out = p_filter_param_->dw_out_buffer_size;
		
		n_error = inflate(&st_stream,Z_FINISH);
		if( n_error == Z_STREAM_END )
			break;
		
		if( n_error != Z_OK )
		{
			switch( n_error )
			{
			case Z_MEM_ERROR:	
				ERROR_CLUE_ON(_T("ZIP½âÑ¹Ê§°Ü£¨ÄÚ´æ´íÎó£©"));
				break;
			case Z_BUF_ERROR:	
				ERROR_CLUE_ON(_T("ZIP½âÑ¹Ê§°Ü£¨»º³å´íÎó£©"));
				break;
			case Z_DATA_ERROR:	
				ERROR_CLUE_ON(_T("ZIP½âÑ¹Ê§°Ü£¨Êý¾Ý´íÎó£©"));
				break;
			default:
				ERROR_CLUE_ON(_T("ZIP½âÑ¹Ê§°Ü£¨Î´Öª´íÎó£©"));
			}
			p_filter_param_->b_success = FALSE;
			return;
		}
	}
	
	n_error = inflateEnd( &st_stream );
	if( n_error != Z_OK )
	{
		ERROR_CLUE_ON(_T("ZIP½âÑ¹Ê§°Ü£¨inflateEnd£©"));
		p_filter_param_->b_success = FALSE;
		return;
	}
	
	p_filter_param_->dw_out_data_size = st_stream.total_out;
	p_filter_param_->b_success = TRUE;
}




} // namespace serverbase{
