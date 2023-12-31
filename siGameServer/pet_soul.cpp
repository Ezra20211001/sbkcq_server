/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//宠物实体

#include "StdAfx.h"
#include "pet_soul.h"

#include "../common/ServerDefine/log_server_define.h"
#include "../common/ServerDefine/pet_server_define.h"
#include "pet_skill_server_define.h"

#include "../common/WorldDefine/pet_protocol.h"
#include "../common/WorldDefine/trigger_define.h"

#include "pet_server_define.h"
#include "role_mgr.h"
#include "db_session.h"
#include "pet_skill.h"
#include "role.h"
#include "pet_tracker.h"
#include "pet.h"
#include "pet_pocket.h"
#include "pet_sns_mgr.h"
//----------------------------------------------------------------------------------------------------
// 构造函数
//----------------------------------------------------------------------------------------------------
PetSoul::PetSoul()
	:m_PetAtt(this), m_EquipBar(this)
{
	m_dwWorkingSkillTypeID = INVALID_VALUE;
	m_pMaster		= NULL;
	m_pBody			= NULL;
	m_pHeti			= NULL;
	nCount = SPIRIT_RESUME_COUNT;
	//m_dwFriendID = INVALID_VALUE;
	//m_dwBeginTime = INVALID_VALUE;
}

//----------------------------------------------------------------------------------------------------
// 析构函数
//----------------------------------------------------------------------------------------------------
PetSoul::~PetSoul()
{
	m_pMaster		= NULL;
	m_pBody			= NULL;
	m_pHeti			= NULL;
	
	PetSkill* pSkill = NULL;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	while (m_mapPetSkill.find_next(itr, pSkill))
	{
		PetSkill::DeletePetSkill(pSkill);
	}

}

//----------------------------------------------------------------------------------------------------
// 数据库创建宠物灵魂
//----------------------------------------------------------------------------------------------------
VOID PetSoul::CreateDBSoul( DWORD dw_data_id,LPCTSTR tszName,Role* pMaster, INT nQualiry )
{
	NET_DB2C_create_pet_soul send;

	PetAtt::InitCreateAtt(&send.create_data, dw_data_id, pMaster->GetID(), tszName, nQualiry);
	
	g_dbSession.Send(&send, send.dw_size);
}

//----------------------------------------------------------------------------------------------------
// 删除宠物灵魂
//----------------------------------------------------------------------------------------------------
VOID PetSoul::DeleteSoul( PetSoul* pSoul, BOOL bFromDB /*= FALSE*/ )
{
	if (bFromDB)
	{
		// 从数据库删除
		NET_DB2C_delete_pet_soul send;
		send.n_pet_soul_num = 1;
		send.dw_pet_id[0] = pSoul->GetID();
		g_dbSession.Send(&send, send.dw_size);
	}

	SAFE_DELETE(pSoul);
}

//----------------------------------------------------------------------------------------------------
// 获取技能
//----------------------------------------------------------------------------------------------------
PetSkill* PetSoul::GetSkill( DWORD dwPetSkillID )
{
	return m_mapPetSkill.find(dwPetSkillID);
}

//----------------------------------------------------------------------------------------------------
// 技能书学习技能
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::LearnBookSkill( INT64 n64ItemID )
{
	// 宠物状态是否满足
	if (!IsCalled())
	{
		return E_Pets_Pet_NotCalled;
	}

	if (IsWorking())
	{
		return E_Pets_PetSkill_Learn_StateLimit;
	}

	// 技能书是否满足
	tagItem *pItem = m_pMaster->GetItemMgr().GetBagItem(n64ItemID);
	if(!VALID_POINT(pItem) || pItem->pProtoType->eSpecFunc != EISF_PetSkillBook)
	{
		return E_Pets_PetSkill_Learn_ItemInvalid;
	}

	// 技能原型
	DWORD dwPetSkillTypeID	= pItem->pProtoType->nSpecFuncVal1;
	DWORD dwPetSkillID		= MTransPetSkillID(dwPetSkillTypeID);
	DWORD dwPetSkillLvl		= MTransPetSkillLevel(dwPetSkillTypeID);
	const tagPetSkillProto* pSkillProto = AttRes::GetInstance()->GetPetSkillProto(dwPetSkillTypeID);
	if (!VALID_POINT(pSkillProto))
	{
		return E_Pets_PetSkill_InvalidSkillID;
	}

	// 技能书等级
	//if (pSkillProto->nPetLvlLim > GetProto()->nRoleLvlLim)
	//{
	//	return E_Pets_PetSkill_Learn_PetLvlLimit;
	//}

	//if (GetPetAtt().GetStep() < pSkillProto->nLearn_step|| GetPetAtt().GetGrade() < pSkillProto->nLearn_grade)
	if (GetPetAtt().GetVLevel() < pSkillProto->nLearn_Level)
	{
		return E_Pets_PetSkill_Learn_PetLvlLimit;
	}
	

	// 技能等级是否满足
	PetSkill* pSkill = GetSkill(dwPetSkillID);
	if (VALID_POINT(pSkill))
	{
		DWORD dwExistPetSkillLvl = MTransPetSkillLevel(pSkill->GetSkillTypeID());

		if (dwPetSkillLvl - dwExistPetSkillLvl > 1)
		{
			return E_Pets_PetSkill_Learn_HasHighLvlSkill;
		}

		// 技能已学会
		if (HasSkill(MTransPetSkillID(dwPetSkillTypeID)) && dwPetSkillLvl == dwExistPetSkillLvl)
		{
			return E_Pets_PetSkill_Learn_Has_Skill;		

		}

	}
	else 
	{
		if (dwPetSkillLvl > 1)
			return E_Pets_PetSkill_Learn_HasHighLvlSkill;

		// 数量已满
		if ( pSkillProto->eType ==EPT_Specialty)
		{
			// 被动融合技能只能有一个
			if (!HasActiveSkill() && GetSkillNum(EPT_Specialty) >= 1 && pSkillProto->eType2 != EPT2_Active)
			{
				return E_Pets_PetSkill_Learn_MaxLeanNum;
			}
			if (GetSkillNum(EPT_Specialty) >= MAX_PET_NORMAL_SKILL_NUM)
			{
				return E_Pets_PetSkill_Learn_MaxLeanNum;
			}
			
		}

		if (pSkillProto->eType ==EPT_Strengthen && GetSkillNum(EPT_Strengthen) >= MAX_PET_BEIDONG_SKILL_NUM)
		{
			return E_Pets_PetSkill_Learn_MaxLeanNum;
		}

		// 已经有主动技能了
		if (HasActiveSkill() && pSkillProto->eType2 == EPT2_Active && !HasSkill(MTransPetSkillID(dwPetSkillTypeID)))
		{
			return E_Pets_PetSkill_Learn_Has_Active;
		}

	}

	// 潜能值不够
	//if (GetPetAtt().GetAttVal(EPA_Potential) < pSkillProto->nLearn_PontentialCost)
	//{
	//	return E_Pets_PetSkill_Learn_PotentialNotEnough;
	//}

	
	// 学习宠物技能
	DWORD dw_error_code = LearnSkill(dwPetSkillTypeID);
	if (E_Pets_Success == dw_error_code)
	{

		m_pMaster->GetAchievementMgr().UpdateAchievementCriteria(ete_use_item, pItem->pProtoType->dw_data_id, 1);

		// 扣除物品
		dw_error_code = m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, (INT16)1, (DWORD)elcid_pet_item_pet_learnskill);
				
		// 扣除潜力值
		//GetPetAtt().ModAttVal(EPA_Potential, -pSkillProto->nLearn_PontentialCost);
	}

	return dw_error_code;
}

DWORD PetSoul::SkillLevelUp(DWORD dwID)
{
	// 宠物状态是否满足
	if (!IsCalled())
	{
		return E_Pets_Pet_NotCalled;
	}

	if (IsWorking())
	{
		return E_Pets_PetSkill_Learn_StateLimit;
	}

	PetSkill* pSkill = GetSkill(dwID);
	if (!VALID_POINT(pSkill))
		return E_Pets_PetSkill_Learn_NOT_SKILL;


	// 技能原型
	DWORD dwPetSkillTypeID	= pSkill->GetSkillTypeID()+1;
	DWORD dwPetSkillID		= dwID;
	DWORD dwPetSkillLvl		= MTransPetSkillLevel(dwPetSkillTypeID);
	const tagPetSkillProto* pSkillProto = AttRes::GetInstance()->GetPetSkillProto(dwPetSkillTypeID);
	if (!VALID_POINT(pSkillProto))
	{
		return E_Pets_PetSkill_InvalidSkillID;
	}


	if (GetPetAtt().GetVLevel() < pSkillProto->nLearn_Level)
	{
		return E_Pets_PetSkill_Learn_PetLvlLimit;
	}


	// 技能等级是否满足
	//if (VALID_POINT(pSkill))
	//{
	//	DWORD dwExistPetSkillLvl = MTransPetSkillLevel(pSkill->GetSkillTypeID());

	//	if (dwPetSkillLvl - dwExistPetSkillLvl > 1)
	//	{
	//		return E_Pets_PetSkill_Learn_HasHighLvlSkill;
	//	}

	//	// 技能已学会
	//	if (HasSkill(MTransPetSkillID(dwPetSkillTypeID)) && dwPetSkillLvl == dwExistPetSkillLvl)
	//	{
	//		return E_Pets_PetSkill_Learn_Has_Skill;		

	//	}

	//}


	// 学习宠物技能
	DWORD dw_error_code = LearnSkill(dwPetSkillTypeID);

	return dw_error_code;
}

