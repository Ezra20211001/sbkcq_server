// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#pragma warning(disable:4311)
#pragma warning(disable:4267)
#pragma warning(disable:4312)


//---------------------------------------------------------------------
// vEngine
//---------------------------------------------------------------------
#define _WIN32_WINNT 0x0403
#define _USE_D3D7_
#include "..\common\serverbase\serverbase.h"
using namespace serverbase;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\serverbase\\debug\\serverbase.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\serverbase\\release\\serverbase.lib")
#endif

#include "..\common\network\network_define.h"
using namespace networkbase;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\network\\debug\\network.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\network\\release\\network.lib")
#endif

#include "..\common\dump\dump_define.h"
using namespace serverdump;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\dump\\debug\\dump.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\dump\\release\\dump.lib")
#endif

#include "..\common\filesystem\file_define.h"
using namespace filesystem;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\filesystem\\debug\\filesystem.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\filesystem\\release\\filesystem.lib")
#endif

#include "..\common\serverframe\frame_define.h"
using namespace serverframe;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\serverframe\\debug\\serverframe.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\serverframe\\release\\serverframe.lib")
#endif

#include "..\common\odbc\odbc.h"
using namespace odbc; 

// #ifdef _DEBUG
// #define X_STRING_RUN_TIME "Debug"
// #pragma comment(lib, "..\\vsout\\ODBC\\debug\\ODBC.lib")
// #else
// #define X_STRING_RUN_TIME "Release"
// #pragma comment(lib,"..\\vsout\\ODBC\\release\\ODBC.lib")
// #endif

//-----------------------------------------------------------------------
// ServerDefine
//-----------------------------------------------------------------------
// #ifdef _DEBUG
// #pragma comment(lib,"..\\vsout\\ServerDefine\\debug\\ServerDefine.lib")
// #else
// #pragma comment(lib,"..\\vsout\\ServerDefine\\release\\ServerDefine.lib")
// #endif

//------------------------------------------------------------------------------
#pragma comment(lib,"Ws2_32.lib")
#pragma comment(lib,"winmm.lib")

//引用STL
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;


// TODO: 在此处引用程序需要的其他头文件
#include "../common/WorldDefine/base_define.h"
#include "../common/WorldDefine/protocol_common_errorcode.h"
#include "../common/ServerDefine/base_server_define.h"


