#pragma once
#include <vector>

#include "CCommonCharacter.h"
#include "CInventoryManager.h"

class CPlayer : public CCommonCharacter {
public:
    CPlayer(MatchUpType type, int hp, int power);
    ~CPlayer();

    void addItem(itemData item);
    void removeItem(int index);
    void useItem(int itemId);
    void printItem();
    int  getItemOffensivePower() { return m_inventoryManager.getOffensivePower(); }
    int  getItemDefensivePower() { return m_inventoryManager.getDefensivePower(); }

    void setJobData(jobData job);
    jobData getJobData() { return m_inventoryManager.getJobData(); }
    skill getSkill() { return m_inventoryManager.getJobData().m_skill; }
    void useSkill();

    void rewardExp(int exp);
    int  getExp() const { return m_exp; }

    void usePotion();

private:
	CInventoryManager m_inventoryManager;
	int m_exp;
};