/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

/**
*	@file		rank_define.h
*	@author		liuchi
*	@date		2010/12/21	initial
*	@version	0.0.1.0
*	@brief		���а�ṹ����
*/

#pragma once


#define FIRSTLEVLETITLE 0

#define FIRSTZHANSHI 3
#define FIRSTFASHI 4
#define FIRSTDAOSHI 5

#define OTHERZHANSHI 8
#define OTHERFASHI 9
#define OTHERDAOSHI 10

#define FIRSTNAN 6
#define FIRSTNV 7
//gx add 2013.12.10
#define MASTERRANK1 19  //һ����ʦ
#define MASTERRANK2 20	//������֪
#define MASTERRANK3 21	//��������
#define MASTERRANK4 22	//�¸�����
//end
#pragma pack(push, 1)

struct tagLevelRankInfo
{
	DWORD			dw_role_id;			// ����ID
	INT				nLevel;				// ����ȼ�
	EClassType		eClass;				// ְҵ
	DWORD			dwGuildID;			// ���ID
};

struct tagEquipRankInfo
{
	DWORD	dw_data_id;				// ��ƷID
	INT		nLevel;					// �ȼ�
	INT		nScore;					// ����
	DWORD	dw_role_id;				// ������
};

struct tagGuildRankInfo
{
	DWORD	dwGuildID;			// ���ID
	INT		nLevel;				// ���ȼ�
	INT		nProsperity;		// ����ʽ�
	DWORD	dwLeaderID;			// ����ID
};

struct tagKillRankInfo
{
	DWORD	dw_role_id;
	INT		nLevel;
	INT		nKillNum;
	DWORD	dwGuildID;
};

struct tagJusticeRankInfo
{
	DWORD		dw_role_id;		// ��ɫid
	INT			nLevel;			// �ȼ�
	INT32		n32Justice;		// ս��
	EClassType	e_class;		// ְҵ
};

struct tag1v1RankInfo
{
	DWORD	dw_role_id;
	INT		nLevel;
	EClassType e_class;
	INT		nScore;
};


struct tagmeiliRankInfo
{
	DWORD		dw_role_id;
	INT			n_level_;
	EClassType		e_class;
	DWORD		dw_shihun;
	BYTE		by_sex;
};

struct tagAchPointRankInfo
{
	DWORD		dw_role_id;
	INT			n_level_;
	DWORD		dw_point;
};

struct tagAchNumberRankInfo
{
	DWORD		dw_role_id;
	INT			n_level_;
	DWORD		dw_number;
};
struct tagMasterGraduateRankInfo
{
	DWORD dw_role_id;
	INT n_Graduates;//��ʦ����
	INT			n_level_;
	EClassType		e_class;
	BYTE		by_Sex;
	BYTE		by_online;
};
#pragma pack(pop)