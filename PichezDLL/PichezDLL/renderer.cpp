#include "renderer.h"

DllExport Renderer::Renderer(static glm::mat4 shaderTransform)
{
	this->shaderTransform = shaderTransform;
}

DllExport Renderer::~Renderer()
{

}

DllExport void Renderer::renderWindow(GLFWwindow* window, float vertexPositions[], unsigned int indexes[])
{
	unsigned int indexBufferObject; //creamos una variable que sera utilizada como buffer
	unsigned int vertexBufferObject;

	setBuffers(1, vertexBufferObject, vertexPositions, GL_STATIC_DRAW, GL_ARRAY_BUFFER); //Seteamos el buffer creado
	setBuffers(1, indexBufferObject, indexes, GL_STATIC_DRAW, GL_ELEMENT_ARRAY_BUFFER); //Seteamos el buffer creado
	setFloatVertex(); //Seteamos los datos de las posiciones de los vertices

	/*std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"}\n";*/

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;"
		"\n"
		"out vec4 vertexColor;"
		"\n"
		"uniform mat4 modelMatrix;"
		"\n"
		"void main()\n"
		"{\n"
		"gl_Position = modelMatrix * vec4(position, 1.0f);\n"
		"vertexColor = vec4(1.0, 0.0, 1.0, 1.0);\n"
		"}\n";

	/*std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0, 0.0, 1.0, 1.0);\n"
		"}\n";*/

	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"in vec4 vertexColor;"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vertexColor;\n"
		"}\n";

	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);
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



DllExport void Renderer::setBuffers(int quantity, unsigned int& id, unsigned int bufferArray[], GLenum drawMode, GLenum bufferMode)
{
	glGenBuffers(quantity, &id); //Crea el buffer con el ID pasado por parametro (un unsigned int)
	glBindBuffer(bufferMode, id); //bindea el parametro id a el bufferMode especificado
	glBufferData(bufferMode, 4 * 2 * sizeof(float), bufferArray, drawMode);	//Le asigna la info al buffer PARAMETROS: modo al que se bindeo el buffer, tamaño del buffer, contenido del buffer, para que se va a suar el buffer
}

DllExport void Renderer::setBuffers(int quantity, unsigned int& id, float bufferArray[], GLenum drawMode, GLenum bufferMode)
{
	glGenBuffers(quantity, &id); //Crea el buffer con el ID pasado por parametro (un unsigned int)
	glBindBuffer(bufferMode, id); //bindea el parametro id a el bufferMode especificado
	glBufferData(bufferMode, 6 * 2 * sizeof(float), bufferArray, drawMode);	//Le asigna la info al buffer
}

DllExport void Renderer::setFloatVertex()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0); //Asigna los atributos XYZ RGBA ST del vertice y por cual debera empezar a leer
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
DllExport  unsigned int Renderer::CreateShader(const std::string& _vertexShader, const std::string& _fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, _vertexShader);
	unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, _fragmentShader);

	glm::mat4 auxMat = shaderTransform;
	unsigned int shaderTransformLoc = glGetUniformLocation(vertexShader, "modelMatrix");
	glUniformMatrix4fv(shaderTransformLoc, 1, GL_FALSE, glm::value_ptr(auxMat));

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return program;
}
DllExport void Renderer::Draw(unsigned int indexCount)
{
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
}



