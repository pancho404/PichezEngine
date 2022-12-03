#include"CollisionManager.h"

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

DllExport bool CollisionManager::isColliding(Entity* objectOne, Entity* objectTwo)
{

    // collision x-axis?
    bool collisionX = (objectOne->getPosX() + objectOne->getScale().x >= objectTwo->getPosX() - objectTwo->getScale().x &&
        objectTwo->getPosX() + objectTwo->getScale().x >= objectOne->getPosX() - objectOne->getScale().x) || (objectOne->getPosX() - objectOne->getScale().x <= objectTwo->getPosX() + objectTwo->getScale().x &&
            objectTwo->getPosX() + objectTwo->getScale().x <= objectOne->getPosX() - objectOne->getScale().x);
      
    // collision y-axis?
    bool collisionY = (objectOne->getPosY() + objectOne->getScale().y >= objectTwo->getPosY() + objectTwo->getScale().y &&
        objectTwo->getPosY() + objectTwo->getScale().y >= objectOne->getPosY() - objectOne->getScale().y) || (objectOne->getPosY() + objectOne->getScale().y >= objectTwo->getPosY() - objectTwo->getScale().y &&
            objectTwo->getPosY() + objectTwo->getScale().y >= objectOne->getPosY() - objectOne->getScale().y);
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

