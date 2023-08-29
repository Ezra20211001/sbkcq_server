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

#include "StdAfx.h"
#include "web_manager.h"
#include "bill_server.h"
#include "../common/ServerDefine/bill_message_client.h"
#include "../common/ServerDefine/bill_message_server.h"


web_manager::web_manager(void)
{
	p_session = new few_connect_server;
	p_iocp = new IOCP;
}

web_manager::~web_manager(void)
{
	SAFE_DELETE(p_session);
	SAFE_DELETE(p_iocp);
	MAP_DB::map_iter iter = m_map_interface.begin();
	db_interface* p_interface = NULL;
	while(m_map_interface.find_next(iter, p_interface))
	{
		if(VALID_POINT(p_interface))
		{
			SAFE_DELETE(p_interface);
		}
	}
	m_map_interface.clear();
}

BOOL web_manager::init()
{

	dw_web_glod_code = bill_server::p_var->get_dword(_T("code webgoldcode"));

	b_connect = FALSE;

	INT n_world_num = bill_server::p_var->get_dword(_T("num zone_server"));

	for(INT n = 0; n < n_world_num; ++n)
	{
		db_interface* p_interface = new db_interface;

		TCHAR sz_name[50];
		ZeroMemory(sz_name, sizeof(sz_name));
		_stprintf(sz_name, _T("zone%d"), n);

		if(!p_interface->init_db(bill_server::p_var->get_string(_T("host_name"), sz_name),
		bill_server::p_var->get_string(_T("user_name"), sz_name),
		bill_server::p_var->get_string(_T("password"), sz_name),
		bill_server::p_var->get_string(_T("db_name"), sz_name),
		bill_server::p_var->get_int(_T("port"), sz_name)))
		{
			SI_LOG->write_log(_T("\r\sz_name db init faild! \r\n"));
			return FALSE;
		}

		tstring str_world_name = bill_server::p_var->get_string(_T("name"), sz_name);
		if( str_world_name.empty() ) return FALSE;

		DWORD dw_name_crc =	get_tool()->crc32(str_world_name.c_str());

		m_map_interface.add(dw_name_crc, p_interface);
	}

	register_net_message();

	INT n_port = bill_server::p_var->get_int(_T("port"), _T("web_session"));
	/*p_session->init(fastdelegate::MakeDelegate(this, &web_manager::login_call_back),
		fastdelegate::MakeDelegate(this, &web_manager::logout_call_back), n_port);*/

	tag_server_config InitParam;
	InitParam.fn_login		=	fastdelegate::MakeDelegate(this, &web_manager::login_call_back);
	InitParam.fn_logout		=	fastdelegate::MakeDelegate(this, &web_manager::logout_call_back);
	InitParam.b_repeat_port	=	true;
	InitParam.n_port			=	n_port;

	p_iocp->init(InitParam);

	return TRUE;
}

VOID web_manager::update()
{
	LPBYTE	p_receive		=	NULL;
	DWORD	dw_size		=	0;
	INT		n_unrecv		=	0;
	DWORD	dw_time		=	0;

	p_receive = recv_message(ID_WEBSERVER, dw_size, n_unrecv);

	while( VALID_POINT(p_receive) )
	{
		handle_command((tag_net_message*)p_receive, dw_size, INVALID_VALUE);

		return_message(ID_WEBSERVER, p_receive);

		p_receive = recv_message(ID_WEBSERVER, dw_size, n_unrecv);
	}
}

VOID web_manager::destroy()
{
	//p_session->destory();

	p_iocp->destroy();
	unregister_net_message();
}


VOID web_manager::register_net_message()
{
	REGISTER_NET_MSG("Web2Bill_Login", web_manager, handle_login, _T(""));
}

VOID web_manager::unregister_net_message()
{
	UNREGISTER_NET_MSG("Web2Bill_Login", web_manager, handle_login);
}

