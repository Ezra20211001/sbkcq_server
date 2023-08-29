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
*	@file		io_pool.h
*	@author		lc
*	@date		2011/01/18	initial
*	@version	0.0.1.0
*	@brief		
*/

//	io_pool类	提供Mysql数据流内存支持
//	初始时预先分配一定大小的内存，内存不足时可以动态扩充，内存不用时可以释放多余内存
//	提供线程安全支持


#ifndef IO_POOL
#define IO_POOL

#include "StdAfx.h"
#include "sql_language_disposal.h"
#include "io_safe_queue.h"

namespace odbc {

class sql_language_disposal;

class odbc_api io_pool
{
public:
	io_pool(INT n_defult_size_=1000);
	virtual ~io_pool();

public:
	inline sql_language_disposal* alloc_io();
	inline void free_io(sql_language_disposal* pStream);

	inline LONG get_idlesse_num() { return idlesse_queue.size(); }
	inline INT get_all_io_num() { return n_io_num; }

private:
	io_pool(const io_pool&);
	io_pool& operator = (const io_pool&);

	inline void real_alloc(INT n_num);
	inline void real_free(INT n_num);
	inline void free_all_memory();

private:

	volatile INT		n_defult_size;		// 内存扩充时的默认大小
	volatile INT		n_io_num;		// 内存池分配了多少io

	mutex				mutex;
	io_safe_queue		idlesse_queue;

};

} // namespace odbc
#endif