#include "projectile.h"

#include "utils/gl_utils.h"
#include "components/simple_scene.h"
#include "lab_m1/tema1/transform2D.h"

Projectile::Projectile(float length, glm::vec3 color, glm::vec3 trajectory,
	bool spawn, float airTime, float cooldown, float speed, float translateX, float translateY, glm::mat3 modelMatrix)
{
	h_length = length;
	h_color = color;
	h_trajectory = trajectory;
	h_spawn = spawn;
	h_airTime = airTime;
	h_cooldown = cooldown;
	h_speed = speed;
	h_translateX = translateX;
	h_translateY = translateY;
	h_modelMatrix = modelMatrix;
}
Projectile::Projectile() {}


void Projectile::setAirTime(float deltaTimeSeconds) {
	h_airTime += deltaTimeSeconds;
}

void Projectile::setSpeed(float deltaTimeSeconds) {
	h_speed = deltaTimeSeconds * 10;
}

void Projectile::setSpawn(bool spawn) {
	h_spawn = spawn;
}

void Projectile::setInitialPos(float x, float y) {
	h_initialPos = glm::vec3(x, y, 0.8f);
}

void Projectile::setTrajectory(int x, int y) {
	h_trajectory = glm::vec3((float)x, (float)y, 1.6f) - h_initialPos;
	h_trajectory = glm::normalize(h_trajectory);
}

void Projectile::setTranslateX(float deltaTimeSeconds) {
	h_translateX += h_trajectory.x * deltaTimeSeconds * 10;
}

void Projectile::setTranslateY(float deltaTimeSeconds) {
	h_translateY += h_trajectory.y * deltaTimeSeconds * 10;
}

void Projectile::setModelMatrix(glm::mat3 visMatrix, float angle) {
	h_modelMatrix = visMatrix * transform2D::Translate( h_playerPos.x + h_translateX,  h_playerPos.y + h_translateY) *
		transform2D::Translate(h_length / 2, h_length / 2) *
		transform2D::Rotate(angle) *
		transform2D::Translate(-h_length / 2, -h_length / 2);
}

void Projectile::setAngle(float angle) {
	h_angle1 = angle;
}

void Projectile::setPlayerPos(float x, float y) {
	h_playerPos = glm::vec3(x, y, 1.0f);
}

void Projectile::setRealPos() {
	h_realPos = glm::vec2(h_playerPos.x + h_translateX, h_playerPos.y + h_translateY);
}