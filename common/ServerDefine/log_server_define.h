
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//��������¼log�õ������������ö��

#pragma once

#pragma pack(push, 1)
//-----------------------------------------------------------------------------
// log��������Ϣö�� -- һ����������ò�Ҫ�޸�(1.���ݿ�������Ӧ��¼��2.�ű�������д��)
//-----------------------------------------------------------------------------
enum e_log_cmd_id
{
	elcid_null					= 0,	// ��

	// �̵����
	elcid_shop_buy_item			= 1,	// ����Ʒ(��װ��)
	elcid_shop_buy_equip		= 2,	// ��װ��
	elcid_shop_sell				= 3,	// ����Ʒ&װ��
	
	// ��������
	elcid_skill					= 5,	// ʹ�ü���
	// PK�������
	elcid_open_safe_guard		= 11,	// ����PK����

	// �����ͷ�
	elcid_dead_penalty			= 12,	// PK�ͷ�

	// �ٱ������
	elcid_baibao_load_from_db	= 20,	// ��item_baibao���ж�ȡ����Ʒ
	elcid_baibao_bill_yuanbao	= 21,	// Ԫ��ֱ��

	// �������
	elcid_bag_pos_overlap		= 30,	// ��ʼ����ɫ����ʱ��������Ʒλ���ص�

	// ϴ��
	elcid_clear_att				= 40,	// ϴ���Ե�
	elcid_clear_talent			= 41,	// ϴ���ʵ�


	// ��ɫ�ֿ����
	elcid_ware_pos_overlap		= 50,	// ��ʼ����ɫ�ֿ�ʱ��������Ʒλ���ص�
	elcid_ware_save_silver		= 51,	// ��Ǯ
	//elcid_ware_save_yuanbao		= 52,	// ��Ԫ��
	elcid_ware_get_silver		= 53,	// ȡǮ
	elcid_ware_get_yuanbao		= 54,	// ȡԪ��

	// �̳�
	elcid_mall_buy_item			= 60,	// �����̳���Ʒ
	elcid_mall_buy_pack			= 61,	// �����̳���Ʒ��
	elcid_mall_free_item		= 62,	// ��ȡ�̳������Ʒ
	elcid_mall_buy_item_add		= 63,	// �����̳���Ʒʱ����
	elcid_mall_buy_pack_add		= 64,	// �����̳���Ʒ��ʱ����
	elcid_mall_present_item		= 65,	// �����̳���Ʒ
	elcid_mall_present_pack		= 66,	// �����̳���Ʒ��
	elcid_mall_present_item_add	= 67,	// �����̳���Ʒʱ����
	elcid_mall_present_pack_add	= 68,	// �����̳���Ʒ��ʱ����

	// Ԫ������
	elcid_trade_save_yuanbao	= 70,	// �����˻���Ԫ��
	elcid_trade_save_silver		= 71,	// �����˻����Ǯ
	elcid_trade_depossit_yuanbao= 72,	// �ӽ����˻�ȡ��Ԫ��
	elcid_trade_deposit_silver	= 73,	// �ӽ����˻�ȡ����Ǯ
	elcid_trade_tax				= 74,	// �ύ����ʱ�۳�������
	elcid_trade_buy_lovevalue	= 75,	// ������ֵ	
	// �̳� - ��
	elcid_mall_exchange_item	= 80,	// �һ��̳���Ʒ
	elcid_mall_exchange_pack	= 81,	// �һ��̳���Ʒ��
	elcid_mall_exchange_item_add= 82,	// �һ��̳���Ʒʱ����
	elcid_mall_exchange_pack_add= 83,	// �һ��̳���Ʒ��ʱ����

	// �Ź�
	elcid_group_purchase_faild		= 90,	// �Ź�ʧ�ܷ������� gx modify ������ 2013.7.3
	elcid_group_purchase_buy_item	= 91,	// �Ź������̳���Ʒ
	elcid_group_purchase_buy_item_add= 92,	// �Ź��̳���Ʒ����

