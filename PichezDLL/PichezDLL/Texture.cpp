#include "Texture.h"
#include"stb_image.h"

Texture::Texture(const std::string& path, Renderer* renderer)
	: rendererID(0), filePath(path), localBuffer(nullptr), width(0), height(0), BPP(0)
{
	unsigned char* data;

	std::string pathName = path;
	data = stbi_load(pathName.c_str(), &width, &height, &BPP, 0);

	if (!data)
	{
		std::cout << "Cant read the data texture" << std::endl;
	}

	glGenTextures(1, &rendererID);
	glBindTexture(GL_TEXTURE_2D, rendererID);

	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (BPP == 4) //dependiendo de los canales, va a usar para rgba o rgb, sino se rompe todo.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	else if (BPP == 3)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	else if (BPP == 2)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	else if (BPP == 1)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_R, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	//Esto generará automáticamente todos los mapas MIP necesarios para la textura enlazada actualmente.
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
}

Texture::~Texture()
{
	glDeleteTextures(1, &rendererID);
}

void Texture::Bind(unsigned int slot, unsigned int textureUnit) const
{
	glBindTexture(GL_TEXTURE_2D, textureUnit);	
}

void Texture::Unbind() const
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

