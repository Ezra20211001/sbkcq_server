/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#pragma once

#include "../../common/WorldDefine/guild_define.h"

#pragma pack(push, 1)


const INT32 MAX_GUILD_INVITE_DELAY_TIME	= TICK_PER_SECOND * 60;	// ����������Ӧʱ��
const INT32 MAX_GUILD_BUFF_SIZE			= 100 * 1000 * 1000;	// ���������ʱ����
const INT32 MAX_GUILDMEM_NUM_PER_MSG	= 10 * 1000;			// ÿ����Ϣ�а��ɳ�Ա��������
const INT32 TEMP_GUILD_BUFF_SIZE		= 100 * 1000;			// ������ʱ����

const INT32 MAX_GUILD_NAME_LEN			= 24;
const INT32 MAX_GUILD_TENET_LEN			= 400;
const INT32 MAX_GUILD_DELATE_LEN		= 200;
const INT32 MAX_GUILD_ENLISTEE_NUM		= 20;
const INT32 MAX_BANNER_NUM				= 5;

CONST INT32 MAX_LOAD_GUILDMEMBER_NUM_ONCE	= 1000;		// һ������෵�ذ��ɳ�Ա����


//! ��������
struct s_guild: public tagGuildBase
{
	tstring				str_name;						//��������
	tstring				str_tenet;						//������ּ
	tstring				str_symbol;						//���ɱ�־
	//BYTE				bySymbol[MAX_GUILD_SYMBOL_LEN];	//���ɱ�־

	s_guild(): tagGuildBase()	{}

	VOID Init(const tstring &strGuildName, DWORD dwGuildID, DWORD dwLeaderID, 
		DWORD dwCreatorNameID, BYTE byGuildLevel, INT16 n16GuildPeace, 
		INT32 nGuildFund, INT32 nGuildMaterial, INT32 nGuildRep, INT32 nGroupPurchase,
		INT32 nProsperity)
	{
		this->str_name				= strGuildName;
		this->dwID					= dwGuildID;	
		this->dwLeaderRoleID		= dwLeaderID;
		this->dwFounderNameID		= dwCreatorNameID;
		this->byLevel				= byGuildLevel;
		this->n16Peace				= n16GuildPeace;
		this->nDailyCost			= (INT32)MGuildDailyCost(this->byLevel, this->n16Peace);
		this->nFund					= nGuildFund;
		this->nMaterial				= nGuildMaterial;
		this->nReputation			= nGuildRep;
		this->nGroupPurchase		= nGroupPurchase;
		this->byAffairRemainTimes	= MGuildAffairTimes(this->byLevel);
		this->bCommendation			= FALSE;
		this->bFormal				= FALSE;
		this->bySignatoryNum		= 0;
		this->nApplyLevel			= 30;
		memset(this->dwSignRoleID, INVALID_VALUE, sizeof(this->dwSignRoleID));
		memset(this->dwEnemyID, INVALID_VALUE, sizeof(this->dwEnemyID));
		this->dwLeagueID = INVALID_VALUE;
		this->nProsperity = nProsperity;
		memset(this->n32ScriptData, 0, sizeof(this->n32ScriptData));
		memset(this->szText, 0, sizeof(this->szText));
	}
};

//! ����������Ϣ
struct s_create_guild_info
{
	DWORD		dw_guild_id;
	DWORD		dw_create_role_name_id;

	DWORD		dw_spec_state;

	INT32		n_guild_rep;
	INT32		n_guild_fund;
	INT32		n_guild_material;
	INT32		n_group_purchase;

	INT16		n16_guild_peace;
	BYTE		by_guild_level;
	BYTE		by_affair_remain_times;
	tagDWORDTime dw_create_time;
	TCHAR       sz_pos_name[X_GUILD_POS_NUM][MAX_GUILD_POS_NAME_LEN];   //����ְλ����
	DWORD       dw_pos_power[X_GUILD_POS_NUM];                          //����ְλȨ��
	tagDWORDTime dw_up_level_time;	
	tagDWORDTime dw_jujue_time;	
	DWORD			dw_sign_role_id[MAX_GUILD_SIGN_NUM];	//����ǩ����
	DWORD			dw_enemy_id[MAX_ENEMY_NUM];							  // �ж԰��
	INT			n_family_name[NPC_NAME_NUM];
	INT			n_name[NPC_NAME_NUM];
	TCHAR		sz_name[1];
};

