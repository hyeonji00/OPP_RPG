#pragma once

#include "CDataListManager.h"
#include "CInventoryManager.h"

class CStoreSystem {
public:
	CStoreSystem();
	~CStoreSystem();

	void enter();

	void buySkill();
private:
	CInventoryManager m_inventoryManager;
};