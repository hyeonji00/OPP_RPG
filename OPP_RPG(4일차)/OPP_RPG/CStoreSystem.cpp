#include "CStoreSystem.h"
using namespace std;

CStoreSystem::CStoreSystem() {

}

CStoreSystem::~CStoreSystem() {

}

void CStoreSystem::enter() {
	cout << "+------------------+" << endl;
	cout << "|   상점 입장 !!   |" << endl;
	cout << "+------------------+" << endl;

	bool run = true;
	int input = -1;
	int skillId = -1;

	while (run) {
		cout << "0. 상점 나가기" << endl;
		cout << "1. 스킬 조회" << endl;
		cout << "2. 스킬 구매" << endl;

		cin >> input;

		switch (input)
		{
		case 0:
			run = false;
			break;
		case 1:
			CDataListManager::showTotalSkillList();
			break;
		case 2:
			cout << "구매하고 싶은 스킬 ID를 입력하세요 : ";
			cin >> skillId;
			m_inventoryManager.addPlayerSkill(skillId);
			break;
		default:
			break;
		}
	}

}

void CStoreSystem::buySkill() {

}