//! �¼����Ա��Ϣ
struct s_create_guild_member_info
{
	DWORD		dw_role_id;
	DWORD		dw_guild_id;
	INT8		n8_guild_pos;
};

//! ������
struct s_invite
{
	DWORD		dw_inviter_id;	// ������id
	INT32		n_invite_count_down;

	s_invite(DWORD dwInviterID)
	{
		this->dw_inviter_id		= dwInviterID;
		this->n_invite_count_down	= MAX_GUILD_INVITE_DELAY_TIME;
	}
};

//! ��ʼ���Ӻ󣬶���Ľṹ
struct s_guild_load: public tagGuildBase
{
	TCHAR			sz_name[MAX_GUILD_NAME_LEN];			// ��������
	TCHAR			sz_tenet[MAX_GUILD_TENET_LEN];			// ������ּ
	TCHAR			sz_symbol[MAX_GUILD_TENET_LEN];		// ���ɱ�־
};

// ��ᵯ������ṹ
struct s_guild_delate_load : public tagGuildDelateBase
{
	TCHAR		sz_content[MAX_GUILD_DELATE_LEN];		// ��ᵯ������
};

struct s_guild_member_load
{
	DWORD			dw_guild_id_;
	tagGuildMember	s_guild_member_;
};


//! ����ʿ��λ����Ϣ
struct s_guild_enlistee_pos
{
	INT16	n_level_;
	DWORD	dw_creature_id_[MAX_GUILD_ENLISTEE_NUM];
	DWORD	dw_way_pos[MAX_GUILD_ENLISTEE_NUM];
};

//! ����pvp����λ����Ϣ
struct s_guild_pvp_banner_pos
{
	INT		n_act_id_;
	DWORD	dw_creature_id_[MAX_BANNER_NUM];
	FLOAT	v_pos_x_[MAX_BANNER_NUM];
	FLOAT	v_pos_z_[MAX_BANNER_NUM];
};


//! ������ʩλ����Ϣ
struct s_guild_grade_pos
{
	DWORD			dw_key_;
	DWORD			dw_creature_type_id_;
	DWORD			dw_creature_way_pos;

	DWORD			dw_npc_type_id;
	DWORD			dw_npc_way_pos;
};


//! ������ʩ��������ṹ
struct s_item_need_info 
{
	DWORD	dw_item_type_id;
	INT32	n_item_need_num;

	BOOL is_valid()
	{
		return VALID_VALUE(dw_item_type_id) && VALID_VALUE(n_item_need_num);
	}
};

struct s_guild_upgrade_need
{
	DWORD					dw_key;
	INT16					n16_full_fill;
	INT16					n16_step;
	INT32					n_fund;
	INT32					n_material;
	INT32					n_base_exploit;
	INT32					n_up_level_time_limit;
	INT32					n_dec_prosperity;
	BYTE					by_step;
	package_list<s_item_need_info>	list_item_info;

	s_guild_upgrade_need()
	{
		n16_full_fill		= 0;
		n16_step			= 0;
		n_fund			= 0;
		n_material		= 0;
		n_base_exploit	= 0;
		list_item_info.clear();
	}
};

//! ������ʩ�����ýṹ
struct s_facilities_load
{
	EFacilitiesType	e_type;
	DWORD			dw_guild_id;
	DWORD			dw_item_type_id[MAX_UPGRADE_NEED_ITEM_TYPE];
	INT32			n_item_need[MAX_UPGRADE_NEED_ITEM_TYPE];
	INT16			n16_progress;
	BYTE			by_level;
	BYTE			by_max_level;
	tagDWORDTime	dw_begin_up_time;
	BOOL			b_up_level;
	BOOL			b_dead;
	tagDWORDTime	dw_dead_begin_time;
	DWORD			dw_relive_time_limit;
	BYTE	byUseType;			// 0 ��ʹ�� 1 ʹ����
	BYTE	byUseNum;
	tagDWORDTime	dwUseTime;
	BYTE	byStep;

