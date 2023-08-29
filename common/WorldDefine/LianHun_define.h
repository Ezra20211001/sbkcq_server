#pragma once


#include "RoleDefine.h"

#pragma pack(push, 1)


// ������
const int HUENLIAN_MIN_ROLE_LEVEL = 1;

//�꾫��������
const int MAX_HUENJING_BAG_SIZE = 32;

//��ɫ�꾫������
const int MAX_ROLE_HUENJING_SIZE = 6;

//�߼��������ķǰ󶨽�
const int HIGHLEVEL_HUENLIAN_SIEVER = 100000;

//�꾫�ҽ�id
const DWORD LIANHUENG_HUIJING = 1000000;

//�õ�����Ʒ�ʻ꾫�ĸ���
const DWORD LIANGHUEN_PRO[5][6] = {
	{5000, 5000, 0,		0,		0,	0},
	{5000, 3000, 2000,	0,		0,	0},
	{5000, 2000, 2500,  500,	0,	0},
	{5000, 1000, 2500,  1000,   500, 0},
	{5000, 500,  1670,  1500,   1000, 330},
};

//�õ��������Ի꾫����
const DWORD JINGHUENATT_PRO[] = { 400, 400, 400, 400, 300, 700, 800, 800, 800, 1000, 1000, 1000, 1000, 1000};

// һ���꾫��ȡ���ֵ
const INT HUENJINGLINGHUEN[] = {10, 50, 100, 200, 400, 800};

// �ȼ�������ȼ�
const INT LEVELCAONEEDLEVEL[] = {20, 30, 40, 50, 60, 70};

// �ɳ���������
const INT GODLEVELCAONEEDLEVEL[] = {4, 5, 8, 12, 17, 23};

// �����¼���������
const INT NEXTGONGJIANGPRO[][4] = {
									{40, 40, 30, 20},
									{90, 70, 50, 30},
									};

// ÿ������������
const INT MAXHUENLIANTIME = 50;

// ������
enum
{
	E_BuyLingqi_Full					=	1,		// ����ֵ������
	E_BuyLingqi_Not_Sivler				=	2,		// Ԫ������

	E_LIANHUEN_NOT_LINGQI				=	3,		// ��������
	E_LIANHUEN_NOT_SIVLER				=	4,		// ��Ҳ���
	E_LIANHUEN_NOT_ENOUTH_BAG_TMP		=	5,		// ��ʱ��������

	E_LIANHUEN_NOT_ENOUTH_BAG			=	6,		// ��������	
	E_LIANHUEN_LEVEL_MAX				=	7,		// �꾫�ﵽ��ɫ�ȼ�����
	E_LIANHUEN_SAME_ATT					=	8,		// ����Ƕ��ͬ���Ի꾫
	E_LIANHUEN_CAN_THIS_NOT_LEVEL		=	9,		// ��λ��û����

	E_LIANHUEN_TIME_FULL				=	10		// �������������
};

//��������
enum E_ARTISAN_TYPE
{
	EAT_0,		//����
	EAT_1,		//����
	EAT_2,		//�м�
	EAT_3,		//�߼�
	EAT_4		//�ؼ�
};

//�꾧ԭ��
struct tagHunJingProto
{
	DWORD			dwID;			//id
	ERoleAttribute	eAtt;			//����
	BYTE			byQuality;		//Ʒ��
	INT				nBaseAtt;		//��������
	INT				nGrowAtt;		//�ɳ�����
};


//�꾧
struct tagHuenJing
{
	DWORD	dw_data_id;
	INT		nLevel;
};


//��ɫ�꾫����
struct tagRoleHuenJingData
{	
	// ��ʱ����
	tagHuenJing	s_huenjing_bag_temp[MAX_HUENJING_BAG_SIZE];
	// �꾫����
	tagHuenJing	s_huenjing_bag[MAX_HUENJING_BAG_SIZE];
	
	// �ȼ���
	tagHuenJing	s_huenjing_role_level[MAX_ROLE_HUENJING_SIZE];
	// �ɳ���
	tagHuenJing	s_huenjing_role_titel[MAX_ROLE_HUENJING_SIZE];

	BYTE		byCurArtisan;	//��ǰ��������

	tagRoleHuenJingData(){ memset(this, 0, sizeof(*this)); }
};



// ��������
class LianHunHelper
{
public:
	// ��ȡ�������򻨷�
	static INT32 GetBuyLingqi(INT32 time)
	{
		return 10+time/7*2;
	}

	// ��ȡ��������ֵ
	static INT getLingqi(BYTE eat)
	{
		return 400 + eat * 200;
	}

