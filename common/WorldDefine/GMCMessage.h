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
 *	@file		GMProtocl
 *	@author		mwh
 *	@date		2011/04/08	initial
 *	@version	0.0.1.0
 *	@brief		GM�ͻ���Э��
*/

#ifndef __GM_GM_PLAYER_MESSAGE_H__
#define __GM_GM_PLAYER_MESSAGE_H__

#pragma pack(push,1)

#include "GMDefine.h"

//=================================================
//	Protocol
//=================================================
//! GM�ͻ���->GM������
struct NET_C2GMS_GMLogin : public tag_net_message 
{ 
	NET_C2GMS_GMLogin ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_GMLogin") ;   
		dw_size = sizeof(*this) ; 
	} 
	EToolType eToolType;
	TCHAR szAccount[X_SHORT_NAME];
	TCHAR szPsd[MAX_MD5_ARRAY];
}; 

//! GM�ͻ���->GM������
struct NET_GMS2C_GMLogin : public tag_net_message 
{ 
	NET_GMS2C_GMLogin ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_GMLogin") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwPrivilege;
	DWORD dwErrorCode;
}; 

//! ������ͣ���ˣ��չ˹����� gx add 2013.11.07
struct NET_C2GMS_FuckWorkRoom : public tag_net_message 
{ 
	NET_C2GMS_FuckWorkRoom ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_FuckWorkRoom") ;   
		dw_size = sizeof(*this) ; 
	}
	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szTrustIP[X_SHORT_NAME];//����IP����һ��
	INT	  nTrustConsider;//�Ƿ�������IP
	INT   nIPNum;//IP����ȫ����
	INT   nForbid;//�Ƿ��ͣ
	INT	  nKick;//�Ƿ�����
};
struct NET_GMS2C_FuckWorkRoom : public tag_net_message 
{ 
	NET_GMS2C_FuckWorkRoom ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_FuckWorkRoom") ;   
		dw_size = sizeof(*this) ; 
	}
	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szIPName[X_SHORT_NAME];//��ͣ��IP��
	INT	  nIPNums;//��IP������
};
//���ݿ���IP�ֶ���ͣ�����ߵ���IP
struct NET_C2GMS_HandleIP_OBO: public tag_net_message
{
	NET_C2GMS_HandleIP_OBO ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_HandleIP_OBO") ;   
		dw_size = sizeof(*this) ; 
	}
	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szInvalidIP[X_SHORT_NAME];//����IP����һ��
	INT   nForbid;//�Ƿ��ͣ
	INT	  nKick;//�Ƿ�����
};
struct NET_GMS2C_HandleIP_OBO:public tag_net_message
{
	NET_GMS2C_HandleIP_OBO ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_HandleIP_OBO") ;   
		dw_size = sizeof(*this) ; 
	}
	DWORD dw_result;
};
//end

//! GM�ͻ���->GM������
struct NET_C2GMS_ForbidAccount : public tag_net_message 
{ 
	NET_C2GMS_ForbidAccount ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_ForbidAccount") ;   
		dw_size = sizeof(*this) ; 
	} 
	BOOL bForbid;
	TCHAR szAccount[X_SHORT_NAME];
	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szReason[LONG_STRING];
	DWORD dwSeconds;
}; 
struct NET_C2GMS_ForbidAccountByAccountID: public tag_net_message 
{ 
	NET_C2GMS_ForbidAccountByAccountID ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_ForbidAccountByAccountID") ;   
		dw_size = sizeof(*this) ; 
	} 
	BOOL bForbid;
	DWORD dwAccountID;
	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szReason[LONG_STRING];
	DWORD dwSeconds;
}; 

//! GM�ͻ���->GM������
struct NET_GMS2C_ForbidAccount : public tag_net_message 
{ 
	NET_GMS2C_ForbidAccount ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_ForbidAccount") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwErrorCode;
}; 

//! GM�ͻ���->GM������
struct NET_C2GMS_ForbidTalk : public tag_net_message 
{ 
	NET_C2GMS_ForbidTalk ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_ForbidTalk") ;   
		dw_size = sizeof(*this) ; 
	} 
	BOOL bForbid;
	DWORD dwSecond;
	TCHAR szReason[LONG_STRING];
	TCHAR szRoleName[X_SHORT_NAME];
	TCHAR szServerName[X_SHORT_NAME];
}; 

//! GM�ͻ���->GM������
struct NET_GMS2C_ForbidTalk : public tag_net_message 
{ 
	NET_GMS2C_ForbidTalk ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_GMS2C_ForbidTalk") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwErrorCode;
}; 

//! GM�ͻ���->GM������
struct NET_C2GMS_Affiche : public tag_net_message 
{ 
	NET_C2GMS_Affiche ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_Affiche") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwSecond;
	TCHAR szAfficheMsg[GMAFFICHELEN];
	TCHAR szServerName[X_SHORT_NAME];
}; 

//GM�ͻ���->GM������ ����
struct NET_C2GMS_Kick : public tag_net_message
{
	NET_C2GMS_Kick()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2GMS_Kick");
		dw_size = sizeof(*this);
	}
	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szRoleName[X_SHORT_NAME];
};

