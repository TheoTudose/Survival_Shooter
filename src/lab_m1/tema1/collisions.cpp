#include "collisions.h"
#include <vector>
#include <iostream>
#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"
#include "player.h"
#include "obstacle.h"
#include "enemy.h"

collisions::Direction collisions::VectorDirection(glm::vec2 target)
{
    glm::vec2 compass[] = {
        glm::vec2(0.0f, 1.0f),
        glm::vec2(0.0f, -1.0f),
        glm::vec2(-1.0f, 0.0f),
        glm::vec2(1.0f, 0.0f)
    };
    float max = 0.0f;
    unsigned int best_match = -1;
    for (unsigned int i = 0; i < 4; i++)
    {
        float dot_product = glm::dot(glm::normalize(target), compass[i]);
        if (dot_product > max)
        {
            max = dot_product;
            best_match = i;
        }
    }
    return (Direction)best_match;
}



collisions::Collision collisions::CheckPOCollision(Player* player, Obstacle& obstacle)
{
   
    glm::vec2 playerPos = glm::vec2(player->getPosition().x, player->getPosition().y);
    glm::vec2 square_halves(obstacle.getSize().x / 2.0f, obstacle.getSize().y / 2.0f);
    glm::vec2 difference = playerPos - glm::vec2(obstacle.getCenterX(), obstacle.getCenterY());
    glm::vec2 clamped = glm::clamp(difference, -square_halves, square_halves);
    glm::vec2 closest = glm::vec2(obstacle.getCenterX(), obstacle.getCenterY()) + clamped;
    difference = closest - playerPos;
    if (glm::length(difference) <= player->getRadius())
        return std::make_tuple(true, VectorDirection(difference), difference);
    else
        return std::make_tuple(false, UP, glm::vec2(0.0f, 0.0f));
}

bool collisions::CheckPrOCollision(std::vector<Projectile>::iterator i, Obstacle& obstacle)
{
   bool collisionX = i->getRealPos().x + i->getLength() >= obstacle.getPos().x &&
        obstacle.getPos().x + obstacle.getSize().x >= i->getRealPos().x;
   bool collisionY = i->getRealPos().y + i->getLength() >= obstacle.getPos().y &&
        obstacle.getPos().y + obstacle.getSize().y >= i->getRealPos().y;
   return collisionX && collisionY;
}

bool collisions::CheckPrECollision(std::vector<Projectile>::iterator i, std::vector<Enemy>::iterator j)
{
    bool collisionX = i->getRealPos().x + i->getLength() >= j->getPosition().x &&
        j->getPosition().x + j->getLength() >= i->getRealPos().x;
    bool collisionY = i->getRealPos().y + i->getLength() >= j->getPosition().y &&
        j->getPosition().y + j->getLength() >= i->getRealPos().y;
    return collisionX && collisionY;
}

bool collisions::CheckEPCollision(Player* player, std::vector<Enemy>::iterator i)
{
    glm::vec2 playerPos = glm::vec2(player->getPosition().x, player->getPosition().y);
    glm::vec2 square_halves(i->getLength() / 2.0f, i->getLength() / 2.0f);
    glm::vec2 proj_center(
        i->getPosition().x + square_halves.x,
        i->getPosition().y + square_halves.y
    );
    glm::vec2 difference = playerPos - proj_center;
    glm::vec2 clamped = glm::clamp(difference, -square_halves, square_halves);
    glm::vec2 closest = proj_center + clamped;
    difference = closest - playerPos;
    return glm::length(difference) < player->getRadius();
}