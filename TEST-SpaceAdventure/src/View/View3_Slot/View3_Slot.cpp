//
//  View3_Slot.cpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 21/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "View3_Slot.hpp"

Slot::Slot()
{
    
}

// Set Methods ->

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

void Slot:: SetFigure1(SDL_Texture* texture)
{
    eFigure1 = texture;
}

void Slot::SetFigure2(SDL_Texture* texture)
{
    eFigure2 = texture;
}

void Slot::SetFigure3(SDL_Texture* texture)
{
    eFigure3 = texture;
}

void Slot::SetFigure4(SDL_Texture* texture)
{
    eFigure4 = texture;
}

void Slot::SetFigure5(SDL_Texture* texture)
{
    eFigure5 = texture;
}

void Slot::SetFigure6(SDL_Texture* texture)
{
    eFigure6 = texture;
}

void Slot::SetFigure7(SDL_Texture* texture)
{
    eFigure7 = texture;
}

void Slot::SetFigure8(SDL_Texture* texture)
{
    eFigure8 = texture;
}

void Slot::SetFigure9(SDL_Texture* texture)
{
    eFigure9 = texture;
}

void Slot:: SetCashOutButton(SDL_Texture* texture)
{
    cashOutButton = texture;
}

void Slot:: SetCashOutButtonPushed(SDL_Texture* texture)
{
    cashOutButtonPushed = texture;
}

void Slot:: SetWhiteScreenTexture(SDL_Texture* texture)
{
    whiteScreenTexture = texture;
}

void Slot::SetLine1(SDL_Texture* texture)
{
    line1 = texture;
}

void Slot::SetLine2(SDL_Texture* texture)
{
    line2 = texture;
}

void Slot::SetLine3(SDL_Texture* texture)
{
    line3 = texture;
}

void Slot::SetLine4(SDL_Texture* texture)
{
    line4 = texture;
}

void Slot::SetLine5(SDL_Texture* texture)
{
    line5 = texture;
}

void Slot::SetLine6(SDL_Texture* texture)
{
    line6 = texture;
}

void Slot::SetLine7(SDL_Texture* texture)
{
    line7 = texture;
}

void Slot::SetLine8(SDL_Texture* texture)
{
    line8 = texture;
}

void Slot::SetLine9(SDL_Texture* texture)
{
    line9 = texture;
}

void Slot::SetLine10(SDL_Texture* texture)
{
    line10 = texture;
}

void Slot::SetLine11(SDL_Texture* texture)
{
    line11 = texture;
}

void Slot::SetLine12(SDL_Texture* texture)
{
    line12 = texture;
}

void Slot::SetLine13(SDL_Texture* texture)
{
    line13 = texture;
}

void Slot::SetLine14(SDL_Texture* texture)
{
    line14 = texture;
}

void Slot::SetLine15(SDL_Texture* texture)
{
    line15 = texture;
}

void Slot::SetLine16(SDL_Texture* texture)
{
    line16 = texture;
}

void Slot::SetLine17(SDL_Texture* texture)
{
    line17 = texture;
}

void Slot::SetLine18(SDL_Texture* texture)
{
    line18 = texture;
}

void Slot::SetLine19(SDL_Texture* texture)
{
    line19 = texture;
}

void Slot::SetLine20(SDL_Texture* texture)
{
    line20 = texture;
}

void Slot::SetLine21(SDL_Texture* texture)
{
    line21 = texture;
}

void Slot::SetLine22(SDL_Texture* texture)
{
    line22 = texture;
}

void Slot::SetLine23(SDL_Texture* texture)
{
    line23 = texture;
}

void Slot::SetLine24(SDL_Texture* texture)
{
    line24 = texture;
}

void Slot::SetLine25(SDL_Texture* texture)
{
    line25 = texture;
}

// Get Methods -> 

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

SDL_Texture* Slot:: GetCashOutButton()
{
    return cashOutButton;
}

SDL_Texture* Slot:: GetCashOutButtonPushed()
{
    return cashOutButtonPushed;
}

SDL_Texture* Slot:: GetWhiteScreenTexture()
{
    return whiteScreenTexture;
}


SDL_Texture* Slot:: GetFigure1()
{
    return eFigure1;
}

SDL_Texture* Slot::GetFigure2()
{
    return eFigure2;
}

SDL_Texture* Slot::GetFigure3()
{
    return eFigure3;
}

SDL_Texture* Slot::GetFigure4()
{
    return eFigure4;
}

SDL_Texture* Slot::GetFigure5()
{
    return eFigure5;
}

SDL_Texture* Slot::GetFigure6()
{
    return eFigure6;
}

SDL_Texture* Slot::GetFigure7()
{
    return eFigure7;
}

SDL_Texture* Slot::GetFigure8()
{
    return eFigure8;
}

SDL_Texture* Slot::GetFigure9()
{
    return eFigure9;
}


SDL_Texture* Slot::GetLine1()
{
    return line1;
    
}

SDL_Texture* Slot::GetLine2()
{
    return line2;
}

SDL_Texture* Slot::GetLine3()
{
    return line3;
}

SDL_Texture* Slot::GetLine4()
{
    return line4;
}

SDL_Texture* Slot::GetLine5()
{
    return line5;
}

SDL_Texture* Slot::GetLine6()
{
    return line6;
}

