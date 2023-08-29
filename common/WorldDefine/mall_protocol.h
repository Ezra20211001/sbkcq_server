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
*	@file		mall_protocol.h
*	@author		lc
*	@date		2011/03/08	initial
*	@version	0.0.1.0
*	@brief		�̳���Ϣ
*/

#ifndef MALL_PROTOCOL
#define MALL_PROTOCOL

#pragma pack(push, 1)

#include "protocol_common_errorcode.h"
#include "mall_define.h"

//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum
{
	//E_Mall_				= ,	// 
	E_Mall_Close						= 1,	// �̳ǹر�

	E_Mall_Item_NotEnough				= 10,	// ��Ʒ�������㹺�����
	E_Mall_Pack_NotEnough				= 11,	// ��Ʒ���������㹺�����

	E_Mall_ID_Error						= 12,	// ID����ȷ
	E_Mall_YuanBao_Error				= 13,	// Ԫ�����۲���ȷ
	E_Mall_Free_NotExist				= 14,	// �����������Ʒ
	E_Mall_ExVolume_Error				= 15,	// ���㵥�۲���ȷ
	E_Mall_Exchange_NotAllowable		= 16,	// ��Ʒ���ɶһ�

	E_Mall_CreateItem_Failed			= 20,	// ��Ʒ����ʧ��
	E_Mall_CreatePres_Failed			= 21,	// ��Ʒ����ʧ��

	E_Mall_Free_AlreadyGet				= 25,	// �����Ʒ����ȡ

	// Ԫ������
	E_Trade_BagYB_NotEnough				= 40,	// ������Ԫ������
	E_Trade_BagSilver_NotEnough			= 41,	// �����н�Ǯ����
	E_Trade_AccountYB_NotEnough			= 42,	// �˻���Ԫ������
	E_Trade_AccountSilver_NotEnough		= 43,	// �˻��н�Ǯ����
	E_Trade_SellOrder_Exit				= 44,	// ֻ���ύһ��Ԫ�����۶���
	E_Trade_BuyOrder_Exit				= 45,	// ֻ���ύһ��Ԫ���չ�����
	E_Trade_Tax_NotEnough				= 46,	// ���������Ѳ���

	// �����Ź� 
	E_GroupPurchase_NotMember			= 50,	// ���Ǳ����ɳ�Ա 
	E_GroupPurchase_ItemNotAllowable	= 51,	// ����Ʒ���ɽ����Ź� //�ѹ�������
	E_GroupPurchase_NotInGuild			= 52,	// ���û�м������   
	E_GroupPurchase_AlreadyInitiate		= 53,	// �Ѿ��Ը���Ʒ������Ź�
	E_GroupPurchase_IsInitiate			= 54,	// ������Ӧ�Լ�������Ź�
	E_GroupPurchase_AlreadyRespond		= 55,	// �Ѿ���Ӧ�����Ź�
	E_GroupPurchase_AlreadyEnd			= 56,	// �Ź��Ѿ�����
	E_GroupPurchase_NoInfo				= 57,	// �Ź���Ϣ������
	E_GroupPurchase_ServerBusy			= 58,	// ������æ

	//gx modify 2013.11.22
	E_MALL_SALE_START				= 59,	//����Ʒ��δ�ϼ�
	E_MALL_SALE_END					= 60,	//����Ʒ�Ѿ��¼�
	
};

//-----------------------------------------------------------------------------
// �����ýṹ
//-----------------------------------------------------------------------------
struct tagSimGPInfo
{
	DWORD			dwGuildID;
	DWORD			dw_role_id;
	DWORD			dwMallID;
	INT32			nPrice;				//�Ź��۸�
	INT16			nParticipatorNum;	//��Ӧ����
	INT16			nRequireNum;		//�Ź���������
	DWORD			dwRemainTime;		//ʣ��ʱ��
};

//----------------------------------------------------------------------------
// ��Ϣ
//----------------------------------------------------------------------------

//--ͬ������
struct NET_SIS_open_mall : public tag_net_message
{
	NET_SIS_open_mall()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_open_mall");
		dw_size = sizeof(NET_SIS_open_mall);
	}
	DWORD		dw_error_code;
	DWORD		dwMallTime;
};

//�������ѯ���Ƿ���Դ��̳�
struct NET_SIC_mall_get : public tag_net_message
{
	NET_SIC_mall_get()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_get");
		dw_size = sizeof(NET_SIC_mall_get);
	}
};