//----------------------------------------------------------------------------------------------------
// 升级学习技能
//----------------------------------------------------------------------------------------------------
VOID PetSoul::LearnNormalSkill( INT nLevel , INT nQuality)
{
	if (nLevel < 0 || nLevel > 90)
	{
		return;
	}
	if (nQuality < 0 || nQuality > 4)
	{
		return;
	}

	// 宠物状态是否满足
	if (IsWorking())
	{
		return;
	}
	
	std::vector<DWORD> vecLearnSkill;
	std::vector<DWORD> vecNeedDeleteSkill;

	// 常被技能升级
	PetSkill* pSkill = NULL;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	while (m_mapPetSkill.find_next(itr, pSkill))
	{
		if (pSkill->GetProto()->eType == EPT_Strengthen)
		{
			DWORD dwSkillTypeID = pSkill->GetSkillTypeID()/100000*100000 + 1000 + nQuality * 100 + nLevel;
			const tagPetSkillProto* pSkillProto = AttRes::GetInstance()->GetPetSkillProto(dwSkillTypeID);
			
			if (!VALID_POINT(pSkillProto) || GetPetAtt().GetVLevel() < pSkillProto->nLearn_Level )
				continue;
			
			if (MTransPetSkillID(dwSkillTypeID) != MTransPetSkillID(pSkill->GetProto()->dw_data_id))
			{
				vecNeedDeleteSkill.push_back(MTransPetSkillID(pSkill->GetProto()->dw_data_id));
			}

			vecLearnSkill.push_back(dwSkillTypeID);
			//LearnSkill(dwSkillTypeID);
		}

		else if (pSkill->GetProto()->eType == EPT_Buff)
		{
			DWORD dwSkillTypeID = MTransPetSkillTypeID(pSkill->GetSkillTypeID()/100, nQuality+1);
			const tagPetSkillProto* pSkillProto = AttRes::GetInstance()->GetPetSkillProto(dwSkillTypeID);

			if (!VALID_POINT(pSkillProto))
				continue;

			vecLearnSkill.push_back(dwSkillTypeID);
			//LearnSkill(dwSkillTypeID);
		}

	}
	
	for (size_t i = 0; i < vecNeedDeleteSkill.size(); i++)
	{
		ForgetSkill(vecNeedDeleteSkill[i]);
	}


	for (size_t i = 0; i < vecLearnSkill.size(); i++)
	{
		LearnSkill(vecLearnSkill[i]);
	}

	//BOOL bHasNew = FALSE;
	//const std::list<DWORD> &normalSkills = AttRes::GetInstance()->GetPetNormalSkillList(nLevel);
	//
	//for (	std::list<DWORD>::const_iterator itr = normalSkills.begin(); 
	//		itr != normalSkills.end(); 
	//		++itr)
	//{
	//	DWORD dwSkillTypeID = *itr;

	//	const tagPetSkillProto* pSkillProto = AttRes::GetInstance()->GetPetSkillProto(dwSkillTypeID);

	//	if (!VALID_POINT(pSkillProto) 
	//		//||!pSkillProto->bLearn_condition 
	//		|| GetPetAtt().GetVLevel() != pSkillProto->nLearn_Level
	//		//|| GetPetAtt().GetGrade() != pSkillProto->nLearn_grade
	//		//|| GetPetAtt().GetStep() != pSkillProto->nLearn_step
	//		//|| pSkillProto->nPetLvlLim != GetProto()->nRoleLvlLim 
	//		//|| !IUTIL->Probability(pSkillProto->nLearn_prob/100)
	//		)
	//		continue;

	//	// 学习宠物技能
	//	if(E_Success == LearnSkill(dwSkillTypeID))
	//		bHasNew = TRUE;
	//	
	//}
	//	
	//return bHasNew ? E_Success : INVALID_VALUE;
}

//----------------------------------------------------------------------------------------------------
// 学习一个技能
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::AddSkill( PetSkill* pSkill )
{
	DWORD dwPetSkillTypeID	= pSkill->GetSkillTypeID();
	DWORD dwPetSkillID		= MTransPetSkillID(dwPetSkillTypeID);
 	DWORD dwPetSkillLvl		= MTransPetSkillLevel(dwPetSkillTypeID);

	// 添加映射
	if (VALID_VALUE(m_mapPetSkill.find(dwPetSkillID)))
	{
		return INVALID_VALUE;
	}
	m_mapPetSkill.add(dwPetSkillID, pSkill);

	if (VALID_POINT(GetMaster()) && IsCalled() && pSkill->GetProto()->eType != EPT_Specialty )
	{
		pSkill->Active(GetMaster());
		if (VALID_POINT(GetMaster()->GetScript()))
			GetMaster()->GetScript()->OnPetSkillChange(GetMaster(), pSkill->GetSkillTypeID(), TRUE);
	}
	
	//if (pSkill->GetProto()->eCastType == EPCT_Enhance)
	//{
	//	EnhanceSkill *pEnhanceSkill = (EnhanceSkill *)pSkill;
	//	pEnhanceSkill->Open();	
	//}


	return E_Pets_Success;
}

DWORD PetSoul::AddSkillOnLoad( PetSkill* pSkill )
{
	DWORD dwPetSkillTypeID		= pSkill->GetSkillTypeID();
	DWORD dwPetSkillID	= MTransPetSkillID(dwPetSkillTypeID);
	DWORD dwPetSkillLvl		= MTransPetSkillLevel(dwPetSkillTypeID);

	// 添加映射
	if (VALID_VALUE(m_mapPetSkill.find(dwPetSkillID)))
	{
		return INVALID_VALUE;
	}
	m_mapPetSkill.add(dwPetSkillID, pSkill);
	
	//if (pSkill->GetProto()->eCastType == EPCT_Enhance)
	//{
	//	EnhanceSkill *pEnhanceSkill = (EnhanceSkill *)pSkill;
	//	pEnhanceSkill->Open();	
	//}

	return E_Pets_Success;
}


//----------------------------------------------------------------------------------------------------
// 遗忘技能
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::ForgetSkill( DWORD dwPetSkillID, BOOL bFromeClient)
{
	if(IsWorking())
	{
		ASSERT(0);
		return INVALID_VALUE;
	}

	PetSkill* pSkill = m_mapPetSkill.find(dwPetSkillID);
	if (!VALID_POINT(pSkill))
	{
		return INVALID_VALUE;
	}
	
	if ( bFromeClient && pSkill->GetProto()->b_cantforget)
	{
		return E_Pets_PetSkill_Forget_cant;
	}

	DWORD dwPetSkillTypeID = pSkill->GetSkillTypeID();
	DWORD dwRtv = RemoveSkill(pSkill);
	if (E_Pets_Success != dwRtv)
	{
		ASSERT(0);
		return dwRtv;
	}

	PetSkill::DeletePetSkill(pSkill);

	if(VALID_POINT(GetMaster()))
	{
		NET_SIS_remove_pet_skill sendNS;
		sendNS.dwPetID			= GetID();
		sendNS.dwSkillID		= dwPetSkillTypeID;
		GetMaster()->SendMessage(&sendNS, sendNS.dw_size);
	}
	NET_DB2C_delete_pet_skill send;
	send.dw_pet_id_			= GetID();
	send.dw_pet_skill_type_id	= dwPetSkillTypeID;
	g_dbSession.Send(&send, send.dw_size);
	
	return E_Pets_Success;
}

