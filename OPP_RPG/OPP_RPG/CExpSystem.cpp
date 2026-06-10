#include "CExpSystem.h"
using namespace std;

CExpSystem::CExpSystem(CPlayer& player, CMonster& monster) :m_player(player), m_monster(monster) {

}

CExpSystem::~CExpSystem() {

}

void CExpSystem::rewardExp() {
	m_player.rewardExp(m_monster.getPower());
}