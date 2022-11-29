#pragma once
#include "DLLExport.h"
#include "renderer.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

struct Coordinates
{
	float x;
	float y;
	float z;

};

class Entity
{
public:
	DllExport Entity();
	DllExport ~Entity();
	DllExport void addPosition(float x, float y, float z);
	DllExport glm::vec3 getPosition();
	DllExport void addRotationToAxis(float angleAmount, glm::vec3 axis);
	DllExport glm::vec3 getRotation();
	DllExport void scaleToRelative(float x, float y, float z);
	DllExport glm::vec3 getScale();
	DllExport void updateModelMatrix();
	DllExport glm::mat4 getModelMatrix();
	DllExport virtual void draw(Renderer* renderer, int indexCount) = 0;
	DllExport unsigned int getVBO();
	DllExport unsigned int getIBO();
	DllExport unsigned int getVAO();
	DllExport float getPosX();
	DllExport float getPosY();
	DllExport float getPosZ();
	DllExport void setPos(glm::vec3 pos);
	DllExport float getSizeX();
	DllExport float getSizeY();
	DllExport float getSizeZ();
	DllExport void setSize(glm::vec3 size);

private:
	glm::vec3 rotationVec = glm::vec3(1.0f,1.0f,1.0f);  //Vector que pertenece a la matriz identidad
	glm::vec3 scaleVec = glm::vec3(1.0f, 1.0f, 1.0f);  //Vector que pertenece a la matriz identidad
	glm::vec3 posVec = glm::vec3(50.0f, 50.0f, 50.0f);
	glm::mat4 translateMat; //Inicializamos las matrices con la matriz identidad glm::mat4(1.0f)
	glm::mat4 rotationMat;
	glm::mat4 scaleMat;
	glm::mat4 modelMatrix;
	
	unsigned int vertexBufferObject;
	unsigned int indexBufferObject;
	unsigned int vertexArrayObject;

protected:
	float lenghtX;
	float lenghtY;
	float lenghtZ;
};


