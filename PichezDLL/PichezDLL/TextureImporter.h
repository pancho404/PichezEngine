#pragma once
#include "DLLExport.h"

class DllExport TextureImporter
{

public:

	void LoadTexture(const char* path, unsigned char* data, unsigned int& texture, int width, int height, int channels, bool transparent);

};

