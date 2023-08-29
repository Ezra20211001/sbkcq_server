#include "StdAfx.h"
#include "WorldServer.h"
#include "center_server.h"

WorldServer::WorldServer(void)
{
}

WorldServer::~WorldServer(void)
{
	destroy();
}

BOOL WorldServer::init(INT n_index_)
{
	if( n_index_ < 0 ) return FALSE;

	dw_time_	=	timeGetTime();

	TCHAR sz_temp[X_SHORT_NAME] = {_T('\0')};
	_stprintf(sz_temp, _T("zone%d"), n_index_);

	tstring str_world_name = center_server::m_pVar->get_string(_T("name"), sz_temp);
	if( str_world_name.empty() ) return FALSE;

	data_.b_connect			=	FALSE;
	data_.dw_name_crc		=	get_tool()->crc32(str_world_name.c_str());
	data_.dw_ip				=	0;
	data_.n_port			=	0;
	_tcsncpy(data_.sz_name, str_world_name.c_str(), X_SHORT_NAME);

	return TRUE;
}

VOID WorldServer::update()
{
	if( is_connect() )
	{
		update_session();
	}
}

VOID WorldServer::destroy()
{

}

BOOL WorldServer::world_login()
{
	if( is_connect() ) return FALSE;	

	data_.b_connect			=	TRUE;

	return TRUE;
}

BOOL WorldServer::world_logout()
{
	if( !is_connect() ) return FALSE;	

	data_.b_connect			=	FALSE;
	data_.dw_ip				=	0;
	data_.n_port			=	0;

	return TRUE;
}

VOID WorldServer::update_session()
{
	LPBYTE	p_receive		=	NULL;
	DWORD	dw_size		=	0;
	INT		n_unrecv		=	0;
	DWORD	dw_time		=	0;

	p_receive = g_center_server.get_world_manager().recv_message(data_.dw_name_crc, dw_size, n_unrecv);

	while( VALID_POINT(p_receive) )
	{
		g_center_server.get_world_manager().handle_command((tag_net_message*)p_receive, dw_size, (DWORD)this);

		g_center_server.get_world_manager().return_message(data_.dw_name_crc, p_receive);

		p_receive = g_center_server.get_world_manager().recv_message(data_.dw_name_crc, dw_size, n_unrecv);
	}
}
