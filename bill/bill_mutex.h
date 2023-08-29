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
*	@file		bill_mutex.h
*	@author		lc
*	@date		2011/02/23	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef BILL_MUTEX
#define BILL_MUTEX

class bill_mutex
{
public:

	bill_mutex()				{	InitializeCriticalSection(&cs);	}
	~bill_mutex()				{	DeleteCriticalSection(&cs);		}

	VOID acquire()			{	EnterCriticalSection(&cs);		}
	VOID release()			{	LeaveCriticalSection(&cs);		}
	BOOL attempt_acquire()	{	return TryEnterCriticalSection(&cs);	}

private:
	 
	CRITICAL_SECTION cs;
};
#endif
