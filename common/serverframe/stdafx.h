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


#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����



// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
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

