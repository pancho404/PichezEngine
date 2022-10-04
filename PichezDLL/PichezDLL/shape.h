#pragma once
#include"entity2d.h"
class Shape : public Entity2d
{
private:
	float vertexPositions[12];
	unsigned int indexes[6]
	{
		0,1,2,
		2,3,0
	};
public:
	DllExport Shape();
	DllExport ~Shape();
	DllExport void setVertices(int subIndex, float newVertexPosition);
	DllExport void draw(Renderer* renderer, int indexCount) override;
	DllExport void createSquare();
	DllExport void createTriangle();
	DllExport float* getVertexPositions();
	DllExport unsigned int* getIndexes();
};

