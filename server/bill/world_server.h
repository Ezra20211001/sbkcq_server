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
*	@file		world_server.h
*	@author		lc
*	@date		2011/02/22	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef WORLD_SERVER
#define WORLD_SERVER

#include "bill_mutex.h"
#include "world_manager.h"


struct tag_world_data 
{
	BOOL			b_connect;					//! 游戏世界是否连接 
	TCHAR			sz_name[X_SHORT_NAME];	    //! 游戏世界名称
	DWORD			dw_name_crc;				//! 游戏世界名称crc
	INT				n_port;						//! 游戏世界端口
	DWORD			dw_ip;						//! 游戏世界ip
	DWORD			dw_world_id;				//! 游戏世界id

	tag_world_data()
	{
		ZeroMemory(this, sizeof(*this));
	}
};

class world_server
{
public:
	world_server(void);
	~world_server(void);

	BOOL			init(INT n_index_);
	VOID			update();
	VOID			destroy();

	BOOL			world_login();
	BOOL			world_logout();

	DWORD			get_id()				{ return data_.dw_name_crc; }
	
	DWORD			get_world_id()		{ return data_.dw_world_id; }
	
	LPCTSTR			get_name()			{ return data_.sz_name; }
	
	BOOL			is_connect()			{ return data_.b_connect; }

private:
	
	VOID			update_session();


private:

	tag_world_data				data_;

	DWORD							dw_time_;					
};
#endif

