/*
 * GameController.h
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include "../../Model/GameModel.h"
#include "../BonusGameController/BonusGame.h"
#include "../GameRecovery/GameRecovery.h"
class GameController
{
private:
	GameModel m_baseGame;
	static int m_iBetStep;
	static vector<BET> m_vecBetPerStep;
	static int m_iBonusCounter;
	vector<int> m_vecWinningLines;
	//set default values for the member fields
	void SetDefault();
	//set random values for the reels
	void InitRandomReels();
	//set the special figure per reel, random appearance
	void SetSpecialFigure();
	//hardcode a special figure at each reel to test the bonus game
	void StartBonusGame();
	//set the same figures on all the reels to test the win function
	void SetTheSameFigures();
	//initialize the reels for the current game
	void InitCurrentReels();
	//set the paylines for the current game
	void InitCurrentPaylines();
	//set the totalBet
	void SetTotalBet();
	//subtract the total bet from the credits
	void AddTotalBetToCredits();
	//set the total winnnings from the paylines and bonus game
	void SetTotalWin();
	//calculate current winning from a single payline
	int WinFromSinglePayline(const Payline&);
	//calculate the coefficient per Figure
	int FigureCoefficient(const Figures&, int);
	//add the win from the paylines to the credit
	void AddWinToCredits();
	//set the number of paylines
	void SetNumberOfPaylines(int);
	//set the bet per line
	void SetBetPerPayline(int);
	//check if the bet increase exceeds the current amount of credits
	bool BetExceedsCredits(int);
	//check if the payline increase exceeds the current amount of credits
	bool PaylinesExceedCredits(int);


public:
	GameController();
	virtual ~GameController();

	//start new game
	void NewGame();
	//load old game
	void LoadGame();
	//spin the reels and set the paylines
	void Spin();
	//check if the total credit doesn't fall in range of the current
	//amount of credits
	bool TotalBetExceedsCredits();

	//set the bet per line and number of lines to their maximum values
	void MaxBet();
	//increase the number of paylines
	void IncreasePaylines();
	//decrease the number of paylines
	void DecreasePaylines();

	//increase, decrease the bet
	void IncreaseBet();
	void DecreaseBet();

	//calculate current winnings from the paylines
	void WinFromPaylines();

	//check if bonus game, if yes - initialize it
	bool IsBonusGame();


	//Getters
	const vector<vector<Figures> >& GetGameReels() const;
	int GetBetPerLine() const;
	int GetCredits() const;
	int GetNumberOfLines() const;
	int GetTotalBet() const;
	int GetWin() const;
	const vector<int>& GetWinningPaylines() const;
	//to_string methods
	string BetPerLineAsString() const;
	string CreditsAsString() const;
	string NumberOfLinesAsString() const;
	string TotalBetAsString() const;
	string WinAsString() const;
	string WinningPaylinesAsString() const;
	//print functions
	void PrintInfo() const;
	void PrintReels() const;
	void PrintPayline(const Payline&) const;
	void PrintPaylines() const;
	void PrintWinningPaylines() const;
	void PrintCredits() const;
	void PrintBetPerLine() const;
	void PrintNumLines() const;
	void PrintTotalBet() const;
	void PrintWin() const;
	//set the credits to null for cashout
	void SetNullCredits();
private:
	void ErasePaylines();
	void InitPayline1();
	void InitPayline2();
	void InitPayline3();
	void InitPayline4();
	void InitPayline5();
	void InitPayline6();
	void InitPayline7();
	void InitPayline8();
	void InitPayline9();
	void InitPayline10();
	void InitPayline11();
	void InitPayline12();
	void InitPayline13();
	void InitPayline14();
	void InitPayline15();
	void InitPayline16();
	void InitPayline17();
	void InitPayline18();
	void InitPayline19();
	void InitPayline20();
	void InitPayline21();
	void InitPayline22();
	void InitPayline23();
	void InitPayline24();
	void InitPayline25();
};

#endif /* GAMECONTROLLER_H_ */
