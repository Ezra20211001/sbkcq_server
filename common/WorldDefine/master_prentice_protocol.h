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
*	@brief		ʦͽ��Ϣ
*/


#ifndef __MSG_MASTER_PRENTICE_H__
#define __MSG_MASTER_PRENTICE_H__

#include "master_prentice_define.h"

enum
{
	E_MakeMaster_You_ForbidOp = 1,		//����ʧ�ܣ����ս��ʦͽ��ϵ���ڽ�������48Сʱ�н������Խ�����ͽ�Ͱ�ʦ��
	E_MakeMaster_You_HasMaster,		//����ʧ�ܣ�������ʦ����ͬʱֻ��ӵ��һλʦ����
	E_MakeMaster_Your_OutOfLevel, //����ʧ�ܣ���ʦ�ĵȼ�����Ҫ��1~25��֮�䡣
	E_MakeMaster_Master_ForbidOp,	//����ʧ�ܣ�Ŀ��ս��ʦͽ��ϵ����48Сʱ�н������Խ�����ͽ��
	E_MakeMaster_Master_OutOfLevel, //����ʧ�ܣ�Ŀ��ȼ������30��
	E_MakeMaster_Master_MaxPrentices, //����ʧ�ܣ�Ŀ��ĵ���̫�಻�����ո����ͽ���ˡ�
	E_MakeMaster_Master_Refuse,		//XXX��ʱ��Ը������Ϊͽ��
	E_MakeMaster_Master_Suceessful, //XXX��XXX�й���ʦ֮�����ʽ����������
	E_MakeMaster_Master_MinOfLevel, // ����ʧ�ܣ�ʦ���ȼ���������Լ��ĵȼ�
	E_MakeMaster_Master_Has_Graduates, //  �ѳ�ʦ�Ľ�ɫ�������ٰ�ʦ

	E_MakePrentice_You_ForbidOp,	//����ʧ�ܣ����ս��ʦͽ��ϵ���ڽ�������48Сʱ�н������Խ�����ͽ�Ͱ�ʦ��
	E_MakePrentice_Your_OutOfLevel, //����ʧ�ܣ���ͽ�ȼ������30��
	E_MakePrentice_Prentice_ForbidOp, ///����ʧ�ܣ�Ŀ��ս��ʦͽ��ϵ����48Сʱ�н������Խ��а�ʦ��
	E_MakePrentice_Prentice_HasMaster, //����ʧ�ܣ�Ŀ������ʦ����
	E_MakePrentice_Prentice_OutOfLevel,//����ʧ�ܣ�Ŀ��ĵȼ�����Ҫ��1~25��֮��
	E_MakePrentice_Your_MaxPrentices, //����ʧ�ܣ�������̫�಻�����ո����ͽ���ˡ�
	E_MakePrentice_Prentice_Refuse,	//XXX��ʱ��Ը���Ϊ���ĵ��ӡ�
	E_MakePrentice_Prentice_Successful, //XXX��XXX�й���ʦ֮�����ʽ����������
	E_MakePrentice_Prentice_MaxOfLevel,  // ����ʧ�ܣ�ͽ�ܵȼ�����С���Լ��ĵȼ�
	E_MakePrentice_Prentice_Has_Graduates, // �ѳ�ʦ�Ľ�ɫ�����Ա���Ϊͽ��

	E_MasterPrenticeBreak_OutOfMoney,	//��Ǯ���㣬���ܽ��ʦͽ��ϵ
	E_MasterPrenticeBreak_Error_Npc,	//Npcû�⹦��

	E_ShowInPanel_Successful,		//�Ǽǳɹ�
	E_ShowInPanel_Your_OutOfLevel,	//����ʧ�ܣ�ֻ�С�30���Ľ�ɫ�ſ��ԵǼ���ͽ��
	E_HideInPanel_Successful,		//�ɹ�ȡ���Ǽ�
	E_HideInPanel_You_NotRegister, //����ʧ�ܣ�ֻ�еǼ���ͽ�Ľ�ɫ�ſ���ȡ���Ǽǡ�

	E_CallInMaster_Master_Refuse,	//����ʦ��ʱ��ʦ���ܾ�
	E_CallInMaster_Success,			//����ʦ��ʱ��ʦ��ͬ��
	E_CallInMaster_No_Master,		//����ʦ��ʱ��û��ʦ��
	E_CallInMaster_Master_Offline,	//����ʦ��ʱ��ʦ������
	E_CallInMaster_No_Item,			//����ʦ��ʱ��û�������

	E_JoinRecruit_AlreadyIn,
	E_JoinRecruit_OutOfLevel,

	E_LeaveRecruit_NotIn,

