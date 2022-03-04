#include "player.h"

#include "utils/gl_utils.h"
#include "components/simple_scene.h"

	Player::Player(float radius, glm::vec3 color, glm::vec3 position, int health, bool isColliding, float reloadTime)
	{
		h_radius = radius;
		h_color = color;
		h_position = position;
		h_health = health;
		h_isColliding = isColliding;
		h_reloadTime = reloadTime;
	}
	Player::Player() {}


	void Player::setHealth(int health) 
	{
		h_health = health;
	}

	void Player::setPosition(float x, float y)
	{
		h_position = glm::vec3(x, y, 1);
	}

	void Player::setIsColliding(bool isColliding)
	{
		h_isColliding = isColliding;
	}
