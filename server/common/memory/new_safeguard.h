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
*	@file		new_safeguard.h
*	@author		lc
*	@date		2011/02/21	initial
*	@version	0.0.1.0
*	@brief		
*/

// ! new·µ»ØÖµ¼ì²é

#ifndef NEW_SAFEGUARD
#define NEW_SAFEGUARD

namespace memorysystem {

inline INT new_disposal( size_t size_ )
{
	g_palarm->error_export(_T("(malloc or new) %lu bytes assign failed\r\n"), size_);
	return 1;
}

inline VOID MEMORY_API init_new_protect()
{
	_set_new_handler( new_disposal );	
	_set_new_mode(1);	
}

}
#endif
