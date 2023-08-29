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

#include "../../common/WorldDefine/base_define.h"
#include "../../common/WorldDefine/RoleDefine.h"
#include "../../common/WorldDefine/time.h"
#include "../../common/WorldDefine/talent_define.h"
#include "../../common/WorldDefine/currency_define.h"
#include "../ServerDefine/clandata_server_define.h"
#include "../../common/WorldDefine/container_define.h"
#include "../../common/WorldDefine/ItemDefine.h"
#include "../../common/WorldDefine/Raid_define.h"
#include "../ServerDefine/log_server_define.h"

#pragma pack(push, 1)

struct tagDWORDTime;


const INT MIN_ROLE_SAVE2DB_INTERVAL			= 60 * TICK_PER_SECOND;
const INT ROLE_TIME_STAT_INTERVAL			= 30 * 60 * TICK_PER_SECOND;
const INT ROLE_HANG_TIME					= 60;
const INT MAX_LEAVE_EXP						= 20000;
const INT MAX_LEAVE_BROTHER					= 50000;
const INT MAX_GIFT_NUM						= 4;				// ���������Ʒ����
const INT32 MAX_ITEM_NEEDLOG_NUM			= 100000;


//! ��һ�����Ա仯�Ķ�������
enum e_role_att_to_change
{
	erac_null = -1,

	erac_attack,
	earc_defense,
	earc_maxhp,
	earc_hit,
	earc_dodge,
	earc_block,
	earc_crit,
	earc_critvalue,
	earc_fancrit,
	earc_fancritvalue,
	earc_maxmp,
	earc_hp_reborn,
	earc_mp_reborn,

	earc_num
};

enum
{
	e_database_insert_role_name_exist		= 1,		// ������ɫ�������Ѵ���(��������ɫ������������ͬ)
	e_database_insert_role_failed			= 2,		// ���ݿ��д�����ɫʧ��
	e_database_insert_friend_failed			= 3,		// ���ݿ�����Ӻ���ʧ��
	e_database_insert_enemy_failed			= 4,		// ���ݿ�����ӳ��ʧ��
	e_database_insert_friendship_failed		= 5,		// ���ݿ�������Ѻö�ʧ��
	e_database_insert_black_failed			= 6,		// ��Ӻ�����ʧ��

	e_database_load_sim_role_failed			= 51,		// ���ʺ����޽�ɫ�����ȡ�ʺŽ�ɫ������Ϣʧ��	
	e_database_load_role_data_failed		= 52,		// �����ݿ��ж�ȡĳ����ɫʧ��	
	e_database_load_skill_failed			= 53,		// �����ݿ��ж�ȡ�����б�ʧ��	
	e_database_load_role_buff_failed		= 54,		// �����ݿ��ж�ȡ��ɫBuffʧ��	
	//E_DBLoad_TalentFailed					= 55,		// �����ݿ��ж�ȡ�����б�ʧ��	
	e_database_load_title_failed			= 56,		// �����ݿ��ж�ȡ�ƺ��б�ʧ��	
	e_database_load_item_Failed				= 57,		// �����ݿ��ж�ȡ��Ʒ�б�ʧ��
	e_database_load_equip_failed			= 58,		// �����ݿ��ж�ȡװ���б�ʧ��	
	e_database_load_friend_failed			= 59,		// �����ݿ��ж�ȡ�����б�ʧ��	
	e_database_load_enemy_failed			= 60,		// �����ݿ��ж�ȡ����б�ʧ��	
	e_database_load_quest_failed			= 61,		// �����ݿ��ж�ȡ�����б�ʧ��	
	e_database_laod_quest_done_failed		= 62,		// �����ݿ��ж�ȡ����������б�ʧ��		
	e_database_load_sim_quest_failed		= 63,		// �����ݿ��ж�ȡ���������б�ʧ��	
	e_database_laod_sim_quest_done_failed	= 64,		// �����ݿ��ж�ȡ����ɼ��������б�ʧ��		
	e_database_friendship_failed			= 65,		// �����ݿ��ж�ȡ���Ѷ��б�ʧ��	

	//	E_DBLoad_BaiBao_NoNewItem			= 65,		// û���µ���Ҫ���ŵ��ٱ����е���Ʒ(װ��)
	e_database_baibao_failed				= 66,
	e_database_load_item_need_log_failed	= 67,	
	e_database_save_role_failed				= 70,		// ���ݿⱣ��ʧ��

	e_database_load_baibao_log_failed		= 71,		// �ٱ�����ʷ��¼��ȡʧ��

	e_backup_del_role_data_failed			= 80,		// ���ݱ�ɾ����ɫ�������ʧ��
	e_backup_delete_item_failed				= 81,		// ���ݱ�ɾ����ɫ��Ʒ����ʧ��
	e_delete_role_data_failed				= 82,		// ɾ����ɫ�����������ʧ��
	e_record_delete_role_data_failed		= 83,		// ��ɫ����ɾ���ɹ�����дrole_del��ʧ��

	//	E_DelItemFailed					= 90,		// ɾ����ɾ����ɫ��Ʒ����ʧ��
	//	E_DBDelete_RoleBuffFailed		= 91,		// ɾ����ɫBuff����ʧ��
	e_database_delete_friend_failed			= 92,		// ɾ������ʧ��
	e_database_delete_enemy_falied			= 93,		// ɾ�����ʧ��
	e_database_delete_role_failed			= 94,		// ɾ����ɫʧ��
	e_database_delete_friendship_failed		= 95,		// ɾ���Ѻö�ʧ��
	e_database_delete_black_failed			= 96,		// ɾ��������ʧ��


	e_change_role_name_failed				= 100,		// �޸Ľ�ɫ����ʧ��

	e_database_load_rep_rankdata_failed		= 120,		// ��ȡ������������

};


//! ���ﴴ���ṹ
struct s_create_role_info
{
	tagAvatarAtt	avatar;						// size = 16
	TCHAR			sz_role_name[X_SHORT_NAME];

	tagDWORDTime	create_time_;					// ����ʱ��
	DWORD			dw_map_id_;
	FLOAT			fX;
	FLOAT			fY;
	FLOAT			fZ;
	FLOAT			f_face_x_;
	FLOAT			f_face_y_;
	FLOAT			f_face_z_;
	EClassType		e_class_type_;
	BYTE			by_level_;
	BYTE			by_reserved_[3];

};


//! ʵʱ�������ݿ�ö��
enum e_real_time_save_att
{
	ertsa_null			= -1,
	ertsa_exp			= 0,
	ertsa_level			= 1,
	ertsa_brotherhood	= 2,
	ertsa_love			= 3,
	ertsa_wuhuen		= 4
};


