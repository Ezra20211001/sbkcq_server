/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//宠物容器

#include "StdAfx.h"
#include "pet_pocket.h"

#include "world.h"
#include "role.h"

#include "pet_server_define.h"
#include "pet_soul.h"
#include "pet.h"
#include "pet_skill.h"
#include "pet_equip.h"
#include "role_mgr.h"
#include "../common/WorldDefine/filter.h"
#include "../common/ServerDefine/log_server_define.h"
#include "../common/WorldDefine/pet_protocol.h"
#include "../common/ServerDefine/pet_server_define.h"
#include "../common/WorldDefine/pet_skill_protocol.h"
#include "../common/WorldDefine/pet_exchange_protocot.h"
#include "../common/WorldDefine/pet_sns_protocol.h"
#include "pet_skill_server_define.h"
#include "pet_sns_mgr.h"
#include "hearSay_helper.h"
//----------------------------------------------------------------------------------------------------
// 测试
//----------------------------------------------------------------------------------------------------
BOOL PetPocket::DynamicTest(INT nTestNo, INT nArg1, INT nArg2)
{
	DWORD dwRtv = E_Pets_Success;

	DWORD	dwPetIDS[10];
	INT		nPetNum = 0;
	GetAllPetID(dwPetIDS, nPetNum);
	if (nArg1 >= nPetNum)
		return FALSE;

	DWORD	dwPetID = dwPetIDS[nArg1];

	DWORD	dwSkillTypeID = 11101;

	switch(nTestNo)
	{
	case -1:
		{
			package_list<tagItem*> itemlist;
			// 宠物蛋typeid 4000001~4000006
			m_pMaster->GetItemMgr().GetBagSameItemList(itemlist, 4000001);
			if (itemlist.empty())
			{
				return FALSE;
			}
			else
			{
				dwRtv = HatchEgg((*itemlist.begin())->GetKey(), _T("helloworld"));
			}			
			
		}

		break;
	case 0:
		{
			m_pMaster->GetPetPocket()->petXiulian(dwPetID, 0, 1, 1);
// 			PetSoul* pSoul = GetPetSoul(dwPetID);
// 			dwRtv = pSoul->LearnNormalSkill(1);//pSoul->LearnSkill(dwSkillTypeID);
		}
		break;
	case 1:
		{
			m_pMaster->GetPetPocket()->petXiulianRetrun(dwPetID);
		}
		break;
	case 2:
		{
			PetSoul* pTakeAway = m_pMaster->GetPetPocket()->GetAway(dwPetID);
			PetSoul::DeleteSoul(pTakeAway, TRUE);
		}
		break;
	case 3:
		{
			DWORD dwRTv = E_Success;
			PetSoul* pSoul = m_pMaster->GetPetPocket()->GetPetSoul(dwPetID);
			package_list<tagItem*> itemlist;
			// 宠物蛋typeid 4000001~4000006
			m_pMaster->GetItemMgr().GetBagSameItemList(itemlist, 4010001);
			if (itemlist.empty())
			{
				return FALSE;
			}
			else
			{
				tagItem* pItem = *itemlist.begin();
				dwRTv = pSoul->Equip(pItem->GetKey(), INVALID_VALUE, TRUE);
			}
		}
		break;
	case 4:
		{
			/*DWORD dwRTv = E_Success;
			PetSoul* pSoul = m_pMaster->GetPetPocket()->GetPetSoul(dwPetID);
			BYTE buffer[1024] = {0};
			
			tagPetInitAttr* pPetInitAtt = new (buffer) tagPetInitAttr;
			pSoul->FillClientPetAtt(pPetInitAtt);
			if (pPetInitAtt->nPetEquipNum != 0)
			{
				tagPetEquipMsgInfo* pEquipMsgInfo = (tagPetEquipMsgInfo*)pPetInitAtt->byData;
				INT i=0; 
				INT64 n64ID = pEquipMsgInfo[nArg2].n64ItemID;
				dwRTv = pSoul->UnEquip(n64ID, INVALID_VALUE, TRUE);
			}*/
		}
		break;
	case 5:
		{
			PetSoul* pSoul = m_pMaster->GetPetPocket()->GetPetSoul(dwPetID);
			pSoul->GetPetAtt().ExpChange(nArg2, TRUE);
		}
		break;
	case 6:
		{
			package_list<tagItem*> itemlist;
			// 宠物蛋typeid 4000001~4000006
			m_pMaster->GetItemMgr().GetBagSameItemList(itemlist, nArg2);
			if (itemlist.empty())
			{
				return FALSE;
			}
			else
			{
				tagItem* pItem = *itemlist.begin();
				PetSoul* pSoul = m_pMaster->GetPetPocket()->GetPetSoul(dwPetID);
				dwRtv = pSoul->LearnBookSkill(pItem->GetKey());				
			}	

		}
		break;
	case 7:
		{
			m_pMaster->GetPetPocket()->PetChange(dwPetID, 0);
		}
		break;
	case 8:
		{
			PetSoul* pSoul = m_pMaster->GetPetPocket()->GetPetSoul(dwPetID);
			pSoul->GetPetAtt().SetAttVal(epa_quality, nArg2);

			pSoul->GetPetAtt().SetAttVal(epa_strength, 0);
			pSoul->GetPetAtt().SetAttVal(epa_agility, 0);
			pSoul->GetPetAtt().SetAttVal(epa_innerForce, 0);
			pSoul->GetPetAtt().SetAttVal(epa_att_point, 0);

			pSoul->OnLevelUp();
		}
		break;
	default:
		break;
	}
	return TRUE;
}

//----------------------------------------------------------------------------------------------------
// 初始化
//----------------------------------------------------------------------------------------------------
BOOL PetPocket::Init(const BYTE* &pData, INT n_num, Role* pRole, INT16 nSize)
{
	m_dwPetIDForUpStep = INVALID_VALUE;
	m_nCalledPets = 0;
	if (!VALID_POINT(pRole))
	{
		return FALSE;
	}

	m_pMaster = pRole;
	
	m_nSize = nSize;
	// 初始化宠物灵魂
	for (INT i=0; i<n_num; ++i)
	{
		PetSoul* pSoul = PetSoul::CreateSoulByDBData(pData, FALSE);
		if (VALID_POINT(pSoul))
		{
			if (E_Success != PutIn(pSoul, FALSE))
			{
				PetSoul::DeleteSoul(pSoul, FALSE);
			}
			
		}
	}
	
	return TRUE;
}

//----------------------------------------------------------------------------------------------------
// 更新
//----------------------------------------------------------------------------------------------------
VOID PetPocket::Update()
{
	DWORD		dwPetID	= INVALID_VALUE;
	PetSoul*	pSoul	= NULL;
	m_mapAllSoul.reset_iterator();
	while( m_mapAllSoul.find_next(dwPetID, pSoul) )
	{
		if (!VALID_POINT(pSoul)) continue;
		pSoul->Update();
	}
}

