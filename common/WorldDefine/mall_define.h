//--------------------------------------------------------------------------------------------
//★Name				:   mall_define.h
//★Compiler			:	Microsoft Visual C++ 9.0
//★Version				:	1.00
//★Create Date			:	2009-1-5
//★LastModified		:	
//★Brief				:	商城相关定义
//--------------------------------------------------------------------------------------------
#pragma once

#pragma pack(push, 1)
//--------------------------------------------------------------------------------------------
// 常量
//--------------------------------------------------------------------------------------------
const INT MALL_PACK_ITEM_NUM		= 5;	// 物品包中最多物品种类数

const INT	Max_LeaveWord_Length		= 20;	//留言20个字
const INT	MAX_PromoteItem			= 5;	//推荐商品个数
const INT64 MAX_YB_NUM				= 9999999;		// 元宝交易账户最大元宝数
const INT64 MAX_SILVER_NUM			= 9999999999;	// 元宝交易账户最大银币数
const INT   Exchange_Goods_Index    = 5;		//需要荣誉点兑换的商品所在的sheet索引
//--------------------------------------------------------------------------------------------
// 静态结构
//--------------------------------------------------------------------------------------------
struct tagMallItemProtoBase
{
	DWORD			dwID;							// ID
	INT				nPrice;							// 定价
	INT				nSalePrice;						// 促销价
	DWORD			dwTimeSaleStart;				// 促销开始时间
	DWORD			dwTimeSaleEnd;					// 促销截止时间
	DWORD			dwSaleBegin;					// 上架时间
	DWORD			dwSaleEnd;						// 下架时间 
	DWORD			dwPresentID;					// 赠品ID
	BYTE			byNum;							// 待售数量
	BYTE			byPresentNum;					// 赠品数量
	BYTE			byExAssign;						// 赠送赠点数量
	BYTE			byExNum;						// 需要赠点数量
	BYTE			bySmallGroupHeadcount;			// 小型团购人数 
	BYTE			bySmallGroupDiscount;			// 小型团购折扣[0，100]
	BYTE			byMediumGroupHeadcount;			// 中型团购人数
	BYTE			byMediumGroupDiscount;			// 中型团购折扣
	BYTE			byBigGroupHeadcount;			// 大型团购人数
	BYTE			byBigGroupDiscount;				// 大型团购折扣
	bool			bNew	: 1;					// 是否为新品
	bool			bHot	: 1;					// 是否热销
	BYTE			byIndexInServer;				// 在服务器中的位置
	DWORD			dwPersistTime;					// 团购持续时间
};


struct tagMallItemProto: public tagMallItemProtoBase
{
	DWORD			dw_data_id;						// 物品TypeID
	INT8			n8Kind;							// 所属分类
	BYTE			byRank;							// 热销排名
	BYTE			byGroupPurchaseAmount;			// 团购数量
	BYTE			byDummy[1];
};

struct tagMallPackProto: public tagMallItemProtoBase
{
	DWORD			dw_data_id[MALL_PACK_ITEM_NUM];	// 物品ID
	INT				nItemPrice[MALL_PACK_ITEM_NUM];	// 各个物品价格(总价)
	BYTE			byItemNum[MALL_PACK_ITEM_NUM];	// 物品个数
	INT8			n8ItemKind;						// 物品种类(ID)个数
	BYTE			byDummy[2];
	tagMallPackProto()
	{
		ZeroMemory(this, sizeof(*this));
		for(INT i=0; i<MALL_PACK_ITEM_NUM; ++i)
		{
			dw_data_id[i] = INVALID_VALUE;
		}
	}
};

struct tagMallFreeItem
{
	DWORD		dw_data_id;	// 物品ID
	INT			nUnitPrice;	// 原单价
	BYTE		byNum;		// 领取个数

	tagMallFreeItem()
	{
		Clear();
	}

	VOID Clear()
	{
		dw_data_id	= INVALID_VALUE;
		nUnitPrice	= 0;
		byNum		= 0;
	}
};

//--------------------------------------------------------------------------------------------
// 服务器数据结构
//--------------------------------------------------------------------------------------------
//struct tagMallGoods
//{
//	DWORD	dwID;		// 商品或礼品包ID
//	BYTE	byCurNum;	// 当前待售数量(INVALID_VALUE表示不限量)
//	BYTE	byDummy[3];
//};

struct tagMallGoods
{
	union
	{
		const tagMallItemProto	*pMallItem;
		const tagMallPackProto	*pMallPack;
		const tagMallFreeItem	*pMallFreeItem;
	};

