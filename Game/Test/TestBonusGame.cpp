/*
 * TestBonusGame.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: SimoAngelov
 */

#include "TestBonusGame.h"
#include <iostream>
using std::endl;
using std::cout;
using std::cin;

TestBonusGame::TestBonusGame()
{
	// TODO Auto-generated constructor stub

}

void TestBonusGame::Round(bool win)
{
	cout << endl;
	cout << "TestBonusGame::1 - Play" << endl;
	cout << "TestBonusGame::2 - Quit" << endl;
	int iChoice = 0;
	cin >> iChoice;
	switch(iChoice)
	{
	case 1:
		cout << "TestBonusGame::1 - select Black Card" << endl;
		cout << "TestBonusGame::2 - select Black Card" << endl;
		cin >> iChoice;
		switch(iChoice)
		{
		case 1: BonusGame::PlayerSelectedBlack(); break;
		case 2: BonusGame::PlayerSelectedRed(); break;
		}
		cout << "TestBonusGame::Current Win: " <<
					TestGameController::m_gameController.GetWin() << endl;
			cout << "TestBonusGame::Current Credits: " <<
					TestGameController::m_gameController.GetCredits() << endl;

			if(!win)BonusGame::PlayBonusRound();
			else BonusGame::WinBonusRound();

			cout << "TestBonusGame::New Win: " <<
						TestGameController::m_gameController.GetWin() << endl;
				cout << "TestBonusGame::New Credits: " <<
						TestGameController::m_gameController.GetCredits() << endl;
		break;
		case 2:
			BonusGame::QuitBonusGame();
			break;
	}
}

void TestBonusGame::TestWinRound1()
{
	cout << "TestBonusGame::Welcome to round 1 " << endl;
	TestBonusGame::Round(true);
}

void TestBonusGame::TestWinRound2()
{
	cout << "TestBonusGame::Welcome to round 2 " << endl;
	TestBonusGame::Round(true);
}

void TestBonusGame::TestRound1()
{
	cout << "TestBonusGame::Welcome to round 1 " << endl;
	TestBonusGame::Round(false);

}

void TestBonusGame::TestRound2()
{
	cout << "TestBonusGame::Welcome to round 2 of the bonus game" << endl;
	TestBonusGame::Round(false);
}

void TestBonusGame::Quit()
{
	BonusGame::QuitBonusGame();
}

void TestBonusGame::PlayBonusGame()
{
	cout << "TestBonusGame::Welcome to the bonus game.\n";
	cout << "TestBonusGame::1 - Play Round 1" << endl;
	cout << "TestBonusGame::XP 2 - Play winning round 1" << endl;
	cout << "TestBonusGame::3 - Play Round 2" << endl;
	cout << "TestBonusGame::XP 4 - Play winning round 2" << endl;
	cout << "TestBonusGame::Default - Quit " << endl;
	int iChoice = 0;
	cin >> iChoice;
	switch(iChoice){
	case 1:
		TestBonusGame::TestRound1();
		break;
	case 2:
		TestBonusGame::TestWinRound1();
		break;
	case 3:
		TestBonusGame::TestRound2();
		break;
	case 4:
		TestBonusGame::TestWinRound2();
		break;
	default:
		TestBonusGame::Quit();
		break;
	}
}

TestBonusGame::~TestBonusGame()
{
	// TODO Auto-generated destructor stub
}

