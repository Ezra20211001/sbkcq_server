//--------------------------------------------------------------------------------------------
//��Name				:   mall_define.h
//��Compiler			:	Microsoft Visual C++ 9.0
//��Version				:	1.00
//��Create Date			:	2009-1-5
//��LastModified		:	
//��Brief				:	�̳���ض���
//--------------------------------------------------------------------------------------------
#pragma once

#pragma pack(push, 1)
//--------------------------------------------------------------------------------------------
// ����
//--------------------------------------------------------------------------------------------
const INT MALL_PACK_ITEM_NUM		= 5;	// ��Ʒ���������Ʒ������

const INT	Max_LeaveWord_Length		= 20;	//����20����
const INT	MAX_PromoteItem			= 5;	//�Ƽ���Ʒ����
const INT64 MAX_YB_NUM				= 9999999;		// Ԫ�������˻����Ԫ����
const INT64 MAX_SILVER_NUM			= 9999999999;	// Ԫ�������˻����������
const INT   Exchange_Goods_Index    = 5;		//��Ҫ������һ�����Ʒ���ڵ�sheet����
//--------------------------------------------------------------------------------------------
// ��̬�ṹ
//--------------------------------------------------------------------------------------------
struct tagMallItemProtoBase
{
	DWORD			dwID;							// ID
	INT				nPrice;							// ����
	INT				nSalePrice;						// ������
	DWORD			dwTimeSaleStart;				// ������ʼʱ��
	DWORD			dwTimeSaleEnd;					// ������ֹʱ��
	DWORD			dwSaleBegin;					// �ϼ�ʱ��
	DWORD			dwSaleEnd;						// �¼�ʱ�� 
	DWORD			dwPresentID;					// ��ƷID
	BYTE			byNum;							// ��������
	BYTE			byPresentNum;					// ��Ʒ����
	BYTE			byExAssign;						// ������������
	BYTE			byExNum;						// ��Ҫ��������
	BYTE			bySmallGroupHeadcount;			// С���Ź����� 
	BYTE			bySmallGroupDiscount;			// С���Ź��ۿ�[0��100]
	BYTE			byMediumGroupHeadcount;			// �����Ź�����
	BYTE			byMediumGroupDiscount;			// �����Ź��ۿ�
	BYTE			byBigGroupHeadcount;			// �����Ź�����
	BYTE			byBigGroupDiscount;				// �����Ź��ۿ�
	bool			bNew	: 1;					// �Ƿ�Ϊ��Ʒ
	bool			bHot	: 1;					// �Ƿ�����
	BYTE			byIndexInServer;				// �ڷ������е�λ��
	DWORD			dwPersistTime;					// �Ź�����ʱ��
};


struct tagMallItemProto: public tagMallItemProtoBase
{
	DWORD			dw_data_id;						// ��ƷTypeID
	INT8			n8Kind;							// ��������
	BYTE			byRank;							// ��������
	BYTE			byGroupPurchaseAmount;			// �Ź�����
	BYTE			byDummy[1];
};

struct tagMallPackProto: public tagMallItemProtoBase
{
	DWORD			dw_data_id[MALL_PACK_ITEM_NUM];	// ��ƷID
	INT				nItemPrice[MALL_PACK_ITEM_NUM];	// ������Ʒ�۸�(�ܼ�)
	BYTE			byItemNum[MALL_PACK_ITEM_NUM];	// ��Ʒ����
	INT8			n8ItemKind;						// ��Ʒ����(ID)����
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
	DWORD		dw_data_id;	// ��ƷID
	INT			nUnitPrice;	// ԭ����
	BYTE		byNum;		// ��ȡ����

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
// ���������ݽṹ
//--------------------------------------------------------------------------------------------
//struct tagMallGoods
//{
//	DWORD	dwID;		// ��Ʒ����Ʒ��ID
//	BYTE	byCurNum;	// ��ǰ��������(INVALID_VALUE��ʾ������)
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

	BYTE	byCurNum;	// ��ǰ��������(INVALID_VALUE��ʾ������)
	BYTE	byDummy[3];
};

//--------------------------------------------------------------------------------------------
// �ͻ������������Ʒ����ͬ���ṹ
//--------------------------------------------------------------------------------------------
struct tagMallUpdate
{
	DWORD		dwID;					//��ƷID
	BYTE		byRemainNum;			//ʣ�����
};

//--------------------------------------------------------------------------------------------
// �����Ź�
//--------------------------------------------------------------------------------------------
enum EGPSCOPE
{
	EGPS_NULL		= -1,
	EGPS_SMALL,							//С���Ź�
	EGPS_MEDIUM,						//�����Ź�
	EGPS_BIG,							//�����Ź�
};

struct tagGroupPurchase
{
	DWORD			dwGuildID;			//����ID
	DWORD			dw_role_id;			//������ID
	DWORD			dwMallID;			//��ƷID
	INT32			nPrice;				//�Ź��۸�
	INT16			nParticipatorNum;	//��Ӧ����
	INT16			nRequireNum;		//�Ź���������
	DWORD			dwRemainTime;		//ʣ��ʱ��
	package_list<DWORD>*	listParticipators;	//��Ӧ���б�

	tagGroupPurchase()
	{
		ZeroMemory(this, sizeof(*this));
	}

	~tagGroupPurchase()
	{
		SAFE_DELETE(listParticipators);
	}
};

enum EYBOTYPE							//Ԫ����������
{
	EYBOT_BUY,							//�չ�
	EYBOT_SELL,							//����
};

enum EYBOMODE							//Ԫ������״̬
{
	EYBOM_Submit,						//ί����
	EYBOM_Cancel,						//����
	EYBOM_Close,						//�ر�
};

//--------------------------------------------------------------------------------------------
// Ԫ�����׶���
//--------------------------------------------------------------------------------------------
struct tagYuanBaoOrder
{
	DWORD				dwID;					//����ID
	DWORD				dw_role_id;				//���ID
	EYBOTYPE			eYBOType;				//��������
	INT					nPrice;					//����
	INT					n_count;					//����
	EYBOMODE			eYBOMode;				//Ԫ������״̬
	tagDWORDTime		dwStartTime;			//��ʼʱ��
	tagDWORDTime		dwEndTime;				//����ʱ��
	INT					nAvgPrice;				//�ɽ�����
	INT					nDealNum;				//�ɽ�����
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
// ����Ԫ�����׶���(�������ݿ�ʱʹ�ã�
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

// Ԫ�����׼۸��б�
struct tagYBPriceList
{
	INT					nPrice;
	INT					n_num;
};
 
// Ԫ�������˻�
struct tagYBAccount
{
	DWORD				dw_role_id;				//���ID
	INT					nYuanBao;				//Ԫ������
	INT					nGold;					//�������
	INT					nSilver;				//��������
	BOOL				bSellOrder;				//�Ƿ��г��۶���
	BOOL				bBuyOrder;				//�Ƿ����չ�����
};

// ������ر�Ԫ�����׶���
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

// ����Ԫ�����׶���
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