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
*	@file		mutex.h
*	@author		lc
*	@date		2011/01/19	initial
*	@version	0.0.1.0
*	@brief		
*/


// mutex Ïß³ÌËø

#ifndef ODBC_MUTEX
#define ODBC_MUTEX

#include "StdAfx.h"

namespace odbc {


class mutex
{
public:
	mutex()		{ if(FALSE == initialize_critical_section_and_spin_count(&cs, 4000)) { abort(); } }
	~mutex()	{ delete_critical_section(&cs); }

public:
	inline BOOL try_lock() { return try_enter_critical_section(&cs); }
	inline void lock() { enter_critical_section(&cs); }
	inline void un_lock() { leave_critical_section(&cs); }

private:
	critical_section cs;

};

} // namespace odbc
#endif