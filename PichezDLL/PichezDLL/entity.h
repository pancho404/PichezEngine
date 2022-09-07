#pragma once
#include "DLLExport.h"
#include <list>

struct Position
{
	float x;
	float y;
	float z;
};

class Entity
{
public:
	DllExport Entity(std::list<Position> vertexes);
	DllExport ~Entity();
	DllExport void setPosition(Position newPos);
	DllExport Position getPosition();
	DllExport std::list<Position> getVertexList();
	DllExport virtual void draw() = 0;
	
private:
	Position entityPos;
	std::list<Position> vertexList;
};


