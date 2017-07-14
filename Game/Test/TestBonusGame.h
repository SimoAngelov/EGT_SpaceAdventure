/*
 * TestBonusGame.h
 *
 *  Created on: Jul 13, 2017
 *      Author: SimoAngelov
 */


#ifndef TEST_TESTBONUSGAME_H_
#define TEST_TESTBONUSGAME_H_
#include "../Controller/BonusGameController/BonusGame.h"
#include "TestGameController.h"
class TestBonusGame
{
public:
	TestBonusGame();
	static void Round(bool );
	static void TestWinRound1();
	static void TestWinRound2();
	static void TestRound1();
	static void TestRound2();
	static void Quit();
	static void PlayBonusGame();
	virtual ~TestBonusGame();
};

#endif /* TEST_TESTBONUSGAME_H_ */
