/*
 * TestRecovery.cpp
 *
 *  Created on: Jul 16, 2017
 *      Author: SimoAngelov
 */

#include "TestRecovery.h"

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

void TestRecovery::Test()
{
	cout << "Welcome to the test recovery program :P" << endl;
	bool bQuit = false;
	while(!bQuit)
	{
		cout << "1 - Create blank save" << endl;
		cout << "2 - Update the view" << endl;
		cout << "3 - Update the volume" << endl;
		cout << "Default - exit" << endl;
		int iChoice = 0;
		cin >> iChoice;
		switch(iChoice)
		{
		case 1: TestRecovery::TestBlankSave(); break;
		case 2: TestRecovery::TestViewUpdate(); break;
		case 3: TestRecovery::TestVolumeUpdate(); break;
		default: bQuit = true; break;
		}
	}
}

TestRecovery::~TestRecovery()
{
	// TODO Auto-generated destructor stub
}