struct NET_SIS_mall_item : public tag_net_message
{
	NET_SIS_mall_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_item");
		dw_size = sizeof(NET_SIS_mall_item);
	}
	INT			nItemNum;
	BYTE		byData[1];				// tagMallItemProto
};

struct NET_SIS_mall_free_item : public tag_net_message
{
	NET_SIS_mall_free_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_free_item");
		dw_size = sizeof(NET_SIS_mall_free_item);
	}
	tagMallFreeItem		freeItem;
};

struct NET_SIS_mall_pack : public tag_net_message
{
	NET_SIS_mall_pack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_pack");
		dw_size = sizeof(NET_SIS_mall_pack);
	}
	INT			nPackNum;
	BYTE		byData[1];
};


//--����
struct NET_SIC_mall_update : public tag_net_message
{
	NET_SIC_mall_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_update");
		dw_size = sizeof(NET_SIC_mall_update);
	}
	DWORD		dwMallTime;
};

struct NET_SIS_mall_update : public tag_net_message
{
	NET_SIS_mall_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_update");
		dw_size = sizeof(NET_SIS_mall_update);
	}
	DWORD		 dwMallTime;
};

struct NET_SIS_mall_update_item : public tag_net_message
{
	NET_SIS_mall_update_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_update_item");
		dw_size = sizeof(NET_SIS_mall_update_item);
	}
	INT			nItemNum;
	BYTE		byData[1];
};

struct NET_SIS_mall_update_pack : public tag_net_message
{
	NET_SIS_mall_update_pack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_update_pack");
		dw_size = sizeof(NET_SIS_mall_update_pack);
	}
	INT			nItemNum;
	BYTE		byData[1];
};

//--����
struct NET_SIC_mall_buy_item : public tag_net_message
{
	NET_SIC_mall_buy_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_buy_item");
		dw_size = sizeof(NET_SIC_mall_buy_item);
	}
	DWORD		dw_data_id;				// �̳���ƷID
	INT			nPrice;					// ��Ʒ�۸�(��ҹ���ʱ�ĵ���)
	INT16		n16BuyNum;				// �������
	BYTE		byIndexInServer;		// �ڷ������е�λ��		
};

struct NET_SIS_mall_buy_item : public tag_net_message
{
	NET_SIS_mall_buy_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_buy_item");
		dw_size = sizeof(NET_SIS_mall_buy_item);
	}
	DWORD		dw_error_code;
};

struct NET_SIC_mall_buy_pack : public tag_net_message
{
	NET_SIC_mall_buy_pack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_buy_pack");
		dw_size = sizeof(NET_SIC_mall_buy_pack);
	}
	DWORD		dw_data_id;				// �̳���ƷID
	INT			nPrice;					// ��Ʒ�۸�(��ҹ���ʱ�ĵ���)
	INT16		n16BuyNum;				// �������
	BYTE		byIndexInServer;		// �ڷ������е�λ��		
};

struct NET_SIS_mall_buy_pack : public tag_net_message
{
	NET_SIS_mall_buy_pack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_buy_pack");
		dw_size = sizeof(NET_SIS_mall_buy_pack);
	}
	DWORD		dw_error_code;
};

//--����
struct NET_SIC_mall_present_item : public tag_net_message
{
	NET_SIC_mall_present_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_present_item");
		dw_size = sizeof(NET_SIC_mall_present_item);
	}
	DWORD		dw_data_id;				// �̳���ƷID
	INT			nPrice;					// ��Ʒ�۸�(��ҹ���ʱ�ĵ���)
	DWORD		dwRoleTgtID;			// Ҫ�͵����ID
	INT16		n16BuyNum;				// �������
	BYTE		byIndexInServer;		// �ڷ������е�λ��		
	TCHAR		szLeave[Max_LeaveWord_Length];
};

struct NET_SIS_mall_present_item : public tag_net_message
{
	NET_SIS_mall_present_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_present_item");
		dw_size = sizeof(NET_SIS_mall_present_item);
	}
	DWORD		dw_error_code;
};

struct NET_SIC_mall_present_pack : public tag_net_message
{
	NET_SIC_mall_present_pack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_present_pack");
		dw_size = sizeof(NET_SIC_mall_present_pack);
	}
	DWORD		dw_data_id;				// �̳���ƷID
	INT			nPrice;					// ��Ʒ�۸�(��ҹ���ʱ�ĵ���)
	DWORD		dwRoleTgtID;			// Ҫ�͵����ID
	INT16		n16BuyNum;				// �������
	BYTE		byIndexInServer;		// �ڷ������е�λ��		
	TCHAR		szLeave[Max_LeaveWord_Length];
};

