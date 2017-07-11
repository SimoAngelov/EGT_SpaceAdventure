/*
 * LineView.h
 *
 *  Created on: 11.07.2017 ã.
 *      Author: user
 */

#ifndef LINEVIEW_H_
#define LINEVIEW_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class LineView
{
public:
	LineView();
	virtual ~LineView();

	//textures setters

	void SetFirstRow(SDL_Texture* texture);
	void SetSecondRow(SDL_Texture* texture);
	void SetThirdRow(SDL_Texture* texture);
	void SetFourthRow(SDL_Texture* texture);

	// texures getters

	SDL_Texture* GetFirstRow();
	SDL_Texture* GetSecondRow();
	SDL_Texture* GetThirdRow();
	SDL_Texture* GetFourthRow();



private:
	// we have 4 rows with lines
	// so we can add effects

	SDL_Texture* firstRow = NULL;
	SDL_Texture* secondRow = NULL;
	SDL_Texture* thirdRow = NULL;
	SDL_Texture* fourthRow = NULL;

};

#endif /* LINEVIEW_H_ */
