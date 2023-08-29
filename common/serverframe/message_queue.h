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
*	@file		message_queue.h
*	@author		lc
*	@date		2011/02/16	initial
*	@version	0.0.1.0
*	@brief		
*/


#ifndef MESSAGE_QUEUE
#define MESSAGE_QUEUE

namespace serverframe {


class FRAME_API message_queue
{
public:
	
	__forceinline BOOL add_message(LPCVOID p_message_, DWORD dw_size_);
	
	__forceinline LPBYTE get_message(DWORD& dw_message_size_);
	
	__forceinline VOID free_message(LPVOID p_message_);

	
	__forceinline VOID reset_iterator();
	
	__forceinline VOID increase_iterator();
	
	__forceinline LPBYTE peek_message(DWORD& dwMsgSize);
	
	__forceinline VOID remove_message();
	
	__forceinline VOID clear();

	
	__forceinline INT get_message_num() { return n_message_num; }
	
	message_queue();
	~message_queue();

private:
	struct tag_message
	{
		DWORD			dw_data_size;
		BYTE*			p_data;
		tag_message*		p_prevenient;
		tag_message*		p_next;
	};

	INT					n_message_num;
	tag_message*			p_queue_begin;
	tag_message*			p_queue_end;
	tag_message*			p_current_message;

	memorysystem::MemPool*			p_memory_pool;
};


BOOL message_queue::add_message(LPCVOID p_message_, DWORD dw_size_)
{
	tag_message* p_add_message = (tag_message*)p_memory_pool->alloc_memory(sizeof(tag_message));
	if( p_add_message == NULL )
		return FALSE;

	p_add_message->dw_data_size = dw_size_;
	p_add_message->p_data = NULL;
	p_add_message->p_prevenient = NULL;
	p_add_message->p_next = NULL;

	p_add_message->p_data = (LPBYTE)p_memory_pool->alloc_memory(dw_size_);
	if( p_add_message->p_data == NULL )
	{
		delete(p_add_message);
		return FALSE;
	}

	memcpy(p_add_message->p_data, p_message_, dw_size_);

	if( p_queue_begin == NULL )	
	{
		p_queue_begin = p_add_message;
		p_queue_end = p_add_message;
		p_current_message = p_add_message;
	}
	else
	{
		p_queue_end->p_next = p_add_message;
		p_add_message->p_prevenient = p_queue_end;
		p_queue_end = p_add_message;

	}

	n_message_num++;
	return TRUE;
}

LPBYTE message_queue::get_message(DWORD& dw_message_size_)
{
	dw_message_size_ = 0;
	if( n_message_num <= 0 )
		return NULL;	

	LPBYTE p_message = p_queue_begin->p_data;
	dw_message_size_ = p_queue_begin->dw_data_size;

	tag_message* pItem = p_queue_begin;
	p_queue_begin = p_queue_begin->p_next;
	if( p_queue_begin )
		p_queue_begin->p_prevenient = NULL;
	p_memory_pool->free_memory(pItem);

	n_message_num--;
	return p_message;
}


VOID message_queue::free_message(LPVOID p_message_) 
{
	p_memory_pool->free_memory(p_message_);
}


VOID message_queue::reset_iterator()
{
	p_current_message = p_queue_begin;
}

VOID message_queue::increase_iterator()
{
	if( !p_current_message )
		return;

	p_current_message = p_current_message->p_next;
}

LPBYTE message_queue::peek_message(DWORD& dwMsgSize)
{
	dwMsgSize = 0;
	if( !p_current_message || n_message_num <= 0 )
		return NULL;

	dwMsgSize = p_current_message->dw_data_size;
	return p_current_message->p_data;
}

VOID message_queue::remove_message()
{
	if( !p_current_message )
		return;

	tag_message* p_message = p_current_message;
	if( p_current_message == p_queue_begin )
	{
		p_queue_begin = p_queue_begin->p_next;
		if( p_queue_begin )
			p_queue_begin->p_prevenient = NULL;
		p_current_message = p_queue_begin;

	}
	else if( p_current_message == p_queue_end )
	{
		p_queue_end = p_queue_end->p_prevenient;
		if( p_queue_end )
			p_queue_end->p_next = NULL;

		p_current_message = NULL;
	}
	else
	{
		p_current_message->p_prevenient->p_next = p_current_message->p_next;
		p_current_message->p_next->p_prevenient = p_current_message->p_prevenient;
		p_current_message = p_current_message->p_next;
	}

	p_memory_pool->free_memory(p_message->p_data);
	p_memory_pool->free_memory(p_message);
	n_message_num--;
	if( 0 == n_message_num )
	{
		p_queue_begin = p_queue_end = p_current_message = NULL;
	}
}

VOID message_queue::clear()
{
	tag_message* p_message = p_queue_begin; 
	while( p_queue_begin )
	{
		p_message = p_queue_begin->p_next;
		p_memory_pool->free_memory( p_queue_begin->p_data);
		p_memory_pool->free_memory(p_queue_begin);
		p_queue_begin = p_message;
	}
	n_message_num = 0;
	p_queue_begin = NULL;
	p_queue_end = NULL;
	p_current_message = NULL;
}

}
#endif