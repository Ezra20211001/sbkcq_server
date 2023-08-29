
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//GM�������GM����֮�����Ϣ����

#pragma once

#include "../../common/WorldDefine/base_define.h"
#include "gm_tool_define.h"
#include "rt_define.h"

#pragma pack(push, 1)

//!GM����
struct NET_GM2C_gm_create : public tag_net_message 
{  
	NET_GM2C_gm_create ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_gm_create" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	TCHAR sz_name[X_SHORT_NAME];	//�ʺ�
	DWORD dw_password_crc;			//����CRC
	EPrivilege e_privilege;			//Ȩ��
};  

struct NET_GM2S_gm_create : public tag_net_message
{   
	NET_GM2S_gm_create ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_gm_create" ) ;
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_error_code;    
};  

//!GM�޸�
struct NET_GM2C_gm_modify : public tag_net_message 
{   
	NET_GM2C_gm_modify ( ) 
	{
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GM2C_gm_modify" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	TCHAR sz_name[X_SHORT_NAME];  //�ʺ�
	EPrivilege e_privilege;  //Ȩ��
};  


struct NET_GM2S_gm_modify : public tag_net_message 
{  
	NET_GM2S_gm_modify ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GM2S_gm_modify" ) ;   
		dw_size = sizeof ( * this ) ; 
	}
	DWORD dw_error_code;   
};  

//!GMɾ��
struct NET_GM2C_gm_delete : public tag_net_message 
{  
	NET_GM2C_gm_delete ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_gm_delete" ) ;   
		dw_size = sizeof ( * this ) ; 
	}   
	TCHAR sz_name[X_SHORT_NAME];   	//�ʺ�
};  

struct NET_GM2S_gm_delete : public tag_net_message 
{  
	NET_GM2S_gm_delete ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_gm_delete" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;   
};  

//! ��ɫ�ָ�
struct NET_GM2C_role_resume : public tag_net_message 
{  
	NET_GM2C_role_resume ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GM2C_role_resume" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	INT n_old_id;  //��ɫԭ����ID
	TCHAR sz_new_name[X_SHORT_NAME];//��ɫ���������
	DWORD dw_section_id;  //����ID
	DWORD dw_world_id;     //��Ϸ����ID
};  


struct NET_GM2S_role_resume : public tag_net_message 
{  
	NET_GM2S_role_resume ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_role_resume" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_error_code;   
};  

//! ��ɫ�����޸�
struct NET_GM2C_promodify : public tag_net_message 
{  
	NET_GM2C_promodify ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_GM2C_promodify" ) ;
		dw_size = sizeof ( * this ) ;     
	}  
	TCHAR sz_name[X_SHORT_NAME];  //��ɫ����
	INT n_level;  //�ȼ�
	INT n_skill;  //���ʵ�
	INT n_yuanbao; //Ԫ��
	INT64 n64_exp; //����
	INT64 n64_money;  //Ǯ	
	DWORD dw_section_id;   //����ID
	DWORD dw_world_id;   //��Ϸ����ID
};  


struct NET_GM2S_promodify : public tag_net_message
{ 
	NET_GM2S_promodify ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_promodify" ) ; 
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_error_code; 
};  


//!��Ʒ����
struct NET_GM2C_item_create : public tag_net_message 
{  
	NET_GM2C_item_create ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GM2C_item_create" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	TCHAR sz_name[X_SHORT_NAME];  //��ɫ
	DWORD dw_item_type_id;   //��ƷTypeID
	INT n_item_num;  //����
	BYTE by_quality;   //Ʒ��
	DWORD dw_section_id;  //����ID
	DWORD dw_world_id;   //��Ϸ����ID
};  

struct NET_GM2S_item_create : public tag_net_message 
{ 
	NET_GM2S_item_create ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_item_create" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_error_code; 
};  

//!��Ʒɾ��
struct NET_GM2C_item_delete : public tag_net_message
{  
	NET_GM2C_item_delete ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GM2C_item_delete" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	TCHAR sz_name[X_SHORT_NAME];  //��ɫ
	INT64 n64_item_id;  //��Ʒȫ��ID
	DWORD dw_section_id;  //����ID
	DWORD dw_world_id;   //��Ϸ����ID
};  


struct NET_GM2S_item_delete : public tag_net_message 
{  
	NET_GM2S_item_delete ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_item_delete" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code; 
};  

//!��Ʒ�ָ�
struct NET_GM2C_item_resume : public tag_net_message
{  
	NET_GM2C_item_resume ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_GM2C_item_resume" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	INT64 n64_serial_num;  //��Ʒȫ��ID
	TCHAR sz_target_role[X_SHORT_NAME];  //Ŀ���ɫ��
	DWORD dw_section_id;  //����ID
	DWORD dw_world_id;    //��Ϸ����ID
};  


struct NET_GM2S_item_resume : public tag_net_message
{  
	NET_GM2S_item_resume ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_item_resume" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;  
};  

//! �˺ŷ�ͣ
struct NET_GM2C_account_forbid : public tag_net_message 
{  
	NET_GM2C_account_forbid ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_account_forbid" ) ;  
		dw_size = sizeof ( * this ) ; 
	} 
	TCHAR sz_account_str[LONG_STRING]; //�˺Ŵ�,���˺�֮�䶺�ŷָ�
	TCHAR sz_section_name[X_SHORT_NAME];  //����
	TCHAR sz_world_name[X_SHORT_NAME]; //��Ϸ����
	INT n_action;  // 0:��� 1����
};  


