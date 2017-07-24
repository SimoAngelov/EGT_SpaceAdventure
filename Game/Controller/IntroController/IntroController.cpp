/*
 * IntroController.cpp
 *
 *  Created on: Jul 21, 2017
 *      Author: SimoAngelov
 */

#include "IntroController.h"

//member field to hold the credits for the intro screen
int IntroController::m_iCredits = 0;

IntroController::IntroController()
{
	// TODO Auto-generated constructor stub
}

//create a blank xml save
void IntroController::PlayNewGame()
{
	GameRecovery::CreateBlankSave();
}

//increase the credits by 10 000 each time the method is called
void IntroController::IncreaseCredits()
{
	//increment the existing credits by 10000
	int iNewCredits = IntroController::m_iCredits + CREDIT_STEP;
	//check to make sure the new amount doesn't exceed the max value
	if (iNewCredits <= MAX_CREDITS)
	{
		IntroController::m_iCredits = iNewCredits;
	} // end if
}

//decrease the credits by 10 000 each time the method is called
void IntroController::DecreaseCredits()
{
	//decrement the existing credits by 10000
	int iNewCredits = IntroController::m_iCredits - CREDIT_STEP;
	//check to make sure the new amount doesn't go below the min amount
	if (iNewCredits >= MIN_CREDITS)
	{
		IntroController::m_iCredits = iNewCredits;
	}
}

//save the credits to xml
void IntroController::SaveCredits()
{
	GameRecovery::UpdateCredits(IntroController::m_iCredits);
}

//print
void IntroController::PrintInfo()
{
	cout << "IntroController::Credits: " << IntroController::m_iCredits << endl;
}

IntroController::~IntroController()
{
	// TODO Auto-generated destructor stub
}

