#ifndef TEMA1_ENEMY_H
#define TEMA1_ENEMY_H

#include "utils/gl_utils.h"
#include "components/simple_scene.h"

class Enemy {
private:
	glm::vec3 h_color = glm::vec3(1.000, 0.271, 0.000);
	glm::vec2 h_position;
	int h_health = 1;
	float h_length = 2;
	glm::vec2 h_initialPos;
	glm::vec2 h_trajectory;
	float h_speed;
	glm::mat3 h_modelMatrix1;
	glm::mat3 h_modelMatrix2;
	glm::mat3 h_modelMatrix3;
	float h_angle1;
	glm::vec2 h_playerPos;
	glm::vec2 h_translate = glm::vec2 (0.0f, 0.0f);

public:
	Enemy(float length, glm::vec3 color, glm::vec2 position, int health, glm::vec2 initialPos,
		glm::vec2 trajectory, glm::mat3 modelMatrix1, glm::mat3 modelMatrix2,
		glm::mat3 modelMatrix3, float angle, glm::vec2 playerPos, glm::vec2 translate);

	Enemy();

	int getHealth()
	{
		return h_health;
	}
	float getLength()
	{
		return h_length;
	}
	glm::vec3 getColor()
	{
		return h_color;
	}

	glm::vec2 getPosition()
	{
		return h_position;
	}

	glm::vec2 getInitialPos()
	{
		return h_initialPos;
	}

	glm::vec2 getTrajectory()
	{
		return h_trajectory;
	}

	float getSpeed()
	{
		return h_speed;
	}

	glm::vec2 getTranslate()
	{
		return h_translate;
	}

	glm::mat3 getModelMatrix1()
	{
		return h_modelMatrix1;
	}

	glm::mat3 getModelMatrix2()
	{
		return h_modelMatrix2;
	}

	glm::mat3 getModelMatrix3()
	{
		return h_modelMatrix3;
	}

	float getAngle()
	{
		return h_angle1;
	}

	glm::vec2 getPlayerPos()
	{
		return h_playerPos;
	}

	void setHealth(int health);

	void setPosition();

	void setSpeed();

	void setInitialPos();

	void setTrajectory(glm::vec2 position);

	void setTranslate(float deltaTimeSeconds);

	void setModelMatrix(glm::mat3 visMatrix);

	void setAngle();

	void setPlayerPos(float x, float y);

};

#endif //TEMA1_ENEMY_H
