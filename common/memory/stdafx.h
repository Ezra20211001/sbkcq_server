// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once


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

#define MEMORY_EXPORTS
#ifdef MEMORY_EXPORTS
#define MEMORY_API __declspec(dllexport)
#else
#define MEMORY_API __declspec(dllimport)
#endif

#include "memory_pool.h"
#include "safe_memory_pool.h"




// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
