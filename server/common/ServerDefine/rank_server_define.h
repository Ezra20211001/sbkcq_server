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
*	@file		rank_define.h
*	@author		mmz
*	@date		2010/12/21	initial
*	@version	0.0.1.0
*	@brief		���а�ṹ����
*/


#pragma once

#pragma pack(push, 1)


//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum
{
	e_rank_lock				=		0,		// ���а����ڸ�����
};


struct s_level_rank
{
	DWORD			dw_role_id;			// ����ID
	INT				n_level_;				// ����ȼ�
	EClassType		e_class;				// ְҵ
	DWORD			dw_guild_id;			// ���ID
};

struct tag1v1ScoreRank
{
	DWORD	dw_role_id;
	INT		n_level;
	EClassType		e_class;
	INT	dw_score;
};

struct tagGuildRank
{
	DWORD	dw_guild_id;			// ���ID
	INT		n_level_;				// ���ȼ�
	INT		n_prosperity_;			// �������
	DWORD	dw_leader_id_;			// ����ID
};

struct tagKillRank
{
	DWORD		dw_role_id;			// ����ID
	INT			n_level_;				// ����ȼ�
	INT			n_kill_num_;			// ɱ����
	DWORD		dw_guild_id;			// ���ID
};

struct tagJusticeRank
{
	DWORD		dw_role_id;			// ����ID
	INT			n_level_;			// ����ȼ�
	INT32		n32_justice;		// ս��
	EClassType		e_class;		// ְҵ
	BYTE		by_Sex;
};

struct tagShihunRank
{
	DWORD		dw_role_id;
	INT			n_level_;
	EClassType		e_class;
	DWORD		dw_shihun;
	BYTE		by_sex;

};

// �ɾ͵�������
struct tagAchievementPointRank
{
	DWORD		dw_role_id;
	INT			n_level_;
	DWORD		dw_point;
};

// �ɾ���������
struct tagAchievementNumberRank
{
	DWORD		dw_role_id;
	INT			n_level_;
	DWORD		dw_number;
};
//ʦͽ�� gx add 2013.12.06
struct tagMasterGraduateRank
{
	DWORD dw_role_id;
	INT n_Graduates;//��ʦ����
	INT			n_level_;
	EClassType		e_class;
	BYTE		by_Sex;
	BYTE		by_online;
};
// �����
struct tagMountsRank
{
	DWORD		dw_role_id;
	INT			n_setp;
	INT			n_grade;
};

// ��ֵ��
struct tagtotalReachRank
{
	DWORD		dw_role_id;
	INT			n_total_reach;
};

//! ��ȡ�ȼ����а�
struct NET_DB2C_load_level_randk : public tag_net_message 
{   
	NET_DB2C_load_level_randk ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_level_randk" ) ; 
		dw_size = sizeof ( * this ) ; 
	}   
};  

struct NET_DB2S_load_level_rank : public tag_net_message 
{  
	NET_DB2S_load_level_rank ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_load_level_rank" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
	INT n_count;  
	s_level_rank s_level_rank_[100];   
};  

//! ��ȡװ�����а�
struct NET_DB2C_load_equip_rank : public tag_net_message
{   
	NET_DB2C_load_equip_rank ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_equip_rank" ) ;
		dw_size = sizeof ( * this ) ;   
	}  
};  

struct NET_DB2S_load_equip_rank : public tag_net_message
{  
	NET_DB2S_load_equip_rank ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_equip_rank" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	tagEquip s_equip;   
}; 

// ! ��ȡ1v1���ְ�
struct NET_DB2C_load_1v1_score_rank : public tag_net_message
{
	NET_DB2C_load_1v1_score_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_1v1_score_rank");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2S_load_1v1_score_rank : public tag_net_message
{
	NET_DB2S_load_1v1_score_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_1v1_score_rank");
		dw_size = sizeof(*this);
	}
	INT n_count;
	tag1v1ScoreRank st_1v1ScoreRank[100];
};

//! ��ȡ������а�
struct NET_DB2C_load_guild_rank : public tag_net_message 
{   
	NET_DB2C_load_guild_rank ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_guild_rank" ) ;
		dw_size = sizeof ( * this ) ; 
	}   
};  

