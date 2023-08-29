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

#include "StdAfx.h"
#include "bill_server.h"
#include "world_manager.h"
#include "..\common\ServerDefine\bill_message_client.h"
#include "..\common\ServerDefine\bill_message_server.h"


#define CONFIG_INI  "server_config\\bill\\bill"

file_container* bill_server::p_var = NULL;
thread_manager*		  bill_server::p_thread = NULL;

bill_server::bill_server(void) : b_end_update(FALSE), n_cpu_num(0), dw_total_memory(0), dw_avail_memory(0), dw_total_run_time(0),
dw_idle_time(0), dw_server_tick(0)
{
	bill_server::p_var = new file_container;
	p_log = new log_file;
	p_file_system = new file_system;
	bill_server::p_thread = new thread_manager;
	p_db_interface = new db_interface;
}

bill_server::~bill_server(void)
{
	SAFE_DELETE(bill_server::p_var);
	SAFE_DELETE(p_file_system);
	SAFE_DELETE(bill_server::p_thread);
	SAFE_DELETE(p_db_interface);
}

BOOL bill_server::init(HINSTANCE h_instance_)
{

	p_log->create_log();

	if( !VALID_POINT(bill_server::p_var) )
	{
		return FALSE;
	}

	TCHAR sz_path[MAX_PATH];
	ZeroMemory(sz_path, sizeof(sz_path));
	if (!get_file_io_mgr()->get_ini_path(sz_path, _T(CONFIG_INI))||
		!bill_server::p_var->load(g_billserver.get_file_system(), sz_path))
	{
		ERROR_CLUE_ON(_T("未能找到配置文件"));
		return FALSE;
	}

	dw_id			=	bill_server::p_var->get_dword(_T("id section"));

	LONG l_width	=	bill_server::p_var->get_dword(_T("width display"));
	LONG l_height	=	bill_server::p_var->get_dword(_T("height display"));

	get_window()->init(l_width, l_height, TRUE);
	get_window()->create_window(_T("BillServer"), h_instance_);

	n_cpu_num = get_tool()->get_cup_num();
	dw_total_run_time = 0;

	/*if(!p_db_interface->init_db(bill_server::p_var->get_string(_T("host_name"), _T("webdb")),
								bill_server::p_var->get_string(_T("user_name"), _T("webdb")),
								bill_server::p_var->get_string(_T("password"), _T("webdb")),
								bill_server::p_var->get_string(_T("db_name"), _T("webdb")),
								bill_server::p_var->get_int(_T("port"), _T("webdb"))))
	{
		SI_LOG->write_log(_T("\r\nwebdb init faild! \r\n"));
		return FALSE;
	}*/

	if( FALSE == g_billserver.get_world_manager().init() )
	{
		SI_LOG->write_log(_T("游戏世界管理初始化失败\r\n"));
		return FALSE;
	}

	if(FALSE == m_web_manager.init())
	{
		SI_LOG->write_log(_T("网页管理初始失败\r\n"));
		return FALSE;
	}

	if( FALSE == bill_server::p_thread->create_thread( _T("thread_update"), 
		&bill_server::static_thread_update, this) )
		return FALSE;

	if( FALSE == bill_server::p_thread->create_thread(_T("thread_work"),
		&bill_server::static_thread_word, this))
		return FALSE;

	return TRUE;

}

VOID bill_server::main_loop()
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
	
		get_window()->watch_info(_T("cup数量:"),				n_cpu_num);
		get_window()->watch_info(_T("内存总数:"),				dw_total_memory);
		get_window()->watch_info(_T("可用内存数:"),				dw_avail_memory);

		get_window()->watch_info(_T("秒: "),					nSec);
		get_window()->watch_info(_T("分: "),					nMin);
		get_window()->watch_info(_T("小时: "),					nHour);

		get_window()->watch_info(_T("运行tick: "),					dw_server_tick);
		get_window()->watch_info(_T("空闲时间: "),					dw_idle_time);

	
		Sleep(50);
	}
}

