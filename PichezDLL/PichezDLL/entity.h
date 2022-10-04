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
	DllExport glm::vec4 getPosition();
	DllExport void addRotationToAxis(float angleAmount, glm::vec3 axis);
	DllExport glm::vec4 getRotation();
	DllExport void scaleToRelative(float x, float y, float z);
	DllExport glm::vec4 getScale();
	DllExport void updateModelMatrix();
	DllExport glm::mat4 getModelMatrix();
	DllExport virtual void draw(Renderer* renderer, int indexCount) = 0;

private:	
	glm::vec4 positionVec = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f); //Vector que pertenece a la matriz identidad
	glm::vec4 rotationVec = glm::vec4(0.0f, 1.0, 0.0f, 1.0f);  //Vector que pertenece a la matriz identidad
	glm::vec4 scaleVec = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);  //Vector que pertenece a la matriz identidad
	glm::mat4 translateMat = glm::mat4(1.0f); //Inicializamos las matrices con la matriz identidad glm::mat4(1.0f)
	glm::mat4 rotationMat = glm::mat4(1.0f);
	glm::mat4 scaleMat = glm::mat4(1.0f);
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	
};


