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
*	@file		master_prentice_protocol.h
*	@author		lc
*	@date		2011/03/08	initial
*	@version	0.0.1.0
*	@brief		师徒消息
*/


#ifndef __MSG_MASTER_PRENTICE_H__
#define __MSG_MASTER_PRENTICE_H__

#include "master_prentice_define.h"

enum
{
	E_MakeMaster_You_ForbidOp = 1,		//操作失败，您刚解除师徒关系，在接下来的48小时中将不可以进行收徒和拜师。
	E_MakeMaster_You_HasMaster,		//操作失败，您已有师傅，同时只能拥有一位师傅。
	E_MakeMaster_Your_OutOfLevel, //操作失败，拜师的等级必须要在1~25级之间。
	E_MakeMaster_Master_ForbidOp,	//操作失败，目标刚解除师徒关系，在48小时中将不可以进行收徒。
	E_MakeMaster_Master_OutOfLevel, //操作失败，目标等级必须≥30级
	E_MakeMaster_Master_MaxPrentices, //操作失败，目标的弟子太多不能再收更多的徒弟了。
	E_MakeMaster_Master_Refuse,		//XXX暂时不愿意收您为徒。
	E_MakeMaster_Master_Suceessful, //XXX向XXX行过拜师之礼后正式归入其门下
	E_MakeMaster_Master_MinOfLevel, // 操作失败，师傅等级必须大于自己的等级
	E_MakeMaster_Master_Has_Graduates, //  已出师的角色，不能再拜师

	E_MakePrentice_You_ForbidOp,	//操作失败，您刚解除师徒关系，在接下来的48小时中将不可以进行收徒和拜师。
	E_MakePrentice_Your_OutOfLevel, //操作失败，收徒等级必须≥30级
	E_MakePrentice_Prentice_ForbidOp, ///操作失败，目标刚解除师徒关系，在48小时中将不可以进行拜师。
	E_MakePrentice_Prentice_HasMaster, //操作失败，目标已有师傅。
	E_MakePrentice_Prentice_OutOfLevel,//操作失败，目标的等级必须要在1~25级之间
	E_MakePrentice_Your_MaxPrentices, //操作失败，您弟子太多不能再收更多的徒弟了。
	E_MakePrentice_Prentice_Refuse,	//XXX暂时不愿意成为您的弟子。
	E_MakePrentice_Prentice_Successful, //XXX向XXX行过拜师之礼后正式归入其门下
	E_MakePrentice_Prentice_MaxOfLevel,  // 操作失败，徒弟等级必须小于自己的等级
	E_MakePrentice_Prentice_Has_Graduates, // 已出师的角色不可以被收为徒弟

	E_MasterPrenticeBreak_OutOfMoney,	//金钱不足，不能解除师徒关系
	E_MasterPrenticeBreak_Error_Npc,	//Npc没这功能

	E_ShowInPanel_Successful,		//登记成功
	E_ShowInPanel_Your_OutOfLevel,	//操作失败，只有≥30级的角色才可以登记收徒。
	E_HideInPanel_Successful,		//成功取消登记
	E_HideInPanel_You_NotRegister, //操作失败，只有登记收徒的角色才可以取消登记。

	E_CallInMaster_Master_Refuse,	//召请师傅时，师傅拒绝
	E_CallInMaster_Success,			//召请师傅时，师傅同意
	E_CallInMaster_No_Master,		//召请师傅时，没有师傅
	E_CallInMaster_Master_Offline,	//召请师傅时，师傅离线
	E_CallInMaster_No_Item,			//召请师傅时，没有召请符

	E_JoinRecruit_AlreadyIn,
	E_JoinRecruit_OutOfLevel,

	E_LeaveRecruit_NotIn,

	E_CallInMaster_In_Intance, //不能副本召请师傅
	E_CallInMaster_In_Prison, //师傅在监狱不能被召请
	E_CallInMaster_You_In_Prison,//在监狱不能被召请师傅
	E_CallInMaster_In_guild_war,//师父在帮会战
	E_CallInMaster_MapLimit,

