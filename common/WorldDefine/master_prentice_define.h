/*******************************************************************************

	Copyright 2010 by tiankong Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef __MASTER_PRENTICE_DEFINE_H__
#define __MASTER_PRENTICE_DEFINE_H__

#include "RoleDefine.h"

#define INVALID_MASTER		0
#define MASTER_MIN_LEVEL	60//出师等级也是可以收徒的最低等级
#define PRENTICE_MIN_LEVEL	10//拜师最低等级
#define PRENTICE_MAX_LEVEL  60//拜师最高等级

#define FUK_PRENTIC_CHECK_MAX 49
#define MASTERPRENTICEFORBIDTIME 86400 //师徒单方面解除关系后的冷却时间。24小时,换算成秒
#define MASTERPRENTICEBREAKCOST	(10)

#define MAX_PRENTICE		5//一个师傅同时最多收的徒弟数

#define CALLINMASTERITEMTYPE 2400014 //召请符类型

#pragma pack(push,1)

//请求回应
enum 
{
	EMASTER_REFUSE = 0,//拒绝
	EMASTER_ACCEPT = 1,//接受
};

//师徒榜显示标志
enum
{
	EMASTER_HIDE  = 0, //隐藏
	EMASTER_SHOW	= 1, //显示
};

//类型
enum eMPMemberType
{
	EMPMT_PRENTICE = 0,
	EMPMT_MASTER   = 1,
	EMPMT_BROTHER = 2,
};

//师德声望等级
enum EMasterReputation
{
	EMREP_NULL	 = 0, //无	
	EMREP_MENTOR = 1, //良师益友
	EMREP_TALENT = 2, //德才兼备(出师徒弟数量达到1个)
	EMREP_ABROAD = 3, //桃李满门(出师徒弟数量达到3个)
	EMREP_LOFTY	 = 4, //一字之师(出师徒弟数量达到5个)
	EMREP_SAINT	 = 5, //先圣先师(出师徒弟数量达到8个)
	EMREP_END
};

//用于向客户端交流
struct tagMPMember
{
	DWORD	dw_role_id;
	BYTE	byLevel;
	bool	bOnline;
	EClassType eClass;	 
	BYTE	bySex;//gx add
	eMPMemberType eMemberType;
};

//师徒榜数据(服务器发给客户端)
struct tagMasterPalcardSim
{
	DWORD dwMaster;
	DWORD dwGraduates;
	bool bOnline;
	BYTE byLevel;
	EMasterReputation eReputation;
	EClassType eClassType;
};

// 拜师帮简易
struct tagMasterRecruitSim
{
	INT nLevel;
	BOOL bOnline;
	DWORD dwRoleID;
	EClassType eClassType;
};


//师德与出师徒弟数量映射
const static UINT32 g_ReputationOfGraduates[EMREP_END] = {0,0,1,3,5,8};
//师德与可收徒弟数量映射
const static UINT32 g_PrenticeMaxNumber[EMREP_END] = {0,1,2,3,4,5};

//出师人数->师德声望
#define GetReputionOfGraduates( Graduate, out_Rep )\
do{\
	(out_Rep)=EMREP_MENTOR;\
	for(INT32 n=EMREP_END-1; n>=EMREP_MENTOR&&(Graduate); --n){\
		if(g_ReputationOfGraduates[n]<=(Graduate)){\
			(out_Rep)=(EMasterReputation)n; break;\
		}\
	}\
}while(FALSE)



#pragma pack(pop)



#endif //__MASTER_PRENTICE_DEFINE_H__