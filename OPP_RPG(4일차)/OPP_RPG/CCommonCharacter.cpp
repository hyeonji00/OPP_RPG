#include "CCommonCharacter.h"

CCommonCharacter::CCommonCharacter() {

}

CCommonCharacter::CCommonCharacter(MatchUpType type, int hp, int power) :m_type(type), m_hp(hp), m_power(power) {

}

CCommonCharacter::~CCommonCharacter() {

}

bool CCommonCharacter::isAlive() {
	return (m_hp > 0);
}

void CCommonCharacter::takeDamage(int damage) {
	m_hp -= damage;
}

void CCommonCharacter::resetHp() {
	m_hp = 100;
}

void CCommonCharacter::chargeHp(int hp) {
	m_hp += hp;
}