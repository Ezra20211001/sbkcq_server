
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//����������Ʒ��ؽṹ

#pragma once

#include "../common/WorldDefine/ItemDefine.h"


#pragma pack(push, 1)

//! �����ĸ��¼��ʱ��
const INT ITEM_UPDATE_TIME		= 60 * TICK_PER_SECOND;		// 60s


//-----------------------------------------------------------------------------
//! ��Ʒ�ƶ�����
//-----------------------------------------------------------------------------
struct s_item_move
{
	tagItem	*p_item2;		//! Ŀ��λ���ϵ���Ʒ
	INT16	n_num_res1;		//! ���ƶ���Ʒ�����ո���
	INT16	n_num_res2;		//! Ŀ��λ������Ʒ�����ո���
	bool	b_create_item;	//! Ŀ��λ���ϵ���Ʒ�Ƿ�Ϊ�´�����(���ʱΪtrue)
	bool	b_overlap;		//! �Ƿ�ѵ�
	bool	b_change_pos;	//! λ���Ƿ��ƶ�

	s_item_move()
	{
		Init();
	}
	
	VOID Init()
	{
		p_item2		= NULL;
		n_num_res1	= 0;
		n_num_res2	= 0;
		b_create_item = FALSE;
		b_overlap	= FALSE;
		b_change_pos	= TRUE;
	}
};

//-----------------------------------------------------------------------------
//! ��ɫ���ݱ���ʱ����µ���Ʒ����
//-----------------------------------------------------------------------------
struct s_item_update
{
	INT64			n64_serial;
	DWORD			dw_owner_id;
	DWORD			dw_account_id;
	INT32			n_use_times;		// ��Ʒ�ϼ���ʹ�ô���
	INT16			n16_num;			// ��Ʒ����
	INT16			n16_index;		// ������λ��
	BYTE			by_conType;		// ��������
	BYTE			by_bind;			// ��
	tagDWORDTime	dw_bind_time;	// ��ʱ��
	DWORD			dw_script_data[2];	// �ű�����
};

struct s_equip_spec_update
{
	INT64			n64_serial;
	tagEquipSpec	equip_spec;
};

//-----------------------------------------------------------------------------
//! IM ��ƷӰ������ö��
//-----------------------------------------------------------------------------
enum e_ime_effect
{
	eime_null			= 0,

	eime_color			= 1,	// ��ɫ
	eime_comadvance		= 2,	// ��߳ɹ�����
	eime_protectsign	= 3,	// ���׷���ǿ��ʧ��ʱ������װ��Ǳ��ֵ��
};

//-----------------------------------------------------------------------------
//! IM ��ƷӰ��
//-----------------------------------------------------------------------------
struct s_ime_effect
{
	e_ime_effect	e_effect;	// Ӱ�����
	DWORD			dw_param1;	// Ӱ��ֵ
	DWORD			dw_param2;
	s_ime_effect()
	{
		e_effect = eime_null;
		dw_param1 = 0;
		dw_param2 = 0;
	}
};



//! �����Ϸ������ȫ����Ʒ�����Ϣ
struct NET_DB2C_get_item_info : public tag_net_message 
{  
	NET_DB2C_get_item_info ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_get_item_info" ) ;  
		dw_size = sizeof ( * this ) ;    
	}   
};  

struct NET_DB2S_get_item_info : public tag_net_message 
{  
	NET_DB2S_get_item_info ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_get_item_info" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_dummy;
	INT64 n64_max_serial; 
	INT64 n64_min_serial;  
};  

struct NET_DB2C_new_item : public tag_net_message
{  
	NET_DB2C_new_item ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_new_item" ) ; 
		dw_size = sizeof ( * this ) ;  
	}   
	tagItem item;  
};  

struct NET_DB2C_new_equip : public tag_net_message
{  
	NET_DB2C_new_equip ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_new_equip" ) ;  
		dw_size = sizeof ( * this ) ;    
	} 
	tagEquip equip;    
};  

struct NET_DB2C_delete_item : public tag_net_message
{   
	NET_DB2C_delete_item ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_item" ) ;
		dw_size = sizeof ( * this ) ; 
	}   
	INT64 n64_serial; 
};  

struct NET_DB2C_delete_equip : public tag_net_message 
{  
	NET_DB2C_delete_equip ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_equip" ) ;  
		dw_size = sizeof ( * this ) ;   
	} 
	INT64 n64_serial;   
};  

struct NET_DB2C_new_baibao_item : public tag_net_message 
{  
	NET_DB2C_new_baibao_item ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_new_baibao_item" ) ;
		dw_size = sizeof ( * this ) ;  
	}  
	tagItem item;    
};  

struct NET_DB2C_new_baibao_equip : public tag_net_message 
{ 
	NET_DB2C_new_baibao_equip ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_new_baibao_equip" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	tagEquip equip;    
};  

struct NET_DB2C_delete_baobao_item : public tag_net_message 
{  
	NET_DB2C_delete_baobao_item ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_baobao_item" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	INT64 n64_serial;   
};  

struct NET_DB2C_delete_baibao_equip : public tag_net_message
{  
	NET_DB2C_delete_baibao_equip ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_baibao_equip" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	INT64 n64_serial;   
};  

//CMD_START(NDBC_UpdateItemPos)	// ������Ʒλ��
//	DWORD		dw_account_id;
//	INT64		n64_serial;
//	DWORD		dw_role_id;
//	INT32		nUseTimes;		// ��Ʒ�ϼ���ʹ�ô���
//	INT16		n16Num;			// ��Ʒ����
//	INT16		n16_index;		// ������λ��
//	BYTE		byConType;		// ��������
//CMD_END;


// ����װ�����ԣ���װ�����Ա�
struct NET_DB2C_update_equip_att : public tag_net_message 
{
	NET_DB2C_update_equip_att ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_equip_att" ) ; 
		dw_size = sizeof ( * this ) ; 
	}   
	s_equip_spec_update equip_spec_update;    
};  


//CMD_START(NDBC_ReplaceItemCDTime)	// �洢��Ʒ��ȴʱ��
//	DWORD			dw_role_id;
//	INT32			n_num;			// ����
//	BYTE			byCDTime[1];	// tagCDTime
//CMD_END;



//! ѹ��ר��
struct NET_DB2C_test_save_item : public tag_net_message 
{   
	NET_DB2C_test_save_item ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_test_save_item" ) ;  
		dw_size = sizeof ( * this ) ; 
	}   
	tagItem item;   
};  

struct NET_DB2C_test_save_equip : public tag_net_message 
{  
	NET_DB2C_test_save_equip ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_test_save_equip" ) ;  
		dw_size = sizeof ( * this ) ; 
	}  
	tagEquip equip;  
};  

#pragma pack(pop)