//----------------------------------------------------------------------------------------------------
// 更新所有技能
//----------------------------------------------------------------------------------------------------
VOID PetSoul::UpdateAllSkill()
{
	PetSkill* pPetSkill = NULL;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	//for all PetSkill 
	while (	m_mapPetSkill.find_next(itr, pPetSkill))
	{
		//Update
		pPetSkill->Update();
	}
}
// 随机删除一个普通技能
VOID PetSoul::RandRemoveNoramlSkill()
{
	std::vector<DWORD> vec;
	PetSkill* pPetSkill = NULL;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	//for all PetSkill 
	while (	m_mapPetSkill.find_next(itr, pPetSkill))
	{
		if (pPetSkill->GetProto()->eType == EPT_Strengthen)
		{
			vec.push_back(pPetSkill->GetSkillTypeID());
		}
	}

	ForgetSkill(MTransPetSkillID(vec[get_tool()->tool_rand() % (vec.size())]));

}

// 得到合体技能的数量
DWORD PetSoul::GetSkillNum(EPetskillType type)
{
	DWORD num = 0;
	PetSkill* pPetSkill = NULL;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	//for all PetSkill 
	while (	m_mapPetSkill.find_next(itr, pPetSkill))
	{
		if (pPetSkill->GetProto()->eType == type)
		{
			num++;
		}
	}
	return num;
}

// 是否有主动技能
BOOL PetSoul::HasActiveSkill()
{
	DWORD num = 0;
	PetSkill* pPetSkill = NULL;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	//for all PetSkill 
	while (	m_mapPetSkill.find_next(itr, pPetSkill))
	{
		if (pPetSkill->GetProto()->eType2 == EPT2_Active)
		{
			return TRUE;
		}
	}
	return FALSE;
}

// 得到主动技能
DWORD PetSoul::GetActiveSkill()
{
	PetSkill* pPetSkill = NULL;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	//for all PetSkill 
	while (	m_mapPetSkill.find_next(itr, pPetSkill))
	{
		if (pPetSkill->GetProto()->eType2 == EPT2_Active)
		{
			return pPetSkill->GetProto()->dw_data_id;
		}
	}

	return INVALID_VALUE;
}

DWORD PetSoul::GetBuffSkill()
{
	PetSkill* pPetSkill = NULL;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	//for all PetSkill 
	while (	m_mapPetSkill.find_next(itr, pPetSkill))
	{
		if (pPetSkill->GetProto()->eType == EPT_Buff)
		{
			return pPetSkill->GetProto()->dw_data_id;
		}
	}

	return INVALID_VALUE;
}
// 是否有某个技能
BOOL PetSoul::HasSkill(DWORD dwSkillID)
{
	if (m_mapPetSkill.is_exist(dwSkillID) )
		return TRUE;

	return FALSE;
}
VOID PetSoul::RemoveNormalSkill()
{
	std::vector<DWORD> vec;
	PetSkill* pPetSkill = NULL;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	//for all PetSkill 
	while (	m_mapPetSkill.find_next(itr, pPetSkill))
	{
		if (pPetSkill->GetProto()->eType == EPT_Strengthen)
		{
			vec.push_back(pPetSkill->GetSkillTypeID());
		}
	}

	for (std::size_t i = 0; i < vec.size(); i++)
	{
		ForgetSkill(MTransPetSkillID(vec[i]));
	}
}

VOID PetSoul::RemoveBuffSkill()
{
	std::vector<DWORD> vec;
	PetSkill* pPetSkill = NULL;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	//for all PetSkill 
	while (	m_mapPetSkill.find_next(itr, pPetSkill))
	{
		if (pPetSkill->GetProto()->eType == EPT_Buff)
		{
			vec.push_back(pPetSkill->GetSkillTypeID());
		}
	}

	for (std::size_t i = 0; i < vec.size(); i++)
	{
		ForgetSkill(MTransPetSkillID(vec[i]));
	}
}

// 删除特长技能
VOID PetSoul::RemoveSpecialtySkill()
{
	std::vector<DWORD> vec;
	PetSkill* pPetSkill = NULL;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	//for all PetSkill 
	while (	m_mapPetSkill.find_next(itr, pPetSkill))
	{
		if (pPetSkill->GetProto()->eType == EPT_Specialty)
		{
			vec.push_back(pPetSkill->GetSkillTypeID());
		}
	}
	
	for (std::size_t i = 0; i < vec.size(); i++)
	{
		ForgetSkill(MTransPetSkillID(vec[i]));
	}
	
}
//----------------------------------------------------------------------------------------------------
// 获得id
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::GetID()const
{
	return	m_PetAtt.GetID();
}

//----------------------------------------------------------------------------------------------------
// 获得原型id
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::GetProtoID() const
{
	return m_PetAtt.GetProtoID();
}

//----------------------------------------------------------------------------------------------------
// 更新
//----------------------------------------------------------------------------------------------------
VOID PetSoul::Update()
{
	if (VALID_POINT(GetMaster()) )
	{
		EMoveState ems = GetMaster()->GetMoveData().GetCurMoveState();
		switch(ems)
		{
		case EMS_Stand:
		case EMS_Walk:
			if (!IsPetInMap())
			{
				BodyEnterMap();
			}
			break;
		}
	}
	//update all skills
	UpdateAllSkill();

	//update equip
	m_EquipBar.Update();

	if (GetPetAtt().IsPetInState(EPS_Working))
		return;

	//生命流失 每10秒扣除1点
	//if (nCount-- < 0)
	//{
	//	nCount = SPIRIT_RESUME_COUNT;
	//	if (GetPetAtt().GetAttVal(epa_spirit) > 0)
	//	{
	//		GetPetAtt().ModAttVal(epa_spirit, -1, TRUE);
	//	}
	//}
}

//----------------------------------------------------------------------------------------------------
// 与躯体整合
//----------------------------------------------------------------------------------------------------
BOOL PetSoul::IntegrateInPet(Pet* pPet)
{
	if (!VALID_POINT(pPet) || VALID_POINT(m_pBody))
	{
		return FALSE;
	}

	//Set Body by Pet
	m_pBody = pPet;

	return TRUE;
}

//----------------------------------------------------------------------------------------------------
// 离开躯体
//----------------------------------------------------------------------------------------------------
VOID PetSoul::DetachFromPet()
{
	if (!VALID_POINT(m_pBody))
	{
		ASSERT(0);
		return;
	}

	//Set Body to NULL
	m_pBody = NULL;
}

//----------------------------------------------------------------------------------------------------
// 初始化
//----------------------------------------------------------------------------------------------------
BOOL PetSoul::Init( const s_db_pet* &pSoulData, BOOL bCreate )
{
	// 加载宠物属性
	if (!m_PetAtt.InitAtt(&pSoulData->pet_att))
	{
		return FALSE;
	}

	PVOID pData = (PVOID)pSoulData->by_data;

	if (bCreate)
	{
		//OnLevelUp();
	}
	else
	{
		// 加载宠物技能
		InitPetSkill(pData, pData, pSoulData->n_pet_skill_num);

		// 加载宠物装备
		InitPetEquip(pData, pData, pSoulData->n_pet_equip_num);

		pSoulData = (s_db_pet*)pData;

	}
	
	// 看是否在工作状态
	tagPetSNSInfo* pSnsInfo = g_petSnsMgr.getPetSNSinfo(GetID());
	if (VALID_POINT(pSnsInfo))
	{
		SetWorking(TRUE);
	}
	else
	{
		SetWorking(FALSE);
	}
	
	// 处理异常技能
	LearnNormalSkill(GetPetAtt().GetVLevel(), GetPetAtt().GetAttVal(epa_quality));

	return TRUE;
}

//----------------------------------------------------------------------------------------------------
// 通过数据库数据创建灵魂
//----------------------------------------------------------------------------------------------------
PetSoul* PetSoul::CreateSoulByDBData( const BYTE* &pData, BOOL bCreate )
{
	M_trans_pointer(pSoulData, pData, const s_db_pet);
	PetSoul* pNewSoul = new PetSoul;

	if (!pNewSoul->Init(pSoulData, bCreate))
	{
		ASSERT(0);
		SAFE_DELETE(pNewSoul);
		return NULL;
	}
	pData = (BYTE*)pSoulData;

	return pNewSoul;
}

