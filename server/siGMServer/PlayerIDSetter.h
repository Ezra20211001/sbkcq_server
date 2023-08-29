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
 *	@file		PlayerIDSetter
 *	@author		mwh
 *	@date		2011/04/06	initial
 *	@version	0.0.1.0
 *	@brief		ID������,����������ʱ��SessionID
*/

#ifndef __PLAYERID_SETTER_H__
#define __PLAYERID_SETTER_H__

// LoginServerSessionID ǿ��Ϊ1
#define LOGINSERVERID 1

// GameServerSessionID Ϊ���ֵ�CRC

// GM�ͻ���ID Ϊ ���ݿ� AccountID
 struct GMPlayerIDAllocator
 {
 	DWORD mIDHolder;
 public:
 	DWORD NewID() { return ++mIDHolder; }
 public:	
 	GMPlayerIDAllocator():mIDHolder(0){ }
 };

#endif // __PLAYERID_SETTER_H__