VOID bill_server::destroy()
{
	Interlocked_Exchange((LPLONG)&b_end_update, TRUE );
	//bill_server::p_thread->waitfor_thread_destroy(_T("thread_update"), INFINITE);
	bill_server::p_thread->waitfor_all_thread_destroy();


	p_db_interface->shut_down();

	m_world_manager.destroy();

	m_web_manager.destroy();

	get_window()->destroy();

}

VOID bill_server::update_media_act()
{
	while(list_media_act.size() > 0)
	{
		tag_media_act_info* p_media_act = list_media_act.pop_front();
		if(!VALID_POINT(p_media_act))
			continue;

		m_web_manager.lock_account_common(p_media_act->dw_world_crc);

		if(!m_web_manager.check_account_common(p_media_act->dw_account_id, p_media_act->dw_world_crc))
		{
			if(!m_web_manager.insert_account_common(p_media_act->dw_account_id, p_media_act->dw_world_crc, p_media_act->sz_account_name))
			{
				SI_LOG->write_log(_T("account_common insert faild id=%u\r\n"), p_media_act->dw_account_id);
				m_web_manager.unlock_tables(p_media_act->dw_world_crc);
				continue;
			}
		}

		if(!m_web_manager.update_media_receive_type(p_media_act->dw_account_id, p_media_act->dw_world_crc, p_media_act->dw_type))
		{
			SI_LOG->write_log(_T("id=%u world=%u media_type=%u account_common update faild\r\n"), p_media_act->dw_account_id, p_media_act->dw_world_crc, p_media_act->dw_type);
			m_web_manager.unlock_tables(p_media_act->dw_world_crc);
			continue;
		}

		m_web_manager.unlock_tables(p_media_act->dw_world_crc);

		SAFE_DELETE(p_media_act);
		
	}
}

VOID bill_server::update_act()
{
	while(list_act.size() > 0)
	{
		tag_web_act_info* p_web_act_info = list_act.pop_front();
		
		if(!VALID_POINT(p_web_act_info))
			continue;

		m_web_manager.lock_account_common(p_web_act_info->dw_world_crc);

		if(!m_web_manager.check_account_common(p_web_act_info->dw_account_id, p_web_act_info->dw_world_crc))
		{
			if(!m_web_manager.insert_account_common(p_web_act_info->dw_account_id, p_web_act_info->dw_world_crc, p_web_act_info->sz_account_name))
			{
				SI_LOG->write_log(_T("account_common insert faild id=%u\r\n"), p_web_act_info->dw_account_id);
				m_web_manager.unlock_tables(p_web_act_info->dw_world_crc);
				/*tagBill2Web_Login send_res;
				send_res.dw_error = 0;
				send_res.dw_account_id = p_web_act_info->dw_account_id;
				strncpy(send_res.sz_account_name, p_web_act_info->sz_account_name, X_SHORT_NAME);
				send_res.n_type = 0;
				m_web_manager.send_message(ID_WEBSERVER, &send_res, send_res.dw_size);*/
				continue;
			}
		}

		if(!m_web_manager.update_receive_type(p_web_act_info->dw_account_id, p_web_act_info->dw_world_crc, p_web_act_info->dw_web_type))
		{
			SI_LOG->write_log(_T("id=%u world=%u wet_type=%u account_common update faild\r\n"), p_web_act_info->dw_account_id, p_web_act_info->dw_world_crc, p_web_act_info->dw_web_type);
			m_web_manager.unlock_tables(p_web_act_info->dw_world_crc);
			/*tagBill2Web_Login send_res;
			send_res.dw_error = 0;
			send_res.dw_account_id = p_web_act_info->dw_account_id;
			strncpy(send_res.sz_account_name, p_web_act_info->sz_account_name, X_SHORT_NAME);
			send_res.n_type = 0;
			m_web_manager.send_message(ID_WEBSERVER, &send_res, send_res.dw_size);*/
			continue;
		}

		m_web_manager.unlock_tables(p_web_act_info->dw_world_crc);

		tagNBW_ChangeReceive send;
		send.dw_account_id = p_web_act_info->dw_account_id;
		g_billserver.get_world_manager().send_message(p_web_act_info->dw_world_crc, &send, send.dw_size);

		/*tagBill2Web_Login send_res;
		send_res.dw_error = 1;
		send_res.dw_account_id = p_web_act_info->dw_account_id;
		strncpy(send_res.sz_account_name, p_web_act_info->sz_account_name, X_SHORT_NAME);
		send_res.n_type = 0;
		m_web_manager.send_message(ID_WEBSERVER, &send_res, send_res.dw_size);*/

		SAFE_DELETE(p_web_act_info);
	}
}

