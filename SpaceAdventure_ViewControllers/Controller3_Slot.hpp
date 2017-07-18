//
//  Controller3_Slot.hpp
//  SpaceAdventure_ViewControllers
//
//  Created by Ichko  on 11/07/17.
//  Copyright © 2017 IliyaStark. All rights reserved.
//

#ifndef Controller3_Slot_hpp
#define Controller3_Slot_hpp

// windows includes

#include <iostream>
#include "Controller1_Intro.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// MAC includes

//#include <SDL2/SDL.h>
//#include <SDL2_image/SDL_image.h>
//#include <SDL2_ttf/SDL_ttf.h>
class Slot

{

private:

	SDL_Texture* slotTexture = NULL;

	//Adding buttons

	SDL_Texture* startSpinButton = NULL;

	SDL_Texture* startSpinButtonPushed = NULL;

	SDL_Texture* maxBetButton = NULL;

	SDL_Texture* maxBetButtonPushed = NULL;

	SDL_Texture* plusLinesButton = NULL;

	SDL_Texture* plusLinesButtonPushed = NULL;

	SDL_Texture* minusButtonLines = NULL;

	SDL_Texture* minusButtonLinesPushed = NULL;

	SDL_Texture* minusButtonBet = NULL;

	SDL_Texture* minusButtonBetPushed = NULL;

	SDL_Texture* plusButtonBet = NULL;

	SDL_Texture* plusButtonBetPushed = NULL;

	//slot figures



	SDL_Texture* eFigure1 = NULL;

	SDL_Texture* eFigure2 = NULL;

	SDL_Texture* eFigure3 = NULL;

	SDL_Texture* eFigure4 = NULL;

	SDL_Texture* eFigure5 = NULL;

	SDL_Texture* eFigure6 = NULL;

	SDL_Texture* eFigure7 = NULL;

	SDL_Texture* eFigure8 = NULL;

	SDL_Texture* eFigure9 = NULL;

	SDL_Texture* line1 = NULL;

	SDL_Texture* line2 = NULL;

	SDL_Texture* line3 = NULL;

	SDL_Texture* line4 = NULL;

	SDL_Texture* line5 = NULL;

	SDL_Texture* line6 = NULL;

	SDL_Texture* line7 = NULL;

	SDL_Texture* line8 = NULL;

	SDL_Texture* line9 = NULL;

	SDL_Texture* line10 = NULL;

	SDL_Texture* line11 = NULL;

	SDL_Texture* line12 = NULL;

	SDL_Texture* line13= NULL;

	SDL_Texture* line14= NULL;

	SDL_Texture* line15 = NULL;

	SDL_Texture* line16 = NULL;

	SDL_Texture* line17 = NULL;

	SDL_Texture* line18 = NULL;

	SDL_Texture* line19 = NULL;

	SDL_Texture* line20 = NULL;

	SDL_Texture* line21 = NULL;

	SDL_Texture* line22 = NULL;

	SDL_Texture* line23 = NULL;

	SDL_Texture* line24 = NULL;

	SDL_Texture* line25 = NULL;




public:

	Slot();

	/////
	//texture setters

	void SetSlotTexture(SDL_Texture* texture);

	void SetStartSpinButton(SDL_Texture* texture);

	void SetStartSpinButtonPushed(SDL_Texture* texture);

	void SetMaxBetButton(SDL_Texture* texture);

	void SetMaxBetButtonPushed(SDL_Texture* texture);

	void SetPlusLinesButton(SDL_Texture* texture);

	void SetPlusLinesButtonPushed(SDL_Texture* texture);

	void SetMinusButtonLines(SDL_Texture* texture);

	void SetMinusButtonLinesPushed(SDL_Texture* texture);

	void SetMinusButtonBet(SDL_Texture* texture);

	void SetMinusButtonBetPushed(SDL_Texture* texture);

	void SetPlusButtonBet(SDL_Texture* texture);

	void SetPlusButtonBetPushed(SDL_Texture* texture);

