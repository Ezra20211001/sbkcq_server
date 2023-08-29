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
*	@file		log_file.h
*	@author		lc
*	@date		2011/02/15	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef LOG_FILE
#define LOG_FILE

namespace filesystem {


class FILE_API log_file
{
public:

	BOOL create_log(LPCTSTR sz_file_name_=NULL);
	BOOL write_log(LPCTSTR sz_format_, ...);
	VOID close_file();
	log_file();~log_file();
private:
	DWORD					dw_file_handle;
	TCHAR					sz_log_file_name[1024];
};

class exception_log_file
{
public:

	BOOL create_log();
	BOOL write_log(LPCSTR sz_format_, ...);
	VOID close_file();
	LPCTSTR	get_log_file_name() { return sz_log_file_name; }

	exception_log_file();~exception_log_file();

private:
	DWORD					dw_file_handle;
	TCHAR					sz_log_file_name[1024];
};


} // namespace filesystem {
#endif
