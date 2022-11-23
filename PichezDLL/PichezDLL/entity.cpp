#include "entity.h"


DllExport Entity::Entity()
{

}

Entity::~Entity()
{

}

DllExport void Entity::addPosition(float x, float y, float z)
{
	glm::vec3 vecToAdd = glm::vec3(x, y, z); //Creamos el vector que se le sumará a la posicion actual de
	translateMat = glm::translate(translateMat, vecToAdd); //realizamos la adicion del vector a la matriz, modificando así los valores de la matriz
	//positionVec = translateMat * positionVec; //Multiplicamos la matriz por el vector, modificando así el vector para actualizar a la posicion actual
	updateModelMatrix();
}

DllExport glm::vec4 Entity::getPosition()
{
	return positionVec;
}

DllExport void Entity::addRotationToAxis(float angleAmount, glm::vec3 axis)
{
	rotationMat = glm::rotate(rotationMat, glm::radians(angleAmount), axis); //Modificamos la matriz rotationMat en una cantidad de radianes sobre un eje en especifico
	//rotationVec = rotationMat * rotationVec; //Actualizamos el vector rotacion mediante multiplicarlo por la matriz correspondiente
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
	//scaleVec = scaleMat * scaleVec; //Actualizamos el vector escala mediante multiplicarlo por la matriz correspondiente
	updateModelMatrix();
}

DllExport glm::vec4 Entity::getScale()
{
	return scaleVec;
}

DllExport void Entity::updateModelMatrix()
{
	//modelMatrix = scaleMat * rotationMat * translateMat;
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

DllExport Coordinates Entity::getPos()
{
	return pos;
}

DllExport void Entity::setPos(Coordinates pos)
{
	this->pos = pos;
}