//----------------------------------------------------------------------------------------------------
// 获取所有宠物id
//----------------------------------------------------------------------------------------------------
#include <list>
VOID PetPocket::GetAllPetID( DWORD* dwPetIDbuf, INT& num )
{
	std::list<DWORD> kList;
	m_mapAllSoul.copy_key_to_list(kList);
	num = 0;
	for (std::list<DWORD>::iterator itr = kList.begin();
		 itr != kList.end();
		 ++itr)
	{
		dwPetIDbuf[num++] = *itr;
	}
}

//----------------------------------------------------------------------------------------------------
// 使用宠物蛋
//----------------------------------------------------------------------------------------------------
DWORD PetPocket::HatchEgg(INT64 n64ItemID, LPCTSTR tszName)
{
	// 宠物数目检查
	if(m_mapAllSoul.size() >= m_nSize)
		return E_Pets_Soul_NumExceed;

	// 宠物蛋
	tagItem* pEgg = m_pMaster->GetItemMgr().GetBagItem(n64ItemID);
	if (!VALID_POINT(pEgg) || pEgg->pProtoType->eSpecFunc != EISF_PetEgg)
	{
		return E_Pets_Soul_PetEggErr;
	}
	DWORD dw_data_id	= pEgg->pProtoType->nSpecFuncVal1;
	const tagPetProto* pPetProto = AttRes::GetInstance()->GetPetProto(dw_data_id);
	if (!VALID_POINT(pPetProto))
	{
		return E_Pets_Soul_PetEggErr;
	}

	if (pPetProto->nRoleLvlLim > m_pMaster->get_level())
	{
		return E_PetRoleLvlNotEnough;
	}

	if(pEgg->pProtoType->nSpecFuncVal1 <= 0)
	{
		print_message(_T("Itemid=%d PetEgg nSpecFuncVal1 error!!!\n"), pEgg->dw_data_id);
		return INVALID_VALUE;
	}

	
	INT	nQuality	= 0;//pEgg->pProtoType->byQuality;
	// 检测名称
	if (E_Success != Filter::CheckName(tszName,X_PET_NAME, 1, AttRes::GetInstance()->GetNameFilterWords()))
	{
		return E_Pets_Soul_NameIllegal;
	}
	

	// 称号消息
	m_pMaster->GetAchievementMgr().UpdateAchievementCriteria(ete_use_item, pEgg->pProtoType->dw_data_id, 1);


	// 使用物品
	if (E_Success != m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_create_pet))
	{
		ASSERT(0);
		return E_Pets_Soul_PetEggErr;
	}

	
	//DB创建PetSoul
	PetSoul::CreateDBSoul(dw_data_id, tszName, m_pMaster, nQuality);
	m_pMaster->GetAchievementMgr().UpdateAchievementCriteria(ete_pet_have_quality, nQuality);	

	return E_Pets_Success;
}

// 扩充宠物栏
DWORD PetPocket::SpePetItem(INT64 n64ItemID)
{
	tagItem* pItem = m_pMaster->GetItemMgr().GetBagItem(n64ItemID);
	if (!VALID_POINT(pItem) || pItem->pProtoType->eSpecFunc != EIST_SpePetItem)
	{
		return E_Pets_NotExpPocket_Item;
	}
	
	DWORD dwItemID = pItem->pProtoType->dw_data_id;
	// 使用物品
	//if (E_Success != m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_pet_spe))
	//{
	//	ASSERT(0);
	//	return E_Pets_Soul_PetEggErr;
	//}
	switch (pItem->pProtoType->nSpecFuncVal1)
	{
	case 0://扩充宠物栏
		{
			if(m_nSize >= MAX_PETSOUL_NUM)
				return E_Pets_pocketMax;

			m_nSize++;

			NET_SIS_pet_pocket_size_change sendNS;
			sendNS.n16NewSize = m_nSize;
			m_pMaster->SendMessage(&sendNS, sendNS.dw_size);

			m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_pet_spe);
		}
		break;
	case 1://随机普通技能
		{
			PetSoul* pCalledSoul = GetCalledPetSoul();
			if (!VALID_POINT(pCalledSoul))
			{
				return E_Pets_Soul_NotExist;
			}
			pCalledSoul->RemoveNormalSkill();
			pCalledSoul->RandNomalSkill();
			m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_pet_spe);
		}
	
		break;
	case 2://随机普通和buff技能
		{
			PetSoul* pCalledSoul = GetCalledPetSoul();
			if (!VALID_POINT(pCalledSoul))
			{
				return E_Pets_Soul_NotExist;
			}
			pCalledSoul->RemoveNormalSkill();
			pCalledSoul->RemoveBuffSkill();
			pCalledSoul->RandNomalSkill();
			pCalledSoul->RandBuffSkill();
			m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_pet_spe);
		}
		break;
	case 3://随机特长
		{
			PetSoul* pCalledSoul = GetCalledPetSoul();
			if (!VALID_POINT(pCalledSoul))
			{
				return E_Pets_Soul_NotExist;
			}
			pCalledSoul->RemoveSpecialtySkill();
			pCalledSoul->RandSpecialtySkill();

			m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_pet_spe);
		}
		break;
	default:
		break;
	}
	
	m_pMaster->GetAchievementMgr().UpdateAchievementCriteria(ete_use_item, dwItemID, 1);

	return E_Pets_Success;
}
DWORD PetPocket::ChangeSize()
{
	if(m_nSize >= MAX_PETSOUL_NUM)
		return E_Pets_pocketMax;
	
	if (m_pMaster->GetCurMgr().GetBagSilver() < PetHelper::getChangeSizeMoney(m_nSize+1))
	{
		return E_Pets_pocket_not_money;
	}
	m_nSize++;

	m_pMaster->GetCurMgr().DecBagSilver(PetHelper::getChangeSizeMoney(m_nSize), elcid_pet_size_change);

}
//宠物改名
DWORD PetPocket::ReName(DWORD dwPetID, LPCTSTR tszName)
{
	// 检测名称
	if (E_Success != Filter::CheckName(tszName,X_PET_NAME, 1, AttRes::GetInstance()->GetNameFilterWords()))
	{
		return E_Pets_Soul_NameIllegal;
	}

	PetSoul* pSoul = m_mapAllSoul.find(dwPetID);
	if (!VALID_POINT(pSoul))
		return E_Pets_Soul_NotExist;
	
	if (pSoul->GetPetAtt().GetRenameCount() > 0)
		return E_Pets_rename_countnot;

	pSoul->GetPetAtt().SetName(tszName);

	// 同步数据库
	NET_DB2C_update_pet_soul send;
	pSoul->GetPetAtt().SaveToDB(&send.pet_att);
	send.n_pet_soul_num = 1;
	g_dbSession.Send(&send, send.dw_size);
	

	// 同步客户端显示
	NET_SIS_get_pet_display_info sendClient;
	sendClient.dwPetID = dwPetID;
	pSoul->GetPetAtt().GetName(sendClient.DispData.szName);
	sendClient.DispData.byQuality = pSoul->GetPetAtt().GetAttVal(epa_quality);
	m_pMaster->get_map()->send_big_visible_tile_message(m_pMaster, &sendClient, sendClient.dw_size);

	return E_Pets_Success;
}
//----------------------------------------------------------------------------------------------------
// 拿走宠物(注意delete)
//----------------------------------------------------------------------------------------------------
PetSoul* PetPocket::GetAway( DWORD dwPetID, BOOL bSync /*= FALSE*/ )
{
	PetSoul* pSoul2Get = m_mapAllSoul.find(dwPetID);
	if (!VALID_POINT(pSoul2Get))
	{
		if (bSync)
		{
			NET_SIS_delete_pet send;
			send.dwPetID = dwPetID;
			send.dwErrCode = E_Pets_Soul_NotExist;
			m_pMaster->SendMessage(&send, send.dw_size);
		}
		return NULL;
	}
	else if (pSoul2Get->IsLocked())
	{
		if (bSync)
		{
			NET_SIS_delete_pet send;
			send.dwPetID = dwPetID;
			send.dwErrCode = E_Pets_Lock_Locked;
			m_pMaster->SendMessage(&send, send.dw_size);
		}
		return NULL;
	}
	else if (pSoul2Get->HasEquip())
	{
		if (bSync)
		{
			NET_SIS_delete_pet send;
			send.dwPetID = dwPetID;
			send.dwErrCode = E_Pets_Delete_HasEquip;
			m_pMaster->SendMessage(&send, send.dw_size);
		}
		return NULL;
	}

	// 取消召唤
	if (pSoul2Get->IsCalled())
	{
		RestPet(pSoul2Get->GetID());
	}

	// 取消工作
	if (pSoul2Get->CanSetWroking())
	{
		pSoul2Get->SetWorking(FALSE, INVALID_VALUE, INVALID_VALUE);
	}


	//Remove from Pocket
	m_mapAllSoul.erase(dwPetID);

	//Free it
	pSoul2Get->DetachFromRole();

	//同步客户端
	if (bSync)
	{
		NET_SIS_delete_pet send;
		send.dwPetID = dwPetID;
		send.dwErrCode = E_Pets_Success;
		m_pMaster->SendMessage(&send, send.dw_size);
	}

	// 同步数据库
	NET_DB2C_update_pet_soul send;
	pSoul2Get->GetPetAtt().SaveToDB(&send.pet_att);
	send.n_pet_soul_num = 1;
	g_dbSession.Send(&send, send.dw_size);

	return pSoul2Get;
}

