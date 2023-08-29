#pragma once

#include "RoleDefine.h"
#include "container_define.h"
#include "../WorldDefine/skill_define.h"
#include "../WorldDefine/time.h"
#include "../WorldDefine/reputation.h"
#include "specfunc_define.h"

#pragma pack(push, 1)

class ItemScript;

//-----------------------------------------------------------------------------
// ��������
//-----------------------------------------------------------------------------
const INT MAX_ITEM_TYPE_NUM				= 100000;	// ��̬���У���Ʒװ�����������

const INT MAX_ROLEATT_BASE_EFFECT		= 10;	// װ��ԭ���п���д��Ӱ�����Ը���

const INT MAX_POSY_TIMES				= 20;	// һ��װ�������������Ĵ���
const INT MAX_ROLEATT_POSY_EFFECT		= 4;	// һ��װ�����������Ӱ������Ը���

const INT MAX_ENGRAVE_TIMES				= 20;	// һ��װ�����������Կ̴���
const INT MAX_ROLEATT_ENGRAVE_EFFECT	= 4;	// һ��װ�����Կ����Ӱ������Ը���

const INT MAX_ROLEATT_ENHANCE_EFFECT	= 3;	// ǿ��װ���Ĳ���Ӱ������Ը���
const INT MAX_EQUIPHOLE_NUM				= 5;	// һ��װ������������Ƕ������

const INT MAX_BASE_ATT					= 10;	// �������Ը���
const INT MAX_RAND_ATT					= 5;	// �������Ը���
const INT MAX_ADDITIONAL_EFFECT			= MAX_RAND_ATT+MAX_BASE_ATT;// װ����󸽼����Ը���

const INT MAX_BRAND_LEVEL				= 10;	// װ������ӡ�ȼ�����

const INT MAX_CONSOLIDATE_LEVEL			= 15;	// ���ǵȼ�����
const float CONSOLIDATE_PARAM			= 1.15f;// ����ÿ���������ӵ����԰ٷֱ�
const float WEAPON_LEVEL_PARAM			= 0.1f;// �����ȼ�ÿ��Ӱ��İٷֱ�

const INT ABRASION2USETIMES				= 450;	// ����ʹ�ô�����ո�¶Ƚ���.1��ո�¶� = ʹ��1��
const INT ARMORABRASION2USETIMES		= 50;	// ����ʹ�ô�����ո�¶Ƚ���.1��ո�¶� = ʹ��1��

const INT MAX_ITEM_DCTIME				= 7 * 24 * 60 * 60;	// ��Ʒ���ȴʱ��(��λ����)

const INT MAX_EQUIP_ATTACH_NUM          = 20;    // װ�����ر���ģ���������

const INT MAX_PEREQUIP_SUIT_NUM			= 3;	// һ��װ����������3����װ

const INT MAX_EQUIP_BUFF_NUM			= 5;	// װ���ϴ���buff������

const INT MAX_WEAPON_LEVEL				= 70;	// װ�������ȼ�

const INT MAX_EQUIP_SKILL_NUM			= 12;	// װ���������

const INT NPC_BIND_TIME					= 2 * 24 * 60 * 60;		// NPC��ʱ��
const INT MOUNT_SKILL_NUM				= 1;
const INT BASE_REPIAR_PRICE				= 1;	// ��������۸�

const INT EQUIP_SKILL_NUMBER			= 2;

// װ�����ۼ۸�Ʒ������ϵ��
#define MCalPriceFactor(fFactor, nQlty)	\
	switch(nQlty)			\
{						\
	case 0:			\
	fFactor = 1.0f;		\
	break;				\
	case 1:			\
	fFactor = 1.5f;		\
	break;				\
	case 2:		\
	fFactor = 2.5f;		\
	break;				\
	case 3:		\
	fFactor = 3.5f;		\
	break;				\
	case 4:		\
	fFactor = 5.0f;		\
	break;				\
	default:				\
	fFactor = 0.1f;		\
	break;				\
}

//-----------------------------------------------------------------------------
// ö�ٶ���
//-----------------------------------------------------------------------------
//enum EItemType
//{
//	EIT_Null		= 0,
//	EIT_Expend		= 1,	// ����Ʒ
//	EIT_Unexpend	= 2,	// ������Ʒ
//	EIT_Spec		= 3,	// ������Ʒ
//	EIT_Pet			= 4,	// ����
//	EIT_Bag			= 5,	// ��Ʒ��
//	EIT_Mall		= 6,	// �̳ǵ���
//
//	EIT_Weapon		= 7,	// ����
//	EIT_ClothArmor	= 8,	// ����
//	EIT_Decoration	= 9,	// ��Ʒ
//	EIT_Fashion		= 10,	// ʱװ
//	EIT_Armor		= 11,	// ����
//};

enum EItemType
{
	EIT_Null		= 0,
	EIT_Equip		= 1,	// װ��
	EIT_QiangHua	= 2,	// ǿ��
	EIT_YaoPin		= 3,	// ҩƷ
	EIT_CaiLiao		= 4,	// ����
	EIT_Picture		= 5,	// ͼֽ
	EIT_Ride		= 6,	// ����
	EIT_Pet			= 7,	// ����
	EIT_Features	= 8,	// ����
	EIT_Other		= 9,	// ����
	EIT_Quest		= 10	// ����
};

//enum EItemTypeEx
//{
//	EITE_Null		= 0,
//	EITE_Resume		= 1,	// �ָ���
//	EITE_Advance	= 2,	// ǿ����
//	EITE_Other		= 3,	// ����
//	EITE_Material	= 4,	// ԭ����
//	EITE_Capture	= 5,	// ս��Ʒ
//	EITE_Quest		= 6,	// ������Ʒ
//	EITE_Book		= 7,	// �ؼ�
//	EITE_Pet		= 8,	// ����
//	EITE_Ride		= 9,	// ����
//	EITE_Expend		= 10,	// ����
//	EITE_Time		= 11,	// ʱ��
//
//	EITE_Claymore		= 12,	// ˫����(�̿�)
//	EITE_Axe    = 13,	// ˫�ִ�(�ͽ�)
//	EITE_Wand		= 14,	// ����(�ٱ�)
//	EITE_Gun		= 15,	// ��(����)
//	EITE_Book		= 16,	// ����(ҩʦ)	
//};

enum EItemTypeEx
{
	EITE_Null		= 0,

	EITE_Advance	= 1,	// ǿ��ʯ
	EITE_ShenShi	= 2,	// ��ʯ
	EITE_DaKong		= 3,	// ���ʯ
	EITE_Bind		= 4,	// ��ʯ
	EITE_Ling		= 5,	// ��ʯ

	EITE_Resume		= 6,	// �ָ���
	EITE_QiangHua	= 7,	// ǿ����

	EITE_KuangShi	= 8,	// ��ʯ
	EITE_CaoYao		= 9,	// ��ҩ
	EITE_DaZhaoShui = 10,	// ����ҩˮ
	EITE_PingZhiUp	= 11,	// Ʒ������
	
	EITE_Axe    = 12,	// (��ͷ ������)
	EITE_Wand		= 13,	// (ħ�ȣ���ʦ)
	EITE_Gun		= 14,	// (ǹ���ͽ�����)
	EITE_Claymore		= 15,	// (��,����)
	EITE_Book		= 16,	// (�飬ռ��ʦ)	
	
	EITE_Ride		= 17,	// ����
	EITE_RideAdvance= 18,	// ����ǿ��
	EITE_RideShenShi= 19,	// ������ʯ
	EITE_RideEquip	= 20,	// ����װ��
					  
	EITE_PetFood	= 21,	// ����ʳ��
	EITE_PetSkillBook=22,	// ���＼����
					  
	EITE_Prictice	= 23,	// ��������
	EITE_Master		= 24,	// ʦ��
	EITE_Guild		= 25,	// ���
	EITE_Bag		= 26,	// ��������
	EITE_BaiTan		= 27,	// ��̯
					  
	EITE_ZhuiSha	= 28,	// ׷ɱ��
	EITE_ZhaoShu	= 29,	// گ��
	EITE_Exp		= 30,	// ���鵤
	EITE_YiQi		= 31,	// ������


};

const INT32 X_WEAPON_TYPE_NUM = EITE_Book - EITE_Axe + 1;

#define M_WEAPON_TYPE_INDEX(X)    (  X   - EITE_Axe )
#define M_IS_VALID_WEAPON_TYPE(X) ( (X) >= EITE_Axe && (X) <= EITE_Book )

