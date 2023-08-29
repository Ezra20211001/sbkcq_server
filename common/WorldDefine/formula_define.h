#pragma once


#include "ItemDefine.h"



class FormulaHelper
{
public:
	//修理收费公式
	static INT64 GetEquipRepairPrice(const tagEquip* pEquip)
	{ 
		return 100 * pEquip->GetNewess();;
	}
	//打孔收费
	static INT64 GetEquipChisePrice(const tagEquip* pEquip)
	{
		////打孔收费=MAX(1,(装备等级*装备等级*装备等级/30000)^(MAX(1,(0.6+装备等级/60))))*(品质系数+1)^2*（当前孔数+1）^2
		BYTE byLevel = pEquip->pEquipProto->byLevel;
		INT nTime = pEquip->equipSpec.byHoleNum;
		double dTemp1 = (double)(pow(byLevel*byLevel*byLevel/30000.0, max(1, 0.6+byLevel/60.0)));
		INT64 nConSilver = (INT64)(max(1, dTemp1)*pow(pEquip->equipSpec.byQuality+1.0, 2)*pow(nTime+1.0, 2));

		return nConSilver;
	}
	
	//强化收费
	static INT64 GetEquipConsolidatePrice(const tagEquip* pEquip)
	{
		//强化系数*强化星数*（1+品质系数/5）*装备等级
		BYTE byLevel = pEquip->pEquipProto->byLevel;

		INT64 nConSilver = (INT64)(ItemHelper::getQianghuaParam(pEquip->equipSpec.byConsolidateLevel) * (pEquip->equipSpec.byConsolidateLevel + 1) *
			(1+ItemHelper::getQianghuaQualityParam(pEquip->equipSpec.byQuality) / 5.0 ) * byLevel);

		return nConSilver;
	}

	//打造收费
	static INT64 GetEquipProducePrice(const tagEquipProto* pEquipProto)
	{
		INT64 nSilver = (INT64)(pow((double)pEquipProto->byMinUseLevel, 2));

		return nSilver;
	}
	
	//原地满血复活
	static INT32 GetRolePerfectionReviveYuanbao(INT nRoleLevel)
	{
		INT32 n32_yuanbao = max(nRoleLevel * nRoleLevel * nRoleLevel / 10000, 1);

		return n32_yuanbao;
	}
	//原地半血复活
	static INT64 GetRoleLocusReviveSivler(INT nRoleLevel)
	{
		INT64 n_Money = max(nRoleLevel * nRoleLevel* nRoleLevel / 1.3, 96);

		return n_Money;
	}
	//回城复活
	static INT64 GetRoleCityReviveSivler(INT nRoleLevel)
	{
		INT64 n_Money = nRoleLevel * nRoleLevel* nRoleLevel / 10;

		return n_Money;
	}
};