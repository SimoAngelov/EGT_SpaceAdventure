//
//  Controller3_Slot.cpp
//  SpaceAdventure_ViewControllers
//
//  Created by Ichko  on 11/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "Controller3_Slot.hpp"

Slot::Slot()
{

}

// Set Methods

void Slot::SetSlotTexture(SDL_Texture* texture)
{
	slotTexture = texture;
}

void Slot::SetStartSpinButton(SDL_Texture* texture)
{
	startSpinButton = texture;
}

void Slot::SetStartSpinButtonPushed(SDL_Texture* texture)
{
	startSpinButtonPushed = texture;
}

void Slot::SetMaxBetButton(SDL_Texture* texture)
{
	maxBetButton = texture;
}

void Slot::SetMaxBetButtonPushed(SDL_Texture* texture)
{
	maxBetButtonPushed = texture;
}

void Slot::SetPlusLinesButton(SDL_Texture* texture)
{
	plusLinesButton = texture;
}

void Slot::SetPlusLinesButtonPushed(SDL_Texture* texture)
{
	plusLinesButtonPushed = texture;
}

void Slot::SetMinusButtonLines(SDL_Texture* texture)
{
	minusButtonLines = texture;

}

void Slot::SetMinusButtonLinesPushed(SDL_Texture* texture)
{
	minusButtonLinesPushed = texture;
}

void Slot::SetMinusButtonBet(SDL_Texture* texture)
{
	minusButtonBet = texture;
}

void Slot::SetMinusButtonBetPushed(SDL_Texture* texture)
{
	minusButtonBetPushed = texture;
}

void Slot::SetPlusButtonBet(SDL_Texture* texture)
{
	plusButtonBet = texture;
}

void Slot::SetPlusButtonBetPushed(SDL_Texture* texture)
{
	plusButtonBetPushed = texture;
}

// Get Methods;

SDL_Texture* Slot::GetSlotTexture()
{
	return slotTexture;
}

SDL_Texture* Slot::GetStartSpinButton()
{
	return startSpinButton;
}

SDL_Texture* Slot::GetStartSpinButtonPushed()
{
	return startSpinButtonPushed;
}

SDL_Texture* Slot::GetMaxBetButton()
{
	return maxBetButton;
}

SDL_Texture* Slot::GetMaxBetButtonPushed()
{
	return maxBetButtonPushed;
}

SDL_Texture* Slot::GetPlusLinesButton()
{
	return plusLinesButton;
}

SDL_Texture* Slot::GetPlusLinesButtonPushed()
{
	return plusLinesButtonPushed;
}

SDL_Texture* Slot::GetMinusButtonLines()
{
	return minusButtonLines;
}

SDL_Texture* Slot::GetMinusButtonLinesPushed()
{
	return minusButtonLinesPushed;
}

SDL_Texture* Slot::GetMinusButtonBet()
{
	return minusButtonBet;
}

SDL_Texture* Slot::GetMinusButtonBetPushed()
{
	return minusButtonBetPushed;
}

SDL_Texture* Slot::GetPlusButtonBet()
{
	return plusButtonBet;
}

SDL_Texture* Slot::GetPlusButtonBetPushed()
{
	return plusButtonBetPushed;
}
