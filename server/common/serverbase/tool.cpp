/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

/**
*	@file		tool.h
*	@author		lc
*	@date		2011/02/21	initial
*	@version	0.0.1.0
*	@brief		
*/


#include "stdafx.h"
#include "tool.h"
#include "des.h"


#undef new
#undef delete
#undef malloc
#undef calloc
#undef realloc
#undef free

static UCHAR key_1[20][3][8] = 
{
	23,90,37,87,165,16,2,7,
	24,114,151,238,148,164,166,173,
	25,139,35,18,166,75,241,159,
	47,186,221,239,150,225,211,115,
	49,235,201,185,80,50,6,121,
	72,52,253,183,8,58,64,185,
	96,148,146,74,82,140,204,134,
	121,14,160,234,61,201,150,29,
	168,182,87,66,127,73,223,252,
	217,144,231,42,169,242,210,207,
	34,178,154,196,110,97,52,4,
	130,53,207,148,3,100,152,156,
	251,49,1,149,152,252,149,50,
	164,213,214,108,5,2,151,201,
	126,84,43,151,156,158,54,255,
	160,244,32,183,84,242,41,41,
	35,24,56,239,68,55,96,137,
	31,55,111,95,163,218,59,196,
	195,250,106,201,109,72,131,72,
	66,61,167,113,222,39,170,242,
	226,32,199,57,24,63,233,220,
	6,38,237,39,63,126,104,69,
	37,75,57,96,159,30,134,203,
	232,52,109,205,109,139,18,221,
	43,95,204,154,8,147,165,131,
	14,109,58,212,220,112,22,153,
	20,129,187,144,109,221,243,141,
	57,186,118,7,116,82,70,211,
	34,220,83,90,206,33,103,59,
	77,42,125,215,166,199,47,106,
	91,133,3,218,129,73,120,226,
	111,244,247,210,84,157,22,248,
	168,157,149,104,188,90,112,105,
	202,104,253,102,35,125,237,87,
	24,128,126,228,8,133,115,202,
	115,243,114,87,95,228,88,35,
	226,214,73,160,255,228,61,96,
	139,98,171,76,76,49,110,206,
	86,184,100,176,252,46,156,107,
	110,39,139,60,57,103,4,111,
	225,9,148,208,10,113,117,228,
	196,205,98,51,61,174,36,9,
	80,30,128,179,240,159,195,204,
	166,196,69,248,233,137,77,26,
	21,217,31,24,2,139,216,242,
	246,208,239,8,10,149,110,97,
	187,140,124,132,142,36,146,243,
	12,152,21,153,40,76,222,210,
	178,75,96,249,34,110,77,32,
	199,19,115,109,143,253,75,107,
	190,209,69,178,66,64,139,246,
	122,76,145,68,134,198,82,73,
	134,210,100,168,47,245,72,145,
	57,12,112,25,72,62,134,24,
	1,13,125,150,222,29,163,187,
	191,204,74,224,191,220,128,60,
	58,7,81,50,241,206,79,139,
	192,199,25,75,61,12,91,230,
	249,193,218,38,99,111,202,177,
	250,188,151,189,33,144,91,13
};

