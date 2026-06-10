#include "CMonster.h"

CMonster::CMonster() {

}

CMonster::CMonster(MatchUpType type, int hp, int power) :CCommonCharacter(type, hp, power) {

}


CMonster::~CMonster() {

}

void CMonster::setRandomItem() {
	m_item = itemManager.returnRandomItem();
}

itemData CMonster::dropItem() {
	return m_item;
}