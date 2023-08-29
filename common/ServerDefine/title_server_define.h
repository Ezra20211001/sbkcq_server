
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//�������óƺ���ؽṹ


#pragma once

#include "role_data_server_define.h"

#pragma pack(push, 1)


const INT TITLE_UPDATA_TIME		=	60 * 60 * TICK_PER_SECOND; //�ƺŸ��¼��

// �ƺŴ洢����
struct s_title_save
{
	UINT16			n_title_id_;		// �ƺ�ID
	DWORD			dw_state_mark_;		// ��Ϊ0�����ʾ�ѻ�ȡ�������ʾpara2
	tagDWORDTime	dw_time;			// �ƺŻ��ʱ��
};


// ��ɫ�ƺ�����(����֪ͨ���ݿ�)
struct NET_DB2C_title_insert : public tag_net_message 
{  
	NET_DB2C_title_insert ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_title_insert" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id;  	// ��ɫID
	s_title_save s_title_save_;	// �ƺ���Ϣ
};  


// ��ɫ�ƺ�����(����֪ͨ���ݿ�)
struct NET_DB2C_title_delete : public tag_net_message 
{  
	NET_DB2C_title_delete ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_title_delete" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id;  	// ��ɫID
	DWORD dw_title_id;	// �ƺ�id
}; 


#pragma pack(pop)