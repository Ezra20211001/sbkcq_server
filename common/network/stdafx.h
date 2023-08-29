// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#define _CRT_SECURE_NO_DEPRECATE

// ����һЩ����
#pragma warning(disable:4355)// Level 3: "this": ���ڻ���Ա��ʼֵ�趨���б�
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

#include "..\serverframe\frame_define.h"
using namespace serverframe;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\serverframe\\debug\\serverframe.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\serverframe\\release\\serverframe.lib")
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

#include "..\filesystem\file_define.h"
using namespace filesystem;

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\filesystem\\debug\\filesystem.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\filesystem\\release\\filesystem.lib")
#endif

#ifdef _DEBUG
#define X_STRING_RUN_TIME "Debug"
//#pragma comment(lib,"..\\vsout\\dump\\debug\\dump.lib")
#else
#define X_STRING_RUN_TIME "Release"
//#pragma comment(lib,"..\\vsout\\dump\\release\\dump.lib")
#endif
#include "../dump/dump_define.h"
using namespace serverdump;

//#include "server_define.h"
#include "server_define.h"

#define win_api WINAPI 

#define NETWORK_EXPORTS
#ifdef NETWORK_EXPORTS
#define NETWORK_API __declspec(dllexport)
#else
#define NETWORK_API __declspec(dllimport)
#endif

