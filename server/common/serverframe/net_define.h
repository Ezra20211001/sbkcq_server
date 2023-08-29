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
*	@file		message_define.h
*	@author		lc
*	@date		2011/02/16	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef MESSAGE_DEFINE
#define MESSAGE_DEFINE

namespace serverframe {
CONST INT SELECT_BLOCK_TIME = 1000*150;	// 150 ms


//-----------------------------------------------------------------------------
// ! 网络消息结构
//-----------------------------------------------------------------------------
struct tag_net_message
{
	DWORD	dw_message_id;
	DWORD	dw_size;
	//CHAR	sz_message_name[100];

	DWORD message_id_crc(LPCSTR sz_message_name_)
	{
		//strncpy(sz_message_name, sz_message_name_, sizeof(sz_message_name));
		UINT u_result;
		LPBYTE p_data = (LPBYTE)sz_message_name_;
		if( 0 == p_data[0] ) 
			return (DWORD)INVALID_VALUE;
		u_result = *p_data++ << 24;
		if( *p_data )
		{
			u_result |= *p_data++ << 16;
			if( *p_data )
			{
				u_result |= *p_data++ << 8;
				if( *p_data ) u_result |= *p_data++;
			}
		}
		u_result = ~ u_result;
		while( *p_data )
		{
			u_result = (u_result << 8 | *p_data) ^ crc32_table[u_result >> 24];
			p_data++;
		}
		return ~u_result;
	}
};

#ifndef NET_CMD_BEGIN
#define NET_CMD_BEGIN(name)	\
struct tag##name : public tag_net_message{	\
	tag##name(){ ZeroMemory(this,sizeof(*this));  \
	dw_message_id = message_id_crc(#name); dw_size = sizeof(*this); }
#define NET_CMD_END		};
#endif

} // namespace serverframe {
#endif
