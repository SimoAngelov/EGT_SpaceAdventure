/*
 * GameController.h
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include "GameModel.h"
#include "BonusGame.h"
class GameController
{
private:
	GameModel m_baseGame;
	vector<vector<int> > m_matrixGameReels;
	static int m_iBetStep;
	static vector<BET> m_vecBetPerStep;
	static bool m_bFigureIsSelected[eNUM_FIGURES];
	static int m_iBonusCounter;
	BonusGame m_bonusGame;
	static COLOR m_playerChoice;
	static bool m_bQuitBonusGame;
	//set default values for the member fields
	void SetDefault();
	//insert credits in order to play
	void InsertCredits(int);
	//set random values for the reels
	void InitRandomReels();
	//set the special figure per reel, random appearance
	void SetSpecialFigure();
	//set unique figures for each reel
	void SetUniqueFigures();
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
	//bonus game round1
	void BonusWin1(const COLOR&);
	//bonus game round2
	void BonusWin2(const COLOR&);
public:
	GameController();
	virtual ~GameController();

	//increase the credits
	void IncreaseCredits();
	//decrease the credits
	void DecreaseCredits();

	//spin the reels and set the paylines
	void Spin();
	//check if the total credit doesn't fall in range of the current
	//amount of credits
	bool TotalBetExceedsCredits();

	//increase the number of paylines
	void IncreasePaylines();
	//decrease the number of paylines
	void DecreasePaylines();

	//increase, decrease the bet
	void IncreaseBet();
	void DecreaseBet();

	//set the total winnnings from the paylines and bonus game
	void SetTotalWin();
	//calculate current winnings from the paylines
	void WinFromPaylines();
	//quit the bonus game
	bool QuitBonusGame();
	//if player wants to play bonus game round 1
	void PlayBonusRoundOne();
	//if player wants to play bonus game round 2
	void PlayBonusRoundTwo();
	//if player selected a black card
	void SelectBlackCard();
	//if the player selected a red card
	void SelectRedCard();

	//Getters
	int GetBetPerLine() const;
	int GetCredits() const;
	int GetNumberOfLines() const;
	int GetTotalBet() const;
	int GetWin() const;

	//print functions
	void PrintReels() const;
	void PrintPayline(const Payline&) const;
	void PrintPaylines() const;
	void PrintCredits() const;
	void PrintBetPerLine() const;
	void PrintNumLines() const;
	void PrintTotalBet() const;
	void PrintWin() const;

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
