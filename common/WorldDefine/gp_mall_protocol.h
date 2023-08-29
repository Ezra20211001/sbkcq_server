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
*	@file		gp_mall_protocol.h
*	@author		lc
*	@date		2012/07/018	initial
*	@version	0.0.1.0
*	@brief		gp�̳�Э��
*/

#ifndef _GP_MALL_PROTOCOL_H_
#define _GP_MALL_PROTOCOL_H_

#include "..\common\WorldDefine\gp_mall_define.h"

#pragma pack(push, 1)

//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum
{
	E_LOTTERY_NOT_GP			=	1,	// gp���� //���ѳ齱��������
	E_LOTTERY_NOT_BAG			=	2,	// �����ռ䲻��
	E_LOTTERY_NOT_KEY			=	3,	// ûԿ�� //��û�г齱����Ҳû�й涨��Ŀ��ָ��Ԫ��
	E_LOTTERY_NOT_PP			=	4,  // pp����
	E_LOTTERY_NOT_SILVER		=	5,  // ��Ҳ���
};

//----------------------------------------------------------------------------
// �齱
//----------------------------------------------------------------------------
struct NET_SIC_get_lottery : public tag_net_message
{
	NET_SIC_get_lottery()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_lottery");
		dw_size = sizeof(NET_SIC_get_lottery);
	}
	BYTE	byType; //0:A��  1:B��
	
};

struct NET_SIS_get_lottery : public tag_net_message
{
	NET_SIS_get_lottery()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_lottery");
		dw_size = sizeof(NET_SIS_get_lottery);
	}
	DWORD	dwItemIndex;//�����Ʒ������ID
	//DWORD dwItemID;		// �����Ʒid
	BYTE	byType;		//0:A��  1:B��
	DWORD dwErrorCode;  // ������
	BYTE  bItemNum;		//��Ʒ����
};



#pragma pack(pop)
#endif