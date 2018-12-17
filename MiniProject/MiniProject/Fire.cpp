#include <iostream>
#include "Fire.h"
#include "InputHandler.h"
#include "Game.h"

#include <SDL.h>

//void Enemy::update()
//{
//	GameObject::update();
//	m_y += 1;
//	//m_x += 1;
//	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
//}
Fire::Fire(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	//m_gameObjects = TheGame::Instance()->getObj();
	collision = false;
}

void Fire::draw()
{
	if (collision == false)
	{
		SDLGameObject::draw(); // we now use SDLGameObject
		update();
	}
}

void Fire::update()
{
	//	GameObject::update();
	//m_position.setY(m_position.getY());

	m_currentFrame = int(((SDL_GetTicks() / 100)%1));

	handleInput();

	//if ((m_position.getX()+32 >= m_gameObjects[1]->posX())&& (m_position.getX() <= m_gameObjects[1]->posX()+1))
	//{
	//	if ((m_position.getY()+16 > m_gameObjects[1]->posY())&& (m_position.getY()-16 <= m_gameObjects[1]->posY()+64))
	//	{	
	//		
	//		std::cout << "crash!!!";
	//		m_position.setX(m_position.getX());
	//		collision = true;
	//		m_gameObjects[1]->check_fire();


	//	/*	TextureManager::Instance()->clearFromTextureMap("bullet");*/
	//	}
	//	else
	//	{
	//		m_position.setX(m_position.getX() + 2);
	//	}
	//}
	//else
	//{
	//	m_position.setX(m_position.getX() + 2);
	//}
	
}

void Fire::clean()
{
	SDL_Renderer* getRenderer = Game::Instance()->getRenderer();
	SDL_RenderClear(getRenderer);
}

float Fire::posX()
{
	return 0.0f;
}

float Fire::posY()
{
	return 0.0f;
}

void Fire::handleInput()
{

}


Fire::~Fire()
{
	std::cout << "Fire is finish";
}