//enum EItemTypeReserved
//{
//	EITR_Null		= 0,
//	EITR_Yaopin		= 1,	// ҩƷ
//	EITR_Shipin		= 2,	// ʳƷ
//	EITR_Xiandan	= 3,	// �ɵ�
//	EITR_Yinji		= 5,	// ӡ��
//	EITR_Baoshi		= 6,	// ��ʯ
//	EITR_Qizhen		= 7,	// ����
//	EITR_Ranliao	= 8,	// Ⱦ��
//	EITR_Siliao		= 9,	// ����
//	EITR_Fuzhou		= 10,	// ����
//	EITR_Kuangshi	= 11,	// ��ʯ
//	EITR_Caoyao		= 12,	// ��ҩ
//	EITR_ShiCai		= 13,	// ʳ��
//	EITR_Buliao		= 14,	// ����
//	EITR_Mucai		= 15,	// ľ��
//	EITR_Yinyuan	= 17,	// ӡ��ԭ��
//
//	EITR_PETFOOD_Fish = 18,	// ��
//	EITR_PETFOOD_ROU  = 19,	// ��
//	EITR_PETFOOD_Cai  = 20,	// ��
//	EITR_PETFOOD_Siliao=21,	// ͨ�ó�������
//};

enum EItemTypeReserved
{
	//װ��
	EITR_Null		= 0,
	EITR_Weapon		= 1,	// ����
	EITR_Head		= 2,	// ͷ
	EITR_Body		= 3,	// ����
	EITR_Hand		= 4,	// ͷ
	EITR_Feet		= 5,	// ��
	EITR_Body0		= 6,	// �ڼ�
	EITR_Body1		= 7,	// ����
	EITR_Wrist		= 8,	// ����
	EITR_Waist		= 9,	// ����
	EITR_Legs		= 10,	// ��
	EITR_Neck		= 11,	// ����
	EITR_Finger		= 12,	// ��ָ
	EITR_Shipin		= 13,	// ��Ʒ
	EITR_Fashion	= 14,	// ʱװ

	//��ʯ
	EITR_HP_LS		= 15,	// ����
	EITR_Ack_LS		= 16,	// ����
	EITR_Def_LS		= 17,	// ����
	EITR_Hit_LS		= 18,	// ����
	EITR_ZJ_LS		= 19,	// �м�
	EITR_SB_LS		= 20,	// ����
	EITR_Crit_LS	= 21,	// ����
	EITR_CirtH_LS	= 22,	// �����˺�
	EITR_FanCrit_LS	= 23,	// ������
	EITR_FanCritH_LS= 24,	// ������
	EITR_HPH_LS		= 25,	// �����ָ�
	EITR_LiLiang_LS	= 26,	// ����
	EITR_MinJie_LS	= 27,	// ����
	EITR_ZhiLi_LS	= 28,	// ����
	EITR_NaiLi_LS	= 29,	// ����
	

	//����
	EITR_BeiBao		= 30,	// ��������
	EITR_Cangku		= 31,	// �ֿ�����
	
	//����ʳƷ
	EITR_PETFOOD_Fish = 32,	// ��
	EITR_PETFOOD_ROU  = 33,	// ��
	EITR_PETFOOD_Cai  = 34,	// ��
	EITR_PETFOOD_Siliao=35,	// ͨ�ó�������

	EITR_PETFOOD_ADDHP = 36,// ��������hp
	EITR_PETFOOD_REBORN = 37, // ���︴��

	EITR_CHUTOU			= 38, // ����ɿ��ͷ
};

#define MISPETFOOD(pItemProto) ((pItemProto)->eTypeReserved >= EITR_PETFOOD_Fish && (pItemProto)->eTypeReserved <= EITR_PETFOOD_Siliao)

//enum EItemQuality
//{
//	EIQ_Start		= -1,
//
//	EIQ_Null		= -1,	// δ����
//	EIQ_White		= 0,	// ��
//	EIQ_Blue		= 1,	// ��
//	EIQ_Yellow		= 2,	// ��
//	EIQ_Orange		= 3,	// ��
//	EIQ_Purple		= 4,	// ��
//
//	EIQ_End			= 5,
//};

enum EItemQuality
{
	EIQ_Start			= -1,

	EIQ_Null			= -1,	// δ����
	EIQ_Quality0		= 0,	// ��
	EIQ_Quality1		= 1,	// ��
	EIQ_Quality2		= 2,	// ��
	EIQ_Quality3		= 3,	// ��
	EIQ_Quality4		= 4,	// ��
	EIQ_Quality5		= 5,	// ��

	EIQ_End			= 6,
};

const INT32 X_EQUIP_QUALITY_NUM = EIQ_End - EIQ_Start - 1;

enum EBindMode	// ������
{
	EBM_Null		= 0,	// ��

	EBM_Gain		= 1,	// ��ð�
};

enum EBindStatus	// ��״̬
{
	EBS_Unknown		= 0,	// δ֪�ģ����̵��е���Ʒ
	EBS_Unbind		= 1,	// δ��
	EBS_Bind		= 2,	// ��
};

//enum ETimeMode		// ��ʱ��ʽ
//{
//	ETM_Null		= 0,
//	TEM_Create		= 1, // ���ɼ�ʱ
//	TEM_Online		= 2, // ���ϼ�ʱ
//	TEM_Battle		= 3, // ս����ʱ
//	TEM_Quest		= 4, // ���񴥷���ʱ
//	TEM_Used		= 5, // ʹ�ú��ʱ
//	TEM_Get			= 6, // ��ü�ʱ
//};

enum ESexLimit		// ��Ʒ��ʹ�õĽ�ɫ�Ա�,Ҫ��AvatarAtt���Ա��Ӧ
{
	ESL_Null		= -1,	// �����ƣ�����Ů������
	ESL_Woman		= 0,	// Ů���ƣ���Ů����
	ESL_Man			= 1,	// �����ƣ����п���
};


enum EWuXing	// ��������
{
	EWX_Start		= -1,
	EWX_Null		= -1,

	EWX_Metal		= 0,
	EWX_Wood		= 1,
	EWX_Water		= 2,
	EWX_Fire		= 3,
	EWX_Soil		= 4,

	EWX_End			= 5,
};

const INT32 X_WUXING_TYPE_NUM = EWX_End - EWX_Start - 1;


enum EStuffType		// ��������
{
	EST_Null		= 0,	//��
	EST_Stone		= 1,	//ʯ
	EST_Jade		= 2,	//��
	EST_Iron		= 3,	//��
	EST_Silver		= 4,	//��
	EST_Gold		= 5,	//��
	EST_ChunXinCao	= 6,	//������
	EST_XiaKuCao	= 7,	//�Ŀݲ�
	EST_QiuBaiCao	= 8,	//��ײ�
	EST_DongKuiCao	= 9,	//������
	EST_DongYangCao = 10,	//������
	EST_Flax		= 11,	//�鲼
	EST_Leather		= 12,	//Ƥ��
	EST_Cotton		= 13,	//�޲�
	EST_SilkOrgandy	= 14,	//��ɴ
	EST_Silk		= 15,	//˿��
	EST_Chop		= 16,	//���
	EST_Dew			= 17,	//¶ˮ
	EST_Grain		= 18,	//����
	EST_Bone		= 19,	//��ͷ
	EST_Potherb		= 20,	//Ұ��
};

enum EItemCreateMode	// ��Ʒ&װ��������ʽ
{
	EICM_Null		= 0, // û�м�¼
	EICM_GM			= 1, // GM��������
	EICM_Loot		= 2, // �������
	EICM_Quest		= 3, // ������
	EICM_Product	= 4, // �������
	EICM_ShopNPC	= 5, // �̵�NPC
	EICM_AccQuest	= 6, // ������
	EICM_Mall		= 7, // �̳�
	EICM_Gift		= 8, // ��Ʒ��
	EICM_ActTreasure= 9, // ���������䱦
	EICM_GMTool		= 10,// GM��������
	EICM_PetSkill	= 11,// ���＼��
	EICM_VipNetBar	= 12,// ��������
	EICM_ReGet		= 13,// ���߻ָ�
	EICM_Activity	= 14,// �����
	EICM_Unbeset	= 15,// ��Ƕ
	EICM_Guild		= 16,// ���
	EICM_Mail		= 17,// �ʼ�
	EICM_NewRoleGift = 18, //���ֽ���
	EICM_Fishing	 = 19, // ����
	EICM_Product_picture	= 20, // ͼֽ����
	EICM_Lottery	= 21,  // ��Ʊ��
	EICM_Sign			=	22,		// ǩ������
	EICM_DAMO		= 23,	// ��ĥ

};

enum EEnhanceEquipPos	// ��ǿ����װ������
{
	EEEP_Hand		= 0x00000001,	// ����
	EEEP_Head		= 0x00000002,	// ͷ��
	EEEP_Face		= 0x00000004,	// �沿
	EEEP_Body		= 0x00000008,	// ����
	EEEP_Legs		= 0x00000010,	// ����
	EEEP_Back		= 0x00000020,	// ����
	EEEP_Wrist		= 0x00000040,	// ��
	EEEP_Feet		= 0x00000080,	// �㲿
	EEEP_Finger		= 0x00000100,	// ��ָ
	EEEP_Waist		= 0x00000200,	// ����
	EEEP_Neck		= 0x00000400,	// ����
};