//! ����������ݽṹ
struct s_role_info
{
	DWORD			dw_role_id;					// ID
	DWORD			dw_role_name_crc;				// ����CRC
	DWORD			dw_account_id;				// �˻�ID
	TCHAR			sz_role_name[X_SHORT_NAME];	// ����
	DWORD			dw_map_id_;					// ���ڵ�ͼ
	tagDWORDTime	dw_time_last_logout_;		// �������ʱ��
	BYTE			by_level;					// �ȼ�
	BYTE			by_sex_;					// �Ա�
	EClassType		e_class_type_;
	bool			b_online_;					// ����Ƿ�����
	DWORD dw_amends_flag;			// �⳥��־
	s_role_info()
	{
		memset(this, 0, sizeof(*this));
	}
};


//! ��ȫ��
struct s_safe_code
{
	DWORD	dw_safe_code_crc;		// ��ȫ��crc32��INVALID_VALUE��ʾû�����ù�
	DWORD	dw_reset_time;		// ����ʱ�䣬INVALID_VALUE��ʾû������
};

//! accountrel�����������
struct s_account_common
{
	s_safe_code	s_safe_code_;
	DWORD		dw_bag_password_crc_;
	INT			n_baibao_yuanbao_;
	INT64		n64_ware_silver_;
	INT16		n16_ware_size_;
	INT16		n16_ware_step;
	INT32		n_yuanbao_recharge;
	BOOL		b_receive;
	DWORD		dw_total_recharge;
	INT16		n16_receive_type;
	DWORD		dw_receive_type;
	DWORD		dw_web_type;
	INT32		n32_score;
	BOOL		b_Robort;

	VOID init()
	{
		s_safe_code_.dw_safe_code_crc = INVALID_VALUE;
		s_safe_code_.dw_reset_time	= INVALID_VALUE;

		dw_bag_password_crc_				= INVALID_VALUE;
		n64_ware_silver_			= 0;
		n_baibao_yuanbao_			= 0;
		n16_ware_size_				= 0;
		n16_ware_step				= 1;
		n_yuanbao_recharge			= 0;
		b_receive					= TRUE;
		dw_total_recharge			= 0;
		n16_receive_type			= 0;
		dw_receive_type				= 0;
		dw_web_type					= 0;
		n32_score					= 0;
	}
};

//! �������
struct s_new_role_gift_proto
{
	INT16	n_id_;
	DWORD	dw_gift_id_[MAX_GIFT_NUM];
	DWORD	dw_time_[MAX_GIFT_NUM];
	DWORD	dw_gift_num[MAX_GIFT_NUM];
};

//! �������
struct s_new_role_gift
{
	INT		n_id_;
	INT		n_step_;				// �׶�
	DWORD	dw_gift_id_;			// ����ID
	DWORD	dw_leave_time_;			// ʣ��ʱ��
	BOOL	b_get_;					// �Ƿ���Ի�ȡ
	BOOL	b_begin_time_;			// �Ƿ�ʼ��ʱ 

	s_new_role_gift()
	{
		n_id_ = 0;
		n_step_ = 0;
		dw_gift_id_ = INVALID_VALUE;
		dw_leave_time_ = 0;
		b_get_ = FALSE;
		b_begin_time_ = FALSE;
	}

	VOID init(INT n_id, INT n_step, DWORD dw_gift_id, DWORD dw_leave_time, BOOL b_get)
	{
		this->n_id_ = n_id;
		this->n_step_ = n_step;
		this->dw_gift_id_ = dw_gift_id;
		this->dw_leave_time_ = dw_leave_time;
		this->b_get_ = b_get;
		b_begin_time_ = FALSE;
	}

	VOID set_get(BOOL b_get) { this->b_get_ = b_get; }

	VOID reset(INT n_id, INT n_step, DWORD dw_gift_id, DWORD dw_leave_time)
	{
		this->n_id_ = n_id;
		this->n_step_ = n_step;
		this->dw_gift_id_ = dw_gift_id;
		this->dw_leave_time_ = dw_leave_time;
		b_get_ = FALSE;
		b_begin_time_ = FALSE;
	}

};

struct s_1v1_score
{
	INT		n_cur_score;		// ��ǰ����
	INT		n_day_max_score;		// ����������
	INT		n_day_scroe_num;		// ���ս������
	INT16	n16_score_award;		// ���־�������
};


//! ��Ϸ�����������ݿ��������ȡ��������ݽṹ
struct s_role_data_const
{
	DWORD			dw_role_name_crc;			// ����CRC
	TCHAR			sz_role_name[X_SHORT_NAME];	// ����
	tagAvatarAtt	avatar;						// ���
	tagDWORDTime	create_time_;				// ����ʱ��
};

struct s_role_data_save
{
	tagDWORDTime	login_time_;				// ����ʱ��
	tagDWORDTime	logout_time_;				// �ǳ�ʱ��
	INT				n_online_time_;				// ������ʱ��
	INT				n_cur_online_time_;			// ��������ʱ��

	tagDWORDTime	leave_guild_time_;			// �뿪���ʱ��

	tagAvatarEquip	avatar_equip_;				// װ�����
	tagDisplaySet	display_set_;				// �����ʾ����

	DWORD			dw_map_id_;					// ���ڵĵ�ͼ��ID
	DWORD			dw_reborn_map_id_;			// �����ͼID
	FLOAT			f_coordinate_[3];			// λ�ã�x,y,z��
	FLOAT			f_face_[3];					// ����Vectro3��

	EClassType		e_class_;					// ְҵ
	EClassTypeEx	e_class_ex_;				// ��չְҵ

	INT				n_level_;					// ��ҵȼ�
	INT				n_cur_exp_;					// ��ҵ�ǰ�������������

	INT				n_hp_;						// ����
	INT				n_mp_;						// ����
	INT				n_rage_;					// ŭ��
	INT				n_endurance_;				// �־��� ��Ϊ�������
	INT				n_brotherhood_;				// ����
	INT				n_injury_;					// ���� ��Ϊ����ֵ
	INT				n_knowledge_;				// ����
	INT				n_morale_;					// ʿ��
	INT				n_morality_;				// ���� ��Ϊ���ֵ
	INT				n_luck_;					// ��ѧ��Ϊ �ĳ�������ֵ
	INT				n_credit_;					// ���ö�
	INT				n_identity_;				// ���
	INT				n_vip_point_;				// ��Ա����
	INT				n_vigour_;					// Ԫ��

	INT				n_att_point_;				// ��ҿ��õ����Ե�
	INT				n_talent_point_;			// ��ҿ��õ����ʵ�

