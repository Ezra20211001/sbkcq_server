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
*	@file		base_define.h
*	@author		lc
*	@date		2011/02/22	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef BASE_DEFINE
#define BASE_DEFINE


#ifndef UNICODE
	#define _UNICODE
	#define  UNICODE
#endif

#define HUGE_STRING		512
#define LONG_STRING		256
#define SHORT_STRING		32


#define INVALID_VALUE				(-1)
#define VALID_VALUE(n)				(((INT)(n)) != INVALID_VALUE)
#define VALID_POINT(n)				( (((INT)(n)) != INVALID_VALUE) && ((n) != NULL) )

#define FILE_SEEK_SET				0
#define FILE_SEEK_CURRENT			1
#define FILE_SEEK_END				2

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)				{ if(p) { delete(p);		(p) = NULL; } }
#endif
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p)		{ if(p) { delete[](p);		(p) = NULL; } }
#endif
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)			{ if(p) { (p)->Release();	(p) = NULL; } }
#endif
#ifndef SAFE_CLOSE_HANDLE
#define SAFE_CLOSE_HANDLE(h)	{ if(h) { CloseHandle(h);	(h) = NULL; } }
#endif
#ifndef ASSERT
#define ASSERT(f)				assert((f))
#endif

#ifdef _UNICODE
typedef std::wstring		tstring;
typedef std::wstringstream	tstringstream;
typedef std::wstreambuf		tstreambuf;
#else
typedef std::string			tstring;
typedef std::stringstream	tstringstream;
typedef std::streambuf		tstreambuf;
#endif

struct lua_State;

//extern "C"
//{
//	LONG  __cdecl _InterlockedIncrement(LONG volatile *Addend);
//	LONG  __cdecl _InterlockedDecrement(LONG volatile *Addend);
//	LONG  __cdecl _InterlockedCompareExchange(long volatile* Dest, long Exchange, long Comp);
//	LONG  __cdecl _InterlockedExchange(LPLONG volatile Target, LONG Value);
//	LONG  __cdecl _InterlockedExchangeAdd(LPLONG volatile Addend, LONG Value);
//}

#pragma intrinsic (_InterlockedCompareExchange)
#define Interlocked_Compare_Exchange _InterlockedCompareExchange

#pragma intrinsic (_InterlockedExchange)
#define Interlocked_Exchange _InterlockedExchange 

#pragma intrinsic (_InterlockedExchangeAdd)
#define Interlocked_Exchange_Add _InterlockedExchangeAdd

#pragma intrinsic (_InterlockedIncrement)
#define Interlocked_Increment _InterlockedIncrement

#pragma intrinsic (_InterlockedDecrement)
#define Interlocked_Decrement _InterlockedDecrement

#ifndef SERVERBASE_EXPORTS
#define SERVERBASE_EXPORTS
#endif

#ifdef SERVERBASE_EXPORTS
#define SERVERBASE_API __declspec(dllexport)
#else
#define SERVERBASE_API __declspec(dllimport)
#endif

#endif

namespace serverbase{

	class error_alarm;
	class file_io_manager;
	class fast_calculate;
	class file_filter;
	class tool;

	typedef UINT (WINAPI* THREAD_PROC)(LPVOID);

	extern SERVERBASE_API const unsigned long	crc32_table[256];
	extern SERVERBASE_API const unsigned short	crc16_table[256];

	extern SERVERBASE_API error_alarm*  g_palarm;
	extern SERVERBASE_API file_io_manager* g_pfile_io_mgr;
	extern SERVERBASE_API tool*		 g_ptool;
	extern SERVERBASE_API fast_calculate*	 g_pfast_code;

	SERVERBASE_API BOOL init_serverbase();
	SERVERBASE_API VOID destroy_serverbase();
	SERVERBASE_API BOOL init_network();		
	SERVERBASE_API VOID destroy_network();	


	SERVERBASE_API file_io_manager* get_file_io_mgr();
	SERVERBASE_API tool* get_tool();
	SERVERBASE_API fast_calculate* get_fast_code();

}	// namespace serverbase{


