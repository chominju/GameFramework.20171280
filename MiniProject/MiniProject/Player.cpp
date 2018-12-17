#include <iostream>
#include "Player.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "MenuButton.h"

//void Player::load(int x, int y, int width, int height,
//	std::string textureID)
//{
//	GameObject::load(x, y, width, height, textureID);
//	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
//}

Player::Player(const LoaderParams* pParams) :SDLGameObject(pParams)
{
	stop = false;
}

void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Player::update()
{
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (m_position.getX() + m_width) &&
		pMousePos->getX() > m_position.getX() &&
		pMousePos->getY() < (m_position.getY() + m_height) &&
		pMousePos->getY() > m_position.getY())
	{
			if (TheInputHandler::Instance()->getMouseButtonState(LEFT) &&
				m_bReleased) {
				m_currentFrame = MOUSE_OVER;
				//m_callback(); // call our callback function
				m_bReleased = false;
			}
			else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
			{
				m_bReleased = true;
				m_currentFrame = MOUSE_OVER;
			}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}

	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	//m_currentFrame =0;
	SDLGameObject::update();

}

void Player::clean()
{

}

void Player::handleInput()
{

	if (TheInputHandler::Instance()->getMouseButtonState(RIGHT))
	{
		
	}

	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		stop = true;
		m_currentFrame = 1;
	}
}