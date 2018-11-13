#pragma once
#include <vector>
#include <SDL.h>
#include "Vector2D.h"
#include "GameObject.h"


enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear

	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

	~InputHandler() {}
	const Uint8* m_keystates;



	// mouse buttion events								
	std::vector<bool> m_mouseButtonStates;

	// mouse motion event					
	Vector2D * m_mousePosition;

	Vector2D * m_objectPosition;




	bool MouseMove(SDL_MouseButtonEvent move);

	std::vector<GameObject*> object;




private:
	InputHandler();
	static InputHandler* s_pInstance;
};


typedef InputHandler TheInputHandler;

