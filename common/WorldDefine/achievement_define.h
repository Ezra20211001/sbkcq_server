/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/



#ifndef _ACHIEVEMENT_H_
#define _ACHIEVEMENT_H_


#pragma pack(push, 1)
//-----------------------------------------------------------------------------
// �����¼�
//-----------------------------------------------------------------------------
enum e_achievement_event
{	
	ete_null						=-1,
	ete_begin						=0 ,	

	ete_kill_monster				=0 ,	// ��ɱ�ض�����
	//m_dwPara1		����id		
	//m_dwPara2		����			
	ete_kill_role					=1 ,	// ��ɱ��ɫ
	//m_dwPara1			
	//m_dwPara2		����	
	ete_quest_complete				=2 ,	// �������
	//m_dwPara1		����id		
	//m_dwPara2		����	
	ete_role_die					=3 ,	// ��ɫ����
	//m_dwPara1				
	//m_dwPara2		����	
	ete_role_skilled_by_role		=4 ,	// ��ɫ��������ɫ��ɱ
	//m_dwPara1			
	//m_dwPara2		����	
	ete_role_level					=5,		// ��ɫ�ﵽ����
	//m_dwPara1			
	//m_dwPara2		����	
	ete_composite_equip_success		=6 ,	// �ϳ�װ���ɹ�
	//m_dwPara1		Ʒ��		
	//m_dwPara2		����
	ete_use_item					=7,		// ��ɫʹ�õ���
	//m_dwPara1		����id		
	//m_dwPara2		����
	ete_use_skill					=8,		// ��ɫʹ�ü���
	//m_dwPara1		����id		
	//m_dwPara2		����
	ete_composite_achievement		=9,		// ��ɳɾ�
	//m_dwPara1		�ɾ�id				
	//m_dwPara2		
	ete_decomposite_three_seven		=10,	// ��ֳ�3��7
	//m_dwPara1						
	//m_dwPara2		����
	eta_decomposite_feil			=11,	// ��ֳ�3������
	//m_dwPara1						
	//m_dwPara2		����
	eta_decomposite_equip			=12,	// ���װ��
	//m_dwPara1						
	//m_dwPara2		����
	eta_skill_level_up				=13,	// ��������
	//m_dwPara1		����id				
	//m_dwPara2		�ȼ�
	eta_fish_sucess					=14,	// ����ɹ�
	//m_dwPara1						
	//m_dwPara2		����
	eta_fish_field					=15,	// ����ʧ��
	//m_dwPara1						
	//m_dwPara2		����
	eta_roborn						=16,	// ����
	//m_dwPara1		����	0 ����ԭ�� 1 ��ͨԭ�� 2 �����س� 3 ��ͨ�س�	4 ��ȴ����				
	//m_dwPara2		����
	eta_add_friend					=17,	// ��Ӻ���
	//m_dwPara1		
	//m_dwPara2		��������
	eta_send_mail					=18,	// �����ʼ�
	//m_dwPara1		
	//m_dwPara2		����
	eta_receive_mail				=19,	// �յ��ʼ�
	//m_dwPara1		
	//m_dwPara2		����
	eta_use_decree					=20,	// �Ѹ�����
	//m_dwPara1		
	//m_dwPara2		����
	eta_use_world					=21,	// ����Ƶ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_win_sice					=22,	// ���ӻ�ʤ
	//m_dwPara1		
	//m_dwPara2		����
	eta_win_sice_yibai				=23,	// ���ӻ�ʤ 100 ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_combat_miss					=24,	// δ����
	//m_dwPara1		
	//m_dwPara2		����
	eta_combat_dodge				=25,	// ����
	//m_dwPara1		
	//m_dwPara2		����
	eta_combat_crit					=26,	// ����
	//m_dwPara1		
	//m_dwPara2		����
	eta_produce_item				=27,	// ����
	//m_dwPara1		��Ʒid
	//m_dwPara2		����
	eta_bind_equip					=28,	// ��ʯ��װ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_unbind_equip_npc			=29,	// npc��
	//m_dwPara1		
	//m_dwPara2		����
	eta_unbind_equip				=30,	// ���ʯ
	//m_dwPara1		
	//m_dwPara2		����
	eta_baitan_sell					=31,	// ��̯����
	//m_dwPara1		
	//m_dwPara2		����
	eta_exchange					=32,	// ���׳ɹ�
	//m_dwPara1		
	//m_dwPara2		����
	eta_extendbag					=33,	// ���Ӱ���
	//m_dwPara1		0 ���� 1�ֿ�
	//m_dwPara2		���䵽����
	eta_bank_buy_success			=34,	// Ǯׯ����ɹ�
	//m_dwPara1		0 ��Ϸ�� 1 Ԫ��
	//m_dwPara2		����
	eta_bank_sell_success			=35,	// Ǯׯ�����ɹ�
	//m_dwPara1		0 ��Ϸ�� 1 Ԫ��
	//m_dwPara2		����
	eta_paimai_buy_success			=36,	// �����й���ɹ�
	//m_dwPara1		
	//m_dwPara2		����
	eta_paimai_sell_success			=37,	// �����������ɹ�
	//m_dwPara1		
	//m_dwPara2		����
	eta_paimai_sell_fail			=38,	// ����������ʧ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_duel_win					=39,	// �д�ʤ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_duel_lost					=40,	// �д�ʧ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_duel						=41,	// �д�
	//m_dwPara1		
	//m_dwPara2		����
	eta_chisel						=42,	// ���
	//m_dwPara1		
	//m_dwPara2		����
	eta_inlay						=43,	// ��Ƕ
	//m_dwPara1		
	//m_dwPara2		����
	eta_pet_level					=44,	// ��������
	//m_dwPara1		
	//m_dwPara2		�ȼ�
	ete_strengthen_weapon_success_2 =45,	// ǿ��2������
	//m_dwPara1		
	//m_dwPara2		�Ǽ�
	ete_strengthen_weapon_success_3	=46,	// ǿ��3������
	//m_dwPara1		
	//m_dwPara2		�Ǽ�
	ete_strengthen_weapon_success_4 =47,	// ǿ��4������
	//m_dwPara1		
	//m_dwPara2		�Ǽ�
	ete_strengthen_armor_success_2  =48,	// ǿ��2�׷���
	//m_dwPara1		
	//m_dwPara2		�Ǽ�
	ete_strengthen_armor_success_3	=49,	// ǿ��3�׷���
	//m_dwPara1		
	//m_dwPara2		�Ǽ�
	ete_strengthen_armor_success_4  =50,	// ǿ��4�׷���
	//m_dwPara1		
	//m_dwPara2		�Ǽ�
	ete_strengthen_weapon_success_4_fail =51,	// ǿ��4������ʧ��
	//m_dwPara1		
	//m_dwPara2		����
	ete_strengthen_armor_success_4_fail =52,	// ǿ��4�׷���ʧ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_be_kill_monster					=53,	// ������ɱ��
	//m_dwPara1		����id		
	//m_dwPara2		����
	eta_load_baobao_yuanbao				=54,	// ��Ԫ��
	//m_dwPara1				
	//m_dwPara2		����
	ete_strengthen_ride_success			=55,	// ����ǿ��
	//m_dwPara1		
	//m_dwPara2		�Ǽ�
	ete_strengthen_ride_fail			=56,	// ����ǿ��ʧ��
	//m_dwPara1		����Ǽ�
	//m_dwPara2		����
	ete_xiangqian_ride					=57,	// ������Ƕ
	//m_dwPara1		
	//m_dwPara2		����
	ete_xiulian							=58,	// ��������
	//m_dwPara1		
	//m_dwPara2		�ȼ�
	ete_produce_equip_up_quality		=59,	// ʹ�ô�������Ʒ�ʼ�����Ʒ
	//m_dwPara1		��Ʒid
	//m_dwPara2		����
	ete_consolidate_up_pro				=60,	// ʹ��ǿ������������Ʒ
	//m_dwPara1		��Ʒid
	//m_dwPara2		����
	ete_into_area						=61,	// ��������
	//m_dwPara1		����id
	//m_dwPara2		����
	ete_graduates_num					=62,	// ��ʦ�����ﵽ
	//m_dwPara1		
	//m_dwPara2		����
	ete_title_num						=63,	// ��óƺ�
	//m_dwPara1		
	//m_dwPara2		����
	ete_strengthen_armor_success		=64,	// ǿ�����ߵ�
	//m_dwPara1		
	//m_dwPara2		����
	ete_fusion_equip					=65,	// �ں�����
	//m_dwPara1		
	//m_dwPara2		����
	ete_set_bag_password				=66,	// �޸ĳ�������
	//m_dwPara1		
	//m_dwPara2		����
	ete_join_guild						=67,	// ������
	//m_dwPara1		
	//m_dwPara2		����
	ete_reatt_equip						=68,	// ϴװ������
	//m_dwPara1		
	//m_dwPara2		����
	ete_delete_item						=69,	// �ݻ�װ��
	//m_dwPara1		
	//m_dwPara2		����	
	ete_make_master						=70,	// ��ʦ�ɹ�
	//m_dwPara1		
	//m_dwPara2		����	
	ete_make_prentice					=71,	// ��ͽ�ɹ�
	//m_dwPara1		
	//m_dwPara2		����	
	ete_into_prison						=72,	// ������
	//m_dwPara1		
	//m_dwPara2		����	
	ete_kill_red_role					=73,	// ɱ�������
	//m_dwPara1		
	//m_dwPara2		����	
	ete_PKValue							=74,	// ���ֵ�ﵽ
	//m_dwPara1		
	//m_dwPara2		ֵ
	ete_add_item						=75,	// ��õ���
	//m_dwPara1		id
	//m_dwPara2		����
	ete_inlay_repeat					=76,	// ������Ƕ
	//m_dwPara1		
	//m_dwPara2		����
	ete_inlay_level						=77,	// ��Ƕ�߼���ʯ
	//m_dwPara1		��ʯ�������װ���ȼ�	
	//m_dwPara2		����
	eta_use_common						=78,	// ��ͨƵ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_use_secret						=79,	// ����Ƶ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_use_map							=80,	// ����Ƶ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_use_team						=81,	// ����Ƶ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_use_guild						=82,	// ����Ƶ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_incbagsilver					=83,	// ��ý�Ǯ
	//m_dwPara1		
	//m_dwPara2		����(���ܳ���4000G)
	eta_incbagbindsilver				=84,	// ��ð󶨽�Ǯ
	//m_dwPara1		
	//m_dwPara2		����(���ܳ���4000G)
	eta_decbagsilver					=85,	// ʧȥ��Ǯ
	//m_dwPara1		
	//m_dwPara2		����(���ܳ���4000G)
	eta_decbagbindsilver				=86,	// ʧȥ�󶨽�Ǯ
	//m_dwPara1		
	//m_dwPara2		����(���ܳ���4000G)
	eta_increase_contribution			=87,	// ��ðﹱ
	//m_dwPara1		
	//m_dwPara2		����
	eta_decrease_contribution			=88,	// ���Ѱﹱ
	//m_dwPara1		
	//m_dwPara2		����
	eta_loop_rand_quest					=89,	// ��ɻ����
	//m_dwPara1		
	//m_dwPara2		����
	eta_prentice_breakwith_master		=90,	// ͽ������ʦ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_master_fire_prentice			=91,	// ʦ������ͽ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_join_team						=92,	// �������
	//m_dwPara1		
	//m_dwPara2		����
	eta_produce_item_fail				=93,	// ����ʧ��
	//m_dwPara1		
	//m_dwPara2		����
	eta_produce_item_bai				=94,	// ����ٷְٳɹ�
	//m_dwPara1		
	//m_dwPara2		����
	eta_produce_item_crit				=95,	// ���𱩻�
	//m_dwPara1		
	//m_dwPara2		����
	eta_shipin_fumo						=96,	// ��Ʒ��ħ
	//m_dwPara1		
	//m_dwPara2		����
	eta_shipin_fumo_crit				=97,	// ��Ʒ��ħ����
	//m_dwPara1		
	//m_dwPara2		����
	eta_unbeset							=98,	// ��Ƕ
	//m_dwPara1		
	//m_dwPara2		����
	eta_unbind_equip_npc_all			=99,	// npcȫ���
	//m_dwPara1		
	//m_dwPara2		����
	eta_equip_xili						=100,	// ϴ��
	//m_dwPara1		����	 0 ���� 1 ս�� 2 2�Ͻ�� 3 10�Ͻ��
	//m_dwPara2		����
	eta_equip_reatt						=101,	// ��������
	//m_dwPara1		����	 0  1  2  
	//m_dwPara2		����
	eta_equip_qianghua_success			=102,	// ǿ���ɹ�
	//m_dwPara1		 
	//m_dwPara2		����
	eta_equip_qianghua_arm_fail			=103,	// ǿ������ʧ��
	//m_dwPara1		 
	//m_dwPara2		����
	eta_equip_xiuli						=104,	// ����װ��
	//m_dwPara1		 
	//m_dwPara2		����
	ete_strengthen_ride					=105,	// ����ǿ��
	//m_dwPara1		
	//m_dwPara2		����
	ete_xiangqian_ride_item				=106,	// ������Ƕĳ����
	//m_dwPara1		����id
	//m_dwPara2		����
	ete_pet_paiqian						=107,	// ��ǲ����
	//m_dwPara1		
	//m_dwPara2		����
	ete_pet_ranse						=108,	// ����Ⱦɫ
	//m_dwPara1		
	//m_dwPara2		����
	ete_pet_have_quality				=109,	// ӵ�г���Ʒ��
	//m_dwPara1		
	//m_dwPara2		Ʒ��
	eta_pet_to_level					=110,	// ���������ȼ����ٴ�
	//m_dwPara1		�ȼ�
	//m_dwPara2		����
	eta_guild_plant_tou					=111,	// ͵��
	//m_dwPara1		
	//m_dwPara2		����
	eta_stall_start						=112,	// ��̯
	//m_dwPara1		
	//m_dwPara2		����
	eta_stall_buy						=113,	// ��̯����
	//m_dwPara1		
	//m_dwPara2		����
	eta_paimai_jingpai					=114,	// ��������
	//m_dwPara1		
	//m_dwPara2		����
	eta_bank_jingpai					=115,	// Ǯׯ����
	//m_dwPara1		
	//m_dwPara2		����
	eta_guild_cailiao					=116,	// ��������
	//m_dwPara1		
	//m_dwPara2		����
	eta_guild_zijin						=117,	// �����Ǯ
	//m_dwPara1		
	//m_dwPara2		����
	eta_equip_kaiguang					=118,	// ����
	//m_dwPara1		0  1�� 1  2��
	//m_dwPara2		����
	eta_equip_kaiguang_get_nai			=119,	// ����������
	//m_dwPara1		0  1�� 1  2��
	//m_dwPara2		����
	eta_equip_clear_talent				=120,	// ���������츳
	//m_dwPara1		
	//m_dwPara2		����
	eta_refresh_circle_quest			=121,	// ˢ�������ͽ�����
	//m_dwPara1		
	//m_dwPara2		����
	eta_SetShareLeaderCircleQuest		=122,	// �Զӳ�����ݼ���ħ���ͽ�����
	//m_dwPara1		
	//m_dwPara2		����
	eta_quest_xuanshan_get				=123,	// ��ȡ��������
	//m_dwPara1		
	//m_dwPara2		����
	eta_quest_xuanshan_put				=124,	// ������������
	//m_dwPara1		
	//m_dwPara2		����
	ete_kill_role_level					=125 ,	// ��ɱ�ض��ȼ���ɫ
	//m_dwPara1		�ȼ�	
	//m_dwPara2		����	
	ete_kill_role_class					=126 ,	// ��ɱ�ض�ְҵ��ɫ
	//m_dwPara1		ְҵ
	//m_dwPara2		����	
	ete_have_prentice					=127 ,	// ӵ��ͽ��
	//m_dwPara1		
	//m_dwPara2		����	
	ete_1v1_win							=128 ,	// ��������ʤ
	//m_dwPara1		
	//m_dwPara2		����
	ete_1v1_lost						=129 ,	// ������ʧ��
	//m_dwPara1		
	//m_dwPara2		����	
	ete_rank_pos						=130 ,	// ĳ�����а����δﵽ
	//m_dwPara1		0 ����ȼ��� 1 �������а� 2 �������а� 3 1v1���а� 4 �ɻ����а� 5 �ɾ͵����� 6 �ɾ�������
	//m_dwPara2		����	
	ete_1v1_win_class					=131 ,	// ��������ʤĳְҵ
	//m_dwPara1		ְҵ
	//m_dwPara2		����
	ete_1v1_win_level					=132 ,	// ������Ӯ�˵ȼ������Լ�XX���Ķ���
	//m_dwPara1		�ȼ���
	//m_dwPara2		����
	eta_unbeset_level					=133 ,	// ��Ƕxx����ʯ
	//m_dwPara1		�����Ƕ�ȼ�
	//m_dwPara2		����
	ete_delete_item_level				=134,	// �ݻ�xx�ȼ�װ��
	//m_dwPara1		��͵ȼ�
	//m_dwPara2		����	
	ete_chushi							=135,	// ��ʦ
	//m_dwPara1		
	//m_dwPara2		����	
	ete_duel_class						=136 ,	// �д��ʤĳְҵ
	//m_dwPara1		ְҵ
	//m_dwPara2		����
	ete_duel_level						=137 ,	// �д�Ӯ�˵ȼ������Լ�XX���Ķ���
	//m_dwPara1		�ȼ���
	//m_dwPara2		����
	eta_team_rand_share_quest			=138,	// ���ħ���ͽ�����
	//m_dwPara1		
	//m_dwPara2		����
	eta_huoyue_yibai					=139,	// ��ȡ100���Ծ��(�ű��жϵ�)
	//m_dwPara1		
	//m_dwPara2		����
	eta_getwuhuen_yibai					=140,	// 100���������������ȡ
	//m_dwPara1		
	//m_dwPara2		����
	eta_shipin_fumo_level				=141,	// ��Ʒ��ħ��XX��
	//m_dwPara1		
	//m_dwPara2		�ȼ�
	ete_kill_role_level_sub				=142,	// ɱ�����Լ�XX�������
	//m_dwPara1		�ȼ���
	//m_dwPara2		����
	ete_title_get						=143,	// ��óƺ�
	//m_dwPara1		�ƺ�id
	//m_dwPara2		����

