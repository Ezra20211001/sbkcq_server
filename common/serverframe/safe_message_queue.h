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
*	@file		safe_message_queue.h
*	@author		lc
*	@date		2011/02/16	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef SAFE_MESSAGE_QUEUE
#define SAFE_MESSAGE_QUEUE

namespace serverframe {


class FRAME_API safe_message_queue
{
public:

	safe_message_queue(BOOL b_send_event_, BOOL b_add_message_head_);
	~safe_message_queue();


	__forceinline BOOL add_message(LPCVOID p_message_, DWORD dw_size_);

	__forceinline LPBYTE get_message(DWORD& dw_message_size_);

	__forceinline VOID free_message(LPVOID p_message);

	__forceinline HANDLE get_event() { return h_event; }

	__forceinline INT get_message_num() { return n_message_num; }
	

private:
	struct tag_message
	{
		DWORD			dw_data_size;
		BYTE*			p_data;
		tag_message*	p_next;
	};

	safe_memory_pool*		p_safe_memory_pool;
	CRITICAL_SECTION	st_lock;
	HANDLE				h_event;
	INT					n_message_num;
	BOOL				b_send_event;
	BOOL				b_add_message_head;	

	tag_message*			p_queue_begin;
	tag_message*			p_queue_end;
};


BOOL safe_message_queue::add_message(LPCVOID p_message_, DWORD dw_size_)
{
	DWORD dw_src_size = dw_size_;
	if( b_add_message_head ) 
		dw_size_ += sizeof(DWORD);

	tag_message* p_new_message = (tag_message*)p_safe_memory_pool->alloc_memory(sizeof(tag_message));
	if( p_new_message == NULL )
		return FALSE;

	p_new_message->dw_data_size = dw_size_;
	p_new_message->p_data = NULL;
	p_new_message->p_next = NULL;

	p_new_message->p_data = (LPBYTE)p_safe_memory_pool->alloc_memory(dw_size_);
	if( p_new_message->p_data == NULL )
	{
		delete(p_new_message);
		return FALSE;
	}

	EnterCriticalSection(&st_lock);	

	if( b_add_message_head )
	{
		*(DWORD*)(p_new_message->p_data) = dw_src_size;
		memcpy(p_new_message->p_data+sizeof(dw_src_size), p_message_, dw_src_size);
	}
	else
	{
		memcpy(p_new_message->p_data, p_message_, dw_size_);
	}

	if( p_queue_begin == NULL )	
	{
		p_queue_begin = p_new_message;
		p_queue_end = p_new_message;
	}
	else
	{
		p_queue_end->p_next = p_new_message;
		p_queue_end = p_new_message;
	}

	n_message_num++;

	if( b_send_event )	
		::SetEvent(h_event);	

	LeaveCriticalSection(&st_lock);
	return TRUE;
}


LPBYTE safe_message_queue::get_message(DWORD& dw_message_size_)
{
	dw_message_size_ = 0;
	if( n_message_num <= 0 )	
		return NULL;	

	EnterCriticalSection(&st_lock);

	if( n_message_num <= 0 )	
	{
		LeaveCriticalSection(&st_lock);
		return NULL;	
	}

	LPBYTE p_message_data = p_queue_begin->p_data;
	dw_message_size_ = p_queue_begin->dw_data_size;

	tag_message* p_message = p_queue_begin;
	p_queue_begin = p_queue_begin->p_next;

	n_message_num--;
	LeaveCriticalSection(&st_lock);

	p_safe_memory_pool->free_memory(p_message);
	return p_message_data;
}

VOID safe_message_queue::free_message(LPVOID p_message)
{
	p_safe_memory_pool->free_memory(p_message);
}


}
#endif