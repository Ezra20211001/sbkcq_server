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
*	@file		web_manager.h
*	@author		lc
*	@date		2011/02/22	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef WEB_MANAGER
#define WEB_MANAGER

#include "bill_mutex.h"

#define ID_WEBSERVER 1

typedef package_map<DWORD, db_interface*>	MAP_DB;

class web_manager
{
public:
	web_manager(void);
	~web_manager(void);

	BOOL		init();
	VOID		update();
	VOID		destroy();

	LPBYTE recv_message(DWORD dw_id_, DWORD& dw_message_size_, INT& n_message_num_)
	{
		return p_session->recv_msg(dw_id_, dw_message_size_, n_message_num_); 
	}

	VOID return_message(DWORD dw_id_, LPBYTE p_message_)	
	{ 
		p_session->free_recv_msg(dw_id_, p_message_); 
	}

	VOID send_message(DWORD dw_id_, LPVOID p_message_, DWORD dw_size_)
	{ 
		p_session->send_msg(dw_id_, p_message_, dw_size_); 
	}
	
	VOID handle_command(LPVOID p_message_, DWORD dw_size_, DWORD dw_param_)
	{ 
		serverframe::net_command_manager::get_singleton().handle_message((tag_net_message*)p_message_, dw_size_, dw_param_); 
	}

	BOOL	check_account_common(DWORD	dw_account_id, DWORD	dw_world_name_crc);
	BOOL	insert_account_common(DWORD	dw_account_id, DWORD	dw_word_name_crc, LPSTR sz_account_name);
	BOOL	update_yuanbao_recharge(DWORD	dw_word_name_crc, DWORD	dw_account_id, DWORD	dw_yuanbao_num);
	BOOL	insert_yuanbao_log(DWORD	dw_account_id, DWORD	dw_yuanbao_num, DWORD dw_world_name_crc, LPSTR sz_trade_code);
	BOOL	insert_serial_reward(DWORD dw_account_id, DWORD dw_world_name_crc, LPSTR sz_serial, INT n_type);

	BOOL	update_receive_type(DWORD dw_account_id, DWORD dw_world_name_crc, DWORD	dw_receive_type);
	BOOL	update_media_receive_type(DWORD dw_account_id, DWORD dw_world_name_crc, DWORD	dw_receive_type);

	BOOL	lock_account_common(DWORD	dw_world_name_crc);
	BOOL	unlock_tables(DWORD	dw_world_name_crc);

	BOOL	lock_serial_reward(DWORD	dw_world_name_crc);


private:
	
	VOID		register_net_message();
	VOID		unregister_net_message();

	
	UINT		login_call_back(tag_unit* pUnit, tag_login_param* pParam);
	UINT		logout_call_back(DWORD dw_param_);

	DWORD		handle_login(tag_net_message* p_message_, DWORD dw_param);

private:

	few_connect_server*			p_session;		

	IOCP*						p_iocp;

	DWORD							dw_web_glod_code;			

	BOOL							b_connect;		

	MAP_DB					m_map_interface;
};
#endif
