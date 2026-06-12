#pragma once
#include "CCommonCharacter.h"

#include "CInventoryManager.h"

class CMonster : public CCommonCharacter {
public:
	CMonster();
	CMonster(MatchUpType type, int hp, int power);
	~CMonster();

	int getItemOffensivePower() override { return 0; };
	int getItemDefensivePower() override { return 0; };

	void setRandomItem();
	itemData dropItem();

private:
	CInventoryManager m_inventoryManager;
	itemData m_item;
};