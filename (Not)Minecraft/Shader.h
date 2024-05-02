#pragma once

#include<iostream>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"TextureLoader.h"
#include"FileParser.h"

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

class Shader {
	const char* vertexShaderSource;
	const char* fragmentShaderSource;
public:
	GLuint ID;
	Shader(const char* vertex, const char* fragment);

	void setInt(const char* name, int i);
	void setFloat(const char* name, float f);

	void setMat4(const char* name, glm::mat4 mat);

	void setVec2(const char* name, glm::vec2 vec);
	void setVec3(const char* name, glm::vec3 vec);

	void activate();
	void terminate();
	void de_instance();
};