UINT web_manager::login_call_back(tag_unit* pUnit, tag_login_param* pParam)
{
	tag_net_message* p_msg = (tag_net_message*)pUnit->p_buffer;

	DWORD dw_msg_type = 0;

	if(p_msg->dw_message_id == get_tool()->crc32("Web2Bill_Login"))
	{
		dw_msg_type = 1;
	}

	if(p_msg->dw_message_id == get_tool()->crc32("Web2Bill_reload_auto_paimai"))
	{
		dw_msg_type = 2;
	}

	if(dw_msg_type == 0)
		return INVALID_VALUE;

	if(dw_msg_type == 1)
	{
		tagWeb2Bill_Login* pCmd = (tagWeb2Bill_Login*)pUnit->p_buffer;

		g_billserver.lock_web_update();

		tagWeb2Bill_Login* p_receive = (tagWeb2Bill_Login*)pCmd;

		/*if(b_connect)
		{
		g_billserver.unlock_web_update();
		return INVALID_VALUE;
		}*/

		if(dw_web_glod_code != p_receive->dw_glod_code)
		{
			g_billserver.unlock_web_update();
			return INVALID_VALUE;
		}

		TCHAR buf[512]={0};
		MultiByteToWideChar(
			CP_UTF8,
			0,
			p_receive->sz_world_name,
			strlen(p_receive->sz_world_name),
			buf,
			512);
		tstring str(buf);

		DWORD dw_world_name_crc = get_tool()->crc32(str.c_str());
		world_server* p_world = g_billserver.get_world_manager().get_world(dw_world_name_crc);
		if(!VALID_POINT(p_world))
		{
			g_billserver.unlock_web_update();
			return INVALID_VALUE;
		}

		if(p_receive->n_type == 1)
		{
			tag_web_recharge_info* p_recharge_info = new tag_web_recharge_info;
			if(!VALID_POINT(p_recharge_info))
			{
				g_billserver.unlock_web_update();
				return INVALID_VALUE;
			}

			ZeroMemory(p_recharge_info, sizeof(p_recharge_info));
			p_recharge_info->dw_account_id = p_receive->dw_account_id;
			p_recharge_info->dw_world_crc = dw_world_name_crc;
			p_recharge_info->dw_recharge_num = p_receive->dw_recharge_num;

			strncpy(p_recharge_info->sz_trade_code, p_receive->sz_trade_code, X_SHORT_NAME);
			strncpy(p_recharge_info->sz_account_name, p_receive->sz_account_name, X_SHORT_NAME);

			g_billserver.get_list_recharge_info().push_back(p_recharge_info);

			//g_billserver.update_recharge();

			/*tagNBW_PickBaiBao send;
			send.dw_account_id = p_receive->dw_account_id;
			g_billserver.get_world_manager().send_message(dw_world_name_crc, &send, send.dw_size);*/
		}
		else if(p_receive->n_type == 2)
		{
			tag_web_act_info* p_web_act_info = new tag_web_act_info;
			if(!VALID_POINT(p_web_act_info))
			{
				g_billserver.unlock_web_update();
				return INVALID_VALUE;
			}

			ZeroMemory(p_web_act_info, sizeof(tag_web_act_info));
			p_web_act_info->dw_account_id = p_receive->dw_account_id;
			p_web_act_info->dw_world_crc = dw_world_name_crc;
			p_web_act_info->dw_web_type = p_receive->dw_receive_type;
			strncpy(p_web_act_info->sz_account_name, p_receive->sz_account_name, X_SHORT_NAME);

			g_billserver.get_list_act_info().push_back(p_web_act_info);

			//g_billserver.update_act();

			/*tagNBW_ChangeReceive send;
			send.dw_account_id = p_receive->dw_account_id;
			g_billserver.get_world_manager().send_message(dw_world_name_crc, &send, send.dw_size);*/
		}
		else if(p_receive->n_type == 3)
		{
			tag_serial_reward_info* p_serial_reward_info = new tag_serial_reward_info;
			if(!VALID_POINT(p_serial_reward_info))
			{
				g_billserver.unlock_web_update();
				return INVALID_VALUE;
			}
			ZeroMemory(p_serial_reward_info, sizeof(tag_serial_reward_info));
			p_serial_reward_info->dw_account_id = p_receive->dw_account_id;
			p_serial_reward_info->dw_world_crc = dw_world_name_crc;
			p_serial_reward_info->n_type = p_receive->n_serial_type;
			strncpy(p_serial_reward_info->sz_account_name, p_receive->sz_account_name, X_SHORT_NAME);
			strncpy(p_serial_reward_info->sz_serial_reward, p_receive->sz_serial_reward, X_SHORT_NAME);

			g_billserver.get_list_serial_reward().push_back(p_serial_reward_info);

			//g_billserver.update_serial();
		}
		else if(p_receive->n_type == 4)
		{
			tag_media_act_info* p_media_act_info = new tag_media_act_info;
			if(!VALID_POINT(p_media_act_info))
			{
				g_billserver.unlock_web_update();
				return INVALID_VALUE;
			}
			ZeroMemory(p_media_act_info, sizeof(tag_media_act_info));
			p_media_act_info->dw_account_id = p_receive->dw_account_id;
			p_media_act_info->dw_world_crc = dw_world_name_crc;
			p_media_act_info->dw_type = p_receive->dw_receive_type;
			strncpy(p_media_act_info->sz_account_name, p_receive->sz_account_name, X_SHORT_NAME);

			g_billserver.get_list_media_act().push_back(p_media_act_info);
		}

		//print_message(_T("web online\r\n"));
		g_billserver.unlock_web_update();
	}

	if(dw_msg_type == 2)
	{
		tagWeb2Bill_reload_auto_paimai* pCmd = (tagWeb2Bill_reload_auto_paimai*)pUnit->p_buffer;

		g_billserver.lock_web_update();

		tagWeb2Bill_reload_auto_paimai* p_receive = (tagWeb2Bill_reload_auto_paimai*)pCmd;

		/*if(b_connect)
		{
		g_billserver.unlock_web_update();
		return INVALID_VALUE;
		}*/

		if(dw_web_glod_code != p_receive->dw_glod_code)
		{
			g_billserver.unlock_web_update();
			return INVALID_VALUE;
		}

		TCHAR buf[512]={0};
		MultiByteToWideChar(
			CP_UTF8,
			0,
			p_receive->sz_world_name,
			strlen(p_receive->sz_world_name),
			buf,
			512);
		tstring str(buf);

		DWORD dw_world_name_crc = get_tool()->crc32(str.c_str());
		world_server* p_world = g_billserver.get_world_manager().get_world(dw_world_name_crc);
		if(!VALID_POINT(p_world))
		{
			g_billserver.unlock_web_update();
			return INVALID_VALUE;
		}

		tagNBW_ReloadAutoPaimai send;
		g_billserver.get_world_manager().send_message(dw_world_name_crc, &send, send.dw_size);
		
		g_billserver.unlock_web_update();
	}
	
	return INVALID_VALUE/*ID_WEBSERVER*/;
}