enum EEquipMdlType     // װ����ģ������
{
	EEMT_NULL	= 0,
	EEMT_FSKIN  = 1,   // ��Ƥ
	EEMT_FAK    = 2,   // �ؼ�֡
	EEMT_FSM    = 3,   // ��̬ģ��
};

enum EEquipAttachPos    // װ���ɱ��β��ֵĹ���λ��
{
    EEAP_NULL     = 0,
    EEAP_HAA      = 1,  // ͷ��
    EEAP_HWR      = 2,  // ����
    EEAP_SHR      = 3,  // �Ҽ�
    EEAP_GRA      = 4,  // ��С��
    EEAP_HWL      = 5,  // ����
    EEAP_SHL      = 6,  // ���
    EEAP_GLA      = 7,  // ��С��
    EEAP_CHM      = 8,  // ǰ��
    EEAP_BAL      = 9,  // ��������
    EEAP_FLA      = 10, // ���
    EEAP_LLA      = 11, // ��С��
    EEAP_FRA      = 12, // �ҽ�
    EEAP_LRA      = 13, // ��С��
    EEAP_CHP      = 14, // ����
	EEAP_Num      = 15,
};



enum ECorlor		// ��ɫ��ͼö��
{
	EC_Null		= -1,

	EC_Start	= 0,
	EC_Val0		= 0,
	EC_Val1		= 1,
	EC_Val2		= 2,
	EC_Val3		= 3,
	EC_Val4		= 4,
	EC_Val5		= 5,
	EC_Val6		= 6,
	EC_Val7		= 7,
	EC_Val8		= 8,
	EC_Val9		= 9,
	EC_Val10	= 10,
	EC_Val11	= 11,
	EC_End		= 11,
};

const INT X_COLOR_NUM	= EC_End - EC_Start + 1;

//װ����������
enum EquipAddAtt
{
	EAA_NULL			= -1,
	EAA_Statr			= 0,

	EAA_ExAttackMin		= 0,		// �﹥����
	EAA_ExAttackMax		= 1,		// �﹥����
	EAA_InAttackMin		= 2,		// ħ������
	EAA_InAttackMax		= 3,		// ħ������
	EAA_ArmorEx			= 4,		// ��������
	EAA_ArmorIn			= 5,		// ��������
	EAA_ExAttack		= 6,		// �������
	EAA_ExDef			= 7,		// �������
	EAA_InAttack		= 8,		// ħ������
	EAA_InDefense		= 9,		// ħ������
	EAA_HitRate			= 10,		// ����
	EAA_Dodge			= 11,		// ����
	EAA_Crit_Rate		= 12,		// ����
	EAA_UnCrit_Rate		= 13,		// ������
	EAA_MaxHP			= 14,		// hp
	EAA_MaxMP			= 15,		// mp

	EAA_End				= 15,	
};

const INT16 ADDATT_TYPE_NUM = EAA_End-EAA_Statr+1;

//�������浽�ĸ�������
enum WeaponRoleAtt
{
	WRA_Null				= -1,
	WRA_ExAttack			= 0,		// ��ս����
	WRA_HitRate				= 1,		// ����
	WRA_Ren					= 2,		// �м�
	WRA_Cirt				= 3,		// ����
	WRA_CirtNum				= 4,		// �����˺�
	WRA_Potence				= 5,		// ����
	WRA_Agility				= 6,		// ����
	WRA_Brains				= 7,		// ����
	WRA_Stamina				= 8,		// ����
	WRA_NUM					= 9,
};

// ������浽�ĸ�������
enum DecorationRoleAtt
{
	DRA_Null				= -1,
	DRA_ExAttack			= 0,		// ��ս����
	DRA_HitRate				= 1,		// ����
	DRA_Cirt				= 2,		// ����
	DRA_CirtNum				= 3,		// �����˺�
	DRA_Potence				= 4,		// ����
	DRA_Agility				= 5,		// ����
	DRA_Brains				= 6,		// ����
	DRA_Stamina				= 7,		// ����
	DRA_NUM					= 8,		
};

//���߿��浽�ĸ�������
enum ArmorRoleAtt
{
	ARA_Null				= -1,
	ARA_Dodge				= 0,			// ����
	ARA_ExDefense			= 1,			// ��ս����
	ARA_Potence				= 2,			// ����
	ARA_Agility				= 3,			// ����
	ARA_Brains				= 4,			// ����
	ARA_Stamina				= 5,			// ����
	ARA_FanCirt				= 6,			// ��������
	ARA_FanCirtNum			= 7,			// �������˺�
	ARA_Ren					= 8,			// �м�

	ARA_Armor_NUM			= 9,
};

// ��Ʒ���浽�ĸ�������
enum ShiPinRoleAtt
{
	SP_Null					= -1,
	SP_Potence				= 0,		// ����
	SP_Agility				= 1,		// ����
	SP_Brains				= 2,		// ����
	SP_Dodge				= 3,		// ����
	SP_HitRate				= 4,		// ����
	SP_Cirt					= 5,		// ����
	SP_CirtNum				= 6,		// �����˺�
	SP_Ren					= 7,		// �м�
	SP_FanCirt				= 8,		// ��������
	SP_FanCirtNum			= 9,		// �������˺�

	SP_NUM					= 10,		
};

enum RideEquipState
{
	ERES_Idle		= 0,
	ERES_Riding		= 1,
};



//-----------------------------------------------------------------------------
// �ṹ����
//-----------------------------------------------------------------------------
struct tagRoleAttEffect
{
	ERoleAttribute	eRoleAtt;
	INT32			nValue;

	tagRoleAttEffect() { ZeroMemory(this, sizeof(*this)); eRoleAtt = ERA_Null; }
};

struct tagEquipQltyPct
{
	DWORD				dw_data_id;
	INT32				nEquipQltyPct[X_EQUIP_QUALITY_NUM];	// Ʒ�����ɼ���
};

struct tagCDTime
{
	DWORD		dw_data_id;
	DWORD		dw_time;		// ��ȴʱ��(��λ������)
};

struct tagEquipLevelUpEffect
{
	INT		nExpLevelUp;		//������һ������ľ���ֵ����
	INT		nExpLevelUpShipin;	//��Ʒ������һ������ľ���ֵ����
	INT16	n16TalentAvail;		//�õ��Ŀ�Ͷ���ʵ�
};

/** struct	tagItemDisplayInfo
brief	��Ʒ��ʾ�ṹ
remarks	��Ҫ���ڴ洢��Ʒ�����ơ����͡�������ģ�͵ȵ�	
*/
struct tagItemDisplayInfo
{
	TCHAR				szType[X_SHORT_NAME];				// ��ʾ����
	TCHAR				szName[X_SHORT_NAME];				// ��Ʒ����
	TCHAR				szDesc[X_HUGE_NAME];				// ��Ʒ����
	TCHAR				szDescEx[X_LONG_NAME];				// ��Ʒ��������
	TCHAR				szMaleIcon[X_SHORT_NAME];			// ��Ʒͼ���а�
	TCHAR				szFemaleIcon[X_SHORT_NAME];			// ��Ʒͼ��Ů��
	TCHAR				szActionMod[X_SHORT_NAME];			// ��Ʒʹ�ö������
	TCHAR				szEffectMod[X_SHORT_NAME];			// ��Ʒʹ����Ч���
	TCHAR				szSourceEffect[X_SHORT_NAME];		// ��Ʒʹ�÷�������Ч���
	TCHAR				szDestEffect[X_SHORT_NAME];			// ��Ʒʹ��Ŀ����Ч���
	TCHAR				szPrepareMod[X_SHORT_NAME];			// ��Ʒʹ�����ֶ������
    TCHAR				szPrepareEffect[X_SHORT_NAME];		// ��Ʒʹ��������Ч���
	TCHAR				szMaleRightMod[X_SHORT_NAME];		// ��ģ�ͱ��1
	TCHAR				szFemaleRightMod[X_SHORT_NAME];		// Ůģ�ͱ��1
	TCHAR				szMaleLeftMod[X_SHORT_NAME];		// ��ģ�ͱ��2
	TCHAR				szFemaleLeftMod[X_SHORT_NAME];		// Ůģ�ͱ��2
    TCHAR               szTexPostfix[X_SHORT_NAME];         // ��ͼ��׺
	TCHAR				szDropMod[X_SHORT_NAME];			// ����ģ�ͱ��
	TCHAR				szPertainMod[X_SHORT_NAME];			// ����ģ�ͱ��
	TCHAR				szBladeFlareSFX[X_SHORT_NAME];		// ������Ч���
    TCHAR				szGlowSFX[X_LONG_NAME];		        // ������Ч���
	TCHAR				szMaleGlowSFX[X_LONG_NAME];		    // �й�����Ч���
    TCHAR				szFemaleGlowSFX[X_LONG_NAME];		// Ů������Ч���
    TCHAR				szAttachSFX[X_LONG_NAME];           // ������Ч���
    TCHAR               szMaleAttachSFX[X_LONG_NAME];       // ��ģ�͹�����Ч
    TCHAR               szFemaleAttachSFX[X_LONG_NAME];     // Ůģ�͹�����Ч

