/*
 * BonusGameController.cpp
 *
 *  Created on: 01.08.2017
 *      Author: sim4o
 */

#include "BonusGameController.h"
#include "../GameRecovery/GameRecovery.h"
//member field to increment the seed additionally each time srand is called
int BonusGameController::m_iRandCounter = 0;


//member field to keep track of the card the player has chosen
COLOR BonusGameController::m_playerChoice = eInvalidColor;

//member field to keep track of the result from the current bonus round
COLOR BonusGameController::m_bonusGameResult = eInvalidColor;

//member field to hold the credits from the game controller
int BonusGameController::m_iCredits = 0;

//member field to hold the bet for the bonus game
int BonusGameController::m_iBet = 0;

//member field to hold the win from the bonus game
int BonusGameController::m_iBonusWin = 0;

//member field to keep track if the player has won round1
bool BonusGameController::m_bWonRound1 = false;

//member field to keep track of the rounds
int BonusGameController::m_iRound = 1;

//member field to keep track if the player wants to quit the bonus round
bool BonusGameController::m_bQuitBonusGame = false;

//constructor
BonusGameController::BonusGameController()
{
	// TODO Auto-generated constructor stub
}

//destructor
BonusGameController::~BonusGameController()
{
	// TODO Auto-generated destructor stub
}

//check if there is a bonus game
bool BonusGameController::IsBonusGame(int iBonusCounter)
{
	return iBonusCounter == BONUS_GAME;
}

//initialize the member fields
void BonusGameController::InitBonusGame()
{
	//load the win and credits from the xml file
	BonusGameController::m_playerChoice = eInvalidColor;
	if(GameRecovery::IsSaveGame())
	{
		//initialize the bonus win with the amount from the game controller
		BonusGameController::m_iBonusWin = GameRecovery::LoadWin();
		//take the credits from the game controller
		BonusGameController::m_iCredits = GameRecovery::LoadCredits();
	} else
	{
		//store the value of the current game win
		BonusGameController::m_iBonusWin = 0;
		//take the credits from the game controller
		BonusGameController::m_iCredits = 0;
	}

	//the bet is the current win from the paylines from the game controller
	BonusGameController::m_iBet = BonusGameController::m_iBonusWin;
	//set the bool values for won round 1 to false
	BonusGameController::m_bWonRound1 = false;
	//increment the round counter to default
	BonusGameController::m_iRound = 1;
	//set the quit game value to false
	BonusGameController::m_bQuitBonusGame = false;
}

//return the bonus win
int BonusGameController::GetBonustWin()
{
	return BonusGameController::m_iBonusWin;
}

//set the result from the card draw
void BonusGameController::SetBonusGameResult()
{
	srand(time(0) + (BonusGameController::m_iRandCounter++));
	BonusGameController::m_bonusGameResult = static_cast<COLOR>(rand() % eNUM_COLORS);
}


//update the win and credits
//the parameter is a bool value to check if the player won or lost
void BonusGameController::UpdateWinAndCredits(bool bIsWin)
{
	//double the win from the bonus game or set them to zero
	BonusGameController::m_iBonusWin = (bIsWin) ? (2 * BonusGameController::m_iBet) : 0;
	//update the credits
	BonusGameController::m_iCredits += BonusGameController::m_iBonusWin;
	//update the bonus bet for the next round
	BonusGameController::m_iBet = BonusGameController::m_iBonusWin;
	//update the game model
	BonusGameController::SaveWinAndCredits();
}


void BonusGameController::PlayerSelectedBlack()
{
	BonusGameController::m_playerChoice = eBlack;
}

void BonusGameController::PlayerSelectedRed()
{
	BonusGameController::m_playerChoice = eRed;

}

// check if the bet is valid
bool BonusGameController::IsValidBet()
{
	return BonusGameController::m_iCredits >= BonusGameController::m_iBet;
}

//return if the player won the round
bool BonusGameController::PlayerWon()
{
	//test cout
	cout << "\t\tCheck if player won" << endl;
	bool bWinCondition1 = (BonusGameController::m_playerChoice
			== BonusGameController::m_bonusGameResult);
	bool bWinCondition2 = (BonusGameController::m_bonusGameResult != eInvalidColor);

	BonusGameController::PrintInfo();
	cout << "bWinCondtion1 is " << bWinCondition1 << endl;
	cout << "bWinCondtion2 is " << bWinCondition2 << endl;
	return bWinCondition1 && bWinCondition2;
}

//check if valid round
bool BonusGameController::IsValidRound()
{
	cout << "The round counter is " << m_iRound << endl;
	//round 1 condition
	bool bRoundOneCondition = BonusGameController::m_iRound == eRound1;
	//round 2 condition
	bool bRoundTwoCondition = (BonusGameController::m_iRound == eRound2)
			&& BonusGameController::m_bWonRound1;
	//test cout
	cout << "bRoundOneCondition is " << bRoundOneCondition << endl;
	cout << "bRoundTwoCondition " << bRoundTwoCondition << endl;
	return bRoundOneCondition || bRoundTwoCondition;
}