static UCHAR key_2[20][3][8] = 
{
	23,201,185,80,50,6,121,72,52,253,
	183,7,204,74,224,191,220,128,60,58,
	7,81,50,241,206,79,139,192,199,25,
	75,61,12,91,230,121,14,160,234,61,
	201,150,29,168,182,87,66,127,73,223,
	249,193,24,114,151,238,148,164,166,173,
	225,211,115,49,235,185,96,148,146,74,
	82,140,204,134,252,152,156,251,49,1,
	149,152,252,149,50,164,217,144,231,42,
	169,242,210,207,34,178,154,196,110,97,
	52,4,130,53,207,148,3,100,213,214,
	108,5,2,151,201,126,84,43,151,156,
	158,54,255,160,244,32,183,84,242,41,
	41,35,24,56,239,68,55,96,137,31,
	55,111,95,163,218,59,196,195,250,106,
	201,109,72,131,72,66,61,167,113,222,
	39,170,242,226,32,199,57,24,63,233,
	220,6,38,237,39,63,126,104,69,37,
	75,57,96,159,30,134,203,232,52,109,
	205,109,139,18,221,43,95,204,154,8,
	147,165,131,14,109,58,212,220,112,22,
	153,20,129,187,144,109,221,243,141,57,
	186,118,7,116,82,70,211,34,220,83,
	90,206,33,103,59,77,42,125,215,166,
	199,47,106,91,133,3,218,129,73,120,
	226,111,244,247,210,84,157,22,248,168,
	157,149,104,188,90,112,105,202,104,253,
	102,35,125,237,87,24,128,126,228,8,
	133,115,202,115,243,114,87,95,228,88,
	35,226,214,73,160,255,228,61,96,139,
	98,171,76,76,49,110,206,86,184,100,
	176,252,46,156,107,110,39,139,60,57,
	103,4,111,225,9,148,208,10,113,117,
	228,196,205,98,51,61,174,36,9,80,
	30,128,179,240,159,195,204,166,196,69,
	248,233,137,77,26,21,217,31,24,2,
	139,216,242,246,208,239,8,10,149,110,
	97,187,140,124,132,142,36,146,243,12,
	152,21,153,40,76,222,210,178,75,96,
	249,34,110,77,32,199,19,115,109,143,
	253,75,107,190,209,69,178,66,64,139,
	246,122,76,145,68,134,198,82,73,134,
	210,100,168,47,245,72,145,57,12,112,
	25,72,62,134,24,1,13,125,150,222,
	29,163,187,191,218,8,58,64,90,37,
	87,165,16,2,38,99,111,202,177,250,
	188,151,189,33,144,91,13,25,139,35,
	18,166,75,241,159,47,186,221,239,150
};

