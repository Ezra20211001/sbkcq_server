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
 *	@file		gm_message
 *	@author		mwh
 *	@date		2011/04/06	initial
 *	@version	0.0.1.0
 *	@brief		Login��GameServer ��GM������Э��
*/

#ifndef __GM_SERVER_PLAYER_MESSAGE_H__
#define __GM_SERVER_PLAYER_MESSAGE_H__

#include "../ServerDefine/login_server_define.h"
#include "../../../common/WorldDefine/GMDefine.h"

#pragma pack(push,1)

//! ������->GM������ ��������½
struct NET_S2GMS_SeverLogin : public tag_net_message 
{ 
	NET_S2GMS_SeverLogin ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_S2GMS_SeverLogin") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dw_crc;
	EServerType e_type;
}; 

//! GM������->������ ��������½
struct NET_GMS2S_SeverLogin : public tag_net_message 
{ 
	NET_GMS2S_SeverLogin ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2S_SeverLogin") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwErrorCode;
}; 

//! ������->GM������ ������״̬
struct NET_S2GMS_ServerInfo : public tag_net_message 
{ 
	NET_S2GMS_ServerInfo ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_S2GMS_ServerInfo") ;   
		dw_size = sizeof(*this) ; 
	} 
	E_world_status e_status;   
	INT n_online_num;			//��Ϸ������������ 4
	INT n_max_online_num;    	//��Ϸ��������������� 4
	E_world_status e_db_status; 
	BOOL is_database_ok;
}; 

//! ��IP ����GMServer ����LoginServer
struct NET_GMS2S_forbid_ip : public tag_net_message 
{  
	NET_GMS2S_forbid_ip ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_GMS2S_forbid_ip" ) ;
		dw_size = sizeof ( * this ) ;    
	}
	DWORD dw_client_id; 
	DWORD dw_ip;  
	BOOL b_forbid;   
};  

//! ��IP ����LoginServer ����GMServer 
struct NET_S2GMS_forbid_ip : public tag_net_message 
{ 
	NET_S2GMS_forbid_ip ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_S2GMS_forbid_ip" ) ; 
		dw_size = sizeof ( * this ) ;    
	}
	DWORD dw_client_id;   
	DWORD dw_error_code;     
};  


//! ��� ����GMServer ����LoginServer
struct NET_GMS2S_forbid_account : public tag_net_message 
{   
	NET_GMS2S_forbid_account ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GMS2S_forbid_account" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_client_id;  
	TCHAR sz_account[LONG_STRING]; 
	TCHAR sz_world[X_SHORT_NAME]; 
	BOOL b_forbid;    //0:��� 1:��
	DWORD dwTimeStart;
	DWORD dwTimeEnd;
};  

//! ��� ����LoginServer ����GMServer 
struct NET_S2GMS_forbid_account : public tag_net_message
{   
	NET_S2GMS_forbid_account ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_S2GMS_forbid_account" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_client_id;  
	TCHAR sz_account[X_SHORT_NAME];  
	DWORD dw_error_code;   
	BOOL b_forbid;    //0:��� 1:��
	DWORD dw_world_crc;
};  

//! ��� ����GMServer ����GameServer
struct NET_GMS2S_forbid_Talk : public tag_net_message 
{   
	NET_GMS2S_forbid_Talk ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GMS2S_forbid_Talk" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_client_id;  
	TCHAR szRoleName[LONG_STRING]; 
	DWORD dwSecond;
	BOOL b_forbid;    //0:��� 1:��
};  

//! ��� ����GameServer ����GMServer 
struct NET_S2GMS_forbid_Talk : public tag_net_message
{   
	NET_S2GMS_forbid_Talk ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_S2GMS_forbid_Talk" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_client_id;  
	TCHAR szRoleName[X_SHORT_NAME];  
	DWORD dw_error_code;   
};  

//! ���� ����GMServer ����GameServer
struct NET_GMS2S_Affiche : public tag_net_message 
{   
	NET_GMS2S_Affiche ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GMS2S_Affiche" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dwSecond;
	TCHAR szAfficheMsg[GMAFFICHELEN];
};

//! ���� ����GMServer ����GameServer
struct NET_GMS2S_Kick : public tag_net_message
{
	NET_GMS2S_Kick()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2S_Kick");
		dw_size = sizeof(*this);
	}
	TCHAR szRoleName[X_SHORT_NAME];
};
//! �õ���Ʒ ��GMServer����GameServer
struct NET_GMS2S_Add_Item : public tag_net_message
{
	NET_GMS2S_Add_Item()
	{
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GMS2S_Add_Item" ) ; 
		dw_size = sizeof ( * this ) ;   
	}
	DWORD dw_client_id;  
	TCHAR szRoleName[LONG_STRING]; 
	DWORD dw_item_data_id;
	INT16 n16Num;
	INT32 nQlty;
	BOOL bBind;
};

