
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//������ͨ���������û����ṹ
#ifndef _FAMEHALL_SERVER_DEFINE_H_
#define _FAMEHALL_SERVER_DEFINE_H_


#include "../common/WorldDefine/famehall_define.h"
#include "../common/WorldDefine/reputation.h"

#pragma pack(push, 1)

enum e_reasure_state
{
	ers_null		= -1,
	ers_begin		= 0,

	ers_nuact		= 0,		//! δ����
	ers_act			= 1,		//! ����

	ers_end,
	ers_num		= ers_end,
};

//! ���������ÿ��������Ŀ
const UINT16 MAX_ENTER_FAMEHALL_SNAP_NUM	= 50;

//! ���������ý�ɫ�����Ŀ
const UINT16 MAX_ENTER_FAMEHALL_ROLE_NUM	= 5000;

// �����䱦�����Ŀ
const UINT16 MAX_ACT_TREASURE_NUM			= CLAN_TREASURE_NUM;



struct tagFameHallEnterSnap
{
	DWORD			dwEnterNameID;
	DWORD			dw_role_id;
	tagDWORDTime	dwtEnterTime;

	BOOL operator ==(const tagFameHallEnterSnap& rhs)
	{
		// �������RoleID����
		return dw_role_id == rhs.dw_role_id /*&& dwEnterNameID == rhs.dwEnterNameID*/;
	}
};


//! ������������ʱ���
struct NET_DB2C_update_reprst_time : public tag_net_message 
{  
	NET_DB2C_update_reprst_time ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_update_reprst_time" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dwRepRstTimeStamp;  
	BYTE byClanType;  
};  



//! �����������
struct NET_DB2C_get_rep_rank_list : public tag_net_message 
{  
	NET_DB2C_get_rep_rank_list ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_get_rep_rank_list" ) ;
		dw_size = sizeof ( * this ) ;  
	}   
	BYTE byClanType; 
};  

struct NET_DB2S_get_rep_rank_list : public tag_net_message
{   
	NET_DB2S_get_rep_rank_list ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_get_rep_rank_list" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	BYTE byClanType; 
	DWORD dw_error_code;  
	INT16 nRecNum;  
	tagRepRankData repRank[MAX_REP_RANK_NUM];  
};  


//! �����ó�ʼ��
struct NET_DB2C_fame_hall_init_start : public tag_net_message 
{   
	NET_DB2C_fame_hall_init_start ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_fame_hall_init_start" ) ;  
		dw_size = sizeof ( * this ) ; 
	}     
};  

//! ��������ʱ���
struct NET_DB2S_get_rep_reset_times_tamp : public tag_net_message
{  
	NET_DB2S_get_rep_reset_times_tamp ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_get_rep_reset_times_tamp" ) ;
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dwResetTime[ECLT_NUM];  
};  



//! ����Ѽ����䱦
struct NET_DB2S_get_act_treasure_list : public tag_net_message 
{  
	NET_DB2S_get_act_treasure_list ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_get_act_treasure_list" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	INT16 nRecNum[ECLT_NUM]; 
	tagTreasureData treasureData[MAX_ACT_TREASURE_NUM];    
};  


//! ��û�ý��������ÿ���
struct NET_DB2S_get_fame_hall_enter_snap : public tag_net_message 
{  
	NET_DB2S_get_fame_hall_enter_snap ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_get_fame_hall_enter_snap" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	INT16 nRecNum[ECLT_NUM];  
	tagFameHallEnterSnap enterSnap[MAX_ENTER_FAMEHALL_SNAP_NUM * ECLT_NUM];
};  


//! ����������
struct NET_DB2C_insert_fame_hall_snap : public tag_net_message
{  
	NET_DB2C_insert_fame_hall_snap ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_insert_fame_hall_snap" ) ; 
		dw_size = sizeof ( * this ) ; 
	} 
	BYTE byClanType;		// ��������
	DWORD dw_role_id;		// ��ɫid
	DWORD dwEnterNameID;	// ����������������id
	DWORD dwEnterTime;		// tagDWORDTime
};  


//! �����䱦
struct NET_DB2C_insert_act_clan_treasure : public tag_net_message 
{  
	NET_DB2C_insert_act_clan_treasure ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_insert_act_clan_treasure" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	BYTE byClanType;			// ��������
	UINT16 u16TreasureID;		// �䱦��������Ʒid
	DWORD dw_role_id;			// �����䱦������id
	DWORD dwActNameID;			// �����䱦ʱ������id
	DWORD dwActTime;			// ����ʱ��
};  


#pragma pack(pop)

#endif