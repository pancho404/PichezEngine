#include "renderer.h"

DllExport Renderer::Renderer()
{

}

DllExport Renderer::~Renderer()
{

}

DllExport void Renderer::renderWindow(GLFWwindow* window)
{
	unsigned int buffer; //creamos una variable que sera utilizada como buffer
	float vertexPositions[vertexBufferSize] = //Creamos el array de las posiciones de los vertices del triangulo 
	{
		-0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f
	};
	setBuffers(1, buffer, vertexBufferSize, vertexPositions, GL_STATIC_DRAW); //Seteamos el buffer creado
	setFloatVertex(); //Seteamos los datos de las posiciones de los vertices

	while (!windowShouldClose(window))
	{
		clearWindow();

		glDrawArrays(GL_TRIANGLES, 0, 3); //Dibujamos recorriendo el array ENTERO creado anteriormente
		
		swapBuffers(window);

		pollEvents();
		
	}
}

DllExport void Renderer::clearWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

DllExport void Renderer::swapBuffers(GLFWwindow* window)
{
	glfwSwapBuffers(window);
}

DllExport void Renderer::pollEvents()
{
	glfwPollEvents();
}

DllExport int Renderer::windowShouldClose(GLFWwindow* window)
{
	return glfwWindowShouldClose(window);
}

DllExport void Renderer::setBuffers(int quantity, unsigned int& id, const int bufferSize, float bufferArray[], GLenum bufferMode)
{
	glGenBuffers(quantity, &id); //Crea el buffer con el ID pasado por parametro (un unsigned int)
	glBindBuffer(GL_ARRAY_BUFFER, id); //Permite utilizar el buffer creado como un buffer de openGL
	glBufferData(GL_ARRAY_BUFFER, bufferSize * sizeof(float), bufferArray, bufferMode);	//Le asigna la info al buffer
}

DllExport void Renderer::setFloatVertex()
{
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0); //Asigna los atributos XYZ RGB ST del vertice y por cual debera empezar a leer
	glEnableVertexAttribArray(0);
}

