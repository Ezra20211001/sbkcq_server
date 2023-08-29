//-----------------------------------------------------------------------------
//file	 QuestDef.h
//
//date   2008-08-06
//update 2008-11-12
//brief  任务数据结构定义
//-----------------------------------------------------------------------------
#pragma once

#include "RoleDefine.h"
#include "script_data.h"
#include "../WorldDefine/time.h"

#pragma pack(push, 1)

#define QUEST_OVERVIEW	512

#define QUEST_MAX_COUNT						30			//一个玩家同时最多接受的任务个数
#define QUEST_ACCEPT_NPC					6			//接取任务NPC数量
#define QUEST_COMPLETE_NPC					6			//接取任务NPC数量
#define QUEST_REPUTATIONS_COUNT 			4			//任务声望种类
#define QUEST_CONTRIBUTION_COUNT            4           //任务贡献种类
#define QUEST_SKILLS_COUNT 					4			//任务技能种类
#define QUEST_ITEMS_COUNT					8			//任务物品种类
#define QUEST_ATTS_COUNT					4			//任务属性种类		
#define QUEST_CREATURES_COUNT				6			//任务怪物种类
#define QUEST_NPC_COUNT						8			//任务NPC数量
#define QUEST_TRIGGERS_COUNT				8			//任务触发器数量
#define QUEST_REW_ITEM						3			//任务奖励物品种类
#define QUEST_REW_BUFF						4			//任务奖励buff种类
#define QUEST_CREATURESID_COUNT				18			//
#define DYNAMIC_TARGET_COUNT				4			//任务动态目标的数量
#define SCRIPTQUEST_VARIABLE_MAX			5

#define QUEST_TRACK_MAX						8
#define QuestTrack(dw_flag)		((dw_flag)&0x80000000)

#define QuestIDDelta				50000
#define CIRCLEQUESTMAXNUMBER		10
#define CIRCLEQUESTFRESHNUMBER		20
#define CIRCLEQUEST_FRESH_NUMBERMAXDAY		10
#define CIRCLEQUESTFRESHNUMBERDELTA 2
#define CIRCLEQUESTPERDAYNUMBER		20

#define BUYCQUESTNUMBERCOSVIGOUR     10
#define BUYCQUESTFRESHCOSTYUANBAO	 5
#define QUESTREWARDNOSEX			 7 //gx add 标识不用区分性别

#define DAILYQUESTMOWU				5//gx add 魔物狩猎基本次数
#define DAILYQUESTXIULU				3//gx add 修罗试炼基本次数
static int get_buy_refresh_yuanbao(int val)
{
	int powof = val + 1;
	powof /= 3;
	int yuanbao  = 3 *( 1 << powof );
	return yuanbao;
}

struct CircleQuestMan
{
	INT nNumber;
	UINT16 u16QuestID[CIRCLEQUESTMAXNUMBER];
	bool bFlag[CIRCLEQUESTMAXNUMBER];
public:
	CircleQuestMan()
	{
		ZeroMemory(this, sizeof(*this));
	}
public:
	//! 加载时初始化
	VOID Init(const CircleQuestMan* pMan)
	{
		memcpy(this, pMan, sizeof(*this));
	}

	//! 填充 跟数据库处理
	INT Fill(OUT CircleQuestMan* pMan) const
	{		
		if(nNumber == 0) memset(pMan, 0, sizeof(*this));
		else memcpy(pMan, this, sizeof(*this));

		return nNumber;
	}

	//! 填充 填充给客户端
	INT Fill(OUT UINT16* pID, OUT bool* pFlag, INT  nSize) const
	{		
		if(nNumber == 0) return 0;

		for(int n = 0; n < nNumber && n < nSize; ++n)
		{
			if(VALID_POINT(pFlag)) pFlag[n] = bFlag[n];
			if(VALID_POINT(pID))  pID[n] = u16QuestID[n];
		}

		return nNumber;
	}