	// �������
	elcid_quest_loot			= 100,	// �������
	elcid_quest_complete		= 101,	// �������
	elcid_quest_accept			= 102,	// ��ȡ����
	elcid_quest_discard			= 103,	// ��������
	elcid_quest_rewards			= 104,  // ������
	elcid_buy_circle			= 105,  // �����������

	// װ��ǿ�����
	elcid_compose_posy			= 150,	// ����
	elcid_compose_engrave		= 151,	// ��
	elcid_compose_enchase		= 152,	// ��Ƕ
	elcid_compose_prictice		= 153,	// ��������
	elcid_compose_reatt			= 154,	// ��������
	elcid_compose_produce		= 155,	// �ϳ�
	elcid_compose_quench		= 156,	// ���
	elcid_compose_decompose		= 157,	// �㻯,װ���ֽ�
	elcid_compose_chisel		= 158,	// ����
	elcid_compose_fusion		= 159,	// �����ں�
	elcid_compose_xili			= 130,	// װ��ϴ��
	elcid_compose_tiqu			= 131,	// ��ȡ���

	// ��Ҽ佻��
	elcid_exchange_verify		= 160,	// ����ȷ��
	
	// gp�̳�
	elcid_exchange_lottey		= 170,	// ��Ʊ��
	elcid_exchange_treasure		= 171,	//���������ʵı���Ŀ������� gx add 2013.12.11

	// ԭ�ظ���
	elcid_revive_locus			= 180,
	elcid_revive_perfection		= 181,
	elcid_revive_return_city	= 182,

	// ��̯
	elcid_stall_besold			= 190,	// ��̯����
	elcid_stall_buy				= 191,	// ��̯λ�Ϲ���

	// ������
	elcid_dak					= 200,

	// ��Ʒ
	elcid_item_use				= 300,	// ��Ʒʹ��
	elcid_item_move				= 301,	// ͬһ�������ƶ�
	elcid_item_move_to_other	= 302,	// ��ͬ�������ƶ�

	elcid_item_at_term			= 310,	// ��ʱ����Ʒ������ɾ��

	// װ��
	elcid_equip_identify		= 350,	// װ������
	elcid_equip_reget			= 351,	// װ���ָ�
	elcid_equip_newness_lost	= 352,	// �;ö�Ϊ0����

	// ����
	elcid_first_online_item		= 380,	// ���ַ���

	// ��ҳԴӱ����ӵ���Ʒ
	elcid_role_discard_item		= 401,

	// ���ʰȡ��Ʒ
	elcid_pickup_item			= 402,
	elcid_pickup_money			= 403,

	// ������������
	elcid_send_gift				= 410,

	// ��Ʒ��
	elcid_gift_bag				= 420,

	// ְ��NPC���
	elcid_bag_extend			= 450,	// ���䱳��
	elcid_ware_extend			= 451,	// ��ɫ�ֿ�����
	elcid_cure_injure			= 452,	// npc��������
	
	// ��ͨ����
	elcid_loot					= 500,	// ��ͨ����

	// �������
	elcid_guild_create			= 600,	// ��������
	elcid_guild_upgrade			= 601,	// ������ʩ����
	elcid_guild_spread_affair	= 602,	// ��������
	elcid_guild_daily_cost		= 603,	// �ճ�����
	elcid_guild_skill_research	= 604,	// ���ɼ�������
	elcid_guild_skill_learn		= 605,	// ѧϰ���ɼ���
	elcid_guild_commerce		= 606,	// ����
	elcid_guild_declarewar		= 607,	// �����ս
	elcid_guild_trans			= 608,	// ����ͼ����
	elcid_guild_win_war			= 609,	// ���ս����
	elcid_guild_inc_fund		= 610,	// ����ʽ����
	elcid_guild_materimal		= 611,  // ���ϻ���

	// �������
	elcid_chat_world_channel		= 700,	//������Ƶ������
	elcid_show_equip_world_channel	= 701,	//������Ƶ��չʾװ��
	elcid_show_item_world_channel	= 702,	//������Ƶ��չʾ��Ʒ
	elcid_talk_decree				= 703,	//����ʹ��IM����

