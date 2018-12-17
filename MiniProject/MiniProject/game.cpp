#include <iostream>
#include "Game.h"
#include <SDL_image.h>
#include "TextureManager.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"

//#include "SDL.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true; //


		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);


		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(MenuState::Instance());

	}
	else
	{
		return false;
	}
	return true;
}
void Game::render()
{
	//SDL_RenderClear(m_pRenderer); // clear to the draw colour
	//for (std::vector<GameObject*>::size_type i = 0;
	//	i != m_gameObjects.size(); i++)
	//{
	//	m_gameObjects[i]->draw(/*m_pRenderer*/);
	//}
	//SDL_RenderPresent(m_pRenderer); // draw to the screen


	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}
void Game::clean()
{
	TheInputHandler::Instance()->clean();
}
void Game::quit()
{
	m_bRunning = false;
}
void Game::update()
{
	/*for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}*/
	m_pGameStateMachine->update();

}
void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}

}