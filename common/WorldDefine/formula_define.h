#pragma once


#include "ItemDefine.h"



class FormulaHelper
{
public:
	//�����շѹ�ʽ
	static INT64 GetEquipRepairPrice(const tagEquip* pEquip)
	{ 
		return 100 * pEquip->GetNewess();;
	}
	//����շ�
	static INT64 GetEquipChisePrice(const tagEquip* pEquip)
	{
		////����շ�=MAX(1,(װ���ȼ�*װ���ȼ�*װ���ȼ�/30000)^(MAX(1,(0.6+װ���ȼ�/60))))*(Ʒ��ϵ��+1)^2*����ǰ����+1��^2
		BYTE byLevel = pEquip->pEquipProto->byLevel;
		INT nTime = pEquip->equipSpec.byHoleNum;
		double dTemp1 = (double)(pow(byLevel*byLevel*byLevel/30000.0, max(1, 0.6+byLevel/60.0)));
		INT64 nConSilver = (INT64)(max(1, dTemp1)*pow(pEquip->equipSpec.byQuality+1.0, 2)*pow(nTime+1.0, 2));

		return nConSilver;
	}
	
	//ǿ���շ�
	static INT64 GetEquipConsolidatePrice(const tagEquip* pEquip)
	{
		//ǿ��ϵ��*ǿ������*��1+Ʒ��ϵ��/5��*װ���ȼ�
		BYTE byLevel = pEquip->pEquipProto->byLevel;

		INT64 nConSilver = (INT64)(ItemHelper::getQianghuaParam(pEquip->equipSpec.byConsolidateLevel) * (pEquip->equipSpec.byConsolidateLevel + 1) *
			(1+ItemHelper::getQianghuaQualityParam(pEquip->equipSpec.byQuality) / 5.0 ) * byLevel);

		return nConSilver;
	}

	//�����շ�
	static INT64 GetEquipProducePrice(const tagEquipProto* pEquipProto)
	{
		INT64 nSilver = (INT64)(pow((double)pEquipProto->byMinUseLevel, 2));

		return nSilver;
	}
	
	//ԭ����Ѫ����
	static INT32 GetRolePerfectionReviveYuanbao(INT nRoleLevel)
	{
		INT32 n32_yuanbao = max(nRoleLevel * nRoleLevel * nRoleLevel / 10000, 1);

		return n32_yuanbao;
	}
	//ԭ�ذ�Ѫ����
	static INT64 GetRoleLocusReviveSivler(INT nRoleLevel)
	{
		INT64 n_Money = max(nRoleLevel * nRoleLevel* nRoleLevel / 1.3, 96);

		return n_Money;
	}
	//�سǸ���
	static INT64 GetRoleCityReviveSivler(INT nRoleLevel)
	{
		INT64 n_Money = nRoleLevel * nRoleLevel* nRoleLevel / 10;

		return n_Money;
	}
};