//============================================================================
// Name        : LineTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "GameController.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	GameController game;
	game.InitCurrentReels();
	game.InitCurrentPayLines();
	game.PrintReels();
	cout << endl;
	game.PrintPaylines();
	return 0;
}
