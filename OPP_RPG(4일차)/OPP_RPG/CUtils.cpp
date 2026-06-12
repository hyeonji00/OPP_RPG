#include "CUtils.h"

CUtils::CUtils() {

}

CUtils::~CUtils() {

}

int CUtils::getRandomInt(int min, int max) {
	static std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}
