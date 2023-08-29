#include "StdAfx.h"
#include "GMServer.h"
#include "LogDB.h"
#include "../common/WorldDefine/GMRoleLogQueryProtocol.h"
#include "../common/WorldDefine/container_define.h"
#include "../common/WorldDefine/ItemDefine.h"


LogDB::LogDB(void)
{
	m_p_db_interface = new db_interface;
}

LogDB::~LogDB(void)
{
	SAFE_DELETE(m_p_db_interface);
}
//根据角色名称获取角色ID
DWORD LogDB::get_roleid_by_role_name(DWORD dw_role_name_crc)
{
	DWORD dw_role_id = INVALID_VALUE;
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("role_data", "role_id");
	pStream->where_item();
	pStream->write_string("role_name_crc=") << dw_role_name_crc;

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
	{
		dw_role_id = (*p_result)[0].get_dword();
	}


	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);

	return dw_role_id;
}
DWORD LogDB::get_account_by_role_name(DWORD	dw_role_name_crc)
{
	DWORD dw_account_id = INVALID_VALUE;
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("role_data", "account_id");
	pStream->where_item();
	pStream->write_string("role_name_crc=") << dw_role_name_crc;

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
	{
		dw_account_id = (*p_result)[0].get_dword();
	}
	
	
	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);

	return dw_account_id;
}
// 通过角色id获取账号ID
DWORD LogDB::get_account_by_role_id(DWORD dw_role_id)
{
	DWORD dw_account_id = INVALID_VALUE;
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("role_data", "account_id");
	pStream->where_item();
	pStream->write_string("role_id=") << dw_role_id;

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
	{
		dw_account_id = (*p_result)[0].get_dword();
	}


	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);

	return dw_account_id;
}
VOID LogDB::get_third_data_by_account_id(DWORD account_id,DWORD& dwthirdID,INT& nthirdType)
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("account_third", "third_id, third_type");
	pStream->where_item();
	pStream->write_string("account_id=") << account_id;

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
	{
		dwthirdID = (*p_result)[0].get_dword();
		nthirdType = (*p_result)[1].get_int();
	}

	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);
}
VOID LogDB::get_account_name_by_id(DWORD account_id, TCHAR* sz_account_name, BOOL& AccOL)
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("account", "name, login_status");
	pStream->where_item();
	pStream->write_string("id=") << account_id;

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
	{
		(*p_result)[0].get_tchar(sz_account_name, X_LONG_NAME);
		AccOL = (BOOL)(*p_result)[1].get_int();
	}

	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);
}

VOID LogDB::get_role_name_by_account_id(DWORD account_id, tag_Role_Name_Info& st_role_name_info)
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("role_data", "role_name");
	pStream->where_item();
	pStream->write_string("account_id=") << account_id;

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
	{
		INT n_num = p_result->get_row_count();

		INT n_index = 0;

		while(n_num)
		{
			(*p_result)[0].get_tchar(st_role_name_info.sz_role_name[n_index], X_SHORT_NAME);
			n_index++;
			n_num--;
			p_result->next_row();
		}
	}

	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);
}

VOID LogDB::get_role_del_list(DWORD dw_account_id, tag_Role_Del_List& st_role_del_list)
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("role_data", "role_name, role_id");
	pStream->where_item();
	pStream->write_string("account_id=") << dw_account_id;
	pStream->write_string(" and remove_flag = 1");

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
	{
		INT n_num = p_result->get_row_count();

		INT n_index = 0;

		while(n_num)
		{
			TCHAR sz_role_name[X_SHORT_NAME];
			ZeroMemory(sz_role_name, sizeof(sz_role_name));
			(*p_result)[0].get_tchar(sz_role_name, X_SHORT_NAME);

			st_role_del_list.v_role_id.push_back( (*p_result)[1].get_dword() );
			tstring str = sz_role_name;
			st_role_del_list.v_role_del.push_back(str);
			n_index++;
			n_num--;
			p_result->next_row();
		}
	}

	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);
}

BOOL LogDB::role_go_home(DWORD	dw_role_id)
{
	DWORD dw_map_id = get_tool()->crc32(_T("m1"));

	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->update_item("role_data");
	pStream->write_string("map_id=") << dw_map_id;
	pStream->write_string(",x=") << 30*48;
	pStream->write_string(",y=") << 0;
	pStream->write_string(",z=") << 30*48;
	pStream->where_item();
	pStream->write_string("role_id=") << dw_role_id;

	BOOL bRet = m_p_db_interface->sql_execute(pStream);

	m_p_db_interface->return_io(pStream);

	return bRet;

}

BOOL LogDB::revover_role(DWORD	dw_role_name_crc)
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->update_item("role_data");
	pStream->write_string("remove_flag=0");
	pStream->where_item();
	pStream->write_string("role_name_crc=") << dw_role_name_crc;

	BOOL bRet = m_p_db_interface->sql_execute(pStream);

	m_p_db_interface->return_io(pStream);

	return bRet;
}
//通过平台数字账号获取账号ID
BOOL LogDB::get_account_id_by_third_account_id(DWORD dwthirdID,INT nthird_type,DWORD& dwaccountID)
{
	dwaccountID = 0;

	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("account_third", "account_id");
	pStream->where_item();
	pStream->write_string("third_type=") << nthird_type;
	pStream->write_string(" AND third_id=") << dwthirdID;

	odbc::execute_result* p_result  = m_p_db_interface->sql_query(pStream);
	if(VALID_POINT(p_result) && p_result->get_row_count())
	{
		dwaccountID = (*p_result)[0].get_dword();
	}
	m_p_db_interface->free_result_query(p_result);
	m_p_db_interface->return_io(pStream);

	//if (0 == dwaccountID)
	//	return dwaccountID;
	////获取了account_id后，查询该账号当前的登录状态
	//pStream = m_p_db_interface->get_io();
	//pStream->clear();
	//pStream->select_item("account", "login_status");
	//pStream->where_item();
	//pStream->write_string("id=")<<dwaccountID;

	//p_result  = m_p_db_interface->sql_query(pStream);
	//if(VALID_POINT(p_result) && p_result->get_row_count())
	//{
	//	AccOL = (*p_result)[0].get_int();
	//}
	//m_p_db_interface->free_result_query(p_result);
	//m_p_db_interface->return_io(pStream);
	return dwaccountID;
}
BOOL LogDB::get_account_id_by_account_name(TCHAR* sz_account_name, DWORD& dwID, BOOL& AccOL)
{
	dwID = 0;

	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("account", "id, login_status");
	pStream->where_item();
	pStream->write_string("name='").write_string(sz_account_name).write_string("'");

	odbc::execute_result* p_result  = m_p_db_interface->sql_query(pStream);
	if(VALID_POINT(p_result) && p_result->get_row_count()){
		dwID = (*p_result)[0].get_dword();
		AccOL = (*p_result)[1].get_int();
	}

	m_p_db_interface->free_result_query(p_result);
	m_p_db_interface->return_io(pStream);
		
	return dwID;
}

