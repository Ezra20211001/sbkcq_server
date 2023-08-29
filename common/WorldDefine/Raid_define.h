#pragma once

// ��
const INT MIN_RAID_STEP	= 0;								// ������С��
const INT MAX_RAID_STEP	= 12;								// ��������
const INT NUM_RAID_STEP	= MAX_RAID_STEP - MIN_RAID_STEP + 1;	// �������
#define IS_RAID_STEP(nlvl)	((nlvl) >= MIN_RAID_STEP && (nLvl) <= MAX_RAID_STEP)

// ��
const INT MIN_RAID_GRADE	= 1;								// ������С��
const INT MAX_RAID_GRADE	= 10;								// ��������
const INT NUM_RAID_GRADE	= MAX_RAID_GRADE - MIN_RAID_GRADE + 1;// �������
#define IS_RAID_GRADE(nlvl)	((nlvl) >= MIN_RAID_GRADE && (nLvl) <= MAX_RAID_GRADE)

// ����ȼ�
const INT MIN_RAID_VLEVEL	= 1;
const INT MAX_RAID_VLEVEL	= 120;
const INT NUM_RAID_VLEVEL	= MAX_RAID_VLEVEL - MIN_RAID_VLEVEL + 1;// ����ȼ�
#define IS_RAID_VLEVEL(nlvl)	((nlvl) >= MIN_RAID_VLEVEL && (nLvl) <= MAX_RAID_VLEVEL)


#define MMID(val, min, max)		((val) = ((val) > (max)) ? (max) : (((val) < (min)) ? (min) : val))
// ����ȼ����׵ȵ�ת��
inline VOID VLevel2StepGrade( INT nVLevel, INT &nStep, INT &nGrade )
{
	MMID(nVLevel, MIN_RAID_VLEVEL, MAX_RAID_VLEVEL);
	nVLevel -= 1;
	nStep	= nVLevel / NUM_RAID_GRADE;
	nGrade	= nVLevel % NUM_RAID_GRADE + 1;
}
// �׵ȵ�����ȼ���ת��
inline VOID StepGrade2VLevel( INT nStep, INT nGrade, INT &nVLevel )
{
	MMID(nStep, MIN_RAID_STEP, MAX_RAID_STEP);
	MMID(nGrade, MIN_RAID_GRADE, MAX_RAID_GRADE);
	nGrade	-= 1;
	nVLevel = nStep * NUM_RAID_GRADE + nGrade;
	nVLevel += 1;
}


#undef MMID


#include "ItemDefine.h"


#define MAX_RAID_ATT_NUM 10		// ������������
#define MOUNTS_NEED_LEVEL 50	// ��������ȼ�
#define MAX_DAY_TOG_TIME 30		// ÿ����������
#pragma pack(push,1)


// ���ﾲ̬����
struct tagRaidProto
{
	DWORD dwTypeID;
	DWORD dwNeedExp;
	DWORD dwModleID;
	INT32 nRating;
	tagRoleAttEffect	sRoleAtt[MAX_RAID_ATT_NUM]; //��ɫ����
};

// ����洢�ṹ
struct s_mounts_save
{
	INT nStep;		//��
	INT nGrade;		//��
	INT nExp;		//����
};


#pragma  pack(pop)