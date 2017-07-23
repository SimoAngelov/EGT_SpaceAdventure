/*
 * GameControllerLogicLogic.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: SimoAngelov
 */

#include <exception>

#include "GameControllerLogic.h"
//member field to control the number of betting steps
int GameControllerLogic::m_iBetStep = 0;

//member field to hold the bets at each step
vector<BET> GameControllerLogic::m_vecBetPerStep
{ eBet0, eBet1, eBet2, eBet3, eBet4, eBet5, eBet6, eBet7, eBet8, eBet9, eBet10,
		eBet11, eBet12, eBet13, eBet14, eBet15 };

//initialize the bonus counter
int GameControllerLogic::m_iBonusCounter = 0;


//constructor
GameControllerLogic::GameControllerLogic() :
		m_baseGame()
{
	// TODO Auto-generated constructor stub
}

GameControllerLogic::~GameControllerLogic()
{
// TODO Auto-generated destructor stub
}


//start new game
void GameControllerLogic::NewGame()
{
	//if the xml file is present, update the member field iCredits
	if(GameRecovery::IsSaveGame())
	{
		//load the credits from the xml file
		int iCurrentCredits = GameRecovery::LoadCredits();
		//update the credits of the game model
		this->m_baseGame.SetICredits(iCurrentCredits);
	}
}

//load old game
void GameControllerLogic::LoadGame()
{
	//update the game model with info from the xml file
//	GameRecovery::LoadGameModel(&(this->m_baseGame));

	//initialize the vector of paylines
	this->InitCurrentPaylines();
}

//Increase the credits
void GameControllerLogic::IncreaseCredits()
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
void GameControllerLogic::DecreaseCredits()
{
	//decrement the existing credits by 10000
	int iNewCredits = this->m_baseGame.GetICredits() - CREDIT_STEP;
	//check to make sure the new amount doesn't go below the min amount
	if (iNewCredits >= MIN_CREDITS)
	{
		this->InsertCredits(iNewCredits);
	}

}

//insert credits in order to play the game
void GameControllerLogic::InsertCredits(int iCredits)
{
	//if the credits are within legal range
	if (iCredits >= MIN_CREDITS && iCredits <= MAX_CREDITS)
	{
		this->m_baseGame.SetICredits(iCredits);
	}
}

//set default values for the member fields
void GameControllerLogic::SetDefault()
{
	GameControllerLogic::m_iBonusCounter = 0;
	this->SetTotalBet();
	this->m_baseGame.SetIWin(0);
}

//spin the reels and set the paylines
void GameControllerLogic::Spin()
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
//		GameRecovery::UpdateGameModel(&(this->m_baseGame));
		//test cout
		cout << "GameControllerLogic::VALID SPIN" << endl;
	} // end if
	  //GameRecovery::UpdateNumberOfPaylines(12);
	  //
}

//intialize the reels for the currentGame
void GameControllerLogic::InitCurrentReels()
{
	//initialize the reels with figures from 0 to 7
	this->InitRandomReels();
	//randomly set or don't set a special figure for a row
//	this->SetSpecialFigure();
	//set a special figure for all the rows
	this->StartBonusGame();
}

//initialize the game reels with random values
void GameControllerLogic::InitRandomReels()
{
	//seed a random sequence of numbers
	srand(time(0));

//traverse each element of the reel
	for (int iRow = 0; iRow < GAME_ROWS; iRow++)
	{
		//traverse each reel
		for (int iReel = 0; iReel < GAME_REELS; iReel++)
		{
			//choose a figure between 1 and 8
			//static cast from int to Figures
			Figures randomFigure = static_cast<Figures>(rand() % eFigure8);
			this->m_baseGame.SetReelElement(randomFigure, iRow, iReel);
			//test cout
			//cout << "Reel: " << iReel << "\tRow: " << iRow << "\tElement"
			//		<< randomFigure << endl;
		} //end row for
	} // end reel for
}

