
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//vip���ɷ���������

#pragma once
#pragma pack(push,1)

//! �������ip����Ŀ
const INT MAX_VNB_IP_NUM	= 5;

//! ���ݿ�洢�˺Žṹ
struct s_db_vnb_players
{
	INT		n_his_players;
	INT		n_todays_players;
	DWORD	dw_account_ids[1];
};

//! vip������Ʒԭ��
struct s_vnb_gift_proto
{
	DWORD	dw_id;
	DWORD	dw_item_type_id;
	INT		n_num;
};

//! vip����װ��ԭ��
struct s_vnb_equip_proto
{
	DWORD	dw_id;
	DWORD	dw_equip_type_id;
	INT		n_quality;
};

//! vip���ɽṹ
struct s_vnb
{
	DWORD	dw_id;
	TCHAR	sz_name[X_SHORT_NAME];
	INT		n_player_num;

	VOID	on_player_login(){++n_player_num;}
	VOID	on_player_logout(){--n_player_num;}

};


//! ��ȡ�˺���ʷ����
struct NET_DB2C_get_vnb_data : public tag_net_message 
{  
	NET_DB2C_get_vnb_data ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_get_vnb_data" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_date;  
};  

struct NET_DB2S_get_vnb_data : public tag_net_message 
{  
	NET_DB2S_get_vnb_data ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_get_vnb_data" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	s_db_vnb_players players;   
};  

//! ����vip�������
struct NET_DB2C_update_vnb_player : public tag_net_message 
{  
	NET_DB2C_update_vnb_player ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_update_vnb_player" ) ;
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_account_id;
	DWORD dw_login_time;  
};  



#pragma pack(pop)