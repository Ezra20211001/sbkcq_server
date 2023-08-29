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
*	@file		compose_protocol.h
*	@author		lc
*	@date		2011/03/01	initial
*	@version	0.0.1.0
*	@brief		装备强化，合成消息
*/

#ifndef COMPOSE_PROTOCOL
#define COMPOSE_PROTOCOL

#include "protocol_common_errorcode.h"
#include "compose_define.h"

#pragma pack(push, 1)

//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum 
{
	//共有错误码
	E_Compose_NPC_Not_Exist = 1, 				//NPC不存在
	E_Compose_Formula_Not_Exist = 2, 			//配方不存在
	E_Compose_Stuff_Not_Enough = 3, 			//材料数量不够
	E_Compose_Stuff_Formula_Not_Match = 4, 		//材料和配方不匹配
	E_Compose_NPC_Distance = 5,					//NPC距离太远
	E_Compost_MustItem_Not_Exit = 6,			//合成必须品不存在
	E_Compose_UpQuality_Not_enough = 7,			//提升概率道具数量不足

	//合成强化返回的三种结果,是根据合成公式算的
	E_Compose_Consolidate_Success = 11, 		//成功
	E_Compose_Consolidate_Lose = 12, 			//失败
	E_Compose_Consolidate_Perfect = 13, 		//完美


	//合成错误码
	E_Compose_OutOf_Vip_Level = 19,
	E_Compose_Stuff_Pro_Not = 20, 				//概率不到1%不能合成
	E_Compose_Stuff_Not_Exist = 21, 			//合成材料不存在
	E_Compose_Type_Not_Exist = 22,				//合成类型不存在
	E_Compose_Skill_Not_Exist = 23,				//玩家没有合成技能
	E_Compose_FormulaNotMatch = 24,				//合成配方不匹配
	E_Compose_NPCCanNotCompose = 25,			//不是合成NPC
	E_Compose_Skill_Not_Same = 26,				//技能和宝盒等级不符
	E_Compose_NotEnough_Money = 27,				//玩家金钱不够
	E_Compose_Bag_Full = 28,					//背包已满
	E_Compose_Item_NotFind = 29,				//图纸不存在
	E_Compose_FormulaID_NotExit=30,				//图纸配方ID不符

	//分解错误码
	E_Decomposition_Item_Not_Exist = 31, 		//分解物品不存在
	E_Decomposition_Pet_NOt		   = 32, 		//没有宠物

	//镶嵌错误码
	E_Consolidate_Equip_Not_Exist = 41, 		//强化装备不存在
	E_Consolidate_Type_Not_Exist,				//强化类型不存在
	E_Consolidate_NPCCanNotPosy,				//不是铭纹NPC
	E_Consolidate_NotEquipment,					//强化的物品不是装备
	E_Consolidate_BeyondPosyTime,
	E_Consolidate_FormulaNotMatch,				//强化配方不匹配
	E_Consolidate_NotEnough_Money,				//玩家金钱不够
	E_Consolidate_NotEnough_Stuff,				//玩家材料不够
	E_Consolidate_EquipCanNotPosy,				//该属性不能被铭纹
	E_Consolidate_ValConsume_Inadequate,		//装备潜力值不足
	E_Consolidate_Param_Not_Find,				//参数表没有

	E_Compose_NPCCanNotEngrave = 61,			//不是镌刻NPC
	E_Consolidate_EquipCanNotEngrave,			//该属性不能被镌刻
	E_Consolidate_BeyondEngraveTime,			//超过镌刻次数

	E_Consolidate_Gem_Not_Exit = 81,			//宝石不存在
	E_Consolidate_Gem_Full,						//装备已镶满宝石
	E_Consolidate_EquipCanNotInlay,				//该宝石不能被镶嵌
	E_Consolidate_Gem_Not_Hole,					//装备无孔
	E_Hole_NPCCanNot_Exit,						//不是打孔NPC
	E_Hole_FormulaParam_Not_Exit,				//打孔公式参数不存在
	E_Hole_NotEnough_Money,						//打孔没有足够的金钱
	E_Consolidate_Gem_level_not,				//宝石等级不符

	E_Consolidate_Brand_Not_Exit = 101,			//印记不存在
	E_Consolidate_Brand_TopLevel,				//印记等级达到上限
	E_Consolidate_EquipCanNotBrand,				//该装备不能被印记

	E_Consolidate_NPCCanNotQuench = 121,		//不是淬火NPC
	E_Consolidate_WXValueInadequate,			//原属性值不足
	E_Consolidate_False,						//淬火失误

	E_Compose_Quality_Not_Match = 131,			//点化只限于黄色及以上装备
	E_Compose_Not_Fashion,						//面具及时装不可点化或分解
	E_Compose_Equip_Lock,						//已锁定的装备不可点化或分解
	E_Compose_Equip_Time_Limit,					//有时间限制的装备不可点化或分解
	E_Compose_Equip_Not_identify,				//未鉴定的装备不可点化或分解
	E_Compose_Equip_Level_Inadequate,			//装备等级不够
	E_Compose_Equip_Quality_Inadequate,			//装备品质不够
	E_Compose_Equip_Type_Inadequate,			//装备类型不满足配方要求
	E_Compose_Equip_Posy,						//装备是铭刻绑定的
	E_Compose_Equip_Bind,						//npc绑定,绑定石绑定不可分解

	E_Consolidate_Chisel_Not_Exit = 151,		//凿石不存在
	E_Consolidate_Equip_CanNot_Chisel,			//装备不能被开凿
	E_Consolidate_Equip_Hole_Full,				//镶嵌孔数量已为5个，不可进行开凿
	E_Consolidate_Chisel_Not_Match,				//凿石等级小于所开凿的装备等级，不可进行开凿
	E_Consolidate_NotIdentified,				//未鉴定装备不可开凿
	E_Consolidate_EquipLevel_Not,				//装备等级不符
	E_Consolidate_Shipingqu_Not,				//时装翅膀不可打孔镶嵌

	E_Repair_NPCCanNotRepair = 161,				//不是维修NPC
	E_Repair_EquipItem_Not_Exit,				//维修物品不存在
	E_Repair_EquipItem_Not_Repair,				//不是维修物品
	E_Repair_Equip_Not_Exist,					//维修装备不存在
	E_Repair_NotEquipment,						//维修装备不是装备
	E_Repair_Num_Not_Inadequate,				//维修物品不足
	E_Repair_Quality_Not_Out,					//超出维修品质
	E_Repair_NotEnough_Money,					//维修金额不足
	E_Repair_NoMall_Item,						//维修物品不是商城物品
	E_Repair_NotRepair,							//装备不用维修

	E_Unbeset_NPCCanNot_Exit = 181,				//拆嵌NPC不存在
	E_Unbeset_BesetItem_Not_Exit,				//镶嵌物品不存在
	E_Unbeset_Item_Not_Exit,					//拆嵌道具不存在
	E_Unbeset_FormulaParam_Not_Exit,			//拆嵌公式不存在
	E_Unbeset_Not_Money,						//金钱不足
	E_Unbeset_Not_bag_free,						//背包空间不足

	E_ShengXing_CanNot = 201,					//装备不能升星
	E_ShengXingItem_Not_Exit,					//升星所需强化石不存在
	E_ShengXing_Abort,							//升星失败
	E_ShengXing_Item_Error,						//强化石不符合要求
	E_ShengXing_Param_Not_Find,					//强化参数未找到
	E_ShengXing_NotEnough_Money,				//强化金钱不足
	E_ShengXing_BingNot,						//强化石与绑定类型不符
	E_ShengXing_NumError,						//神石数量不符
	E_ShengXing_Type_Error,						//强化石类型不符

	E_ShengXing_Baohu_not_bind,					//没有用绑定石不能使用保护石
	E_ShengXing_Baohu_Not_Find,					//保护石不存在
	E_ShengXing_Baohu_level_error,				//保护石等级不符

	E_Fusion_NPCCanNot_Exist = 221,				//不是融合NPC
	E_Fusion_Equip1_Not_Exist,					//被融合的装备1未找到
	E_Fusion_Equip2_Not_Exist,					//被融合的装备2未找到
	E_Fusion_NotEquipment1,						//物品1不是武器
	E_Fusion_NotEquipment2,						//物品2不是武器
	E_Fusion_Level_Not_Exist,					//武器1的等级小于武器2
	E_Fusion_Talent_Not_Exist,					//武器天赋不符
	E_Fusion_NotEnough_Money,					//融合金钱不足
	E_Fusion_Equip1Level_low,					//材料武器等级太低
	E_Fusion_EquiplevelUp_NotFind,				//装备等级经验数据未找到
	E_Fusion_Level_low,							//人物等级不够
	E_Fusion_Class_Not_Exist,					//职业不符

	E_Prictice_NotFind_Equip = 241,				//修炼装备不存在
	E_Prictice_Not_Weapon,						//修炼装备不是武器
	E_Prictice_Not_State,						//当前状态不可修炼
	E_Prictice_Brotherhood_Not,					//义气值不够
	E_Prictice_Level_Max,						//武器等级上限
	E_Prictice_Speed_item_Error,				//加速道具非法或数量不足
	E_Prictice_Speed_item_level_Error,			//加速道具等级不符

	E_Weapon_LearnSkill_NotFind = 261,			//装备不存在
	E_Weapon_LearnSKill_NotWeapon,				//不是武器
	E_Weapon_LearnSkill_NotEquip,				//武器没装备上
	E_Weapon_LearnSKill_NotSkill,				//技能不存在
	E_Weapon_LearnSkill_Existed,				//装备上已有该技能
	E_Weapon_LearnSkill_TalentNot,				//装备和技能天赋类型不符
	E_Weapon_LearnSkill_MustPassive,			//只有被动技能能加上
	E_Weapon_LearnSkill_NoPreSkill,				//没有前置技能
	E_Weapon_LearnSkill_NeedMoreTalentPoint,	//还需更多的天赋点
	E_Weapon_LearnSkill_NoTalentPoint,			//天赋点不足
	E_Weapon_LearnSkill_RoleExisted,			//玩家身上已有该技能
	E_Weapon_LearnSkill_FullSkillList,			//装备技能已满
	E_Weapon_LevelUpSkill_NotExisted,			//装备上没有该技能
	E_Weapon_LevelUpSkill_RoleNoExisted,		//玩家没该技能	
	E_Weapon_ClearTalent_NoEquip,				//装备未找到
	E_Weapon_ClearTalent_NotWeapon,				//不是武器
	E_Weapon_ClearTalent_NoItem,				//洗点道具没找到
	E_ClearTalent_ItemNotValid,					//物品本身是不是洗点道具
	E_Weapon_Clear_Not_clear,					//武器不需要洗点
	E_Weapon_LearnSkill_NeedMoreLevel,			//人物等级不够

	E_Equip_Bind_NotFind	=	300,			//绑定装备部存在
	E_Equip_Bind_ItemNotFind,					//绑定道具不存在
	E_Equip_Bind_ItemTypeError,					//绑定道具类型不符
	E_Equip_Bind_NPC_Error,						//绑定NPC错误
	E_Equip_UnBind_ItemNotFind,					//解除绑定道具不存在
	E_Equip_UnBind_SystemBind,					//系统绑定不能解绑
	E_Equip_Bind_Not_bind,						//无法绑定 已经绑定石绑定了或该物品有时限
	E_Equip_UnBind_Not_UnBind,					//已经在解绑中
	E_Equip_Bind_IS_Fashion,					//时装不能绑定解绑
	E_Equip_UnBind_IS_Level,					//已经注入神魂的武器不可进行道具解绑操作

	E_Equip_Reatt_NotFind = 320,				//装备部存在
	E_Equip_Reatt_Not_Quality3,					//不是紫装
	E_Equip_Reatt_NotEnough_Money,				//元宝不足
	E_Equip_Reatt_Index_Not,					//不能重置该属性
	E_Equip_Reatt_level_not,					//45级以上的装备才能洗属性
	E_Equip_Reatt_is_Picture_Mod,				//图纸打造的装备不能重置
	E_Equip_Reatt_item_Not_find,				//重置属性道具不存在
	E_Equip_Reatt_item_Type_Not,				//重置属性道具类型不符
	E_Equip_Reatt_item_Level_Not,				//重置属性道具等级不符
	E_Equip_Reatt_Star_not,						//重置属性强化等级不符

	E_Role_No_Prictice_State = 340,				// 角色不在修炼状态
	E_Role_LeavePrictice_Area_Limit,			// 离线修炼区域限制
	E_Role_LeavePricitice_level_limit,			// 离线修炼等级限制
	E_Role_LeavePricitice_love_limit,			// 离线修炼爱心值限制
	E_Role_LeavePricitice_TimeType_Not,			// 离线修炼时间类型非法
	E_Role_LeavePricitice_MulType_Not,			// 离线修炼倍数类型非法
	E_Role_LeavePricitice_RedName_limit,		// 红名不能使用离线修炼

	E_Role_Weapon_Kaiguang_Not_Find = 360,		// 武器不存在
	E_Role_Weapon_Kaiguang_Not_Con,				// 条件不符
	E_Role_Weapon_Kaiguang_Not_Role_level,		// 角色等级不符
	E_Role_Weapon_Kaiguang_Not_goon,			// 已经不能再开光了
	E_Role_Weapon_Kaiguang_NotEnough_Money,		// 金币不足

	E_Role_Equip_xili_quality_not = 380,		// 必须是绿色以上
	E_Role_Equip_xili_level_not,				// 必须是30级以上装备	
	E_Role_Equip_xili_product_picture,			// 图纸打造装备不能洗礼
	E_Role_Equip_xili_Not_enough_cur,			// 战功不足
	E_Role_Equip_xili_All_full,					// 所有属性最大
	E_Role_Equip_xili_Not_enough_yuanbao,		// 紫金币不足
	E_Role_Equip_xili_role_level_not,			// 角色等级不足
	E_Role_Equip_xili_OutOfTimes,				// 洗礼次数限制

	E_Role_Equip_Wuhuen_Not_Count = 390,		// 当天提取上限
	E_Role_Equip_Wuhuen_Outof_yuanbao = 391,	// 元宝不足

	E_Role_Equip_ronglian_level_max = 400,		// 武器等级上限
	E_Role_Equip_ronglian_not_wuhuen,			// 武魂不够


	E_Role_change_petxiulian_not_monery = 410,	// 金钱不足
	E_Role_change_petxiulian_max,				// 最大了

	E_Role_yuanshi_damo_NPC_NOT			= 500,	// npc不符
	E_Role_yuanshi_damo_not_yuanshi		= 501,	// 不是原石不能打磨
	E_Role_yuanshi_damo_not_silver		= 502,	// 金钱不足
	E_Role_yuanshi_damo_error			= 503,	// 添加物品失败
};

