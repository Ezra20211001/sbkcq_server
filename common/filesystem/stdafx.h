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
#include "..\serverbase\serverbase.h"
using namespace serverbase;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\serverbase\\debug\\serverbase.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\serverbase\\release\\serverbase.lib")
#endif

#define FILE_EXPORTS
#ifdef FILE_EXPORTS
#define FILE_API __declspec(dllexport)
#else
#define FILE_API __declspec(dllimport)
#endif

#include "file_system.h"
#include "log_file.h"
#include "file_container.h"
#include "tinyXml.h"



