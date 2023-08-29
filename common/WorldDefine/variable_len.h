//-----------------------------------------------------------------------------
//★Name				:   variable_len.h
//★Compiler			:	Microsoft Visual C++ 9.0
//★Version				:	1.00
//★Create Date			:	2009-04-10
//★LastModified		:	
//★Brief				:	不同语言版本字符(TCHAR)个数结构定义
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
struct tagVariableLen
{
	// 角色名字
	INT		nRoleNameMax;
	INT		nRoleNameMin;
	
	// 帮派相关
	INT		nGuildNameMax;
	INT		nGuildNameMin;
	INT		nGuildTenet;
	INT		nGuildSymbol;

	// 摆摊
	INT		nStallTitleMax;

	//PK
	INT		nPKKillWrite;

	INT		nPKKillRed;

	INT		nPKValueDec;

	// 组队杀怪提升的义气
	INT		nBrother;

	// 基础邮费
	INT		nMailMoney;
	
	// 公告最大长度 add by gtj
	INT		nTeamPlacardMax;
	
	// 能量相关
	INT		nRageLoss; //怒气减少
	INT		nPointLoss;//点数减少
	INT		nEnergyCom;//战斗能量增加
	INT		nEnergy;   //非战斗能量增加
	INT		nFocusLoss;//集中点数减少

	INT		n_paimai_duty;		// 拍卖税
	
	// 宠物sns
	INT		n_pet_return_min_time; 
	INT		n_pet_return_max_time;

	INT		n_fishing_vigour_cost_second;

	// 钱庄汇率
	INT		n_bank_radio;

	// 是否开启验证码功能
	INT		n_verification;
	
	// 移动过快是否踢下线
	INT		n_kick_fast_move;

	// 验证码时间
	INT		n_min_verification_time;
	INT		n_max_verification_time;

	// 老友礼包开关
	INT		n_LeaveTimeReward;

	// 
	INT		n_public_cd_time[X_ClASS_TYPE_NUM+2];


	INT dancing_multiple_start_time ;
	INT dancing_multiple_end_time ;
	INT dancing_factor;
	INT pet_ernie_level;
	INT attack_stop_mount_prob;
	
	INT nSignLevel;

	tagVariableLen() { ZeroMemory(this, sizeof(*this)); }

	BOOL CheckValid() const
	{
		return (IsRoleNameValid()
				&& IsGuildNameValid()
				&& IsStallTitleValid());
	}

private:
	BOOL IsRoleNameValid() const
	{
		return !(nRoleNameMin < 0 || nRoleNameMax < nRoleNameMin || X_SHORT_NAME < nRoleNameMax);
	}

	BOOL IsGuildNameValid() const
	{
		return !(nGuildNameMin < 0 || nGuildNameMin > nGuildNameMax || nGuildTenet < 0);
	}

	BOOL IsStallTitleValid() const
	{
		return nStallTitleMax > 0;
	}
};