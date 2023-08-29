/*******************************************************************************

	Copyright 2010 by tiankong Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	tiankong Interactive  Co., Ltd.

*******************************************************************************/

/**
 *	@file		GMServerHandler_Save
 *	@author		mwh
 *	@date		2011/09/01	initial
 *	@version	0.0.1.0
 *	@brief		保存数据
*/

#include "stdafx.h"
#include "GMServerHanlder.h"
#include "GMPlayer.h"
#include "LogDB.h"
#include "GMLogQueryManager.h"
#include "GMLogHelper.h"
#include "GMSaveDataCheck.h"
#include "ServerPlayer.h"
#include "../../common/WorldDefine/GMSaveProtocol.h"
#include "../../common/WorldDefine/currency_define.h"
#include "../common/ServerDefine/GMServerMessage.h"

#define ErrorProtocolReturn(PMSG, TYPE, RET)\
	if(PMSG->dw_size != sizeof(TYPE)){ ErrMessage(_T("\n!!Protocol[%s]'s size error!!\n"), _T(#TYPE)); return RET;}

//! 保存角色基础数据
DWORD GMServerHanlder::HandleSaveRoleBasic(tag_net_message* pMsg, DWORD dwParam)
{
	ErrorProtocolReturn(pMsg, NET_C2GMS_SaveRoleBasicData, -1);

	NET_C2GMS_SaveRoleBasicData* xProtocol = (NET_C2GMS_SaveRoleBasicData*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	
	NET_GMS2C_SaveRoleBasicData send;
	send.dwRoleID = xProtocol->dwRoleID;
	send.dwError = E_SystemError;
	if(VALID_POINT(pDB) && EditToolDataCheck(&xProtocol->stRoleSaveBasic)) 
	{
		//! 取得原有的
		DWORD dwSize ; INT nNumber;

		DWORD dwOldYuanBao = pDB->get_account_yuanbao(xProtocol->dwAccountID);
		tag_role_data stOldData;
		pDB->get_role_basic("role_data", &stOldData, xProtocol->dwAccountID, xProtocol->dwRoleID, dwSize, nNumber);

		////! 更新元宝
		//send.dwError = pDB->save_account_yuanbao("account_common", &xProtocol->stRoleSaveBasic,
		//	xProtocol->dwAccountID, xProtocol->dwRoleID);

		////! yuanbao log
		//INT yuanbao_diff = xProtocol->stRoleSaveBasic.dw_yuanbao - dwOldYuanBao;
		//g_GMPlayerManager.WriteYuanBaoLog(xGMPlayer, xProtocol->dwAccountID, ELCT_BaiBao,
		//	 yuanbao_diff, xProtocol->stRoleSaveBasic.dw_yuanbao);

		//! 更新金钱
		send.dwError = pDB->save_role_basic("role_data", &xProtocol->stRoleSaveBasic,
			xProtocol->dwAccountID, xProtocol->dwRoleID, 1, sizeof(xProtocol->stRoleSaveBasic));

		// 金钱计算宏
#define CalcMoney2Copper(ST, Pre, Var)\
	INT64 Var = MGold2Silver((ST.Pre##_gold)) + MGold2Silver((ST.Pre##_silver)+ST.Pre##_copper);

		////! bind money log
		//CalcMoney2Copper(stOldData, n_bag_bind, bind_money_old);
		//CalcMoney2Copper(xProtocol->stRoleSaveBasic, n_bag_bind, bind_money_new);
		//g_GMPlayerManager.WriteMoneyLog(xGMPlayer, xProtocol->dwRoleID, 
		//	ELCT_BagBind, bind_money_new - bind_money_old, bind_money_new);

		//! money log
		CalcMoney2Copper(stOldData, n_bag, money_old);
		CalcMoney2Copper(xProtocol->stRoleSaveBasic, n_bag, money_new);
		g_GMPlayerManager.WriteMoneyLog(xGMPlayer, xProtocol->dwRoleID, 
			ELCT_Bag, money_new - money_old, money_new);

		//! ware money
		/*CalcMoney2Copper(stOldData, n_ware, ware_money_old);
		CalcMoney2Copper(xProtocol->stRoleSaveBasic, n_ware, ware_money_new)
		g_GMPlayerManager.WriteMoneyLog(xGMPlayer, xProtocol->dwRoleID, ELCT_RoleWare,
			ware_money_new - ware_money_old, ware_money_new);*/
#undef CalcMoney2Copper 		
	}
	xGMPlayer->SendMessage(&send, send.dw_size);

	return E_Success;
}

//! 保存角色技能
DWORD GMServerHanlder::HandleSaveRoleSkill(tag_net_message* pMsg, DWORD dwParam)
{
	ErrorProtocolReturn(pMsg, NET_C2GMS_SaveRoleSkill, -1);

	NET_C2GMS_SaveRoleSkill* xProtocol = (NET_C2GMS_SaveRoleSkill*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));

	NET_GMS2C_SaveRoleSkill send;
	send.dwRoleID = xProtocol->dwRoleID;
	send.dwError = E_SystemError;

	if(VALID_POINT(pDB) && EditToolDataCheck(&xProtocol->stRoleSkillSave))
	{
		send.dwError = pDB->save_role_skill("skill", &xProtocol->stRoleSkillSave, INVALID_VALUE, 
										xProtocol->dwRoleID, 1, sizeof(xProtocol->stRoleSkillSave));
		g_GMPlayerManager.WriteGMLog( xGMPlayer, send.dwError, 
			LogHelper(_T("修改角色[%u]的技能"), xProtocol->dwRoleID));
	}
	xGMPlayer->SendMessage(&send, send.dw_size);

	return E_Success;
}

//! 保存宠物
DWORD GMServerHanlder::HandleSaveRolePet(tag_net_message* pMsg, DWORD dwParam)
{
	ErrorProtocolReturn(pMsg, NET_C2GMS_SaveRolePet, -1);
	NET_C2GMS_SaveRolePet* xProtocol = (NET_C2GMS_SaveRolePet*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));

	NET_GMS2C_SaveRolePet send;
	send.dwRoleID = xProtocol->dwRoleID;
	send.dwError = E_SystemError;
	if(VALID_POINT(pDB) && EditToolDataCheck(&xProtocol->stRolePetSave))
	{
		send.dwError = pDB->save_role_pet("", &xProtocol->stRolePetSave, INVALID_VALUE,
			xProtocol->dwRoleID, 1, sizeof(xProtocol->stRolePetSave));

		//if(send.dwError == E_Success)
		//	send.dwError = pDB->save_role_pet_skill("", &xProtocol->stRolePetSave, INVALID_VALUE, INVALID_VALUE, 1, 0);

		g_GMPlayerManager.WriteGMLog( xGMPlayer, send.dwError, 
			LogHelper(_T("修改角色[%u],宠物[%d]数据"), xProtocol->dwRoleID, xProtocol->stRolePetSave.dw_id));
	}
	xGMPlayer->SendMessage(&send, send.dw_size);

	return E_Success;
}

//! 保存装备
DWORD GMServerHanlder::HandleSaveRoleEquip(tag_net_message* pMsg, DWORD dwParam)
{
	ErrorProtocolReturn(pMsg, NET_C2GMS_SaveRoleEquip, -1);
	NET_C2GMS_SaveRoleEquip* xProtocol = (NET_C2GMS_SaveRoleEquip*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));

	NET_GMS2C_SaveRoleEquip send;
	send.dwRoleID = xProtocol->dwRoleID;
	send.dwRoleID = E_SystemError;
	if(VALID_POINT(pDB) && EditToolDataCheck(&xProtocol->stRoleEquipSave))
	{
		send.dwError = pDB->save_role_equip("", &xProtocol->stRoleEquipSave, 
			INVALID_VALUE,xProtocol->dwRoleID, 1, sizeof(xProtocol->stRoleEquipSave));
		g_GMPlayerManager.WriteGMLog( xGMPlayer, send.dwError, 
			LogHelper(_T("修改角色[%u],装备[%I64d]"), xProtocol->dwRoleID, xProtocol->stRoleEquipSave.n64_serial));
	}
	xGMPlayer->SendMessage(&send, send.dw_size);

	return E_Success;
}

//! 制造装备
DWORD GMServerHanlder::HandleGMCreateEquip(tag_net_message* pMsg, DWORD dwParam)
{
	ErrorProtocolReturn(pMsg, NET_C2GMS_GMCreateEquip, -1);
	NET_C2GMS_GMCreateEquip* xProtocol = (NET_C2GMS_GMCreateEquip*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pServerPlayer))
	{
		NET_GMS2S_GMCreateEquip send;
		send.dwClientID = xGMPlayer->GetID( );
		send.dwRoleID = xProtocol->dwRoleID;
		get_fast_code()->memory_copy(&send.stEquipCreate, &xProtocol->stEquipCreate, sizeof(send.stEquipCreate));
		pServerPlayer->SendMessage(&send, send.dw_size);

		g_GMPlayerManager.WriteGMLog( xGMPlayer, 0, 
			LogHelper(_T("给角色[%u]装备类型ID[%u]"), xProtocol->dwRoleID, xProtocol->stEquipCreate.dw_data_id));
	}

	return E_Success;
}
//! 根据玩家名称制造物品用于批量发放道具
//gx add 2013.11.05
DWORD GMServerHanlder::HandleGMCreateItemByRoleName(tag_net_message* pMsg,DWORD dwParam)
{
	ErrorProtocolReturn(pMsg, NET_C2GMS_GMCreateItem_Serial, -1);
	NET_C2GMS_GMCreateItem_Serial* xProtocol = (NET_C2GMS_GMCreateItem_Serial*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pServerPlayer))
	{
		//获取该玩家名称对应的roleID
		DWORD dwRoleID = INVALID_VALUE;
		LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
		if (!VALID_POINT(pDB))
			return 0;
		dwRoleID = pDB->get_roleid_by_role_name(get_tool()->crc32(xProtocol->szRoleName));
		//end
		NET_GMS2S_GMCreateItem send;
		send.dwClientID = xGMPlayer->GetID( );
		send.dwRoleID = dwRoleID;
		get_fast_code()->memory_copy(&send.stItemCreate, &xProtocol->stItemCreate, sizeof(send.stItemCreate));
		pServerPlayer->SendMessage(&send, send.dw_size);

		g_GMPlayerManager.WriteGMLog( xGMPlayer, 0, 
			LogHelper(_T("给角色[%u]物品类型ID[%u]数量[%d]"), dwRoleID, 
			xProtocol->stItemCreate.dw_data_id, xProtocol->stItemCreate.n16Number));
	}

	return E_Success;
}
//! 制造物品
DWORD GMServerHanlder::HandleGMCreateItem(tag_net_message* pMsg, DWORD dwParam)
{
	ErrorProtocolReturn(pMsg, NET_C2GMS_GMCreateItem, -1);
	NET_C2GMS_GMCreateItem* xProtocol = (NET_C2GMS_GMCreateItem*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pServerPlayer))
	{
		NET_GMS2S_GMCreateItem send;
		send.dwClientID = xGMPlayer->GetID( );
		send.dwRoleID = xProtocol->dwRoleID;
		get_fast_code()->memory_copy(&send.stItemCreate, &xProtocol->stItemCreate, sizeof(send.stItemCreate));
		pServerPlayer->SendMessage(&send, send.dw_size);

		g_GMPlayerManager.WriteGMLog( xGMPlayer, 0, 
			LogHelper(_T("给角色[%u]物品类型ID[%u]数量[%d]"), xProtocol->dwRoleID, 
			xProtocol->stItemCreate.dw_data_id, xProtocol->stItemCreate.n16Number));
	}

	return E_Success;
}