#define LEAVE_PRICTICE_LEVEL	30			// 离线修炼等级

//-----------------------------------------------------------------------------
//	合成消息
//-----------------------------------------------------------------------------
struct NET_SIC_produce : public tag_net_message
{
	NET_SIC_produce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_produce");
		dw_size = sizeof(NET_SIC_produce);
	}
	DWORD 				dwNPCID; 		//NPCID
	//DWORD				dwSkillID;		//技能ID
	//INT64				n64ItemID;		//物品ID
	DWORD 				dwFormulaID;  	//配方ID
	//INT64				n64IMID;		//IMid
	//BOOL				bBind;			//是否生成绑定物品
	//BYTE				byUseUpQualityItem;//提升品质概率物品 -1:不使用 0:白 1:绿 2：蓝 3:紫 4：橙
	//BYTE				byQualityNum;	//提升概率物使用数量
	//DWORD				byYuanBao;		//炼丹使用元宝数量
	//DWORD				dw_safe_code;
	//INT64				n64StuffID[1]; 	//材料 数量变长
};

struct NET_SIS_produce : public tag_net_message
{
	NET_SIS_produce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_produce");
		dw_size = sizeof(NET_SIS_produce);
	}
	DWORD				dw_error_code;	//返回码
};

//-----------------------------------------------------------------------------
//	分解消息 属于点化技能中的一个分支
//-----------------------------------------------------------------------------
struct NET_SIC_decomposition : public tag_net_message
{
	NET_SIC_decomposition()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_decomposition");
		dw_size = sizeof(NET_SIC_decomposition);
	}
	DWORD				dwNPCID; 		//NPCID	
	DWORD				dwSkillID;		//技能ID
	INT64				n64ItemID;		//物品ID
	DWORD				dwFormulaID;	//配方ID
	INT64				n64IMID;		//IMid
	INT64				n64Item; 		//被分解物品64位ID
	BOOL				bPetDec;		//是否是宠物拆分
};

