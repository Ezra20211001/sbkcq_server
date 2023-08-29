
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//服务器用宠物相关结构

#pragma once
#include "../../common/WorldDefine/pet_define.h"
#include "../../common/WorldDefine/ItemDefine.h"
#pragma pack(push, 1)

const INT MAX_CALLED_PET_NUM		= 1;	// 最多召唤宠物数量

const INT SPIRIT_RESUME_COUNT		= 10 * TICK_PER_SECOND;	// 生命流失时间

const INT CHANGEEXP_RESUME_COUNT	= TICK_PER_SECOND * 60;		// 亲密度变化计数
const INT CHANGEEXP_VALUE			= 5;						//每次亲密度变化的值

const INT HAPPY_RESUME_COUNT		= 20 * TICK_PER_SECOND ;//心情变化计数

const INT SAD_RESUME_COUNT			= 20 * TICK_PER_SECOND;		//伤心计时



enum e_pet_att
{
	epa_null				=-1,
	epa_begin				= 0,

	epa_quality				= 0,	//品质	1~5品，决定灵兽的资质、天赋技能数量、天赋计数	天赋技能共有五种，用于额外产出收益，促进灵力消耗
	epa_aptitude			= 1,	//资质	决定灵兽的灵力成长，决定初始潜能	取值1~100，具体取决于品质
	epa_spirit				= 2,	//生命	
	epa_talent_count		= 3,	//天赋计数	
	epa_potential			= 4,	//潜能	学习技能时消耗该值，类似装备潜力值	初始潜能=资质×10
	epa_wuxing_energy		= 5,	//五行力	当灵兽使用技能时，可以储存该值，在施展天赋技能时消耗该值	技能对应的五行值在宠物技能表中填写
	epa_mount_num			= 6,	//骑乘人数
	epa_addon_begin			= 7,

	epa_spirit_max			= 7,	//最大生命= 30000*1.2^n
	epa_talent_count_max	= 8,	//天赋计数最大值	用于当天的天赋技能使用次数计数，每天重置；当计数达到最大值时，不可使用天赋技能	品质白=1，品质黄=2，品质绿=3，品质蓝=4，品质橙=5 天赋计数=阶＋品质×3
	epa_bag_grid			= 9,	//行囊格数	使用相关技能时，灵兽能运载物品的数量	默认4，装备加成2~16
	epa_delivery_consume	=10,	//快递耗时	使用快递技能时，灵兽工作的时间缩放	默认0，装备加成-？~0：ms，对应技能表“工作时间”（降低5秒，填-5000）
	epa_sell_consume		=11,	//贩卖耗时	使用贩卖技能时，灵兽工作的时间缩放	默认0，装备加成-？~0：ms，对应技能表“工作时间”
	epa_storage_consume		=12,	//存放耗时	使用存放技能时，灵兽工作的时间缩放	默认0，装备加成-？~0：ms，对应技能表“工作时间”
	epa_gather_consume		=13,	//采集耗时	使用采集技能时，灵兽工作时间缩放	默认0，装备加成-？~0：ms，对应技能表“工作时间”
	epa_train_resume		=14,	//训练恢复	灵兽的自动训练技能的恢复时间缩放	默认0，装备加成-？~0：ms，对应技能表“恢复时间”
	epa_spirit_rate			=15,	//灵力消耗	(0-1 0-10000)使用技能时的灵力消耗缩放比	默认100%，装备加成-100%~0%，对应技能表energy_cost
	epa_exp_rate			=16,	//经验加成	(0-1 0-10000)获得经验时的缩放比	默认100%，装备加成0%~400%
	epa_pick_up_resume		=17,	//拾取恢复	降低灵兽拾取的恢复时间	默认0，装备加成-20~-1
	epa_medicine_saving		=18,	//吃药节省	(0-1 0-10000)宠物每次喂药时可能不消耗该药品	默认0%，装备加成1%~5%
	epa_strength_effect		=19,	//强身效果	(0-1 0-10000)提升强身类技能的效果	默认100%，装备加成0%~400%
	epa_wuxing_consume		=20,	//五行力消耗	(0-1 0-10000)当使用天赋技能时，降低该技能对五行力的需求	默认100%，装备加成-50%~0%，对应技能表“五行力消耗”
	epa_mount_speed			=21,	//骑乘速度	(0-1 0-10000)灵兽被驾御时的移动速度	默认白30%，黄40%，绿50%，蓝60%，橙70% 装备加成0%~100%	受阶影响
	epa_mount_num_max		=22,	//骑乘人数
	epa_happy_value			=23,	//开心度 
	epa_color				=24,	//颜色
	epa_strength			=25,	//附加角色力量
	epa_agility				=26,	//附加角色敏捷
	epa_innerForce			=27,	//附加角色智力
	epa_att_point			=28,	//属性点

