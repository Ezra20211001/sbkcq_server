#pragma once
#pragma pack(push, 1)

// ���������������
const UINT16 MAX_REP_RANK_NUM				= 50;

// �����䱦����
const UINT16 CLAN_TREASURE_NUM				= 300;




//----------------------------------------------------------------------------
// �����䱦
//----------------------------------------------------------------------------
struct tagTreasureData
{
	UINT16	n16TreasureID;			// �䱦id
	DWORD	dwNamePrefixID;			// �䱦����ǰ׺
}; 

//-----------------------------------------------------------------------------
// ������������
//-----------------------------------------------------------------------------
struct tagRepRankData
{
	DWORD	dw_role_id;				// ��ɫID
	DWORD	dwReputValue;			// ����ֵ
};


#pragma pack(pop)