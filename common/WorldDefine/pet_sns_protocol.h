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
*	@brief		����sns��Ϣ
*/

#ifndef PET_SNS_PROTOCOL
#define PET_SNS_PROTOCOL

#pragma pack(push,1)

#include "pet_define.h"
//#include "protocol_common_errorcode.h"

//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum 
{
	E_Pets_SNS_UnkownErr		=-1,
	E_Pets_SNS_Success			= 0,	

	E_Pets_SNS_Soul_NotExist	= 1,	// ���ﲻ����
	E_PetS_SNS_Cannot_paiqian	= 2,	// ��ǰ״̬������ǲ
	E_PetS_SNS_Friend_Has_pet	= 3,	// �ú�������ǲ����
	E_PetS_SNS_Friend_NotExis	= 4,	// ���Ѳ����ڻ���˫�����
	E_PetS_SNS_Friend_Level_NotExis = 5, // �ȼ���̫��


	E_PetS_SNS_Not_Pet			= 6,	// û�иó���
	E_PetS_SNS_Not_Work			= 7,	// �ó���û����ǲ	
	E_PetS_SNS_Not_to_You		= 8,	// �ó��ﲻ���ɸ����
	E_PetS_SNS_Time_Not_Relay	= 9,	// ʱ��û����������ȡ�Է�����ᾧ
};


// ��ǲ����
struct NET_SIC_pet_paiqian : public tag_net_message
{
	NET_SIC_pet_paiqian()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_paiqian");
		dw_size = sizeof(NET_SIC_pet_paiqian);
	}
	DWORD           dw_pet_id;		//!< ����id
	DWORD           dw_friend_id;   //!< ����id
};


struct NET_SIS_pet_paiqian : public tag_net_message
{
	NET_SIS_pet_paiqian()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_paiqian");
		dw_size = sizeof(NET_SIS_pet_paiqian);
	}

	DWORD           dw_pet_id;      //!< ����ID
	DWORD           dw_friend_id;   //!< ����id
	DWORD			dw_time;		//!< ʱ��
	DWORD			dwErrCode;		//!< ������
};

// ����ǲ����
struct NET_SIS_pet_be_paiqian : public tag_net_message
{
	NET_SIS_pet_be_paiqian()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_be_paiqian");
		dw_size = sizeof(NET_SIS_pet_be_paiqian);

	}
	
	DWORD           dw_pet_id;      //!< ����ID
	DWORD           dw_friend_id;   //!< ����id
	DWORD			dw_time;		//!< ʱ��
};


// �ջس���
struct NET_SIC_pet_return : public tag_net_message
{
	NET_SIC_pet_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_pet_return");
		dw_size = sizeof(NET_SIC_pet_return);

	}

	DWORD           dw_pet_id;      //!< ����ID
	BYTE			by_type;		//0:�ջ��Լ��ĳ��� 1����ȡ���ѵĳ���
};

struct NET_SIS_pet_return : public tag_net_message
{
	NET_SIS_pet_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_return");
		dw_size = sizeof(NET_SIS_pet_return);

	}

	DWORD           dw_pet_id;      //!< ����ID
	BYTE			by_type;		//0:�ջ��Լ��ĳ��� 1����ȡ���ѵĳ���
	INT				n_itemNum;		//��ýᾧ����
	DWORD			dwErrCode;	
};


// ���ﱻ�Է��ջ���
struct NET_SIS_pet_be_return : public tag_net_message
{
	NET_SIS_pet_be_return()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_be_return");
		dw_size = sizeof(NET_SIS_pet_be_return);

	}

	DWORD           dw_pet_id;      //!< ����ID
	BYTE			by_type;		//0:�Լ��ĳ��ﱻ�ջ� 1���Է��ĳ��ﱻ�Է��ջ�
};


//�����ͻ��˳���sns��ʼ��Ϣ
struct NET_SIS_pet_SNS_info : public tag_net_message
{
	NET_SIS_pet_SNS_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_pet_SNS_info");
		dw_size = sizeof(NET_SIS_pet_SNS_info);

	}

	INT				n_num;		  // ����sns��Ϣ����
	tagPetSNSInfo	petSNSInfo[1];
};

#pragma pack(pop)
#endif
