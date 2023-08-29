/*******************************************************************************

	Copyright 2010 by tiankong Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef __GMDEFINE_H__
#define __GMDEFINE_H__

#pragma pack(push,1)

#ifndef MAX_MD5_ARRAY
	#define MAX_MD5_ARRAY 35
#endif // MAX_MD5_ARRAY

#ifndef GMAFFICHELEN
	#define  GMAFFICHELEN 200	// �������㲥��������ַ���
#endif // GMAFFICHELEN

#ifndef GMPERIODMAXINDEX 
	#define GMPERIODMAXINDEX 10 // �������Զ��㲥���������Ŀ
#endif // GMPERIODMAXINDEX

#ifndef MAX_GUIL_BUILD
	#define MAX_GUIL_BUILD 5
#endif //MAX_GUIL_BUILD

// DWORD 32bit 32��Ȩ��
enum EGMPrivilege
{
	EGMP_ONOFF						= 1 << 0, // ��/��
	EGMP_VIPLOOK					= 1 << 1, // �ص���
	EGMP_FORBIDTALK			= 1 << 2, // ����<s>
	EGMP_KEYWORDS				= 1 << 3, // �ؼ���
	EGMP_KICKROLE					= 1 << 4, // ����<s>
	EGMP_FORBIDACCOUNT	= 1 << 5, // ���<s>
	EGMP_AFFICHE					= 1 << 6, // ����<s>
};

enum EServerType
{
	EST_GAMESERVER,
	EST_LOGINSERVER,
};

//! �����޸�ֵ�������DB����һ��
enum EToolType
{
	ETTYPE_COMMON = 0,
	ETTYPE_CHATTOOL = 25,
	ETTYPE_EDITTOOL	= 255,
	ETTYPE_SERVERTOOL = 65535,
};

enum EGMDoubleType
{
	EGMDT_EXP		= 0,				//˫������
	EGMDT_ITEM		= 1,				//˫����Ʒ
	EGMDT_Practice	= 2,				//˫������
	EGMDT_Dacning	= 3,				//����
	EGMDT_NUMBER	,
};
#define EDT_VALID(E)	((E) >= EGMDT_EXP && (E) < EGMDT_NUMBER)	

enum EGMLogicError
{
	EGMProof_Denied = 1,
	EGMForbidTalk_RoleNotExist,
	EGMForbidTalk_ServerNotExist,
	EGMForbidAccount_ServerNotExist,
	EGMForbidAccount_Forbidded,			// �˺��Ѿ�����
	EGMForbidAccount_Freed,				// �˺��Ѿ����
	EGMForbidAccount_AccountNotExist,	// �˺Ų�����


//=================================================
//	����������ڴ�֮��
//=================================================
	EGMMall_Init_Failed,
	EGMMall_LoadProto_Failed,
	EGMDatabase_Busy,

	EGMLE_MAX
};


struct tag_Role_Name_Info
{
	TCHAR sz_account_name[X_LONG_NAME];
	TCHAR sz_role_name[3][X_SHORT_NAME];
};

struct tag_Role_Del_List
{
	vector<tstring> v_role_del;
	vector<DWORD> v_role_id;
};

struct tag_role_sim_info
{
	DWORD dw_role_id;
	TCHAR sz_role_name[X_SHORT_NAME];
};

struct tag_time_bound
{
	BYTE start_month;
	BYTE start_day;
	BYTE end_month;
	BYTE end_day;
	tag_time_bound() { memset(this, 0, sizeof(*this)); }
	BOOL Check(){ return start_month <= end_month; }
};

struct tag_item_log
{
	DWORD cmd_id; // CMD<e_log_cmd_id>
	DWORD type_id;	// ����TYPEID
	INT optnum; // �仯����(+����ʾ��ã�-����ʾʧȥ)
	INT64 serial;			// 64λID
	INT container_type; // ��������
	INT result_num;		// ���ո���
	INT64 serial2;			// 64λID
	INT container_type2; // ��������
	INT result_num2;	// ���ո���
	DWORD dw_role_relation; // �����Ľ�ɫid
	DWORD dwTime;	// ʱ��<tagDWORDTime>
	DWORD dw_role_id;// ��ɫID
};

struct tag_money_log
{
	DWORD cmd_id; // CMD<e_log_cmd_id>
	INT container_type; // ��������
	INT number;				// ����(+����ʾ���룻-����ʾȡ��)
	INT64 total_number; // ָ����������������
	DWORD dw_role_relation; // �����Ľ�ɫid
	DWORD dwTime;			// ʱ��<tagDWORDTime>
};
struct tag_exploits_log
{
	DWORD cmd_id; // CMD<e_log_cmd_id>
	INT number;				// ����(+����ʾ���룻-����ʾȡ��)
	INT64 total_number; // ָ����������������
	DWORD dw_role_relation; // �����Ľ�ɫid
	DWORD dwTime;			// ʱ��<tagDWORDTime>
};

struct tag_yuanbao_log
{
	DWORD cmd_id; // CMD<e_log_cmd_id>
	INT container_type; // ��������
	INT number;				// ����(+����ʾ���룻-����ʾȡ��)
	INT64 total_number; // ָ����������������
	DWORD dw_role_relation; // �����Ľ�ɫid
	DWORD dwTime;// ʱ��<tagDWORDTime>
};

struct tag_bank_log
{
	DWORD	 seller_id; // ������
	DWORD buyer_id; // ������
	DWORD bidup_id; // ������
	DWORD type;			// ��������
	DWORD bidup;		// ���ļ۸�
	DWORD chaw;	//  һ�ڼ�
	DWORD number;// ��������
	DWORD time;//  �ɽ�ʱ��
};

struct tag_paimai_log
{
	INT64 serial;
	DWORD	 seller_id; // ������
	DWORD buyer_id; // ������
	DWORD bidup_id; // ������
	DWORD bidup;		// ���ļ۸�
	DWORD chaw;	//  һ�ڼ�
	DWORD time;//  �ɽ�ʱ��
};

struct tag_gamaserver_info
{
	DWORD dwIP;			// ip int_ntoa
	INT mMaxNumber;
	INT mOnlineNumber;
	BOOL mStatus;
	BOOL mDBStatus;
	BOOL mDatebase;
	TCHAR szServerName[X_SHORT_NAME];
};

struct tag_affiche_cache
{
	DWORD dwCurTick;
	DWORD dwTickTimes;
	TCHAR szAfficheMsg[GMAFFICHELEN];
public:
	BOOL elapse() const { return dwCurTick>= dwTickTimes;}
	VOID reset() { dwCurTick = 0;}
	VOID update() { ++dwCurTick;}
};

struct tag_role_skill
{
	INT n_id;	// ����ID
	INT bidden_level; // ��ѧϰ�ȼ�
	INT self_level;		// ��ǩ�ȼ�
	INT proficiency;	// ������
	INT cooldowm;	// CD
};

struct tag_role_pet
{
	DWORD dw_id; // ����ID
	DWORD dw_type_id; // ��������ID
	INT quality;				// ����Ʒ��
	INT grade;					// ����Ʒ��???<��ѯlc>
	INT step;						// 
	INT state;						// ״̬
	DWORD dw_cur_spirit;	// ����
	DWORD dw_happy_val; // ����
	DWORD dw_skill_id[5]; // ���＼��
	TCHAR sz_pet_name[X_SHORT_NAME];	// ����
	INT		n_strength;				// ���ӽ�ɫ����
	INT		n_agility;				// ���ӽ�ɫ����
	INT		n_innerForce;			// ���ӽ�ɫ����
	INT		n_att_point;			// ���Ե�
	void Init( ){memset(this, 0, sizeof(*this));}
};

struct tag_role_data
{
	DWORD dw_account_id; // �˺�ID
	DWORD dw_role_id;		// ��ɫID
	TCHAR sz_role_name[X_SHORT_NAME];	// ��ɫ����
	BYTE e_class; //ְҵ EClassType
	BYTE e_sex;//�Ա�
	INT n_shengw;//����
	INT n_level; // �ȼ�
	INT n_cur_exp; // ��ǰ����
	INT n_hp;	// Ѫ
	INT n_mp; // ħ��
	INT n_brotherhood; // ����
	INT n_vigour;			// Ԫ��
	INT n_pk;			// pkֵ
	DWORD dw_guild;	// ���ID
	DWORD dw_map;	// ��ͼID
	DWORD dw_yuanbao;	// ���ϵ�Ԫ����
	INT16			n16_bag_size;					// ������С
	INT				n_bag_gold;					// �����н�����
	INT				n_bag_silver;					// ������������
	INT				n_bag_copper;					// ������ͭ��
	INT				n_bag_bind_gold;				// �����а󶨽�����
	INT				n_bag_bind_silver;				// �����а�������
	INT				n_bag_bind_copper;				// �����а�ͭ��
	INT				n_bag_tuanbao;					// ������Ԫ����

	INT16			n16_ware_size;				// �˺Ųֿ��С
	INT				n_ware_gold;					// �˺Ųֿ��н�����
	INT				n_ware_silver;				// �˺Ųֿ���������
	INT				n_ware_copper;				// �˺Ųֿ���ͭ��
	FLOAT			f_coordinate[3];			// λ�ã�x,y,z��
	INT				n_exploits;					// ս��
	INT				n_totalrecharge;			// ��ǰ�˺ų�ֵԪ������ gx add 2013.11.05
	BOOL			b_gm;							// GM�˺�
	// ��Ʒ(/װ��)->
	INT				n_item_num;					// ��Ʒװ������		-- tagItem,tagEquip
	INT				n_skill_num;					// ������ -- tag_role_skill
	INT				n_pets_num;					// ������Ŀ
	BYTE by_data[1];
};


//! �����Խ�ɫ
struct tag_forbid_talk_role
{
	DWORD dw_role_id;					// ��ɫID
	DWORD dw_account_id;
	DWORD dw_forbid_time_start;			// ���Կ�ʼʱ��
	DWORD dw_forbid_time_end;			// ���Խ���ʱ��
	TCHAR sz_role_name[X_SHORT_NAME];	// ��ɫ���� 
};

//! ����ͣ�˺�
struct tag_forbid_account
{
	DWORD dw_account_id;					//! �˺�ID 
	DWORD dw_forbid_mask;					//!	����ԭ��
	TCHAR sz_account_name[X_SHORT_NAME];	//!	�˺�
};


//! GM������־
struct tag_gm_log
{
	DWORD dw_ip; // gm����IP ntoa
	DWORD dw_time; // gm����ʱ��
	DWORD dw_account; // gm�˺�
	TCHAR sz_gm_cmd[X_HUGE_NAME]; // ������¼
};

//! ����������
struct tag_guild_basic
{
	DWORD dw_guild_id;
	DWORD dw_guild_level;
	TCHAR sz_guild_name[X_SHORT_NAME];
};

//! ��Ὠ��
struct tag_guild_build
{
	DWORD dw_type;
	DWORD dw_level;
	DWORD dw_max_level;
	DWORD dw_holiness_step;
	DWORD dw_use_num;
	DWORD dw_use_time; // ����ʱ��
	tag_guild_build() { memset(this, 0, sizeof(*this));}
};
//! ����������, ��ϸ�����ѯ"����"��ʦ
#include "guild_define.h"
struct tag_guild_data
{
	DWORD dw_guild_id;
	DWORD dw_creator_id;
	DWORD dw_create_time;
	DWORD dw_master_id;
	DWORD dw_member_num;
	//DWORD dw_member_max; //��Ա���� ����
	DWORD dw_prosperity;
	// ά���� ����
	// ��¯�ȼ� == ���ȼ�
	// ����Ч�� 2 * ��¯�ȼ�
	// ��¹���� (��)
	INT32 n32_script_data[64];	// ���ű�����	
	TCHAR sz_pos_name[X_GUILD_POS_NUM][MAX_GUILD_POS_NAME_LEN];
	tag_guild_build stData[MAX_GUIL_BUILD];
	tag_guild_data() { memset(this, 0, sizeof(*this));}
};

//! ����Ա����
struct tag_guild_member
{
	DWORD dw_role_id;
	DWORD dw_role_level;
	BYTE  by_class; //ְҵ EClassType	
	BYTE  by_position; // ְλ EGuildMemberPos
	DWORD dw_contribution; // �ﹱ
	DWORD dw_last_login;	// ����½
	TCHAR sz_role_name[X_SHORT_NAME];
};


//! ����洢�ṹ �벻Ҫ�����޸�

//! ��ɫ��������
struct tag_role_basic_save
{
	INT n_cur_exp;				// ��ǰ����
	INT n_level;			// �ȼ�
	INT n_pk;					// pkֵ
	DWORD dw_yuanbao;			// ���ϵ�Ԫ����
	
	INT	n_bag_gold;				// �����н�����
	INT	n_bag_silver;			// ������������
	INT	n_bag_copper;			// ������ͭ��
	
	INT	n_bag_bind_gold;		// �����а󶨽�����
	INT	n_bag_bind_silver;		// �����а�������
	INT	n_bag_bind_copper;		// �����а�ͭ��

	INT	n_ware_gold;			// �˺Ųֿ��н�����
	INT	n_ware_silver;			// �˺Ųֿ���������
	INT	n_ware_copper;			// �˺Ųֿ���ͭ��

	INT exploits;
	DWORD dw_bindyuanbao;		//��ȯ
};

//! �洢����
struct tag_role_skill_save
{
	INT nSkillID;
	INT nSkillLevel;
	INT nProficiency;
	INT nCooldown;
};

//! �������
struct tag_role_pet_save
{
	DWORD dw_id; // ����ID
	INT nGrade; // nGrade �� nStep ����ȼ��� 
	INT nStep;	// nGrade �� nStep ����ȼ��� 
	DWORD dw_cur_spirit;	// ����
	DWORD dw_happy_val; // ����
	INT		n_strength;				// ���ӽ�ɫ����
	INT		n_agility;				// ���ӽ�ɫ����
	INT		n_innerForce;			// ���ӽ�ɫ����
	INT		n_att_point;			// ���Ե�
	//DWORD dw_skill_id[5]; // ���＼��
};

//! ����װ��
struct tag_equip_save
{
	INT64 n64_serial;// ��ƷΨһ���к�
	INT32 nLevel;			// �ȼ�
	INT32 nCurLevelExp;	// ��ǰ��������
	BYTE  bybind;			// ������
	BYTE  byTalentPoint;//��Ͷ�츳��
	BYTE  byMaxTalentPoint;//����츳��
	BYTE  byHoleNum;		// ����
	DWORD dwHoleGemID[MAX_EQUIPHOLE_NUM]; // ��Ƕ�ı�ʯ
	BYTE  byQuality;  //Ʒ��
	BYTE  byConsolidateLevel;//ǿ���ȼ�
	BYTE  byConsolidateLevelStar;//ǿ������
	BYTE	byFlareVal;		// ����
	tagRoleAttEffect EquipAttitionalAtt[MAX_ADDITIONAL_EFFECT]; // ��������
};

//! ����װ��
struct tag_equip_create
{
	DWORD dw_data_id; // ������Ʒ������
	BYTE  byBind;	  // ��״̬
	BYTE  byQuality; //Ʒ�� EItemQuality
	INT32 nLevel;			// �ȼ�
	INT32 nCurLevelExp;	// ��ǰ��������
	BYTE  byTalentPoint;//��Ͷ�츳��
	BYTE  byMaxTalentPoint;//����츳��
	BYTE  byHoleNum;		// ����
	DWORD dwHoleGemID[MAX_EQUIPHOLE_NUM]; // ��Ƕ�ı�ʯ
	BYTE  byConsolidateLevel;//ǿ���ȼ�
	BYTE  byConsolidateLevelStar;//ǿ������
	tagRoleAttEffect EquipAttitionalAtt[MAX_ADDITIONAL_EFFECT]; // ��������
	INT32				EquipAttitional[MAX_RAND_ATT];
	BYTE	byFlareVal;		// ����
};

//! ������Ʒ
struct tag_item_create
{
	DWORD dw_data_id; // ������Ʒ������
	BYTE  byBind;	  // ��״̬
	INT16 n16Number; // ����
};
//! �����Ƿ�IP gx add 2013.11.07
struct tag_Invalid_IP
{
	TCHAR sz_ip_name[X_SHORT_NAME];
	INT	  n_ip_num;//��IP��Ӧ�ĸ���
public:
	tag_Invalid_IP()
	{
		ZeroMemory(sz_ip_name , X_SHORT_NAME*sizeof(TCHAR));
	}
};
#pragma pack(pop)

#endif //__GMDEFINE_H__
