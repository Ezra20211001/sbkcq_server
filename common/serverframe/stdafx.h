// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#define _CRT_SECURE_NO_DEPRECATE

// 屏蔽一些警告
#pragma warning(disable:4355)// Level 3: "this": 用于基成员初始值设定项列表
#pragma warning(disable:4251)// Level 3: need to have dll-interface
#pragma warning(disable:4996)


#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料



// TODO: 在此处引用程序需要的其他头文件
// TODO: 在此处引用程序需要的其他头文件
#include "..\serverbase\serverbase.h"
using namespace serverbase;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\serverbase\\debug\\serverbase.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\serverbase\\release\\serverbase.lib")
#endif

#include "..\memory\memory_define.h"
using namespace memorysystem;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\memory\\debug\\memory.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\memory\\release\\memory.lib")
#endif

#define FRAME_EXPORTS
#ifdef FRAME_EXPORTS
#define FRAME_API __declspec(dllexport)
#else
#define FRAME_API __declspec(dllimport)
#endif

#include "rect.h"
#include "message_queue.h"
#include "safe_message_queue.h"
#include "package_map.h"
#include "package_list.h"
#include "package_safe_list.h"
#include "package_safe_map.h"
#include "net_define.h"
#include "singleton.h"
#include "window_frame.h"
#include "thread_manager.h"

