
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//GM服务端与GM工具之间的数据定义

#pragma once
#pragma pack(push, 1)

#define Notice_Title 30
#define Notice_Content 256
#define Notice_Link 256
#define System_Cmd_Length 1024

//! 列举与定时有关的消息
enum E_time_limited_msg
{
	etlm_start,

	etlm_double = 1,
	etlm_right_notice,
	etlm_auto_notice,
	etlm_auto_chat_notice,

	etlm_end
};

enum 
{
	e_gm_tool_error							= -1,
	e_gm_tool_success						= 0,

	e_gm_tool_gm_already_exist				= 1,		// GM已经存在
	e_gm_tool_gm_not_exist					= 2,		// GM不存在
	e_gm_tool_gm_create_fail				= 3,		// GM创建失败

	e_gm_tool_resume_role_name_already_exist= 10,		// 角色名已经存在（重新起名）
	e_gm_tool_resume_role_not_exist			= 11,		// 恢复的角色不存在

	e_gm_tool_modify_role_role_not_exist	= 20,		// 角色不存在

	e_gm_tool_null_content					= 30,		// 内容不能为空

	e_gm_tool_role_not_exist				= 40,		// 角色不存在

	e_gm_tool_delete_item_item_not_exist	= 50,		// 物品不存在
	e_gm_tool_create_item_equip_num_error	= 51,		// 装备数量错误
	e_gm_tool_create_item_item_quality_error= 52,		// 物品品级错误

	e_gm_tool_time_error					= 100,		// 时间不对	

	e_montior_client_ipbind_error			= 110,		// ip绑定错误
	e_montior_client_error					= 111,		// ip绑定错误

	e_gm_tool_time_set_error				= 120,		// 时间设置错误，设置的开始时间已过

	e_montior_client_not_enough_pri			= 130,		// 权限不够，不能查询

	e_gm_tool_resume_item_not_exit			= 140,		// 要恢复的装备不存在
	e_gm_tool_resume_item_not_equip			= 141,		// 要恢复的物品不是装备
};

enum E_double_type
{
	edt_null		= -1,
	edt_exp			= 0,				//双倍经验
	edt_item		= 1,				//双倍物品
	edt_end			= 2,
};

const INT NUM_EDT			= edt_end - edt_exp;
#define EDT_VALID(edt)	((edt) > edt_null && (edt) < edt_end)	


//! 马跑灯/自动循环公告颜色设置
enum E_color_type
{
	ect_null		= -1,
	ect_red			= 0,
	ect_yellow		= 1,
	ect_green		= 2,	
	ect_blue		= 3,
	ect_orange		= 4,
	ect_end			= 5,
};


#pragma pack(pop)