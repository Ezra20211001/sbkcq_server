//-------------------------------------------------------------------------------
//★Name				:   filter.h
//★Compiler			:	Microsoft Visual C++ 9.0
//★Version				:	1.00
//★Create Date			:	2008-12-17
//★LastModified		:	
//★Brief				:	名称过滤
//-------------------------------------------------------------------------------
#pragma once

#include <wtypes.h>
#include <vector>
using namespace std;

#ifdef _UNICODE
typedef std::wstring		tstring;
typedef std::wstringstream	tstringstream;
typedef std::wstreambuf		tstreambuf;
#else
typedef std::string			tstring;
typedef std::stringstream	tstringstream;
typedef std::streambuf		tstreambuf;
#endif

//-------------------------------------------------------------------------------
// 方法
//-------------------------------------------------------------------------------
namespace Filter
{
	DWORD	CheckName(LPCTSTR strName, INT nMax=7, INT nMin=1, vector<tstring>* pFilter=NULL);
	DWORD	CheckContent(LPCTSTR strContent, INT nMax=7, INT nMin=1, vector<tstring>* pFilter=NULL);
	DWORD	IsNameLegal(LPCTSTR strName, INT nMax=7, INT nMin=1);
	DWORD	IsNameInNameFilterFile(LPCTSTR szName, vector<tstring>* pFilter=NULL);
	DWORD	IsContentLegal(LPCTSTR strContent, INT nMax=7, INT nMin=1);
	DWORD	WordsFilterForChat(tstring& strText, vector<tstring>* pFilter=NULL);
}