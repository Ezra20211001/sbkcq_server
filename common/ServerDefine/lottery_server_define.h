/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//彩票机消息结构


#pragma once

#pragma pack(push, 1)

// 彩票存储结构
struct s_lottery_save
{
	DWORD dwItemID;
	DWORD dwNumber;
	BYTE byType;
};

// 读取彩票信息
struct NET_S2DB_load_lottery_data : public tag_net_message
{
	NET_S2DB_load_lottery_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_load_lottery_data");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2S_load_lottery_data : public tag_net_message
{
	NET_DB2S_load_lottery_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_lottery_data");
		dw_size = sizeof(*this);
	}
	INT n_num;
	s_lottery_save	st_data[1];
};

// 存回数据库
struct NET_S2DB_save_lottery_data : public tag_net_message
{
	NET_S2DB_save_lottery_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2DB_save_lottery_data");
		dw_size = sizeof(*this);
	}
	INT n_num;
	s_lottery_save	st_data[1];
};


#pragma pack(pop)