UINT web_manager::logout_call_back(DWORD dw_param_)
{
	/*g_billserver.lock_web_update();

	b_connect = FALSE;

	print_message(_T("web leave online\r\n"));

	g_billserver.unlock_web_update();*/

	return 0;
}

DWORD web_manager::handle_login(tag_net_message* p_message_, DWORD dw_param)
{
	//tagWeb2Bill_Login* p_receive = (tagWeb2Bill_Login*)p_message_;

	//TCHAR buf[512]={0};
	//MultiByteToWideChar(
	//	CP_UTF8,
	//	0,
	//	p_receive->sz_world_name,
	//	strlen(p_receive->sz_world_name),
	//	buf,
	//	512);
	//tstring str(buf);

	//DWORD dw_world_name_crc = get_tool()->crc32(str.c_str());
	//world_server* p_world = g_billserver.get_world_manager().get_world(dw_world_name_crc);
	//if(!VALID_POINT(p_world))
	//{
	//	g_billserver.unlock_web_update();
	//	return INVALID_VALUE;
	//}

	//if(p_receive->n_type == 1)
	//{
	//	tag_web_recharge_info* p_recharge_info = new tag_web_recharge_info;
	//	if(!VALID_POINT(p_recharge_info))
	//	{
	//		g_billserver.unlock_web_update();
	//		return INVALID_VALUE;
	//	}

	//	ZeroMemory(p_recharge_info, sizeof(p_recharge_info));
	//	p_recharge_info->dw_account_id = p_receive->dw_account_id;
	//	p_recharge_info->dw_world_crc = dw_world_name_crc;
	//	p_recharge_info->dw_recharge_num = p_receive->dw_recharge_num;

	//	strncpy(p_recharge_info->sz_trade_code, p_receive->sz_trade_code, X_SHORT_NAME);
	//	strncpy(p_recharge_info->sz_account_name, p_receive->sz_account_name, X_SHORT_NAME);

	//	g_billserver.get_list_recharge_info().push_back(p_recharge_info);

	//	g_billserver.update_recharge();

	//	/*tagNBW_PickBaiBao send;
	//	send.dw_account_id = p_receive->dw_account_id;
	//	g_billserver.get_world_manager().send_message(dw_world_name_crc, &send, send.dw_size);*/
	//}
	//else if(p_receive->n_type == 2)
	//{
	//	tag_web_act_info* p_web_act_info = new tag_web_act_info;
	//	if(!VALID_POINT(p_web_act_info))
	//	{
	//		g_billserver.unlock_web_update();
	//		return INVALID_VALUE;
	//	}

	//	ZeroMemory(p_web_act_info, sizeof(tag_web_act_info));
	//	p_web_act_info->dw_account_id = p_receive->dw_account_id;
	//	p_web_act_info->dw_world_crc = dw_world_name_crc;
	//	p_web_act_info->dw_web_type = p_receive->dw_receive_type;
	//	strncpy(p_web_act_info->sz_account_name, p_receive->sz_account_name, X_SHORT_NAME);

	//	g_billserver.get_list_act_info().push_back(p_web_act_info);

	//	g_billserver.update_act();

	//	/*tagNBW_ChangeReceive send;
	//	send.dw_account_id = p_receive->dw_account_id;
	//	g_billserver.get_world_manager().send_message(dw_world_name_crc, &send, send.dw_size);*/
	//}
	//else if(p_receive->n_type == 3)
	//{
	//	tag_serial_reward_info* p_serial_reward_info = new tag_serial_reward_info;
	//	if(!VALID_POINT(p_serial_reward_info))
	//	{
	//		g_billserver.unlock_web_update();
	//		return INVALID_VALUE;
	//	}
	//	ZeroMemory(p_serial_reward_info, sizeof(tag_serial_reward_info));
	//	p_serial_reward_info->dw_account_id = p_receive->dw_account_id;
	//	p_serial_reward_info->dw_world_crc = dw_world_name_crc;
	//	p_serial_reward_info->n_type = p_receive->n_serial_type;
	//	strncpy(p_serial_reward_info->sz_account_name, p_receive->sz_account_name, X_SHORT_NAME);
	//	strncpy(p_serial_reward_info->sz_serial_reward, p_receive->sz_serial_reward, X_SHORT_NAME);

	//	g_billserver.get_list_serial_reward().push_back(p_serial_reward_info);

	//	g_billserver.update_serial();
	//}

	//p_session->kick_connect(ID_WEBSERVER);

	return INVALID_VALUE;
}