//set the special figure in each game reel
void GameControllerLogic::SetSpecialFigure()
{
	//seed a random sequence of numbers
	srand(time(0));
//traverse each row
	for (int iRow = 0; iRow < GAME_ROWS; iRow++)
	{
		//traverse the first, second etc element of each reel
		for (int iReel = 0; iReel < GAME_REELS; iReel++)
		{
			//static cast from int to Figures
			Figures randomFigure = static_cast<Figures>(rand() % eNUM_FIGURES);
			if (randomFigure == eFigure9)
			{
				//if the current figure is 9 aka special, break the inner loop
				//GameModel::m_iGameReels[iRow][iCol] = randomFigure;
				this->m_baseGame.SetReelElement(randomFigure, iReel, iRow);
				//test cout
			//	cout << "GameControllerLogicLogic::bonus counter ="
			//			<< GameControllerLogicLogic::m_iBonusCounter << endl;
				GameControllerLogic::m_iBonusCounter++;
				break;
			} //end if
		} //end reel for
	} //end row for
}

//hardcode a special figure at each reel to test the bonus game
void GameControllerLogic::StartBonusGame()
{
	//seed a random sequence of numbers
	srand(time(0));
//traverse each reel
	for (int iReel = 0; iReel < GAME_REELS; iReel++)
	{
		int iRandomRow = rand() % 3;
		Figures specialFigure = eFigure9;
		this->m_baseGame.SetReelElement(specialFigure, iRandomRow, iReel);
		//cout << "Reel: " << iReel << "\tRow: " << iRandomRow << "\tElement"
		//		<< specialFigure << endl;
		//tes//coutut
		//cout << "GameControllerLogicLogic::bonus counter ="
		//		<< GameControllerLogicLogic::m_iBonusCounter << endl;
		GameControllerLogic::m_iBonusCounter++;
	} //end reel for
}


//set the same figures per each reel
void GameControllerLogic::SetTheSameFigures()
{
	//seed a random sequence of numbers
	srand(time(0));
	//static cast from int to Figures
	Figures randFigure = static_cast<Figures>(rand() % eNUM_FIGURES);
//traverse each reel
	for (int iCol = 0; iCol < GAME_REELS; iCol++)
	{
//traverse each element of the reel
		for (int iRow = 0; iRow < GAME_ROWS; iRow++)
		{
			this->m_baseGame.SetReelElement(randFigure, iRow, iCol);
		} //end row for
	} // end reel for
}

//Function to initialize the lines
void GameControllerLogic::InitCurrentPaylines()
{
	//empty the vector of the old lines
	ErasePaylines();
	//initialize the new lines
	InitPayline1();
	InitPayline2();
	InitPayline3();
	InitPayline4();
	InitPayline5();
	InitPayline6();
	InitPayline7();
	InitPayline8();
	InitPayline9();
	InitPayline10();
	InitPayline11();
	InitPayline12();
	InitPayline13();
	InitPayline14();
	InitPayline15();
	InitPayline16();
	InitPayline17();
	InitPayline18();
	InitPayline19();
	InitPayline20();
	InitPayline21();
	InitPayline22();
	InitPayline23();
	InitPayline24();
	InitPayline25();
}

//set the bet per line and number of lines to their maximum values
void GameControllerLogic::MaxBet()
{
	//if the available credits are above the max bet
	if (this->GetCredits() >= MAX_TOTAL_BET)
	{
		//update the betting step
		GameControllerLogic::m_iBetStep = MAX_BET_STEP - 1;
		//set the bet per line to max
		this->SetBetPerPayline(GameControllerLogic::m_iBetStep);
		//set the number of paylines to max
		this->SetNumberOfPaylines(MAX_PAYLINES);
	} //end if
}

//increase the number of paylines
void GameControllerLogic::IncreasePaylines()
{
	//take the current number of paylines
	int iNumPayLines = this->GetNumberOfLines();

//check if the number of paylines doesn't exceed the max value
	if (iNumPayLines < MAX_PAYLINES)
	{
		//increment the paylines
		int iLineIncrement = iNumPayLines + 1;
//check if the payLines don't cause the total bet to exceed the
//current amount of credits
		if (!(this->PaylinesExceedCredits(iLineIncrement)))
		{
			this->SetNumberOfPaylines(iLineIncrement);
			//update the total bet
			this->SetTotalBet();
		} // end if total bet doesn't exceed credits
	} // end if paylines don't exceed max value
}

//decrease the number of paylines
void GameControllerLogic::DecreasePaylines()
{
	//take the current number of paylines
	int iNumPayLines = this->GetNumberOfLines();
	//check if they are above the minimum
	if (iNumPayLines > MIN_PAYLINES)
	{
		//decrement the number of paylines
		this->SetNumberOfPaylines(--iNumPayLines);
		//update the total bet
		this->SetTotalBet();
	} //end if
}