	// �������
	elcid_pet_item_create_pet		= 800,	// ���ɳ���
	elcid_pet_item_feed_pet			= 801,	// ����ιʳ
	elcid_pet_item_pet_learnskill	= 802,	// ����ѧϰ����
	elcid_pet_item_pet_revive		= 803,	// ���︴��
	elcid_pet_item_pet_equip		= 804,	// ����װ��
	elcid_role_pour_exp_pet			= 805,	// ��ע����
	elcid_pet_item_pet_enhance		= 806,	// ����װ��
	elcid_pet_item_pet_lock			= 807,	// ��������
	elcid_pet_item_pet_unlock		= 808,	// �������
	elcid_pet_item_pet_food			= 809,	// ����ʳ��
	elcid_pet_item_pet_spe			= 810,	// �����������
	elcid_pet_color					= 811,	// ����Ⱦɫ
	elcid_pet_item_fusion			= 812,	// �����ں�	
	elcid_pet_size_change			= 813,  // ����������
	elcid_pet_xiulian_size_change	= 814,  // �������������
	elcid_pet_xiulian				= 815,  // �������

	// �������
	elcid_act_treasure				= 900,	// ���������䱦���

	//�̶�����
	elcid_wu_se_shi					= 1000, // �̶��ɾ����ɫʯ
	elcid_pvp						= 1001, // pvp�̶��

	// VIP̯λ���
	elcid_vip_stall_rent			= 1100,	// VIP̯λ����

	// vip����
	elcid_vip_netbar				= 1200,	// vip����
	
	elcid_npc_repair				= 1201, //װ��ά��
	elcid_npc_hole					= 1202, //װ�����
	elcid_npc_unbeset				= 1203, //װ����Ƕ
	elcid_npc_shengxin				= 1204,	//װ������
	elcid_guild_delate				= 1205,	//��ᵯ��
	elcid_npc_fusion				= 1206,	//�����ں�
	elcid_npc_inlay					= 1207,	//��Ƕ
	elcid_npc_daomo					= 1208, //��ĥ

	elcid_npc_mail					= 1212, //�ʼ�

	elcid_gdquest_putout			= 1300, //������������
	elcid_xsquest_accept			= 1301, //��ȡ��������

	elcid_upgrade_ride				= 1302, //ǿ������
	elcid_remove_ride_inlay			= 1303,	//�����ĥ
	elcid_riad_inlay				= 1304, //������Ƕ

	elcid_call_in_master			= 1305, //����ʦ��

	//ѧϰ����
	elcid_learn_skill				= 1400, //ѧϰ����

	elcid_leave_hang				= 1401,	// ���߹һ�

	// PK�ͷ�
	elcid_pk_penalty				= 1501, //PK�ͷ�

	// �������߽���
	elcid_new_role_gift				= 1502,	// �������߽���

	// ������Ʒ
	elcid_paimai_item				= 1503,	// ������Ʒ

	// Ǯׯ
	elcid_bank						= 1504,	// Ǯׯ����

	// �ű�
	elcid_script					= 1505,	// �ű�

	// ����
	elcid_fishing					=	1506, // ����

	// ����
	elcid_instance					=	1507,	// ����

	// Ԫ���һ�
	elcid_bank_exchange				=	1508,	// Ԫ���һ�

	// �һ�
	elcid_hang						=	1509,	// �һ�

	// װ������
	elcid_equip_destroy				=	1510,	// װ������

	// ����Ԫ��
	elcid_compensate_yuanbao		=	1511,	// �⳥Ԫ��

	// ���Ԫ��
	elcid_pack_yuanbao				=	1512,	// ���Ԫ��

	// 1v1������
	elcid_1v1						=	1513,	// 1v1������

	// Լս������
	elcid_reservation				=	1514,	// Լս������

	// ������
	elcid_changename				=	1600,	// ��ɫ����
	

	// ��������
	elci_leave_pracitce				=	1515,	// ��������

	// ��Ծ��
	elci_active						=	1516,	// ��Ծ��
	
	// �������
	elci_kick_role_vercation		=	1600,	// ��֤������
	elci_kick_role_move_fast		=	1601,	// �ƶ�̫��

	// ������������
	elci_process					=	1602,	// ���ø�������

	// ����Ȩֵ����
	elci_inst_limit					=	1603,	// ���ø���Ȩֵ

