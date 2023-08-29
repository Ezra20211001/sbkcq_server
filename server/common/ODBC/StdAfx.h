#pragma once

#pragma warning(disable:4355)	// Level 3: "this": 用于基成员初始值设定项列表
#pragma warning(disable:4251)	// Level 3: need to have dll-interface
#pragma warning(disable:4244)
#pragma warning(disable:4996)
#pragma warning(disable:4311)
#pragma warning(disable:4312)
#pragma warning(disable:4267)
#pragma warning(disable:4245)
#pragma warning(disable:4100)
#pragma warning(disable:4201)
#pragma warning(disable:4127)

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT 0x0403 

#include "..\serverbase\serverbase.h"
using namespace serverbase;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\serverbase\\debug\\serverbase.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\serverbase\\release\\serverbase.lib")
#endif

#include "..\dump\dump_define.h"
using namespace serverdump;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\dump\\debug\\dump.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\dump\\release\\dump.lib")
#endif

#include "..\filesystem\file_define.h"
using namespace filesystem;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\filesystem\\debug\\filesystem.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\filesystem\\release\\filesystem.lib")
#endif

#include <windows.h>
#include <tchar.h>
#include <ctype.h>
#include <assert.h>

#include <string>
#include <list>

#include "mysql.h"
#pragma comment(lib,"libmysql.lib")

#if defined _UNICODE
#define sstring std::wstring
#else
#define sstring std::string
#endif

typedef unsigned long u_long;

#define initialize_critical_section_and_spin_count ::InitializeCriticalSectionAndSpinCount
#define delete_critical_section ::DeleteCriticalSection
#define try_enter_critical_section ::TryEnterCriticalSection
#define enter_critical_section ::EnterCriticalSection
#define leave_critical_section ::LeaveCriticalSection
#define critical_section CRITICAL_SECTION
#define mysql_res MYSQL_RES 
#define mysql_field MYSQL_FIELD
#define mysql_row MYSQL_ROW
#define multi_byte_to_wide_char MultiByteToWideChar
#define wide_char_to_multi_byte WideCharToMultiByte
#define create_event ::CreateEvent
#define win_api WINAPI
#define mysql MYSQL
#define get_module_file_name GetModuleFileName
#define get_system_time_as_file_time GetSystemTimeAsFileTime
#define file_time_to_local_file_time FileTimeToLocalFileTime
#define file_time_to_dos_date_time FileTimeToDosDateTime
#define get_current_process_id GetCurrentProcessId

#define null NULL


#define ODBC_EXPORTS
#ifdef ODBC_EXPORTS
#define odbc_api __declspec(dllexport)
#else
#define odbc_api __declspec(dllimport)
#endif