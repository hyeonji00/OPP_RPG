#include "CPlayer.h"
using namespace std;

CPlayer::CPlayer(MatchUpType type, int hp, int power)
    : CCommonCharacter(type, hp, power), m_exp(0) {
}
CPlayer::~CPlayer() {}

void CPlayer::rewardExp(int exp) { 
    m_exp += exp; 
}

void CPlayer::addItem(itemData item) { 
    m_inventoryManager.addItem(item); 
}

void CPlayer::removeItem(int idx) { 
    m_inventoryManager.removeItem(idx);
}

void CPlayer::useItem(int itemId) { 
    m_inventoryManager.useItem(itemId); 
}

void CPlayer::showPlayerItemList() { 
    m_inventoryManager.showPlayerItemList(); 
}

void CPlayer::addItemData(itemData item) {
    m_inventoryManager.addItemData(item);
}

void CPlayer::removeItemData(int idx) {
    m_inventoryManager.removeItem(idx);
}

void CPlayer::addSkillData(skillData skill) {
    m_inventoryManager.addSkillData(skill);
}

void CPlayer::removeSkillData(int idx) {
    m_inventoryManager.removeSkillData(idx);
}

void CPlayer::setJobData(jobData job) {
    m_inventoryManager.setJobData(job);
}

void CPlayer::usePotion() { 
    resetHp(); 
    // m_inventoryManager에서 인벤토리에서 포션 삭제
}