	E_MasterTeach_Prentice_offline,//传功徒弟不在线
	E_MasterTeach_Prentice_full,//该徒弟今日已被传功

	E_MasterPrentice_OutSafeArea,//试图建立师徒关系的玩家不在安全区内
	E_MakeMaster_MasterIsPrentice,//试图拜师的对象还是别人的徒弟
	E_MakePrentice_NotMaster,//试图收徒的人还不是师傅

	E_MakeMaster_MasterBusy,//师傅正在处理玩家的拜师的请求
	E_MakePrentice_PrenticeBusy,//徒弟正在处理玩家的收徒的请求

	E_MakeMaster_ToConfirm,//邀请已发出，等待师傅确认
	E_MakePrentice_ToConfirm,//邀请已发出，等待徒弟确认
};


#pragma pack(push,1)

//拜师
struct NET_SIC_make_master : public tag_net_message
{
	NET_SIC_make_master()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_make_master");
		dw_size = sizeof(NET_SIC_make_master);
	}
	DWORD dwMaster;
};


//转发请求给师傅
struct NET_SIS_make_master_extend : public tag_net_message
{
	NET_SIS_make_master_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_make_master_extend");
		dw_size = sizeof(NET_SIS_make_master_extend);
	}
	DWORD dwPrentice;
};


//师傅回应
struct NET_SIC_make_master_extend : public tag_net_message
{
	NET_SIC_make_master_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_make_master_extend");
		dw_size = sizeof(NET_SIC_make_master_extend);
	}
	DWORD dwPrentice;
	BYTE  byAck;	//EMASTER_REFUSE or EMASTER_ACCEPT
};
//师傅同意时，真正拜师成功
struct NET_SIS_make_master_result_to_master : public tag_net_message
{
	NET_SIS_make_master_result_to_master()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_make_master_result_to_master");
		dw_size = sizeof(*this);
	}
	DWORD dwPrentice;
};


//拜师结果
struct NET_SIS_make_master : public tag_net_message
{
	NET_SIS_make_master()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_make_master");
		dw_size = sizeof(NET_SIS_make_master);
	}
	DWORD dwMaster; //师傅 RoleID
	DWORD dwError;
};
 
 //发送师徒所有数据,不包括自己
struct NET_SIS_master_and_prentices : public tag_net_message
{
	NET_SIS_master_and_prentices()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_master_and_prentices");
		dw_size = sizeof(NET_SIS_master_and_prentices);
	}
	BYTE byNumber;
	tagMPMember stMember[1];
};
 
//收徒
struct NET_SIC_make_prentice : public tag_net_message
{
	NET_SIC_make_prentice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_make_prentice");
		dw_size = sizeof(NET_SIC_make_prentice);
	}
	DWORD dwPrentice;
};

//转发给徒弟
struct NET_SIS_make_prentice_extend : public tag_net_message
{
	NET_SIS_make_prentice_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_make_prentice_extend");
		dw_size = sizeof(NET_SIS_make_prentice_extend);
	}
	DWORD dwMaster;
};

// 徒弟同意时，真正收徒成功
struct NET_SIS_make_prentice_result_to_prentice : public tag_net_message
{
	NET_SIS_make_prentice_result_to_prentice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_make_prentice_result_to_prentice");
		dw_size = sizeof(*this);
	}
	DWORD dwMaster;
};

//徒弟回应
struct NET_SIC_make_prentice_extend : public tag_net_message
{
	NET_SIC_make_prentice_extend()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_make_prentice_extend");
		dw_size = sizeof(NET_SIC_make_prentice_extend);
	}
	DWORD dwMaster;
	BYTE  byAck; //EMASTER_REFUSE or EMASTER_ACCEPT
};


//新徒弟资料
struct NET_SIS_new_prentice : public tag_net_message
{
	NET_SIS_new_prentice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_new_prentice");
		dw_size = sizeof(NET_SIS_new_prentice);
	}
	tagMPMember stMember;
};

//收徒结果
struct NET_SIS_make_prentice : public tag_net_message
{
	NET_SIS_make_prentice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_make_prentice");
		dw_size = sizeof(NET_SIS_make_prentice);
	}
	DWORD dwPrentice;
	DWORD dwError;
};