struct NET_SIS_decomposition : public tag_net_message
{
	NET_SIS_decomposition()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_decomposition");
		dw_size = sizeof(NET_SIS_decomposition);
	}
	DWORD				dw_error_code;	//返回码
	INT					nStuffIndex[1];	//分解材料索引
};

//-----------------------------------------------------------------------------
//	强化消息
//-----------------------------------------------------------------------------
struct NET_SIC_consolidate_posy : public tag_net_message
{
	NET_SIC_consolidate_posy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_consolidate_posy");
		dw_size = sizeof(NET_SIC_consolidate_posy);
	}
	DWORD 				dwNPCID; 		//NPCID
	DWORD 				dwFormulaID;  	//配方ID
	INT64 				n64ItemID; 		//要被强化物品的64位ID
	INT64				n64IMID;		//IMid
	INT64				n64StuffID[1]; 	//材料 数量变长	
};

struct NET_SIS_consolidate_posy : public tag_net_message
{
	NET_SIS_consolidate_posy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_consolidate_posy");
		dw_size = sizeof(NET_SIS_consolidate_posy);
	}
	DWORD				dw_error_code;	//返回码
};

struct NET_SIC_consolidate_engrave : public tag_net_message
{
	NET_SIC_consolidate_engrave()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_consolidate_engrave");
		dw_size = sizeof(NET_SIC_consolidate_engrave);
	}
	DWORD				dwNPCID;		//NPCID
	DWORD				dwFormulaID;	//配方ID
	INT64				n64ItemID;		//要被强化物品的64位ID
	INT64				n64IMID;		//IMID
	INT64				n64StuffID[1];	//材料 
};

