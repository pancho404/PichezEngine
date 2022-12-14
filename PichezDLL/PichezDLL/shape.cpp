#include "shape.h"

DllExport Shape::Shape()
{
	
}

DllExport Shape::~Shape()
{
}

DllExport void Shape::draw(Renderer* renderer, int indexCount, unsigned int textureID)
{
	unsigned int VAO = getVAO();
	renderer->Draw(indexCount, VAO, textureID);
}



DllExport void Shape::createSquare(Renderer* renderer)
{
	
	
	unsigned int indexes[] =
	{
		0,1,3,
		1,2,3
	};
	lenghtX = 100.0f;
	lenghtY = 100.0f;
	lenghtZ = 100.0f;
	setSize(glm::vec3(50.0f, 50.0f, 50.0f));
	unsigned int vbo = getVBO();
	unsigned int ibo = getIBO();
	renderer->setBuffers(1, vertices, GL_STATIC_DRAW, GL_ARRAY_BUFFER, vbo); //Seteamos el buffer creado
	renderer->setBuffers(1, indexes, GL_STATIC_DRAW, GL_ELEMENT_ARRAY_BUFFER, ibo); //Seteamos el buffer creado
	//Hardcodeamos las posiciones del array de vertices

}

DllExport void Shape::createTriangle(Renderer* renderer)
{
	
	unsigned int indexes[] =
	{
		0,1,3,
		1,2,3
	};
	setSize(glm::vec3(50.0f, 50.0f, 50.0f));
	unsigned int vbo;
	unsigned int ibo;
	lenghtX = 100.0f;
	lenghtY = 100.0f;
	lenghtZ = 100.0f;
	renderer->setBuffers(1, vertices, GL_STATIC_DRAW, GL_ARRAY_BUFFER, vbo); //Seteamos el buffer creado
	renderer->setBuffers(1, indexes, GL_STATIC_DRAW, GL_ELEMENT_ARRAY_BUFFER, ibo); //Seteamos el buffer creado
	//Hardcodeamos las posiciones del array de vertices
}

DllExport void Shape::updatePos()
{
	
}

DllExport float* Shape::getVertices()
{
	return vertices;
}