//广播
struct NET_SIS_role_master : public tag_net_message
{
	NET_SIS_role_master()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_role_master");
		dw_size = sizeof(NET_SIS_role_master);
	}
	DWORD dwMaster;
	DWORD dwPrentice;
};

//师徒榜
struct NET_SIC_get_master_placard : public tag_net_message
{
	NET_SIC_get_master_placard()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_get_master_placard");
		dw_size = sizeof(NET_SIC_get_master_placard);
	}
};

struct NET_SIS_get_master_placard : public tag_net_message
{
	NET_SIS_get_master_placard()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_get_master_placard");
		dw_size = sizeof(NET_SIS_get_master_placard);
	}
	UINT16 u16Number;
	tagMasterPalcardSim stMPlacardSim[1];
};


//师德值和毕业数
struct NET_SIS_master_moral_and_gradates : public tag_net_message
{
	NET_SIS_master_moral_and_gradates()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_master_moral_and_gradates");
		dw_size = sizeof(NET_SIS_master_moral_and_gradates);
	}
	/*DWORD	dwMasterMoral;
	DWORD	dwGraduates;*/
	DWORD dwMasterID;
};

//徒弟毕业了
struct NET_SIS_prentice_graduate : public tag_net_message
{
	NET_SIS_prentice_graduate()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_prentice_graduate");
		dw_size = sizeof(NET_SIS_prentice_graduate);
	}
	DWORD dwPrentice;
};

//师徒决裂
struct NET_SIC_master_prentice_break : public tag_net_message
{
	NET_SIC_master_prentice_break()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_master_prentice_break");
		dw_size = sizeof(NET_SIC_master_prentice_break);
	}
	DWORD dwNpcID;
	DWORD dw_role_id;//徒弟主动解除关系：roleid=INVALID_VALUE；师傅主动解除关系：roleid=徒弟ID；
};

struct NET_SIS_master_prentice_break_error : public tag_net_message
{
	NET_SIS_master_prentice_break_error()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_master_prentice_break_error");
		dw_size = sizeof(NET_SIS_master_prentice_break_error);
	}
	DWORD dwError;
	DWORD dwNpcID;
};

struct NET_SIS_master_prentice_break : public tag_net_message
{
	NET_SIS_master_prentice_break()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_master_prentice_break");
		dw_size = sizeof(NET_SIS_master_prentice_break);
	}
	BYTE  byMasterOP;
	DWORD dw_role_id; //转发给师门所有其他人 roleid 脱离师门
};

//设置是否在师徒榜显示自己
struct NET_SIC_show_in_master_placard : public tag_net_message
{
	NET_SIC_show_in_master_placard()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_show_in_master_placard");
		dw_size = sizeof(NET_SIC_show_in_master_placard);
	}
	BYTE byFlag;// EMASTER_HIDE or EMASTER_SHOW
};

struct NET_SIS_show_in_master_placard : public tag_net_message
{
	NET_SIS_show_in_master_placard()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_show_in_master_placard");
		dw_size = sizeof(NET_SIS_show_in_master_placard);
	}
	DWORD dwError;
};


//师傅删除角色
struct NET_SIS_master_delete_role : public tag_net_message
{
	NET_SIS_master_delete_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_master_delete_role");
		dw_size = sizeof(NET_SIS_master_delete_role);
	}
};

//徒弟删除角色
struct NET_SIS_prentice_delete_role : public tag_net_message
{
	NET_SIS_prentice_delete_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_prentice_delete_role");
		dw_size = sizeof(NET_SIS_prentice_delete_role);
	}
	DWORD dwPrentice;
};

//召请师傅
struct NET_SIC_call_in_master : public tag_net_message
{
	NET_SIC_call_in_master()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_call_in_master");
		dw_size = sizeof(NET_SIC_call_in_master);
	}
};

//转发给师傅
struct NET_SIS_prentice_call_in : public tag_net_message
{
	NET_SIS_prentice_call_in()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_prentice_call_in");
		dw_size = sizeof(NET_SIS_prentice_call_in);
	}
	DWORD dwPrentice;
};


