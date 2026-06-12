#pragma once

enum class MatchUpType {ROCK=0, SCISSORS, PAPER};

class CCommonCharacter {
public:
	CCommonCharacter();
	CCommonCharacter(MatchUpType type, int hp, int power);
	~CCommonCharacter();

	virtual int getItemOffensivePower() = 0;
	virtual int getItemDefensivePower() = 0;

	bool isAlive();

	void takeDamage(int damage);
	void resetHp();
	void chargeHp(int hp);

	MatchUpType getType() { return m_type; };
	int getHp() { return m_hp; };
	int getPower() { return m_power; };

private:
	MatchUpType m_type;
	int m_hp;
	int m_power;
};