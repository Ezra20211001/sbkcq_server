
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//����������������

#pragma once

#pragma pack(push)
#pragma pack(1)
#include "../../../common/WorldDefine/vcard_define.h"

//! ���������Զ�����Ϣ
struct NET_DB2C_vcard_change : public tag_net_message 
{  
	NET_DB2C_vcard_change ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_vcard_change" ) ;   
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_role_id; // ��ɫID
	tagVCardData s_card_data_;  // �Զ�����Ϣ  
};  


//! ��ȡ�����������
struct NET_DB2C_get_off_line_vcard : public tag_net_message 
{  
	NET_DB2C_get_off_line_vcard ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_get_off_line_vcard" ) ;
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_role_id;  	// ����ѯ��ID
	DWORD dw_query_id;  // ��ѯ��ID
};  


struct NET_DB2S_get_off_line_vcard : public tag_net_message 
{ 
	NET_DB2S_get_off_line_vcard ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_get_off_line_vcard" ) ;   
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_role_id; // ����ѯ��ID
	DWORD dw_query_id;   // ��ѯ��ID
	DWORD dw_error_code;   
	BYTE by_data[1];    
};  


#pragma pack(pop)
