#pragma once

#pragma pack(push, 1)

#define EVO_START_LEVEL 3
#define PET_MAX_LEVEL 7

const INT MAX_PETSOUL_NUM			= 12;	// ���ӵ�г�������
const INT MAX_HAPPY_VALUE			= 300;	// ����Ķ�

const INT PET_RETURN_MIN_TIME		= 18 * 60 * 60 ; // ���ճ�����Сʱ�� 			 
const INT PET_RETURN_MAX_TIME		= 19 * 60 * 60 ; // ���ճ������ʱ��

const DWORD PET_JIEJING				= 5300007;	// ����ᾧID


const INT YUANBAO_LOVE_VALUE		= 1000;		// һ��Ԫ����Ӧ���ٰ���ֵ
//! ����ģ����̬����
enum EPetModelType
{
    EPMT_Follow  =   0,  //!< ����
    EPMT_Mount,         //!< ���
    //EPMT_Fly,	        //!< ����
    EPMT_NUM
};

//! ����״̬
enum EPetState
{
	EPS_Called		= 1 << 0, //0x01,
	EPS_Working		= 1 << 1, //0x02,
	EPS_Preparing	= 1 << 2, //0x04,
	EPS_Mounting	= 1 << 3, //0x08,
	EPS_Ronghe		= 1 << 4, //0x16,
	EPS_Dead		= 1 << 5, //0x32,
	EPS_Xiulian		= 1 << 6, //0x64,
};

// ����
enum EPetMood
{
	EPM_VerySad	=	-1,	//��ŭ
	EPM_Sad		=	0,	//����
	EPM_NoHappy	=	1,	//������
	EPM_Happy	=	2	//����
};

//! ʳ������
enum EPetFood
{
	EPF_fish	=	0x01,	//��
	FPF_Rou		=	0x02,	//��
	FPF_Cai		=	0x04	//��
};
enum EPetStateFlag
{
	EPSF_Mounting		= 0x0001,
	EPSF_UnMounting		= 0x0002,
	EPSF_Preparing		= 0x0004,
	EPSF_UnPreparing	= 0x0008,
	EPSF_Working		= 0x0010,
	EPSF_UnWorking		= 0x0020,
	EPSF_Called			= 0x0040,
	EPSF_UnCalled		= 0x0080,
	EPSF_Ronghe			= 0x0100,
	EPSF_UnRonghe		= 0x0200,	
	EPSF_Dead			= 0x0400,
	EPSF_UnDead			= 0x0800,	
	EPSF_Xiulian		= 0x1000,
	EPSF_UnXiulian		= 0x2000	
};


//! ����״̬
union UPetState
{
	struct
	{
		bool bisCalled      : 1;
		bool bisWorking     : 1;
		bool bisPreparing   : 1;
		bool bisRiding      : 1;
		bool b_is_Ronghe :1;
		bool bDead:1;
		bool bDeposit:1;
	};
	BYTE	byPetState;
};


// �����ʼ������
struct tagPetInitAttr
{
    DWORD           dwID;                       //!< ���������ʱ,����Ϸ�������ɵ�ΨһID
    DWORD           dw_data_id;                   //!< ��������ID,��ӦtagPetProto�е�ID
    UINT8           nQuality;                   //!< Ʒ��
    INT16           nAptitude;                  //!< ����
    INT				nSpiritMax;                 //!< �������ֵ
    INT				nSpirit;                    //!< ����
    INT16           nPotential;                 //!< Ǳ��
    INT16           nWuXingEnergy;              //!< ������(���9999)
    UINT8           nLevel;                     //!< ����ȼ�
    INT             nExpCurrent;                //!< ��ǰ����
    INT             nExpLevelUp;                //!< ��������
    INT             nMountSpeed;                //!< ����ٶ�
    INT             nBagGrid;                   //!< ���Ҹ���
    INT8            byPetState;                 //!< ����״̬(EPetState)
    INT8            nMountNum;                  //!< ��ǰ�����Ŀ
    INT8            nMountNumMax;               //!< ��������Ŀ
	bool			bLocked;					//!< �Ƿ�����
    INT8            nPetEquipNum;	            //!< ����װ����
    INT8            nPetSkillNum;	            //!< ���＼����
	INT8			nPetRenameCount;			//!< �����������
	INT16			nPetHappyValue;				//!< ���￪�Ķ�
	INT8			nPetColor;					//!< ������ɫ
	INT				n_strength;					//!< ���ӽ�ɫ����
	INT				n_agility;					//!< ���ӽ�ɫ����
	INT				n_innerForce;				//!< ���ӽ�ɫ����
	INT				n_att_point;				//!< ���Ե�
	DWORD			n_time_type;				//!< ����ʱ������ 
	DWORD			n_mode_type;				//!< ����ģʽ����
	DWORD			n_xiulian_time;				//!< ����ʱ��

