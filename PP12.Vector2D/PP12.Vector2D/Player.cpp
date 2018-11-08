#include <iostream>
#include "Player.h"
#include "SDLGameObject.h"

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
}

void Player::update()
{
	/*m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));*/

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_acceleration.setX(1);
	SDLGameObject::update();

}

void Player::clean()
{

}