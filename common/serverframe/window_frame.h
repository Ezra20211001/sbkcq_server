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
*	@file		window_frame.h
*	@author		lc
*	@date		2011/02/18	initial
*	@version	0.0.1.0
*	@brief		
*/

#ifndef WINDOW_FRAM
#define WINDOW_FRAM

namespace serverframe {
#define	WM_MYSELF_USER		(WM_APP + 10)
#define print_message			get_window()->print

class FRAME_API window_frame
{
public:
	BOOL init(INT n_width_=0, INT n_height_=0, BOOL b_board_=FALSE, BOOL b_show_taskbar_=TRUE);
	VOID destroy();
	BOOL create_window(LPCTSTR sz_caption_, HINSTANCE h_hinstance_, HICON h_icon_=0, HMENU h_menu_=0, BOOL b_min_box_=TRUE);
	__forceinline BOOL message_loop();
	__forceinline BOOL peek_window_message(DWORD& dw_message_, DWORD& dw_param1_, DWORD& dw_param2_);
	
	BOOL is_window_active() { return b_window_active; }

	HWND create_systeminfo_tree(HWND h_hwnd_parent_) ;

	VOID watch_info(LPCTSTR sz_name_, DWORD dw_value_, DWORD dw_value2_=0);

	HWND create_list_box(HWND h_hwnd_parent_);

	VOID print(LPCTSTR sz_text_, ... );
	VOID		lock() { EnterCriticalSection(&_lock); }
	VOID		unlock() { LeaveCriticalSection(&_lock); }

	VOID print_list();

	window_frame();
	~window_frame();
	
	const HWND& getHWND() {return h_wnd;}
private:

	LRESULT	window_proc(HWND, UINT, WPARAM, LPARAM);

	static LRESULT static_window_proc(HWND hwnd_, UINT message_, WPARAM w_param_, LPARAM l_param_);

	__forceinline VOID on_window_message(DWORD dw_message_, DWORD dw_param1_, DWORD dw_param2_);

private:
	CRITICAL_SECTION				_lock;
	
	HWND							h_wnd;

	INT								n_width;
	INT								n_height;
	BOOL							b_board;
	BOOL							b_show_taskbar;

	HACCEL							h_accel;
	HCURSOR							h_current_cursor;
	HCURSOR							h_arrow_cursor;

	volatile DWORD					dw_main_thread_id;
	volatile BOOL					b_window_active;
	volatile BOOL					b_invisible_ime;

	HINSTANCE						h_instance;
	HWND							h_hwnd_tv;
	HTREEITEM						h_tree_root;

	HWND							h_list_box;

	std::map<DWORD, HTREEITEM>		map_tree_item;


	struct tag_windows_message
	{
		DWORD dw_message;
		DWORD dw_param1;
		DWORD dw_param2;
	};

	message_queue	list_windows_message;
	safe_message_queue*	list_list_message;

};


BOOL window_frame::message_loop()
{
	MSG st_msg;
	while( PeekMessage( &st_msg, NULL, 0, 0, PM_REMOVE) )
	{
		if( WM_QUIT == st_msg.message )
			return TRUE;

		if( !TranslateAccelerator(st_msg.hwnd, h_accel, &st_msg) )
		{
			TranslateMessage(&st_msg);
			DispatchMessage(&st_msg);
		}
	}

	return FALSE;
}




VOID window_frame::on_window_message(DWORD dw_message_, DWORD dw_param1_, DWORD dw_param2_)
{
	tag_windows_message st_msg;
	st_msg.dw_message = dw_message_;
	st_msg.dw_param1 = dw_param1_;
	st_msg.dw_param2 = dw_param2_;

	list_windows_message.add_message(&st_msg, sizeof(st_msg));
}

BOOL window_frame::peek_window_message(DWORD& dw_message_, DWORD& dw_param1_, DWORD& dw_param2_)
{
	DWORD dw_size = 0;
	tag_windows_message* p_message = (tag_windows_message*)list_windows_message.get_message(dw_size);
	if( !p_message )
		return FALSE;

	dw_message_ = p_message->dw_message;
	dw_param1_ = p_message->dw_param1;
	dw_param2_ = p_message->dw_param2;

	list_windows_message.free_message(p_message);
	return TRUE;
}

extern FRAME_API window_frame* g_pwindow;
FRAME_API window_frame* get_window();

} // namespace serverframe {
#endif
