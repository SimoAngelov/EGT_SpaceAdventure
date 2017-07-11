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
class TestGameController
{
private:
	GameController m_gameController;
public:
	TestGameController();
	virtual ~TestGameController();
	void TestCreditInsert();
	void TestBetIncrement();
	void TestLineIncrement();
	void TestMaxBet();
	void TestSpin();

	void TestGame();
};

#endif /* TESTGAMECONTROLLER_H_ */
