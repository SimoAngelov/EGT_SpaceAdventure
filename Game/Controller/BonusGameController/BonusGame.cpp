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
bool BonusGame::m_bIsRound[eNUM_ROUNDS] =
{ true, false };

//member field to keep track of the rounds
int BonusGame::m_iRound = 0;

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
	//test cout
	cout << "BonusGame::InitBonusGame - Initializing bonus game :O" << endl;
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
	//increment the round counter to default
	BonusGame::m_iRound = 0;
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
	//update the bonus bet for the next round
	BonusGame::m_iBet = BonusGame::m_iBonusWin;
	//update the game model
	BonusGame::UpdateWinAndCredits();
	//test cout
	cout << "BonusGame::After Win" << endl;
	cout << "Win: " << BonusGame::m_baseGamePtr->GetIWin();
	cout << "\nCredits: " << BonusGame::m_baseGamePtr->GetICredits();
	cout << "\nEND AFTER WIN\n";
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
	//update the game model
	BonusGame::UpdateWinAndCredits();
	//update the bonus bet for the next round
	BonusGame::m_iBet = BonusGame::m_iBonusWin;
	//test cout
	cout << "BonusGame::After LOSS" << endl;
	cout << "Win: " << BonusGame::m_baseGamePtr->GetIWin();
	cout << "\nCredits: " << BonusGame::m_baseGamePtr->GetICredits();
	cout << "\nEND AFTER LOSS\n";
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
	bool bWinCondition1 = BonusGame::m_playerChoice
			== BonusGame::m_bonusGameResult;
	bool bWinCondition2 = BonusGame::m_bonusGameResult != eInvalidColor;
	return bWinCondition1 && bWinCondition2;
}


//double up the wins from the game controller, or set them to zero
void BonusGame::DoubleUpWins()
{
	//increment the bonus round counter
	BonusGame::m_iRound++;
	//if round 1 or round 2
	if (BonusGame::m_iRound == eRound1 || BonusGame::m_iRound == eRound2)
	{
		//if the bet is valid
		if (BonusGame::IsValidBet())
		{
			//test cout
			cout << "BonusGame::IsValidBet" << endl;
			cout << "Playing Round " << BonusGame::m_iRound << endl;
			cout << "Credits before taking bonus bet: " <<
					BonusGame::m_iCredits
					<< endl;
			//take the bet from the credits
			BonusGame::m_iCredits -= BonusGame::m_iBet;
			//test cout
			cout << "Credits after taking bonus bet: " <<
					BonusGame::m_iCredits
							<< endl;
			//if the player won
			if (BonusGame::PlayerWon())
			{
				//test cout
				cout << "BonusGame::WON ROUND " <<
						BonusGame::m_iRound << endl;
				//update the win and credits
				BonusGame::UpdateIfWin();
			} //end if player won round 1
			else
			{
				//test cout
				cout << "BonusGame::LOST ROUND " <<
						BonusGame::m_iRound  << endl;
				//update the win and credits
				BonusGame::UpdateIfLoss();
			} // end if player lost round 1
		}//end if valid bet
	}//end if round
}

//play bonus round
void BonusGame::PlayBonusRound()
{
	//test cout
	cout << "BonusGame::PlayBonusRound = Current Bet: "
				<< BonusGame::m_iBet << endl;
	cout << "BonusGame::PlayBonusRound = Current Win: "
			<< BonusGame::m_iBonusWin << endl;
	cout << "BonusGame::PlayBonusRound = Current Credits: "
			<< BonusGame::m_iCredits << endl;
	//set the bonusGame result
	BonusGame::SetBonusGameResult();
	BonusGame::DoubleUpWins();
}

void BonusGame::WinBonusRound()
{
	//test cout
	cout << "BonusGame::PlayBonusRound = Current Bet: "
				<< BonusGame::m_iBet << endl;
	cout << "BonusGame::PlayBonusRound = Current Win: "
			<< BonusGame::m_iBonusWin << endl;
	cout << "BonusGame::PlayBonusRound = Current Credits: "
			<< BonusGame::m_iCredits << endl;
	//set the bonusGame result
	BonusGame::SetBonusGameResult();
	BonusGame::m_playerChoice = BonusGame::m_bonusGameResult;
	BonusGame::DoubleUpWins();
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

