#pragma once

#pragma pack(push, 1)

//玩家聊天发言频道
enum ESendChatChannel
{
	ESCC_NULL = -1,
	ESCC_Common = 0,		//普通
	ESCC_Secret,			//密语
	ESCC_Team,				//队伍
	ESCC_Guild,				//帮派
	ESCC_Map,				//区域
	ESCC_World,				//世界
	ESCC_Qianli,			//千里传音

	ESCC_Decree,			//昭告
	ESCC_Hearsay,			//传闻
	ESCC_Combat,			//战斗
	ESCC_Affiche,			//公告
	ESCC_GM,				//GM
	ESCC_System,			//系统
	
	ESCC_SiLiao,			//私聊
	ESCC_System_Online_Remain,
	ESCC_System_No_System,
	ESCC_System_White,
	ESCC_System_White_Yellow,
	ESCC_System_White_Green,
	ESCC_System_White_Pink,
	ESCC_System_White_Purple,
	ESCC_Red_Cue,

	ESCC_End,	
};

//世界频道时间间隔
const INT WORLD_CHANNEL_INTERVAL = TICK_PER_SECOND * 5;

//世界频道消息长度限制
const INT WORLD_CHANNEL_MSG_LEN = 200;

//世界频道消息玩家等级限制
const INT	WORLD_CHANNEL_ROLE_LVL = 10;

//gx moidfy 2013.6.18
const DWORD TYPEID_IM_DECREE = 1400034;//昭告天下所需道具ID
const DWORD TYPEID_IM_QIANLI = 1400033;//千里传音所需道具ID
//end
const INT DECREE_COST_YUANBAO = 10;

#pragma pack(pop)