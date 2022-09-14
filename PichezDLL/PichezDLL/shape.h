#pragma once
#include"entity2d.h"
class Shape :Entity2d
{
private:
	float* vertexPosition;
	int vertexCount;

public:
	Shape();
	~Shape();
	void setVertices(int vertexCount, float* vertexPosition);
	void draw(Renderer* renderer) override;
	float* getVertexPosition()
	{
		return vertexPosition;
	}
	int getVertexCount()
	{
		return vertexCount;
	}


};