// 更新元宝充值
BOOL web_manager::update_yuanbao_recharge(DWORD	dw_word_name_crc, DWORD	dw_account_id, DWORD	dw_yuanbao_num)
{
	BOOL bRet = TRUE;

	db_interface* p_db_interface = m_map_interface.find(dw_word_name_crc);
	if(!VALID_POINT(p_db_interface))
		return FALSE;

	odbc::sql_language_disposal* pStream = p_db_interface->get_io();

	pStream->clear();

	pStream->update_item("account_common");
	pStream->write_string("yuanbao_recharge=yuanbao_recharge+") << dw_yuanbao_num;
	pStream->where_item();
	pStream->write_string("account_id=") << dw_account_id;
	

	bRet = p_db_interface->sql_execute(pStream);

	p_db_interface->return_io(pStream);

	return bRet;
}

// 检查账号是否存在记录
BOOL web_manager::check_account_common(DWORD	dw_account_id, DWORD	dw_world_name_crc)
{
	BOOL bRet = TRUE;

	db_interface* p_db_interface = m_map_interface.find(dw_world_name_crc);
	if(!VALID_POINT(p_db_interface))
		return FALSE;

	odbc::sql_language_disposal* pStream = p_db_interface->get_io();

	pStream->clear();

	pStream->select_item("account_common", "account_id");
	pStream->where_item();
	pStream->write_string("account_id=") << dw_account_id;

	execute_result* p_result = p_db_interface->sql_query(pStream);

	if(!VALID_POINT(p_result) || p_result->get_row_count() <= 0) return FALSE;

	p_db_interface->return_io(pStream);
	p_db_interface->free_result_query(p_result);

	return bRet;
}

