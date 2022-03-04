#pragma once
#include "player.h"
#include "obstacle.h"
#include "projectile.h"
#include "enemy.h"
#include "components/simple_scene.h"

namespace collisions
{

	enum Direction {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	
	Direction VectorDirection(glm::vec2 target);

	typedef std::tuple<bool, Direction, glm::vec2> Collision;
	
	Collision CheckPOCollision(Player* one, Obstacle& two);

	bool CheckPrOCollision(std::vector<Projectile>::iterator one, Obstacle& two);

	bool CheckPrECollision(std::vector<Projectile>::iterator one, std::vector<Enemy>::iterator two);

	bool CheckEPCollision(Player* one, std::vector<Enemy>::iterator two);
}