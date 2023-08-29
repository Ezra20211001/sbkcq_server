
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//服务器用成就相关结构


#ifndef _ACHIEVEMENT_SERVER_H_
#define _ACHIEVEMENT_SERVER_H_


//#include "role_data_server_define.h"

#pragma pack(push, 1)

// 保存到数据库的完成成就
struct s_achievement_complate_save
{
	DWORD	dw_id;	
	DWORD	dw_date;
};


// 成就进度
struct s_achievement_process_save
{
	DWORD dw_id;
	DWORD dw_count;
	DWORD dw_date;
};


#pragma pack(pop)

#endif