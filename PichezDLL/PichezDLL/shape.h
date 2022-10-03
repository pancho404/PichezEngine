#pragma once
#include"entity2d.h"
class Shape :Entity2d
{
private:
	float vertexPositions[12];
	unsigned int indexes[6]
	{
		0,1,2,
		2,3,0
	};
public:
	Shape();
	~Shape();
	void setVertices(int vertexCount, float* vertexPosition);
	void draw(Renderer* renderer, int indexCount) override;
	void createSquare();
	void createTriangle();
	float* getVertexPositions();
	unsigned int* getIndexes();
};

