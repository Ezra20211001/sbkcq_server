/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

// gp�̳�
#pragma once

#pragma pack(push, 1)


// ��Ʊ����gp
#define NEED_GP 60

#define NEED_SILVER 300000

// ��Ʊa�������
#define TPYE_A_NEED_ITEM 1300045

// ��Ʊb�������(�õ��߶�Ӧ������֮�ǡ���ID)
#define TPYE_B_NEED_ITEM 1400058//���� gx modify 2013.6.3
//�齱����ķǰ󶨵�Ԫ���� 
#define NEED_NONBINDYB 10
//gx add 2013.6.3
//
//end
//��Ʊ����Ʒ
struct tagLotteryProto
{
	DWORD dwID;		
	DWORD dwItemID;		//��Ʒid
	DWORD dwNumber;		//����
	BYTE  byType;		//0:a�� 1��b��
	BYTE  b_prize;		//�Ƿ�ͷ��
	BYTE  b_bind;		//�Ƿ��
	BYTE  b_ItemNum;	//�ý�Ʒ������ gx add 2013.6.26
};


// ͷ�������
struct tagPrizeRole
{
	DWORD dwRoleID;
	DWORD dwTime;
	TCHAR szRoleName[X_SHORT_NAME];
};

#pragma pack(pop)