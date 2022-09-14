#include "entity.h"

DllExport Entity::Entity(/*std::list<Coordinates> vertexes*/)
{
	//vertexList = vertexes;
}

Entity::~Entity()
{

}

DllExport void Entity::setPosition(Coordinates newPos)
{
	pos = newPos;
}

DllExport Coordinates Entity::getPosition()
{
	return pos;
}

//DllExport std::list<Coordinates> Entity::getVertexList()
//{
//	return vertexList;
//}

DllExport void Entity::setRotation(Coordinates newRotation)
{
	rotation = newRotation;
}

DllExport Coordinates Entity::getRotation()
{
	return rotation;
}

DllExport void Entity::setScale(Coordinates newScale)
{
	scale = newScale;
}

DllExport Coordinates Entity::getScale()
{
	return scale;
}


