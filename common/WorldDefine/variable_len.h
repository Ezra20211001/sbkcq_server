//-----------------------------------------------------------------------------
//��Name				:   variable_len.h
//��Compiler			:	Microsoft Visual C++ 9.0
//��Version				:	1.00
//��Create Date			:	2009-04-10
//��LastModified		:	
//��Brief				:	��ͬ���԰汾�ַ�(TCHAR)�����ṹ����
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
struct tagVariableLen
{
	// ��ɫ����
	INT		nRoleNameMax;
	INT		nRoleNameMin;
	
	// �������
	INT		nGuildNameMax;
	INT		nGuildNameMin;
	INT		nGuildTenet;
	INT		nGuildSymbol;

	// ��̯
	INT		nStallTitleMax;

	//PK
	INT		nPKKillWrite;

	INT		nPKKillRed;

	INT		nPKValueDec;

	// ���ɱ������������
	INT		nBrother;

	// �����ʷ�
	INT		nMailMoney;
	
	// ������󳤶� add by gtj
	INT		nTeamPlacardMax;
	
	// �������
	INT		nRageLoss; //ŭ������
	INT		nPointLoss;//��������
	INT		nEnergyCom;//ս����������
	INT		nEnergy;   //��ս����������
	INT		nFocusLoss;//���е�������

	INT		n_paimai_duty;		// ����˰
	
	// ����sns
	INT		n_pet_return_min_time; 
	INT		n_pet_return_max_time;

	INT		n_fishing_vigour_cost_second;

	// Ǯׯ����
	INT		n_bank_radio;

	// �Ƿ�����֤�빦��
	INT		n_verification;
	
	// �ƶ������Ƿ�������
	INT		n_kick_fast_move;

	// ��֤��ʱ��
	INT		n_min_verification_time;
	INT		n_max_verification_time;

	// �����������
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