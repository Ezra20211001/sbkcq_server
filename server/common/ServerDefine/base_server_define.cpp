#pragma warning(disable:4355)	// Level 3: "this": 用于基成员初始值设定项列表
#pragma warning(disable:4251)	// Level 3: need to have dll-interface
#pragma warning(disable:4996)
#pragma warning(disable:4311)
#pragma warning(disable:4267)
#pragma warning(disable:4244)
#pragma warning(disable:4245)
#pragma warning(disable:4100)
#pragma warning(disable:4201)
#pragma warning(disable:4127)
#pragma warning(disable:4312)

#include "../serverbase/serverbase.h"
#include "../memory/memory_define.h"
memorysystem::safe_memory_pool s_MemPoolSafe;

#include "base_server_define.h"
server_mem_pool g_mem_pool_safe;

LPVOID server_mem_pool::alloc( DWORD dw_size )
{
	return s_MemPoolSafe.alloc_memory(dw_size);
}

VOID server_mem_pool::_free( LPVOID pMem )
{
	s_MemPoolSafe.free_memory(pMem);
}