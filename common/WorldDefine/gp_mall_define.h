/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

// gp商城
#pragma once

#pragma pack(push, 1)


// 彩票所需gp
#define NEED_GP 60

#define NEED_SILVER 300000

// 彩票a所需道具
#define TPYE_A_NEED_ITEM 1300045

// 彩票b所需道具(该道具对应“命运之星”的ID)
#define TPYE_B_NEED_ITEM 1400058//待改 gx modify 2013.6.3
//抽奖所需的非绑定的元宝数 
#define NEED_NONBINDYB 10
//gx add 2013.6.3
//
//end
//彩票机奖品
struct tagLotteryProto
{
	DWORD dwID;		
	DWORD dwItemID;		//物品id
	DWORD dwNumber;		//数量
	BYTE  byType;		//0:a型 1：b型
	BYTE  b_prize;		//是否头奖
	BYTE  b_bind;		//是否绑定
	BYTE  b_ItemNum;	//该奖品的数量 gx add 2013.6.26
};


// 头奖获得者
struct tagPrizeRole
{
	DWORD dwRoleID;
	DWORD dwTime;
	TCHAR szRoleName[X_SHORT_NAME];
};

#pragma pack(pop)