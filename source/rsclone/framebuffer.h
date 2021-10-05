#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GL/GLU.h>
#include <iostream>

#include "shader.h"

class Framebuffer
{

public:
	Framebuffer(int width, int height);
	~Framebuffer();
	void Bind();
	void Draw();

	Shader screenShader = Shader("screen.vert", "screen.frag");

	unsigned int quadVAO, quadVBO;
	unsigned int framebuffer;
	unsigned int textureColorbuffer;
	unsigned int renderbuffer;
};

#endif