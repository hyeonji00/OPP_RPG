#include "CDataListManager.h"
using namespace std;

std::vector<itemData>  CDataListManager::m_totalItemList;
std::vector<skillData> CDataListManager::m_totalSkillList;
std::vector<jobData>   CDataListManager::m_totaljobList;

CDataListManager::CDataListManager() {
    m_totalItemList.push_back({ "sword",   35,  5 });
    m_totalItemList.push_back({ "spear",   30,  4 });
    m_totalItemList.push_back({ "helmet",   2, 20 });
    m_totalItemList.push_back({ "shield",   0, 25 });

    for (int i = 0; i < 100; i++) {
        m_totalSkillList.push_back({ "skill", CUtils::getRandomInt(0,100), CUtils::getRandomInt(0,100), "common" });
    }

    m_totaljobList.push_back({ "tanker" });
    m_totaljobList.push_back({ "dealer" });
    m_totaljobList.push_back({ "healer" });

    for (int i = 0; i < 3; i++) {
        m_totalSkillList[i].m_requiredJob = m_totaljobList[i];
    }
}

CDataListManager::~CDataListManager() {

}

void CDataListManager::showTotalSkillList() {
    if (m_totalSkillList.empty()) {
        cout << "스킬이 없습니다." << endl;
        return;
    }
    cout << "--------------- 스킬 목록 -------------------" << endl;
    for (int i = 0; i < (int)m_totalSkillList.size(); i++) {
        cout << i + 1 << ". " << m_totalSkillList[i].m_name
            << " | 공격력: " << m_totalSkillList[i].m_attackPower
            << " | 방어력: " << m_totalSkillList[i].m_healPower;
        cout << endl;
    }
    cout << "----------------------------------------------" << endl;
}