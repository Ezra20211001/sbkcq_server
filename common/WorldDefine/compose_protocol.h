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
*	@brief		װ��ǿ�����ϳ���Ϣ
*/

#ifndef COMPOSE_PROTOCOL
#define COMPOSE_PROTOCOL

#include "protocol_common_errorcode.h"
#include "compose_define.h"

#pragma pack(push, 1)

//----------------------------------------------------------------------------
// ������ö��
//----------------------------------------------------------------------------
enum 
{
	//���д�����
	E_Compose_NPC_Not_Exist = 1, 				//NPC������
	E_Compose_Formula_Not_Exist = 2, 			//�䷽������
	E_Compose_Stuff_Not_Enough = 3, 			//������������
	E_Compose_Stuff_Formula_Not_Match = 4, 		//���Ϻ��䷽��ƥ��
	E_Compose_NPC_Distance = 5,					//NPC����̫Զ
	E_Compost_MustItem_Not_Exit = 6,			//�ϳɱ���Ʒ������
	E_Compose_UpQuality_Not_enough = 7,			//�������ʵ�����������

	//�ϳ�ǿ�����ص����ֽ��,�Ǹ��ݺϳɹ�ʽ���
	E_Compose_Consolidate_Success = 11, 		//�ɹ�
	E_Compose_Consolidate_Lose = 12, 			//ʧ��
	E_Compose_Consolidate_Perfect = 13, 		//����


	//�ϳɴ�����
	E_Compose_OutOf_Vip_Level = 19,
	E_Compose_Stuff_Pro_Not = 20, 				//���ʲ���1%���ܺϳ�
	E_Compose_Stuff_Not_Exist = 21, 			//�ϳɲ��ϲ�����
	E_Compose_Type_Not_Exist = 22,				//�ϳ����Ͳ�����
	E_Compose_Skill_Not_Exist = 23,				//���û�кϳɼ���
	E_Compose_FormulaNotMatch = 24,				//�ϳ��䷽��ƥ��
	E_Compose_NPCCanNotCompose = 25,			//���Ǻϳ�NPC
	E_Compose_Skill_Not_Same = 26,				//���ܺͱ��еȼ�����
	E_Compose_NotEnough_Money = 27,				//��ҽ�Ǯ����
	E_Compose_Bag_Full = 28,					//��������
	E_Compose_Item_NotFind = 29,				//ͼֽ������
	E_Compose_FormulaID_NotExit=30,				//ͼֽ�䷽ID����

	//�ֽ������
	E_Decomposition_Item_Not_Exist = 31, 		//�ֽ���Ʒ������
	E_Decomposition_Pet_NOt		   = 32, 		//û�г���

	//��Ƕ������
	E_Consolidate_Equip_Not_Exist = 41, 		//ǿ��װ��������
	E_Consolidate_Type_Not_Exist,				//ǿ�����Ͳ�����
	E_Consolidate_NPCCanNotPosy,				//��������NPC
	E_Consolidate_NotEquipment,					//ǿ������Ʒ����װ��
	E_Consolidate_BeyondPosyTime,
	E_Consolidate_FormulaNotMatch,				//ǿ���䷽��ƥ��
	E_Consolidate_NotEnough_Money,				//��ҽ�Ǯ����
	E_Consolidate_NotEnough_Stuff,				//��Ҳ��ϲ���
	E_Consolidate_EquipCanNotPosy,				//�����Բ��ܱ�����
	E_Consolidate_ValConsume_Inadequate,		//װ��Ǳ��ֵ����
	E_Consolidate_Param_Not_Find,				//������û��

	E_Compose_NPCCanNotEngrave = 61,			//�����Կ�NPC
	E_Consolidate_EquipCanNotEngrave,			//�����Բ��ܱ��Կ�
	E_Consolidate_BeyondEngraveTime,			//�����Կ̴���

