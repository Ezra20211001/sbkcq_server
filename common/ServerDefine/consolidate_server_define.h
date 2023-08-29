
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//服务器用装备强化相关结构

#include "../ServerDefine/base_server_define.h"
#include "../common/WorldDefine/compose_define.h"

#pragma once

#pragma pack(push, 1)

//! 装备强化类型
enum E_consolidate_type_ser
{
	//ects_posy		= 0,	// 铭纹
	//ects_engrave	= 1,	// 镌刻
	ects_inlay		= 2,	// 镶嵌
	//ects_brand		= 3,	// 烙印
	//ects_fpsoul		= 4,	// 龙附			
	//ects_quench		= 5,	// 淬火
	ects_produce	= 6,	// 生产
	ects_decompose  = 8,	// 点化分解

	ects_hole		= 9,	// 打孔
	ects_unbeset	= 10,	// 拆嵌
	ects_shengxing	= 11,	// 升星
	ects_fusion		= 12,	// 融合
};

//! 生产合成
struct s_produce_proto_ser
{
	DWORD				dw_id;					//配方ID
	TCHAR				sz_name[X_SHORT_NAME];	//配方名称
	EProduceType		e_pro_type;				//生产类型
	EComposeType		e_com_type;				//合成类型
	EFormulaFrom		e_form_from;			//配方来源
	INT			  		n_form_levle;			//配方等级
	DWORD				dw_pro_item_data_id;	//合成的物品
	DWORD				dw_pro_quan_tity;		//合成的数量
	INT					n_success_rate;			//成功率
	DWORD				dw_master_incre;		//熟练度增加
	DWORD				dw_money_consume;		//金钱消耗
	tagProduceSutff		produce_stuff[MAX_PRODUCE_STUFF_QUANTITY];//生产材料
	INT					nQualiyNum[EIQ_End];	//提升品质物最大数量
	INT					nQualiyPro[EIQ_End];	//提升品质物概率
	BOOL				bBind;					//是否绑定
};

struct s_decompose_proto_ser
{
	DWORD				dw_id;					//配方ID
	EComposeType		e_com_type;				//合成类型
	BYTE				by_level;				//装备等级
	BYTE				by_quality;				//装备品级
	EItemType			e_type;					//装备类型
	EItemTypeEx			e_type_ex;				//武器类型
	EEquipPos			e_pos;					//装备位置
	INT					n_form_level;			//配方等级
	EFormulaFrom		e_form_from;			//配方来源
	DWORD				dw_master_incre;		//熟练度增加
	DWORD				dw_money_consume;		//金钱消耗
	INT					n_out_stuff_num;		//输出材料数量
	std::vector<tagOutputStuff>	output_stuff;	//输出材料
	tagOutputStuff		out_per_stuff;			//完美材料		
};

#pragma pack(pop)

