#pragma once

#include <iostream>
#include <glad/glad.h>
#include "VBO.h"

class VAO {
public:
	GLuint ID;
	VAO();

	void LinkAttrib(VBO VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

	void activate();
	void terminate();
	void destroy();
};