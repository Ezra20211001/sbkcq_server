/************************************************************************/
/*  backkom 2012-09-12 VIP                                                                     */
/************************************************************************/

#ifndef __VIP_DEFINE_H__
#define __VIP_DEFINE_H__

#pragma pack(push,1)

#define VIP_MAKE_EQUIP_NONPC_LEVEL_MIN 2
//gx modify 2013.8.14
struct vip_proto{
	// VIP特权
	int vip_level;
	// 双修
	int compractice_add;
	// 修罗试炼
	int xiuluoshilian_add;
	// 魔物狩猎
	int mowushoulie_add;
	// 行会烧香
	int hanghuishaoxiang_add;
	// 饮酒
	int wine_add;
	// 天命问运
	int tianming_add;
	// 焰火屠魔
	int yanhuotumo_add;
	// 免费坐骑培养
	int zuojipeiyang_add;
	// 心有灵犀
	int xinyoulixi_add;
	// 比武
	int biwu_cold;
	// VIP时限 单位 天
	int vip_time;
	//// 需要多少钱
	//int need_yuanbao;
	//// 单人环随机免费刷新次数 
	//int quest_fresh_add;
	//// 增加 每日公会签到次数
	//int guild_checkin;
	//// 每使用1颗月石打造装备额外增加 成功率
	//int make_equip_prob;
	//// 装备强化成功率提升
	//int equip_consolidate_prob;
	//// 坐骑强化成功率提升
	//int ride_consolidate_prob;
	//// 每日获得免费洗礼机会
	//int xili_add;
	//// 公会材料捐款数量增加 
	//int guild_juancailiao;
	//// 公会资金捐款次数增加 
	//int guild_juankuan;
	//// 灵气上限增加
	//int lingqi_max;
	//// 炼魂次数附加值
	//int lianhuen_time;
	//// 炼金N-B型/ 炼金小叮当 折扣
	//float make_equip_priceoff;
	vip_proto(){ memset(this, 0, sizeof(*this));}
};

enum EVIPVType
{
	VIP_LEVEL,//等级
	NEED_YUABAO,
	QUEST_REFRESH,
	GUILD_CHECKIN,
	MAKE_EQUIP_PROB,
	CONSOLIDATE_EQUIP_PROB,
	CONSOLIDATE_RIDE_PROB,
	XILI_ADD,
	GUILD_JUANKUAN,
	MAKE_EQUIP_PRICEOFF,
	GUILD_JUANCAILAO,
	LINGQI_MAX,
	LIANHUEN_TIME_MAX,

	/*gx add 2013.8.14*/
	COMPRACTICE_ADD,// 双修
	XIULUOSHILIAN_ADD,// 修罗试炼
	MOWUSHOULIE_ADD,// 魔物狩猎
	HANGHUISHAOXIANG_ADD,// 行会烧香
	WINE_ADD,// 饮酒
	TIANMING_ADD,// 天命问运
	YANHUOTUMO_ADD,// 焰火屠魔
	ZUOJIPEIYANG_ADD,// 免费坐骑培养
	XINYOULINXI,// 心有灵犀
	BIWU_COLD,// 比武
	VIP_TIME// VIP时限
	//END
};

template<class T> T 
GetVIPV(const vip_proto *proto, EVIPVType type)
{
	if(!VALID_POINT(proto)) return T(0);
	switch(type)
	{
		case VIP_LEVEL:
			return (T)proto->vip_level;
			break;
		case COMPRACTICE_ADD:
			return (T)proto->compractice_add;
			break;
		case XIULUOSHILIAN_ADD:
			return (T)proto->xiuluoshilian_add;
			break;
		case MOWUSHOULIE_ADD:
			return (T)proto->mowushoulie_add;
			break;
		case HANGHUISHAOXIANG_ADD:
			return (T)proto->hanghuishaoxiang_add;
			break;
		case WINE_ADD:
			return (T)proto->wine_add;
			break;
		case TIANMING_ADD:
			return (T)proto->tianming_add;
			break;
		case YANHUOTUMO_ADD:
			return (T)proto->yanhuotumo_add;
			break;
		case VIP_TIME:
			return (T)proto->vip_time;
			break;
	}
	return T(0);
}

#define GET_VIP_EXTVAL(VIP_Level, ValueT, T)\
	GetVIPV<T>(AttRes::GetInstance()->GetVipProto(VIP_Level), (ValueT))


#pragma pack(pop)

#endif /* __VIP_DEFINE_H__ */