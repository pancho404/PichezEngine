#include "entity.h"


DllExport Entity::Entity()
{
	
}

Entity::~Entity()
{

}

DllExport void Entity::setPosition(float x, float y, float z)
{
	glm::vec3 vecToAdd = glm::vec3(x, y, z);
	translateMat = glm::translate(translateMat, vecToAdd);
	positionVec = translateMat * positionVec;
}

DllExport glm::vec4 Entity::getPosition()
{
	return positionVec;
}

DllExport void Entity::setRotation(float angleAmount, glm::vec3 axis)
{
	translateMat = glm::rotate(translateMat, glm::radians(angleAmount), axis);
}

DllExport glm::vec4 Entity::getRotation()
{
	return rotationVec;
}

DllExport void Entity::setScale(float x, float y, float z)
{
	glm::vec3 vector = glm::vec3(x, y, z);
	scaleMat = glm::scale(scaleMat, vector);
	scaleVec;
}

DllExport glm::vec4 Entity::getScale()
{
	return scaleVec;
}

DllExport void Entity::updateModelMatrix()
{
	rotationMat* scaleMat* translateMat;
}

DllExport glm::mat4 Entity::getModelMatrix()
{
	return modelMatrix;
}


