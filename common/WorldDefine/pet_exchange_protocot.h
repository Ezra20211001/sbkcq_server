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
*	@file		pet_exchange_protocot.h
*	@author		lc
*	@date		2011/03/09	initial
*	@version	0.0.1.0
*	@brief		���ｻ����Ϣ
*/

#ifndef PET_EXCHANGE_PROTOCOL
#define PET_EXCHANGE_PROTOCOL

#include "protocol_common_errorcode.h"

#pragma pack(push, 1)
//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum
{
    E_Pet_Exchange_Accept				= E_Success,	// �Է�ͬ�⽻��
    E_Pet_Exchange_Refuse				= 1,	// �Է��ܾ�		
    E_Pet_Exchange_NotEnough_Space	    = 2,	// �������ռ䲻��
    E_Pet_Exchange_RoleBusy				= 3,	// �����뷽æ	
    E_Pet_Exchange_WithMore				= 4,	// ���ܺͶ���ͬʱ����
    E_Pet_Exchange_OutOfRange			= 5,	// ���׾��뷶Χ֮��
    E_Pet_Exchange_NotInSame_Map		= 6,	// ����ͬһ����
    E_Pet_Exchange_PetCanNot_Exchange	= 7,	// ���ﲻ�ܽ���
    E_Pet_Exchange_PetCanNot_Find		= 8,	// û���ҵ�ָ���ĳ���
    E_Pet_Exchange_NotEnough_Money		= 9,	// ���׵Ľ�Ǯ����
    E_Pet_Exchange_ApplicantTgt_Change	= 10,	// ��������Ľ���Ŀ�귢���仯
    E_Pet_Exchange_NotAnswer			= 11,	// �Է�û����Ӧ
    E_Pet_Exchange_SelfBusy				= 12,	// ����Լ�æ

	E_Pet_Exchange_PetHasEquip			= 20,	// ������װ��
	E_Pet_Exchange_RoleLvlNotEnough		= 21,	// Ŀ����ҵȼ�����
	E_Pet_Exchange_PetLocked			= 22,	// ���ﱻ����
	E_Pet_Exchange_PetBinded			= 23,	// ���ﱻ��
	E_Pet_Exchange_PetStateNotAllow		= 24,	// ����״̬������

    E_Pet_Exchange_End
};




//----------------------------------------------------------------------------
// ��������
//----------------------------------------------------------------------------

// ������󽻻�����
struct NET_SIC_pet_exchange_request : public tag_net_message
{
	NET_SIC_pet_exchange_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_request");
		dw_size = sizeof(NET_SIC_pet_exchange_request);
	}
	 DWORD	dwDstID;	// ��ϢĿ��ID
};

// ������ת����Ŀ�����
struct NET_SIS_pet_exchange_request : public tag_net_message
{
	NET_SIS_pet_exchange_request()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_request");
		dw_size = sizeof(NET_SIS_pet_exchange_request);
	}
	DWORD	dwSrcID;	// ��Ϣ������ID
};


// Ŀ����ҽ���������
struct NET_SIC_pet_exchange_request_result : public tag_net_message
{
	NET_SIC_pet_exchange_request_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_request_result");
		dw_size = sizeof(NET_SIC_pet_exchange_request_result);
	}
	DWORD	dw_error_code;
	DWORD	dwDstID;
};


// ������ת����˫����ҽ���������
struct NET_SIS_pet_exchange_request_result : public tag_net_message
{
	NET_SIS_pet_exchange_request_result()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_request_result");
		dw_size = sizeof(NET_SIS_pet_exchange_request_result);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;    // ������id
	DWORD	dwDstID;    // Ŀ��id
};

//----------------------------------------------------------------------------
// ���׹���
//----------------------------------------------------------------------------


// ��ӽ��׵ĳ���
struct NET_SIC_pet_exchange_add : public tag_net_message
{
	NET_SIC_pet_exchange_add()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_add");
		dw_size = sizeof(NET_SIC_pet_exchange_add);
	}
	 DWORD	dwPetID;
};

// ��������ɹ��򱾵����
struct NET_SIS_pet_exchange_add_to_src : public tag_net_message
{
	NET_SIS_pet_exchange_add_to_src()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_add_to_src");
		dw_size = sizeof(NET_SIS_pet_exchange_add_to_src);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;        // ��ӷ�����id
	DWORD	dwDstID;
	DWORD	dwPetID;
};