// 插入序列号礼包
BOOL web_manager::insert_serial_reward(DWORD dw_account_id, DWORD dw_world_name_crc, LPSTR sz_serial, INT n_type)
{
	BOOL bRet = TRUE;

	db_interface* p_db_interface = m_map_interface.find(dw_world_name_crc);
	if(!VALID_POINT(p_db_interface))
		return FALSE;

	odbc::sql_language_disposal* pStream = p_db_interface->get_io();
	odbc::tag_mysql_connect* pCon = p_db_interface->get_idlesse_connect();

	pStream->clear();

	pStream->insert_item("serial_reward");
	//pStream->write_string("account_id=") << dw_account_id;
	pStream->write_string("serial='").write_string(sz_serial, pCon).write_string("'");
	pStream->write_string(",type=") << n_type;

	bRet = p_db_interface->sql_execute(pStream);

	p_db_interface->return_use_connect(pCon);
	p_db_interface->return_io(pStream);

	return bRet;
}

// 插入账号共用数据
BOOL web_manager::insert_account_common(DWORD	dw_account_id, DWORD	dw_word_name_crc, LPSTR sz_account_name)
{
	BOOL bRet = TRUE;

	db_interface* p_db_interface = m_map_interface.find(dw_word_name_crc);
	if(!VALID_POINT(p_db_interface))
		return FALSE;

	odbc::sql_language_disposal* pStream = p_db_interface->get_io();
	odbc::tag_mysql_connect* pCon = p_db_interface->get_idlesse_connect();

	pStream->clear();

	pStream->insert_item("account_common");
	pStream->write_string("account_id=") << dw_account_id;
	pStream->write_string(",account_name='").write_string(sz_account_name, pCon).write_string("'");
	
	bRet = p_db_interface->sql_execute(pStream);

	p_db_interface->return_use_connect(pCon);
	p_db_interface->return_io(pStream);

	return bRet;
}

// 写入元宝充值log
BOOL web_manager::insert_yuanbao_log(DWORD	dw_account_id, DWORD	dw_yuanbao_num, DWORD dw_world_name_crc, LPSTR sz_trade_code)
{
	BOOL bRet = TRUE;

	db_interface* p_db_interface = m_map_interface.find(dw_world_name_crc);
	if(!VALID_POINT(p_db_interface))
		return FALSE;

	odbc::sql_language_disposal* pStream = p_db_interface->get_io();
	odbc::tag_mysql_connect* pCon = p_db_interface->get_idlesse_connect();

	pStream->clear();

	pStream->insert_item("bill_yuanbao_log");
	pStream->write_string("account_id=") << dw_account_id;
	pStream->write_string(",token_id='").write_string(sz_trade_code, pCon).write_string("'");
	pStream->write_string(",yuanbao=") << dw_yuanbao_num;
	pStream->write_string(",time=now()");

	bRet = p_db_interface->sql_execute(pStream);

	p_db_interface->return_use_connect(pCon);
	p_db_interface->return_io(pStream);

	return bRet;
}

