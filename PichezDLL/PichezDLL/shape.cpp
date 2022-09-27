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

void Shape::draw(Renderer* renderer)
{
	renderer->Draw(vertexCount);
}
