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
*	@file		safe_list.h
*	@author		lc
*	@date		2011/02/10	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef SAFE_LIST
#define SAFE_LIST

namespace networkbase {

//-----------------------------------------------------------------------------
// 封装std::list，提供线程安全list
//-----------------------------------------------------------------------------
template<typename Type> class safe_list
{
public:

	// 添加元素
	__forceinline VOID pust_back(Type val)	
	{
		lock();
		_list.push_back(val);
		++n_item_num;
		unlock();
	}

	// 从队列头提取元素
	__forceinline Type pop_front()	
	{
		if( n_item_num <= 0 )
			return Type(INVALID_VALUE);

		lock();
		if( n_item_num <= 0 )
		{
			unlock();
			return Type(INVALID_VALUE);
		}
		Type val = _list.front();
		_list.pop_front();
		n_item_num--;
		unlock();
		return val;
	}
	
	// 删除指定元素
	__forceinline BOOL erase(Type& val)	
	{
		std::list<Type>::iterator it;
		lock();
		for(it=_list.begin(); it!=_list.end(); ++it)
		{
			if( val == *it )
			{
				_list.erase(it);
				--n_item_num;
				unlock();
				return TRUE;
			}
		}
		unlock();
		return FALSE;
	}

	// 判断指定元素是否存在
	__forceinline BOOL is_exist(Type& val)	
	{
		lock();
		std::list<Type>::iterator it;
		for(it=_list.begin(); it!=_list.end(); ++it)
		{
			if( val == *it )
			{
				unlock();
				return TRUE
			}
		}
		unlock();
		return FALSE;
	}

	// 清空所有元素
	__forceinline VOID clear()	
	{
		lock();
		m_list.clear();
		n_item_num=0;
		unlock();
	}

	// 得到队列元素个数
	__forceinline INT	size() { return n_item_num;	}

	// 获得迭代器指向元素（需要lock后再调用）
	__forceinline BOOL peek(Type& value)
	{
		if( _iter == _list.end() )
			return FALSE;
		value = *_iter;
		return TRUE;
	}

	__forceinline VOID reset_iterator(){ _iter = _list.begin(); }
	__forceinline VOID add_iterator(){ ++_iter; }
	__forceinline VOID erase_iterator(){ _list.erase(_iter); }

	__forceinline safe_list():n_item_num(0), l_lock(0) {}
	__forceinline ~safe_list(){ }
	__forceinline VOID	lock() { while(Interlocked_Compare_Exchange((long*)&l_lock, 1, 0)!= 0) Sleep(0); }
	__forceinline VOID	unlock() { Interlocked_Exchange((LPLONG)(&l_lock), 0); }

private:
	std::list<Type>						_list;
	typename std::list<Type>::iterator	_iter;
	
	INT	volatile	n_item_num;
	LONG volatile	l_lock;
};

}
#endif