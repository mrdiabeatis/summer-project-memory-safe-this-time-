#include"Mesh.h"

Mesh::Mesh(std::vector<GLfloat>& positions, std::vector<GLuint>& indices, std::vector<GLfloat>& uvs, std::vector<GLfloat>& normals) {
	VAO _vao;
	_vao.activate();

	VBO V_vbo(positions);
	V_vbo.activate();
	EBO ebo(indices);
	ebo.activate();

	_vao.LinkAttrib(V_vbo, 0, 3, GL_FLOAT, 3 * sizeof(GL_FLOAT), (void*)0);
	//vao.LinkAttrib(V_vbo, 1, 2, GL_FLOAT, 2 * sizeof(GL_FLOAT), (void*)0);

	_vao.terminate();
	V_vbo.terminate();
	ebo.terminate();

	data.vao = _vao;
}