namespace serverbase {


tool::tool():dw_id_seed(1),n_rand_seed(0),n_rand_call_num(0)
{
	InitializeCriticalSection(&_lock);
	p_char_buffer = new CHAR[CHAR_BUFFER_SIZE];
	p_tchar_buffer = new TCHAR[CHAR_BUFFER_SIZE];
}

tool::~tool()
{
	DeleteCriticalSection(&_lock);
	SAFE_DELETE_ARRAY(p_char_buffer);
	SAFE_DELETE_ARRAY(p_tchar_buffer);
}


DWORD tool::get_idlesse_id()
{
	if( dw_id_seed >= 0x7fffffff )	
		dw_id_seed = 1;
	return dw_id_seed++;
}


VOID tool::tool_randomize(DWORD dw_seed_)
{
	n_rand_seed = (INT)dw_seed_;
	n_rand_call_num = 0;
}

INT tool::tool_rand()
{
	EnterCriticalSection(&_lock);
	n_rand_call_num++;
	
	
	INT n_result = (((n_rand_seed = n_rand_seed * 1103515245 + 12345) >> 1 ) & LONG_MAX);
	
	LeaveCriticalSection(&_lock);
	return n_result;
}

INT tool::get_cup_num()
{
	SYSTEM_INFO  sysinfo;
	GetSystemInfo(&sysinfo);
	return (INT)sysinfo.dwNumberOfProcessors;
}


//-----------------------------------------------------------------------------
//! 根据概率计算成功率
//-----------------------------------------------------------------------------
BOOL tool::probability(INT n_radices_)
{
	INT n_temp = 0, n_max = 0;
	if( n_radices_<=0 )
		return FALSE;

	n_max = (INT)(((FLOAT)CARDINAL_NUMBER) / 100.0f * (FLOAT)n_radices_);
	n_temp = (this->tool_rand() % CARDINAL_NUMBER);
	if (n_temp < n_max)
		return TRUE;
	else
		return FALSE;
}


//-----------------------------------------------------------------------------
//! 给定数值及上下浮动范围，算出浮动数
//-----------------------------------------------------------------------------
FLOAT tool::fluctuate(FLOAT f_num_, FLOAT f_increase_, FLOAT f_decrease_)
{
	FLOAT f_max = f_num_ * ( 100.0f + f_increase_ ) / 100.0f;
	FLOAT f_min = f_num_ * ( 100.0f - f_decrease_ ) / 100.0f;
	if (f_num_ < 0)
	{
		FLOAT fTemp = f_max;
		f_max = f_min;
		f_min = fTemp;
	}
	FLOAT f_result = f_min;
	if( (INT)(f_max-f_min) == 0 )
		f_result = f_min;
	else
		f_result = f_min + (FLOAT)(tool_rand() % ((INT)(f_max - f_min)));

    return f_result;
}

//-----------------------------------------------------------------------------
// ! 给定最大，最小值，算出某个中间值
//-----------------------------------------------------------------------------
INT tool::rand_in_range(INT n_min_, INT n_max_)
{
	if( n_min_ < 0 || n_max_ < 0 ) return 0;

	if( n_max_ <= n_min_ ) return n_min_;

	return n_min_ + tool_rand() % (n_max_ - n_min_ + 1);
}

//-----------------------------------------------------------------------------
// 计算16位CRC,算法没有上面的crc32快,code from quake2
//-----------------------------------------------------------------------------
WORD tool::crc16(PBYTE p_data_, INT n_byte_count_)
{
	WORD w_crc = 0xffff;
	while( n_byte_count_-- )
		w_crc = (unsigned short)((w_crc << 8) ^ crc16_table[(w_crc >> 8) ^ *p_data_++]);

	return w_crc;
}


//-----------------------------------------------------------------------------
// ! 删除tstring头尾的空格
//-----------------------------------------------------------------------------
VOID tool::cut_string_head_tail_space(tstring& string_)
{
	if( string_.find_first_not_of(_T(" ")) != -1 )
	{
		string_.assign(string_, string_.find_first_not_of(_T(" ")),
			string_.find_last_not_of(_T(" "))-string_.find_first_not_of(_T(" "))+1);
	}
	else
	{
		string_.clear();
	}
}


//-----------------------------------------------------------------------------
// ! 解析字符串命令中的数值，并压入vector
//-----------------------------------------------------------------------------
VOID tool::string_to_vector(std::vector<tstring>& vector_, LPCWSTR sz_string_, WCHAR sz_separator_)
{
	ASSERT(sz_string_);
	tstring str;
	vector_.clear();

	bool bIntoQuotMark = false;	
	for(LPCTSTR pStr = sz_string_; *pStr; pStr++)
	{
		if( *pStr == sz_separator_ )
		{
			if( !str.empty() )
			{
				if( bIntoQuotMark )
					str.append(sz_separator_, 1);	
				else
				{
					vector_.push_back(str);
					str.clear();
				}
			}
		}
		else if( *pStr == _T('"') )
		{
			bIntoQuotMark = !bIntoQuotMark;
		}
		else
		{
			str.append(pStr, 1);
		}
	}

	if(!str.empty())	
		vector_.push_back(str);
}



//-----------------------------------------------------------------------------
// ! 检查注册表中的指定键值是否存在 
//-----------------------------------------------------------------------------
BOOL tool::check_register(HKEY key_, LPCTSTR sz_subkey_)
{
	HKEY h_key;
	long l_result = RegOpenKeyEx(key_, sz_subkey_, 0, KEY_READ, &h_key);
	if ( l_result == ERROR_SUCCESS )
	{
		RegCloseKey(h_key);
		return true;
	}

	RegCloseKey(h_key);
	return false;
}



//-----------------------------------------------------------------------------
// ! 按指定路径写入键值，如果指定路径，就在注册表中建立路径并写入键值
//-----------------------------------------------------------------------------
BOOL tool::write_register(LPCTSTR sz_register_path_, LPCTSTR sz_key_name_, LPCTSTR sz_string_)
{
	if( sz_register_path_ == NULL || sz_key_name_ == NULL ) 
		return FALSE;

	HKEY h_key;
	DWORD dw_new_key = REG_CREATED_NEW_KEY;

	long l_result = 0;
	if ( !check_register(HKEY_LOCAL_MACHINE, sz_register_path_) )
	{
		l_result = RegCreateKeyEx(HKEY_LOCAL_MACHINE, sz_register_path_, 0, NULL,
			REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &h_key, &dw_new_key);
		if ( l_result != ERROR_SUCCESS )
			return FALSE;

		RegCloseKey(h_key);
	}

	RegOpenKeyEx( HKEY_LOCAL_MACHINE, sz_register_path_, 0, KEY_WRITE, &h_key );
	l_result = RegSetValueEx(h_key, sz_key_name_, NULL, REG_SZ, (const BYTE*)sz_string_, lstrlen(sz_string_)*sizeof(sz_string_[0])+sizeof(sz_string_[0]));
	if ( l_result != ERROR_SUCCESS )
		return FALSE;

	RegCloseKey(h_key);
	return TRUE;
}



//-----------------------------------------------------------------------------
// ! 读取注册表指定路径的指定键值
//-----------------------------------------------------------------------------
BOOL tool::read_rigister(LPCTSTR sz_register_path_, LPCTSTR sz_key_name_, DWORD& dw_key_value_)
{
	HKEY h_key;
	long l_result = RegOpenKeyEx( HKEY_LOCAL_MACHINE, sz_register_path_, 0, KEY_QUERY_VALUE, &h_key );
	if( l_result != ERROR_SUCCESS )
		return FALSE;

	DWORD dw_buffer_length=32;
	RegQueryValueEx( h_key, sz_key_name_, NULL, NULL, (LPBYTE)&dw_key_value_, &dw_buffer_length);
	RegCloseKey(h_key);

	return TRUE;
}


//-----------------------------------------------------------------------------
// 读注册表
//-----------------------------------------------------------------------------
BOOL tool::read_rigister(LPCTSTR sz_register_path_, LPCTSTR sz_key_name_, LPTSTR sz_out_)
{
	ASSERT( sz_out_ != NULL );
	HKEY h_key;
	long l_result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, sz_register_path_, 0, KEY_READ, &h_key);
	if ( l_result != ERROR_SUCCESS )
	{
		sz_out_[0] = 0;
		return FALSE;
	}
	DWORD dw_length = MAX_PATH, dw_type = REG_SZ;
	