	// slot figures textures

	void SetFigure1(SDL_Texture* texture);

	void SetFigure2(SDL_Texture* texture);

	void SetFigure3(SDL_Texture* texture);

	void SetFigure4(SDL_Texture* texture);

	void SetFigure5(SDL_Texture* texture);

	void SetFigure6(SDL_Texture* texture);

	void SetFigure7(SDL_Texture* texture);

	void SetFigure8(SDL_Texture* texture);

	void SetFigure9(SDL_Texture* texture);

	// lines textures

	void SetLine1(SDL_Texture* texture);

	void SetLine2(SDL_Texture* texture);

	void SetLine3(SDL_Texture* texture);

	void SetLine4(SDL_Texture* texture);

	void SetLine5(SDL_Texture* texture);

	void SetLine6(SDL_Texture* texture);

	void SetLine7(SDL_Texture* texture);

	void SetLine8(SDL_Texture* texture);

	void SetLine9(SDL_Texture* texture);

	void SetLine10(SDL_Texture* texture);

	void SetLine11(SDL_Texture* texture);

	void SetLine12(SDL_Texture* texture);

	void SetLine13(SDL_Texture* texture);

	void SetLine14(SDL_Texture* texture);

	void SetLine15(SDL_Texture* texture);

	void SetLine16(SDL_Texture* texture);

	void SetLine17(SDL_Texture* texture);

	void SetLine18(SDL_Texture* texture);

	void SetLine19(SDL_Texture* texture);

	void SetLine20(SDL_Texture* texture);

	void SetLine21(SDL_Texture* texture);

	void SetLine22(SDL_Texture* texture);

	void SetLine23(SDL_Texture* texture);

	void SetLine24(SDL_Texture* texture);

	void SetLine25(SDL_Texture* texture);




	//texture getters

	SDL_Texture* GetSlotTexture();

	SDL_Texture* GetStartSpinButton();

	SDL_Texture* GetStartSpinButtonPushed();

	SDL_Texture* GetMaxBetButton();

	SDL_Texture* GetMaxBetButtonPushed();

	SDL_Texture* GetPlusLinesButton();

	SDL_Texture* GetPlusLinesButtonPushed();

	SDL_Texture* GetMinusButtonLines();

	SDL_Texture* GetMinusButtonLinesPushed();

	SDL_Texture* GetMinusButtonBet();

	SDL_Texture* GetMinusButtonBetPushed();

	SDL_Texture* GetPlusButtonBet();

	SDL_Texture* GetPlusButtonBetPushed();



	SDL_Texture* GetFigure1();

	SDL_Texture* GetFigure2();

	SDL_Texture* GetFigure3();

	SDL_Texture* GetFigure4();

	SDL_Texture* GetFigure5();

	SDL_Texture* GetFigure6();

	SDL_Texture* GetFigure7();

	SDL_Texture* GetFigure8();

	SDL_Texture* GetFigure9();

	//lines texture

	SDL_Texture* GetLine1();

	SDL_Texture* GetLine2();

	SDL_Texture* GetLine3();

	SDL_Texture* GetLine4();

	SDL_Texture* GetLine5();

	SDL_Texture* GetLine6();

	SDL_Texture* GetLine7();

	SDL_Texture* GetLine8();

	SDL_Texture* GetLine9();

	SDL_Texture* GetLine10();

	SDL_Texture* GetLine11();

	SDL_Texture* GetLine12();

	SDL_Texture* GetLine13();

	SDL_Texture* GetLine14();

	SDL_Texture* GetLine15();

	SDL_Texture* GetLine16();

	SDL_Texture* GetLine17();

	SDL_Texture* GetLine18();

	SDL_Texture* GetLine19();

	SDL_Texture* GetLine20();

	SDL_Texture* GetLine21();

	SDL_Texture* GetLine22();

	SDL_Texture* GetLine23();

	SDL_Texture* GetLine24();

	SDL_Texture* GetLine25();


};

#endif /* Controller3_Slot_hpp */
