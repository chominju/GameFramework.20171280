#pragma once

#include "SDL.h"

class Game
{

public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);


	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;

	SDL_Texture* m_pTexture;

	SDL_Texture* m_pTexture2;

	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
	SDL_Rect m_sourceRectangle2;
	SDL_Rect m_destinationRectangle2;
	SDL_Rect m_sourceRectangle3;
	SDL_Rect m_destinationRectangle3;

	bool m_bRunning;

};