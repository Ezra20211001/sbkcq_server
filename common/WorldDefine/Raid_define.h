#pragma once

// 阶
const INT MIN_RAID_STEP	= 0;								// 坐骑最小阶
const INT MAX_RAID_STEP	= 12;								// 坐骑最大阶
const INT NUM_RAID_STEP	= MAX_RAID_STEP - MIN_RAID_STEP + 1;	// 坐骑阶数
#define IS_RAID_STEP(nlvl)	((nlvl) >= MIN_RAID_STEP && (nLvl) <= MAX_RAID_STEP)

// 等
const INT MIN_RAID_GRADE	= 1;								// 坐骑最小等
const INT MAX_RAID_GRADE	= 10;								// 坐骑最大等
const INT NUM_RAID_GRADE	= MAX_RAID_GRADE - MIN_RAID_GRADE + 1;// 坐骑等数
#define IS_RAID_GRADE(nlvl)	((nlvl) >= MIN_RAID_GRADE && (nLvl) <= MAX_RAID_GRADE)

// 虚拟等级
const INT MIN_RAID_VLEVEL	= 1;
const INT MAX_RAID_VLEVEL	= 120;
const INT NUM_RAID_VLEVEL	= MAX_RAID_VLEVEL - MIN_RAID_VLEVEL + 1;// 虚拟等级
#define IS_RAID_VLEVEL(nlvl)	((nlvl) >= MIN_RAID_VLEVEL && (nLvl) <= MAX_RAID_VLEVEL)


#define MMID(val, min, max)		((val) = ((val) > (max)) ? (max) : (((val) < (min)) ? (min) : val))
// 虚拟等级到阶等的转换
inline VOID VLevel2StepGrade( INT nVLevel, INT &nStep, INT &nGrade )
{
	MMID(nVLevel, MIN_RAID_VLEVEL, MAX_RAID_VLEVEL);
	nVLevel -= 1;
	nStep	= nVLevel / NUM_RAID_GRADE;
	nGrade	= nVLevel % NUM_RAID_GRADE + 1;
}
// 阶等到虚拟等级的转换
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


#define MAX_RAID_ATT_NUM 10		// 坐骑属性数量
#define MOUNTS_NEED_LEVEL 50	// 坐骑所需等级
#define MAX_DAY_TOG_TIME 30		// 每天培养次数
#pragma pack(push,1)


// 坐骑静态属性
struct tagRaidProto
{
	DWORD dwTypeID;
	DWORD dwNeedExp;
	DWORD dwModleID;
	INT32 nRating;
	tagRoleAttEffect	sRoleAtt[MAX_RAID_ATT_NUM]; //角色属性
};

// 坐骑存储结构
struct s_mounts_save
{
	INT nStep;		//阶
	INT nGrade;		//等
	INT nExp;		//经验
};


#pragma  pack(pop)