	E_Consolidate_Gem_Not_Exit = 81,			//��ʯ������
	E_Consolidate_Gem_Full,						//װ����������ʯ
	E_Consolidate_EquipCanNotInlay,				//�ñ�ʯ���ܱ���Ƕ
	E_Consolidate_Gem_Not_Hole,					//װ���޿�
	E_Hole_NPCCanNot_Exit,						//���Ǵ��NPC
	E_Hole_FormulaParam_Not_Exit,				//��׹�ʽ����������
	E_Hole_NotEnough_Money,						//���û���㹻�Ľ�Ǯ
	E_Consolidate_Gem_level_not,				//��ʯ�ȼ�����

	E_Consolidate_Brand_Not_Exit = 101,			//ӡ�ǲ�����
	E_Consolidate_Brand_TopLevel,				//ӡ�ǵȼ��ﵽ����
	E_Consolidate_EquipCanNotBrand,				//��װ�����ܱ�ӡ��

	E_Consolidate_NPCCanNotQuench = 121,		//���Ǵ��NPC
	E_Consolidate_WXValueInadequate,			//ԭ����ֵ����
	E_Consolidate_False,						//���ʧ��

	E_Compose_Quality_Not_Match = 131,			//�㻯ֻ���ڻ�ɫ������װ��
	E_Compose_Not_Fashion,						//��߼�ʱװ���ɵ㻯��ֽ�
	E_Compose_Equip_Lock,						//��������װ�����ɵ㻯��ֽ�
	E_Compose_Equip_Time_Limit,					//��ʱ�����Ƶ�װ�����ɵ㻯��ֽ�
	E_Compose_Equip_Not_identify,				//δ������װ�����ɵ㻯��ֽ�
	E_Compose_Equip_Level_Inadequate,			//װ���ȼ�����
	E_Compose_Equip_Quality_Inadequate,			//װ��Ʒ�ʲ���
	E_Compose_Equip_Type_Inadequate,			//װ�����Ͳ������䷽Ҫ��
	E_Compose_Equip_Posy,						//װ�������̰󶨵�
	E_Compose_Equip_Bind,						//npc��,��ʯ�󶨲��ɷֽ�

	E_Consolidate_Chisel_Not_Exit = 151,		//��ʯ������
	E_Consolidate_Equip_CanNot_Chisel,			//װ�����ܱ�����
	E_Consolidate_Equip_Hole_Full,				//��Ƕ��������Ϊ5�������ɽ��п���
	E_Consolidate_Chisel_Not_Match,				//��ʯ�ȼ�С���������װ���ȼ������ɽ��п���
	E_Consolidate_NotIdentified,				//δ����װ�����ɿ���
	E_Consolidate_EquipLevel_Not,				//װ���ȼ�����
	E_Consolidate_Shipingqu_Not,				//ʱװ��򲻿ɴ����Ƕ

	E_Repair_NPCCanNotRepair = 161,				//����ά��NPC
	E_Repair_EquipItem_Not_Exit,				//ά����Ʒ������
	E_Repair_EquipItem_Not_Repair,				//����ά����Ʒ
	E_Repair_Equip_Not_Exist,					//ά��װ��������
	E_Repair_NotEquipment,						//ά��װ������װ��
	E_Repair_Num_Not_Inadequate,				//ά����Ʒ����
	E_Repair_Quality_Not_Out,					//����ά��Ʒ��
	E_Repair_NotEnough_Money,					//ά�޽���
	E_Repair_NoMall_Item,						//ά����Ʒ�����̳���Ʒ
	E_Repair_NotRepair,							//װ������ά��

	E_Unbeset_NPCCanNot_Exit = 181,				//��ǶNPC������
	E_Unbeset_BesetItem_Not_Exit,				//��Ƕ��Ʒ������
	E_Unbeset_Item_Not_Exit,					//��Ƕ���߲�����
	E_Unbeset_FormulaParam_Not_Exit,			//��Ƕ��ʽ������
	E_Unbeset_Not_Money,						//��Ǯ����
	E_Unbeset_Not_bag_free,						//�����ռ䲻��

