#pragma once
#include "glew.h"
#include "glfw3.h"
#include "DLLExport.h"
#include <iostream>
#include <string.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Renderer
{
public:
	DllExport Renderer(static glm::mat4 rendererModelMatrix, std::string method);
	DllExport ~Renderer();
	DllExport void renderWindow(GLFWwindow* window, float vertexPositions[], unsigned int indexes[]);
	DllExport void clearWindow();
	DllExport void swapBuffers(GLFWwindow* window);
	DllExport void setBuffers(int quantity, unsigned int& id, unsigned int bufferArray[], GLenum drawMode, GLenum bufferMode);
	DllExport void setBuffers(int quantity, unsigned int& id, float bufferArray[], GLenum drawMode, GLenum bufferMode);
	DllExport void setFloatVertex();
	DllExport static unsigned int CompileShader(unsigned int type, const std::string& source);
	DllExport static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	DllExport void Draw(unsigned int indexCount);
	DllExport void updateRendererModelMatrix(glm::mat4 modelMatrix);
	DllExport void updateMVPMatrix(glm::mat4 viewMatrix);
private:
	glm::mat4 rendererModelMatrix;
	glm::mat4 projectionMatrix;
	glm::mat4 rendererMVPMatrix;
};

