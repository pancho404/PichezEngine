#pragma once

#include"renderer.h"
class Texture
{
private:
	unsigned int rendererID;
	std::string filePath;
	unsigned char* localBuffer;
	int width, height, BPP;
	Renderer* renderer;
public:
	Texture(const std::string& path, Renderer* renderer);
	~Texture();

	void Bind()const;
	void Unbind()const;
	int GetWidth()const { return width; }
	int GetHeight()const { return height; }
	unsigned int GetID()const { return rendererID; }
	
};