BOOL LogDB::is_gm_account(DWORD dw_account_id)
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("account", "privilege");
	pStream->where_item();
	pStream->write_string("id=") << dw_account_id;

	odbc::execute_result* p_result  = m_p_db_interface->sql_query(pStream);

	return (!VALID_POINT(p_result) || p_result->get_row_count( ) <= 0) ? FALSE : TRUE;
}

VOID LogDB::get_role_list(DWORD account_id, tag_role_sim_info* _out, int _out_size)
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("role_data", "role_id, role_name");
	pStream->where_item();
	pStream->write_string("account_id=") << account_id;
	pStream->write_string(" and remove_flag = 0");

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
	{
		INT n_index = 0, n_num = p_result->get_row_count();
		while(n_num > 0 && n_index < _out_size)
		{
			_out[n_index].dw_role_id = (*p_result)[0].get_dword();
			(*p_result)[1].get_tchar(_out[n_index].sz_role_name, X_SHORT_NAME);

			n_index++; n_num--;
			p_result->next_row();
		}
	}

	m_p_db_interface->free_result_query(p_result);
	m_p_db_interface->return_io(pStream);
}

DWORD LogDB::get_guild_member_number(DWORD dw_guild_id)
{
	DWORD dw_number = 0;
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("guild_member", "count(*)");
	pStream->where_item();
	pStream->write_string("guild_id=") << dw_guild_id;

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
		dw_number = (*p_result)[0].get_dword();

	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);

	return dw_number;
}
// 查询物品数量
DWORD LogDB::get_item_number(DWORD dw_data_id)
{
	DWORD dw_number = 0;
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("item", "num");
	pStream->where_item();
	pStream->write_string("type_id=") << dw_data_id;

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);
	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
	{
		int n_row = p_result->get_row_count( );
		for(; n_row > 0; --n_row)
		{
			dw_number += (*p_result)[0].get_dword();
			p_result->next_row( );
		}
	}

	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);

	return dw_number;
}
//获取该账号当前已充值元宝总数
DWORD LogDB::get_account_totalrecharge(DWORD dw_account_id)
{
	DWORD dw_number = 0;
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("account_common", "total_recharge");
	pStream->where_item();
	pStream->write_string("account_id=") << dw_account_id;

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
		dw_number = (*p_result)[0].get_dword();

	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);

	return dw_number;
}
DWORD LogDB::get_account_yuanbao(DWORD dw_account_id)
{
	DWORD dw_number = 0;
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->select_item("account_common", "baibao_yuanbao");
	pStream->where_item();
	pStream->write_string("account_id=") << dw_account_id;

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
		dw_number = (*p_result)[0].get_dword();

	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);

	return dw_number;
}
//!
VOID LogDB::get_role_full_data(DWORD dw_role, VOID* out)
{
	NET_GMS2C_GetRoleFullData* pProtocol = (NET_GMS2C_GetRoleFullData*)out;
	INT nNumber = 0;
	//! 1.基本资料
	get_role_basic("role_data", &pProtocol->stData, INVALID_VALUE, dw_role, pProtocol->dw_size, nNumber);
	//! 1-E 获取身上元宝
	pProtocol->stData.dw_yuanbao = get_account_yuanbao(pProtocol->stData.dw_account_id);
	pProtocol->stData.n_totalrecharge = get_account_totalrecharge(pProtocol->stData.dw_account_id);//gx add
	VOID* p_buffer = pProtocol->stData.by_data;
	//! 2.物品
	pProtocol->stData.n_item_num = 0;
	get_role_item("", p_buffer, INVALID_VALUE, dw_role, pProtocol->dw_size, pProtocol->stData.n_item_num);

	//!3.技能
	pProtocol->stData.n_skill_num = 0;
	get_role_skill("", p_buffer, INVALID_VALUE, dw_role, pProtocol->dw_size, pProtocol->stData.n_skill_num);

	//! 4 - 1.宠物
	tag_role_pet* p_pet = (tag_role_pet*)p_buffer;
	pProtocol->stData.n_pets_num = 0;
	get_role_pet("", p_buffer, INVALID_VALUE, dw_role, pProtocol->dw_size, pProtocol->stData.n_pets_num);

	//! 4 - 2.宠物技能
	if(pProtocol->stData.n_pets_num)
	{
		for( int n = 0; n < pProtocol->stData.n_pets_num; ++n)
		{
			DWORD dwSize = 0;
			VOID* p_pet_buffer = &p_pet[n];
			get_role_pet_skill("", p_pet_buffer, INVALID_VALUE, p_pet[n].dw_id, dwSize, nNumber);
		}
	}
}
//! 角色基本资料
VOID LogDB::get_role_basic(const char* table_name, VOID* out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_get_role_basic),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_role_basic), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_get_role_basic(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item(table_name,
		"role_id," "role_name," "class," "level," "exp_cur_level,"
		"hp," "mp," "vitality," "vigour," "pk_value,"
		"guild_id," "map_id," "bag_size,"		"bag_gold,"	 "bag_silver,"	
		 "bag_copper," "bag_bind_gold,"	  "bag_bind_silver," "bag_bind_copper," "bag_yuanbao,"
		 "ware_size,"	"ware_gold,"	"ware_silver,"		"ware_copper,"  "x,"	"y,"	
		 "z," "account_id," "exploits," "sex," "knowledge");
	p_stream->where_item();
	p_stream->write_string("role_id=") << dw_role;
}
VOID LogDB::func_proc_res_role_basic(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	tag_role_data* p_data = (tag_role_data*)out_buffer;
	p_data->dw_role_id = (*p_result)[0].get_dword( );
	(*p_result)[1].get_tchar(p_data->sz_role_name, X_SHORT_NAME);
	p_data->e_class = (*p_result)[2].get_byte();
	p_data->n_level = (*p_result)[3].get_int();
	p_data->n_cur_exp = (*p_result)[4].get_int();
	p_data->n_hp  = (*p_result)[5].get_int();
	p_data->n_mp = (*p_result)[6].get_int();
	p_data->n_brotherhood = (*p_result)[7].get_int();
	p_data->n_vigour = (*p_result)[8].get_int();
	p_data->n_pk = (*p_result)[9].get_int();
	p_data->dw_guild = (*p_result)[10].get_dword();
	p_data->dw_map = (*p_result)[11].get_dword();

	p_data->n16_bag_size = (INT16)(*p_result)[12].get_int();					// 背包大小
	p_data->n_bag_gold = (*p_result)[13].get_int();					// 背包中金子数
	p_data->n_bag_silver = (*p_result)[14].get_int();					// 背包中银子数
	p_data->n_bag_copper = (*p_result)[15].get_int();					// 背包中铜数
	p_data->n_bag_bind_gold = (*p_result)[16].get_int();				// 背包中绑定金子数
	p_data->n_bag_bind_silver = (*p_result)[17].get_int();				// 背包中绑定银子数
	p_data->n_bag_bind_copper = (*p_result)[18].get_int();				// 背包中绑定铜数
	p_data->n_bag_tuanbao = (*p_result)[19].get_int();					// 背包中元宝数

	p_data->n16_ware_size = (INT16)(*p_result)[20].get_int();				// 账号仓库大小
	p_data->n_ware_gold = (*p_result)[21].get_int();					// 账号仓库中金子数
	p_data->n_ware_silver = (*p_result)[22].get_int();				// 账号仓库中银子数
	p_data->n_ware_copper = (*p_result)[23].get_int();				// 账号仓库中铜数
	p_data->f_coordinate[0] = (*p_result)[24].get_int();			// 位置（x,y,z）
	p_data->f_coordinate[1] =  (*p_result)[25].get_int();			// 位置（x,y,z）
	p_data->f_coordinate[2] =  (*p_result)[26].get_int();			// 位置（x,y,z）
	
	p_data->dw_account_id = (*p_result)[27].get_dword();
	p_data->n_exploits = (*p_result)[28].get_int();
	p_data->e_sex = (*p_result)[29].get_byte();
	p_data->n_shengw = (*p_result)[30].get_int();
}

