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
 *	@file		GMForibAccMgr
 *	@author		mwh
 *	@date		2011/12/06	initial
 *	@version	0.0.1.0
 *	@brief		
*/

#include "stdafx.h"
#include "GMLogQueryManager.h"
#include "LogDB.h"
#include "ServerPlayer.h"
#include "ServerPlayerManager.h"
//#include "GMForibAccMgr.h"

#include "../common/ServerDefine/GMServerMessage.h"

GMForbidAccMgr g_GMForbidAccMgr;

BOOL GMForbidAccMgr::Init( )
{
	mAccountDB = g_LogQueryMgr.GetAccountDB( )->get_db_interface( );
	return VALID_POINT(mAccountDB) && LoadAllForbidAccount( );
}

VOID GMForbidAccMgr::Update( )
{
	static  unsigned sUPTICK = 0;
	if( (++sUPTICK % (TICK_PER_SECOND * 600)))
		return;

	DWORD dwCurTime = GetCurrentDWORDTime( );
	tag_forbid_account_free* p ; mForbids.reset_iterator();
	while(mForbids.find_next(p))
	{
		if(p->dwEnd <= dwCurTime)
		{
			FreeAccount(p->dw_account_id, p->dw_world_crc);
			mForbids.erase(p->dw_account_id);
			SAFE_DELETE(p);
		}
	}
}

VOID GMForbidAccMgr::Destroy( )
{
	tag_forbid_account_free* p ; mForbids.reset_iterator();
	while(mForbids.find_next(p)) delete p;
	mForbids.clear( );
}

VOID GMForbidAccMgr::AddNew(DWORD dwAccountID, DWORD world_crc)
{
	odbc::sql_language_disposal* p_stream = mAccountDB->get_io();
	p_stream->select_item("world_forbid", "account_id, forbid_start, forbid_end,world_name_crc");
	p_stream->where_item();
	p_stream->write_string("account_id=")  << dwAccountID;
	p_stream->write_string(" AND world_name_crc=")  << world_crc;
	odbc::execute_result* pResult = mAccountDB->sql_query(p_stream);
	mAccountDB->return_io(p_stream);


	if(!VALID_POINT(pResult))return ;
	if(pResult->get_row_count( ))
	{
		DWORD dwID = (*pResult)[0].get_dword( );
		if(!mForbids.is_exist(dwID))
		{
			tag_forbid_account_free* p = new tag_forbid_account_free;
			if(!VALID_POINT(p)) return ;
			p->dw_account_id = (*pResult)[0].get_dword( );
			p->dwStart = (*pResult)[1].get_dword( );
			p->dwEnd = (*pResult)[2].get_dword( );
			p->dw_world_crc = (*pResult)[3].get_dword( );
			mForbids.add(dwID, p);
		}
	}

	mAccountDB->free_result_query(pResult);
}

VOID GMForbidAccMgr::Remove(DWORD dwAccountID)
{
	tag_forbid_account_free* p = mForbids.find(dwAccountID);
	if(VALID_POINT(p))
	{
		mForbids.erase(p->dw_account_id);
		SAFE_DELETE(p);
	}
}

BOOL GMForbidAccMgr::LoadAllForbidAccount( )
{
	LogDB* pAccountDB = g_LogQueryMgr.GetAccountDB( );
	if(!VALID_POINT(pAccountDB)) return FALSE;

	odbc::sql_language_disposal* p_stream = mAccountDB->get_io();
	p_stream->select_item("world_forbid", "account_id, forbid_start, forbid_end,world_name_crc");
	odbc::execute_result* pResult = mAccountDB->sql_query(p_stream);
	mAccountDB->return_io(p_stream);

	if(!VALID_POINT(pResult))return FALSE;

	if(pResult->get_row_count( ))
	{
		for(int n = 0; n < pResult->get_row_count(); ++n, pResult->next_row( ))
		{
			DWORD dwID = (*pResult)[0].get_dword( );
			if(mForbids.is_exist(dwID)) continue;

			tag_forbid_account_free* p = new tag_forbid_account_free;
			if(!VALID_POINT(p)) return FALSE;
			p->dw_account_id = (*pResult)[0].get_dword( );
			p->dwStart = (*pResult)[1].get_dword( );
			p->dwEnd = (*pResult)[2].get_dword( );
			p->dw_world_crc = (*pResult)[3].get_dword( );
			mForbids.add(dwID, p);
		}
	}

	mAccountDB->free_result_query(pResult);
	return TRUE;
}


VOID GMForbidAccMgr::FreeAccount(DWORD dwAccountID, DWORD world_crc)
{
	LogDB* pAccountDB = g_LogQueryMgr.GetAccountDB( );
	if(!VALID_POINT(pAccountDB)) return;

	ServerPlayer* pServer = g_ServerPlayerMgr.GetGameServerPlayer(world_crc);
	if(!VALID_POINT(pServer)) return;

	NET_GMS2S_forbid_account send; BOOL bOL;
	pAccountDB->get_account_name_by_id(dwAccountID, send.sz_account, bOL);

	send.b_forbid = FALSE;
	send.dw_client_id = 0;
	_tcscpy(send.sz_world, pServer->GetName( ));
	g_ServerPlayerMgr.SendLoginServerMsg(&send, send.dw_size);
}
//批量封号，踢人
VOID GMForbidAccMgr::Update_studio()
{
	int count = 0;
	ACCOUNT_STU_VEC::iterator iter_account = m_account_studio.begin();
	for (;iter_account != m_account_studio.end();)
	{
		if (count > 5)
		{
			break;//一次发5个
		}
		count++;
		NET_GMS2S_forbid_account send;
		send.b_forbid = TRUE;
		send.dw_client_id = iter_account->dw_client_id;
		_tcscpy(send.sz_account, iter_account->sz_account);
		_tcscpy(send.sz_world, iter_account->sz_world);
		send.dwTimeStart = GetCurrentDWORDTime( );
		send.dwTimeEnd = 0xFFFFFFFF;//永久封号
		g_ServerPlayerMgr.SendLoginServerMsg(&send, send.dw_size);
		iter_account = m_account_studio.erase(iter_account);
	}

	count = 0;

	KICK_STU_VEC::iterator iter_kick = m_kick_studio.begin();
	for (;iter_kick != m_kick_studio.end();)
	{
		if (count > 5)
		{
			break;//一次发5个
		}
		count++;
		ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(iter_kick->szServerName));
		if(VALID_POINT(pServerPlayer))
		{
			NET_GMS2S_Kick send;
			_tcsncpy(send.szRoleName, iter_kick->szRoleName, X_SHORT_NAME);
			pServerPlayer->SendMessage(&send, send.dw_size);
		}
		iter_kick = m_kick_studio.erase(iter_kick);
	}
}
