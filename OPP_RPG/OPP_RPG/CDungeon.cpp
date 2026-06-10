#include "CDungeon.h"
using namespace std;

CDungeon::CDungeon(CPlayer& player) : m_player(player) {

}


CDungeon::~CDungeon() {

}

CMonster CDungeon::createMonster() {
	MatchUpType randomType = (MatchUpType)CUtils::getRandomInt(0, 2);
	int randomPower = CUtils::getRandomInt(1, 2);
	CMonster newMonster(randomType, 100, randomPower * 10);
	return newMonster;
}

void CDungeon::enter() {
	cout << "+------------------+" << endl;
	cout << "|   던전 입장 !!   |" << endl;
	cout << "+------------------+" << endl;

	int monsterCnt = CUtils::getRandomInt(1, 5);
	int matchUpCnt = 1;

	cout << monsterCnt << "개의 몬스터와 조우 !!" << endl;
	while (monsterCnt--) {
		if (!m_player.isAlive()) {
			cout << "모든 전투가 끝나기 전에 플레이어가 죽어 던전을 퇴장합니다 !!\n\n" << endl;
			break;
		}
		CMonster monster = createMonster();

		CMatchUpSystem matchUpSystem(m_player, monster);
		CExpSystem expSystem(m_player, monster);

		cout << "\n\n======================= " << matchUpCnt++ << "번째 전투 =========================" << endl;
		matchUpSystem.matchUp();
		if (!monster.isAlive()) {
			expSystem.rewardExp();
			cout << "현재 경험치 : " << m_player.getExp() << endl;
		}
		/*m_player.takePotion();
		cout << "플레이어가 전투를 끝내고 포션을 먹어 HP가 100이 되었습니다" << endl;*/
		cout << "============================================================" << endl;
		Sleep(1000);
	}
	cout << "모든 전투가 끝나 던전을 퇴장합니다 !!\n\n" << endl;

}