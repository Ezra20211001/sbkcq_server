#pragma once

#pragma pack(push, 1)

const INT	MAX_REWARD_NUM			=	10;			// 最大奖励数量
const INT	MAX_SIGN_DAY_NUM		=   31;			// 最大签到天数

const INT	MAX_VIP_MIANQIAN_TIME	= 3;			// vip免签次数
enum
{
	SIGN_NOT_OPEN			=		1,				// 签到活动尚未开始
	SIGN_HAVE_SIGN			=		2,				// 已经签过到了
	SIGN_SYSTEM_ERROR		=		3,				// 签到系统异常，没有找到可签日期
	SIGN_PEPEAT_REWARD		=		4,				// 重复领奖
	SIGN_BAG_FULL			=		5,				// 包裹已满
	SIGN_BUQIANERROR		=		6,				// 补签日期不符
	SIGN_BUQIAN_VIP			=		7,				// 不是vip不能补签
	SIGN_BUQIAN_NUM			=		8,				// 补签次数已满
	SIGN_LEVEL_NOT			=		9				// 等级限制
};

struct tagSingRewardData
{
	INT		n_condition;			// 条件
	DWORD	dw_reward_id;			// 奖品ID
	BOOL	bBind;					// 是否绑定
};

struct tagSignProto
{
	DWORD				dw_id;							// id 同活动id对应
	INT					n_keep_time;					// 持续时间（单位天）
	INT					n_reward_num;					// 领奖数量
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
//角色签到数据
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

// 获取签到数据
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

// 签到
struct NET_SIC_sign : public tag_net_message
{
	NET_SIC_sign()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_sign");
		dw_size = sizeof(*this);
	}

	BOOL	b_buqian;			// 是否补签
	DWORD	dw_date;			// 补签日期
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

// 签到领奖
struct NET_SIC_sign_reward : public tag_net_message
{
	NET_SIC_sign_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_sign_reward");
		dw_size = sizeof(*this);
	}

	INT n_index;			// 领奖索引
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

// 新的领取签到奖励
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