	// �ܷ�������һ������
	static BOOL canNextArtisan(BYTE byCur, INT nRoleLevel)
	{
		if (nRoleLevel >= 20 && nRoleLevel < 30)
		{
			return byCur < EAT_1;
		}
		else if (nRoleLevel >= 30 && nRoleLevel < 40)
		{
			return byCur < EAT_2;
		}
		else if (nRoleLevel >= 40 && nRoleLevel < 50)
		{
			return byCur < EAT_3;
		}
		else
		{
			return byCur < EAT_4;
		}
	}
	static int getHuenjingLevelUpExp(int nLevel, BYTE byQuality)
	{
		if (byQuality <= 1)
		{
			//Ʒ��*��(�ȼ�\10)^2*�ȼ�+�ȼ�*10��/2
			return (byQuality+1)*(pow(nLevel/10 * 1.0, 2)*nLevel + nLevel*10)/2;
		}
		else
		{
			//4^��Ʒ��-2)*��(�ȼ�\10)^2*�ȼ�+�ȼ�*10��/2
			return pow(4.0, (byQuality+1)-2) * (pow(nLevel/10 * 1.0, 2)*nLevel + nLevel*10)/2;
		}

	}

	static int getHuenJingLevelUpExpTotal(int nLevel, BYTE byQuality)
	{
		int nTotal = 0;
		for (int i = 1; i < nLevel; i++)
		{
			nTotal += getHuenjingLevelUpExp(i,byQuality);
		}

		return nTotal;
	}
	
};

class HuenJingSort
{
public:
	bool operator () (tagHuenJing s1, tagHuenJing s2) const
	{
		if ((s1.dw_data_id / 10000 % 10000) > (s2.dw_data_id / 10000 % 10000))
		{
			return true;
		}
		else
		{
			return s1.nLevel > s2.nLevel;
		}
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////

//��������
struct NET_SIC_buy_lingqi_vaule : public tag_net_message
{
	NET_SIC_buy_lingqi_vaule()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_buy_lingqi_vaule");
		dw_size = sizeof(NET_SIC_buy_lingqi_vaule);
	}
	DWORD	dw_safe_code;
};

struct NET_SIS_buy_lingqi_vaule : public tag_net_message
{
	NET_SIS_buy_lingqi_vaule()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_buy_lingqi_vaule");
		dw_size = sizeof(NET_SIS_buy_lingqi_vaule);
	}
	DWORD			dwErrCode;		// ������
};


// ��ȡ�꾧����
struct NET_SIC_get_HunJing_data : public tag_net_message
{
	NET_SIC_get_HunJing_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_HunJing_data");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_HunJing_data : public tag_net_message
{
	NET_SIS_get_HunJing_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_HunJing_data");
		dw_size = sizeof(*this);
	}

	tagRoleHuenJingData st_data;
};

// ���»꾫����
struct NET_SIS_update_HunJing_data : public tag_net_message
{
	NET_SIS_update_HunJing_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_HunJing_data");
		dw_size = sizeof(*this);
	}

	BYTE byType; //�꾫�������� 0 ��ʱ���� 1 �꾫���� 2  �ȼ���3  �ɳ���
	BYTE byIndex; //λ��
	tagHuenJing s_data; // ����
};


// ����
struct NET_SIC_LianHun : public tag_net_message
{
	NET_SIC_LianHun()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_LianHun");
		dw_size = sizeof(*this);
	}

	BYTE	byType;		// 0 ��ͨ 1�߼�
};


struct NET_SIS_LianHun: public tag_net_message
{
	NET_SIS_LianHun()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_LianHun");
		dw_size = sizeof(*this);
	}
	BYTE byCurArtisan;  //��ǰ����
	DWORD dw_error;
};


// �꾫����
struct NET_SIC_huenjing_opteron : public tag_net_message
{
	NET_SIC_huenjing_opteron()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_huenjing_opteron");
		dw_size = sizeof(*this);
	}
	
	INT		nIndex;	//��������  -1ʱΪ����
	BYTE	byOpt;	//��������  0 ���뾫�걳�� 1 ת��Ϊ���ֵ 2 ����
	BYTE	byConType;	// ������������ 0 ��ʱ�� 1 �����
};

struct NET_SIS_huenjing_opteron: public tag_net_message
{
	NET_SIS_huenjing_opteron()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_huenjing_opteron");
		dw_size = sizeof(*this);
	}
	
	DWORD dw_error_code;
};


// ��������
struct NET_SIC_huenjing_UpLevel : public tag_net_message
{
	NET_SIC_huenjing_UpLevel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_huenjing_UpLevel");
		dw_size = sizeof(*this);
	}

	INT		nIndex;	//��������  
};

struct NET_SIS_huenjing_UpLevel : public tag_net_message
{
	NET_SIS_huenjing_UpLevel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_huenjing_UpLevel");
		dw_size = sizeof(*this);
	}

	DWORD dw_error_code;  
};

// ������Ƕ
struct NET_SIC_huenjing_Inlay : public tag_net_message
{
	NET_SIC_huenjing_Inlay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_huenjing_Inlay");
		dw_size = sizeof(*this);
	}

	INT		nSrcIndex;	//��������  
	INT		nDesIndex;	//��������
	BYTE	byType;		//0 �ȼ��� 1 �ɳ���
	BYTE	byOptType;	// �������� 0 װ�� 1 ж��
};

struct NET_SIS_huenjing_Inlay : public tag_net_message
{
	NET_SIS_huenjing_Inlay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_huenjing_Inlay");
		dw_size = sizeof(*this);
	}

	DWORD dw_error_code;  
};

#pragma pack(pop)