	E_ShengXing_CanNot = 201,					//װ����������
	E_ShengXingItem_Not_Exit,					//��������ǿ��ʯ������
	E_ShengXing_Abort,							//����ʧ��
	E_ShengXing_Item_Error,						//ǿ��ʯ������Ҫ��
	E_ShengXing_Param_Not_Find,					//ǿ������δ�ҵ�
	E_ShengXing_NotEnough_Money,				//ǿ����Ǯ����
	E_ShengXing_BingNot,						//ǿ��ʯ������Ͳ���
	E_ShengXing_NumError,						//��ʯ��������
	E_ShengXing_Type_Error,						//ǿ��ʯ���Ͳ���

	E_ShengXing_Baohu_not_bind,					//û���ð�ʯ����ʹ�ñ���ʯ
	E_ShengXing_Baohu_Not_Find,					//����ʯ������
	E_ShengXing_Baohu_level_error,				//����ʯ�ȼ�����

	E_Fusion_NPCCanNot_Exist = 221,				//�����ں�NPC
	E_Fusion_Equip1_Not_Exist,					//���ںϵ�װ��1δ�ҵ�
	E_Fusion_Equip2_Not_Exist,					//���ںϵ�װ��2δ�ҵ�
	E_Fusion_NotEquipment1,						//��Ʒ1��������
	E_Fusion_NotEquipment2,						//��Ʒ2��������
	E_Fusion_Level_Not_Exist,					//����1�ĵȼ�С������2
	E_Fusion_Talent_Not_Exist,					//�����츳����
	E_Fusion_NotEnough_Money,					//�ںϽ�Ǯ����
	E_Fusion_Equip1Level_low,					//���������ȼ�̫��
	E_Fusion_EquiplevelUp_NotFind,				//װ���ȼ���������δ�ҵ�
	E_Fusion_Level_low,							//����ȼ�����
	E_Fusion_Class_Not_Exist,					//ְҵ����

	E_Prictice_NotFind_Equip = 241,				//����װ��������
	E_Prictice_Not_Weapon,						//����װ����������
	E_Prictice_Not_State,						//��ǰ״̬��������
	E_Prictice_Brotherhood_Not,					//����ֵ����
	E_Prictice_Level_Max,						//�����ȼ�����
	E_Prictice_Speed_item_Error,				//���ٵ��߷Ƿ�����������
	E_Prictice_Speed_item_level_Error,			//���ٵ��ߵȼ�����

	E_Weapon_LearnSkill_NotFind = 261,			//װ��������
	E_Weapon_LearnSKill_NotWeapon,				//��������
	E_Weapon_LearnSkill_NotEquip,				//����ûװ����
	E_Weapon_LearnSKill_NotSkill,				//���ܲ�����
	E_Weapon_LearnSkill_Existed,				//װ�������иü���
	E_Weapon_LearnSkill_TalentNot,				//װ���ͼ����츳���Ͳ���
	E_Weapon_LearnSkill_MustPassive,			//ֻ�б��������ܼ���
	E_Weapon_LearnSkill_NoPreSkill,				//û��ǰ�ü���
	E_Weapon_LearnSkill_NeedMoreTalentPoint,	//���������츳��
	E_Weapon_LearnSkill_NoTalentPoint,			//�츳�㲻��
	E_Weapon_LearnSkill_RoleExisted,			//����������иü���
	E_Weapon_LearnSkill_FullSkillList,			//װ����������
	E_Weapon_LevelUpSkill_NotExisted,			//װ����û�иü���
	E_Weapon_LevelUpSkill_RoleNoExisted,		//���û�ü���	
	E_Weapon_ClearTalent_NoEquip,				//װ��δ�ҵ�
	E_Weapon_ClearTalent_NotWeapon,				//��������
	E_Weapon_ClearTalent_NoItem,				//ϴ�����û�ҵ�
	E_ClearTalent_ItemNotValid,					//��Ʒ�����ǲ���ϴ�����
	E_Weapon_Clear_Not_clear,					//��������Ҫϴ��
	E_Weapon_LearnSkill_NeedMoreLevel,			//����ȼ�����

