//-----------------------------------------------------------------------------
//��Name				:   script_data.h
//��Compiler			:	Microsoft Visual C++ 9.0wjiang
//��Version				:	1.00
//��Create Date			:	2009-04-6
//��LastModified		:	
//��Brief				:	�ű�ͨ�����ݹ�����
//-----------------------------------------------------------------------------

#pragma once

#pragma pack(push, 1)

//-----------------------------------------------------------------------------
// �ű�ģ��Size
//-----------------------------------------------------------------------------
enum EScirptData
{
	ESD_Quest		=	10,		// ����ű����ݸ���
	ESD_Role		=	100,	// ��ҽű����ݸ���
	ESD_Creature	=	8,		// ����ű����ݸ���
	ESD_Activity	=	50,		// ��ű����ݸ���
	ESD_Map			=	40,		// ��ͼ�ű����ݸ���
};
//-----------------------------------------------------------------------------
// �ű�����ʹ��˵����gx add 2013.10.25����10����촽���,11��12���ں촽���֮��Ƚ��
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// �ű�����ģ��
//-----------------------------------------------------------------------------
template<INT nSize>
struct tagScriptData
{
	DWORD	dwData[nSize];
	tagScriptData()
	{
		ZeroMemory(dwData, sizeof(DWORD)*nSize);
	}
};


template<INT nSize>
class ScriptData
{
public:
	ScriptData() {}

	inline VOID	ModScriptData(INT nIndex, DWORD dwValue)
	{
		ASSERT(nIndex >= 0 && nIndex < nSize);
		m_ScriptData.dwData[nIndex] += dwValue;
	}

	inline VOID	SetScriptData(INT nIndex, DWORD dwValue)
	{
		ASSERT(nIndex >= 0 && nIndex < nSize);
		m_ScriptData.dwData[nIndex] = dwValue;
	}

	inline DWORD GetScriptData(INT nIndex)
	{
		ASSERT(nIndex >= 0 && nIndex < nSize);
		return	m_ScriptData.dwData[nIndex];
	}

protected:
	tagScriptData<nSize>   m_ScriptData;
};


#pragma pack(pop)
