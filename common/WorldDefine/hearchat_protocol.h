/*******************************************************************************

	Copyright 2010 by Shengshi Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	Shengshi Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	Shengshi Interactive  Co., Ltd.

*******************************************************************************/

/**
 *	@file		hearchat_protocol
 *	@author		mwh
 *	@date		2011/05/23	initial
 *	@version	0.0.1.0
 *	@brief		传闻频道处理
*/

#define  ROLE_COMEBACK_HEARSAY_TIME_SEC (30 * 24 * 3600)

enum EHearSayType
{
	EHST_START = 0,
	//! dwParam0：typeid 
	//! dwParam1：0,史诗 1，传说
	//! 装备鉴定信息
	EHST_EQUIPUPGRADE = 0, // 鉴定 gx modify 2013.7.20
	
	//! dwroleid:男方ID
	//! dwParam0：女方ID 
	//! 结婚传闻
	EHST_MARRAIAGE = 1, // 结婚 gx modify 2013.7.20

	//! dwParam0：typeid
	//! 携带装备信息
	EHST_EQUIPPRODUCE = 2, // 装备打造

	//! dwParam0：typeid 
	//! dwParam1：获得物品个数
	EHST_EQUIPCOMPOSE = 3, // 装备拆分

	//! dwParam0：玩家坐骑当前阶数
	//! gx modify 2013.11.11
	EHST_RIDEUPGRADE = 4, // 坐骑升级全服公告
	
	//! dwParam0：PK值
	EHST_PKVALUE = 5,				// PK变化

	//! dwParam0：追杀目标ID
	//! dwParam1：追杀令TYPEID
	EHST_USEKILLBAGAGE = 6, // 使用追杀令

	//! dwParam0：紫装TPYEID
	//! dwParam1：BOSSID
	//! 携带装备信息<根据dwParam0决定>
	EHST_KILLBOSSGETITEM = 7, // 杀BOSS得紫装

	//! dwParam0:装备ID
	//! dwParam1:强化等级
	EHST_EQUIPSTRENGTH = 8,			// 装备强化 gx modify 2013.7.20

	EHST_CREATEGUILD	=		9,		// 创建帮会

	//! dwParam0：宝箱typeid
	//! dwParam1：元宝数量
	EHST_BAOXIANGYUANBAO	=	10,		// 宝箱获得元宝

	//! dwParam0：guildid
	//! dwParam1：类型 0 期间 1 结束
	//! p_buffer: 帮会名称
	EHST_GUILDFIRSTKILL		=	11,		//攻城战占领沙巴克

	//! dwParam0: Last Login Time
	EHST_ROLEBACK30DAYS		=	12,		// 30天重回游戏的传闻

	//! dwParam0：x
	//! dwParam1：y
	//! dwParam2：z
	//! dwParam3: mapid
	EHST_PURPUREPOS = 13,			// 紫名位置

	//! dwParam0：roleid
	EHST_PURPUREBEKILLED = 14,			// 紫名被杀

	//! dwParam0 活动ID
	//! 活动状态 : 1:开始;0：结束
	EHST_ACTIVITY = 15, 

	//! dwParam0：stringMsg.xml 中的id
	EHST_activity			=	16,		// 活动全服公告

	//! dwParam0：mapid	
	//! dwParam1:1代表蛋糕
	EHST_USE_ITEM		=	17,		// 使用蛋糕等特效物品 gx modify 2013.8.23


	//! dwParam0:称号索引
	//!
	EHST_TITLE_NOTICE =	18,		//称号头衔 gx modify 2013.7.20

	
	//! dwParam0：物品id
	//! dwParam1：奖励种类  0：一等将 1：二等将
	//! dwParam2：类型	   0:a      1:b
	EHST_Lottery			=	19,		// 彩票机结果

	//! dwParam0:2，银贵；3，白金；4，至尊
	//!  dwParam1:道具ID
	EHST_BAOXIANGITEM = 20,//gx modify 2013.8.15 VIP 全服公告

	//!  dwParam0:道具ID
	//!  dwParam1:消费累计金额
	EHST_ConsumeRewardItem = 21,

	//!  dwParam0:融合前品质
	//!  dwParam1:1 成功 0 失败
	EHST_Ronghe_pet = 22,
	
	//!  dwParam0:deadId
	EHST_GuildMap_Kill = 23,
	
	//gx modify 2013.6.27
	//!  dwParam0:收礼者roleID
	EHST_LianHuen = 24,		//增加魅力值
	//end

	//gx add 2013.10.29
	//!  dwParam0:itemtypeid
	EHST_SPECIAL_ITEM_USED = 25,//特殊物品使用全服公告，此类公告必要统一参数形式

	//!  dwParam0:获胜roleID
	EHST_ACTIVITY_BIWU_WIN = 26,//比武竞技场获胜公告

	EHST_MAX
};

struct HearSayChannel 
{
	//! 消息源
	DWORD dwRoleID;

	//! 参考上面注解分析
	DWORD dwParam0;
	DWORD dwParam1;
	DWORD dwParam2;
	DWORD dwParam3;

	//! 只在聊天频道显示
	BOOL bChatChannel;

	//! 消息类型
	EHearSayType eType;
};

// 传闻频道消息
struct NET_SIS_HearSayChannel : public tag_net_message
{
	NET_SIS_HearSayChannel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_HearSayChannel");
		dw_size = sizeof(*this);
	}
	HearSayChannel stData;
	CHAR cBuffer[1]; // 所需要的装备信息
};