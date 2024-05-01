#include"VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &ID);
}

void VAO::LinkAttrib(VBO VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
	VBO.activate();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.terminate();
}

void VAO::activate() {
	glBindVertexArray(ID);
}

void VAO::terminate() {
	glBindVertexArray(0);
}

void VAO::destroy() {
	glDeleteVertexArrays(1, &ID);
}