//============================================================================
// Name        : LineTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Test\TestGameController.h"
#include "Controller\GameRecovery\GameRecovery.h"
using namespace std;

int main() {
	//TestGameController testGame;
	//testGame.TestGame();
	GameRecovery ob;
	ob.CreateBlankSave();
	return 0;
}
