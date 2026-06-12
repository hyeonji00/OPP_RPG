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
    void showPlayerItemList();
    int  getItemOffensivePower() { return m_inventoryManager.getOffensivePower(); }
    int  getItemDefensivePower() { return m_inventoryManager.getDefensivePower(); }

    void addItemData(itemData item);
    void removeItemData(int idx);

    void addSkillData(skillData skill);
    void removeSkillData(int idx);
    std::vector<skillData> getSkill() { return m_inventoryManager.getSkillData(); }

    void setJobData(jobData job);
    jobData getJobData() { return m_inventoryManager.getJobData(); }

    void rewardExp(int exp);
    int  getExp() const { return m_exp; }

    void usePotion();

private:
	CInventoryManager m_inventoryManager;
	int m_exp;
};