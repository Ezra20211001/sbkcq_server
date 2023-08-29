/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#pragma once

#include "StdAfx.h"
#include "db_interface.h"
#include "sql_language_disposal.h"
#include "io_safe_queue.h"
#include "io_pool.h"
#include "execute_result.h"

namespace odbc
{

tag_mysql_connect::tag_mysql_connect()
{
	_mysql = null;
}

db_interface::db_interface() : n_port(INVALID_VALUE), fn_alarm(null), n_connect_num(0), p_st_connect(null), b_connect_lost(TRUE),
					   h_asynchronism_query_thread(null), h_check_thread(null), b_end_asynchronism_query(FALSE), b_end_check(FALSE), p_log(null)
{
	
}

db_interface::~db_interface()
{
	shut_down();
	
}

//----------------------------------------------------------------------------------------------------------------------------
// 设置数据库参数
//----------------------------------------------------------------------------------------------------------------------------
void db_interface::set_db_info(const char* sz_host_, const char* sz_user_, const char* sz_password_, const char* sz_db_name_, INT n_port_, INT n_connect_num_)
{
	str_host = std::string(sz_host_);
	str_user = std::string(sz_user_);
	str_password = std::string(sz_password_);
	str_db_name = std::string(sz_db_name_);
	n_port = n_port_;
	n_connect_num = n_connect_num_;
}

//----------------------------------------------------------------------------------------------------------------------------
// 设置数据库参数
//----------------------------------------------------------------------------------------------------------------------------
void db_interface::set_db_info(const WCHAR* sz_host_, const WCHAR* sz_user_, const WCHAR* sz_password_, const WCHAR* sz_db_name_, INT n_port_, INT n_connect_num_)
{
	str_host = std::string(get_tool()->unicode_to_unicode8(sz_host_));
	str_user = std::string(get_tool()->unicode_to_unicode8(sz_user_));
	str_password = std::string(get_tool()->unicode_to_unicode8(sz_password_));
	str_db_name = std::string(get_tool()->unicode_to_unicode8(sz_db_name_));
	n_port = n_port_;
	n_connect_num = n_connect_num_;
}

//----------------------------------------------------------------------------------------------------------------------------
// 初始化数据库，并创建连接
//----------------------------------------------------------------------------------------------------------------------------
BOOL db_interface::init_db(LPCTSTR str_host_, LPCTSTR str_user_, LPCTSTR str_password_, LPCTSTR str_db_name, INT n_port_, INT n_connect_num_/*=2*/)
{
	if( n_connect_num_ <= 1 ) return FALSE;
	
	set_db_info(str_host_, str_user_, str_password_, str_db_name, n_port_, n_connect_num_);

	return start_connect();
}

//---------------------------------------------------------------------------------------------------------------
// 重新建立数据库连接
//---------------------------------------------------------------------------------------------------------------
BOOL db_interface::reset_connect()
{
	shut_down();		
	return start_connect();	
}

//---------------------------------------------------------------------------------------------------------------
// 启动数据库连接
//---------------------------------------------------------------------------------------------------------------
BOOL db_interface::start_connect()
{
	p_st_connect = new tag_mysql_connect[n_connect_num];

	for(INT n = 0; n < n_connect_num; n++)
	{
		MYSQL* temp = mysql_init(null);
		if( mysql_options(temp, MYSQL_SET_CHARSET_NAME, "utf8") )
		{
			
		}

		my_bool my_true = true;
		if( mysql_options(temp, MYSQL_OPT_RECONNECT, &my_true) )
		{
			
		}

		if( null == mysql_real_connect(temp, str_host.c_str(), str_user.c_str(), str_password.c_str(), str_db_name.c_str(), n_port, null, 0) )
		{
			return false;
		}

		p_st_connect[n]._mysql = temp;
	}

	p_log = new log_file;

	if( !VALID_POINT(p_log) )
	{
		return FALSE;
	}
	str_log_file_name = create_log_file_name();
	if( FALSE == p_log->create_log(str_log_file_name.c_str()) )
	{
		return FALSE;
	}

	b_end_asynchronism_query = FALSE;
	INT nRet = _beginthreadex(null, 0, odbc::asynchronism_query_thread, this, 0, null);
	if( 0 == nRet || -1 == nRet )
	{
		return FALSE;
	}
	h_asynchronism_query_thread = (HANDLE)nRet;

	b_end_check = FALSE;
	nRet = _beginthreadex(null, 0, odbc::check_thread, this, 0, null);
	if( 0 == nRet || -1 == nRet )
	{
		return FALSE;
	}
	h_check_thread = (HANDLE)nRet;

	b_connect_lost = FALSE;

	return TRUE;
}

//---------------------------------------------------------------------------------------------------------------
// 关闭数据库连接
//---------------------------------------------------------------------------------------------------------------
void db_interface::shut_down()
{
	Interlocked_Exchange((LPLONG)&b_end_asynchronism_query, TRUE);
	Interlocked_Exchange((LPLONG)&b_end_check, TRUE);

	WaitForSingleObject(h_asynchronism_query_thread, INFINITE);
	WaitForSingleObject(h_check_thread, INFINITE);

	SAFE_CLOSE_HANDLE(h_asynchronism_query_thread);
	SAFE_CLOSE_HANDLE(h_check_thread);

	if( VALID_POINT(p_st_connect) )
	{
		for(INT n = 0; n < n_connect_num; n++)
		{
			if( p_st_connect[n]._mysql )
				mysql_close(p_st_connect[n]._mysql);
		}
		SAFE_DELETE_ARRAY(p_st_connect);
	}

	if( VALID_POINT(p_log) )
	{
		p_log->close_file();
		SAFE_DELETE(p_log);
	}
}

//-----------------------------------------------------------------------------------------------------------------
// 获取空闲数据库连线
//-----------------------------------------------------------------------------------------------------------------
tag_mysql_connect* db_interface::get_idlesse_connect()
{
	DWORD n = 0;
	while(TRUE)
	{
		tag_mysql_connect* con = &p_st_connect[((n++) % n_connect_num)];
		if( con->_mutex.try_lock() )
			return con;
	}

	return null;
}

//------------------------------------------------------------------------------------------------------------------
// 归还使用完的连线
//------------------------------------------------------------------------------------------------------------------
void db_interface::return_use_connect(tag_mysql_connect* con)
{
	if( null != con )
		con->_mutex.un_lock();
}

//-------------------------------------------------------------------------------------------------------------------
// 非阻塞式数据库查询
//-------------------------------------------------------------------------------------------------------------------
execute_result* db_interface::sql_query(const char* sz_content_)
{
	if( null == sz_content_ ) return null;

	tag_mysql_connect* con = get_idlesse_connect();

	execute_result* pRet = null;

	if( inform_query(con, sz_content_, strlen(sz_content_)) )
	{
		pRet = block_query_result(con);
	}

	return_use_connect(con);
	return pRet;
}

execute_result* db_interface::sql_query(const sql_language_disposal* p_io_)
{
	if( null == p_io_ || null == p_io_->get_buffer() || 0 == p_io_->get_buffer_length() )
		return null;

	tag_mysql_connect* con = get_idlesse_connect();

	execute_result* pRet = null;

	if( inform_query(con, p_io_->get_buffer(), p_io_->get_buffer_length()) )
	{
		pRet = block_query_result(con);
	}

	return_use_connect(con);
	return pRet;
}

//------------------------------------------------------------------------------------------------------------------------
// 阻塞式数据库查询
//------------------------------------------------------------------------------------------------------------------------
execute_result* db_interface::sql_block_query(const char* sz_content_, tag_mysql_connect* p_connect_)
{
	if( null == sz_content_ || null == p_connect_ ) return null;

	execute_result* pRet = null;

	if( inform_query(p_connect_, sz_content_, strlen(sz_content_)) )
	{
		pRet = block_query_result(p_connect_);
	}

	return pRet;
}

execute_result* db_interface::sql_block_query(const sql_language_disposal* p_io_, tag_mysql_connect* p_connect_)
{
	if( null == p_io_ || null == p_io_->get_buffer() || 0 == p_io_->get_buffer_length() || null == p_connect_ )
		return null;

	execute_result* pRet = null;

	if( inform_query(p_connect_, p_io_->get_buffer(), p_io_->get_buffer_length()) )
	{
		pRet = block_query_result(p_connect_);
	}

	return pRet;
}

//-----------------------------------------------------------------------------------------------------------
// 非阻塞式数据库执行
//-----------------------------------------------------------------------------------------------------------
BOOL db_interface::sql_execute(const char* sz_content_)
{
	if( null == sz_content_ ) return FALSE;

	tag_mysql_connect* con = get_idlesse_connect();

	BOOL bRet = inform_query(con, sz_content_, strlen(sz_content_));

	return_use_connect(con);
	return bRet;
}

BOOL db_interface::sql_execute(const sql_language_disposal* p_io_)
{
	if( null == p_io_ || null == p_io_->get_buffer() || 0 == p_io_->get_buffer_length() )
		return FALSE;

	tag_mysql_connect* con = get_idlesse_connect();

	BOOL bRet = inform_query(con, p_io_->get_buffer(), p_io_->get_buffer_length());

	return_use_connect(con);
	return bRet;
}

//-------------------------------------------------------------------------------------------------------------
// 阻塞式数据库执行
//--------------------------------------------------------------------------------------------------------------
BOOL db_interface::sql_block_execute(const char* sz_content_, tag_mysql_connect* p_connect_)
{
	if( null == sz_content_ || null == p_connect_ ) return FALSE;

	return inform_query(p_connect_, sz_content_, strlen(sz_content_));

}

BOOL db_interface::sql_block_execute(const sql_language_disposal* p_io_, tag_mysql_connect* p_connect_)
{
	if( null == p_io_ || null == p_io_->get_buffer() || 0 == p_io_->get_buffer_length() || null == p_connect_ )
		return FALSE;

	return inform_query(p_connect_, p_io_->get_buffer(), p_io_->get_buffer_length());
}

//---------------------------------------------------------------------------------------------------------------
// 非阻塞式数据库执行结果检测
//---------------------------------------------------------------------------------------------------------------
INT db_interface::sql_execute_check(const char* sz_content_)
{
	if( null == sz_content_ ) return INVALID_VALUE;

	tag_mysql_connect* con = get_idlesse_connect();

	BOOL bRet = inform_query(con, sz_content_, strlen(sz_content_));

	return_use_connect(con);

	return (bRet ? (INT)mysql_affected_rows(con->_mysql) : INVALID_VALUE);
}

INT db_interface::sql_execute_check(const sql_language_disposal* pStream)
{
	if( null == pStream || null == pStream->get_buffer() || 0 == pStream->get_buffer_length() )
		return INVALID_VALUE;

	tag_mysql_connect* con = get_idlesse_connect();

	BOOL bRet = inform_query(con, pStream->get_buffer(), pStream->get_buffer_length());

	return_use_connect(con);

	return (bRet ? (INT)mysql_affected_rows(con->_mysql) : INVALID_VALUE);
}

//---------------------------------------------------------------------------------------------------------------
// 阻塞式数据库执行结果检测
//---------------------------------------------------------------------------------------------------------------
INT db_interface::sql_block_execute_check(const char* sz_content_, tag_mysql_connect* p_connect_)
{
	if( null == sz_content_ || null == p_connect_ ) return INVALID_VALUE;

	BOOL bRet = inform_query(p_connect_, sz_content_, strlen(sz_content_));

	return (bRet ? (INT)mysql_affected_rows(p_connect_->_mysql) : INVALID_VALUE);
}

INT db_interface::sql_block_execute_check(const sql_language_disposal* p_io_, tag_mysql_connect* p_connect_)
{
	if( null == p_io_ || null == p_io_->get_buffer() || 0 == p_io_->get_buffer_length() || null == p_connect_ )
		return INVALID_VALUE;

	BOOL bRet = inform_query(p_connect_, p_io_->get_buffer(), p_io_->get_buffer_length());

	return (bRet ? (INT)mysql_affected_rows(p_connect_->_mysql) : INVALID_VALUE);
}

//---------------------------------------------------------------------------------------------------------------
// sql事务
//---------------------------------------------------------------------------------------------------------------
BOOL db_interface::begin_trans(tag_mysql_connect* p_connect_)
{
	return sql_block_execute("start transaction", p_connect_);
}

BOOL db_interface::end_trans(tag_mysql_connect* p_connect_)
{
	return sql_block_execute("commit", p_connect_);
}

BOOL db_interface::roll_back(tag_mysql_connect* p_connect_)
{
	return sql_block_execute("rollback", p_connect_);
}

//------------------------------------------------------------------------------------------------------------------
// 通知数据库进行查询
//------------------------------------------------------------------------------------------------------------------
BOOL db_interface::inform_query(tag_mysql_connect* p_connect_, const char* sz_sql_, INT n_length_, BOOL b_self_/*=FALSE*/)
{
	INT nResult = mysql_real_query(p_connect_->_mysql, sz_sql_, n_length_);
	if( nResult != 0 )
	{
		if( b_self_ == FALSE /*&& get_db_error(p_connect_, mysql_errno(p_connect_->_mysql), sz_sql_)*/ )
		{
			if(get_db_error(p_connect_, mysql_errno(p_connect_->_mysql), sz_sql_) == 1)
			{
				return inform_query(p_connect_, sz_sql_, n_length_, FALSE);
			}
			else
			{
				return inform_query(p_connect_, sz_sql_, n_length_, TRUE);
			}
		}
	}

	return (nResult == 0 ? TRUE : FALSE);
}

//-------------------------------------------------------------------------------------------------------------------
// 获得数据库查询的结果集
//-------------------------------------------------------------------------------------------------------------------
execute_result* db_interface::block_query_result(tag_mysql_connect* con)
{
	if( null == con ) return null;

	execute_result* pResult = null;

	mysql_res* pRes = mysql_store_result(con->_mysql);
	INT nRows = (INT)mysql_affected_rows(con->_mysql);
	INT nFields = (INT)mysql_field_count(con->_mysql);

	if( 0 == nFields || null == pRes )
	{
		if( pRes != null )
			mysql_free_result(pRes);

		return null;
	}

	pResult = new execute_result(pRes, nRows, nFields);

	pResult->next_row();

	return pResult;
}

//----------------------------------------------------------------------------------------------------------------------
// 获取数据库错误信息
//----------------------------------------------------------------------------------------------------------------------
BOOL db_interface::get_db_error(tag_mysql_connect* p_connect_, DWORD dw_error_code_, const char* sz_sql_)
{
	if( null == p_connect_ ) return 2;

	p_log->write_log(_T("errorcode: %u\r\n"), dw_error_code_);
	p_log->write_log(_T("causation: %s\r\n"), get_tool()->unicode8_to_unicode(mysql_error(p_connect_->_mysql)));
	p_log->write_log(_T("sql_sentence: %s\r\n\r\n"), get_tool()->ansi_to_unicode(sz_sql_));

	switch(dw_error_code_)
	{
	case 2006:  
	case 2008:  
	case 2013:  
	case 2055:  
		{
			if(reconnect(p_connect_) == FALSE)
				return 1;
		}
		break;
	}

	return 2;
}

//----------------------------------------------------------------------------------------------------------------------
// 数据库重连
//----------------------------------------------------------------------------------------------------------------------
BOOL db_interface::reconnect(tag_mysql_connect* p_connect_)
{
	if( null == p_connect_ ) return FALSE;

	MYSQL* temp = mysql_init(null);
	my_bool my_true = true;
	mysql_options(temp, MYSQL_SET_CHARSET_NAME, "utf8");
	mysql_options(temp, MYSQL_OPT_RECONNECT, &my_true);

	if( null == mysql_real_connect(temp, str_host.c_str(), str_user.c_str(), str_password.c_str(), str_db_name.c_str(), n_port, null , 0) )
	{
		mysql_close(temp);

		b_connect_lost = TRUE;

		if( fn_alarm )
			(*fn_alarm)(this, EOE_System, 0);
		return FALSE;
	}

	if( p_connect_->_mysql != null )
		mysql_close(p_connect_->_mysql);

	p_connect_->_mysql = temp;

	b_connect_lost = FALSE;
	return TRUE;
}

UINT win_api asynchronism_query_thread(void* p)
{
	THROW_EXCEPTION_START;

	db_interface* p_db_interface_ = (db_interface*)p;

	tag_mysql_connect* con = p_db_interface_->get_idlesse_connect();
	if( null == con ) return 1;

	while( FALSE == p_db_interface_->get_is_end_asynchronism_query() )
	{
		while(TRUE)
		{
			sql_language_disposal* pStream = p_db_interface_->get_asynchronism_io_queue().get();
			if( null == pStream )
				break;

			p_db_interface_->sql_block_execute(pStream, con);
			p_db_interface_->return_io(pStream);
		}

		WaitForSingleObject(p_db_interface_->get_asynchronism_io_queue().get_event(), 120);
	}

	while(TRUE)
	{
		sql_language_disposal* pStream = p_db_interface_->get_asynchronism_io_queue().get();
		if( null == pStream )
			break;

		p_db_interface_->sql_block_execute(pStream, con);
		p_db_interface_->return_io(pStream);
	}

	p_db_interface_->return_use_connect(con);

	THROW_EXCEPTION_END;
	_endthreadex(0);
	return 0;
}

//---------------------------------------------------------------------------------------------------------------------
// 检测线程
//---------------------------------------------------------------------------------------------------------------------
UINT win_api check_thread(void* p)
{
	THROW_EXCEPTION_START;

	db_interface* p_db_interface_ = (db_interface*)p;

	BOOL bWarningQueueFullNotified = FALSE;
	BOOL bWarningPoolFullNotified = FALSE;
	
	while( FALSE == p_db_interface_->get_is_end_check() )
	{
		INT nQueryNum = p_db_interface_->get_asynchronism_io_queue().size();
		if( nQueryNum >= asynchronism_queue_max_num && FALSE == bWarningQueueFullNotified )
		{
			if( p_db_interface_->get_alarm_call_back() )
				(*p_db_interface_->get_alarm_call_back())(p_db_interface_, db_interface::EOE_QueueFull, nQueryNum);
			bWarningQueueFullNotified = TRUE;
		}
		else if( nQueryNum < asynchronism_queue_max_num && TRUE == bWarningQueueFullNotified )
		{
			bWarningQueueFullNotified = FALSE;
		}

		INT nPoolNum = p_db_interface_->get_io_pool().get_all_io_num();
		if( nPoolNum >= sql_language_max_num && FALSE == bWarningPoolFullNotified )
		{
			if( p_db_interface_->get_alarm_call_back() )
				(*p_db_interface_->get_alarm_call_back())(p_db_interface_, db_interface::EOE_PoolFull, nPoolNum);
			bWarningPoolFullNotified = TRUE;
		}
		else if( nPoolNum < sql_language_max_num && TRUE == bWarningPoolFullNotified )
		{
			bWarningPoolFullNotified = FALSE;
		}

		Sleep(2000);
	}

	THROW_EXCEPTION_END;
	_endthreadex(0);
	return 0;
}

//------------------------------------------------------------------------------
// 生成log文件名
//------------------------------------------------------------------------------
tstring db_interface::create_log_file_name()
{
	tstring str_file_name = _T("log\\");

	TCHAR sz_time[MAX_PATH], sz_handle_name[MAX_PATH];
	get_module_file_name(null, sz_handle_name, MAX_PATH);

	TCHAR *p_result = _tcsrchr(sz_handle_name, _T('\\'));
	p_result = p_result ?	p_result+1 :	p_result = (TCHAR *)sz_handle_name;

	TCHAR* p_result1 = _tcsrchr(p_result, _T('.'));
	if( p_result1 )
		*p_result1 = _T('\0');

	str_file_name += p_result;
	str_file_name += _T("_");

	str_file_name += get_tool()->unicode8_to_unicode(str_db_name.c_str());
	str_file_name += _T("_");

	FILETIME st_current_time;
	get_system_time_as_file_time(&st_current_time);
	sz_time[0] = _T('\0');
	WORD w_data, w_time;
	if (file_time_to_local_file_time(&st_current_time, &st_current_time) &&
		file_time_to_dos_date_time(&st_current_time, &w_data, &w_time))
	{
		wsprintf(sz_time, _T("[%d-%d-%d %02d-%02d-%02d %05d___%d].odbclog"),
			(w_data / 32) & 15, w_data & 31, (w_data / 512) + 1980,
			(w_time >> 11), (w_time >> 5) & 0x3F, (w_time & 0x1F) * 2, 
			get_current_process_id(),
			rand());
	}

	str_file_name += sz_time;

	return str_file_name;
}

} // namespace odbc