	E_Equip_Bind_NotFind	=	300,			//��װ��������
	E_Equip_Bind_ItemNotFind,					//�󶨵��߲�����
	E_Equip_Bind_ItemTypeError,					//�󶨵������Ͳ���
	E_Equip_Bind_NPC_Error,						//��NPC����
	E_Equip_UnBind_ItemNotFind,					//����󶨵��߲�����
	E_Equip_UnBind_SystemBind,					//ϵͳ�󶨲��ܽ��
	E_Equip_Bind_Not_bind,						//�޷��� �Ѿ���ʯ���˻����Ʒ��ʱ��
	E_Equip_UnBind_Not_UnBind,					//�Ѿ��ڽ����
	E_Equip_Bind_IS_Fashion,					//ʱװ���ܰ󶨽��
	E_Equip_UnBind_IS_Level,					//�Ѿ�ע�������������ɽ��е��߽�����

	E_Equip_Reatt_NotFind = 320,				//װ��������
	E_Equip_Reatt_Not_Quality3,					//������װ
	E_Equip_Reatt_NotEnough_Money,				//Ԫ������
	E_Equip_Reatt_Index_Not,					//�������ø�����
	E_Equip_Reatt_level_not,					//45�����ϵ�װ������ϴ����
	E_Equip_Reatt_is_Picture_Mod,				//ͼֽ�����װ����������
	E_Equip_Reatt_item_Not_find,				//�������Ե��߲�����
	E_Equip_Reatt_item_Type_Not,				//�������Ե������Ͳ���
	E_Equip_Reatt_item_Level_Not,				//�������Ե��ߵȼ�����
	E_Equip_Reatt_Star_not,						//��������ǿ���ȼ�����

	E_Role_No_Prictice_State = 340,				// ��ɫ��������״̬
	E_Role_LeavePrictice_Area_Limit,			// ����������������
	E_Role_LeavePricitice_level_limit,			// ���������ȼ�����
	E_Role_LeavePricitice_love_limit,			// ������������ֵ����
	E_Role_LeavePricitice_TimeType_Not,			// ��������ʱ�����ͷǷ�
	E_Role_LeavePricitice_MulType_Not,			// ���������������ͷǷ�
	E_Role_LeavePricitice_RedName_limit,		// ��������ʹ����������

	E_Role_Weapon_Kaiguang_Not_Find = 360,		// ����������
	E_Role_Weapon_Kaiguang_Not_Con,				// ��������
	E_Role_Weapon_Kaiguang_Not_Role_level,		// ��ɫ�ȼ�����
	E_Role_Weapon_Kaiguang_Not_goon,			// �Ѿ������ٿ�����
	E_Role_Weapon_Kaiguang_NotEnough_Money,		// ��Ҳ���

	E_Role_Equip_xili_quality_not = 380,		// ��������ɫ����
	E_Role_Equip_xili_level_not,				// ������30������װ��	
	E_Role_Equip_xili_product_picture,			// ͼֽ����װ������ϴ��
	E_Role_Equip_xili_Not_enough_cur,			// ս������
	E_Role_Equip_xili_All_full,					// �����������
	E_Role_Equip_xili_Not_enough_yuanbao,		// �Ͻ�Ҳ���
	E_Role_Equip_xili_role_level_not,			// ��ɫ�ȼ�����
	E_Role_Equip_xili_OutOfTimes,				// ϴ���������

	E_Role_Equip_Wuhuen_Not_Count = 390,		// ������ȡ����
	E_Role_Equip_Wuhuen_Outof_yuanbao = 391,	// Ԫ������

	E_Role_Equip_ronglian_level_max = 400,		// �����ȼ�����
	E_Role_Equip_ronglian_not_wuhuen,			// ��겻��


