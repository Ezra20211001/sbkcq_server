/*******************************************************************************

 Copyright 2010 by tiankong Interactive Game Co., Ltd.
 All rights reserved.
 
 This software is the confidential and proprietary information of
 tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
 not disclose such Confidential Information and shall use it only in
 accordance with the terms of the license agreement you entered into with
 tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef __GUERDON_QUEST_DEFINE_H__
#define __GUERDON_QUEST_DEFINE_H__

#pragma pack(push,1)

#define MAXPUTOUTQUESTHOUR  24     // �����ʱ��
#define TAKEQUESTFOREGIFTSILVER  (GOLD2SILVER*20)	// ��ȡʱ��Ѻ��20��
#define HANDLINGCHARGESILVER (SILVER2COPPER*5)		// ��ȡʱ������5��
#define PUTOUTSHANDLECHARGE	 (SILVER2COPPER*20)		// ����������20��
#define MAXGDQUEST 5        // �������������
#define TAKEQUESTCOSTVIGOUR 5      // ��ȡ�۳�Ԫ��ֵ 
#define TAKEGDQUESTMINLEVEL 25  // ��ȡ�����������С�ȼ�

struct tagItem;

enum EGuerdonQuestState
{
 EGQS_WaitForInit = 0,
 EGQS_WaitForTake,
 EGQS_WaitForFinish,
};

// ����-���ݿ�
struct guerdon_quest
{
 // 64λID
 INT64 n64Serial;
 // ����ID
 UINT16 u16QuestID;
 // ������RoleID
 DWORD dwSender;
 // �ӵ���RoleID
 DWORD dwReciver;
 // ���ޱ����
 BOOL  bGuildFix;
 // ����ʱ��
 DWORD dwEndTime;
 // ״̬
 EGuerdonQuestState eState;
 // Ԫ��
 INT16 u16YuanBao;
// ��Ʒ��Ϣ<ֻ��Mgr����>
 // ����1
 tagItem* pItem0;
 // ����2
 tagItem* pItem1;
public:
 guerdon_quest(){ZeroMemory(this,sizeof(*this));}
public:
 static INT64 MakeSerial(DWORD dwSender, UINT u16QuestID){ return (INT64)((INT64)dwSender << 32 | u16QuestID);}
 INT64 GetSerial() const { return n64Serial;}
 BOOL Assert() const {return ((n64Serial >> 32) == dwSender) && ((UINT16)n64Serial == u16QuestID);}
};

// ������-�ͻ���
struct guerdon_quest_data
{
 // 64λID
 INT64 n64Serial;
 // ����ID
 UINT16 u16QuestID;
 // ������RoleID
 DWORD dwSender;
 // �ӵ���RoleID
 DWORD dwReciver;
 // ���ޱ����
 BOOL  bGuildFix;
 // Ԫ��
 INT16 u16YuanBao;
 // ����ʱ��
 DWORD dwEndTime;
 // ����1<TypeID>
 DWORD dwItem0;
 INT16 n16Number0;
 // ����2<TypeID>
 DWORD dwItem1;
 INT16 n16Number1;
};

// ������������Ʒ���
inline BOOL GDQuestRewardCheck(DWORD dw_data_id)
{
	 switch (dw_data_id)
	 {
		 case 4132001: // ����ʯ��Ƭ
		 case 4132002: // ����ʯ
		 case 3320001: // ���
		 case 3320002: // �������
		 case 5400001: // ��ζ��
		 case 5400002: // Ұ�˸���
		 case 5400003: // ��ζ�ز�
		 case 5400004: // μ��з
		 case 5400005: // ��������
		 case 5400006: // ����
		 case 5400007: // ��͢������
		 case 4150001: // �ںϵ�
		 case 4140004: // ϴ��ˮ
		 case 2300201: // 1��������
		 case 2300202: // 2��������
		 case 2300203: // 3��������
		 case 2300204: // 4��������
		 case 2300205: // 5��������
		 case 2300206: // 6��������
		 case 2300207: // 7��������
		 case 2300208: // 8��������
		 case 2400015: // 1��˫�����鵤
		 case 2400016: // 2��˫�����鵤
		 case 2400017: // 3��˫�����鵤
		 case 2400018: // 4��˫�����鵤
		 case 5300007: // ����ᾧ
			return TRUE;
	 }
	 return FALSE;
}

#pragma pack(pop)


#endif //__GUERDON_QUEST_DEFINE_H__