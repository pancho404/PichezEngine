#pragma once
#include "entity.h"
#include "Texture.h"

#include "Animation.h"
class  DllExport Sprite : public Entity
{

private:
	Texture* texturejeje;
	Renderer* renderer;
	unsigned int texture;
	int width;
	int height;
	int channels;
	unsigned char* data;
	Animation* animation;
	bool settedAnimation;
	bool isTransparent;
	unsigned int textureVerticesSize;
	unsigned int indices[6] =
	{
		0, 1, 3,
		1, 2, 3
	};
	float vertices[32] =
	{
		// positions          // colors           // texture coords
		 100.0f,  0, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // top right
		 100.0f, 100.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,   // bottom right
		 0.0f, 100.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,   // bottom left
		 0.0f,  0.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f    // top left 
	};
	float* vertexBuffer;
	unsigned int VBO;
	unsigned int VAO;
	unsigned int uvVAO;
	unsigned int uvVBO;

public:

	Sprite(Renderer* rend);
	~Sprite();
	void LoadTexture(const char* path, bool isTransparent);
	void StartUseAnimation();
	void SetAnimation(int columns, int rows, float framesPerSeconds);
	void AddFrameToAnimation(int frameX, int frameY, int frame);
	void DrawTexture(Renderer* renderer);
	void draw(Renderer* renderer, int indexCount, unsigned int textureID) override;
	void UpdateAnimation();
	float* GetVertices();
	int GetChannels();
	void BlendSprite();
	void UnBlendSprite();
};



