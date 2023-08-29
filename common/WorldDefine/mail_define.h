#pragma once


#pragma pack(push, 1)
const INT32 Max_Mail_Name = 18;			// 邮件名称最大字数
const INT32 Min_Mail_Name = 1;			// 邮件名称最小字数
const INT32 Max_Item_Num = 3;			// 邮件物品的最大数量
const INT32 Max_Mail_Content = 128;		// 邮件内容的最大字数
const INT32 Min_Mail_Content = 1;		// 邮件内容的最小字数
const INT32 Max_Mail_Size	= 50;		// 玩家最大邮箱容量
const INT32 Max_Role_SendMailNum	= 20; // 人物当天发送邮件最大数量
const DWORD Max_Money_Limit			= 2000000000;		// 最大可以发送的钱数

enum
{
	E_Mail_Role_Level_NotEnough		= 1,	// 人物等级不足
	E_Mail_SendMoney_NotEnough		= 2,	// 要邮寄的钱不够
	E_Mail_AcceptMoney_NotEnough	= 3,	// 收件要付的费用不够
	E_Mail_Bag_NotEnough			= 4,	// 包裹位置不足
	E_Mail_Condition_NotEnough		= 5,	// 不在NPC附近或没有必要道具
	E_Mail_NoCan_Delete				= 6,	// 不能删除邮件
	E_Mail_MaxSendNum				= 7,	// 超过最大发件数量
	E_Mail_NoCan_SendOwn			= 8,	// 不能给自己发送邮件
	E_Mail_RecvRole_NotExist		= 9,	// 收件人不存在
	E_Mail_Item_NoExist				= 10,	// 邮寄物品不存在
	E_Mail_No_Accessory				= 11,	// 没有附件
	E_Mail_NoCan_Solve				= 12,	// 没有物品不能设置付费
	E_Mail_SystemMail_NoCan_Return	= 13,   // 系统邮件不能退信
	E_Mail_Money_Limit				= 14,	// 钱数超过邮件限制
};

struct tagMailBase
{
	DWORD				dwID;							// 邮件ID
	DWORD				dwSendRoleID;					// 发件人ID(如果为-1,则为系统邮件)
	DWORD				dwRecvRoleID;					// 收件人ID
	BOOL				bAtOnce;						// 是否立即发送
	BOOL				bSend;							// 邮件是否发出
	BOOL				bReed;							// 邮件是否已阅读
	BOOL				bWithdrawal;					// 是否为退件
	DWORD				dwSolve;						// 对方收件要付的费用
	DWORD				dwGiveMoney;					// 邮寄的钱数
	BYTE				byType;							// 邮寄钱类型 0 游戏币 1 元宝
	INT					n_yuanbao_type;					// 元宝发放类型
	INT64				n64ItemSerial[Max_Item_Num];	// 邮寄的所有物品编号
	tagDWORDTime		dwSendTime;						// 发送邮件时间
	tagDWORDTime		dwRecvTime;						// 收到邮件时间

	tagMailBase() { ZeroMemory(this, sizeof(*this)); }
};

struct tagMail : public tagMailBase
{
	tstring strName;	//邮件名称
	tstring strContent;	//邮件内容

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
	DWORD				dwID;							// 邮件ID
	DWORD				dwSendRoleID;					// 发件人ID(如果为-1,则为系统邮件)
	BOOL				bReed;							// 邮件是否已阅读
	BOOL				bWithdrawal;					// 是否为退件
	DWORD				dwSolve;						// 对方收件要付的费用
	DWORD				dwGiveMoney;					// 邮寄的钱数
	BYTE				byType;							// 邮寄钱的类型 0 游戏币 1 元宝
};

struct tagMailInfo
{
	TCHAR szName[Max_Mail_Name+1];		// 邮件名称
	tagClientMailInfo stMailInfo;		// 邮件基础信息
	DWORD	dwType;						// 道具编号
	DWORD   dwFreeTime;					// 剩余时间（秒）
};
#pragma pack(pop)