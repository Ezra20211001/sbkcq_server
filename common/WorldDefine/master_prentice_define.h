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
#define MASTER_MIN_LEVEL	60//��ʦ�ȼ�Ҳ�ǿ�����ͽ����͵ȼ�
#define PRENTICE_MIN_LEVEL	10//��ʦ��͵ȼ�
#define PRENTICE_MAX_LEVEL  60//��ʦ��ߵȼ�

#define FUK_PRENTIC_CHECK_MAX 49
#define MASTERPRENTICEFORBIDTIME 86400 //ʦͽ����������ϵ�����ȴʱ�䡣24Сʱ,�������
#define MASTERPRENTICEBREAKCOST	(10)

#define MAX_PRENTICE		5//һ��ʦ��ͬʱ����յ�ͽ����

#define CALLINMASTERITEMTYPE 2400014 //���������

#pragma pack(push,1)

//�����Ӧ
enum 
{
	EMASTER_REFUSE = 0,//�ܾ�
	EMASTER_ACCEPT = 1,//����
};

//ʦͽ����ʾ��־
enum
{
	EMASTER_HIDE  = 0, //����
	EMASTER_SHOW	= 1, //��ʾ
};

//����
enum eMPMemberType
{
	EMPMT_PRENTICE = 0,
	EMPMT_MASTER   = 1,
	EMPMT_BROTHER = 2,
};

//ʦ�������ȼ�
enum EMasterReputation
{
	EMREP_NULL	 = 0, //��	
	EMREP_MENTOR = 1, //��ʦ����
	EMREP_TALENT = 2, //�²ż汸(��ʦͽ�������ﵽ1��)
	EMREP_ABROAD = 3, //��������(��ʦͽ�������ﵽ3��)
	EMREP_LOFTY	 = 4, //һ��֮ʦ(��ʦͽ�������ﵽ5��)
	EMREP_SAINT	 = 5, //��ʥ��ʦ(��ʦͽ�������ﵽ8��)
	EMREP_END
};

//������ͻ��˽���
struct tagMPMember
{
	DWORD	dw_role_id;
	BYTE	byLevel;
	bool	bOnline;
	EClassType eClass;	 
	BYTE	bySex;//gx add
	eMPMemberType eMemberType;
};

//ʦͽ������(�����������ͻ���)
struct tagMasterPalcardSim
{
	DWORD dwMaster;
	DWORD dwGraduates;
	bool bOnline;
	BYTE byLevel;
	EMasterReputation eReputation;
	EClassType eClassType;
};

// ��ʦ�����
struct tagMasterRecruitSim
{
	INT nLevel;
	BOOL bOnline;
	DWORD dwRoleID;
	EClassType eClassType;
};


//ʦ�����ʦͽ������ӳ��
const static UINT32 g_ReputationOfGraduates[EMREP_END] = {0,0,1,3,5,8};
//ʦ�������ͽ������ӳ��
const static UINT32 g_PrenticeMaxNumber[EMREP_END] = {0,1,2,3,4,5};

//��ʦ����->ʦ������
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