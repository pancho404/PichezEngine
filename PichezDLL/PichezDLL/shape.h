#pragma once
#include<vector>
#include"entity2d.h"
class Shape : public Entity2d
{
private:
	
public:
	DllExport Shape();
	DllExport ~Shape();
	DllExport void draw(Renderer* renderer, int indexCount, unsigned int textureID) override;
	DllExport void createSquare(Renderer* renderer);
	DllExport void createTriangle(Renderer* renderer);
	DllExport void updatePos();
	DllExport float* getVertices();

};

