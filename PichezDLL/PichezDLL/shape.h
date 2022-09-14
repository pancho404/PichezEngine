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
	void draw() override;


};

