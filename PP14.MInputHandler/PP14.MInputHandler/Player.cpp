﻿#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Fire.h"
#include "Game.h"

//void Player::load(int x, int y, int width, int height,
//	std::string textureID)
//{
//	GameObject::load(x, y, width, height, textureID);
//	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
//}

Player::Player(const LoaderParams* pParams) :SDLGameObject(pParams)
{

}

void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(/*m_pRenderer*/);
	}

}

void Player::update()
{
	/*m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));*/

	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	//m_acceleration.setX(1);
	//SDLGameObject::update();

	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

}

void Player::clean()
{

}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		if (TheInputHandler::Instance()->oneFire())
		{
			TheInputHandler::Instance()->setFire();
			/*m_gameObjects.push_back(new Fire(new LoaderParams(m_velocity.getX(), m_velocity.getY(), 32, 32, "fire")));*/
			/*m_gameObjects.push_back(new Fire());*/

			TheGame::Instance()->fireOn();
		}
	}
}