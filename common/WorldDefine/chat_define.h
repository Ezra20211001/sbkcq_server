#pragma once

#pragma pack(push, 1)

//������췢��Ƶ��
enum ESendChatChannel
{
	ESCC_NULL = -1,
	ESCC_Common = 0,		//��ͨ
	ESCC_Secret,			//����
	ESCC_Team,				//����
	ESCC_Guild,				//����
	ESCC_Map,				//����
	ESCC_World,				//����
	ESCC_Qianli,			//ǧ�ﴫ��

	ESCC_Decree,			//�Ѹ�
	ESCC_Hearsay,			//����
	ESCC_Combat,			//ս��
	ESCC_Affiche,			//����
	ESCC_GM,				//GM
	ESCC_System,			//ϵͳ
	
	ESCC_SiLiao,			//˽��
	ESCC_System_Online_Remain,
	ESCC_System_No_System,
	ESCC_System_White,
	ESCC_System_White_Yellow,
	ESCC_System_White_Green,
	ESCC_System_White_Pink,
	ESCC_System_White_Purple,
	ESCC_Red_Cue,

	ESCC_End,	
};

//����Ƶ��ʱ����
const INT WORLD_CHANNEL_INTERVAL = TICK_PER_SECOND * 5;

//����Ƶ����Ϣ��������
const INT WORLD_CHANNEL_MSG_LEN = 200;

//����Ƶ����Ϣ��ҵȼ�����
const INT	WORLD_CHANNEL_ROLE_LVL = 10;

//gx moidfy 2013.6.18
const DWORD TYPEID_IM_DECREE = 1400034;//�Ѹ������������ID
const DWORD TYPEID_IM_QIANLI = 1400033;//ǧ�ﴫ���������ID
//end
const INT DECREE_COST_YUANBAO = 10;

#pragma pack(pop)