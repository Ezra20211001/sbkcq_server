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

#include "stdafx.h"
#include "message_queue.h"

#include "..\memory\memory_pool.h"
namespace serverframe {

message_queue::message_queue()
{
	n_message_num = 0;
	p_queue_begin = NULL;
	p_queue_end = NULL;
	p_current_message = NULL;

	p_memory_pool = new MemPool(16*1024);	
}

message_queue::~message_queue()
{
	clear();
	SAFE_DELETE(p_memory_pool);
}

}