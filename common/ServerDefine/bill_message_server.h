
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//ֱ�����������Ϸ����Ľ��

#pragma once

//! ��Ϸ�����½
struct tagNWB_Login : public tag_net_message 
{  
	tagNWB_Login ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NWB_Login" ) ;  
		dw_size = sizeof ( * this ) ; 
	} 
	TCHAR sz_world_name[X_SHORT_NAME]; 
};  

struct tagNBW_Login : public tag_net_message 
{  
	tagNBW_Login ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NBW_Login" ) ;  
		dw_size = sizeof ( * this ) ;  
	}
	DWORD dw_error_code;  
};  

//! ��֪��Ϸ����ȡ�ٱ���
struct tagNBW_PickBaiBao : public tag_net_message
{  
	tagNBW_PickBaiBao ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NBW_PickBaiBao" ) ;   
		dw_size = sizeof ( * this ) ;  
	} 
	/*INT64 n64_serial;*/
	DWORD dw_account_id;  
	INT32 n32_yuanbao;
	DWORD dw_recharge_num;
};  

// ֪ͨ��Ϸ��������콱��־
struct tagNBW_ChangeReceive : public tag_net_message
{
	tagNBW_ChangeReceive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NBW_ChangeReceive");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
};

// ֪ͨ��Ϸ����������к����
struct tagNBW_UpdateSerialReward : public tag_net_message
{
	tagNBW_UpdateSerialReward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NBW_UpdateSerialReward");
		dw_size = sizeof(*this);
	}

	DWORD dw_account_id;
	INT	  n_type;
	CHAR  sz_serial[X_SHORT_NAME];
};

// ֪ͨ���¼����Զ�����
struct tagNBW_ReloadAutoPaimai : public tag_net_message
{
	tagNBW_ReloadAutoPaimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NBW_ReloadAutoPaimai");
		dw_size = sizeof(*this);
	}
};
