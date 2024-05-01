#pragma once

#include<iostream>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"TextureLoader.h"
#include"FileParser.h"

class Shader {
	const char* vertexShaderSource;
	const char* fragmentShaderSource;
public:
	GLuint ID;
	Shader(const char* vertex, const char* fragment);
	void activate();
	void terminate();
	void destroy();
};