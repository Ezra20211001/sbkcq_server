
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

//������Ϣ���ݿ�洢�ṹ
#pragma once
#include "../../common/WorldDefine/reputation.h"

#pragma pack(push,1)
struct s_db_repute_data 
{
	INT8			n8_act_count_[ECLT_NUM];				// ʣ�༤�����
	INT32			n_reputation_[ECLT_NUM];				// ����ֵ
	INT32			n_contribution_[ECLT_NUM];				// ����ֵ
	tagDWORDTime	last_reset_time_;						// �ϴ���������ʱ��
	UINT16			u16_fame_mask;							// �����ó�Ա
	s_db_repute_data(){	ZeroMemory(this, sizeof(*this));}
};
#pragma pack(pop)