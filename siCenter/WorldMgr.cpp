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
*	@file		WorldMgr.cpp
*	@author		lc
*	@date		2011/03/16	initial
*	@version	0.0.1.0
*	@brief		游戏世界管理器
*/

#include "StdAfx.h"
#include "WorldMgr.h"
#include "WorldServer.h"
#include "center_server.h"
#include "../common/ServerDefine/paimai_define.h"


WorldMgr::WorldMgr(void)
{
	p_session = new few_connect_server;
	p_memory_pool = new memorysystem::MemPool(32 * 1024);
}

WorldMgr::~WorldMgr(void)
{
	SAFE_DELETE(p_session);
	SAFE_DELETE(p_memory_pool);
}

BOOL WorldMgr::init()
{

	get_tool()->tool_randomize(unsigned(time(0)));

	INT n_world_num = center_server::m_pVar->get_dword(_T("num zone_server"));

	for(INT n = 0; n < n_world_num; ++n)
	{
		WorldServer* p_world = new WorldServer;

		if( FALSE == p_world->init(n) )
		{
			SAFE_DELETE(p_world);
			return FALSE;
		}
		map_world.add(p_world->get_id(), p_world);
	}

	if( map_world.empty() )
		return FALSE;

	register_net_message();

	INT n_port = center_server::m_pVar->get_int(_T("port"), _T("zone_session"));
	p_session->init(fastdelegate::MakeDelegate(this, &WorldMgr::login_call_back),
		fastdelegate::MakeDelegate(this, &WorldMgr::logout_call_back), n_port);

	return TRUE;
}

VOID WorldMgr::destroy()
{
	WorldServer* p_world = NULL;

	map_world.reset_iterator();
	while( map_world.find_next(p_world) )
	{
		SAFE_DELETE(p_world);
	}
	map_world.clear();

	p_session->destory();

	unregister_net_message();
}

VOID WorldMgr::update()
{
	WorldServer* p_world = NULL;

	map_world.reset_iterator();
	while( map_world.find_next(p_world) )
	{
		p_world->update();
	}
}

VOID WorldMgr::register_net_message()
{
	REGISTER_NET_MSG("NET_G2P_Login",		WorldMgr,	handle_login,		_T("NET_G2P_Login") );
	REGISTER_NET_MSG("NET_W2C_verify_code",	WorldMgr,	handle_verify_code,		_T("NET_W2C_verify_code") );
}

VOID WorldMgr::unregister_net_message()
{
	UNREGISTER_NET_MSG("NET_G2P_Login",			WorldMgr,	handle_login);
	UNREGISTER_NET_MSG("NET_W2C_verify_code",	WorldMgr,	handle_verify_code);
}

DWORD WorldMgr::login_call_back(LPBYTE p_byte_, DWORD dw_size_)
{
	NET_G2P_Login* p_receive = (NET_G2P_Login*)p_byte_;

	g_center_server.lock_update();

	DWORD dw_name_crc = get_tool()->crc32(p_receive->sz_ServerName);

	WorldServer* p_world = get_world(dw_name_crc);
	if( !VALID_POINT(p_world) )
	{
		print_message(_T("worldServer login fail, world<%s>not regist\r\n"), p_receive->sz_ServerName);

		g_center_server.unlock_update();

		return INVALID_VALUE;
	}

	if( !p_world->world_login() )
	{
		print_message(_T("world<%s>has exist\r\n"), p_receive->sz_ServerName);

		g_center_server.unlock_update();

		return INVALID_VALUE;
	}

	print_message(_T("world<%s>login success\r\n"),p_receive->sz_ServerName);

	g_center_server.unlock_update();

	return dw_name_crc;
}

DWORD WorldMgr::logout_call_back(DWORD dw_param_)
{
	DWORD dw_world_id = dw_param_;

	g_center_server.lock_update();

	WorldServer* p_world = get_world(dw_world_id);
	if( !VALID_POINT(p_world) )
	{
		g_center_server.unlock_update();

		return 0; 
	}

	p_world->world_logout();
	print_message(_T("游戏世界<%s>登出\r\n"), p_world->get_name());

	g_center_server.unlock_update();

	return 0;
}