//! �رշ����� ����GMServer ���� GameServer
struct NET_GMS2S_ShutDown : public tag_net_message
{
	NET_GMS2S_ShutDown()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2S_ShutDown");
		dw_size = sizeof(*this);
	}
	INT nTime;
};

//! �����趨 ���� GameServer
struct NET_GMS2S_SetDoublePolicy : public tag_net_message
{
	NET_GMS2S_SetDoublePolicy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2S_SetDoublePolicy");
		dw_size = sizeof(*this);
	}
	EGMDoubleType eType; 
	DWORD dwValue;		// eg. 100��ʾ1��,200��ʾ2�� ....
	DWORD dwStartTime; // tagDWORDTime
	DWORD dwPersistSeconds;
};

//! ��� ����GMServer ����LoginServer
struct NET_GMS2S_SetMaxPlayerNumber : public tag_net_message 
{   
	NET_GMS2S_SetMaxPlayerNumber ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_GMS2S_SetMaxPlayerNumber" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	INT nMaxPlayerNumber;
	DWORD dwWorldNameCRC;
};  

//! GM����װ��
struct NET_GMS2S_GMCreateEquip : public tag_net_message
{
	NET_GMS2S_GMCreateEquip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2S_GMCreateEquip");
		dw_size = sizeof(*this);
	}
	DWORD dwClientID;	// GM��ID
	DWORD dwRoleID;		// װ����������
	tag_equip_create stEquipCreate; // װ������
};
struct NET_S2GMS_GMCreateEquip : public tag_net_message
{
	NET_S2GMS_GMCreateEquip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2GMS_GMCreateEquip");
		dw_size = sizeof(*this);
	}
	INT64 n64Serial; // װ������Ψһ��ʾ
	DWORD dwRoleID;	// װ����������
	DWORD dwClientID;	// GM��ID
	DWORD dwError;
};

//! GM������Ʒ
struct NET_GMS2S_GMCreateItem : public tag_net_message
{
	NET_GMS2S_GMCreateItem()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2S_GMCreateItem");
		dw_size = sizeof(*this);
	}
	DWORD dwClientID;	// GM��ID
	DWORD dwRoleID;		// ��Ʒ��������
	tag_item_create stItemCreate; //��Ʒ����
};
struct NET_S2GMS_GMCreateItem : public tag_net_message
{
	NET_S2GMS_GMCreateItem()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2GMS_GMCreateItem");
		dw_size = sizeof(*this);
	}
	INT64 n64Serial; // װ������Ψһ��ʾ
	DWORD dwTypeID;//�õ��ߵ�TypeID gx add 2013.11.06
	DWORD dwRoleID;	// ��Ʒ��������
	DWORD dwClientID;	// GM��ID
	DWORD dwError;
};
//! ת��������Ϣ
struct NET_S2GMS_ChatTransmit : public tag_net_message
{
	NET_S2GMS_ChatTransmit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2GMS_ChatTransmit");
		dw_size = sizeof(*this);
	}
	DWORD dwRoleID;
	DWORD dwAccountID;
	BYTE	byChannel;		//��Ƶ��
	TCHAR szRoleName[X_SHORT_NAME];
	TCHAR	szMsg[1];		//���Ի�����  
};

//! ��Ǯ����Ԫ��
struct NET_GMS2S_GMGiveMoney : public tag_net_message
{
	NET_GMS2S_GMGiveMoney ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2S_GMGiveMoney") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	DWORD dwClientID;
	DWORD dwYuanBao;
	DWORD dwMoney;
};

struct NET_S2GMS_GMGiveMoney: public tag_net_message 
{ 
	NET_S2GMS_GMGiveMoney ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_S2GMS_GMGiveMoney") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwRoleID;
	DWORD dwError;
	DWORD dwYuanBao;
	DWORD dwMoney;
	DWORD dwClientID;
};

//!�ر���֤��
struct NET_GMS2S_validate : public tag_net_message
{
	NET_GMS2S_validate()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2S_validate");
		dw_size = sizeof(*this);
	}
	BOOL bOpen;
	DWORD dwClientID;
};
struct NET_S2GMS_validate : public tag_net_message
{
	NET_S2GMS_validate()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2GMS_validate");
		dw_size = sizeof(*this);
	}
	BOOL bOpen;
	DWORD dwClientID;
};

#pragma pack(pop)

#endif // __GM_SERVER_PLAYER_MESSAGE_H__
