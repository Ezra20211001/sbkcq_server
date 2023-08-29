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

//��ȡ���ݿ�����ʦͽ��������ʱbuffer��С(2M,����ÿ�˿���ͽ28)
#define MASTERPRENTICELOADMAXBUFF (128*8*2048)
//����ҷ���ʦ������������ʱbuffer��С(0.5k)
#define MASTERPRENTICEONEBUFF (512)
//����ʦͽ������ʱһ�����ʹ����ʱbuffer��С(2K)
#define MASTERPRENTICEPLACARDBUFF (16*128)
//һ���������N��ʦͽ������
#define MASTERPRENTICEONTIMECOUNT (128)
// �����ͽ��
#define PRENTICE_MAX_COUNT  5
// ��ȡʦͽ��buffer��С
#define MASTERRECRUITBUFFER (4*1024*1024)

#pragma pack(push,1)


//! �洢ʦͽ����
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

//! ����ʦͽ����
struct s_master_prentice_load
{
	DWORD	dw_master;					// ʦ��id
	DWORD	dw_graduates;				// ��ʦ����
	DWORD	dw_master_moral;			// ʦ��ֵ
	BYTE	b_show_in_panel;			// �Ƿ���ʦͽ������ʾ
	BYTE	by_number;					// ͽ�ܸ���
	DWORD	dw_prentices[1];			// ͽ��id
};
#define MasterPrenticeLoadRealSize(PrenticeNumber)\
	(sizeof(s_master_prentice_load)+sizeof(DWORD)*((PrenticeNumber)-1))

//! ��ͽ������(�������洢�����ݿ��������ڴ��ӳ��)
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

//! ���һ���˵�ʦͽ��
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

//! �洢
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

//! ����
struct NET_DB2C_load_all_master_prentice : public tag_net_message 
{   
	NET_DB2C_load_all_master_prentice ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_load_all_master_prentice" ) ;  
		dw_size = sizeof ( * this ) ; 
	}   
};  

//! ʦͽ���ݿ�����
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

//! ����ʦ��ID��ʦͽ��ϵ������ֹʱ��
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

//! ʦ��ɾ����ɫ
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

//! ���ذ�ʦ��
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

//! �Ǽǰ�ʦ��
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

//! ȡ���Ǽǰ�ʦ��
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