	TCHAR				szMaleShoulderMode[X_LONG_NAME];   //������ģ��
	TCHAR				szFemaleShoulderMode[X_LONG_NAME]; //Ů����ģ��

	EWeaponPos			ePertainModPos;						// ����ģ�͹���λ��
	EEquipMdlType       eModelType;							// ģ������
	EEquipAttachPos     eAttachModelPos[MAX_EQUIP_ATTACH_NUM];  // ���ر���ģ�͵�λ��
	BOOL				bActionBlend;						// �Ƿ�������ֿ�
	
	tagItemDisplayInfo(){ZeroMemory(this, sizeof(*this));}
};

struct tagItemProto
{
	DWORD				dw_data_id;		// ������Ʒ������(ͬ����Ʒ��ͬ)

	EItemType			eType;			// ��������
	EItemTypeEx			eTypeEx;		// ��չ����
	EItemTypeReserved	eTypeReserved;	// ��������

	EStuffType			eStuffType;		// �������ͣ��ϳ���

 	DWORD				dwQuestID;		// ������
	INT32				nBasePrice;		// �����۸�

	INT32				nGemNess;		// ��Ƕ����;ö�
	INT32				nMaxUseTimes;	// ���ʹ�ô���
	INT16				n16MaxLapNum;	// ����������
	INT16				n16MaxHoldNum;	// ���ӵ������

	DWORD				dwTimeLimit;	// ��ʱ����Ʒ(��)

	INT16				n16Enmity;		// ���

	BYTE				byMinUseLevel;	// �ȼ�����
	BYTE				byMaxUseLevel;	// �ȼ�����
	ESexLimit			eSexLimit;		// �Ա�����
	DWORD				dwVocationLimit;// ְҵ����

	//EReputationType		eClanRepute;	// ������������ֵ
	//INT32				nClanReputeVal;	// ��������ֵ
	//EReputationType		eOtherClanRepute;	// ������������ֵ
	//INT32				nOtherClanReputeVal;// ��������ֵ

	EItemSpecFunc		eSpecFunc;		// ��Ʒ���⹦������
	INT32				nSpecFuncVal1;
	INT32				nSpecFuncVal2;

	ESkillOPType		eOPType;							// ��������
	FLOAT				fOPDist;							// ���þ��루���絥λ��
	FLOAT				fOPRadius;							// ���÷�Χ�����絥λ��
	INT32				nPrepareTime;						// ����ʱ�䣨���룩
	DWORD				dwCooldownTime;						// ������ȴʱ��(��λ��ms)
	INT32				nInterruptSkillOrdRate;				// ��ͨ���ܴ�ϼ���[0,10000]
	DWORD				dwSpecBuffLimitID;					// ����BUFF����ID
	DWORD				dwStateLimit;						// ����״̬��־λ����
	DWORD				dwTargetLimit;						// ��������
	BOOL				bMoveable;							// �Ƿ�����ƶ�ʹ��			
	bool				bInterruptMove;						// �Ƿ��ƶ����

	BYTE				byLevel;			// ��Ʒ�ȼ�
	BYTE				byQuality;			// ��ƷƷ��

	BYTE				byBindType;			// ������

	DWORD				dwTriggerID0;		// ��������
	DWORD				dwBuffID0;			// Buff
	
	DWORD				dwTriggerID1;		// ������ID1
	DWORD				dwBuffID1;			// ״̬ID1

	DWORD				dwTransTriggerID;	// ���δ�������ID
	DWORD				dwTransID;			// ���κ�ID

	bool				bNeedBroadcast;		// �Ƿ�㲥(0�����㲥��1���㲥)
	bool				bCanSell;			// �Ƿ񲻿ɳ���(0���ɳ��ۣ�1�����ɳ���)

	bool				bNeedLog;			// �Ƿ���Ҫ��log(����������Ӫͨ�����ݱ�item_needlog�༭)
	BYTE				byLogMinQlty;		// ��¼log��Ʒ�����Ʒ��

	bool				bDeadLoot;			// ��������
	
	tagItemDisplayInfo*	pDisplayInfo;		// ��Ʒ��ʾ�ṹ���ͻ�����

	INT					n_keeping;			// ��Ʒ�������ܷ�
	BOOL				bCantDrop;
	
	tagItemProto(){ZeroMemory(this,sizeof(*this));}
	tagItemProto(DWORD dwID){ZeroMemory(this,sizeof(*this)); dw_data_id = dwID;}
};

struct tagEquipProto: public tagItemProto
{
	ETalentType			eTalentType;							// ��������

	DWORD				dwSuitID[MAX_PEREQUIP_SUIT_NUM];		// ��װ���
	BYTE				bySuitMinQlty[MAX_PEREQUIP_SUIT_NUM];	// ���Ʒ��Ҫ��
	//bool				bCanDye;								// ʱװ�Ƿ��Ⱦɫ

	//INT16				n16AttALimit[X_ERA_ATTA_NUM];			// ��������
	
	DWORD				dwVocationLimitWear;					// ����ְҵ����
	DWORD				dwPkValueLimit;							// pkֵ���ܴ���

	EEquipPos			eEquipPos;		// װ��λ��
	//EWeaponPos			eWeaponPos;		// ����λ��

	INT16				n16MinDmg;		// ������С�˺�
	INT16				n16MaxDmg;		// ������˺�
	//INT16				n16MinDmgIn;	// Զ��������С�˺�
	//INT16				n16MaxDmgIn;	// Զ����������˺�
	INT16				n16Armor;		// ���߻���
	//INT16				n16ArmorIn;		// Զ�̷��߻���

	//INT32				nMaxPotVal;		// װ�����Ǳ��ֵ
	//INT32				nPotVal;		// װ��Ǳ��ֵ

	tagRoleAttEffect	BaseEffect[MAX_ROLEATT_BASE_EFFECT];// �ӹ�ǰ��Ӱ�������(��Ʒ���޹�)
	tagRoleAttEffect	RandEffect[MAX_BASE_ATT];			// �������Թ̶�ֵ
	DWORD				dwRandEffectPro[MAX_BASE_ATT];		// �������Գ��ּ���
	//BYTE				byClassLimit[X_ClASS_TYPE_NUM];		// ְҵ����(ָ��ְҵ����)//??

	DWORD				dwTriggerID2;		// ������ID1
	DWORD				dwBuffID2;			// ״̬ID1
	
	//���Ӽ���
	DWORD				dwSkillID[EQUIP_SKILL_NUMBER];

	//DWORD				dwColor;			// ��ɫ

	INT16				n16Newness;			// �;ö�

	//bool				bIdentifyProduct;	// ��������״̬
	//bool				bIdentifyLoot;		// �������״̬
	
	//INT16				n16HolePrice;		//װ����׼۸�
	
	//INT16				n16HolePriceDiff;	//��׼۸񸡶�ϵ��
	
	DWORD				dwPetID;			// ���ID
	
	CHAR				byLuck;				// ����
	
	BYTE				bySuitTriggerCount;	// ��װ��������������

	tagEquipProto(){ZeroMemory(this,sizeof(*this));}
	tagEquipProto(DWORD dwID){ZeroMemory(this, sizeof(*this)); dw_data_id = dwID;}
};

#define MArmorMaxUseTimes(pEquipProto)	((pEquipProto)->n16Newness * ARMORABRASION2USETIMES)
#define MEquipMaxUseTimes(pEquipProto)	((pEquipProto)->n16Newness * ABRASION2USETIMES)
#define MEquipIsRide(pItemProto) ((pItemProto)->eTypeEx == EITE_Ride )
#define MIsWeapon(pItemProto) ((pItemProto)->eTypeReserved == EITR_Weapon && (pItemProto)->eType == EIT_Equip)
//struct tagGemProto		// ǿ����Ʒԭ��
//{
//	DWORD				dw_data_id;		// ��Ʒԭ�ͱ��
//
//	INT16				n16PotValNeed;	// ��Ҫ���ĵ�װ��Ǳ��ֵ
//	INT16				n16SuccessPct;	// �ɹ���
//
//	tagRoleAttEffect	BaseEffect[MAX_ROLEATT_ENHANCE_EFFECT];	// װ��ǿ��Ӱ��
//
//	INT32				nEnhanceFlg;	// ��λ��¼ -- EEnhanceEquipPos
//
//	tagGemProto() { ZeroMemory(this, sizeof(*this)); }
//};

