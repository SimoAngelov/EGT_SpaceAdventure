/*
 * GameController.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: SimoAngelov
 */

#include "GameController.h"
#include <exception>
int GameController::m_iBetStep = 0;
//member field to control the number of betting steps


//member field to hold the bets at each step
vector<BET> GameController::m_vecBetPerStep
{ eBet0, eBet1, eBet2, eBet3, eBet4, eBet5, eBet6, eBet7, eBet8, eBet9, eBet10,
		eBet11, eBet12, eBet13, eBet14, eBet15 };

//initialize the bonus counter
int GameController::m_iBonusCounter = 0;


//constructor
GameController::GameController() :
		m_baseGame(), m_vecWinningLines()
{
}

GameController::~GameController()
{
// TODO Auto-generated destructor stub
}

//start new game
void GameController::NewGame()
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
void GameController::LoadGame()
{
	//update the game model with info from the xml file
	GameRecovery::LoadGameModel(&(this->m_baseGame));
	//initialize the vector of paylines
	this->InitCurrentPaylines();
}

//set default values for the member fields
void GameController::SetDefault()
{
	GameController::m_iBonusCounter = 0;
	this->SetTotalBet();
	this->m_baseGame.SetIWin(0);
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
		GameRecovery::UpdateGameModel(&(this->m_baseGame));
	} // end if
}

//intialize the reels for the currentGame
void GameController::InitCurrentReels()
{
	//initialize the reels with figures from 0 to 7
	this->InitRandomReels();
	//randomly set or don't set a special figure for a row
//	this->SetSpecialFigure();
	//set a special figure for all the rows
	this->StartBonusGame();
}

//initialize the game reels with random values
void GameController::InitRandomReels()
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
		} //end row for
	} // end reel for
}

//set the special figure in each game reel
void GameController::SetSpecialFigure()
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
				this->m_baseGame.SetReelElement(randomFigure, iReel, iRow);
				//increment the bonus counter
				GameController::m_iBonusCounter++;
				break;
			} //end if
		} //end reel for
	} //end row for
}

//hardcode a special figure at each reel to test the bonus game
void GameController::StartBonusGame()
{
	//seed a random sequence of numbers
	srand(time(0));
//traverse each reel
	for (int iReel = 0; iReel < GAME_REELS; iReel++)
	{
		int iRandomRow = rand() % 3;
		Figures specialFigure = eFigure9;
		this->m_baseGame.SetReelElement(specialFigure, iRandomRow, iReel);
		//increment the bonus counter
		GameController::m_iBonusCounter++;
	} //end reel for
}

//set the same figures per each reel
void GameController::SetTheSameFigures()
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
void GameController::InitCurrentPaylines()
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
void GameController::MaxBet()
{
	//if the available credits are above the max bet
	if (this->GetCredits() >= MAX_TOTAL_BET)
	{
		//update the betting step
		GameController::m_iBetStep = MAX_BET_STEP - 1;
		//set the bet per line to max
		this->SetBetPerPayline(GameController::m_iBetStep);
		//set the number of paylines to max
		this->SetNumberOfPaylines(MAX_PAYLINES);
	} //end if
}

//increase the number of paylines
void GameController::IncreasePaylines()
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
void GameController::DecreasePaylines()
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
void GameController::SetNumberOfPaylines(int iNumberOfPaylines)
{
	this->m_baseGame.SetINumberOfLines(iNumberOfPaylines);
}

//check if the payline increase exceeds the current amount of credits
bool GameController::PaylinesExceedCredits(int iNextStep)
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
void GameController::IncreaseBet()
{
	int iCurrentStep = GameController::m_iBetStep;
//check if the betting step doesn't exceed the max value
	if (iCurrentStep <= MAX_BET_STEP - 1)
	{
		int iNextStep = iCurrentStep + 1;
//check if the incremented step doesn't cause
//total bet to exceed the current amount of credits
		if (!(this->BetExceedsCredits(iNextStep)))
		{
			GameController::m_iBetStep++;
			this->SetBetPerPayline(GameController::m_iBetStep);
		}//end if bet does not exceed credits
	} //end if the current step doesn't exceed the the max value
}

//decrease the bet by 1 step
void GameController::DecreaseBet()
{
	if (GameController::m_iBetStep > 0)
	{
		//decrement the bet step
		GameController::m_iBetStep--;
		//update the bet per line
		this->SetBetPerPayline(GameController::m_iBetStep);
		//update the total bet
		this->SetTotalBet();
	}

}

//set the bet per line, depending on the number of steps
void GameController::SetBetPerPayline(int iStep)
{
	//take the bet from the vector
	int iBet = this->m_vecBetPerStep[iStep];
	//update the bet per line in the model
	this->m_baseGame.SetIBetPerLine(iBet);
}

//check if the bet increase exceeds the current amount of credits
bool GameController::BetExceedsCredits(int iNextStep)
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
void GameController::SetTotalBet()
{
	this->m_baseGame.SetITotalBet();
}

//subtract the total bet from the credits
void GameController::AddTotalBetToCredits()
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
	//save the win and credits to XML
	GameRecovery::UpdateWin(this->GetWin());
	GameRecovery::UpdateCredits(this->GetCredits());
	//check if bonus game
	if (this->IsBonusGame())
	{
		//start the bonus game by the game model by reference
		BonusGame::InitBonusGame(&this->m_baseGame);
	}
}

