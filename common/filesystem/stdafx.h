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