struct NET_SIS_mall_present_pack : public tag_net_message
{
	NET_SIS_mall_present_pack()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_present_pack");
		dw_size = sizeof(NET_SIS_mall_present_pack);
	}
	DWORD		dw_error_code;
};

//--�����ȡ
struct NET_SIC_mall_free_get_item : public tag_net_message
{
	NET_SIC_mall_free_get_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_free_get_item");
		dw_size = sizeof(NET_SIC_mall_free_get_item);
	}
	DWORD		dw_data_id;
};

struct NET_SIS_mall_free_get_item : public tag_net_message
{
	NET_SIS_mall_free_get_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_free_get_item");
		dw_size = sizeof(NET_SIS_mall_free_get_item);
	}
	DWORD		dw_error_code;
};


//--�����Ź�
struct NET_SIC_launch_group_purchase : public tag_net_message
{
	NET_SIC_launch_group_purchase()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_launch_group_purchase");
		dw_size = sizeof(NET_SIC_launch_group_purchase);
	}
	DWORD		dw_data_id;				// �̳���ƷID
	INT			nPrice;					// ��Ʒ�۸�(��ҹ���ʱ�ĵ���)
	BYTE		byScope;				// �Ź���ģ
	BYTE		byIndexInServer;		// �ڷ������е�λ��
};

struct NET_SIS_launch_group_purchase : public tag_net_message
{
	NET_SIS_launch_group_purchase()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_launch_group_purchase");
		dw_size = sizeof(NET_SIS_launch_group_purchase);
	}
	DWORD		dw_error_code;
};

struct NET_SIC_respond_group_purchase : public tag_net_message
{
	NET_SIC_respond_group_purchase()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_respond_group_purchase");
		dw_size = sizeof(NET_SIC_respond_group_purchase);
	}
	DWORD		dwGuildID;				// �Ź���Ϣ��������
	DWORD		dw_data_id;				// �̳���ƷID
	DWORD		dw_role_id;				// ������ID
	INT			nPrice;					// ��Ʒ�۸�(�Ź��ܼ۸�)
};

struct NET_SIS_respond_group_purchase : public tag_net_message
{
	NET_SIS_respond_group_purchase()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_respond_group_purchase");
		dw_size = sizeof(NET_SIS_respond_group_purchase);
	}
	DWORD		dw_error_code;
	INT64		nGroupPurchaseKey;		// �Ź���Ϣ��ֵ(RoleID<<32 | MallID)
};

struct NET_SIC_guild_buy_info : public tag_net_message
{
	NET_SIC_guild_buy_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_guild_buy_info");
		dw_size = sizeof(NET_SIC_guild_buy_info);
	}
};

struct NET_SIS_guild_buy_info : public tag_net_message
{
	NET_SIS_guild_buy_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_guild_buy_info");
		dw_size = sizeof(NET_SIS_guild_buy_info);
	}
	DWORD				dw_error_code;
	INT32				nGroupPurchase;		// �����Ź�ָ��
	INT					nGPInfoNum;			// �Ź���Ϣ����
	tagSimGPInfo		simData[1];			// �������Ź���Ϣ
};

struct NET_SIC_get_participators : public tag_net_message
{
	NET_SIC_get_participators()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_participators");
		dw_size = sizeof(NET_SIC_get_participators);
	}
	DWORD		dwGuildID;				// �Ź���Ϣ��������
	DWORD		dw_data_id;				// �̳���ƷID
	DWORD		dw_role_id;				// ������ID	
};

struct NET_SIS_get_participators : public tag_net_message
{
	NET_SIS_get_participators()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_participators");
		dw_size = sizeof(NET_SIS_get_participators);
	}
	DWORD		dw_error_code;
	INT64		nGroupPurchaseKey;		// �Ź���Ϣ��ֵ(RoleID<<32 | MallID)
	INT			nParticipatorNum;		// ��Ӧ������
	DWORD		dwParticipators[1];		// ��Ӧ���б�
};


enum ERespondBroadCast
{
	ERespondBroadCast_NULL		= 0,
	ERespondBroadCast_Launch,
	ERespondBroadCast_Success,
	ERespondBroadCast_Lose,
};

struct NET_SIS_respond_broad : public tag_net_message
{
	NET_SIS_respond_broad()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_respond_broad");
		dw_size = sizeof(NET_SIS_respond_broad);
	}
	ERespondBroadCast	eType;
	DWORD				dw_role_id;
	DWORD				dw_data_id;			//��ƷTypeID
};


