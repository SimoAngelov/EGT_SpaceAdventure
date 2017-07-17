//============================================================================
// Name        : LineTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Test\TestGameController.h"
#include "Test\TestRecovery.h"
#include "Controller\GameRecovery\GameRecovery.h"

using namespace std;

int main() {
	TestGameController testGame;
	testGame.TestGame();
////	GameRecovery ob;
////	ob.CreateBlankSave();
//    TestRecovery::Test();
	return 0;
}