	ete_max_event_num,					// �¼���Ŀ
	ete_end								=ete_max_event_num,
};


//-----------------------------------------------------------------------------
// �ƺ���������
//-----------------------------------------------------------------------------
enum e_condition_type
{
	ect_count						= 0,	// ��������
	ect_value						= 1,	// ��ֵ����
	ect_check						= 2,	// ����������
};

// �ɾ���������
enum e_achievement_signet
{
	eas_chuanqi = 0,		// ����
	eas_war,				// ս��
	eas_zanmei,				// ����
	eas_tianqi,				// ����
	eas_totle,				// ��

	eas_number
};

//-----------------------------------------------------------------------------
// �ɾ�ԭ��
//-----------------------------------------------------------------------------
struct AchievementEntry
{
	DWORD				m_ID;
	DWORD				m_refAchievement;			// ��Ӧ�ɾ�ID,�еĳɾ���������������ɾ�
	UINT32				m_point;					// �ɾ͵���
	e_achievement_signet m_signet;					// ��������
	UINT32				m_count;					// ��Ҫ��ɵ���������
	DWORD				m_nTitleID;					// ��óƺ�id
};

// �ɾ�����
struct AchievementCriteriaEntry
{
	DWORD				m_ID;                                          
	DWORD				m_referredAchievement;    // ��Ӧ�ɾ�id             					

