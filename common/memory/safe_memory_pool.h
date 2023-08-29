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

#ifndef SAFE_MEMORY_POOL
#define SAFE_MEMORY_POOL

namespace memorysystem {

class MEMORY_API safe_memory_pool
{
public:
	__forceinline LPVOID	alloc_memory(DWORD dw_bytes_);
	__forceinline VOID		free_memory(LPVOID p_memory_);
	__forceinline LPVOID	try_alloc_memory(DWORD dw_bytes_);	
	__forceinline BOOL		try_free_memory(LPVOID p_memory_);		
	__forceinline VOID		set_max_memory_size(DWORD dw_size) { dw_max_memory_size = dw_size; }
	__forceinline DWORD		get_current_size() { return dw_current_memory_size; }
	__forceinline DWORD		get_alloc_num() { return dw_alloc_num; }
	__forceinline DWORD		get_reclaim_num() { return dw_reclaim_num; }

	safe_memory_pool(DWORD dw_max_pool_size_=16*1024*1024);
	~safe_memory_pool();

private:
	//�� �ڴ��
	struct tag_memory_node	
	{
		tag_memory_node*	p_next;
		tag_memory_node*	p_previous;
		INT			n_index;
		DWORD		dw_size;
		DWORD		dw_use_num;
		DWORD		p_memory[1];	//�� ʵ���ڴ�
	};

	struct
	{
		tag_memory_node*	p_first;
		tag_memory_node*	p_last;
	} _pool[16];

	DWORD dw_max_memory_size;		//�� ������������ڴ�
	DWORD dw_alloc_num;			//! �����ڴ����
	DWORD dw_reclaim_num;		//! �ڴ���մ���

	DWORD volatile 	dw_current_memory_size;	// ����ǰ�����ڴ�
	LONG volatile 	_lock;

	__forceinline VOID lock() { while(Interlocked_Compare_Exchange((long*)&_lock, 1, 0)!= 0) Sleep(0); }
	__forceinline VOID unlock() { Interlocked_Exchange((LPLONG)(&_lock), 0); }
	__forceinline bool try_lock() { return Interlocked_Compare_Exchange((long*)(&_lock), 1, 0) == 0;	}

