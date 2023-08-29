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
 *	@file		GMServerHanlder
 *	@author		mwh
 *	@date		2011/04/08	initial
 *	@version	0.0.1.0
 *	@brief		逻辑处理
*/

#include "StdAfx.h"
#include "GMServerHanlder.h"


#define RegisterNetMsg(msg_name,cls_name, obj_ptr, mem_fun,desc)\
	serverframe::net_command_manager::get_singleton().register_message(msg_name, \
	fastdelegate::MakeDelegate(obj_ptr, (DWORD(cls_name::*)(tag_net_message*,DWORD))&cls_name::mem_fun), desc);

#define UnRegisterNetMsg(msg_name,cls_name, obj_ptr, mem_fun)\
	serverframe::net_command_manager::get_singleton().unregister_message( msg_name,\
	fastdelegate::MakeDelegate(obj_ptr, (DWORD(cls_name::*)(tag_net_message*,DWORD))&cls_name::mem_fun) );

GMServerHanlder g_GMLogicHandler;

VOID GMServerHanlder::RegisterCmd()
{
	if(mRegistered) return;
	mRegistered = TRUE;

	//=================================================
	//	以下是GMServerPlayer处理
	//=================================================
	RegisterNetMsg("NET_S2GMS_SeverLogin",			GMServerHanlder, this, HandleServerLogin,		_T("NET_S2GMS_SeverLogin"));
	RegisterNetMsg("NET_S2GMS_ServerInfo",			GMServerHanlder, this, HandleServerInfo,		_T("NET_S2GMS_ServerInfo"));
	RegisterNetMsg("NET_S2GMS_forbid_Talk",			GMServerHanlder, this, HandleGSForbiTalk,		_T("NET_S2GMS_forbid_Talk"));
	RegisterNetMsg("NET_S2GMS_forbid_account",		GMServerHanlder, this, HandleLSForbiAccount,	_T("NET_S2GMS_forbid_account"));
	RegisterNetMsg("NET_S2GMS_GMCreateEquip",		GMServerHanlder, this, HandleGMCreateEquipResult,	_T("NET_S2GMS_GMCreateEquip"));
	RegisterNetMsg("NET_S2GMS_GMCreateItem",		GMServerHanlder, this, HandleGMCreateItemResult,	_T("NET_S2GMS_GMCreateItem"));
	RegisterNetMsg("NET_S2GMS_GMGiveMoney",			GMServerHanlder, this, HandleGMGiveMoneyResult,		_T("NET_S2GMS_GMGiveMoney"));
	RegisterNetMsg("NET_S2GMS_ChatTransmit",		GMServerHanlder, this, HandleServerChatTransmit,	_T("NET_S2GMS_ChatTransmit"));
	RegisterNetMsg("NET_S2GMS_validate",		GMServerHanlder, this, HandleValidateResult,	_T("NET_S2GMS_validate"));

	//=================================================
	// 以下是GMPlayer的处理
	//=================================================
	RegisterNetMsg("NET_C2GMS_GMLogin",									GMServerHanlder, this, HandleGMLogin,											_T("NET_C2GMS_GMLogin"));
	RegisterNetMsg("NET_C2GMS_ForbidTalk",									GMServerHanlder, this, HandleForbiTalk,											_T("NET_C2GMS_ForbidTalk"));
	RegisterNetMsg("NET_C2GMS_ForbidAccount",							GMServerHanlder, this, HandleForbiAccount,										_T("NET_C2GMS_ForbidAccount"));
	RegisterNetMsg("NET_C2GMS_FuckWorkRoom",							GMServerHanlder,this,HandleFuckWorkRoom,_T("NET_C2GMS_FuckWorkRoom"));//gx add 2013.11.07
	RegisterNetMsg("NET_C2GMS_HandleIP_OBO",							GMServerHanlder,this,HandleFuckWorkRoom_OBO,_T("NET_C2GMS_HandleIP_OBO"));//gx add 2013.11.19
	RegisterNetMsg("NET_C2GMS_ForbidAccountByAccountID",		GMServerHanlder, this, HandleForbiAccountByAccountID,				_T("NET_C2GMS_ForbidAccountByAccountID"));
	RegisterNetMsg("NET_C2GMS_Affiche",										GMServerHanlder, this, HandleAfficheMsg,											_T("NET_C2GMS_Affiche"));
	RegisterNetMsg("NET_C2GMS_Kick",											GMServerHanlder, this, HandleGMKick,												_T("NET_C2GMS_Kick"));
	RegisterNetMsg("NET_C2GMS_ShutDown",									GMServerHanlder, this, HandleShutDown,											_T("NET_C2GMS_ShutDown"));
	RegisterNetMsg("NET_C2GMS_Add_item",									GMServerHanlder, this, HandleAddItem,												_T("NET_C2GMS_Add_item"));	
	
	RegisterNetMsg("NET_C2GMS_GetRoleListByRoleID",		GMServerHanlder, this, HandleQueryRoleListByRoleID,					_T("NET_C2GMS_GetRoleListByRoleID"));	
	RegisterNetMsg("NET_C2GMS_GetRoleListByAccountName",	GMServerHanlder, this, HandleQueryRoleListByAccountName,		_T("NET_C2GMS_GetRoleListByAccountName"));	
	RegisterNetMsg("NET_C2GMS_GetRoleListByRoleName",		GMServerHanlder, this, HandleQueryRoleListByRoleName,					_T("NET_C2GMS_GetRoleListByRoleName"));	
	RegisterNetMsg("NET_C2GMS_GetRoleListByThirdAccountID",GMServerHanlder,this,HandleQueryRoleListByThirdAccountID,_T("NET_C2GMS_GetRoleListByThirdAccountID"));//gx add
	RegisterNetMsg("NET_C2GMS_GetDeleteRoleListByRoleID",		GMServerHanlder, this, HandleQueryDeleteRoleListByRoleID,					_T("NET_C2GMS_GetDeleteRoleListByRoleID"));	
	RegisterNetMsg("NET_C2GMS_GetDeleteRoleListByAccountName",	GMServerHanlder, this, HandleQueryDeleteRoleListByAccountName,		_T("NET_C2GMS_GetDeleteRoleListByAccountName"));	
	RegisterNetMsg("NET_C2GMS_GetDeleteRoleListByRoleName",		GMServerHanlder, this, HandleQueryDeleteRoleListByRoleName,					_T("NET_C2GMS_GetDeleteRoleListByRoleName"));	

	RegisterNetMsg("NET_C2GMS_GetRoleFullData",		GMServerHanlder, this, HandleQueryRoleData,					_T("NET_C2GMS_GetRoleFullData"));	

	RegisterNetMsg("NET_C2GMS_RoleGoHome",		GMServerHanlder, this, HandleRoleGoHome,					_T("NET_C2GMS_RoleGoHome"));	

	RegisterNetMsg("NET_C2GMS_GetForbidTalkRoleList",		GMServerHanlder, this, HandleGetForbidTalkRoleList,					_T("NET_C2GMS_GetForbidTalkRoleList"));	
	RegisterNetMsg("NET_C2GMS_GetForbidAccountList",		GMServerHanlder, this, HandleGetForbidAccountList,					_T("NET_C2GMS_GetForbidAccountList"));	
	
	RegisterNetMsg("NET_C2GMS_QueryGuildList",					GMServerHanlder, this, HandleQueryGuildList,							_T("NET_C2GMS_QueryGuildList"));
	RegisterNetMsg("NET_C2GMS_QueryGuildData",					GMServerHanlder, this, HandleQueryGuildData,							_T("NET_C2GMS_QueryGuildData"));
	RegisterNetMsg("NET_C2GMS_QueryGuildMember",					GMServerHanlder, this, HandleQueryGuildMember,							_T("NET_C2GMS_QueryGuildMember"));
	RegisterNetMsg("NET_C2GMS_QueryGMLogByAccount",					GMServerHanlder, this, HandleQueryGMLogByAccount,							_T("NET_C2GMS_QueryGMLogByAccount"));
	RegisterNetMsg("NET_C2GMS_QueryGMLog",					GMServerHanlder, this, HandleQueryGMLog,							_T("NET_C2GMS_QueryGMLog"));
	RegisterNetMsg("NET_C2GMS_QueryRoleItemLog",					GMServerHanlder, this, HandleQueryRoleItemLog,							_T("NET_C2GMS_QueryRoleItemLog"));
	RegisterNetMsg("NET_C2GMS_QueryRoleMoneyLog",				GMServerHanlder, this, HandleQueryRoleMoneyLog,						_T("NET_C2GMS_QueryRoleMoneyLog"));
	RegisterNetMsg("NET_C2GMS_QueryRoleexploitsLog",				GMServerHanlder, this, HandleQueryRoleExploitsLog,						_T("NET_C2GMS_QueryRoleexploitsLog"));
	RegisterNetMsg("NET_C2GMS_QueryRoleYuanBaoLog",			GMServerHanlder, this, HandleQueryRoleYuanBaoLog,						_T("NET_C2GMS_QueryRoleYuanBaoLog"));	
	RegisterNetMsg("NET_C2GMS_QueryOneItemLog",					GMServerHanlder, this, HandleQueryOneItemLog,						_T("NET_C2GMS_QueryOneItemLog"));	
	RegisterNetMsg("NET_C2GMS_QueryRoleBankLog",					GMServerHanlder, this, HandleQueryBankLog,						_T("NET_C2GMS_QueryRoleBankLog"));	
	RegisterNetMsg("NET_C2GMS_QueryRolePaiMaiLog",					GMServerHanlder, this, HandleQueryPaiMaiLog,						_T("NET_C2GMS_QueryRolePaiMaiLog"));	
	RegisterNetMsg("NET_C2GMS_QueryItemNumberByType",					GMServerHanlder, this, HandleQueryItemNumber,						_T("NET_C2GMS_QueryItemNumberByType"));	
	RegisterNetMsg("NET_C2GMS_QueryLoginStatus",						GMServerHanlder, this, HandleQueryLoginStatus,					_T("NET_C2GMS_QueryLoginStatus"));	
	RegisterNetMsg("NET_C2GMS_QueryGameServerList",				GMServerHanlder, this, HandleQueryGameSeverStatus,						_T("NET_C2GMS_QueryGameServerList"));	
	RegisterNetMsg("NET_C2GMS_SetServerMaxPlayerNumber",				GMServerHanlder, this, HandleSetServerMaxPlayer,				_T("NET_C2GMS_SetServerMaxPlayerNumber"));	
	RegisterNetMsg("NET_C2GMS_SetDoublePolicy",						GMServerHanlder, this, HandleSetDoublePolicy,						_T("NET_C2GMS_SetDoublePolicy"));	
	RegisterNetMsg("NET_C2GMS_Affiche_Periodicity",						GMServerHanlder, this, HandleAffichePeriodicity,				_T("NET_C2GMS_Affiche_Periodicity"));
	RegisterNetMsg("NET_C2GMS_Cancel_Affiche_Periodicity",						GMServerHanlder, this, HandleCancelAffichePeriodicity,	_T("NET_C2GMS_Cancel_Affiche_Periodicity"));
	RegisterNetMsg("NET_C2GMS_SaveRoleBasicData",	GMServerHanlder, this, HandleSaveRoleBasic,	_T("NET_C2GMS_SaveRoleBasicData"));
	RegisterNetMsg("NET_C2GMS_SaveRoleSkill",	GMServerHanlder, this, HandleSaveRoleSkill,	_T("NET_C2GMS_SaveRoleSkill"));
	RegisterNetMsg("NET_C2GMS_SaveRolePet",	GMServerHanlder, this, HandleSaveRolePet,	_T("NET_C2GMS_SaveRolePet"));
	RegisterNetMsg("NET_C2GMS_SaveRoleEquip",	GMServerHanlder, this, HandleSaveRoleEquip,	_T("NET_C2GMS_SaveRoleEquip"));
	RegisterNetMsg("NET_C2GMS_GMCreateEquip",	GMServerHanlder, this, HandleGMCreateEquip,	_T("NET_C2GMS_GMCreateEquip"));
	RegisterNetMsg("NET_C2GMS_GMCreateItem",	GMServerHanlder, this, HandleGMCreateItem,	_T("NET_C2GMS_GMCreateItem"));
	RegisterNetMsg("NET_C2GMS_GMCreateItem_Serial",	GMServerHanlder, this, HandleGMCreateItemByRoleName,	_T("NET_C2GMS_GMCreateItem_Serial"));//gx add
	RegisterNetMsg("NET_C2GMS_GMGiveMoney",		GMServerHanlder, this, HandleGiveMoney,		_T("NET_C2GMS_GMGiveMoney"));	
	RegisterNetMsg("NET_C2GMS_DeleteItem",	GMServerHanlder, this, HandleDeleteRoleItem,	_T("NET_C2GMS_DeleteItem"));
	RegisterNetMsg("NET_C2GMS_DeletePet",	GMServerHanlder, this, HandleDeleteRolePet,	_T("NET_C2GMS_DeletePet"));
	RegisterNetMsg("NET_C2GMS_DeleteRoleSkill",	GMServerHanlder, this, HandleDeleteRoleSkill,	_T("NET_C2GMS_DeleteRoleSkill"));
	RegisterNetMsg("NET_C2GMS_VerifyGDQuestFlag",	GMServerHanlder, this, HandleVerifyGDQuestFlag,	_T("NET_C2GMS_VerifyGDQuestFlag"));
	RegisterNetMsg("NET_C2GMS_validate",		GMServerHanlder, this, HandleGMValidate, _T("NET_C2GMS_validate"));	
}