	//! 新增ID
	VOID Add(UINT16 u16, bool bShare = false)
	{
		if(nNumber < CIRCLEQUESTMAXNUMBER)
		{
			bFlag[nNumber] = bShare;
			u16QuestID[nNumber] = u16;
			++nNumber;
		}
	}

	//! 移除ID
	VOID Remove(UINT16 u16)
	{
		INT tIndex = GetIndex(u16);
		if(tIndex != -1)
		{
			for(INT n = tIndex + 1; n < nNumber; ++n)
			{
				if(u16QuestID[n])
				{
					u16QuestID[tIndex] = u16QuestID[n];
					++tIndex;
				}
			}
			u16QuestID[tIndex] = 0;
			--nNumber;
		}
	}

	//! 移除ID
	INT RemoveEX(UINT16 u16)
	{
		INT tIndex = GetIndex(u16);
		if(tIndex != -1){
			u16QuestID[tIndex] = 0;
		}
		return tIndex;
	}

	VOID AddEX(UINT16 u16, INT idx)
	{
		if(idx >= nNumber || idx >= CIRCLEQUESTMAXNUMBER)
			return;

		u16QuestID[idx] = u16;
	}

	//! 是否存在
	BOOL Exist(UINT16 u16) const { return GetIndex(u16) != -1; }

	//! 搜索ID索引
	INT GetIndex(UINT16 u16) const 
	{
		for(INT n = 0; n < nNumber; ++n)
			if(u16QuestID[n] == u16) return n;
		return -1;
	}

	INT16 GetValue(INT nIndex)
	{
		return nIndex < nNumber ? u16QuestID[nIndex] : 0;
	}

	bool GetFlag(INT nIndex)
	{
		return nIndex < nNumber ? bFlag[nIndex] : false;
	}

	//! 当前个数
	INT GetNumber() const { return nNumber; }
};
struct QuestIDHelper
{
	static UINT16 RestoreID(UINT16 u16QuestID)
	{
		return (u16QuestID>QuestIDDelta) ?
			(u16QuestID-QuestIDDelta): u16QuestID;
	}

	static UINT16 GenerateID(UINT16 u16QuestID, BOOL IDSpecial = FALSE)
	{
		return IDSpecial ? (u16QuestID + QuestIDDelta) : u16QuestID;
	}

	static BOOL SpecialID(UINT16 u16QuestID)
	{
		return u16QuestID > QuestIDDelta;
	}
};

struct tagDWORDQuestFlag
{
	DWORD	dwReserved			:	28, // 保留
			dwCompleteByReciver : 1, // 是否已经被接单者完成
			dwTakeFromGuerdon	:	1,  // 来自悬赏榜
			dwQuestBeGuerdon	:	1,  // 是否被悬赏
			dwQuestTrack		:	1;// 是否追踪

	tagDWORDQuestFlag(DWORD dwQuestFlg = 0){*this = *(tagDWORDQuestFlag*)&dwQuestFlg;}
	tagDWORDQuestFlag& operator= (DWORD dwQuestFlg){return (*this) = (*(tagDWORDQuestFlag*)&dwQuestFlg);}
	operator DWORD() { return *(DWORD*)this; }
};

enum EQuestTargetMode
{
	EQTM_STATIC		=	0,		// 静态目标
	EQTM_DYNAMIC	=	1,		// 动态目标
};

enum EQuestTargetType
{
	EQTT_NULL		=	0,
	EQTT_Kill		=	1,		// 击杀目标
	EQTT_Collect	=	2,		// 收集道具	
	EQTT_NPCTalk	=	3,		// NPC对话
	EQTT_Invest		=	4,		// 调查地物
};

//显示任务类型
enum QuestType
{
	QT_KILL = 1,
	QT_TALK ,
	QT_CAIJI ,
	QT_SONGDA ,
	QT_FUBEN,
	QT_TOTAL,
};

