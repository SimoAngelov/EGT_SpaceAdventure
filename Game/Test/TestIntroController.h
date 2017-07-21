/*
 * TestIntroController.h
 *
 *  Created on: Jul 21, 2017
 *      Author: SimoAngelov
 */

#ifndef SRC_TEST_TESTINTROCONTROLLER_H_
#define SRC_TEST_TESTINTROCONTROLLER_H_

#include "../Controller/IntroController/IntroController.h"
#include "TestGameController.h"

class TestIntroController
{
public:
	TestIntroController();
	static void TestInsertCredtits();
	static void TestGameController();
	static void InitTest();
	virtual ~TestIntroController();
};

#endif /* SRC_TEST_TESTINTROCONTROLLER_H_ */
