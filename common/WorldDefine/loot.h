//-----------------------------------------------------------------------------
//��Name				:   loot.h
//��Compiler			:	Microsoft Visual C++ 9.0Aslan
//��Version				:	1.00
//��Create Date			:	2008-08-10
//��LastModified		:	2008-10-22
//��Brief				:	���侲̬����
//-----------------------------------------------------------------------------
#pragma once
#include "ItemDefine.h"
//------------------------------------------------------------------------
// �����������
//------------------------------------------------------------------------
enum ELootOpType
{
	ELOT_Common		= 0,	// ��ͨ���䣨������
	ELOT_OnlyOne	= 1,	// ��һ���䣨һ����
};

//------------------------------------------------------------------------
// ����ģʽ
//------------------------------------------------------------------------
enum ELootMode
{
	ELM_LootToGround = 0,		// ʵ�����
	ELM_LootToBag    = 1,		// ֱ�ӻ��
};

//------------------------------------------------------------------------
// ��������
//------------------------------------------------------------------------
enum ELootType
{
	ELT_Item = 0,		// ��Ʒ
	ELT_Set  = 1,		// ����
};

//------------------------------------------------------------------------
// ʰȡ��Χ
//------------------------------------------------------------------------
const float X_DEF_PICKUP_DIST = 40.0f*100.0f;		// ʰȡ��Χ��40��
const float X_DEF_PICKUP_DIST_SQ = 25.0f*100.0f * 25.0f*100.0f;
const float X_DEF_AUTO_PICKUP_DIST = 20.0f*100.0f;	// �Զ�ʰȡ��Χ��20��

//------------------------------------------------------------------------
// ������Ʒ����
//------------------------------------------------------------------------
const INT MAX_ITEM_SET_NUM = 50;	// ��Ʒ�����д�����Ʒ����

struct tagItemSet
{
	DWORD dwItemID; 	//��ƷID
	INT   nItemNum;    //��Ʒ����
	FLOAT fChance;		// ����
	INT32 nEquipQltyPct[X_EQUIP_QUALITY_NUM];	// Ʒ�����ɼ���
};

struct tagLootItemSet
{
	DWORD  dwSetID;							//����id
	tagItemSet ItemSet[MAX_ITEM_SET_NUM];	//��Ʒ����
};

//------------------------------------------------------------------------
// ����������Ʒ
//------------------------------------------------------------------------
const INT MAX_LOOT_QUEST_ITEM_NUM = 10;	// ����������Ʒ����

struct tagQuestItem
{
	DWORD  dwQuestItemID;	//������ƷID
	FLOAT  fChance;			//������Ʒ����
	FLOAT  fTeamChance;		//С��������Ʒ����
};

struct tagLootQuestItem
{
	DWORD  dwCreatureID;								//����ID
	tagQuestItem QuestItem[MAX_LOOT_QUEST_ITEM_NUM];	//������Ʒ	
};

//-----------------------------------------------------------------------
// ����Ļ����ṹ�������ڹ�������Լ���Ʒ�ȵȵĵ��䷽ʽ
//-----------------------------------------------------------------------
struct tagLoot
{
	DWORD		dwItemID;		// ��ƷID�������������Ϊ���ϣ���Ϊ����ID��
	ELootType	eLootType;      // ��������
	INT			nMin;			// ��Ʒ����С����
	INT			nMax;			// ��Ʒ���������
	FLOAT		fChance;		// ���伸��
	INT32		nEquipQltyPct[X_EQUIP_QUALITY_NUM];	// Ʒ�����ɼ���
};

//------------------------------------------------------------------------
// �������ṹ
//------------------------------------------------------------------------
const INT MAX_CREATURE_LOOT_NUM = 30;	// �������������Ʒ����

struct tagCreatureLoot
{
	DWORD		dwLootID;						// ����ID
	ELootOpType		eOpType;						// ��������
	ELootMode	eLootMode;						// ����ģʽ
	INT			nMinMoney;						// ������С��Ǯ
	INT			nMaxMoney;						// ��������Ǯ
	INT			nMoneyNumMin;					// ������������С
	INT			nMoneyNumMax;					// �������������
	FLOAT		fMoneyChance;					// �����Ҽ���
	tagLoot		Loot[MAX_CREATURE_LOOT_NUM];	// �������Ʒ����
};