	e_condition_type 	m_CondType;				// ��������
	e_achievement_event	m_Events;				// �¼�����

	DWORD				m_dwPara1;
	DWORD				m_dwPara2;

	DWORD				m_dwTimeLimit;			// ʱ������(�೤ʱ�������)
};

// �����е�����
struct CriteriaProgress
{
	DWORD	m_ID; 
	DWORD	m_date;					// ʱ��
	DWORD	m_counter;				// ����
	bool	m_changed;				// �Ƿ�ı�,��¼���ݿ���
	bool	m_bTimedCriteriaFailed;	//�Ƿ��Ѿ���ʱ
};


// ����ɵĳɾ�
struct CompletedAchievementData
{
	DWORD	m_ID; 
	DWORD	m_date;			// ʱ��
	bool	m_changed;		// �Ƿ�ı�,��¼���ݿ���
};


class AchievementHelper
{
public:
	// ��ȡ��Ӧ���µȼ�
	static INT GetSignetLevel(e_achievement_signet eType, INT nComplateNum)
	{
		switch (eType)
		{
		case eas_chuanqi:
			break;
		case eas_war:
			break;
		case eas_zanmei:
			break;
		case eas_tianqi:
			break;
		case eas_totle:
			break;
		default:
			break;
		}
		if(nComplateNum < 20)
			return 1;
		else if(nComplateNum >= 20 && nComplateNum < 50)
			return 2;
		else if(nComplateNum >= 50 && nComplateNum < 90)
			return 3;
		else if(nComplateNum >= 90 && nComplateNum < 140)
			return 4;
		else if(nComplateNum >= 140 && nComplateNum < 200)
			return 5;
		else if(nComplateNum >= 200)
			return 6;
		else
			return 1;
	}

