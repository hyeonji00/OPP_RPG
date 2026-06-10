#pragma once
#include "CPlayer.h"
#include "CUtils.h"

class CVillage {
public:
	CVillage(CPlayer& player);
	~CVillage();

	void enter();

private:
	CPlayer& m_player;
};