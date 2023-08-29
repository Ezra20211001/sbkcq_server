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
*	@file		mail_protocol.h
*	@author		lc
*	@date		2011/03/08	initial
*	@version	0.0.1.0
*	@brief		邮件消息
*/

#ifndef MAIL_PROTOCOL
#define MAIL_PROTOCOL

#include "mail_define.h"
#include "protocol_common_errorcode.h"
#pragma pack(push,1)

//发送邮件
struct NET_SIC_send_mail : public tag_net_message
{
	NET_SIC_send_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_send_mail");
		dw_size = sizeof(NET_SIC_send_mail);
	}
	DWORD dwNPCID;
	TCHAR		szName[Max_Mail_Name+1];
	DWORD dwRecvCrc;			// 收件人NameCrc
	tagMailBase		stMail;
	DWORD		dw_safe_code;
	TCHAR		szContent[1];
};

struct NET_SIS_send_mail : public tag_net_message
{
	NET_SIS_send_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_send_mail");
		dw_size = sizeof(NET_SIS_send_mail);
	}
	DWORD dwError;
};


// 通知有有新邮件
struct NET_SIS_inform_new_mail : public tag_net_message
{
	NET_SIS_inform_new_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_inform_new_mail");
		dw_size = sizeof(NET_SIS_inform_new_mail);
	}
	DWORD dwMailID;
};


// 通知有未读邮件
struct NET_SIS_inform_noread_mail : public tag_net_message
{
	NET_SIS_inform_noread_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_inform_noread_mail");
		dw_size = sizeof(NET_SIS_inform_noread_mail);
	}
};

// 通知退件
struct NET_SIS_inform_return_mail : public tag_net_message
{
	NET_SIS_inform_return_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_inform_return_mail");
		dw_size = sizeof(NET_SIS_inform_return_mail);
	}
	DWORD dwMailID;
};


// 通知删除邮件
struct NET_SIS_inform_delete_mail : public tag_net_message
{
	NET_SIS_inform_delete_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_inform_delete_mail");
		dw_size = sizeof(NET_SIS_inform_delete_mail);
	}
	DWORD dwMailID;
};


//获取一封邮件简易数据
struct NET_SIC_get_one_mail : public tag_net_message
{
	NET_SIC_get_one_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_one_mail");
		dw_size = sizeof(NET_SIC_get_one_mail);
	}
	DWORD	dwMailID;
};

struct NET_SIS_get_one_mail : public tag_net_message
{
	NET_SIS_get_one_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_one_mail");
		dw_size = sizeof(NET_SIS_get_one_mail);
	}
	tagMailInfo stMailInfo;
};


// 获取邮件列表
struct NET_SIC_get_own_mail : public tag_net_message
{
	NET_SIC_get_own_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_own_mail");
		dw_size = sizeof(NET_SIC_get_own_mail);
	}
};

struct NET_SIS_get_own_mail : public tag_net_message
{
	NET_SIS_get_own_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_own_mail");
		dw_size = sizeof(NET_SIS_get_own_mail);
	}
	INT	n_num;			// 小于50封直接读取，大于50封则只读取50封剩下的为未能获取邮件
	tagMailInfo stMailInfo[1];
};

// 获取邮件内容
struct NET_SIC_get_mail_content : public tag_net_message
{
	NET_SIC_get_mail_content()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_mail_content");
		dw_size = sizeof(NET_SIC_get_mail_content);
	}
	DWORD dwMailID;
};

struct NET_SIS_get_mail_content : public tag_net_message
{
	NET_SIS_get_mail_content()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_mail_content");
		dw_size = sizeof(NET_SIS_get_mail_content);
	}
	DWORD dwMailID;
	TCHAR szContent[1];
};


// 获取邮件物品
struct NET_SIC_get_mail_item : public tag_net_message
{
	NET_SIC_get_mail_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_mail_item");
		dw_size = sizeof(NET_SIC_get_mail_item);
	}
	DWORD dwMailID;
};

struct NET_SIS_get_mail_item : public tag_net_message
{
	NET_SIS_get_mail_item()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_mail_item");
		dw_size = sizeof(NET_SIS_get_mail_item);
	}
	DWORD dwMailID;
	DWORD dwGiveMoney;					// 邮寄的钱数
	INT32 n32ItemNum;
	BYTE  byData[1];
};

// 读取邮件
struct NET_SIC_read_mail : public tag_net_message
{
	NET_SIC_read_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_read_mail");
		dw_size = sizeof(NET_SIC_read_mail);
	}
	DWORD dwMailID;
};

struct NET_SIS_read_mail : public tag_net_message
{
	NET_SIS_read_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_read_mail");
		dw_size = sizeof(NET_SIS_read_mail);
	}
	DWORD dwMailID;
	DWORD dwError;
};


// 收取邮件附件
struct NET_SIC_accept_accessory_mail : public tag_net_message
{
	NET_SIC_accept_accessory_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_accept_accessory_mail");
		dw_size = sizeof(NET_SIC_accept_accessory_mail);
	}
	DWORD dwMailID;
	DWORD dw_safe_code; //超级密码
};

struct NET_SIS_accept_mail : public tag_net_message
{
	NET_SIS_accept_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_accept_mail");
		dw_size = sizeof(NET_SIS_accept_mail);
	}
	DWORD dwMailID;
	DWORD dwError;
};


// 删除邮件
struct NET_SIC_delete_mail : public tag_net_message
{
	NET_SIC_delete_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_delete_mail");
		dw_size = sizeof(NET_SIC_delete_mail);
	}
	DWORD dwMailID;
};

struct NET_SIS_delete_mail : public tag_net_message
{
	NET_SIS_delete_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_delete_mail");
		dw_size = sizeof(NET_SIS_delete_mail);
	}
	DWORD dwError;
};

// 退回邮件
struct NET_SIC_return_mail : public tag_net_message
{
	NET_SIC_return_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_return_mail");
		dw_size = sizeof(NET_SIC_return_mail);
	}
	DWORD dwMailID;
};

struct NET_SIS_return_mail : public tag_net_message
{
	NET_SIS_return_mail()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_return_mail");
		dw_size = sizeof(NET_SIS_return_mail);
	}
	DWORD dwError;
};


// 获取邮件数量
struct NET_SIC_get_mail_num : public tag_net_message
{
	NET_SIC_get_mail_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_mail_num");
		dw_size = sizeof(NET_SIC_get_mail_num);
	}
	DWORD dw_role_id;
};

struct NET_SIS_get_mail_num : public tag_net_message
{
	NET_SIS_get_mail_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_mail_num");
		dw_size = sizeof(NET_SIS_get_mail_num);
	}
	DWORD dwMainNum;	// 邮件数量
	BOOL  bRead;		// 是否有未读邮件
};

#pragma pack(pop)
#endif