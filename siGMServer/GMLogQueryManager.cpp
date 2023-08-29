#include "StdAfx.h"
#include "GMLogQueryManager.h"
#include "LogDB.h"

#define GMGAME_LOG _T("server_config\\gm\\querylog")

GMLogQueryManager::GMLogQueryManager(void)
{
	mIniFile = new file_system;
	mConfig = new file_container;
}

GMLogQueryManager::~GMLogQueryManager(void)
{
	SAFE_DELETE(mIniFile);
	SAFE_DELETE(mConfig);
}

BOOL GMLogQueryManager::Init()
{
	TCHAR szPath[MAX_PATH] = {0};
	if(!get_file_io_mgr()->get_ini_path(szPath, GMGAME_LOG)||
		!mConfig->load(mIniFile, szPath))
	{
		ErrMessage(_T("\n\nfatal error read server_config\\gm\\querylog.ini!!\n\n"));
		return FALSE;
	}

	m_pLoginLogDB = new LogDB;
	if(VALID_POINT(m_pLoginLogDB))
	{
		if(VALID_POINT(m_pLoginLogDB->get_db_interface()))
		{
			if(!m_pLoginLogDB->get_db_interface()->init_db(mConfig->get_string(_T("db_ip"), _T("accountdb")),
														   mConfig->get_string(_T("db_user"), _T("accountdb")),
														   mConfig->get_string(_T("db_password"), _T("accountdb")),
														   mConfig->get_string(_T("db_name"), _T("accountdb")),
														   mConfig->get_int(_T("db_port"), _T("accountdb"))))
			{
				ErrMessage(_T("\r\nfaile error init LoginLogDB\r\n"));
				return FALSE;
			}
		}
	}
	else
	{
		return FALSE;
	}

	INT	n_num = mConfig->get_int(_T("num"), _T("logdbnum"));

	for(INT i = 0; i < n_num; i++)
	{
		TCHAR sz_name[50];
		ZeroMemory(sz_name, sizeof(sz_name));
		_stprintf(sz_name, _T("gameserver%d"), i+1);

		LogDB* p_LogDB = new LogDB;
		if(VALID_POINT(p_LogDB))
		{
			if(!p_LogDB->get_db_interface()->init_db(mConfig->get_string(_T("db_ip"), sz_name),
				mConfig->get_string(_T("db_user"), sz_name),
				mConfig->get_string(_T("db_password"), sz_name),
				mConfig->get_string(_T("db_name"), sz_name),
				mConfig->get_int(_T("db_port"), sz_name)))
			{
				ErrMessage(_T("\r\nfaile error init %sDB\r\n"), sz_name);
				return FALSE;
			}

			DWORD dw_server_name_crc = get_tool()->crc32(mConfig->get_string(_T("server_name"), sz_name));

			m_map_game_log.add(dw_server_name_crc, p_LogDB);
		}
		else
		{
			return FALSE;
		}

		ZeroMemory(sz_name, sizeof(sz_name));
		_stprintf(sz_name, _T("gamelog%d"), i+1);

		p_LogDB = new LogDB;
		if(VALID_POINT(p_LogDB))
		{
			if(!p_LogDB->get_db_interface()->init_db(mConfig->get_string(_T("db_ip"), sz_name),
				mConfig->get_string(_T("db_user"), sz_name),
				mConfig->get_string(_T("db_password"), sz_name),
				mConfig->get_string(_T("db_name"), sz_name),
				mConfig->get_int(_T("db_port"), sz_name)))
			{
				ErrMessage(_T("\r\nfaile error init %sDB\r\n"), sz_name);
				return FALSE;
			}

			DWORD dw_server_name_crc = get_tool()->crc32(mConfig->get_string(_T("server_name"), sz_name));

			m_map_log.add(dw_server_name_crc, p_LogDB);
		}
		else
		{
			return FALSE;
		}
	}

	//3285686846
	
	return TRUE;
}

VOID GMLogQueryManager::query_role_name_info(DWORD dw_world_crc, DWORD dw_role_name_crc, tag_Role_Name_Info& st_role_name_info)
{
	ZeroMemory(&st_role_name_info, sizeof(st_role_name_info));

	LogDB* p_log_db = m_map_game_log.find(dw_world_crc);
	if(!VALID_POINT(p_log_db))
		return;

	DWORD dw_account_id = p_log_db->get_account_by_role_name(dw_role_name_crc);

	if(dw_account_id == INVALID_VALUE)
		return;
	BOOL bOL;
	m_pLoginLogDB->get_account_name_by_id(dw_account_id, st_role_name_info.sz_account_name, bOL);

	p_log_db->get_role_name_by_account_id(dw_account_id, st_role_name_info);
}

GMLogQueryManager g_LogQueryMgr;