//calculate the win from the selected paylines
void GameController::WinFromPaylines()
{
	int winFromPaylines = 0;
	for (int iLine = 0; iLine < this->GetNumberOfLines(); iLine++)
	{
		Payline currentPayline = this->m_baseGame.GetVecPaylines()[iLine];
		winFromPaylines += this->WinFromSinglePayline(currentPayline);
		//if it is a winning payline add it to the winning paylines vector
		if (this->WinFromSinglePayline(currentPayline) > 0)
		{
			this->m_vecWinningLines.push_back(iLine + 1);
		}//end if winnig line
	}// end line traversal
	int currentWinnings = this->GetWin();
	int newWinnings = currentWinnings + winFromPaylines;
	this->m_baseGame.SetIWin(newWinnings);
}

//calculate the win from a single line based on the figures
//this function finds the maximum sequence of equal figures
int GameController::WinFromSinglePayline(const Payline& payline)
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
int GameController::FigureCoefficient(const Figures& figure, int iOccurrences)
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
void GameController::AddWinToCredits()
{
	//if there was a win, add it to the credits
	if (this->GetWin() > 0)
	{
		//if bonus game - add 5 times max bet to the win
		if(this->IsBonusGame())
		{
			int iBonusWin = this->GetWin() + (5 * MAX_BET);
			this->m_baseGame.SetIWin(iBonusWin);
		}
		//add the win to the credits
		int iCurrCredits = this->GetCredits();
		int iCurrWin = this->GetWin();
		int iNewCredits = iCurrCredits + iCurrWin;
		this->m_baseGame.SetICredits(iNewCredits);
	}
}

//check if bonus game.
bool GameController::IsBonusGame()
{
	//pass the bonus counter to the bonus game
	bool result = BonusGame::IsBonusGame(GameController::m_iBonusCounter);
	//return the result
	return result;
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

const vector<int>& GameController::GetWinningPaylines() const
{
	return this->m_vecWinningLines;
}

//set the credits to null for cashout
void GameController::SetNullCredits()
{
	this->m_baseGame.SetICredits(0);
	GameRecovery::UpdateCredits(0);
}

//to string methods
string GameController::BetPerLineAsString() const
{
	string res = itos(this->m_baseGame.GetIBetPerLine());
	return res;
}

string GameController::CreditsAsString() const
{
	string res = itos(this->m_baseGame.GetICredits());
	return res;
}

string GameController::NumberOfLinesAsString() const
{
	string res = itos(this->m_baseGame.GetINumberOfLines());
	return res;
}

string GameController::TotalBetAsString() const
{
	string res = itos(this->m_baseGame.GetITotalBet());
	return res;
}

string GameController::WinAsString() const
{
	string res = itos(this->m_baseGame.GetIWin());
	return res;
}

string GameController::WinningPaylinesAsString() const
{
	//string to hold the result
	string res;
	//string to hold the comma
	string comma = ",";
	int size = this->GetWinningPaylines().size();
	for(int i = 0; i < size; i++)
	{
		//get the current element from the vector
		int iCurrLine = this->GetWinningPaylines()[i];
		//convert it to string
		string strLine = itos(iCurrLine);
		//append it to the result
		res.append(strLine);
		//if not last element, append a comma
		if(i != (size - 1))
		{
			res.append(comma);
		}
	}//end vector for
	return res;
}
//printing functions

void GameController::PrintInfo() const
{
	cout << "==GameController==" << endl;
	this->PrintReels();
	this->PrintPaylines();
	this->PrintNumLines();
	this->PrintWinningPaylines();
	this->PrintBetPerLine();
	this->PrintTotalBet();
	this->PrintWin();
	this->PrintCredits();
}

void GameController::PrintReels() const
{
	this->m_baseGame.PrintReels();
	cout << endl;

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
	for (int i = 0; i < (int) this->m_baseGame.GetVecPaylines().size(); i++)
	{
		cout << "PayLine " << i + 1 << ":\t";
		this->PrintPayline(this->m_baseGame.GetVecPaylines()[i]);
	}
}

void GameController::PrintCredits() const
{
	cout << "Credits: " << this->CreditsAsString() << endl;
}

void GameController::PrintBetPerLine() const
{
	cout << "BetPerLine: " << this->BetPerLineAsString() << endl;
}

void GameController::PrintNumLines() const
{
	cout << "Number of Paylines: " << this->NumberOfLinesAsString()
			<< endl;
}

void GameController::PrintTotalBet() const
{
	cout << "Total Bet: " << this->TotalBetAsString() << endl;
}

void GameController::PrintWin() const
{
	cout << "Win: " << this->WinAsString() << endl;
}

void GameController::PrintWinningPaylines() const
{
	cout << "Winning lines: " << this->WinningPaylinesAsString() << endl;
}
//erase the contents from the vector, holding the paylines
void GameController::ErasePaylines()
{
	//check if the vector, holding the paylines is empty is empty
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
	//if the winnig paylines vector is not empty, erase its contents
	if(!this->m_vecWinningLines.empty())
	{
		//iterator pointing to the first element of the winning payline vector
		vector<int>::iterator paylinesBegin =
				this->m_vecWinningLines.begin();
		//iterator pointing to the one after last element of  the winning payline vector
		vector<int>::iterator paylinesEnd =
				this->m_vecWinningLines.end();
		//erase the contents of the vector
		this->m_vecWinningLines.erase(paylinesBegin, paylinesEnd);
	}
}

//initialize each payline individually
void GameController::InitPayline1()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline2()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline3()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline4()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline5()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline6()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline7()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline8()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline9()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline10()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline11()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline12()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline13()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline14()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline15()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline16()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline17()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline18()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline19()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline20()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline21()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline22()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline23()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline24()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0],
			this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.AddPayline(line);
}

void GameController::InitPayline25()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0],
			this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.AddPayline(line);
}


