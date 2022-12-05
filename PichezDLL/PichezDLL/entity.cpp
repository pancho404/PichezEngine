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
	//glm::vec3 vecToAdd = glm::vec3(0.0f, 0.0f, 0.0f); //Creamos el vector que se le sumará a la posicion actual de
	//vecToAdd = glm::vec3(x, y, z); //Creamos el vector que se le sumará a la posicion actual de
	translateMat = glm::mat4(1.0f);
	posVec.x += x;
	posVec.y += y;
	posVec.z += z;
	translateMat = glm::translate(translateMat, posVec); //realizamos la adicion del vector a la matriz, modificando así los valores de la matriz
	updateModelMatrix();
}

DllExport glm::vec3 Entity::getPosition()
{
	return posVec;
}

DllExport void Entity::addRotationToAxis(float angleAmount, glm::vec3 axis)
{
	rotationMat = glm::rotate(rotationMat, glm::radians(angleAmount), axis); //Modificamos la matriz rotationMat en una cantidad de radianes sobre un eje en especifico
	updateModelMatrix();
}

DllExport glm::vec3 Entity::getRotation()
{
	return rotationVec;
}

DllExport void Entity::scaleToRelative(float x, float y, float z)
{
	glm::vec3 vector = glm::vec3(x, y, z); //Creamos un vector con los valores pasados por parametro	
	//scaleVec = vector + glm::vec3(scaleVec.x, scaleVec.y, scaleVec.z);
	//posVec = vector + glm::vec3(posVec.x, posVec.y, posVec.z) / glm::vec3(2.0f);
	scaleMat = glm::scale(scaleMat, vector); //Escalamaos pasando por parametro la matriz escala y el vector que contiene el valor relativo al que sera escalado el objeto
	lenghtX += scaleVec.x;
	lenghtX += scaleVec.y;
	lenghtX += scaleVec.z;
	updateModelMatrix();
}

DllExport glm::vec3 Entity::getScale()
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

DllExport float Entity::getPosX()
{
	return posVec.x;
}

DllExport float Entity::getPosY()
{
	return posVec.y;
}

DllExport float Entity::getPosZ()
{
	return posVec.z;
}

DllExport float Entity::getSizeX()
{
	return lenghtX;
}

DllExport float Entity::getSizeY()
{
	return lenghtY;
}

DllExport float Entity::getSizeZ()
{
	return lenghtZ;
}

DllExport void Entity::setSize(glm::vec3 size)
{
	this->scaleVec.x = size.x;
	this->scaleVec.y = size.y;
	this->scaleVec.z = size.z;
}

DllExport void Entity::setPos(glm::vec3 pos)
{
	this->posVec = pos;
}



