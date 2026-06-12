#include <iostream>
using namespace std;

#include "CVillage.h"
#include "CDungeon.h"

int main() {
	int input = -1;

	CPlayer  hero(MatchUpType::ROCK, 100, 60);
	hero.setJobData({ "healer"});

	CDungeon dungeon(hero);
	CVillage village(hero);

	
	while (1) {
		cout << "+====================+" << endl;
		cout << "1. 던전 입장" << endl;
		cout << "2. 마을 입장" << endl;
		cout << "+====================+" << endl;
		
		cin >> input;

		switch (input) {
		case 1:
			//던전입장
			dungeon.enter();
			break;
		case 2:
			//마을입장
			village.enter();
			break;
		default:
			std::cout << "잘못된 입력입니다!\n";
			break;
		}
	}

	return 0;
}