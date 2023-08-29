#pragma once

//! �ڴ��
class server_mem_pool
{
public:
	LPVOID	alloc(DWORD dw_size);
	VOID	_free(LPVOID p_mem);
};

extern server_mem_pool g_mem_pool_safe;

#pragma pack(push, 1)


const INT X_ROLE_BUFF_SIZE			= (2 * 1024 * 1024);		// 2M.��ȡ�����ɫ����ʱ����Ϣbuff��С

const INT64 MIN_ITEM_SERIAL_INTERNAL	= 500000000000;
const INT64 MAX_ITEM_SERIAL_OUTTER		= 400000000000;
const INT64 MIN_ITEM_SERIAL_OUTTER		= 300000000001;
const INT64	MAX_ITEM_SERIAL_BILL		= 300000000000;



//! �ַ����޹صļ����ַ������ַ�������
#define cal_tchar_array_num(szArray)		(sizeof(TCHAR) == 1 ? sizeof(szArray) : (sizeof(szArray) >> 1))



//! �ж�װ���Ƿ��Ѽ���
#define M_is_identified(pEquip)			(pEquip->equipSpec.byQuality != (BYTE)EIQ_Null)

//! �ж�װ���Ƿ�Ϊ��ָ,��Ʒ
#define M_is_ring(pEquip)				(EEP_Finger1 == pEquip->pEquipProto->eEquipPos)
#define M_is_Wrist(pEquip)			(EEP_Wrist1 == pEquip->pEquipProto->eEquipPos)
#define M_is_weapon(pEquip)			(EEP_RightHand == pEquip->pEquipProto->eEquipPos)
#define M_is_fashion(pEquip)			(EITR_Fashion == pEquip->pProtoType->eTypeReserved)

#define M_is_wapon_by_display_pos(nPos)	(EAE_RWeapon == nPos)
#define M_is_weapon_by_equip_pos(nPos)	(EEP_RightHand == nPos)

//! �ж��Ƿ�Ϊ�ٷ���
#define M_is_value_pct(n_num)			((n_num) > 100000 || (n_num) < -100000)

//! ���ٷ���ת��Ϊ��ֵ
#define M_value_pct_trans(n_num)		((n_num) > 100000 ? (n_num) - 100000 : (n_num) + 100000)

#define M_msg_init(ptr, TYPE)				\
	{											\
	TYPE tmp##TYPE;								\
	memcpy(ptr, &tmp##TYPE, sizeof(tag_net_message));	\
	}


#define GET_MESSAGE(p_receive,p_message,MSG_KIND) \
	MSG_KIND* p_receive = (MSG_KIND*)p_message;


#define M_trans_pointer(PNEWPOINTER, PDATA, DST_POINTER_TYPE)	\
	DST_POINTER_TYPE* PNEWPOINTER = (DST_POINTER_TYPE*)PDATA;


#define M_trans_else_ret(PNEWPOINTER, PDATA, DST_POINTER_TYPE, RETVALUE)		\
	M_trans_pointer(PNEWPOINTER, PDATA, DST_POINTER_TYPE);		\
	if(!VALID_POINT(PNEWPOINTER))	return RETVALUE;

//----------------------------------------------------------------
// ��������Ϣ�ڴ����봦�� -- ���ⲿ����������Ϣ��С
//----------------------------------------------------------------
//#define MCREATE_MSG(PSEND, SIZE, MSG_KIND)	\
//	BYTE* temp_p_##MSG_KIND = new BYTE[SIZE];					\
//	ZeroMemory(temp_p_##MSG_KIND, SIZE);						\
//	tag##MSG_KIND* PSEND = new(temp_p_##MSG_KIND) tag##MSG_KIND;\
//	PSEND->dw_size = SIZE;
//
//
//#define MDEL_MSG(PSEND)		delete [](BYTE*)PSEND;

//----------------------------------------------------------------
// ��������Ϣ�ڴ����봦�� -- ���ⲿ����������Ϣ��С
// �ŵ㣺���ù����ڴ棻ȱ�㣺����ʱ��������Ӧ��Ϣ��ģ�庯��
//----------------------------------------------------------------
class msg_send
{
public:
	msg_send(INT nSize)
	{
		m_nSize = nSize;

		// ������СΪ4��������
		m_nSize = (((m_nSize - 1) >> 2) + 1) << 2;

		m_pBuff = (BYTE*)g_mem_pool_safe.alloc(m_nSize);
	}

	~msg_send()
	{
		if(m_pBuff != NULL)
		{
			g_mem_pool_safe._free(m_pBuff);
		}
	}

	template<typename T>
	VOID get_data(T* &pT)
	{
		ASSERT(m_nSize >= sizeof(T));
		ZeroMemory(m_pBuff, m_nSize);
		M_msg_init(m_pBuff, T);
		pT = (T*)m_pBuff;
	}

private:
	BYTE	*m_pBuff;
	INT		m_nSize;
};

// �������õĺ����¶�����
//#define M_CREATE_MSG(PSEND,SIZE,MSG_KIND)		\
//	msg_send tmp##PSEND(SIZE);	\
//	tag##MSG_KIND* PSEND;		\
//	tmp##PSEND.get_data(PSEND);	\
//	PSEND->dw_size = SIZE;

#define MDEL_MSG(PSEND)		(0)

#define CREATE_MSG(PSEND, SIZE, MSG_KIND)		\
	msg_send tmp##PSEND(SIZE);	\
	MSG_KIND* PSEND;		\
	tmp##PSEND.get_data(PSEND);	\
	PSEND->dw_size = SIZE

//----------------------------------------------------------------
// ��������ͻ����ַ������� -- ȷ�����ַ���������
//----------------------------------------------------------------
//#define m_get_msg_string(TSTR, PMSGSTR, MSGSZ, MSG_KIND, STRFIELD)						\
//	INT32 tmpStrSz = (MSGSZ - FIELD_OFFSET(tag##MSG_KIND, STRFIELD)) / sizeof(TCHAR);	\
//	if(tmpStrSz < 0)	tmpStrSz = 0;													\
//	tstring TSTR(PMSGSTR, tmpStrSz)

//#define GET_MESSAGE_STRING(TSTR, PMSGSTR, MSGSZ, MSG_KIND, STRFIELD)						\
//	INT32 tmpStrSz = (MSGSZ - FIELD_OFFSET(MSG_KIND, STRFIELD)) / sizeof(TCHAR);	\
//	if(tmpStrSz < 0)	tmpStrSz = 0;													\
//	tstring TSTR(PMSGSTR, tmpStrSz)

//! �����������̨���;�����Ϣ
#define m_att_res_caution(FileName, KeyName, KeyVal) \
	print_message(_T("\n\ngame resource faild<%s-%s-%u>!!!!!\n\n"), (FileName), (KeyName), (KeyVal));					
	

#define ASSERT_P_VALID( ptr ) ASSERT(VALID_POINT(ptr))


#define SHUT_DOWN_YEAY 21		//2011
#define SHUT_DOWN_MONTH 6
#pragma pack(pop)