	epa_addon_end			=29,

	epa_end					=29,
};

const INT EPA_NUM		= epa_end - epa_begin;


#define IS_EPA(n)		( (n) >= epa_begin && (n) < epa_end )
#define IS_EPA_ADDON(n)	( (n) >= epa_addon_begin && (n) < epa_addon_end )

#define EPATOEPAAO(n)	( INT((n) - epa_addon_begin) )

#define PET_RANDOM_SKILL_NUM	5
#define PET_RANDOM_Specialty	5

//! 宠物属性默认值
struct s_pet_def_min_max
{
	INT		n_def;
	INT		n_min;
	INT		n_max;
};


//! 宠物灵魂创建数据
struct s_db_pet_soul_create
{
	TCHAR	sz_name_[X_SHORT_NAME];	// 宠物名称
	INT		n_quality_;				// 品质
	INT		n_aptitude_;			// 资质
	INT		n_potential_;			// 当前潜能 
	INT		n_spirte_;				// 当前灵力
//	BOOL	bMountable;				// 能否骑乘

	DWORD	dw_proto_id;			// 原型ID
	DWORD	dw_master_id;			// 主人ID
	s_db_pet_soul_create()	{ZeroMemory(this, sizeof(*this));}
};


//! 宠物灵魂数据
struct s_db_pet_att
{
	DWORD	dw_pet_id_;				// 宠物ID
	TCHAR	sz_name_[X_SHORT_NAME];	// 宠物名称
	DWORD	dw_proto_id_;			// 原型ID
	DWORD	dw_master_id_;			// 主人ID

	INT		n_quality_;				// 品质
	INT		n_aptitude_;			// 资质
	INT		n_potential_;			// 当前潜能 
	INT		n_spirit_;				// 当前灵力
	INT		n_wuxing_energy_;		// 五行力
	INT		n_talent_count_;		// 天赋计数
	BYTE	by_pet_state_;				// 灵兽状态

	INT		n_exp_cur_;				// 当前经验
	INT		n_step_;				// 阶
	INT		n_grade_;				// 等
	INT		n_rename_count_;		// 改名次数
	BOOL	b_locked_;				// 是否锁定
	INT		n_happy_value_;			// 开心度
	INT		n_color;				// 颜色
	INT		n_strength;				// 附加角色力量
	INT		n_agility;				// 附加角色敏捷
	INT		n_innerForce;			// 附加角色智力
	INT		n_att_point;			// 属性点
	DWORD	dw_time_type;			// 寄养时间类型
	DWORD	dw_mode_type;			// 寄养模式类型
	DWORD	dw_xiulian_time;		// 寄养时间

	s_db_pet_att()	{ZeroMemory(this, sizeof(*this));}
};

//! 宠物技能数据
struct s_db_pet_skill
{
	DWORD	dw_data_id;				// 原型id
	INT		n_para1_;				// 冷却计时
	INT		n_para2_;				// 使用计时
	s_db_pet_skill()	{ZeroMemory(this, sizeof(*this));}
};

//! 宠物加载数据
struct s_db_pet
{
	s_db_pet_att	pet_att;			// 宠物属性
	INT				n_pet_skill_num;	// 宠物技能
	INT				n_pet_equip_num;	// 宠物装备
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

//! 宠物随机技能表
struct s_pet_skill_list
{
	DWORD	dw_id;
	
	//普通技能
	std::vector<DWORD>	vec_normal;
	//buff技能
	std::vector<DWORD>	vec_buff;
	//特长(也是技能)
	std::vector<DWORD>	vec_specialty;
	//主动技能
	std::vector<DWORD>	vec_Action;
};


//! 创建PetSoul
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

//! 加载Pet
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


//! 更新PetSoul
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


//! 删除PetSoul
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


//! 宠物装备添加删除
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



//! 插入宠物技能
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

//! 删除宠物技能
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

// 加载sns信息
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

// 插入sns信息
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

// 删除sns信息
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