	//ͨ���ȼ�ȡ��������
	static INT GetMaxPoint(INT nLevel)
	{
		if(nLevel == 1)
		{
			return 20;
		}
		else if(nLevel == 2)
		{
			return 50;
		}
		else if(nLevel == 3)
		{
			return 90;
		}
		else if(nLevel == 4)
		{
			return 140;
		}
		else if(nLevel == 5)
		{
			return 200;
		}
		else if(nLevel == 6)
		{
			return 500;
		}
		return 10;
	}

	// ��ȡ�ɾ����µȼ�
	static INT GetAchievementLevel(INT nAchievementNum)
	{
		if (nAchievementNum >= 620)
		{
			return 6;
		}
		if (nAchievementNum >= 430)
		{
			return 5;
		}
		if (nAchievementNum >= 280)
		{
			return 4;
		}
		if (nAchievementNum >= 160)
		{
			return 3;
		}
		if (nAchievementNum >= 60)
		{
			return 2;
		}
		return 1;
	}

	// ��ȡ��ǰ�ȼ����ֵ
	static INT GetMaxNumByLevel(INT nLevel)
	{
		if (nLevel == 1)
		{
			return 60;
		}
		if (nLevel == 2)
		{
			return 160;
		}
		if (nLevel == 3)
		{
			return 280;
		}
		if (nLevel == 4)
		{
			return 430;
		}
		if (nLevel == 5)
		{
			return 620;
		}
		if (nLevel == 6)
		{
			return 1000;
		}
		return 60;
	}
};
#pragma pack(pop)


#endif