VOID bill_server::update_recharge()
{
	while(list_recharge_info.size() > 0)
	{
		tag_web_recharge_info* p_recharge_info = list_recharge_info.pop_front();

		if(!VALID_POINT(p_recharge_info))
			continue;

		m_web_manager.lock_account_common(p_recharge_info->dw_world_crc);

		if(!m_web_manager.check_account_common(p_recharge_info->dw_account_id, p_recharge_info->dw_world_crc))
		{
			if(!m_web_manager.insert_account_common(p_recharge_info->dw_account_id, p_recharge_info->dw_world_crc, p_recharge_info->sz_account_name))
			{
				SI_LOG->write_log(_T("account_common insert faild id=%u\r\n"), p_recharge_info->dw_account_id);
				m_web_manager.unlock_tables(p_recharge_info->dw_world_crc);
				/*tagBill2Web_Login send;
				send.dw_error = 0;
				send.dw_account_id = p_recharge_info->dw_account_id;
				strncpy(send.sz_account_name, p_recharge_info->sz_account_name, X_SHORT_NAME);
				strncpy(send.sz_trade_code, p_recharge_info->sz_trade_code, X_SHORT_NAME);
				send.n_type = 1;
				m_web_manager.send_message(ID_WEBSERVER, &send, send.dw_size);*/
				continue;
			}
		}
		
		if(!m_web_manager.update_yuanbao_recharge(p_recharge_info->dw_world_crc, p_recharge_info->dw_account_id, p_recharge_info->dw_recharge_num))
		{
			SI_LOG->write_log(_T("id=%u serial=%s num=%u world=%u recharge faild\r\n"), p_recharge_info->dw_account_id, get_tool()->ansi_to_unicode(p_recharge_info->sz_trade_code),
				p_recharge_info->dw_recharge_num, p_recharge_info->dw_world_crc);
			m_web_manager.unlock_tables(p_recharge_info->dw_world_crc);
			/*tagBill2Web_Login send;
			send.dw_error = 0;
			send.dw_account_id = p_recharge_info->dw_account_id;
			strncpy(send.sz_account_name, p_recharge_info->sz_account_name, X_SHORT_NAME);
			strncpy(send.sz_trade_code, p_recharge_info->sz_trade_code, X_SHORT_NAME);
			send.n_type = 1;
			m_web_manager.send_message(ID_WEBSERVER, &send, send.dw_size);*/
			continue;
		}

		m_web_manager.unlock_tables(p_recharge_info->dw_world_crc);

		m_web_manager.insert_yuanbao_log(p_recharge_info->dw_account_id, p_recharge_info->dw_recharge_num, p_recharge_info->dw_world_crc, p_recharge_info->sz_trade_code);

		tagNBW_PickBaiBao send;
		send.dw_account_id = p_recharge_info->dw_account_id;
		send.dw_recharge_num = p_recharge_info->dw_recharge_num;
		g_billserver.get_world_manager().send_message(p_recharge_info->dw_world_crc, &send, send.dw_size);

		/*tagBill2Web_Login send_res;
		send_res.dw_error = 1;
		send_res.dw_account_id = p_recharge_info->dw_account_id;
		strncpy(send_res.sz_account_name, p_recharge_info->sz_account_name, X_SHORT_NAME);
		strncpy(send_res.sz_trade_code, p_recharge_info->sz_trade_code, X_SHORT_NAME);
		send_res.n_type = 1;
		m_web_manager.send_message(ID_WEBSERVER, &send_res, send_res.dw_size);*/

		SAFE_DELETE(p_recharge_info);
	}
}