	RegQueryValueEx(h_key, sz_key_name_, NULL, &dw_type, (LPBYTE)sz_out_, &dw_length);

	RegCloseKey(h_key);
	return TRUE;
}

bool tool::is_debug_present()
{
	__asm
	{
		mov     eax, fs:18h
		mov     eax, [eax+30h]
		movzx   eax, byte ptr [eax+2]
	}
}

//----------------------------------------------------------------------------------
// ! 通用的加解密函数
//----------------------------------------------------------------------------------
BOOL tool::encrypt_and_decrypt(UCHAR* p_in_, UCHAR* p_out_, const INT n_length_, UCHAR* p_key_, bool b_encypt_)
{
	if( n_length_ % 8 != 0 || n_length_ <= 0 )
		return FALSE;

	des3_context context;
	des3_set_3keys(&context, p_key_, p_key_+8, p_key_+16);

	for(INT i = 0; i < n_length_; i += 8)
	{
		if( b_encypt_ )
			des3_encrypt(&context, &p_in_[i], &p_out_[i]);
		else
			des3_decrypt(&context, &p_in_[i], &p_out_[i]);
	}

	return TRUE;
}

//---------------------------------------------------------------------------------------
//! 通过密匙对某段内存区域加密（内存区域必须满足8字节的整数倍）
//---------------------------------------------------------------------------------------
BOOL tool::encrypt(VOID* p_in_, VOID* p_out_, const INT n_length_, UCHAR* p_key_)
{
	return encrypt_and_decrypt((UCHAR*)p_in_, (UCHAR*)p_out_, n_length_, p_key_, 1);
}

