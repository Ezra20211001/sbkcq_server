#pragma once

#pragma pack(push, 1)

const INT	MAX_REWARD_NUM			=	10;			// ���������
const INT	MAX_SIGN_DAY_NUM		=   31;			// ���ǩ������

const INT	MAX_VIP_MIANQIAN_TIME	= 3;			// vip��ǩ����
enum
{
	SIGN_NOT_OPEN			=		1,				// ǩ�����δ��ʼ
	SIGN_HAVE_SIGN			=		2,				// �Ѿ�ǩ������
	SIGN_SYSTEM_ERROR		=		3,				// ǩ��ϵͳ�쳣��û���ҵ���ǩ����
	SIGN_PEPEAT_REWARD		=		4,				// �ظ��콱
	SIGN_BAG_FULL			=		5,				// ��������
	SIGN_BUQIANERROR		=		6,				// ��ǩ���ڲ���
	SIGN_BUQIAN_VIP			=		7,				// ����vip���ܲ�ǩ
	SIGN_BUQIAN_NUM			=		8,				// ��ǩ��������
	SIGN_LEVEL_NOT			=		9				// �ȼ�����
};

struct tagSingRewardData
{
	INT		n_condition;			// ����
	DWORD	dw_reward_id;			// ��ƷID
	BOOL	bBind;					// �Ƿ��
};

struct tagSignProto
{
	DWORD				dw_id;							// id ͬ�id��Ӧ
	INT					n_keep_time;					// ����ʱ�䣨��λ�죩
	INT					n_reward_num;					// �콱����
	tagSingRewardData	st_reward_data[MAX_REWARD_NUM];	

	tagSignProto()
	{
		dw_id = INVALID_VALUE;
		n_keep_time = 0;
		n_reward_num = 0;
		for(INT i = 0; i < MAX_REWARD_NUM; i++)
		{
			st_reward_data[i].dw_reward_id = INVALID_VALUE;
			st_reward_data[i].n_condition = 0;
		}
	}
};

struct SignInfo
{
	tagDWORDTime	st_time;
	BOOL			b_sign;
};
//��ɫǩ������
struct tagRoleSignData
{
	SignInfo st_sign_info[MAX_SIGN_DAY_NUM];

	BOOL	b_reward[MAX_REWARD_NUM];
	
	INT16	n16_mianqian_time;

	tagRoleSignData()
	{
		ZeroMemory(st_sign_info, sizeof(st_sign_info));
		ZeroMemory(b_reward, sizeof(b_reward));
		n16_mianqian_time = 0;
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////

// ��ȡǩ������
struct NET_SIC_get_sign_data : public tag_net_message
{
	NET_SIC_get_sign_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_sign_data");
		dw_size = sizeof(*this);
	}
};

struct NET_SIS_get_sign_data : public tag_net_message
{
	NET_SIS_get_sign_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_sign_data");
		dw_size = sizeof(*this);
	}

	tagRoleSignData st_role_sign_data;
	INT16			n16_mianqian_time;
	DWORD			dw_error;
};

// ǩ��
struct NET_SIC_sign : public tag_net_message
{
	NET_SIC_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_sign");
		dw_size = sizeof(*this);
	}

	BOOL	b_buqian;			// �Ƿ�ǩ
	DWORD	dw_date;			// ��ǩ����
};

struct NET_SIS_sign : public tag_net_message
{
	NET_SIS_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_sign");
		dw_size = sizeof(*this);
	}
	tagDWORDTime		st_sign_time;
	DWORD				dw_error;
};

// ǩ���콱
struct NET_SIC_sign_reward : public tag_net_message
{
	NET_SIC_sign_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_sign_reward");
		dw_size = sizeof(*this);
	}

	INT n_index;			// �콱����
};

struct NET_SIS_sign_reward : public tag_net_message
{
	NET_SIS_sign_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_sign_reward");
		dw_size = sizeof(*this);
	}
	INT	  n_index;
	DWORD dw_error;
};

// �µ���ȡǩ������
struct NET_SIC_get_sign_reward : public tag_net_message
{
	NET_SIC_get_sign_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_sign_reward");
		dw_size = sizeof(*this);
	}

};

struct NET_SIS_get_sign_reward : public tag_net_message
{
	NET_SIS_get_sign_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_sign_reward");
		dw_size = sizeof(*this);
	}
	DWORD dw_error;
};

#pragma pack(pop)