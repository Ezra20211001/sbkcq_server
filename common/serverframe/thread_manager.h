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
*	@file		thread_manager.h
*	@author		lc
*	@date		2011/02/18	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef THREAD_MANAGER
#define THREAD_MANAGER

namespace serverframe {


class FRAME_API thread_manager
{
public:

	
	BOOL create_thread(LPCTSTR sz_thread_name_, THREAD_PROC fn_, LPVOID p_param_);
	
	BOOL waitfor_thread_destroy(LPCTSTR sz_thread_name_, DWORD dw_wait_time_);
	
	VOID waitfor_all_thread_destroy();

	BOOL is_thread_active(LPCTSTR sz_thread_name_);

	HANDLE get_thread_handle(LPCTSTR sz_thread_name_);
	

	thread_manager();
	~thread_manager();

private:
	
	package_safe_map<DWORD, HANDLE>		map_thread_handle;

};






} // namespace serverframe {
#endif
