/*
 * GameController.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: SimoAngelov
 */

#include "GameControllerLogic.hpp"

//member field to control the number of betting steps
int GameControllerLogic::m_iBetStep = 0;

//member field to hold the bets at each step
vector<BET> GameControllerLogic::m_vecBetPerStep
{ eBet0, eBet1, eBet2, eBet3, eBet4, eBet5, eBet6, eBet7, eBet8, eBet9, eBet10,
		eBet11, eBet12, eBet13, eBet14, eBet15 };

//member field to keep track of which figures are selected at each reel
bool GameControllerLogic::m_bFigureIsSelected[eNUM_FIGURES] =
{ false };

//initialize the bonus counter
int GameControllerLogic::m_iBonusCounter = 0;

//member field to keep track of the choice the player made during the bonus game
COLOR GameControllerLogic::m_playerChoice = eInvalidColor;
//member field to keep track if the player wants to keep the bonus game
bool GameControllerLogic::m_bQuitBonusGame = false;

//constructor
GameControllerLogic::GameControllerLogic() :
		m_baseGame()
{
	// TODO Auto-generated constructor stub
}

//GameControllerLogic::~GameController()
//{
//// TODO Auto-generated destructor stub
//}

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
//	if (!(this->TotalBetExceedsCredits()))
//	{
//		//subtract the current bet from the credits
//		this->AddTotalBetToCredits();
//		//init the reels and set the paylines
		this->InitCurrentReels();
//		this->InitCurrentPaylines();
//		//Calculate the winnings from the spin
//		this->SetTotalWin();
//		//test cout
//		cout << "GameController::VALID SPIN" << endl;
//	} // end if
}

//intialize the reels for the currentGame
void GameControllerLogic::InitCurrentReels()
{
	this->InitRandomReels();
//	this->SetSpecialFigure();

//	this->SetUniqueFigures();

//	this->SetTheSameFigures();

	this->StartBonusGame();

}

//initialize the game reels with random values
void GameControllerLogic::InitRandomReels()
{
	//seed a random sequence of numbers
	srand(time(0));
//traverse each reel
	for (int iCol = 0; iCol < GAME_REELS; iCol++)
	{
//traverse each element of the reel
		for (int iRow = 0; iRow < GAME_ROWS; iRow++)
		{
			//choose a figure between 1 and 8
			Figures randomFigure = static_cast<Figures>(rand() % eFigure9);
			this->m_baseGame.SetReelElement(randomFigure, iRow, iCol);
		} //end row for
	} // end reel for
}

//set the special figure in each game reel
void GameControllerLogic::SetSpecialFigure()
{
	//seed a random sequence of numbers
	srand(time(0));
//traverse each reel
	for (int iCol = 0; iCol < GAME_REELS; iCol++)
	{
//traverse each element of the reel
		for (int iRow = 0; iRow < GAME_ROWS; iRow++)
		{
			Figures randomFigure = static_cast<Figures>(rand() % eNUM_FIGURES);
			if (randomFigure == eFigure9)
			{
				//if the current figure is 9 aka special, break the inner loop
				//GameModel::m_iGameReels[iRow][iCol] = randomFigure;
				this->m_baseGame.SetReelElement(randomFigure, iRow, iCol);
				//test cout
				cout << "GameControllerLogic::bonus counter ="
						<< GameControllerLogic::m_iBonusCounter << endl;
				GameControllerLogic::m_iBonusCounter++;
				break;
			} //end if
		} //end row for
	} //end reel for
}

//hardcode a special figure at each reel to test the bonus game
void GameControllerLogic::StartBonusGame()
{
	//seed a random sequence of numbers
	srand(time(0));
//traverse each reel
	for (int iCol = 0; iCol < GAME_REELS; iCol++)
	{
		int iRandomRow= rand() % 3;
		Figures specialFigure = eFigure9;
		this->m_baseGame.SetReelElement(specialFigure, iRandomRow, iCol);
		//test cout
		cout << "GameController::bonus counter ="
				<< GameControllerLogic::m_iBonusCounter << endl;
		GameControllerLogic::m_iBonusCounter++;
	} //end reel for
}

