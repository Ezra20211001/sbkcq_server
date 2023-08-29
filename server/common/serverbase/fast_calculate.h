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
*	@file		fast_calculate.h
*	@author		lc
*	@date		2011/02/21	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef FAST_CALCULATE
#define FAST_CALCULATE

namespace serverbase{

class SERVERBASE_API fast_calculate
{
public:
	__forceinline INT float_to_int(FLOAT f_);
	__forceinline BYTE float_to_byte(FLOAT f_);

	__forceinline FLOAT fast_abs(FLOAT f_);

	// ! 求平方根
	__forceinline FLOAT fast_square_root(FLOAT f_);

	// ! 求反平方根
	__forceinline FLOAT fast_reverse_square_root(FLOAT f_);

	__forceinline VOID memory_copy( void* dest_, const void* src_, INT n_count_ );

	fast_calculate() { square_table();	}

private:
	UINT n_fast_square_table[0x10000];

	//! 建立平方根对照表
	__forceinline VOID square_table();
};


//-----------------------------------------------------------------------------
// ! 建立平方根对照表
//-----------------------------------------------------------------------------
VOID fast_calculate::square_table()
{
	UINT i;
	union{FLOAT f; UINT i;} s;

	for( i = 0; i <= 0x7FFF; i++ )
	{
		s.i = (i << 8) | (0x7F << 23);
		s.f = (FLOAT) sqrt(s.f);

		n_fast_square_table[i + 0x8000] = (s.i & 0x7FFFFF);

		s.i = (i << 8) | (0x80 << 23);
		s.f = (FLOAT) sqrt(s.f);

		n_fast_square_table[i] = (s.i & 0x7FFFFF);
	}
}

__forceinline INT fast_calculate::float_to_int(FLOAT f_)	
{ 
	INT t;  
	__asm fld f_
	__asm fistp t
	return t; 


}	

__forceinline BYTE fast_calculate::float_to_byte(FLOAT f_)
{ 	
	float t; 
	t = f_ + (float)0xC00000; 
	return * (BYTE *) &t;	
}

__forceinline FLOAT fast_calculate::fast_abs(FLOAT f_) 
{
	__asm fld f_
	__asm fabs
	return f_; 
}

#define SI_BITS_(fp) (* (DWORD *) &(fp))
__forceinline FLOAT fast_calculate::fast_square_root(FLOAT f_)
{
	if (SI_BITS_(f_) == 0) 
		return 0.0f; 

	SI_BITS_(f_) = n_fast_square_table[(SI_BITS_(f_) >> 8) & 0xFFFF] | 
		((((SI_BITS_(f_) - 0x3F800000) >> 1) + 0x3F800000) & 0x7F800000);
	return f_;
}
#undef SI_BITS_

__forceinline FLOAT fast_calculate::fast_reverse_square_root(FLOAT f_)
{
#pragma warning (disable : 4244)
	LONG i;
	FLOAT x2, y;
	CONST FLOAT threehalfs = 1.5f;

	x2 = f_ * 0.5f;
	y = f_;
	i = * (LONG*) &y;
	i = 0x5f3759df - (i >> 1);
	y = * (LONG*) &i;
	y = y * (threehalfs - (x2 * y * y));

	return y;
#pragma warning (default : 4244)
}


#define MIN_BLOCK_COYP 64       
#define CACHE_COPY 64 * 1024  
#define UN_CACHE_COPY 197 * 1024 
#define CACHE_BLOCK 80h
__forceinline VOID fast_calculate::memory_copy( void* dest_, const void* src_, INT n_count_ )
{
	__asm 
	{
		mov		ecx, [n_count_]	; number of bytes to copy
		mov		edi, [dest_]		; destination
		mov		esi, [src_]		; source
		mov		ebx, ecx		; keep a copy of count

		cld
		cmp		ecx, MIN_BLOCK_COYP
		jb		$memcpy_ic_3	; tiny? skip mmx copy

		cmp		ecx, 32*1024		; don't align between 32k-64k because
		jbe		$memcpy_do_align	;  it appears to be slower
		cmp		ecx, 64*1024
		jbe		$memcpy_align_done
	$memcpy_do_align:
		mov		ecx, 8			; a trick that's faster than rep movsb...
		sub		ecx, edi		; align destination to qword
		and		ecx, 111b		; get the low bits
		sub		ebx, ecx		; update copy count
		neg		ecx				; set up to jump into the array
		add		ecx, offset $memcpy_align_done
		jmp		ecx				; jump to array of movsb's

	align 4
		movsb
		movsb
		movsb
		movsb
		movsb
		movsb
		movsb
		movsb

	$memcpy_align_done:			; destination is dword aligned
		mov		ecx, ebx		; number of bytes left to copy
		shr		ecx, 6			; get 64-byte block count
		jz		$memcpy_ic_2	; finish the last few bytes

		cmp		ecx, CACHE_COPY/64	; too big 4 cache? use uncached copy
		jae		$memcpy_uc_test

	
	align 16
	$memcpy_ic_1:			; 64-byte block copies, in-cache copy

		prefetchnta [esi + (200*64/34+192)]		; start reading ahead

		movq	mm0, [esi+0]	; read 64 bits
		movq	mm1, [esi+8]
		movq	[edi+0], mm0	; write 64 bits
		movq	[edi+8], mm1	;    note:  the normal movq writes the
		movq	mm2, [esi+16]	;    data to cache; a cache line will be
		movq	mm3, [esi+24]	;    allocated as needed, to store the data
		movq	[edi+16], mm2
		movq	[edi+24], mm3
		movq	mm0, [esi+32]
		movq	mm1, [esi+40]
		movq	[edi+32], mm0
		movq	[edi+40], mm1
		movq	mm2, [esi+48]
		movq	mm3, [esi+56]
		movq	[edi+48], mm2
		movq	[edi+56], mm3

		add		esi, 64			; update source pointer
		add		edi, 64			; update destination pointer
		dec		ecx				; count down
		jnz		$memcpy_ic_1	; last 64-byte block?

	$memcpy_ic_2:
		mov		ecx, ebx		; has valid low 6 bits of the byte count
	$memcpy_ic_3:
		shr		ecx, 2			; dword count
		and		ecx, 1111b		; only look at the "remainder" bits
		neg		ecx				; set up to jump into the array
		add		ecx, offset $memcpy_last_few
		jmp		ecx				; jump to array of movsd's

	$memcpy_uc_test:
		cmp		ecx, UN_CACHE_COPY/64	; big enough? use block prefetch copy
		jae		$memcpy_bp_1

	$memcpy_64_test:
		or		ecx, ecx		; tail end of block prefetch will jump here
		jz		$memcpy_ic_2	; no more 64-byte blocks left

	align 16
	$memcpy_uc_1:				; 64-byte blocks, uncached copy

		prefetchnta [esi + (200*64/34+192)]		; start reading ahead

		movq	mm0,[esi+0]		; read 64 bits
		add		edi,64			; update destination pointer
		movq	mm1,[esi+8]
		add		esi,64			; update source pointer
		movq	mm2,[esi-48]
		movntq	[edi-64], mm0	; write 64 bits, bypassing the cache
		movq	mm0,[esi-40]	;    note: movntq also prevents the CPU
		movntq	[edi-56], mm1	;    from READING the destination address
		movq	mm1,[esi-32]	;    into the cache, only to be over-written
		movntq	[edi-48], mm2	;    so that also helps performance
		movq	mm2,[esi-24]
		movntq	[edi-40], mm0
		movq	mm0,[esi-16]
		movntq	[edi-32], mm1
		movq	mm1,[esi-8]
		movntq	[edi-24], mm2
		movntq	[edi-16], mm0
		dec		ecx
		movntq	[edi-8], mm1
		jnz		$memcpy_uc_1	; last 64-byte block?

		jmp		$memcpy_ic_2		; almost done

	$memcpy_bp_1:			; large blocks, block prefetch copy

		cmp		ecx, CACHE_BLOCK			; big enough to run another prefetch loop?
		jl		$memcpy_64_test			; no, back to regular uncached copy

		mov		eax, CACHE_BLOCK / 2		; block prefetch loop, unrolled 2X
		add		esi, CACHE_BLOCK * 64	; move to the top of the block
	align 16
	$memcpy_bp_2:
		mov		edx, [esi-64]		; grab one address per cache line
		mov		edx, [esi-128]		; grab one address per cache line
		sub		esi, 128			; go reverse order to suppress HW prefetcher
		dec		eax					; count down the cache lines
		jnz		$memcpy_bp_2		; keep grabbing more lines into cache

		mov		eax, CACHE_BLOCK		; now that it's in cache, do the copy
	align 16
	$memcpy_bp_3:
		movq	mm0, [esi   ]		; read 64 bits
		movq	mm1, [esi+ 8]
		movq	mm2, [esi+16]
		movq	mm3, [esi+24]
		movq	mm4, [esi+32]
		movq	mm5, [esi+40]
		movq	mm6, [esi+48]
		movq	mm7, [esi+56]
		add		esi, 64				; update source pointer
		movntq	[edi   ], mm0		; write 64 bits, bypassing cache
		movntq	[edi+ 8], mm1		;    note: movntq also prevents the CPU
		movntq	[edi+16], mm2		;    from READING the destination address 
		movntq	[edi+24], mm3		;    into the cache, only to be over-written,
		movntq	[edi+32], mm4		;    so that also helps performance
		movntq	[edi+40], mm5
		movntq	[edi+48], mm6
		movntq	[edi+56], mm7
		add		edi, 64				; update dest pointer

		dec		eax					; count down

		jnz		$memcpy_bp_3		; keep copying
		sub		ecx, CACHE_BLOCK		; update the 64-byte block count
		jmp		$memcpy_bp_1		; keep processing chunks

	align 4
		movsd
		movsd			; perform last 1-15 dword copies
		movsd
		movsd
		movsd
		movsd
		movsd
		movsd
		movsd
		movsd			; perform last 1-7 dword copies
		movsd
		movsd
		movsd
		movsd
		movsd
		movsd

	$memcpy_last_few:		; dword aligned from before movsd's
		mov		ecx, ebx	; has valid low 2 bits of the byte count
		and		ecx, 11b	; the last few cows must come home
		jz		$memcpy_final	; no more, let's leave
		rep		movsb		; the last 1, 2, or 3 bytes

	$memcpy_final: 
		emms				; clean up the MMX state
		sfence				; flush the write buffer
	}
}

} // namespace serverbase {
#endif