//师傅回应
struct NET_SIC_prentice_call_in : public tag_net_message
{
	NET_SIC_prentice_call_in()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_prentice_call_in");
		dw_size = sizeof(NET_SIC_prentice_call_in);
	}
	DWORD dwPrentice;
	BYTE byAck;
};


//召请结果
struct NET_SIS_call_in_master : public tag_net_message
{
	NET_SIS_call_in_master()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_call_in_master");
		dw_size = sizeof(NET_SIS_call_in_master);
	}
	DWORD dwError;
};

// 加入拜师榜
struct NET_SIC_join_master_recruit : public tag_net_message
{
	NET_SIC_join_master_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_join_master_recruit");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
};

struct NET_SIS_join_master_recruit : public tag_net_message
{
	NET_SIS_join_master_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_join_master_recruit");
		dw_size = sizeof(*this);
	}
	DWORD dw_error;
};

// 离开拜师榜
struct NET_SIC_leave_master_recruit : public tag_net_message
{
	NET_SIC_leave_master_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_master_recruit");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
};

struct NET_SIS_leave_master_recruit : public tag_net_message
{
	NET_SIS_leave_master_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_leave_master_recruit");
		dw_size = sizeof(*this);
	}
	DWORD dw_error;
};

// 查询拜师榜信息
struct NET_SIC_query_page_master_recruit : public tag_net_message
{
	NET_SIC_query_page_master_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_query_page_master_recruit");
		dw_size = sizeof(*this);
	}
	INT n_page;
};

struct NET_SIS_query_page_master_recruit : public tag_net_message
{
	NET_SIS_query_page_master_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_query_page_master_recruit");
		dw_size = sizeof(*this);
	}
	INT	n_page; // 总页数
	INT n_cur;	 // 当前页数
	INT n_num; // p_data有效个数
	BOOL b_register; // 我是否登记
	tagMasterRecruitSim p_data[1];
};

// 出师
struct NET_SIS_say_goodbye_to_master : public tag_net_message
{
	NET_SIS_say_goodbye_to_master()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_say_goodbye_to_master");
		dw_size = sizeof(*this);
	}
};

struct NET_SIC_say_goodbye_to_master : public tag_net_message
{
	NET_SIC_say_goodbye_to_master()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_say_goodbye_to_master");
		dw_size = sizeof(*this);
	}
	BYTE  byAck;	//1 = OK or 0=NO
};
//gx add 2013.12.06 师傅给徒弟传功
struct NET_SIC_Master_teach_Prentice:public tag_net_message
{
	NET_SIC_Master_teach_Prentice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Master_teach_Prentice");
		dw_size = sizeof(*this);
	}
	DWORD dwPrentice;//徒弟ID
};
struct NET_SIS_Master_teach_Prentice:public tag_net_message
{
	NET_SIS_Master_teach_Prentice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Master_teach_Prentice");
		dw_size = sizeof(*this);
	}
	DWORD dwPrentice;//徒弟ID
	DWORD dwAddExp;//传功一次徒弟得到的经验值
	DWORD dw_error;
};
//师徒上下线之间的消息发送 gx add 2013.12.13
struct NET_SIS_Master_Login:public tag_net_message
{
	NET_SIS_Master_Login()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Master_Login");
		dw_size = sizeof(*this);
	}
};
struct NET_SIS_Master_Logout:public tag_net_message
{
	NET_SIS_Master_Logout()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Master_Logout");
		dw_size = sizeof(*this);
	}
};
struct NET_SIS_Prentice_Login:public tag_net_message
{
	NET_SIS_Prentice_Login()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Prentice_Login");
		dw_size = sizeof(*this);
	}
	DWORD dwPrentice;
};
struct NET_SIS_Prentice_Logout:public tag_net_message
{
	NET_SIS_Prentice_Logout()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Prentice_Logout");
		dw_size = sizeof(*this);
	}
	DWORD dwPrentice;
};
//end
#pragma pack(pop)

#endif //__MSG_MASTER_PRENTICE_H__