//---------------------------------------------------------------------------------------
// ! 通过密匙对某段内存区域解密（内存区域必须满足8字节的整数倍）
//---------------------------------------------------------------------------------------
BOOL tool::decrypt(VOID* p_in_, VOID* p_out_, const INT n_length_, UCHAR* p_key_)
{
	return encrypt_and_decrypt((UCHAR*)p_in_, (UCHAR*)p_out_, n_length_, p_key_, 0);
}
UCHAR* GetKeys(const INT n_index_, const INT n_mode_)
{
	switch(n_mode_)
	{
	case 0:
		return (UCHAR*)key_1[n_index_];
	case 1:
		return (UCHAR*)key_2[n_index_];
	default:
		ASSERT(0);
		return NULL;
	}	
}
//-----------------------------------------------------------------------------------------
// ! 通过密匙数组中的索引对某个内存区域进行加密 
//-----------------------------------------------------------------------------------------
BOOL tool::encrypt(VOID* p_in_, VOID* p_out_, const INT n_length_, const INT n_index_, const INT n_mode_)
{
	ASSERT( n_index_ >= 0 && n_index_ < 20 );
	ASSERT( n_mode_ >= 0 && n_mode_ < 2);
	UCHAR* p_key = GetKeys(n_index_, n_mode_);
	if(!VALID_POINT(p_key))
		return FALSE;
	return encrypt_and_decrypt((UCHAR*)p_in_, (UCHAR*)p_out_, n_length_, p_key, 1);
}

//-----------------------------------------------------------------------------------------
// ! 通过密匙数组中的索引对某个内存区域进行解密
//-----------------------------------------------------------------------------------------
BOOL tool::decrypt(VOID* p_in_, VOID* p_out_, const INT n_length_, const INT n_index_, const INT n_mode_)
{
	ASSERT( n_index_ >= 0 && n_index_ < 20 );
	ASSERT( n_mode_ >= 0 && n_mode_ < 2);
	UCHAR* p_key = GetKeys(n_index_, n_mode_);
	if(!VALID_POINT(p_key))
		return FALSE;
	return encrypt_and_decrypt((UCHAR*)p_in_, (UCHAR*)p_out_, n_length_, p_key, 0);
}


//-----------------------------------------------------------------------------
//! md5 运算
//-----------------------------------------------------------------------------
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21
//--------------------------------------------------------------------
//！线性函数
//--------------------------------------------------------------------

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))


#define RIGHT_ROTATE_MOVE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))


#define FF(a, b, c, d, x, s, ac) \
{ \
	(a) += F ((b), (c), (d)) + (x) + (DWORD)(ac); \
	(a) = RIGHT_ROTATE_MOVE_LEFT ((a), (s)); \
	(a) += (b); \
}
#define GG(a, b, c, d, x, s, ac)\
{ \
	(a) += G ((b), (c), (d)) + (x) + (DWORD)(ac); \
	(a) = RIGHT_ROTATE_MOVE_LEFT ((a), (s)); \
	(a) += (b); \
}
#define HH(a, b, c, d, x, s, ac) \
{ \
	(a) += H ((b), (c), (d)) + (x) + (DWORD)(ac); \
	(a) = RIGHT_ROTATE_MOVE_LEFT ((a), (s)); \
	(a) += (b); \
}
#define II(a, b, c, d, x, s, ac) \
{ \
	(a) += I ((b), (c), (d)) + (x) + (DWORD)(ac); \
	(a) = RIGHT_ROTATE_MOVE_LEFT ((a), (s)); \
	(a) += (b); \
}


//--------------------------------------------------------------------
static BYTE by_num[64] =
{
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};


void tool::md5_init()
{
	st_context._count[0] = st_context._count[1] = 0;

	st_context._state[0] = 0x67452301;
	st_context._state[1] = 0xefcdab89;
	st_context._state[2] = 0x98badcfe;
	st_context._state[3] = 0x10325476;
}