struct tagItem
{
	INT64			n64_serial;		// ��ƷΨһ���к�(��ͬ�ѵ���Ʒ��ͬ)
	DWORD			dw_data_id;		// ������Ʒ������(ͬ����Ʒ��ͬ)

	INT16			n16Num;			// ��Ʒ����
	bool			bLock	: 1;	// ������־
	bool			bUsing	: 1;	// �Ƿ��ڶԸ���Ʒ������������
	bool			bCreateBind;	// ���ɵ�ʱ���Ƿ��
	BYTE			byBind;			// ��״̬
	INT32			nUseTimes;		// ��Ʒ�ϼ���ʹ�ô���

	DWORD			dw_account_id;	// ����˺�ID, �ٱ����ͽ�ɫ�ֿ���(ͬһ�ʺ��½�ɫ����)
	DWORD			dwOwnerID;		// ӵ����, INVALID_VALUE��ʾû��ӵ����

	EItemConType	eConType;		// ��Ʒ������������
	INT16			n16Index;		// ��Ʒ�������е�λ��
	INT16			n16Dummy;		// �ڴ������

	EItemCreateMode	eCreateMode;	// ��Ʒ&װ�����ɷ�ʽ
	DWORD			dwCreateID;		// �ⲿ���ɸ���Ʒ��ID���磺GMID��QuestID��, �����ϲ���ʾ
	
	DWORD			dwCreatorID;	// ��Ʒ�����ߣ�INVALID_VALUE��ʾϵͳ����, ��������ʾ
	tagDWORDTime	dwCreateTime;	// ������Ʒ��ʱ��

	DWORD			dwNameID;		// �䱦����ID

	tagDWORDTime	dw1stGainTime;	// ��һ����һ��ʱ��
	
	tagDWORDTime	dwBindTime;	// ��ʱ��

	EUpdateDBStatus	eStatus;		// ��¼��Ʒ�Ƿ���Ҫ�������ݿ����

	union
	{
		const tagItemProto	*pProtoType;	// ָ����Ʒ��������
		const tagEquipProto	*pEquipProto;	// ִ��װ����������
	};

	const ItemScript		*pScript;		// �ű�ָ��
	DWORD			dw_script_data[2];		// �ű�����
	
	tagItem() { ZeroMemory(this, sizeof(*this)); }
	VOID SetOwner(DWORD dwNewOwnerID, DWORD dwNewAccountID) { dwOwnerID = dwNewOwnerID; dw_account_id = dwNewAccountID; }
	VOID SetPos(EItemConType eNewCon, INT16 n16NewIndex) { eConType = eNewCon; n16Index = n16NewIndex; }
	VOID SetIndex(INT16 n16NewIndex) { n16Index = n16NewIndex; }
	VOID SetUsing(bool bUsingState) { bUsing = bUsingState; }
	VOID SetUpdate(EUpdateDBStatus eNewUpdateStatus) { eStatus = eNewUpdateStatus; }
	INT64 GetKey() const { return n64_serial; }
	INT16 GetNum() const { return n16Num; }
	BOOL CanOverlap() const { return (VALID_POINT(pProtoType) ? pProtoType->n16MaxLapNum > 1 : FALSE); }
	VOID IncUseTimes(INT32 nUse) { nUseTimes += nUse; SetUpdate(EUDBS_Update); }
	BYTE GetQuality() const { return pProtoType->byQuality; }
 
	// �õ�ĳ��������Ӧ��BuffID
	DWORD GetBuffID(INT nIndex)
	{
		switch(nIndex)
		{
		case 0:
			return pProtoType->dwBuffID0;
		case 1:
			return pProtoType->dwBuffID1;
		case 2:
			return pProtoType->dwTransID;
		default:
			return INVALID_VALUE;
		}
	}

	// �õ�ĳ��������Ӧ��TriggerID
	DWORD GetTriggerID(INT nIndex)
	{
		switch(nIndex)
		{
		case 0:
			return pProtoType->dwTriggerID0;
		case 1:
			return pProtoType->dwTriggerID1;
		case 2:
			return pProtoType->dwTransTriggerID;
		default:
			return INVALID_VALUE;
		}
	}

	//VOID Bind()
	//{
	//	SI_ASSERT(VALID_POINT(pProtoType));
	//	switch(pProtoType->byBindType)
	//	{
	//	case EBM_Null:
	//		byBind = EBS_Unbind;
	//		break;
	//	case EBM_Gain:
	//		byBind = EBS_Bind;
	//		break;
	//	}
	//}

	VOID SetBind(EBindStatus bindtype)
	{
		if (byBind == bindtype)
			return;

		byBind = bindtype;
		SetUpdate(EUDBS_Update);	
	}

	VOID SetBindTime(DWORD bindtime)
	{
		dwBindTime = bindtime;
	}

	VOID SetBindTime(const tagDWORDTime& bindtime)
	{
		dwBindTime = bindtime;
		SetUpdate(EUDBS_Update);
	}

	VOID UpdateBind(EBindStatus bindtype , DWORD bindtime)
	{
		byBind = bindtype;
		dwBindTime = bindtime;
	}

	BOOL IsBind() const { return EBS_Unbind != byBind && EBS_Unknown != byBind; }
	BOOL IsLock() const { return bLock;}
	BOOL IsLevelLimit(BYTE byRoleLevel) const
	{
		return pProtoType->byMinUseLevel > byRoleLevel || pProtoType->byMaxUseLevel < byRoleLevel;
	}

	BOOL is_time_limit() const { return pProtoType->dwTimeLimit != INVALID_VALUE; }

};

struct tagEquipSpec
{
	/******�����������******/
	//INT32					nLevel;			// �ȼ�
	//INT32					nCurLevelExp;	// ��ǰ��������

	///******װ������ʱȷ��******/
	//INT16				n16MinDmg;		// ��ս������С�˺�
	//INT16				n16MaxDmg;		// ��ս��������˺�
	//INT16				n16Armor;		// ��ս���߻���
	//
	// ��������
	tagRoleAttEffect	EquipAttitionalAtt[MAX_ADDITIONAL_EFFECT];	
	// ϴ������
	INT32				EquipAttitional[MAX_RAND_ATT];

	CHAR				byLuck;
	// ��������
	//BYTE				bySpecAtt;
	
	/******���������츳******/
	//BYTE				byTalentPoint;//��Ͷ�츳��
	//BYTE				byMaxTalentPoint;//����츳��
	//INT8				byAddTalentPoint;//�����츳��
	//DWORD				dwSkillList[MAX_EQUIP_SKILL_NUM];//�����б�

	// ʹ�õȼ�����(�����ⲿ��������)
	//BYTE				byMinUseLevel;
	//BYTE				byMaxUseLevel;

	// Ʒ��
	BYTE				byQuality;
	INT					nRating;

	/******װ��ǿ��ʱ�޸�******/
	//BYTE				byFlareVal;		// ����

	BYTE				byHoleNum;
	BYTE				byConsolidateLevel;//ǿ���ȼ�

	DWORD				dwHoleGemID[MAX_EQUIPHOLE_NUM];

	/******����******/
	tagEquipSpec() { ZeroMemory(this, sizeof(*this));}

	DWORD getGemNum() const
	{ 
		DWORD dwNum = 0;
		for (int i = 0; i < MAX_EQUIPHOLE_NUM; i++)
		{
			if ( dwHoleGemID[i] != 0 && dwHoleGemID[i] != -1)
			{
				dwNum++;
			}
		}
		return dwNum;
	}
};

struct tagEquip: public tagItem
{
	tagEquipSpec	equipSpec;

	BOOL ExpChange(INT nValue);
	static INT16 GetAddTalent(INT32 beginLevel, INT32 endLevel);
	//VOID LevelChange(INT nValue)
	//{
	//	if( nValue < 0 || nValue > pEquipProto->byMaxLevel )
	//		return;

	//	if( equipSpec.nLevel == nValue ) return;

	//	equipSpec.nLevel = nValue;
	//	equipSpec.nCurLevelExp = 0;
	//}

	//VOID SetFlareVal(BYTE byFlareVal)
	//{
	//	equipSpec.byFlareVal = byFlareVal;
	//}

	//VOID ChangeFlareVal(BYTE byFlareVal)
	//{
	//	equipSpec.byFlareVal += byFlareVal;
	//	equipSpec.byFlareVal = (equipSpec.byFlareVal > 100) ? 100 : equipSpec.byFlareVal;
	//	equipSpec.byFlareVal = (equipSpec.byFlareVal < 0 ) ? 0 : equipSpec.byFlareVal;
	//}