//set the number of paylines for the current game
void GameControllerLogic::SetNumberOfPaylines(int iNumberOfPaylines)
{
	this->m_baseGame.SetINumberOfLines(iNumberOfPaylines);
}

//check if the payline increase exceeds the current amount of credits
bool GameControllerLogic::PaylinesExceedCredits(int iNextStep)
{
	//take the available credits
	int iAvailableCredits = this->m_baseGame.GetICredits();
	//update the number of paylines with the next step
	int iNewNumLines = iNextStep;
	//take the current bet per line
	int iCurrBet = this->m_baseGame.GetIBetPerLine();
	//update the total bet
	int iNewBet = iNewNumLines * iCurrBet;
	//check if the total bet exceeds the credits
	return iNewBet > iAvailableCredits;
}

//increase the bet by 1 step
void GameControllerLogic::IncreaseBet()
{
	int iCurrentStep = GameControllerLogic::m_iBetStep;
//check if the betting step doesn't exceed the max value
	if (iCurrentStep <= MAX_BET_STEP - 1)
	{
		int iNextStep = iCurrentStep + 1;
//check if the incremented step doesn't cause
//total bet to exceed the current amount of credits
		if (!(this->BetExceedsCredits(iNextStep)))
		{
			GameControllerLogic::m_iBetStep++;
			//test //cout
			//cout << "\t\t\t\tIncreasing Bet To " << GameControllerLogicLogic::m_iBetStep
					//<< endl;
			this->SetBetPerPayline(GameControllerLogic::m_iBetStep);
			//cout << "\t\t\t\tBetPerLine is " << this->GetBetPerLine() << endl;
		}
	}
}

//decrease the bet by 1 step
void GameControllerLogic::DecreaseBet()
{
	if (GameControllerLogic::m_iBetStep > 0)
	{
		GameControllerLogic::m_iBetStep--;
		//test cout
		//cout << "\t\t\t\tDecreasingBet To " << GameControllerLogicLogic::m_iBetStep
		//		<< endl;
		this->SetBetPerPayline(GameControllerLogic::m_iBetStep);
		//cout << "\t\t\t\tBetPerLine is " << this->GetBetPerLine() << endl;
		this->SetTotalBet();
	}

}

//set the bet per line, depending on the number of steps
void GameControllerLogic::SetBetPerPayline(int iStep)
{
	//take the bet from the vector
	int iBet = this->m_vecBetPerStep[iStep];
	//update the bet per line in the model
	this->m_baseGame.SetIBetPerLine(iBet);
}

//check if the bet increase exceeds the current amount of credits
bool GameControllerLogic::BetExceedsCredits(int iNextStep)
{
	//take the current credits
	int iAvailableCredits = this->m_baseGame.GetICredits();
	//take the current number of paylines
	int iCurrNumLines = this->m_baseGame.GetINumberOfLines();
	//new bet per line
	int iNewBet = this->m_vecBetPerStep[iNextStep];
	//new total bet
	int iNewTotalBet = iCurrNumLines * iNewBet;
	//check if the new total bet doesn't exceed the current credits
	return iNewTotalBet > iAvailableCredits;
}

//set the total bet
void GameControllerLogic::SetTotalBet()
{
	this->m_baseGame.SetITotalBet();
}

//subtract the total bet from the credits
void GameControllerLogic::AddTotalBetToCredits()
{
	if (!(this->TotalBetExceedsCredits()))
	{
		//take the bet out of the credits
		int iCurrCredits = this->GetCredits();
		int iCurrTotalBet = this->GetTotalBet();
		int iNewCredits = iCurrCredits - iCurrTotalBet;
		this->m_baseGame.SetICredits(iNewCredits);
	}
}

//check if the total credit doesn't fall in range of the current
//amount of credits
bool GameControllerLogic::TotalBetExceedsCredits()
{
	bool bExceedsMin = this->GetTotalBet() < 0;
	bool bExceedsMax = this->GetTotalBet() > this->GetCredits();
	return bExceedsMin || bExceedsMax;
}

