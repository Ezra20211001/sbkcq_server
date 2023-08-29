
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//�������ó�����ؽṹ

#pragma once
#include "../../common/WorldDefine/pet_define.h"
#include "../../common/WorldDefine/ItemDefine.h"
#pragma pack(push, 1)

const INT MAX_CALLED_PET_NUM		= 1;	// ����ٻ���������

const INT SPIRIT_RESUME_COUNT		= 10 * TICK_PER_SECOND;	// ������ʧʱ��

const INT CHANGEEXP_RESUME_COUNT	= TICK_PER_SECOND * 60;		// ���ܶȱ仯����
const INT CHANGEEXP_VALUE			= 5;						//ÿ�����ܶȱ仯��ֵ

const INT HAPPY_RESUME_COUNT		= 20 * TICK_PER_SECOND ;//����仯����

const INT SAD_RESUME_COUNT			= 20 * TICK_PER_SECOND;		//���ļ�ʱ



enum e_pet_att
{
	epa_null				=-1,
	epa_begin				= 0,

	epa_quality				= 0,	//Ʒ��	1~5Ʒ���������޵����ʡ��츳�����������츳����	�츳���ܹ������֣����ڶ���������棬�ٽ���������
	epa_aptitude			= 1,	//����	�������޵������ɳ���������ʼǱ��	ȡֵ1~100������ȡ����Ʒ��
	epa_spirit				= 2,	//����	
	epa_talent_count		= 3,	//�츳����	
	epa_potential			= 4,	//Ǳ��	ѧϰ����ʱ���ĸ�ֵ������װ��Ǳ��ֵ	��ʼǱ��=���ʡ�10
	epa_wuxing_energy		= 5,	//������	������ʹ�ü���ʱ�����Դ����ֵ����ʩչ�츳����ʱ���ĸ�ֵ	���ܶ�Ӧ������ֵ�ڳ��＼�ܱ�����д
	epa_mount_num			= 6,	//�������
	epa_addon_begin			= 7,

	epa_spirit_max			= 7,	//�������= 30000*1.2^n
	epa_talent_count_max	= 8,	//�츳�������ֵ	���ڵ�����츳����ʹ�ô���������ÿ�����ã��������ﵽ���ֵʱ������ʹ���츳����	Ʒ�ʰ�=1��Ʒ�ʻ�=2��Ʒ����=3��Ʒ����=4��Ʒ�ʳ�=5 �츳����=�ף�Ʒ�ʡ�3
	epa_bag_grid			= 9,	//���Ҹ���	ʹ����ؼ���ʱ��������������Ʒ������	Ĭ��4��װ���ӳ�2~16
	epa_delivery_consume	=10,	//��ݺ�ʱ	ʹ�ÿ�ݼ���ʱ�����޹�����ʱ������	Ĭ��0��װ���ӳ�-��~0��ms����Ӧ���ܱ�����ʱ�䡱������5�룬��-5000��
	epa_sell_consume		=11,	//������ʱ	ʹ�÷�������ʱ�����޹�����ʱ������	Ĭ��0��װ���ӳ�-��~0��ms����Ӧ���ܱ�����ʱ�䡱
	epa_storage_consume		=12,	//��ź�ʱ	ʹ�ô�ż���ʱ�����޹�����ʱ������	Ĭ��0��װ���ӳ�-��~0��ms����Ӧ���ܱ�����ʱ�䡱
	epa_gather_consume		=13,	//�ɼ���ʱ	ʹ�òɼ�����ʱ�����޹���ʱ������	Ĭ��0��װ���ӳ�-��~0��ms����Ӧ���ܱ�����ʱ�䡱
	epa_train_resume		=14,	//ѵ���ָ�	���޵��Զ�ѵ�����ܵĻָ�ʱ������	Ĭ��0��װ���ӳ�-��~0��ms����Ӧ���ܱ��ָ�ʱ�䡱
	epa_spirit_rate			=15,	//��������	(0-1 0-10000)ʹ�ü���ʱ�������������ű�	Ĭ��100%��װ���ӳ�-100%~0%����Ӧ���ܱ�energy_cost
	epa_exp_rate			=16,	//����ӳ�	(0-1 0-10000)��þ���ʱ�����ű�	Ĭ��100%��װ���ӳ�0%~400%
	epa_pick_up_resume		=17,	//ʰȡ�ָ�	��������ʰȡ�Ļָ�ʱ��	Ĭ��0��װ���ӳ�-20~-1
	epa_medicine_saving		=18,	//��ҩ��ʡ	(0-1 0-10000)����ÿ��ιҩʱ���ܲ����ĸ�ҩƷ	Ĭ��0%��װ���ӳ�1%~5%
	epa_strength_effect		=19,	//ǿ��Ч��	(0-1 0-10000)����ǿ���༼�ܵ�Ч��	Ĭ��100%��װ���ӳ�0%~400%
	epa_wuxing_consume		=20,	//����������	(0-1 0-10000)��ʹ���츳����ʱ�����͸ü��ܶ�������������	Ĭ��100%��װ���ӳ�-50%~0%����Ӧ���ܱ����������ġ�
	epa_mount_speed			=21,	//����ٶ�	(0-1 0-10000)���ޱ�����ʱ���ƶ��ٶ�	Ĭ�ϰ�30%����40%����50%����60%����70% װ���ӳ�0%~100%	�ܽ�Ӱ��
	epa_mount_num_max		=22,	//�������
	epa_happy_value			=23,	//���Ķ� 
	epa_color				=24,	//��ɫ
	epa_strength			=25,	//���ӽ�ɫ����
	epa_agility				=26,	//���ӽ�ɫ����
	epa_innerForce			=27,	//���ӽ�ɫ����
	epa_att_point			=28,	//���Ե�

