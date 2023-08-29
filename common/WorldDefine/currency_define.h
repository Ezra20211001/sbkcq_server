//-----------------------------------------------------------------------------
//★Name				:   currency_define.h
//★Compiler			:	Microsoft Visual C++ 9.0Sxg
//★Version				:	1.00
//★Create Date			:	2008-08-14
//★LastModified		:	
//★Brief				:	货币系统中常量定义
//-----------------------------------------------------------------------------
#pragma once


//-----------------------------------------------------------------------------
// 常量
//-----------------------------------------------------------------------------
const INT32 GOLD2SILVER					= 10000;
const INT32 SILVER2COPPER				= 100;

const INT32 MAX_BAG_YUANBAO_NUM			= 999999;
const INT32 MAX_BAG_GOLD_NUM			= 999999;
const INT64 MAX_BAG_SILVER_NUM			= (INT64)MAX_BAG_GOLD_NUM * GOLD2SILVER + (GOLD2SILVER - 1);

const INT32 MAX_BAIBAO_YUANBAO_NUM		= 999999;
const INT32 MAX_WARE_GOLD_NUM			= 999999;
const INT64 MAX_WARE_SILVER_NUM			= (INT64)MAX_WARE_GOLD_NUM * GOLD2SILVER + (GOLD2SILVER - 1);

const INT64 MAX_EXCHANGE_VOLUME_NUM		= 2000000000;
const INT32 MAX_EXPLOITS				= 100000000;

const DWORD MAX_PAIMAI_VOLUME_NUM		= 50000000;
const DWORD MAX_BANK_MONEY				= 50000000;
const DWORD MIN_BANK_MONEY				= 100000;
const INT32 MAX_BANK_YUANBAO			= 5000;
const INT32 MIN_BANK_YUANBAO			= 10;

#define  MAX_GOLD_DISPLAY  999999
#define  MAX_OTHER_DISPLAY  99
//-----------------------------------------------------------------------------
// 宏
//-----------------------------------------------------------------------------
#define MGold2Silver(n_gold_)				((INT64)(n_gold_) * GOLD2SILVER)
#define MSilver2Copper(n_silver_)			((INT64)(n_silver_) * SILVER2COPPER)

#define MSilver2DBGold(n64_silver)		(INT32)((n64_silver) / GOLD2SILVER)
#define MSilver2DBSilver(n64_silver)		(INT32)(((n64_silver) % GOLD2SILVER) / SILVER2COPPER)
#define MSilver2DBCopper(n64_silver)		(INT32)(((n64_silver) % GOLD2SILVER) % SILVER2COPPER)

//-----------------------------------------------------------------------------
// 结构
//-----------------------------------------------------------------------------

// 金钱
struct tagMoney 
{
	INT		nGold;
	INT		nSilver;
};


//游戏货币 输入和显示的转换
struct GameCurrency
{
	GameCurrency(INT64 money_):
	money((money_ > MAX_BAG_SILVER_NUM) ?  MAX_BAG_SILVER_NUM :money_)
	{
		copper = (short)(money%SILVER2COPPER);
		silver = (short)(money%GOLD2SILVER/SILVER2COPPER);
		gold =(DWORD) (money/GOLD2SILVER);
	}

	GameCurrency(DWORD gold_,short silver_,short copper_):
	gold((gold_ >MAX_GOLD_DISPLAY)? MAX_GOLD_DISPLAY:gold_),
	silver((silver_ >MAX_OTHER_DISPLAY)? MAX_OTHER_DISPLAY:silver_),
	copper((copper_ >MAX_OTHER_DISPLAY)? MAX_OTHER_DISPLAY:copper_)
	{
		money= static_cast<INT64>(gold)*GOLD2SILVER +  static_cast<INT64>(silver)*SILVER2COPPER+static_cast<INT64>(copper);
	}

	GameCurrency& operator =(const GameCurrency& other)
	{
		money = other.money;
		copper = other.copper;
		silver = other.silver;
		gold = other.gold;

		return *this;
	}

	GameCurrency& operator =(INT64 money_)
	{
		money =(money_ > MAX_BAG_SILVER_NUM) ? MAX_BAG_SILVER_NUM :money_;
		copper = (short)(money%SILVER2COPPER);
		silver = (short)(money%GOLD2SILVER/SILVER2COPPER);
		gold =(DWORD) (money/GOLD2SILVER);

		return *this;
	}

	INT64	money;
	short	copper;
	short	silver;
	DWORD	gold;
};

//提供货币显示的字符串，用于label_ext控件
inline tstring const get_currency_string(__int64 money_)
{
	tstringstream ss;
	GameCurrency gc(money_);
	if (money_>0)
	{
		if(gc.gold)
			ss<<gc.gold<<_T("<pic=data\\ui\\Common_now\\icon_gold.png,0,0,15,15>");
		if(gc.silver)
			ss<<gc.silver<<_T("<pic=data\\ui\\Common_now\\icon_silver.png,0,0,15,15>");
		if(gc.copper)
			ss<<gc.copper<<_T("<pic=data\\ui\\Common_now\\icon_copper.png,0,0,15,15>");
	}
	else if (money_ ==0)
	{
		ss<<gc.copper<<_T("<pic=data\\ui\\Common_now\\icon_copper.png,0,0,15,15>");
	}

	return ss.str();
}

inline tstring const get_currency_string_ex(__int64 money_)
{
	tstringstream ss;
	GameCurrency gc(money_);
	if (money_>0)
	{
		if(gc.gold)
			ss<<gc.gold<<_T("<pic=data\\ui\\Common_now\\icon_gold.png,0,0,15,15>");
		if(gc.silver)
			ss<<gc.silver<<_T("<pic=data\\ui\\Common_now\\icon_silver.png,0,0,15,15>");
		if(gc.copper)
			ss<<gc.copper<<_T("<pic=data\\ui\\Common_now\\icon_copper.png,0,0,15,15>");
		return ss.str();
	}
	else
		return _T("");
}

inline tstring const get_yuanbao_string(int yuanbao_)
{
	tstringstream ss;
	if(yuanbao_>0)
	{
		ss<<yuanbao_<<_T("<pic=data\\ui\\Bag\\treasure .png,0,0,16,16>");
		return ss.str();
	}
	else
		return _T("");
}