#pragma once
#include "DLLExport.h"
#include "entity.h"
#include "shape.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();
	DllExport bool isColliding(Entity* objectOne, Entity* objectTwo);
	DllExport bool isCollidiingX(Entity* objectOne, Entity* objectTwo);
	DllExport bool isCollidiingY(Entity* objectOne, Entity* objectTwo);
private:

};