// ��ɹ���֪ͨĿ�������ӳ���
struct NET_SIS_exchange_add_to_dest : public tag_net_message
{
	NET_SIS_exchange_add_to_dest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_exchange_add_to_dest");
		dw_size = sizeof(NET_SIS_exchange_add_to_dest);
	}
	DWORD	dwSrcID;        // �Է�������id
	DWORD	dwPetID;
};


// ȡ�����׵ĳ���
struct NET_SIC_pet_exchange_subtract : public tag_net_message
{
	NET_SIC_pet_exchange_subtract()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_subtract");
		dw_size = sizeof(NET_SIC_pet_exchange_subtract);
	}
	DWORD	dwSrcID;        // ��ӷ�����id
	DWORD	dwPetID;
};


// ��������ɹ��򱾵ؼ���
struct NET_SIS_pet_exchange_subtract : public tag_net_message
{
	NET_SIS_pet_exchange_subtract()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_subtract");
		dw_size = sizeof(NET_SIS_pet_exchange_subtract);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;        // ���ٷ�����id
	DWORD	dwDstID;
	DWORD	dwPetID;
};


// ��ɹ���֪ͨĿ�����ȡ������
struct NET_SIS_pet_exchange_subtract_to_dest : public tag_net_message
{
	NET_SIS_pet_exchange_subtract_to_dest()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_subtract_to_dest");
		dw_size = sizeof(NET_SIS_pet_exchange_subtract_to_dest);
	}
	DWORD	dwSrcID;        // ���ٷ�����id
	DWORD	dwPetID;
};


// ��Ǯ�����ı� 
struct NET_SIC_pet_exchange_money : public tag_net_message
{
	NET_SIC_pet_exchange_money()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_money");
		dw_size = sizeof(NET_SIC_pet_exchange_money);
	}
	INT64	n64Money;
};


// ֪ͨ˫��
struct NET_SIS_pet_exchange_money : public tag_net_message
{
	NET_SIS_pet_exchange_money()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_money");
		dw_size = sizeof(NET_SIS_pet_exchange_money);
	}
	DWORD	dw_error_code;	
	INT64	n64Money;
	DWORD	dwSrcID;       // �ı��Ǯ������id
};

// �������׳���
struct NET_SIC_pet_exchange_lock : public tag_net_message
{
	NET_SIC_pet_exchange_lock()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_lock");
		dw_size = sizeof(NET_SIC_pet_exchange_lock);
	}
};


// ֪ͨ˫��
struct NET_SIS_pet_exchange_lock : public tag_net_message
{
	NET_SIS_pet_exchange_lock()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_lock");
		dw_size = sizeof(NET_SIS_pet_exchange_lock);
	}
	DWORD	dw_error_code;
	DWORD	dwSrcID;       // �������׷�����id
};


// ȡ������
struct NET_SIC_pet_exchange_cancel : public tag_net_message
{
	NET_SIC_pet_exchange_cancel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_cancel");
		dw_size = sizeof(NET_SIC_pet_exchange_cancel);
	}
};


// ֪ͨ˫��
struct NET_SIS_pet_exchange_cancel : public tag_net_message
{
	NET_SIS_pet_exchange_cancel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_cancel");
		dw_size = sizeof(NET_SIS_pet_exchange_cancel);
	}
	 DWORD	dwSrcID;        // ȡ�����׷�����id
};


// ���ȷ�Ͻ���
struct NET_SIC_pet_exchange_verify : public tag_net_message
{
	NET_SIC_pet_exchange_verify()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_exchange_verify");
		dw_size = sizeof(NET_SIC_pet_exchange_verify);
	}
};


// �������
struct NET_SIS_pet_exchange_finish : public tag_net_message
{
	NET_SIS_pet_exchange_finish()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_exchange_finish");
		dw_size = sizeof(NET_SIS_pet_exchange_finish);
	}
	DWORD	dw_error_code;
	DWORD	dwFailedRoleID;		// ����ʧ����ID
};


//----------------------------------------------------------------------------
#pragma pack(pop)
#endif