//set the total winnings from the paylines and add it to the credits
void GameControllerLogic::SetTotalWin()
{
	this->WinFromPaylines();
	this->AddWinToCredits();
	//TODO save the win and credits to XML

//TODO bonus game
	if (this->IsBonusGame())
	{
		//test cout
		//cout << "GameControllerLogicLogic:: This is Bonus Game" << endl;
		//start the bonus game by passing the win and credits as arguments
//		BonusGame::InitBonusGame(&this->m_baseGame);
	}
}

//calculate the win from the selected paylines
void GameControllerLogic::WinFromPaylines()
{
	int winFromPaylines = 0;
	for (int i = 0; i < this->GetNumberOfLines(); i++)
	{
		Payline currentPayline = this->m_baseGame.GetVecPaylines()[i];
		winFromPaylines += this->WinFromSinglePayline(currentPayline);
		//test cout
		//if (this->WinFromSinglePayline(currentPayline) > 0)
			//cout << "GameControllerLogicLogic::Win for line" << i + 1 << ": "
			//		<< this->WinFromSinglePayline(currentPayline) << endl;
	}
	int currentWinnings = this->GetWin();
	int newWinnings = currentWinnings + winFromPaylines;
	this->m_baseGame.SetIWin(newWinnings);
}

//calculate the win from a single line based on the figures
//this function finds the maximum sequence of equal figures
int GameControllerLogic::WinFromSinglePayline(const Payline& payline)
{
	//local variable to hold the best figure
	Figures bestFigure = eInvalidFigure;
	//local variable to hold the occurrence of the best figure
	int iBestOccurrence = 0;

//initialize the currentFigure with the first element of the line
	Figures currentFigure = payline.figure[0];
	//since it is the first element it has currently occurred once
	int iCurrentOccurrence = 1;

//traverse the rest of the line
	for (int i = 1; i < GAME_REELS; i++)
	{
//increment the occurrence of the figure, if it is the same as the previous figure
		if (payline.figure[i] == currentFigure)
		{
			iCurrentOccurrence++;
		}
//first occurrence of the figure in the sequence
		else
		{
			currentFigure = payline.figure[i];
			iCurrentOccurrence = 1;
		}
		//if the current occurrence of the figure is more than the best occurrence
		if (iCurrentOccurrence >= iBestOccurrence)
		{
			//update the best figure and best occurrence
			iBestOccurrence = iCurrentOccurrence;
			bestFigure = currentFigure;
		}
	} //end for

	//find the figure coefficient
	int iFigCoeff = this->FigureCoefficient(bestFigure, iBestOccurrence);
	//get the current bet per line
	int iBet = this->m_baseGame.GetIBetPerLine();
	//the winning per line is the product of the figure coefficient and the bet per line
	int winningsPerLine = iFigCoeff * iBet;
	//return the winnings from the line
	return winningsPerLine;
}

//calculate the coefficient of a figure based on its weight
int GameControllerLogic::FigureCoefficient(const Figures& figure, int iOccurrences)
{
	//local variable to hold the figure weight
	int iWeight = 0;
	//local variable to hold the figure coefficient
	int iCoefficient = 0;
	switch (iOccurrences)
	{
	// for 0 to 2 occurrences the win is zero
	case 0:
	case 1:
	case 2:
		iWeight = 0;
		iCoefficient = 0;
		break;
	case 3:
		iWeight = 10 * iOccurrences;
		break;
	case 4:
		iWeight = 20 * iOccurrences;
		break;
	case 5:
		iWeight = 30 * iOccurrences;
		break;
	default:
		iWeight = 0;
		iCoefficient = 0;
		break;
	}
	//calculate the coefficient
	iCoefficient = (1 + figure) * iWeight;
	return iCoefficient;
}

//Add the win from the paylines to the credits
void GameControllerLogic::AddWinToCredits()
{
	//if there was a win, add it to the credits
	if (this->GetWin() > 0)
	{
		//test cout
		//cout << "GameControllerLogicLogic::THERE IS A WIN" << endl;
		//add the win to the credits
		int iCurrCredits = this->GetCredits();
		int iCurrWin = this->GetWin();
		int iNewCredits = iCurrCredits + iCurrWin;
		this->m_baseGame.SetICredits(iNewCredits);
	}
}

