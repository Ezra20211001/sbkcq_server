/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

******************************************************************************/

/**
*	@file		function_npc_protocol.h
*	@author		lc
*	@date		2011/03/03	initial
*	@version	0.0.1.0
*	@brief		npcְ����Ϣ
*/


#ifndef FUNCTION_NPC_PROTOCOL
#define FUNCTION_NPC_PROTOCOL

#include "protocol_common_errorcode.h"

#pragma pack(push, 1)
//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum
{	
	E_Dak_NPCNotFound		= 1,	// û���ҵ�ָ��NPC
	E_Dak_NPCNotValid		= 2,	// ������վNPC
	E_Dak_TooFar			= 3,	// ������վNPC̫Զ
	E_Dak_NotExist			= 4,	// ��ָ��NPC����û���ҵ���վ
	E_Dak_TargetMap_Invalid	= 5,	// ָ��������map id��ָ��id����
	E_Dak_NotEnough_Money	= 6,	// ����Ʒ����
	E_Dak_ChangeMap_Failed	= 7,	// ����ʱʧ��

	E_Ware_NPCNotValid		= 10,	// ���ǽ�ɫ�ֿ�NPC
	
	E_Con_Cannot_Extend		= 50,	// ����������
	E_Con_Cannot_itemExtend = 51,	// ������߲�����
	E_Con_exstep_low		= 52,	// ������ߵȼ�̫��
	E_Con_exstep_up			= 53,	// ������ߵȼ�̫��

	E_Silver_NotEnough		= 60,	// ��Ǯ����
	E_YuanBao_NotEnough		= 61,	// Ԫ������
};

//----------------------------------------------------------------------------
// ��վ&Ǭ��ʯ
//----------------------------------------------------------------------------
struct NET_SIC_posthouse : public tag_net_message
{
	NET_SIC_posthouse()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_posthouse");
		dw_size = sizeof(NET_SIC_posthouse);
	}
	DWORD	dwNPCID;	// ְ��NPC ID
	INT32	nIndex;		// ��վĿ�ĵ��ڸ�NPC������
	DWORD	dwPosID;	// ��վid
	BYTE	by_type;	// �������� 0 ��ͨ 1 ��Ӣ�����������ͨ��ͼ��ֵ��0��
	DWORD	dwMapID;	// Ŀ�ĵ�Map ID
};

struct NET_SIS_posthouse : public tag_net_message
{
	NET_SIS_posthouse()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_posthouse");
		dw_size = sizeof(NET_SIS_posthouse);
	}
	DWORD	dw_error_code;
};

// ����ɨ������
struct NET_SIS_get_saodang_data : public tag_net_message
{
	NET_SIS_get_saodang_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_saodang_data");
		dw_size = sizeof(NET_SIS_get_saodang_data);
	}
	int		nIndex;		// ��������
	tagDWORDTime	dwBeginTime;	//��ʼʱ��
};

// ����ɨ��
struct NET_SIC_instance_saodang : public tag_net_message
{
	NET_SIC_instance_saodang()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_instance_saodang");
		dw_size = sizeof(NET_SIC_instance_saodang);
	}

	int		nIndex;		// ��������

};

struct NET_SIS_instance_saodang : public tag_net_message
{
	NET_SIS_instance_saodang()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_instance_saodang");
		dw_size = sizeof(NET_SIS_instance_saodang);
	}
	int		nIndex;		// ��������
	DWORD	dw_error_code;
};

// ����ɨ��
struct NET_SIC_saodang_over : public tag_net_message
{
	NET_SIC_saodang_over()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_saodang_over");
		dw_size = sizeof(NET_SIC_saodang_over);
	}

};

struct NET_SIS_saodang_over : public tag_net_message
{
	NET_SIS_saodang_over()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_saodang_over");
		dw_size = sizeof(NET_SIS_saodang_over);
	}
	DWORD	dw_error_code;
};

struct NET_SIC_ware_extend : public tag_net_message
{
	NET_SIC_ware_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_ware_extend");
		dw_size = sizeof(NET_SIC_ware_extend);
	}
	DWORD	dwNPCID;
	bool	bUseSilver;		// true: ʹ����Ϸ�ң�false:ʹ��Ԫ��
};

struct NET_SIS_ware_extend : public tag_net_message
{
	NET_SIS_ware_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_ware_extend");
		dw_size = sizeof(NET_SIS_ware_extend);
	}
	DWORD	dw_error_code;
	INT16	n16WareNum;
};

struct NET_SIC_bag_extend : public tag_net_message
{
	NET_SIC_bag_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_bag_extend");
		dw_size = sizeof(NET_SIC_bag_extend);
	}
	INT64	n64ItemSerial;
	INT32	n32_type;		// 0 ���� 1 �ֿ�
};

struct NET_SIS_bag_extend : public tag_net_message
{
	NET_SIS_bag_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_bag_extend");
		dw_size = sizeof(NET_SIS_bag_extend);
	}
	DWORD	dw_error_code;
	INT32	n32_type;		// 0 ���� 1 �ֿ�
	INT16	n16BagNum;
};

//----------------------------------------------------------------------------
// ��Ǯ&Ԫ��
//----------------------------------------------------------------------------
struct NET_SIC_save_silver : public tag_net_message
{
	NET_SIC_save_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_save_silver");
		dw_size = sizeof(NET_SIC_save_silver);
	}
	DWORD	dwNPCID;
	INT64	n64SilverSave;
};

struct NET_SIS_save_silver : public tag_net_message
{
	NET_SIS_save_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_save_silver");
		dw_size = sizeof(NET_SIS_save_silver);
	}
	DWORD	dw_error_code;
};

struct NET_SIC_get_silver : public tag_net_message
{
	NET_SIC_get_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_silver");
		dw_size = sizeof(NET_SIC_get_silver);
	}
	DWORD	dwNPCID;
	INT64	n64SilverGet;
	DWORD	dw_safe_code;
};

struct NET_SIS_get_silver : public tag_net_message
{
	NET_SIS_get_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_silver");
		dw_size = sizeof(NET_SIS_get_silver);
	}
	DWORD	dw_error_code;
};

struct NET_SIS_save_yuan_bao : public tag_net_message
{
	NET_SIS_save_yuan_bao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_save_yuan_bao");
		dw_size = sizeof(NET_SIS_save_yuan_bao);
	}
	DWORD	dw_error_code;
};

// �Ӱٱ����л�ȡԪ��
struct NET_SIC_get_yuan_bao : public tag_net_message
{
	NET_SIC_get_yuan_bao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_yuan_bao");
		dw_size = sizeof(NET_SIC_get_yuan_bao);
	}
	INT		nYuanBaoGet;
};



//----------------------------------------------------------------------------
// ʹ��ĥʯ
//----------------------------------------------------------------------------
struct NET_SIC_abrase_stone : public tag_net_message
{
	NET_SIC_abrase_stone()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_abrase_stone");
		dw_size = sizeof(NET_SIC_abrase_stone);
	}
	INT64	n64AbraserSerial;	// ĥʯ64λid
	//INT64	n64WeaponSerial;	// ����64λid
};

struct NET_SIS_abrase_stone : public tag_net_message
{
	NET_SIS_abrase_stone()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_abrase_stone");
		dw_size = sizeof(NET_SIS_abrase_stone);
	}
	DWORD	dw_error_code;
	//INT64	n64WeaponSerial;	// ����64λid
	//INT		nAttackTimes;		// ���º�����ʹ�ô���
};


//----------------------------------------------------------------------------
#pragma pack(pop)
#endif