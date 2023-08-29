/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#pragma once
#include "../common/WorldDefine/mail_define.h"

#pragma pack(push, 1)

const INT32 MAX_LOAD_BUFFER	= 10 * 1000 * 1000;	// ÿ�ζ�ȡ�ʼ�������ֽ�
const INT32 MAX_LOAD_NUM	= 10 * 1000;		// ÿ�η��͵��ʼ�����
const INT32 TMP_BUFFER		= 100 * 1000;		// �ʼ���ʱ����

struct s_load_mail
{
	TCHAR str_name[Max_Mail_Name+1];
	tagMailBase s_mail_base_;
};

struct tag_mail_content
{
	DWORD dw_main_serial; 
	TCHAR sz_content_[Max_Mail_Content+1]; 
};


//! ��ȡ�ʼ������
struct NET_DB2C_get_mail_max_serial : public tag_net_message 
{   
	NET_DB2C_get_mail_max_serial ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_get_mail_max_serial" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
};  

struct NET_DB2S_get_mail_max_serial : public tag_net_message 
{  
	NET_DB2S_get_mail_max_serial ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_get_mail_max_serial" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_max_mail_serial_;  
};  

//! ������Ʒ����
struct NET_DB2C_save_mail_item : public tag_net_message 
{ 
	NET_DB2C_save_mail_item ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_save_mail_item" ) ;  
		dw_size = sizeof ( * this ) ;
	}  
	INT n_count; 
	BYTE by_buffer_[1];
};  

//! �����ʼ�
struct NET_DB2C_save_mail : public tag_net_message 
{  
	NET_DB2C_save_mail ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_save_mail" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	TCHAR str_name_[Max_Mail_Name+1];  
	tagMailBase s_mail_base_;   
	TCHAR sz_content_[1];    
};  

//! ��ȡ�ʼ�
struct NET_DB2C_load_all_mail : public tag_net_message 
{   
	NET_DB2C_load_all_mail ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_load_all_mail" ) ; 
		dw_size = sizeof ( * this ) ;  
	}    
};  

struct NET_DB2S_load_all_mail : public tag_net_message 
{  
	NET_DB2S_load_all_mail ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_load_all_mail" ) ;   
		dw_size = sizeof ( * this ) ;  
	}   
	INT32 n32_num_;  
	s_load_mail s_load_mail_[1];   
};  

struct NET_DB2S_load_all_mail_end : public tag_net_message
{
	NET_DB2S_load_all_mail_end()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_all_mail_end");
		dw_size = sizeof(*this);
	}
};

//! ��ȡ�ʼ�����
struct NET_DB2C_load_mail_content : public tag_net_message
{ 
	NET_DB2C_load_mail_content ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_mail_content" ) ;
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_mail_serial_;   
};  

struct NET_DB2S_load_mail_content : public tag_net_message 
{  
	NET_DB2S_load_mail_content ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_mail_content" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	INT	n_num;
	tag_mail_content st_mail_content[1];
}; 

struct NET_DB2S_load_mail_content_end : public tag_net_message
{
	NET_DB2S_load_mail_content_end()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_mail_content_end");
		dw_size = sizeof(*this);
	}
};

//! ��ȡ�ʼ�����Ʒ
struct NET_DB2C_load_mail_item : public tag_net_message
{ 
	NET_DB2C_load_mail_item ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_mail_item" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_mail_serial;  
};  

struct NET_DB2S_load_mail_item : public tag_net_message
{   
	NET_DB2S_load_mail_item ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_mail_item" ) ; 
		dw_size = sizeof ( * this ) ;    
	} 
	INT n_count;  
	BYTE by_data_[1];  
};  

struct NET_DB2S_load_mail_item_end : public tag_net_message
{
	NET_DB2S_load_mail_item_end()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_mail_item_end");
		dw_size = sizeof(*this);
	}
};

//! �����ʼ�
struct NET_DB2C_update_mail : public tag_net_message 
{  
	NET_DB2C_update_mail ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_update_mail" ) ; 
		dw_size = sizeof ( * this ) ;  
	}   
	tagMailBase s_mail_base;   
};  

//! ɾ���ʼ�
struct NET_DB2C_delete_mail : public tag_net_message 
{   
	NET_DB2C_delete_mail ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_delete_mail" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_mail_id;     
};  

//! ������ҽ�Ǯ
struct NET_DB2C_change_role_money : public tag_net_message 
{  
	NET_DB2C_change_role_money ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_role_money" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id_;  
	INT n_gold_;  // ������
	INT n_silver_;   // ������
};  


//! ������ҷ����ʼ�����
struct NET_DB2C_update_role_send_num : public tag_net_message
{  
	NET_DB2C_update_role_send_num ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_update_role_send_num" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id;  
};  

#pragma pack(pop)