//! 发钱
DWORD GMServerHanlder::HandleGiveMoney(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_GMGiveMoney* xProtocol = (NET_C2GMS_GMGiveMoney*)(pMsg);
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	ServerPlayer* pServerPlayer = g_ServerPlayerMgr.GetGameServerPlayer(get_tool()->crc32(xProtocol->szServerName));
	if(VALID_POINT(pServerPlayer))
	{
		NET_GMS2S_GMGiveMoney send;
		send.dwClientID = xGMPlayer->GetID( );
		send.dwMoney = xProtocol->dwMoney;
		send.dwYuanBao = xProtocol->dwYuanBao;
		send.dwRoleID = xProtocol->dwRoleID;
		pServerPlayer->SendMessage(&send, send.dw_size);

		g_GMPlayerManager.WriteGMLog(xGMPlayer->GetID(), 0,
			LogHelper(_T("给[%d] 发送元宝[%d],非绑定金币[%d]!"), send.dwRoleID, send.dwYuanBao, send.dwMoney));
	}

	return E_Success;
}
//！ 删除物品&&装备
DWORD GMServerHanlder::HandleDeleteRoleItem(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_DeleteItem* xProtocol = (NET_C2GMS_DeleteItem*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);
	
	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));
	
	NET_GMS2C_DeleteItem send;
	send.serial = xProtocol->serial;
	send.dw_role_id = xProtocol->dw_role_id;
	send.bSuccess = FALSE;
	if(VALID_POINT(pDB))
	{
		if(MIsEquipment(xProtocol->dw_type_id))
			send.bSuccess = pDB->delete_role_equip("", xProtocol, -1, xProtocol->dw_role_id, 1, 0);
		else
			send.bSuccess = pDB->delete_role_item("", xProtocol, -1, xProtocol->dw_role_id, 1, 0);
		g_GMPlayerManager.WriteGMLog( xGMPlayer, send.bSuccess ? E_Success : E_SystemError, 
			LogHelper(_T("Edit工具删除角色[%u],物品[%I64d],TYPE[%u]"), xProtocol->dw_role_id, xProtocol->serial, xProtocol->dw_type_id));
	}

	xGMPlayer->SendMessage(&send, send.dw_size);

	return E_Success;
}
//! 删除宠物
DWORD GMServerHanlder::HandleDeleteRolePet(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_DeletePet* xProtocol = (NET_C2GMS_DeletePet*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));

	NET_GMS2C_DeletePet send;
	send.dw_pet_id = xProtocol->dw_pet_id;
	send.dw_role_id = xProtocol->dw_role_id;
	send.bSuccess = FALSE;
	if(VALID_POINT(pDB)) 
	{
		send.bSuccess = pDB->delete_role_pet("", xProtocol, -1, xProtocol->dw_role_id, 1, 0);
		g_GMPlayerManager.WriteGMLog( xGMPlayer, send.bSuccess ? E_Success : E_SystemError, 
			LogHelper(_T("Edit工具删除角色[%u],宠物[%u]"), xProtocol->dw_role_id, xProtocol->dw_pet_id));
	}
	xGMPlayer->SendMessage(&send, send.dw_size);

	return E_Success;
}

DWORD GMServerHanlder::HandleDeleteRoleSkill(tag_net_message* pMsg, DWORD dwParam)
{
	NET_C2GMS_DeleteRoleSkill* xProtocol = (NET_C2GMS_DeleteRoleSkill*)pMsg;
	GMPlayer* xGMPlayer = PlayerCast<DWORD,GMPlayer>(dwParam);

	LogDB* pDB = g_LogQueryMgr.GetGameDB(get_tool()->crc32(xProtocol->szServerName));

	NET_GMS2C_DeleteRoleSkill send;
	send.dw_skill_id = xProtocol->dw_skill_id;
	send.dw_role_id = xProtocol->dw_role_id;
	send.bSuccess = FALSE;
	if(VALID_POINT(pDB)) 
	{
		send.bSuccess = pDB->delete_role_skill("", xProtocol, -1, xProtocol->dw_role_id, 1, 0);
		g_GMPlayerManager.WriteGMLog( xGMPlayer, send.bSuccess ? E_Success : E_SystemError, 
			LogHelper(_T("Edit工具删除角色[%u],技能[%u]"), xProtocol->dw_role_id, xProtocol->dw_skill_id));
	}
	xGMPlayer->SendMessage(&send, send.dw_size);

	return E_Success;
}