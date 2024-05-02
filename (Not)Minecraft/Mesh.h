#pragma once

#include"Shader.h"

#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

class Mesh {
public:
	struct data { VAO vao = *(VAO*)calloc(1, sizeof(VAO)); } data;
	Mesh(std::vector<GLfloat> &positions, std::vector<GLuint> &indices, std::vector<GLfloat> &uvs, std::vector<GLfloat> &normals);

	void de_instance();
};