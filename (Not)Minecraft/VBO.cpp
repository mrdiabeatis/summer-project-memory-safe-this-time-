#include"VBO.h"

VBO::VBO(std::vector<GLfloat>& data) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);
	terminate();
}

VBO::VBO(std::vector<GLdouble>& data) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLdouble), data.data(), GL_STATIC_DRAW);
	terminate();
}

VBO::VBO(std::vector<GLint>& data) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLint), data.data(), GL_STATIC_DRAW);
	terminate();
}

VBO::VBO(std::vector<GLuint>& data) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLuint), data.data(), GL_STATIC_DRAW);
	terminate();
}

VBO::VBO(std::vector<GLchar>& data) {
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLchar), data.data(), GL_STATIC_DRAW);
	terminate();
}

void VBO::activate() {
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::terminate() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::destroy() {
	glDeleteBuffers(1, &ID);
}