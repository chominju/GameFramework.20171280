#pragma once
//#include <SDL.h>
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Fire /*: public SDLGameObject*/

{
public:
	/*void load(int x, int y, int width, int height, std::string textureID);*/
	Fire(/*const LoaderParams* pParams*/);
	virtual void draw();
	virtual void update();
	virtual void clean();

	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;

	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;


private:
	void handleInput();

};