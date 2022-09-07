#include "entity.h"

DllExport Entity::Entity(std::list<Position> vertexes)
{
	vertexList = vertexes;
}

Entity::~Entity()
{

}

DllExport void Entity::setPosition(Position newPos)
{
	entityPos = newPos;
}

DllExport Position Entity::getPosition()
{
	return entityPos;
}

DllExport std::list<Position> Entity::getVertexList()
{
	return vertexList;
}