void tool::md5_update(BYTE *p_in_, UINT n_in_length_)
{
	UINT i=0;
	UINT n_index = 0;
	UINT n_length = 0;

	n_index = (UINT)( (st_context._count[0] >> 3) & 0x3F );
	if( (st_context._count[0] += ((DWORD)n_in_length_ << 3)) < ((DWORD)n_in_length_ << 3) )
		st_context._count[1]++;
	st_context._count[1] += ((DWORD)n_in_length_ >> 29);
	n_length = 64 - n_index;

	if( n_in_length_ >= n_length )
	{
		memcpy(st_context._buffer+n_index, p_in_, n_length);
		md5_transform(st_context._state, st_context._buffer);

		for(i=n_length; i+63 < n_in_length_; i+=64)
			md5_transform(st_context._state, p_in_+i);

		n_index = 0;
	}
	else 
		i = 0;
	memcpy(st_context._buffer+n_index, p_in_+i, n_in_length_-i);
}

void tool::md5_final(BYTE by_digest_[16])
{
	BYTE by_bits[8];
	UINT n_index = 0;
	UINT n_length;

	encode(by_bits, st_context._count, 8);

	n_index = (UINT)((st_context._count[0] >> 3) & 0x3f);
	n_length = (n_index < 56) ? (56-n_index) : (120-n_index);

	md5_update(by_num, n_length);
	md5_update(by_bits, 8);
	encode(by_digest_, st_context._state, 16);

	memset(&st_context, 0, sizeof(MD5_CONTEXT));
}