struct NET_SIS_consolidate_engrave : public tag_net_message
{
	NET_SIS_consolidate_engrave()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_consolidate_engrave");
		dw_size = sizeof(NET_SIS_consolidate_engrave);
	}
	DWORD				dw_error_code;	//返回码
};

struct NET_SIC_consolidate_quench : public tag_net_message
{
	NET_SIC_consolidate_quench()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_consolidate_quench");
		dw_size = sizeof(NET_SIC_consolidate_quench);
	}
	DWORD				dwNPCID;		//NPCID
	DWORD				dwFormulaID;	//配方ID
	INT64				n64ItemID;		//要被强化物品的64位ID
	INT64				n64IMID;		//IMID
	INT64				n64StuffID[1];	//材料 
};

struct NET_SIS_consolidate_quench : public tag_net_message
{
	NET_SIS_consolidate_quench()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_consolidate_quench");
		dw_size = sizeof(NET_SIS_consolidate_quench);
	}
	DWORD				dw_error_code;	//返回码
};

//升星
struct NET_SIC_shengxing : public tag_net_message
{
	NET_SIC_shengxing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_shengxing");
		dw_size = sizeof(NET_SIC_shengxing);
	}
	INT64	n64SerialEquip;		//装备
	DWORD	dwNPCID;			//NPCID
	INT64	n64ShengXingItem;	//升品物品(强化石)
	DWORD	dwStuffID;			//提升概率物品(神石)
	INT		nStuffNum;			//使用的提升几率物品数量
	BOOL	bBind;				//是否是绑定的
	INT64	n64BaohuItem;		//保护石
	DWORD	dw_safe_code;
};

