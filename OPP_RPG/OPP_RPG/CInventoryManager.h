#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "CUtils.h"

struct itemData {
    std::string m_name;
    int m_offensivePower;
    int m_defensivePower;
};

enum class skill {CHARGE=0, STEALTH, HEAL};

struct jobData {
    std::string m_name;
    skill m_skill;
};

class CInventoryManager {
public:
    CInventoryManager();
    ~CInventoryManager();

    itemData returnRandomItem();

    void addItem(itemData item) { m_playerItemList.push_back(item); }
    void removeItem(int index) { m_playerItemList.erase(m_playerItemList.begin() + index); }
    void useItem(int itemId);
    void printInventory() const;
    int  getOffensivePower() const;
    int  getDefensivePower() const;

    void setJobData(jobData job);
    jobData getJobData() { return m_playerJobData; }

private:
    std::vector<itemData> m_totalItemList;
    std::vector<itemData> m_playerItemList;

    std::vector<jobData> m_totaljobList;
    jobData m_playerJobData;

    int m_currentItemIdx;
};