//! 角色物品
VOID LogDB::get_role_item(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_get_role_item),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_role_item), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_get_role_item(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->clear();
	p_stream->write_string("select ");

	p_stream->write_string(
		"serial,"	"num,"				"type_id,"		"bind,"				"lock_state,"
		"use_times,"		"first_gain_time,"	"creator_id,"	"create_time,"		"owner_id,"
		"account_id,"	"container_type_id,"	"suffix,"		"quality,"			"potval_used,"
		"min_use_level,"	"max_use_level,"		"min_dmg_in,"		"min_dmg,"			"max_dmg,"		
		"armor,"		"potval,"			"role_att_effect," "posy_times," "posy_effect,"
		"engrave_times,"	"engrave_att,"		"hole_num,"		"hole_gem_id,"		"brand_level,"
		"derate_val,"	"x_ful_level,"		"hole_gem_ness,"		"can_cut,"			"xer_in_id,"
		"xer_out_id,"	"0,"				"0,"			"special_att,"			"appearance,"
		"rein,"			"savvy,"			"fortune,"		"color_id,"			"quality_mod_pct,"
		"quality_mod_pct_ex,"	"create_mode,"		"create_id,"		"att_a_lim_mod," "att_a_lim_mod_pct,"
		"flare_val,"		"name_id,"			"pot_val_mod_pct,"	"consolidate_level," "exp," "level," 
		"max_dmg_in,"		"armor_in,"			"equip_add_att,"	"talent_point,"		"max_talent_point,"
		"skill_list,"	"bind_time,"			"rating,"			"script_data1,"		"script_data2, " 
		"create_bind,"	"consolidate_level_star," "add_talent_point," "equip_rel_att");

	p_stream->write_string(" from item left join equip using(serial)");
	p_stream->where_item();
	p_stream->write_string("(owner_id=") << dw_role;
	p_stream->write_string(" and (container_type_id >=") << EICT_Bag;
	p_stream->write_string(" or container_type_id <=") << EICT_Equip;
	p_stream->write_string("))");
}
VOID LogDB::func_proc_res_role_item(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
#pragma warning(disable:4800)
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	VOID* p_buffer = out_buffer;

	nNumber = p_result->get_row_count();
	for(int i=0; i< nNumber; ++i)
	{
		tagItem * pItem = ( tagItem * ) p_buffer ;  

		pItem->n64_serial 					= (*p_result)[0].get_long();
		pItem->n16Num 						= (*p_result)[1].get_short();
		pItem->dw_data_id 					= (*p_result)[2].get_dword();
		pItem->byBind 						= (*p_result)[3].get_int();
		pItem->bCreateBind					= (*p_result)[66].get_bool();
		pItem->bLock 						= (*p_result)[4].get_bool();

		pItem->nUseTimes 					= (*p_result)[5].get_int();
		pItem->dwCreatorID 					= (*p_result)[7].get_dword();
		pItem->dwOwnerID 					= (*p_result)[9].get_dword();
		pItem->dw_account_id 					= (*p_result)[10].get_dword();

		pItem->eConType 					= (EItemConType)(*p_result)[11].get_int();
		pItem->n16Index 					= (*p_result)[12].get_short();
		pItem->eCreateMode					= (EItemCreateMode)(*p_result)[46].get_int();
		pItem->dwCreateID					= (*p_result)[47].get_dword();

		pItem->dwNameID						=(*p_result)[51].get_dword();

		DataTime2DwordTime(pItem->dw1stGainTime, (*p_result)[6].get_string(), (*p_result)[6].get_length());
		DataTime2DwordTime(pItem->dwCreateTime, (*p_result)[8].get_string(), (*p_result)[8].get_length());
		DataTime2DwordTime(pItem->dwBindTime, (*p_result)[62].get_string(), (*p_result)[62].get_length());

		pItem->dw_script_data[0] = (*p_result)[64].get_dword();
		pItem->dw_script_data[1] = (*p_result)[65].get_dword();

		if(!MIsEquipment(pItem->dw_data_id))
		{
			p_buffer = &pItem[1];
			p_result->next_row();
			continue;
		}

		tagEquip * p_equip = ( tagEquip * ) p_buffer ;  

		// 装备附加属性
		p_equip->equipSpec.byQuality 		= (*p_result)[13].get_byte();
		//p_equip->equipSpec.nPotValUsed 		= (*p_result)[14].get_int();
		//p_equip->equipSpec.byMinUseLevel 	= (*p_result)[15].get_byte();
		//p_equip->equipSpec.byMaxUseLevel 	= (*p_result)[16].get_byte();
		//p_equip->equipSpec.n16MinDmg 		= (*p_result)[18].get_short();
		//p_equip->equipSpec.n16MaxDmg 		= (*p_result)[19].get_short();
		//p_equip->equipSpec.n16Armor 		= (*p_result)[20].get_short();
		//p_equip->equipSpec.nPotVal 			= (*p_result)[21].get_int();
		//p_equip->equipSpec.byPosyTimes 		= (*p_result)[23].get_byte();
		//p_equip->equipSpec.byEngraveTimes 	= (*p_result)[25].get_byte();
		p_equip->equipSpec.byHoleNum 		= (*p_result)[27].get_byte();
		//p_equip->equipSpec.byTriggerCount 	= (*p_result)[29].get_byte();
		//p_equip->equipSpec.byLongfuLevel	= (*p_result)[31].get_byte();
		//p_equip->equipSpec.bCanCut 			= (*p_result)[33].get_bool();
		p_equip->equipSpec.byLuck		= (*p_result)[38].get_int();

		// 时装附加属性
		//p_equip->equipSpec.n16Appearance				= (*p_result)[39].get_int();
		//p_equip->equipSpec.byRein					= (*p_result)[40].get_byte();
		//p_equip->equipSpec.bySavvy					= (*p_result)[41].get_byte();
		//p_equip->equipSpec.byFortune					= (*p_result)[42].get_byte();
		//p_equip->equipSpec.n8ColorID					= (INT8)(*p_result)[43].get_int();

		/*p_equip->equipSpec.n16QltyModPct				= (*p_result)[44].get_short();
		p_equip->equipSpec.n16QltyModPctEx			= (*p_result)[45].get_short();
		p_equip->equipSpec.n16PotValModPct			= (*p_result)[52].get_short();
		p_equip->equipSpec.n16AttALimMod				= (*p_result)[48].get_int();
		p_equip->equipSpec.n16AttALimModPct			= (*p_result)[49].get_int();
		p_equip->equipSpec.byFlareVal				= (*p_result)[50].get_byte();*/
		p_equip->equipSpec.byConsolidateLevel		= (*p_result)[53].get_byte();
		//p_equip->equipSpec.nCurLevelExp				= (*p_result)[54].get_int();
		//p_equip->equipSpec.nLevel					= (*p_result)[55].get_int();
		//p_equip->equipSpec.byTalentPoint				= (*p_result)[59].get_int();
		//p_equip->equipSpec.byMaxTalentPoint			= (*p_result)[60].get_int();
		p_equip->equipSpec.nRating					= (*p_result)[63].get_int();

		//(*p_result)[22].get_blob(p_equip->equipSpec.nRoleAttEffect, min((*p_result)[22].get_length(), sizeof(p_equip->equipSpec.nRoleAttEffect)));
		//(*p_result)[24].get_blob(p_equip->equipSpec.PosyEffect, min((*p_result)[24].get_length(), sizeof(p_equip->equipSpec.PosyEffect)));
		//(*p_result)[26].get_blob(p_equip->equipSpec.nEngraveAtt, min((*p_result)[26].get_length(), sizeof(p_equip->equipSpec.nEngraveAtt)));
		(*p_result)[28].get_blob(p_equip->equipSpec.dwHoleGemID, min((*p_result)[28].get_length(), sizeof(p_equip->equipSpec.dwHoleGemID)));
		//(*p_result)[30].get_blob(p_equip->equipSpec.nBrandAtt, min((*p_result)[30].get_length(), sizeof(p_equip->equipSpec.nBrandAtt)));
		//(*p_result)[32].get_blob(p_equip->equipSpec.byHoleGemNess, min((*p_result)[32].get_length(), sizeof(p_equip->equipSpec.byHoleGemNess)));
		(*p_result)[58].get_blob(p_equip->equipSpec.EquipAttitionalAtt, min((*p_result)[58].get_length(), sizeof(p_equip->equipSpec.EquipAttitionalAtt)));
		//(*p_result)[61].get_blob(p_equip->equipSpec.dwSkillList, min((*p_result)[61].get_length(), sizeof(p_equip->equipSpec.dwSkillList)));

		//p_equip->equipSpec.byConsolidateLevelStar		= (*p_result)[67].get_byte();
		//p_equip->equipSpec.byAddTalentPoint			= (*p_result)[68].get_byte();
		(*p_result)[69].get_blob(p_equip->equipSpec.EquipAttitional, min((*p_result)[69].get_length(), sizeof(p_equip->equipSpec.EquipAttitional)));

		p_buffer = &p_equip[1];
		p_result->next_row();
	}

	dwSize += ((char*)p_buffer - (char*)out_buffer);
	out_buffer = p_buffer;
#pragma warning(pop)
}
//! 角色技能
VOID LogDB::get_role_skill(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_get_role_skill),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_role_skill), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_get_role_skill(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->clear();
	p_stream->select_item("skill", "id," "bidden_level," "self_level," "proficiency," "cooldown");
	p_stream->where_item();
	p_stream->write_string("role_id=") << dw_role;

}
VOID LogDB::func_proc_res_role_skill(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count();
	tag_role_skill* p_skill = (tag_role_skill*)out_buffer;
	for(int n = 0; n < nNumber; ++n)
	{
		p_skill->n_id = (*p_result)[0].get_int();
		p_skill->bidden_level = (*p_result)[1].get_int();
		p_skill->self_level = (*p_result)[2].get_int();
		p_skill->proficiency = (*p_result)[3].get_int();
		p_skill->cooldowm = (*p_result)[4].get_int();
		p_skill = &p_skill[1];
		p_result->next_row();
	}
	dwSize += sizeof(tag_role_skill) * nNumber;
	out_buffer = p_skill;
}
//! 角色宠物
VOID LogDB::get_role_pet(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_get_role_pet),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_role_pet), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_get_role_pet(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->clear();
	p_stream->select_item("pet_data", 
					"pet_id," "type_id," "quality," "grade,"  "step,"
					"cur_spirit," "happy_value,""pet_name," "pet_state,"
					"strength, agility, innerforce, attpoint");
	p_stream->where_item();
	p_stream->write_string("master_id=") << dw_role;
}
VOID LogDB::func_proc_res_role_pet(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count();
	tag_role_pet* p_pet = (tag_role_pet*)out_buffer;
	for(int n = 0; n < nNumber; ++n)
	{
		p_pet->Init( );
		p_pet->dw_id		= (*p_result)[0].get_dword();
		p_pet->dw_type_id	= (*p_result)[1].get_dword();
		p_pet->quality		= (*p_result)[2].get_int();
		p_pet->grade		= (*p_result)[3].get_int();
		p_pet->step			= (*p_result)[4].get_int();
		p_pet->dw_cur_spirit= (*p_result)[5].get_dword();
		p_pet->dw_happy_val = (*p_result)[6].get_dword();
		(*p_result)[7].get_tchar(p_pet->sz_pet_name, X_SHORT_NAME);
		p_pet->state		= (*p_result)[8].get_byte();
		p_pet->n_strength	= (*p_result)[9].get_int();
		p_pet->n_agility	= (*p_result)[10].get_int();
		p_pet->n_innerForce	= (*p_result)[11].get_int();
		p_pet->n_att_point	= (*p_result)[12].get_int();
		p_pet = &p_pet[1];
		p_result->next_row( ); 
	}
	dwSize += sizeof(tag_role_pet) * nNumber;
	out_buffer = p_pet;
}
//! 宠物技能
VOID LogDB::get_role_pet_skill(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_get_role_pet_skill),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_role_pet_skill), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_get_role_pet_skill(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->clear();
	p_stream->select_item("pet_skill", "pet_skill_type_id");
	p_stream->where_item();
	p_stream->write_string("pet_id=") << dw_role;
}
VOID LogDB::func_proc_res_role_pet_skill(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count();
	tag_role_pet* p_pet = (tag_role_pet*)out_buffer;
	for(int n = 0;  n < nNumber && n < _countof(p_pet->dw_skill_id); ++n)
	{
		p_pet->dw_skill_id[n] = (*p_result)[0].get_int();
		p_result->next_row( );
	}
}

