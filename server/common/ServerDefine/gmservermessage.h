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
 *	@brief		Login、GameServer 与GM服务器协议
*/

#ifndef __GM_SERVER_PLAYER_MESSAGE_H__
#define __GM_SERVER_PLAYER_MESSAGE_H__

#include "../ServerDefine/login_server_define.h"
#include "../../../common/WorldDefine/GMDefine.h"

#pragma pack(push,1)

//! 服务器->GM服务器 服务器登陆
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

//! GM服务器->服务器 服务器登陆
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

//! 服务器->GM服务器 服务器状态
struct NET_S2GMS_ServerInfo : public tag_net_message 
{ 
	NET_S2GMS_ServerInfo ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_S2GMS_ServerInfo") ;   
		dw_size = sizeof(*this) ; 
	} 
	E_world_status e_status;   
	INT n_online_num;			//游戏世界在线人数 4
	INT n_max_online_num;    	//游戏世界最大在线人数 4
	E_world_status e_db_status; 
	BOOL is_database_ok;
}; 

//! 封IP 发自GMServer 发往LoginServer
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

//! 封IP 发自LoginServer 发往GMServer 
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


//! 封号 发自GMServer 发往LoginServer
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
	BOOL b_forbid;    //0:解封 1:封
	DWORD dwTimeStart;
	DWORD dwTimeEnd;
};  

//! 封号 发自LoginServer 发往GMServer 
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
	BOOL b_forbid;    //0:解封 1:封
	DWORD dw_world_crc;
};  

//! 封号 发自GMServer 发往GameServer
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
	BOOL b_forbid;    //0:解封 1:封
};  

//! 封号 发自GameServer 发往GMServer 
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

//! 公告 发自GMServer 发往GameServer
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

//! 踢人 发自GMServer 发往GameServer
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
//! 得到物品 从GMServer发往GameServer
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

//! 关闭服务器 发自GMServer 发往 GameServer
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

//! 倍率设定 发往 GameServer
struct NET_GMS2S_SetDoublePolicy : public tag_net_message
{
	NET_GMS2S_SetDoublePolicy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2S_SetDoublePolicy");
		dw_size = sizeof(*this);
	}
	EGMDoubleType eType; 
	DWORD dwValue;		// eg. 100表示1倍,200表示2倍 ....
	DWORD dwStartTime; // tagDWORDTime
	DWORD dwPersistSeconds;
};

//! 封号 发自GMServer 发往LoginServer
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

//! GM制造装备
struct NET_GMS2S_GMCreateEquip : public tag_net_message
{
	NET_GMS2S_GMCreateEquip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2S_GMCreateEquip");
		dw_size = sizeof(*this);
	}
	DWORD dwClientID;	// GM的ID
	DWORD dwRoleID;		// 装备的所有者
	tag_equip_create stEquipCreate; // 装备数据
};
struct NET_S2GMS_GMCreateEquip : public tag_net_message
{
	NET_S2GMS_GMCreateEquip()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2GMS_GMCreateEquip");
		dw_size = sizeof(*this);
	}
	INT64 n64Serial; // 装备世界唯一标示
	DWORD dwRoleID;	// 装备的所有者
	DWORD dwClientID;	// GM的ID
	DWORD dwError;
};

//! GM制造物品
struct NET_GMS2S_GMCreateItem : public tag_net_message
{
	NET_GMS2S_GMCreateItem()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2S_GMCreateItem");
		dw_size = sizeof(*this);
	}
	DWORD dwClientID;	// GM的ID
	DWORD dwRoleID;		// 物品的所有者
	tag_item_create stItemCreate; //物品数据
};
struct NET_S2GMS_GMCreateItem : public tag_net_message
{
	NET_S2GMS_GMCreateItem()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_S2GMS_GMCreateItem");
		dw_size = sizeof(*this);
	}
	INT64 n64Serial; // 装备世界唯一标示
	DWORD dwTypeID;//该道具的TypeID gx add 2013.11.06
	DWORD dwRoleID;	// 物品的所有者
	DWORD dwClientID;	// GM的ID
	DWORD dwError;
};
//! 转发聊天消息
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
	BYTE	byChannel;		//！频道
	TCHAR szRoleName[X_SHORT_NAME];
	TCHAR	szMsg[1];		//！对话内容  
};

//! 发钱或者元宝
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

//!关闭验证码
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
