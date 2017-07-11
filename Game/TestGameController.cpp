/*
 * TestGameController.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: SimoAngelov
 */

#include "TestGameController.h"

TestGameController::TestGameController():
	m_gameController()
{
	// TODO Auto-generated constructor stub

}

TestGameController::~TestGameController()
{
	// TODO Auto-generated destructor stub
}

void TestGameController::TestCreditInsert()
{
	cout << "Welcome to SpaceAdventure-> Please insertCredits";
	cout << "Current Credits:\t" << this->m_gameController.GetCredits() << endl;
	bool bQuit = false;
	while(!bQuit)
	{
		cout << "Press 1 to decrease and 2 to increase";
		int choice;
		cin >> choice;
		switch(choice)
		{
		case 1:
			this->m_gameController.DecreaseCredits();
			break;
		case 2:
			this->m_gameController.IncreaseCredits();
			break;
		default:
			bQuit = true;
			break;
		}
		cout << "Current Credits: " << this->m_gameController.GetCredits() << endl;

	}

}

void TestGameController::TestBetIncrement()
{
	cout << "Current Credits:\t" << this->m_gameController.GetCredits() << endl;
	cout << "Current bet per line:\t"
			<< this->m_gameController.GetBetPerLine() << endl;
	cout << "Total Bet:\t" << this->m_gameController.GetTotalBet() << endl;
		bool bQuit = false;
		while(!bQuit)
		{
			cout << "Press 1 to decrease and 2 to increase bet per line" << endl;
			int choice;
			cin >> choice;
			switch(choice)
			{
			case 1:
				this->m_gameController.DecreaseBet();
				break;
			case 2:
				this->m_gameController.IncreaseBet();
				break;
			default:
				bQuit = true;
				break;
			}
			cout << "Current bet per line:\t"
					<< this->m_gameController.GetBetPerLine() << endl;
			cout << "Total Bet(current):\t" << this->m_gameController.GetTotalBet() << endl;
			cout << "Current Credits: " << this->m_gameController.GetCredits() << endl;

		}
}

void TestGameController::TestLineIncrement()
{
	cout << "Current Credits:\t" << this->m_gameController.GetCredits() << endl;
	cout << "Current number of lines:\t"
			<< this->m_gameController.GetNumberOfLines() << endl;
	cout << "Total Bet:\t" << this->m_gameController.GetTotalBet() << endl;
		bool bQuit = false;
		while(!bQuit)
		{
			cout << "Press 1 to decrease and 2 to increase the number of lines" << endl;
			int choice;
			cin >> choice;
			switch(choice)
			{
			case 1:
				this->m_gameController.DecreasePaylines();
				break;
			case 2:
				this->m_gameController.IncreasePaylines();
				break;
			default:
				bQuit = true;
				break;
			}
			cout << "Current Lines: " << this->m_gameController.GetNumberOfLines()
					<< endl;
			cout << "Current total bet: " << this->m_gameController.GetTotalBet()
				<< endl;
			cout << "Current Credits: " << this->m_gameController.GetCredits()
					<< endl;

		}
}

void TestGameController::TestSpin()
{
	if(!(this->m_gameController.TotalBetExceedsCredits()))
	{
	this->m_gameController.Spin();
	this->m_gameController.PrintReels();
	cout << endl;
	this->m_gameController.PrintPaylines();
	cout << "Total Bet: " << this->m_gameController.GetTotalBet() << endl;
	cout << "Credits: " << this->m_gameController.GetCredits() << endl;
	cout << "Win: " << this->m_gameController.GetWin() << endl;
	}
}

void TestGameController::TestGame()
{

	bool bQuit = false;
	while(!bQuit)
	{
		cout << "\n1 - Insert Credits" << endl;
			cout << "2 - Toggle Bet per Line" << endl;
			cout << "3 - Toggle number of paylines" << endl;
			cout << "4 - Print reels\n" << endl;
			int iChoice = 0;
			cin >> iChoice;
			switch(iChoice)
			{
			case 1: this->TestCreditInsert(); break;
			case 2: this->TestBetIncrement(); break;
			case 3: this->TestLineIncrement(); break;
			case 4: this->TestSpin(); break;
			default: bQuit = true; break;
			}
	}
}
