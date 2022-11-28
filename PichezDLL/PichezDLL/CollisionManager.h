#pragma once
#include "DLLExport.h"
#include "entity.h"
#include "shape.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();
	DllExport bool isColliding(Shape* objectOne, Shape* objectTwo);
	DllExport bool isCollidiingX(Shape* objectOne, Shape* objectTwo);
	DllExport bool isCollidiingY(Shape* objectOne, Shape* objectTwo);
private:

};

