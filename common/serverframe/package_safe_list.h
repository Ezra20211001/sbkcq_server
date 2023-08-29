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
*	@file		package_safe_list.h
*	@author		lc
*	@date		2011/02/11	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef PACKAGE_SAFE_LIST
#define PACKAGE_SAFE_LIST

namespace serverframe {


template<typename Type> class package_safe_list
{
public:
	
	VOID push_back(Type value_)
	{
		EnterCriticalSection(&st_lock);
		_list.push_back(value_);
		++n_element_num;
		LeaveCriticalSection(&st_lock);
	}

	VOID push_front(Type value_)
	{
		EnterCriticalSection(&st_lock);
		_list.push_front(value_);
		++n_element_num;
		LeaveCriticalSection(&st_lock);
	}

	Type pop_front()
	{
		Type value_;
		if( n_element_num <= 0 )
			return Type(INVALID_VALUE);

		EnterCriticalSection(&st_lock);
		if( n_element_num <= 0 )
		{
			LeaveCriticalSection(&st_lock);
			return Type(INVALID_VALUE);
		}

		value_ = _list.front();
		_list.pop_front();
		n_element_num--;
		
		LeaveCriticalSection(&st_lock);
		return value_;
	}

	BOOL erase(Type& value_)
	{
		std::list<Type>::iterator iter;
		EnterCriticalSection(&st_lock);
		for(iter=_list.begin(); iter!=_list.end(); ++iter)
		{
			if( value_ == *iter )
			{
				_list.erase(iter);
				--n_element_num;
				LeaveCriticalSection(&st_lock);
				return TRUE;
			}
		}
		LeaveCriticalSection(&st_lock);
		return FALSE;
	}

	BOOL is_exist(Type& value_)
	{
		BOOL bFound = FALSE;
		EnterCriticalSection(&st_lock);
		std::list<Type>::iterator iter;
		for(iter=_list.begin(); iter!=_list.end(); ++iter)
		{
			if( value_ == *iter )
			{
				bFound = TRUE;
				break;
			}
		}
		LeaveCriticalSection(&st_lock);
		return bFound;
	}

	VOID clear()
	{
		EnterCriticalSection(&st_lock);
		_list.clear();
		n_element_num=0;
		LeaveCriticalSection(&st_lock);
	}

	INT	size() { return n_element_num;	}

	INT copy_list(std::list<Type>& list_out_)
	{
		INT n_num=0;
		EnterCriticalSection(&st_lock);
		std::list<Type>::iterator iter;
		for(iter=_list.begin(); iter!=_list.end(); ++iter, ++n_num)
			list_out_.push_back(*iter);
            
		LeaveCriticalSection(&st_lock);
		return n_num;
	}


	package_safe_list():n_element_num(0) { InitializeCriticalSection(&st_lock); }
	~package_safe_list(){ DeleteCriticalSection(&st_lock); }

private:
	std::list<Type>		_list;
	INT					n_element_num;
	CRITICAL_SECTION	st_lock;
};



}
#endif