//double up the wins from the game controller, or set them to zero
void BonusGameController::DoubleUpWins()
{
	cout << "\t\tBonusGameController::PlayBonusRound()" << endl;
	BonusGameController::SetDefault();
	cout << "\t\tEND::BonusGameController::PlayBonusRound()" << endl;
	//if round 1 or round 2
	if (BonusGameController::IsValidRound())
	{
		//if the bet is valid
		if (BonusGameController::IsValidBet())
		{
			//set the bonusGame result
			BonusGameController::SetBonusGameResult();
			//take the bet from the credits
			BonusGameController::m_iCredits -= BonusGameController::m_iBet;
			//check if the player won and update the win and credits
			BonusGameController::UpdateWinAndCredits(BonusGameController::PlayerWon());
		} //end if valid bet
	} //end if round
	//if round 1, update the flag
	if(BonusGameController::m_iRound == eRound1)
	{
		BonusGameController::m_bWonRound1 = BonusGameController::PlayerWon();
		cout << "BonusGameController::SetDefault()   The player has won: " << BonusGameController::m_bWonRound1 << endl;
	}
	//increment the bonus round counter
	BonusGameController::m_iRound++;
}

//play bonus round
void BonusGameController::PlayBonusRound()
{
	//if the win is above zero
	if(BonusGameController::m_iBonusWin > 0)
	{
		BonusGameController::DoubleUpWins();
	}
}

void BonusGameController::SaveWinAndCredits()
{
	//save to xml
	GameRecovery::UpdateWin(BonusGameController::m_iBonusWin);
	GameRecovery::UpdateCredits(BonusGameController::m_iCredits);
}

//set the bonus game result to default
void BonusGameController::SetDefault()
{
	cout << "BonusGameController::SetDefault()   The Round is " << m_iRound << endl;
	BonusGameController::m_bonusGameResult = COLOR::eInvalidColor;
}


//gamble amount
string BonusGameController::GambleAmount()
{
	string res = itos(BonusGameController::m_iBet);
	//return the bet, which is the current winnings from the game
	return res;
}

//amount to win
string BonusGameController::GambleToWin()
{
	string res = itos(2 * BonusGameController::m_iBet);
	//the expected win is double the old winnings
	return res;
}

//return the bonus win member field as a string
string BonusGameController::BonusWinAsString()
{
	string res = itos(BonusGameController::m_iBonusWin);
	return res;
}
//return the status of the quit member field
bool BonusGameController::IsQuitBonusGame()
{
	return BonusGameController::m_bQuitBonusGame;
}

//quit the bonus game
void BonusGameController::QuitBonusGame()
{
	BonusGameController::m_bQuitBonusGame = true;
}

//get the bonus game result
COLOR BonusGameController::GetBonusGameResult()
{
	return BonusGameController::m_bonusGameResult;
}

//get the player choice
COLOR BonusGameController::GetPlayerChoice()
{
	return BonusGameController::m_playerChoice;
}

//print method
void BonusGameController::PrintInfo()
{
	cout << "++BonusGameInfo++" << endl;
	cout << BonusGameController::TestStringPlayerChoice() << endl;
	cout << BonusGameController::TestStringBonusGameResult() << endl;
	//cout << BonusGameController::TestStringPlayerWon() << endl;
	cout << "Credits: " << BonusGameController::m_iCredits << endl;
	cout << "Winnings: " << BonusGameController::BonusWinAsString().c_str() << endl;
}

//test methods to present the results in a user-friendly way
string BonusGameController::TestStringPlayerChoice()
{
	string res = "";
	switch(BonusGameController::GetPlayerChoice())
	{
	case 0: res.append("Player has selected the color black"); break;
	case 1: res.append("Player has selected the color red"); break;
	default: res.append("ERR! Player has selected an invalid color"); break;
	}
	return res;
}

string BonusGameController::TestStringBonusGameResult()
{
	string res = "The result from the bonus game is: ";
	switch(BonusGameController::GetBonusGameResult())
	{
	case 0: res.append("BLACK"); break;
	case 1: res.append("RED"); break;
	default: res.append("ERR! INVALID COLOR"); break;
	}
	return res;
}

string BonusGameController::TestStringPlayerWon()
{
	string res = "";
	switch(BonusGameController::PlayerWon())
	{
	case true: res.append("Yay. The player won!"); break;
	case false: res.append("Rats. The player lost"); break;
	default: res.append("Houston, we have a problem determining if the player won"); break;
	}
	return res;
}



