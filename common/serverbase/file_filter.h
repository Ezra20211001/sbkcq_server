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
*	@file		file_filter.h
*	@author		lc
*	@date		2011/02/22	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef FILE_FILTER
#define FILE_FILTER

namespace serverbase{

//! �ļ���������
enum E_FILTER_TYPE	
{
	EFLT_Null,

	//! ѹ������
	EFLT_Changeless,
	EFLT_MiniLzo,
	EFLT_ZLib,
	EFLT_ZLibChapfallen,

	//! �ӽ�������
	EFLT_Des,
	EFLT_Ras,
	EFLT_Md5,
	EFLT_Sha1,
	EFLT_Sha512,

	EFLT_End
};
 
// ! �ļ�����������
struct tag_file_filter_param	
{
	// ����Ҫ����Ĳ���
	E_FILTER_TYPE	e_filter_type;			// ���ļ���������
	BOOL		b_compress;			//! �Ƿ�ѹ��
	LPVOID		p_memory_in;			// !���뻺����
	LPVOID		p_memory_out;			// !���������
	DWORD		dw_in_buffer_size;		// !���뻺������С
	DWORD		dw_out_buffer_size;	// !�����������С
	DWORD		dw_in_data_size;		// !��������ݴ�С	

	// ���������
	DWORD		dw_out_data_size;	
	BOOL		b_success;
};

class file_filter
{
public:

	BOOL init_file_filter(E_FILTER_TYPE e_filter_type_);	
	
	DWORD get_filter_extra_space(DWORD dw_src_size_, E_FILTER_TYPE e_filter_type_);
	
	BOOL check_extra_space(DWORD dw_in_size_, DWORD dw_out_size_, E_FILTER_TYPE e_filter_type_);

	VOID filter_file(tag_file_filter_param* p_filter_param_);

	file_filter();
	~file_filter();

private:
	
	VOID filter_minilzo(tag_file_filter_param* p_filter_param_);
	VOID filter_zlib(tag_file_filter_param* p_filter_param_);
	VOID filter_zlib_chapfallen(tag_file_filter_param* p_filter_param_);

};



} // namespace serverbase{
#endif