void tool::md5_transform (DWORD state_[4], unsigned char block_[64])
{
	DWORD a = state_[0], b = state_[1], c = state_[2], d = state_[3];
	DWORD x[16];

	decode (x, block_, 64);

	/* Round 1 */
	FF (a, b, c, d, x[ 0], S11, 0xd76aa478); /* 1 */
	FF (d, a, b, c, x[ 1], S12, 0xe8c7b756); /* 2 */
	FF (c, d, a, b, x[ 2], S13, 0x242070db); /* 3 */
	FF (b, c, d, a, x[ 3], S14, 0xc1bdceee); /* 4 */
	FF (a, b, c, d, x[ 4], S11, 0xf57c0faf); /* 5 */
	FF (d, a, b, c, x[ 5], S12, 0x4787c62a); /* 6 */
	FF (c, d, a, b, x[ 6], S13, 0xa8304613); /* 7 */
	FF (b, c, d, a, x[ 7], S14, 0xfd469501); /* 8 */
	FF (a, b, c, d, x[ 8], S11, 0x698098d8); /* 9 */
	FF (d, a, b, c, x[ 9], S12, 0x8b44f7af); /* 10 */
	FF (c, d, a, b, x[10], S13, 0xffff5bb1); /* 11 */
	FF (b, c, d, a, x[11], S14, 0x895cd7be); /* 12 */
	FF (a, b, c, d, x[12], S11, 0x6b901122); /* 13 */
	FF (d, a, b, c, x[13], S12, 0xfd987193); /* 14 */
	FF (c, d, a, b, x[14], S13, 0xa679438e); /* 15 */
	FF (b, c, d, a, x[15], S14, 0x49b40821); /* 16 */

	/* Round 2 */
	GG (a, b, c, d, x[ 1], S21, 0xf61e2562); /* 17 */
	GG (d, a, b, c, x[ 6], S22, 0xc040b340); /* 18 */
	GG (c, d, a, b, x[11], S23, 0x265e5a51); /* 19 */
	GG (b, c, d, a, x[ 0], S24, 0xe9b6c7aa); /* 20 */
	GG (a, b, c, d, x[ 5], S21, 0xd62f105d); /* 21 */
	GG (d, a, b, c, x[10], S22,  0x2441453); /* 22 */
	GG (c, d, a, b, x[15], S23, 0xd8a1e681); /* 23 */
	GG (b, c, d, a, x[ 4], S24, 0xe7d3fbc8); /* 24 */
	GG (a, b, c, d, x[ 9], S21, 0x21e1cde6); /* 25 */
	GG (d, a, b, c, x[14], S22, 0xc33707d6); /* 26 */
	GG (c, d, a, b, x[ 3], S23, 0xf4d50d87); /* 27 */
	GG (b, c, d, a, x[ 8], S24, 0x455a14ed); /* 28 */
	GG (a, b, c, d, x[13], S21, 0xa9e3e905); /* 29 */
	GG (d, a, b, c, x[ 2], S22, 0xfcefa3f8); /* 30 */
	GG (c, d, a, b, x[ 7], S23, 0x676f02d9); /* 31 */
	GG (b, c, d, a, x[12], S24, 0x8d2a4c8a); /* 32 */

	/* Round 3 */
	HH (a, b, c, d, x[ 5], S31, 0xfffa3942); /* 33 */
	HH (d, a, b, c, x[ 8], S32, 0x8771f681); /* 34 */
	HH (c, d, a, b, x[11], S33, 0x6d9d6122); /* 35 */
	HH (b, c, d, a, x[14], S34, 0xfde5380c); /* 36 */
	HH (a, b, c, d, x[ 1], S31, 0xa4beea44); /* 37 */
	HH (d, a, b, c, x[ 4], S32, 0x4bdecfa9); /* 38 */
	HH (c, d, a, b, x[ 7], S33, 0xf6bb4b60); /* 39 */
	HH (b, c, d, a, x[10], S34, 0xbebfbc70); /* 40 */
	HH (a, b, c, d, x[13], S31, 0x289b7ec6); /* 41 */
	HH (d, a, b, c, x[ 0], S32, 0xeaa127fa); /* 42 */
	HH (c, d, a, b, x[ 3], S33, 0xd4ef3085); /* 43 */
	HH (b, c, d, a, x[ 6], S34,  0x4881d05); /* 44 */
	HH (a, b, c, d, x[ 9], S31, 0xd9d4d039); /* 45 */
	HH (d, a, b, c, x[12], S32, 0xe6db99e5); /* 46 */
	HH (c, d, a, b, x[15], S33, 0x1fa27cf8); /* 47 */
	HH (b, c, d, a, x[ 2], S34, 0xc4ac5665); /* 48 */

	/* Round 4 */
	II (a, b, c, d, x[ 0], S41, 0xf4292244); /* 49 */
	II (d, a, b, c, x[ 7], S42, 0x432aff97); /* 50 */
	II (c, d, a, b, x[14], S43, 0xab9423a7); /* 51 */
	II (b, c, d, a, x[ 5], S44, 0xfc93a039); /* 52 */
	II (a, b, c, d, x[12], S41, 0x655b59c3); /* 53 */
	II (d, a, b, c, x[ 3], S42, 0x8f0ccc92); /* 54 */
	II (c, d, a, b, x[10], S43, 0xffeff47d); /* 55 */
	II (b, c, d, a, x[ 1], S44, 0x85845dd1); /* 56 */
	II (a, b, c, d, x[ 8], S41, 0x6fa87e4f); /* 57 */
	II (d, a, b, c, x[15], S42, 0xfe2ce6e0); /* 58 */
	II (c, d, a, b, x[ 6], S43, 0xa3014314); /* 59 */
	II (b, c, d, a, x[13], S44, 0x4e0811a1); /* 60 */
	II (a, b, c, d, x[ 4], S41, 0xf7537e82); /* 61 */
	II (d, a, b, c, x[11], S42, 0xbd3af235); /* 62 */
	II (c, d, a, b, x[ 2], S43, 0x2ad7d2bb); /* 63 */
	II (b, c, d, a, x[ 9], S44, 0xeb86d391); /* 64 */

	state_[0] += a;
	state_[1] += b;
	state_[2] += c;
	state_[3] += d;

	memset(x, 0, sizeof(x));
}

void tool::encode(BYTE* p_out_, DWORD* p_in_, unsigned int n_length_)
{
	UINT i, j;

	for (i=0, j=0; j<n_length_; i++, j+=4)
	{
		p_out_[j] = (unsigned char)(p_in_[i] & 0xff);
		p_out_[j+1] = (unsigned char)((p_in_[i] >> 8) & 0xff);
		p_out_[j+2] = (unsigned char)((p_in_[i] >> 16) & 0xff);
		p_out_[j+3] = (unsigned char)((p_in_[i] >> 24) & 0xff);
	}
}