	E_Role_change_petxiulian_not_monery = 410,	// ��Ǯ����
	E_Role_change_petxiulian_max,				// �����

	E_Role_yuanshi_damo_NPC_NOT			= 500,	// npc����
	E_Role_yuanshi_damo_not_yuanshi		= 501,	// ����ԭʯ���ܴ�ĥ
	E_Role_yuanshi_damo_not_silver		= 502,	// ��Ǯ����
	E_Role_yuanshi_damo_error			= 503,	// �����Ʒʧ��
};

#define LEAVE_PRICTICE_LEVEL	30			// ���������ȼ�

//-----------------------------------------------------------------------------
//	�ϳ���Ϣ
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
	//DWORD				dwSkillID;		//����ID
	//INT64				n64ItemID;		//��ƷID
	DWORD 				dwFormulaID;  	//�䷽ID
	//INT64				n64IMID;		//IMid
	//BOOL				bBind;			//�Ƿ����ɰ���Ʒ
	//BYTE				byUseUpQualityItem;//����Ʒ�ʸ�����Ʒ -1:��ʹ�� 0:�� 1:�� 2���� 3:�� 4����
	//BYTE				byQualityNum;	//����������ʹ������
	//DWORD				byYuanBao;		//����ʹ��Ԫ������
	//DWORD				dw_safe_code;
	//INT64				n64StuffID[1]; 	//���� �����䳤
};

struct NET_SIS_produce : public tag_net_message
{
	NET_SIS_produce()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_produce");
		dw_size = sizeof(NET_SIS_produce);
	}
	DWORD				dw_error_code;	//������
};

//-----------------------------------------------------------------------------
//	�ֽ���Ϣ ���ڵ㻯�����е�һ����֧
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
	DWORD				dwSkillID;		//����ID
	INT64				n64ItemID;		//��ƷID
	DWORD				dwFormulaID;	//�䷽ID
	INT64				n64IMID;		//IMid
	INT64				n64Item; 		//���ֽ���Ʒ64λID
	BOOL				bPetDec;		//�Ƿ��ǳ�����
};

struct NET_SIS_decomposition : public tag_net_message
{
	NET_SIS_decomposition()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_decomposition");
		dw_size = sizeof(NET_SIS_decomposition);
	}
	DWORD				dw_error_code;	//������
	INT					nStuffIndex[1];	//�ֽ��������
};

//-----------------------------------------------------------------------------
//	ǿ����Ϣ
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
	DWORD 				dwFormulaID;  	//�䷽ID
	INT64 				n64ItemID; 		//Ҫ��ǿ����Ʒ��64λID
	INT64				n64IMID;		//IMid
	INT64				n64StuffID[1]; 	//���� �����䳤	
};

struct NET_SIS_consolidate_posy : public tag_net_message
{
	NET_SIS_consolidate_posy()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_consolidate_posy");
		dw_size = sizeof(NET_SIS_consolidate_posy);
	}
	DWORD				dw_error_code;	//������
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
	DWORD				dwFormulaID;	//�䷽ID
	INT64				n64ItemID;		//Ҫ��ǿ����Ʒ��64λID
	INT64				n64IMID;		//IMID
	INT64				n64StuffID[1];	//���� 
};

struct NET_SIS_consolidate_engrave : public tag_net_message
{
	NET_SIS_consolidate_engrave()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_consolidate_engrave");
		dw_size = sizeof(NET_SIS_consolidate_engrave);
	}
	DWORD				dw_error_code;	//������
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
	DWORD				dwFormulaID;	//�䷽ID
	INT64				n64ItemID;		//Ҫ��ǿ����Ʒ��64λID
	INT64				n64IMID;		//IMID
	INT64				n64StuffID[1];	//���� 
};

struct NET_SIS_consolidate_quench : public tag_net_message
{
	NET_SIS_consolidate_quench()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_consolidate_quench");
		dw_size = sizeof(NET_SIS_consolidate_quench);
	}
	DWORD				dw_error_code;	//������
};