	INT				n_att_point_add_[X_ERA_ATTA_NUM];// ���Ͷ�ŵ�����һ�������е�ֵ
	tagRoleTalent	talent_[X_MAX_TALENT_PER_ROLE];// ��ҵ�����

	BOOL			b_safe_guard_;					// �Ƿ�PK����
	tagDWORDTime	close_safe_guard_time_;			// �ϴιر�PK������ʱ��
	INT				n_pk_value_;					// pkֵ
	
	DWORD			dw_destory_equip_count;			// �ݻ�װ������
	INT16			n16_bag_size_;					// ������С
	INT				n_bag_gold_;					// �����н�����
	INT				n_bag_silver_;					// ������������
	INT				n_bag_copper_;					// ������ͭ��
	INT				n_bag_bind_gold_;				// �����а󶨽�����
	INT				n_bag_bind_silver_;				// �����а�������
	INT				n_bag_bind_copper_;				// �����а�ͭ��
	INT				n_bag_tuanbao_;					// ������Ԫ����
	INT				n_ex_volume_;					// ��ɫ������
	
	INT16			n16_pet_packet_size_;			// ����������
	INT16			n16WareSize;				// �˺Ųֿ��С
	INT				nWareGold;					// �˺Ųֿ��н�����
	INT				nWareSilver;				// �˺Ųֿ���������
	INT				nWareCopper;				// �˺Ųֿ���ͭ��
	//INT				nWareYuanBao;				// �˺Ųֿ���Ԫ����

	DWORD			dw_guild_id;					// ����id
	DWORD			dw_team_id_;					// ����ID
	
	INT				n_total_tax_;					// ��˰�ܶ�

	tagRemoteOpenSet s_remote_open_set_;			// ��Զ����ҹ�����Ϣ����
	UINT16			u16_active_title_id[3];			// ��ǰ�ƺ�

	DWORD			dw_time_get_mall_free_;			// �ϴδ��̳���ȡ�����Ʒʱ��

	INT	 			n_skill_num_;					// ���ܸ���			-- tagSkillSave
	INT				n_buff_num_;					// ״̬����			-- tagBuffSave

	INT				n_title_num_;					// �ƺŸ���			-- tagTitleSave

	INT				n_item_num_;					// ��Ʒװ������		-- tagItem,tagEquip
	INT				n_friend_num_;					// ���Ѹ���			-- ��: tagFriendSave, ��: ʵʱ,����������Ϣ
	INT				n_enemy_num_;					// ��и���			-- ��: DWORD dwEnemyID, ��: ʵʱ,����������Ϣ
	INT				n_quest_num_;					// �����б����		-- tagQuestSave
	INT				n_quest_done_num;				// ����ɵ�������� -- ����tagQuestDoneSave���棺ʵʱ
	INT				n_item_cd_time_num_;			// ��Ʒ��ȴʱ��		-- tagCDTime
	INT				n_friendship_num_;				// �Ѻö�			-- tagFriendshipSave
	INT				n_black_num_;					// ������			-- DWORD
	BOOL			b_clan_data_chg_;				// ���������Ƿ�ı�
	INT				n_pets_num_;					// ������Ŀ
	tagScriptData<ESD_Role>	data_;					// ��ҽű�����
	INT				n_treasure_sum_;				// ��ҿ���������
	INT				n_map_limit_num_;				// �����ͼ��������
	INT				n_achievement_num_;				// ��ɳɾ͸���
	INT				n_achievement_criteria_num_;	// �����еĳɾ���������

	DWORD			dw_last_stall_time_;			// ̯λ�������ʱ��
	INT32			n_stall_daily_exp_;				// ̯λ���վ���
	INT32			n_stall_cur_exp_;				// ̯λ��ǰ�ȼ�����
	BYTE			by_stall_level_;				// ̯λ�ȼ�
	BOOL			h_has_left_msg_;				// ������
	
	// ����״̬
	DWORD	dw_forbid_talk_start_;
	DWORD	dw_forbid_talk_end_;

	INT16			n16_hang_num_;					// �һ�����
	BOOL			b_exp_;							// �Ƿ�ʹ�þ��鵤
	BOOL			b_brotherhood_;					// �Ƿ�ʹ��������
	INT				n_leave_exp_;					// ���߾���
	INT				n_leave_brotherhood_;			// ��������

	INT				n_total_mater_moral_;			// ʦ��ֵ

	INT				n_send_mail_num_;				// �����ʼ�������

	DWORD		 dw_master_id_;					//ʦ��
	DWORD        dw_master_prentice_forbid_time_;		//��ֹ��ͽ���ʦʱ��

	DWORD		 dw_own_instance_id_;				// ���ڸ���ID
	DWORD		 dw_own_instance_map_id_;			// ���ڸ�����ͼID
	tagDWORDTime dw_instance_create_time_;			// ��������ʱ��

	BYTE		 by_role_help_[ROLE_HELP_NUM];		// �����������
	BYTE		 by_talk_data_[TALK_DATA_NUM];		// ����Ի�����
	//tagKeyInfo   st_key_info_[MAX_KEY_NUM];			// ��ݼ�����
	roleOnlineState st_key_info_;

	BYTE		 by_role_day_clear[ROLE_DAY_CLEAR_NUM];	// ÿ����������

	INT			n_kill_num_;						// ɱ����

	INT		n_gift_id_;								// ������ID	
	INT		n_gift_step_;								// �׶�
	DWORD	dw_gift_id_;								// ����ID
	DWORD	dw_gift_leave_time_;						// ʣ��ʱ��
	BOOL	b_gift_get_;								// �Ƿ���Ի�ȡ

	ECamp	e_role_camp;								// ������Ӫ

	INT		n_paimai_limit;								// ����������������
	
	INT		n_bank_limit;								// ����Ǯׯ������������

	INT		n_shop_exploits_limit;						// ս���̵�����

	DWORD	dw_today_online_tick_;						// ��������ʱ��
	DWORD	dw_history_vigour_cost_;					// Ԫ��ֵ����
	DWORD	dw_perday_get_vigour_total;	

	INT16	n16_exbag_step;								// ��������׶�
	INT16	n16_exware_step;							// ����ֿ�׶�

	INT		n_yuanbao_exchange_num;						// Ԫ���һ�����
	INT		n_achievement_point;						// �ɾ͵���
	INT		n_achievement_num;							// �ɾ�����

	TCHAR	sz_signature_name[X_SHORT_NAME];			// ǩ�� 
	CircleQuestMan	circle_quest_man_;					// ���������
	INT n_graduates_num;				// �Ƿ��ʦ

	s_1v1_score		st_1v1_score;		// ���־���

	INT		n_inst_process_num;							// ������������

