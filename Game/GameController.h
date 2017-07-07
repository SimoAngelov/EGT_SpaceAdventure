/*
 * GameController.h
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include "GameModel.h"
class GameController
{
private:
	GameModel m_baseGame;
	static int m_iBetStep;
	void InitRandomReels();
	void SetSpecialFigure();


public:
	GameController();
	virtual ~GameController();

	//start a new game
	void Spin();
	//initialize the reels for the current game
	void InitCurrentReels();
	//set the paylines for the current game
	void InitCurrentPaylines();

	//insert credits in order to play
	void InsertCredits(int);
	//set the number of paylines
	void SetNumberOfPaylines(int);

	//increase, decrease and set the bet
	void IncreaseBet();
	void DecreaseBet();
	void SetBetPerPayline(int);

	//calculate current winnings from the paylines
	void WinFromPaylines();
	//calculate current winning from a single payline
	int WinFromSinglePayline(const Payline&);
	//calculate the winnings per Figure
	int WinPerFigure(const Figures&, int);


	//print functions
	void PrintReels() const;
	void PrintPayline(const Payline&) const;
	void PrintPaylines() const;
private:
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
