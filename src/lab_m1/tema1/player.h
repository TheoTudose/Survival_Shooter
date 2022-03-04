#ifndef TEMA1_PLAYER_H
#define TEMA1_PLAYER_H

#include "utils/gl_utils.h"
#include "components/simple_scene.h"


class Player {
private:
	glm::vec3 h_color = glm::vec3 (1, 1, 0);
	glm::vec3 h_position;
	int h_health = 10;
	float h_radius = 1.0f;
	glm::vec3 h_initialPos = glm::vec3 (15, 10, 1);
	bool h_isColliding = false;;
	float h_reloadTime = 0.5f;

public:
	Player(float radius, glm::vec3 color, glm::vec3 position, int health, bool isColliding, float reloadTime);
	
	Player();

	int getHealth()
	{
		return h_health;
	}
	float getRadius()
	{
		return h_radius;
	}
	glm::vec3 getColor()
	{
		return h_color;
	}

	glm::vec3 getPosition()
	{
		return h_position;
	}

	glm::vec3 getInitialPos()
	{
	return h_initialPos;
	}

	bool getIsColliding()
	{
		return h_isColliding;
	}

	float getReloadTime()
	{
		return h_reloadTime;
	}

	void setHealth(int health);

	void setPosition(float x, float y);

	void setIsColliding(bool isColliding);

};

#endif //TEMA1_PLAYER_H
