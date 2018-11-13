#include "InputHandler.h"
#include "Game.h"


InputHandler* InputHandler::s_pInstance = 0;

bool InputHandler::MouseMove(SDL_MouseButtonEvent move)
{
	return false;
}

InputHandler::InputHandler()
{
	m_mousePosition = new Vector2D(0, 0);
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}

}

void InputHandler::clean()
{
	// 향후 추가 
}

void InputHandler::update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			TheGame::Instance()->quit();
		}

		if (event.type == SDL_KEYUP)
		{
			m_keystates = SDL_GetKeyboardState(0);
		}

		if (event.type == SDL_KEYDOWN)
		{
			m_keystates = SDL_GetKeyboardState(0);
		}

		// void InputHandler::update()에 추가 : 마우스 Motion 이벤트
		if (event.type == SDL_MOUSEMOTION)
		{
			m_mousePosition->setX(event.motion.x);
			m_mousePosition->setY(event.motion.y);
		}

		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				object = TheGame::Instance()->getGameObject();
			
				m_objectPosition = TheGame::Instance()->getObjcetPosition();
				for (std::vector<GameObject*>::size_type i = 0;  i != object.size(); i++)
				{
					
					if ((m_objectPosition->getX() <= m_mousePosition->getX())&& (m_mousePosition->getX() < m_objectPosition->getX()+26)) // 대상의 x값 < 마우스 x값 < 대상의 x값 +26
					{
						if ((m_objectPosition->getY() <= m_mousePosition->getY()) && (m_mousePosition->getY() < m_objectPosition->getY() + 26)) // 대상의 y값 < 마우스 y값 < 대상의 y값 +26
						{
							/*object[i]->clean();*/
							/*object[i]->draw();*/
			
						}
					}
					//if(m_mousePosition->getX)
					//object[i]->draw(/*m_pRenderer*/);
				}

			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = true;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = true;
			}
		}


		else if (event.type == SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = false;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = false;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = false;
			}
		}

		

	}
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0) {
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}


bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

Vector2D*  InputHandler::getMousePosition()
{
	return m_mousePosition;
}