	s_facilities_load()
	{
		ZeroMemory(this, sizeof(*this));
	}

	s_facilities_load& operator= (tagGuildFacilitiesInfo& s_info)
	{
		e_type		= s_info.eType;
		by_level		= s_info.byLevel;
		by_max_level  = s_info.byMaxLevel;
		n16_progress	= s_info.nProgress;
		dw_begin_up_time = s_info.dwBeginUpTime;
		b_up_level    = s_info.bUpLevel;
		b_dead		= s_info.bDead;
		dw_dead_begin_time = s_info.dwDeadBeginTime;
		dw_relive_time_limit = s_info.dwReliveTimeLimit;
		byUseType = s_info.byUseType;
		byUseNum = s_info.byUseNum;
		dwUseTime = s_info.dwUseTime;
		byStep = s_info.byStep;

		for (int n=0; n<MAX_UPGRADE_NEED_ITEM_TYPE; n++)
		{
			dw_item_type_id[n]	= s_info.dwItemID[n];
			n_item_need[n]	= s_info.nNeedNum[n];
		}

		return *this;
	}
};


//! ����������Ϣ
struct s_guild_affair_info 
{
	DWORD		dw_buff_id;
	INT32		n_fund;
	INT32		n_material;
	BYTE		by_guild_level;
	BYTE		by_hold_city;
};


//! ���ɼ�����Ϣ
struct s_guild_skill_info
{
	DWORD		dw_skill_id;
	INT			n_level;
	BOOL		b_researching;	// ֻ������ʱʹ��
	INT16		n16_progress;
};


//! ����������Ϣ
struct s_redound_info
{
	INT32	n_exp;			// ���齱��
	INT32	n_contribution;	// ���ɹ��׽���
	INT32	n_exploit;		// ������������(δʵ��)
};

struct s_commerce_info		// ��������̬��Ϣ
{
	DWORD			dw_id;	// �ȼ���Χ
	tagTaelInfo		tagTaelInfo;
	s_redound_info	s_redound_info_;
};

struct s_guild_commerce_info 
{
	DWORD				dw_role_id;
	INT					n_level;
	INT32				n_tael;
	tagCommerceGoodInfo	s_good_info[MAX_COMMODITY_CAPACITY];
};


//! �����þ�̬��Ϣ
struct s_commodity_proto 
{
	DWORD				dw_good_id;
	INT32				n_low_price;
	INT32				n_high_price;
	BYTE				by_refresh_num;
	BYTE				by_holder_id;
};

struct s_cof_c_proto 
{
	INT64				n64_key;
	FLOAT				f_profit;
};

struct s_cof_csp_proto
{
	DWORD				dw_cof_cid;
	BYTE				by_holder_id;
};


//! ���ݵ�����
struct s_guild_pvp_data
{
	INT		n_act_id;				//�ID

	DWORD	dw_instance_id;		//����ID

	DWORD			dw_guild_id[MAX_BANNER_NUM];		//	����ռ����
	tagDWORDTime	dw_occupy_time[MAX_BANNER_NUM];	//  ����ռ����ʼʱ��

	VOID Init()
	{
		n_act_id = 0;
		dw_instance_id = INVALID_VALUE;
		memset(dw_guild_id, INVALID_VALUE, sizeof(dw_guild_id));
		memset(dw_occupy_time, 0, sizeof(dw_occupy_time));
	}

	VOID SetInstanceID(DWORD dwInstanceID)
	{
		this->dw_instance_id = dwInstanceID;
	}

