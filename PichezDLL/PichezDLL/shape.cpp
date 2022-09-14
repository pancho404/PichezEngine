#include "shape.h"

Shape::Shape()
{
}

Shape::~Shape()
{
}

void Shape::setVertices(int vertexCount, float* vertexPosition)
{
	this->vertexPosition = vertexPosition;
	this->vertexCount = vertexCount;
}
