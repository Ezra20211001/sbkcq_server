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
*	@file		package_safe_map.h
*	@author		lc
*	@date		2011/02/16	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef PACKAGE_SAFE_MAP
#define PACKAGE_SAFE_MAP

namespace serverframe {


template<typename KeyType, typename ValueType> class package_safe_map
{
public:
	typedef typename std::map<KeyType, ValueType>::iterator map_iter;

public:
	
	BOOL empty() { return _map.empty(); }

	map_iter begin()
	{ 
		return _map.begin(); 
	}

	VOID add(KeyType key_, ValueType value_)
	{
		EnterCriticalSection(&st_lock);
		_map.insert(std::pair<KeyType, ValueType>(key_, value_));
		LeaveCriticalSection(&st_lock);
	}

	ValueType find(KeyType key_)
	{
		ValueType value_temp;
		std::map<KeyType, ValueType>::iterator iter;
		EnterCriticalSection(&st_lock);
		iter = _map.find(key_);
		if( iter == _map.end() )
			value_temp = ValueType(INVALID_VALUE);
		else
			value_temp = iter->second;
		LeaveCriticalSection(&st_lock);
		return value_temp;
	}

	BOOL find_next(map_iter& iter_, KeyType& key_, ValueType& value_)
	{
		if( iter_ == _map.end() )
			return FALSE;
		key_ = iter_->first;
		value_ = iter_->second;
		++iter_;
		return TRUE;
	}

	BOOL change_value(KeyType key_, ValueType value_)
	{
		std::map<KeyType, ValueType>::iterator iter;
		EnterCriticalSection(&st_lock);
		iter = _map.find(key_);
		
		if( iter == _map.end() )
		{
			LeaveCriticalSection(&st_lock);
			return FALSE;
		}
		else
		{
			iter->second = value_;
			LeaveCriticalSection(&st_lock);
			return TRUE;
		}
	}

	BOOL is_exist(KeyType key_)
	{
		BOOL b_result = FALSE;
		std::map<KeyType, ValueType>::iterator iter;
		EnterCriticalSection(&st_lock);
		iter = _map.find(key_);
		
		if( iter == _map.end() )
			b_result = FALSE;
		else
			b_result = TRUE;
		LeaveCriticalSection(&st_lock);

		return b_result;
	}

	BOOL erase(KeyType key_)
	{
		BOOL b_result = FALSE;
		std::map<KeyType, ValueType>::iterator iter;
		
		EnterCriticalSection(&st_lock);
		iter = _map.find(key_);
		if( iter == _map.end() )
		{
			b_result = FALSE;
		}
		else
		{
			_map.erase(iter);
			b_result = TRUE;
		}
		LeaveCriticalSection(&st_lock);
		return b_result;
	}

	VOID clear()
	{
		EnterCriticalSection(&st_lock);
		_map.clear();
		LeaveCriticalSection(&st_lock);
	}

	INT	size() { return (INT)_map.size(); }

	INT copy_key_to_list(std::list<KeyType>& list_out_)
	{
		INT n_num=0;
		EnterCriticalSection(&st_lock);
		std::map<KeyType, ValueType>::iterator iter;
		for(iter = _map.begin(); iter != _map.end(); ++iter, ++n_num)
			list_out_.push_back(iter->first);
		LeaveCriticalSection(&st_lock);
		return n_num;
	}

	INT copy_value_to_list(std::list<ValueType>& list_out_)
	{
		INT n_num=0;
		EnterCriticalSection(&st_lock);
		std::map<KeyType, ValueType>::iterator iter;
		for(iter = _map.begin(); iter != _map.end(); ++iter, ++n_num)
			list_out_.push_back(iter->second);
		LeaveCriticalSection(&st_lock);
		return n_num;
	}

	VOID lock() { EnterCriticalSection(&st_lock); }
	VOID unlock() { LeaveCriticalSection(&st_lock); }


	package_safe_map() { InitializeCriticalSection(&st_lock); }
	~package_safe_map()	{ DeleteCriticalSection(&st_lock); }


private:
	std::map<KeyType, ValueType>			_map;
	CRITICAL_SECTION						st_lock;
	
	

};



}
#endif