	elci_kick_role_move_fast1		=	1604,	// �ƶ�̫��
	// ǩ��
	elci_sign						=	1605,	// ǩ��

	// ������
	elci_buy_lingqi					=	1606,
	
	// ����
	elci_huenlian					=	1607,

	elci_kick_role_move_fast2		=	1608,	// �ƶ�̫��

	elci_KillBadage					=	1701,	//ͨ��ĳ��

	

	// �ű��ӵ�Ԫ��
	elcid_script_add_yuanbao_1		=	3000,	// ���BOSSԪ������

	// ��������ڴ˴�֮�ϼ�
	
	// GM����
	elcid_gm_clear_bag				= 1000000,	// ������
	elcid_gm_create_item			= 1000001,	// ������Ʒ/װ��/ʱװ
	elcid_gm_get_money				= 1000002,	// ��ý�Ǯ
	elcid_gm_get_yuanbao			= 1000003,	// ���Ԫ��
	elcid_gm_get_exvolume			= 1000004,	// �������
	elcid_gm_getfund				= 1000005,	// ��ð����ʽ�
	elcid_gm_get_material			= 1000006,	// ��ð����ʲ�
	elcid_gm_get_contribute			= 1000007,	// ��ð��ɸ��˹���
};


struct s_log_silver				// ��Ǯ�仯
{
	DWORD	dw_account_id;
	DWORD	dw_role_id;
	DWORD	dw_cmd_id;
	DWORD	dw_role_id_rel;
	INT64	n64_silver;			// +����ã�-��ʧȥ
	INT64	n64_total_silver;	// ��Ӧ����������
	INT8	n8_log_con_type;	// �������ֿ�
};

struct s_log_yuanbao			// Ԫ���仯
{
	DWORD	dw_account_id;
	DWORD	dw_role_id;
	DWORD	dw_cmd_id;
	DWORD	dw_role_id_rel;
	INT		n_yuanbao;			// +����ã�-��ʧȥ
	INT		n_total_yuanbao;	// ��Ӧ����������
	INT8	n8_log_con_type;	// �������ٱ���
};

struct s_log_ex_volume			// ����仯
{
	DWORD	dw_account_id;
	DWORD	dw_role_id;
	DWORD	dw_cmd_id;
	INT		n_ex_volume;		// +����ã�-��ʧȥ
	INT		n_total_ex_volume;	// ��Ӧ����������
};

struct s_log_exploits	// ս���仯
{
	DWORD dw_account_id;
	DWORD dw_role_id;
	DWORD dw_cmd_id;
	INT32 n_exploits;
	INT32 n_total_exploits;
};

struct s_log_time_stat			// ������Ҷ�ʱͳ��
{
	DWORD	dw_account_id;
	DWORD	dw_role_id;
	INT64	n64_bag_silver;
	INT64	n64_ware_silver;
	INT		n_bag_yuanbao;
	INT		n_baibao_yuanbao;
	INT		n_ex_volume;
};

// ��Ҫ��log��Ʒ�Ľṹ
struct s_need_log_item
{
	DWORD	dw_data_id;
	BYTE	by_quality;
};


struct s_log_item				// ��Ʒlog�ṹ
{
	DWORD		dw_role_id;
	DWORD		dw_data_id;

	INT64		n64_serial1;
	INT64		n64_serial2;
	INT8		n8_con_type1;
	INT8		n8_con_type2;
	INT16		n16_res_num1;
	INT16		n16_res_num2;

	INT16		n16_opt_num;		// �仯����(+����ʾ��ã�-����ʾʧȥ)
	DWORD		dw_cmd_id;
	DWORD		dw_role_id_rel;
};

struct s_log_mall_sell			// �̳ǳ�����Ʒlog�ṹ
{
	INT64		n64_serial;
	DWORD		dw_data_id;
	DWORD		dw_role_id;		// ������
	DWORD		dw_to_role_id;		// �����Ʒ��
	DWORD		dw_first_gain_time;
	DWORD		dw_exist_item;
	INT			n_max_use_times;
	INT			n_cost_yuanbao;
	INT			n_cost_ex_volume;
	DWORD		dw_cmd_id;
	INT16		n16_num_sell;
};

