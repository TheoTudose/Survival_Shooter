#ifndef TEMA1_PROJECTILE_H
#define TEMA1_PROJECTILE_H

#include "utils/gl_utils.h"
#include "components/simple_scene.h"


class Projectile {
private:
	glm::vec3 h_color = glm::vec3(0.000, 0.749, 1.000);
	glm::vec3 h_trajectory;
	bool h_spawn = true;
	float h_length = 0.8f;
	glm::vec3 h_initialPos;
	float h_airTime = 0;
	float h_cooldown = 0.5f;
	float h_speed;
	float h_translateX = 0;
	float h_translateY = 0;
	glm::mat3 h_modelMatrix;
	float h_angle1;
	glm::vec3 h_playerPos;
	glm::vec2 h_realPos;


public:
	Projectile(float length, glm::vec3 color, glm::vec3 trajectory,
		bool spawn, float airTime, float cooldown, float speed, float translateX, float translateY, glm::mat3 modelMatrix);

	Projectile();

	bool getSpawn()
	{
		return h_spawn;
	}
	float getLength()
	{
		return h_length;
	}
	glm::vec3 getColor()
	{
		return h_color;
	}

	glm::vec3 getTrajectory()
	{
		return h_trajectory;
	}

	glm::vec3 getInitialPos()
	{
		return h_initialPos;
	}

	float getAirTime()
	{
		return h_airTime;
	}

	float getCoolDown()
	{
		return h_cooldown;
	}

	float getSpeed()
	{
		return h_speed;
	}

	float getTranslateX()
	{
		return h_translateX;
	}

	float getTranslateY()
	{
		return h_translateY;
	}

	glm::mat3 getModelMatrix()
	{
		return h_modelMatrix;
	}

	float getAngle()
	{
		return h_angle1;
	}

	glm::vec2 getRealPos()
	{
		return h_realPos;
	}


	void setAirTime(float deltaTimeSeconds);

	void setSpeed(float deltaTimeSeconds);

	void setSpawn(bool spawn);

	void setInitialPos(float x, float y);

	void setTrajectory(int x, int y);

	void setTranslateX(float deltaTimeSeconds);

	void setTranslateY(float deltaTimeSeconds);

	void setModelMatrix(glm::mat3 visMatrix, float angle);

	void setAngle(float angle);

	void setPlayerPos(float x, float y);

	void setRealPos();
};

#endif //TEMA1_PROJECTILE_H
