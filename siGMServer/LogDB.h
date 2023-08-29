#ifndef LOGDB
#define LOGDB
#include "../common/WorldDefine/GMDefine.h"
#include "GMForibAccMgr.h"
/*
* ��Ҫ����common_query_function������API������Ҫע�����������:

@! ����:
	VOID get_forbid_talk_list(const char* table_name, VOID*& out, ....);
	struct NET_GMS2C_GetForbidTalkRoleList{ X stData[1];}
@! ����ʹ�ã�
	NET_GMS2C_GetForbidTalkRoleList send;
	pDB->get_forbid_talk_list(table_name, (VOID*&)send.stData, ...);
	API�β�Ϊһ��VOID*& ��ʵ��Ϊ(VOID*&)send.stData,����ʹ�û���ִ���ڴ���
@! ��ȷʹ��:
	NET_GMS2C_GetForbidTalkRoleList send;
	VOID* p = send.stData;
	pDB->get_forbid_talk_list(table_name, p, ...);
*/

//-----------------------------------------------------------------------------
// log����������ö��
//-----------------------------------------------------------------------------
 enum ELogConType
 {
 	ELCT_Null		= 0,
 
 	ELCT_Bag		= 1,	// ����
 	ELCT_RoleWare	= 2,	// ��ɫ�ֿ�
 	ELCT_BaiBao		= 3,	// �ٱ���
 	ELCT_BagBind	= 4,	// ������
 };


typedef fastdelegate::FastDelegate4<const char*, odbc::sql_language_disposal*, DWORD, DWORD, VOID> func_select_set_item;
typedef fastdelegate::FastDelegate4<odbc::execute_result*, VOID*&, DWORD&, INT&, VOID> func_proc_res;
typedef fastdelegate::FastDelegate5<const char*, odbc::sql_language_disposal*, VOID*, DWORD, DWORD, VOID> func_update_set_item;

class LogDB
{
private:
	db_interface* m_p_db_interface;
public:
	LogDB(void);
	~LogDB(void);

public:
	db_interface* get_db_interface() { if(VALID_POINT(m_p_db_interface)) return m_p_db_interface; return NULL; }

	// ͨ����ɫ����crc��ȡ�˺�id
	DWORD	get_account_by_role_name(DWORD	dw_role_name_crc);

	// ͨ����ɫ���ƻ�ȡ��ɫID gx add 2013.11.05
	DWORD   get_roleid_by_role_name(DWORD dw_role_name_crc);

	// ͨ����ɫid��ȡ�˺�ID
	DWORD	get_account_by_role_id(DWORD dw_role_id);

	// ͨ���˺�id��ȡ�˺�����
	VOID	get_account_name_by_id(DWORD account_id, TCHAR* sz_account_name, BOOL& AccOL);

	// ͨ��account_id��õ�����ƽ̨�˺�ID��ƽ̨����
	VOID	get_third_data_by_account_id(DWORD account_id,DWORD& dwthirdID,INT& nthirdType);

	// ͨ���˺�id��ȡ��ɫ����
	VOID	get_role_name_by_account_id(DWORD account_id, tag_Role_Name_Info& st_role_name_info);

	// ��ѯ����ɾ���б�
	VOID	get_role_del_list(DWORD dw_account_id, tag_Role_Del_List& st_role_del_list);

	// ��ɫ�������ִ�
	BOOL	role_go_home(DWORD	dw_role_id);

	// ��ԭɾ���Ľ�ɫ
	BOOL	revover_role(DWORD	dw_role_name_crc);

	// ͨ���˺����ƻ�ȡ�˺�ID
	BOOL get_account_id_by_account_name(TCHAR* sz_account_name, DWORD& dwID, BOOL& AccOL);

	// ͨ��������ƽ̨�˺�ID��ȡaccount_id gx add 2013.11.05
	BOOL get_account_id_by_third_account_id(DWORD dwthirdID,INT nthird_type,DWORD& dwaccountID);

	// ��ѯ�����ɫ�б�
	VOID get_role_list(DWORD account_id, tag_role_sim_info* _out, int _out_size);

	// ��ѯ��������
	VOID get_role_full_data(DWORD dw_role, VOID* out);

	BOOL is_gm_account(DWORD dw_account_id);

	// ��ɫԪ��
	DWORD get_account_yuanbao(DWORD dw_account_id);

	// ��ɫ��ֵԪ������ gx add 2013.11.05
	DWORD get_account_totalrecharge(DWORD dw_account_id);

	// ��ѯgm����ID
	DWORD get_gm_tool_account_id(db_interface* pGMDB, TCHAR* sz_gm_account);

	// ��ѯ�������
	DWORD get_guild_member_number(DWORD dw_guild_id);

	// ��ѯ��Ʒ����
	DWORD get_item_number(DWORD dw_data_id);  