	INT32	n32_exploits;				// ս��
	INT	n_circle_quest_fresh;		// �����ˢ�´���
	INT	n_circle_quest_freshMax;		// �����ˢ�´���
	INT n_circle_quest_perdaynum;			// �������
	BOOL b_PurpureDec;
	INT n_CoolDownReviveCD;
	INT n_PerDayHangGetExpTimeMS;
	INT32	n32_active_num;							// ��Ծ��
	INT32	n32_active_data[MAX_ACTIVE_DATA];		// ��Ծ������
	BOOL	b_active_receive[MAX_ACTIVE_RECEIVE];	// ��Ծ���콱����
	
	INT32	n32_guild_active_num;						// ����Ծ��
	INT32	n32_guild_active_data[MAX_ACTIVE_DATA];		// ����Ծ������
	BOOL	b_guild_active_receive[MAX_ACTIVE_RECEIVE];	// ����Ծ���콱����

	INT32	n32_rating;			// ս����
	DWORD			dw_shihun;			// �ɻ�
	INT16	n16_pet_xiulian_size;			// �����������
	INT				n_god_level_;					// ��

	INT32	nInstanceData;		//  �����Ƿ�����
	tagDWORDTime nInstanceShaodang;	//	ɨ����ʼʱ��
	INT32	nSaodangIndex;		//  ɨ���ĸ�������
	DWORD	dwSpouseID;			//	��żID
	INT dwVIPLevel;				//	vip�ȼ�
	tagDWORDTime dwVIP_Deadline;//  vip��ֹ����
	/*********************************************************************************************************
	*�����б�״̬�б��ƺ��б��ƺ������б���Ʒ�б�װ���б������б�����б������б�����������б�
	*��Ʒ��ȴʱ���, �Ѻöȱ���ɫ����(�Զ���)
	*���밴˳�򿽱�
	*********************************************************************************************************/

	BYTE			by_data[1];
};

struct s_role_data_load
{
	DWORD				dw_size;					// �����Ϣ��С
	s_role_data_const	role_data_const_;
	s_role_data_save	role_data_save_;
};

struct s_record_del // ɾ���������Ϣ(���α����)
{
	INT	 	n_skill_num_;		// ���ܸ���(dwSkillID):  ����ԭ������ļ�����ʧ,�������������ѧ,�˴�Ҳ���¼
	INT		n_buff_num_;		// ״̬����(dwBuffID):    �����������ʧ��������״̬
//	INT		nTalentNum;		// �����б�(ETalentType): ϴ�������
//	INT		n_item_num;		// ��Ʒ����(n64_serial):   ��ݻٵģ���������ݿ���ɾ���� -- ʵʱ
//	INT		nEquipNum;		// װ������(n64_serial):   ��ݻٵģ���������ݿ���ɾ���� -- ʵʱ
	INT		n_quest_num_;		// �������(dwQuestID):   ����ɾ���ĺ���ɵ�

	/*********************************************************************************************************
	*�����б�״̬�б���Ʒ�б�װ���б������б�
	*���밴˳�򿽱�
	*********************************************************************************************************/
	BYTE	by_data_[1];		// ��¼����
};

//! ���＼��
struct s_skill_save
{
	DWORD	dw_id;				// ����ID
	INT		n_self_level_;		// ����ȼ�
	INT		n_learn_level_;		// Ͷ��ȼ�
	INT		n_cool_down_;		// ���ܻ���Ҫ����ȴʱ��
	INT     n_proficiency_;		// ����������
};

//! ����buff�Ļ�����Ϣ
struct s_buff_save
{
	DWORD		dw_buff_id_;					// ID
	INT32		n_persist_tick_;				// ��ǰ����ʱ��

	INT8		n_level_;						// �ȼ�
	INT8		n_cur_lap_times_;				// ��ǰ���Ӵ���
	INT8		n_modifier_num_;				// Ӱ�����ļ��ܸ���
	INT8		n_dummy_[1];

	DWORD		dw_src_unit_id_;				// ԴUnit��ID
	DWORD		dw_src_skill_id_;				// ���ĸ����ܲ�������ID��
	INT64		n_serial_;						// ���ĸ���Ʒ��װ������
	DWORD		dw_item_type_id_;				// ��Ʒ��װ��������ID

	BYTE		by_data_[1];
};

//! ����
struct s_friend_save
{
	DWORD		dw_friend_id_;		// ����id
	INT32		n_group_id_;		// ����
};

struct s_friendship_save
{
	DWORD		dw_friend_id_;		// ����id
	INT32		n_frival_;		// �Ѻö�
};


//! ��Ҹ�����������Ӧ�Ļ������Լ������ü��õ����ʺ�������һ������ľ������� -- ��xml�ж���
struct s_level_up_effect
{
	DWORD	dw_level_up_id_;	// ��������id ��ְҵ�͵ȼ�����
	INT		n_exp_level_up_;	// ������һ������ľ�������
	INT16	n_role_att_[10];	// �����С���� ���� ħ�� ����
	//INT16	n16RoleAttAvail;	// �õ��Ŀ�Ͷ���Ե�
	INT16	n_talent_avail_;	// �õ��Ŀ�Ͷ���ʵ�
	INT		n_hp_;				// ��ǰ����Ѫ��
	INT		n_mp_;				// ��ǰ����������
	INT		n_rating;			// ��ǰ�������ս��
	INT16	n_dummy_;

	s_level_up_effect() { ZeroMemory(this, sizeof(*this)); n_exp_level_up_ = INVALID_VALUE; }
};

//! ���һ�����ԶԶ�������ת����
struct s_role_att_change
{
	DWORD	dw_id_;						//id ְҵ��һ�����Ե����
	INT16	n_att_change_[earc_num];		//��Ӧ�������Ա仯
};

//! ��ҽű��������Ͷ���
enum e_role_script_data
{
	drsd_injury			=	0,				// 0������������״̬
	drsd_end			=	100,
};

//! �����ͼ����
struct s_enter_map_limit
{
	DWORD				dw_map_id_;				// ��ͼID
	DWORD				dw_enter_num_;			// Ȩֵ
	INT					e_enter_limit_;			// ��������
};


// ��֤��
struct s_verification_code
{
	DWORD	dw_id;
	tstring	dw_code;
};

#define MAX_INST_DOOR_NUM	50
#define MAX_INST_CREATURE_NUM	1000

struct s_inst_door_state
{
	DWORD	dw_door_id;
	BOOL	b_open;
};
// ! ��������
struct s_inst_process
{
	DWORD	dw_map_id;						// ��ͼID
	INT16	n_mode;						// �Ѷ�����
	INT16	n_type;						// ��������
	s_inst_door_state st_door_state[MAX_INST_DOOR_NUM];		// �Ž���
	DWORD	dw_creature_id[MAX_INST_CREATURE_NUM];	// �������
};

