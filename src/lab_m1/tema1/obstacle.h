#ifndef TEMA1_OBSTACLE_H
#define TEMA1_OBSTACLE_H

#include "utils/gl_utils.h"
#include "components/simple_scene.h"

class Obstacle {
private:
	glm::vec3 h_color = glm::vec3(0, 1, 0);
	float h_length;
	glm::vec3 h_pos;
	glm::vec3 h_size;
	float h_centerX;
	float h_centerY;
	glm::mat3 h_modelMatrix;

public:
	Obstacle(glm::vec3 color, float length, glm::vec3 pos, glm::vec3 size,
		float centerX, float centerY, glm::mat3 modelMatrix);

	Obstacle();

	glm::vec3 getColor()
	{
		return h_color;
	}

	glm::vec3 getPos()
	{
		return h_pos;
	}

	glm::vec3 getSize()
	{
		return h_size;
	}

	float getCenterX()
	{
		return h_centerX;
	}

	float getCenterY()
	{
		return h_centerY;
	}

	glm::mat3 getModelMatrix()
	{
		return h_modelMatrix;
	}

	void setPos(float x, float y);

	void setSize(float x, float y);

	void setCenterX();

	void setCenterY();

	void setModelMatrix(glm::mat3 visMatrix);

};
#endif //TEMA1_OBSTACLE_H
