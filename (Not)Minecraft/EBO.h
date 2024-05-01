#pragma once

#include<glad/glad.h>
#include<vector>

class EBO {
public:
	GLuint ID;
	EBO(std::vector<GLuint>& data);

	void activate();
	void terminate();
	void destroy();
};