	E_CallInMaster_In_Intance, //���ܸ�������ʦ��
	E_CallInMaster_In_Prison, //ʦ���ڼ������ܱ�����
	E_CallInMaster_You_In_Prison,//�ڼ������ܱ�����ʦ��
	E_CallInMaster_In_guild_war,//ʦ���ڰ��ս
	E_CallInMaster_MapLimit,

	E_MasterTeach_Prentice_offline,//����ͽ�ܲ�����
	E_MasterTeach_Prentice_full,//��ͽ�ܽ����ѱ�����

	E_MasterPrentice_OutSafeArea,//��ͼ����ʦͽ��ϵ����Ҳ��ڰ�ȫ����
	E_MakeMaster_MasterIsPrentice,//��ͼ��ʦ�Ķ����Ǳ��˵�ͽ��
	E_MakePrentice_NotMaster,//��ͼ��ͽ���˻�����ʦ��

	E_MakeMaster_MasterBusy,//ʦ�����ڴ�����ҵİ�ʦ������
	E_MakePrentice_PrenticeBusy,//ͽ�����ڴ�����ҵ���ͽ������

	E_MakeMaster_ToConfirm,//�����ѷ������ȴ�ʦ��ȷ��
	E_MakePrentice_ToConfirm,//�����ѷ������ȴ�ͽ��ȷ��
};


#pragma pack(push,1)

//��ʦ
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


//ת�������ʦ��
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


//ʦ����Ӧ
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
//ʦ��ͬ��ʱ��������ʦ�ɹ�
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


//��ʦ���
struct NET_SIS_make_master : public tag_net_message
{
	NET_SIS_make_master()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_make_master");
		dw_size = sizeof(NET_SIS_make_master);
	}
	DWORD dwMaster; //ʦ�� RoleID
	DWORD dwError;
};
 
 //����ʦͽ��������,�������Լ�
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
 
//��ͽ
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

//ת����ͽ��
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

// ͽ��ͬ��ʱ��������ͽ�ɹ�
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

//ͽ�ܻ�Ӧ
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


//��ͽ������
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

//��ͽ���
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

//�㲥
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

//ʦͽ��
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


//ʦ��ֵ�ͱ�ҵ��
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

//ͽ�ܱ�ҵ��
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

//ʦͽ����
struct NET_SIC_master_prentice_break : public tag_net_message
{
	NET_SIC_master_prentice_break()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_master_prentice_break");
		dw_size = sizeof(NET_SIC_master_prentice_break);
	}
	DWORD dwNpcID;
	DWORD dw_role_id;//ͽ�����������ϵ��roleid=INVALID_VALUE��ʦ�����������ϵ��roleid=ͽ��ID��
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
	DWORD dw_role_id; //ת����ʦ������������ roleid ����ʦ��
};

//�����Ƿ���ʦͽ����ʾ�Լ�
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


//ʦ��ɾ����ɫ
struct NET_SIS_master_delete_role : public tag_net_message
{
	NET_SIS_master_delete_role()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_master_delete_role");
		dw_size = sizeof(NET_SIS_master_delete_role);
	}
};

//ͽ��ɾ����ɫ
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

//����ʦ��
struct NET_SIC_call_in_master : public tag_net_message
{
	NET_SIC_call_in_master()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_call_in_master");
		dw_size = sizeof(NET_SIC_call_in_master);
	}
};

//ת����ʦ��
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


//ʦ����Ӧ
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


//������
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

// �����ʦ��
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

// �뿪��ʦ��
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

// ��ѯ��ʦ����Ϣ
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
	INT	n_page; // ��ҳ��
	INT n_cur;	 // ��ǰҳ��
	INT n_num; // p_data��Ч����
	BOOL b_register; // ���Ƿ�Ǽ�
	tagMasterRecruitSim p_data[1];
};

// ��ʦ
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
//gx add 2013.12.06 ʦ����ͽ�ܴ���
struct NET_SIC_Master_teach_Prentice:public tag_net_message
{
	NET_SIC_Master_teach_Prentice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_Master_teach_Prentice");
		dw_size = sizeof(*this);
	}
	DWORD dwPrentice;//ͽ��ID
};
struct NET_SIS_Master_teach_Prentice:public tag_net_message
{
	NET_SIS_Master_teach_Prentice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_Master_teach_Prentice");
		dw_size = sizeof(*this);
	}
	DWORD dwPrentice;//ͽ��ID
	DWORD dwAddExp;//����һ��ͽ�ܵõ��ľ���ֵ
	DWORD dw_error;
};
//ʦͽ������֮�����Ϣ���� gx add 2013.12.13
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