	epa_addon_end			=29,

	epa_end					=29,
};

const INT EPA_NUM		= epa_end - epa_begin;


#define IS_EPA(n)		( (n) >= epa_begin && (n) < epa_end )
#define IS_EPA_ADDON(n)	( (n) >= epa_addon_begin && (n) < epa_addon_end )

#define EPATOEPAAO(n)	( INT((n) - epa_addon_begin) )

#define PET_RANDOM_SKILL_NUM	5
#define PET_RANDOM_Specialty	5

//! ��������Ĭ��ֵ
struct s_pet_def_min_max
{
	INT		n_def;
	INT		n_min;
	INT		n_max;
};


//! ������괴������
struct s_db_pet_soul_create
{
	TCHAR	sz_name_[X_SHORT_NAME];	// ��������
	INT		n_quality_;				// Ʒ��
	INT		n_aptitude_;			// ����
	INT		n_potential_;			// ��ǰǱ�� 
	INT		n_spirte_;				// ��ǰ����
//	BOOL	bMountable;				// �ܷ����

	DWORD	dw_proto_id;			// ԭ��ID
	DWORD	dw_master_id;			// ����ID
	s_db_pet_soul_create()	{ZeroMemory(this, sizeof(*this));}
};


//! �����������
struct s_db_pet_att
{
	DWORD	dw_pet_id_;				// ����ID
	TCHAR	sz_name_[X_SHORT_NAME];	// ��������
	DWORD	dw_proto_id_;			// ԭ��ID
	DWORD	dw_master_id_;			// ����ID

	INT		n_quality_;				// Ʒ��
	INT		n_aptitude_;			// ����
	INT		n_potential_;			// ��ǰǱ�� 
	INT		n_spirit_;				// ��ǰ����
	INT		n_wuxing_energy_;		// ������
	INT		n_talent_count_;		// �츳����
	BYTE	by_pet_state_;				// ����״̬

	INT		n_exp_cur_;				// ��ǰ����
	INT		n_step_;				// ��
	INT		n_grade_;				// ��
	INT		n_rename_count_;		// ��������
	BOOL	b_locked_;				// �Ƿ�����
	INT		n_happy_value_;			// ���Ķ�
	INT		n_color;				// ��ɫ
	INT		n_strength;				// ���ӽ�ɫ����
	INT		n_agility;				// ���ӽ�ɫ����
	INT		n_innerForce;			// ���ӽ�ɫ����
	INT		n_att_point;			// ���Ե�
	DWORD	dw_time_type;			// ����ʱ������
	DWORD	dw_mode_type;			// ����ģʽ����
	DWORD	dw_xiulian_time;		// ����ʱ��

	s_db_pet_att()	{ZeroMemory(this, sizeof(*this));}
};

//! ���＼������
struct s_db_pet_skill
{
	DWORD	dw_data_id;				// ԭ��id
	INT		n_para1_;				// ��ȴ��ʱ
	INT		n_para2_;				// ʹ�ü�ʱ
	s_db_pet_skill()	{ZeroMemory(this, sizeof(*this));}
};

