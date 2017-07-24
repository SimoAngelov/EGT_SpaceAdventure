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
	//if the player hasn't quit the bonus game
	if (!BonusGame::IsQuitBonusGame())
	{
		cout << endl;
		cout << "Gamble amount: " << BonusGame::GambleAmount().c_str() << endl;
		cout << "Gamble to win: " << BonusGame::GambleToWin().c_str() << endl;
		cout << "TestBonusGame::1 - Play" << endl;
		cout << "TestBonusGame::2 - Quit" << endl;
		int iChoice = 0;
		cin >> iChoice;
		switch (iChoice)
		{
		case 1:
			cout << "TestBonusGame::1 - select Black Card" << endl;
			cout << "TestBonusGame::2 - select Black Card" << endl;
			cin >> iChoice;
			switch (iChoice)
			{
			case 1:
				BonusGame::PlayerSelectedBlack();
				break;
			case 2:
				BonusGame::PlayerSelectedRed();
				break;
			}

			cout << "TestBonusGame::Current Credits: "
					<< TestGameController::m_gameController.GetCredits()
					<< endl;

			if (!win)
				BonusGame::PlayBonusRound();
			else
				BonusGame::WinBonusRound();

			cout << "TestBonusGame::New Win: "
					<< TestGameController::m_gameController.GetWin() << endl;
			cout << "TestBonusGame::New Credits: "
					<< TestGameController::m_gameController.GetCredits()
					<< endl;
			break;
		case 2:
			BonusGame::QuitBonusGame();
			break;
		}
	}
}

void TestBonusGame::TestWinRound()
{
	cout << "TestBonusGame::Welcome to bonus round " << endl;
	TestBonusGame::Round(true);
}

void TestBonusGame::TestRound()
{
	cout << "TestBonusGame::Welcome to bonus round " << endl;
	TestBonusGame::Round(false);

}

void TestBonusGame::Quit()
{
	BonusGame::QuitBonusGame();
}

void TestBonusGame::PlayBonusGame()
{
	cout << "TestBonusGame::Welcome to the bonus game.\n";
	cout << "TestBonusGame::1 - Play Round " << endl;
	cout << "TestBonusGame::XP 2 - Play winning round " << endl;
	cout << "TestBonusGame::Default - Quit " << endl;
	int iChoice = 0;
	cin >> iChoice;
	switch (iChoice)
	{
	case 1:
		TestBonusGame::TestRound();
		break;
	case 2:
		TestBonusGame::TestWinRound();
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

