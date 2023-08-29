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
 *	@file		LogicHandler
 *	@author		mwh
 *	@date		2011/04/07	initial
 *	@version	0.0.1.0
 *	@brief		逻辑处理
*/

#ifndef __LOGICHANDLER_H__
#define __LOGICHANDLER_H__

//=================================================
//	以后可能有virtual的加入
//=================================================
template<class Src, class Dst>
Dst* PlayerCast(Src& _Src){ return static_cast<Dst*>((VOID*)_Src);};

class GMServerHanlder
{
	BOOL mRegistered;
public:
	GMServerHanlder():mRegistered(FALSE){}
public:
	VOID RegisterCmd();
	VOID UnRegisterCmd();
	//=================================================
	//	以下是服务器与GM服务器之间的逻辑处理
	//=================================================
public:
	DWORD HandleServerLogin(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleServerInfo(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleGSForbiTalk(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleLSForbiAccount(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleGMCreateEquipResult(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleGMCreateItemResult(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleServerChatTransmit(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleGMGiveMoneyResult(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleValidateResult(tag_net_message* pMsg, DWORD dwParam);
public:
	//=================================================
	//	以下是GM客户端与GM服务器之间的逻辑处理
	//=================================================
	DWORD HandleGMLogin(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleForbiTalk(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleForbiAccount(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleFuckWorkRoom(tag_net_message* pMsg, DWORD dwParam);//批量封停，踢掉工作室
	DWORD HandleFuckWorkRoom_OBO(tag_net_message* pMsg,DWORD dwParam);//一个一个地处理异常IP
	DWORD HandleForbiAccountByAccountID(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleAfficheMsg(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleGMKick(tag_net_message* pMsg,	DWORD dwParam);
	DWORD HandleShutDown(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleAddItem(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleGiveMoney(tag_net_message* pMsg, DWORD dwParam);
	
	DWORD HandleQueryRoleListByRoleID(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryRoleListByAccountName(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryRoleListByRoleName(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryRoleListByThirdAccountID(tag_net_message* pMsg,DWORD dwParam);//gx add 2013.11.05

	//! 删除角色列表
	DWORD HandleQueryDeleteRoleListByRoleID(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryDeleteRoleListByAccountName(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryDeleteRoleListByRoleName(tag_net_message* pMsg, DWORD dwParam);

	//! 角色完整资料
	DWORD HandleQueryRoleData(tag_net_message* pMsg, DWORD dwParam);

	//! 查询被禁言列表
	DWORD HandleGetForbidTalkRoleList(tag_net_message* pMsg, DWORD dwParam);

	//! 查询被封号列表
	DWORD HandleGetForbidAccountList(tag_net_message* pMsg, DWORD dwParam);

	//! 查询GM日志
	DWORD HandleQueryGMLogByAccount(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryGMLog(tag_net_message* pMsg, DWORD dwParam);

	//! 查询帮会列表
	DWORD HandleQueryGuildList(tag_net_message* pMsg, DWORD dwParam);

	//! 帮会基础资料
	DWORD HandleQueryGuildData(tag_net_message* pMsg, DWORD dwParam);

	//! 帮会成员列表
	DWORD HandleQueryGuildMember(tag_net_message* pMsg, DWORD dwParam);

	//! gohome
	DWORD HandleRoleGoHome(tag_net_message* pMsg, DWORD dwParam);

	//! 查询角色log
	DWORD HandleQueryRoleItemLog(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryRoleMoneyLog(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryRoleExploitsLog(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryRoleYuanBaoLog(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryOneItemLog(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryBankLog(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryPaiMaiLog(tag_net_message* pMsg, DWORD dwParam);

	//! 服务器某一物品数量
	DWORD HandleQueryItemNumber(tag_net_message* pMsg, DWORD dwParam);

	//! 服务器管理
	DWORD HandleQueryLoginStatus(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleQueryGameSeverStatus(tag_net_message* pMsg, DWORD dwParam);

	//! 服务器设置
	DWORD HandleSetServerMaxPlayer(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleSetDoublePolicy(tag_net_message* pMsg, DWORD dwParam);

	//! 服务器定时公告
	DWORD HandleAffichePeriodicity(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleCancelAffichePeriodicity(tag_net_message* pMsg, DWORD dwParam);

	//! 修复悬赏任务标志
	DWORD HandleVerifyGDQuestFlag(tag_net_message* pMsg, DWORD dwParam);

	DWORD HandleGMValidate(tag_net_message* pMsg, DWORD dwParam);

	//=================================================
	//	Save Role
	//=================================================
	DWORD HandleSaveRoleBasic(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleSaveRoleSkill(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleSaveRolePet(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleSaveRoleEquip(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleGMCreateEquip(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleGMCreateItem(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleGMCreateItemByRoleName(tag_net_message* pMsg,DWORD dwParam);//gx add 2013.11.05
	//=================================================
	//	Delete Role's Item && Pet
	//=================================================
	DWORD HandleDeleteRoleItem(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleDeleteRolePet(tag_net_message* pMsg, DWORD dwParam);
	DWORD HandleDeleteRoleSkill(tag_net_message* pMsg, DWORD dwParam);
};

extern GMServerHanlder g_GMLogicHandler;

#endif //__LOGICHANDLER_H__