	VOID Reset()
	{
		for(INT i = 1; i < MAX_BANNER_NUM; i++)
		{
			dw_guild_id[i] = INVALID_VALUE;
		}

		memset(dw_occupy_time, 0, sizeof(dw_occupy_time));
	}
};

struct s_load_guild_pvp_data
{
	INT		n_act_id;		// �ID

	DWORD	dw_guild_id[MAX_BANNER_NUM];		//	����ռ����
};

// ���boss��ɱ
struct s_guild_kill_boss
{
	DWORD	dw_monster_id;
	DWORD	dw_guild_id;
};

// �����ֲ��Ϣ
struct s_guild_plant
{
	DWORD	dw_guild_id;
	tagPlantData	s_data[MAX_PLANT_NUMBER];
};

// �����
struct tagGuildSSpawnPointProto
{
	DWORD	dw_creature_id;
	INT		n_pro[MAX_GUILD_LEVEL];
};
//! ���������Ӻ󣬶�ȡ�������
struct NET_DB2C_load_all_guild : public tag_net_message
{  
	NET_DB2C_load_all_guild ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_all_guild" ) ; 
		dw_size = sizeof ( * this ) ; 
	}
};  

//! ÿ�η���һ��������Ϣ
struct NET_DB2S_load_all_guild : public tag_net_message
{ 
	NET_DB2S_load_all_guild ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_load_all_guild" ) ;  
		dw_size = sizeof ( * this ) ; 
	}  
	s_guild_load s_guild_load_;   
};  

struct NET_DB2C_load_all_guild_member : public tag_net_message
{  
	NET_DB2C_load_all_guild_member ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_all_guild_member" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
};  

struct NET_DB2S_load_all_guild_member : public tag_net_message
{  
	NET_DB2S_load_all_guild_member ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2S_load_all_guild_member" ) ;  
		dw_size = sizeof ( * this ) ; 
	}  
	INT n_all_guild_num;  
	s_guild_member_load guild_member_load_[1];    
};  

struct NET_DB2C_guild_init_ok : public tag_net_message 
{  
	NET_DB2C_guild_init_ok ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_guild_init_ok" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
};  

struct NET_DB2S_guild_init_ok : public tag_net_message 
{  
	NET_DB2S_guild_init_ok ( )
	{
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_guild_init_ok" ) ;
		dw_size = sizeof ( * this ) ;
	}  
};  

//! �ر���Ϸ������ʱ������İ�������
struct NET_DB2C_save_all_guild : public tag_net_message 
{   
	NET_DB2C_save_all_guild ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_save_all_guild" ) ;   
		dw_size = sizeof ( * this ) ;  
	} 
	INT n_guild_num;
	tagGuildBase guild_base[1];    
};  

struct NET_DB2C_save_all_guild_plant : public tag_net_message 
{   
	NET_DB2C_save_all_guild_plant ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_save_all_guild_plant" ) ;   
		dw_size = sizeof ( * this ) ;  
	} 
	INT n_guild_num;
	s_guild_plant guild_plant[1];    
};  

//! ���Ա��ʱ����İ�������
struct NET_DB2C_save_guild_att : public tag_net_message 
{   
	NET_DB2C_save_guild_att ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_save_guild_att" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	tagGuildBase p_guild_base;  
};  

struct NET_DB2C_save_plant : public tag_net_message
{   
	NET_DB2C_save_plant ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_save_plant" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	s_guild_plant p_guild_plant;  
};

struct NET_DB2C_change_guild_pos_name : public tag_net_message
{   
	NET_DB2C_change_guild_pos_name ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_change_guild_pos_name" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_guild_id;  
	TCHAR sz_pos_name[X_GUILD_POS_NUM][MAX_GUILD_POS_NAME_LEN];   
};  


//! �޸ļ���ְλȨ��
struct NET_DB2C_change_guild_pos_power : public tag_net_message 
{  
	NET_DB2C_change_guild_pos_power ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_guild_pos_power" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_guild_id; 
	DWORD dw_pos_power[X_GUILD_POS_NUM];   
};  