struct s_log_mall_sell_pack		// �̳ǳ�����Ʒ��log�ṹ
{
	DWORD		dw_pack_id;
	DWORD		dw_buy_role_id;
	DWORD		dw_to_role_id;
	INT			n_cost_yuanbao;
};

struct s_log_item_times			// ��Ʒʹ�ô���log�ṹ
{
	DWORD		dw_role_id;
	DWORD		dw_cmd_id;

	INT64		n64_serial;
	DWORD		dw_data_id;
	INT			n_used_times;
	INT			n_max_use_times;
	INT8		n8_con_type;
};

struct tagLogFund
{
	DWORD		dw_guild_id;
	DWORD		dw_account_id;
	DWORD		dw_role_id;
	DWORD		dw_cmd_id;

	INT			n_fund;
	INT			n_total_funk;
};

struct tagLogMaterial
{
	DWORD		dw_guild_id;
	DWORD		dw_account_id;
	DWORD		dw_role_id;
	DWORD		dw_cmd_id;

	INT			n_material;
	INT			n_total_material;
};

struct tagLogReputation
{
	DWORD		dw_guild_id;
	DWORD		dw_account_id;
	DWORD		dw_role_id;
	DWORD		dw_cmd_id;

	INT			n_reputation;
	INT			n_total_reputation;
};

struct tagLogGMCmd
{
	DWORD		dw_role_id;
	TCHAR		sz_gm_cmd[LONG_STRING];
	DWORD		dw_error_code;
};

struct tagLogBank
{
	DWORD dw_sell_id;
	DWORD dw_buy_id;
	DWORD dw_bidup_id;
	BYTE  by_type;
	DWORD dw_bidup;
	DWORD dw_chaw;
	DWORD dw_sell;
};

struct tagLogPaimai
{
	INT64	n64_serial;
	DWORD	dw_sell_id;
	DWORD	dw_buy_id;
	DWORD	dw_bidup_id;
	DWORD	dw_bidup;
	DWORD	dw_chaw;
};

struct tagLogLeavePractice
{
	DWORD	dw_role_id;
	DWORD	dw_drop_love;
	DWORD	dw_cur_love;
};

struct tagLogSerialReward
{
	DWORD	dw_account_id;
	INT		n_type;
	CHAR	sz_serial[X_SHORT_NAME];
};

struct tagLogReward
{
	DWORD dw_account_id;
	DWORD dw_role_id;
	DWORD dw_type;
};

struct tagKickRole
{
	DWORD dw_account_id;
	DWORD dw_role_id;
	DWORD dw_cmd_id;
};

struct tagLotteryLog
{
	DWORD dw_account_id;
	DWORD dw_role_id;
	DWORD dw_item_id;
	DWORD dw_type;
	DWORD dw_index;
};
//! ��Ǯ�仯
struct NET_DB2C_log_silver : public tag_net_message 
{  
	NET_DB2C_log_silver ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_log_silver" ) ;
		dw_size = sizeof ( * this ) ;    
	}  
	s_log_silver s_log_silver_;  
};  

//! Ԫ���仯
struct NET_DB2C_log_yuanbao : public tag_net_message 
{  
	NET_DB2C_log_yuanbao ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_log_yuanbao" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	s_log_yuanbao s_log_yuanbao_; 
};  

//! ����仯
struct NET_DB2C_log_exvolume : public tag_net_message 
{ 
	NET_DB2C_log_exvolume ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_log_exvolume" ) ;  
		dw_size = sizeof ( * this ) ;     
	}   
	s_log_ex_volume s_log_ex_volume_;   
};  

//! ս���仯
struct NET_DB2C_log_exploits : public tag_net_message
{
	NET_DB2C_log_exploits()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_exploits");
		dw_size = sizeof(*this);
	}
	s_log_exploits s_log_exploits;
};

//! ��ʱͳ��
struct NET_DB2C_log_time_stat : public tag_net_message 
{  
	NET_DB2C_log_time_stat ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_log_time_stat" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	s_log_time_stat s_log_times_stat_; 
};  