struct NET_DB2S_load_guild_rank : public tag_net_message 
{   
	NET_DB2S_load_guild_rank ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2S_load_guild_rank" ) ;   
		dw_size = sizeof ( * this ) ;    
	}  
	INT n_count;
	tagGuildRank s_guild_rank_[100]; 
};  

//! ��ȡ���˰�
struct NET_DB2C_load_kill_rank : public tag_net_message
{  
	NET_DB2C_load_kill_rank ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_kill_rank" ) ;  
		dw_size = sizeof ( * this ) ;   
	}    
};  

struct NET_DB2S_load_kill_rank : public tag_net_message 
{   
	NET_DB2S_load_kill_rank ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_load_kill_rank" ) ;
		dw_size = sizeof ( * this ) ;   
	}   
	INT n_count; 
	tagKillRank s_kill_rank_[100];     
};  

// ��ȡ�����
struct NET_DB2C_load_justice_rank : public tag_net_message
{
	NET_DB2C_load_justice_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_justice_rank");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2S_load_justice_rank : public tag_net_message
{
	NET_DB2S_load_justice_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_justice_rank");
		dw_size = sizeof(*this);
	}
	INT n_count;
	tagJusticeRank s_justice_rank_[100];
};

// �ɻ��
struct NET_DB2C_load_shihun_rank : public tag_net_message
{
	NET_DB2C_load_shihun_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_shihun_rank");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2S_load_shihun_rank : public tag_net_message
{
	NET_DB2S_load_shihun_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_shihun_rank");
		dw_size = sizeof(*this);
	}
	INT n_count;
	tagShihunRank s_shihun_rank[100];
};

// �ɾ͵�����
struct NET_DB2C_load_achievement_point_rank : public tag_net_message
{
	NET_DB2C_load_achievement_point_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_achievement_point_rank");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2S_load_achievement_point_rank : public tag_net_message
{
	NET_DB2S_load_achievement_point_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_achievement_point_rank");
		dw_size = sizeof(*this);
	}
	INT n_count;
	tagAchievementPointRank s_point_rank[100];
};

// �ɾ�������
struct NET_DB2C_load_achievement_number_rank : public tag_net_message
{
	NET_DB2C_load_achievement_number_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_achievement_number_rank");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2S_load_achievement_number_rank : public tag_net_message
{
	NET_DB2S_load_achievement_number_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_achievement_number_rank");
		dw_size = sizeof(*this);
	}
	INT n_count;
	tagAchievementNumberRank s_number_rank[100];
};

//! ��ȡʦͽ���а� gx add 2013.12.06
struct NET_DB2C_load_MasterGraduate_randk : public tag_net_message 
{   
	NET_DB2C_load_MasterGraduate_randk ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_MasterGraduate_randk" ) ; 
		dw_size = sizeof ( * this ) ; 
	}   
};  

struct NET_DB2S_load_MasterGraduate_rank : public tag_net_message 
{  
	NET_DB2S_load_MasterGraduate_rank ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_load_MasterGraduate_rank" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
	INT n_count;  
	tagMasterGraduateRank s_master_rank_[100];   
};  
//end
// �����
struct NET_DB2C_load_mounts_rank : public tag_net_message
{
	NET_DB2C_load_mounts_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_mounts_rank");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2S_load_mounts_rank : public tag_net_message
{
	NET_DB2S_load_mounts_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_mounts_rank");
		dw_size = sizeof(*this);
	}
	INT n_count;
	tagMountsRank s_mounts_rank[100];
};

// ��ֵ��
struct NET_DB2C_load_reach_rank : public tag_net_message
{
	NET_DB2C_load_reach_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_reach_rank");
		dw_size = sizeof(*this);
	}
};

struct NET_DB2S_load_reach_rank : public tag_net_message
{
	NET_DB2S_load_reach_rank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_reach_rank");
		dw_size = sizeof(*this);
	}
	INT n_count;
	tagtotalReachRank s_reach_rank[100];
};

#pragma pack(pop)
