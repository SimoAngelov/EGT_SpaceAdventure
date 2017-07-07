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
	cout << "EnterCredits" << endl;
	int credits;
	cin >> credits;
	game.InsertCredits(credits);
	cout << "Enter Number Of Lines: " << endl;
	int numberOfLines;
	cin >> numberOfLines;
	game.SetNumberOfPaylines(numberOfLines);
	cout << "set steps for bet" << endl;
	int step;
	cin >> step;
	game.SetBetPerPayline(step);

	game.Spin();
//	game.InitCurrentReels();
//	//game.InitCurrentPayLines();
//	game.InitCurrentPaylines();
	game.PrintReels();
	cout << endl;
	game.PrintPaylines();
	cout << endl;
	game.WinFromPaylines();
	return 0;
}