	//VOID ChangePotVal(INT nValue)
	//{
	//	INT nOrgPotVal = equipSpec.nPotVal;
	//	equipSpec.nPotVal += nValue;

	//	if(equipSpec.nPotVal < 0)		equipSpec.nPotVal = 0;

	//	if(equipSpec.nPotVal > pEquipProto->nMaxPotVal)
	//		equipSpec.nPotVal = pEquipProto->nMaxPotVal;

	//	if(nValue < 0)
	//		equipSpec.nPotValUsed += (nOrgPotVal - equipSpec.nPotVal);
	//}
	
	// ��ǰ�;�
	int GetEquipNewness()
	{
		if (pEquipProto->eEquipPos == EEP_RightHand)
		{
			return pEquipProto->n16Newness - nUseTimes / ABRASION2USETIMES;
		}
		else
		{
			return pEquipProto->n16Newness - nUseTimes / ARMORABRASION2USETIMES;
		}
	}
	
	VOID ChangeNewness(INT16 nValue)
	{
		if (pEquipProto->eEquipPos == EEP_RightHand)
		{
			nUseTimes -= (nValue * ABRASION2USETIMES);

			if (nUseTimes > pEquipProto->n16Newness * ABRASION2USETIMES)
			{
				nUseTimes = pEquipProto->n16Newness * ABRASION2USETIMES;
			}
		}
		else
		{
			nUseTimes -= (nValue * ARMORABRASION2USETIMES);

			if (nUseTimes > pEquipProto->n16Newness * ARMORABRASION2USETIMES)
			{
				nUseTimes = pEquipProto->n16Newness * ARMORABRASION2USETIMES;
			}

		}

		if (nUseTimes < 0)
		{
			nUseTimes = 0;
		}
		
	}
	VOID IncAttackTimes()
	{		
		++nUseTimes;

		if(eStatus != EUDBS_Update)
		{
			SetUpdate(EUDBS_Update);
		}
	}

	VOID DecAttackTimes(INT nTimes)
	{
		nUseTimes = min(MEquipMaxUseTimes(pEquipProto), nUseTimes);
		nUseTimes = max(0, nUseTimes - nTimes);

		if(eStatus != EUDBS_Update)
		{
			SetUpdate(EUDBS_Update);
		}
	}

	BOOL IsNewessChange(INT &nCurAttackTimes)
	{

		nCurAttackTimes = MEquipMaxUseTimes(pEquipProto);
		if(nUseTimes > nCurAttackTimes)
		{
			nUseTimes = nCurAttackTimes;
			return FALSE;
		}

		nCurAttackTimes = nUseTimes;
		if(nUseTimes % ABRASION2USETIMES == 0)
		{
			return TRUE;
		}

		return FALSE;
	}
	
	BOOL IsArmorNewessChange(INT &nCurAttackTimes)
	{
		nCurAttackTimes = MArmorMaxUseTimes(pEquipProto);
		if(nUseTimes > nCurAttackTimes)
		{
			nUseTimes = nCurAttackTimes;
			return FALSE;
		}

		nCurAttackTimes = nUseTimes;
		if(nUseTimes % ARMORABRASION2USETIMES == 0)
		{
			return TRUE;
		}

		return FALSE;
	}

	VOID GetTriggerIDBuffID(OUT DWORD &dwTriggerID, OUT DWORD &dwBuffID, IN INT nIndex)
	{
		dwTriggerID = dwBuffID = INVALID_VALUE;

		if(!VALID_POINT(pEquipProto))
		{
			assert(0);
			return;
		}

		switch(nIndex)
		{
		case 0:
			dwTriggerID = pEquipProto->dwTriggerID0;
			dwBuffID	= pEquipProto->dwBuffID0;
			break;
		case 1:
			dwTriggerID = pEquipProto->dwTriggerID1;
			dwBuffID	= pEquipProto->dwBuffID1;
			break;
		case 2:
			dwTriggerID = pEquipProto->dwTriggerID2;
			dwBuffID	= pEquipProto->dwBuffID2;
			break;
		default:
			break;
		}
	}
	

	// ���˶����;�
	INT16 GetNewess() const
	{
		if (pEquipProto->eEquipPos == EEP_RightHand)
		{
			return nUseTimes / ABRASION2USETIMES;
		}
		else
		{
			return nUseTimes / ARMORABRASION2USETIMES;
		}
		
	}
	
	INT16 GetMaxNewess() const
	{
		return pEquipProto->n16Newness;
	}

	//INT16 GetArmorNewess()
	//{
	//	return nUseTimes / ARMORABRASION2USETIMES;
	//}
	
	//�õ��ۼ�
	INT64	GetPrice() const 
	{
		INT64 n64Price = pProtoType->nBasePrice * n16Num;
		FLOAT fFactor = 1.0f;
		MCalPriceFactor(fFactor, equipSpec.byQuality);
		n64Price = (INT64)(n64Price * fFactor);
		if(n64Price < 0)
		{
			assert(0);
			n64Price = 0;
		}
		return n64Price;
	}

	//�õ�����۸�
	INT64	GetRepairPrice() 
	{
		/*FLOAT fp = BASE_REPIAR_PRICE * GetRepairPosParam() * 
			pEquipProto->byLevel * 
			GetRepairQualityParam();*/


		//��װ���ȼ�*װ���ȼ�*(װ��Ʒ��)/2+װ���ȼ�*װ���ȼ�/1*�������ȼ�+��Ƕ��ʯ������^(MAX(1,0.7+װ���ȼ�*0.005��+1
		double fp = pEquipProto->byLevel * pEquipProto->byLevel * (equipSpec.byQuality + 1)/2 + 
			pEquipProto->byLevel * pEquipProto->byLevel * (equipSpec.byConsolidateLevel + equipSpec.getGemNum());
		
		fp = pow(fp, max(1, 0.7 + pEquipProto->byLevel*0.005)) + 1;

		fp = fp / 1600 * GetNewess();

		return (INT64)fp;
	}
	
	FLOAT GetRepairPosParam()
	{
		FLOAT fParam = 0.0f;
		switch (pEquipProto->eEquipPos)
		{
		case EEP_RightHand: fParam = 1.5f; break;
		case EEP_Head: fParam = 1.0f; break;
		case EEP_Body: fParam = 1.3f; break;
		case EEP_Wrist1: fParam = 0.8f; break;
		case EEP_Wrist2: fParam = 0.8f; break;
		case EEP_Waist: fParam = 0.7f; break;
		case EEP_Feet: fParam = 1.0f; break;
		case EEP_Body1: fParam = 1.0f; break;
		case EEP_Neck: fParam = 0.8f; break;
		}

		return fParam;
	}

	FLOAT GetRepairQualityParam()
	{
		FLOAT fParam = 0.0f;
		switch(equipSpec.byQuality)
		{
		case EIQ_Quality0: fParam = 1.0f; break;
		case EIQ_Quality1: fParam = 1.1f; break;
		case EIQ_Quality2: fParam = 1.2f; break;
		case EIQ_Quality3: fParam = 1.3f; break;
		case EIQ_Quality4: fParam = 1.5f; break;
		}

		return fParam;
	}

	VOID ZeroEuqipUseTimes()
	{
		nUseTimes = 0;
		if(eStatus != EUDBS_Update)
		{
			SetUpdate(EUDBS_Update);
		}
	}

	//BOOL HasSkill(DWORD dwSkillID)
	//{
	//	for (int i = 0; i < MAX_EQUIP_SKILL_NUM; i++)
	//	{
	//		if ( dwSkillID == (equipSpec.dwSkillList[i] / 100))
	//			return TRUE;
	//	}
	//	return FALSE;
	//}

	//INT GetSkillLevel(DWORD dwSkillID)
	//{
	//	for (int i = 0; i < MAX_EQUIP_SKILL_NUM; i++)
	//	{
	//		if ( dwSkillID == (equipSpec.dwSkillList[i] / 100))
	//			return equipSpec.dwSkillList[i] % 100;
	//	}

	//	return INVALID_VALUE;
	//}

	//BOOL AddSkill(DWORD dwSkillTypeID)
	//{
	//	if (HasSkill(dwSkillTypeID/100))
	//		return FALSE;

	//	for (int i = 0; i < MAX_EQUIP_SKILL_NUM; i++)
	//	{
	//		if ( equipSpec.dwSkillList[i] == 0)
	//		{
	//			equipSpec.dwSkillList[i] = dwSkillTypeID;
	//			return TRUE;
	//		}
	//	}
	//	return FALSE;
	//}