//����
struct NET_SIC_shengxing : public tag_net_message
{
	NET_SIC_shengxing()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_shengxing");
		dw_size = sizeof(NET_SIC_shengxing);
	}
	INT64	n64SerialEquip;		//װ��
	DWORD	dwNPCID;			//NPCID
	INT64	n64ShengXingItem;	//��Ʒ��Ʒ(ǿ��ʯ)
	DWORD	dwStuffID;			//����������Ʒ(��ʯ)
	INT		nStuffNum;			//ʹ�õ�����������Ʒ����
	BOOL	bBind;				//�Ƿ��ǰ󶨵�
	INT64	n64BaohuItem;		//����ʯ
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
//	��Ƕ
//-----------------------------------------------------------------------------
struct NET_SIC_inlay : public tag_net_message
{
	NET_SIC_inlay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_inlay");
		dw_size = sizeof(NET_SIC_inlay);
	}
	INT64				n64DstItemID;	//װ����64ID
	INT64				n64SrcItemID[MAX_EQUIPHOLE_NUM];	//��ʯ��64ID
};

struct NET_SIS_inlay : public tag_net_message
{
	NET_SIS_inlay()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_inlay");
		dw_size = sizeof(NET_SIS_inlay);
	}
	DWORD				dw_error_code;	//������
};

//����
struct NET_SIC_chisel : public tag_net_message
{
	NET_SIC_chisel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_chisel");
		dw_size = sizeof(NET_SIC_chisel);
	}
	INT64				n64SrcItemID;	//װ����64ID
	DWORD 				dwNPCID; 		//NPCID
	INT64				n64StuffID;		//���ʯ
};

struct NET_SIS_chisel : public tag_net_message
{
	NET_SIS_chisel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_chisel");
		dw_size = sizeof(NET_SIS_chisel);
	}
	DWORD				dw_error_code;	//������
};

//��Ƕ
struct NET_SIC_unbeset : public tag_net_message
{
	NET_SIC_unbeset()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_unbeset");
		dw_size = sizeof(NET_SIC_unbeset);
	}
	INT64		n64SerialEquip;		//װ��
	DWORD		dwNPCID;			//NPCID
	BYTE		byUnBesetPos;		//��Ҫ�������Ƕ��Ʒλ��
	//INT64		n16SerialUnBesetItem;		//��Ƕ��Ʒ
	//INT64		n64StuffID;		//������Ʒ
	//BYTE		byYuanBaoNum;	//Ԫ������
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

// ԭʯ��ĥ
struct NET_SIC_damo : public tag_net_message
{
	NET_SIC_damo()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_damo");
		dw_size = sizeof(NET_SIC_damo);
	}
	
	DWORD		dwItemID;		//ԭʯid
	DWORD		dwNumber;		//����
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

	DWORD		dw_error_code;		// ������

};


//---------------------------[12/1/2010 Administrator]
//��������
//---------------------------
//��ʼ���� �������
struct NET_SIC_practice_begin : public tag_net_message
{
	NET_SIC_practice_begin()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_practice_begin");
		dw_size = sizeof(NET_SIC_practice_begin);
	}
	INT64		n64SerialEquip;			//����
	DWORD		dw_speed_item_data_id[MAX_XIULIAN_ITEM_NUMBER];	//���ٵ���dataId
	DWORD		dw_speed_item_number[MAX_XIULIAN_ITEM_NUMBER];	//���ٵ�������
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

//ֹͣ����
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

// ������������
struct NET_SIC_leave_parcitice : public tag_net_message
{
	NET_SIC_leave_parcitice()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_leave_parcitice");
		dw_size = sizeof(NET_SIC_leave_parcitice);
	}

	BYTE	byTimeType;			// ��������ʱ������ 1. 2Сʱ 2. 3Сʱ 3. 8Сʱ 4. 12Сʱ
	BYTE	byMulType;			// ������������		1. 1��  2. 2��  3. 4��  4. 6��  5. 8��
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