//check if bonus game.
bool GameControllerLogic::IsBonusGame()
{
	//pass the bonus counter to the bonus game
	bool result = BonusGame::IsBonusGame(GameControllerLogic::m_iBonusCounter);
	//return the result
	return result;
}

//Getters
const vector<vector<Figures> >& GameControllerLogic::GetGameReels() const
{
	return this->m_baseGame.GetMatrixGameReels();
}

int GameControllerLogic::GetBetPerLine() const
{
	return this->m_baseGame.GetIBetPerLine();
}

int GameControllerLogic::GetCredits() const
{
	return this->m_baseGame.GetICredits();
}

int GameControllerLogic::GetNumberOfLines() const
{
	return this->m_baseGame.GetINumberOfLines();
}

int GameControllerLogic::GetTotalBet() const
{
	return this->m_baseGame.GetITotalBet();
}

int GameControllerLogic::GetWin() const
{
	return this->m_baseGame.GetIWin();
}

//to string methods

string GameControllerLogic::BetPerLineAsString() const
{
	string res = itos(this->m_baseGame.GetIBetPerLine());
	return res;
}

string GameControllerLogic::CreditsAsString() const
{
	string res = itos(this->m_baseGame.GetICredits());
	return res;
}

string GameControllerLogic::NumberOfLinesAsString() const
{
	string res = itos(this->m_baseGame.GetINumberOfLines());
	return res;
}

string GameControllerLogic::TotalBetAsString() const
{
	string res = itos(this->m_baseGame.GetITotalBet());
	return res;
}

string GameControllerLogic::WinAsString() const
{
	string res = itos(this->m_baseGame.GetIWin());
	return res;
}


//printing functions

void GameControllerLogic::PrintInfo() const
{
	cout << "==GameControllerLogic==" << endl;
	this->PrintReels();
	this->PrintPaylines();
	this->PrintNumLines();
	this->PrintBetPerLine();
	this->PrintTotalBet();
	this->PrintWin();
	this->PrintCredits();
}

void GameControllerLogic::PrintReels() const
{
	this->m_baseGame.PrintReels();
	cout << endl;
	//cout << "GameControllerLogicLogic::Print..." << endl;

}

void GameControllerLogic::PrintPayline(const Payline& payline) const
{
	for (int i = 0; i < GAME_REELS; i++)
	{
		cout << payline.figure[i] << "\t";
	}
	cout << endl;
}

void GameControllerLogic::PrintPaylines() const
{
	for (int i = 0; i < (int) this->m_baseGame.GetVecPaylines().size(); i++)
	{
		cout << "PayLine " << i + 1 << ":\t";
		this->PrintPayline(this->m_baseGame.GetVecPaylines()[i]);
	}
}

void GameControllerLogic::PrintCredits() const
{
	cout << "Credits: " << this->CreditsAsString() << endl;
}

void GameControllerLogic::PrintBetPerLine() const
{
	cout << "BetPerLine: " << this->BetPerLineAsString() << endl;
}

void GameControllerLogic::PrintNumLines() const
{
	cout << "Number of Paylines: " << this->NumberOfLinesAsString()
			<< endl;
}

void GameControllerLogic::PrintTotalBet() const
{
	cout << "Total Bet: " << this->TotalBetAsString() << endl;
}

void GameControllerLogic::PrintWin() const
{
	cout << "Win: " << this->WinAsString() << endl;
}

//erase the contents from the vector, holding the paylines
void GameControllerLogic::ErasePaylines()
{
	//check if the vector is empty
	if (!this->m_baseGame.GetVecPaylines().empty())
	{
		//iterator pointing to the first element of the payline vector
		vector<Payline>::iterator paylinesBegin =
				this->m_baseGame.GetVecPaylines().begin();
		//iterator pointing to the one after last element of payline vector
		vector<Payline>::iterator paylinesEnd =
				this->m_baseGame.GetVecPaylines().end();
		//erase the contents of the vector
		this->m_baseGame.GetVecPaylines().erase(paylinesBegin, paylinesEnd);
	}
}

//initialize each payline individually
void GameControllerLogic::InitPayline1()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline2()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline3()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline4()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline5()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline6()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline7()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline8()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline9()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline10()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline11()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline12()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline13()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline14()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline15()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline16()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline17()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline18()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline19()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline20()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline21()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline22()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline23()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline24()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameControllerLogic::InitPayline25()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

