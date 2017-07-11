/*
 * GameController_PaylineMethods.cpp
 *
 *  Created on: Jul 11, 2017
 *      Author: SimoAngelov
 */

#include "GameController.h"

//initialize each payline individually
void GameController::InitPayline1()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0], this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline2()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0], this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline3()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0], this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline4()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0], this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline5()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0], this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline6()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][2], this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline7()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0], this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline8()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0], this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline9()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0], this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline10()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0], this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline11()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0], this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline12()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0], this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline13()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0], this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline14()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0], this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline15()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0], this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline16()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0], this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline17()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0], this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[1][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline18()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0], this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline19()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0], this->m_baseGame.GetMatrixGameReels()[1][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline20()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0], this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline21()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0], this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline22()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0], this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[2][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline23()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[1][0], this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[0][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[1][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline24()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[0][0], this->m_baseGame.GetMatrixGameReels()[0][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[2][3],
			this->m_baseGame.GetMatrixGameReels()[2][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}

void GameController::InitPayline25()
{
	Payline line =
	{ this->m_baseGame.GetMatrixGameReels()[2][0], this->m_baseGame.GetMatrixGameReels()[2][1],
			this->m_baseGame.GetMatrixGameReels()[1][2],
			this->m_baseGame.GetMatrixGameReels()[0][3],
			this->m_baseGame.GetMatrixGameReels()[0][4] };
	this->m_baseGame.m_vecPaylines.push_back(line);
}



