#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "CUtils.h"

struct itemData {
    std::string m_name;
    int m_offensivePower;
    int m_defensivePower;
};

struct jobData {
    std::string m_name;
};

struct skillData {
    std::string m_name;
    int m_attackPower;
    int m_healPower;
    jobData m_requiredJob;
};

class CDataListManager {
public:
    CDataListManager();
    ~CDataListManager();

    static void showTotalSkillList();

    static int getTotalItemSize() { return m_totalItemList.size(); };
    static std::vector<itemData> getTotalItemList() { return m_totalItemList; };
    static itemData getItemData(int idx) { return m_totalItemList[idx]; };

    static int getTotalSkillSize() { return m_totalSkillList.size(); };
    static std::vector<skillData> getTotalSkillList() { return m_totalSkillList; };
    static skillData getSkillData(int idx) { return m_totalSkillList[idx]; };

    static int getTotalJobSize() { return m_totaljobList.size(); };
    static std::vector<jobData> getTotalJobList() { return m_totaljobList; };
    static jobData getJobData(int idx) { return m_totaljobList[idx]; };
private:
    static std::vector<itemData> m_totalItemList;
    static std::vector<skillData> m_totalSkillList;
    static std::vector<jobData> m_totaljobList;
};