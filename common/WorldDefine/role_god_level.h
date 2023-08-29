#pragma once

#include "RoleDefine.h"

#pragma pack(push, 1)

// ������
enum 
{
	E_GOD_LEVEL_UP_IS_ZERO	=	1,	// 0����������
	E_GOD_LEVEL_NOT_PROTO	=	2,	// �õȼ������ڻ�ﵽ�����
	E_GOD_LEVEL_UP_NOT_CON	=	3,	// ������������
};


// ��������
enum E_GOD_LEVEL_CONDITION
{
	EGLC_ROLE_LEVEL			= 0,		// ��ɫ�ȼ�
	EGLC_WEAPON_LEVEL		= 1,		// �����ȼ�
	EGLC_HUIZHANG_LEVEL		= 2,		// ���µȼ�
	EGLC_YAPPEI_LEVEL		= 3,		// ����ȼ�
	EGLC_PET_LEVEL			= 4,		// ����ȼ�
	EGLC_HUENLIAN_TIME		= 5,		// ��������
	EGLC_HUENJIN_LEVEL		= 6,		// �꾫�ȼ�

	EGLC_NUM			
};

// ����������
struct tagGodLevelProto
{
	INT		nID;	
	INT		nCondition[EGLC_NUM];	//����
	DWORD	dwSkill[5][2];				//ѧϰ�ļ���
};


//////////////////////////////////////////////////////////////////////////////////////////////
//������
struct NET_SIC_god_level_up : public tag_net_message
{
	NET_SIC_god_level_up()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_god_level_up");
		dw_size = sizeof(NET_SIC_god_level_up);
	}
};

struct NET_SIS_god_level_up : public tag_net_message
{
	NET_SIS_god_level_up()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_god_level_up");
		dw_size = sizeof(NET_SIS_god_level_up);
	}
	INT		nLevel;
	DWORD dw_error_code;
};

struct NET_SIS_god_level_update : public tag_net_message
{
	NET_SIS_god_level_update()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_god_level_update");
		dw_size = sizeof(NET_SIS_god_level_update);
	}
	INT		nLevel;
};


#pragma pack(pop)