struct NET_SIS_shengxing : public tag_net_message
{
	NET_SIS_shengxing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_shengxing");
		dw_size = sizeof(NET_SIS_shengxing);
	}
	INT64	n64SerialEquip;
	DWORD	dw_error_code;
};


//-----------------------------------------------------------------------------
//	镶嵌
//-----------------------------------------------------------------------------
struct NET_SIC_inlay : public tag_net_message
{
	NET_SIC_inlay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_inlay");
		dw_size = sizeof(NET_SIC_inlay);
	}
	INT64				n64DstItemID;	//装备的64ID
	INT64				n64SrcItemID[MAX_EQUIPHOLE_NUM];	//宝石的64ID
};

struct NET_SIS_inlay : public tag_net_message
{
	NET_SIS_inlay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_inlay");
		dw_size = sizeof(NET_SIS_inlay);
	}
	DWORD				dw_error_code;	//返回码
};

//开凿
struct NET_SIC_chisel : public tag_net_message
{
	NET_SIC_chisel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_chisel");
		dw_size = sizeof(NET_SIC_chisel);
	}
	INT64				n64SrcItemID;	//装备的64ID
	DWORD 				dwNPCID; 		//NPCID
	INT64				n64StuffID;		//打孔石
};

struct NET_SIS_chisel : public tag_net_message
{
	NET_SIS_chisel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_chisel");
		dw_size = sizeof(NET_SIS_chisel);
	}
	DWORD				dw_error_code;	//返回码
};

