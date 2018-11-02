#pragma once
//#include <SDL.h>
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Player : public SDLGameObject

{
public:
	/*void load(int x, int y, int width, int height, std::string textureID);*/
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};