	//BOOL LevelUpSkill(DWORD dwSkillID)
	//{
	//	for (int i = 0; i < MAX_EQUIP_SKILL_NUM; i++)
	//	{
	//		if ( dwSkillID == (equipSpec.dwSkillList[i] / 100))
	//		{
	//			equipSpec.dwSkillList[i]++;
	//			return TRUE;
	//		}
	//	}
	//	return TRUE;
	//}

	//VOID ClearSkill()
	//{
	//	for (int i = 0; i < MAX_EQUIP_SKILL_NUM; i++)
	//	{
	//		equipSpec.dwSkillList[i] = 0;
	//	}
	//}
	BYTE GetQuality() const { return equipSpec.byQuality; }

	INT GetRating() const;

	//����ǿ���ȼ�Ӱ��
	INT CalConsolidate(INT16 nBaseValue, BYTE byConLevel, float fParam) const
	{
		if (nBaseValue == 0)
			return 0;

		float result = nBaseValue * pow(fParam, byConLevel);

		/*for (BYTE i = 0; i < byConLevel; ++i)
		{
			result = result + (result * fParam);
		}*/

		//result += byConLevel;

		return (int)result;
	}

	//INT GetMinDmg() const 
	//{
	//	//��������=��ʼ����*�����ȼ�/5+�����ȼ�*�����ȼ�/24+4
	//	if (equipSpec.n16MinDmg == 0)
	//		return 0;
	//	
	//	INT	nMinDmg = equipSpec.n16MinDmg;
	//	if (pEquipProto->eEquipPos == EEP_RightHand)
	//	{
	//		nMinDmg =static_cast<INT>(equipSpec.n16MinDmg * equipSpec.nLevel/5.0f + equipSpec.nLevel * equipSpec.nLevel / 24.0f +4.0f) ;
	//	}

	//	/*if (equipSpec.nLevel <=1)
	//	{
	//		nMinDmg = equipSpec.n16MinDmg;
	//	}*/

	//	nMinDmg = CalConsolidate(nMinDmg, equipSpec.byConsolidateLevel, CONSOLIDATE_PARAM) + equipSpec.byConsolidateLevel;
	//	return nMinDmg;
	//}

	//INT GetMaxDmg() const 
	//{
	//	if (equipSpec.n16MaxDmg == 0)
	//		return 0;
	//	
	//	INT nMaxDmg = equipSpec.n16MaxDmg;
	//	if (pEquipProto->eEquipPos == EEP_RightHand)
	//	{
	//		nMaxDmg = static_cast<INT>(equipSpec.n16MaxDmg * equipSpec.nLevel/5.0f + equipSpec.nLevel * equipSpec.nLevel / 24.0f +4.0f);
	//	}
	//	
	//	/*if (equipSpec.nLevel <=1)
	//	{
	//		nMaxDmg = equipSpec.n16MaxDmg;
	//	}*/

	//	nMaxDmg = CalConsolidate(nMaxDmg, equipSpec.byConsolidateLevel, CONSOLIDATE_PARAM) + equipSpec.byConsolidateLevel;
	//	return nMaxDmg;
	//}

	//INT GetArmor() const 
	//{
	//	//  ����=����*(1.15^ǿ���ȼ�)+ǿ���ȼ�*5
	//	if (equipSpec.n16Armor == 0)
	//		return 0;

	//	INT nArmor = CalConsolidate(equipSpec.n16Armor, equipSpec.byConsolidateLevel, CONSOLIDATE_PARAM)+equipSpec.byConsolidateLevel*5;
	//	return nArmor;
	//}
};

// ������Ʒ&װ��(������tagItem��ʹ������������)
static VOID Destroy(tagItem *&pItem)
{
	if(!VALID_POINT(pItem))
	{
		return;
	}
	
	if(MIsEquipment(pItem->dw_data_id))
	{
		delete ((tagEquip*)pItem);
	}
	else
	{
		delete pItem;
	}

	pItem = NULL;
}

// ������Ʒ&װ��(������tagItem��ʹ������������)
static VOID Destroy(tagEquip *&pEquip)
{
	if(!VALID_POINT(pEquip))
	{
		return;
	}

	SAFE_DELETE(pEquip);
}

//-----------------------------------------------------------------------------
// �������� -- �ͽṹ���
//-----------------------------------------------------------------------------
const INT SIZE_ITEM						= sizeof(tagItem);
const INT SIZE_EQUIP					= sizeof(tagEquip);
const INT SIZE_EQUIPSPEC				= sizeof(tagEquipSpec);

struct tagEquipLevelPctProto
{
	INT16				n16Index;			//�ȼ����
	FLOAT				fLevelPct;			//���Լӳ�ϵ�� �������
	FLOAT				fLevelPct2;			//�̶�����ϵ��
	INT					nDerateMin;			//���������Сֵ
	INT					nDerateMax;			//����������ֵ	
	FLOAT				fPosPct[EEP_MaxEquip];//װ����λϵ��
	INT					nMaxAttValue;		//�������ֵ

	tagEquipLevelPctProto(){ZeroMemory(this, sizeof(*this));}
};

//-----------------------------------------------------------------------------
// װ����ʾ��Ϣ
//-----------------------------------------------------------------------------
struct tagEquipViewInfo
{
	DWORD				dw_data_id;
	INT32				nLevel;												//gx modify �����Ϊս����
	BYTE				byConsolidateLevel;									// ǿ���ȼ�
	BYTE				byConsolidateLevelStar;								// ǿ���Ǽ� gx modify �����ΪƷ��
	BYTE				byBind;												// ��״̬
	BYTE				byHoldNum;											// ��Ƕ����
	INT32				nUseTimes;											// ʹ�ô���
	tagRoleAttEffect	EquipAttitionalAtt[MAX_ADDITIONAL_EFFECT];			// ��������
	DWORD				dwHoleGemID[MAX_EQUIPHOLE_NUM];
	INT16				n16MinDmg;											// ��ս������С�˺�
	INT16				n16MaxDmg;											// ��ս��������˺�
	INT16				n16Armor;											// ���߻��� 
};

struct tagEquipViewInfoEx : public tagEquipViewInfo
{
	INT16		n_num;
};


// ��Ʒϵͳ��غ���
class ItemHelper
{
public:
	// ��ȡǿ����������
	static INT GetUpstarsPro(BYTE byLevel)
	{
		INT fpro = 0;
		switch (byLevel)
		{
		case 0:
		case 1:
		case 2:
			fpro = 10000;
			break;
		case 3:
			fpro = 8000;
			break;
		case 4:
			fpro = 6000;
			break;
		case 5:
			fpro = 4000;
			break;
		case 6:
			fpro = 2000;
			break;
		case 7:
		case 8:
			fpro = 1000;
			break;
		case 9:
			fpro = 100;
			break;
		}

		return fpro;
	}

	static INT GetUpstarsAddPro(INT number, BYTE byConsolidateLevel)
	{
		
		if (byConsolidateLevel < 0 || byConsolidateLevel >= MAX_CONSOLIDATE_LEVEL)
			return 0;

		INT nParam[] = {2500, 2000, 1500, 1500, 1100, 700, 300, 800, 600, 400, 200, 400, 300, 200, 100};
		
		return nParam[byConsolidateLevel] * number;
	}

	//ȡ�ô��ʯid
	static DWORD GetChiselTypeID(INT nCurHoldNum)
	{
		DWORD dwTypeID = 0;
		switch(nCurHoldNum)
		{
		case 0: dwTypeID = 4121001; break;
		case 1: dwTypeID = 4121002; break;
		case 2: dwTypeID = 4121003; break;
		case 3: dwTypeID = 4121004; break;
		case 4: dwTypeID = 4121005; break;
		case 5: dwTypeID = 4121006; break;
		default: break;
		}
		return dwTypeID;
	}

	//ȡ��ǿ��ʯid
	static DWORD GetQiangHuaStoneTypeID(INT nCurLevel, bool bAttack )
	{
		if(bAttack)
		{
			if	   (nCurLevel <= 10)	return 4111101;
			else if(nCurLevel <= 20)	return 4111102;
			else if(nCurLevel <= 30)	return 4111103;
			else if(nCurLevel <= 40)	return 4111104;
			else if(nCurLevel <= 50)	return 4111105;
			else if(nCurLevel <= 60)	return 4111106;
			else if(nCurLevel <= 70)	return 4111107;
			else if(nCurLevel <= 80)	return 4111108;
			else if(nCurLevel <= 90)	return 4111109;
			else if(nCurLevel <= 100)	return 4111110;
			else return 0;
		}
		else
		{
			if	   (nCurLevel <= 10)	return 4111201;
			else if(nCurLevel <= 20)	return 4111202;
			else if(nCurLevel <= 30)	return 4111203;
			else if(nCurLevel <= 40)	return 4111204;
			else if(nCurLevel <= 50)	return 4111205;
			else if(nCurLevel <= 60)	return 4111206;
			else if(nCurLevel <= 70)	return 4111207;
			else if(nCurLevel <= 80)	return 4111208;
			else if(nCurLevel <= 90)	return 4111209;
			else if(nCurLevel <= 100)	return 4111210;
			else return 0;
		}
	}