//----------------------------------------------------------------------------------------------------
// 宠物换装
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::Equip( INT64 n64ItemID, INT8 n8DstPos, BOOL bSend /*= FALSE*/ )
{
	tagItem* p2Equip = m_EquipBar.GetFromRoleBag(n64ItemID);
	if (!VALID_POINT(p2Equip))
	{
		ASSERT(0);
		return E_Pets_PetEquip_PetEquipNotInBag;
	}

	if (EISF_PetEquipment != p2Equip->pProtoType->eSpecFunc)
	{
		ASSERT(0);
		return E_Pets_PetEquip_IsNotPetEquip;
	}

	const tagPetEquipProto* pProto = AttRes::GetInstance()->GetPetEquipProto(p2Equip->pProtoType->nSpecFuncVal1);
	if (!VALID_POINT(pProto))
	{
		ASSERT(0);
		return E_Pets_PetEquip_UnknownEquipProto;
	}

	//检查等级
	if (m_PetAtt.GetStep() < pProto->nStep || m_PetAtt.GetGrade() < pProto->nGrade)
	{
		return E_Pets_PetEquip_PetLevelNotEnough;
	}

	return m_EquipBar.Equip(n64ItemID, n8DstPos, bSend);
}

//----------------------------------------------------------------------------------------------------
// 宠物卸装
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::UnEquip( INT64 n64ItemID, INT16 n16DstPos, BOOL bSend /*= FALSE*/ )
{
	// 例行检查
	tagItem* p2Equip = m_EquipBar.GetFromPet(n64ItemID);
	if (!VALID_POINT(p2Equip))
	{
		ASSERT(0);
		return E_Pets_PetEquip_PetEquipNotInBag;
	}

	const tagPetEquipProto* pProto = AttRes::GetInstance()->GetPetEquipProto(p2Equip->pProtoType->nSpecFuncVal1);
	if (!VALID_POINT(pProto))
	{
		ASSERT(0);
		return E_Pets_PetEquip_UnknownEquipProto;
	}

	return m_EquipBar.UnEquip(n64ItemID, n16DstPos, bSend);
}

//----------------------------------------------------------------------------------------------------
// 初始化宠物技能
//----------------------------------------------------------------------------------------------------
VOID PetSoul::InitPetSkill(IN PVOID pData, OUT PVOID& pDataOut, IN INT n_num)
{
	s_db_pet_skill* pDBPetSkill		= (s_db_pet_skill*)pData;
	s_db_pet_skill* pDBPetSkillEnd	= (s_db_pet_skill*)pData + n_num;

	while(pDBPetSkill < pDBPetSkillEnd)
	{
		PetSkill* pPetSkill = PetSkill::CreateDBPetSkill(pDBPetSkill, this);
		if (VALID_POINT(pPetSkill))
		{
			if (E_Pets_Success != AddSkillOnLoad(pPetSkill))
			{
				ASSERT(0);
				PetSkill::DeletePetSkill(pPetSkill);
			}
		}
		else
		{
			ASSERT(0);
		}
		++pDBPetSkill;
	}

	pDataOut = (PVOID)pDBPetSkillEnd;
}

BOOL PetSoul::InitRandomSkill()
{
	const s_pet_skill_list* pRs = AttRes::GetInstance()->GetPetRandomSkill(GetProto()->dwSkillListID);
	if (!VALID_POINT(pRs))
		return FALSE;
	
	INT dwSkillLevel = GetPetAtt().GetAttVal(epa_quality) + 1;
	RandNomalSkill(dwSkillLevel);
	RandBuffSkill();
	RandSpecialtySkill();	
	RandActionSkill();


	return TRUE;
}

VOID PetSoul::RandNomalSkill(INT nSkillLevel/* = INVALID_VALUE*/)
{
	const s_pet_skill_list* pRs = AttRes::GetInstance()->GetPetRandomSkill(GetProto()->dwSkillListID);
	if (!VALID_POINT(pRs))
		return;

	// 随机技能
	std::vector<DWORD> vecList = pRs->vec_normal;
	
	if (vecList.size() <= 0)
		return;

	std::size_t index = get_tool()->tool_rand() % (vecList.size());
	DWORD dwSkillID = vecList[index];
	if (nSkillLevel != INVALID_VALUE)
	{
		DWORD skillID		= MTransPetSkillID(dwSkillID);
		dwSkillID = MTransPetSkillTypeID(skillID, nSkillLevel);
	}

	LearnSkill(dwSkillID);

	/*vecList.erase(vecList.begin()+index);
	index = get_tool()->tool_rand() % (vecList.size());
	dwSkillID = vecList[index];
	LearnSkill(dwSkillID);*/
}

VOID PetSoul::RandBuffSkill(INT nSkillLevel/* = INVALID_VALUE*/)
{
	const s_pet_skill_list* pRs = AttRes::GetInstance()->GetPetRandomSkill(GetProto()->dwSkillListID);
	if (!VALID_POINT(pRs))
		return;

	if (pRs->vec_buff.size() <= 0)
		return;

	// 随机buff类技能
	DWORD dwSpe = pRs->vec_buff[get_tool()->tool_rand() % (pRs->vec_buff.size())];

	if (nSkillLevel != INVALID_VALUE)
	{
		DWORD skillID		= MTransPetSkillID(dwSpe);
		dwSpe = MTransPetSkillTypeID(skillID, nSkillLevel);
	}

	LearnSkill(dwSpe);
}

VOID PetSoul::RandSpecialtySkill(INT nSkillLevel/* = INVALID_VALUE*/)
{
	const s_pet_skill_list* pRs = AttRes::GetInstance()->GetPetRandomSkill(GetProto()->dwSkillListID);
	if (!VALID_POINT(pRs))
		return;

	if (pRs->vec_specialty.size() <= 0)
		return;

	// 随机特长
	DWORD dwSpe = pRs->vec_specialty[get_tool()->tool_rand() % (pRs->vec_specialty.size())];

	if (nSkillLevel != INVALID_VALUE)
	{
		DWORD skillID		= MTransPetSkillID(dwSpe);
		dwSpe = MTransPetSkillTypeID(skillID, nSkillLevel);
	}

	LearnSkill(dwSpe);
}

VOID PetSoul::RandActionSkill(INT nSkillLevel)
{
	const s_pet_skill_list* pRs = AttRes::GetInstance()->GetPetRandomSkill(GetProto()->dwSkillListID);
	if (!VALID_POINT(pRs))
		return;

	if (pRs->vec_Action.size() <= 0)
		return;

	// 随机主动技能
	DWORD dwSpe = pRs->vec_Action[get_tool()->tool_rand() % (pRs->vec_Action.size())];

	if (nSkillLevel != INVALID_VALUE)
	{
		DWORD skillID		= MTransPetSkillID(dwSpe);
		dwSpe = MTransPetSkillTypeID(skillID, nSkillLevel);
	}

	LearnSkill(dwSpe);
}
//----------------------------------------------------------------------------------------------------
// 初始化宠物装备
//----------------------------------------------------------------------------------------------------
VOID PetSoul::InitPetEquip(IN PVOID pData, OUT PVOID& pDataOut, IN INT n_num)
{
	const tagItem* pItem	= (const tagItem*)pData;
	const tagItem* pItemEnd = (const tagItem*)pData + n_num;

	while (pItem < pItemEnd)
	{
		tagItem* pTmpItem = new tagItem;
		ASSERT(!MIsEquipment(pItem->dw_data_id));
		get_fast_code()->memory_copy(pTmpItem, pItem, sizeof(tagItem));

		const tagItemProto* pItemProto = AttRes::GetInstance()->GetItemProto(pTmpItem->dw_data_id);
		if (!VALID_POINT(pItemProto))
		{
			SAFE_DELETE(pTmpItem);
			continue;
		}
		pTmpItem->pProtoType = pItemProto;

		pTmpItem->pScript = g_ScriptMgr.GetItemScript( pTmpItem->dw_data_id);

		m_EquipBar.AddEquip(pTmpItem, pTmpItem->n16Index, TRUE);
		++pItem;
	}

	pDataOut = (PVOID)pItemEnd;
}

