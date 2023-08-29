//-------------------------------------------------------------------------------
//��Name				:   filter.h
//��Compiler			:	Microsoft Visual C++ 9.0
//��Version				:	1.00
//��Create Date			:	2008-12-17
//��LastModified		:	
//��Brief				:	���ƹ���
//-------------------------------------------------------------------------------
#include "filter.h"
#include "protocol_common_errorcode.h"
#include <tchar.h>
#include <algorithm>

#define JUDGE_ACSII_1(c)	{ if( c>=32 && c<=47 )			return E_Filter_Name_Illegal; }
#define JUDGE_ACSII_2(c)	{ if( c>=58 && c<=64 )			return E_Filter_Name_Illegal; }
#define JUDGE_ACSII_3(c)	{ if( c>=91 && c<=96 )			return E_Filter_Name_Illegal; }
#define JUDGE_ACSII_4(c)	{ if( c>=123 && c<=127 )		return E_Filter_Name_Illegal; }
#define JUDGE_ACSII_5(c)	{ if( c==10 || c==13 )          return E_Filter_Name_Illegal; }
#define JUDEG_ASCII_Tab(c)	{ if( c==9 )					return E_Filter_Name_Illegal; }
#define JUDGE_UNICODE_1(c)	{ if( c>=0x3000 && c<=0x301F )	return  E_Filter_Name_Illegal; }
#define JUDGE_UNICODE_2(c)	{ if( c>=0x2000 && c<=0x2050 )	return  E_Filter_Name_Illegal; }
#define JUDGE_UNICODE_3(c)	{ if( c>=0xFF00 && c<=0xFF0F )	return  E_Filter_Name_Illegal; }
#define JUDGE_UNICODE_4(c)	{ if( c>=0xFF1A && c<=0xFF20 )	return  E_Filter_Name_Illegal; }
#define JUDGE_UNICODE_5(c)	{ if( c>=0xFF3B && c<=0xFF40 )	return  E_Filter_Name_Illegal; }
#define JUDGE_UNICODE_6(c)	{ if( c>=0xFF5B && c<=0xFF65 )	return  E_Filter_Name_Illegal; }
//#define JUDGE_UNICODE_7(c)	{ if( c < 0x4e00 || c > 0x9fa5) return  E_Filter_Name_Illegal; }
//-------------------------------------------------------------------------------
namespace Filter
{
	//-------------------------------------------------------------------------------
	// �ַ��Ϸ��Լ��Ƿ��ڹ��˴ʱ���
	//-------------------------------------------------------------------------------
	DWORD CheckName(LPCTSTR strName, INT nMax/*=7*/, INT nMin/*=1*/, vector<tstring>* pFilter/*=NULL*/)
	{
		// ����ַ��Ϸ���
		DWORD dw_error_code = Filter::IsNameLegal(strName, nMax, nMin);
		if(dw_error_code != E_Success)
		{
			return dw_error_code;
		}

		return IsNameInNameFilterFile(strName, pFilter);
	}

	DWORD	CheckContent(LPCTSTR strContent, INT nMax/*=7*/, INT nMin/*=1*/, vector<tstring>* pFilter/*=NULL*/)
	{
		// ����ַ��Ϸ���
		DWORD dw_error_code = Filter::IsContentLegal(strContent, nMax, nMin);
		if(dw_error_code != E_Success)
		{
			return dw_error_code;
		}

		return IsNameInNameFilterFile(strContent, pFilter);
	}
	