//----------------------------------------------------------------------------------------------------
// 放入宠物
//----------------------------------------------------------------------------------------------------
DWORD PetPocket::PutIn( PetSoul* pSoul, BOOL bSend /*= TRUE*/ )
{
	if (!VALID_POINT(pSoul))
	{
		return E_Pets_Soul_PtrNotValid;
	}

	// num check
	if (m_mapAllSoul.size() > MAX_PETSOUL_NUM)
	{
		return E_Pets_Soul_NumExceed;
	}

	//pSoul is not in Pocket
	if (VALID_POINT(m_mapAllSoul.find(pSoul->GetID())))
	{
		return E_Pets_Soul_AlreadyExist;
	}

	//Add to my pocket
	m_mapAllSoul.add(pSoul->GetID(), pSoul);

	//Tag it
	pSoul->IntegrateInRole(m_pMaster);

	if (pSoul->IsInState(EPS_Called))
	{
		CallPet(pSoul->GetID());
	}

	//Sync
	if (bSend)
	{
		// 同步到客户端
		BYTE buffer[1024] = {0};
		NET_SIS_get_pet_att* pSend = (NET_SIS_get_pet_att*)buffer;
		NET_SIS_get_pet_att tmp;
		pSend->dw_message_id = tmp.dw_message_id;
		pSend->dw_role_id = m_pMaster->GetID();
		pSoul->FillClientPetAtt(&pSend->petAttr);
		pSend->dw_size = sizeof(NET_SIS_get_pet_att) - 1 + 
			sizeof(tagPetSkillMsgInfo) * pSend->petAttr.nPetSkillNum + 
			sizeof(tagPetEquipMsgInfo) * pSend->petAttr.nPetEquipNum;
		m_pMaster->SendMessage(pSend, pSend->dw_size);
	}

	// 同步到数据库
	NET_DB2C_update_pet_soul send;
	pSoul->GetPetAtt().SaveToDB(&send.pet_att);
	send.n_pet_soul_num = 1;
	g_dbSession.Send(&send, send.dw_size);

	return E_Pets_Success;
}

//----------------------------------------------------------------------------------------------------
// 召唤宠物
//----------------------------------------------------------------------------------------------------
DWORD PetPocket::CallPet(DWORD dwPetID)
{
	//all precondition
	if( !VALID_POINT(m_pMaster) ||
		!IS_PET(dwPetID)	
		)
	{
		//ASSERT(0);
		return E_Pets_UnkownErr;
	}

	//是否在战斗状态 修炼状态
	if(/*m_pMaster->IsInRoleState(ERS_Combat) || */m_pMaster->IsInRoleState(ERS_Prictice))
	{
		//ASSERT(0);
		return E_Master_StateLimit;
	}

	//Get PetSoul by PetID
	PetSoul* pCalledSoul = GetPetSoul(dwPetID);
	if (!VALID_POINT(pCalledSoul))
	{
		//ASSERT(0);
		return E_Pets_Soul_NotExist;
	}

	if (!pCalledSoul->CanSetCalled())
	{
		//ASSERT(0);
		return E_Pets_Pet_AlreadyCalled;
	}

	if (m_nCalledPets >= MAX_CALLED_PET_NUM)
	{
		if (RestAPet() != E_Pets_Success)
		{
			//ASSERT(0);
			return E_Pets_Pet_CalledNumExceed;
		}
		//ASSERT(m_nCalledPets < MAX_CALLED_PET_NUM);
	}

	if (!pCalledSoul->SetCalled(TRUE, TRUE))
	{
		return E_Pets_UnkownErr;
	}
	++m_nCalledPets;
	


	return E_Pets_Success;
}

//----------------------------------------------------------------------------------------------------
// 宠物休息
//----------------------------------------------------------------------------------------------------
DWORD PetPocket::RestPet(DWORD dwPetID, BOOL bDestory)
{
	PetSoul* pSoul = m_mapAllSoul.find(dwPetID);
	if (!VALID_POINT(pSoul))
	{
		ASSERT(0);
		return E_Pets_Soul_NotExist;
	}

	if (!pSoul->IsCalled())
	{
		ASSERT(0);
		return E_Pets_Pet_NotCalled;
	}

	pSoul->SetCalled(FALSE, bDestory? FALSE:TRUE);

	--m_nCalledPets;

	return E_Pets_Success;
}

//----------------------------------------------------------------------------------------------------
// 获取PetSoul
//----------------------------------------------------------------------------------------------------
PetSoul* PetPocket::GetPetSoul(DWORD dwPetID)
{
	return m_mapAllSoul.find(dwPetID);
}

