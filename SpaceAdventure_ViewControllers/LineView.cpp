/*
 * LineView.cpp
 *
 *  Created on: 11.07.2017 ã.
 *      Author: user
 */

#include "LineView.h"

LineView::LineView()
{
	// TODO Auto-generated constructor stub

}

LineView::~LineView()
{
	// TODO Auto-generated destructor stub
}

void LineView::SetFirstRow(SDL_Texture* texture)
{
	firstRow = texture;
}

void LineView::SetSecondRow(SDL_Texture* texture)
{
	secondRow = texture;
}

void LineView::SetThirdRow(SDL_Texture* texture)
{
	thirdRow = texture;
}

void LineView::SetFourthRow(SDL_Texture* texture)
{
	fourthRow = texture;
}

SDL_Texture* LineView::GetFirstRow()
{
	return firstRow;
}

SDL_Texture* LineView::GetSecondRow()
{
	return secondRow;
}

SDL_Texture* LineView::GetThirdRow()
{
	return thirdRow;
}

SDL_Texture* LineView::GetFourthRow()
{
	return fourthRow;
}
