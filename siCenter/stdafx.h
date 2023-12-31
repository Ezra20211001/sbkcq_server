// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#ifndef STDAFX_
#define STDAFX_



// TODO: 在此处引用程序需要的其他头文件
#pragma warning(disable:4311)
#pragma warning(disable:4267)
#pragma warning(disable:4312)

//-----------------------------------------------------------------------------
// 引用底层引擎
//-----------------------------------------------------------------------------

#define _WIN32_WINNT 0x0403
#define _USE_D3D7_

#include "..\common\ODBC\ODBC.h"
#include "..\common\network\network_define.h"
using namespace serverbase;
using namespace odbc; 
using namespace networkbase;


#ifdef _DEBUG
//#pragma comment(lib,"..\\vsout\\ODBC\\debug\\ODBC.lib")
#else
//#pragma comment(lib,"..\\vsout\\ODBC\\release\\ODBC.lib")
#endif

#ifdef _DEBUG
//#pragma comment(lib,"..\\vsout\\network\\debug\\network.lib")
#else
//#pragma comment(lib,"..\\vsout\\network\\release\\network.lib")
#endif

#ifdef _DEBUG
//#pragma comment(lib,"..\\vsout\\ServerDefine\\debug\\ServerDefine.lib")
#else
//#pragma comment(lib,"..\\vsout\\ServerDefine\\release\\ServerDefine.lib")
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


//extern "C"
//{
//#include "..\common\jpeglib\jpeglib.h"
//};

#pragma comment(lib,"Ws2_32.lib")
#pragma comment(lib,"winmm.lib")

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

#include "Mutex.h"

#include "../common/WorldDefine/base_define.h"
#include "../common/WorldDefine/protocol_common_errorcode.h"


#include "zlib\zlib.h"

#ifdef _DEBUG
#pragma comment(lib, "zlib\\zlibd.lib")
#else
#pragma comment(lib, "zlib\\zlib.lib")
#endif

#endif