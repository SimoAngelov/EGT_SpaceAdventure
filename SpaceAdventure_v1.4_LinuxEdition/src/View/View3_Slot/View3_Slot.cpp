//
//  View3_Slot.cpp
//  SpaceAdventure_View
//
//  Created by Ichko  on 21/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#include "View3_Slot.hpp"

View3_Slot::View3_Slot()
{
    
}

// Set Methods ->

void View3_Slot::SetSlotTexture(SDL_Texture* texture)
{
    slotTexture = texture;
}

void View3_Slot::SetStartSpinButton(SDL_Texture* texture)
{
    startSpinButton = texture;
}

void View3_Slot::SetStartSpinButtonPushed(SDL_Texture* texture)
{
    startSpinButtonPushed = texture;
}

void View3_Slot::SetMaxBetButton(SDL_Texture* texture)
{
    maxBetButton = texture;
}

void View3_Slot::SetMaxBetButtonPushed(SDL_Texture* texture)
{
    maxBetButtonPushed = texture;
}

void View3_Slot::SetPlusLinesButton(SDL_Texture* texture)
{
    plusLinesButton = texture;
}

void View3_Slot::SetPlusLinesButtonPushed(SDL_Texture* texture)
{
    plusLinesButtonPushed = texture;
}

void View3_Slot::SetMinusButtonLines(SDL_Texture* texture)
{
    minusButtonLines = texture;
    
}

void View3_Slot::SetMinusButtonLinesPushed(SDL_Texture* texture)
{
    minusButtonLinesPushed = texture;
}

void View3_Slot::SetMinusButtonBet(SDL_Texture* texture)
{
    minusButtonBet = texture;
}

void View3_Slot::SetMinusButtonBetPushed(SDL_Texture* texture)
{
    minusButtonBetPushed = texture;
}

void View3_Slot::SetPlusButtonBet(SDL_Texture* texture)
{
    plusButtonBet = texture;
}

void View3_Slot::SetPlusButtonBetPushed(SDL_Texture* texture)
{
    plusButtonBetPushed = texture;
}

void View3_Slot:: SetFigure1(SDL_Texture* texture)
{
    eFigure1 = texture;
}

void View3_Slot::SetFigure2(SDL_Texture* texture)
{
    eFigure2 = texture;
}

void View3_Slot::SetFigure3(SDL_Texture* texture)
{
    eFigure3 = texture;
}

void View3_Slot::SetFigure4(SDL_Texture* texture)
{
    eFigure4 = texture;
}

void View3_Slot::SetFigure5(SDL_Texture* texture)
{
    eFigure5 = texture;
}

void View3_Slot::SetFigure6(SDL_Texture* texture)
{
    eFigure6 = texture;
}

void View3_Slot::SetFigure7(SDL_Texture* texture)
{
    eFigure7 = texture;
}

void View3_Slot::SetFigure8(SDL_Texture* texture)
{
    eFigure8 = texture;
}

void View3_Slot::SetFigure9(SDL_Texture* texture)
{
    eFigure9 = texture;
}

void View3_Slot:: SetCashOutButton(SDL_Texture* texture)
{
    cashOutButton = texture;
}

void View3_Slot:: SetCashOutButtonPushed(SDL_Texture* texture)
{
    cashOutButtonPushed = texture;
}

void View3_Slot:: SetWhiteScreenTexture(SDL_Texture* texture)
{
    whiteScreenTexture = texture;
}

void View3_Slot::SetLine1(SDL_Texture* texture)
{
    line1 = texture;
}

void View3_Slot::SetLine2(SDL_Texture* texture)
{
    line2 = texture;
}

void View3_Slot::SetLine3(SDL_Texture* texture)
{
    line3 = texture;
}

void View3_Slot::SetLine4(SDL_Texture* texture)
{
    line4 = texture;
}

void View3_Slot::SetLine5(SDL_Texture* texture)
{
    line5 = texture;
}

void View3_Slot::SetLine6(SDL_Texture* texture)
{
    line6 = texture;
}

void View3_Slot::SetLine7(SDL_Texture* texture)
{
    line7 = texture;
}

void View3_Slot::SetLine8(SDL_Texture* texture)
{
    line8 = texture;
}

void View3_Slot::SetLine9(SDL_Texture* texture)
{
    line9 = texture;
}

void View3_Slot::SetLine10(SDL_Texture* texture)
{
    line10 = texture;
}

void View3_Slot::SetLine11(SDL_Texture* texture)
{
    line11 = texture;
}

void View3_Slot::SetLine12(SDL_Texture* texture)
{
    line12 = texture;
}

void View3_Slot::SetLine13(SDL_Texture* texture)
{
    line13 = texture;
}

void View3_Slot::SetLine14(SDL_Texture* texture)
{
    line14 = texture;
}

void View3_Slot::SetLine15(SDL_Texture* texture)
{
    line15 = texture;
}

void View3_Slot::SetLine16(SDL_Texture* texture)
{
    line16 = texture;
}

void View3_Slot::SetLine17(SDL_Texture* texture)
{
    line17 = texture;
}

void View3_Slot::SetLine18(SDL_Texture* texture)
{
    line18 = texture;
}

void View3_Slot::SetLine19(SDL_Texture* texture)
{
    line19 = texture;
}

