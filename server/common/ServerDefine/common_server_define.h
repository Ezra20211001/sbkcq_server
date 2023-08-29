/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

 ��ɫͨ��������Ϣ
*******************************************************************************/


#ifndef _COMMON_SERVER_DEFINE_H_
#define _COMMON_SERVER_DEFINE_H_

#pragma pack(push, 1)
//-----------------------------------------------------------------------------

//! ���İ�������
struct NET_DB2C_change_bag_password : public tag_net_message
{   
	NET_DB2C_change_bag_password ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_change_bag_password" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_account_id; 
	DWORD dw_bag_password;  
};  


//! ���ð�ȫ��
struct NET_DB2C_safe_code_set : public tag_net_message 
{  
	NET_DB2C_safe_code_set ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_safe_code_set" ) ; 
		dw_size = sizeof ( * this ) ;
	}  
	DWORD dw_account_id;
	DWORD dw_safe_code_crc;  
};  

//CMD_START(NDBS_SafeCodeSet)
//	DWORD		dw_error_code;
//CMD_END

//! ���谲ȫ��
struct NET_DB2C_safe_code_reset : public tag_net_message 
{ 
	NET_DB2C_safe_code_reset ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_safe_code_reset" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_account_id; 
	DWORD dw_reset_time;   
};  

//! ȡ����ȫ��
struct NET_DB2C_safe_code_reset_cancel : public tag_net_message 
{  
	NET_DB2C_safe_code_reset_cancel ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_safe_code_reset_cancel" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_account_id;  
};  

//! ������С����
struct NET_DB2C_ware_size_update : public tag_net_message
{   
	NET_DB2C_ware_size_update ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_ware_size_update" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_account_id; 
	INT16 n16_ware_size; 
	INT16 n16_ware_step;
};  

//! ��Ǯ����
struct NET_DB2C_ware_money_update : public tag_net_message 
{   
	NET_DB2C_ware_money_update ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_ware_money_update" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_account_id; 
	INT64 n64_ware_silver; 
};  

//! ���·ǰ󶨱�
struct NET_DB2C_bag_money_update : public tag_net_message
{
	NET_DB2C_bag_money_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_bag_money_update");
		dw_size = sizeof(*this);
	}

	DWORD	dw_role_id;
	INT				n_bag_gold_;					// �����н�����
	INT				n_bag_silver_;					// ������������
	INT				n_bag_copper_;					// ������ͭ��
};

//! Ԫ������
struct NET_DB2C_baibao_yuanbao_update : public tag_net_message 
{  
	NET_DB2C_baibao_yuanbao_update ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_baibao_yuanbao_update" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_account_id; 
	INT nBaiBaoYuanBao;   
};  

//! ���ָ���
struct NET_DB2C_exchange_volume_update : public tag_net_message
{
	NET_DB2C_exchange_volume_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_exchange_volume_update");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
	INT		n_volume;
};

// ���½�Ʒ��ȡ��־
struct NET_DB2C_update_receive : public tag_net_message
{
	NET_DB2C_update_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_receive");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
};

// ���½�Ʒ��ȡ��־
struct NET_DB2C_update_receive_ex : public tag_net_message
{
	NET_DB2C_update_receive_ex()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_receive_ex");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
	DWORD	dw_receive_type;
};

// ������ҳ�콱��־
struct NET_DB2C_update_web_recieve : public tag_net_message
{
	NET_DB2C_update_web_recieve()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_web_recieve");
		dw_size = sizeof(*this);
	}

	DWORD	dw_account_id;
};

// ɾ�����к����
struct NET_DB2C_delete_serial_reward : public tag_net_message
{
	NET_DB2C_delete_serial_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_delete_serial_reward");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
	CHAR	sz_serial[X_SHORT_NAME];
};


//-----------------------------------------------------------------------------
#pragma pack(pop)

#endif