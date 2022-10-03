#include "shape.h"

DllExport Shape::Shape()
{
}

DllExport Shape::~Shape()
{
}

DllExport void Shape::draw(Renderer* renderer, int indexCount)
{
	renderer->Draw(indexCount);
}

DllExport unsigned int* Shape::getIndexes()
{
	return indexes;
}

DllExport void Shape::createSquare()
{
	vertexPositions[0] = -0.5f;
	vertexPositions[1] = -0.5f;
	vertexPositions[2] = 0.0f;
	vertexPositions[3] = 0.5f;
	vertexPositions[4] = -0.5f;
	vertexPositions[5] = 0.0f;
	vertexPositions[6] = 0.5f;
	vertexPositions[7] = 0.5f;
	vertexPositions[8] = 0.0f;
	vertexPositions[9] = -0.5f;
	vertexPositions[10] = 0.5f;
	vertexPositions[11] = 0.0f;
}

DllExport void Shape::createTriangle()
{
	vertexPositions[0] = -0.5f;
	vertexPositions[1] = -0.5f;
	vertexPositions[2] = 0.0f;
	vertexPositions[3] = 0.5f;
	vertexPositions[4] = -0.5f;
	vertexPositions[5] = 0.0f;
	vertexPositions[6] = 0.5f;
	vertexPositions[7] = 0.5f;
	vertexPositions[8] = 0.0f;
}

DllExport float* Shape::getVertexPositions()
{
	return vertexPositions;
}

DllExport void Shape::setVertices(int subindex, float newVertexPos)
{
	this->vertexPositions[subindex] = newVertexPos;
}

