#include "pch.h"
#include "../OPP_RPG/CDungeon.h"
#include "../OPP_RPG/CVillage.h"

#include <iostream>
using namespace std;

TEST(create_player_case, create_player_type_rock_test) {
	CPlayer  hero(MatchUpType::ROCK, 100, 60);

	EXPECT_EQ(hero.getType(), MatchUpType::ROCK);
}

TEST(create_player_case, create_player_HP_100_test) {
	CPlayer  hero(MatchUpType::ROCK, 100, 60);

	EXPECT_EQ(hero.getHp(), 100);
}

TEST(create_player_case, create_player_power_60_test) {
	CPlayer  hero(MatchUpType::ROCK, 100, 60);

	EXPECT_EQ(hero.getPower(), 60);
}

TEST(create_player_case, create_player_exp_init_test) {
	CPlayer hero(MatchUpType::ROCK, 100, 60);

	EXPECT_EQ(hero.getExp(), 0);
}

TEST(set_player_job_case, set_player_job_healer_test) {

	CPlayer  hero(MatchUpType::ROCK, 100, 60);
	hero.setJobData({ "healer" });

	EXPECT_EQ(hero.getJobData().m_name, "healer");
}

TEST(create_monster_case, create_monster_HP_100_test) {
	CPlayer  hero(MatchUpType::ROCK, 100, 60);
	hero.setJobData({ "healer" });

	CDungeon dungeon(hero);

	CMonster monster;
	monster = dungeon.createMonster();

	EXPECT_EQ(monster.getHp(), 100);
}

TEST(match_up_case, match_up_paper_boss_monster) {
	CPlayer  hero(MatchUpType::ROCK, 100, 60);
	hero.setJobData({ "healer" });

	CDungeon dungeon(hero);

	CMonster monster(MatchUpType::PAPER, 100, 100);

	CMatchUpSystem matchUpSystem(hero, monster);
	CDataListManager dataListManager;
	matchUpSystem.matchUp();

	EXPECT_FALSE(hero.isAlive());
}

TEST(match_up_case, match_up_scissors_weak_monster) {
	CPlayer  hero(MatchUpType::ROCK, 100, 100);
	hero.setJobData({ "dealer" });

	CDungeon dungeon(hero);

	CMonster monster(MatchUpType::SCISSORS, 100, 0);

	CMatchUpSystem matchUpSystem(hero, monster);
	CDataListManager dataListManager;
	matchUpSystem.matchUp();

	EXPECT_FALSE(monster.isAlive());
}

TEST(match_up_case, match_up_rock_simmillar_monster) {
	CPlayer  hero(MatchUpType::ROCK, 100, 60);
	hero.setJobData({ "dealer" });

	CDungeon dungeon(hero);

	CMonster monster(MatchUpType::ROCK, 100, 60);

	CMatchUpSystem matchUpSystem(hero, monster);
	CDataListManager dataListManager;
	matchUpSystem.matchUp();

	EXPECT_FALSE(monster.isAlive());
}

TEST(match_up_exp_case, match_up_exp_50) {
	CPlayer  hero(MatchUpType::ROCK, 100, 60);
	hero.setJobData({ "healer" });

	CDungeon dungeon(hero);

	CMonster monster(MatchUpType::ROCK, 100, 50);

	CMatchUpSystem matchUpSystem(hero, monster);
	CDataListManager dataListManager;
	CExpSystem expSystem(hero, monster);

	matchUpSystem.matchUp();

	if (!monster.isAlive()) {
		expSystem.rewardExp();
	}

	EXPECT_EQ(hero.getExp(), 50);
}

TEST(buy_skill_case, buy_first_skill_check_name) {
	CPlayer  hero(MatchUpType::ROCK, 100, 60);
	hero.setJobData({ "healer" });

	int idx = 0;

	CDataListManager dataListManager;
	skillData tmp = dataListManager.getSkillData(idx);

	hero.addSkillData(tmp);
	EXPECT_EQ(hero.getSkill()[idx].m_name, tmp.m_name);
}