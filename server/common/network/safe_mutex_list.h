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
*	@file		safe_mutex_list.h
*	@author		lc
*	@date		2011/02/11	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef SAFE_MUTEX_LIST
#define SAFE_MUTEX_LIST

namespace networkbase {

template<typename Type> class safe_mutex_list
{
public:
	
	VOID push_back(Type value_)
	{
		EnterCriticalSection(&_lock);
		_list.push_back(value_);
		n_element_num++;
		::SetEvent(h_event);		
		LeaveCriticalSection(&_lock);
	}

	Type pop_front()
	{
		Type value_;
		if( n_element_num <= 0 )
			return Type(INVALID_VALUE);

		EnterCriticalSection(&_lock);
		if( n_element_num <= 0 )
		{
			LeaveCriticalSection(&_lock);
			return Type(INVALID_VALUE);
		}

		value_ = _list.front();
		_list.pop_front();
		n_element_num--;
		
		LeaveCriticalSection(&_lock);
		return value_;
	}

	BOOL erase(Type value_)
	{
		std::list<Type>::iterator iter;
		BOOL b_result = FALSE;
		EnterCriticalSection(&_lock);
		for(iter=_list.begin(); iter!=_list.end(); ++iter)
		{
			if( value_ == *iter )
			{
				_list.erase(iter);
				n_element_num--;
				b_result = TRUE;
				break;
			}
		}
		LeaveCriticalSection(&_lock);
		return b_result;
	}

	BOOL is_exist(Type& value_)
	{
		BOOL b_find = FALSE;
		EnterCriticalSection(&_lock);
		std::list<Type>::iterator iter;
		for(iter=_list.begin(); iter!=_list.end(); ++iter)
		{
			if( value_ == *iter )
			{
				b_find = TRUE;
				break;
			}
		}
		LeaveCriticalSection(&_lock);
		return b_find;
	}

	VOID clear()
	{
		EnterCriticalSection(&_lock);
		_list.clear();
		n_element_num=0;
		LeaveCriticalSection(&_lock);
	}

	INT	size() { return n_element_num;	}

	VOID lock() { EnterCriticalSection(&_lock); }
	VOID unlock() { LeaveCriticalSection(&_lock); }

	BOOL find_next(Type& value_)
	{
		if( _iter == _list.end() )
			return FALSE;
		value_ = *_iter;
		++_iter;
		return TRUE;
	}

	VOID reset_iterator(){ _iter = _list.begin(); }

	HANDLE	get_event() { return h_event; }

	safe_mutex_list():n_element_num(0) 
	{ 
		h_event = ::CreateEvent(NULL, FALSE, TRUE, NULL);	
		InitializeCriticalSectionAndSpinCount(&_lock, SPIN_COUNT); 
	}
	~safe_mutex_list()
	{ 
		DeleteCriticalSection(&_lock); 
		CloseHandle(h_event);
	}

private:
	std::list<Type>						_list;
	INT									n_element_num;
	HANDLE								h_event;
	CRITICAL_SECTION					_lock;
	typename std::list<Type>::iterator	_iter;
};





}
#endif