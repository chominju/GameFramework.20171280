#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "game.h"

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, /*fullscreen*/SDL_WINDOW_SHOWN);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			m_bRunning = true;

			SDL_Surface* pTempSurface = IMG_Load("assets/gray.png");

			SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);

			m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

			SDL_FreeSurface(pTempSurface);

			m_sourceRectangle[0].w = 26;
			m_sourceRectangle[0].h = 26;

			m_destinationRectangle[0].x = m_sourceRectangle[0].x = 0;
			m_destinationRectangle[0].y = m_sourceRectangle[0].y = 0;

			m_destinationRectangle[0].w = m_sourceRectangle[0].w;
			m_destinationRectangle[0].h = m_sourceRectangle[0].h;

			for (int i = 1; i < 400; i++)
			{
				m_destinationRectangle[i].x += 27;
				m_sourceRectangle[i].x += 27; // ³×¸ðÄ­ ¸¸Å­ ´õÇØÁÜ.
				m_destinationRectangle[i].y = m_sourceRectangle[i].y = 0;
			}
		}

	}
	else
	{
		return false;
	}

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	for (int i = 0; i < 400; i++)
	{
		SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle[i], &m_destinationRectangle[i]);
	}
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{

}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;
		}
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