void tool::decode(DWORD* p_out_, BYTE* p_in_, unsigned int n_length_)
{
	UINT i, j;

	for (i=0, j=0; j<n_length_; i++, j+=4)
		p_out_[i] = ((DWORD)p_in_[j]) | (((DWORD)p_in_[j+1]) << 8) |
		(((DWORD)p_in_[j+2]) << 16) | (((DWORD)p_in_[j+3]) << 24);
}


//-----------------------------------------------------------------------
// ! 获得md5摘要信息
//-----------------------------------------------------------------------
BOOL tool::md5_for_file(LPCTSTR sz_file_name_, BYTE by_digest_[16])
{
	if( NULL == sz_file_name_ )
		return FALSE;

	HANDLE h_file = ::CreateFile(sz_file_name_, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS, NULL);
	if( INVALID_HANDLE_VALUE == h_file ) 
		return FALSE;


	INT64 n64_file_size = 0;
	INT64 n64_current = 0;
	SYSTEM_INFO st_system_info;
	::GetSystemInfo(&st_system_info); 
	
	INT64 n64_section = (1024*1024*128) / st_system_info.dwAllocationGranularity * st_system_info.dwAllocationGranularity;

	::GetFileSizeEx(h_file, (PLARGE_INTEGER)&n64_file_size);	

	HANDLE h_file_map = CreateFileMapping(h_file, NULL, PAGE_READONLY, 0, 0, NULL);
	if( NULL == h_file_map )
	{
		::CloseHandle(h_file);
		return FALSE;
	}

	md5_init();
	LPVOID p_buffer = NULL;
	while( n64_file_size > 0 )
	{
		if( n64_file_size > n64_section )
		{
			p_buffer = ::MapViewOfFile(h_file_map, FILE_MAP_READ, (DWORD)(n64_current>>32), (DWORD)n64_current, (DWORD)n64_section);
			md5_update((BYTE*)p_buffer, (DWORD)n64_section);
			n64_current += n64_section;
			n64_file_size -= n64_section;
		}
		else
		{
			p_buffer = ::MapViewOfFile(h_file_map, FILE_MAP_READ, (DWORD)(n64_current>>32), (DWORD)n64_current, (DWORD)n64_file_size);
			md5_update((BYTE*)p_buffer, (DWORD)n64_file_size);
			n64_file_size = 0;
		}

		::UnmapViewOfFile(p_buffer);
	}

	md5_final(by_digest_);
	CloseHandle(h_file_map);
	CloseHandle(h_file);


	return TRUE;
}


//-----------------------------------------------------------------------
// ! 获得md5摘要信息
//-----------------------------------------------------------------------
VOID tool::md5_to_string(std::string& string_, BYTE by_digest_[16])
{
	char sz_buffer[256];
	ZeroMemory(sz_buffer, sizeof(sz_buffer));
	for(int i=0; i<16; i++)
		sprintf(sz_buffer, "%s%02x", sz_buffer, by_digest_[i]);

	string_ = sz_buffer;
}


//-----------------------------------------------------------------------
// ! 获得md5摘要信息
//-----------------------------------------------------------------------
VOID tool::md5_for_string(CHAR* sz_string_, BYTE by_digest_[16])
{
	UINT n_length = (UINT)strlen(sz_string_);
	md5_for_buffer((BYTE*)sz_string_, n_length, by_digest_);
}


//-----------------------------------------------------------------------
//! 获得md5摘要信息
//-----------------------------------------------------------------------
VOID tool::md5_for_buffer(BYTE* p_buffer_, UINT n_buffer_length_, BYTE by_digest_[16])
{
	md5_init();
	md5_update(p_buffer_, n_buffer_length_);
	md5_final(by_digest_);
}

} // namespace serverbase {


