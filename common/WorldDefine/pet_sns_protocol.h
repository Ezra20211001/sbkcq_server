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
*	@file		pet_protocol.h
*	@author		lc
*	@date		2011/06/30	initial
*	@version	0.0.1.0
*	@brief		宠物sns消息
*/

#ifndef PET_SNS_PROTOCOL
#define PET_SNS_PROTOCOL

#pragma pack(push,1)

#include "pet_define.h"
//#include "protocol_common_errorcode.h"

//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum 
{
	E_Pets_SNS_UnkownErr		=-1,
	E_Pets_SNS_Success			= 0,	

	E_Pets_SNS_Soul_NotExist	= 1,	// 宠物不存在
	E_PetS_SNS_Cannot_paiqian	= 2,	// 当前状态不能派遣
	E_PetS_SNS_Friend_Has_pet	= 3,	// 该好友已派遣宠物
	E_PetS_SNS_Friend_NotExis	= 4,	// 好友不存在或不是双向好友
	E_PetS_SNS_Friend_Level_NotExis = 5, // 等级差太大


	E_PetS_SNS_Not_Pet			= 6,	// 没有该宠物
	E_PetS_SNS_Not_Work			= 7,	// 该宠物没有派遣	
	E_PetS_SNS_Not_to_You		= 8,	// 该宠物不是派给你的
	E_PetS_SNS_Time_Not_Relay	= 9,	// 时间没到，不能收取对方宠物结晶
};


// 派遣宠物
struct NET_SIC_pet_paiqian : public tag_net_message
{
	NET_SIC_pet_paiqian()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_paiqian");
		dw_size = sizeof(NET_SIC_pet_paiqian);
	}
	DWORD           dw_pet_id;		//!< 宠物id
	DWORD           dw_friend_id;   //!< 好友id
};


struct NET_SIS_pet_paiqian : public tag_net_message
{
	NET_SIS_pet_paiqian()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_paiqian");
		dw_size = sizeof(NET_SIS_pet_paiqian);
	}

	DWORD           dw_pet_id;      //!< 宠物ID
	DWORD           dw_friend_id;   //!< 好友id
	DWORD			dw_time;		//!< 时间
	DWORD			dwErrCode;		//!< 错误码
};

// 被派遣宠物
struct NET_SIS_pet_be_paiqian : public tag_net_message
{
	NET_SIS_pet_be_paiqian()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_be_paiqian");
		dw_size = sizeof(NET_SIS_pet_be_paiqian);

	}
	
	DWORD           dw_pet_id;      //!< 宠物ID
	DWORD           dw_friend_id;   //!< 好友id
	DWORD			dw_time;		//!< 时间
};


// 收回宠物
struct NET_SIC_pet_return : public tag_net_message
{
	NET_SIC_pet_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_return");
		dw_size = sizeof(NET_SIC_pet_return);

	}

	DWORD           dw_pet_id;      //!< 宠物ID
	BYTE			by_type;		//0:收回自己的宠物 1：收取好友的宠物
};

struct NET_SIS_pet_return : public tag_net_message
{
	NET_SIS_pet_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_return");
		dw_size = sizeof(NET_SIS_pet_return);

	}

	DWORD           dw_pet_id;      //!< 宠物ID
	BYTE			by_type;		//0:收回自己的宠物 1：收取好友的宠物
	INT				n_itemNum;		//获得结晶数量
	DWORD			dwErrCode;	
};


// 宠物被对方收回了
struct NET_SIS_pet_be_return : public tag_net_message
{
	NET_SIS_pet_be_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_be_return");
		dw_size = sizeof(NET_SIS_pet_be_return);

	}

	DWORD           dw_pet_id;      //!< 宠物ID
	BYTE			by_type;		//0:自己的宠物被收回 1：对方的宠物被对方收回
};


//发给客户端宠物sns初始信息
struct NET_SIS_pet_SNS_info : public tag_net_message
{
	NET_SIS_pet_SNS_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_SNS_info");
		dw_size = sizeof(NET_SIS_pet_SNS_info);

	}

	INT				n_num;		  // 宠物sns信息数量
	tagPetSNSInfo	petSNSInfo[1];
};

#pragma pack(pop)
#endif
