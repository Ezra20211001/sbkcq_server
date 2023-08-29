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
*	@file		center_server.h
*	@author		lc
*	@date		2011/03/15	initial
*	@version	0.0.1.0
*	@brief		中心服务器
*/
#ifndef PAI_SERVER
#define PAI_SERVER

#include "WorldMgr.h"

class center_server
{
public:
	center_server(void);
	~center_server(void);

public:

	BOOL			Init(HINSTANCE h_instance_);
	VOID			MainLoop();
	VOID			Destroy();

	UINT			thread_update();
	static UINT WINAPI static_thread_update(LPVOID p_data);

	VOID			lock_update()		{ m_UpdateLock.acquire(); }
	VOID			unlock_update()		{ m_UpdateLock.release(); }

	WorldMgr&		get_world_manager()	{ return m_WorldMgr; }
	
	log_file*		get_log()	{ return m_pLog; }

public:

	static file_container*			m_pVar;
	static thread_manager*			m_pThread;

private:

	VOID			update_memory_use();

private:

	log_file*				m_pLog;
	file_system*			m_pFileSyetem;

	volatile BOOL			b_end_update;	

	Mutex					m_UpdateLock;

	WorldMgr				m_WorldMgr;


	INT						n_cpu_num;				
	DWORD					dw_total_memory;			
	DWORD					dw_avail_memory;			
	DWORD					dw_total_run_time;		


	volatile DWORD			dw_idle_time;			
	volatile DWORD			dw_server_tick;				
};

extern center_server g_center_server;
#define SI_LOG	(g_center_server.get_log())

#endif
