
/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/
//服务器用物品相关结构

#pragma once

#include "../common/WorldDefine/ItemDefine.h"


#pragma pack(push, 1)

//! 容器的更新间隔时间
const INT ITEM_UPDATE_TIME		= 60 * TICK_PER_SECOND;		// 60s


//-----------------------------------------------------------------------------
//! 物品移动参数
//-----------------------------------------------------------------------------
struct s_item_move
{
	tagItem	*p_item2;		//! 目标位置上的物品
	INT16	n_num_res1;		//! 待移动物品的最终个数
	INT16	n_num_res2;		//! 目标位置上物品的最终个数
	bool	b_create_item;	//! 目标位置上的物品是否为新创建的(拆分时为true)
	bool	b_overlap;		//! 是否堆叠
	bool	b_change_pos;	//! 位置是否移动

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
//! 角色数据保存时需更新的物品数据
//-----------------------------------------------------------------------------
struct s_item_update
{
	INT64			n64_serial;
	DWORD			dw_owner_id;
	DWORD			dw_account_id;
	INT32			n_use_times;		// 物品上技能使用次数
	INT16			n16_num;			// 物品个数
	INT16			n16_index;		// 容器中位置
	BYTE			by_conType;		// 容器类型
	BYTE			by_bind;			// 绑定
	tagDWORDTime	dw_bind_time;	// 绑定时间
	DWORD			dw_script_data[2];	// 脚本数据
};

struct s_equip_spec_update
{
	INT64			n64_serial;
	tagEquipSpec	equip_spec;
};

//-----------------------------------------------------------------------------
//! IM 物品影响属性枚举
//-----------------------------------------------------------------------------
enum e_ime_effect
{
	eime_null			= 0,

	eime_color			= 1,	// 颜色
	eime_comadvance		= 2,	// 提高成功几率
	eime_protectsign	= 3,	// 保底符（强化失败时不消耗装备潜力值）
};

//-----------------------------------------------------------------------------
//! IM 物品影响
//-----------------------------------------------------------------------------
struct s_ime_effect
{
	e_ime_effect	e_effect;	// 影响类别
	DWORD			dw_param1;	// 影响值
	DWORD			dw_param2;
	s_ime_effect()
	{
		e_effect = eime_null;
		dw_param1 = 0;
		dw_param2 = 0;
	}
};



//! 获得游戏世界中全局物品相关信息
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

//CMD_START(NDBC_UpdateItemPos)	// 更新物品位置
//	DWORD		dw_account_id;
//	INT64		n64_serial;
//	DWORD		dw_role_id;
//	INT32		nUseTimes;		// 物品上技能使用次数
//	INT16		n16Num;			// 物品个数
//	INT16		n16_index;		// 容器中位置
//	BYTE		byConType;		// 容器类型
//CMD_END;


// 更新装备属性，即装备属性表
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


//CMD_START(NDBC_ReplaceItemCDTime)	// 存储物品冷却时间
//	DWORD			dw_role_id;
//	INT32			n_num;			// 个数
//	BYTE			byCDTime[1];	// tagCDTime
//CMD_END;



//! 压测专用
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