//! ��������
struct NET_DB2C_create_guild : public tag_net_message 
{  
	NET_DB2C_create_guild ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_create_guild" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	s_create_guild_info create_guild_info_;    
};  

//! �������� -- ���ݿⴴ��ʧ�ܲŻ᷵��//??��δ����
struct NET_DB2S_create_guild : public tag_net_message
{  
	NET_DB2S_create_guild ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_create_guild" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_error_code; 
	DWORD dw_guild_id;    
};  

struct NET_DB2C_dismiss_guild : public tag_net_message
{   
	NET_DB2C_dismiss_guild ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_dismiss_guild" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_guild_id;    
};  

struct ET_DB2C_reset_signUpAttact : public tag_net_message
{
	ET_DB2C_reset_signUpAttact ()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc( "ET_DB2C_reset_signUpAttact" );
		dw_size = sizeof(*this);
	}
};

//! �޸İ�����ּ
struct NET_DB2C_change_guild_tenet : public tag_net_message
{  
	NET_DB2C_change_guild_tenet ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_change_guild_tenet" ) ;
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_guild_id; 
	TCHAR sz_new_tenet[1];  
};  

//! �޸İ��ɱ�־
struct NET_DB2C_change_guild_symbol : public tag_net_message 
{   
	NET_DB2C_change_guild_symbol ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_guild_symbol" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_guild_id;  
	TCHAR by_guild_symbol[1];
};  


//! �������
struct NET_DB2C_join_guild : public tag_net_message 
{  
	NET_DB2C_join_guild ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_join_guild" ) ; 
		dw_size = sizeof ( * this ) ; 
	} 
	s_create_guild_member_info guild_member_info;  
};  

//! �뿪���ɻ���
struct NET_DB2C_leave_guild : public tag_net_message 
{ 
	NET_DB2C_leave_guild ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_leave_guild" ) ;   
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_role_id;   
};  


//! ����ְλ�ı�
struct NET_DB2C_change_guild_pos : public tag_net_message
{   
	NET_DB2C_change_guild_pos ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_guild_pos" ) ;  
		dw_size = sizeof ( * this ) ;
	}   
	DWORD dw_role_id; 
	INT8 n_new_pos;    
};  


//! ���ɹ��׸ı�
struct NET_DB2C_change_contrib : public tag_net_message 
{   
	NET_DB2C_change_contrib ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_contrib" ) ;
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_role_id; 
	INT32 n_contribution;  // �仯�����
	INT32 n_total_contribution;  
	INT32 n_total_fund;
};  

struct NET_DB2C_change_exmloit : public tag_net_message 
{  
	NET_DB2C_change_exmloit ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_change_exmloit" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;  
	INT32 n_exploit;   
};  

struct NET_DB2C_change_ballot : public tag_net_message 
{   
	NET_DB2C_change_ballot ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_ballot" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id;  
	BOOL b_ballot;  
};  

struct NET_DB2C_change_can_war : public tag_net_message 
{   
	NET_DB2C_change_can_war ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_can_war" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 

	DWORD dw_role_id;  
	BOOL b_war;  
};  

struct NET_DB2C_change_dkp : public tag_net_message 
{   
	NET_DB2C_change_dkp ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_dkp" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id; 
	INT32 n_dkp;  
};  

//CMD_START(NDBC_ChangeGuildExploit)	// ���ɹ�ѫ�ı�
//	DWORD		dw_role_id;
//	INT32		nNewExploit;
//CMD_END
//
//CMD_START(NDBC_ChangeGuildSalary)	// ���ɹ��ʸı�
//	DWORD		dw_role_id;
//	INT32		nNewSalary;
//CMD_END


//! ���ɲֿ�
struct NET_DB2C_load_guild_ware_items : public tag_net_message 
{   
	NET_DB2C_load_guild_ware_items ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_guild_ware_items" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_guild_id;   
};  

struct NET_DB2S_load_guild_ware_items : public tag_net_message 
{  
	NET_DB2S_load_guild_ware_items ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_guild_ware_items" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_guild_id;  
	INT n_item_num;   
	BYTE by_data[1];  
};  

