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
*	@file		safe_queue.h
*	@author		lc
*	@date		2011/02/10	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef SAFE_QUEUE
#define SAFE_QUEUE

namespace networkbase {
//-----------------------------------------------------------------------------
// 提供线程安全的队列
//-----------------------------------------------------------------------------
template<typename POINT> class safe_queue
{
public:
	// 添加元素到队列尾
	__forceinline BOOL add(POINT p_item)	
	{
		lock();
		if( 0 == l_item_num )
			p_first = p_item;
		else
			p_last->p_next = p_item;
		p_last = p_item;
		++l_item_num;
		unlock();
		return TRUE;
	}

	// 从队列头获取元素（元素内存在外面负责释放）
	__forceinline POINT get()	
	{
		if( l_item_num <= 0 )	
			return NULL;
		lock();
		if( l_item_num <= 0 )
		{
			unlock();
			return NULL;
		}
		POINT p_item = p_first;	
		p_first = p_first->p_next;
		--l_item_num;
		unlock();
		return p_item;
	}

	// 添加元素到队列头
	__forceinline BOOL add_front(POINT p_item)	
	{
		lock();
		if( 0 == l_item_num )
			p_last = p_item;
		else
			p_item->p_next = p_first;
		p_first = p_item;
		++l_item_num;
		unlock();
		return TRUE;
	}
	
	__forceinline LONG get_num() { return l_item_num; }	// 获取队列中元素个数
	__forceinline safe_queue():l_item_num(0),p_first(0), p_last(0), l_lock(0) {}
	__forceinline ~safe_queue() { }

private:
	LONG volatile		l_lock;
	LONG volatile		l_item_num;
	POINT		p_first;
	POINT		p_last;

	__forceinline VOID lock() { while(Interlocked_Compare_Exchange((long*)&l_lock, 1, 0)!= 0) Sleep(0); }
	__forceinline VOID unlock() { Interlocked_Exchange((LPLONG)(&l_lock), 0); }
};
}
#endif
