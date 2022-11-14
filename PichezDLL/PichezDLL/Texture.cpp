#include "Texture.h"
#include"stb_image.h"

Texture::Texture(const std::string& path)
	: rendererID(0), filePath(path), localBuffer(nullptr), width(0), height(0), BPP(0)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(1);
	glGenTextures(1, &rendererID);
	/*glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, rendererID);*/
	unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &BPP, 0);
	//localBuffer = stbi_load("res/sauron.jpg", &width, &height, &BPP, 0);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	
	stbi_image_free(data);
}

Texture::~Texture()
{
	glDeleteTextures(1, &rendererID);
}

void Texture::Bind(unsigned int slot, unsigned int textureUnit) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, textureUnit);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

