#include "enemy.h"

#include "utils/gl_utils.h"
#include "components/simple_scene.h"
#include "lab_m1/tema1/transform2D.h"

Enemy::Enemy(float length, glm::vec3 color, glm::vec2 position, int health, glm::vec2 initialPos,
	glm::vec2 trajectory, glm::mat3 modelMatrix1, glm::mat3 modelMatrix2,
	glm::mat3 modelMatrix3, float angle, glm::vec2 playerPos, glm::vec2 translate)
{
	h_length = length;
	h_color = color;
	h_position = position;
	h_health = health;
	h_initialPos = initialPos;
	h_trajectory = trajectory;
	h_modelMatrix1 = modelMatrix1;
	h_modelMatrix2 = modelMatrix2;
	h_modelMatrix3 = modelMatrix3;
	h_angle1 = angle;
	h_playerPos = playerPos;
	h_translate = translate;
}
Enemy::Enemy() {}


void Enemy::setHealth(int health)
{
	h_health = health;
}

void Enemy::setPosition()
{
	h_position = glm::vec2(h_initialPos.x + h_translate.x, h_initialPos.y + h_translate.y);
}

void Enemy::setSpeed()
{
	h_speed = rand() % 10 + 3;
}

void Enemy::setInitialPos()
{
	h_initialPos.x = rand() % 47 - 11;
	h_initialPos.y = rand() % 38 + 0;
}

void Enemy::setTrajectory(glm::vec2 position) {
	h_trajectory = h_playerPos - position;
	h_trajectory = glm::normalize(h_trajectory);
}

void Enemy::setTranslate(float deltaTimeSeconds)
{
	h_translate.x += h_trajectory.x * deltaTimeSeconds * h_speed;
		h_translate.y += h_trajectory.y * deltaTimeSeconds * h_speed;
}

void Enemy::setModelMatrix(glm::mat3 visMatrix)
{
	h_modelMatrix1 = visMatrix * transform2D::Translate(h_initialPos.x + h_translate.x, h_initialPos.y + h_translate.y) *
		transform2D::Translate(h_length / 2, h_length / 2) *
		transform2D::Rotate(h_angle1) *
		transform2D::Translate(-h_length / 2, -h_length / 2);
	h_modelMatrix2 = visMatrix * transform2D::Translate((h_initialPos.x + 1.0f) + h_translate.x, (h_initialPos.y + 1.0f)+ h_translate.y) *
		transform2D::Rotate(h_angle1) *
		transform2D::Translate(-h_initialPos.x - 1.0f, -h_initialPos.y - 1.0f)*
		transform2D::Translate(h_initialPos.x + 2.0f , h_initialPos.y + 2.0f);

	h_modelMatrix3 = visMatrix * transform2D::Translate((h_initialPos.x + 1.0f) + h_translate.x, (h_initialPos.y + 1.0f) + h_translate.y) *
		transform2D::Rotate(h_angle1) *
		transform2D::Translate(-h_initialPos.x - 1.0f, -h_initialPos.y - 1.0f) *
		transform2D::Translate(h_initialPos.x + 2.0f, h_initialPos.y);
}

void Enemy::setPlayerPos(float x, float y)
{
	h_playerPos.x = x;
	h_playerPos.y = y;
}

void Enemy::setAngle()
{
	float x = h_playerPos.x - h_position.x;
	float y = h_playerPos.y - h_position.y;
	h_angle1 = atan2(y, x);
}