	//! �ڴ����
	__forceinline VOID memory_reclaim(DWORD dw_reclaim_size_, DWORD dw_use_num_);
	//�������ڴ�ƥ��Ĵ�С
	__forceinline INT get_size_index(DWORD dw_size_, DWORD& dw_fact_size_);
};


//-----------------------------------------------------------------------------
// ! �����ڴ�
//-----------------------------------------------------------------------------
LPVOID safe_memory_pool::alloc_memory(DWORD dw_bytes_)
{
	DWORD dw_fact_size = 0;
	INT n_index = get_size_index(dw_bytes_, dw_fact_size);
	if( INVALID_VALUE != n_index )
	{
		if( _pool[n_index].p_first )	
		{
			lock();
			if( _pool[n_index].p_first )	//! ����ڴ�������ڴ棬�ʹӳ��������
			{
				tag_memory_node* p_node = _pool[n_index].p_first;
				_pool[n_index].p_first = _pool[n_index].p_first->p_next;
				if( _pool[n_index].p_first )
					_pool[n_index].p_first->p_previous = NULL;
				else
					_pool[n_index].p_last = NULL;
				dw_current_memory_size -= dw_fact_size;
				++p_node->dw_use_num;
				unlock();
				return p_node->p_memory;	
			}
			unlock();
		}
	}

	++dw_alloc_num;
	tag_memory_node* p_node = (tag_memory_node*)malloc(dw_fact_size + sizeof(tag_memory_node) - sizeof(DWORD));
	if( !p_node )
		return NULL;

	p_node->n_index = n_index;
	p_node->dw_size = dw_fact_size;
	p_node->p_next = NULL;
	p_node->p_previous = NULL;
	p_node->dw_use_num = 0;
	return p_node->p_memory;	//! ���ط�����ڴ�
}


//-----------------------------------------------------------------------------
// ! �ͷ��ڴ�
//-----------------------------------------------------------------------------
VOID safe_memory_pool::free_memory(LPVOID p_memory_)
{
	tag_memory_node* p_node = (tag_memory_node*)(((LPBYTE)p_memory_) - sizeof(tag_memory_node) + sizeof(DWORD));
	if( INVALID_VALUE != p_node->n_index )
	{
		lock();
		if( p_node->dw_size + dw_current_memory_size > dw_max_memory_size && p_node->dw_use_num > 0 )
			memory_reclaim(p_node->dw_size*2, p_node->dw_use_num);	// �����ռ�

		if( p_node->dw_size + dw_current_memory_size <= dw_max_memory_size ) // �ڴ�ؿ�������
		{
			p_node->p_previous = NULL;
			p_node->p_next = _pool[p_node->n_index].p_first;
			if( _pool[p_node->n_index].p_first )
				_pool[p_node->n_index].p_first->p_previous = p_node;
			else
				_pool[p_node->n_index].p_last = p_node;

			_pool[p_node->n_index].p_first = p_node;
			dw_current_memory_size += p_node->dw_size;
			unlock();
			return;
		}
		unlock();
	}

	free(p_node);
}


//-----------------------------------------------------------------------------
// ! �����ڴ�
//-----------------------------------------------------------------------------
LPVOID safe_memory_pool::try_alloc_memory(DWORD dw_bytes_)
{
#if _WIN32_WINNT < 0x0400
	return alloc_memory(dw_bytes_);
#else
	DWORD dw_fact_size = 0;
	INT n_index = get_size_index(dw_bytes_, dw_fact_size);
	if( INVALID_VALUE != n_index )
	{
		if( !try_lock() )
			return NULL;

		if( _pool[n_index].p_first )	// �����У��ʹӳ������
		{
			tag_memory_node* p_node = _pool[n_index].p_first;
			_pool[n_index].p_first = _pool[n_index].p_first->p_next;
			if( _pool[n_index].p_first )
				_pool[n_index].p_first->p_previous = NULL;
			else
				_pool[n_index].p_last = NULL;
			dw_current_memory_size -= dw_fact_size;
			++p_node->dw_use_num;
			unlock();
			return p_node->p_memory;	
		}
		unlock();
	}

	++dw_alloc_num;
	tag_memory_node* p_node = (tag_memory_node*)malloc(dw_fact_size + sizeof(tag_memory_node) - sizeof(DWORD));
	if( !p_node )
		return NULL;

	p_node->n_index = n_index;
	p_node->dw_size = dw_fact_size;
	p_node->p_next = NULL;
	p_node->p_previous = NULL;
	p_node->dw_use_num = 0;
	return p_node->p_memory;	// ��ʵ���ڴ��з���
#endif


}


//-----------------------------------------------------------------------------
// ! �ͷ��ڴ�
//-----------------------------------------------------------------------------
BOOL safe_memory_pool::try_free_memory(LPVOID p_memory_)
{
#if _WIN32_WINNT < 0x0400
	free_memory(p_memory_);
	return TRUE;
#else
	tag_memory_node* p_node = (tag_memory_node*)(((LPBYTE)p_memory_) - sizeof(tag_memory_node) + sizeof(DWORD));
	if( INVALID_VALUE != p_node->n_index )
	{
		if( !try_lock() )
			return FALSE;

		if( p_node->dw_size + dw_current_memory_size > dw_max_memory_size && p_node->dw_use_num > 0 )
			memory_reclaim(p_node->dw_size*2, p_node->dw_use_num);	

		if( p_node->dw_size + dw_current_memory_size <= dw_max_memory_size ) 
		{
			p_node->p_previous = NULL;
			p_node->p_next = _pool[p_node->n_index].p_first;
			if( _pool[p_node->n_index].p_first )
				_pool[p_node->n_index].p_first->p_previous = p_node;
			else
				_pool[p_node->n_index].p_last = p_node;

			_pool[p_node->n_index].p_first = p_node;
			dw_current_memory_size += p_node->dw_size;
			unlock();
			return TRUE;
		}
		unlock();
	}
	free(p_node);
	return TRUE;
#endif
}



//-----------------------------------------------------------------------------
// ! �ڴ����
//-----------------------------------------------------------------------------
VOID safe_memory_pool::memory_reclaim(DWORD dw_reclaim_size_, DWORD dw_use_num_)
{
	++dw_reclaim_num;
	DWORD dw_free_size = 0;
	for(INT n=15; n>=0; --n)	
	{
		if( !_pool[n].p_first )
			continue;

		tag_memory_node* p_node = _pool[n].p_last; 
		while( p_node )
		{
			tag_memory_node* pTempNode = p_node;
			p_node = p_node->p_previous;
			if( pTempNode->dw_use_num < dw_use_num_ )	
			{
				if( p_node )
					p_node->p_next = pTempNode->p_next;
				if( pTempNode->p_next )
					pTempNode->p_next->p_previous = p_node;
				if( _pool[n].p_last == pTempNode )
					_pool[n].p_last = p_node;
				if( _pool[n].p_first == pTempNode )
					_pool[n].p_first = pTempNode->p_next;

				dw_current_memory_size -= pTempNode->dw_size;
				dw_free_size += pTempNode->dw_size;
				free(pTempNode);
			}

			if( dw_free_size >= dw_reclaim_size_ )
				return;
		}
	}
}


//-----------------------------------------------------------------------------
// ! ʵ�ʷ�����ڴ��С
//-----------------------------------------------------------------------------
INT safe_memory_pool::get_size_index(DWORD dw_size_, DWORD& dw_fact_size_)
{
	if( dw_size_<=32 )		{ dw_fact_size_ = 32;			return 0; }
	if( dw_size_<=64 )		{ dw_fact_size_ = 64;			return 1; }
	if( dw_size_<=128 )		{ dw_fact_size_ = 128;			return 2; }
	if( dw_size_<=256 )		{ dw_fact_size_ = 256;			return 3; }
	if( dw_size_<=512 )		{ dw_fact_size_ = 512;			return 4; }
	if( dw_size_<=1024 )		{ dw_fact_size_ = 1024;		return 5; }
	if( dw_size_<=2*1024 )	{ dw_fact_size_ = 2*1024;		return 6; }
	if( dw_size_<=4*1024 )	{ dw_fact_size_ = 4*1024;		return 7; }
	if( dw_size_<=8*1024 )	{ dw_fact_size_ = 8*1024;		return 8; }
	if( dw_size_<=16*1024 )	{ dw_fact_size_ = 16*1024;		return 9; }
	if( dw_size_<=32*1024 )	{ dw_fact_size_ = 32*1024;		return 10; }
	if( dw_size_<=64*1024 )	{ dw_fact_size_ = 64*1024;		return 11; }
	if( dw_size_<=128*1024 )	{ dw_fact_size_ = 128*1024;	return 12; }
	if( dw_size_<=256*1024 )	{ dw_fact_size_ = 256*1024;	return 13; }
	if( dw_size_<=512*1024 )	{ dw_fact_size_ = 512*1024;	return 14; }
	if( dw_size_<=1024*1024 )	{ dw_fact_size_ = 1024*1024;	return 15; }
	dw_fact_size_ = dw_size_;
	return INVALID_VALUE;
}
} // namespace memorysystem {
#endif
