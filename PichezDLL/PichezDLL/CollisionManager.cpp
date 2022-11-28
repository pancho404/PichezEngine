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

DllExport bool CollisionManager::isCollidiingX(Shape* objectOne, Shape* objectTwo)
{
    bool collision = objectOne->getPosX() > objectTwo->getPosX() || objectOne->getPosX() < objectTwo->getPosX();
    return collision;
}

DllExport bool CollisionManager::isCollidiingY(Shape* objectOne, Shape* objectTwo)
{
    bool collision = objectOne->getPosY() > objectTwo->getPosY() || objectOne->getPosY() < objectTwo->getPosY();
    return collision;
}