//----------------------------------------------------------------------------------------------------
// 填充客户端用宠物属性结构
//----------------------------------------------------------------------------------------------------
VOID PetSoul::FillClientPetAtt( tagPetInitAttr* pInitAtt )
{
	pInitAtt->dwID				= GetID();
	pInitAtt->dw_data_id			= GetProtoID();

	pInitAtt->nQuality			= GetPetAtt().GetAttVal(epa_quality);
	pInitAtt->nAptitude			= GetPetAtt().GetAttVal(epa_aptitude);
	pInitAtt->nSpirit			= GetPetAtt().GetAttVal(epa_spirit);
	pInitAtt->nSpiritMax		= GetPetAtt().GetAttVal(epa_spirit_max);
	pInitAtt->nWuXingEnergy		= GetPetAtt().GetAttVal(epa_wuxing_energy); 
	pInitAtt->nLevel			= GetPetAtt().GetVLevel();
	pInitAtt->nExpCurrent		= GetPetAtt().GetCurExp();
	pInitAtt->nExpLevelUp		= GetPetAtt().GetExpLvlUp();
	pInitAtt->nPotential		= GetPetAtt().GetAttVal(epa_potential);
	pInitAtt->nMountSpeed		= GetPetAtt().GetAttVal(epa_mount_speed);
	pInitAtt->nBagGrid			= GetPetAtt().GetAttVal(epa_bag_grid);
	pInitAtt->byPetState		= GetPetAtt().GetState();
	pInitAtt->nMountNum			= GetPetAtt().GetAttVal(epa_mount_num);
	pInitAtt->nMountNumMax		= GetPetAtt().GetAttVal(epa_mount_num_max);
	pInitAtt->bLocked			= GetPetAtt().IsLocked() == TRUE;
	pInitAtt->nPetRenameCount	= GetPetAtt().GetRenameCount();
	pInitAtt->nPetHappyValue	= GetPetAtt().GetAttVal(epa_happy_value);
	pInitAtt->nPetColor			= GetPetAtt().GetAttVal(epa_color);
	pInitAtt->n_strength		= GetPetAtt().GetAttVal(epa_strength);
	pInitAtt->n_agility			= GetPetAtt().GetAttVal(epa_agility);
	pInitAtt->n_innerForce		= GetPetAtt().GetAttVal(epa_innerForce);
	pInitAtt->n_att_point		= GetPetAtt().GetAttVal(epa_att_point);
	pInitAtt->n_time_type		= GetPetAtt().GetTimeType();
	pInitAtt->n_mode_type		= GetPetAtt().GetModeType();
	pInitAtt->n_xiulian_time	= GetPetAtt().GetXiulianTime();

	// 序列化装备
	pInitAtt->nPetEquipNum		= 0;
	tagPetEquipMsgInfo* pEquipMsgInfo = (tagPetEquipMsgInfo*)pInitAtt->byData;
	for(INT16 nIndex = 0; nIndex < SIZE_PET_EQUIP_BAR; ++nIndex)
	{
		tagItem* pItem = m_EquipBar.GetItem(nIndex);
		if (!VALID_POINT(pItem)) 
			continue;
		m_EquipBar.FillClientEquipData(pEquipMsgInfo, pItem);
		++pEquipMsgInfo;
		++pInitAtt->nPetEquipNum;
	}

	// 序列化技能
	pInitAtt->nPetSkillNum		= m_mapPetSkill.size();
	tagPetSkillMsgInfo* pSkillMsgInfo	= (tagPetSkillMsgInfo*)pEquipMsgInfo;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	PetSkill* pSkill = NULL;
	while (m_mapPetSkill.find_next(itr, pSkill))
	{
		if (!VALID_POINT(pSkill))
			continue;
		pSkill->FillClientInfo(pSkillMsgInfo);
		++pSkillMsgInfo;		
	}
}

//----------------------------------------------------------------------------------------------------
// 存数据库
//----------------------------------------------------------------------------------------------------
BOOL PetSoul::SaveToDB( IN LPVOID pData, OUT LPVOID &pOutPointer )
{
	M_trans_pointer(pDBPet, pData, s_db_pet);

	// 宠物属性
	if(!GetPetAtt().SaveToDB(&pDBPet->pet_att))
		return FALSE;

	// 宠物技能
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	PetSkill* pSkill = NULL;
	pDBPet->n_pet_skill_num = 0;
	s_db_pet_skill* pSkills = (s_db_pet_skill*)pDBPet->by_data;
	while (m_mapPetSkill.find_next(itr, pSkill))
	{
		if(!VALID_POINT(pSkill))
			continue;
		pSkill->SaveToDB(&pSkills[pDBPet->n_pet_skill_num]);
		++pDBPet->n_pet_skill_num;
	}

	pOutPointer = (PVOID)(&pSkills[pDBPet->n_pet_skill_num]);

// 	// 宠物装备
// 	pDBPet->nPetEquipNum = 0;
// 	PVOID pEquips = (PVOID)(&pSkills[pDBPet->n_pet_skill_num]);
// 	m_EquipBar.SaveToDB(pEquips, pEquips, pDBPet->nPetEquipNum);
// 	pOutPointer = (PVOID)pEquips;

	return TRUE;
}

//----------------------------------------------------------------------------------------------------
// 装备换位置
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::EquipSwapPos( INT64 n64ItemID, INT8 n8DstPos, BOOL bSend /*= FALSE*/ )
{
	INT16 n16DstPos = (INT16)n8DstPos;

	return m_EquipBar.SwapEquipPos(n64ItemID, n8DstPos, bSend);
}

//----------------------------------------------------------------------------------------------------
// 填充客户端用宠物属性结构
//----------------------------------------------------------------------------------------------------
VOID PetSoul::GetEquipInfo( INT64 n64ItemID, tagPetEquipMsgInfo* pMsgInfo )
{
	tagItem* pItem = m_EquipBar.GetItem(n64ItemID);
	m_EquipBar.FillClientEquipData(pMsgInfo, pItem);
}

//----------------------------------------------------------------------------------------------------
// 灌注经验
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::PourExp( INT64 n64ItemID )
{
	if (!IsCalled())
		return E_Pets_StateLimit;

	Role* pMaster = GetMaster();
	if (!VALID_POINT(pMaster))
		return E_Pets_Soul_MasterNotFound;

	if (GetPetAtt().GetGrade() == MAX_PET_GRADE && 
		GetPetAtt().GetCurExp() >= GetPetAtt().GetExpLvlUp())
		return E_Pets_Soul_GradeNotFit;

	// 普通灌注
	if (!VALID_VALUE(n64ItemID))
	{
		DWORD dwRtv = E_Pets_Success;

		INT32 nID = pMaster->GetClass()*1000 + pMaster->get_level();
		const s_level_up_effect* pEffect = AttRes::GetInstance()->GetLevelUpEffect(nID);
		ASSERT(VALID_POINT(pEffect));
		INT64 nMoneyNeed	= GetPetAtt().CalPourMoney();
		INT64 nCurMoney		= GetMaster()->GetCurMgr().GetBagSilver();
		INT nNeedExp		= INT(pEffect->n_exp_level_up_ * 0.02);
		INT nCurExp			= pMaster->GetCurLevelExp();
		if(nCurExp < nNeedExp)
		{
			dwRtv = E_Pets_Soul_RoleExpNotEnough;
		}
		else if (nCurMoney < nMoneyNeed)
		{
			dwRtv = E_Pets_Soul_RoleMoneyNotEnough;
		}
		else
		{
			//pMaster->ExpChange(-nNeedExp);
			pMaster->GetCurMgr().DecBagSilver(nMoneyNeed, elcid_role_pour_exp_pet);

			GetPetAtt().ExpChange(nNeedExp, TRUE);
			dwRtv = E_Pets_Success;
		}

		return dwRtv;
		
	}
	// 物品灌注
	else
	{
		tagItem* pItem = GetMaster()->GetItemMgr().GetBagItem(n64ItemID);
		if (!VALID_POINT(pItem) || pItem->pProtoType->eSpecFunc != EISF_PetExpPour)
		{
			return E_Pets_ItemNotValid;
		}
		
		GetPetAtt().ExpChange(pItem->pProtoType->nSpecFuncVal1, TRUE);

		GetMaster()->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_role_pour_exp_pet);

		return E_Pets_Success;
	}
}

//----------------------------------------------------------------------------------------------------
// 灌注经验
//----------------------------------------------------------------------------------------------------
VOID PetSoul::OnLevelUp()
{
	// 学习技能
	LearnNormalSkill(GetPetAtt().GetVLevel(), GetPetAtt().GetAttVal(epa_quality));
	
	INT nPoint = PetHelper::getAddpoint(GetPetAtt().GetAttVal(epa_quality)) ;

	GetPetAtt().ModAttVal(epa_att_point, nPoint);

	if (VALID_POINT(m_pMaster))
	{
		m_pMaster->GetAchievementMgr().UpdateAchievementCriteria(eta_pet_level, GetPetAtt().GetVLevel());
		m_pMaster->GetAchievementMgr().UpdateAchievementCriteria(eta_pet_to_level, GetPetAtt().GetVLevel(), 1);
	}
}