VOID bill_server::update_serial()
{
	while(list_serial_reward.size() > 0)
	{
		tag_serial_reward_info* p_serial_info = list_serial_reward.pop_front();

		if(!VALID_POINT(p_serial_info))
			continue;

		m_web_manager.lock_serial_reward(p_serial_info->dw_world_crc);

		if(!m_web_manager.insert_serial_reward(p_serial_info->dw_account_id, p_serial_info->dw_world_crc, p_serial_info->sz_serial_reward, p_serial_info->n_type))
		{
			m_web_manager.unlock_tables(p_serial_info->dw_world_crc);

			SI_LOG->write_log(_T("id=%u type=%d serial=%s world=%u serial reward faild"), p_serial_info->dw_account_id, p_serial_info->n_type, 
				get_tool()->ansi_to_unicode(p_serial_info->sz_serial_reward), p_serial_info->dw_world_crc);
			continue;
		}

		m_web_manager.unlock_tables(p_serial_info->dw_world_crc);

		/*tagNBW_UpdateSerialReward send;
		send.dw_account_id = p_serial_info->dw_account_id;
		send.n_type = p_serial_info->n_type;
		strncpy(send.sz_serial, p_serial_info->sz_serial_reward, X_SHORT_NAME);
		g_billserver.get_world_manager().send_message(p_serial_info->dw_world_crc, &send, send.dw_size);*/

		SAFE_DELETE(p_serial_info);
	}
}

VOID bill_server::query_recharge_yuanbao(tag_web_recharge_info* p_recharge, INT32& n32_yuanbao)
{
	odbc::sql_language_disposal* pStream = p_db_interface->get_io();

	pStream->clear();

	pStream->select_item("ssplay_web", "fee");
	pStream->where_item();
	pStream->write_string("SsplayOrderNO='").write_string(p_recharge->sz_trade_code);
	pStream->write_string("'");

	odbc::execute_result* p_result = p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
	{
		n32_yuanbao = (*p_result)[0].get_int();
	}


	p_db_interface->return_io(pStream);
	p_db_interface->free_result_query(p_result);
}

BOOL bill_server::update_recharge_sign(tag_web_recharge_info* p_recharge)
{
	odbc::sql_language_disposal* pStream = p_db_interface->get_io();

	pStream->clear();

	pStream->update_item("ssplay_web");
	pStream->write_string("isTrans=1");
	pStream->where_item();
	pStream->write_string("SsplayOrderNO='").write_string(p_recharge->sz_trade_code);
	pStream->write_string("'");

	BOOL bRet = p_db_interface->sql_execute(pStream);

	p_db_interface->return_io(pStream);

	return bRet;
}

UINT bill_server::thread_work()
{
	DWORD dw_time = 0;

	_set_se_translator(serverdump::si_translation); 

	try
	{
		while(!b_end_update)
		{
			update_recharge();

			update_act();

			update_serial();

			update_media_act();

			dw_time = timeGetTime() - dw_time;

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

UINT bill_server::thread_update()
{
	DWORD dw_time = 0;

	_set_se_translator(serverdump::si_translation); 

	try
	{
		while( !b_end_update )
		{
			dw_time = timeGetTime();

			lock_update();

			//m_web_manager.update();

			m_world_manager.update();

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

UINT bill_server::static_thread_update(LPVOID p_data)
{
	ASSERT(VALID_POINT(p_data));
	bill_server* p_this = (bill_server*)p_data;
	return p_this->thread_update();
}

UINT bill_server::static_thread_word(LPVOID p_data)
{
	bill_server* p_this = (bill_server*)p_data;
	return p_this->thread_work();
}

VOID bill_server::update_memory_use()
{
	MEMORYSTATUS st_memory_status;
	st_memory_status.dwLength = sizeof(st_memory_status);
	GlobalMemoryStatus(&st_memory_status);

	dw_total_memory = st_memory_status.dwTotalPhys;
	dw_avail_memory = st_memory_status.dwAvailPhys;

	PROCESS_MEMORY_COUNTERS st_memory_counters;
	GetProcessMemoryInfo(GetCurrentProcess(), &st_memory_counters, sizeof(st_memory_counters));
}


bill_server g_billserver;