//! �����������
struct s_db_pet
{
	s_db_pet_att	pet_att;			// ��������
	INT				n_pet_skill_num;	// ���＼��
	INT				n_pet_equip_num;	// ����װ��
	BYTE			by_data[1];		// tagDBPetSkill and tagItem
	s_db_pet()	{ZeroMemory(this, sizeof(*this));}
	INT	get_size()
	{
		if (0 == n_pet_skill_num && 0 == n_pet_equip_num)
			return sizeof(*this);
		else
			return sizeof(*this) - 1 + sizeof(s_db_pet_skill) * n_pet_skill_num + sizeof(tagItem) * n_pet_equip_num;
	}
};

//! ����������ܱ�
struct s_pet_skill_list
{
	DWORD	dw_id;
	
	//��ͨ����
	std::vector<DWORD>	vec_normal;
	//buff����
	std::vector<DWORD>	vec_buff;
	//�س�(Ҳ�Ǽ���)
	std::vector<DWORD>	vec_specialty;
	//��������
	std::vector<DWORD>	vec_Action;
};


//! ����PetSoul
struct NET_DB2C_create_pet_soul : public tag_net_message
{ 
	NET_DB2C_create_pet_soul ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_create_pet_soul" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	s_db_pet_soul_create create_data;  
};  

struct NET_DB2S_create_pet_soul : public tag_net_message 
{   
	NET_DB2S_create_pet_soul ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_create_pet_soul" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_error_code; 
	s_db_pet pet_data_load;   
};  

//! ����Pet
struct NET_DB2C_load_pet : public tag_net_message 
{  
	NET_DB2C_load_pet ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_load_pet" ) ; 
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_master_id;  
};  

struct NET_DB2S_load_pet : public tag_net_message 
{  
	NET_DB2S_load_pet ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_pet" ) ; 
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_master_id; 
	INT n_pet_soul_num; 
	BYTE by_data[1];  
};  


//! ����PetSoul
struct NET_DB2C_update_pet_soul : public tag_net_message 
{   
	NET_DB2C_update_pet_soul ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_update_pet_soul" ) ;   
		dw_size = sizeof ( * this ) ;   
	}   
	INT n_pet_soul_num; 
	s_db_pet_att pet_att;   
};  


//! ɾ��PetSoul
struct NET_DB2C_delete_pet_soul : public tag_net_message 
{  
	NET_DB2C_delete_pet_soul ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_pet_soul" ) ;   
		dw_size = sizeof ( * this ) ; 
	}  
	INT n_pet_soul_num;  
	DWORD dw_pet_id[1];  
};  


//! ����װ�����ɾ��
struct NET_DB2C_pet_equip : public tag_net_message 
{  
	NET_DB2C_pet_equip ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_pet_equip" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	tagItem item;
	bool b_insert;    
};  



//! ������＼��
struct NET_DB2C_insert_pet_skill : public tag_net_message 
{  
	NET_DB2C_insert_pet_skill ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_insert_pet_skill" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_pet_id_;   
	s_db_pet_skill pet_skill_;    
};  

//! ɾ�����＼��
struct NET_DB2C_delete_pet_skill : public tag_net_message 
{   
	NET_DB2C_delete_pet_skill ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_pet_skill" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_pet_id_;  
	DWORD dw_pet_skill_type_id;  
};  

// ����sns��Ϣ
struct NET_DB2C_load_pet_sns : public tag_net_message
{
	NET_DB2C_load_pet_sns ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_pet_sns" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
};


struct NET_DB2S_load_pet_sns : public tag_net_message
{
	NET_DB2S_load_pet_sns ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_pet_sns" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_error_code;   
	INT32 n_count; 
	tagPetSNSInfo pet_sns_info[1];
};

// ����sns��Ϣ
struct NET_DB2C_insert_pet_sns : public tag_net_message
{
	NET_DB2C_insert_pet_sns ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_insert_pet_sns" ) ;  
		dw_size = sizeof ( * this ) ;  
	}
	tagPetSNSInfo pet_sns_info;
};

// ɾ��sns��Ϣ
struct NET_DB2C_delete_pet_sns : public tag_net_message
{
	NET_DB2C_delete_pet_sns ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_pet_sns" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD	dw_pet_id;
};
#pragma pack(pop)