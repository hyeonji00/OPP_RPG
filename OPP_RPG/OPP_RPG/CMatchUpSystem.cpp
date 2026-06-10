#include "CMatchupSystem.h"
using namespace std;

CMatchUpSystem::CMatchUpSystem(CPlayer& player, CMonster& monster) :m_monster(monster), m_player(player){
	
}

CMatchUpSystem::~CMatchUpSystem() {

}

string CMatchUpSystem::typeToString(MatchUpType type) {
	switch (type) {
	case MatchUpType::ROCK:     return "ROCK";
	case MatchUpType::SCISSORS: return "SCISSORS";
	case MatchUpType::PAPER:    return "PAPER";
	default:                    return "UNKNOWN";
	}
}

int CMatchUpSystem::calculateDamage(CCommonCharacter& attacker, CCommonCharacter& defender) {
	const float MULTIPLIER[3][3] = {
		{ 1.0f,  1.2f,  0.8f },
		{ 0.8f,  1.0f,  1.2f },
		{ 1.2f,  0.8f,  1.0f },
	};

	int attackerIdx = (int)attacker.getType();
	int defenderIdx = (int)defender.getType();

	int totalPower = attacker.getPower() + attacker.getItemOffensivePower() - defender.getItemDefensivePower();

	return (int)(totalPower * MULTIPLIER[attackerIdx][defenderIdx]);
}

bool CMatchUpSystem::isEndMatchUp() {
	if (!m_player.isAlive()) {
		cout << "---------------- 매치업 종료 !! ----------------" << endl;
		cout << "player 패배..... ㅠ.ㅠ" << endl;
		return true;
	}
	else if (!m_monster.isAlive()) {
		cout << "---------------- 매치업 종료 !! ----------------" << endl;
		cout << "player 승리 !!!! ^0^" << endl;

		itemData item = m_monster.dropItem();
		m_player.addItem(item);
		cout << "처치한 monster로부터 " << item.m_name << " item 획득" << endl;
		return true;
	}
	return false;
}

void CMatchUpSystem::applySkill() {
	skill playerSkill = m_player.getSkill();
	if (skill::CHARGE == playerSkill) {
		m_monster.takeDamage(20);
	}
	else if (skill::STEALTH == playerSkill) {
		m_monster.takeDamage(10);
		m_player.chargeHp();
	}
	else if (skill::HEAL == playerSkill) {
		m_player.resetHp();
	}
}

void CMatchUpSystem::matchUp() {
	int cnt = 1;
	
	cout << "player의 power : " << m_player.getPower() << " || type : " << typeToString(m_player.getType()) << endl;
	cout << "monster의 power : " << m_monster.getPower() << " || type : " << typeToString(m_monster.getType()) << endl;
	cout << "---------------- 매치업 시작 !! ----------------" << endl << endl;
	m_monster.setRandomItem();

	while (1) {
		m_monster.takeDamage(calculateDamage(m_player, m_monster));
		if (isEndMatchUp()) {
			break;
		}
		m_player.takeDamage(calculateDamage(m_monster, m_player));
		if (isEndMatchUp()) {
			break;
		}
		applySkill();
		if (isEndMatchUp()) {
			break;
		}

		cout << cnt++ << "번째 매치" << endl;
		cout << "player의 HP : " << m_player.getHp() << endl;
		cout << "monster의 HP : " << m_monster.getHp() << endl << endl;
	}
}