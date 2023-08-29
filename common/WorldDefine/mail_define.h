#pragma once


#pragma pack(push, 1)
const INT32 Max_Mail_Name = 18;			// �ʼ������������
const INT32 Min_Mail_Name = 1;			// �ʼ�������С����
const INT32 Max_Item_Num = 3;			// �ʼ���Ʒ���������
const INT32 Max_Mail_Content = 128;		// �ʼ����ݵ��������
const INT32 Min_Mail_Content = 1;		// �ʼ����ݵ���С����
const INT32 Max_Mail_Size	= 50;		// ��������������
const INT32 Max_Role_SendMailNum	= 20; // ���ﵱ�췢���ʼ��������
const DWORD Max_Money_Limit			= 2000000000;		// �����Է��͵�Ǯ��

enum
{
	E_Mail_Role_Level_NotEnough		= 1,	// ����ȼ�����
	E_Mail_SendMoney_NotEnough		= 2,	// Ҫ�ʼĵ�Ǯ����
	E_Mail_AcceptMoney_NotEnough	= 3,	// �ռ�Ҫ���ķ��ò���
	E_Mail_Bag_NotEnough			= 4,	// ����λ�ò���
	E_Mail_Condition_NotEnough		= 5,	// ����NPC������û�б�Ҫ����
	E_Mail_NoCan_Delete				= 6,	// ����ɾ���ʼ�
	E_Mail_MaxSendNum				= 7,	// ������󷢼�����
	E_Mail_NoCan_SendOwn			= 8,	// ���ܸ��Լ������ʼ�
	E_Mail_RecvRole_NotExist		= 9,	// �ռ��˲�����
	E_Mail_Item_NoExist				= 10,	// �ʼ���Ʒ������
	E_Mail_No_Accessory				= 11,	// û�и���
	E_Mail_NoCan_Solve				= 12,	// û����Ʒ�������ø���
	E_Mail_SystemMail_NoCan_Return	= 13,   // ϵͳ�ʼ���������
	E_Mail_Money_Limit				= 14,	// Ǯ�������ʼ�����
};

struct tagMailBase
{
	DWORD				dwID;							// �ʼ�ID
	DWORD				dwSendRoleID;					// ������ID(���Ϊ-1,��Ϊϵͳ�ʼ�)
	DWORD				dwRecvRoleID;					// �ռ���ID
	BOOL				bAtOnce;						// �Ƿ���������
	BOOL				bSend;							// �ʼ��Ƿ񷢳�
	BOOL				bReed;							// �ʼ��Ƿ����Ķ�
	BOOL				bWithdrawal;					// �Ƿ�Ϊ�˼�
	DWORD				dwSolve;						// �Է��ռ�Ҫ���ķ���
	DWORD				dwGiveMoney;					// �ʼĵ�Ǯ��
	BYTE				byType;							// �ʼ�Ǯ���� 0 ��Ϸ�� 1 Ԫ��
	INT					n_yuanbao_type;					// Ԫ����������
	INT64				n64ItemSerial[Max_Item_Num];	// �ʼĵ�������Ʒ���
	tagDWORDTime		dwSendTime;						// �����ʼ�ʱ��
	tagDWORDTime		dwRecvTime;						// �յ��ʼ�ʱ��

	tagMailBase() { ZeroMemory(this, sizeof(*this)); }
};

struct tagMail : public tagMailBase
{
	tstring strName;	//�ʼ�����
	tstring strContent;	//�ʼ�����

	tagMail() : tagMailBase(){};

	VOID Init(DWORD dwSerial, tstring& strName, tstring& strContent, tagMailBase& stMailBase)
	{
		this->dwID = dwSerial;
		this->strName = strName;
		this->strContent = strContent;
		this->dwSendRoleID = stMailBase.dwSendRoleID;
		this->dwRecvRoleID = stMailBase.dwRecvRoleID;
		this->dwSolve = stMailBase.dwSolve;
		this->dwGiveMoney = stMailBase.dwGiveMoney;
		this->byType = stMailBase.byType;
		this->n_yuanbao_type = stMailBase.n_yuanbao_type;
		memcpy(this->n64ItemSerial, stMailBase.n64ItemSerial, sizeof(this->n64ItemSerial));
	}

};

struct tagClientMailInfo
{
	DWORD				dwID;							// �ʼ�ID
	DWORD				dwSendRoleID;					// ������ID(���Ϊ-1,��Ϊϵͳ�ʼ�)
	BOOL				bReed;							// �ʼ��Ƿ����Ķ�
	BOOL				bWithdrawal;					// �Ƿ�Ϊ�˼�
	DWORD				dwSolve;						// �Է��ռ�Ҫ���ķ���
	DWORD				dwGiveMoney;					// �ʼĵ�Ǯ��
	BYTE				byType;							// �ʼ�Ǯ������ 0 ��Ϸ�� 1 Ԫ��
};

struct tagMailInfo
{
	TCHAR szName[Max_Mail_Name+1];		// �ʼ�����
	tagClientMailInfo stMailInfo;		// �ʼ�������Ϣ
	DWORD	dwType;						// ���߱��
	DWORD   dwFreeTime;					// ʣ��ʱ�䣨�룩
};
#pragma pack(pop)