//拆嵌
struct NET_SIC_unbeset : public tag_net_message
{
	NET_SIC_unbeset()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_unbeset");
		dw_size = sizeof(NET_SIC_unbeset);
	}
	INT64		n64SerialEquip;		//装备
	DWORD		dwNPCID;			//NPCID
	BYTE		byUnBesetPos;		//需要拆除的镶嵌物品位置
	//INT64		n16SerialUnBesetItem;		//拆嵌物品
	//INT64		n64StuffID;		//保底物品
	//BYTE		byYuanBaoNum;	//元宝数量
};

struct NET_SIS_unbeset : public tag_net_message
{
	NET_SIS_unbeset()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_unbeset");
		dw_size = sizeof(NET_SIS_unbeset);
	}
	DWORD		dw_error_code;
};

// 原石打磨
struct NET_SIC_damo : public tag_net_message
{
	NET_SIC_damo()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_damo");
		dw_size = sizeof(NET_SIC_damo);
	}
	
	DWORD		dwItemID;		//原石id
	DWORD		dwNumber;		//数量
	DWORD 		dwNPCID; 		//NPCID

};

struct NET_SIS_damo : public tag_net_message
{
	NET_SIS_damo()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_damo");
		dw_size = sizeof(NET_SIS_damo);
	}

	DWORD		dw_error_code;		// 错误码

};


//---------------------------[12/1/2010 Administrator]
//武器修炼
//---------------------------
//开始修炼 领悟武魂
struct NET_SIC_practice_begin : public tag_net_message
{
	NET_SIC_practice_begin()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_practice_begin");
		dw_size = sizeof(NET_SIC_practice_begin);
	}
	INT64		n64SerialEquip;			//武器
	DWORD		dw_speed_item_data_id[MAX_XIULIAN_ITEM_NUMBER];	//加速道具dataId
	DWORD		dw_speed_item_number[MAX_XIULIAN_ITEM_NUMBER];	//加速道具数量
};

struct NET_SIS_practice_begin : public tag_net_message
{
	NET_SIS_practice_begin()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_practice_begin");
		dw_size = sizeof(NET_SIS_practice_begin);
	}
	DWORD		dw_error_code;
};

//停止修炼
struct NET_SIC_parctice_end : public tag_net_message
{
	NET_SIC_parctice_end()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_parctice_end");
		dw_size = sizeof(NET_SIC_parctice_end);
	}
};

struct NET_SIS_parctice_end : public tag_net_message
{
	NET_SIS_parctice_end()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_parctice_end");
		dw_size = sizeof(NET_SIS_parctice_end);
	}
	DWORD		dw_error_code;
};

// 设置离线修炼
struct NET_SIC_leave_parcitice : public tag_net_message
{
	NET_SIC_leave_parcitice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_parcitice");
		dw_size = sizeof(NET_SIC_leave_parcitice);
	}

	BYTE	byTimeType;			// 离线修炼时间类型 1. 2小时 2. 3小时 3. 8小时 4. 12小时
	BYTE	byMulType;			// 离线修炼倍数		1. 1倍  2. 2倍  3. 4倍  4. 6倍  5. 8倍
};

struct NET_SIS_leave_parcitice : public tag_net_message
{
	NET_SIS_leave_parcitice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_leave_parcitice");
		dw_size = sizeof(NET_SIS_leave_parcitice);
	}

	DWORD	dw_error;
};

