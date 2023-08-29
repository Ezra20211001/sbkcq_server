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
*	@file		safe_memory_pool.h
*	@author		lc
*	@date		2011/02/21	initial
*	@version	0.0.1.0
*	@brief		
*/

#include "stdafx.h"
#include "safe_memory_pool.h"

namespace memorysystem {

safe_memory_pool::safe_memory_pool(DWORD dw_max_pool_size_)
{
	dw_max_memory_size = dw_max_pool_size_;
	dw_current_memory_size = 0;
	dw_alloc_num = 0;
	dw_reclaim_num = 0;
	_lock = 0;
	ZeroMemory(_pool, sizeof(_pool));
}


safe_memory_pool::~safe_memory_pool()
{
	for( int n=0; n<16; n++ )
	{
		while( _pool[n].p_first )
		{
			tag_memory_node* p_node = _pool[n].p_first;
			_pool[n].p_first = _pool[n].p_first->p_next;
			free(p_node);
		}
	}
}

} // namespace memorysystem {
