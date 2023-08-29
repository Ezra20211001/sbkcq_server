//--------------------------------------------------------------------------------------------
//★Name				:   shop_define.h
//★Compiler			:	Microsoft Visual C++ 9.0
//★Version				:	1.00
//★Create Date			:	2008-10-22
//★LastModified		:	
//★Brief				:	商店相关定义
//--------------------------------------------------------------------------------------------
#pragma once

#include "../WorldDefine/ItemDefine.h"
#include "../WorldDefine/cost_type_define.h"

#pragma pack(push, 1)
//-----------------------------------------------------------------------------
// 常量
//-----------------------------------------------------------------------------
const INT MAX_SHOP_SHELF_NUM		= 4;	// 商店界面最大Tab页数
const INT MAX_SHOP_COMMON_ITEM		= 100;	// 出售的最大普通物品类型数
const INT MAX_SHOP_RARE_ITEM		= 30;	// 出售的最大稀有物品类型数
const INT MAX_SHOP_ONE_SHELF		= 14;	// 单页货架格数
const INT MAX_SHOP_TOTAL_ITEM		= MAX_SHOP_COMMON_ITEM + MAX_SHOP_RARE_ITEM;

//-----------------------------------------------------------------------------
// 枚举
//-----------------------------------------------------------------------------
// 商品类型(稀有商品有刷新时间等)
enum EShopItemType
{
	ESIT_Normal 		= 0, 	// 普通商品
	ESIT_Rare 			= 1, 	// 稀有商品
};

//-----------------------------------------------------------------------------
// 数据结构
//-----------------------------------------------------------------------------
// 普通商品
struct tagShopItemProto
{
	DWORD				dw_data_id;   	// 固定商品ID
	INT32				nSilver;		// 消耗金钱数
	INT32				nCostNum;		// 特殊消耗
	BYTE				byRepLevel;		// 声望阶段要求
	BYTE				byShelf;		// 所属分页

	tagShopItemProto() { ZeroMemory(this, sizeof(*this)); dw_data_id = INVALID_VALUE; }
};

// 稀有商品 -- 修改该结构时，注意前面部分字段顺序要和结构tagShopItemProto一致
struct tagShopRareItemProto
{
	DWORD				dw_data_id;   	// 固定商品ID
	INT32				nSilver;		// 消耗金钱数
	INT32				nCostNum;		// 特殊消耗
	BYTE				byRepLevel;		// 声望阶段要求
	BYTE				byShelf;		// 所属分页
	BYTE				byQuality;		// 刷新品质
	BYTE				byRefreshNum;	// 刷新数量
	DWORD				dwRefreshTime;	// 刷新时间间隔(单位: 秒)

	tagShopRareItemProto() { ZeroMemory(this, sizeof(*this)); dw_data_id = INVALID_VALUE; }
};

// 商店静态结构
struct tagShopProto
{
	DWORD					dwID;							// 商店编号
	ECurCostType			eCostType;						// 商店特殊消耗类型
	DWORD					dwItemTypeID;					// 兑换所需物品typeid
	INT16					n16Num[MAX_SHOP_SHELF_NUM];		// 第x页中商品个数
	// tbc:
	BOOL					bClanTreasury;					// 氏族宝库
	BOOL					bEquip;							// 是: 出售的全部是装备
															// 否: 不出售装备
	BOOL					bBind;							// 出售的物品是否绑定
	BOOL					bRandAtt;						// 装备属性是否随机

	tagShopItemProto		Item[MAX_SHOP_COMMON_ITEM];		// 普通商品
	tagShopRareItemProto	RareItem[MAX_SHOP_RARE_ITEM];	// 限量(稀有)商品
};

// 客户端用商品静态结构
struct tagShopProtoClient : public tagShopProto
{
	TCHAR					szName[X_SHORT_NAME];						// 商店名称
	TCHAR					szShelf[MAX_SHOP_SHELF_NUM][X_SHORT_NAME];	// 货架1名称
	tstring					szPicName;									// 商店title的图片名称
};

// 物品(非装备)结构
struct tagShopItem
{
	DWORD					dw_data_id;		// 物品Type ID
	INT16					n16RemainNum;	// 该值为INVALID_VALUE时，表示该商品不限量
	INT16					n16Index;		// 服务器中物品下标
	BYTE					byProtoIndex;	// 商品原型索引
	DWORD					dwRefreshTime;	// 上次刷新时间(单位：秒)
	
