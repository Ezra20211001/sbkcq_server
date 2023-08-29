// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once


// 屏蔽一些警告
#pragma warning(disable:4355)// Level 3: "this": 用于基成员初始值设定项列表
#pragma warning(disable:4251)// Level 3: need to have dll-interface
#pragma warning(disable:4996)

#define WIN32_LEAN_AND_MEAN

#include "..\serverbase\serverbase.h"
using namespace serverbase;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\serverbase\\debug\\serverbase.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\serverbase\\release\\serverbase.lib")
#endif

#define MEMORY_EXPORTS
#ifdef MEMORY_EXPORTS
#define MEMORY_API __declspec(dllexport)
#else
#define MEMORY_API __declspec(dllimport)
#endif

#include "memory_pool.h"
#include "safe_memory_pool.h"




// TODO: 在此处引用程序需要的其他头文件
