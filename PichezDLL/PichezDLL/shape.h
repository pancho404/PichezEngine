#pragma once
#include<vector>
#include"entity2d.h"
class Shape : public Entity2d
{
private:
	float vertices[32] =
	{
		// positions          // colors           // texture coords
		 100.0f,  0, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // top right
		 100.0f, 100.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,   // bottom right
		 0.0f, 100.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,   // bottom left
		 0.0f,  0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f    // top left 
	};
public:
	DllExport Shape();
	DllExport ~Shape();
	DllExport void draw(Renderer* renderer, int indexCount, unsigned int textureID) override;
	DllExport void createSquare(Renderer* renderer);
	DllExport void createTriangle(Renderer* renderer);
	DllExport void updatePos();
	DllExport float* getVertices();

};