//set unique figures per each reel
void GameControllerLogic::SetUniqueFigures()
{
	//seed a random sequence of numbers
	srand(time(0));
//traverse each reel
	for (int iCol = 0; iCol < GAME_REELS; iCol++)
	{
//traverse each element of the reel
		for (int iRow = 0; iRow < GAME_ROWS; iRow++)
		{
			//while the current element has an invalid value
			while (this->m_baseGame.GetReelElement(iRow, iCol) == eInvalidFigure)
			{
				//pick a random figure
				Figures randomFigure = static_cast<Figures>(rand() % eFigure9);
				//check to see if it hasn't been selected
				if (m_bFigureIsSelected[randomFigure] == false)
				{
					//if it hasn't been selected, set the bool value to true
					this->m_baseGame.SetReelElement(randomFigure, iRow, iCol);
					m_bFigureIsSelected[randomFigure] = true;
					//if the selected figure is Special
					if (randomFigure == eFigure9)
					{
						GameControllerLogic::m_iBonusCounter++;
					}
				}
			} //end while
			  //set the figureIsSelected to false for the next reel
			GameControllerLogic::m_bFigureIsSelected[eNUM_FIGURES] = false;
		} //end row for
	} // end reel for
}

//set unique figures per each reel
void GameControllerLogic::SetTheSameFigures()
{
	//seed a random sequence of numbers
	srand(time(0));
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
	if (this->GetCredits() >= MAX_TOTAL_BET)
	{
		this->SetBetPerPayline(MAX_BET_STEP - 1);
		this->SetNumberOfPaylines(MAX_PAYLINES);
	}
}

//increase the number of paylines
void GameControllerLogic::IncreasePaylines()
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
void GameControllerLogic::DecreasePaylines()
{
	int iNumPayLines = this->GetNumberOfLines();
	if (iNumPayLines > MIN_PAYLINES)
	{
		this->SetNumberOfPaylines(--iNumPayLines);
		this->SetTotalBet();
	}
}

//set the number of paylines for the current game
void GameControllerLogic::SetNumberOfPaylines(int iNumberOfPaylines)
{
	this->m_baseGame.SetINumberOfLines(iNumberOfPaylines);
}

//check if the payline increase exceeds the current amount of credits
bool GameControllerLogic::PaylinesExceedCredits(int iNextStep)
{
	int iAvailableCredits = this->m_baseGame.GetICredits();
	int iNewNumLines = iNextStep;
	int iCurrBet = this->m_baseGame.GetIBetPerLine();
	int iNewBet = iNewNumLines * iCurrBet;
	return iNewBet > iAvailableCredits;
}

//increase the bet by 1 step
void GameControllerLogic::IncreaseBet()
{
	int iCurrentStep = GameControllerLogic::m_iBetStep;
//check if the betting step doesn't exceed the max value
	if (iCurrentStep <= MAX_BET_STEP)
	{
		int iNextStep = iCurrentStep + 1;
//check if the incremented step doesn't cause
//total bet to exceed the current amount of credits
		if (!(this->BetExceedsCredits(iNextStep)))
		{
			GameControllerLogic::m_iBetStep++;
			this->SetBetPerPayline(GameControllerLogic::m_iBetStep);
			this->SetTotalBet();
		}
	}
}

//decrease the bet by 1 step
void GameControllerLogic::DecreaseBet()
{
	if (GameControllerLogic::m_iBetStep > 0)
	{
		GameControllerLogic::m_iBetStep--;
		this->SetBetPerPayline(GameControllerLogic::m_iBetStep);
		this->SetTotalBet();
	}

}

//set the bet per line, depending on the number of steps
void GameControllerLogic::SetBetPerPayline(int iStep)
{
	int iBet = this->m_vecBetPerStep[iStep];
	this->m_baseGame.SetIBetPerLine(iBet);
}

