/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#include "StdAfx.h"
#include "sql_language_disposal.h"
#include "io_safe_queue.h"

namespace odbc
{
//--------------------------------------------------------------------------------------------------------
// Îö¹¹º¯Êý
//--------------------------------------------------------------------------------------------------------
io_safe_queue::~io_safe_queue()
{
	if( h_event )
		::CloseHandle(h_event);
}

} // namespace odbc