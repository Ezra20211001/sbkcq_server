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
*	@file		db_interface.h
*	@author		lc
*	@date		2011/01/20	initial
*	@version	0.0.1.0
*	@brief		
*/

//db_interface �ṩ���ݿⴴ����ά������ѯ�����»���
// �Ե�һ���ݿ��ṩ�����߻��ƣ�������̵߳���
// �ṩ����ʽ���ص�ʽ���޷��ز���

#ifndef DB_INTERFACE
#define DB_INTERFACE

#include "StdAfx.h"
#include "mutex.h"
#include "sql_language_disposal.h"
#include "io_safe_queue.h"
#include "io_pool.h"
#include "execute_result.h"

namespace odbc {

class mutex;
class execute_result;
class sql_language_disposal;

class db_interface;

typedef void (win_api* alarm_call_back)(db_interface*, INT nReason, INT nParam);
UINT win_api asynchronism_query_thread(void* p);
UINT win_api check_thread(void* p);


const INT asynchronism_queue_max_num = 1000;		// �첽�������ֵ
const INT sql_language_max_num = 20000;				// sql�����������

struct odbc_api tag_mysql_connect
{
	mutex		_mutex;	// ������
	mysql*		_mysql;

	tag_mysql_connect();
};

class odbc_api db_interface
{
public:
	typedef enum			
	{
		EOE_System,			// mysql����error
		EOE_QueueFull,		// ���ݿ�����
		EOE_PoolFull,		// sql������
	} E_odbc_error;
public:
	db_interface();
	virtual ~db_interface();

	void set_alarm_call_back(alarm_call_back fn_alarm_) { fn_alarm = fn_alarm_; }

	//---------------------------------------------------------------------------
	// �������ݿ�����
	//---------------------------------------------------------------------------
	BOOL init_db(LPCTSTR str_host_, LPCTSTR str_user_, LPCTSTR str_password_, LPCTSTR str_db_name, INT n_port_, INT n_connect_num_=2);
	
	//---------------------------------------------------------------------------
	// ����
	//---------------------------------------------------------------------------
	void shut_down();

	//---------------------------------------------------------------------------
	// ��ȡ���ݿ�����
	//---------------------------------------------------------------------------
	inline tag_mysql_connect* get_idlesse_connect();

	//---------------------------------------------------------------------------
	// �ͷ����ݿ�����
	//---------------------------------------------------------------------------
	inline void return_use_connect(tag_mysql_connect* con);

	//---------------------------------------------------------------------------
	// �������ݿ�
	//---------------------------------------------------------------------------
	BOOL reset_connect();

	//---------------------------------------------------------------------------
	//  ���ݿ������Ƿ�Ͽ�
	//---------------------------------------------------------------------------
	inline BOOL is_disconnect()		{ return b_connect_lost; }


	//---------------------------------------------------------------------------
	// io���
	//---------------------------------------------------------------------------
	inline sql_language_disposal* get_io() { return _io_pool.alloc_io(); }
	inline void return_io(sql_language_disposal* pStream) { _io_pool.free_io(pStream); }

	//----------------------------------------------------------------------------
	// ��ѯ
	//----------------------------------------------------------------------------
	inline execute_result* sql_query(const char* sz_content_);
	inline execute_result* sql_query(const sql_language_disposal* p_io_);

	//----------------------------------------------------------------------------
	// ����ʽ��ѯ
	//----------------------------------------------------------------------------
	inline execute_result* sql_block_query(const char* sz_content_, tag_mysql_connect* p_connect_);
	inline execute_result* sql_block_query(const sql_language_disposal* p_io_, tag_mysql_connect* p_connect_);

	//-----------------------------------------------------------------------------
	// ִ��
	//-----------------------------------------------------------------------------
	inline BOOL sql_execute(const char* sz_content_);
	inline BOOL sql_execute(const sql_language_disposal* p_io_);

	//-----------------------------------------------------------------------------
	// ����ʽִ��
	//-----------------------------------------------------------------------------
	inline BOOL sql_block_execute(const char* sz_content_, tag_mysql_connect* p_connect_);
	inline BOOL sql_block_execute(const sql_language_disposal* p_io_, tag_mysql_connect* p_connect_);

