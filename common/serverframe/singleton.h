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
*	@file		singleton.h
*	@author		lc
*	@date		2011/02/17	initial
*	@version	0.0.1.0
*	@brief		
*/


#ifndef SINGLETON
#define SINGLETON

namespace serverframe {

	template<typename T>
	struct static_instance
	{
		static T* get_instance() { static T instance; return &instance; }
	};

	
	template<typename T, template<typename> class Instance = static_instance>
	class singleton
	{
	public:
		singleton()
		{
			ASSERT( !p_singleton );
			p_singleton = static_cast<T*>(this);
		}

		~singleton()
		{
			ASSERT( p_singleton );
			p_singleton = NULL;
		}

		static T& get_singleton()    {  try_get_instance(); return *p_singleton; }
		static T* get_singleton_pointer() {  try_get_instance(); return  p_singleton; }
	private:
		static void try_get_instance() { if ( !p_singleton ) p_singleton = Instance<T>::get_instance(); }
		static T* p_singleton;
	};

	template<typename T, template<typename> class Instance> 
	T* singleton<T,Instance>::p_singleton;

}
#endif
