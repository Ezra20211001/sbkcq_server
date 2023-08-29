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
*	@file		io_safe_queue.h
*	@author		lc
*	@date		2011/01/18	initial
*	@version	0.0.1.0
*	@brief		
*/

//	io_safe_queue 
//	需要处理的sql语句可以放入此队列中处理


#ifndef IO_SAFE_QUEUE
#define IO_SAFE_QUEUE

#include "StdAfx.h"
#include "sql_language_disposal.h"

namespace odbc {

class sql_language_disposal;
class mutex;

class io_safe_queue
{
public:
	io_safe_queue() : l_num(0) { h_event = create_event(null, FALSE, TRUE, null); }
	virtual ~io_safe_queue();

public:

	inline void add(sql_language_disposal* pStream);
	inline sql_language_disposal* get();
	inline LONG size() const { return l_num; }

	inline HANDLE get_event() { return h_event; }


private:
	io_safe_queue(const io_safe_queue&);
	io_safe_queue& operator = (const io_safe_queue&);

private:
	mutex					mutex;
	HANDLE					h_event;
	std::list<sql_language_disposal*>	list_queue;
	volatile LONG			l_num;
};

//---------------------------------------------------------------------------------------------------------
// 外部获得一个io
//---------------------------------------------------------------------------------------------------------
sql_language_disposal* io_safe_queue::get()
{
	if( l_num == 0 ) return null;

	mutex.lock();

	if( l_num == 0 )
	{
		mutex.un_lock();
		return null;
	}
	sql_language_disposal* pStream = list_queue.front();
	list_queue.pop_front();
	Interlocked_Exchange_Add((LPLONG)&l_num, -1);

	mutex.un_lock();

	return pStream;
}

//-----------------------------------------------------------------------------------------------------------
// 添加一个io
//-----------------------------------------------------------------------------------------------------------
void io_safe_queue::add(sql_language_disposal* pStream)
{
	if( null == pStream ) return;

	mutex.lock();

	list_queue.push_back(pStream);
	Interlocked_Exchange_Add((LPLONG)&l_num, 1);

	if( l_num == 1 )
		::SetEvent(h_event);	

	mutex.un_lock();
}

} // namespace odbc
#endif