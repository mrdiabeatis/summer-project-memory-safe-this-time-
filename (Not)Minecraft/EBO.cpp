#include"EBO.h"

EBO::EBO(std::vector<GLuint>& data) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GLuint), data.data(), GL_STATIC_DRAW);
	terminate();
}

void EBO::activate() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::terminate() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::destroy() {
	glDeleteBuffers(1, &ID);
}