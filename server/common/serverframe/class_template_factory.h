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
*	@file		class_template_factory.h
*	@author		lc
*	@date		2011/02/16	initial
*	@version	0.0.1.0
*	@brief		
*/


#ifndef CLASS_TEMPLATE_FACTROY
#define CLASS_TEMPLATE_FACTROY

namespace serverframe {

class bind_base
{ 	
public:
	virtual LPVOID create_class()=0;	
	virtual VOID destroy_class(LPVOID)=0;	
};

template<typename entity_class>class class_bind : public bind_base
{
public:
	LPVOID create_class() { return (LPVOID)(new entity_class); }
	VOID destroy_class(LPVOID p) { delete((entity_class*)p); }
};


template<typename entity_class>class wrap{};



template<typename abstract_class>	
class class_template_factory
{
public:
	
	template<typename entity_class>
	BOOL register_class(wrap<entity_class>, DWORD dw_id_)
	{ 
		class_bind<entity_class>* p_bind_class = new class_bind<entity_class>;
		if( NULL == p_bind_class )
			return FALSE;

		ASSERT( map_bind_class.find(dw_id_) == map_bind_class.end() );	
		map_bind_class.insert(std::pair<DWORD, bind_base*>(dw_id_, p_bind_class));
		return TRUE;
	}

	template<typename entity_class>
	BOOL unregister_class(wrap<entity_class>, DWORD dw_id_)
	{
		std::map<DWORD, bind_base*>::iterator iter = map_bind_class.find(dw_id_);
		if( iter == map_bind_class.end() )
			return FALSE;

		delete((class_bind<entity_class>*)(iter->second));
		map_bind_class.erase(dw_id_);
		return TRUE;
	}

	abstract_class* create_class(DWORD dw_id_)
	{
		std::map<DWORD, bind_base*>::iterator iter = map_bind_class.find(dw_id_);
		if( iter == map_bind_class.end() )
			return NULL;

		return (abstract_class*)iter->second->create_class();
	}

	VOID destroy_class(LPVOID p, DWORD dw_id_)
	{
		std::map<DWORD, bind_base*>::iterator iter = map_bind_class.find(dw_id_);
		if( iter != map_bind_class.end() )
			iter->second->destroy_class(p);
	}

	~class_template_factory() 
	{	
		std::map<DWORD, bind_base*>::iterator iter;
		for( iter=map_bind_class.begin(); iter!=map_bind_class.end(); ++iter )
			delete(iter->second);
	}

private:
	std::map<DWORD, bind_base*> map_bind_class;
};


} // namespace serverframe {
#endif