//! ����
struct NET_heartbeat : public tag_net_message
{  
	NET_heartbeat ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_heartbeat" ) ;
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dwGoldenCode;  // ��������ɫ����
	DWORD dwHeartbeat;   // �������������� 
};  


struct NET_retification : public tag_net_message 
{   
	NET_retification ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_retification" ) ;
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_golden_code_;
	TCHAR sz_world_name_[X_SHORT_NAME];
};  

struct NET_DB2C_world_shutdown : public tag_net_message 
{   
	NET_DB2C_world_shutdown ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_world_shutdown" ) ;   
		dw_size = sizeof ( * this ) ;   
	}   
};  

struct NET_DB2S_world_shutdown : public tag_net_message 
{  
	NET_DB2S_world_shutdown ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_world_shutdown" ) ;
		dw_size = sizeof ( * this ) ;    
	} 
};  


struct NET_DB2C_load_all_role_info : public tag_net_message 
{   
	NET_DB2C_load_all_role_info ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_all_role_info" ) ;  
		dw_size = sizeof ( * this ) ;    
	}
};  

struct NET_DB2S_load_all_role_info : public tag_net_message
{  
	NET_DB2S_load_all_role_info ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_all_role_info" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_error_code;   
	INT32 n_count; 
	s_role_info role_info_[1];
};  

struct NET_DB2C_load_sim_role : public tag_net_message 
{   
	NET_DB2C_load_sim_role ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_sim_role" ) ;  
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_account_id; 
	CHAR sz_account[X_SHORT_NAME];
};  

struct NET_DB2S_load_simrole : public tag_net_message 
{  
	NET_DB2S_load_simrole ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_simrole" ) ; 
		dw_size = sizeof ( * this ) ;    
	} 
	DWORD dw_error_code;   
	DWORD dw_account_id;   
	INT32 n_count;  
	s_account_common s_account_common_;
	tagSimRole sim_role_[MAX_ROLENUM_ONEACCOUNT];  
};  

struct NET_DB2C_create_role : public tag_net_message 
{   
	NET_DB2C_create_role ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_create_role" ) ;   
		dw_size = sizeof ( * this ) ;    
	}   
	DWORD dw_account_id; 
	s_create_role_info s_role_info_;   
};  

struct NET_DB2S_create_role : public tag_net_message 
{  
	NET_DB2S_create_role ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2S_create_role" ) ;   
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_error_code;  
	DWORD dw_account_id;
	tagSimRole s_sim_role_;  
	s_role_info s_role_info_;  
};  

struct NET_DB2C_delete_role : public tag_net_message 
{   
	NET_DB2C_delete_role ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_role" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_account_id;  
	DWORD dw_role_id;
	DWORD dw_time;  
	TCHAR sz_role_name[X_SHORT_NAME]; 
	CHAR sz_ip[X_IP_LEN];  
};  


struct NET_DB2S_delete_role : public tag_net_message 
{   
	NET_DB2S_delete_role ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2S_delete_role" ) ;   
		dw_size = sizeof ( * this ) ;    
	} 
	DWORD dw_error_code; 
	DWORD dw_role_id;  
	DWORD dw_account_id;    
};  
//!
struct NET_DB2C_delete_role_guard_time_set : public tag_net_message 
{   
	NET_DB2C_delete_role_guard_time_set ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_role_guard_time_set" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_account_id;  
	DWORD dw_role_id;
	DWORD dw_delGuardTime;
}; 

struct NET_DB2S_delete_role_guard_time_set : public tag_net_message 
{   
	NET_DB2S_delete_role_guard_time_set ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_delete_role_guard_time_set" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_error_code;
	DWORD dw_account_id;  
	DWORD dw_role_id;
	DWORD dw_delGuardTime;
}; 


struct NET_DB2C_load_role : public tag_net_message 
{   
	NET_DB2C_load_role ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_role" ) ;  
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_account_id;
	DWORD dw_role_id;    
};  

//! ע�����Ϣ�ṹ��С�����¼���
struct NET_DB2S_load_role : public tag_net_message 
{   
	NET_DB2S_load_role ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_role" ) ; 
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_error_code; 
	DWORD dw_account_id;  
	DWORD dw_role_id; 
	s_role_data_load RoleData;   
};  

struct NET_DB2C_load_serial_reward : public tag_net_message
{
	NET_DB2C_load_serial_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_serial_reward");
		dw_size = sizeof(*this);
	}
	//DWORD dw_account_id;
	DWORD dw_role_id;
	CHAR sz_serial[X_SHORT_NAME];
};

struct NET_DB2S_load_serial_reward : public tag_net_message
{
	NET_DB2S_load_serial_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_serial_reward");
		dw_size = sizeof(*this);
	}
	/*DWORD dw_account_id;
	INT		n_num;
	BYTE by_data_[1];  */
	DWORD dw_role_id;
	BOOL b_exists;
	CHAR sz_serial[X_SHORT_NAME];
	INT	 n_type;
};


struct NET_DB2C_resume_role : public tag_net_message 
{ 
	NET_DB2C_resume_role ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_resume_role" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
};  


