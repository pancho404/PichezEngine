#include "Texture.h"
#include"stb_image.h"

Texture::Texture(const std::string& path)
	: rendererID(0), filePath(path), localBuffer(nullptr), width(54), height(81), BPP(0)
{
	stbi_set_flip_vertically_on_load(1);
	glGenTextures(1, &rendererID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, rendererID);
	//Bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int awidth, aheight, nrChannels;
	unsigned char* data = stbi_load("C:/Users/Administrador/Desktop/PichezEngine/PichezDLL/res/sauron.jpg", &awidth, &aheight, &nrChannels, 0);
	//localBuffer = stbi_load("res/sauron.jpg", &width, &height, &BPP, 0);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, awidth, aheight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	
	stbi_image_free(localBuffer);
}

Texture::~Texture()
{
	glDeleteTextures(1, &rendererID);
}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, rendererID);
	
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

