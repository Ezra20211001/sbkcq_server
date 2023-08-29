/*******************************************************************************

	Copyright 2010 by Shengshi Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	Shengshi Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	Shengshi Interactive  Co., Ltd.

*******************************************************************************/

/**
 *	@file		hearchat_protocol
 *	@author		mwh
 *	@date		2011/05/23	initial
 *	@version	0.0.1.0
 *	@brief		����Ƶ������
*/

#define  ROLE_COMEBACK_HEARSAY_TIME_SEC (30 * 24 * 3600)

enum EHearSayType
{
	EHST_START = 0,
	//! dwParam0��typeid 
	//! dwParam1��0,ʷʫ 1����˵
	//! װ��������Ϣ
	EHST_EQUIPUPGRADE = 0, // ���� gx modify 2013.7.20
	
	//! dwroleid:�з�ID
	//! dwParam0��Ů��ID 
	//! ��鴫��
	EHST_MARRAIAGE = 1, // ��� gx modify 2013.7.20

	//! dwParam0��typeid
	//! Я��װ����Ϣ
	EHST_EQUIPPRODUCE = 2, // װ������

	//! dwParam0��typeid 
	//! dwParam1�������Ʒ����
	EHST_EQUIPCOMPOSE = 3, // װ�����

	//! dwParam0��������ﵱǰ����
	//! gx modify 2013.11.11
	EHST_RIDEUPGRADE = 4, // ��������ȫ������
	
	//! dwParam0��PKֵ
	EHST_PKVALUE = 5,				// PK�仯

	//! dwParam0��׷ɱĿ��ID
	//! dwParam1��׷ɱ��TYPEID
	EHST_USEKILLBAGAGE = 6, // ʹ��׷ɱ��

	//! dwParam0����װTPYEID
	//! dwParam1��BOSSID
	//! Я��װ����Ϣ<����dwParam0����>
	EHST_KILLBOSSGETITEM = 7, // ɱBOSS����װ

	//! dwParam0:װ��ID
	//! dwParam1:ǿ���ȼ�
	EHST_EQUIPSTRENGTH = 8,			// װ��ǿ�� gx modify 2013.7.20

	EHST_CREATEGUILD	=		9,		// �������

	//! dwParam0������typeid
	//! dwParam1��Ԫ������
	EHST_BAOXIANGYUANBAO	=	10,		// ������Ԫ��

	//! dwParam0��guildid
	//! dwParam1������ 0 �ڼ� 1 ����
	//! p_buffer: �������
	EHST_GUILDFIRSTKILL		=	11,		//����սռ��ɳ�Ϳ�

	//! dwParam0: Last Login Time
	EHST_ROLEBACK30DAYS		=	12,		// 30���ػ���Ϸ�Ĵ���

	//! dwParam0��x
	//! dwParam1��y
	//! dwParam2��z
	//! dwParam3: mapid
	EHST_PURPUREPOS = 13,			// ����λ��

	//! dwParam0��roleid
	EHST_PURPUREBEKILLED = 14,			// ������ɱ

	//! dwParam0 �ID
	//! �״̬ : 1:��ʼ;0������
	EHST_ACTIVITY = 15, 

	//! dwParam0��stringMsg.xml �е�id
	EHST_activity			=	16,		// �ȫ������

	//! dwParam0��mapid	
	//! dwParam1:1������
	EHST_USE_ITEM		=	17,		// ʹ�õ������Ч��Ʒ gx modify 2013.8.23


	//! dwParam0:�ƺ�����
	//!
	EHST_TITLE_NOTICE =	18,		//�ƺ�ͷ�� gx modify 2013.7.20

	
	//! dwParam0����Ʒid
	//! dwParam1����������  0��һ�Ƚ� 1�����Ƚ�
	//! dwParam2������	   0:a      1:b
	EHST_Lottery			=	19,		// ��Ʊ�����

	//! dwParam0:2������3���׽�4������
	//!  dwParam1:����ID
	EHST_BAOXIANGITEM = 20,//gx modify 2013.8.15 VIP ȫ������

	//!  dwParam0:����ID
	//!  dwParam1:�����ۼƽ��
	EHST_ConsumeRewardItem = 21,

	//!  dwParam0:�ں�ǰƷ��
	//!  dwParam1:1 �ɹ� 0 ʧ��
	EHST_Ronghe_pet = 22,
	
	//!  dwParam0:deadId
	EHST_GuildMap_Kill = 23,
	
	//gx modify 2013.6.27
	//!  dwParam0:������roleID
	EHST_LianHuen = 24,		//��������ֵ
	//end

	//gx add 2013.10.29
	//!  dwParam0:itemtypeid
	EHST_SPECIAL_ITEM_USED = 25,//������Ʒʹ��ȫ�����棬���๫���Ҫͳһ������ʽ

	//!  dwParam0:��ʤroleID
	EHST_ACTIVITY_BIWU_WIN = 26,//���侺������ʤ����

	EHST_MAX
};

struct HearSayChannel 
{
	//! ��ϢԴ
	DWORD dwRoleID;

	//! �ο�����ע�����
	DWORD dwParam0;
	DWORD dwParam1;
	DWORD dwParam2;
	DWORD dwParam3;

	//! ֻ������Ƶ����ʾ
	BOOL bChatChannel;

	//! ��Ϣ����
	EHearSayType eType;
};

// ����Ƶ����Ϣ
struct NET_SIS_HearSayChannel : public tag_net_message
{
	NET_SIS_HearSayChannel()
	{
		ZeroMemory(this, sizeof(*this));
		dw_message_id = message_id_crc("NET_SIS_HearSayChannel");
		dw_size = sizeof(*this);
	}
	HearSayChannel stData;
	CHAR cBuffer[1]; // ����Ҫ��װ����Ϣ
};