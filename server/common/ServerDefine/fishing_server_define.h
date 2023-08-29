/*******************************************************************************

	Copyright 2010 by Shengshi Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	Shengshi Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	Shengshi Interactive  Co., Ltd.

*******************************************************************************/

/**
 *	@file		fishing_server_define
 *	@author		mwh
 *	@date		2011/06/28	initial
 *	@version	0.0.1.0
 *	@brief		���㶨��
*/

#ifndef __FISHING_SERVER_DEFINE_H__
#define __FISHING_SERVER_DEFINE_H__
#pragma pack(push,1)

struct tagFishItem
{
	DWORD dwItemID;					// TYPEID
	DWORD dwItemProb;				// ����
	DWORD dwSkillProficiency;		// ������������
};

struct tagNpcFishingProto
{
	INT nMinLevel;					// ��С�ȼ�
	INT nSkillLevel;					// ��С���ܵȼ�
	DWORD dwID;						// ��ͼ��CRC
	DWORD dwNullGetProb;			// ���ռ���
	std::vector<tagFishItem> outs;	// ��
	std::vector<tagFishItem> outs_sp; // ������
};

#pragma pack(pop)
#endif // __FISHING_SERVER_DEFINE_H__