//! common function
VOID LogDB::common_query_function(const char* _table_name, func_select_set_item func_set, 
									   func_proc_res func_proc, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(m_p_db_interface))return;
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();
	if(!VALID_POINT(pStream)) return;

	pStream->clear();
	func_set(_table_name, pStream, dw_account, dw_role);
	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);
	if(!VALID_POINT(p_result)) return;

	func_proc(p_result, out, dwSize, nNumber);
	m_p_db_interface->free_result_query(p_result);
	m_p_db_interface->return_io(pStream);
}
//! common function with special db_interface
VOID LogDB::common_query_function(db_interface* p_interface, const char* _table_name, func_select_set_item func_set, func_proc_res func_proc, 
								 VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_interface)) return;

	odbc::sql_language_disposal* pStream = p_interface->get_io();
	if(!VALID_POINT(pStream)) return;

	pStream->clear();
	func_set(_table_name, pStream, dw_account, dw_role);
	odbc::execute_result* p_result = p_interface->sql_query(pStream);
	if(!VALID_POINT(p_result)) return;

	func_proc(p_result, out, dwSize, nNumber);
	p_interface->free_result_query(p_result);
	p_interface->return_io(pStream);
}

//! common update function
DWORD LogDB::common_update_function(const char *table_name, func_update_set_item func_set, void *in, 
								   DWORD dw_account, DWORD dw_role, int nCount, int nSzOne)
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();
	if(!VALID_POINT(pStream)) return E_SystemError;
	
	BOOL bRet = TRUE;
	for(int n = 0; n < nCount; ++n)
	{
		pStream->clear();
		func_set(table_name, pStream, in, dw_account, dw_role);
		if(!pStream->is_empty())
		{
			bRet = m_p_db_interface->sql_execute(pStream);
			ErrLog(_T("\n%s\n"),get_tool()->ansi_to_unicode(pStream->get_buffer()));
		}
		in = (VOID*)((char*)in + nSzOne);
	}
	m_p_db_interface->return_io(pStream);

	return bRet ? E_Success : E_SystemError;
}
DWORD LogDB::common_update_function(db_interface* p_interface, const char* table_name, func_update_set_item func_set, void* in, 
								   DWORD dw_account, DWORD dw_role, int nCount, int nSzOne)
{
	if(!VALID_POINT(p_interface)) return E_SystemError;
	odbc::sql_language_disposal* pStream = p_interface->get_io();
	if(!VALID_POINT(pStream)) return E_SystemError;

	BOOL bRet = TRUE;
	for(int n = 0; n < nCount; ++n)
	{
		pStream->clear();
		func_set(table_name, pStream, in, dw_account, dw_role);
		if(!pStream->is_empty())
		{
			bRet = p_interface->sql_execute(pStream);
			if(!bRet) ErrLog(_T("%s"),get_tool()->ansi_to_unicode(pStream->get_buffer()));
		}
		in = (VOID*)((char*)in + nSzOne);
	}
	p_interface->return_io(pStream);

	return bRet ? E_Success : E_SystemError;
}
//! get item log
VOID LogDB::get_item_log(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_item_log),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_item_log), out, dw_account, dw_role, dwSize, nNumber);
}

