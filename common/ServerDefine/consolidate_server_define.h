
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//��������װ��ǿ����ؽṹ

#include "../ServerDefine/base_server_define.h"
#include "../common/WorldDefine/compose_define.h"

#pragma once

#pragma pack(push, 1)

//! װ��ǿ������
enum E_consolidate_type_ser
{
	//ects_posy		= 0,	// ����
	//ects_engrave	= 1,	// �Կ�
	ects_inlay		= 2,	// ��Ƕ
	//ects_brand		= 3,	// ��ӡ
	//ects_fpsoul		= 4,	// ����			
	//ects_quench		= 5,	// ���
	ects_produce	= 6,	// ����
	ects_decompose  = 8,	// �㻯�ֽ�

	ects_hole		= 9,	// ���
	ects_unbeset	= 10,	// ��Ƕ
	ects_shengxing	= 11,	// ����
	ects_fusion		= 12,	// �ں�
};

//! �����ϳ�
struct s_produce_proto_ser
{
	DWORD				dw_id;					//�䷽ID
	TCHAR				sz_name[X_SHORT_NAME];	//�䷽����
	EProduceType		e_pro_type;				//��������
	EComposeType		e_com_type;				//�ϳ�����
	EFormulaFrom		e_form_from;			//�䷽��Դ
	INT			  		n_form_levle;			//�䷽�ȼ�
	DWORD				dw_pro_item_data_id;	//�ϳɵ���Ʒ
	DWORD				dw_pro_quan_tity;		//�ϳɵ�����
	INT					n_success_rate;			//�ɹ���
	DWORD				dw_master_incre;		//����������
	DWORD				dw_money_consume;		//��Ǯ����
	tagProduceSutff		produce_stuff[MAX_PRODUCE_STUFF_QUANTITY];//��������
	INT					nQualiyNum[EIQ_End];	//����Ʒ�����������
	INT					nQualiyPro[EIQ_End];	//����Ʒ�������
	BOOL				bBind;					//�Ƿ��
};

struct s_decompose_proto_ser
{
	DWORD				dw_id;					//�䷽ID
	EComposeType		e_com_type;				//�ϳ�����
	BYTE				by_level;				//װ���ȼ�
	BYTE				by_quality;				//װ��Ʒ��
	EItemType			e_type;					//װ������
	EItemTypeEx			e_type_ex;				//��������
	EEquipPos			e_pos;					//װ��λ��
	INT					n_form_level;			//�䷽�ȼ�
	EFormulaFrom		e_form_from;			//�䷽��Դ
	DWORD				dw_master_incre;		//����������
	DWORD				dw_money_consume;		//��Ǯ����
	INT					n_out_stuff_num;		//�����������
	std::vector<tagOutputStuff>	output_stuff;	//�������
	tagOutputStuff		out_per_stuff;			//��������		
};

#pragma pack(pop)

