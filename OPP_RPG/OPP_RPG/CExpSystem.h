#pragma once
#include "CPlayer.h"
#include "CMonster.h"

class CExpSystem {
public:
	CExpSystem(CPlayer& player, CMonster& monster);
	~CExpSystem();

	void rewardExp();

private:
	CPlayer& m_player;
	CMonster& m_monster;
};
