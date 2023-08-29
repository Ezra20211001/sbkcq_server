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
*	@file		window_fram.h
*	@author		lc
*	@date		2011/02/18	initial
*	@version	0.0.1.0
*	@brief		
*/

#include "stdafx.h"
#include "window_frame.h"


namespace serverframe {

window_frame* g_pwindow = new window_frame;

FRAME_API window_frame* get_window()
{
	ASSERT(g_pwindow);
	return g_pwindow;
}

window_frame::window_frame()
{
	h_wnd = 0;
	h_accel = 0;
	n_width = 0;
	n_height = 0;
	b_board = FALSE;
	b_show_taskbar = FALSE;
	b_invisible_ime	= FALSE;
	list_list_message = new safe_message_queue(FALSE, FALSE);
}

window_frame::~window_frame()
{
	h_wnd = 0;
	SAFE_DELETE(list_list_message);
	this->destroy();
}

BOOL window_frame::init(INT n_width_, INT n_height_, BOOL b_board_, BOOL b_show_taskbar_)
{
	n_width = n_width_;
	n_height = n_height_;
	b_board = b_board_;
	b_show_taskbar = b_show_taskbar_;
	b_window_active = TRUE;

	if( n_width == 0 )
		n_width = GetSystemMetrics(SM_CXSCREEN);

	if( n_height == 0 )
		n_height = GetSystemMetrics(SM_CYSCREEN);

	InitializeCriticalSection(&_lock);

	return TRUE;
}

VOID window_frame::destroy()
{
	DeleteCriticalSection(&_lock);
	if( h_wnd )
	{
		DestroyWindow(h_wnd); 
		h_wnd = 0;
	}
}

BOOL window_frame::create_window(LPCTSTR sz_caption_, HINSTANCE h_hinstance_, HICON h_icon_, HMENU h_menu_, BOOL b_min_box_)
{
	dw_main_thread_id = GetCurrentThreadId();
	h_arrow_cursor = LoadCursor(NULL, IDC_ARROW);
	h_current_cursor = h_arrow_cursor;

	WNDCLASSEX wcex;

	wcex.cbSize			= sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc	= (WNDPROC)(&window_frame::static_window_proc);
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= h_hinstance_;
	wcex.hIcon			= h_icon_;
	wcex.hCursor		= h_current_cursor;
	wcex.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName	= 0;
	wcex.lpszClassName	= sz_caption_;
	wcex.hIconSm		= 0;
	
	if( 0 == RegisterClassEx(&wcex) ) 
	{
		OutputDebugString(_T("register window error"));
		return FALSE;
	}

	if( b_min_box_ )
		h_wnd = ::CreateWindow(sz_caption_, sz_caption_, WS_OVERLAPPED|WS_CAPTION|WS_MINIMIZEBOX|WS_SYSMENU,
			CW_USEDEFAULT, CW_USEDEFAULT, n_width, n_height, NULL, NULL, h_hinstance_, this);
	else
		h_wnd = ::CreateWindow(sz_caption_, sz_caption_, WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU,
		 	CW_USEDEFAULT, CW_USEDEFAULT, n_width, n_height, NULL, NULL, h_hinstance_, this);

	if( !h_wnd ) 
	{
		OutputDebugString(_T("create window error"));
		return 1;
	}

	if( h_menu_ )
		::SetMenu(h_wnd, h_menu_);

	if( !b_board )
	{
		SetWindowLong(h_wnd, GWL_STYLE, WS_POPUP);
		SetWindowPos(h_wnd,HWND_TOP,0,0,0,0,SWP_FRAMECHANGED|SWP_NOMOVE|SWP_NOSIZE);
	}

	RECT rc_client;   
	RECT rc_window;   
	::GetWindowRect(h_wnd, &rc_window);	
	::GetClientRect(h_wnd, &rc_client);
	INT x = (rc_window.right-rc_window.left) - (rc_client.right-rc_client.left);
	INT y = (rc_window.bottom-rc_window.top) - (rc_client.bottom-rc_client.top);

	if( b_show_taskbar )
	{
		RECT rc = {0, n_width, 0, n_height};
		SystemParametersInfo(SPI_GETWORKAREA, 0, &rc, 0);	
		if( n_width + x > rc.right - rc.left || n_height + y > rc.bottom - rc.top )
		{
			::GetWindowRect(h_wnd, &rc_window);	
			::GetClientRect(h_wnd, &rc_client);
			x = (rc_window.right-rc_window.left) - (rc_client.right-rc_client.left);
			y = (rc_window.bottom-rc_window.top) - (rc_client.bottom-rc_client.top);
			n_width = rc.right - rc.left - x;
			n_height = rc.bottom - rc.top - y;
		}
	}

	SetWindowPos(h_wnd, HWND_TOP, 0, 0, n_width + x, n_height + y, SWP_SHOWWINDOW|SWP_NOMOVE);

	ShowWindow(h_wnd, SW_SHOWNORMAL);
	UpdateWindow(h_wnd);

	::SetCursor(h_current_cursor);
	return TRUE;
}

VOID window_frame::watch_info(LPCTSTR sz_name_, DWORD dw_value_, DWORD dw_value2_)
{
	DWORD dw_id = get_tool()->crc32(sz_name_);
	HTREEITEM p_temp_item;
	std::map<DWORD, HTREEITEM>::iterator iter =  map_tree_item.find(dw_id);
	if(iter == map_tree_item.end())
	{
		p_temp_item = NULL;
	}
	else
	{
		p_temp_item = iter->second;
	}

	
	if(VALID_POINT(p_temp_item))
	{
		TVITEMEX item_data;
		::ZeroMemory(&item_data, sizeof(TVITEMEX));
		item_data.mask = TVIF_TEXT;
		TCHAR s[260];
		if(dw_value2_ == 0)
		{
			wsprintf(s, _T("%s %d"), sz_name_, dw_value_);
		}
		else
		{
			wsprintf(s, _T("%s %d  %d"), sz_name_, dw_value_, dw_value2_);
		}
		item_data.pszText = s;
		item_data.cchTextMax = sizeof(s)/sizeof(TCHAR);
		item_data.hItem = p_temp_item;
		BOOL b = TreeView_SetItem(h_hwnd_tv, &item_data);
	}
	else
	{
		TVITEM tvi; 
		TVINSERTSTRUCT tvins;
		HTREEITEM temp_tree_item;
		tvi.mask = TVIF_TEXT | TVIF_PARAM; 

		tvi.pszText = (LPWSTR)sz_name_; 
		tvi.cchTextMax = sizeof(sz_name_)/sizeof(TCHAR); 

		tvi.lParam = (LPARAM)1; 
		tvins.item = tvi; 
		tvins.hParent = h_tree_root;
	
		temp_tree_item = (HTREEITEM)SendMessage(h_hwnd_tv, 
			TVM_INSERTITEM, 
			0,
			(LPARAM)(LPTVINSERTSTRUCT)&tvins); 
		map_tree_item.insert(std::make_pair(dw_id, temp_tree_item));

	}
}

HWND window_frame::create_list_box(HWND h_hwnd_parent_)
{
	h_list_box = CreateWindowEx(0, _T("LISTBOX"), 
		_T("ListBox"), 
		WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL,
		n_width/4,
		0,
		n_width - n_width/4,
		n_height+8,
		h_hwnd_parent_,
		NULL, 
		h_instance,
		NULL
		);
	return h_list_box;
}

VOID window_frame::print(LPCTSTR sz_text_, ... )
{
	if(!h_list_box)
		return;

	TCHAR sz_buffer[4096*2];

	ZeroMemory(sz_buffer, sizeof(sz_buffer));
	va_list argptr = NULL;
	va_start(argptr, sz_text_);
	_vstprintf_s(sz_buffer, sizeof(sz_buffer)/sizeof(TCHAR), sz_text_, argptr);
	va_end(argptr);

	list_list_message->add_message(sz_buffer, sizeof(sz_buffer));

	PostMessage(h_wnd, WM_MYSELF_USER, 1, 0);

	/*lock();
	INT nCount = SendMessage(h_list_box, LB_GETCOUNT, 0, 0);
	if(nCount > 300)
	{
		for(INT i = 0; i < 150; i++)
		{
			SendMessage(h_list_box, LB_DELETESTRING, 0, 0);
		}
	}
	unlock();*/
}

VOID window_frame::print_list()
{
	DWORD dw_size = 0;
	TCHAR* sz_buff = (TCHAR*)list_list_message->get_message(dw_size);
	if(!VALID_POINT(sz_buff))
		return;

	SendMessage(h_list_box, LB_ADDSTRING, 0, (LPARAM)sz_buff);

	list_list_message->free_message(sz_buff);
}

LRESULT window_frame::window_proc(HWND hwnd_, UINT message_, WPARAM w_param_, LPARAM l_param_)
{
	switch( message_ )
	{
	case WM_CREATE:
		create_systeminfo_tree(hwnd_);
		create_list_box(hwnd_);
		break;
	case WM_ERASEBKGND:	
		return false;
	case WM_DESTROY:
		PostQuitMessage(0);	
		break;
	case WM_ACTIVATEAPP:
	case WM_ACTIVATE:
		/*b_window_active = (w_param_ != 0);
		if( FALSE == b_window_active )
			::ClipCursor(NULL);	*/
		break;

	case WM_LBUTTONDOWN:	
		/*if( b_window_active )
		{
			RECT rcWindow;	
			::GetClientRect(hwnd_, &rcWindow);
			::ClientToScreen(hwnd_, (LPPOINT)&rcWindow);
			::ClientToScreen(hwnd_, (LPPOINT)&rcWindow + 1);
			::ClipCursor(&rcWindow);
		}*/
		break;

	case WM_LBUTTONUP:	
		if( b_window_active )
			::ClipCursor(NULL);	
		break;

	case WM_MOVE: 
	case WM_SIZE:
		break;

	case WM_SETCURSOR:  
		on_window_message(WM_SETCURSOR, (DWORD)w_param_, (DWORD)l_param_);
		return true;

    case WM_SYSCOMMAND:
		switch (w_param_)
		{
		case SC_TASKLIST:
		case SC_SCREENSAVE:
		case SC_MONITORPOWER:
        case SC_KEYMENU:
        case SC_MOUSEMENU:
			return false;
		case SC_CLOSE:
			{
				if(MessageBox(hwnd_, _T("is close server"), _T("alarm"), MB_YESNO) == IDYES)
				{
					on_window_message(WM_QUIT, 0, 0);
				}
				return false;
			}
		default:
			on_window_message((DWORD)message_, (DWORD)w_param_, (DWORD)l_param_);
			break;
		}
		break;

	case WM_SYSKEYUP:
		if( w_param_ == VK_MENU || w_param_ == VK_F10 ) 
			return false;
		break;
	case WM_SYSKEYDOWN:
		if(w_param_ == VK_F10)
		{
			b_window_active = !b_window_active;
			if( FALSE == b_window_active )
				::ClipCursor(NULL);	
		}

		break;
	}

	{
		switch( message_ )
		{
		case WM_CHAR:
		case WM_KEYDOWN:
		case WM_KEYUP:
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_LBUTTONDBLCLK:
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
		case WM_MOUSEMOVE:
		case WM_MOUSEWHEEL:
		case WM_SYSKEYDOWN:
		case WM_SYSCHAR:
		case WM_SYSKEYUP:
		case WM_INPUTLANGCHANGE:
		case WM_IME_SETCONTEXT:				
		case WM_INPUTLANGCHANGEREQUEST:
		case WM_MYSELF_USER:
		case WM_COMMAND:
			{
				on_window_message((DWORD)message_, (DWORD)w_param_, (DWORD)l_param_);
				break;
			}
		case WM_IME_STARTCOMPOSITION:
		case WM_IME_ENDCOMPOSITION:
		case WM_IME_NOTIFY:
		case WM_IME_COMPOSITION:
			{
				on_window_message((DWORD)message_, (DWORD)w_param_, (DWORD)l_param_);
				if( b_invisible_ime )
					return false;
			}
			break;
		}
	}

	return DefWindowProc( hwnd_, message_, w_param_, l_param_ );
}

LRESULT window_frame::static_window_proc(HWND hwnd_, UINT message_, WPARAM w_param_, LPARAM l_param_)
{
	static window_frame* p_window_frame = NULL;
	
	switch(message_)
	{
	case WM_CREATE:
		p_window_frame = (window_frame*)(((LPCREATESTRUCT)l_param_)->lpCreateParams);
		break;
	}

	if (VALID_POINT(p_window_frame))
	{
		return p_window_frame->window_proc(hwnd_, message_, w_param_, l_param_);
	}
	return DefWindowProc( hwnd_, message_, w_param_, l_param_ );

}

HWND window_frame::create_systeminfo_tree(HWND h_hwnd_parent_) 
{ 
	InitCommonControls(); 

	h_hwnd_tv = CreateWindowEx(0,
		WC_TREEVIEW,
		_T("Tree View"),
		WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL | TVS_HASLINES, 
		0, 
		0, 
		n_width-(n_width/4*3), 
		n_height,
		h_hwnd_parent_, 
		NULL, 
		h_instance, 
		NULL); 

	TVITEM tvi; 
	TVINSERTSTRUCT tvins; 
	static HTREEITEM hPrev = (HTREEITEM)TVI_FIRST; 
	static HTREEITEM hPrevRootItem = NULL; 
	static HTREEITEM hPrevLev2Item = NULL; 

	tvi.mask = TVIF_TEXT | TVIF_PARAM; 

	tvi.pszText = _T("系统信息"); 
	tvi.cchTextMax = sizeof(tvi.pszText)/sizeof(tvi.pszText[0]); 

	tvi.lParam = (LPARAM)0; 
	tvins.item = tvi; 
	tvins.hInsertAfter = hPrev; 

	tvins.hParent = TVI_ROOT; 

	h_tree_root = (HTREEITEM)SendMessage(h_hwnd_tv, 
		TVM_INSERTITEM, 
		0,
		(LPARAM)(LPTVINSERTSTRUCT)&tvins); 

	return h_hwnd_tv;
} 






} // namespace serverbase {