//----------------------------------------------------------------------------------------------------
// 处理宠物技能命令
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::HandleSkillCmd( DWORD dwPetSkillTypeID, tagPetSkillCmdParam* pCmd )
{
	DWORD dwPetSkillID = MTransPetSkillID(dwPetSkillTypeID);
	PetSkill* pPetSkill = GetSkill(dwPetSkillID);
	if (!VALID_POINT(pPetSkill))
	{
		ASSERT(0);
		return E_Pets_PetSkill_Skill_NotExist;
	}

	BYTE byCastCond		= pPetSkill->GetCastCondition();
	BYTE byStateFlag	= GetPetAtt().GetStateFlag();
	if((byStateFlag & byCastCond) != byStateFlag 
		|| IsWorking() && GetWorkingSkillTypeID() != pPetSkill->GetSkillTypeID())
	{
		return E_Pets_PetSkill_Use_StateLimit;
	}
	
	if (pPetSkill->GetProto()->eCastType == EPCT_Active)
	{
		ActiveSkill *pActiveSkill = (ActiveSkill *)pPetSkill;
		return pActiveSkill->HandleCmd(pCmd);	
	}

	//ActiveSkill *pActiveSkill = dynamic_cast<ActiveSkill *>(pPetSkill);
	//if (NULL != pActiveSkill)
	//{
	//	return pActiveSkill->HandleCmd(pCmd);
	//}
	else
	{
		return E_Pets_PetSkill_Use_NotActiveSkill;
	}
}

//----------------------------------------------------------------------------------------------------
// 整合到玩家
//----------------------------------------------------------------------------------------------------
BOOL PetSoul::IntegrateInRole( Role* pRole )
{
	if (!VALID_POINT(pRole))
	{
		ASSERT(0);
		return FALSE;
	}
	SetMaster(pRole);

	return TRUE;
}

//----------------------------------------------------------------------------------------------------
// 从玩家身上分离
//----------------------------------------------------------------------------------------------------
VOID PetSoul::DetachFromRole()
{

	SetMaster(NULL);
}

//----------------------------------------------------------------------------------------------------
// 实体进入地图
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::BodyEnterMap()
{
	if (!VALID_POINT(m_pMaster) || !VALID_POINT(m_pMaster->get_map()))
	{
		ASSERT(0);
		return INVALID_VALUE;
	}

	if(!VALID_POINT(m_pBody))	return INVALID_VALUE;

	if(IsPetInMap())		return INVALID_VALUE;

	DWORD	dwMapID = m_pMaster->GetMapID();
	Vector3	vNewPos = m_pMaster->GetMoveData().m_vPos;
	Vector3	vNewFace = m_pMaster->GetMoveData().m_vFace;

	m_pBody->SetMapID(dwMapID);
	m_pBody->GetMoveData().Reset(vNewPos.x, vNewPos.y, vNewPos.z, vNewFace.x, vNewFace.y, vNewFace.z);

	m_pMaster->get_map()->add_creature(m_pBody);

	return E_Success;
}

//----------------------------------------------------------------------------------------------------
// 宠物实体离开地图
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::BodyLeaveMap(BOOL bSendMsg)
{
	if (!VALID_POINT(GetBody()))
	{
		ASSERT(0);
		return INVALID_VALUE;
	}
	
	if(!IsPetInMap())		return INVALID_VALUE;

	if (VALID_POINT(GetBody()->get_map()))
	{
		GetBody()->get_map()->remove_pet(m_pBody, bSendMsg);
	}
	
	return E_Success;
}

//----------------------------------------------------------------------------------------------------
// 是否召唤
//----------------------------------------------------------------------------------------------------
BOOL PetSoul::IsCalled()
{
	return IsInState(EPS_Called) && VALID_POINT(m_pBody);
}

//----------------------------------------------------------------------------------------------------
// 是否合体
//----------------------------------------------------------------------------------------------------
BOOL PetSoul::IsRonghe()
{
	return IsInState(EPS_Ronghe) && !VALID_POINT(m_pBody);
}

//----------------------------------------------------------------------------------------------------
// 学习技能
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::LearnSkill( DWORD dwPetSkillTypeID )
{
	DWORD dwSkillID		= MTransPetSkillID(dwPetSkillTypeID);
	INT	nSkillLvl		= MTransPetSkillLevel(dwPetSkillTypeID);

	const tagPetSkillProto* pProto = AttRes::GetInstance()->GetPetSkillProto(dwPetSkillTypeID);
	if (!VALID_POINT(pProto))
	{
		ASSERT(0);
		SI_LOG->write_log(_T("learn pet skill no pet proto<skill_type_id: %u>,<pet_id: %u>\r\n"),dwPetSkillTypeID, GetID());
		return E_Pets_UnkownErr;
	}

	DWORD dwSkillType3 = GetPetAtt().GetProto()->nType3;
	if(pProto->nType3 != 0 && pProto->nType3 != dwSkillType3)
		return E_Pets_PetSkill_Learn_Type3NotFit;

	PetSkill* pPreSkill = GetSkill(dwSkillID);
	//if( nSkillLvl != 1 && !VALID_POINT(pPreSkill) 
	//	|| VALID_POINT(pPreSkill) && pPreSkill->GetProto()->nSkillLevel + 1 != nSkillLvl)
	//	return E_Pets_PetSkill_Learn_NoPreSkill;
	
	if (VALID_POINT(pPreSkill))
	{
		// 遗忘低级技能
		ForgetSkill(dwSkillID);
	}
	

	// 宠物是否有空闲位置
	if (m_mapPetSkill.size() >= MAX_PET_SKILL_NUM)
	{
		SI_LOG->write_log(_T("learn pet skill not enough space<skill_type_id: %u>,<pet_id: %u>\r\n"),dwPetSkillTypeID, GetID());
		return E_Pets_PetSkill_Learn_MaxLeanNum;
	}

	// 创建技能对象
	PetSkill* pPetSkill = PetSkill::CreatePetSkill(dwPetSkillTypeID, this);
	if (!VALID_POINT(pPetSkill))
	{
		SI_LOG->write_log(_T("learn pet skill create err<skill_type_id: %u>,<pet_id: %u>\r\n"),dwPetSkillTypeID, GetID());
		return E_Pets_UnkownErr;
	}

	// 添加技能
	DWORD dwRtv = AddSkill(pPetSkill);
	if (E_Pets_Success != dwRtv)
	{
		SI_LOG->write_log(_T("learn pet skill addskill err<skill_type_id: %u>,<pet_id: %u>\r\n"),dwPetSkillTypeID, GetID());
		PetSkill::DeletePetSkill(pPetSkill);
	}
	else
	{
		if (VALID_POINT(GetMaster()))
		{
			NET_SIS_add_pet_skill sendNS;
			sendNS.dwPetID	= GetID();
			sendNS.dwSkillID	= dwPetSkillTypeID;
			GetMaster()->SendMessage(&sendNS, sendNS.dw_size);
		}

		NET_DB2C_insert_pet_skill send;
		send.dw_pet_id_	= GetID();
		pPetSkill->SaveToDB(&send.pet_skill_);
		g_dbSession.Send(&send, send.dw_size);
	}

	return dwRtv;
}

//----------------------------------------------------------------------------------------------------
// 移除一个技能
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::RemoveSkill( PetSkill* pSkill )
{
	// 停止工作
	if(pSkill->CanSetWorking(FALSE))
		pSkill->SetWorking(FALSE);
	
	// 失效
	if (pSkill->GetProto()->eCastType == EPCT_Passive)
	{
		PassiveSkill *pPassiveSkill = (PassiveSkill *)pSkill;
		if (pPassiveSkill->GetProto()->eType != EPT_Specialty)
		{
			pPassiveSkill->DeActive(GetMaster());
		}
	}
	
	//if (pSkill->GetProto()->eCastType == EPCT_Enhance)
	//{
	//	EnhanceSkill *pEnhanceSkill = (EnhanceSkill *)pSkill;
	//	pEnhanceSkill->Close();	
	//}

	//PassiveSkill *pPassiveSkill = dynamic_cast<PassiveSkill *>(pSkill);
	//if (VALID_POINT(pPassiveSkill))
	//{
	//	pPassiveSkill->DeActive();
	//}

	//EnhanceSkill *pEnhanceSkill = dynamic_cast<EnhanceSkill *>(pSkill);
	//if (VALID_POINT(pEnhanceSkill))
	//{
	//	pEnhanceSkill->Close();
	//}


	DWORD dwPetSkillTypeID	= pSkill->GetSkillTypeID();
	DWORD dwPetSkillID		= MTransPetSkillID(dwPetSkillTypeID);
	DWORD dwPetSkillLvl		= MTransPetSkillLevel(dwPetSkillTypeID);

	// 移除映射
	if (!VALID_VALUE(m_mapPetSkill.find(dwPetSkillID)))
	{
		return INVALID_VALUE;
	}
	m_mapPetSkill.erase(dwPetSkillID);

	return E_Pets_Success;
}

