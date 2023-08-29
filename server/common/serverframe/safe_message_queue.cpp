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

#include "stdafx.h"
#include "safe_message_queue.h"

namespace serverframe {

safe_message_queue::safe_message_queue(BOOL b_send_event_, BOOL b_add_message_head_)
{
	b_send_event = b_send_event_;
	b_add_message_head = b_add_message_head_;
	
	n_message_num = 0;
	h_event = NULL;
	p_queue_begin = NULL;
	p_queue_end = NULL;
	
	InitializeCriticalSection(&st_lock);

	if( b_send_event )
		h_event = ::CreateEvent(NULL, FALSE, TRUE, NULL);	

	p_safe_memory_pool = new safe_memory_pool(256*1024);	
}

safe_message_queue::~safe_message_queue()
{
	tag_message* p_message = p_queue_begin; 
	while( p_queue_begin )
	{
		p_message = p_queue_begin->p_next;
		p_safe_memory_pool->free_memory(p_queue_begin->p_data);
		p_safe_memory_pool->free_memory(p_queue_begin);
		p_queue_begin = p_message;
	}

	if( b_send_event )
		CloseHandle(h_event);

	DeleteCriticalSection(&st_lock);
	SAFE_DELETE(p_safe_memory_pool);
}





}