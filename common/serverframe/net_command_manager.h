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
 *	@file		net_command_manager.h
 *	@author		lc
 *	@date		2011/02/16
 *	@version	
 *	@brief		
 */
#ifndef NET_COMMAND_MANAGER
#define NET_COMMAND_MANAGER

namespace serverframe {

typedef fastdelegate::FastDelegate2<tag_net_message*,DWORD,DWORD> NET_MESSAGE_PROC;

class net_command_manager : public serverframe::singleton<net_command_manager>
{
public:
    net_command_manager();
    ~net_command_manager();
public:
    BOOL register_message(LPCSTR sz_command_, NET_MESSAGE_PROC fn_, LPCTSTR sz_description_);
    BOOL unregister_message(LPCSTR sz_command_, NET_MESSAGE_PROC fn_);
    BOOL handle_message(tag_net_message* p_message_, DWORD dw_message_size_, DWORD dw_param_);
private:
    struct tag_command
    {
        std::string			str_command;		// 消息名称
        tstring				str_description;	// 消息描述
        package_list<NET_MESSAGE_PROC>	list_command_fn;		// 消息处理函数列表
        DWORD				dw_disposal_num;	// 消息处理次数
    };

    package_map<DWORD, tag_command*>	map_command;
 
};

}; // namespace serverframe

#define REGISTER_NET_MSG(msg_name,cls_name,mem_fun,desc)   serverframe::net_command_manager::get_singleton().register_message  ( msg_name, fastdelegate::MakeDelegate(this, (DWORD(cls_name::*)(tag_net_message*,DWORD))&cls_name::mem_fun), desc );
#define UNREGISTER_NET_MSG(msg_name,cls_name,mem_fun)      serverframe::net_command_manager::get_singleton().unregister_message( msg_name, fastdelegate::MakeDelegate(this, (DWORD(cls_name::*)(tag_net_message*,DWORD))&cls_name::mem_fun) );
#endif
