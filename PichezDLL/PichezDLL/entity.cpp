#include "entity.h"


DllExport Entity::Entity()
{
	translateMat = glm::mat4(1.0f);
	scaleMat = glm::mat4(1.0f);
	rotationMat = glm::mat4(1.0f);
	modelMatrix = glm::mat4(1.0f);
}

Entity::~Entity()
{

}

DllExport void Entity::addPosition(float x, float y, float z)
{
	glm::vec3 vecToAdd = glm::vec3(x, y, z); //Creamos el vector que se le sumará a la posicion actual de
	translateMat = glm::translate(translateMat, vecToAdd); //realizamos la adicion del vector a la matriz, modificando así los valores de la matriz
	updateModelMatrix();
}

DllExport glm::vec4 Entity::getPosition()
{
	return positionVec;
}

DllExport void Entity::addRotationToAxis(float angleAmount, glm::vec3 axis)
{
	rotationMat = glm::rotate(rotationMat, glm::radians(angleAmount), axis); //Modificamos la matriz rotationMat en una cantidad de radianes sobre un eje en especifico
	updateModelMatrix();
}

DllExport glm::vec4 Entity::getRotation()
{
	return rotationVec;
}

DllExport void Entity::scaleToRelative(float x, float y, float z)
{
	glm::vec3 vector = glm::vec3(x, y, z); //Creamos un vector con los valores pasados por parametro
	scaleMat = glm::scale(scaleMat, vector); //Escalamaos pasando por parametro la matriz escala y el vector que contiene el valor relativo al que sera escalado el objeto
	updateModelMatrix();
}

DllExport glm::vec4 Entity::getScale()
{
	return scaleVec;
}

DllExport void Entity::updateModelMatrix()
{
	modelMatrix = translateMat * rotationMat * scaleMat;
}

DllExport glm::mat4 Entity::getModelMatrix()
{
	return modelMatrix;
}

DllExport unsigned int Entity::getVBO()
{
	return vertexBufferObject;
}

DllExport unsigned int Entity::getIBO()
{
	return indexBufferObject;
}

DllExport unsigned int Entity::getVAO()
{
	return vertexArrayObject;
}

DllExport Coordinates Entity::getPos()
{
	return pos;
}

DllExport void Entity::setPos(Coordinates pos)
{
	this->pos = pos;
}



