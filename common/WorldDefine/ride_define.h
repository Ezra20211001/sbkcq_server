/*******************************************************************************

	Copyright 2010 by tiankong Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef __RIDE_DEFINE_H__
#define __RIDE_DEFINE_H__

#pragma pack(push,1)
/**
 *	@file		ride_define
 *	@author		mawenhong
 *	@date		2010/11/16	initial
 *	@version	0.0.1.0
 *	@brief		
*/


#define  MAX_RIDEHOLE_NUM			4	//坐骑装备最大空数
#define  MAX_RIDE_CONSOLIDATE_LEVEL	10	//坐骑升星最大等级
#define  MIN_BROAD_RIDE_LEVEL		4	//坐骑强化到这个等级需要广播
#define	 CONSOLIDATE_COST			1	//升级基本花销
#define	 MAX_GODSTONE_NUM			10
#define  MAX_GODSTONE_NUM_MAX		10

struct tagRideUpgrade
{
	BYTE	byFailedTo;
	DWORD	dwProbability;
	DWORD	dwIncSpeed;
};

const static tagRideUpgrade g_RideUpg[MAX_RIDE_CONSOLIDATE_LEVEL+1]=
{
	{0, 10000, 500},//0-1
	{0, 10000, 1000},//1-2
	{0, 10000, 1500},//2-3
	{1, 8000, 2000},//3-4
	{2, 6000, 2500},//4-5
	{3, 4000, 3000},//5-6
	{0, 2000, 3500},//6-7
	{0, 1000, 4000},//7-8
	{0, 1000, 4500},//8-9
	{0, 1000, 5000},//9-10
	{0, 1000, 5000}//10-10
};

#define RideGodStoneProbCalc(Number) ((28 * (Number) - (Number) * (Number) + 20) * 10)
#define RideUpgradeProbCalc(CurLevel,Number) (g_RideUpg[(CurLevel)]+RideGodStoneProbCalc(Number))

#pragma  pack(pop)
#endif //__RIDE_DEFINE_H__