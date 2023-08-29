//-----------------------------------------------------------------------------
//★Name				:   exchange_define.h
//★Compiler			:	Microsoft Visual C++ 9.0Sxg
//★Version				:	1.00
//★Create Date			:	2008-08-25
//★LastModified		:	
//★Brief				:	玩家间交易
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
const INT32 MAX_EXCHANGE_ITEM			= 5;				// 一次最多交换5件物品 gx modify 2013.11.25
const INT32 MAX_EXCHANGE_MONEY			= 0;				// 0
const FLOAT MAX_EXCHANGE_DISTANCE		= 3 * 48.0f;		// 交易距离(3个格子)gx modify 2013.7.2
const INT32 MAX_EXCHANGE_DELAY_TIME		= 15 * 1000;		// 等待时间15秒，交易申请菜单无响应关闭
const INT32	MAX_EXCHANGE_SPACE			= 20 * TILE_SCALE;	// 玩家交互（包括和玩家，NPC，摊位的情况）最远距离
//-----------------------------------------------------------------------------

