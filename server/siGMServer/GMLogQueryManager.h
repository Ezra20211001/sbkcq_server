#ifndef GMLOGQUERY
#define GMLOGQUERY

#include "../../common/WorldDefine/GMDefine.h"

class LogDB;

typedef package_map<DWORD, LogDB*> MAP_GAMELOG;
typedef package_map<DWORD, LogDB*> MAP_LOG;

class GMLogQueryManager
{
public:
	GMLogQueryManager(void);
	~GMLogQueryManager(void);

	BOOL	Init();

	LogDB* GetLoginLogDB() { if(VALID_POINT(m_pLoginLogDB)) return m_pLoginLogDB; return NULL;}

	MAP_GAMELOG&	GetGameLog() { return m_map_game_log; }
	MAP_GAMELOG&	GetLog() { return m_map_log; }

	// 查询角色名称和账号名称
	VOID	query_role_name_info(DWORD dw_world_crc, DWORD dw_role_name_crc, tag_Role_Name_Info& st_role_name_info);
public:
	LogDB* GetGameDB(DWORD dw_world_crc){ return m_map_game_log.find(dw_world_crc);}
	LogDB* GetLogDB(DWORD dw_world_crc){ return m_map_log.find(dw_world_crc);}
	LogDB* GetAccountDB(){ return m_pLoginLogDB; }
private:
	LogDB* m_pLoginLogDB;
	MAP_GAMELOG		m_map_game_log;
	MAP_GAMELOG		m_map_log;

	file_system* mIniFile;
	file_container* mConfig;
};

extern GMLogQueryManager g_LogQueryMgr;

#endif
