#include "Enemy.h"
#include "SDLGameObject.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	/*m_y += 1;
	m_x += 1;*/

	m_position.setX(m_position.getX() + 1);
	m_position.setY(m_position.getY() + 1);

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Enemy::clean()
{
}
