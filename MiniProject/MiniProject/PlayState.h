#pragma once
#include "GameState.h"
#include "SDLGameObject.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }

	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}


private:
	static const std::string s_playID;
	static PlayState* s_pInstance;
};

//class GameObject;
//class PlayState : public GameState
//{
//public:
//	virtual void update();
//	virtual void render();
//	virtual bool onEnter();
//	virtual bool onExit();
//	virtual std::string getStateID() const { return s_playID; }
//private:
//	static const std::string s_playID;
//	std::vector<GameObject*> m_gameObjects;
//};

