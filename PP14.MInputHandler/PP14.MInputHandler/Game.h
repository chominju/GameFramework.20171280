#pragma once
#include <SDL.h>
#include <vector>
#include "TextureManager.h"
#include "Player.h"
#include "GameObject.h"
#include "Fire.h"


class Game
{
private:
	//SDL_Texture* m_pTexture; //
	//SDL_Rect m_sourceRectangle; //
	//SDL_Rect m_destinationRectangle; //
	//SDL_Texture* m_pTexture; // the new SDL_Texture variable
	//SDL_Rect m_sourceRectangle; // ���� �簢�� 
	//SDL_Rect m_destinationRectangle; // ��� �簢��
	//SDL_Rect m_destinationRectangle2; // ��� �簢��
	//GameObject m_go;
	//Player m_player;

	SDL_Window * m_pWindow;
	bool m_bRunning;

	int m_currentFrame;
	SDL_Renderer* m_pRenderer;
	TextureManager m_textureManager;

	std::vector<GameObject*> m_gameObjects;

	Fire *ball;

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

	bool fireCheck();
	void fireOn();
	bool fire = false;

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