    BYTE			byData[1];                  //!< ����Ϊ����װ���ṹtagPetEquipMsgInfo,���м��ܽṹtagPetSkillMsgInfo
};

// �軺�屾�صĳ�����Ϣ
struct tagPetDispInfo
{
    TCHAR           szName[X_SHORT_NAME];       //!< ������
    DWORD	        dw_data_id;                 //!< ����ԭ��id
	INT16			n_color;					//!< ��ɫ
	BYTE			byQuality;					// Ʒ�� 
};

// ����sns��Ϣ
struct tagPetSNSInfo
{
	DWORD			dw_pet_id;			// ����ID
	DWORD			dw_master_id;		// ����ID
	DWORD			dw_friend_id;		// ����ID
	DWORD			dw_begin_time;		// ��ǲʱ��	

	tagPetSNSInfo() { memset(this, 0, sizeof(*this)); }
};

// ͨѶ�ó�������ö��
enum ECSPetAtt
{
	ECSPA_Null				= -1,
	ECSPA_Begin				= 0,

	ECSPA_nQuality          = 0,    //!< Ʒ��
	ECSPA_nAptitude         = 1,    //!< ����
    ECSPA_nSpiritMax        = 2,    //!< �������
	ECSPA_nSpirit           = 3,    //!< ����
    ECSPA_nPotential        = 4,    //!< Ǳ��
	ECSPA_nWuXingEnergy     = 5,    //!< ������
	ECSPA_nLevel            = 6,    //!< ����ȼ�
	ECSPA_nExpCurrent       = 7,    //!< ��ǰ����
	ECSPA_nExpLevelUp       = 8,    //!< ��������
	ECSPA_nMountSpeed       = 9,    //!< ����ٶ�
    ECSPA_BagGrid           = 10,   //!< ���Ҹ���
	ECSPA_PetState          = 11,   //!< ����״̬(EPetState)
	ECSPA_nMountNum			= 12,	//!< ��ǰ�������
	ECSPA_nMountNumMax		= 13,	//!< ����������
	ECSPA_bLocked			= 14,	//!< �Ƿ�����
	ECSPA_nHappyValue		= 15,	//!< ���Ķ� 2:���� 1:������ 0:����
	ECSPA_nRenameCount		= 16,	//!< ��������
	ECSPA_nColor			= 17,	//!< ������ɫ
	ECSPA_nstrength			= 18,	//!< ���ӽ�ɫ����
	ECSPA_nagility			= 19,	//!< ���ӽ�ɫ����
	ECSPA_ninnerForce		= 20,	//!< ���ӽ�ɫ����
	ECSPA_natt_point		= 21,	//!< ���Ե�
	ECSPA_time_type			= 22,	//!< ����ʱ������
	ECSPA_mode_type			= 23,	//!< ����ģʽ����
	ECSPA_xiulian_time		= 24,	//!< ������ʼʱ��

	ECSPA_End,
};

// ����������ü��������Ŀ
CONST INT MAX_PET_STEP_UPGRADE_SKILL_NUM		= 6;


// ��������ԭ��
struct tagPetLvlUpProto
{
	DWORD	dwVLevel;
	INT		nStep;
	INT		nGrade;
	INT		nExpLvlUpNeed;
	INT		nMoneyRatePourExpNeed;
};

