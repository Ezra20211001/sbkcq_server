/*******************************************************************************

 Copyright 2010 by tiankong Interactive Game Co., Ltd.
 All rights reserved.
 
 This software is the confidential and proprietary information of
 tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
 not disclose such Confidential Information and shall use it only in
 accordance with the terms of the license agreement you entered into with
 tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef __GUERDON_QUEST_DEFINE_H__
#define __GUERDON_QUEST_DEFINE_H__

#pragma pack(push,1)

#define MAXPUTOUTQUESTHOUR  24     // 任务最长时间
#define TAKEQUESTFOREGIFTSILVER  (GOLD2SILVER*20)	// 接取时的押金20金
#define HANDLINGCHARGESILVER (SILVER2COPPER*5)		// 接取时手续费5银
#define PUTOUTSHANDLECHARGE	 (SILVER2COPPER*20)		// 发布手续费20银
#define MAXGDQUEST 5        // 最大悬赏任务数
#define TAKEQUESTCOSTVIGOUR 5      // 接取扣除元气值 
#define TAKEGDQUESTMINLEVEL 25  // 接取悬赏任务的最小等级

struct tagItem;

enum EGuerdonQuestState
{
 EGQS_WaitForInit = 0,
 EGQS_WaitForTake,
 EGQS_WaitForFinish,
};

// 服务-数据库
struct guerdon_quest
{
 // 64位ID
 INT64 n64Serial;
 // 任务ID
 UINT16 u16QuestID;
 // 发布者RoleID
 DWORD dwSender;
 // 接单者RoleID
 DWORD dwReciver;
 // 仅限本帮会
 BOOL  bGuildFix;
 // 过期时间
 DWORD dwEndTime;
 // 状态
 EGuerdonQuestState eState;
 // 元宝
 INT16 u16YuanBao;
// 奖品信息<只对Mgr有用>
 // 奖励1
 tagItem* pItem0;
 // 奖励2
 tagItem* pItem1;
public:
 guerdon_quest(){ZeroMemory(this,sizeof(*this));}
public:
 static INT64 MakeSerial(DWORD dwSender, UINT u16QuestID){ return (INT64)((INT64)dwSender << 32 | u16QuestID);}
 INT64 GetSerial() const { return n64Serial;}
 BOOL Assert() const {return ((n64Serial >> 32) == dwSender) && ((UINT16)n64Serial == u16QuestID);}
};

// 服务器-客户端
struct guerdon_quest_data
{
 // 64位ID
 INT64 n64Serial;
 // 任务ID
 UINT16 u16QuestID;
 // 发布者RoleID
 DWORD dwSender;
 // 接单者RoleID
 DWORD dwReciver;
 // 仅限本帮会
 BOOL  bGuildFix;
 // 元宝
 INT16 u16YuanBao;
 // 过期时间
 DWORD dwEndTime;
 // 奖励1<TypeID>
 DWORD dwItem0;
 INT16 n16Number0;
 // 奖励2<TypeID>
 DWORD dwItem1;
 INT16 n16Number1;
};

// 悬赏任务奖励物品检查
inline BOOL GDQuestRewardCheck(DWORD dw_data_id)
{
	 switch (dw_data_id)
	 {
		 case 4132001: // 解灵石碎片
		 case 4132002: // 解灵石
		 case 3320001: // 鱼竿
		 case 3320002: // 扁竹鱼竿
		 case 5400001: // 珍味果
		 case 5400002: // 野菜根块
		 case 5400003: // 美味素餐
		 case 5400004: // 渭河蟹
		 case 5400005: // 神秘丸子
		 case 5400006: // 胡羹
		 case 5400007: // 宫廷宠物粮
		 case 4150001: // 融合丹
		 case 4140004: // 洗灵水
		 case 2300201: // 1阶修炼丹
		 case 2300202: // 2阶修炼丹
		 case 2300203: // 3阶修炼丹
		 case 2300204: // 4阶修炼丹
		 case 2300205: // 5阶修炼丹
		 case 2300206: // 6阶修炼丹
		 case 2300207: // 7阶修炼丹
		 case 2300208: // 8阶修炼丹
		 case 2400015: // 1阶双倍经验丹
		 case 2400016: // 2阶双倍经验丹
		 case 2400017: // 3阶双倍经验丹
		 case 2400018: // 4阶双倍经验丹
		 case 5300007: // 宠物结晶
			return TRUE;
	 }
	 return FALSE;
}

#pragma pack(pop)


#endif //__GUERDON_QUEST_DEFINE_H__