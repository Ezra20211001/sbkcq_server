/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/



#ifndef _TITLE_H_
#define _TITLE_H_

#include "../WorldDefine/ItemDefine.h"

//-----------------------------------------------------------------------------
// �ƺ���Ŀ
//-----------------------------------------------------------------------------
const DWORD MAX_TITLE_NUM			= 200;

//-----------------------------------------------------------------------------
// �ƺ�Ч������
//-----------------------------------------------------------------------------
const INT	MAX_TITLE_SPECNUM		= 10;

//-----------------------------------------------------------------------------
// �ƺ�ID�Ƿ���Ч
//-----------------------------------------------------------------------------
#define TITLEID_VALID( id ) ((id) >= 0 && (id) < MAX_TITLE_NUM)

enum Titel_Type
{
	TT_TIANQI		= 0,		// ����
	TT_SANHUI		= 1,		// ����
	TT_ACHIEVEMENT	= 2,		// �ɾ�
	TT_YINCANG		= 3,		// ����
	TT_HUODONG		= 4,		// �
	TT_VIP			= 5,		// VIP

	TT_ALL,
};
////-----------------------------------------------------------------------------
//// �ƺ���������
////-----------------------------------------------------------------------------
//class condition
//{
//public:
//	condition(UINT16 n_title_id, DWORD dw_param1, DWORD dw_param2, BOOL b_show)
//		:n16_title_id_(n_title_id), dw_param1_(dw_param1), dw_param2_(dw_param2),b_show_(b_show){}
//	bool is_count_cond() const;
//	e_check_result check(DWORD dw_arg1, DWORD dw_arg2) {	return do_check(dw_arg1, dw_arg2);	}
//	void set_para2(DWORD dw_para2)	{	dw_param2_ = dw_para2; }
//	DWORD get_para2() const {return dw_param2_;}
//	BOOL  is_show() { return b_show_; }
//protected:
//	//	Role* GetRole() const {return m_pRole;}
//private:
//	virtual e_check_result do_check(DWORD dwArg1, DWORD dwArg2) = 0;
//
//protected:
//	DWORD	dw_param1_;
//	DWORD	dw_param2_;
//private:
//	UINT16	n16_title_id_;
//	BOOL	b_show_;
//	//	Role*	m_pRole;
//};
//
//
////-----------------------------------------------------------------------------
//// ��������
////-----------------------------------------------------------------------------
//class count_condition: public condition
//{
//public:
//	count_condition(INT16 n_title_id, DWORD dw_param1, DWORD dw_param2, BOOL b_show)
//		:condition(n_title_id, dw_param1, dw_param2, b_show){}
//
//private:
//	virtual e_check_result do_check(DWORD dwSubType, DWORD dwArg2)
//	{
//		if ( VALID_VALUE(dw_param1_) && dwSubType != dw_param1_) return ecr_noafect; 
//		if ((--dw_param2_) <= 0)
//		{
//			return ecr_active;
//		}
//		else
//		{
//			return ecr_count_down;
//		}
//	}
//};
//
////-----------------------------------------------------------------------------
//// ��ֵ����
////-----------------------------------------------------------------------------
//class ValueCondition: public condition
//{
//public:
//	ValueCondition(UINT16 u16TitleID, DWORD dwPara1, DWORD dwPara2, BOOL IsShow)
//		:condition(u16TitleID, dwPara1, dwPara2, IsShow){}
//private:
//	virtual e_check_result do_check(DWORD dwSubType, DWORD dwValue)
//	{
//		if ( VALID_VALUE(dw_param1_) && dwSubType != dw_param1_) return ecr_noafect; 
//		if (dwValue >= dw_param2_)
//		{
//			return ecr_active;
//		}
//		else
//		{
//			return ecr_noafect; 
//		}
//	}
//};
//
////-----------------------------------------------------------------------------
//// ���Ӽ������
////-----------------------------------------------------------------------------
//class CheckCondition:public condition
//{
//public:
//	CheckCondition(UINT16 u16TitleID, DWORD dwPara1, DWORD dwPara2, BOOL IsShow)
//		:condition(u16TitleID, dwPara1, dwPara2, IsShow){}
//private:
//	virtual e_check_result do_check(DWORD dwArg1, DWORD dwArg2)
//	{
//		//		Role* pRole = GetRole();
//
//		return ecr_noafect;//pRole->CheckCondition();
//	}
//};

//-----------------------------------------------------------------------------
// �ƺ�Ч��
//-----------------------------------------------------------------------------
//struct tagTitleSpecEffect
//{
//	INT					nValue;			// ֵ
//	DWORD				dwItemTypeID;	// ��ƷID
//};

//-----------------------------------------------------------------------------
// �ƺ�ԭ��
//-----------------------------------------------------------------------------
struct tagTitleProto
{

	DWORD				m_dwID;
	DWORD				m_dwType;
	DWORD				m_dwColor;
	BYTE				m_byLevel;
	BYTE				m_byNeedRoleLevel;
	DWORD				m_dwBuffID;
	tagRoleAttEffect	m_roleAtt[MAX_TITLE_SPECNUM];
	DWORD				m_dwAchievementPoint;

	BOOL				m_bSpecial;
	
	INT					m_nNeedYuanbaoLevel;		// �����ֵԪ���ȼ�

	INT					m_nNeedAchievementLevel;	// ����ɾ͵ȼ�

	DWORD				m_dwTimeLimit;				// ʱ������
};


#endif