	//ȡ����ʯID
	static DWORD GetShenStoneTypeID(INT nCurLevel)
	{
		if	   (nCurLevel <= 30)	return 4112101;
		else if(nCurLevel <= 50)	return 4112102;
		else if(nCurLevel <= 70)	return 4112103;
		else return 0;
	}

	//ȡ�ù���ʯID
	static DWORD GetGuxingShiTypeID(INT nCurLevel)
	{
		if	   (nCurLevel < 3)		return NULL;
		else if(nCurLevel == 3)		return 4112201;
		else if(nCurLevel == 4)		return 4112202;
		else if(nCurLevel == 5)		return 4112202;
		else if(nCurLevel == 6)		return 4112203;
		else if(nCurLevel == 7)		return 4112204;
		else if(nCurLevel == 8)		return 4112204;
		else if(nCurLevel == 9)		return 4112205;
		else if(nCurLevel == 10)	return NULL;
		else return 0;
	}

	//ȡ��npc���������������id
	static DWORD GetProduceQualityID(INT nCurLevel, BYTE byQuality)
	{
		if (nCurLevel <= 30)		
		{
			switch(byQuality)
			{
			case 2: return 3420201;
			case 3: return 3420206;
			}
		}
		else if(nCurLevel <= 40)	
		{
			switch(byQuality)
			{
			case 2: return 3420202;
			case 3: return 3420207;
			}
		}
		else if(nCurLevel <= 50)
		{
			switch(byQuality)
			{
			case 2: return 3420203;
			case 3: return 3420208;
			}
		}
		else if(nCurLevel <= 60)
		{
			switch(byQuality)
			{
			case 2: return 3420204;
			case 3: return 3420209;
			}
		}
		else if(nCurLevel <= 70)
		{
			switch(byQuality)
			{
			case 2: return 3420205;
			case 3: return 3420210;
			}
		}
		return 0;
	}
	//ȡ��npc�����������������������
	static INT GetProduceQualityAttValue(INT nCurLevel, BYTE byQuality)
	{
		if (nCurLevel <= 30)		
		{
			switch(byQuality)
			{
			case 2: return 1;
			case 3: return 2;
			}
		}
		else if(nCurLevel <= 40)	
		{
			switch(byQuality)
			{
			case 2: return 2;
			case 3: return 3;
			}
		}
		else if(nCurLevel <= 50)
		{
			switch(byQuality)
			{
			case 2: return 3;
			case 3: return 4;
			}
		}
		else if(nCurLevel <= 60)
		{
			switch(byQuality)
			{
			case 2: return 4;
			case 3: return 5;
			}
		}
		else if(nCurLevel <= 70)
		{
			switch(byQuality)
			{
			case 2: return 5;
			case 3: return 6;
			}
		}
		return 0;
	}
	//ȡ��npc��������������������������ֵ
	static INT GetProduceQualityAttValueMax(INT nCurLevel)
	{
		if (nCurLevel < 20)
			return 1;
		else if (nCurLevel < 30)
			return 2;
		else if (nCurLevel < 40)
			return 3;
		else if (nCurLevel < 50)
			return 4;
		else if (nCurLevel < 60)
			return 7;
		else if (nCurLevel < 70)
			return 9;

		return 11;
	}

	// ȡ������ǿ�����ʯID
	static DWORD GetRideUpgradeSoulStoneTypeID( INT nCurLevel )
	{
		switch(nCurLevel)
		{
		case 0:
		case 1:
		case 2:
			return 4211001;
			break;
		case 3:
		case 4:
		case 5:
			return 4211002;
			break;
		case 6:
		case 7:
		case 8:
			return 4211003;
			break;
		case 9: return 4211004; break;
		default: return 4211004; break;
		}
	}

	// ��������ںϵ�id
	static DWORD GetFusionDanTypeID( /*INT nCurLevel*/ )
	{
		return 4150001;
	}

	// ȡ��������ʯID
	static DWORD GetRideUpgradeGodStoneTypeID()
	{
		return 4212001;
	}

	static BYTE GetQuality(const tagItem* pItem) 
	{
		if (MIsEquipment(pItem->dw_data_id))
		{
			return ((const tagEquip*)pItem)->GetQuality();
		}
		return pItem->GetQuality();
	}
	
	// ��ȡװ����������Ԫ������
	static INT GetEquipReattYuanbao(INT nLevel)
	{
		if (nLevel>=45 && nLevel <= 50)
		{
			return 50;
		}
		if (nLevel>50 && nLevel <= 55)
		{
			return 250;
		}
		if (nLevel>55 && nLevel <= 60)
		{
			return 450;
		}
		if (nLevel>60 && nLevel <= 65)
		{
			return 650;
		}
		if (nLevel>65 && nLevel <= 70)
		{
			return 850;
		}
		return 0;
	}

	// ��ȡװ����������ǿ������
	static INT GetEquipReattStar(INT nLevel)
	{
		if (nLevel>=45 && nLevel <= 50)
		{
			return 0;
		}
		if (nLevel>50 && nLevel <= 55)
		{
			return 4;
		}
		if (nLevel>55 && nLevel <= 60)
		{
			return 7;
		}
		if (nLevel>60 && nLevel <= 65)
		{
			return 7;
		}
		if (nLevel>65 && nLevel <= 70)
		{
			return 7;
		}
		return 0;
	}

	// ϴ��ս������
	static INT32 GetXiliExplios(BYTE byEquipLevel)
	{
		if (byEquipLevel >= 30 && byEquipLevel < 40)
		{
			return 50;
		}
		if (byEquipLevel >= 40 && byEquipLevel < 50)
		{
			return 200;
		}
		if (byEquipLevel >= 50 && byEquipLevel < 60)
		{
			return 800;
		}
		if (byEquipLevel >= 60 && byEquipLevel < 70)
		{
			return 1500;
		}
		if (byEquipLevel >= 70)
		{
			return 2000;
		}
		return 0;
	}

	static double getQianghuaQualityParam(BYTE byQuality)
	{
		return pow(2.0, byQuality*1.0);
	}

	static int getQianghuaParam(BYTE byStar)
	{
		if (byStar >= 0 && byStar <=2)
		{
			return 10;
		}
		if (byStar >= 3 && byStar <=5)
		{
			return 20;
		}
		if (byStar >= 6 && byStar <=8)
		{
			return 30;
		}
		if (byStar >= 9)
		{
			return 100;
		}

		return 0;
	}

	// ��ħ������������ֵ
	static int getShipinFumoAttAdd(ERoleAttribute era)
	{
		INT nParam = 1;
		if ((era >= ERA_Physique && era <= ERA_Agility) || era == ERA_ExDefense)
		{
			return 1 * nParam;
		}
		else if (era == ERA_ExAttack)
		{
			return 10 * nParam;
		}
		else
		{
			return 2 * nParam;
		}
	}

	// ��ħ��������Ʒ������ֵ
	static VOID getShipinFumoAttCritAdd(BYTE byQuality, INT& nMin, INT& nMax)
	{
		switch(byQuality)
		{
		case 1:
			{
				nMin = 1;
				nMax = 2;
			}
			
			break;
		case 2:
			{
				nMin = 1;
				nMax = 3;
			}
			break;
		case 3:
			{
				nMin = 2;
				nMax = 4;
			}
			break;
		}
	}

	static INT32 getConsolidateAtt(INT32 nAttValue, BYTE byConsolidate)
	{
		if (byConsolidate<=0 || byConsolidate > MAX_CONSOLIDATE_LEVEL)
			return 0;

		INT nParam[] = {300, 600, 900, 1400, 1900, 2400, 2900, 3500, 4100, 4700, 5300, 5900, 6500, 7200, 8000};
	
		return max(byConsolidate, nAttValue * (nParam[byConsolidate - 1] / 10000.0));
	}
};

// ���װ����Ϣ
struct tagEquipTeamInfo
{
	INT32 n32_ConsolidateNum;		// װ����ǿ������
	INT32 n32_InlayNum;				// װ������Ƕ����
	INT32 n32_Rating;				// װ��������
};
//
static INT GetMountSpellTimeDelta( BYTE bySolidateLevel )
{
	if(bySolidateLevel < 4) return 0;
	if(bySolidateLevel < 7) return -500;
	if(bySolidateLevel < 10) return -1000;
	return -1500;
}
//-----------------------------------------------------------------------------
#pragma pack(pop)
