/*
 * TestGameController.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: SimoAngelov
 */

#include "TestGameController.h"

GameController TestGameController::m_gameController;
TestGameController::TestGameController()
{
	// TODO Auto-generated constructor stub

}

TestGameController::~TestGameController()
{
	// TODO Auto-generated destructor stub
}

void TestGameController::TestNewGame()
{
	cout << "TestGameController::New Game" << endl;
	m_gameController.NewGame();
}

void TestGameController::TestLoadGame()
{
	cout << "TestGameController::Load game" << endl;
	m_gameController.LoadGame();
}

void TestGameController::TestBetIncrement()
{
	cout << "Current Credits:\t" << m_gameController.GetCredits() << endl;
	cout << "Current bet per line:\t" << m_gameController.GetBetPerLine()
			<< endl;
	cout << "Total Bet:\t" << m_gameController.GetTotalBet() << endl;
	bool bQuit = false;
	while (!bQuit)
	{
		cout << "Press 1 to decrease and 2 to increase bet per line" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			m_gameController.DecreaseBet();
			break;
		case 2:
			m_gameController.IncreaseBet();
			break;
		default:
			bQuit = true;
			break;
		}
		cout << "Current bet per line:\t" << m_gameController.GetBetPerLine()
				<< endl;
		cout << "Total Bet(current):\t" << m_gameController.GetTotalBet()
				<< endl;
		cout << "Current Credits: " << m_gameController.GetCredits() << endl;

	}
}

void TestGameController::TestLineIncrement()
{
	cout << "Current Credits:\t" << m_gameController.GetCredits() << endl;
	cout << "Current number of lines:\t" << m_gameController.GetNumberOfLines()
			<< endl;
	cout << "Total Bet:\t" << m_gameController.GetTotalBet() << endl;
	bool bQuit = false;
	while (!bQuit)
	{
		cout << "Press 1 to decrease and 2 to increase the number of lines"
				<< endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			m_gameController.DecreasePaylines();
			break;
		case 2:
			m_gameController.IncreasePaylines();
			break;
		default:
			bQuit = true;
			break;
		}
		cout << "Current Lines: " << m_gameController.GetNumberOfLines()
				<< endl;
		cout << "Current total bet: " << m_gameController.GetTotalBet() << endl;
		cout << "Current Credits: " << m_gameController.GetCredits() << endl;

	}
}

void TestGameController::TestMaxBet()
{
	cout << "totalBet before MaxSpin: " << m_gameController.GetTotalBet()
			<< endl;
	m_gameController.MaxBet();
	cout << "totalBet after MaxSpin: " << m_gameController.GetTotalBet()
			<< endl;
}

void TestGameController::TestSpin()
{
	if (!(m_gameController.TotalBetExceedsCredits()))
	{
		cout << "Old Total Bet: " << m_gameController.GetTotalBet() << endl;
		cout << "Old Credits: " << m_gameController.GetCredits() << endl;
		cout << "Old Win: " << m_gameController.GetWin() << endl;
		m_gameController.Spin();

		m_gameController.PrintReels();
		cout << endl;
		cout << "New Total Bet: " << m_gameController.GetTotalBet() << endl;
		cout << "New Credits: " << m_gameController.GetCredits() << endl;
		cout << "New Win: " << m_gameController.GetWin() << endl;
		while (m_gameController.IsBonusGame())
		{
			cout << "THIS IS A BONUS GAME";
			TestBonusGame::PlayBonusGame();
			if (BonusGame::IsQuitBonusGame())
				break;
		}
		//update credits and win
		m_gameController.LoadGame();
		cout << "Bonus Total Bet: " << m_gameController.GetTotalBet() << endl;
		cout << "Bonus New Credits: " << m_gameController.GetCredits() << endl;
		cout << "Bonus New Win: " << m_gameController.GetWin() << endl;
	}
}

void TestGameController::PrintInfo()
{
	m_gameController.PrintInfo();
}





void TestGameController::InitTest()
{
	cout << "Welcome to testing the game controller :P" << endl;
	bool bQuit = false;

	cout << "\n1 - New Game" << endl;
	cout << "2 - Load Game" << endl;
	int iChoice = 0;
	cin >> iChoice;
	switch (iChoice)
	{
	case 1:
		TestNewGame();
		break;
	case 2:
		TestLoadGame();
		break;
	}
	while (!bQuit)
	{
		cout << "3 - Toggle Bet per Line" << endl;
		cout << "4 - Toggle number of paylines" << endl;
		cout << "5 - Toggle max bet" << endl;
		cout << "6 - Test spin" << endl;
		cout << "7 - Print GameCOntroller info\n" << endl;
		cout << "8 - Test SetNullCredits: " << endl;
		cin >> iChoice;
		switch (iChoice)
		{
		case 1:
			TestNewGame();
			break;
		case 2:
			TestLoadGame();
			break;
		case 3:
			TestBetIncrement();
			break;
		case 4:
			TestLineIncrement();
			break;
		case 5:
			TestMaxBet();
			break;
		case 6:
			TestSpin();
			break;
		case 7:
			PrintInfo();
			break;
		case 8:
			cout << "Before SetCreditsNUll " << m_gameController.GetCredits()
			<< endl;
			m_gameController.SetNullCredits();
			cout << "After SetCreditsNUll " << m_gameController.GetCredits()
						<< endl;
			break;
		default:
			bQuit = true;
			break;
		}
	}
}