VOID LogDB::func_set_item_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item(table_name, 
		"cmd_id," "type_id," "optnum," "serial1," 
		"container_type1," "result_num1," "serial2," "container_type2," 
		"result_num2," "role_id_relation,"  "time," "role_id");
	p_stream->where_item();
	p_stream->write_string("role_id=") << dw_role;
}

VOID LogDB::func_proc_res_item_log(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count();
	tag_item_log* p = (tag_item_log*)out_buffer;
	for(int n = 0; n < nNumber; ++n, ++p)
	{
		p->cmd_id = (*p_result)[0].get_dword();
		p->type_id = (*p_result)[1].get_dword();
		p->optnum = (*p_result)[2].get_int();
		p->serial = (*p_result)[3].get_long();
		p->container_type = (*p_result)[4].get_int();
		p->result_num = (*p_result)[5].get_int();
		p->serial2 = (*p_result)[6].get_long();
		p->container_type2 = (*p_result)[7].get_int();
		p->result_num2 = (*p_result)[8].get_int();
		p->dw_role_relation = (*p_result)[9].get_dword();
		DataTime2DwordTime((tagDWORDTime&)p->dwTime,	(*p_result)[10].get_string(), (*p_result)[10].get_length());
		p->dw_role_id = (*p_result)[11].get_dword();
		p_result->next_row();
	}
	dwSize += sizeof(tag_item_log) * p_result->get_row_count();
}

