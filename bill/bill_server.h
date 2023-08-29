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
*	@file		bill_server.h
*	@author		lc
*	@date		2011/02/22	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef BILL_SERVER
#define BILL_SERVER

#include "bill_mutex.h"
#include "world_manager.h"
#include "web_manager.h"

struct tag_web_recharge_info;
struct tag_web_act_info;
struct tag_serial_reward_info;
struct tag_media_act_info;

typedef package_safe_list<tag_web_recharge_info*> LIST_RECHARGE;

typedef package_safe_list<tag_web_act_info*> LIST_ACT;
typedef package_safe_list<tag_serial_reward_info*> LIST_SERIAL_REWARD;
typedef package_safe_list<tag_media_act_info*> LIST_MEDIA_ACT;

class bill_server
{
public:
	bill_server(void);
	~bill_server(void);

	BOOL			init(HINSTANCE h_instance_);
	VOID			main_loop();
	VOID			destroy();


	UINT			thread_update();
	static UINT WINAPI static_thread_update(LPVOID p_data);

	UINT			thread_work();
	static UINT WINAPI static_thread_word(LPVOID p_data);


	VOID			lock_update()		{ update_lock.acquire(); }
	VOID			unlock_update()		{ update_lock.release(); }

	VOID			lock_web_update()		{ web_lock.acquire(); }
	VOID			unlock_web_update()		{ web_lock.release(); }	

	
	VOID			shut_down()			{ Interlocked_Exchange((long*)(&b_end_update), TRUE); }

	
	DWORD			get_section_id()		{ return dw_id; }

	
	log_file*		get_log()	{ return p_log; }
	world_manager&		get_world_manager()	{ return m_world_manager; }

	file_system*	get_file_system() { return p_file_system; }

	LIST_RECHARGE&	get_list_recharge_info() { return list_recharge_info; } 
	LIST_ACT&		get_list_act_info()	{ return list_act; }
	LIST_SERIAL_REWARD& get_list_serial_reward() { return list_serial_reward; }
	LIST_MEDIA_ACT&	get_list_media_act() { return list_media_act; }

	VOID		update_recharge();
	VOID		update_act();
	VOID        update_serial();
	VOID		update_media_act();

	VOID		query_recharge_yuanbao(tag_web_recharge_info* p_recharge, INT32& n32_yuanbao);
	BOOL		update_recharge_sign(tag_web_recharge_info* p_recharge);

public:
	static file_container*	p_var;
	static thread_manager*			p_thread;

private:
	
	VOID			update_memory_use();

private:
	
	log_file*				p_log;
	file_system*			p_file_system;

	db_interface*			p_db_interface;
	LIST_RECHARGE			list_recharge_info;
	LIST_ACT				list_act;
	LIST_SERIAL_REWARD		list_serial_reward;
	LIST_MEDIA_ACT			list_media_act;


	DWORD					dw_id;

	world_manager				m_world_manager;

	web_manager					m_web_manager;

	
	volatile BOOL			b_end_update;		
	bill_mutex				update_lock;			
	bill_mutex				web_lock;			

	
	INT						n_cpu_num;				
	DWORD					dw_total_memory;			
	DWORD					dw_avail_memory;			
	DWORD					dw_total_run_time;		

	
	volatile DWORD			dw_idle_time;			
	volatile DWORD			dw_server_tick;				
};

extern bill_server g_billserver;
#define SI_LOG	(g_billserver.get_log())

#endif
