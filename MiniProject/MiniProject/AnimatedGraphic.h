#pragma once

#include "SDLGameObject.h"
#include "GameObject.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
	int m_animSpeed;


	void update();
	
};

