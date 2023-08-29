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
*	@file		center_server.cpp
*	@author		lc
*	@date		2011/03/15	initial
*	@version	0.0.1.0
*	@brief		中心服务器
*/


#include "StdAfx.h"
#include "center_server.h"


#define CONFIG_INI  "server_config\\center\\center"

center_server g_center_server;

file_container*	center_server::m_pVar = NULL;
thread_manager*	center_server::m_pThread = NULL;

center_server::center_server(void) : b_end_update(FALSE), n_cpu_num(0), dw_total_memory(0), dw_avail_memory(0), dw_total_run_time(0),
dw_idle_time(0), dw_server_tick(0)
{
	m_pLog = new log_file;
	m_pFileSyetem = new file_system;
	center_server::m_pVar = new file_container;
	center_server::m_pThread = new thread_manager;
}

center_server::~center_server(void)
{
	SAFE_DELETE(m_pLog);
	SAFE_DELETE(m_pFileSyetem);
	SAFE_DELETE(center_server::m_pVar);
	SAFE_DELETE(center_server::m_pThread);
}

BOOL center_server::Init(HINSTANCE h_instance_)
{
	m_pLog->create_log();

	if(!VALID_POINT(center_server::m_pVar))
	{
		return FALSE;
	}

	TCHAR sz_path[MAX_PATH];
	ZeroMemory(sz_path, sizeof(sz_path));
	if (!get_file_io_mgr()->get_ini_path(sz_path, _T(CONFIG_INI))||
		!center_server::m_pVar->load(m_pFileSyetem, sz_path))
	{
		ERROR_CLUE_ON(_T("not find config file"));
		return FALSE;
	}

	LONG l_width	=	center_server::m_pVar->get_dword(_T("width display"));
	LONG l_height	=	center_server::m_pVar->get_dword(_T("height display"));

	get_window()->init(l_width, l_height, TRUE);
	get_window()->create_window(_T("VerifyServer"), h_instance_);

	n_cpu_num = get_tool()->get_cup_num();
	dw_total_run_time = 0;

	if( FALSE == m_WorldMgr.init() )
	{
		SI_LOG->write_log(_T("world mamager init fail\r\n"));
		return FALSE;
	}

	if( FALSE == center_server::m_pThread->create_thread( _T("thread_update"), 
		&center_server::static_thread_update, this) )
		return FALSE;

	return TRUE;
}

VOID center_server::MainLoop()
{
	DWORD dw_message, dw_param1, dw_param2;
	static DWORD dw_current_time = timeGetTime();

	while ( FALSE == get_window()->message_loop() && FALSE == b_end_update )
	{
		if( FALSE == get_window()->is_window_active() )
		{
			Sleep(30);
			continue;
		}

		while( get_window()->peek_window_message( dw_message, dw_param1, dw_param2 ) )
		{
			if( dw_message == WM_QUIT )
			{
				return;
			}
			if(dw_message == WM_MYSELF_USER)
			{
				if(dw_param1 == 1)
				{
					get_window()->print_list();
				}
			}
		}

		update_memory_use();

		dw_total_run_time = timeGetTime() - dw_current_time;
		INT nHour = dw_total_run_time / 3600000;
		INT nMin = (dw_total_run_time % 3600000) / 60000;
		INT nSec = ((dw_total_run_time % 3600000) % 60000) / 1000;

		get_window()->watch_info(_T("cup_number:"),				n_cpu_num);
		get_window()->watch_info(_T("memory_total:"),				dw_total_memory);
		get_window()->watch_info(_T("memory_avail:"),				dw_avail_memory);

		get_window()->watch_info(_T("second: "),					nSec);
		get_window()->watch_info(_T("min: "),					nMin);
		get_window()->watch_info(_T("hour: "),					nHour);

		get_window()->watch_info(_T("tick: "),					dw_server_tick);
		get_window()->watch_info(_T("idle_time: "),					dw_idle_time);


		Sleep(50);
	}
}

VOID center_server::Destroy()
{
	Interlocked_Exchange((LPLONG)&b_end_update, TRUE );
	center_server::m_pThread->waitfor_thread_destroy(_T("thread_update"), INFINITE);


	get_window()->destroy();
}

VOID center_server::update_memory_use()
{
	MEMORYSTATUS st_memory_status;
	st_memory_status.dwLength = sizeof(st_memory_status);
	GlobalMemoryStatus(&st_memory_status);

	dw_total_memory = st_memory_status.dwTotalPhys;
	dw_avail_memory = st_memory_status.dwAvailPhys;

	PROCESS_MEMORY_COUNTERS st_memory_counters;
	GetProcessMemoryInfo(GetCurrentProcess(), &st_memory_counters, sizeof(st_memory_counters));
}

UINT center_server::thread_update()
{
	DWORD dw_time = 0;

	_set_se_translator(serverdump::si_translation); 

	try
	{
		while( !b_end_update )
		{
			dw_time = timeGetTime();

			lock_update();

			m_WorldMgr.update();

			unlock_update();

			dw_time = timeGetTime() - dw_time;
			if( dw_time < TICK_TIME )
			{
				Interlocked_Exchange((LPLONG)&dw_idle_time, TICK_TIME - dw_time);
			}
			else
			{
				Interlocked_Exchange((LPLONG)&dw_idle_time, 0);
			}

			Interlocked_Exchange_Add((LPLONG)&dw_server_tick, 1);

			if( dw_time < TICK_TIME )
			{
				Sleep(TICK_TIME - dw_time);
			}
		}
	}
	catch(serverdump::throw_exception)
	{
		if( get_tool()->is_debug_present() )
		{
			throw;
		}
		else
		{
			exit(1);
		}
	}
	_endthreadex(0);

	return 0;
}

UINT center_server::static_thread_update(LPVOID p_data)
{
	ASSERT(VALID_POINT(p_data));
	center_server* p_this = (center_server*)p_data;
	return p_this->thread_update();
}