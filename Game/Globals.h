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



//define a user type for a line
typedef struct Payline
{
	int figure[5];
} Line;

//number of reels
const int GAME_REELS = 5;

//number of rows
const int GAME_ROWS = 3;

//number of winning paylines
const int MAX_PAYLINES = 25;

//enumerator for the figures
typedef enum
{
	eFigure1,
	eFigure2,
	eFigure3,
	eFigure4,
	eFigure5,
	eFigure6,
	eFigure7,
	eFigure8,
	eFigure9
} Figures;

#endif /* GLOBALS_H_ */
