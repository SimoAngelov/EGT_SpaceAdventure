/*
 * BonusGame.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: SimoAngelov
 */

#include "BonusGame.h"
#include "../GameRecovery/GameRecovery.h"
//member field to increment the seed additionally each time srand is called
int BonusGame::m_iRandCounter = 0;


//member field to keep track of the card the player has chosen
COLOR BonusGame::m_playerChoice = eInvalidColor;

//member field to keep track of the result from the current bonus round
COLOR BonusGame::m_bonusGameResult = eInvalidColor;

//member field to hold the credits from the game controller
int BonusGame::m_iCredits = 0;

//member field to hold the bet for the bonus game
int BonusGame::m_iBet = 0;

//member field to hold the win from the bonus game
int BonusGame::m_iBonusWin = 0;

//member field to keep track if the player has won round1
bool BonusGame::m_bWonRound1 = false;

//member field to keep track of the rounds
int BonusGame::m_iRound = 1;

//member field to keep track if the player wants to quit the bonus round
bool BonusGame::m_bQuitBonusGame = false;

//constructor
BonusGame::BonusGame()
{
	// TODO Auto-generated constructor stub
}

//destructor
BonusGame::~BonusGame()
{
	// TODO Auto-generated destructor stub
}

//check if there is a bonus game
bool BonusGame::IsBonusGame(int iBonusCounter)
{
	return iBonusCounter == BONUS_GAME;
}

//initialize the member fields
void BonusGame::InitBonusGame()
{
	//load the win and credits from the xml file
	BonusGame::m_playerChoice = eInvalidColor;
	if(GameRecovery::IsSaveGame())
	{
		//initialize the bonus win with the amount from the game controller
		BonusGame::m_iBonusWin = GameRecovery::LoadWin();
		//take the credits from the game controller
		BonusGame::m_iCredits = GameRecovery::LoadCredits();
	} else
	{
		//store the value of the current game win
		BonusGame::m_iBonusWin = 0;
		//take the credits from the game controller
		BonusGame::m_iCredits = 0;
	}

	//the bet is the current win from the paylines from the game controller
	BonusGame::m_iBet = BonusGame::m_iBonusWin;
	//set the bool values for won round 1 to false
	BonusGame::m_bWonRound1 = false;
	//increment the round counter to default
	BonusGame::m_iRound = 1;
	//set the quit game value to false
	BonusGame::m_bQuitBonusGame = false;
}

//return the bonus win
int BonusGame::GetBonustWin()
{
	return BonusGame::m_iBonusWin;
}

//set the result from the card draw
void BonusGame::SetBonusGameResult()
{
	srand(time(0) + (BonusGame::m_iRandCounter++));
	BonusGame::m_bonusGameResult = static_cast<COLOR>(rand() % eNUM_COLORS);
}


