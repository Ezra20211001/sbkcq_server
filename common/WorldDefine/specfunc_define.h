#pragma once


#pragma pack(push, 1)

//------------------------------------------------------------------------------
// ��Ʒ���⹦�����Ͷ���
//------------------------------------------------------------------------------

/** \��Ʒ���⹦������(�ô���<val1, val2>��ʾ��2������,<val>��ʾ1��,û��ע����ʾû��)
*/
enum EItemSpecFunc	
{
	EISF_Null										= 0,	// ��

	EISF_AcceptQuest								= 1,	// ��ȡ����
	// nSpecFuncVal1: ������
	// nSpecFuncVal2: ����
	EISF_IdetifyEquip								= 2,	// ����װ��
	// nSpecFuncVal1: 0:��ͨ 1:�߼� 2:ʷʫ 3:��˵
	// nSpecFuncVal2: 
	EISF_HoleGem									= 3,    // ��Ƕ
	// nSpecFuncVal1: װ����С�ȼ�
	// nSpecFuncVal2: װ�����ȼ�
	EISF_Luck										= 4,	// ף����
	// nSpecFuncVal1: 0 �ͼ� 1 �߼�
	// nSpecFuncVal2: ����
	EISF_RemoveAttPt								= 6,	// ����ϴ��
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����.

	EISF_RemoveTalentPt								= 7,	// ����ϴ��
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EISF_LearnSkill									= 8,	// ѧϰ����
	// nSpecFuncVal1: ����ID
	// nSpecFuncVal2: ����
	EISF_Grind										= 9,	// �޸���ˮ
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EISF_ComposeAdvance								= 10,	// ǿ������
	// nSpecFuncVal1: ��Сǿ���ȼ�	
	// nSpecFuncVal2: ���ǿ���ȼ�
	EISF_OpenSafeGuard								= 11,	// ǿ��PK����
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EISF_RevieveItem								= 12,	// �������
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EISF_FriendGift									= 13,	// ��������
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EISF_Chisel										= 15,	// ���
	// nSpecFuncVal1: ��������
	// nSpecFuncVal2: ���ȼ�
	EISF_ProtectSign								= 16,	// ǿ������ʯ
	// nSpecFuncVal1: ǿ���ȼ���С
	// nSpecFuncVal2: ǿ���ȼ����
	EISF_Chest										= 17,	// ����
	// nSpecFuncVal1: ���俪������Ʒ(�����)
	// nSpecFuncVal2: Կ�׵�TypeID
	EISF_ChestKey									= 18,	// ����Կ��
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����

	//EISF_Chest*                                     = 19,   // ���䱣��
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����

	EISF_PetEgg										= 20,	// ���ﵰ
	// nSpecFuncVal1: ԭ��ID
	// nSpecFuncVal2: ����
	EISF_PetFood									= 21,	// ����ʳ��
	// nSpecFuncVal1: Я���ȼ�
	// nSpecFuncVal2: ����ֵ
	EISF_PetSkillBook								= 22,	// ���＼����
	// nSpecFuncVal1: ����ԭ��ID
	// nSpecFuncVal2: ����
	EISF_PetLvlupStep								= 23,	// ��������
	// nSpecFuncVal1: ��׺�Ҫ��������ֵ
	// nSpecFuncVal2: ����
	EISF_PetEquipment                               = 24,	// ����װ��
	// nSpecFuncVal1: װ��ԭ��ID
	// nSpecFuncVal2: ����
	EISF_ColorProbability                           = 25,   // ָ����ɫ�׶μ�������
	// nSpecFuncVal1: ����1-4���ɵ͵��߷ֱ��ʾ�ĸ���ɫϡ�г̶Ƚ׶Σ��ͣ��У��ߣ�����
	// nSpecFuncVal2: 1-10000����ʾ��ָ���׶εļ��ʵ������̶ȣ�10000��ʾ����100%��
	EISF_Dye                                        = 26,   // Ⱦ��
	// nSpecFuncVal1: 1-12����Ӧ��ɫ��ͼ���
	// nSpecFuncVal2: ����
	EISF_CreateGuild								= 27,	// �������
	// nSpecFuncVal1: 
	// nSpecFuncVal2: 

	EISF_LeagueSkillBook							= 28,	// ���弼�ܵ伮
	// nSpecFuncVal1: �Ͻ�ʱ��������������
	// nSpecFuncVal2: ���幱��������

	EISF_PetExpPour									= 29,	// ���ﾭ���ע
	// nSpecFuncVal1: ��ע����ֵ
	// nSpecFuncVal2: ����
	EISF_PetEnhance									= 30,	// ������������
	// nSpecFuncVal1: ���޵�Ʒ��
	// nSpecFuncVal2: �������ֵ
	EISF_EquipLock									= 31,	// װ������
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EISF_EquipUnLock								= 32,	// װ������
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EISF_PetLock									= 33,	// ��������
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EISF_PetUnLock									= 34,	// �������
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EISF_Repair										= 35,   //ά��
	// nSpecFuncVal1: ά����Ʒ������ֵ
	// nSpecFuncVal2: ����ά��װ����Ʒ��
	EISF_Easy										= 36,	//����
	// nSpecFuncVal1: ���ý��͵ĵȼ�
	// nSpecFuncVal2: ����
	EIST_Unbeset									= 37,	//��Ƕ
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EIST_ShengPin									= 38,	//��Ʒ
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EIST_EquipProduce								= 39,	//װ���ϳ�
	// nSpecFuncVal1: �䷽ID
	// nSpecFuncVal2: ��Ҫ�ĺϳɱ���Ʒ
	EIST_ShengXing									= 40,	//����
	// nSpecFuncVal1: ������Ʒ�ȼ�
	// nSpecFuncVal2: 0������ǿ�� 1������ǿ��
	//	EISF_		= ,	// 
	EIST_Sing										= 41,   // ǩ��
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EIST_Delate										= 42,	// ����
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����

