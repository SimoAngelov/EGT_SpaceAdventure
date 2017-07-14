/*
 * BonusGame.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: SimoAngelov
 */

#include "BonusGame.h"

//member field to increment the seed additionally each time srand is called
int BonusGame::m_iRandCounter = 0;

//member field that points to the game model field of the controller
GameModel* BonusGame::m_baseGamePtr = NULL;

//member field to keep track of the card the player has chosen
COLOR BonusGame::m_playerChoice = eInvalidColor;

//member field to keep track of the result from the current bonus round
COLOR BonusGame::m_bonusGameResult = eInvalidColor;

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
bool BonusGame::m_bIsRound[eNUM_ROUNDS] = {true, false};

//member field to keep track if the player wants to quit the bonus round
bool BonusGame::m_bQuitBonusGame = false;

BonusGame::BonusGame()
{
	// TODO Auto-generated constructor stub
}

//check if there is a bonus game
bool BonusGame::IsBonusGame(int iBonusCounter)
{
	return iBonusCounter == BONUS_GAME;
}

//initialize the member fields
void BonusGame::InitBonusGame(GameModel* gameModelPtr)
{
	//set the game model
	BonusGame::m_baseGamePtr = gameModelPtr;
	//store the value of the current game win
	BonusGame::m_iGameWin = m_baseGamePtr->GetIWin();
	//the initial bonus win is zero
	BonusGame::m_iBonusWin = 0;
	//the bet is the current win from the paylines from the game controller
	BonusGame::m_iBet = m_baseGamePtr->GetIWin();
	//take the credits from the game controller
	BonusGame::m_iCredits = m_baseGamePtr->GetICredits();
	//set the bool values from round 1 and round 2 to false
	BonusGame::m_bIsRound[eNUM_ROUNDS] =
	{	false};
	//set the quit game value to false
	BonusGame::m_bQuitBonusGame = false;
}

//return the bonus win
int BonusGame::GetWin()
{
	return BonusGame::m_iGameWin;
}

//set the result from the card draw
void BonusGame::SetBonusGameResult()
{
	srand(time(0) + (BonusGame::m_iRandCounter++));
	BonusGame::m_bonusGameResult = static_cast<COLOR>(rand() % eNUM_COLORS);
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
	BonusGame::m_playerChoice = eBlack;
}

void BonusGame::PlayerSelectedRed()
{
	BonusGame::m_playerChoice = eRed;

}

// check if the bet is valid
bool BonusGame::IsValidBet()
{
	return BonusGame::m_iCredits >= BonusGame::m_iBet;
}

bool BonusGame::PlayerWon()
{
	bool bWinCondition1 = BonusGame::m_playerChoice == BonusGame::m_bonusGameResult;
	bool bWinCondition2 = BonusGame::m_bonusGameResult != eInvalidColor;
	return bWinCondition1 && bWinCondition2;
}

//play round 1
void BonusGame::RoundOne()
{
	//if the bet is valid
	if(BonusGame::IsValidBet())
	{
		//take the bet from the credits
			BonusGame::m_iCredits -= BonusGame::m_iBet;
			//if the player won
			if (BonusGame::PlayerWon())
			{
				//test cout
				cout << "BonusGame::WON ROUND 1" << endl;
				//update the win and credits
				BonusGame::UpdateIfWin();
				//set the flag for round 2
				BonusGame::m_bIsRound[eRound2] = true;
			} //end if player won round 1
			else
			{
				//test cout
				cout << "BonusGame::LOST ROUND 1" << endl;
				//update the win and credits
				BonusGame::UpdateIfLoss();
				//set the flag for round 2
				BonusGame::m_bIsRound[eRound2] = false;
			} // end if player lost round 1
			//set the flag to round 1 to false
			BonusGame::m_bIsRound[eRound1] = false;
	}
}

//play round2
void BonusGame::RoundTwo()
{
	if(BonusGame::IsValidBet())
	{
		//update the bet with the win from the previous round
		BonusGame::m_iBet = BonusGame::m_iBonusWin;
		//subtract the bet from the credits
		BonusGame::m_iCredits -= BonusGame::m_iBet;
		//check if the player won
		if (BonusGame::PlayerWon())
		{
			//test cout
			cout << "BonusGame::WON ROUND 2" << endl;
			//update the win and credits
			BonusGame::UpdateIfWin();
		}
		else
		{
			//test cout
			cout << "BonusGame::LOST ROUND 2" << endl;
			//update the win and credits
			BonusGame::UpdateIfLoss();
		} //end if player lost round 2
		  //set the flags to false
		BonusGame::m_bIsRound[eNUM_ROUNDS] = {false};
	}
}

void BonusGame::PlayBonusRound()
{
	//set the bonusGame result
	BonusGame::SetBonusGameResult();
	//if round 1
	if (BonusGame::m_bIsRound[eRound1])
	{
		//test cout
		cout << "BonusGame::Playing Round 1" << endl;
		//play round1
		BonusGame::RoundOne();
		//update win and credits
		BonusGame::UpdateWinAndCredits();
		//TODO save the win and credits to XML
	} // end if round 1
	  //if round 2 and not round 1
	if (BonusGame::m_bIsRound[eRound2] &&
			!BonusGame::m_bIsRound[eRound1])
	{
		//test cout
		cout << "BonusGame::Playing Round 2" << endl;
		//play round 2
		BonusGame::RoundTwo();
		//update win and credits
		BonusGame::UpdateWinAndCredits();
		//TODO save the win and credits to XML
	}	//end if round 2
}

void BonusGame::WinBonusRound()
{
	//set the bonusGame result
	BonusGame::SetBonusGameResult();
	BonusGame::m_playerChoice = BonusGame::m_bonusGameResult;
	//if round 1
		if (BonusGame::m_bIsRound[eRound1])
		{
			//test cout
			cout << "BonusGame::Playing WINRound 1" << endl;
			//play round1
			BonusGame::RoundOne();
			//update win and credits
			BonusGame::UpdateWinAndCredits();
			//TODO save the win and credits to XML
		} // end if round 1
		  //if round 2 and not round 1
		if (BonusGame::m_bIsRound[eRound2] &&
				!BonusGame::m_bIsRound[eRound1])
		{
			//test cout
			cout << "BonusGame::Playing WINRound 2" << endl;
			//play round 2
			BonusGame::RoundTwo();
			//update win and credits
			BonusGame::UpdateWinAndCredits();
			//TODO save the win and credits to XML
		}	//end if round 2
}

void BonusGame::UpdateWinAndCredits()
{
	//update the win
	BonusGame::m_baseGamePtr->SetIWin(BonusGame::m_iBonusWin);
	//update the credits
	BonusGame::m_baseGamePtr->SetICredits(BonusGame::m_iCredits);
}

//return the status of the quit member field
bool BonusGame::IsQuitBonusGame()
{
	return BonusGame::m_bQuitBonusGame;
}

//quit the bonus game
void BonusGame::QuitBonusGame()
{
	//set the game model pointer to point to NULL
	BonusGame::m_baseGamePtr = NULL;
	BonusGame::m_bQuitBonusGame = true;
}

BonusGame::~BonusGame()
{
	// TODO Auto-generated destructor stub
}