PetSoul* PetPocket::GetCalledPetSoul()
{
	SoulTMap::map_iter itr = m_mapAllSoul.begin();
	PetSoul* pSoul = NULL;
	while (m_mapAllSoul.find_next(itr, pSoul))
	{
		if (!VALID_POINT(pSoul))
			continue;

		if (pSoul->IsCalled())
		{
			return pSoul;
		}
	}

	return NULL;
}
//----------------------------------------------------------------------------------------------------
// 召唤出的宠物进入宠物带
//----------------------------------------------------------------------------------------------------
VOID PetPocket::CalledPetEnterPocket()
{
	PetSoul* pSoul = NULL;
	SoulTMap::map_iter itr = m_mapAllSoul.begin();
	while (m_mapAllSoul.find_next(itr, pSoul))
	{
		if (VALID_POINT(pSoul) && pSoul->IsCalled())
		{
			if (pSoul->IsPetInMap())
			{
				pSoul->BodyLeaveMap();
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------
// 召唤出的宠物离开宠物带
//----------------------------------------------------------------------------------------------------
VOID PetPocket::CalledPetLeavePocket()
{
	PetSoul* pSoul = NULL;
	SoulTMap::map_iter itr = m_mapAllSoul.begin();
	while (m_mapAllSoul.find_next(itr, pSoul))
	{
		if (VALID_POINT(pSoul) && pSoul->IsCalled() && !pSoul->IsPetInMap())
		{
			pSoul->BodyEnterMap();
		}
	}
}

//----------------------------------------------------------------------------------------------------
// 内存泄露销毁
//----------------------------------------------------------------------------------------------------
VOID PetPocket::Destroy()
{
	//delete all soul
	PetSoul* pSoul = NULL;
	SoulTMap::map_iter itr = m_mapAllSoul.begin();
	
	while (m_mapAllSoul.find_next(itr, pSoul))
	{
		if (!VALID_POINT(pSoul))
			continue;
		if (pSoul->IsCalled())
			RestPet(pSoul->GetID(), TRUE);
		PetSoul::DeleteSoul(pSoul, FALSE);
	}
	m_mapAllSoul.clear();
	m_nCalledPets = 0;
}

//----------------------------------------------------------------------------------------------------
// 保存数据
//----------------------------------------------------------------------------------------------------
BOOL PetPocket::SaveToDB( IN LPVOID pData, OUT LPVOID &pOutPointer, OUT INT32 &n_num )
{
	pOutPointer = pData;
	n_num = 0;

	SoulTMap::map_iter itr = m_mapAllSoul.begin();
	PetSoul* pSoul = NULL;
	while (m_mapAllSoul.find_next(itr, pSoul))
	{
		if (!VALID_POINT(pSoul))
			continue;

		if (!pSoul->SaveToDB(pData, pData))
			continue;

		++n_num;
	}

	pOutPointer = pData;

	return TRUE;
}

//----------------------------------------------------------------------------------------------------
// 设置一个宠物到休息状态
//----------------------------------------------------------------------------------------------------
DWORD PetPocket::RestAPet()
{
	SoulTMap::map_iter itr = m_mapAllSoul.begin();
	PetSoul* pSoul = NULL;
	while (m_mapAllSoul.find_next(itr, pSoul))
	{
		if (VALID_POINT(pSoul) && pSoul->IsCalled())
		{
			if (E_Pets_Success == RestPet(pSoul->GetID()))
			{
				return E_Pets_Success;
			}
		}
	}
	
	return INVALID_VALUE;
}

INT PetPocket::GetXiulianNumber()
{
	INT nNum = 0;

	SoulTMap::map_iter itr = m_mapAllSoul.begin();
	PetSoul* pSoul = NULL;
	while (m_mapAllSoul.find_next(itr, pSoul))
	{
		if (VALID_POINT(pSoul) && pSoul->GetPetAtt().IsPetInState(EPS_Xiulian))
		{
			nNum++;
		}
	}

	return nNum;
}

INT PetPocket::GetMaxPetLevel()
{
	INT nMax = 0;

	SoulTMap::map_iter itr = m_mapAllSoul.begin();
	PetSoul* pSoul = NULL;
	while (m_mapAllSoul.find_next(itr, pSoul))
	{

		if (VALID_POINT(pSoul) && pSoul->GetPetAtt().GetVLevel() > nMax)
		{
			nMax = pSoul->GetPetAtt().GetVLevel();
		}
	}

	return nMax;
}

// 所有宠物取消合体状态
VOID PetPocket::RestAllPetHeti()
{
	SoulTMap::map_iter itr = m_mapAllSoul.begin();
	PetSoul* pSoul = NULL;
	while (m_mapAllSoul.find_next(itr, pSoul))
	{
		if (VALID_POINT(pSoul) && pSoul->IsRonghe())
		{
			pSoul->SetHeti(FALSE, NULL);
		}
	}
}

//----------------------------------------------------------------------------------------------------
// 某个宠物能否被交易
//----------------------------------------------------------------------------------------------------
DWORD PetPocket::CanExchange( DWORD dwPetID )
{
	PetSoul* pSoul = GetPetSoul(dwPetID);
	if (!VALID_POINT(pSoul))
	{
		return INVALID_VALUE;
	}

	if (pSoul->IsLocked())
	{
		return E_Pet_Exchange_PetLocked;
	}
	else if (pSoul->GetProto()->bBind)
	{
		return E_Pet_Exchange_PetBinded;
	}
	else if (pSoul->IsWorking())
	{
		return E_Pet_Exchange_PetStateNotAllow;
	}
	else if(pSoul->IsCalled())
	{
		return E_Pet_Exchange_PetStateNotAllow;
	}
	else if(pSoul->HasEquip())
	{
		return E_Pet_Exchange_PetHasEquip;
	}
	else
	{
		return E_Success;
	}
}

//----------------------------------------------------------------------------------------------------
// 检查指定的宠物是可以交易
//----------------------------------------------------------------------------------------------------
BOOL PetPocket::CheckExistInPocket( DWORD *dwPetIDs, INT n_num )
{
	for (INT i=0; i<n_num; ++i)
	{
		DWORD dwPetID = dwPetIDs[i];
		if (VALID_POINT(dwPetID) && E_Success != CanExchange(dwPetID))
		{
			return FALSE;
		}
	}
	return TRUE;
}

//----------------------------------------------------------------------------------------------------
// 从宠物带中拿走
//----------------------------------------------------------------------------------------------------
VOID PetPocket::TakeFromPocket( PetSoul* *pSouls, INT nSizeSouls, DWORD* dwPetIDs, INT nNumPetID )
{
	INT iSouls=0;

	for (INT i=0; i<nNumPetID; ++i)
	{
		PetSoul* pSoul = GetAway(dwPetIDs[i], TRUE);
		if (VALID_POINT(pSoul))
		{
			pSouls[iSouls++] = pSoul;
			if (iSouls >= nSizeSouls)
			{
				break;
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------
// 放入宠物带
//----------------------------------------------------------------------------------------------------
VOID PetPocket::PutInPocket( PetSoul* *pSouls, INT nSizeSouls )
{
	for (INT i=0; i<nSizeSouls; ++i)
	{
		PetSoul* pSoul = pSouls[i];
		if (VALID_POINT(pSoul))
		{
			DWORD dwErr = PutIn(pSoul);
			if (dwErr != E_Pets_Success)
			{
				break;
			}
		}		
	}
}

//----------------------------------------------------------------------------------------------------
// 得到可用宠物带空间
//----------------------------------------------------------------------------------------------------
BOOL PetPocket::GetFreeSize()
{
	return MAX_PETSOUL_NUM - m_mapAllSoul.size();
}

//----------------------------------------------------------------------------------------------------
// 召唤的宠物提升资质
//----------------------------------------------------------------------------------------------------
DWORD PetPocket::CalledSoulEnhance( INT64 n64ItemID )
{
	M_trans_else_ret(pCalled, GetCalledPetSoul(), PetSoul, E_Pets_Pet_NotCalled);

	INT nQuality = pCalled->GetPetAtt().GetAttVal(epa_quality);
	//if (pCalled->GetPetAtt().GetAttVal(epa_aptitude) >= pCalled->GetProto()->nAptitudeMax[nQuality])
	//{
	//	return E_Pets_AlreadyMaxAptitude;
	//}

	M_trans_else_ret(pItem, m_pMaster->GetItemMgr().GetBagItem(n64ItemID), tagItem, E_Pets_ItemNotValid);
	if (pItem->pProtoType->eSpecFunc != EISF_PetEnhance)
	{
		return E_Pets_ItemNotValid;
	}

	if (pItem->pProtoType->nSpecFuncVal1 != pCalled->GetPetAtt().GetAttVal(epa_quality))
	{
		return E_Pets_QualityNotFit;
	}

	INT nAptitudeAdd = get_tool()->rand_in_range(0, pItem->pProtoType->nSpecFuncVal2);
	if (nAptitudeAdd == 0)
	{
		return E_Pets_EnhanceFailed;
	}

	if (E_Success != m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_pet_enhance))
	{
		return E_Pets_ItemNotValid;
	}

	return pCalled->Enhance(nAptitudeAdd);
}

//----------------------------------------------------------------------------------------------------
// 召唤的宠物升阶
//----------------------------------------------------------------------------------------------------
DWORD PetPocket::CalledSoulUpStep( INT64 n64ItemID, DWORD &dwSkillID, INT &nDstStep)
{
	if (VALID_VALUE(n64ItemID) && VALID_VALUE(m_dwPetIDForUpStep))
	{
		m_dwPetIDForUpStep = INVALID_VALUE;
	}
	if (VALID_VALUE(n64ItemID) && !VALID_VALUE(m_dwPetIDForUpStep))
	{
		dwSkillID = INVALID_VALUE;
		nDstStep = INVALID_VALUE;

		M_trans_else_ret(pCalled, GetCalledPetSoul(), PetSoul, E_Pets_Pet_NotCalled);
		M_trans_else_ret(pItem, m_pMaster->GetItemMgr().GetBagItem(n64ItemID), tagItem, E_Pets_ItemNotValid);
		if (pItem->pProtoType->eSpecFunc != EISF_PetLvlupStep)
		{
			return E_Pets_ItemNotValid;
		}

		if (pItem->pProtoType->nSpecFuncVal1 != pCalled->GetPetAtt().GetStep() + 1)
		{
			return E_Pets_ItemNotValid;
		}

		if (pItem->pProtoType->byMinUseLevel > m_pMaster->get_level())
		{
			return E_Pets_ItemNotValid;
		}

		nDstStep = pCalled->GetPetAtt().GetStep() + 1;

		const tagPetLvlUpItemProto* pLvlUpItemProto = AttRes::GetInstance()->GetPetLvlUpItemProto(pItem->dw_data_id);
		if (!VALID_POINT(pLvlUpItemProto))
		{
			dwSkillID = INVALID_VALUE;
		}
		else
		{
			INT nSkillIndex = get_tool()->rand_in_range(1, pItem->pProtoType->nSpecFuncVal2);
			dwSkillID = pLvlUpItemProto->dwSkillIDs[nSkillIndex - 1];
		}
		m_dwPetIDForUpStep = pCalled->GetID();
		m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_pet_enhance);

		return E_Pets_Success;
	}
	else if (VALID_VALUE(nDstStep) && !VALID_VALUE(n64ItemID) && VALID_VALUE(m_dwPetIDForUpStep))
	{
		PetSoul* pUpSoul = GetPetSoul(m_dwPetIDForUpStep);
		if (nDstStep != pUpSoul->GetPetAtt().GetStep() + 1)
		{
			return E_Pets_ItemNotValid;
		}
		m_dwPetIDForUpStep = INVALID_VALUE;
		return pUpSoul->UpStep(dwSkillID);
	}
	else
	{
		ASSERT(0);
		return INVALID_VALUE;
	}
	
}

DWORD PetPocket::LockPet( DWORD dwPetID, INT64 n64ItemID )
{
	// 获得宠物
	M_trans_else_ret(pToLock, GetPetSoul(dwPetID), PetSoul, E_Pets_Pet_NotExist);

	// 获得物品
	M_trans_else_ret(pItem, m_pMaster->GetItemMgr().GetBagItem(n64ItemID), tagItem, E_Pets_ItemNotValid);
	if (pItem->pProtoType->eSpecFunc != EISF_PetLock)
	{
		return E_Pets_ItemNotValid;
	}

	// 宠物可锁定
	if (pToLock->IsLocked())
	{
		return E_Pets_Lock_AlreadyLocked;
	}
	// 扣除物品
	if(E_Success == m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_pet_lock))
	{
		// 锁定
		pToLock->SetLocked(TRUE);
	}
	return E_Success;
}

DWORD PetPocket::UnLockPet( DWORD dwPetID, INT64 n64ItemID )
{
	// 获得宠物
	M_trans_else_ret(pToUnLock, GetPetSoul(dwPetID), PetSoul, E_Pets_Pet_NotExist);

	// 获得物品
	M_trans_else_ret(pItem, m_pMaster->GetItemMgr().GetBagItem(n64ItemID), tagItem, E_Pets_ItemNotValid);
	if (pItem->pProtoType->eSpecFunc != EISF_PetUnLock)
	{
		return E_Pets_ItemNotValid;
	}

	// 宠物可解锁
	if (!pToUnLock->IsLocked())
	{
		return E_Pets_Lock_NotLocked;
	}
	// 扣除物品
	if(E_Success == m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_pet_unlock))
	{
		// 解锁
		pToUnLock->SetLocked(FALSE);
	}

	return E_Success;
}

DWORD PetPocket::InitRandomSkill(DWORD dwPetID)
{
	PetSoul* pSoul = GetPetSoul(dwPetID);
	if (!VALID_POINT(pSoul))
		return FALSE;

	//生成随机技能
	pSoul->InitRandomSkill();
	// 学会自动拾取技能
	pSoul->LearnSkill(PET_PICKUP_SKILL_ID);
	return TRUE;
}

DWORD PetPocket::CalledPetFeed( INT64 n64ItemID, DWORD dwFoodType)
{
	PetSoul* pCalledSoul = GetCalledPetSoul();
	if (!VALID_POINT(pCalledSoul))
	{
		return E_Pets_Soul_NotExist;
	}
	
	// 没召唤出来不能喂食
	if (!pCalledSoul->IsCalled())
		return E_Pets_Food_NotInCalld;

	tagItem* pItem = m_pMaster->GetItemMgr().GetBagItem(n64ItemID);

	if (!VALID_POINT(pItem) )
		return E_Pets_ItemNotValid;

	// 普通喂食
	if (0 == dwFoodType)
	{

		if (!VALID_POINT(pItem) || !MISPETFOOD(pItem->pProtoType) /*|| pItem->pProtoType->eSpecFunc != EISF_PetFood*/)
			return E_Pets_ItemNotValid;
		
		INT32 nAddHappyValue =  pItem->pProtoType->nSpecFuncVal2;
		// 食物等级判断
		if (pCalledSoul->GetPetAtt().GetVLevel() > pItem->pProtoType->nSpecFuncVal1)
		{
			nAddHappyValue = nAddHappyValue * 0.5f;
		}
		
		// 是否吃该类型的食物
		if (!pCalledSoul->GetPetAtt().IsPetEatFood(pItem->pProtoType->eTypeReserved))
			return E_Pets_Food_NotEat;

		//提高开心度
		pCalledSoul->GetPetAtt().ModAttVal(epa_happy_value, nAddHappyValue);

		//重置开心度计时
		pCalledSoul->GetBody()->ResetHappyTimeCount();
		
		m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_pet_food);

		if(VALID_POINT(m_pMaster->GetScript()))
		{
			m_pMaster->GetScript()->OnPetFeed(m_pMaster);
		}

	}
	// 道具赠与
	else if(1 == dwFoodType)
	{
		if (!MIsEquipment(n64ItemID) || MEquipIsRide(pItem->pProtoType))
			return E_Pets_Food_NotEquip;
		
		tagEquip* pEquip = (tagEquip*)pItem;
		//增加经验 暂时固定增加10点
		//pCalledSoul->GetPetAtt().ExpChange(10, 1);

		//修改为公式计算 所加经验=物品等级*(1+品级*0.5)/2
		FLOAT fAddExp = (pEquip->pEquipProto->byLevel + 1) * (1 + pEquip->equipSpec.byQuality * 0.5f) / 2;
		pCalledSoul->GetPetAtt().ExpChange((INT)fAddExp, TRUE);

		////提高开心度
		//pCalledSoul->GetPetAtt().ModAttVal(epa_happy_value, 1);
		//
		////重置开心度计时
		//pCalledSoul->GetBody()->ResetHappyTimeCount();

		m_pMaster->GetItemMgr().DelFromBag(n64ItemID, elcid_pet_item_pet_food, 1);
	}
	//增加宠物生命
	else if(2 == dwFoodType)
	{
		if (!VALID_POINT(pItem) || pItem->pProtoType->eTypeReserved != EITR_PETFOOD_ADDHP /*|| pItem->pProtoType->eSpecFunc != EISF_PetFood*/)
			return E_Pets_ItemNotValid;
		
		pCalledSoul->GetPetAtt().ModAttVal(epa_spirit, pItem->pProtoType->nSpecFuncVal2);

		m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_pet_food);
	}
	return E_Pets_Success;


	//DWORD dwRtv = pCalledSoul->Feed(pItem->pProtoType->nSpecFuncVal2);

	//if (E_Pets_Success == dwRtv)
	//{
	//	m_pMaster->GetItemMgr().ItemUsedFromBag(n64ItemID, 1, elcid_pet_item_pet_food);
	//}

	//return dwRtv;
}

//复活宠物
DWORD PetPocket::RebornPet(DWORD dwPetID, INT64 dw64ItemID)
{
	//all precondition
	if( !VALID_POINT(m_pMaster) ||
		!IS_PET(dwPetID)	
		)
	{
		//ASSERT(0);
		return E_Pets_UnkownErr;
	}

	PetSoul* pCalledSoul = GetPetSoul(dwPetID);
	if (!VALID_POINT(pCalledSoul))
	{
		//ASSERT(0);
		return E_Pets_Soul_NotExist;
	}

	tagItem* pItem = m_pMaster->GetItemMgr().GetBagItem(dw64ItemID);

	if (!VALID_POINT(pItem) || pItem->pProtoType->eSpecFunc != EIST_Pet_Roborn)
		return E_Pets_ItemNotValid;

	if (pCalledSoul->GetPetAtt().GetAttVal(epa_quality) != pItem->pProtoType->nSpecFuncVal1 )
		return E_Pets_ItemNotValid;

	pCalledSoul->GetPetAtt().UnSetPetState(EPS_Dead);

	m_pMaster->GetItemMgr().ItemUsedFromBag(dw64ItemID, 1, elcid_pet_item_pet_food);
	return E_Pets_Success;
}	

//染色
DWORD PetPocket::PetColor(DWORD dwPetID, INT nColor )
{
	//all precondition
	if( !VALID_POINT(m_pMaster) ||
		!IS_PET(dwPetID)	
		)
	{
		//ASSERT(0);
		return E_Pets_UnkownErr;
	}

	PetSoul* pCalledSoul = GetPetSoul(dwPetID);
	if (!VALID_POINT(pCalledSoul))
	{
		//ASSERT(0);
		return E_Pets_Soul_NotExist;
	}
	
	if (nColor < 0 || nColor > 4)
	{
		return E_Pets_color_not_true;
	}
	
	if (pCalledSoul->IsCalled())
	{
		return E_PetS_color_has_called;
	}

	INT64 nSilver = 1000000;
	if (m_pMaster->GetCurMgr().GetBagSilver() < nSilver)
	{
		return E_Pets_color_not_silver;
	}

	pCalledSoul->GetPetAtt().SetAttVal(epa_color, nColor);
	
	m_pMaster->GetCurMgr().DecBagSilver(nSilver, elcid_pet_color);
	
	m_pMaster->GetAchievementMgr().UpdateAchievementCriteria(ete_pet_ranse, 1);	

	return E_Pets_Success;
}

//蜕变
DWORD PetPocket::PetChange(DWORD dwPetID, INT64 dw64ItemID)
{
	if( !VALID_POINT(m_pMaster) ||
		!IS_PET(dwPetID)	
		)
	{
		//ASSERT(0);
		return E_Pets_UnkownErr;
	}

	PetSoul* pCalledSoul = GetPetSoul(dwPetID);
	if (!VALID_POINT(pCalledSoul))
	{
		//ASSERT(0);
		return E_Pets_Soul_NotExist;
	}

	if (pCalledSoul->GetPetAtt().GetVLevel() < MIN_CHANGE_LEVEL || 
		pCalledSoul->GetPetAtt().GetVLevel() >= MAX_PET_VLEVEL)
	{
		return E_PetS_Change_level_not;
	}
	
	if (pCalledSoul->IsCalled())
	{
		return INVALID_VALUE;
	}

	tagItem* pItem = m_pMaster->GetItemMgr().GetBagItem(dw64ItemID);
	if (!VALID_POINT(pItem) || pItem->pProtoType->eSpecFunc != EIST_Pet_Change)
	{
		return E_PetS_Change_item_not;
	}
	
	if(pItem->pProtoType->nSpecFuncVal1 != pCalledSoul->GetPetAtt().GetVLevel())
	{
		return E_PetS_Change_item_level_not;
	}

	if (!pCalledSoul->GetPetAtt().UpStep())
	{
		return E_PetS_Change_level_not;
	}
	
	
	m_pMaster->GetItemMgr().ItemUsedFromBag(dw64ItemID, 1, elcid_role_pour_exp_pet);


	return E_Pets_Success;
}

DWORD PetPocket::PetAddPoint(DWORD dwPetID, BYTE byType, INT nValue)
{
	if( !VALID_POINT(m_pMaster) ||
		!IS_PET(dwPetID)	
		)
	{
		return E_Pets_UnkownErr;
	}

	PetSoul* pSoul = GetPetSoul(dwPetID);
	if (!VALID_POINT(pSoul))
	{
		return E_Pets_Soul_NotExist;
	}

	if (byType < 0 || byType > 2)
		return INVALID_VALUE;

	if (pSoul->GetPetAtt().GetAttVal(epa_att_point) < nValue)
		return E_PetS_AddPoint_not_point;

	INT nPetAtt = 0;
	INT nRoleAtt = 0;
	switch(byType)
	{
	case 0:
		nPetAtt = epa_strength;
		nRoleAtt = ERA_Strength;
		break;
	case 1:
		nPetAtt = epa_agility;
		nRoleAtt = ERA_Agility;
		break;
	case 2:
		nPetAtt = epa_innerForce;
		nRoleAtt = ERA_InnerForce;
		break;
	default:
		break;
	}
	pSoul->GetPetAtt().ModAttVal(nPetAtt, nValue);
	pSoul->GetPetAtt().ModAttVal(epa_att_point, -nValue);
	
	if (pSoul->IsCalled())
	{
		m_pMaster->ModAttModValue(nRoleAtt, nValue);
		m_pMaster->RecalAtt();
	}


	NET_DB2C_update_pet_soul send;
	pSoul->GetPetAtt().SaveToDB(&send.pet_att);
	send.n_pet_soul_num = 1;
	g_dbSession.Send(&send, send.dw_size);

	return E_Pets_Success;
}

// 宠物融合
DWORD PetPocket::FusionPet(DWORD dwPetID1, DWORD dwPetID2, INT64 dw64ItemID1)
{
	if( !VALID_POINT(m_pMaster) ||
		!IS_PET(dwPetID1) ||
		!IS_PET(dwPetID2)
		)
	{
		return E_Pets_UnkownErr;
	}

	PetSoul* pCalledSoul1 = GetPetSoul(dwPetID1);
	PetSoul* pCalledSoul2 = GetPetSoul(dwPetID2);
	if (!VALID_POINT(pCalledSoul1) || !VALID_POINT(pCalledSoul2))
	{
		return E_Pets_Soul_NotExist;
	}
	
	if (pCalledSoul1->GetProtoID() != pCalledSoul2->GetProtoID())
	{
		return INVALID_VALUE;
	}

	if (pCalledSoul1->IsCalled() || pCalledSoul1->IsWorking() || 
		pCalledSoul1->GetPetAtt().IsPetInState(EPS_Dead) || pCalledSoul1->GetPetAtt().IsPetInState(EPS_Xiulian) ||
		pCalledSoul2->IsCalled() || pCalledSoul2->IsWorking() ||
		pCalledSoul2->GetPetAtt().IsPetInState(EPS_Dead) || pCalledSoul2->GetPetAtt().IsPetInState(EPS_Xiulian))
	{
		return E_Pets_Fusion_Is_Called;
	}

	INT nPet1Quality = pCalledSoul1->GetPetAtt().GetAttVal(epa_quality);
	if ( nPet1Quality>=4 )
	{
		return E_Pets_Fusion_Quality_Not;
	}

	INT nQualitySub = nPet1Quality - pCalledSoul2->GetPetAtt().GetAttVal(epa_quality);
	if (nQualitySub != 0)
	{
		return E_Pets_Fusion_Quality_Not;
	}
	
	if (pCalledSoul1->GetPetAtt().GetVLevel() < nPet1Quality+1)
	{
		return E_Pets_Funion_Level_Not;
	}

	//融合消耗金币公式=(（主宠物品质+1）*2)^（主宠物品质+1）*500
	INT64 nSilver = pow((nPet1Quality + 1) * 2.0, (nPet1Quality+1)) * 500;
	if (m_pMaster->GetCurMgr().GetBagSilver() < nSilver )
		return E_Pets_Fusion_Not_Money;

	//培元丹提升的概率
	//INT nAddPro = 0;
	//const tagItemProto* pItemProto = AttRes::GetInstance()->GetItemProto(dwItemID3);
	//if (VALID_POINT(pItemProto) && dwItem3Num > 0 && pItemProto->eSpecFunc == EIST_Pet_Fusion && pItemProto->nSpecFuncVal1 == 2)
	//{

	//	package_list<tagItem*> itemList;
	//	INT32 n32num = m_pMaster->GetItemMgr().GetBag().GetSameItemList(itemList, dwItemID3, dwItem3Num);

	//	n32num = min(10, n32num);

	//	nAddPro = n32num * PetHelper::getFusionProPeiYuan(nPet1Quality);

	//	m_pMaster->GetItemMgr().DelBagSameItem(itemList, n32num, elcid_npc_shengxin);

	//}

	//BOOL bUseHuyuan = FALSE;
	//BOOL bUseguyuan = FALSE;

	//tagItem* pItem1 = m_pMaster->GetItemMgr().GetBagItem(dw64ItemID1);
	//if (VALID_POINT(pItem1) && pItem1->pProtoType->eSpecFunc == EIST_Pet_Fusion && pItem1->pProtoType->nSpecFuncVal1 == 0)
	//{
	//	bUseHuyuan = TRUE;
	//}

	//tagItem* pItem2 = m_pMaster->GetItemMgr().GetBagItem(dw64ItemID2);
	//if (VALID_POINT(pItem2) && pItem2->pProtoType->eSpecFunc == EIST_Pet_Fusion && pItem2->pProtoType->nSpecFuncVal1 == 1)
	//{
	//	bUseguyuan = TRUE;
	//}

	DWORD dwResule = E_Success;
	BOOL bSuccess = (get_tool()->tool_rand() % 10000) < (PetHelper::getFusionPro(nPet1Quality) );
	if (bSuccess)
	{
		// 提升主宠的品质
		pCalledSoul1->GetPetAtt().ModAttVal(epa_quality, 1);
		
		m_pMaster->GetAchievementMgr().UpdateAchievementCriteria(ete_pet_have_quality, pCalledSoul1->GetPetAtt().GetAttVal(epa_quality));

		pCalledSoul1->GetPetAtt().SetAttVal(epa_strength, 0);
		pCalledSoul1->GetPetAtt().SetAttVal(epa_agility, 0);
		pCalledSoul1->GetPetAtt().SetAttVal(epa_innerForce, 0);
		pCalledSoul1->GetPetAtt().SetAttVal(epa_att_point, 0);

		NET_SIS_get_pet_display_info sendClient;
		sendClient.dwPetID = pCalledSoul1->GetID();
		pCalledSoul1->GetPetAtt().GetName(sendClient.DispData.szName);
		sendClient.DispData.byQuality = pCalledSoul1->GetPetAtt().GetAttVal(epa_quality);
		sendClient.DispData.n_color = pCalledSoul1->GetPetAtt().GetAttVal(epa_color);
		m_pMaster->get_map()->send_big_visible_tile_message(m_pMaster, &sendClient, sendClient.dw_size);


		// 主宠等级归1
		//if (!bUseHuyuan)
		//{
			pCalledSoul1->GetPetAtt().ChangeLevel(1, TRUE);
		//}

		
		//tagItem* pItem = m_pMaster->GetItemMgr().GetBagItem(dw64ItemID1);
		//if (VALID_POINT(pItem) && pItem->pProtoType->eSpecFunc == EIST_Pet_Fusion)
		//{
		//	pCalledSoul1->RemoveBuffSkill();
		//	DWORD dwSkillTypeID = pCalledSoul2->GetBuffSkill();

		//	if (dwSkillTypeID != INVALID_VALUE)
		//	{
		//		pCalledSoul1->LearnSkill(dwSkillTypeID);
		//	}
		//	
		//	m_pMaster->GetItemMgr().ItemUsedFromBag(dw64ItemID1, 1, elcid_pet_item_fusion);
		//}

		// 处理技能升级
		pCalledSoul1->OnLevelUp();

		// 学习副宠的主动合体技能
		//if (!pCalledSoul1->HasActiveSkill())
		//{
		//	DWORD dwSkillTypeID = pCalledSoul2->GetActiveSkill();
		//	if (dwSkillTypeID != INVALID_VALUE)
		//	{
		//		//DWORD dwSkillNewTypeID = MTransPetSkillTypeID(dwSkillTypeID/100, pCalledSoul1->GetPetAtt().GetVLevel());

		//		pCalledSoul1->LearnSkill(dwSkillTypeID);
		//	}
		//}

		//// 学习其他技能
		//INT nLearnNum = MAX_PET_NORMAL_SKILL_NUM - pCalledSoul1->GetSkillNum(EPT_Specialty);
		//{
		//	PetSkill* pPetSkill = NULL;
		//	PetSoul::PetSkillMap::map_iter itr = pCalledSoul2->m_mapPetSkill.begin();

		//	while (	pCalledSoul2->m_mapPetSkill.find_next(itr, pPetSkill))
		//	{
		//		if (nLearnNum <= 0)
		//			break;

		//		if (pPetSkill->GetProto()->eType2 == EPT2_Passive)
		//		{
		//			if (!pCalledSoul1->HasSkill(pPetSkill->GetProto()->dw_data_id/100))
		//			{
		//				pCalledSoul1->LearnSkill(pPetSkill->GetProto()->dw_data_id);
		//				nLearnNum--;
		//			}
		//		}
		//	}
		//}

		//删除副宠
		PetSoul* pSoul = GetAway(dwPetID2, TRUE);
		if (VALID_POINT(pSoul))
		{
			PetSoul::DeleteSoul(pSoul, TRUE);
		}

	}
	else
	{

		pCalledSoul2->GetPetAtt().SetPetState(EPS_Dead);

		// 主宠消失
		//if (!bUseguyuan)
		//{
		//	if ((get_tool()->tool_rand() % 10000) < 5000)
		//	{
		//		PetSoul* pSoul = GetAway(dwPetID1, TRUE);
		//		if (VALID_POINT(pSoul))
		//		{
		//			PetSoul::DeleteSoul(pSoul, TRUE);
		//		}
		//	}
		//}

		dwResule = E_Pets_Funion_fail;
	}
	
	if ((nPet1Quality >= 2 && bSuccess))
	{
		HearSayHelper::SendMessage(EHST_Ronghe_pet,
			m_pMaster->GetID(), nPet1Quality,  bSuccess, INVALID_VALUE, INVALID_VALUE, NULL);
	}
	

	//if (bUseHuyuan)
	//{
	//	m_pMaster->GetItemMgr().ItemUsedFromBag(dw64ItemID1, 1, elcid_pet_item_fusion);
	//}
	//if (bUseguyuan)
	//{
	//	m_pMaster->GetItemMgr().ItemUsedFromBag(dw64ItemID2, 1, elcid_pet_item_fusion);
	//}

	m_pMaster->GetCurMgr().DecBagSilver(nSilver, elcid_pet_item_fusion);

	return dwResule;
}


//宠物寄养
DWORD PetPocket::petXiulian(DWORD dwPetID, DWORD dwNpcID, DWORD dwTimeType, DWORD dwModeType)
{
	Creature* pNPC = m_pMaster->get_map()->find_creature(dwNpcID);
	if( !VALID_POINT(pNPC)) 
		return E_Compose_NPC_Not_Exist;

	if( FALSE == pNPC->CheckNPCTalkDistance(m_pMaster) )
		return E_Compose_NPC_Distance;

	if( FALSE == pNPC->IsFunctionNPC(EFNPCT_Pet_Xiulian) )
		return E_Compose_NPCCanNotCompose;
	
	PetSoul* pSoul = GetPetSoul(dwPetID);
	if (!VALID_POINT(pSoul))
		return INVALID_VALUE;

	if (!pSoul->CanSetXiulian())
		return E_Pets_Xiulian_Cant;
	
	if (GetXiulianNumber() >= m_pMaster->get_pet_xiulian_size())
		return E_Pets_Xiulian_Full;

	INT64 nMonery = RoleHelper::GetPetXiulianTimeSilver(dwTimeType);
	INT32 nYuanbao = RoleHelper::GetPetXiulianModeYuanbao(dwModeType);
	
	if (m_pMaster->GetCurMgr().GetBagSilver() < nMonery)
		return E_Pets_Xiulian_Not_Sivler;

	if (m_pMaster->GetCurMgr().GetBaiBaoYuanBao() < nYuanbao)
		return E_Pets_Xiulian_Not_Yuanbao;
	
	pSoul->GetPetAtt().SetXiulianTime(g_world.GetWorldTime());
	pSoul->GetPetAtt().SetTimeType(dwTimeType);
	pSoul->GetPetAtt().SetModeType(dwModeType);
	pSoul->GetPetAtt().SetPetState(EPS_Xiulian);

	m_pMaster->GetCurMgr().DecBagSilver(nMonery, elcid_pet_xiulian);
	m_pMaster->GetCurMgr().DecBaiBaoYuanBao(nYuanbao, elcid_pet_xiulian);


	return E_Pets_Success;
}

//宠物寄养收回
DWORD PetPocket::petXiulianRetrun(DWORD dwPetID)
{
	PetSoul* pSoul = GetPetSoul(dwPetID);
	if (!VALID_POINT(pSoul))
		return INVALID_VALUE;
	
	if (!pSoul->GetPetAtt().IsPetInState(EPS_Xiulian))
		return E_Pets_XiulianReturn_cant;

	DWORD dwFen = CalcTimeDiff(g_world.GetWorldTime(), (pSoul->GetPetAtt().GetXiulianTime())) / 60;
	DWORD dwTime = RoleHelper::GetPetXiulianTime(pSoul->GetPetAtt().GetTimeType());

	dwFen = min(dwFen, dwTime);

	INT dwExp = RoleHelper::GetPetXiulianModeExp(pSoul->GetPetAtt().GetModeType());
	
	pSoul->GetPetAtt().ExpChange(dwExp * dwFen, TRUE);

	pSoul->GetPetAtt().UnSetPetState(EPS_Xiulian);

	return E_Pets_Success;
}