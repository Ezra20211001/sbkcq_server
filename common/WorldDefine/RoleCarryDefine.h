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
 *	@file		RoleCarryDefine
 *	@author		mwh
 *	@date		2012/05/30	initial
 *	@version	0.0.1.0
 *	@brief		搬运
*/

#ifndef __ROLE_CARRY_H__
#define __ROLE_CARRY_H__

#pragma pack(push, 1)

// 搬运某个东西 
struct NET_SIS_CarrySomething : public tag_net_message
{
	NET_SIS_CarrySomething()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_CarrySomething");
		dw_size = sizeof(*this);
	}
	DWORD dwRoleID;
	DWORD dwTypeID;
};

// 客户端主动退出
struct NET_SIC_StopCarrySomething : public tag_net_message
{
	NET_SIC_StopCarrySomething()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_StopCarrySomething");
		dw_size = sizeof(*this);
	}
};




#pragma pack(pop)


#endif /** __ROLE_CARRY_H__ */