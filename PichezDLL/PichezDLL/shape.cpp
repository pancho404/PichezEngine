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
	//Hardcodeamos las posiciones del array de vertices
	vertexPositions[0] = 1.5f;
	vertexPositions[1] = -1.5f;
	vertexPositions[2] = 0.0f;
	vertexPositions[3] = 2.5f;
	vertexPositions[4] = -1.5f;
	vertexPositions[5] = 0.0f;
	vertexPositions[6] = 2.5f;
	vertexPositions[7] = -1.0f;
	vertexPositions[8] = 0.0f;
	vertexPositions[9] = 1.5f;
	vertexPositions[10] = -1.0f;
	vertexPositions[11] = 0.0f;
}

DllExport void Shape::createTriangle()
{
	//Hardcodeamos las posiciones del array de vertices
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

DllExport void Shape::setVertices(int subIndex, float newVertexPos) //Esta función permite cambiar el valor de un vertice especificando su subindice y la nueva posicion
{
	this->vertexPositions[subIndex] = newVertexPos; 
}