//update the win and credits
//the parameter is a bool value to check if the player won or lost
void BonusGame::UpdateWinAndCredits(bool bIsWin)
{
	//double the win from the bonus game or set them to zero
	BonusGame::m_iBonusWin = (bIsWin) ? (2 * BonusGame::m_iBet) : 0;
	//update the credits
	BonusGame::m_iCredits += BonusGame::m_iBonusWin;
	//update the bonus bet for the next round
	BonusGame::m_iBet = BonusGame::m_iBonusWin;
	//update the game model
	BonusGame::SaveWinAndCredits();
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

//return if the player won the round
bool BonusGame::PlayerWon()
{
	//test cout
	cout << "\t\tCheck if player won" << endl;
	bool bWinCondition1 = (BonusGame::m_playerChoice
			== BonusGame::m_bonusGameResult);
	bool bWinCondition2 = (BonusGame::m_bonusGameResult != eInvalidColor);

	BonusGame::PrintInfo();
	cout << "bWinCondtion1 is " << bWinCondition1 << endl;
	cout << "bWinCondtion2 is " << bWinCondition2 << endl;
	return bWinCondition1 && bWinCondition2;
}

//check if valid round
bool BonusGame::IsValidRound()
{
	cout << "The round counter is " << m_iRound << endl;
	//round 1 condition
	bool bRoundOneCondition = BonusGame::m_iRound == eRound1;
	//round 2 condition
	bool bRoundTwoCondition = (BonusGame::m_iRound == eRound2)
			&& BonusGame::m_bWonRound1;
	//test cout
	cout << "bRoundOneCondition is " << bRoundOneCondition << endl;
	cout << "bRoundTwoCondition " << bRoundTwoCondition << endl;
	return bRoundOneCondition || bRoundTwoCondition;
}

//double up the wins from the game controller, or set them to zero
void BonusGame::DoubleUpWins()
{
	cout << "\t\tBonusGame::PlayBonusRound()" << endl;
	BonusGame::SetDefault();
	cout << "\t\tEND::BonusGame::PlayBonusRound()" << endl;
	//if round 1 or round 2
	if (BonusGame::IsValidRound())
	{
		//if the bet is valid
		if (BonusGame::IsValidBet())
		{
			//set the bonusGame result
			BonusGame::SetBonusGameResult();
			//take the bet from the credits
			BonusGame::m_iCredits -= BonusGame::m_iBet;
			//check if the player won and update the win and credits
			BonusGame::UpdateWinAndCredits(BonusGame::PlayerWon());
		} //end if valid bet
	} //end if round
	//if round 1, update the flag
	if(BonusGame::m_iRound == eRound1)
	{
		BonusGame::m_bWonRound1 = BonusGame::PlayerWon();
		cout << "BonusGame::SetDefault()   The player has won: " << BonusGame::m_bWonRound1 << endl;
	}
	//increment the bonus round counter
	BonusGame::m_iRound++;
}

//play bonus round
void BonusGame::PlayBonusRound()
{
	//if the win is above zero
	if(BonusGame::m_iBonusWin > 0)
	{
		BonusGame::DoubleUpWins();
	}
}

void BonusGame::SaveWinAndCredits()
{
	//save to xml
	GameRecovery::UpdateWin(BonusGame::m_iBonusWin);
	GameRecovery::UpdateCredits(BonusGame::m_iCredits);
}

//set the bonus game result to default
void BonusGame::SetDefault()
{
	cout << "BonusGame::SetDefault()   The Round is " << m_iRound << endl;
	BonusGame::m_bonusGameResult = COLOR::eInvalidColor;
}


//gamble amount
string BonusGame::GambleAmount()
{
	string res = itos(BonusGame::m_iBet);
	//return the bet, which is the current winnings from the game
	return res;
}

//amount to win
string BonusGame::GambleToWin()
{
	string res = itos(2 * BonusGame::m_iBet);
	//the expected win is double the old winnings
	return res;
}

//return the bonus win member field as a string
string BonusGame::BonusWinAsString()
{
	string res = itos(BonusGame::m_iBonusWin);
	return res;
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

//get the bonus game result
COLOR BonusGame::GetBonusGameResult()
{
	return BonusGame::m_bonusGameResult;
}

//get the player choice
COLOR BonusGame::GetPlayerChoice()
{
	return BonusGame::m_playerChoice;
}

//print method
void BonusGame::PrintInfo()
{
	cout << "++BonusGameInfo++" << endl;
	cout << BonusGame::TestStringPlayerChoice() << endl;
	cout << BonusGame::TestStringBonusGameResult() << endl;
	//cout << BonusGame::TestStringPlayerWon() << endl;
	cout << "Credits: " << BonusGame::m_iCredits << endl;
	cout << "Winnings: " << BonusGame::BonusWinAsString().c_str() << endl;
}

//test methods to present the results in a user-friendly way
string BonusGame::TestStringPlayerChoice()
{
	string res = "";
	switch(BonusGame::GetPlayerChoice())
	{
	case 0: res.append("Player has selected the color black"); break;
	case 1: res.append("Player has selected the color red"); break;
	default: res.append("ERR! Player has selected an invalid color"); break;
	}
	return res;
}

string BonusGame::TestStringBonusGameResult()
{
	string res = "The result from the bonus game is: ";
	switch(BonusGame::GetBonusGameResult())
	{
	case 0: res.append("BLACK"); break;
	case 1: res.append("RED"); break;
	default: res.append("ERR! INVALID COLOR"); break;
	}
	return res;
}

string BonusGame::TestStringPlayerWon()
{
	string res = "";
	switch(BonusGame::PlayerWon())
	{
	case true: res.append("Yay. The player won!"); break;
	case false: res.append("Rats. The player lost"); break;
	default: res.append("Houston, we have a problem determining if the player won"); break;
	}
	return res;
}


