#include "renderer.h"

DllExport Renderer::Renderer(static glm::mat4 rendererModelMatrix, std::string method)
{
	this->rendererModelMatrix = rendererModelMatrix;
	viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	if (method == "ortho") //Proyeccion ortografica/paralela
	{
		projectionMatrix = glm::ortho(0.0f, 640.0f, 480.0f, 0.0f, -50.0f, 50.0f);
	}
	else if (method == "perspective") //En este caso seria en perspectiva pero como se trata de un motor 2D no lo vamos a programar por ahora
	{
		//projectionMatrix= glm::perspective()
	}
}

DllExport Renderer::~Renderer()
{
	glDeleteProgram(shader);
}

DllExport void Renderer::renderWindow(GLFWwindow* window)
{


	setFloatVertex(); //Seteamos los datos de las posiciones de los vertices

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec3 position;" //creamos un vector que corresponde a la posicion de los vertices
		"\n"
		"layout (location = 1) in vec3 aColor;"
		"\n"
		"layout(location = 2) in vec2 aTexCoord;"
		"\n"
		"out vec3 ourColor;"
		"\n"
		"out vec2 TexCoord;"
		"\n"
		"uniform mat4 model = mat4(1.0f);" //creamos la matriz MVP (Model View Projection) que modificara la posicion de los vertices
		"\n"
		"uniform mat4 view = mat4(1.0f);" //creamos la matriz MVP (Model View Projection) que modificara la posicion de los vertices
		"\n"
		"uniform mat4 projection = mat4(1.0f);" //creamos la matriz MVP (Model View Projection) que modificara la posicion de los vertices
		"\n"
		"void main()\n"
		"{\n"
			"gl_Position =  projection * view * model * vec4(position, 1.0f);\n" //Multiplicamos la MVPMat por un vec4 que contiene el vec3 anteriormente creado y un valor harcodeado en 1.0f para poder mutliplicarlo con la matriz
			"ourColor = aColor;\n"
			"TexCoord = aTexCoord;\n"
		"}\n";

	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"in vec3 ourColor;"
		"\n"
		"in vec2 TexCoord;\n"
		"\n"
		"uniform sampler2D ourTexture;\n"
		"\n"
		"void main()\n"
		"{\n"
			"color = texture(ourTexture, TexCoord);"
			//"color = ourColor;"
		"}\n";


	shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);
	


	//glUseProgram(0);
}

DllExport void Renderer::clearWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}

DllExport void Renderer::swapBuffers(GLFWwindow* window)
{
	glfwSwapBuffers(window);
}



DllExport void Renderer::setBuffers(int quantity, unsigned int bufferArray[], GLenum drawMode, GLenum bufferMode, unsigned int &indexBufferObject)
{
	glGenBuffers(quantity, &indexBufferObject); //Crea el buffer con el ID pasado por parametro (un unsigned int)
	glBindBuffer(bufferMode, indexBufferObject); //bindea el parametro id a el bufferMode especificado
	glBufferData(bufferMode, 6 * sizeof(float), bufferArray, drawMode);	//Le asigna la info al buffer PARAMETROS: modo al que se bindeo el buffer, tama�o del buffer, contenido del buffer, para que se va a suar el buffer
}

DllExport void Renderer::setBuffers(int quantity, float bufferArray[], GLenum drawMode, GLenum bufferMode, unsigned int &vertexBufferObject)
{
	glGenBuffers(quantity, &vertexBufferObject); //Crea el buffer con el ID pasado por parametro (un unsigned int)
	glBindBuffer(bufferMode, vertexBufferObject); //bindea el parametro id a el bufferMode especificado
	glBufferData(bufferMode, 4 * 3 * 3 * 2 * sizeof(float), bufferArray, drawMode);	//Le asigna la info al buffer
}

DllExport void Renderer::setFloatVertex()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, 0); //Asigna los atributos XYZ RGBA ST del vertice y por cual debera empezar a leer
	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(3 * sizeof(float))); //Asigna los atributos XYZ RGBA ST del vertice y por cual debera empezar a leer
	glEnableVertexAttribArray(1);
	
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(6 * sizeof(float))); //Asigna los atributos XYZ RGBA ST del vertice y por cual debera empezar a leer
	glEnableVertexAttribArray(2);
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
DllExport void Renderer::Draw(unsigned int indexCount, unsigned int &vertexArrayObject, unsigned int textureID)
{
	glBindVertexArray(vertexArrayObject);
	glUniform1f(glGetUniformLocation(shader, "ourTexture"), (GLfloat)textureID);
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
}

DllExport void Renderer::updateRendererModelMatrix(glm::mat4 modelMatrix)
{
	rendererModelMatrix = modelMatrix;
}

DllExport void Renderer::updateMVPMatrix()
{
	glUseProgram(shader);
	unsigned int modelLoc = glGetUniformLocation(shader, "model"); //Buscamos en AMBOS shaders la variable uniform llamada mvpMat y obtenemos su posicion en memoria
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(rendererModelMatrix)); //le asignamos contenido a la variable que se encuentra en esa posicion de memoria
	unsigned int viewLoc = glGetUniformLocation(shader, "view"); //Buscamos en AMBOS shaders la variable uniform llamada mvpMat y obtenemos su posicion en memoria
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix)); //le asignamos contenido a la variable que se encuentra en esa posicion de memoria
	unsigned int projectionLoc = glGetUniformLocation(shader, "projection"); //Buscamos en AMBOS shaders la variable uniform llamada mvpMat y obtenemos su posicion en memoria
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix)); //le asignamos contenido a la variable que se encuentra en esa posicion de memoria
}

DllExport glm::mat4 Renderer::getViewMatrix()
{
	return viewMatrix;
}

DllExport void Renderer::updateViewMatrix()
{
	viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

DllExport void Renderer::drawTexture(unsigned int indices, unsigned int& VAO, unsigned int& VBO, float* vertices, float textureVerticesSize)
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, textureVerticesSize, vertices, GL_STATIC_DRAW);

	glUseProgram(shader);

	unsigned int texLocation = glGetAttribLocation(shader, "ourTexture");

	glVertexAttribPointer(texLocation, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(6 * sizeof(float))); //Asigna los atributos XYZ RGBA ST del vertice y por cual debera empezar a leer
	glEnableVertexAttribArray(texLocation);

	glDrawElements(GL_TRIANGLES, indices, GL_UNSIGNED_INT, nullptr);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glUseProgram(0);
}



