#pragma once

#include<glad/glad.h>
#include<vector>

class VBO {
public:
	GLuint ID;
	VBO(std::vector<GLfloat>& data);
	VBO(std::vector<GLdouble>& data);
	VBO(std::vector<GLint>& data);
	VBO(std::vector<GLuint>& data);
	VBO(std::vector<GLchar>& data);

	void activate();
	void terminate();
	void destroy();
};