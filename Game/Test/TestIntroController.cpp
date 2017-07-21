/*
 * TestIntroController.cpp
 *
 *  Created on: Jul 21, 2017
 *      Author: SimoAngelov
 */

#include "TestIntroController.h"
#include <iostream>
using std::cin;
TestIntroController::TestIntroController()
{
	// TODO Auto-generated constructor stub

}

void TestIntroController::TestInsertCredtits()
{
	cout << "Welcome to SpaceAdventure-> Please insertCredits";
	cout << "Current Credits:\t";
	IntroController::PrintInfo();
	bool bQuit = false;
	while(!bQuit)
	{
		cout << "Press 1 to decrease and 2 to increase";
		int choice;
		cin >> choice;
		switch(choice)
		{
		case 1:
			IntroController::DecreaseCredits();
			break;
		case 2:
			IntroController::IncreaseCredits();
			break;
		default:
			bQuit = true;
			IntroController::SaveCredits();
			break;
		}
		cout << "Current Credits: ";
		IntroController::PrintInfo();
	}
}

void TestIntroController::TestGameController()
{
	TestGameController::InitTest();
}

void TestIntroController::InitTest()
{
	bool bQuit = false;
	IntroController::PlayNewGame();
	while(!bQuit)
	{
		cout << "1 - Insert Credits" << endl;
		cout << "2 - Play Game" << endl;
		int iChoice = 0;
		cin >> iChoice;
		switch(iChoice)
		{
		case 1: TestIntroController::TestInsertCredtits(); break;
		case 2: TestIntroController::TestGameController(); break;
		default: bQuit = true; break;
		}
	}
	IntroController::SaveCredits();
}
TestIntroController::~TestIntroController()
{
	// TODO Auto-generated destructor stub
}