	//-----------------------------------------------------------------------------
	// ִ�в������
	//-----------------------------------------------------------------------------
	inline INT sql_execute_check(const char* sz_content_);
	inline INT sql_execute_check(const sql_language_disposal* pStream);
	inline INT sql_block_execute_check(const char* sz_content_, tag_mysql_connect* p_connect_);
	inline INT sql_block_execute_check(const sql_language_disposal* p_io_, tag_mysql_connect* p_connect_);

	//------------------------------------------------------------------------------
	// �ͷŽ����
	//------------------------------------------------------------------------------
	inline void free_result_query(execute_result* p_result_) { SAFE_DELETE(p_result_); }

	//------------------------------------------------------------------------------
	// ���첽���������sql���
	//------------------------------------------------------------------------------
	inline void add_asynchronism_query(sql_language_disposal* p_io_) { _asynchronism_io_queue.add(p_io_); }

	//------------------------------------------------------------------------------
	// sql����
	//------------------------------------------------------------------------------
	inline BOOL begin_trans(tag_mysql_connect* p_connect_);
	inline BOOL end_trans(tag_mysql_connect* p_connect_);
	inline BOOL roll_back(tag_mysql_connect* p_connect_);

	//-------------------------------------------------------------------------------
	// ���ݿ���Ϣ
	//-------------------------------------------------------------------------------
	inline const std::string& get_host() const { return str_host; }
	inline const std::string& get_user() const { return str_user; }
	inline const std::string& get_password() const { return str_password; }
	inline const std::string& get_db_name() const { return str_db_name; }
	inline const INT get_port() const { return n_port; }

	//-------------------------------------------------------------------------------
	// �ײ�������Ϣ
	//-------------------------------------------------------------------------------
	inline INT get_idlesse_io_num() { return _io_pool.get_idlesse_num(); }
	inline INT get_all_io_num() { return _io_pool.get_all_io_num(); }
	inline INT get_asynchronism_queue_size() { return _asynchronism_io_queue.size(); }

	//-------------------------------------------------------------------------------
	// ����log�ļ���
	//-------------------------------------------------------------------------------
	tstring create_log_file_name();

	BOOL	get_is_end_asynchronism_query(){ return b_end_asynchronism_query; }
	io_safe_queue& get_asynchronism_io_queue() { return _asynchronism_io_queue; }

	BOOL	get_is_end_check() { return b_end_check; }
	io_pool&	get_io_pool() { return _io_pool; }

	alarm_call_back get_alarm_call_back() { return fn_alarm; }

	
private:
	db_interface(const db_interface&);
	db_interface& operator = (const db_interface&);

	void set_db_info(const char* sz_host_, const char* sz_user_, const char* sz_password_, const char* sz_db_name_, INT n_port_, INT n_connect_num_);
	void set_db_info(const WCHAR* sz_host_, const WCHAR* sz_user_, const WCHAR* sz_password_, const WCHAR* sz_db_name_, INT n_port_, INT n_connect_num_);

	BOOL start_connect();

	inline INT get_db_error(tag_mysql_connect* p_connect_, DWORD dw_error_code_, const char* sz_sql_);
	inline BOOL reconnect(tag_mysql_connect* p_connect_);

	inline BOOL inform_query(tag_mysql_connect* p_connect_, const char* sz_sql_, INT n_length_, BOOL b_self_=FALSE);
	inline execute_result* block_query_result(tag_mysql_connect* con);

private:
	
	

	log_file*						p_log;
	tstring						str_log_file_name;

	std::string					str_host;				// mysql��������
	std::string					str_user;				// mysql�û���
	std::string					str_password;			// mysql����
	std::string					str_db_name;			// ���ӵ����ݿ�����
	INT							n_port;					// mysql�˿�

	alarm_call_back				fn_alarm;				// �����ص�����

	tag_mysql_connect*			p_st_connect;			// ���ݿ�����
	INT							n_connect_num;			// ���ݿ���������
	BOOL						b_connect_lost;			// ���ݿ������Ƿ�ʧ

	io_pool						_io_pool;				// sql�������
	io_safe_queue				_asynchronism_io_queue;		// �첽sql������

	HANDLE						h_asynchronism_query_thread;		// �첽sql��䴦���߳�
	HANDLE						h_check_thread;			// ����߳�

	volatile BOOL				b_end_asynchronism_query;	// �Ƿ��˳��첽sql��䴦���߳�
	volatile BOOL				b_end_check;		// �Ƿ��˳�����߳�
};

} // namespace odbc
#endif