/*
 * GameController.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#include "GameController.h"

//member field to control the number of betting steps
int GameController::m_iBetStep = 0;

//member field to hold the bets at each step
vector<BET> GameController::m_vecBetPerStep
{ eBet0, eBet1, eBet2, eBet3, eBet4, eBet5, eBet6, eBet7, eBet8, eBet9, eBet10,
		eBet11, eBet12, eBet13, eBet14, eBet15 };

//member field to keep track of which figures are selected at each reel
bool GameController::m_bFigureIsSelected[eNUM_FIGURES] =
{ false };

//member field to keep track of the number of special figures per reel
int GameController::m_iBonusCounter = 0;

//member field to keep track of the choice the player made during the bonus game
COLOR GameController::m_playerChoice = eInvalidColor;
//member field to keep track if the player wants to keep the bonus game
bool GameController::m_bQuitBonusGame = false;

//constructor
GameController::GameController() :
		m_baseGame()
{
	// TODO Auto-generated constructor stub
}

//Increase the credits
void GameController::IncreaseCredits()
{
	//increment the existing credits by 10000
	int iNewCredits = this->m_baseGame.GetICredits() + CREDIT_STEP;
	//check to make sure the new amount doesn't exceed the max value
	if (iNewCredits <= MAX_CREDITS)
	{
		this->InsertCredits(iNewCredits);
	} // end if
}

//Decrease Credits
void GameController::DecreaseCredits()
{
	//decrement the existing credits by 10000
	int iNewCredits = this->m_baseGame.GetICredits() - CREDIT_STEP;
	//check to make sure the new amount doesn't go below the min amount
	if (iNewCredits >= MIN_CREDITS)
	{
		this->InsertCredits(iNewCredits);
	}

}
//spin the reels and set the paylines
void GameController::Spin()
{
	//set the total bet and the win to default
	this->SetDefault();
//only spin if the total bet is above 0
	if (!(this->TotalBetExceedsCredits()))
	{
		//subtract the current bet from the credits
		this->AddTotalBetToCredits();
		//init the reels and set the paylines
		this->InitCurrentReels();
		this->InitCurrentPaylines();
		//Calculate the winnings from the spin
		this->SetTotalWin();
		//test cout
		cout << "VALID SPIN" << endl;
	} // end if
}

GameController::~GameController()
{
// TODO Auto-generated destructor stub
}

//increase the number of paylines
void GameController::IncreasePaylines()
{
	int iNumPayLines = this->GetNumberOfLines();

//check if the number of paylines doesn't exceed the max value
	if (iNumPayLines < MAX_PAYLINES)
	{
		int iLineIncrement = iNumPayLines + 1;
//check if the payLines don't cause the total bet to exceed the
//current amount of credits
		if (!(this->PaylinesExceedCredits(iLineIncrement)))
		{
			this->SetNumberOfPaylines(++iNumPayLines);
			this->SetTotalBet();
		}

	}
}

//decrease the number of paylines
void GameController::DecreasePaylines()
{
	int iNumPayLines = this->GetNumberOfLines();
	if (iNumPayLines > MIN_PAYLINES)
	{
		this->SetNumberOfPaylines(--iNumPayLines);
		this->SetTotalBet();
	}
}

//increase the bet by 1 step
void GameController::IncreaseBet()
{
	int iCurrentStep = GameController::m_iBetStep;
//check if the betting step doesn't exceed the max value
	if (iCurrentStep <= MAX_BET_STEP)
	{
		int iNextStep = iCurrentStep + 1;
//check if the incremented step doesn't cause
//total bet to exceed the current amount of credits
		if (!(this->BetExceedsCredits(iNextStep)))
		{
			GameController::m_iBetStep++;
			this->SetBetPerPayline(GameController::m_iBetStep);
			this->SetTotalBet();
		}
	}
}

//decrease the bet by 1 step
void GameController::DecreaseBet()
{
	if (GameController::m_iBetStep > 0)
	{
		GameController::m_iBetStep--;
		this->SetBetPerPayline(GameController::m_iBetStep);
		this->SetTotalBet();
	}

}

//check if the total credit doesn't fall in range of the current
//amount of credits
bool GameController::TotalBetExceedsCredits()
{
	bool bExceedsMin = this->GetTotalBet() < 0;
	bool bExceedsMax = this->GetTotalBet() > this->GetCredits();
	return bExceedsMin || bExceedsMax;
}

//set the total winnings from the paylines and add it to the credits
void GameController::SetTotalWin()
{
	this->WinFromPaylines();
	this->AddWinToCredits();
}

//quit the bonus game
bool GameController::QuitBonusGame()
{
	GameController::m_bQuitBonusGame = true;
	return GameController::m_bQuitBonusGame;
}
//bonus game round1
void GameController::BonusWin1(const COLOR& playerChoice)
{
	int newWin = -1;
	if (this->m_bonusGame.RoundOne(playerChoice))
	{
		newWin = 2 * this->GetWin();
	}
	else
	{
		newWin = 0;
	}
	this->m_baseGame.SetIWin(newWin);
	//TODO Update Credits

}

//bonus game round2
void GameController::BonusWin2(const COLOR& playerChoice)
{
	int newWin = -1;
	if (this->m_bonusGame.RoundTwo(playerChoice))
	{
		newWin = 2 * this->GetWin();
	}
	else
	{
		newWin = 0;
	}
	this->m_baseGame.SetIWin(newWin);
	//TODO Update Credits
}

//if player wants to play bonus game round 1
void GameController::PlayBonusRoundOne()
{
	//if the player choice is valid
	if (GameController::m_playerChoice == eBlack
			|| GameController::m_playerChoice == eRed)
	{
		this->BonusWin1(GameController::m_playerChoice);
	}

}

//if player wants to play bonus game round 2
void GameController::PlayBonusRoundTwo()
{

}

//if player selected a black card
void GameController::SelectBlackCard()
{
	GameController::m_playerChoice = eBlack;
}

//if the player selected a red card
void GameController::SelectRedCard()
{
	GameController::m_playerChoice = eRed;
}

//set the bet per line and number of lines to their maximum values
void GameController::MaxBet()
{
	if (this->GetCredits() >= MAX_TOTAL_BET)
	{
		this->SetBetPerPayline(MAX_BET_STEP - 1);
		this->SetNumberOfPaylines(MAX_PAYLINES);
	}
}

//Getters
const vector<vector<Figures> >& GameController::GetGameReels() const
{
	return this->m_baseGame.GetMatrixGameReels();
}

int GameController::GetBetPerLine() const
{
	return this->m_baseGame.GetIBetPerLine();
}

int GameController::GetCredits() const
{
	return this->m_baseGame.GetICredits();
}

int GameController::GetNumberOfLines() const
{
	return this->m_baseGame.GetINumberOfLines();
}

int GameController::GetTotalBet() const
{
	return this->m_baseGame.GetITotalBet();
}

int GameController::GetWin() const
{
	return this->m_baseGame.GetIWin();
}

//printing functions
void GameController::PrintReels() const
{
	this->m_baseGame.PrintReels();
	for (int iRow = 0; iRow < GAME_ROWS; iRow++)
	{
		for (int iCol = 0; iCol < GAME_REELS; iCol++)
		{
			//cout << GameModel::m_iGameReels[iRow][iCol] << "\t";
			cout << this->m_baseGame.GetMatrixGameReels()[iRow][iCol] << "\t";
		}
		cout << endl;
	}
}

void GameController::PrintPayline(const Payline& payline) const
{
	for (int i = 0; i < GAME_REELS; i++)
	{
		cout << payline.figure[i] << "\t";
	}
	cout << endl;
}

void GameController::PrintPaylines() const
{
	for (int i = 0; i < (int) this->m_baseGame.m_vecPaylines.size(); i++)
	{
		cout << "PayLine " << i + 1 << ":\t";
		this->PrintPayline(this->m_baseGame.m_vecPaylines[i]);
	}
}

void GameController::PrintCredits() const
{
	cout << "Credits: " << this->m_baseGame.GetICredits() << endl;
}

void GameController::PrintBetPerLine() const
{
	cout << "BetPerLine: " << this->m_baseGame.GetIBetPerLine() << endl;
}

void GameController::PrintNumLines() const
{
	cout << "Number of Paylines: " << this->m_baseGame.GetINumberOfLines()
			<< endl;
}

void GameController::PrintTotalBet() const
{
	cout << "Total Bet: " << this->m_baseGame.GetITotalBet() << endl;
}

void GameController::PrintWin() const
{
	cout << "Win: " << this->m_baseGame.GetIWin() << endl;
}

//erase the contents from the vector, holding the paylines
void GameController::ErasePaylines()
{
	//check if the vector is empty
	if (!this->m_baseGame.m_vecPaylines.empty())
	{
		//iterator pointing to the first element of the payline vector
		vector<Payline>::iterator paylinesBegin =
				this->m_baseGame.m_vecPaylines.begin();
		//iterator pointing to the one after last element of payline vector
		vector<Payline>::iterator paylinesEnd =
				this->m_baseGame.m_vecPaylines.end();
		//erase the contents of the vector
		this->m_baseGame.m_vecPaylines.erase(paylinesBegin, paylinesEnd);
	}
}

