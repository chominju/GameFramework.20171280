#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Fire.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Game.h"

//void Player::load(int x, int y, int width, int height,
//	std::string textureID)
//{
//	GameObject::load(x, y, width, height, textureID);
//	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
//}

Fire::Fire(/*const LoaderParams* pParams) :SDLGameObject(pParams*/)
{
	SDL_Surface* pTempSurface = IMG_Load("assets/fire.png");

	m_pRenderer = TheGame::Instance()->getRenderer();
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

	m_sourceRectangle.w = 32;
	m_sourceRectangle.h = 32;

	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;

	m_destinationRectangle.x = 110;
	m_destinationRectangle.y = 30;

	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;
}

void Fire::draw()
{
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

	//SDLGameObject::draw(); // we now use SDLGameObject
}

void Fire::update()
{
	/*m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));*/

	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	//m_acceleration.setX(1);
	//SDLGameObject::update();

	//m_velocity.setX(2);

	//SDLGameObject::update();

	m_destinationRectangle.x += 2;

}

void Fire::clean()
{

}

void Fire::handleInput()
{

}