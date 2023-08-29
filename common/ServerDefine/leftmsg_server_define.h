#pragma once

#pragma pack(push)
#pragma pack(1)


//! ¡Ù—‘
struct s_database_left_msg
{
	DWORD	dw_date_time;
	DWORD	dw_role_id;
	BYTE	by_data[1];
};

const INT MAX_LEFTMSG_NUM = 50;


//! ±£¥Ê¡Ù—‘
struct NET_DB2C_insert_left_message : public tag_net_message 
{   
	NET_DB2C_insert_left_message ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2C_insert_left_message" ) ;  
		dw_size = sizeof ( * this ) ; 
	} 
	s_database_left_msg data;   
};  

struct NET_DB2S_insert_left_message : public tag_net_message
{ 
	NET_DB2S_insert_left_message ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_insert_left_message" ) ;  
		dw_size = sizeof ( * this ) ;   
	} 
};  


//! ∏¸–¬¡Ù—‘
// CMD_START(NDBC_UpdateLeftMsg)
// 	DWORD dwOldDateTime;
// 	s_database_left_msg data;
// CMD_END;
// 
// CMD_START(NDBS_UpdateLeftMsg)
// CMD_END;


//! ∂¡»°¡Ù—‘
struct NET_DB2C_load_left_message : public tag_net_message 
{  
	NET_DB2C_load_left_message ( )
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;   
		dw_message_id = message_id_crc ( "NET_DB2C_load_left_message" ) ;  
		dw_size = sizeof ( * this ) ;   
	} 
	DWORD dw_role_id;  
};  

struct NET_DB2S_load_left_message : public tag_net_message 
{  
	NET_DB2S_load_left_message ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;  
		dw_message_id = message_id_crc ( "NET_DB2S_load_left_message" ) ;
		dw_size = sizeof ( * this ) ;   
	}   
	DWORD dw_error_code;  
	DWORD dw_role_id; 
	BYTE by_data[1];   
};  

//! «Âø’¡Ù—‘
struct NET_DB2C_clear_left_message : public tag_net_message
{  
	NET_DB2C_clear_left_message ( ) 
	{  
		ZeroMemory ( this , sizeof ( * this ) ) ;
		dw_message_id = message_id_crc ( "NET_DB2C_clear_left_message" ) ; 
		dw_size = sizeof ( * this ) ;    
	}  
	DWORD dw_role_id;   
};  

struct NET_DB2S_clear_left_message : public tag_net_message
{  
	NET_DB2S_clear_left_message ( ) 
	{   
		ZeroMemory ( this , sizeof ( * this ) ) ; 
		dw_message_id = message_id_crc ( "NET_DB2S_clear_left_message" ) ; 
		dw_size = sizeof ( * this ) ;  
	}  
	DWORD dw_error_code;   
};  


#pragma pack(pop)