//--�һ�
struct NET_SIC_mall_item_exchange : public tag_net_message
{
	NET_SIC_mall_item_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_item_exchange");
		dw_size = sizeof(NET_SIC_mall_item_exchange);
	}
	DWORD		dwMallID;				// �̳���ƷID
	INT			nPrice;					// ������Ʒ������������
	INT16		n16BuyNum;				// �һ�����
	BYTE		byIndexInServer;		// �ڷ������е�λ��		
};

struct NET_SIS_mall_item_exchange : public tag_net_message
{
	NET_SIS_mall_item_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_item_exchange");
		dw_size = sizeof(NET_SIS_mall_item_exchange);
	}
	DWORD		dw_error_code;
};

struct NET_SIC_mall_pack_exchange : public tag_net_message
{
	NET_SIC_mall_pack_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_mall_pack_exchange");
		dw_size = sizeof(NET_SIC_mall_pack_exchange);
	}
	DWORD		dwMallID;				// �̳���ƷID
	INT			nPrice;					// ������������
	BYTE		byIndexInServer;		// �ڷ������е�λ��	
};

struct NET_SIS_mall_pack_exchange : public tag_net_message
{
	NET_SIS_mall_pack_exchange()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_mall_pack_exchange");
		dw_size = sizeof(NET_SIS_mall_pack_exchange);
	}
	DWORD		dw_error_code;
};

//----------------------------------------------------------------------------
// Ԫ������
//----------------------------------------------------------------------------
// ͬ�������˻���Ԫ����
struct NET_SIS_synchronize_account_yuanbao : public tag_net_message
{
	NET_SIS_synchronize_account_yuanbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_account_yuanbao");
		dw_size = sizeof(NET_SIS_synchronize_account_yuanbao);
	}
	INT			nYuanBao;
};

// ͬ�������˻��Ľ�Ǯ��
struct NET_SIS_synchronize_account_silver : public tag_net_message
{
	NET_SIS_synchronize_account_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_account_silver");
		dw_size = sizeof(NET_SIS_synchronize_account_silver);
	}
	INT64		nSilver;
};

// ͬ�������˻�
struct NET_SIS_synchronize_account : public tag_net_message
{
	NET_SIS_synchronize_account()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_account");
		dw_size = sizeof(NET_SIS_synchronize_account);
	}
	INT			nYuanBao;
	INT			nSilver;
};

// ��������˻���Ԫ��
struct NET_SIC_save_yuanbao_to_account : public tag_net_message
{
	NET_SIC_save_yuanbao_to_account()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_save_yuanbao_to_account");
		dw_size = sizeof(NET_SIC_save_yuanbao_to_account);
	}
	INT			n_num;					// Ԫ������
};

struct NET_SIS_save_yuanbao_to_account : public tag_net_message
{
	NET_SIS_save_yuanbao_to_account()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_save_yuanbao_to_account");
		dw_size = sizeof(NET_SIS_save_yuanbao_to_account);
	}
	DWORD		dw_error_code;
};

// ��������˻����Ǯ
struct NET_SIC_save_silver_to_account : public tag_net_message
{
	NET_SIC_save_silver_to_account()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_save_silver_to_account");
		dw_size = sizeof(NET_SIC_save_silver_to_account);
	}
	INT64		n_num;
};

struct NET_SIS_save_silver_to_account : public tag_net_message
{
	NET_SIS_save_silver_to_account()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_save_silver_to_account");
		dw_size = sizeof(NET_SIS_save_silver_to_account);
	}
	DWORD		dw_error_code;
};

// �ӽ����˻���ȡԪ��
struct NET_SIC_deposit_account_yuanbao : public tag_net_message
{
	NET_SIC_deposit_account_yuanbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_deposit_account_yuanbao");
		dw_size = sizeof(NET_SIC_deposit_account_yuanbao);
	}
	INT			n_num;
};

struct NET_SIS_deposit_account_yuanbao : public tag_net_message
{
	NET_SIS_deposit_account_yuanbao()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_deposit_account_yuanbao");
		dw_size = sizeof(NET_SIS_deposit_account_yuanbao);
	}
	DWORD		dw_error_code;
};

// �ӽ����˻���ȡ��Ǯ
struct NET_SIC_deposit_account_silver : public tag_net_message
{
	NET_SIC_deposit_account_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_deposit_account_silver");
		dw_size = sizeof(NET_SIC_deposit_account_silver);
	}
	INT64		n_num;
};

