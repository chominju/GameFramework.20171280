#include <iostream>
#include "Game.h"
#include <SDL_image.h>
#include "TextureManager.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "Fire.h"

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
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
			"animate", m_pRenderer))
		{
			return false;
		}


		//SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");
		//SDL_Surface* pTempSurface = IMG_Load("assets/animate.png");
		//SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");

		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

		
		m_gameObjects.push_back(new Player(new LoaderParams(0, 0, 128, 82, "animate")));
		
	/*	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));*/


	}
	else
	{
		return false;
	}
	return true;
}
void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear to the draw colour
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(/*m_pRenderer*/);
	}

	if (fireCheck())
	{
		ball->draw();
	}
	SDL_RenderPresent(m_pRenderer); // draw to the screen
}
void Game::clean()
{
	TheInputHandler::Instance()->clean();
}
void Game::quit()
{
	m_bRunning = false;
}
bool Game::fireCheck()
{
	return fire;
}
void Game::fireOn()
{
	fire = true;
	ball= new Fire();
}
void Game::update()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	if (fireCheck())
	{
		ball->update();
	}
}
void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}