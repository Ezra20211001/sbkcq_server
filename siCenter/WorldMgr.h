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
*	@file		WorldMgr.h
*	@author		lc
*	@date		2011/03/16	initial
*	@version	0.0.1.0
*	@brief		游戏世界管理器
*/

#ifndef WORLDMGR
#define WORLDMGR

//#include "../common/JPGStreamGenerator/ValidationCodeImageCreator.h"


class WorldServer;

class WorldMgr
{
public:
	WorldMgr(void);
	~WorldMgr(void);

	BOOL		init();
	VOID		update();
	VOID		destroy();

	LPBYTE recv_message(DWORD dw_id_, DWORD& dw_message_size_, INT& n_recv_num_)	
	{ 
		return p_session->recv_msg(dw_id_, dw_message_size_, n_recv_num_); 
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


	WorldServer* get_world(DWORD dw_name_crc)	{ return map_world.find(dw_name_crc); }
	DWORD		  get_world_num()				{ return map_world.size();		}
	
	VOID productVerify(DWORD dwType, TCHAR* str, DWORD& dwParam, DWORD& dwAnswer);
	VOID productVerifyOne(TCHAR* str, DWORD& dwParam, DWORD& dwAnswer);
	VOID productVerifyTwo(TCHAR* str, DWORD& dwParam, DWORD& dwAnswer);
	VOID productVerifyThree(TCHAR* str, DWORD& dwParam, DWORD& dwAnswer);
private:

	VOID		register_net_message();
	VOID		unregister_net_message();


	DWORD		login_call_back(LPBYTE p_byte_, DWORD dw_size_);
	DWORD		logout_call_back(DWORD dw_param_);

	DWORD		handle_login(tag_net_message* p_message_, WorldServer* p_world_);
	DWORD		handle_verify_code(tag_net_message* p_message_, WorldServer* p_world_);

private:
	package_map<DWORD, WorldServer*>		map_world;			

	few_connect_server*			p_session;		
	memorysystem::MemPool*					p_memory_pool;	

	//CValidationCodeImageCreator m_oCreator;

};

#endif
