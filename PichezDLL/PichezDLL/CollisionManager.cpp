#include"CollisionManager.h"

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

DllExport bool CollisionManager::isColliding(Shape* objectOne, Shape* objectTwo)
{

    // collision x-axis?
    bool collisionX = objectOne->getPosX() + objectOne->getSizeX() >= objectTwo->getPosX() &&
        objectTwo->getPosX() + objectTwo->getSizeX() >= objectOne->getPosX();
    // collision y-axis?
    bool collisionY = objectOne->getPosY() + objectOne->getSizeY() >= objectTwo->getPosY() &&
        objectTwo->getPosY() + objectTwo->getSizeY() >= objectOne->getPosY();
    // collision only if on both axes
    
    return collisionX && collisionY;
}
