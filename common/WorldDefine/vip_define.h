/************************************************************************/
/*  backkom 2012-09-12 VIP                                                                     */
/************************************************************************/

#ifndef __VIP_DEFINE_H__
#define __VIP_DEFINE_H__

#pragma pack(push,1)

#define VIP_MAKE_EQUIP_NONPC_LEVEL_MIN 2
//gx modify 2013.8.14
struct vip_proto{
	// VIP��Ȩ
	int vip_level;
	// ˫��
	int compractice_add;
	// ��������
	int xiuluoshilian_add;
	// ħ������
	int mowushoulie_add;
	// �л�����
	int hanghuishaoxiang_add;
	// ����
	int wine_add;
	// ��������
	int tianming_add;
	// �����ħ
	int yanhuotumo_add;
	// �����������
	int zuojipeiyang_add;
	// ������Ϭ
	int xinyoulixi_add;
	// ����
	int biwu_cold;
	// VIPʱ�� ��λ ��
	int vip_time;
	//// ��Ҫ����Ǯ
	//int need_yuanbao;
	//// ���˻�������ˢ�´��� 
	//int quest_fresh_add;
	//// ���� ÿ�չ���ǩ������
	//int guild_checkin;
	//// ÿʹ��1����ʯ����װ���������� �ɹ���
	//int make_equip_prob;
	//// װ��ǿ���ɹ�������
	//int equip_consolidate_prob;
	//// ����ǿ���ɹ�������
	//int ride_consolidate_prob;
	//// ÿ�ջ�����ϴ�����
	//int xili_add;
	//// ������Ͼ���������� 
	//int guild_juancailiao;
	//// �����ʽ���������� 
	//int guild_juankuan;
	//// ������������
	//int lingqi_max;
	//// �����������ֵ
	//int lianhuen_time;
	//// ����N-B��/ ����С���� �ۿ�
	//float make_equip_priceoff;
	vip_proto(){ memset(this, 0, sizeof(*this));}
};

enum EVIPVType
{
	VIP_LEVEL,//�ȼ�
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
	COMPRACTICE_ADD,// ˫��
	XIULUOSHILIAN_ADD,// ��������
	MOWUSHOULIE_ADD,// ħ������
	HANGHUISHAOXIANG_ADD,// �л�����
	WINE_ADD,// ����
	TIANMING_ADD,// ��������
	YANHUOTUMO_ADD,// �����ħ
	ZUOJIPEIYANG_ADD,// �����������
	XINYOULINXI,// ������Ϭ
	BIWU_COLD,// ����
	VIP_TIME// VIPʱ��
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