/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#pragma once

#define _CRT_SECURE_NO_DEPRECATE


#pragma warning(disable:4355)
#pragma warning(disable:4251)
#pragma warning(disable:4996)

#define WIN32_LEAN_AND_MEAN

#ifdef SERVERBASE_LIB
	#define  _USE_D3D7_
	#if _WIN32_WINNT < 0x0500
	#undef _WIN32_WINNT
	#define _WIN32_WINNT 0x0500
	#endif 
#else
	#ifdef SERVERBASE_EXPORTS
		#define  _USE_D3D7_
		#if _WIN32_WINNT < 0x0500
			#undef _WIN32_WINNT
			#define _WIN32_WINNT 0x0500
		#endif 
	#endif 
#endif 

#pragma comment(lib,"winmm.lib")
//#pragma comment(lib,"dsound.lib")
//#pragma comment(lib,"dxguid.lib")
//#pragma comment(lib,"ddraw.lib")
//#pragma comment(lib,"dinput.lib")
#pragma comment(lib,"Mswsock.lib")
#pragma comment(lib,"Ws2_32.lib")
#pragma comment(lib,"odbc32.lib")
#pragma comment(lib,"odbccp32.lib")
#pragma comment(lib,"comctl32.lib")

// #ifdef _DEBUG
// #pragma comment(lib,"..\\vsout\\Lua\\debug\\Lua.lib")
// #else
// #pragma comment(lib,"..\\vsout\\Lua\\release\\Lua.lib")
// #endif

#include <windows.h>
#include <commctrl.h>
#include <ctype.h>
#include <time.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <mswsock.h>
#include <wininet.h>
#include <shlwapi.h>
#include <process.h>	
#include <mmsystem.h>
#include <tchar.h>
#include <assert.h>
#include <eh.h>			
#include <math.h>
#include <new.h>
//#include <dinput.h>
//#include <ddraw.h>
//#include <dsound.h>
//#include <dmusici.h>
#include <ShellAPI.h>

#ifdef _USE_D3D7_
	//#include <d3d.h>
#endif

#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <queue>
#include <algorithm>


extern HINSTANCE g_hInstance; 

#include "base_define.h"


#include "tool.h"
#include "error_alarm.h"
#include "FastDelegate.h"
#include "FastDelegateBind.h"
#include "base64.h"