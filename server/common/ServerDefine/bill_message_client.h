
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//ֱ�����������վ�ӿ�

#pragma once


#pragma pack(push, 1)

//! ��½ 1623520129
struct tagWeb2Bill_Login : public tag_net_message
{  
	tagWeb2Bill_Login ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "Web2Bill_Login" ) ;  //1623520129 size 124
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_glod_code;						// ��֤��
	CHAR  sz_world_name[X_SHORT_NAME];		// ��Ϸ��������
	CHAR  sz_trade_code[X_SHORT_NAME];		// ���׺�
	CHAR  sz_account_name[X_SHORT_NAME];	// �˺�����
	CHAR  sz_serial_reward[X_SHORT_NAME];	// ������к�
	INT	  n_serial_type;					// �����������
	DWORD dw_recharge_num;					// ��ֵ���
	DWORD dw_account_id;					// �˺�id
	DWORD dw_receive_type;					// ��������
	INT	  n_type;							//1 ��ֵ 2 ���� 3 ��������� 4 ý�����
}; 

//! ���¼����Զ����� 1190903304
struct tagWeb2Bill_reload_auto_paimai : public tag_net_message
{
	tagWeb2Bill_reload_auto_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("Web2Bill_reload_auto_paimai");
		dw_size = sizeof(*this);
	}
	DWORD dw_glod_code;
	CHAR  sz_world_name[X_SHORT_NAME];
};

//! Ԫ������
struct tagNBS_YuanBao : public tag_net_message
{   
	tagNBS_YuanBao ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NBS_YuanBao" ) ; 
		dw_size = sizeof ( * this ) ;   
	}   
	CHAR sz_token_id[50];// ����ID
	DWORD dw_world_id;   // ��Ϸ����ID
	CHAR sz_account_name[50];  // �ʺ���
	INT n_num;   // Ԫ������
};  
struct tagBill2Web_Login : public tag_net_message
{
	tagBill2Web_Login()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("Bill2Web_Login"); //1917453688 size 84
		dw_size = sizeof(*this);
	}

	DWORD	dw_error;
	DWORD	dw_account_id;
	CHAR  sz_trade_code[X_SHORT_NAME];		// ���׺�
	CHAR  sz_account_name[X_SHORT_NAME];	// �˺�����
	INT	  n_type;							//1 ��ֵ 2 ���� 2 ���������
};

// ��ҳ��ֵ��Ϣ
struct tag_web_recharge_info
{
	DWORD	dw_world_crc;		// ��Ϸ����crcֵ
	CHAR	sz_trade_code[X_SHORT_NAME];		// ���׺�
	CHAR	sz_account_name[X_SHORT_NAME];		// �˺�����
	DWORD	dw_account_id;		// �˺�id
	DWORD	dw_recharge_num;	// ��ʵ���
};

// ��ҳ���Ϣ
struct tag_web_act_info
{
	DWORD	dw_world_crc;		// ��Ϸ����crcֵ
	CHAR	sz_account_name[X_SHORT_NAME];		// �˺�����
	DWORD	dw_account_id;		// �˺�id
	DWORD	dw_web_type;		// �����
};

// ���������
struct tag_serial_reward_info
{
	DWORD	dw_world_crc;		// ��Ϸʱ��crcֵ
	CHAR	sz_account_name[X_SHORT_NAME];		// �˺�����
	DWORD	dw_account_id;		// �˺�id
	CHAR	sz_serial_reward[X_SHORT_NAME];		// ������к�
	INT		n_type;				// �����������
};

// ý�������Ϣ
struct tag_media_act_info
{
	DWORD	dw_world_crc;		// ��Ϸ����crcֵ
	CHAR	sz_account_name[X_SHORT_NAME];		// �˺�����
	DWORD	dw_account_id;		// �˺�id
	DWORD	dw_type;			// �������
};

#pragma pack(pop)