//--------------------------------------------------------------------------------
// 任务动态目标类型结构
//--------------------------------------------------------------------------------
struct tagQuestDynamicTarget
{
	EQuestTargetType	eTargetType;							// 任务目标类型
	DWORD				dwQuestTipsID;
	DWORD				dwTargetID[DYNAMIC_TARGET_COUNT];		// 目标TypeID
	INT					nTargetNum[DYNAMIC_TARGET_COUNT];		// 目标数量
	tagQuestDynamicTarget()
	{
		ZeroMemory(this, sizeof(*this));
		memset(dwTargetID, 0XFF, sizeof(DWORD)*DYNAMIC_TARGET_COUNT);
	}
};
//--------------------------------------------------------------------
// 任务动态奖励
//--------------------------------------------------------------------
struct tagQuestDynamicReward
{
	DWORD	rew_item[QUEST_REW_ITEM];						//任务奖励的物品ID
	BYTE	rew_item_num[QUEST_REW_ITEM];					//任务奖励的物品数量
	BYTE	rew_item_quality[QUEST_REW_ITEM];				//任务奖励的物品品级
	BYTE		rew_item_bind[QUEST_REW_ITEM];				//是否绑定
	DWORD	rew_choice_item[QUEST_REW_ITEM];			//任务奖励的可选物品ID
	BYTE	rew_choice_item_num[QUEST_REW_ITEM];		//任务奖励的可选物品数量
	BYTE	rew_choice_quality[QUEST_REW_ITEM];			//任务奖励的可选物品品级
	BYTE		rew_choice_bind[QUEST_REW_ITEM];			//是否绑定
	tagQuestDynamicReward( )
	{
		ZeroMemory(this, sizeof(*this));
		memset(rew_item_bind,1, sizeof(rew_item_bind));
		memset(rew_choice_bind,1, sizeof(rew_item_bind));
	}
};

//--------------------------------------------------------------------
// 脚本任务
//--------------------------------------------------------------------
struct tagQuestVar
{
	//!完成条件描述
	UINT32 TargetMsgID;
	//!变量id
	UINT16 ID;
	//!值
	INT16  Value;
	//!完成值
	INT16  CompValue;
	//!失败值
	INT16  FailValue;
public:
	BOOL IsComplete( ) const{ return Value>= CompValue; }
	BOOL IsFail( ) const{ return  FailValue == Value; }
	VOID IncVar( INT16 delta ){ Value += delta; }
	VOID SetVar( INT16 var ){ Value = var; }
	INT16 GetVar( ) const{ return Value; }
	VOID SetTargetMsgID( UINT32 MsgID ){ TargetMsgID = MsgID; }
};
struct tagScriptQuestVar
{
	//!任务描述
	UINT32 OverviewMsgID;
	//!变量有效个数
	BYTE   Number;
	tagQuestVar stVariable[SCRIPTQUEST_VARIABLE_MAX];
public:
	tagScriptQuestVar( ){ZeroMemory( this, sizeof(*this) );}

	VOID SetOverviewMsgID( UINT32 MsgID ){ OverviewMsgID = MsgID;}
	BOOL IsComplete( ) const
	{
		for( BYTE n = 0; n < Number; ++n)
			if( !stVariable[n].IsComplete( )) return FALSE;
		return TRUE;
	}
	BOOL IsFail( )const
	{
		for( BYTE n = 0; n < Number; ++n)
			if( stVariable[n].IsFail( ) ) return TRUE;
		return FALSE;
	}
	BOOL SetTargetMsgID(BYTE id, UINT32 MsgID )
	{
		char cIndex = GetIndex( id );
		if( cIndex >= 0 )stVariable[cIndex].SetTargetMsgID(MsgID);
		return cIndex >= 0;
	}

	BOOL IncVar( BYTE id, INT16 delta )
	{
		char cIndex = GetIndex( id );
		if( cIndex >= 0 && stVariable[cIndex].IsComplete( ) ) return FALSE;
		if( cIndex >= 0 && stVariable[cIndex].IsFail( ) ) return FALSE;
		if( cIndex >= 0 )stVariable[cIndex].IncVar(delta);
		return cIndex >= 0;
	}