void View3_Slot::SetLine20(SDL_Texture* texture)
{
    line20 = texture;
}

void View3_Slot::SetLine21(SDL_Texture* texture)
{
    line21 = texture;
}

void View3_Slot::SetLine22(SDL_Texture* texture)
{
    line22 = texture;
}

void View3_Slot::SetLine23(SDL_Texture* texture)
{
    line23 = texture;
}

void View3_Slot::SetLine24(SDL_Texture* texture)
{
    line24 = texture;
}

void View3_Slot::SetLine25(SDL_Texture* texture)
{
    line25 = texture;
}

// Get Methods -> 

SDL_Texture* View3_Slot::GetSlotTexture()
{
    return slotTexture;
}

SDL_Texture* View3_Slot::GetStartSpinButton()
{
    return startSpinButton;
}

SDL_Texture* View3_Slot::GetStartSpinButtonPushed()
{
    return startSpinButtonPushed;
}

SDL_Texture* View3_Slot::GetMaxBetButton()
{
    return maxBetButton;
}

SDL_Texture* View3_Slot::GetMaxBetButtonPushed()
{
    return maxBetButtonPushed;
}

SDL_Texture* View3_Slot::GetPlusLinesButton()
{
    return plusLinesButton;
}

SDL_Texture* View3_Slot::GetPlusLinesButtonPushed()
{
    return plusLinesButtonPushed;
}

SDL_Texture* View3_Slot::GetMinusButtonLines()
{
    return minusButtonLines;
}

SDL_Texture* View3_Slot::GetMinusButtonLinesPushed()
{
    return minusButtonLinesPushed;
}

SDL_Texture* View3_Slot::GetMinusButtonBet()
{
    return minusButtonBet;
}

SDL_Texture* View3_Slot::GetMinusButtonBetPushed()
{
    return minusButtonBetPushed;
}

SDL_Texture* View3_Slot::GetPlusButtonBet()
{
    return plusButtonBet;
}

SDL_Texture* View3_Slot::GetPlusButtonBetPushed()
{
    return plusButtonBetPushed;
}

SDL_Texture* View3_Slot:: GetCashOutButton()
{
    return cashOutButton;
}

SDL_Texture* View3_Slot:: GetCashOutButtonPushed()
{
    return cashOutButtonPushed;
}

SDL_Texture* View3_Slot:: GetWhiteScreenTexture()
{
    return whiteScreenTexture;
}


SDL_Texture* View3_Slot:: GetFigure1()
{
    return eFigure1;
}

SDL_Texture* View3_Slot::GetFigure2()
{
    return eFigure2;
}

SDL_Texture* View3_Slot::GetFigure3()
{
    return eFigure3;
}

SDL_Texture* View3_Slot::GetFigure4()
{
    return eFigure4;
}

SDL_Texture* View3_Slot::GetFigure5()
{
    return eFigure5;
}

SDL_Texture* View3_Slot::GetFigure6()
{
    return eFigure6;
}

SDL_Texture* View3_Slot::GetFigure7()
{
    return eFigure7;
}

SDL_Texture* View3_Slot::GetFigure8()
{
    return eFigure8;
}

SDL_Texture* View3_Slot::GetFigure9()
{
    return eFigure9;
}


SDL_Texture* View3_Slot::GetLine1()
{
    return line1;
    
}

SDL_Texture* View3_Slot::GetLine2()
{
    return line2;
}

SDL_Texture* View3_Slot::GetLine3()
{
    return line3;
}

SDL_Texture* View3_Slot::GetLine4()
{
    return line4;
}

SDL_Texture* View3_Slot::GetLine5()
{
    return line5;
}

SDL_Texture* View3_Slot::GetLine6()
{
    return line6;
}

SDL_Texture* View3_Slot::GetLine7()
{
    return line7;
}

SDL_Texture* View3_Slot::GetLine8()
{
    return line8;
}

SDL_Texture* View3_Slot::GetLine9()
{
    return line9;
}

SDL_Texture* View3_Slot::GetLine10()
{
    return line10;
}

SDL_Texture* View3_Slot::GetLine11()
{
    return line11;
}

SDL_Texture* View3_Slot::GetLine12()
{
    return line12;
}

SDL_Texture* View3_Slot::GetLine13()
{
    return line13;
}

SDL_Texture* View3_Slot::GetLine14()
{
    return line14;
}

SDL_Texture* View3_Slot::GetLine15()
{
    return line15;
}

SDL_Texture* View3_Slot::GetLine16()
{
    return line16;
}

SDL_Texture* View3_Slot::GetLine17()
{
    return line17;
}

SDL_Texture* View3_Slot::GetLine18()
{
    return line18;
}

SDL_Texture* View3_Slot::GetLine19()
{
    return line19;
}

SDL_Texture* View3_Slot::GetLine20()
{
    return line20;
}

SDL_Texture* View3_Slot::GetLine21()
{
    return line21;
}

SDL_Texture* View3_Slot::GetLine22()
{
    return line22;
}

SDL_Texture* View3_Slot::GetLine23()
{
    return line23;
}

SDL_Texture* View3_Slot::GetLine24()
{
    return line24;
}

SDL_Texture* View3_Slot::GetLine25()
{
    return line25;
}
