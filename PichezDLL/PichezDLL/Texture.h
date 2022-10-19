#pragma once

#include"renderer.h"
class Texture
{
private:
	unsigned int rendererID;
	std::string filePath;
	unsigned char* localBuffer;
	int width, height, BPP;

public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0)const;
	void Unbind()const;
	int GetWidth()const { return width; }
	int GetHeight()const { return height; }

};

