/*
 * Globals.h
 *
 *  Created on: Jul 6, 2017
 *      Author: SimoAngelov
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <vector>
using std::vector;
#include <ctime>
#include <cstdlib>
#include <iostream>
using std::endl;
using std::cout;

//enumerator for the figures
typedef enum
{
	eInvalidFigure = -1,
	eFigure1,
	eFigure2,
	eFigure3,
	eFigure4,
	eFigure5,
	eFigure6,
	eFigure7,
	eFigure8,
	eFigure9,
	eNUM_FIGURES
} Figures;

//define a user type for a line
typedef struct Payline
{
	Figures figure[5];
} Payline;

//number of reels
const int GAME_REELS = 5;

//number of rows
const int GAME_ROWS = 3;

//min number of paylines
const int MIN_PAYLINES = 1;
//max number of paylines
const int MAX_PAYLINES = 25;

//min amount of credits per single bet
const int MIN_BET = 1;
//max amount of credits per single bet
const int MAX_BET = 2000;

//max number of betting steps
const int MAX_BET_STEP = 15;

//betting amount for each step
typedef enum
{
	eBet0 = 1,
	eBet1 = 2,
	eBet2 = 5,
	eBet3 = 10,
	eBet4 = 25,
	eBet5 = 50,
	eBet6 = 75,
	eBet7 = 100,
	eBet8 = 250,
	eBet9 = 500,
	eBet10 = 750,
	eBet11 = 1000,
	eBet12 = 1250,
	eBet13 = 1500,
	eBet14 = 1750,
	eBet15 = 2000
} BET;

#endif /* GLOBALS_H_ */
