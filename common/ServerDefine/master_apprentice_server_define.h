/*******************************************************************************

	Copyright 2010 by tiankong Interactive Game Co., Ltd.
	All rights reserved.
	
	This software is the confidential and proprietary information of
	tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
	not disclose such Confidential Information and shall use it only in
	accordance with the terms of the license agreement you entered into with
	tiankong Interactive  Co., Ltd.

*******************************************************************************/

#ifndef __MASTER_PRENTICE_SERVER_DEFINE_H__
#define __MASTER_PRENTICE_SERVER_DEFINE_H__

//读取数据库所有师徒榜数据临时buffer大小(2M,假设每人可收徒28)
#define MASTERPRENTICELOADMAXBUFF (128*8*2048)
//向玩家发送师门所有数据临时buffer大小(0.5k)
#define MASTERPRENTICEONEBUFF (512)
//发送师徒榜数据时一个封包使用临时buffer大小(2K)
#define MASTERPRENTICEPLACARDBUFF (16*128)
//一个封包发送N笔师徒榜数据
#define MASTERPRENTICEONTIMECOUNT (128)
// 最大收徒数
#define PRENTICE_MAX_COUNT  5
// 读取师徒榜buffer大小
#define MASTERRECRUITBUFFER (4*1024*1024)

#pragma pack(push,1)


//! 存储师徒数据
struct s_master_prentice_save
{
	DWORD	dw_master;
	DWORD	dw_graduates;
	DWORD	dw_master_moral;
	BYTE	b_show_in_panel;
	BYTE	by_number;
	DWORD	dw_prentices[PRENTICE_MAX_COUNT];
};
#define MasterPrenticeSaveRealSize(PrenticeNumber) (sizeof(s_master_prentice_save))

//! 加载师徒数据
struct s_master_prentice_load
{
	DWORD	dw_master;					// 师傅id
	DWORD	dw_graduates;				// 出师人数
	DWORD	dw_master_moral;			// 师德值
	BYTE	b_show_in_panel;			// 是否在师徒榜中显示
	BYTE	by_number;					// 徒弟个数
	DWORD	dw_prentices[1];			// 徒弟id
};
#define MasterPrenticeLoadRealSize(PrenticeNumber)\
	(sizeof(s_master_prentice_load)+sizeof(DWORD)*((PrenticeNumber)-1))

//! 招徒榜数据(服务器存储；数据库数据在内存的映射)
struct s_master_placard
{
	DWORD	dw_master;
	DWORD	dw_graduates;
	DWORD	dw_master_moral;
	BYTE	b_show_in_panel;
	BYTE	by_number;
	BYTE	by_master_repution;
	DWORD	dw_prenices[PRENTICE_MAX_COUNT];

	BOOL has_prentice( DWORD dw_role_id )
	{
		for( INT n = 0; n < by_number; ++n)
			if( dw_role_id == dw_prenices[n]) return TRUE;
		
		return FALSE;
	}

	VOID remove_prentice(DWORD dw_role_id )
	{
		INT n = -1;
		for( UINT i = 0; i < by_number; ++i)
		{
			if(dw_role_id == dw_prenices[i])
			{
				n = i; break;
			}
		}

		if( n != -1)
		{
			for( INT i = n+1; i < by_number; ++i)
			{
				if( dw_prenices[i] )
				{
					dw_prenices[n] = dw_prenices[i]; ++n;
				}
			}
			dw_prenices[n] = 0; --by_number;
		}
	}

	VOID add_prentice( DWORD dw_role_id )
	{
		if( by_number < PRENTICE_MAX_COUNT )
		{
			dw_prenices[ by_number ] = dw_role_id;
			++by_number;
		}
	}
	VOID inc_graduate( ){ ++dw_graduates; }
};
#define MasterPlacardRealSize(PrenticeNumber) (sizeof(s_master_placard))

//! 添加一个人到师徒表
struct NET_DB2C_insert_master : public tag_net_message 
{  
	NET_DB2C_insert_master ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_insert_master" ) ; 
		dw_size = sizeof ( * this ) ;     
	}   
	DWORD dw_master;  
};  

//! 存储
struct NET_DB2C_save_master_prentice : public tag_net_message 
{  
	NET_DB2C_save_master_prentice ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2C_save_master_prentice" ) ; 
		dw_size = sizeof ( * this ) ; 
	}  
	UINT32 u32_number;  
	s_master_prentice_save master_prentice[1];  
};  

//! 加载
struct NET_DB2C_load_all_master_prentice : public tag_net_message 
{   
	NET_DB2C_load_all_master_prentice ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_all_master_prentice" ) ;  
		dw_size = sizeof ( * this ) ; 
	}   
};  

//! 师徒数据库数据
struct NET_DB2S_load_all_master_prentice : public tag_net_message 
{ 
	NET_DB2S_load_all_master_prentice ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_load_all_master_prentice" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	UINT32 u32_number;  
	s_master_prentice_load master_prentice[1]; 
};  

//! 更新师傅ID和师徒关系操作禁止时间
struct NET_DB2C_update_master_id_and_forbid_time : public tag_net_message 
{ 
	NET_DB2C_update_master_id_and_forbid_time ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_update_master_id_and_forbid_time" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_role_id;
	DWORD dw_master;  
	DWORD dw_forbid_time;     
};  

//! 师傅删除角色
struct NET_DB2C_master_delete_role : public tag_net_message 
{   
	NET_DB2C_master_delete_role ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_master_delete_role" ) ;
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_role_id;     
};

//! 加载拜师榜
struct NET_DB2C_load_all_master_recruit : public tag_net_message 
{   
	NET_DB2C_load_all_master_recruit ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_all_master_recruit" ) ;  
		dw_size = sizeof ( * this ) ; 
	}   
}; 
struct NET_DB2S_load_all_master_recruit : public tag_net_message 
{ 
	NET_DB2S_load_all_master_recruit ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_load_all_master_recruit" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	UINT32 u32_number;  
	DWORD dwRoleID[1];
}; 

//! 登记拜师榜
struct NET_DB2C_join_master_recruit: public tag_net_message 
{   
	NET_DB2C_join_master_recruit ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_join_master_recruit" ) ;
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_role_id;     
};  

//! 取消登记拜师榜
struct NET_DB2C_leave_master_recruit: public tag_net_message 
{   
	NET_DB2C_leave_master_recruit ( )
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_leave_master_recruit" ) ;
		dw_size = sizeof ( * this ) ; 
	} 
	DWORD dw_role_id;     
};  

#pragma pack(pop)

#endif //__MASTER_PRENTICE_SERVER_DEFINE_H__