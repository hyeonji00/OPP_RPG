#pragma once
#include <random>
#include <windows.h>

class CUtils {
public:
	CUtils();
	~CUtils();

	static int getRandomInt(int min, int max);
};