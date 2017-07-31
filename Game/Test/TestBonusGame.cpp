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

void TestBonusGame::Round()
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
			cout << "TestBonusGame::2 - select Red Card" << endl;
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

			BonusGame::PlayBonusRound();

			break;
		case 2:
			BonusGame::QuitBonusGame();
			break;
		}
	}
}


void TestBonusGame::TestRound()
{
	cout << "TestBonusGame::Welcome to bonus round " << endl;
	if(BonusGame::IsValidRound())
	TestBonusGame::Round();
	else cout << "Not a valid round" << endl;
}

void TestBonusGame::Quit()
{
	BonusGame::QuitBonusGame();
}

void TestBonusGame::PlayBonusGame()
{
	cout << "TestBonusGame::Welcome to the bonus game.\n";
	cout << "TestBonusGame::1 - Play Round " << endl;
	cout << "TestBonusGame::Default - Quit " << endl;
	int iChoice = 0;
	cin >> iChoice;
	switch (iChoice)
	{
	case 1:

		TestBonusGame::TestRound();

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

