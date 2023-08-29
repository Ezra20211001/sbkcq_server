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
*	@file		package_list.h
*	@author		lc
*	@date		2011/02/16	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef PACKAGE_LIST
#define PACKAGE_LIST

namespace serverframe {


template<typename Type> class package_list
{
public:
	typedef typename std::list<Type>::iterator list_iter;

public:
	
	VOID push_back(Type value_)
	{
		_list.push_back(value_);
		++n_element_num;
	}

	
	Type pop_front()
	{
		Type value_;
		if( n_element_num <= 0 )
			return Type(INVALID_VALUE);

		value_ = _list.front();
		_list.pop_front();
		n_element_num--;
		return value_;
	}

	
	VOID push_front(Type value_)
	{
		_list.push_front(value_);
		++n_element_num;
	}

	
	Type front()
	{
		if( n_element_num <= 0 )
			return Type(INVALID_VALUE);

		return _list.front();
	}

	
	BOOL erase(Type& value_)
	{
		std::list<Type>::iterator iter_;
		for(iter_=_list.begin(); iter_!=_list.end(); ++iter_)
		{
			if( value_ == *iter_ )
			{
				_list.erase(iter_);
				--n_element_num;	
				return TRUE;
			}
		}
		return FALSE;
	}

	
	BOOL is_exist(Type& value_)
	{
		std::list<Type>::iterator iter_;
		for(iter_=_list.begin(); iter_!=_list.end(); ++iter_)
		{
			if( value_ == *iter_ )
				return TRUE;
		}
		return FALSE;
	}

	
	VOID clear()
	{
		_list.clear();
		n_element_num=0;
	}

	
	INT	size() { return n_element_num;	}
	BOOL empty() { return (0 == n_element_num); }

	BOOL rand_find(Type& value_, BOOL b_del_=FALSE)
	{
		if( _list.empty() )
			return FALSE;

		INT n_rand = rand() % n_element_num;
		std::list<Type>::iterator iter_ = _list.begin();
		for(INT n=0; n<n_rand; n++)
			++iter_;
       
		value_ = *iter_;
		if( b_del_ )
		{
			_list.erase(iter_);
			n_element_num--;
		}
			
		return TRUE;
	}

	BOOL find_next(Type& value_)
	{
		if( iter == _list.end() )
			return FALSE;
		value_ = *iter;
		++iter;
		return TRUE;
	}

	BOOL find_next(list_iter& iter_, Type& value_)
	{
		if( iter_ == _list.end() )
			return FALSE;
		value_ = *iter_;
		++iter_;
		return TRUE;
	}

	VOID reset_iterator()
	{ iter = _list.begin();	}

	list_iter begin()
	{
		return _list.begin();
	}

	std::list<Type>& get_list() { return _list; }


	VOID operator=(std::list<Type>& list) { _list = list;	}
	VOID operator=(package_list<Type>& list) { _list = list.get_list(); n_element_num = _list.size(); iter = _list.end(); }


	package_list():n_element_num(0) {}
	package_list(std::list<Type>& list){ _list = list; }
	~package_list(){}

private:
	std::list<Type>						_list;
	INT									n_element_num;
	typename std::list<Type>::iterator	iter;
};



}
#endif