struct NET_GM2S_account_forbid : public tag_net_message 
{  
	NET_GM2S_account_forbid ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_account_forbid" ) ;
		dw_size = sizeof ( * this ) ;  
	}  
	TCHAR sz_account[X_SHORT_NAME]; 
	DWORD dw_error_code; 
};  

//!--˫��
struct NET_GM2C_double : public tag_net_message 
{  
	NET_GM2C_double ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_double" ) ; 
		dw_size = sizeof ( * this ) ;    
	}   
	E_double_type e_d_type; //����ʱ��
	DWORD dw_open_time;   //����ʱ��
	DWORD dw_last_time;  //����
	DWORD dw_ration;  //����ID,
	DWORD dw_section_id; 
	DWORD dw_world_id[1];  //����	��Ϸ����ID[n]     ����ô�����������Ϸ
};  

//!--���½ǹ���
struct NET_GM2C_right_notice : public tag_net_message 
{  
	NET_GM2C_right_notice ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_right_notice" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_notice_time;//����ʱ�� tagDWORDTime 0Ϊ��ʱ
	TCHAR sz_tiele[Notice_Title];  //����
	TCHAR sz_content[Notice_Content];  //����
	TCHAR sz_link[Notice_Link];  //���ӵ���վ
	DWORD dw_section_id;  //����ID,
	DWORD dw_world_id[1];    //��Ϸ����ID[n]      ��Ϸ����ID:INVALID_VALUE����ô�����������Ϸ����											
};  


//! --�Զ�ѭ������
struct NET_GM2C_auto_notice : public tag_net_message
{   
	NET_GM2C_auto_notice ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_auto_notice" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	TCHAR sz_content[Notice_Content];	//����
	E_color_type e_type;				//��ɫ
	INT n_time_interval;				//ʱ����
	INT n_cir_interval;					//ѭ�����
	INT n_cir_num;						//ѭ������
	DWORD dw_section_id;				//����ID,
	DWORD dw_world_id[1];				//��Ϸ����ID[n]      ��Ϸ����ID:INVALID_VALUE����ô�����������Ϸ����	
};  


//!--��ʱ���йصķ�����Ϣ
struct NET_GM2S_time_limited_msg : public tag_net_message
{  
	NET_GM2S_time_limited_msg ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_time_limited_msg" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	E_time_limited_msg e_type;  
	DWORD dw_error_code;// 0-�ɹ�
	DWORD dw_world_id;    
};  


//! ���/ɾ��������IP
struct NET_GM2C_black_list : public tag_net_message
{   
	NET_GM2C_black_list ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_GM2C_black_list" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
	TCHAR sz_section_name[X_SHORT_NAME]; // ����
	DWORD dw_ip;  // IP
	INT n_action;    // 0:��� 1����
};  

struct NET_GM2S_black_list : public tag_net_message
{   
	NET_GM2S_black_list ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_GM2S_black_list" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_error_code;    
};  

//! ����Ƶ���Զ�����
struct NET_GM2C_auto_chat_notice : public tag_net_message 
{   
	NET_GM2C_auto_chat_notice ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_auto_chat_notice" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	TCHAR sz_notice[HUGE_STRING];// ��������
	BYTE by_hour;  // ����: ʱ
	BYTE by_minute;  // ����: ��
	DWORD dw_section_id;// ����ID
	DWORD dw_world_id[1];    // ��Ϸ����ID[n]      ��Ϸ����ID:INVALID_VALUE����ô�����������Ϸ����	// ����ʱ��
};  


struct NET_GM2S_aoto_chat_notice : public tag_net_message 
{   
	NET_GM2S_aoto_chat_notice ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_aoto_chat_notice" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_error_code;    
};  

//! ȡ���������趨����Ƶ����Ϣ
struct NET_GM2C_cancel_auto_chat_notice : public tag_net_message 
{  
	NET_GM2C_cancel_auto_chat_notice ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_cancel_auto_chat_notice" ) ; 
		dw_size = sizeof ( * this ) ; 
	}   
};  

struct NET_GM2S_cancel_auto_chat_notice : public tag_net_message
{  
	NET_GM2S_cancel_auto_chat_notice ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_cancel_auto_chat_notice" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;  
};  

//! ȡ�����м�ʱ��Ϣ
struct NET_GM2C_cancel_time_limited_msg : public tag_net_message 
{  
	NET_GM2C_cancel_time_limited_msg ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_cancel_time_limited_msg" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
};  

struct NET_GM2S_cancel_time_limited_msg : public tag_net_message 
{ 
	NET_GM2S_cancel_time_limited_msg ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_cancel_time_limited_msg" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;   
};  

//! ȡ������˫������
struct NET_GM2C_cancel_double_msg : public tag_net_message
{   
	NET_GM2C_cancel_double_msg ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2C_cancel_double_msg" ) ;
		dw_size = sizeof ( * this ) ;   
	}
};  

struct NET_GM2S_cancel_double_msg : public tag_net_message
{  
	NET_GM2S_cancel_double_msg ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_cancel_double_msg" ) ;  
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_error_code;    
};  

//! ȡ���������趨���½�
struct NET_GM2C_cancel_right_notice : public tag_net_message
{  
	NET_GM2C_cancel_right_notice ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_GM2C_cancel_right_notice" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
};  

struct NET_GM2S_cancel_right_notice : public tag_net_message 
{ 
	NET_GM2S_cancel_right_notice ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_GM2S_cancel_right_notice" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_error_code;    
};  

#pragma pack(pop)
