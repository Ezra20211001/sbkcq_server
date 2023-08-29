#pragma once

#pragma pack(push, 1)

const INT MAX_FRIENDNUM					= 100;		// ����������
const INT MAX_BLACKLIST					= 20;		// �����������
const INT MAX_FRIENDVAL					= 25920;	// ���Ѷ����ֵ
const INT MAX_ENEMYNUM					= 50;		// ���������
const INT GIFT_STORE_TIME				= 60 * TICK_PER_SECOND;	// �����ڹܵ��ﱣ��ʱ��
const INT ADD_FRIENDVALUE_COUNT			= 300 * TICK_PER_SECOND;
const INT TEAM_BUFF_ID					= 6100001;	// ����buffid
#define SEND_GIFT_NEED_ITEM 1400027		//��õ��typeID gx add 2013.6.27
const INT MAX_COMPRACTICENUM			= 2;		//���ÿ�����ɽ���˫�޴���
const INT COMPRACTICE_EXP_TICKS			= 25;		//25��ticks����5�룩�����һ�ξ���
const INT COMPRACTICE_WHOLE_TICKS		= 900;		//˫��һ�γ�����tick����
const INT COMPRACTICE_MAX_DISTANCE		= 48;		//˫����Զ���룬һ������
const INT MARRY_MIN_LEVEL				= 35;		//�����͵ȼ�
#define MARRY_NEED_ITEM		1300018		//���������ĵ���ID
const INT DIVORCE_NEED_GOLD			= 5000000;		//������ĵĽ���� 500��
#define MARRY_TRANS_ITEM	1400112		//���󷢷Ÿ����޵Ľ�����
const INT REDZUI_FLAG_INDEX				= 10;		//��ҽű�����ָ��촽��ǵ�����
const INT QBJJ_MARRAY_INDEX_WOMAN		= 11;		//��Ƚ��Ů���콱����
const INT QBJJ_MARRAY_INDEX_MAN			= 12;		//��Ƚ��Ů�������콱����
const INT QBJJ_REWARD_LEVEL_MIN			= 45;		//��ȡ��Ƚ�ά������С��ҵȼ�
const INT QBJJ_REWARD_LEVEL_MAX			= 80;		//��ȡ��Ƚ�ά���������ҵȼ�
struct tagFriend
{
	DWORD	dwFriendID;								// ����ID
	DWORD	dwFriVal;								// ���Ѷ�
	BYTE	byGroup;								// ����
	tagFriend():dwFriendID(INVALID_VALUE),dwFriVal(0),byGroup(1){}
};

struct tagFriendInfo
{
	DWORD	dwFriendID;								// ����ID
	DWORD	dwFriVal;								// ���Ѷ�
	BYTE	byGroup;								// ����
	BOOL    bOnline;								// �����Ƿ�����
	INT		nLevel;									// ��ɫ�ȼ�
	EClassType	 eClassType;						// ְҵ
	BYTE	bySex;									// �Ա�
};

struct tagBlackInfo
{
	DWORD	dwBlackID;								// ������ID
	INT		nLevel;									// �ȼ�
	EClassType	eClassType;							// ְҵ
	BYTE	bySex;
};

struct tagEnemyInfo
{
	DWORD	dwEnemyID;								// ����ID
	INT		nLevel;									// �ȼ�
	EClassType eClassType;							// ְҵ
	BYTE	bySex;
};

struct tagSendGift				
{
	DWORD	dwSrcRoleID;							// ������
	DWORD	dwDestRoleID;							// ������
	DWORD	dw_data_id;								// ����TypeID
	INT 	nStoreTick;								// ����ʱ��
	tagSendGift(DWORD dwSrcRoleID, DWORD dwDestRoleID, DWORD dw_data_id):
		dwSrcRoleID(dwSrcRoleID),dwDestRoleID(dwDestRoleID),dw_data_id(dw_data_id)
	{
		nStoreTick = GIFT_STORE_TIME;
	}
};

struct tagFriUpdate
{
	DWORD   dw_role_id;								// ����ID
	BOOL	bOnline;								// �Ƿ�����
	INT		nLevel;									// �ȼ�
};

#pragma pack(pop)