//----------------------------------------------------------------------------------------------------
// 设置是否是工作状态
//----------------------------------------------------------------------------------------------------
BOOL PetSoul::SetWorking( BOOL bWorking, DWORD dwFrinedID, DWORD dwTime )
{
	if (bWorking)
	{
		GetPetAtt().SetPetState(EPS_Working, TRUE);
		//m_dwFriendID = dwFrinedID;
		//m_dwBeginTime = dwTime;
		SetLocked(TRUE);
		return TRUE;
	}
	else
	{
		
		GetPetAtt().UnSetPetState(EPS_Working, TRUE);
		//m_dwFriendID = INVALID_VALUE;
		//m_dwBeginTime = INVALID_VALUE;
		SetLocked(FALSE);
		return TRUE;
	}
}

//----------------------------------------------------------------------------------------------------
// 能否设置为工作
//----------------------------------------------------------------------------------------------------
BOOL PetSoul::CanSetWroking()
{
	if (IsCalled())
	{
		return false;
	}
	if (IsRonghe())
	{
		return false;
	}
	//if (GetPetAtt().GetAttVal(epa_spirit) <= 0)
	//{
	//	return false;
	//}
	if (IsWorking())
	{
		return false;
	}

	if (IsInState(EPS_Dead) || IsInState(EPS_Xiulian))
	{
		return false;
	}

	return TRUE;
}

BOOL PetSoul::CanSetDead()
{
	if (IsInState(EPS_Called) || IsInState(EPS_Working) || IsInState(EPS_Ronghe) || 
		IsInState(EPS_Dead) || IsInState(EPS_Xiulian))
	{
		return false;
	}
	return true;
}
BOOL PetSoul::CanSetXiulian()
{
	if (IsInState(EPS_Called) || IsInState(EPS_Working) || IsInState(EPS_Ronghe) || 
		IsInState(EPS_Dead) || IsInState(EPS_Xiulian))
	{
		return false;
	}
	return true;
}
//----------------------------------------------------------------------------------------------------
// 是否正在工作
//----------------------------------------------------------------------------------------------------
BOOL PetSoul::IsWorking()
{
	return IsInState(EPS_Working);
}

//----------------------------------------------------------------------------------------------------
// 是否在某种状态
//----------------------------------------------------------------------------------------------------
BOOL PetSoul::IsInState( EPetState eState )
{
	return GetPetAtt().IsPetInState(eState);
}

//----------------------------------------------------------------------------------------------------
// 能否被设置是否召唤
//----------------------------------------------------------------------------------------------------
BOOL PetSoul::CanSetCalled( )
{
	if (IsCalled())
	{
		return false;
	}
	if (IsRonghe())
	{
		return false;
	}
	//if (GetPetAtt().GetAttVal(epa_spirit) <= 0)
	//{
	//	return false;
	//}
	if (IsWorking())
	{
		return false;
	}

	if (IsInState(EPS_Dead) || IsInState(EPS_Xiulian))
	{
		return false;
	}
	return true;
}

//----------------------------------------------------------------------------------------------------
// 设置是否召唤
//----------------------------------------------------------------------------------------------------
BOOL PetSoul::SetCalled( BOOL bSet, BOOL bSync /*= TRUE*/ )
{
	if (bSet)
	{
		//Create Pet by PetID
		M_trans_else_ret(pNewBody, Pet::Create(GetID(), this), Pet, FALSE);
		pNewBody->SetCollide(TRUE);

		//IntegrateSoul
		pNewBody->IntegrateSoul(this);

		SetBody(pNewBody);

		//Set Pet State
		GetPetAtt().SetPetState(EPS_Called, bSync);

		if (VALID_POINT(GetMaster()->get_map()) && !IsPetInMap())
		{
			BodyEnterMap();
		}

		// 所有被动技能生效
		PetSkill* pSkill = NULL;
		PetSkillMap::map_iter itr = m_mapPetSkill.begin();
		while (m_mapPetSkill.find_next(itr, pSkill))
		{
			if (pSkill->GetProto()->eType != EPT_Specialty)
			{
				pSkill->Active(GetMaster());
				if (VALID_POINT(GetMaster()->GetScript()))
					GetMaster()->GetScript()->OnPetSkillChange(GetMaster(), pSkill->GetSkillTypeID(), TRUE);
			}
			
		}

		// 增加主人的属性
		m_pMaster->ModAttModValue(ERA_Strength, GetPetAtt().GetAttVal(epa_strength));
		m_pMaster->ModAttModValue(ERA_Agility, GetPetAtt().GetAttVal(epa_agility));
		m_pMaster->ModAttModValue(ERA_InnerForce, GetPetAtt().GetAttVal(epa_innerForce));
		m_pMaster->RecalAtt(bSync);	
		
	}
	else
	{
		GetPetAtt().UnSetPetState(EPS_Called, bSync);

		if (!GetPetAtt().IsPetInState(EPS_Ronghe))
		{
			// 所有被动技能失效
			PetSkill* pSkill = NULL;
			PetSkillMap::map_iter itr = m_mapPetSkill.begin();
			while (m_mapPetSkill.find_next(itr, pSkill))
			{

				if (pSkill->GetProto()->eCastType == EPCT_Passive)
				{
					PassiveSkill *pPassiveSkill = (PassiveSkill *)pSkill;
					if (pPassiveSkill->GetProto()->eType != EPT_Specialty)
					{
						pPassiveSkill->DeActive(GetMaster(), bSync);
						if (VALID_POINT(GetMaster()->GetScript()))
							GetMaster()->GetScript()->OnPetSkillChange(GetMaster(), pSkill->GetSkillTypeID(), FALSE);

					}
				}
			}
		}

		
		// 减去主人的属性
		m_pMaster->ModAttModValue(ERA_Strength, -GetPetAtt().GetAttVal(epa_strength));
		m_pMaster->ModAttModValue(ERA_Agility, -GetPetAtt().GetAttVal(epa_agility));
		m_pMaster->ModAttModValue(ERA_InnerForce, -GetPetAtt().GetAttVal(epa_innerForce));
		m_pMaster->RecalAtt(bSync);	

		if (IsPetInMap())
		{
			GetBody()->get_map()->add_pet_delete_map(m_pBody);
			DWORD dw_result = BodyLeaveMap(bSync);
		//	if(dw_result != INVALID_VALUE)
		//	{
		//		SI_LOG->write_log(_T("Pet leave map error--1/r/n"));
		//	}
		}
		//else
		//{
		//	SI_LOG->write_log(_T("Pet leave map error--2/r/n"));
		//}
		
		Pet* pPet = (Pet*)GetBody();
		//DetachSoul Soul from Pet
		GetBody()->DetachSoul();

		//delete Pet
		//Pet::Delete(pPet);
		pPet->SetDel();
		
		SetBody(NULL);

		
	}

	return TRUE;
}

//设置是否合体
VOID PetSoul::SetHeti(BOOL bSet, Role* pRole, INT nAddSkillLevel,  BOOL bSync /*= TRUE*/)
{
	if (bSet)
	{
		// 必须是召唤出来的
		if (!IsCalled())
			return;
		
		GetPetAtt().SetPetState(EPS_Ronghe, bSync);

		// 取消召唤状态
		m_pMaster->GetPetPocket()->RestPet(GetID());
		
		m_pHeti = pRole;

		// 合体技能生效
		PetSkill* pSkill = NULL;
		PetSkillMap::map_iter itr = m_mapPetSkill.begin();
		while (m_mapPetSkill.find_next(itr, pSkill))
		{
			PassiveSkill *pPassiveSkill = (PassiveSkill *)pSkill;
			if (pPassiveSkill->GetProto()->eType == EPT_Specialty)
			{
				if (pPassiveSkill->GetProto()->eType2 == EPT2_Active ) // 主动技能不算增加的等级
					nAddSkillLevel = 0;

				pPassiveSkill->Active(pRole, nAddSkillLevel);
				if (VALID_POINT(pRole->GetScript()))
					pRole->GetScript()->OnPetSkillChange(pRole, pSkill->GetSkillTypeID(), TRUE);

			}
		}
	}	
	else
	{	
		
		GetPetAtt().UnSetPetState(EPS_Ronghe, bSync);

		// 合体技能失效
		PetSkill* pSkill = NULL;
		PetSkillMap::map_iter itr = m_mapPetSkill.begin();
		while (m_mapPetSkill.find_next(itr, pSkill))
		{
			PassiveSkill *pPassiveSkill = (PassiveSkill *)pSkill;
			//if (pPassiveSkill->GetProto()->eType == EPT_Specialty)
			//{
				pPassiveSkill->DeActive(m_pHeti, bSync);
				if (VALID_POINT(m_pHeti->GetScript()))
					m_pHeti->GetScript()->OnPetSkillChange(m_pHeti, pSkill->GetSkillTypeID(), FALSE);

			//}
		}
		m_pHeti = NULL;

		// 召唤出来
		//m_pMaster->GetPetPocket()->CallPet(GetID());

	}

	NET_DB2C_update_pet_soul send;
	GetPetAtt().SaveToDB(&send.pet_att);
	send.n_pet_soul_num = 1;
	g_dbSession.Send(&send, send.dw_size);

}
//----------------------------------------------------------------------------------------------------
// 取得原型
//----------------------------------------------------------------------------------------------------
const tagPetProto* PetSoul::GetProto()
{
	return GetPetAtt().GetProto();
}

