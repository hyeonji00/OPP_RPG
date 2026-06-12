#include "CVillage.h"
using namespace std;

CVillage::CVillage(CPlayer& player) : m_player(player) {

}


CVillage::~CVillage() {

}

void CVillage::enter() {
	cout << "+------------------+" << endl;
	cout << "|   마을 입장 !!   |" << endl;
	cout << "+------------------+" << endl;

	bool run = true;
	int input = -1;
	int itemId = -1;

	CStoreSystem storeSystem;

	while (run) {
		cout << "0. 마을 나가기" << endl;
		cout << "1. 아이템 조회" << endl;
		cout << "2. 아이템 착용" << endl;
		cout << "3. 상점 이동" << endl;

		cin >> input;

		switch (input)
		{
		case 0:
			run = false;
			break;
		case 1:
			m_player.showPlayerItemList();
			break;
		case 2:
			cout << "착용하고 싶은 아이템 ID를 입력하세요 : ";
			cin >> itemId;
			m_player.useItem(itemId);
			break;
		case 3:
			storeSystem.enter();
			break;
		default:
			break;
		}
	}

}