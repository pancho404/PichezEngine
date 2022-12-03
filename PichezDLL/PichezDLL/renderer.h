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
	DllExport void renderWindow(GLFWwindow* window);
	DllExport void clearWindow();
	DllExport void swapBuffers(GLFWwindow* window);
	DllExport void setBuffers(int quantity, unsigned int bufferArray[], GLenum drawMode, GLenum bufferMode, unsigned int &indexBufferObject);
	DllExport void setBuffers(int quantity, float bufferArray[], GLenum drawMode, GLenum bufferMode, unsigned int &vertexBufferObject);
	DllExport void setFloatVertex();
	DllExport static unsigned int CompileShader(unsigned int type, const std::string& source);
	DllExport static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	DllExport void Draw(unsigned int indexCount, unsigned int& vertexArrayObject, unsigned int textureID);
	DllExport void updateRendererModelMatrix(glm::mat4 modelMatrix);
	DllExport void updateMVPMatrix();
	DllExport void setUniform1i();
	DllExport glm::mat4 getViewMatrix();
	DllExport void updateViewMatrix();
	unsigned int shader;
	DllExport void drawTexture(unsigned int indices, unsigned int VAO, unsigned int VBO, float* vertices, float textureVerticesSize);
private:
	glm::mat4 rendererModelMatrix;
	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;
	glm::mat4 rendererMVPMatrix;
	unsigned int indexBufferObject;
	unsigned int vertexBufferObject;
	unsigned int vertexArrayObject;
};

