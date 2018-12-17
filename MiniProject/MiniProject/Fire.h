#pragma once
#include <vector>
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Fire : public SDLGameObject
{
public:
	//void load(int x, int y, int width, int height,
	//	std::string textureID);
	Fire(const LoaderParams* pParams);
	/*void draw(SDL_Renderer* pRenderer);*/
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual float posX();
	virtual float posY();
	//virtual bool check();

	void handleInput();

	bool collision;

	std::vector<GameObject*> m_gameObjects;

	~Fire();
};