//! bank log
VOID LogDB::get_bank_log(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_bank_log),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_bank_log), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_set_bank_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item(table_name, 
		"sell_id," "buy_id," "bidup_id," "type," "bidup," "chaw," "sell," "time" );
	p_stream->where_item();
	p_stream->write_string("sell_id=") << dw_role;
	p_stream->write_string(" or buy_id=") << dw_role;
	p_stream->write_string(" or bidup_id=") << dw_role;
}
VOID LogDB::func_proc_res_bank_log(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count();
	tag_bank_log* p = (tag_bank_log*)out_buffer;
	for(int n = 0; n < nNumber; ++n, ++p)
	{
		p->seller_id = (*p_result)[0].get_dword();
		p->buyer_id = (*p_result)[1].get_dword();
		p->bidup_id = (*p_result)[2].get_int();
		p->type = (*p_result)[3].get_long();
		p->bidup = (*p_result)[4].get_int();
		p->chaw = (*p_result)[5].get_int();
		p->number = (*p_result)[6].get_long();
		DataTime2DwordTime((tagDWORDTime&)p->time,	(*p_result)[7].get_string(), (*p_result)[7].get_length());
		p_result->next_row();
	}
	dwSize += sizeof(tag_bank_log) * p_result->get_row_count();
}
//! paimai log
VOID LogDB::get_paimai_log(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_paimai_log),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_paimai_log), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_set_paimai_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item(table_name, 
		"serial," "sell_id," "buy_id," "bidup_id," "bidup," "chaw," "time" );
	p_stream->where_item();
	p_stream->write_string("sell_id=") << dw_role;
	p_stream->write_string(" or buy_id=") << dw_role;
	p_stream->write_string(" or bidup_id=") << dw_role;
}
VOID LogDB::func_proc_res_paimai_log(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count();
	tag_paimai_log* p = (tag_paimai_log*)out_buffer;
	for(int n = 0; n < nNumber; ++n, ++p)
	{
		p->serial = (*p_result)[0].get_long();
		p->seller_id = (*p_result)[1].get_dword();
		p->buyer_id = (*p_result)[2].get_dword();
		p->bidup_id = (*p_result)[3].get_int();
		p->bidup = (*p_result)[4].get_int();
		p->chaw = (*p_result)[5].get_int();
		DataTime2DwordTime((tagDWORDTime&)p->time,	(*p_result)[6].get_string(), (*p_result)[6].get_length());
		p_result->next_row();
	}
	dwSize += sizeof(tag_paimai_log) * p_result->get_row_count();
}
//! 
VOID LogDB::get_item_log_by_serial(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_item_log_serial),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_item_log), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_set_item_log_serial(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	INT64 n64Serial = ((INT64)dw_account)  << 32 | dw_role;
	p_stream->select_item(table_name, 
		"cmd_id," "type_id," "optnum," "serial1," 
		"container_type1," "result_num1," "serial2," "container_type2," 
		"result_num2," "role_id_relation,"  "time," "role_id");
	p_stream->where_item();
	p_stream->write_string("serial1=") << n64Serial;
	p_stream->write_string(" or serial2=") << n64Serial;
}
//! get money log
VOID LogDB::get_money_log(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_money_log),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_money_log), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_set_money_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item(table_name,
		 "cmd_id," "container_type," "num," 
		 "total_num," "role_id_relation," "time");
	p_stream->where_item();
	p_stream->write_string("role_id =") << dw_role ;
}
VOID LogDB::func_proc_res_money_log(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count();
	tag_money_log* p = (tag_money_log*)out_buffer;
	for(int n = 0; n < nNumber; ++n, ++p)
	{
		p->cmd_id = (*p_result)[0].get_dword();
		p->container_type = (*p_result)[1].get_int();
		p->number = (*p_result)[2].get_int();
		p->total_number = (*p_result)[3].get_long();
		p->dw_role_relation = (*p_result)[4].get_dword();
		DataTime2DwordTime((tagDWORDTime&)p->dwTime,	(*p_result)[5].get_string(), (*p_result)[5].get_length());
		p_result->next_row();
	}
	dwSize += sizeof(tag_money_log) * p_result->get_row_count();
}
//! get exploits log
VOID LogDB::get_exploits_log(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_exploits_log),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_exploits_log), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_set_exploits_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item(table_name,
		"cmd_id,"  "num," "total_num," "role_id_relation," "time");
	p_stream->where_item();
	p_stream->write_string("role_id =") << dw_role ;
}
VOID LogDB::func_proc_res_exploits_log(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count();
	tag_exploits_log* p = (tag_exploits_log*)out_buffer;
	for(int n = 0; n < nNumber; ++n, ++p)
	{
		p->cmd_id = (*p_result)[0].get_dword();
		p->number = (*p_result)[2].get_int();
		p->total_number = (*p_result)[3].get_long();
		p->dw_role_relation = (*p_result)[4].get_dword();
		DataTime2DwordTime((tagDWORDTime&)p->dwTime,	(*p_result)[5].get_string(), (*p_result)[5].get_length());
		p_result->next_row();
	}
	dwSize += sizeof(tag_exploits_log) * p_result->get_row_count();
}
//! get yuanbao log
VOID LogDB::get_yuanbao_log(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_yuanbao_log),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_yuanbao_log), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_set_yuanbao_log(const char* table_name, odbc::sql_language_disposal* p_stream,  DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item(table_name,
		"cmd_id," "container_type," "num," 
		"total_num,"  "role_id_relation," "time");
	p_stream->where_item();
	p_stream->write_string("role_id =") << dw_role ;
}
VOID LogDB::func_proc_res_yuanbao_log(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count();
	tag_yuanbao_log* p = (tag_yuanbao_log*)out_buffer;
	for(int n = 0; n < nNumber; ++n, ++p)
	{
		p->cmd_id = (*p_result)[0].get_dword();
		p->container_type = (*p_result)[1].get_int();
		p->number = (*p_result)[2].get_int();
		p->total_number = (*p_result)[3].get_long();
		p->dw_role_relation = (*p_result)[4].get_dword();
		DataTime2DwordTime((tagDWORDTime&)p->dwTime,	(*p_result)[5].get_string(), (*p_result)[5].get_length());
		p_result->next_row();
	}
	dwSize += sizeof(tag_yuanbao_log) * p_result->get_row_count();
}
//! forbid talk role list
VOID LogDB::get_forbid_talk_list(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_forbid_talk_list),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_forbid_talk_list), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_set_forbid_talk_list(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item(table_name,
		"role_id," "account_id," "forbid_talk_start," "forbid_talk_end," "role_name");
	p_stream->where_item();
	p_stream->write_string("forbid_talk_start<forbid_talk_end");
}
VOID LogDB::func_proc_res_forbid_talk_list(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber =p_result->get_row_count();
	tag_forbid_talk_role* p = (tag_forbid_talk_role*)out_buffer;
	for(INT n = 0; n < nNumber; ++n, ++p)
	{
		p->dw_role_id = (*p_result)[0].get_dword();
		p->dw_account_id = (*p_result)[1].get_dword();
		p->dw_forbid_time_start = (*p_result)[2].get_dword();
		p->dw_forbid_time_end = (*p_result)[3].get_dword();
		(*p_result)[4].get_tchar(p->sz_role_name, X_SHORT_NAME);
		p_result->next_row();
	}
	dwSize += sizeof(tag_forbid_talk_role)* nNumber;
}
//! forbid account list
VOID LogDB::get_forbid_account_list(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_forbid_account_list),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_forbid_account_list), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_set_forbid_account_list(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item("account",
		"id," "forbid_mask," "name");
	p_stream->where_item();
	p_stream->write_string("forbid_mask>0");
}
VOID LogDB::func_proc_res_forbid_account_list(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count( );
	tag_forbid_account* p = (tag_forbid_account*)out_buffer;
	for(INT n = 0; n < nNumber; ++n, ++p)
	{
		p->dw_account_id = (*p_result)[0].get_dword();
		p->dw_forbid_mask = (*p_result)[1].get_dword();
		(*p_result)[2].get_tchar(p->sz_account_name, X_SHORT_NAME);
		p_result->next_row( );
	}
	dwSize += sizeof(tag_forbid_account) * nNumber;
}

