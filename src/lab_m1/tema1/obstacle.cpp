#include "obstacle.h"
#include "utils/gl_utils.h"
#include "components/simple_scene.h"
#include "lab_m1/tema1/transform2D.h"

Obstacle::Obstacle(glm::vec3 color, float length, glm::vec3 pos, glm::vec3 size,
	float centerX, float centerY, glm::mat3 modelMatrix) 
{
	h_color = color;
	h_length = length;
	h_pos = pos;
	h_size = size;
	h_centerX = centerX;
	h_centerY = centerY;
	h_modelMatrix = modelMatrix;
}

Obstacle::Obstacle() {}

void Obstacle::setPos(float x, float y) 
{
	h_pos = glm::vec3(x, y, 0);
}

void Obstacle::setSize(float x, float y) 
{
	h_size = glm::vec3(x, y, 0);
}

void Obstacle::setCenterX()
{
	h_centerX = h_pos.x + h_size.x / 2.0f;
}

void Obstacle::setCenterY()
{
	h_centerY = h_pos.y + h_size.y / 2.0f;
}

void Obstacle::setModelMatrix(glm::mat3 visMatrix)
{
h_modelMatrix = visMatrix * transform2D::Translate(h_pos.x, h_pos.y) *
transform2D::Scale(h_size.x, h_size.y);
}