//GM �ͻ���->GM������ �رշ�����
struct NET_C2GMS_ShutDown : public tag_net_message
{
	NET_C2GMS_ShutDown()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2GMS_ShutDown");
		dw_size = sizeof(*this);
	}
	TCHAR szServerName[X_SHORT_NAME];
	INT		nTime;
};


//! GM�ͻ���->GM������
struct NET_C2GMS_Add_item : public tag_net_message 
{ 
	NET_C2GMS_Add_item ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_Add_item") ;   
		dw_size = sizeof(*this) ; 
	} 

	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szRoleName[LONG_STRING]; 
	DWORD dw_item_data_id;
	INT16 n16Num;
	INT32 nQlty;
	BOOL bBind;
};

//! GM�ͻ���->GM������
struct NET_C2GMS_QueryGameServerList : public tag_net_message
{
	NET_C2GMS_QueryGameServerList()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2GMS_QueryGameServerList");
		dw_size = sizeof(*this);
	}
};
struct NET_GMS2C_QueryGameServerList : public tag_net_message
{
	NET_GMS2C_QueryGameServerList()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2C_QueryGameServerList");
		dw_size = sizeof(*this);
	}
	INT nNumber;
	tag_gamaserver_info info[64];
};

//! GM�ͻ���->GM������
struct NET_C2GMS_QueryLoginStatus : public tag_net_message
{
	NET_C2GMS_QueryLoginStatus()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2GMS_QueryLoginStatus");
		dw_size = sizeof(*this);
	}
};

struct NET_GMS2C_QueryLoginStatus : public tag_net_message
{
	NET_GMS2C_QueryLoginStatus()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2C_QueryLoginStatus");
		dw_size = sizeof(*this);
	}
	DWORD dwIP;
	BOOL bOK;
	INT nOnlinNumber;
	TCHAR szServerName[X_SHORT_NAME];
};


//! GM�ͻ���->GM������
struct NET_C2GMS_SetServerMaxPlayerNumber : public tag_net_message
{
	NET_C2GMS_SetServerMaxPlayerNumber()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2GMS_SetServerMaxPlayerNumber");
		dw_size = sizeof(*this);
	}
	INT nMaxPlayerNumber;
	TCHAR szServerName[X_SHORT_NAME];
};
//! GM�ͻ���->GM������
struct NET_C2GMS_SetDoublePolicy : public tag_net_message
{
	NET_C2GMS_SetDoublePolicy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2GMS_SetDoublePolicy");
		dw_size = sizeof(*this);
	}
	EGMDoubleType eType; 
	DWORD dwValue;		// eg. 100��ʾ1��,200��ʾ2�� ....
	DWORD dwStartTime;
	DWORD dwPersistSeconds;
	TCHAR szServerName[X_SHORT_NAME];
};

//! GM�ͻ���->GM���������ڹ㲥
struct NET_C2GMS_Affiche_Periodicity : public tag_net_message 
{ 
	NET_C2GMS_Affiche_Periodicity ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_Affiche_Periodicity") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwSecond;
	DWORD dwIndex;
	TCHAR szAfficheMsg[GMAFFICHELEN];
	TCHAR szServerName[X_SHORT_NAME];
}; 

//�� GM�ͻ���->GM��������ȡ���ڹ㲥
struct NET_C2GMS_Cancel_Affiche_Periodicity : public tag_net_message 
{ 
	NET_C2GMS_Cancel_Affiche_Periodicity ( )
	{   
		ZeroMemory (this, sizeof(*this)) ;  
		dw_message_id = message_id_crc ("NET_C2GMS_Cancel_Affiche_Periodicity") ;   
		dw_size = sizeof(*this) ; 
	} 
	DWORD dwIndex;
	TCHAR szServerName[X_SHORT_NAME];
}; 

//! ������Ϣ
struct NET_GMS2C_ChatTransmit : public tag_net_message
{
	NET_GMS2C_ChatTransmit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2C_ChatTransmit");
		dw_size = sizeof(*this);
	}
	DWORD dwRoleID;
	DWORD dwAccountID;
	BYTE	byChannel;		//��Ƶ��
	TCHAR szServerName[X_SHORT_NAME];
	TCHAR szRoleName[X_SHORT_NAME];
	TCHAR	szMsg[1024];		//���Ի�����  
};

//!�ر���֤��
struct NET_C2GMS_validate : public tag_net_message
{
	NET_C2GMS_validate()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2GMS_validate");
		dw_size = sizeof(*this);
	}
	BOOL bOpen;
	TCHAR szServerName[X_SHORT_NAME];
};
struct NET_GMS2C_validate : public tag_net_message
{
	NET_GMS2C_validate()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_GMS2C_validate");
		dw_size = sizeof(*this);
	}
	BOOL bOpen;
	DWORD dwError;
	TCHAR szServerName[X_SHORT_NAME];
};

#pragma pack(pop)

#endif //__GM_GM_PLAYER_MESSAGE_H__
