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
 *	@brief		封号管理
*/

struct tag_forbid_account_free
{
	DWORD dwStart;
	DWORD dwEnd;
	DWORD dw_account_id;
	DWORD dw_world_crc;
};

//gx add 2013.11.07 针对工作室
struct tag_forbid_account_studio
{
	DWORD dw_client_id;  
	DWORD dw_account_id;
	TCHAR sz_account[LONG_STRING]; 
	TCHAR sz_world[X_SHORT_NAME]; 
};
struct tag_kick_role_studio
{
	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szRoleName[X_SHORT_NAME];
};
//end
class GMForbidAccMgr
{
public:
	typedef std::vector<tag_forbid_account_studio> ACCOUNT_STU_VEC;
	typedef std::vector<tag_kick_role_studio> KICK_STU_VEC;
public:
	BOOL Init( );
	VOID Update( );
	VOID Destroy( );
	VOID Remove(DWORD dwAccountID);
	VOID AddNew(DWORD dwAccountID, DWORD world_crc);
public:
	VOID Update_studio();//专门伺候工作室 gx add 2013.11.07
	ACCOUNT_STU_VEC& get_account_studio() {return m_account_studio;}
	KICK_STU_VEC& get_kick_studio() {return m_kick_studio;}
private:
	BOOL LoadAllForbidAccount( );
	VOID FreeAccount(DWORD dwAccountID, DWORD world_crc);
private:
	odbc::db_interface* mAccountDB;
	package_map<DWORD, tag_forbid_account_free*> mForbids;
	ACCOUNT_STU_VEC m_account_studio;
	KICK_STU_VEC m_kick_studio;
};

extern GMForbidAccMgr g_GMForbidAccMgr;