DWORD WorldMgr::handle_login(tag_net_message* p_message_, WorldServer* p_world_)
{
	NET_P2G_Login send;
	send.dw_Error = E_Success;
	p_session->send_msg(p_world_->get_id(), &send, send.dw_size);

	return E_Success;
}

VOID WorldMgr::productVerify(DWORD dwType, TCHAR* str, DWORD& dwParam, DWORD& dwAnswer)
{
	switch (dwType)
	{
	case 0:
		productVerifyOne(str, dwParam, dwAnswer);
		break;
	case 1:
		productVerifyTwo(str, dwParam, dwAnswer);
		break;
	case 2:
		productVerifyThree(str, dwParam, dwAnswer);
		break;
	default:
		productVerifyOne(str, dwParam, dwAnswer);
		break;
	}
}

VOID WorldMgr::productVerifyOne(TCHAR* str, DWORD& dwParam, DWORD& dwAnswer)
{
	//srand(unsigned(time(0)));

	for (int i = 0; i < 4; i++)
	{
		INT32 nType = get_tool()->tool_rand()%3;
		if (nType == 0)
		{
			str[i] = get_tool()->rand_in_range(_T('a'), _T('z'));
		}
		else if(nType == 1)
		{
			str[i] = get_tool()->rand_in_range(_T('A'), _T('Z'));
		}
		else
		{
			str[i] = get_tool()->rand_in_range(_T('1'), _T('9'));
		}
	}

	{
		dwParam = get_tool()->tool_rand()%4;
		TCHAR sz[2] = _T(""); 
		sz[0] = str[dwParam];

		tstring strTmp = sz;
		transform(strTmp.begin(), strTmp.end(), strTmp.begin(), tolower);
		dwAnswer = get_tool()->crc32(strTmp.c_str());
	}	
}

VOID WorldMgr::productVerifyTwo(TCHAR* str, DWORD& dwParam, DWORD& dwAnswer)
{
	//srand(unsigned(time(0)));

	str[3] = _T('=');
	
	INT nParam1 = get_tool()->rand_in_range(1,9);
	INT nParam2 = get_tool()->rand_in_range(1,9);

	TCHAR szParam[][9] = {
		{_T('壹'), _T('贰'), _T('叁'), _T('肆'), _T('伍'), _T('陆'), _T('柒'), _T('捌'), _T('玖')},
		{_T('1'), _T('2'), _T('3'), _T('4'), _T('5'), _T('6'), _T('7'), _T('8'), _T('9')}
	};

	TCHAR szType[][2] = { {_T('加'), _T('乘')}, {_T('+'), _T('×')}};

	str[0] = szParam[get_tool()->tool_rand()%2][nParam1-1];
	str[2] = szParam[get_tool()->tool_rand()%2][nParam2-1];
	
	BYTE byTpe = get_tool()->tool_rand() % 2;
	if (byTpe == 0)
	{ 
		str[1] = szType[get_tool()->tool_rand()%2][0];
		dwAnswer = nParam1 + nParam2;
	}
	else if(byTpe == 1)
	{
		str[1] = szType[get_tool()->tool_rand()%2][1];
		dwAnswer = nParam1 * nParam2;
	}

}

// 随机生成n个相同汉字
VOID WorldMgr::productVerifyThree(TCHAR* str, DWORD& dwParam, DWORD& dwAnswer)
{
	//srand(unsigned(time(0)));
	DWORD dwStrNum = 4;

	dwAnswer = get_tool()->tool_rand() % dwStrNum;

	INT nMin = _T('A');
	INT nMax = _T('Z');
	INT nTemp = 0;

	INT nTime = dwStrNum-dwAnswer;
	for (int i = 0; i < nTime; i++)
	{
		nTemp = get_tool()->rand_in_range(nMin, nMax);
		str[i] = nTemp;
		if ((nTemp - nMin) >= (nMax - nTemp))
		{
			nMax = nTemp-1;
		}
		else
		{
			nMin = nTemp+1;
		}
	}
	for (int i = dwAnswer, j = dwStrNum-1; i > 0; i--,j--)
	{
		str[j] = str[0];
	}

	if (dwAnswer != 0)
	{
		dwAnswer++;
	}
}

