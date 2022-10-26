#pragma once
#include<vector>
#include"entity2d.h"
class Shape : public Entity2d
{
private:
	std::vector<float> vertices;

public:
	DllExport Shape();
	DllExport ~Shape();
	DllExport void draw(Renderer* renderer, int indexCount) override;
	DllExport void createSquare(Renderer* renderer);
	DllExport void createTriangle(Renderer* renderer);


};