//! ���ɲֿ�Ȩ�ޱ��
struct NET_DB2C_guild_ware_pri : public tag_net_message 
{ 
	NET_DB2C_guild_ware_pri ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_guild_ware_pri" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id; 
	BOOL b_enable;     
};  

struct NET_DB2C_save_guild_ware : public tag_net_message 
{  
	NET_DB2C_save_guild_ware ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_save_guild_ware" ) ; 
		dw_size = sizeof ( * this ) ; 
	} 
	INT n_item_num;  
	BYTE by_data[1];   
};  


//! ������ʩ
struct NET_DB2C_load_facilities_info : public tag_net_message 
{   
	NET_DB2C_load_facilities_info ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_facilities_info" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_guild_id;   
};  

struct NET_DB2S_load_facilities_info : public tag_net_message 
{  
	NET_DB2S_load_facilities_info ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_facilities_info" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_guild_id;
	INT32 n_info_num;  
	s_facilities_load s_facilities_info_[1];
};  

struct NET_DB2C_create_facilities : public tag_net_message
{  
	NET_DB2C_create_facilities ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_create_facilities" ) ;  
		dw_size = sizeof ( * this ) ;   
	} 
	s_facilities_load s_facilities_info_;
};  

struct NET_DB2C_facilities_upgrade : public tag_net_message
{  
	NET_DB2C_facilities_upgrade ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_facilities_upgrade" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	s_facilities_load s_facilities_info_;  
};  

struct NET_DB2C_remove_all_facilities : public tag_net_message 
{  
	NET_DB2C_remove_all_facilities ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_remove_all_facilities" ) ;   
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_guild_id;    
};  


//! ���ɼ���
struct NET_DB2C_load_guild_skill_info : public tag_net_message
{   
	NET_DB2C_load_guild_skill_info ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_load_guild_skill_info" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_guild_id;   
};  

struct NET_DB2S_load_guild_skill_info : public tag_net_message
{   
	NET_DB2S_load_guild_skill_info ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_guild_skill_info" ) ; 
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_guild_id;  
	INT n_info_num_;  
	s_guild_skill_info s_guild_skill_info_[1];  
};  


struct NET_DB2C_create_guild_skill : public tag_net_message
{   
	NET_DB2C_create_guild_skill ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_create_guild_skill" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_guild_id;  
	s_guild_skill_info s_skill_info;  
};  

struct NET_DB2C_save_guild_skill : public tag_net_message
{   
	NET_DB2C_save_guild_skill ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_save_guild_skill" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_guild_id;  
	s_guild_skill_info s_skill_info; 
};  

struct NET_DB2C_change_research_skill : public tag_net_message
{   
	NET_DB2C_change_research_skill ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_research_skill" ) ;
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_guild_id; 
	DWORD dw_new_skill_id;   
};  

struct NET_DB2C_remove_guild_skill : public tag_net_message 
{  
	NET_DB2C_remove_guild_skill ( ) 
	{
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_remove_guild_skill" ) ;
		dw_size = sizeof ( * this ) ;    
	} 
	DWORD dw_guild_id;  
};  


//! ���ɵ���
struct NET_DB2C_create_guild_delate : public tag_net_message 
{  
	NET_DB2C_create_guild_delate ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_create_guild_delate" ) ;   
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_guild_id;   
};  

struct NET_DB2C_load_guild_delate : public tag_net_message
{  
	NET_DB2C_load_guild_delate ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_guild_delate" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_guild_id;  
};  


struct NET_DB2S_load_guild_delate : public tag_net_message 
{  
	NET_DB2S_load_guild_delate ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2S_load_guild_delate" ) ; 
		dw_size = sizeof ( * this ) ;
	}  
	s_guild_delate_load s_guild_delate_load_;  
};  


struct NET_DB2C_remove_guild_delate : public tag_net_message 
{  
	NET_DB2C_remove_guild_delate ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_remove_guild_delate" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_guild_id; 
};  

