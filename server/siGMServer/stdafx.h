// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#pragma warning(disable:4311)
#pragma warning(disable:4267)
#pragma warning(disable:4312)


//---------------------------------------------------------------------
// Server
//---------------------------------------------------------------------
#define _WIN32_WINNT 0x0403
#define _USE_D3D7_

#include "..\common\serverframe\frame_define.h"
#include "..\common\filesystem\file_define.h"
#include "..\common\dump\dump_define.h"
#include "..\common\network\network_define.h"
#include "..\common\serverbase\serverbase.h"
#include "..\common\odbc\odbc.h"

using namespace serverbase;
using namespace networkbase;
using namespace serverdump;
using namespace odbc;
using namespace serverframe;
using namespace filesystem;

#ifdef _DEBUG
	#define X_STRING_RUN_TIME "Debug"
// 	#pragma comment(lib, "../vsout/ODBC/debug/ODBC.lib")
// 	#pragma comment(lib, "../vsout/network/debug/network.lib")
	//#pragma comment(lib, "../vsout/ServerDefine/debug/ServerDefine.lib")
	//#pragma comment(lib,"..\\vsout\\dump\\debug\\dump.lib")
	//#pragma comment(lib,"..\\vsout\\serverframe\\debug\\serverframe.lib")
	//#pragma comment(lib,"..\\vsout\\filesystem\\debug\\filesystem.lib")
	//#pragma comment(lib,"..\\vsout\\serverbase\\debug\\serverbase.lib")
#else
	#define X_STRING_RUN_TIME "Release"
// 	#pragma comment(lib, "../vsout/ODBC/release/ODBC.lib")
// 	#pragma comment(lib, "../vsout/network/release/network.lib")
	//#pragma comment(lib, "../vsout/ServerDefine/release/ServerDefine.lib")
	//#pragma comment(lib,"..\\vsout\\dump\\release\\dump.lib")
	//#pragma comment(lib,"..\\vsout\\serverframe\\release\\serverframe.lib")
	//#pragma comment(lib,"..\\vsout\\filesystem\\release\\filesystem.lib")
	//#pragma comment(lib,"..\\vsout\\serverbase\\release\\serverbase.lib")
#endif

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
#include "../../common/WorldDefine/base_define.h"
#include "../../common/WorldDefine/protocol_common_errorcode.h"
#include "../common/ServerDefine/base_server_define.h"

#define ErrMessage ERROR_CLUE_ON
#define CON_LOST (0xdeadc000)
#define ErrLog g_GMServer.GetLogFile()->write_log