	//-------------------------------------------------------------------------------
	// �ַ��Ϸ���
	//-------------------------------------------------------------------------------
	DWORD IsNameLegal(LPCTSTR strName, INT nMax/*=7*/, INT nMin/*=1*/)
	{
		INT nLen = (INT)_tcslen(strName);
		if(  strName==NULL || nLen==0  )
			return E_Filter_Name_Null;

		if( nLen>nMax )
			return E_Filter_Name_TooLong;

		for( int i=0; i<nLen; i++ )
		{
			JUDGE_ACSII_1(strName[i]);
			JUDGE_ACSII_2(strName[i]);
			JUDGE_ACSII_3(strName[i]);
			JUDGE_ACSII_4(strName[i]);
            JUDGE_ACSII_5(strName[i]);
			JUDEG_ASCII_Tab(strName[i]);
			JUDGE_UNICODE_1(strName[i]);
			JUDGE_UNICODE_2(strName[i]);
			JUDGE_UNICODE_3(strName[i]);
			JUDGE_UNICODE_4(strName[i]);
			JUDGE_UNICODE_5(strName[i]);
			JUDGE_UNICODE_6(strName[i]);
			//JUDGE_UNICODE_7(strName[i]);
		}

		return E_Success;
	}

	DWORD IsContentLegal(LPCTSTR strContent, INT nMax/*=7*/, INT nMin/*=1*/)
	{
		INT nLen = (INT)_tcslen(strContent);
		if(  strContent==NULL || nLen==0  )
			return E_Filter_Name_Null;

		if( nLen>nMax )
			return E_Filter_Name_TooLong;

		for( int i=0; i<nLen; i++ )
		{
			//JUDGE_UNICODE_7(strContent[i]);
		}

		return E_Success;
	}

	//-------------------------------------------------------------------------------
	// �Ƿ��ڹ��˴ʱ���
	//-------------------------------------------------------------------------------
	DWORD IsNameInNameFilterFile( LPCTSTR szName, vector<tstring>* pFilter/*=NULL*/ )
	{
		if( pFilter==NULL )
			return E_Success;

		tstring::size_type index = 0;
		tstring	strName = szName;
		transform(strName.begin(), strName.end(), strName.begin(), tolower);
		size_t	nameLen = strName.size();	//�������ַ����ĳ���
		size_t fLen = pFilter->size();		//��Ĵ�С

		for(size_t i=0; i<fLen; ++i)
		{
			index = 0;
			size_t length = pFilter->at(i).size();
			if(nameLen < length)	
				continue;
			tstring strFind = pFilter->at(i);
			transform(strFind.begin(), strFind.end(), strFind.begin(), tolower);
			index  = strName.find(strFind);
			if(index != tstring::npos)
			{	
				return E_Filter_Name_InFilterFile;
			}	
		}
		return E_Success;
	}

	//-------------------------------------------------------------------------------
	// �������ݹ���,�����˴�ת��Ϊ"*"
	//-------------------------------------------------------------------------------
	DWORD WordsFilterForChat( tstring& strText, vector<tstring>* pFilter/*=NULL*/ )
	{
		size_t textLen = strText.size();	//�������ַ����ĳ���
		if( textLen == 0 )
			return E_Filter_Chat_NoContent;

		tstring strTemp;
		strTemp.assign(strText);
		transform(strText.begin(), strText.end(), strText.begin(), tolower);
		tstring::size_type index = 0;
		size_t fLen = pFilter->size();		//��Ĵ�С

		for( size_t i=0; i<fLen; ++i )
		{
			index = 0;
			size_t length = pFilter->at(i).size();
			if(textLen < length)
				continue;
			
			tstring strFind = pFilter->at(i);
			transform(strFind.begin(), strFind.end(), strFind.begin(), tolower);
			index = strText.find(strFind, index);
			while( index != string::npos )
			{
				return E_Filter_Name_Illegal;

				// 				strText.replace(index, length, length, _T('*'));
				// 				index += length;
				// 				if(index > textLen-1)
				// 					break;
				// 				index = strText.find(pFilter->at(i), index);
				// 				if( index+length > textLen-1 )
				// 					break;
			}
		}

		for( int i=0; i<(int)strText.size(); i++ )
		{
			if( strText[i]>='a' && strText[i]<='z' )
			{
				strText.replace(i, 1, 1, strTemp[i]);
			}
		}

		return E_Success;
	}


} // namespace Filter