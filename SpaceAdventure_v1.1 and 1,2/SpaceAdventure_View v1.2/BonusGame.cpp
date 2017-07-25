/*
 * BonusGame.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: SimoAngelov
 */

#include "BonusGame.h"
#include "GameRecovery.h"
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

//member field to keep track if the player has won round1
bool BonusGame::m_bWonRound1 = false;

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
	//cout << "BonusGame::InitBonusGame - Initializing bonus game :O" << endl;
	//load the players choice from the xml
	BonusGame::m_playerChoice = GameRecovery::LoadBonusPlayerChoice();
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
	//set the bool values for won round 1 to false
	BonusGame::m_bWonRound1 = false;
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
	//cout << "\t\t\t\tBonusGame::After WIN" << endl;
	//cout << "\t\t\t\tWin: " << BonusGame::m_baseGamePtr->GetIWin();
	//cout << "\n\t\t\t\tCredits: " << BonusGame::m_baseGamePtr->GetICredits();
	//cout << "\n\t\t\t\tEND AFTER WIN\n";
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
	//cout << "\t\t\t\tBonusGame::After LOSS" << endl;
	//cout << "\t\t\t\tWin: " << BonusGame::m_baseGamePtr->GetIWin();
	//cout << "\n\t\t\t\tCredits: " << BonusGame::m_baseGamePtr->GetICredits();

	//cout << "\n\t\t\t\tEND AFTER LOSS\n";
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
	//round 1 condition
	bool b_RoundOneCondition = BonusGame::m_iRound == eRound1;
	bool b_RoundTwoCondition = (BonusGame::m_iRound == eRound2)
			&& BonusGame::m_bWonRound1;
//	test cout
//	cout << "\t\tBonusGame::m_iRound == eRound1:   " << b_RoundOneCondition
//			<< endl;
//	cout << "\t\tBonusGame::m_iRound == eRound2 :   "
//			<< (BonusGame::m_iRound == eRound2) << endl;
//	cout << "\t\tPlayer WOn round 1 :   "
//			<< BonusGame::m_bWonRound1 << endl;
//	cout << "\t\tBonusGame::m_iRound == eRound2 && player won :   "
//			<< b_RoundTwoCondition << endl;
//	cout << "\t\tROUND IS " << BonusGame::m_iRound << endl;
//	test cout
	//cout << "BonusGame:: PLAYING DOUBLE UP WINS\n";

	//if round 1 or round 2
	if (b_RoundOneCondition || b_RoundTwoCondition)
	{
		//if the bet is valid
		if (BonusGame::IsValidBet())
		{
			//set the bonusGame result
			BonusGame::SetBonusGameResult();
			//test cout
			//cout << "BonusGame::IsValidBet" << endl;
			//cout << "Playing Round " << BonusGame::m_iRound << endl;
			//cout << "Credits before taking bonus bet: " <<
//					BonusGame::m_iCredits
//					<< endl;
			//take the bet from the credits
			BonusGame::m_iCredits -= BonusGame::m_iBet;
			//test cout
//			cout << "Credits after taking bonus bet: " <<
//					BonusGame::m_iCredits
//							<< endl;
			//if the player won
			if (BonusGame::PlayerWon())
			{
				//test cout
				cout << "\t\tBonusGame::WON ROUND " << BonusGame::m_iRound
						<< endl;
				//update the win and credits
				BonusGame::UpdateIfWin();
			} //end if player won round 1
			else
			{
				//test cout
				cout << "\t\tBonusGame::LOST ROUND " << BonusGame::m_iRound
						<< endl;
				//update the win and credits
				BonusGame::UpdateIfLoss();
			} // end if player lost round 1
		} //end if valid bet
//		cout << "\t\tBonusGame::PlayerWon: " << BonusGame::PlayerWon() << endl;
//		cout << "\t\tPlayer choice: " << BonusGame::m_playerChoice << endl;
//		cout << "\t\tBonusGame result: " << BonusGame::m_bonusGameResult
//				<< endl;
	} //end if round
}

//play bonus round
void BonusGame::PlayBonusRound()
{
	//test cout
//	cout << "\t\tBonusGame::PlayBonusRound" << endl;
//	cout << "\t\tPlayer choice: " << BonusGame::m_playerChoice << endl;
//	cout << "\t\tBonusGame result: " << BonusGame::m_bonusGameResult << endl;
//	cout << "BonusGame::PlayBonusRound = Current Bet: "
//				<< BonusGame::m_iBet << endl;
//	cout << "BonusGame::PlayBonusRound = Current Win: "
//			<< BonusGame::m_iBonusWin << endl;
//	cout << "BonusGame::PlayBonusRound = Current Credits: "
//			<< BonusGame::m_iCredits << endl;

//	cout << "\t\tBonusGame::PlayBonusRound___PlayerWon() "
//			<< BonusGame::PlayerWon();
	//if the win is above zero
	if(BonusGame::m_baseGamePtr->GetIWin() > 0)
	{
		BonusGame::DoubleUpWins();
	}

}

//test function to test the win of a round
void BonusGame::WinBonusRound()
{
	//test cout
//	cout << "BonusGame::PlayBonusRound = Current Bet: " << BonusGame::m_iBet
//			<< endl;
//	cout << "BonusGame::PlayBonusRound = Current Win: "
//			<< BonusGame::m_iBonusWin << endl;
//	cout << "BonusGame::PlayBonusRound = Current Credits: "
//			<< BonusGame::m_iCredits << endl;
	BonusGame::m_playerChoice = BonusGame::m_bonusGameResult;
	BonusGame::DoubleUpWins();
}

void BonusGame::UpdateWinAndCredits()
{
	//update the win
	BonusGame::m_baseGamePtr->SetIWin(BonusGame::m_iBonusWin);
	//update the credits
	BonusGame::m_baseGamePtr->SetICredits(BonusGame::m_iCredits);
	//save to xml
	GameRecovery::UpdateWin(BonusGame::m_iBonusWin);
	GameRecovery::UpdateCredits(BonusGame::m_iCredits);
	GameRecovery::UpdateBonusPlayerChoice(BonusGame::m_playerChoice);
	//set game result and player choice to default
	BonusGame::SetDefault();
}

//set player choice and bonus game result to defaul
void BonusGame::SetDefault()
{
	//if round 1, update the flag
	if(BonusGame::m_iRound == eRound1)
	{
		BonusGame::m_bWonRound1 = BonusGame::PlayerWon();
	}
	BonusGame::m_playerChoice = COLOR::eInvalidColor;
	BonusGame::m_bonusGameResult = COLOR::eInvalidColor;
	//test cout
	cout << "\t\tBonusGame::m_bWonRound1 is " << BonusGame::m_bWonRound1 << endl;
}


//gamble amount
string BonusGame::GambleAmount()
//string BonusGame::GambleAmount()
{
	string res = itos(BonusGame::m_iBet);
	cout << "BonusGame::GambleAmount res is " << res << endl;
	cout << "c_str = " << res.c_str() << endl;
	//return the bet, which is the current winnings from the game
	return res.c_str();
}

//amount to win
string BonusGame::GambleToWin()
//string BonusGame::GambleToWin()
{
	string res = itos(2 * BonusGame::m_iBet);
	cout << "BonusGame::GambleAmount res is " << res << endl;
	cout << "c_str = " << res.c_str() << endl;
	//the expected win is double the old winnings
	return res.c_str();
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

