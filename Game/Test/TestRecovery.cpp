/*
 * TestRecovery.cpp
 *
 *  Created on: Jul 16, 2017
 *      Author: SimoAngelov
 */

#include "TestRecovery.h"
#include <iostream>
using std::cin;
TestRecovery::TestRecovery()
{
	// TODO Auto-generated constructor stub

}

void TestRecovery::TestBlankSave()
{
	m_gameSave.CreateBlankSave();
}

void TestRecovery::TestViewUpdate()
{
	cout << "Enter a value to update the view" << endl;
	int val;
	cin >> val;
	m_gameSave.UpdateView(val);


}

void TestRecovery::TestVolumeUpdate()
{
	cout << "Enter a value to update the volume" << endl;
	int val;
	cin >> val;
	m_gameSave.UpdateVolume(val);
}

void TestRecovery::TestNumberOfLinesUpdate()
{
	cout << "Enter a value to update the payline number" << endl;
	int val;
	cin >> val;
	m_gameSave.UpdateNumberOfPaylines(val);
}

void TestRecovery::TestBetPerLineUpdate()
{
	cout << "Enter a value to update the bet per payline" << endl;
	int val;
	cin >> val;
	m_gameSave.UpdateBetPerPayline(val);
}

void TestRecovery::TestTotalBetUpdate()
{
	cout << "Enter a value to update the total bet" << endl;
	int val;
	cin >> val;
	m_gameSave.UpdateTotalBet(val);
}
void TestRecovery::TestCreditsUpdate()
{
	cout << "Enter a value to update the credits" << endl;
	int val;
	cin >> val;
	m_gameSave.UpdateCredits(val);
}

void TestRecovery::TestWinUpdate()
{
	cout << "Enter a value to update the win" << endl;
	int val;
	cin >> val;
//	m_gameSave.UpdateWin(val);
	GameRecovery::UpdateWin(val);
}

void TestRecovery::Test()
{
	cout << "Welcome to the test recovery program :P" << endl;
	bool bQuit = false;
	while(!bQuit)
	{
		cout << "1 - Create blank save" << endl;
		cout << "2 - Update the view" << endl;
		cout << "3 - Update the volume" << endl;
		cout << "4 - Update number of lines" << endl;
		cout << "5 - Update bet per line" << endl;
		cout << "6 - Update total bet" << endl;
		cout << "7 - Update win" << endl;
		cout << "8 - Update credits" << endl;
		cout << "Default - exit" << endl;
		int iChoice = 0;
		cin >> iChoice;
		switch(iChoice)
		{
		case 1: TestRecovery::TestBlankSave(); break;
		case 2: TestRecovery::TestViewUpdate(); break;
		case 3: TestRecovery::TestVolumeUpdate(); break;
		case 4: TestRecovery::TestNumberOfLinesUpdate(); break;
		case 5: TestRecovery::TestBetPerLineUpdate(); break;
		case 6: TestRecovery::TestTotalBetUpdate(); break;
		case 7: TestRecovery::TestWinUpdate(); break;
		case 8: TestRecovery::TestCreditsUpdate(); break;
		default: bQuit = true; break;
		}
	}
}

TestRecovery::~TestRecovery()
{
	// TODO Auto-generated destructor stub
}

