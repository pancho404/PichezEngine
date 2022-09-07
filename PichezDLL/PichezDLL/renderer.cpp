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

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"}\n";

	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0, 0.0, 0.0, 1.0);\n"
		"}\n";

	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	while (!windowShouldClose(window))
	{
		clearWindow();

		glDrawArrays(GL_TRIANGLES, 0, 3); //Dibujamos recorriendo el array ENTERO creado anteriormente

		swapBuffers(window);

		pollEvents();

	}
	glDeleteProgram(shader);
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

DllExport unsigned int Renderer::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);


	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? " vertex" : " fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);

		return 0;
	}
	return id;
}
DllExport  unsigned int Renderer::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vS = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fS = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vS);
	glAttachShader(program, fS);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vS);
	glDeleteShader(fS);

	return program;
}

