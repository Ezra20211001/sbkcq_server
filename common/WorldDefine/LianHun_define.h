#pragma once


#include "RoleDefine.h"

#pragma pack(push, 1)


// 混炼神级
const int HUENLIAN_MIN_ROLE_LEVEL = 1;

//魂精包裹数量
const int MAX_HUENJING_BAG_SIZE = 32;

//角色魂精槽数量
const int MAX_ROLE_HUENJING_SIZE = 6;

//高级混炼消耗非绑定金
const int HIGHLEVEL_HUENLIAN_SIEVER = 100000;

//魂精灰烬id
const DWORD LIANHUENG_HUIJING = 1000000;

//得到各个品质魂精的概率
const DWORD LIANGHUEN_PRO[5][6] = {
	{5000, 5000, 0,		0,		0,	0},
	{5000, 3000, 2000,	0,		0,	0},
	{5000, 2000, 2500,  500,	0,	0},
	{5000, 1000, 2500,  1000,   500, 0},
	{5000, 500,  1670,  1500,   1000, 330},
};

//得到各个属性魂精概率
const DWORD JINGHUENATT_PRO[] = { 400, 400, 400, 400, 300, 700, 800, 800, 800, 1000, 1000, 1000, 1000, 1000};

// 一级魂精获取灵魂值
const INT HUENJINGLINGHUEN[] = {10, 50, 100, 200, 400, 800};

// 等级槽所需等级
const INT LEVELCAONEEDLEVEL[] = {20, 30, 40, 50, 60, 70};

// 成长槽所需神级
const INT GODLEVELCAONEEDLEVEL[] = {4, 5, 8, 12, 17, 23};

// 遇到下级工匠概率
const INT NEXTGONGJIANGPRO[][4] = {
									{40, 40, 30, 20},
									{90, 70, 50, 30},
									};

// 每天最大魂练次数
const INT MAXHUENLIANTIME = 50;

// 错误码
enum
{
	E_BuyLingqi_Full					=	1,		// 灵气值快满了
	E_BuyLingqi_Not_Sivler				=	2,		// 元宝不足

	E_LIANHUEN_NOT_LINGQI				=	3,		// 灵气不足
	E_LIANHUEN_NOT_SIVLER				=	4,		// 金币不足
	E_LIANHUEN_NOT_ENOUTH_BAG_TMP		=	5,		// 临时包裹满了

	E_LIANHUEN_NOT_ENOUTH_BAG			=	6,		// 包裹满了	
	E_LIANHUEN_LEVEL_MAX				=	7,		// 魂精达到角色等级上限
	E_LIANHUEN_SAME_ATT					=	8,		// 已镶嵌相同属性魂精
	E_LIANHUEN_CAN_THIS_NOT_LEVEL		=	9,		// 该位置没开启

	E_LIANHUEN_TIME_FULL				=	10		// 买次数到上限了
};

//工匠类型
enum E_ARTISAN_TYPE
{
	EAT_0,		//入门
	EAT_1,		//初级
	EAT_2,		//中级
	EAT_3,		//高级
	EAT_4		//特级
};

//魂晶原型
struct tagHunJingProto
{
	DWORD			dwID;			//id
	ERoleAttribute	eAtt;			//属性
	BYTE			byQuality;		//品质
	INT				nBaseAtt;		//基础属性
	INT				nGrowAtt;		//成长属性
};


//魂晶
struct tagHuenJing
{
	DWORD	dw_data_id;
	INT		nLevel;
};


//角色魂精数据
struct tagRoleHuenJingData
{	
	// 零时包裹
	tagHuenJing	s_huenjing_bag_temp[MAX_HUENJING_BAG_SIZE];
	// 魂精包裹
	tagHuenJing	s_huenjing_bag[MAX_HUENJING_BAG_SIZE];
	
	// 等级槽
	tagHuenJing	s_huenjing_role_level[MAX_ROLE_HUENJING_SIZE];
	// 成长槽
	tagHuenJing	s_huenjing_role_titel[MAX_ROLE_HUENJING_SIZE];

	BYTE		byCurArtisan;	//当前工匠类型

	tagRoleHuenJingData(){ memset(this, 0, sizeof(*this)); }
};



// 辅助函数
class LianHunHelper
{
public:
	// 获取灵气购买花费
	static INT32 GetBuyLingqi(INT32 time)
	{
		return 10+time/7*2;
	}

	// 获取消耗灵气值
	static INT getLingqi(BYTE eat)
	{
		return 400 + eat * 200;
	}

	// 能否遇到下一级工匠
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
			//品质*（(等级\10)^2*等级+等级*10）/2
			return (byQuality+1)*(pow(nLevel/10 * 1.0, 2)*nLevel + nLevel*10)/2;
		}
		else
		{
			//4^（品质-2)*（(等级\10)^2*等级+等级*10）/2
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

//购买灵气
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
	DWORD			dwErrCode;		// 错误码
};


// 获取魂晶数据
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

// 更新魂精数据
struct NET_SIS_update_HunJing_data : public tag_net_message
{
	NET_SIS_update_HunJing_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_update_HunJing_data");
		dw_size = sizeof(*this);
	}

	BYTE byType; //魂精容器类型 0 临时包裹 1 魂精包裹 2  等级槽3  成长槽
	BYTE byIndex; //位置
	tagHuenJing s_data; // 数据
};


// 炼魂
struct NET_SIC_LianHun : public tag_net_message
{
	NET_SIC_LianHun()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_LianHun");
		dw_size = sizeof(*this);
	}

	BYTE	byType;		// 0 普通 1高级
};


struct NET_SIS_LianHun: public tag_net_message
{
	NET_SIS_LianHun()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_LianHun");
		dw_size = sizeof(*this);
	}
	BYTE byCurArtisan;  //当前工匠
	DWORD dw_error;
};


// 魂精操作
struct NET_SIC_huenjing_opteron : public tag_net_message
{
	NET_SIC_huenjing_opteron()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_huenjing_opteron");
		dw_size = sizeof(*this);
	}
	
	INT		nIndex;	//操作索引  -1时为所有
	BYTE	byOpt;	//操作类型  0 放入精魂背包 1 转化为灵魂值 2 整理
	BYTE	byConType;	// 操作容器类型 0 临时包 1 精魂包
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


// 精魂升级
struct NET_SIC_huenjing_UpLevel : public tag_net_message
{
	NET_SIC_huenjing_UpLevel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_huenjing_UpLevel");
		dw_size = sizeof(*this);
	}

	INT		nIndex;	//操作索引  
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

// 精魂镶嵌
struct NET_SIC_huenjing_Inlay : public tag_net_message
{
	NET_SIC_huenjing_Inlay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_huenjing_Inlay");
		dw_size = sizeof(*this);
	}

	INT		nSrcIndex;	//操作索引  
	INT		nDesIndex;	//操作索引
	BYTE	byType;		//0 等级槽 1 成长槽
	BYTE	byOptType;	// 操作类型 0 装上 1 卸下
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