	BOOL SetVar( BYTE id, INT16 Value )
	{
		char cIndex = GetIndex( id );
		if( cIndex >= 0 )stVariable[cIndex].SetVar(Value);
		return cIndex >= 0;
	}

	BOOL AddVar( BYTE id, UINT32 MsgID, INT16 Value, INT16 Complete, INT16 Fail )
	{
		if( Number>=SCRIPTQUEST_VARIABLE_MAX ) return FALSE;
		stVariable[Number].ID = id;
		stVariable[Number].TargetMsgID = MsgID;
		stVariable[Number].Value = Value;
		stVariable[Number].CompValue = Complete;
		stVariable[Number].FailValue = Fail;
		++Number;
		return TRUE;
	}

	BOOL GetVar( BYTE id, INT16&Value  )const
	{
		Value = -1;
		char cIndex = GetIndex( id );
		if( cIndex >= 0 ) Value = stVariable[cIndex].Value;
		return cIndex >= 0;
	}

	char GetIndex( BYTE id )const
	{
		for( char c = 0; c < SCRIPTQUEST_VARIABLE_MAX; ++c )
			if(stVariable[c].ID == id ) return c;
		
		return -1;
	}
};

// DB服务器用到的任务结构
struct tagQuestSave // 任务结构, 用于游戏服务器和数据库服务间传输
{
	UINT16	u16QuestID;								// 任务ID
	INT16	n16MonsterNum[QUEST_CREATURES_COUNT];	// 完成的任务怪个数
	DWORD	dwAcceptTime;							// 接受任务的时间
	DWORD	dwQuestFlag;							// 任务完成状态
	UINT16	u16Quest_NewFlag;						// 标识每日任务 gx add
	tagScriptData<ESD_Quest>	Data;				// 脚本通用数据
	tagQuestDynamicTarget		DynamicTarget;		// 任务动态目标
	tagQuestDynamicReward		DynamicReward;		// 任务动态奖励
	tagScriptQuestVar			ScriptQuestVar;		// 脚本设置数据
};


struct tagQuestDoneSave		// 已完成任务结构, 用于游戏服务器和数据库服务间传输(游戏服务器请求完整结构时)
{
	DWORD	dwStartTime;	// 记录任务中接受第一个任务的时间
	INT32	nTimes;			// 一个时期内完成的任务次数
	UINT16	u16QuestID;		// 任务ID
	UINT16	u16QuestFalg;	//每日任务标识
};

struct tagQuestDoneSimSave	// 已完成任务简易结构, 用于游戏服务器和数据库服务间传输(玩家登陆时)
{
	UINT16	u16QuestID;		// 任务ID
};

struct tagAcceptQuest 
{
	DWORD	dwAcceptTime;		// 任务接取时间
	UINT16	u16QuestID;			// 任务ID
	INT32	nNewFlag;
};
//-----------------------------------------------------------------------------
// 各种任务事件定义
//-----------------------------------------------------------------------------
enum EQuestEvent
{
	EQE_Null,
	EQE_Talk,		// 对话
	EQE_Kill,		// 击杀
	EQE_Item,		// 物品
	EQE_Trigger,	// 触发器
	EQE_Invest,		// 调查地物
	EQE_DlgDefault,	// 服务器可控对话框缺省事件 
	EQE_UseItem,    // js zhaopeng 2010.04.01 使用物品
	EQE_Rescue,     // js zhaopeng 2010.04.08 营救NPC
	EQE_Convoy,     // js zhaopeng 2010.04.13 护送NPC
	EQE_End
};