	BOOL verify_gdquest_data(DWORD dw_role_id);

	VOID get_role_basic(const char* table_name, VOID* out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
private:
	VOID func_get_role_basic(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_role_basic(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
private:
	VOID get_role_skill(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID func_get_role_skill(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_role_skill(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
private:
	VOID get_role_pet(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID func_get_role_pet(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_role_pet(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
private:
	VOID get_role_pet_skill(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID func_get_role_pet_skill(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_role_pet_skill(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
private:
	VOID get_role_item(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID func_get_role_item(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_role_item(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
public:
	VOID get_item_log(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID get_money_log(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID get_exploits_log(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID get_yuanbao_log(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID get_item_log_by_serial(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID get_bank_log(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID get_paimai_log(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
private:
	//! item log
	VOID func_set_item_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_item_log(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
	//! item 
	VOID func_set_item_log_serial(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	//! money log
	VOID func_set_money_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_money_log(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
	//! exploits log
	VOID func_set_exploits_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_exploits_log(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
	//! yuanbao log
	VOID func_set_yuanbao_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_yuanbao_log(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
	//! bank log
	VOID func_set_bank_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_bank_log(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
	//! paimai log
	VOID func_set_paimai_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_paimai_log(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
private:
	//! ��ѯĳһ���ĳһ���͵�LOG
	VOID common_query_function(const char* _table_name, func_select_set_item func_set, func_proc_res func_proc, 
		VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dw_size, INT& nNumber);

	VOID common_query_function(db_interface* p_interface, const char* _table_name, func_select_set_item func_set, func_proc_res func_proc, 
		VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dw_size, INT& nNumber);

	//! �������ݿ�
	DWORD common_update_function(const char* table_name, func_update_set_item func_set, void* in,  
		DWORD dw_account, DWORD dw_role, int nCount, int nSzOne);

	DWORD common_update_function(db_interface* p_interface, const char* table_name, func_update_set_item func_set, void* in, 
		DWORD dw_account, DWORD dw_role, int nCount, int nSzOne);
public:
	//! ����
	VOID get_forbid_talk_list(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
private:
	VOID func_set_forbid_talk_list(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_forbid_talk_list(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
	//! ���
public:
	VOID get_forbid_account_list(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
private:
	VOID func_set_forbid_account_list(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_forbid_account_list(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
	//! gm tool
public:
	VOID func_get_invalid_ip_section(std::vector<tag_Invalid_IP>& ip_vec,INT ip_num,TCHAR* sz_trust_ip);
	//����һ��IP�õ���֮��ص����е�account_name gx add 2013.11.07
	VOID func_get_account_name_by_ip(GMForbidAccMgr::ACCOUNT_STU_VEC& _vec,TCHAR* ipname,TCHAR* servername,DWORD dwclient_id);
	//����һ��account_name�õ����Ӧ������role_name
	VOID fun_get_rolename_by_accountname(GMForbidAccMgr::KICK_STU_VEC& _vec,DWORD dwaccount_id,TCHAR* servername);
public:
	VOID get_gm_log(db_interface* pGMDB, const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
private:
	VOID func_set_gm_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
	
	//! ���
public:
	VOID get_guild_basic_list(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID get_guild_data(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID get_guild_build(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
	VOID get_guild_member(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber);
private:
	VOID func_set_guild_basic_list(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_guild_basic_list(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
	VOID func_set_guild_data(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_guild_data(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
	VOID func_set_guild_build(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_guild_build(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
	VOID func_set_guild_member(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role);
	VOID func_proc_res_guild_member(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber);
//=================================================
//	GM Edit Tool Save ||
//=================================================
public:
	DWORD save_role_basic(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne);
	DWORD save_account_yuanbao(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role);
	DWORD save_role_skill(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne);
	DWORD save_role_pet(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne);
	DWORD save_role_pet_skill(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne);
	DWORD save_role_equip(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne);
	BOOL delete_role_item(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne);
	BOOL delete_role_equip(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne);
	BOOL delete_role_pet(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne);
	BOOL delete_role_skill(const char* table_name, VOID* in, DWORD dw_account, DWORD dw_role, int nCount, int nSzOne);
private:
	VOID func_set_save_role_basic(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role);
	VOID func_set_save_account_yuanbao(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role);
	VOID func_set_save_role_skill(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role);
	VOID func_set_save_pet_basic(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role);
	VOID func_set_save_pet_skill(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role);
	VOID func_set_delete_pet_skill(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role);
	VOID func_set_save_role_equip(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role);
	VOID func_set_save_role_equip_bind(const char* table_name, odbc::sql_language_disposal* p_stream, VOID* in, DWORD dw_account, DWORD dw_role);
};
#endif