//! ��Ʒlog
struct NET_DB2C_log_item : public tag_net_message
{ 
	NET_DB2C_log_item ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_log_item" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	s_log_item s_log_item_;    
};  

//! ��Ʒlog
struct NET_DB2C_log_item_times : public tag_net_message 
{  
	NET_DB2C_log_item_times ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_log_item_times" ) ;  
		dw_size = sizeof ( * this ) ;  
	}
	s_log_item_times s_log_item_times_;  
};  



//! �̳ǳ�����Ʒlog
struct NET_DB2C_log_mall_sell : public tag_net_message 
{   
	NET_DB2C_log_mall_sell ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_log_mall_sell" ) ;  
		dw_size = sizeof ( * this ) ;  
	}  
	s_log_mall_sell s_log_mall_sell_;   
};  


//! �̳ǳ�����Ʒ��log
struct NET_DB2C_log_mall_sell_pack : public tag_net_message
{  
	NET_DB2C_log_mall_sell_pack ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_log_mall_sell_pack" ) ;   
		dw_size = sizeof ( * this ) ;
	}  
	s_log_mall_sell_pack s_log_mall_sell_pack_; 
};  


//! ����LOG��¼
struct NET_DB2C_log_fund : public tag_net_message
{  
	NET_DB2C_log_fund ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_log_fund" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	tagLogFund s_log_fund_; 
};  

struct NET_DB2C_log_material : public tag_net_message 
{  
	NET_DB2C_log_material ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_log_material" ) ; 
		dw_size = sizeof ( * this ) ;
	}   
	tagLogMaterial s_log_material_;  
};  

struct NET_DB2C_log_reputation : public tag_net_message
{   
	NET_DB2C_log_reputation ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_log_reputation" ) ;   
		dw_size = sizeof ( * this ) ; 
	}  
	tagLogReputation s_log_reputation_;    
};  

//! ����LOG��¼
struct NET_DB2C_log_gm_cmd : public tag_net_message 
{ 
	NET_DB2C_log_gm_cmd ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_log_gm_cmd" ) ;   
		dw_size = sizeof ( * this ) ; 
	} 
	tagLogGMCmd s_log_gm_cmd_;  
};  

// Ǯׯlog
struct NET_DB2C_log_bank : public tag_net_message
{
	NET_DB2C_log_bank()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_bank");
		dw_size = sizeof(*this);
	}
	tagLogBank s_log_bank;
};

// ����log
struct NET_DB2C_log_paimai : public tag_net_message
{
	NET_DB2C_log_paimai()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_paimai");
		dw_size = sizeof(*this);
	}
	tagLogPaimai s_log_paimai;
};

// ��������log
struct NET_DB2C_log_leave_practice : public tag_net_message
{
	NET_DB2C_log_leave_practice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_leave_practice");
		dw_size = sizeof(*this);
	}
	tagLogLeavePractice s_log_leave_pracitce;
};

// ���к����LOG
struct NET_DB2C_log_serial_reward : public tag_net_message
{
	NET_DB2C_log_serial_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_serial_reward");
		dw_size = sizeof(*this);
	}
	tagLogSerialReward s_log_serial_reward;
};

// ���log
struct NET_DB2C_log_reward : public tag_net_message
{
	NET_DB2C_log_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_reward");
		dw_size = sizeof(*this);
	}

	tagLogReward s_log_reward;
};
// ����log
struct NET_DB2C_log_kick : public tag_net_message
{
	NET_DB2C_log_kick()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_kick");
		dw_size = sizeof(*this);
	}
	tagKickRole s_log_kick;
};

// ��Ʊlog
struct NET_DB2C_log_lottery : public tag_net_message
{
	NET_DB2C_log_lottery()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_log_lottery");
		dw_size = sizeof(*this);
	}
	tagLotteryLog s_log;
};

// ������������
struct NET_DB2C_update_online_num : public tag_net_message
{
	NET_DB2C_update_online_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_online_num");
		dw_size = sizeof(*this);
	}
	CHAR szName[X_SHORT_NAME];
	INT	nNum;
};
//-----------------------------------------------------------------------------
#pragma pack(pop)