//任务共享消息
enum EQuestShareMessages
{
	QUEST_PARTY_MSG_SHARING_QUEST   = 0,			//共享任务
	QUEST_PARTY_MSG_CANT_TAKE_QUEST = 1,			//不能接取任务
	QUEST_PARTY_MSG_ACCEPT_QUEST    = 2,			//接取任务
	QUEST_PARTY_MSG_REFUSE_QUEST    = 3,			//拒绝接受任务
	QUEST_PARTY_MSG_TOO_FAR         = 4,			//距离太远
	QUEST_PARTY_MSG_BUSY            = 5,			//忙碌状态
	QUEST_PARTY_MSG_LOG_FULL        = 6,			//任务满了
	QUEST_PARTY_MSG_HAVE_QUEST      = 7,			//已经有这个任务
	QUEST_PARTY_MSG_FINISH_QUEST    = 8,			//已经完成该任务
};

//任务完成事件类型
enum EQuestCompleteEventType
{
	EQCET_Null = 0,		
	EQCET_UseItem = 1,	//使用物品事件
	EQCET_UseSkill = 2, //使用技能事件
};

enum EWeek
{
	EWeek_SUN = 0,
	EWeek_MON = 1,
	EWeek_TUES = 2,
	EWeek_WEDNES = 3,
	EWeek_THURS = 4,
	EWeek_FRI = 5,
	EWeek_SAT = 6,
	EWeek_ANY = 255,
};

enum EQuestPeriodic
{
	EQuestPeriodic_DAY = 0,
	EQuestPeriodic_WEEK = 1,
};

//任务标志
enum QuestFlag
{
	Quest_Flag_KILL		 = 0x00000001,
	Quest_Flag_ITEM		 = 0x00000002,
	Quest_Flag_NPC_TALK  = 0x00000004,
	Quest_Flag_Trigger	 = 0x00000008,
	Quest_Flag_Invest	 = 0x00000010,
};

//任务接取标志
enum QuestAcceptFlag
{
	Quest_Accept_Flag_Player = 0x00000001, //玩家主动接取
	Quest_Accept_Flag_System = 0x00000002, //系统发布
	Quest_Accept_Flag_Item   = 0x00000004, //从物品接取
};

enum e_quest_difficulty
{
	eqd_normal = 0, //普通
	eqd_elite,
	eqd_hero,
};
class quest_script;

// 任务数据结构
// Tip:循环任务：
struct  tagQuestProto
{
	// 任务属性
	UINT16 					id;												//任务ID，唯一标识任务
	UINT16  				prev_quest_id;									//前一个任务1ID
	UINT16  				prev_quest2_id;									//前一个任务2ID
	INT						prev_quest_relation;							//两个前序任务之间的关系, 0 为两个都必须完成 1 两个完成其中一个就可以
	UINT16  				next_quest_id;									//后续任务ID
	UINT16  				uncomplete_quest_id;							//未完成任务ID,为了达到 如果完成某个任务,就不能接取接取该任务
	UINT16					undone_quest_id;										
	BOOL 					auto_add_quest;									//当前任务完成后，后续任务是否自动加载到玩家身上
	DWORD					accept_flags;									//任务接取标志
	INT						type;											//任务类型： 新手任务 主线任务 剧情任务等等
	EQuestTargetMode		target_mode;									//任务目标类型:	0 -- 静态目标, 1 --  动态目标
	BYTE 					suggested_players;								//建议玩家个数	
	DWORD 					limit_time;										//任务完成的限制时间
	BYTE 					accept_times;									//每个玩家接取任务次数
	BOOL					period;											//是否是周期性任务
	EQuestPeriodic			period_type;									//任务周期类别（每天 每周）
	EWeek					week;
	BOOL					repeatable;										//任务是否可以重复
	DWORD					accept_quest_npc[QUEST_ACCEPT_NPC];				//接取任务NPCID
	DWORD					accpet_link_npc[QUEST_ACCEPT_NPC];				//接取任务npc的链接npcid，用来寻路指引
	DWORD					complete_quest_npc[QUEST_COMPLETE_NPC];			//完成任务NPCID
	DWORD					complete_quest_npc_guide[QUEST_COMPLETE_NPC]; //完成任务npc的指引者，用来寻路
	DWORD					src_item;										//任务发布者给的任务物品ID
	INT16					src_item_num;									//任务发布者给的任务物品数量
	BOOL					src_item_bind;
	BOOL					show_quest_dialog;								//接取任务后是否弹出任务界面
	FLOAT					destination_x;									//任务目的地 X 坐标
	FLOAT					destination_y;									//任务目的地 Y 坐标
	FLOAT					destination_z;									//任务目的地 Z 坐标
	BOOL					no_delete;										//任务不能被删除 为 TRUE时不能被删除，FALSE 可以被删除，大部分任务是可以被删除的
	DWORD					investigate_objects[QUEST_ITEMS_COUNT];			//可调查地物
	DWORD					CompleteType;
	BOOL			hide_in_acceptable;								//在可接任务中隐藏
	e_quest_difficulty  difficulty_type;								//任务难度
	// 字符串相关
	TCHAR					name[X_SHORT_NAME];								//任务名称
	TCHAR					conditions[X_SHORT_NAME];						//任务条件
	TCHAR 					over_view[QUEST_OVERVIEW];						//任务概述
	BOOL					loop_rand_quest_flag;							//是否循环任务随机
	BOOL					xuanshang_flag;									//是否能悬赏
	BOOL					team_rand_share;								//是否队伍随机共享

