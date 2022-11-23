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



DllExport void Shape::createSquare(Renderer* renderer)
{

	float vertices[] =
	{
		// positions          // colors           // texture coords
		 640.0f,  0.0f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		 640.0f, 100.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
	 	 550.0f, 100.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		 550.0f,  0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};
	unsigned int indexes[] =
	{
		0,1,3,
		1,2,3
	};
	unsigned int vbo = getVBO();
	unsigned int ibo = getIBO();
	renderer->setBuffers(1, vertices, GL_STATIC_DRAW, GL_ARRAY_BUFFER, vbo); //Seteamos el buffer creado
	renderer->setBuffers(1, indexes, GL_STATIC_DRAW, GL_ELEMENT_ARRAY_BUFFER, ibo); //Seteamos el buffer creado
	//Hardcodeamos las posiciones del array de vertices

}

DllExport void Shape::createTriangle(Renderer* renderer)
{
	float vertices[] =
	{
		// positions          // colors           // texture coords
		 100.0f,  0.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
		 100.0f, 100.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
		 0.0f, 100.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		 550.0f,  0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};
	unsigned int indexes[] =
	{
		0,1,3
	};

	unsigned int vbo = getVBO();
	unsigned int ibo = getIBO();
	renderer->setBuffers(1, vertices, GL_STATIC_DRAW, GL_ARRAY_BUFFER, vbo); //Seteamos el buffer creado
	renderer->setBuffers(1, indexes, GL_STATIC_DRAW, GL_ELEMENT_ARRAY_BUFFER, ibo); //Seteamos el buffer creado
	//Hardcodeamos las posiciones del array de vertices
}



