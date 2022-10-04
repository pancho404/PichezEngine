#include "renderer.h"

DllExport Renderer::Renderer(static glm::mat4 rendererModelMatrix, std::string method)
{
	this->rendererModelMatrix = rendererModelMatrix;
	viewMatrix = glm::mat4(1.0f);
	if (method=="ortho") //Proyeccion ortografica/paralela
	{
		projectionMatrix = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
	}
	else if (method=="perspective") //En este caso seria en perspectiva pero como se trata de un motor 2D no lo vamos a programar por ahora
	{
		//projectionMatrix= glm::perspective()
	}
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

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec3 position;" //creamos un vector que corresponde a la posicion de los vertices
		"\n"
		"uniform mat4 mvpMat;" //creamos la matriz MVP (Model View Projection) que modificara la posicion de los vertices
		"\n"
		"void main()\n"
		"{\n"
			"gl_Position =  mvpMat * vec4(position, 1.0f);\n" //Multiplicamos la MVPMat por un vec4 que contiene el vec3 anteriormente creado y un valor harcodeado en 1.0f para poder mutliplicarlo con la matriz
		"}\n";
	
	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"		
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0, 0.0, 1.0, 1.0);\n"
		"}\n";

	
	unsigned int shader = CreateShader(vertexShader, fragmentShader); 
	glUseProgram(shader);

	unsigned int shaderTransformLoc = glGetUniformLocation(shader, "mvpMat"); //Buscamos en AMBOS shaders la variable uniform llamada mvpMat y obtenemos su posicion en memoria
	glUniformMatrix4fv(shaderTransformLoc, 1, GL_FALSE, glm::value_ptr(rendererMVPMatrix)); //le asignamos contenido a la variable que se encuentra en esa posicion de memoria

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
	glBufferData(bufferMode, 4 * 2 * sizeof(float), bufferArray, drawMode);	//Le asigna la info al buffer PARAMETROS: modo al que se bindeo el buffer, tama�o del buffer, contenido del buffer, para que se va a suar el buffer
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

DllExport void Renderer::updateRendererModelMatrix(glm::mat4 modelMatrix)
{
	rendererModelMatrix = modelMatrix;
}

DllExport void Renderer::updateMVPMatrix()
{
	rendererMVPMatrix = projectionMatrix * viewMatrix * rendererModelMatrix;
}

DllExport glm::mat4 Renderer::getViewMatrix()
{
	return viewMatrix;
}