//! ע�����Ϣ�ṹ��С�����¼���
struct NET_DB2C_save_role : public tag_net_message
{  
	NET_DB2C_save_role ( ) 
	{
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_save_role" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;  
	s_role_data_save RoleData;
};  
//gx add �������������Ϣ�󣬶�Ҫ�����н�����Ϣ�����ݿ� 2013.9.17
struct NET_DB2C_update_role_reward_data : public tag_net_message
{
	NET_DB2C_update_role_reward_data()
	{
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_role_reward_data" ) ; 
		dw_size = sizeof ( * this ) ; 
	}
	DWORD dw_role_id;
	BYTE  by_data[1];//tagRewardData
};
//end

//! ����
struct NET_DB2C_change_role_name : public tag_net_message 
{   
	NET_DB2C_change_role_name ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_role_name" ) ; 
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_account_id; 
	DWORD dw_role_id; 
	DWORD dw_change_time;
	DWORD dw_name_crc;
	TCHAR sz_new_role_name[X_SHORT_NAME]; 
};  

struct NET_DB2S_change_role_name : public tag_net_message 
{   
	NET_DB2S_change_role_name ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_change_role_name" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_error_code;  
	DWORD dw_account_id;  
	DWORD dw_role_id; 
	DWORD dw_change_time;
	DWORD dw_name_crc;
	TCHAR sz_new_role_name[X_SHORT_NAME];  
}; 

//! �ָ�ɾ������
struct NET_DB2C_cancel_role_del_guard_time : public tag_net_message 
{   
	NET_DB2C_cancel_role_del_guard_time ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_cancel_role_del_guard_time" ) ; 
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_account_id; 
	DWORD dw_role_id; 
}; 

struct NET_DB2S_cancel_role_del_guard_time : public tag_net_message 
{   
	NET_DB2S_cancel_role_del_guard_time ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_cancel_role_del_guard_time" ) ; 
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_error;
	DWORD dw_role_id; 
	DWORD dw_account_id;
};  

//
struct NET_DB2C_change_role_guild : public tag_net_message 
{  
	NET_DB2C_change_role_guild ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_change_role_guild" ) ;   
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_role_id;  
	DWORD dw_guild_id;  
};  

struct NET_DB2C_change_role_leave_guild_time : public tag_net_message 
{  
	NET_DB2C_change_role_leave_guild_time ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_role_leave_guild_time" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;
	tagDWORDTime dw_leave_guild_time_;  
};  
//gx add 2013.8.14
struct NET_DB2C_change_role_VIP_Info:public tag_net_message
{
	NET_DB2C_change_role_VIP_Info ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_change_role_VIP_Info" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;
	INT16 n_VIP_Level;
	tagDWORDTime dw_VIP_deadline;  
};
struct NET_C2DB_clear_role_VIP_info:public tag_net_message
{
	NET_C2DB_clear_role_VIP_info ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_C2DB_clear_role_VIP_info" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;
};
struct NET_DB2C_insert_friend : public tag_net_message 
{  
	NET_DB2C_insert_friend ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_insert_friend" ) ;
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_role_id; 
	s_friend_save s_friend_save_;    
};  

struct NET_DB2C_delete_friend : public tag_net_message 
{  
	NET_DB2C_delete_friend ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_friend" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id; 
	DWORD dw_friend_id_;  
};  

struct NET_DB2C_update_friend : public tag_net_message 
{  
	NET_DB2C_update_friend ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_update_friend" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_role_id;  
	s_friend_save s_friend_save_; 
};  


//! ע�⣺��DBServer�����Ѻö������Ϣʱ��Ӧdw_role_id < dwFriendID
struct NET_DB2C_delete_frival : public tag_net_message 
{  
	NET_DB2C_delete_frival ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_delete_frival" ) ;   
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_role_id;  
	DWORD dw_friend_id_; 
};  


//! ɾ����ɫʱ��ɾ�����ݿ���������غ�����Ϣ
struct NET_DB2C_delete_all_friend : public tag_net_message 
{ 
	NET_DB2C_delete_all_friend ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_all_friend" ) ;
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_role_id;  
};  


//! ɾ����ɫʱ��ɾ�����ݿ���������غ��Ѷ���Ϣ
struct NET_DB2C_delete_all_friend_value : public tag_net_message 
{   
	NET_DB2C_delete_all_friend_value ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_all_friend_value" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_role_id;  
};  

struct NET_DB2C_insert_friend_value : public tag_net_message 
{   
	NET_DB2C_insert_friend_value ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_insert_friend_value" ) ; 
		dw_size = sizeof ( * this ) ; 
	}   
	DWORD dw_role_id;  
	s_friendship_save s_friendship_save_;
};  

struct NET_DB2C_update_friend_value : public tag_net_message 
{   
	NET_DB2C_update_friend_value ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_friend_value" ) ;
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_role_id; 
	s_friendship_save s_friendship_save_;    
};  

//CMD_START(NDBS_DeleteFriend)
//	DWORD		dw_error_code;
//	DWORD		dw_role_id;
//	DWORD		dwFriendID;
//CMD_END;


//! ������
struct NET_DB2C_insert_black : public tag_net_message 
{  
	NET_DB2C_insert_black ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_insert_black" ) ;   
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_role_id; 
	DWORD dw_black_id_;  
};  

struct NET_DB2C_delete_black : public tag_net_message 
{   
	NET_DB2C_delete_black ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_delete_black" ) ;  
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_role_id;  
	DWORD dw_black_id_; 
};  

struct NET_DB2C_insert_enemy : public tag_net_message 
{  
	NET_DB2C_insert_enemy ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_insert_enemy" ) ;
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_role_id;
	DWORD dw_enemy_id_;  
};  

struct NET_DB2S_insert_enemy : public tag_net_message
{   
	NET_DB2S_insert_enemy ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_insert_enemy" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_error_code;
	DWORD dw_role_id;  
	DWORD dw_enemy_id_;  
};  

struct NET_DB2C_delete_enemy : public tag_net_message 
{   
	NET_DB2C_delete_enemy ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_enemy" ) ;
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_role_id;  
	DWORD dw_enemy_id_;   
};  

struct NET_DB2S_delete_enemy : public tag_net_message
{  
	NET_DB2S_delete_enemy ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_delete_enemy" ) ;  
		dw_size = sizeof ( * this ) ;  
	}   
	DWORD dw_error_code; 
	DWORD dw_role_id; 
	DWORD dw_enemy_id;    
};  


//! �ٱ������п�λʱ,�����ȡ����Ʒ��Ϣ
struct NET_DB2C_load_baibao : public tag_net_message 
{   
	NET_DB2C_load_baibao ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_baibao" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_account_id;  
	INT32 n_free_space_size_; 	// �ٱ����п�λ��Ŀ
	INT64 n64_serial;  // ��ȡָ��ID����Ʒ(��ָ����ΪINVALID_VALUE)
};  

struct NET_DB2S_load_baibao : public tag_net_message 
{  
	NET_DB2S_load_baibao ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_baibao" ) ;
		dw_size = sizeof ( * this ) ;    
	} 
	DWORD dw_error_code; 
	DWORD dw_account_id;  
	INT32 n_ret_num_; // ��ȡ������Ʒ(װ��)����
	BYTE by_data_[SPACE_BAIBAO_BAG * sizeof(tagEquip)]; 
};  

// ��ȡ��ҳ�콱��־
struct NET_DB2C_load_web_receive : public tag_net_message
{
	NET_DB2C_load_web_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_load_web_receive");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
};

struct NET_DB2S_load_web_receive : public tag_net_message
{
	NET_DB2S_load_web_receive()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2S_load_web_receive");
		dw_size = sizeof(*this);
	}
	DWORD	dw_account_id;
	DWORD	dw_web_receive;
};


struct NET_DB2C_load_baibao_yuanbao : public tag_net_message 
{   
	NET_DB2C_load_baibao_yuanbao ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_load_baibao_yuanbao" ) ;   
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_account_id;  
	DWORD dw_recharge_num;
};  

struct NET_DB2S_load_baobao_yuanbao : public tag_net_message
{   
	NET_DB2S_load_baobao_yuanbao ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_baobao_yuanbao" ) ;  
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_account_id; 
	INT32 n_baibao_yaunbao_;   
}; 

