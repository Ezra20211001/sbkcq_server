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

//db_interface 提供数据库创建，维护，查询，更新机制
// 对单一数据库提供多连线机制，方便多线程调用
// 提供阻塞式，回调式，无返回操作

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


const INT asynchronism_queue_max_num = 1000;		// 异步队列最大值
const INT sql_language_max_num = 20000;				// sql语句容量限制

struct odbc_api tag_mysql_connect
{
	mutex		_mutex;	// 并发锁
	mysql*		_mysql;

	tag_mysql_connect();
};

class odbc_api db_interface
{
public:
	typedef enum			
	{
		EOE_System,			// mysql服务error
		EOE_QueueFull,		// 数据库阻塞
		EOE_PoolFull,		// sql语句过多
	} E_odbc_error;
public:
	db_interface();
	virtual ~db_interface();

	void set_alarm_call_back(alarm_call_back fn_alarm_) { fn_alarm = fn_alarm_; }

	//---------------------------------------------------------------------------
	// 创建数据库连接
	//---------------------------------------------------------------------------
	BOOL init_db(LPCTSTR str_host_, LPCTSTR str_user_, LPCTSTR str_password_, LPCTSTR str_db_name, INT n_port_, INT n_connect_num_=2);
	
	//---------------------------------------------------------------------------
	// 销毁
	//---------------------------------------------------------------------------
	void shut_down();

	//---------------------------------------------------------------------------
	// 获取数据库连线
	//---------------------------------------------------------------------------
	inline tag_mysql_connect* get_idlesse_connect();

	//---------------------------------------------------------------------------
	// 释放数据库连线
	//---------------------------------------------------------------------------
	inline void return_use_connect(tag_mysql_connect* con);

	//---------------------------------------------------------------------------
	// 重连数据库
	//---------------------------------------------------------------------------
	BOOL reset_connect();

	//---------------------------------------------------------------------------
	//  数据库连线是否断开
	//---------------------------------------------------------------------------
	inline BOOL is_disconnect()		{ return b_connect_lost; }


	//---------------------------------------------------------------------------
	// io相关
	//---------------------------------------------------------------------------
	inline sql_language_disposal* get_io() { return _io_pool.alloc_io(); }
	inline void return_io(sql_language_disposal* pStream) { _io_pool.free_io(pStream); }

	//----------------------------------------------------------------------------
	// 查询
	//----------------------------------------------------------------------------
	inline execute_result* sql_query(const char* sz_content_);
	inline execute_result* sql_query(const sql_language_disposal* p_io_);

	//----------------------------------------------------------------------------
	// 阻塞式查询
	//----------------------------------------------------------------------------
	inline execute_result* sql_block_query(const char* sz_content_, tag_mysql_connect* p_connect_);
	inline execute_result* sql_block_query(const sql_language_disposal* p_io_, tag_mysql_connect* p_connect_);

	//-----------------------------------------------------------------------------
	// 执行
	//-----------------------------------------------------------------------------
	inline BOOL sql_execute(const char* sz_content_);
	inline BOOL sql_execute(const sql_language_disposal* p_io_);

	//-----------------------------------------------------------------------------
	// 阻塞式执行
	//-----------------------------------------------------------------------------
	inline BOOL sql_block_execute(const char* sz_content_, tag_mysql_connect* p_connect_);
	inline BOOL sql_block_execute(const sql_language_disposal* p_io_, tag_mysql_connect* p_connect_);

	//-----------------------------------------------------------------------------
	// 执行操作检测
	//-----------------------------------------------------------------------------
	inline INT sql_execute_check(const char* sz_content_);
	inline INT sql_execute_check(const sql_language_disposal* pStream);
	inline INT sql_block_execute_check(const char* sz_content_, tag_mysql_connect* p_connect_);
	inline INT sql_block_execute_check(const sql_language_disposal* p_io_, tag_mysql_connect* p_connect_);

	//------------------------------------------------------------------------------
	// 释放结果集
	//------------------------------------------------------------------------------
	inline void free_result_query(execute_result* p_result_) { SAFE_DELETE(p_result_); }

	//------------------------------------------------------------------------------
	// 向异步队列中添加sql语句
	//------------------------------------------------------------------------------
	inline void add_asynchronism_query(sql_language_disposal* p_io_) { _asynchronism_io_queue.add(p_io_); }

	//------------------------------------------------------------------------------
	// sql事务
	//------------------------------------------------------------------------------
	inline BOOL begin_trans(tag_mysql_connect* p_connect_);
	inline BOOL end_trans(tag_mysql_connect* p_connect_);
	inline BOOL roll_back(tag_mysql_connect* p_connect_);

	//-------------------------------------------------------------------------------
	// 数据库信息
	//-------------------------------------------------------------------------------
	inline const std::string& get_host() const { return str_host; }
	inline const std::string& get_user() const { return str_user; }
	inline const std::string& get_password() const { return str_password; }
	inline const std::string& get_db_name() const { return str_db_name; }
	inline const INT get_port() const { return n_port; }

	//-------------------------------------------------------------------------------
	// 底层运行信息
	//-------------------------------------------------------------------------------
	inline INT get_idlesse_io_num() { return _io_pool.get_idlesse_num(); }
	inline INT get_all_io_num() { return _io_pool.get_all_io_num(); }
	inline INT get_asynchronism_queue_size() { return _asynchronism_io_queue.size(); }

	//-------------------------------------------------------------------------------
	// 生成log文件名
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

	std::string					str_host;				// mysql主机名称
	std::string					str_user;				// mysql用户名
	std::string					str_password;			// mysql密码
	std::string					str_db_name;			// 连接的数据库名称
	INT							n_port;					// mysql端口

	alarm_call_back				fn_alarm;				// 报警回调函数

	tag_mysql_connect*			p_st_connect;			// 数据库连线
	INT							n_connect_num;			// 数据库连线数量
	BOOL						b_connect_lost;			// 数据库连接是否丢失

	io_pool						_io_pool;				// sql语句容器
	io_safe_queue				_asynchronism_io_queue;		// 异步sql语句队列

	HANDLE						h_asynchronism_query_thread;		// 异步sql语句处理线程
	HANDLE						h_check_thread;			// 检测线程

	volatile BOOL				b_end_asynchronism_query;	// 是否退出异步sql语句处理线程
	volatile BOOL				b_end_check;		// 是否退出检测线程
};

} // namespace odbc
#endif