// �������׵��߱�
struct tagPetLvlUpItemProto
{
	DWORD	dw_data_id;
	INT		dwSkillIDs[MAX_PET_STEP_UPGRADE_SKILL_NUM];
};

const INT ECSPA_Num = ECSPA_End - ECSPA_Begin;

#define EPATOERPA(n)	(ECSPetAtt)(n)

// ��
const INT MIN_PET_STEP	= 0;								// ������С��
const INT MAX_PET_STEP	= 0;								// ��������
const INT NUM_PET_STEP	= MAX_PET_STEP - MIN_PET_STEP + 1;	// �������
#define IS_PET_STEP(nlvl)	((nlvl) >= MIN_PET_STEP && (nLvl) <= MAX_PET_STEP)

// ��
const INT MIN_PET_GRADE	= 1;								// ������С��
const INT MAX_PET_GRADE	= 7;								// ��������
const INT NUM_PET_GRADE	= MAX_PET_GRADE - MIN_PET_GRADE + 1;// �������
#define IS_PET_GRADE(nlvl)	((nlvl) >= MIN_PET_GRADE && (nLvl) <= MAX_PET_GRADE)

// ����ȼ�
const INT MIN_PET_VLEVEL	= 1;
const INT MAX_PET_VLEVEL	= 7;
const INT NUM_PET_VLEVEL	= MAX_PET_VLEVEL - MIN_PET_VLEVEL + 1;// ��������ȼ�
#define IS_PET_VLEVEL(nlvl)	((nlvl) >= MIN_PET_VLEVEL && (nLvl) <= MAX_PET_VLEVEL)

// ��Ҫ�ɱ��������
const INT MIN_CHANGE_LEVEL = 3;

#define MMID(val, min, max)		((val) = ((val) > (max)) ? (max) : (((val) < (min)) ? (min) : val))
// ����ȼ����׵ȵ�ת��
inline VOID TransVLevel2StepGrade( INT nVLevel, INT &nStep, INT &nGrade )
{
	MMID(nVLevel, MIN_PET_VLEVEL, MAX_PET_VLEVEL);
	nVLevel -= 1;
	nStep	= nVLevel / NUM_PET_GRADE;
	nGrade	= nVLevel % NUM_PET_GRADE + 1;
}
// �׵ȵ�����ȼ���ת��
inline VOID TransStepGrade2VLevel( INT nStep, INT nGrade, INT &nVLevel )
{
	MMID(nStep, MIN_PET_STEP, MAX_PET_STEP);
	MMID(nGrade, MIN_PET_GRADE, MAX_PET_GRADE);
	nGrade	-= 1;
	nVLevel = nStep * NUM_PET_GRADE + nGrade;
	nVLevel += 1;
}
#undef MMID

// ��Զ��������˾���
const FLOAT MAX_MOUNTINVITE_DISTANCE = 10 * 50.0f;	


// �����ںϳɹ���
class PetHelper
{
public:
	//�ںϳɹ���
	static INT getFusionPro(INT nQuality)
	{
		switch (nQuality)
		{
		case 0:
			return 10000;
		case 1:
			return 6000;
		case 2:
			return 4000;
		case 3:
			return 2000;
		default:
			return 0;
		}
	}

	//ÿ����Ԫ����������
	static INT getFusionProPeiYuan(INT nQuality)
	{
		switch (nQuality)
		{
		case 0:
			return 300;
		case 1:
			return 200;
		case 2:
			return 150;
		case 3:
			return 150;
		default:
			return 0;
		}
	}

	static INT getChangeSizeMoney(INT nSize)
	{
		switch(nSize)
		{
		case 1:
			return 0;
		case 2:
			return 50000;
		case 3:
			return 100000;
		case 4:
			return 500000;
		case 5:
			return 1000000;
		case 6:
			return 2000000;
		default:
			return 5000000;
		}
		return 0;
	}

	static INT getAddpoint(BYTE byQuality)
	{
		switch (byQuality)
		{
		case 0:
			return 3;
		case 1:
			return 4;
		case 2:
			return 6;
		case 3:
			return 10;
		case 4:
			return 16;
		default:
			return 0;
		}

		return 0;
	}
};

#pragma pack(pop)