//! gm工具日志
VOID LogDB::get_gm_log(db_interface* pGMDB, const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(pGMDB, table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_gm_log),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_set_gm_log(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item(table_name,
		"ip," "time," "gm_accountid," "gm_cmd");
	if(VALID_POINT(dw_account))
	{
		p_stream->where_item();
		p_stream->write_string("gm_accountid=") << dw_account;
	}
}
VOID LogDB::func_proc_res_(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count( );
	tag_gm_log* p = (tag_gm_log*)out_buffer;
	for(int n = 0; n < nNumber; ++n, ++p)
	{
		p->dw_ip = inet_addr((*p_result)[0].get_string());

		tagDWORDTime dwtime;
		DataTime2DwordTime(dwtime, (*p_result)[1].get_string(), (*p_result)[1].get_length());
		p->dw_time = (DWORD)dwtime;

		p->dw_account = (*p_result)[2].get_dword();
		(*p_result)[3].get_tchar(p->sz_gm_cmd, X_HUGE_NAME);

		p_result->next_row( );
	}
	dwSize += sizeof(tag_gm_log) * nNumber;
}
// 查询gm工具ID
DWORD LogDB::get_gm_tool_account_id(db_interface* pGMDB, TCHAR* sz_gm_account)
{
	if(!VALID_POINT(pGMDB)|| !VALID_POINT(sz_gm_account))
		return 0;

	DWORD dw_account_id = INVALID_VALUE;
	odbc::sql_language_disposal* pStream = pGMDB->get_io();

	pStream->select_item("gmaccount", "id");
	pStream->where_item();
	pStream->write_string("name=").write_string(sz_gm_account);

	odbc::execute_result* p_result = pGMDB->sql_query(pStream);
	if(VALID_POINT(p_result) && p_result->get_row_count() > 0)
		dw_account_id = (*p_result)[0].get_dword();

	pGMDB->return_io(pStream);
	pGMDB->free_result_query(p_result);

	return dw_account_id;
}
//! 帮会
VOID LogDB::get_guild_basic_list(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_guild_basic_list),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_guild_basic_list), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_set_guild_basic_list(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item("guild", "id," "level," "name" );
}
VOID LogDB::func_proc_res_guild_basic_list(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count( );
	tag_guild_basic* p = (tag_guild_basic*)out_buffer;
	for(INT n = 0; n < nNumber; ++n, ++p)
	{
		p->dw_guild_id = (*p_result)[0].get_dword();
		p->dw_guild_level = (*p_result)[1].get_dword();
		(*p_result)[2].get_blob(p->sz_guild_name, sizeof(p->sz_guild_name));
		p_result->next_row( );
	}

	dwSize += sizeof(tag_guild_basic) * nNumber;
}
//!
VOID LogDB::get_guild_data(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_guild_data),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_guild_data), out, dw_account, dw_role, dwSize, nNumber);
}

VOID LogDB::func_set_guild_data(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item(table_name, "id," "creater_name_id," "create_time," "leader_id," "fund," "pos_name," "script_data" );
	p_stream->where_item();
	p_stream->write_string("id=") << dw_account;
}

VOID LogDB::func_proc_res_guild_data(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;
	
	nNumber = p_result->get_row_count( );
	tag_guild_data* p = (tag_guild_data*)out_buffer;
	for(INT n = 0; n < nNumber; ++n, ++p)
	{
		p->dw_guild_id = (*p_result)[0].get_dword();
		p->dw_creator_id = (*p_result)[1].get_dword();

		tagDWORDTime dwtime;
		DataTime2DwordTime(dwtime, (*p_result)[2].get_string(),  (*p_result)[2].get_length());
		p->dw_create_time = (DWORD)dwtime;
		
		p->dw_master_id = (*p_result)[3].get_dword();
		p->dw_prosperity = (*p_result)[4].get_dword();

		(*p_result)[5].get_blob(p->sz_pos_name, sizeof(p->sz_pos_name));
		(*p_result)[6].get_blob(p->n32_script_data, sizeof(p->n32_script_data));

		p_result->next_row( );
	}
}
//!
VOID LogDB::get_guild_build(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_guild_build),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_guild_build), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_set_guild_build(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->select_item(table_name,
		"type," "level," "max_level," "holiness_step," "use_time," "use_num");
	p_stream->where_item();
	p_stream->write_string("guild_id=") << dw_account;
}
VOID LogDB::func_proc_res_guild_build(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count( );
	tag_guild_build* p = (tag_guild_build*)out_buffer;	
	for(INT n = 0; n < nNumber; ++n, ++p)
	{
		p->dw_type = (*p_result)[0].get_dword();
		p->dw_level = (*p_result)[1].get_dword();
		p->dw_max_level = (*p_result)[2].get_dword();
		p->dw_holiness_step = (*p_result)[3].get_dword();
		
		tagDWORDTime dwtime;
		DataTime2DwordTime(dwtime, (*p_result)[4].get_string(), (*p_result)[4].get_length());
		p->dw_use_time = (DWORD)dwtime;

		p->dw_use_num = (*p_result)[5].get_dword( );

		p_result->next_row( );
	}
}