//check if the bet increase exceeds the current amount of credits
bool GameControllerLogic::BetExceedsCredits(int iNextStep)
{
	int iAvailableCredits = this->m_baseGame.GetICredits();
	int iCurrNumLines = this->m_baseGame.GetINumberOfLines();
	int iNewBet = this->m_vecBetPerStep[iNextStep];
	int iNewTotalBet = iCurrNumLines * iNewBet;
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
	if(this->IsBonusGame())
	{
		//test cout
		cout << "GameController:: This is Bonus Game" << endl;
		//start the bonus game by passing the win and credits as arguments
		//BonusGame::InitBonusGame(&this->m_baseGame);
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
		if (this->WinFromSinglePayline(currentPayline) > 0)
			cout << "GameController::Win for line" << i + 1 << ": "
					<< this->WinFromSinglePayline(currentPayline) << endl;
	}
	int currentWinnings = this->GetWin();
	int newWinnings = currentWinnings + winFromPaylines;
	this->m_baseGame.SetIWin(newWinnings);
}

//calculate the win from a single line based on the figures
int GameControllerLogic::WinFromSinglePayline(const Payline& payline)
{
//this function finds the maximum sequence of equal figures
	Figures bestFigure = eInvalidFigure;
	int iBestOccurrence = 0;

//initialize the bestFigure with the first element of the line
	Figures currentFigure = payline.figure[0];
	int iCurrentOccurrence = 1;

//traverse the rest of the line
	for (int i = 1; i < GAME_REELS; i++)
	{
//increment the occurrence of the figure
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

		if (iCurrentOccurrence >= iBestOccurrence)
		{
			iBestOccurrence = iCurrentOccurrence;
			bestFigure = currentFigure;
		}
	} //end for

//return the winnings from the line
	int iFigCoeff = this->FigureCoefficient(bestFigure, iBestOccurrence);
	int iBet = this->m_baseGame.GetIBetPerLine();
	int winningsPerLine = iFigCoeff * iBet;
	return winningsPerLine;
}

//calculate the coefficient of a figure based on its weight
int GameControllerLogic::FigureCoefficient(const Figures& figure, int iOccurrences)
{
	int iWeight = 0;
	int iCoefficient = 0;
	switch (iOccurrences)
	{
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
		cout << "GameController::THERE IS A WIN" << endl;
		//add the win to the credits
		int iCurrCredits = this->GetCredits();
		int iCurrWin = this->GetWin();
		int iNewCredits = iCurrCredits + iCurrWin;
		this->m_baseGame.SetICredits(iNewCredits);
	}
}


//check if bonus game. if yes - initialize it
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

//printing functions

void GameControllerLogic::PrintInfo() const
{
	cout << "==GameController==" << endl;
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
//	for (int iRow = 0; iRow < GAME_ROWS; iRow++)
//	{
//		for (int iCol = 0; iCol < GAME_REELS; iCol++)
//		{
//			//cout << GameModel::m_iGameReels[iRow][iCol] << "\t";
//			cout << this->m_baseGame.GetMatrixGameReels()[iRow][iCol] << "\t";
//		}
//		cout << endl;
//	}
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
	cout << "Credits: " << this->m_baseGame.GetICredits() << endl;
}

void GameControllerLogic::PrintBetPerLine() const
{
	cout << "BetPerLine: " << this->m_baseGame.GetIBetPerLine() << endl;
}

void GameControllerLogic::PrintNumLines() const
{
	cout << "Number of Paylines: " << this->m_baseGame.GetINumberOfLines()
			<< endl;
}

void GameControllerLogic::PrintTotalBet() const
{
	cout << "Total Bet: " << this->m_baseGame.GetITotalBet() << endl;
}

void GameControllerLogic::PrintWin() const
{
	cout << "Win: " << this->m_baseGame.GetIWin() << endl;
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