	EIST_RideEquip									= 43,	// ����װ��	
	// nSpecFuncVal1: ���������ٶȱ�����1-10000��
	// nSpecFuncVal2: ����

	EIST_GodStone									= 44,	//��ʯ(��������ǿ������)
	// nSpecFuncVal1: �������ʣ�1-10000��
	// nSpecFuncVal2: ����

	EIST_SoulStone									= 45,	//����ʯ(����ǿ��ר��)
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����

	EIST_CrushStone									= 46,	//ĥ��ʯ(�����ĥר��)
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����

	EIST_PRACTICE									= 47,	//���������õ���
	// nSpecFuncVal1: 0:���� 1:��ֵ
	// nSpecFuncVal2: �Ӷ���	
	EIST_Hang										= 48,	// ���߹һ���ҩ
	// nSpecFuncVal1: ��������ֵ
	// nSpecFuncVal2: ��������ֵ
	EIST_Exp										= 49,	// ���鵤
	// nSpecFuncVal1: ��������ֵ
	// nSpecFuncVal2: ����
	EIST_Brother									= 50,	// ������
	// nSpecFuncVal1: ��������ֵ
	// nSpecFuncVal2: ����
	EIST_SpePetItem									= 51,	// �����������
	// nSpecFuncVal1: 0:��������� 1�����������ͨ���� 2:�����ͨ��buff���� 3:����س�
	// nSpecFuncVal2: ����
	EIST_EquipBind									= 52,	// װ����
	// nSpecFuncVal1: ������������
	// nSpecFuncVal2: ����������ֵ
	EIST_EquipUnBind								= 53,	// װ�����
	// nSpecFuncVal1: 0:װ����� 1:������
	// nSpecFuncVal2: ����
	EIST_BagExtand									= 54,	// ��������
	// nSpecFuncVal1: 0 ���� 1 �ֿ�
	// nSpecFuncVal2: �������
	EIST_WeaponFusion								= 55,	// �����ںϵȼ�������
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EIST_Killbadge									= 56,	// ׷ɱ��
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����	
	EIST_Produce_Picture							= 57,	// �ϳ�ͼֽ
	// nSpecFuncVal1: �䷽ID
	// nSpecFuncVal2: ����Ʒ��						
	EIST_QuestBind									= 58,
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EIST_ProduceBox									= 59,	// ���챦��
	// nSpecFuncVal1: �ȼ�
	// nSpecFuncVal2: ���� 0 ���� 1 ����
	EIST_GuildTrans									= 60,	// ��ᴫ�ͷ�
	// nSpecFuncVal1: ����
	// nSpecFuncVal2: ����
	EIST_FishingRod									= 61,	// ���
	// nSpecFuncVal1: ����������
	// nSpecFuncVal2: ����ɹ���������
	EIST_Bait										= 62,	// ���
	// nSpecFuncVal1: 0 ���� ����ID
	// nSpecFuncVal2:  ��������
	EIST_ReAtt_Equip								= 63,	// ����װ������
	// nSpecFuncVal1: װ����͵ȼ�����
	// nSpecFuncVal2: װ����ߵȼ�����
	EIST_Pet_Change									= 64,	// �����ɱ䵤
	// nSpecFuncVal1: ��Ҫ����ȼ�
	// nSpecFuncVal2: 
	EIST_Pet_Fusion									= 65,	// �����ں�
	// nSpecFuncVal1: 0 ��Ԫ�� 1 ��Ԫ�� 2 ��Ԫ��
	// nSpecFuncVal2:	
	EIST_Equip_Get_Wuhuen							= 66,	// ��ȡ������
	// nSpecFuncVal1: ��ȡ���� ��ֱ�
	// nSpecFuncVal2:
	EIST_Equip_fumo									= 67,	// ��Ʒ��ħ����������
	// nSpecFuncVal1: ��߶��� ��ֱ�
	// nSpecFuncVal2:
	EIST_Equip_shipin								= 68,	// δ������Ʒ
	// nSpecFuncVal1: ��ɫ��Ʒid
	// nSpecFuncVal2: ��ɫ��Ʒid
	EIST_Guild_mianzhan								= 69,	// �����ս��
	// nSpecFuncVal1: 
	// nSpecFuncVal2: 
	EIST_Pet_Roborn									= 70,	// ���︴��
	// nSpecFuncVal1: Ʒ��
	// nSpecFuncVal2: 

	EIST_Lottery_key								= 71,	// ��Ʊ�������
	// nSpecFuncVal1: 0:a�� 1:b��
	// nSpecFuncVal2: ����
};	


/** \�ϳɼ��������� EISF_ComposeAdvance �������������
*/
enum ESpecFuncComposeAdvance			
{
	ESFCA_AllProduce		= 0,	// ����������������
	ESFCA_Artisan,					// �ɽ�
	ESFCA_DanTraining,				// ����
	ESFCA_Smith,					// ����
	ESFCA_Casting,					// ����
	ESFCA_Dressmaker,				// �÷�
	ESFCA_Aechnics,					// ����
	ESFCA_Smilt,					// ұ��

	EISFC_AllConsolidate	= 10,	// ����װ��ǿ����������
	EISFC_Posy,						// ����
	EISFC_Engrave,					// �Կ�
	EISFC_Quench,					// ���
	EISFC_ShengXing,				// ����
	EISFC_Fusion,					// �ں�

	EISFC_All				= 20,	// ���кϳɶ������� 
};


#pragma pack(pop)