VOID GMServerHanlder::UnRegisterCmd()
{
	if(!mRegistered) return;
	mRegistered = FALSE;
	//=================================================
	//	以下是GMServerPlayer处理
	//=================================================
	UnRegisterNetMsg("NET_S2GMS_SeverLogin", GMServerHanlder, this, HandleServerLogin);
	UnRegisterNetMsg("NET_S2GMS_ServerInfo", GMServerHanlder, this, HandleServerInfo);
	UnRegisterNetMsg("NET_S2GMS_forbid_Talk", GMServerHanlder, this, HandleGSForbiTalk);
	UnRegisterNetMsg("NET_S2GMS_forbid_account", GMServerHanlder, this, HandleLSForbiAccount);
	UnRegisterNetMsg("NET_S2GMS_GMCreateEquip",		GMServerHanlder, this, HandleGMCreateEquipResult);
	UnRegisterNetMsg("NET_S2GMS_GMCreateItem",		GMServerHanlder, this, HandleGMCreateItemResult);
	UnRegisterNetMsg("NET_S2GMS_GMGiveMoney",		GMServerHanlder, this, HandleGMGiveMoneyResult);
	UnRegisterNetMsg("NET_S2GMS_ChatTransmit",		GMServerHanlder, this, HandleServerChatTransmit);
	UnRegisterNetMsg("NET_S2GMS_validate",		GMServerHanlder, this, HandleValidateResult);

	//=================================================
	// 以下是GMPlayer的处理
	//=================================================
	UnRegisterNetMsg("NET_C2GMS_GMLogin", GMServerHanlder, this, HandleGMLogin);
	UnRegisterNetMsg("NET_C2GMS_ForbidTalk", GMServerHanlder, this, HandleForbiTalk);
	UnRegisterNetMsg("NET_C2GMS_ForbidAccount", GMServerHanlder, this, HandleForbiAccount);
	UnRegisterNetMsg("NET_C2GMS_FuckWorkRoom",GMServerHanlder,this,HandleFuckWorkRoom);
	UnRegisterNetMsg("NET_C2GMS_HandleIP_OBO",GMServerHanlder,this,HandleFuckWorkRoom_OBO);
	UnRegisterNetMsg("NET_C2GMS_ForbidAccountByAccountID",		GMServerHanlder, this, HandleForbiAccountByAccountID);
	UnRegisterNetMsg("NET_C2GMS_Affiche",		GMServerHanlder, this, HandleAfficheMsg);
	UnRegisterNetMsg("NET_C2GMS_Kick",				GMServerHanlder, this, HandleGMKick);
	UnRegisterNetMsg("NET_C2GMS_ShutDown",			GMServerHanlder, this, HandleShutDown);
	UnRegisterNetMsg("NET_C2GMS_Add_item",		GMServerHanlder, this, HandleAddItem);	
	UnRegisterNetMsg("NET_C2GMS_GetRoleListByRoleID",		GMServerHanlder, this, HandleQueryRoleListByRoleID);	
	UnRegisterNetMsg("NET_C2GMS_GetRoleListByAccountName",	GMServerHanlder, this, HandleQueryRoleListByAccountName);
	UnRegisterNetMsg("NET_C2GMS_GetRoleListByThirdAccountID",GMServerHanlder,this,HandleQueryRoleListByThirdAccountID);//gx add
	UnRegisterNetMsg("NET_C2GMS_GetDeleteRoleListByRoleID",		GMServerHanlder, this, HandleQueryDeleteRoleListByRoleID);	
	UnRegisterNetMsg("NET_C2GMS_GetDeleteRoleListByAccountName",	GMServerHanlder, this, HandleQueryDeleteRoleListByAccountName);	
	UnRegisterNetMsg("NET_C2GMS_GetDeleteRoleListByRoleName",		GMServerHanlder, this, HandleQueryDeleteRoleListByRoleName);	
	UnRegisterNetMsg("NET_C2GMS_GetRoleFullData",		GMServerHanlder, this, HandleQueryRoleData);	
	UnRegisterNetMsg("NET_C2GMS_RoleGoHome",		GMServerHanlder, this, HandleRoleGoHome);	
	UnRegisterNetMsg("NET_C2GMS_QueryRoleItemLog",					GMServerHanlder, this, HandleQueryRoleItemLog);
	UnRegisterNetMsg("NET_C2GMS_QueryRoleMoneyLog",				GMServerHanlder, this, HandleQueryRoleMoneyLog);
	UnRegisterNetMsg("NET_C2GMS_QueryRoleexploitsLog",				GMServerHanlder, this, HandleQueryRoleExploitsLog);
	UnRegisterNetMsg("NET_C2GMS_QueryRoleYuanBaoLog",			GMServerHanlder, this, HandleQueryRoleYuanBaoLog);	
	UnRegisterNetMsg("NET_C2GMS_QueryOneItemLog",					GMServerHanlder, this, HandleQueryOneItemLog);
	UnRegisterNetMsg("NET_C2GMS_QueryRoleBankLog",					GMServerHanlder, this, HandleQueryBankLog);	
	UnRegisterNetMsg("NET_C2GMS_QueryRolePaiMaiLog",					GMServerHanlder, this, HandleQueryPaiMaiLog);	
	UnRegisterNetMsg("NET_C2GMS_QueryItemNumberByType",					GMServerHanlder, this, HandleQueryItemNumber);
	UnRegisterNetMsg("NET_C2GMS_QueryLoginStatus",						GMServerHanlder, this, HandleQueryLoginStatus);	
	UnRegisterNetMsg("NET_C2GMS_QueryGameServerList",				GMServerHanlder, this, HandleQueryGameSeverStatus);	
	UnRegisterNetMsg("NET_C2GMS_SetServerMaxPlayerNumber",				GMServerHanlder, this, HandleSetServerMaxPlayer);	
	UnRegisterNetMsg("NET_C2GMS_SetDoublePolicy",						GMServerHanlder, this, HandleSetDoublePolicy);	
	UnRegisterNetMsg("NET_C2GMS_Affiche_Periodicity",						GMServerHanlder, this, HandleAffichePeriodicity);
	UnRegisterNetMsg("NET_C2GMS_Cancel_Affiche_Periodicity",					GMServerHanlder, this, HandleCancelAffichePeriodicity);
	UnRegisterNetMsg("NET_C2GMS_GetForbidTalkRoleList",		GMServerHanlder, this, HandleGetForbidTalkRoleList);	
	UnRegisterNetMsg("NET_C2GMS_GetForbidAccountList",		GMServerHanlder, this, HandleGetForbidAccountList);	
	UnRegisterNetMsg("NET_C2GMS_QueryGMLog",					GMServerHanlder, this, HandleQueryGMLog);
	UnRegisterNetMsg("NET_C2GMS_QueryGMLogByAccount",					GMServerHanlder, this, HandleQueryGMLogByAccount);
	UnRegisterNetMsg("NET_C2GMS_QueryGuildList",					GMServerHanlder, this, HandleQueryGuildList);
	UnRegisterNetMsg("NET_C2GMS_QueryGuildData",					GMServerHanlder, this, HandleQueryGuildData);
	UnRegisterNetMsg("NET_C2GMS_QueryGuildMember",					GMServerHanlder, this, HandleQueryGuildMember);
	UnRegisterNetMsg("NET_C2GMS_SaveRoleBasicData",						GMServerHanlder, this, HandleSaveRoleBasic);
	UnRegisterNetMsg("NET_C2GMS_SaveRoleSkill",	GMServerHanlder, this, HandleSaveRoleSkill);
	UnRegisterNetMsg("NET_C2GMS_SaveRolePet",	GMServerHanlder, this, HandleSaveRolePet);
	UnRegisterNetMsg("NET_C2GMS_SaveRoleEquip",	GMServerHanlder, this, HandleSaveRoleEquip);
	UnRegisterNetMsg("NET_C2GMS_GMCreateEquip",	GMServerHanlder, this, HandleGMCreateEquip);
	UnRegisterNetMsg("NET_C2GMS_GMCreateItem",	GMServerHanlder, this, HandleGMCreateItem);
	UnRegisterNetMsg("NET_C2GMS_GMCreateItem_Serial",	GMServerHanlder, this, HandleGMCreateItemByRoleName);//gx add
	UnRegisterNetMsg("NET_C2GMS_GMGiveMoney",	GMServerHanlder, this, HandleGiveMoney);
	UnRegisterNetMsg("NET_C2GMS_DeleteItem",	GMServerHanlder, this, HandleDeleteRoleItem);
	UnRegisterNetMsg("NET_C2GMS_DeletePet",	GMServerHanlder, this, HandleDeleteRolePet);
	UnRegisterNetMsg("NET_C2GMS_DeleteRoleSkill",	GMServerHanlder, this, HandleDeleteRoleSkill);
	UnRegisterNetMsg("NET_C2GMS_VerifyGDQuestFlag",	GMServerHanlder, this, HandleVerifyGDQuestFlag);
	UnRegisterNetMsg("NET_C2GMS_validate",		GMServerHanlder, this, HandleGMValidate);	
}