//----------------------------------------------------------------------------------------------------
// 提升资质
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::Enhance( INT nAptitudeAdd )
{
	INT nAptitudeOld = GetPetAtt().GetAttVal(epa_aptitude);
	GetPetAtt().ModAttVal(epa_aptitude, nAptitudeAdd, TRUE);
	nAptitudeAdd = GetPetAtt().GetAttVal(epa_aptitude) - nAptitudeOld;
	GetPetAtt().ModAttVal(epa_potential, 10 * nAptitudeAdd, TRUE);

	NET_DB2C_update_pet_soul send;
	GetPetAtt().SaveToDB(&send.pet_att);
	send.n_pet_soul_num = 1;
	g_dbSession.Send(&send, send.dw_size);

	return E_Pets_Success;
}

//----------------------------------------------------------------------------------------------------
// 升阶
//----------------------------------------------------------------------------------------------------
DWORD PetSoul::UpStep( DWORD dwPetSkillTypeID )
{
	if (VALID_VALUE(dwPetSkillTypeID))
	{
		LearnSkill(dwPetSkillTypeID);
	}
	
	return GetPetAtt().UpStep();
}

BOOL PetSoul::IsPetInMap()
{
	Pet* pBody = GetBody();
	if (!VALID_POINT(pBody) || !VALID_POINT(pBody->get_map()))
	{
		return false;
	}
	return VALID_POINT(GetBody()->get_map()->find_pet(GetPetAtt().GetID()));
	//Map* pMap = (Map*)m_pMaster->get_map();
	//if(!VALID_POINT(pMap))	return FALSE;
	//return VALID_POINT(pMap->find_pet(GetPetAtt().GetID()));
}

VOID PetSoul::SetLocked( BOOL bSet )
{
	if (m_PetAtt.IsLocked() == bSet)
	{
		return;
	}
	m_PetAtt.SetLocked(bSet);		
	// 同步到数据库
	NET_DB2C_update_pet_soul send;
	GetPetAtt().SaveToDB(&send.pet_att);
	send.n_pet_soul_num = 1;
	g_dbSession.Send(&send, send.dw_size);
}

BOOL PetSoul::HasEquip()
{
	return m_EquipBar.HasEquip();
}

INT PetSoul::ExportSpecSkill( INT nPetAtt, std::list<PetSkill*> &listModSkill )
{
	INT nPetSkillType = GetModSkillType(nPetAtt);
	std::list<PetSkill*> listAllSkill;
	m_mapPetSkill.copy_value_to_list(listAllSkill);
	std::list<PetSkill*>::iterator itr = listAllSkill.begin();
	while(itr != listAllSkill.end())
	{
		const tagPetSkillProto* pProto = (*itr)->GetProto();
		if (VALID_POINT(pProto) && pProto->eType == (EPetskillType3)nPetSkillType)
		{
			listModSkill.push_back(*itr);
		}
		++itr;
	}
	return listModSkill.size();
}

INT PetSoul::GetModSkillType( INT nPetAtt )
{
	switch(nPetAtt)
	{
	case epa_delivery_consume:	//快递耗时	使用快递技能时，灵兽工作的时间缩放	默认0，装备加成-？~0：ms，对应技能表“工作时间”（降低5秒，填-5000）
		return EPT_Deliver;
		break;
	case epa_sell_consume:		//贩卖耗时	使用贩卖技能时，灵兽工作的时间缩放	默认0，装备加成-？~0：ms，对应技能表“工作时间”
		return EPT_Sale;
		break;
	case epa_storage_consume:	//存放耗时	使用存放技能时，灵兽工作的时间缩放	默认0，装备加成-？~0：ms，对应技能表“工作时间”
		return EPT_StoreHouse;
		break;
	case epa_gather_consume:		//采集耗时	使用采集技能时，灵兽工作时间缩放	默认0，装备加成-？~0：ms，对应技能表“工作时间”
		return EPT_Gather;
		break;
	case epa_train_resume:		//训练恢复	灵兽的自动训练技能的恢复时间缩放	默认0，装备加成-？~0：ms，对应技能表“恢复时间”
		return EPT_Experience;
		break;
	case epa_spirit_rate:		//灵力消耗	(0-1 0-10000)使用技能时的灵力消耗缩放比	默认100%，装备加成-100%~0%，对应技能表energy_cost
		return EPT_Null;
		break;
	case epa_exp_rate:			//经验加成	(0-1 0-10000)获得经验时的缩放比	默认100%，装备加成0%~400%
		return EPT_Null;
		break;
	case epa_pick_up_resume:		//拾取恢复	降低灵兽拾取的恢复时间	默认0，装备加成-20~-1
		return EPT_PickUp;
		break;
	case epa_medicine_saving:	//吃药节省	(0-1 0-10000)宠物每次喂药时可能不消耗该药品	默认0%，装备加成1%~5%
		return EPT_MedicineFeed;
		break;
	case epa_strength_effect:	//强身效果	(0-1 0-10000)提升强身类技能的效果	默认100%，装备加成0%~400%
		return EPT_Strengthen;
		break;
	case epa_wuxing_consume:		//五行力消耗	(0-1 0-10000)当使用天赋技能时，降低该技能对五行力的需求	默认100%，装备加成-50%~0%，对应技能表“五行力消耗”
		return EPT_WuXing;
		break;
	case epa_mount_speed:		//骑乘速度	(0-1 0-10000)灵兽被驾御时的移动速度	默认白30%，黄40%，绿50%，蓝60%，橙70% 装备加成0%~100%	受阶影响
		return EPT_Null;
		break;
	case epa_mount_num_max:		//骑乘人数
		return EPT_MountAdd;
		break;
	default:
		return EPT_Null;
		break;
	}

}

DWORD PetSoul::Feed( INT nSpritMod )
{
	//GetPetAtt().ModAttVal(epa_spirit, nSpritMod);
	GetPetAtt().ModAttVal(epa_happy_value, 1);
	return E_Pets_Success;
}

VOID PetSoul::OnPetSkillBuffTrigger(ETriggerEventType eEvent, EPassiveSkillAndEquipTrigger eTriggerType)
{
	if(!IsCalled())
		return;

	PetSkillMap::map_iter iter = m_mapPetSkill.begin();
	PetSkill* pSkill = NULL;
	while(m_mapPetSkill.find_next(iter, pSkill))
	{
		if(!VALID_POINT(pSkill))
			continue;

		if(pSkill->GetProto()->eCastType != EPCT_Passive)
			continue;

		const tagTriggerProto* pTriggerProto = AttRes::GetInstance()->GetTriggerProto(pSkill->GetProto()->dwTriggerID);
		if(!VALID_POINT(pTriggerProto))
		{
			//MAttResCaution(_T("equip trigger or buff"), _T("equip typeid"), pEquip->dw_data_id);
			continue;
		}

		// 查看trigger类型是否相同，主要是为了优化
		if(ETEE_Null == pTriggerProto->eEventType || eEvent != pTriggerProto->eEventType)
		{
			continue;
		}

		const tagBuffProto*	pBuffProto = AttRes::GetInstance()->GetBuffProto(pSkill->GetProto()->dwBufferID);
		if(!VALID_POINT(pBuffProto))
		{
			//MAttResCaution(_T("equip buff"), _T("equip typeid"), pEquip->dw_data_id);
			continue;
		}

		// 给自己是否满足
		if(VALID_POINT(m_pMaster))
		{
			m_pMaster->TryAddBuff(m_pMaster, pBuffProto, pTriggerProto, NULL, NULL);
		}
	}
}

VOID PetSoul::SetActiveSkill(EPetskillType ePetSkillType, bool bActive)
{
	PetSkill* pSkill = NULL;
	PetSkillMap::map_iter itr = m_mapPetSkill.begin();
	while (m_mapPetSkill.find_next(itr, pSkill))
	{
		if (pSkill->GetProto()->eType == ePetSkillType)
		{
			if (bActive)
			{
				pSkill->Active(GetMaster());
			}
			else
			{
				pSkill->DeActive(GetMaster());
			}
		}
	}
}