	//任务接取条件
	INT32  					accept_req_max_level;							//接取任务所需要的最大等级
	INT32  					accept_req_min_level;							//接取任务所需要的最小等级
	INT32					accept_req_rep[QUEST_REPUTATIONS_COUNT];		//接取任务所需要的声望
	INT32					accept_req_min_rep[QUEST_REPUTATIONS_COUNT];	//接取任务所需要的声望最小值
	INT32					accept_req_max_rep[QUEST_REPUTATIONS_COUNT];	//接取任务所需要的声望最大值
	BYTE					sex;											//接取任务所需要的性别
	INT						class_type;										//接取任务所需要的职业	
	DWORD					accept_req_map;									//接取任务所需要的地图
	DWORD					accept_req_skill[QUEST_SKILLS_COUNT];			//接取任务所需要的技能
	INT32					accept_req_skill_val[QUEST_SKILLS_COUNT];		//接取任务所需要的技能值
	DWORD					accept_req_item[QUEST_ITEMS_COUNT];				//接取任务所需要的物品ID
	INT16					accept_req_item_num[QUEST_ITEMS_COUNT];			//接取任务所需要的物品数量
	INT16					accept_req_att[QUEST_ATTS_COUNT];				//接取任务所需要的人物属性
	INT32					accept_req_att_val[QUEST_ATTS_COUNT];			//接取任务所需要的人物属性值
	DWORD					accept_req_trriger[QUEST_TRIGGERS_COUNT];		//接取任务所需要的触发器ID
	DWORD					accept_cant_has_item[QUEST_ITEMS_COUNT];		//接取任务不能有的物品ID
	INT32					accept_req_money;								//接取任务所需要的金钱
	BOOL					accept_del_money;								//接取任务后,是否删除相应金钱
	BOOL					del_req_item;									//限制物品是否删除
	BOOL 					married;										//是否结婚
	BYTE 					lover_num;										//情侣数量
	UINT16					xs_send_need_money;								//发布悬赏任务需要金钱
	UINT16					xs_recv_need_money;								//接取悬赏任务需要金钱
	BOOL					bNeedGuild;										// 帮会
	BOOL					bNeedMaster;									// 师傅
	BOOL					bNeedPrentice;									// 徒弟
	BOOL					bBangZhu;										// 帮主
	UINT16					accept_guild_level_min;							// 帮会最小等级
	UINT16					accept_guild_level_max;							// 帮会最大等级
	UINT16					accept_vip_level;								// vip等级