struct NET_DB2C_update_yuanbao_recharge : public tag_net_message
{
	NET_DB2C_update_yuanbao_recharge()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_yuanbao_recharge");
		dw_size = sizeof(NET_DB2C_update_yuanbao_recharge);
	}
	DWORD	dw_account_id;
	INT32	n32_yuanbao;
};

struct NET_DB2C_update_total_recharge : public tag_net_message
{
	NET_DB2C_update_total_recharge()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_total_recharge");
		dw_size = sizeof(*this);
	}

	DWORD		dw_account_id;
	INT32		n32_yuanbao;
};

//! �����ȡ�ٱ�����ʷ��¼
struct NET_DB2C_load_baobao_log : public tag_net_message 
{  
	NET_DB2C_load_baobao_log ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_baobao_log" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_account_id; 
};  

struct NET_DB2S_load_baibao_log : public tag_net_message
{   
	NET_DB2S_load_baibao_log ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2S_load_baibao_log" ) ; 
		dw_size = sizeof ( * this ) ; 
	}
	DWORD dw_error_code; 
	DWORD dw_account_id;  
	INT32 n_log_num_;  // ��ȡ���ļ�¼����
	BYTE by_data_[1];    // Log��¼����
};  

//! ����׷��һ����¼
struct NET_DB2C_add_baibao_log : public tag_net_message 
{   
	NET_DB2C_add_baibao_log ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_add_baibao_log" ) ;   
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_account_id; 
	tagBaiBaoRecord log_info_;  
};  

struct NET_DB2C_load_item_need_log : public tag_net_message
{  
	NET_DB2C_load_item_need_log ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_load_item_need_log" ) ;  
		dw_size = sizeof ( * this ) ; 
	} 
};  

struct NET_DB2S_load_item_need_log : public tag_net_message
{   
	NET_DB2S_load_item_need_log ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_load_item_need_log" ) ;   
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_error_code;  
	INT32 n_item_num; 
	s_need_log_item	sNeedLogItem[MAX_ITEM_NEEDLOG_NUM];
	//DWORD dw_data_id[MAX_ITEM_NEEDLOG_NUM];   
};  


//! GameServer��DBServer���͵ĳ�ʼ����ɵ�ȷ����Ϣ	
struct NET_DB2C_world_init_ok : public tag_net_message
{  
	NET_DB2C_world_init_ok ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_world_init_ok" ) ;   
		dw_size = sizeof ( * this ) ; 
	}
};  

struct NET_DB2S_world_init_ok : public tag_net_message 
{  
	NET_DB2S_world_init_ok ( ) 
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_world_init_ok" ) ; 
		dw_size = sizeof ( * this ) ;   
	}    
};  

struct NET_DB2C_clear_role_dress_mdid : public tag_net_message 
{  
	NET_DB2C_clear_role_dress_mdid ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_clear_role_dress_mdid" ) ;   
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_role_id;  
	WORD w_new_val;  
};  

//! ��ȡ��Ʒ&װ��(ѹ��������)
struct NET_DB2C_test_load_role_item : public tag_net_message
{  
	NET_DB2C_test_load_role_item ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_test_load_role_item" ) ;
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_account_id;   
	DWORD dw_role_id;     
};  

struct NET_DB2C_test_load_role : public tag_net_message
{   
	NET_DB2C_test_load_role ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_test_load_role" ) ;  
		dw_size = sizeof ( * this ) ;     
	}  
	DWORD dw_account_id;  
	DWORD dw_role_id;    
};  

//!	��������������
struct NET_DB2C_update_treasure_sum : public tag_net_message 
{   
	NET_DB2C_update_treasure_sum ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_update_treasure_sum" ) ;  
		dw_size = sizeof ( * this ) ;   
	}  
	DWORD dw_role_id;
	INT n_sum_;    
};  

struct NET_DB2S_update_treasure_sum : public tag_net_message 
{   
	NET_DB2S_update_treasure_sum ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_update_treasure_sum" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;   
	INT n_sum_;   
};  

//! ������Ҿ���
struct NET_DB2C_update_role_att : public tag_net_message
{   
	NET_DB2C_update_role_att ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_role_att" ) ;
		dw_size = sizeof ( * this ) ; 
	}  
	DWORD dw_role_id;
	INT n_type_; 
	INT n_value_;
};  

//! ����������߾���
struct NET_DB2C_clean_role_leave_exp : public tag_net_message 
{  
	NET_DB2C_clean_role_leave_exp ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_clean_role_leave_exp" ) ;
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_role_id;
};  

//! ���������������
struct NET_DB2C_clean_role_leave_brother : public tag_net_message 
{  
	NET_DB2C_clean_role_leave_brother ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_clean_role_leave_brother" ) ;  
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id;  
};  

//! ��չһ�����
struct NET_DB2C_clean_role_hang_num : public tag_net_message 
{   
	NET_DB2C_clean_role_hang_num ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_clean_role_hang_num" ) ; 
		dw_size = sizeof ( * this ) ; 
	}    
};  
// ���Ԫ���һ�����
struct NET_DB2C_clean_role_yuanbao_exchange_num : public tag_net_message
{
	NET_DB2C_clean_role_yuanbao_exchange_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_clean_role_yuanbao_exchange_num");
		dw_size = sizeof(*this);
	}
};
//! �����ż��Ϣ gx add 2013.7.3
struct NET_C2DB_clean_role_spouse_id : public tag_net_message 
{   
	NET_C2DB_clean_role_spouse_id ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_C2DB_clean_role_spouse_id" ) ; 
		dw_size = sizeof ( * this ) ; 
	}    
	DWORD dw_role_id; 
};
//! �����������
struct NET_C2DB_CleanRolePaiMaiNum : public tag_net_message
{
	NET_C2DB_CleanRolePaiMaiNum()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_CleanRolePaiMaiNum");
		dw_size = sizeof(NET_C2DB_CleanRolePaiMaiNum);
	}
};

//�����ǩ������
struct NET_C2DB_clean_role_sign_data : public tag_net_message
{
	NET_C2DB_clean_role_sign_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_sign_data");
		dw_size = sizeof(*this);
	}
};

//! �������ֵ
struct NET_C2DB_clean_role_luck : public tag_net_message
{
	NET_C2DB_clean_role_luck()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_luck");
		dw_size = sizeof(NET_C2DB_clean_role_luck);
	}

};

//! ���ӻ����ˢ�´���
struct NET_C2DB_UpdateCircleRefreshNumberAndQuestNum : public tag_net_message
{
	NET_C2DB_UpdateCircleRefreshNumberAndQuestNum()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_UpdateCircleRefreshNumberAndQuestNum");
		dw_size = sizeof(*this);
	}

	INT nDelta;
	INT nPerDayNum;
	INT nRefreshMax;
};


