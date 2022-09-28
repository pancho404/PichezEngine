#pragma once
#include "DLLExport.h"
#include <list>
#include"renderer.h"

struct Coordinates
{
	float x;
	float y;
	float z;
};

class Entity
{
public:
	DllExport Entity(/*std::list<Coordinates> vertexes*/);
	DllExport ~Entity();
	DllExport void setPosition(Coordinates newPos);
	DllExport Coordinates getPosition();
	DllExport void setRotation(Coordinates newRotation);
	DllExport Coordinates getRotation();
	DllExport void setScale(Coordinates newScale);
	DllExport Coordinates getScale();
	//DllExport std::list<Coordinates> getVertexList();
	DllExport virtual void draw(Renderer* renderer, int indexCount) = 0;

private:
	Coordinates pos;
	Coordinates rotation;
	Coordinates scale;
	//std::list<Coordinates> vertexList;
};


