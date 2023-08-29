#pragma once

#pragma pack(push, 1)

const INT MAX_FRIENDNUM					= 100;		// 好友最大个数
const INT MAX_BLACKLIST					= 20;		// 黑名单最倒个数
const INT MAX_FRIENDVAL					= 25920;	// 好友度最大值
const INT MAX_ENEMYNUM					= 50;		// 仇敌最大个数
const INT GIFT_STORE_TIME				= 60 * TICK_PER_SECOND;	// 礼物在管道里保存时间
const INT ADD_FRIENDVALUE_COUNT			= 300 * TICK_PER_SECOND;
const INT TEAM_BUFF_ID					= 6100001;	// 队伍buffid
#define SEND_GIFT_NEED_ITEM 1400027		//红玫瑰typeID gx add 2013.6.27
const INT MAX_COMPRACTICENUM			= 2;		//玩家每日最多可进行双修次数
const INT COMPRACTICE_EXP_TICKS			= 25;		//25个ticks（即5秒）给玩家一次经验
const INT COMPRACTICE_WHOLE_TICKS		= 900;		//双修一次持续的tick总数
const INT COMPRACTICE_MAX_DISTANCE		= 48;		//双修最远距离，一个格子
const INT MARRY_MIN_LEVEL				= 35;		//结婚最低等级
#define MARRY_NEED_ITEM		1300018		//结婚所需婚戒的道具ID
const INT DIVORCE_NEED_GOLD			= 5000000;		//离婚消耗的金币数 500万
#define MARRY_TRANS_ITEM	1400112		//结婚后发放给夫妻的结婚礼包
const INT REDZUI_FLAG_INDEX				= 10;		//玩家脚本数据指向红唇标记的索引
const INT QBJJ_MARRAY_INDEX_WOMAN		= 11;		//情比金坚女神领奖索引
const INT QBJJ_MARRAY_INDEX_MAN			= 12;		//情比金坚女神男人领奖索引
const INT QBJJ_REWARD_LEVEL_MIN			= 45;		//领取情比金坚奖励的最小玩家等级
const INT QBJJ_REWARD_LEVEL_MAX			= 80;		//领取情比金坚奖励的最大玩家等级
struct tagFriend
{
	DWORD	dwFriendID;								// 好友ID
	DWORD	dwFriVal;								// 好友度
	BYTE	byGroup;								// 分组
	tagFriend():dwFriendID(INVALID_VALUE),dwFriVal(0),byGroup(1){}
};

struct tagFriendInfo
{
	DWORD	dwFriendID;								// 好友ID
	DWORD	dwFriVal;								// 好友度
	BYTE	byGroup;								// 分组
	BOOL    bOnline;								// 好友是否在线
	INT		nLevel;									// 角色等级
	EClassType	 eClassType;						// 职业
	BYTE	bySex;									// 性别
};

struct tagBlackInfo
{
	DWORD	dwBlackID;								// 黑名人ID
	INT		nLevel;									// 等级
	EClassType	eClassType;							// 职业
	BYTE	bySex;
};

struct tagEnemyInfo
{
	DWORD	dwEnemyID;								// 仇人ID
	INT		nLevel;									// 等级
	EClassType eClassType;							// 职业
	BYTE	bySex;
};

struct tagSendGift				
{
	DWORD	dwSrcRoleID;							// 发送者
	DWORD	dwDestRoleID;							// 接收者
	DWORD	dw_data_id;								// 礼物TypeID
	INT 	nStoreTick;								// 发送时间
	tagSendGift(DWORD dwSrcRoleID, DWORD dwDestRoleID, DWORD dw_data_id):
		dwSrcRoleID(dwSrcRoleID),dwDestRoleID(dwDestRoleID),dw_data_id(dw_data_id)
	{
		nStoreTick = GIFT_STORE_TIME;
	}
};

struct tagFriUpdate
{
	DWORD   dw_role_id;								// 好友ID
	BOOL	bOnline;								// 是否在线
	INT		nLevel;									// 等级
};

#pragma pack(pop)