	//任务完成条件
	DWORD					complete_req_item[QUEST_ITEMS_COUNT];			//完成任务所需要的物品
	INT16					complete_req_item_num[QUEST_ITEMS_COUNT];		//完成任务所需要的物品数量
	DWORD					pursueNPC[QUEST_ITEMS_COUNT];					//完成任务所需要的npcid
	BOOL					only_one_item;									//是否搜集完其中一种就可完成
	BOOL					delete_item;									//完成任务后是否需要删除物品
	DWORD					complete_req_creature[QUEST_CREATURESID_COUNT];	//完成任务所需要杀的怪
	INT16					complete_req_creature_num[QUEST_CREATURES_COUNT];//完成任务所需要杀的怪数量
	DWORD				complete_req_creature_pursue_npc[QUEST_CREATURES_COUNT]; //接引人
	BOOL					creature_level;									//是否指定击杀指定等级 的怪物
	BOOL					only_one_creature;								//是否击杀完指定数量的一种怪物就可完成
	DWORD					complete_req_npc[QUEST_NPC_COUNT];				//完成任务所需要对话的NPC数量
	BOOL					only_in_order;									//是否必须按顺序对话
	BOOL					only_one_npc;									//是否只和一个NPC对话后就可完成
	DWORD					complete_req_trigger[QUEST_TRIGGERS_COUNT];		//完成任务所需要的触发器ID
	BOOL					only_one_trigger;								//是否只触发一个就可完成
	INT32					complete_req_money;								//完成任务所需要的金钱
	BOOL					complete_del_money;								//完成任务后是否删除相应金钱
	DWORD					complete_req_map;								//完成任务所需要的地图ID
	FLOAT					complete_req_map_x;								//完成任务所需要的地图X坐标
	FLOAT					complete_req_map_y;								//完成任务所需要的地图Y坐标
	FLOAT					complete_req_map_z;								//完成任务所需要的地图Z坐标
	FLOAT					complete_req_map_radius;						//完成任务所需要的地图半径
	BOOL					coordinate_random;								//这个坐标是否随机生成
	EQuestCompleteEventType event_type;										//任务完成事件类型
	DWORD					use_item;										//使用的物品ID
	DWORD					use_skill;										//使用的技能ID
	BOOL					only_one_condition;								//是否以上所有条件完成一项即可完成整个任务
	INT32 					complete_req_level;								//完成任务需要的等级
	BOOL 					complete_req_married;							//是否结婚
	BYTE 					complete_req_lover_num;							//情侣数量
	BOOL					complete_req_bag_password;						// 是否需要验证超级密码
	INT32					complete_need_yuanbao;							// 需要XXX元宝

	//!mwh-2011-07-25
	BOOL					del_vigour;													// 是否删除
	INT32					vigour_val;													// 元气值
	BOOL					del_banggong;												// 需要帮贡
	INT32					banggong_val;												//  帮贡值

	
	//任务奖励
	BOOL					bind_money_flag;								//金钱奖励，是否为绑定
	INT32					rew_money;										//任务完成后，奖励的金钱
	INT32					rew_xp;											//任务完成后，奖励的经验值
	INT32					rew_yuanbao;									//任务完成后，奖元宝
	INT32					rew_exploits;									//任务完成后，奖励的战功
	INT32					rew_contributions;								//帮派贡献
	INT32					rew_prosperity;									//帮派繁荣度
	INT32					rew_guild_fund;									//帮派资金
	DWORD					rew_rep[QUEST_REPUTATIONS_COUNT];				//任务奖励的声望
	INT32					rew_rep_val[QUEST_REPUTATIONS_COUNT];			//任务奖励的声望值
	DWORD					rew_contribution[QUEST_CONTRIBUTION_COUNT];		//任务奖励的贡献
	INT32					rew_contribution_val[QUEST_CONTRIBUTION_COUNT];	//任务奖励的贡献值
	DWORD					rew_item[QUEST_REW_ITEM*X_ClASS_TYPE_NUM];		//任务奖励的物品ID
	INT16					rew_item_num[QUEST_REW_ITEM*X_ClASS_TYPE_NUM];	//任务奖励的物品数量
	INT16					rew_item_quality[QUEST_REW_ITEM*X_ClASS_TYPE_NUM];		//任务奖励的物品品级
	EClassType				rew_item_classtype[QUEST_REW_ITEM*X_ClASS_TYPE_NUM];	//奖励物品的职业
	//gx add 2013.6.3 用于区分任务奖励的玩家的性别
	BYTE					rew_item_rolesex[QUEST_REW_ITEM*X_ClASS_TYPE_NUM];	//奖励物品的玩家性别
	//end
	BOOL					rew_item_bind[QUEST_REW_ITEM*X_ClASS_TYPE_NUM]; // 物品绑定
	DWORD					rew_choice_item[QUEST_REW_ITEM*X_ClASS_TYPE_NUM];		//任务奖励的可选物品ID
	INT16					rew_choice_item_num[QUEST_REW_ITEM*X_ClASS_TYPE_NUM];	//任务奖励的可选物品数量
	INT16					rew_choice_quality[QUEST_REW_ITEM*X_ClASS_TYPE_NUM];	//任务奖励的可选物品品级
	EClassType				rew_choice_classtype[QUEST_REW_ITEM*X_ClASS_TYPE_NUM];	//奖励物品的职业
	BOOL					rew_choice_bind[QUEST_REW_ITEM*X_ClASS_TYPE_NUM]; // 物品绑定