//! ��մݻ�װ������
struct NET_C2DB_clean_role_destroy_equip_count : public tag_net_message
{
	NET_C2DB_clean_role_destroy_equip_count()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_destroy_equip_count");
		dw_size = sizeof(NET_C2DB_clean_role_destroy_equip_count);
	}

};


//! ���Ǯׯ��������
struct NET_C2DB_clean_role_bank_num : public tag_net_message
{
	NET_C2DB_clean_role_bank_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_bank_num");
		dw_size = sizeof(NET_C2DB_clean_role_bank_num);
	}
};

// ���ս���̵깺�����
struct NET_C2DB_clean_role_exploits_num : public tag_net_message
{
	NET_C2DB_clean_role_exploits_num()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_exploits_num");
		dw_size = sizeof(*this);
	}
};

// �����Ծ������
struct NET_C2DB_clean_role_active_data : public tag_net_message
{
	NET_C2DB_clean_role_active_data()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_active_data");
		dw_size = sizeof(*this);
	}
};

// ���ÿ����������
struct NET_C2DB_clean_role_day : public tag_net_message
{
	NET_C2DB_clean_role_day()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_clean_role_day");
		dw_size = sizeof(*this);
	}
};


// ���ÿ����������
struct NET_C2DB_reset_role_value_at_0 : public tag_net_message
{
	NET_C2DB_reset_role_value_at_0()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_reset_role_value_at_0");
		dw_size = sizeof(*this);
	}
	INT nPerDayHangGetExpTimeMS;
	INT nCoolDownReviveCD;
};

// ������߽�������
struct NET_C2DB_reset_role_online_reward : public tag_net_message
{
	NET_C2DB_reset_role_online_reward()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_reset_role_online_reward");
		dw_size = sizeof(*this);
	}

	DWORD	dw_gift_id_;								// ����ID
	DWORD	dw_gift_leave_time_;						// ʣ��ʱ��

};

//! ����ÿ��1v1����
struct NET_C2DB_update_day_1v1_score : public tag_net_message
{
	NET_C2DB_update_day_1v1_score()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_update_day_1v1_score");
		dw_size = sizeof(NET_C2DB_update_day_1v1_score);
	}
};

// !����1v1�ܻ���
struct NET_C2DB_update_week_1v1_score : public tag_net_message
{
	NET_C2DB_update_week_1v1_score()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_update_week_1v1_score");
		dw_size = sizeof(*this);
	}
};

// ! ����1v1�콱��־
struct NET_C2DB_update_1v1_award : public tag_net_message
{
	NET_C2DB_update_1v1_award()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_update_1v1_award");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	INT16	n16_award;
};

// �����ɻ�
struct NET_C2DB_update_shihun : public tag_net_message
{
	NET_C2DB_update_shihun()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_C2DB_update_shihun");
		dw_size = sizeof(*this);
	}
};

//! ����������Ե�
struct NET_DB2C_update_role_att_point : public tag_net_message 
{   
	NET_DB2C_update_role_att_point ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_role_att_point" ) ;  
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_role_id;
	INT n_att_point_add_[X_ERA_ATTA_NUM];   
	INT n_att_point_left_;    
};  

//! ����������ʵ�
struct NET_DB2C_update_role_talent_point : public tag_net_message 
{   
	NET_DB2C_update_role_talent_point ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_role_talent_point" ) ;
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_role_id;
	tagRoleTalent s_talent_; 
	INT n_index_;  
	INT n_talent_point_;  
};  

//! �����ҵ�ͼ����
struct NET_DB2C_delete_role_map_limit : public tag_net_message 
{  
	NET_DB2C_delete_role_map_limit ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_delete_role_map_limit" ) ;
		dw_size = sizeof ( * this ) ;   
	}   
	INT n_type;  
};  

// �����Ҹ�������
struct NET_DB2C_delete_role_map_process : public tag_net_message
{
	NET_DB2C_delete_role_map_process()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_delete_role_map_process");
		dw_size = sizeof(*this);
	}
	INT n_type;
};

//! �Ƴ���ҵ�ͼ����
struct NET_DB2C_remove_role_map_limit : public tag_net_message 
{  
	NET_DB2C_remove_role_map_limit ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_remove_role_map_limit" ) ; 
		dw_size = sizeof ( * this ) ; 
	}   
	DWORD dw_role_id; 
};  

struct NET_DB2C_insert_role_map_limit : public tag_net_message 
{ 
	NET_DB2C_insert_role_map_limit ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_insert_role_map_limit" ) ;   
		dw_size = sizeof ( * this ) ;   
	}   DWORD dw_role_id;  
	s_enter_map_limit st_enter_map_limit_;     
};  


//! ���Ӽ���
struct NET_DB2C_add_skill : public tag_net_message 
{   
	NET_DB2C_add_skill ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_add_skill" ) ;
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_role_id;  
	s_skill_save s_skill_;  
};  

//! ���漼��
struct NET_DB2C_update_skill : public tag_net_message 
{  
	NET_DB2C_update_skill ( )
	{ 
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_skill" ) ;  
		dw_size = sizeof ( * this ) ; 
	}   
	DWORD dw_role_id;  
	s_skill_save s_skill_;  
};  


//! ɾ������
struct NET_DB2C_remove_skill : public tag_net_message 
{ 
	NET_DB2C_remove_skill ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_remove_skill" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
	DWORD dw_role_id;  
	DWORD dw_skill_id;  
};  

// �������Ԫ��ֵ
struct NET_DB2C_reset_vigour : public tag_net_message
{
	NET_DB2C_reset_vigour ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_reset_vigour" ) ; 
		dw_size = sizeof ( * this ) ;  
	} 
};

// ���½�ɫ��������
struct NET_DB2C_update_role_1v1_score : public tag_net_message
{
	NET_DB2C_update_role_1v1_score()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_role_1v1_score");
		dw_size = sizeof(*this);
	}

	DWORD	dw_role_id;
	INT		nScroe;
	INT		nJoinNum;
};

// �������߽�ɫ��������
struct NET_DB2C_update_noline_role_1v1_score : public tag_net_message
{
	NET_DB2C_update_noline_role_1v1_score()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_noline_role_1v1_score");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	INT		nScore;
};

// ������������
struct NET_DB2C_update_mounts : public tag_net_message
{
	NET_DB2C_update_mounts()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_DB2C_update_mounts");
		dw_size = sizeof(*this);
	}
	DWORD	dw_role_id;
	s_mounts_save sMounts;
};
#pragma pack(pop)
