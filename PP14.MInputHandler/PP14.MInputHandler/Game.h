#pragma once
#include <SDL.h>
#include <vector>
#include "TextureManager.h"
#include "Player.h"
#include "GameObject.h"


class Game
{
private:
	//SDL_Texture* m_pTexture; //
	//SDL_Rect m_sourceRectangle; //
	//SDL_Rect m_destinationRectangle; //
	//SDL_Texture* m_pTexture; // the new SDL_Texture variable
	//SDL_Rect m_sourceRectangle; // 원본 사각형 
	//SDL_Rect m_destinationRectangle; // 대상 사각형
	//SDL_Rect m_destinationRectangle2; // 대상 사각형
	//GameObject m_go;
	//Player m_player;

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int m_currentFrame;
	TextureManager m_textureManager;

	std::vector<GameObject*> m_gameObjects;

	//GameObject* m_go;
	//GameObject* m_player;
	//GameObject* m_enemy;

	Game() {};

	static Game*s_pInstance;


public:

	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	void quit();

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
};
typedef Game TheGame;


