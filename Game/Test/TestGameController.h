/*
 * TestGameController.h
 *
 *  Created on: Jul 9, 2017
 *      Author: SimoAngelov
 */

#ifndef TESTGAMECONTROLLER_H_
#define TESTGAMECONTROLLER_H_
#include <iostream>
using std::cin;
#include "..\Controller\GameController\GameController.h"
#include "TestBonusGame.h"
class TestGameController
{
	friend class TestBonusGame;
private:
	static GameController m_gameController;
public:
	TestGameController();
	virtual ~TestGameController();
	static void TestCreditInsert();
	static void TestBetIncrement();
	static void TestLineIncrement();
	static void TestMaxBet();
	static void TestSpin();
	void TestGame();
};

#endif /* TESTGAMECONTROLLER_H_ */