	INT16					rew_att[QUEST_ATTS_COUNT];						//任务奖励的属性
	INT32					rew_att_val[QUEST_ATTS_COUNT];					//任务奖励的属性值
	DWORD					rew_skill[QUEST_SKILLS_COUNT];					//任务奖励的技能
	INT32					rew_skill_val[QUEST_SKILLS_COUNT];				//任务奖励的技能值
	DWORD					rew_buff[QUEST_REW_BUFF];						//任务奖励的buff

	//任务脚本指针
	mutable quest_script* 	quest_script; 									//任务脚本
	DWORD					quest_flags;									//任务标识,杀怪,收集物品等等
	DWORD					quest_entrance_id;					//任务接引人id
	DWORD					quest_title_color;						//任务标题颜色
public://增加一些接口
	INT16 GetChoiceIndex( EClassType eClass, INT nChoiceItemIndex ) const
	{
		INT16 n16Idx = -1;
		for( size_t n = 0; n < QUEST_REW_ITEM*X_ClASS_TYPE_NUM; ++n )
		{
			if( !rew_choice_item[n] ) break;
			if( rew_choice_classtype[n] == 0 || rew_choice_classtype[n] == eClass ) ++n16Idx;
			if( n16Idx == nChoiceItemIndex ) break;
		}
		return n16Idx;
	}

	BOOL is_dynamic( ) const { return EQTM_DYNAMIC == target_mode; }
};

#define macroIsXSQuest(pProto)			((pProto)->xuanshang_flag)
#define macroIsLoopQuest(pProto)		((pProto)->loop_rand_quest_flag)
#define macroIsTeamShareRand(pProto)	((pProto)->team_rand_share)


//--------------------------------------------------------------------------------
// 任务传送客户端的消息结构
//--------------------------------------------------------------------------------
struct tagCompleteQuestMsgInfo
{
	UINT16	u16QuestID;								// 任务ID
	DWORD	dwStartTime;							// 记录任务中接受第一个任务的时间
	INT		nTimes;									// 一个时期内完成的任务次数
};

struct tagIncompleteQuestMsgInfo
{
	UINT16	u16QuestID;								// 任务ID
	DWORD	dwAcceptTime;							// 接收任务的时间
	DWORD	dwQuestFlag;
	INT16	n16CreatureNum[QUEST_CREATURES_COUNT];	// 杀怪数量
	INT16	n16ItemNum[QUEST_ITEMS_COUNT];			// 物品数量
	tagQuestDynamicTarget	DynamicTarget;			// 动态目标任务才会发给客户端
	tagQuestDynamicReward	DynamicReward;			// 动态任务奖励
	tagScriptQuestVar		ScriptQuestVar;			//脚本设置数据
};


#pragma pack(pop)

