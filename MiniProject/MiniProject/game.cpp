#include <iostream>
#include "Game.h"
#include <SDL_image.h>
#include "TextureManager.h"
#include "Enemy.h"
#include "InputHandler.h"

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
		if (!TheTextureManager::Instance()->load("assets/main_square.png",
			"animate", m_pRenderer))
		{
			return false;
		}

		m_textureManager.load("assets/main_square.png", "animate", m_pRenderer);

		//m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,
		//	pTempSurface);
		//SDL_FreeSurface(pTempSurface);

		//m_sourceRectangle.w = 128;
		//m_sourceRectangle.h = 82;

		//m_destinationRectangle.x = m_sourceRectangle.x = 0;
		//m_destinationRectangle.y = m_sourceRectangle.y = 0;
		//m_destinationRectangle.w = m_sourceRectangle.w;
		//m_destinationRectangle.h = m_sourceRectangle.h;

		//m_destinationRectangle2.x = m_sourceRectangle.x = 100;
		//m_destinationRectangle2.y = m_sourceRectangle.y = 0;
		//m_destinationRectangle2.w = m_sourceRectangle.w;
		//m_destinationRectangle2.h = m_sourceRectangle.h;

		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 0);

		//m_go.load(100, 100, 128, 82, "animate");
		//m_player.load(300, 300, 128, 82, "animate");

		//m_go = new GameObject();
		//m_player = new Player();
		//m_enemy = new Enemy();

		int k = 0;

		//m_go->load(100, 100, 128, 82, "animate");
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				m_gameObjects.push_back(new Player(new LoaderParams(j*26, i*26, 26, 26, "animate")));
				m_objectPosition[k] = new Vector2D(j*26.0f, i*26.0f);
				k++;
			}
		}

		//for (int i = 0; i < 19; i++)
		//{
		//	for (int j = 0; j < 19; j++)
		//	{
		//		m_gameObjects.push_back(new Enemy(new LoaderParams(j * 26, i * 26, 26, 26, "animate")));
		//	}
		//}
	

		//m_gameObjects.push_back(m_go);
		//m_gameObjects.push_back(m_player);
		//m_gameObjects.push_back(m_enemy);

		/*m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));*/

		//SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp"); //
		//m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface); //
		//SDL_FreeSurface(pTempSurface); //
		//SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h); //
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


void Game::update()
{

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}

std::vector<GameObject*> Game::getGameObject()
{
	return m_gameObjects;
}

Vector2D * Game::getObjcetPosition()
{
	return *m_objectPosition;
}
