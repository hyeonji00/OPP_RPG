#pragma once
#include <iostream>
#include <string.h>

#include "CPlayer.h"
#include "CMonster.h"

class CMatchUpSystem {

public:
	CMatchUpSystem(CPlayer& player, CMonster& monster);
	~CMatchUpSystem();

	bool isEndMatchUp();
	void applySkill();
	void matchUp();

private:
	std::string typeToString(MatchUpType type);
	int calculateDamage(CCommonCharacter& attacker, CCommonCharacter& defender);

	CPlayer&	m_player;
	CMonster&	m_monster;
};