#include "CInventoryManager.h"
using namespace std;

CInventoryManager::CInventoryManager() : m_currentItemIdx(-1) {

}

CInventoryManager::~CInventoryManager() {

}

itemData CInventoryManager::returnRandomItem() {
    int randomIdx = CUtils::getRandomInt(0, CDataListManager::getTotalItemSize() - 1);
    return CDataListManager::getItemData(randomIdx);
}

void CInventoryManager::useItem(int itemId) {
    if (0 < itemId && itemId <= (int)m_playerItemList.size()) {
        m_currentItemIdx = itemId - 1;
        cout << itemId << "번 아이템 " << m_playerItemList[m_currentItemIdx].m_name << "을 착용하였습니다.\n\n";
    }
    else {
        cout << "존재하지 않는 아이템입니다.\n\n";
    }
}

void CInventoryManager::showPlayerItemList() const {
    if (m_playerItemList.empty()) {
        cout << "아이템이 없습니다." << endl;
        return;
    }
    cout << "--------------- 아이템 목록 -------------------" << endl;
    for (int i = 0; i < (int)m_playerItemList.size(); i++) {
        cout << i + 1 << ". " << m_playerItemList[i].m_name
            << " | 공격력: " << m_playerItemList[i].m_offensivePower
            << " | 방어력: " << m_playerItemList[i].m_defensivePower;
        if (i == m_currentItemIdx) {
            cout << "\t--> 현재 착용 중인 아이템";
        }
        cout << endl;
    }
    cout << "----------------------------------------------" << endl;
}

void CInventoryManager::showPlayerSkillList() const {
    if (m_playerSkillList.empty()) {
        cout << "스킬이 없습니다." << endl;
        return;
    }
    cout << "--------------- 스킬 목록 -------------------" << endl;
    for (int i = 0; i < (int)m_playerSkillList.size(); i++) {
        cout << i + 1 << ". " << m_playerSkillList[i].m_name
            << " | 공격력: " << m_playerSkillList[i].m_attackPower
            << " | 방어력: " << m_playerSkillList[i].m_healPower;
        cout << endl;
    }
    cout << "----------------------------------------------" << endl;
}

int CInventoryManager::getOffensivePower() const {
    if (!m_playerItemList.empty() && m_currentItemIdx > -1) {
        return m_playerItemList[m_currentItemIdx].m_offensivePower;
    }
    return 0;
}

int CInventoryManager::getDefensivePower() const {
    if (!m_playerItemList.empty() && m_currentItemIdx > -1) {
        return m_playerItemList[m_currentItemIdx].m_defensivePower;
    }
    return 0;
}

void CInventoryManager::addItemData(itemData item) {
    m_playerItemList.push_back(item);
}

void CInventoryManager::removeItemData(int idx) {
    if (idx < 0 || idx >= m_playerItemList.size()) {
        return;
    }
    cout << m_playerItemList[idx].m_name << " 삭제 완료\n";
    m_playerItemList.erase(m_playerItemList.begin() + idx);
}

void CInventoryManager::addSkillData(skillData skill) {
    m_playerSkillList.push_back(skill);
}

void CInventoryManager::addPlayerSkill(int idx) {
    m_playerSkillList.push_back(CDataListManager::getTotalSkillList()[idx]);
}

void CInventoryManager::removeSkillData(int idx) {
    if (idx < 0 || idx >= m_playerSkillList.size()) {
        return;
    }
    cout << m_playerSkillList[idx].m_name << " 삭제 완료\n";
    m_playerSkillList.erase(m_playerSkillList.begin() + idx);
}

void CInventoryManager::setJobData(jobData job) {
    m_playerJobData = job;
}