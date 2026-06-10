#include "CInventoryManager.h"
using namespace std;

CInventoryManager::CInventoryManager() : m_currentItemIdx(-1) {
    // 아이템 풀 초기화
    m_totalItemList.push_back({ "sword",   35,  5 });
    m_totalItemList.push_back({ "spear",   30,  4 });
    m_totalItemList.push_back({ "helmet",   2, 20 });
    m_totalItemList.push_back({ "shield",   0, 25 });

    m_totaljobList.push_back({ "Tanker", skill::CHARGE });
    m_totaljobList.push_back({ "Dealer", skill::STEALTH });
    m_totaljobList.push_back({ "Healer", skill::HEAL });
}

CInventoryManager::~CInventoryManager() {

}

itemData CInventoryManager::returnRandomItem() {
    int randomIdx = CUtils::getRandomInt(0, m_totalItemList.size() - 1);
    return m_totalItemList[randomIdx];
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

void CInventoryManager::printInventory() const {
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

void CInventoryManager::setJobData(jobData job) {
    m_playerJobData = job;
}