//武器融合
struct NET_SIC_fusion : public tag_net_message
{
	NET_SIC_fusion()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_fusion");
		dw_size = sizeof(NET_SIC_fusion);
	}
	INT64		nEquip1;	//旧武器
	INT64		nEquip2;	//新武器
	INT64		n64ItemID;	//不消耗义气值
	DWORD		dw_safe_code;
};

struct NET_SIS_fusion : public tag_net_message
{
	NET_SIS_fusion()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_fusion");
		dw_size = sizeof(NET_SIS_fusion);
	}
	DWORD		dw_error_code;
};


//武器洗天赋点
struct NET_SIC_weapon_clear_talent : public tag_net_message
{
	NET_SIC_weapon_clear_talent()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_weapon_clear_talent");
		dw_size = sizeof(NET_SIC_weapon_clear_talent);
	}
	//INT64		n64EquipID;				// 装备ID
	INT64		n64ItemID;				// 使用的道具
};

struct NET_SIS_weapon_clear_talent : public tag_net_message
{
	NET_SIS_weapon_clear_talent()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_weapon_clear_talent");
		dw_size = sizeof(NET_SIS_weapon_clear_talent);
	}
	//INT64		n64EquipID;				// 装备ID
	DWORD		dw_error_code;			// 错误码
};


//装备绑定
struct NET_SIC_equip_bind : public tag_net_message
{
	NET_SIC_equip_bind()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_bind");
		dw_size = sizeof(NET_SIC_equip_bind);
	}
	INT64		n64EquipID;				//装备ID ::= -1 npc绑定所有身上装备
	INT64		n64ItemID;				//绑定道具ID ::= -1是说明用npc绑定
	DWORD		dwNPCID;				//NPCID ::=0时说明用道具绑定
};

struct NET_SIS_equip_bind : public tag_net_message
{
	NET_SIS_equip_bind()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_bind");
		dw_size = sizeof(NET_SIS_equip_bind);
	}
	INT64		n64EquipID;
	EBindStatus	eBindType;	
	DWORD		dw_error_code;
};


//装备解绑
struct NET_SIC_equip_unbind : public tag_net_message
{
	NET_SIC_equip_unbind()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_unbind");
		dw_size = sizeof(NET_SIC_equip_unbind);
	}
	INT64		n64EquipID;				//装备ID
	INT64		n64ItemID;				//解除绑定道具ID
};

struct NET_SIS_equip_unbind : public tag_net_message
{
	NET_SIS_equip_unbind()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_unbind");
		dw_size = sizeof(NET_SIS_equip_unbind);
	}
	INT64		n64EquipID;	
	DWORD		dw_error_code;
};

//装备重置属性
struct NET_SIC_equip_reatt : public tag_net_message
{
	NET_SIC_equip_reatt()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_reatt");
		dw_size = sizeof(NET_SIC_equip_reatt);
	}
	INT64		n64EquipID;				//装备ID
	INT64		n64ItemID;				//重置道具id
	BYTE		byIndex;				//哪个属性
	BYTE		byType;					//重置类型 0:只用钱 1:用一半钱和道具 2: 只用道具重置3条属性
	DWORD		dwNPCID;				
};

struct NET_SIS_equip_reatt : public tag_net_message
{
	NET_SIS_equip_reatt()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_reatt");
		dw_size = sizeof(NET_SIS_equip_reatt);
	}
	INT64		n64EquipID;	
	DWORD		dw_error_code;
};


//武器开光
struct NET_SIC_equip_kaiguang : public tag_net_message
{
	NET_SIC_equip_kaiguang()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_kaiguang");
		dw_size = sizeof(NET_SIC_equip_kaiguang);
	}
	INT64		n64EquipID;	
};

struct NET_SIS_equip_kaiguang : public tag_net_message
{
	NET_SIS_equip_kaiguang()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_kaiguang");
		dw_size = sizeof(NET_SIS_equip_kaiguang);
	}
	INT64		n64EquipID;	
	DWORD		dw_error_code;
};