//�����ں�
struct NET_SIC_fusion : public tag_net_message
{
	NET_SIC_fusion()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_fusion");
		dw_size = sizeof(NET_SIC_fusion);
	}
	INT64		nEquip1;	//������
	INT64		nEquip2;	//������
	INT64		n64ItemID;	//����������ֵ
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


//����ϴ�츳��
struct NET_SIC_weapon_clear_talent : public tag_net_message
{
	NET_SIC_weapon_clear_talent()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_weapon_clear_talent");
		dw_size = sizeof(NET_SIC_weapon_clear_talent);
	}
	//INT64		n64EquipID;				// װ��ID
	INT64		n64ItemID;				// ʹ�õĵ���
};

struct NET_SIS_weapon_clear_talent : public tag_net_message
{
	NET_SIS_weapon_clear_talent()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_weapon_clear_talent");
		dw_size = sizeof(NET_SIS_weapon_clear_talent);
	}
	//INT64		n64EquipID;				// װ��ID
	DWORD		dw_error_code;			// ������
};


//װ����
struct NET_SIC_equip_bind : public tag_net_message
{
	NET_SIC_equip_bind()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_bind");
		dw_size = sizeof(NET_SIC_equip_bind);
	}
	INT64		n64EquipID;				//װ��ID ::= -1 npc����������װ��
	INT64		n64ItemID;				//�󶨵���ID ::= -1��˵����npc��
	DWORD		dwNPCID;				//NPCID ::=0ʱ˵���õ��߰�
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


//װ�����
struct NET_SIC_equip_unbind : public tag_net_message
{
	NET_SIC_equip_unbind()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_unbind");
		dw_size = sizeof(NET_SIC_equip_unbind);
	}
	INT64		n64EquipID;				//װ��ID
	INT64		n64ItemID;				//����󶨵���ID
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

//װ����������
struct NET_SIC_equip_reatt : public tag_net_message
{
	NET_SIC_equip_reatt()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_reatt");
		dw_size = sizeof(NET_SIC_equip_reatt);
	}
	INT64		n64EquipID;				//װ��ID
	INT64		n64ItemID;				//���õ���id
	BYTE		byIndex;				//�ĸ�����
	BYTE		byType;					//�������� 0:ֻ��Ǯ 1:��һ��Ǯ�͵��� 2: ֻ�õ�������3������
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


//��������
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

//װ��ϴ��
struct NET_SIC_equip_xili : public tag_net_message
{
	NET_SIC_equip_xili()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_xili");
		dw_size = sizeof(NET_SIC_equip_xili);
	}
	INT64		n64EquipID;	
	DWORD		dwType;		//����0:ս��  1:�Ͻ��2   2:�Ͻ��10
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
	INT32		EquipAttitional[MAX_RAND_ATT];	//�滻�������
	DWORD		dw_error_code;
};

//װ��ϴ���滻
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

// ���������ȡ
struct NET_SIC_equip_get_wuhuen : public tag_net_message
{
	NET_SIC_equip_get_wuhuen()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_get_wuhuen");
		dw_size = sizeof(NET_SIC_equip_get_wuhuen);
	}
	INT64		n64EquipID;	
	DWORD		dwItemID;		//����Һ
	INT			nNumber;		//����
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

// ������������
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

// ��Ʒ��ħ
struct NET_SIC_equip_fumo : public tag_net_message
{
	NET_SIC_equip_fumo()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIC_equip_fumo");
		dw_size = sizeof(NET_SIC_equip_fumo);
	}
	INT64		n64EquipID;	
	DWORD		dwItemID;		//���ӱ�����Ʒ
	INT			nNumber;		//����
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

// װ���任
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


// ʹ��ף����
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
	CHAR	ch_CurLuck;//��ǰ��������ֵ
	CHAR	ch_ChangeLuck;//���˱仯ֵ
	DWORD dw_error_code;
};

#pragma pack(pop)
		
#endif



