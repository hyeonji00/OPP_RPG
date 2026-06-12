#pragma once
#include "CMatchupSystem.h"
#include "CExpSystem.h"
#include "CUtils.h"

class CDungeon {
public:
	CDungeon(CPlayer& player);
	~CDungeon();

	CMonster createMonster();
	void enter();
	
private:
	CPlayer& m_player;
};