// 更新活动标志
BOOL web_manager::update_receive_type(DWORD dw_account_id, DWORD dw_world_name_crc, DWORD	dw_receive_type)
{
	BOOL bRet = TRUE;

	db_interface* p_db_interface = m_map_interface.find(dw_world_name_crc);
	if(!VALID_POINT(p_db_interface))
		return FALSE;

	odbc::sql_language_disposal* pStream = p_db_interface->get_io();

	pStream->clear();

	pStream->update_item("account_common");
	pStream->write_string("web_type = web_type | ") << dw_receive_type;
	pStream->where_item();
	pStream->write_string("account_id=") << dw_account_id;


	bRet = p_db_interface->sql_execute(pStream);

	p_db_interface->return_io(pStream);

	return bRet;
}

// 更新媒体礼包标志
BOOL web_manager::update_media_receive_type(DWORD dw_account_id, DWORD dw_world_name_crc, DWORD	dw_receive_type)
{
	BOOL bRet = TRUE;

	db_interface* p_db_interface = m_map_interface.find(dw_world_name_crc);
	if(!VALID_POINT(p_db_interface))
		return FALSE;

	odbc::sql_language_disposal* pStream = p_db_interface->get_io();

	pStream->clear();

	pStream->update_item("account_common");
	pStream->write_string("receive_type = ") << dw_receive_type;
	pStream->write_string(",IsReceive=0");
	pStream->where_item();
	pStream->write_string("account_id=") << dw_account_id;

	bRet = p_db_interface->sql_execute(pStream);

	p_db_interface->return_io(pStream);

	return bRet;
}

BOOL web_manager::lock_serial_reward(DWORD	dw_world_name_crc)
{
	BOOL bRet = TRUE;

	db_interface* p_db_interface = m_map_interface.find(dw_world_name_crc);
	if(!VALID_POINT(p_db_interface))
		return FALSE;

	odbc::sql_language_disposal* pStream = p_db_interface->get_io();

	pStream->clear();

	pStream->write_string("Lock Tables ");
	pStream->write_string("serial_reward");
	pStream->write_string(" WRITE");

	bRet = p_db_interface->sql_execute(pStream);

	p_db_interface->return_io(pStream);

	return bRet;
}

BOOL web_manager::lock_account_common(DWORD	dw_world_name_crc)
{
	BOOL bRet = TRUE;

	db_interface* p_db_interface = m_map_interface.find(dw_world_name_crc);
	if(!VALID_POINT(p_db_interface))
		return FALSE;

	odbc::sql_language_disposal* pStream = p_db_interface->get_io();

	pStream->clear();

	pStream->write_string("Lock Tables ");
	pStream->write_string("account_common");
	pStream->write_string(" WRITE");

	bRet = p_db_interface->sql_execute(pStream);

	p_db_interface->return_io(pStream);

	return bRet;
}

BOOL web_manager::unlock_tables(DWORD	dw_world_name_crc)
{
	BOOL bRet = TRUE;

	db_interface* p_db_interface = m_map_interface.find(dw_world_name_crc);
	if(!VALID_POINT(p_db_interface))
		return FALSE;

	odbc::sql_language_disposal* pStream = p_db_interface->get_io();

	pStream->clear();

	pStream->write_string("Unlock Tables");

	bRet = p_db_interface->sql_execute(pStream);

	p_db_interface->return_io(pStream);

	return bRet;
}
