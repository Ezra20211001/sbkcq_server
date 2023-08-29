/*******************************************************************************

Copyright 2010 by tiankong Interactive Game Co., Ltd.
All rights reserved.

This software is the confidential and proprietary information of
tiankong Interactive Game Co., Ltd. ('Confidential Information'). You shall
not disclose such Confidential Information and shall use it only in
accordance with the terms of the license agreement you entered into with
tiankong Interactive  Co., Ltd.

*******************************************************************************/

#pragma once


//!  Game World �� server ����
enum E_server_type 
{
	est_world,		//��Ϸ���������
	est_db,			//��Ϸ�������ݿ������
	est_login,		//��Ϸ����login������	
};

//! �ͻ���Ȩ��
enum EPrivilege
{
	ep_null		=	-1,		// δ��ʼ��
	ep_pri_gm_d	=	0,		// 1��Ȩ��
	ep_pri_gm_c	=	1,		// 2��Ȩ��
	ep_pri_gm_b	=	2,		// 3��Ȩ��
	ep_pri_gm_a	=	3,		// 4��Ȩ��
	ep_pri_gm_s	=	4,		// 5��Ȩ��
	ep_pri_rt_b	=	5,		// 6��Ȩ��
	ep_pri_rt_a	=	6,		// 7��Ȩ��(6 7��ΪԶ�̼��ʹ��)
	ep_pri_rt_c	=	7,		// 8��Ȩ��(��������������������)
	ep_pri_rt_d	=	8,		// 9��Ȩ��(�����̳���)
	ep_end		=	9
};

#define M_is_gm_tool_pri(ePri)	((ePri) >= ep_pri_gm_d && (ePri) <= ep_pri_gm_s)
#define M_is_rt_client_pri(ePri)	((ePri) >= ep_pri_rt_b && (ePri) <= ep_pri_rt_d)

#define M_is_gm_op_gm(root, gm)		(M_is_gm_tool_pri(root)		&& M_is_gm_tool_pri(gm) )
#define M_is_rt_op_rt(root, rt)		(M_is_rt_client_pri(root)		&& M_is_rt_client_pri(rt) )