//!
VOID LogDB::get_guild_member(const char* table_name, VOID*& out, DWORD dw_account, DWORD dw_role, DWORD& dwSize, INT& nNumber)
{
	this->common_query_function(table_name,
		fastdelegate::MakeDelegate(this, &LogDB::func_set_guild_member),
		fastdelegate::MakeDelegate(this, &LogDB::func_proc_res_guild_member), out, dw_account, dw_role, dwSize, nNumber);
}
VOID LogDB::func_set_guild_member(const char* table_name, odbc::sql_language_disposal* p_stream, DWORD dw_account, DWORD dw_role)
{
	p_stream->write_string("select ");
	p_stream->write_string("role_id," "level," "class," "guild_pos," "cur_contribution," "login_time," "role_name");
	p_stream->write_string(" from guild_member left join role_data using(role_id)");
	p_stream->where_item();
	p_stream->write_string("guild_member.guild_id=") << dw_account;
}
VOID LogDB::func_proc_res_guild_member(odbc::execute_result* p_result, VOID*& out_buffer, DWORD& dwSize, INT& nNumber)
{
	if(!VALID_POINT(p_result) || !p_result->get_row_count())
		return;

	nNumber = p_result->get_row_count( );
	tag_guild_member* p = (tag_guild_member*)out_buffer;	
	for(INT n = 0; n < nNumber; ++n, ++p)
	{
		p->dw_role_id = (*p_result)[0].get_dword();
		p->dw_role_level = (*p_result)[1].get_dword();
		p->by_class = (*p_result)[2].get_byte();
		p->by_position = (*p_result)[3].get_byte();
		p->dw_contribution = (*p_result)[4].get_dword();

		tagDWORDTime dwtime;
		DataTime2DwordTime(dwtime, (*p_result)[5].get_string(), (*p_result)[5].get_length());
		p->dw_last_login = (DWORD)dwtime;

		(*p_result)[6].get_tchar(p->sz_role_name, X_SHORT_NAME);

		p_result->next_row( );
	}
	dwSize += sizeof(tag_guild_member) * nNumber;
}

BOOL LogDB::verify_gdquest_data(DWORD dw_role_id)
{
	DWORD dw_number = 0;
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();

	pStream->clear( );
	pStream->write_string("update quest set quest_flag = 0 where (quest_flag  & 1073741824) > 0 and (quest_flag  & 268435456)  = 0");
	pStream->write_string(" and role_id =")<< dw_role_id;
	pStream->write_string(" and quest_id not in (select  quest_id from guerdon_quest  where sender =") << dw_role_id;
	pStream->write_string(")");
	BOOL b = m_p_db_interface->sql_execute(pStream);

	m_p_db_interface->return_io(pStream);

	return b;
}
//! 获取超过规定IP数的IP信息
VOID LogDB::func_get_invalid_ip_section(std::vector<tag_Invalid_IP>& ip_vec,INT ip_num,TCHAR* sz_trust_ip)
{
	//SELECT account.ip FROM account GROUP BY account.ip HAVING(COUNT(*))>5
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();
	tag_mysql_connect* p_con = m_p_db_interface->get_idlesse_connect();

	pStream->select_item("account", "count(ip),ip");
	pStream->where_item();
	pStream->write_string(" forbid_mask = 0 AND login_status=1");
	if (sz_trust_ip)
	{
		pStream->write_string(" AND ip != '").write_string(sz_trust_ip, p_con).write_string("'");
	}
	pStream->write_string(" GROUP BY ip HAVING(COUNT(*)) > ")<<ip_num;

	m_p_db_interface->return_use_connect(p_con);

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result))
	{
		INT nNum = p_result->get_row_count() ;
		while(nNum)
		{
			tag_Invalid_IP tmpIPData;
			tmpIPData.n_ip_num = (*p_result)[0].get_int();
			(*p_result)[1].get_tchar(tmpIPData.sz_ip_name, X_LONG_NAME);
			ip_vec.push_back(tmpIPData);

			nNum--;
			p_result->next_row();
		}
	}

	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);
	return;
}

VOID LogDB::func_get_account_name_by_ip( GMForbidAccMgr::ACCOUNT_STU_VEC& _vec,TCHAR* ipname,TCHAR* servername,DWORD dwclient_id )
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();
	tag_mysql_connect* p_con = m_p_db_interface->get_idlesse_connect();
	pStream->select_item("account", "id,name");
	pStream->where_item();
	pStream->write_string(" ip='").write_string(ipname, p_con).write_string("'");

	m_p_db_interface->return_use_connect(p_con);

	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result))
	{
		INT nNum = p_result->get_row_count() ;
		while (nNum)
		{
			tag_forbid_account_studio tmp_tag;
			tmp_tag.dw_account_id = (*p_result)[0].get_dword();
			(*p_result)[1].get_tchar(tmp_tag.sz_account, X_LONG_NAME);
			tmp_tag.dw_client_id = dwclient_id;
			memcpy(tmp_tag.sz_world,servername,sizeof(TCHAR)*X_SHORT_NAME);
			_vec.push_back(tmp_tag);

			nNum--;
			p_result->next_row();
		}
	}

	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);
	return;
}

VOID LogDB::fun_get_rolename_by_accountname( GMForbidAccMgr::KICK_STU_VEC& _vec,DWORD dwaccount_id,TCHAR* servername )
{
	odbc::sql_language_disposal* pStream = m_p_db_interface->get_io();
	
	pStream->select_item("role_data", "role_name");
	pStream->where_item();
	pStream->write_string(" account_id=") << dwaccount_id;


	odbc::execute_result* p_result = m_p_db_interface->sql_query(pStream);

	if(VALID_POINT(p_result))
	{
		INT nNum = p_result->get_row_count() ;
		while (nNum)
		{
			tag_kick_role_studio tmp_tag;
			(*p_result)[0].get_tchar(tmp_tag.szRoleName, X_SHORT_NAME);
			memcpy(tmp_tag.szServerName,servername,sizeof(TCHAR)*X_SHORT_NAME);
			_vec.push_back(tmp_tag);

			nNum--;
			p_result->next_row();
		}
	}

	m_p_db_interface->return_io(pStream);
	m_p_db_interface->free_result_query(p_result);
	return;
}