	union	// 对应的静态结构，访问稀有商品中和普通商品相同的字段时，也可以直接用pProto -- 修改时应注意
	{
		const tagShopItemProto		*pProto;
		const tagShopRareItemProto	*pRareProto;
	};
	
	// 容器模版用的接口定义
	DWORD GetKey() const { return dw_data_id; }
	INT16 GetNum() const { return n16RemainNum != INVALID_VALUE ? n16RemainNum : 1; }
	VOID SetPos(EItemConType eNewCon, INT16 n16NewIndex) { n16Index = n16NewIndex; }
	VOID SetUpdate(EUpdateDBStatus eNewUpdateStatus) { return; }
};

// 装备结构
struct tagShopEquip
{
	tagEquip				*pEquip;		// 生成的装备
	INT16					n16RemainNum;	// 该值为INVALID_VALUE时，表示该商品不限量
	INT16					n16Index;		// 服务器中物品下标
	BYTE					byProtoIndex;	// 商品原型索引
	DWORD					dwRefreshTime;	// 上次刷新时间(单位：秒)

	union	// 对应的静态结构，访问稀有商品中和普通商品相同的字段时，也可以直接用pProto -- 修改时应注意
	{
		const tagShopItemProto		*pProto;
		const tagShopRareItemProto	*pRareProto;
	};

	// 容器模版用的接口定义
	DWORD GetKey() const {		return VALID_VALUE(n16RemainNum) ? pRareProto->dw_data_id : pProto->dw_data_id; 	}
	INT16 GetNum() const { return n16RemainNum != INVALID_VALUE ? n16RemainNum : 1; }
	VOID SetPos(EItemConType eNewCon, INT16 n16NewIndex) { n16Index = n16NewIndex; }
	VOID SetUpdate(EUpdateDBStatus eNewUpdateStatus) { return; }
};

// 氏族珍宝(非装备)结构
struct tagTreasuryItem:public tagShopItem
{
	DWORD	dwNameID;		// 名字ID
	VOID	SetAct(DWORD dwNameID)
	{
		this->dwNameID = dwNameID;
	}
	BOOL	IsAct() const
	{
		return VALID_VALUE(dwNameID);
	}
};

// 氏族珍宝(装备)结构
struct tagTreasuryEquip:public tagShopEquip
{
	DWORD	dwNameID;		// 名字ID
	VOID	SetAct(DWORD dwNameID)
	{
		this->dwNameID = dwNameID;
	}
	BOOL	IsAct() const
	{
		return VALID_VALUE(dwNameID);
	}
};


// 物品(非装备)结构 -- 给客户端发送消息用
struct tagMsgShopItem
{
	DWORD					dw_data_id;		// 物品Type ID
	INT16					n16RemainNum;	// 该值为INVALID_VALUE时，表示该商品不限量
	INT16					n16Index;		// 服务器中物品下标
	BYTE					byProtoIndex;	// 商品原型索引
};

// 装备结构 -- 给客户端发送消息用
struct tagMsgShopEquip
{
	tagEquip				Equip;			// 生成的装备
	INT16					n16RemainNum;	// 该值为INVALID_VALUE时，表示该商品不限量
	INT16					n16Index;		// 服务器中物品下标
	BYTE					byProtoIndex;	// 商品原型索引
};

// 物品价格结构
struct tagItemCost
{
	INT64					n64CostSilver;		// 金钱
	ECurCostType			eCostType;			// 特殊价格类型
	int						nCostNum;			// 特殊价格
	INT16					nRepLevel;			// 声望级别
	DWORD					dwCostItemTypeID;	// 消耗物品原型ID

	tagItemCost(){n64CostSilver = nCostNum = nRepLevel = 0; eCostType = ECCT_Null;dwCostItemTypeID = INVALID_VALUE;}
	tagItemCost(INT nSilver, ECurCostType eType, INT n_num, INT nRep, DWORD dwID)
	{n64CostSilver = nSilver; nCostNum = n_num; nRepLevel = nRep; eCostType = eType; dwCostItemTypeID = dwID;}
};

static VOID Destroy(tagShopItem *pItem)
{
	SAFE_DELETE(pItem);
}

static VOID Destroy(tagShopEquip *pItem)
{
	SAFE_DELETE(pItem);
}

//-----------------------------------------------------------------------------
// 宏
//-----------------------------------------------------------------------------
// 判断商品是否为稀有(刷新)商品
#define MIsShopRareGoods(pShopGoods)		(pShopGoods->n16RemainNum != INVALID_VALUE)




//-----------------------------------------------------------------------------
#pragma pack(pop) 