struct NET_SIS_deposit_account_silver : public tag_net_message
{
	NET_SIS_deposit_account_silver()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_deposit_account_silver");
		dw_size = sizeof(NET_SIS_deposit_account_silver);
	}
	DWORD		dw_error_code;
};

// ��ȡ����Ԫ�����׼۸���б�ͽ����˻���Ϣ
struct NET_SIC_synchronize_yuanbao_trade_info : public tag_net_message
{
	NET_SIC_synchronize_yuanbao_trade_info()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_synchronize_yuanbao_trade_info");
		dw_size = sizeof(NET_SIC_synchronize_yuanbao_trade_info);
	}
};

struct NET_SIS_get_sell_price_list : public tag_net_message
{
	NET_SIS_get_sell_price_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_sell_price_list");
		dw_size = sizeof(NET_SIS_get_sell_price_list);
	}
	INT				nListNum;
	tagYBPriceList	YBPriceList[1];
};

struct NET_SIS_get_buy_price_list : public tag_net_message
{
	NET_SIS_get_buy_price_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_buy_price_list");
		dw_size = sizeof(NET_SIS_get_buy_price_list);
	}
	INT				nListNum;
	tagYBPriceList	YBPriceList[1];
};

// ���Ԫ�������˻�
struct NET_SIS_get_yuanbao_account : public tag_net_message
{
	NET_SIS_get_yuanbao_account()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_yuanbao_account");
		dw_size = sizeof(NET_SIS_get_yuanbao_account);
	}
	DWORD			dw_role_id;			// ���ID
	INT				nYuanBao;			// Ԫ������
	INT64			nSilver;			// ��Ǯ����
	BOOL			bSellOrder;			// �Ƿ��г��۶���
	BOOL			bBuyOrder;			// �Ƿ����չ�����
};

// ͬ�����ۼ۸��б�
struct NET_SIS_synchronize_price_list : public tag_net_message
{
	NET_SIS_synchronize_price_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_price_list");
		dw_size = sizeof(NET_SIS_synchronize_price_list);
	}
	INT				nPrice;
	INT				n_num;
};

// ͬ������۸��б�
struct NET_SIS_synchronize_buy_price_list : public tag_net_message
{
	NET_SIS_synchronize_buy_price_list()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_synchronize_buy_price_list");
		dw_size = sizeof(NET_SIS_synchronize_buy_price_list);
	}
	INT				nPrice;
	INT				n_num;
};

// �ύԪ�����۶���
struct NET_SIC_submit_sell_order : public tag_net_message
{
	NET_SIC_submit_sell_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_submit_sell_order");
		dw_size = sizeof(NET_SIC_submit_sell_order);
	}
	INT				n_num;				// Ԫ������
	INT				nPrice;				// ����
};

struct NET_SIS_submit_sell_order : public tag_net_message
{
	NET_SIS_submit_sell_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_submit_sell_order");
		dw_size = sizeof(NET_SIS_submit_sell_order);
	}
	DWORD			dw_error_code;
};

// �ύԪ���չ�����
struct NET_SIC_submit_buy_order : public tag_net_message
{
	NET_SIC_submit_buy_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_submit_buy_order");
		dw_size = sizeof(NET_SIC_submit_buy_order);
	}
	INT				n_num;
	INT				nPrice;
};

struct NET_SIS_submit_buy_order : public tag_net_message
{
	NET_SIS_submit_buy_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_submit_buy_order");
		dw_size = sizeof(NET_SIS_submit_buy_order);
	}
	DWORD			dw_error_code;
};

 // �����Ҷ���
struct NET_SIC_get_yuanbao_order : public tag_net_message
{
	NET_SIC_get_yuanbao_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_yuanbao_order");
		dw_size = sizeof(NET_SIC_get_yuanbao_order);
	}
};

struct NET_SIS_get_yuanbao_order : public tag_net_message
{
	NET_SIS_get_yuanbao_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_yuanbao_order");
		dw_size = sizeof(NET_SIS_get_yuanbao_order);
	}
	INT             n_num;               // ��������
	tagYuanBaoOrder Orders[1];
};

// ɾ������
struct NET_SIC_delete_order : public tag_net_message
{
	NET_SIC_delete_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_order");
		dw_size = sizeof(NET_SIC_delete_order);
	}
	DWORD			dwOrderID;			// ����ID
	EYBOTYPE		eYBOType;			// ��������
};

struct NET_SIS_delete_order : public tag_net_message
{
	NET_SIS_delete_order()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_order");
		dw_size = sizeof(NET_SIS_delete_order);
	}
	DWORD			dw_error_code;
};


#pragma pack(pop)
#endif