SDL_Texture* Slot::GetLine7()
{
    return line7;
}

SDL_Texture* Slot::GetLine8()
{
    return line8;
}

SDL_Texture* Slot::GetLine9()
{
    return line9;
}

SDL_Texture* Slot::GetLine10()
{
    return line10;
}

SDL_Texture* Slot::GetLine11()
{
    return line11;
}

SDL_Texture* Slot::GetLine12()
{
    return line12;
}

SDL_Texture* Slot::GetLine13()
{
    return line13;
}

SDL_Texture* Slot::GetLine14()
{
    return line14;
}

SDL_Texture* Slot::GetLine15()
{
    return line15;
}

SDL_Texture* Slot::GetLine16()
{
    return line16;
}

SDL_Texture* Slot::GetLine17()
{
    return line17;
}

SDL_Texture* Slot::GetLine18()
{
    return line18;
}

SDL_Texture* Slot::GetLine19()
{
    return line19;
}

SDL_Texture* Slot::GetLine20()
{
    return line20;
}

SDL_Texture* Slot::GetLine21()
{
    return line21;
}

SDL_Texture* Slot::GetLine22()
{
    return line22;
}

SDL_Texture* Slot::GetLine23()
{
    return line23;
}

SDL_Texture* Slot::GetLine24()
{
    return line24;
}

SDL_Texture* Slot::GetLine25()
{
    return line25;
}
void Slot::QuitView3()
{
	SDL_DestroyTexture(slotTexture);
		SDL_DestroyTexture(startSpinButton);
		SDL_DestroyTexture(startSpinButtonPushed);
		SDL_DestroyTexture(maxBetButton);
		SDL_DestroyTexture(maxBetButtonPushed);
		SDL_DestroyTexture(plusLinesButton);
		SDL_DestroyTexture(plusLinesButtonPushed);
		SDL_DestroyTexture(minusButtonLines);
		SDL_DestroyTexture(minusButtonLinesPushed);
		SDL_DestroyTexture(minusButtonBet);
		SDL_DestroyTexture(minusButtonBetPushed);
		SDL_DestroyTexture(plusButtonBet);
		SDL_DestroyTexture(plusButtonBetPushed);
		SDL_DestroyTexture(cashOutButton);
		SDL_DestroyTexture(cashOutButtonPushed);
		SDL_DestroyTexture(whiteScreenTexture);
		SDL_DestroyTexture(eFigure1);
		SDL_DestroyTexture(eFigure2);
		SDL_DestroyTexture(eFigure3);
		SDL_DestroyTexture(eFigure4);
		SDL_DestroyTexture(eFigure5);
		SDL_DestroyTexture(eFigure6);
		SDL_DestroyTexture(eFigure7);
		SDL_DestroyTexture(eFigure8);
		SDL_DestroyTexture(eFigure9);
		SDL_DestroyTexture(line1);
		SDL_DestroyTexture(line2);
		SDL_DestroyTexture(line3);
		SDL_DestroyTexture(line4);
		SDL_DestroyTexture(line5);
		SDL_DestroyTexture(line6);
		SDL_DestroyTexture(line7);
		SDL_DestroyTexture(line8);
		SDL_DestroyTexture(line9);
		SDL_DestroyTexture(line10);
		SDL_DestroyTexture(line11);
		SDL_DestroyTexture(line12);
		SDL_DestroyTexture(line13);
		SDL_DestroyTexture(line14);
		SDL_DestroyTexture(line15);
		SDL_DestroyTexture(line16);
		SDL_DestroyTexture(line17);
		SDL_DestroyTexture(line18);
		SDL_DestroyTexture(line19);
		SDL_DestroyTexture(line20);
		SDL_DestroyTexture(line21);
		SDL_DestroyTexture(line22);
		SDL_DestroyTexture(line23);
		SDL_DestroyTexture(line24);
		SDL_DestroyTexture(line25);


		slotTexture = NULL;
		startSpinButton = NULL;
		startSpinButtonPushed = NULL;
		maxBetButton = NULL;
		maxBetButtonPushed = NULL;
		plusLinesButton = NULL;
		plusLinesButtonPushed = NULL;
		minusButtonLines = NULL;
		minusButtonLinesPushed = NULL;
		minusButtonBet = NULL;
		minusButtonBetPushed = NULL;
		plusButtonBet = NULL;
		plusButtonBetPushed = NULL;
		cashOutButton = NULL;
		whiteScreenTexture = NULL;
		eFigure1 = NULL;
		eFigure2 = NULL;
		eFigure3 = NULL;
		eFigure4 = NULL;
		eFigure5 = NULL;
		eFigure6 = NULL;
		eFigure7 = NULL;
		eFigure8 = NULL;
		eFigure9 = NULL;
		line1 = NULL;
		line2 = NULL;
		line3 = NULL;
		line4 = NULL;
		line5 = NULL;
		line6 = NULL;
		line7 = NULL;
		line8 = NULL;
		line9 = NULL;
		line10 = NULL;
		line11 = NULL;
		line12 = NULL;
		line13 = NULL;
		line14 = NULL;
		line15 = NULL;
		line16 = NULL;
		line17 = NULL;
		line18 = NULL;
		line19 = NULL;
		line20 = NULL;
		line21 = NULL;
		line22 = NULL;
		line23 = NULL;
		line24 = NULL;
		line25 = NULL;

}
