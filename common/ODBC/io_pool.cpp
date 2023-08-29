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

io_pool::io_pool(INT n_defult_size_)
	: n_defult_size(n_defult_size_), n_io_num(0)
{
	real_alloc(n_defult_size);
}

io_pool::~io_pool()
{
	free_all_memory();
}

//------------------------------------------------------------------------------------------------------------
// �����ڴ�
//------------------------------------------------------------------------------------------------------------
void io_pool::real_alloc(INT n_num)
{
	if( n_num <= 0 ) return;

	mutex.lock();
	for(INT n = 0; n < n_num; n++)
	{
		sql_language_disposal* pStream = new sql_language_disposal();
		if( null == pStream ) break;

		idlesse_queue.add(pStream);
		Interlocked_Exchange_Add((LPLONG)&n_io_num, 1);
	}
	mutex.un_lock();
}

//-------------------------------------------------------------------------------------------------------------
// �ͷ��ڴ�
//-------------------------------------------------------------------------------------------------------------
void io_pool::real_free(INT n_num)
{
	if( n_num <= 0 ) return;

	mutex.lock();
	for(INT n = 0; n < n_num; n++)
	{
		sql_language_disposal* pStream = idlesse_queue.get();
		if( pStream )
		{
			SAFE_DELETE(pStream);
			Interlocked_Exchange_Add((LPLONG)&n_io_num, -1);
		}
	}
	mutex.un_lock();
}

//-------------------------------------------------------------------------------------------------------------
// �ͷ������ڴ�
//-------------------------------------------------------------------------------------------------------------
void io_pool::free_all_memory()
{
	while( n_io_num != 0 )
	{
		sql_language_disposal* pStream = idlesse_queue.get();
		if( null == pStream ) continue;

		SAFE_DELETE(pStream);
		Interlocked_Exchange_Add((LPLONG)&n_io_num, -1);
	}
}

//-------------------------------------------------------------------------------------------------------------
// ȡ���ڴ棬���û�У�������
//--------------------------------------------------------------------------------------------------------------
sql_language_disposal* io_pool::alloc_io()
{
	sql_language_disposal* pStream = idlesse_queue.get();

	while( null == pStream )
	{
		real_alloc(n_defult_size);
		pStream = idlesse_queue.get();
	}

	return pStream;
}

//---------------------------------------------------------------------------------------------------------------
// �����ڴ�
//----------------------------------------------------------------------------------------------------------------
void io_pool::free_io(sql_language_disposal* pStream)
{
	if( null == pStream ) return;

	idlesse_queue.add(pStream);

	// ������̫����ڴ棬 �ͷ�һЩ
	INT nSize = idlesse_queue.size();
	if( nSize >= 8 * n_defult_size )
	{
		real_free(nSize/4);
	}
}

} // namespace odbc
