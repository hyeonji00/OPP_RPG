#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "CUtils.h"
#include "CDataListManager.h"

class CInventoryManager {
public:
    CInventoryManager();
    ~CInventoryManager();

    itemData returnRandomItem();

    void addItem(itemData item) { m_playerItemList.push_back(item); }
    void removeItem(int index) { m_playerItemList.erase(m_playerItemList.begin() + index); }
    void useItem(int itemId);
    void showPlayerItemList() const;
    void showPlayerSkillList() const;
    int  getOffensivePower() const;
    int  getDefensivePower() const;

    void addItemData(itemData item);
    void removeItemData(int idx);
    std::vector<itemData> getItemData() { return m_playerItemList; }

    void addSkillData(skillData skill);
    void addPlayerSkill(int idx);
    void removeSkillData(int idx);
    std::vector<skillData> getSkillData() { return m_playerSkillList; }

    void setJobData(jobData job);
    jobData getJobData() { return m_playerJobData; }

private:
    std::vector<itemData> m_playerItemList;
    int m_currentItemIdx;

    std::vector<skillData> m_playerSkillList;

    jobData m_playerJobData;
};