DWORD WorldMgr::handle_verify_code(tag_net_message* p_message, WorldServer* p_world)
{
	//srand(unsigned(time(0)));

	//NET_W2C_verify_code* p_receive = (NET_W2C_verify_code*)p_message;
	//
	//tstring str;
	//TCHAR szTemp[X_SHORT_NAME] = _T("");
	//DWORD dwParam = 0;
	//DWORD dwAnswer = 0;

	//DWORD dwType = 0;
	//INT nPro = get_tool()->tool_rand() % 100;
	//if (nPro > 90)
	//{
	//	dwType = 1;
	//}
	////DWORD dwType = get_tool()->tool_rand() % 2;
	//productVerify(dwType, szTemp, dwParam, dwAnswer);
	//
	//str = szTemp;
	//
	//// 颜色类型
	//DWORD dwColor = COLOR_1BITS;
	//// 未压缩数据所需内存
	//size_t iGetSize = m_oCreator.GetMemorySize(dwColor);
	//BYTE* pImage = (BYTE*)p_memory_pool->alloc_memory(iGetSize);
	//ZeroMemory(pImage, iGetSize);


	//// 获取图像数据
	//DWORD dwTempSize = 0;
	//DWORD dwFlag = POLICY_BM_1BIT;
	//switch(dwType)
	//{
	//case 1:
	//	dwFlag |= POLICY_GM_ODER;
	//	break;
	//case 2:
	//	dwFlag |= POLICY_GM_CLUSTER;
	//	break;
	//default:
	//	dwFlag |= POLICY_GM_ODER;
	//	break;
	//}

	//if (!m_oCreator.GenerateImage( pImage, str, iGetSize, dwTempSize, dwFlag))
	//{
	//	p_memory_pool->free_memory(pImage);
	//	NET_C2W_verify_code send;
	//	send.dw_error_code = INVALID_VALUE;
	//	p_session->send_msg(p_world->get_id(), &send, send.dw_size);
	//	return E_Success;
	//}
	//
	//DWORD dwBuffSize = dwTempSize;
	//// 若用的是256色,压缩下
	//if (dwColor == COLOR_8BITS)
	//{

	//	BYTE* pZipImage = (BYTE*)p_memory_pool->alloc_memory(dwTempSize);
	//	ZeroMemory(pZipImage, dwTempSize);
	//	compress( pZipImage, &dwTempSize, pImage, iGetSize);
	//	dwBuffSize = dwTempSize;
	//	memcpy(pImage, pZipImage, dwBuffSize);
	//	p_memory_pool->free_memory(pZipImage);
	//}

	//INT nBuffSize = sizeof(NET_C2W_verify_code) - sizeof(BYTE) + sizeof(BYTE) * dwBuffSize;
	//BYTE* pBuff = (BYTE*)p_memory_pool->alloc_memory(nBuffSize);
	//ZeroMemory(pBuff, nBuffSize);

	//NET_C2W_verify_code* pSend = (NET_C2W_verify_code*)pBuff;
	//
	//memcpy(pSend->by_code, pImage, dwBuffSize);

	//pSend->dw_message_id = pSend->message_id_crc("NET_C2W_verify_code");
	//pSend->dw_account_id = p_receive->dw_account_id;
	//pSend->n_verify_code_size = iGetSize;
	//pSend->dw_type = dwType;
	//pSend->dw_param = dwParam;
	//pSend->dw_answer_crc = dwAnswer;

	//pSend->dw_size = nBuffSize;
	//p_session->send_msg(p_world->get_id(), pSend, pSend->dw_size);


	//p_memory_pool->free_memory(pImage);
	//p_memory_pool->free_memory(pBuff);

	return E_Success;
}