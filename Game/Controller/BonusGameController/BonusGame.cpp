/*
 * BonusGame.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: SimoAngelov
 */

#include "BonusGame.h"

//member field to increment the seed additionally each time srand is called
int BonusGame::m_iRandCounter = 0;

//member field to hold the credits from the game controller
int BonusGame::m_iCredits = 0;

//member field to hold the bet for the bonus game
int BonusGame::m_iBet = 0;

//member field to hold the current win from the game
int BonusGame::m_iGameWin = 0;

//member field to hold the win from the bonus game
int BonusGame::m_iBonusWin = 0;

//member field to keep track of the rounds. index[0] corresponds to round 1
// index[1] corresponds to round2
bool BonusGame::m_bIsRound[eNUM_ROUNDS] = {false};

//member field to keep track if the player wants to quit the bonus round
bool BonusGame::m_bQuitBonusGame = false;

BonusGame::BonusGame():
		m_playerChoice(eInvalidColor),
		m_bonusGameResult(eInvalidColor)
{
	// TODO Auto-generated constructor stub
}

//check if there is a bonus game
bool BonusGame::IsBonusGame(int iBonusCounter)
{
	return iBonusCounter == BONUS_GAME;
}

//initialize the member fields
void BonusGame::InitBonusGame(int iWin, int iCredits)
{
	//store the value of the current game win
	BonusGame::m_iGameWin = iWin;
	//the initial bonus win is zero
	BonusGame::m_iBonusWin = 0;
	//the bet is the current win from the paylines from the game controller
	BonusGame::m_iBet = iWin;
	//take the credits from the game controller
	BonusGame::m_iCredits = iCredits;
	//set the bool values from round 1 and round 2 to false
	BonusGame::m_bIsRound[eNUM_ROUNDS] = {false};
}

//return the bonus win
int BonusGame::GetBonusWin()
{
	return BonusGame::m_iBonusWin;
}



//set the result from the card draw
void BonusGame::SetBonusGameResult()
{
	srand(time(0) + (BonusGame::m_iRandCounter++));
	this->m_bonusGameResult = static_cast<COLOR>(rand()% eNUM_COLORS);
}

//update the member fields in case of a win
void BonusGame::UpdateIfWin()
{
	//double the win from the bonus game
	BonusGame::m_iBonusWin = 2 * BonusGame::m_iBet;
	//update the credits
	BonusGame::m_iCredits += BonusGame::m_iBonusWin;
	//update the game win
	BonusGame::m_iGameWin = BonusGame::m_iBonusWin;
}

//update the member fields in case of a loss
void BonusGame::UpdateIfLoss()
{
	//set the win from the bonus game to 0
	BonusGame::m_iBonusWin = 0;
	//update the credits
	BonusGame::m_iCredits += BonusGame::m_iBonusWin;
	//update the game win
	BonusGame::m_iGameWin = BonusGame::m_iBonusWin;
}

void BonusGame::PlayerSelectedBlack()
{
	this->m_playerChoice = eBlack;
	//initialize round 1
	this->m_bIsRound[eRound1] = true;
}

void BonusGame::PlayerSelectedRed()
{
	this->m_playerChoice = eRed;
	//initialize round 1
	this->m_bIsRound[eRound1] = true;
}

bool BonusGame::PlayerWon() const
{
	bool bWinCondition1 = this->m_playerChoice == this->m_bonusGameResult;
	bool bWinCondition2 = this->m_bonusGameResult != eInvalidColor;
	return bWinCondition1 && bWinCondition2;
}





void BonusGame::PlayBonusRound()
{
	//if round 1
	if(BonusGame::m_bIsRound[eRound1])
	{
		//take the bet from the credits
		BonusGame::m_iCredits -= BonusGame::m_iBet;
		//if the player won
		if(this->PlayerWon())
		{
			//update the win and credits
			BonusGame::UpdateIfWin();
			//set the flag for round 2
			BonusGame::m_bIsRound[eRound2] = true;
		}//end if player won round 1
		else {
			//update the win and credits
			BonusGame::UpdateIfLoss();
			//set the flag for round 2
			BonusGame::m_bIsRound[eRound2] = false;
		} // end if player lost round 1

		//TODO save the win and credits to XML

	} // end if round 1
	//if round 2
	if(BonusGame::m_bIsRound[eRound2])
	{
		//update the bet with the win from the previous round
		BonusGame::m_iBet = BonusGame::m_iBonusWin;
		//subtract the bet from the credits
		BonusGame::m_iCredits -= BonusGame::m_iBet;
		//check if the player won
		if(this->PlayerWon())
		{
			//update the win and credits
			BonusGame::UpdateIfWin();
		} else
		{
			//update the win and credits
			BonusGame::UpdateIfLoss();
		}//end if player lost round 2
		//TODO save the win and credits to XML
		//set the flags to false
		BonusGame::m_bIsRound[eNUM_ROUNDS] = {false};
	}//end if round 2

}

//return the status of the quit member field
bool BonusGame::IsQuitBonusGame()
{
	return BonusGame::m_bQuitBonusGame;
}

//quit the bonus game
void BonusGame::QuitBonusGame()
{
	BonusGame::m_bQuitBonusGame = true;
}

BonusGame::~BonusGame()
{
	// TODO Auto-generated destructor stub
}