	BYTE	byCurNum;	// 当前待售数量(INVALID_VALUE表示不限量)
	BYTE	byDummy[3];
};

//--------------------------------------------------------------------------------------------
// 客户端与服务器商品个数同步结构
//--------------------------------------------------------------------------------------------
struct tagMallUpdate
{
	DWORD		dwID;					//商品ID
	BYTE		byRemainNum;			//剩余个数
};

//--------------------------------------------------------------------------------------------
// 帮派团购
//--------------------------------------------------------------------------------------------
enum EGPSCOPE
{
	EGPS_NULL		= -1,
	EGPS_SMALL,							//小型团购
	EGPS_MEDIUM,						//中型团购
	EGPS_BIG,							//大型团购
};

struct tagGroupPurchase
{
	DWORD			dwGuildID;			//帮派ID
	DWORD			dw_role_id;			//发起者ID
	DWORD			dwMallID;			//商品ID
	INT32			nPrice;				//团购价格
	INT16			nParticipatorNum;	//响应人数
	INT16			nRequireNum;		//团购所需人数
	DWORD			dwRemainTime;		//剩余时间
	package_list<DWORD>*	listParticipators;	//响应者列表

	tagGroupPurchase()
	{
		ZeroMemory(this, sizeof(*this));
	}

	~tagGroupPurchase()
	{
		SAFE_DELETE(listParticipators);
	}
};

enum EYBOTYPE							//元宝订单类型
{
	EYBOT_BUY,							//收购
	EYBOT_SELL,							//寄售
};

enum EYBOMODE							//元宝交易状态
{
	EYBOM_Submit,						//委托中
	EYBOM_Cancel,						//撤销
	EYBOM_Close,						//关闭
};

//--------------------------------------------------------------------------------------------
// 元宝交易订单
//--------------------------------------------------------------------------------------------
struct tagYuanBaoOrder
{
	DWORD				dwID;					//订单ID
	DWORD				dw_role_id;				//玩家ID
	EYBOTYPE			eYBOType;				//订单类型
	INT					nPrice;					//单价
	INT					n_count;					//数量
	EYBOMODE			eYBOMode;				//元宝交易状态
	tagDWORDTime		dwStartTime;			//开始时间
	tagDWORDTime		dwEndTime;				//结束时间
	INT					nAvgPrice;				//成交均价
	INT					nDealNum;				//成交数量
	tagYuanBaoOrder()
	{
		ZeroMemory(this, sizeof(*this));
		dwID = INVALID_VALUE;
		dwStartTime = INVALID_VALUE;
		dwEndTime = INVALID_VALUE;
	}

	INT		GetRemainNum() { return n_count - nDealNum; }	
};

//--------------------------------------------------------------------------------------------
// 创建元宝交易订单(插入数据库时使用）
//--------------------------------------------------------------------------------------------
struct tagYBOrder
{
	DWORD				dwID;
	DWORD				dw_role_id;
	INT16				nType;
	INT					nPrice;
	INT					n_count;
	INT16				nYBMode;
	DWORD				dwStartTime;
	tagYBOrder()
	{
		ZeroMemory(this, sizeof(*this));
		dwID = INVALID_VALUE;
		dwStartTime = INVALID_VALUE;
	}
};

// 元宝交易价格列表
struct tagYBPriceList
{
	INT					nPrice;
	INT					n_num;
};
 
// 元宝交易账户
struct tagYBAccount
{
	DWORD				dw_role_id;				//玩家ID
	INT					nYuanBao;				//元宝数量
	INT					nGold;					//金币数量
	INT					nSilver;				//银币数量
	BOOL				bSellOrder;				//是否有出售订单
	BOOL				bBuyOrder;				//是否有收购订单
};

// 撤销或关闭元宝交易订单
struct tagCompleteOrder
{
	DWORD				dwID;
	INT16				nYBOMode;
	DWORD				dwEndTime;
	tagCompleteOrder()
	{
		ZeroMemory(this, sizeof(*this));
		dwID = INVALID_VALUE;
		dwEndTime = INVALID_VALUE;
	}
};

// 更新元宝交易订单
struct tagRefresh
{	
	DWORD				dwID;
	INT					nAvgPrice;
	INT					nDealNum;
	tagRefresh()
	{
		ZeroMemory(this, sizeof(*this));
		dwID = INVALID_VALUE;
	}
};



//--------------------------------------------------------------------------------------------
#pragma pack(pop)