struct NET_DB2C_update_guild_dalate : public tag_net_message 
{
	NET_DB2C_update_guild_dalate ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_update_guild_dalate" ) ;   
		dw_size = sizeof ( * this ) ;    
	}   
	tagGuildDelateBase s_guild_delate_base_;    
};  


struct NET_DB2C_update_guild_delate_content : public tag_net_message
{   
	NET_DB2C_update_guild_delate_content ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_guild_delate_content" ) ;   
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_guild_id;  
	TCHAR sz_content[1];  
};  



//! ��������
struct NET_DB2C_load_commodity : public tag_net_message
{  
	NET_DB2C_load_commodity ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_commodity" ) ; 
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_guild_id;  
};  


struct NET_DB2S_load_commodity : public tag_net_message 
{   
	NET_DB2S_load_commodity ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_commodity" ) ;
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_guild_id;  
	INT n_commodity_num;   
	s_guild_commerce_info s_commerce_info_[1];   
};  

struct NET_DB2C_load_commerce_rank : public tag_net_message
{   
	NET_DB2C_load_commerce_rank ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_commerce_rank" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_guild_id;    
};  

struct NET_DB2S_load_commerce_rank : public tag_net_message 
{   
	NET_DB2S_load_commerce_rank ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_commerce_rank" ) ; 
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_guild_id;
	INT n_rank_num;  
	tagCommerceRank s_rank_info[1];  
};  


//! ��ʼ�̻�����Ϊ��
struct NET_DB2C_create_commodity : public tag_net_message
{   
	NET_DB2C_create_commodity ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_create_commodity" ) ;  
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_guild_id;
	DWORD dw_role_id; 
	INT n_level;  
	INT32 n_tael;   
};  

struct NET_DB2C_change_tael : public tag_net_message 
{   
	NET_DB2C_change_tael ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_change_tael" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id;   
	INT32 n_tael;  
};  


struct NET_DB2C_save_commodity : public tag_net_message 
{   
	NET_DB2C_save_commodity ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_save_commodity" ) ;
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id; 
	tagCommerceGoodInfo s_good_info[MAX_COMMODITY_CAPACITY]; 
};  

struct NET_DB2C_remove_commodity : public tag_net_message 
{   
	NET_DB2C_remove_commodity ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_remove_commodity" ) ;
		dw_size = sizeof ( * this ) ;
	}   DWORD dw_role_id;    
};  

struct NET_DB2C_set_commendation : public tag_net_message 
{  
	NET_DB2C_set_commendation ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_set_commendation" ) ;
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_guild_id; 
	BOOL b_commend;    
};  

struct NET_DB2C_update_commerce_rank : public tag_net_message 
{  
	NET_DB2C_update_commerce_rank ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_update_commerce_rank" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_guild_id;
	tagCommerceRank s_rank_info;  
};  

struct NET_DB2C_remove_commerce_rank : public tag_net_message
{  
	NET_DB2C_remove_commerce_rank ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_remove_commerce_rank" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_guild_id;  
	DWORD dw_role_id;  

};  

//! ����pvp
struct NET_DB2C_insert_pvp_data : public tag_net_message 
{  
	NET_DB2C_insert_pvp_data ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_insert_pvp_data" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
	INT n_act_id;  //  �ID
	DWORD dw_guild_id[MAX_BANNER_NUM]; //	����ռ����
};  


struct NET_DB2C_load_pvp_data : public tag_net_message 
{   
	NET_DB2C_load_pvp_data ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_pvp_data" ) ; 
		dw_size = sizeof ( * this ) ;   
	}   
};  

struct NET_DB2S_load_pvp_data : public tag_net_message 
{  
	NET_DB2S_load_pvp_data ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_load_pvp_data" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	INT n_count;  
	s_load_guild_pvp_data st_load_guild_pvp_data[1]; 
};  