//装备洗礼
struct NET_SIC_equip_xili : public tag_net_message
{
	NET_SIC_equip_xili()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_xili");
		dw_size = sizeof(NET_SIC_equip_xili);
	}
	INT64		n64EquipID;	
	DWORD		dwType;		//种类0:战功  1:紫金币2   2:紫金币10
};

struct NET_SIS_equip_xili : public tag_net_message
{
	NET_SIS_equip_xili()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_xili");
		dw_size = sizeof(NET_SIS_equip_xili);
	}
	INT64		n64EquipID;	
	INT32		EquipAttitional[MAX_RAND_ATT];	//替换后的属性
	DWORD		dw_error_code;
};

//装备洗礼替换
struct NET_SIC_equip_xili_change : public tag_net_message
{
	NET_SIC_equip_xili_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_xili_change");
		dw_size = sizeof(NET_SIC_equip_xili_change);
	}
	INT64		n64EquipID;	
};

struct NET_SIS_equip_xili_change : public tag_net_message
{
	NET_SIS_equip_xili_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_xili_change");
		dw_size = sizeof(NET_SIS_equip_xili_change);
	}
	INT64		n64EquipID;	
	DWORD		dw_error_code;
};

// 武器武魂提取
struct NET_SIC_equip_get_wuhuen : public tag_net_message
{
	NET_SIC_equip_get_wuhuen()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_get_wuhuen");
		dw_size = sizeof(NET_SIC_equip_get_wuhuen);
	}
	INT64		n64EquipID;	
	DWORD		dwItemID;		//提炼液
	INT			nNumber;		//数量
};

struct NET_SIS_equip_get_wuhuen : public tag_net_message
{
	NET_SIS_equip_get_wuhuen()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_get_wuhuen");
		dw_size = sizeof(NET_SIS_equip_get_wuhuen);
	}
	INT64		n64EquipID;	
	DWORD		dw_error_code;
};

// 武器熔炼升级
struct NET_SIC_equip_ronglian : public tag_net_message
{
	NET_SIC_equip_ronglian()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_ronglian");
		dw_size = sizeof(NET_SIC_equip_ronglian);
	}
	INT64		n64EquipID;	
};

struct NET_SIS_equip_ronglian : public tag_net_message
{
	NET_SIS_equip_ronglian()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_ronglian");
		dw_size = sizeof(NET_SIS_equip_ronglian);
	}
	INT64		n64EquipID;	
	DWORD		dw_error_code;
};

// 饰品附魔
struct NET_SIC_equip_fumo : public tag_net_message
{
	NET_SIC_equip_fumo()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_fumo");
		dw_size = sizeof(NET_SIC_equip_fumo);
	}
	INT64		n64EquipID;	
	DWORD		dwItemID;		//增加暴击物品
	INT			nNumber;		//数量
};

struct NET_SIS_equip_fumo : public tag_net_message
{
	NET_SIS_equip_fumo()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_fumo");
		dw_size = sizeof(NET_SIS_equip_fumo);
	}
	INT64		n64EquipID;	
	DWORD		dw_error_code;
};

// 装备变换
struct NET_SIC_equip_type_change : public tag_net_message
{
	NET_SIC_equip_type_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_type_change");
		dw_size = sizeof(NET_SIC_equip_type_change);
	}
	INT64		n64EquipID;	
	DWORD		n64Item1;
	DWORD		n64Item2;
	DWORD		n64Item3;
};

struct NET_SIS_equip_type_change : public tag_net_message
{
	NET_SIS_equip_type_change()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_equip_type_change");
		dw_size = sizeof(NET_SIS_equip_type_change);
	}
	INT64		n64EquipID;	
	DWORD		dw_error_code;
};


// 使用祝福油
struct NET_SIC_use_luck_you : public tag_net_message
{
	NET_SIC_use_luck_you()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_use_luck_you");
		dw_size = sizeof(NET_SIC_use_luck_you);
	}

	INT64		n64Item;
};

struct NET_SIS_use_luck_you : public tag_net_message
{
	NET_SIS_use_luck_you()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_use_luck_you");
		dw_size = sizeof(NET_SIS_use_luck_you);
	}
	CHAR	ch_CurLuck;//当前武器幸运值
	CHAR	ch_ChangeLuck;//幸运变化值
	DWORD dw_error_code;
};

#pragma pack(pop)
		
#endif



