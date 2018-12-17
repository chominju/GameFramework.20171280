#pragma once
#include <SDL.h>
#include <vector>
#include "TextureManager.h"
#include "Player.h"
#include "GameObject.h"
#include "GameStateMachine.h"

class Game
{
private:

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int m_currentFrame;
	TextureManager m_textureManager;

	std::vector<GameObject*> m_gameObjects;

	Game() {};

	static Game*s_pInstance;

	GameStateMachine* m_pGameStateMachine;

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

	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

};
typedef Game TheGame;