struct NET_DB2C_up_pvp_data : public tag_net_message 
{   
	NET_DB2C_up_pvp_data ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_up_pvp_data" ) ; 
		dw_size = sizeof ( * this ) ; 
	}   
	INT n_act_id; //  �ID
	DWORD dw_guild_id[MAX_BANNER_NUM];  //	����ռ����
}; 

struct NET_C2DB_clean_guild_recruit : public tag_net_message
{
	NET_C2DB_clean_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_guild_recruit");
		dw_size = sizeof(*this);
	}
};

// �����ļ��
struct NET_C2DB_load_guild_recruit : public tag_net_message
{
	NET_C2DB_load_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_load_guild_recruit");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2C_load_guild_recruit : public tag_net_message
{
	NET_DB2C_load_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_guild_recruit");
		dw_size = sizeof(*this);
	}
	INT			n_num;
	DWORD		p_data[1];
};

struct NET_C2DB_insert_guild_recruit : public tag_net_message
{
	NET_C2DB_insert_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_insert_guild_recruit");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
};

struct NET_C2DB_delete_guild_recruit : public tag_net_message
{
	NET_C2DB_delete_guild_recruit()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_delete_guild_recruit");
		dw_size = sizeof(*this);
	}
	DWORD dw_role_id;
};

// ����ɱboss
struct NET_C2DB_load_guild_skill_boss : public tag_net_message
{
	NET_C2DB_load_guild_skill_boss()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_load_guild_skill_boss");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2C_load_guild_skill_boss : public tag_net_message
{
	NET_DB2C_load_guild_skill_boss()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_guild_skill_boss");
		dw_size = sizeof(*this);
	}
	INT		n_num;
	s_guild_kill_boss st_guild_kill_boss[1];
};

struct NET_C2DB_insert_guild_skill_boss : public tag_net_message
{
	NET_C2DB_insert_guild_skill_boss()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_insert_guild_skill_boss");
		dw_size = sizeof(*this);
	}
	s_guild_kill_boss st_guild_kill_boss;
};


// ���ս��
struct NET_C2DB_load_guild_war_history : public tag_net_message
{
	NET_C2DB_load_guild_war_history()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_load_guild_war_history");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2C_load_guild_war_history : public tag_net_message
{
	NET_DB2C_load_guild_war_history()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_guild_war_history");
		dw_size = sizeof(*this);
	}
	INT		n_num;
	tagGuildWarHistory st_guild_war_history[1];
};

//! ��ȡ�����ֲ��Ϣ
struct NET_C2DB_load_guild_plant_data : public tag_net_message
{  
	NET_C2DB_load_guild_plant_data ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_C2DB_load_guild_plant_data" ) ; 
		dw_size = sizeof ( * this ) ; 
	}
}; 

struct NET_DB2C_load_guild_plant_data : public tag_net_message
{
	NET_DB2C_load_guild_plant_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_guild_plant_data");
		dw_size = sizeof(*this);
	}
	s_guild_plant	s_plant_data;
};

struct NET_C2DB_insert_guild_war_history : public tag_net_message
{
	NET_C2DB_insert_guild_war_history()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_insert_guild_war_history");
		dw_size = sizeof(*this);
	}
	tagGuildWarHistory st_guild_war_history;
};

struct NET_C2DB_delete_guild_war_history : public tag_net_message
{
	NET_C2DB_delete_guild_war_history()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_delete_guild_war_history");
		dw_size = sizeof(*this);
	}
	tagGuildWarHistory st_guild_war_history;
};


// ����ɳ�Ϳ�����
struct NET_C2DB_save_sbk : public tag_net_message
{
	NET_C2DB_save_sbk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_save_sbk");
		dw_size = sizeof(*this);
	}

	DWORD dw_guild_id;
};
struct NET_C2DB_load_sbk : public tag_net_message
{
	NET_C2DB_load_sbk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_load_sbk");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2C_load_sbk : public tag_net_message
{
	NET_DB2C_load_sbk()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_sbk");
		dw_size = sizeof(*this);
	}

	DWORD dw_guild_id;
};

//-----------------------------------------------------------------------------
#pragma pack(pop)